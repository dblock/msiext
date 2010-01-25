#include "StdAfx.h"
#include "ODBQCmdEngine.h"

ODBQCmdEngine::ODBQCmdEngine(int argc, wchar_t * argv[])
    : _cmd(L"ODBQ " _T(VERSION_VALUE), L' ', _T(VERSION_VALUE))
	, _nologo(L"", L"nologo", L"Suppress logo and messages, raw output only.", _cmd)
	, _nosql(L"", L"nosql", L"Suppress SQL statements output to console.", _cmd)
	, _noresults(L"", L"noresults", L"Suppress results output to console.", _cmd)
    , _connectionstring(L"", L"connectionstring", L"Driver-specific connection string to use to connect to the server,  eg. \"Driver=SQL Server;Server=.;Trusted_Connection=yes\"", false, L"Driver=SQL Server;Server=.;Trusted_Connection=yes;", L"string", _cmd)
    , _sql(L"", L"sql", L"SQL query to execute, eg. \"SELECT @@VERSION\".", true, L"string")
    , _file(L"", L"file", L"File(s) containing SQL statements, may be a wildcard.", true, L"file")
    , _type(L"t", L"type", L"Type of sql script: mssql (default), oracle.", false, L"SqlServer", L"string", _cmd)
    , _delimiter(L"", L"delimiter", L"Delimiter for splitting SQL statements, eg. \"GO\".", false, L"", L"string", _cmd)
    , _outputfile(L"", L"outputfile", L"Xml output file for messages and dataset results.", false, L"", L"file", _cmd)
    , _datafile(L"", L"datafile", L"XML file containing data sets to insert.", true, L"datafile")
{
    std::vector<TCLAP::Arg *> file_args;
    file_args.push_back(& _sql);
    file_args.push_back(& _file);
    file_args.push_back(& _datafile);
    _cmd.xorAdd(file_args);
    _cmd.parse(argc, argv, true);
}

void ODBQCmdEngine::Execute()
{
    _xmlresults.Create();
    _xmlresults_rootnode = _xmlresults.AppendChild(L"Data");

	if (! _nologo.getValue())
	{
		std::wcout << std::endl << L"- Connecting with \"" << _connectionstring.getValue() << L"\"";
		if (!_type.getValue().empty()) 
		{
			std::wcout << std::endl << L"- Using \"" << _type.getValue() << L"\" parser";
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
			std::wcout << std::endl << L"- Writing \"" + outputfile_full + L"\"";
		}

        CHECK_HR(_xmlresults->save(CComVariant(outputfile_full.c_str())),
            L"Error saving \"" << _outputfile.getValue() << L"\"");
    }
}

void ODBQCmdEngine::ExecuteFile(const std::wstring& file)
{
    std::wstring query;
	
	if (! _nologo.getValue())
	{
		std::wcout << std::endl << L"- Loading \"" + file + L"\"";
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
	
	if (_delimiter.isSet())
	{
		std::vector<const std::wstring> delims;
		delims.push_back(_delimiter.getValue());
		parser.setDelimiters(delims);
	}
	else if (!_type.getValue().empty()) 
	{
		parser.setSqlFlavour(_type.getValue());
	}
	Execute(parser);
}

void ODBQCmdEngine::Execute(AppSecInc::Databases::ODBC::OdbcParser& parser)
{
    AppSecInc::Databases::ODBC::ODBCConnectionStringInfo ci(_connectionstring.getValue());
    AppSecInc::Databases::ODBC::ODBCConnection conn;
    conn.Connect(ci);

    while(parser.hasMore())
    {
		const std::wstring statement = parser.getNextBatch();
        long messages = 0;
		std::wstring executed_statement = statement;
		AppSecInc::StringUtils::lrtrimcrlf(executed_statement);

		if (executed_statement.empty())
			continue;

		if (! _nosql.getValue())
		{
			std::wcout << std::endl;
			if (! _nologo.getValue()) std::wcout << L"> ";
			std::wcout << executed_statement;
			messages++;
		}

        MSXML2::IXMLDOMNodePtr result = conn.GetXml(executed_statement, _xmlresults, _xmlresults_rootnode);

        if (_noresults.getValue())
            continue;

        long cols = AppSecInc::StringUtils::stringToLong(_xmlresults.SelectAttributeValue(L"columns", result));
        long rows = AppSecInc::StringUtils::stringToLong(_xmlresults.SelectAttributeValue(L"rows", result));

		if (! _noresults.getValue())
		{
			if (rows != 0)
			{
				std::wcout << std::endl << L"< " << rows << L"x" << cols;
				messages++;
			}
		}

        // output messages
		{
			MSXML2::IXMLDOMNodeListPtr message_rows = _xmlresults.SelectNodes(L"Messages/Message", result);
			MSXML2::IXMLDOMNodePtr message_row = NULL;	
			while (NULL != (message_row = message_rows->nextNode()))
			{
				if (messages++ > 0) std::wcout << std::endl;
				if (! _nologo.getValue()) std::wcout << L"< ";
				std::wcout << message_row->text;
			}
		}

        // output results
		{
			MSXML2::IXMLDOMNodeListPtr result_rows = _xmlresults.SelectNodes(L"RowSet/Row", result);
			MSXML2::IXMLDOMNodePtr result_row = NULL;
			int row = 0;
			while (NULL != (result_row = result_rows->nextNode()))
			{
                // column header
                if (row == 0)
                {
                    if (! _nologo.getValue() || messages > 0) std::wcout << std::endl;
                    int col = 0;
				    MSXML2::IXMLDOMNodeListPtr result_columns = result_row->childNodes;
				    MSXML2::IXMLDOMNodePtr result_column = NULL;
				    while (NULL != (result_column = result_columns->nextNode()))
				    {
					    if (col++ > 0) std::wcout << L"\t";
                        std::wcout << result_column->nodeName;
				    }
                }

                // column divider
                if (row == 0)
                {
                    std::wcout << std::endl;
                    int col = 0;
				    MSXML2::IXMLDOMNodeListPtr result_columns = result_row->childNodes;
				    MSXML2::IXMLDOMNodePtr result_column = NULL;
				    while (NULL != (result_column = result_columns->nextNode()))
				    {
					    if (col++ > 0) std::wcout << L"\t";
                        for (unsigned int c = 0; c < result_column->nodeName.length(); c++) std::wcout << "-";
				    }
                }

                // column values
                {
				    std::wcout << std::endl;
                    int col = 0;
				    MSXML2::IXMLDOMNodeListPtr result_columns = result_row->childNodes;
				    MSXML2::IXMLDOMNodePtr result_column = NULL;
				    while (NULL != (result_column = result_columns->nextNode()))
				    {
					    if (col++ > 0) std::wcout << L"\t";
                        std::wcout << result_column->text;
				    }
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
		std::wcout << std::endl << L"- Importing \"" + file + L"\"";
	}

    AppSecInc::Xml::XmlDocument xmldoc;
    xmldoc.Load(file);

    AppSecInc::Databases::ODBC::ODBCConnectionStringInfo ci(_connectionstring.getValue());
    AppSecInc::Databases::ODBC::ODBCConnection conn;
    conn.Connect(ci);
    conn.InsertXml(xmldoc, _xmlresults, _xmlresults_rootnode);
}
