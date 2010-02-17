#include "StdAfx.h"
#include "ODBQCmdEngine.h"

ODBQCmdEngine::ODBQCmdEngine(int argc, wchar_t * argv[])
    : _cmd(L"ODBQ " _T(VERSION_VALUE), L' ', _T(VERSION_VALUE))
	, _nologo(L"", L"nologo", L"Suppress logo and messages, raw output only.", _cmd)
	, _nosql(L"", L"nosql", L"Suppress SQL statements output to console.", _cmd)
	, _noresults(L"", L"noresults", L"Suppress results output to console.", _cmd)
    , _connectionstring(L"", L"connectionstring", L"Driver-specific connection string to use to connect to the server,  eg. \"Driver=SQL Server;Server=.;Trusted_Connection=yes\"", false, L"Driver=SQL Server;Server=.;Trusted_Connection=yes;", L"string", _cmd)
    , _database(L"d", L"database", L"Default database name.", false, L"", L"string", _cmd)
    , _sql(L"", L"sql", L"SQL query to execute, eg. \"SELECT @@VERSION\".", true, L"string")
    , _file(L"f", L"file", L"File(s) containing SQL statements, may be a wildcard.", true, L"file")
    , _type(L"t", L"type", L"Type of sql script: mssql (default), oracle.", false, L"SqlServer", L"string", _cmd)
    , _delimiter(L"", L"delimiter", L"Delimiter for splitting SQL statements, eg. \"GO\".", false, L"", L"string", _cmd)
    , _outputfile(L"o", L"outputfile", L"Xml output file for messages and dataset results.", false, L"", L"file", _cmd)
    , _datafile(L"", L"datafile", L"XML file containing data sets to insert.", true, L"datafile")
    , _flatten(L"", L"flattenonly", L"Substitute included files only.", _cmd)
    , _rawoutput(L"", L"rawoutput", L"Output results in raw format.", _cmd)
{
    std::vector<TCLAP::Arg *> file_args;
    file_args.push_back(& _sql);
    file_args.push_back(& _file);
    file_args.push_back(& _datafile);
    _cmd.xorAdd(file_args);
    _cmd.parse(argc, argv, true);
}

std::wstring ODBQCmdEngine::GetConnectionString()
{
	std::wstringstream result;
	result << _connectionstring.getValue();
	if (_database.isSet()) 
	{
		result << L"database=" << _database.getValue() << L";";
	}
	return result.str();
}

void ODBQCmdEngine::Execute()
{
    _xmlresults.Create();
    _xmlresults_rootnode = _xmlresults.AppendChild(L"Data");

	if (! _nologo.getValue())
	{
		std::wcout << L"- Connecting with \"" << GetConnectionString() << L"\"" << std::endl;
		if (!_type.getValue().empty()) 
		{
			std::wcout << L"- Using \"" << _type.getValue() << L"\" parser" << std::endl;
		}
	}

    if (_file.isSet())
    {
        for each(const std::wstring& file in _file.getValue())
        {
			std::list<std::wstring> flagged_files = AppSecInc::File::GetFiles(file, AppSecInc::File::GET_FILES_FILES);
			
			if (flagged_files.size() == 0) 
			{
				throw std::exception(("Missing \"" + AppSecInc::StringUtils::wc2mb(file) + "\"").c_str());
			}

			for each(const std::wstring& flagged_file in flagged_files)
			{
				ExecuteFile(flagged_file);
			}
        }
    }

    if (_sql.isSet())
    {
        for each(const std::wstring& sql in _sql.getValue())
        {
            ExecuteSql(sql);
        }
    }

    if (_datafile.isSet())
    {
        for each(const std::wstring& datafile in _datafile.getValue())
        {
            InsertDataFile(datafile);
        }
    }

    if (_outputfile.isSet())
    {
        std::wstring outputfile_full = AppSecInc::File::DirectoryCombine(
            AppSecInc::File::GetCurrentDirectoryW(), _outputfile.getValue());

		if (! _nologo.getValue())
		{
			std::wcout << L"- Writing \"" + outputfile_full + L"\"" << std::endl;
		}
		
		if (output.empty()) 
		{
            CHECK_HR(_xmlresults->save(CComVariant(outputfile_full.c_str())),
                L"Error saving \"" << _outputfile.getValue() << L"\"");
        }
        else 
        {
			std::string out = AppSecInc::StringUtils::wc2mb(output);
			std::vector<char> vout(out.begin(), out.end());
			AppSecInc::File::FileWrite(outputfile_full, vout);
        }
    }
    else 
	{
		if (!output.empty()) 
		{
			std::wcout << output << std::endl;
		}
	}
}

void ODBQCmdEngine::ExecuteFile(const std::wstring& file)
{
    std::wstring query;
	
	if (! _nologo.getValue())
	{
		std::wcout << L"- Loading \"" + file + L"\"" << std::endl;
	}

    AppSecInc::File::ReadToEnd(file, query);
    CHECK_BOOL(! query.empty(),
        L"File \"" << file << L"\" is empty");
    ExecuteSql(query);
}

void ODBQCmdEngine::ExecuteSql(const std::wstring& sql)
{
	AppSecInc::Databases::ODBC::OdbcParser parser;
	parser.setInput(sql);
	// since type has a default, we need to empty it if delimiter was set:
	std::wstring type = (_type.isSet() || !_delimiter.isSet()? _type.getValue(): L"");
	parser.setSqlTypeOrDelimiter(type, _delimiter.getValue());
	
	if (_flatten.isSet()) 
	{
		output = parser.processInsertsOnly();
	}
	else 
	{
		Execute(parser);
	}
}

void ODBQCmdEngine::Execute(AppSecInc::Databases::ODBC::OdbcParser& parser)
{
    AppSecInc::Databases::ODBC::ODBCConnectionStringInfo ci(GetConnectionString());
    AppSecInc::Databases::ODBC::ODBCConnection conn;
    conn.Connect(ci);

    while(parser.hasMore())
    {
		const std::wstring statement = parser.getNextBatch();
        long messages = 0;

		if (statement.empty())
			continue;

		if (! _nosql.getValue())
		{
			if (! _nologo.getValue()) std::wcout << L"> ";
			std::wcout << statement;
			std::wcout << std::endl;
			messages++;
		}

		MSXML2::IXMLDOMNodePtr result;
        try {
            result = conn.GetXml(statement, _xmlresults, _xmlresults_rootnode);
        }
        catch (std::exception& ex) 
        {
            std::wstringstream error;
            error << AppSecInc::StringUtils::mb2wc(ex.what())
                  << (parser.exitOnErrorFlag()? L"": L" - IGNORED");
            std::wcout << error.str() << std::endl;
            if (parser.exitOnErrorFlag()) {
                throw std::exception("Error executing sql statement, terminated");
            }
        }

        if (_noresults.getValue())
            continue;

        // output messages
		{
			MSXML2::IXMLDOMNodeListPtr message_rows = _xmlresults.SelectNodes(L"Messages/Message", result);
			MSXML2::IXMLDOMNodePtr message_row = NULL;	
			while (NULL != (message_row = message_rows->nextNode()))
			{
				if (! _nologo.getValue()) std::wcout << L"< ";
				std::wcout << message_row->text << std::endl;
			}
		}

        long cols = 0;
        long rows = 0;
        if (result != NULL)
        {
            cols = AppSecInc::StringUtils::stringToLong(_xmlresults.SelectAttributeValue(L"columns", result));
            rows = AppSecInc::StringUtils::stringToLong(_xmlresults.SelectAttributeValue(L"rows", result));
        }

		if (rows != 0 && !_rawoutput.getValue())
		{
			std::wcout << L"< " << rows << L"x" << cols << std::endl;
			messages++;
		}

        // output results
		{
			MSXML2::IXMLDOMNodeListPtr result_rows = _xmlresults.SelectNodes(L"RowSet/Row", result);
			MSXML2::IXMLDOMNodePtr result_row = NULL;
			int row = 0;
			while (NULL != (result_row = result_rows->nextNode()))
			{
                // column header
                if (row == 0 && !_rawoutput.getValue())
                {
                    int col = 0;
				    MSXML2::IXMLDOMNodeListPtr result_columns = result_row->childNodes;
				    MSXML2::IXMLDOMNodePtr result_column = NULL;
				    while (NULL != (result_column = result_columns->nextNode()))
				    {
					    if (col++ > 0) std::wcout << L"\t";
                        std::wcout << result_column->nodeName;
				    }
				    std::wcout << std::endl;
                }

                // column divider
                if (row == 0 && !_rawoutput.getValue())
                {
                    int col = 0;
				    MSXML2::IXMLDOMNodeListPtr result_columns = result_row->childNodes;
				    MSXML2::IXMLDOMNodePtr result_column = NULL;
				    while (NULL != (result_column = result_columns->nextNode()))
				    {
					    if (col++ > 0) std::wcout << L"\t";
                        for (unsigned int c = 0; c < result_column->nodeName.length(); c++)
                             std::wcout << "-";
				    }
                    std::wcout << std::endl;
                }

                // column values
                {
                    int col = 0;
				    MSXML2::IXMLDOMNodeListPtr result_columns = result_row->childNodes;
				    MSXML2::IXMLDOMNodePtr result_column = NULL;
				    while (NULL != (result_column = result_columns->nextNode()))
				    {
						if (_rawoutput.getValue()) {
							if (col++ > 0) output += L"\t";
							output += result_column->text;
						}
						else {
							if (col++ > 0) std::wcout << L"\t";
							std::wcout << result_column->text;
						}
				    }
					if (_rawoutput.getValue())
						output += L"\n";
					else
						std::wcout << std::endl;
                }

                row++;
			}
		}
    }
}

void ODBQCmdEngine::InsertDataFile(const std::wstring& file)
{
	if (! _nologo.getValue())
	{
		std::wcout << L"- Importing \"" + file + L"\"" << std::endl;
	}

    AppSecInc::Xml::XmlDocument xmldoc;
    xmldoc.Load(file);

    AppSecInc::Databases::ODBC::ODBCConnectionStringInfo ci(GetConnectionString());
    AppSecInc::Databases::ODBC::ODBCConnection conn;
    conn.Connect(ci);
    conn.InsertXml(xmldoc, _xmlresults, _xmlresults_rootnode);
}
