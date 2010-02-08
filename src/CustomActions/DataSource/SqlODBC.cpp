#include "StdAfx.h"
#include "SqlODBC.h"
#include "BinaryIdPathResolver.h"
#include "SqlHandle.h"
#include "FlagMaps.h"

CA_API UINT __stdcall ODBC_Connect(MSIHANDLE hInstall)
{
    MSI_EXCEPTION_HANDLER_PROLOG;
    MsiImpersonatedInstall msiInstall(hInstall);

    // get connection string
    std::wstring connection_string = msiInstall.GetProperty(L"ODBC_CONNECTION_STRING");
    CHECK_BOOL(connection_string.length() > 0, L"Missing connection string");

    AppSecInc::Databases::ODBC::ODBCConnectionStringInfo connection_info(connection_string);
    AppSecInc::Databases::ODBC::ODBCConnection conn;
    try
    {
        conn.Connect(connection_info);
        msiInstall.SetProperty(L"ODBC_CONNECTION_ESTABLISHED", L"1");
        msiInstall.SetProperty(L"ODBC_ERROR", L"");
    }
    catch(std::exception& ex)
    {
        msiInstall.SetProperty(L"ODBC_CONNECTION_ESTABLISHED", L"");
        msiInstall.SetProperty("ODBC_ERROR", ex.what());
        throw ex;
    }

    MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall ODBC_Execute(MSIHANDLE hInstall)
{
    MSI_EXCEPTION_HANDLER_PROLOG;
    MsiImpersonatedInstall msiInstall(hInstall);

	std::wstring sql = msiInstall.GetProperty(L"ODBC_SQL_QUERY");
	std::wstring sqltype = msiInstall.GetProperty(L"ODBC_SQL_TYPE");
	std::wstring delimiter = msiInstall.GetProperty(L"ODBC_SQL_DELIMITER");

	AppSecInc::Databases::ODBC::ODBCConnectionStringInfo connection_info(
        msiInstall.GetProperty(L"ODBC_CONNECTION_STRING"));
	AppSecInc::Databases::ODBC::ODBCConnection conn;
    conn.Connect(connection_info);
	
	AppSecInc::Databases::ODBC::OdbcParser parser;
    parser.setInput(sql);
    parser.setSqlTypeOrDelimiter(sqltype, delimiter);
    
	while (parser.hasMore()) 
	{
        std::wstring trimmed_statement = parser.getNextBatch();
        if (trimmed_statement.empty()) 
			continue;
		
		conn.Execute(trimmed_statement);
    }

    MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}


CA_API UINT __stdcall ODBC_GetString(MSIHANDLE hInstall)
{
    MSI_EXCEPTION_HANDLER_PROLOG;
    MsiImpersonatedInstall msiInstall(hInstall);

    msiInstall.SetProperty(L"ODBC_SQL_RESULT", L"");
    AppSecInc::Databases::ODBC::ODBCConnectionStringInfo connection_info(
        msiInstall.GetProperty(L"ODBC_CONNECTION_STRING"));
    AppSecInc::Databases::ODBC::ODBCConnection conn;
    conn.Connect(connection_info);
    WORD flags = GetPropertyValue<FlagMapEntry[ARRAYSIZE(s_OdbcSqlFlags)], WORD>(msiInstall, L"ODBC_SQL_FLAGS", s_OdbcSqlFlags);
    std::wstring result = conn.GetWString(msiInstall.GetProperty(L"ODBC_SQL_QUERY"), flags);
    msiInstall.SetProperty(L"ODBC_SQL_RESULT", result);

    MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall ODBC_GetScalar(MSIHANDLE hInstall)
{
    MSI_EXCEPTION_HANDLER_PROLOG;
    MsiImpersonatedInstall msiInstall(hInstall);

    AppSecInc::Databases::ODBC::ODBCConnectionStringInfo connection_info(
        msiInstall.GetProperty(L"ODBC_CONNECTION_STRING"));
    AppSecInc::Databases::ODBC::ODBCConnection conn;
    conn.Connect(connection_info);
    long result = conn.GetScalar(msiInstall.GetProperty(L"ODBC_SQL_QUERY"));
    msiInstall.SetProperty(L"ODBC_SQL_RESULT", AppSecInc::StringUtils::toWString(result));

    MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall ODBC_GetXml(MSIHANDLE hInstall)
{
    MSI_EXCEPTION_HANDLER_PROLOG;
    MsiImpersonatedInstall msiInstall(hInstall);

    AppSecInc::Databases::ODBC::ODBCConnectionStringInfo connection_info(
        msiInstall.GetProperty(L"ODBC_CONNECTION_STRING"));
    AppSecInc::Databases::ODBC::ODBCConnection conn;
    conn.Connect(connection_info);
    std::wstring xml = conn.GetXml(msiInstall.GetProperty(L"ODBC_SQL_QUERY"));
    msiInstall.SetProperty(L"ODBC_SQL_RESULT", xml);

    MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Execute_ODBC_Deferred(MSIHANDLE hInstall)
{
    MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    // process ODBC statements
    AppSecInc::Xml::XmlDocument xmlDocument;
    xmlDocument.LoadXml(msiInstall.GetActionData());

    MSXML2::IXMLDOMNodeListPtr rows = xmlDocument.SelectNodes(L"/ODBCExecutes/ODBCExecute[@execute=\"true\"]");
    MSXML2::IXMLDOMNodePtr row = NULL;
    while (NULL != (row = rows->nextNode()))
    {
        std::wstring id = xmlDocument.SelectAttributeValue(L"id", row);
        std::wstring connectionstring = xmlDocument.SelectNodeValue(L"ConnectionString", row);
        std::wstring sql = xmlDocument.SelectNodeValue(L"Sql", row, L"");
        std::wstring filename = xmlDocument.SelectNodeValue(L"Filename", row, L"");
        std::wstring outputfilename = xmlDocument.SelectNodeValue(L"OutputFilename", row, L"");
        std::wstring delimiter = xmlDocument.SelectNodeValue(L"Delimiter", row, L"");
        std::wstring sqltype = xmlDocument.SelectNodeValue(L"Type", row, L"");
        std::wstring basepath = xmlDocument.SelectNodeValue(L"BasePath", row, L"");

        CHECK_BOOL(! (sql.empty() && filename.empty()),
            L"Missing SQL/Filename");

        if (! filename.empty())
        {
            msiInstall.LogInfo(_T(__FUNCTION__), L"Loading \"" + filename + L"\"");
            AppSecInc::File::ReadToEnd(filename, sql);

            CHECK_BOOL(! sql.empty(),
                L"File \"" << filename << L"\" is empty");
        }

        AppSecInc::Databases::ODBC::ODBCConnectionStringInfo ci(connectionstring);
        AppSecInc::Databases::ODBC::ODBCConnection conn;
        conn.Connect(ci);

        AppSecInc::Databases::ODBC::OdbcParser parser;
        parser.setInput(sql);
        parser.setSqlTypeOrDelimiter(sqltype, delimiter);
        parser.getPathResolver()->setBasePath(basepath);
        
        AppSecInc::Xml::XmlDocument xmlresults;
        xmlresults.Create();
        MSXML2::IXMLDOMNodePtr xmlresults_rootnode = xmlresults.AppendChild(L"Data");
        
        while (parser.hasMore()) 
		{
            std::wstring trimmed_statement = parser.getNextBatch();
            if (trimmed_statement.empty()) continue;
            std::wstringstream status;
            status << L"Executing \"" << trimmed_statement << "\" on \"" << connectionstring << L"\" (" << id << L")";
            msiInstall.LogInfo(_T(__FUNCTION__), status.str());
            try 
			{
                conn.GetXml(trimmed_statement, xmlresults, xmlresults_rootnode);
            }
            catch (std::exception& ex) 
            {
                std::wstringstream error;
                error << AppSecInc::StringUtils::mb2wc(ex.what())
                      << (parser.exitOnErrorFlag()? L"": L" - IGNORED");
                msiInstall.LogError(error.str());                
				if (parser.exitOnErrorFlag()) 
				{
                    throw std::exception("Error executing sql statement, terminated");
                }
            }
        }

        if (! outputfilename.empty())
        {
            msiInstall.LogInfo(_T(__FUNCTION__), L"Writing \"" + outputfilename + L"\"");
            CHECK_HR(xmlresults->save(CComVariant(outputfilename.c_str())),
                L"Error saving \"" << outputfilename << L"\"");
        }
    }

    MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Execute_ODBC_Immediate(MSIHANDLE hInstall)
{
    MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    typedef enum ODBCExecuteAttributes
    {
        ExecuteOnInstall = 1,
        ExecuteOnUnInstall = 2,
        ExecuteOnReInstall = 4,
        EvaluateProperties = 8
    };

    // immediate custom action, evaluate conditions and update the custom action table data

    /* 
        This produces an xml like this:

         <ODBCExecutes>
          <ODBCExecute>
           <Sql />
           <Attributes />
           <ConnectionString />
           ...
          </ODBCExecute>
         </ODBCExecute>

    */

    // combined xml document
    AppSecInc::Xml::XmlDocument combined_xml_document;
    combined_xml_document.Create();
    MSXML2::IXMLDOMNodePtr combined_xml_root = combined_xml_document.AppendChild(L"ODBCExecutes");

    // connection strings
    AppSecInc::Xml::XmlDocument connectionstring_xml_document;
    connectionstring_xml_document.LoadXml(msiInstall.GetViewData(L"SELECT * FROM `DatabaseConnectionString`"));
    std::map<std::wstring, std::wstring> connectionstring_map;
    MSXML2::IXMLDOMNodeListPtr connectionstring_rows = connectionstring_xml_document.SelectNodes(L"//Row");
    MSXML2::IXMLDOMNodePtr connectionstring_row = NULL;
    while (NULL != (connectionstring_row = connectionstring_rows->nextNode()))
    {
        std::wstring connectionstring_id = connectionstring_xml_document.SelectNodeValue(L"Data[@Column=\"Id\"]", connectionstring_row);
        std::wstring connectionstring = connectionstring_xml_document.SelectNodeValue(L"Data[@Column=\"ConnectionString\"]", connectionstring_row);
        connectionstring_map.insert(std::pair<std::wstring, std::wstring>(connectionstring_id, connectionstring));
    }

    // ODBC execute statements
    AppSecInc::Xml::XmlDocument odbcexecute_xml_document;
    odbcexecute_xml_document.LoadXml(msiInstall.GetViewData(L"SELECT * FROM `ODBCExecute`"));
    MSXML2::IXMLDOMNodeListPtr odbcexecute_rows = odbcexecute_xml_document.SelectNodes(L"//Row");
    MSXML2::IXMLDOMNodePtr odbcexecute_row = NULL;
    while (NULL != (odbcexecute_row = odbcexecute_rows->nextNode()))
    {
        std::wstring odbcexecute_id = odbcexecute_xml_document.SelectNodeValue(L"Data[@Column=\"Id\"]", odbcexecute_row);
        std::wstring odbcexecutecomponent_id = odbcexecute_xml_document.SelectNodeValue(L"Data[@Column=\"ComponentId\"]", odbcexecute_row, L"");
        std::wstring sql = odbcexecute_xml_document.SelectNodeValue(L"Data[@Column=\"Sql\"]", odbcexecute_row, L"");
        std::wstring filename = odbcexecute_xml_document.SelectNodeValue(L"Data[@Column=\"Filename\"]", odbcexecute_row, L"");
        std::wstring outputfilename = odbcexecute_xml_document.SelectNodeValue(L"Data[@Column=\"OutputFilename\"]", odbcexecute_row, L"");
        std::wstring binaryid = odbcexecute_xml_document.SelectNodeValue(L"Data[@Column=\"BinaryId\"]", odbcexecute_row, L"");
        std::wstring delimiter = odbcexecute_xml_document.SelectNodeValue(L"Data[@Column=\"Delimiter\"]", odbcexecute_row, L"");
        std::wstring sqltype = odbcexecute_xml_document.SelectNodeValue(L"Data[@Column=\"Type\"]", odbcexecute_row, L"");
        std::wstring basepath = odbcexecute_xml_document.SelectNodeValue(L"Data[@Column=\"BasePath\"]", odbcexecute_row, L"");
        std::wstring condition = odbcexecute_xml_document.SelectNodeValue(L"Data[@Column=\"Condition\"]", odbcexecute_row);
        // connection string
        std::wstring connectionstring = odbcexecute_xml_document.SelectNodeValue(L"Data[@Column=\"ConnectionStringId\"]", odbcexecute_row);
        connectionstring = connectionstring_map[connectionstring];
        // operational attributes
        long attributes = AppSecInc::StringUtils::stringToLong(odbcexecute_xml_document.SelectNodeValue(L"Data[@Column=\"Attributes\"]", odbcexecute_row));

        // no condition (executes by default) or condition evaluates to true
        bool execute_per_condition = condition.empty() || msiInstall.EvaluateCondition(condition);
        // execute on install
        bool execute_per_component_install = (odbcexecutecomponent_id.empty() || msiInstall.IsComponentInstalling(odbcexecutecomponent_id));
        // execute on uninstall
        bool execute_per_component_uninstall = (odbcexecutecomponent_id.empty() || msiInstall.IsComponentUnInstalling(odbcexecutecomponent_id));

        bool execute = execute_per_condition && (
            (execute_per_component_install && (attributes & ExecuteOnInstall) && msiInstall.IsInstalling()) 
            || (execute_per_component_uninstall && (attributes & ExecuteOnUnInstall) && msiInstall.IsUnInstalling())
            );

        // write the odbc query to xml
        MSXML2::IXMLDOMNodePtr combined_xml_odbcexecute_root = combined_xml_document.AppendChild(L"ODBCExecute", combined_xml_root);
        combined_xml_document.SetAttribute(L"execute", execute ? L"true" : L"false", combined_xml_odbcexecute_root);
        combined_xml_document.SetAttribute(L"id", odbcexecute_id, combined_xml_odbcexecute_root);

        // fetch the contents of the binary as SQL, substitute all inserts
        if (! binaryid.empty())
        {
            BinaryIdPathResolver resolver(&msiInstall);
            AppSecInc::Databases::ODBC::OdbcParser parser;
            parser.setPathResolver(&resolver);
            parser.setSqlTypeOrDelimiter(sqltype, delimiter);
            parser.setSourcePath(binaryid);
            sql = parser.processInsertsOnly();

            if (attributes & EvaluateProperties)
            {
                sql = msiInstall.GetFormattedString(sql);
            }
        } 

        if (! filename.empty())
        {
            if (basepath.empty())
            {
                basepath = AppSecInc::File::GetFileDirectoryW(filename);
            }
            combined_xml_document.AppendChild(L"Filename", combined_xml_odbcexecute_root)->text = _bstr_t(filename.c_str());
        }

        if (! outputfilename.empty())
        {
            combined_xml_document.AppendChild(L"OutputFilename", combined_xml_odbcexecute_root)->text = _bstr_t(outputfilename.c_str());
        }

        if (! sql.empty())
        {
            combined_xml_document.AppendChild(L"Sql", combined_xml_odbcexecute_root)->text = _bstr_t(sql.c_str());
        }

        combined_xml_document.AppendChild(L"ConnectionString", combined_xml_odbcexecute_root)->text = _bstr_t(connectionstring.c_str());
        combined_xml_document.AppendChild(L"Delimiter", combined_xml_odbcexecute_root)->text = _bstr_t(delimiter.c_str());
        combined_xml_document.AppendChild(L"Type", combined_xml_odbcexecute_root)->text = _bstr_t(sqltype.c_str());
        combined_xml_document.AppendChild(L"BasePath", combined_xml_odbcexecute_root)->text = _bstr_t(basepath.c_str());
    }

    std::wstring action = L"Execute_ODBC_Deferred_";
    action.append(msiInstall.IsInstalling() ? L"Install" : L"UnInstall");
    msiInstall.SetActionData(action, combined_xml_document.GetXml());

    MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall DataSource_ODBC_Immediate(MSIHANDLE hInstall)
{
    MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    typedef enum ODBCDataSourceAttributes
    {
        CreateOnInstall = 1,
        DeleteOnInstall = 2,
        CreateOnUnInstall = 4,
        DeleteOnUnInstall = 8,
        ConfigureOnInstall = 16,
        ConfigureOnUnInstall = 32,
    };

    std::wstring xml = msiInstall.GetViewData(L"SELECT * FROM `ODBCDataSourceConfig`");
    AppSecInc::Xml::XmlDocument xmlDocument;
    xmlDocument.LoadXml(xml);

    MSXML2::IXMLDOMNodeListPtr rows = xmlDocument.SelectNodes(L"//Row");
    MSXML2::IXMLDOMNodePtr row = NULL;
    while (NULL != (row = rows->nextNode()))
    {
        // id
        std::wstring id = xmlDocument.SelectNodeValue(L"Data[@Column=\"Id\"]", row, L"");
        // component id
        std::wstring component_id = xmlDocument.SelectNodeValue(L"Data[@Column=\"ComponentId\"]", row, L"");
        // node condition
        std::wstring condition = xmlDocument.SelectNodeValue(L"Data[@Column=\"Condition\"]", row);
        // operational attributes
        long attributes = AppSecInc::StringUtils::stringToLong(xmlDocument.SelectNodeValue(L"Data[@Column=\"Attributes\"]", row));
        // no condition (configures by default) or condition evaluates to true
        bool configure_per_condition = condition.empty() || msiInstall.EvaluateCondition(condition);
        // configure on install
        bool configure_per_component_install = (component_id.empty() || msiInstall.IsComponentInstalling(component_id));
        // configure on uninstall
        bool configure_per_component_uninstall = (component_id.empty() || msiInstall.IsComponentUnInstalling(component_id));

        bool create = configure_per_condition && (
            (configure_per_component_install && (attributes & CreateOnInstall) && msiInstall.IsInstalling()) 
            || (configure_per_component_uninstall && (attributes & CreateOnUnInstall) && msiInstall.IsUnInstalling())
            );

        bool remove = configure_per_condition && (
            (configure_per_component_install && (attributes & DeleteOnInstall) && msiInstall.IsInstalling()) 
            || (configure_per_component_uninstall && (attributes & DeleteOnUnInstall) && msiInstall.IsUnInstalling())
            );

        bool config = configure_per_condition && (
            (configure_per_component_install && (attributes & ConfigureOnInstall) && msiInstall.IsInstalling()) 
            || (configure_per_component_uninstall && (attributes & ConfigureOnUnInstall) && msiInstall.IsUnInstalling())
            );

        if (create) xmlDocument.SetAttribute(L"operation", L"create", row);
        else if (remove) xmlDocument.SetAttribute(L"operation", L"remove", row);
        else if (config) xmlDocument.SetAttribute(L"operation", L"config", row);
    }

    std::wstring action = L"DataSource_ODBC_Deferred_";
    action.append(msiInstall.IsInstalling() ? L"Install" : L"UnInstall");
    msiInstall.SetActionData(action, xmlDocument.GetXml());

    MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall DataSource_ODBC_Deferred(MSIHANDLE hInstall)
{
    MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    // process ODBC statements
    AppSecInc::Xml::XmlDocument xmlDocument;
    xmlDocument.LoadXml(msiInstall.GetActionData());

    MSXML2::IXMLDOMNodeListPtr rows = xmlDocument.SelectNodes(L"//Row");
    MSXML2::IXMLDOMNodePtr row = NULL;
    while (NULL != (row = rows->nextNode()))
    {
        std::wstring id = xmlDocument.SelectNodeValue(L"Data[@Column=\"Id\"]", row);
        std::wstring name = xmlDocument.SelectNodeValue(L"Data[@Column=\"Name\"]", row);
        std::wstring driver = xmlDocument.SelectNodeValue(L"Data[@Column=\"Driver\"]", row);
        std::wstring value = xmlDocument.SelectNodeValue(L"Data[@Column=\"Value\"]", row, L"");
        std::wstring type = xmlDocument.SelectNodeValue(L"Data[@Column=\"Type\"]", row, L"");
        std::wstring operation = xmlDocument.SelectAttributeValue(L"operation", row);

        // insert DSN name
        value.insert(0, L"DSN=" + name + L";");

        WORD request = 0;
        bool system = AppSecInc::StringUtils::comparei(type, L"system");
        if (operation == L"create") 
        {
            request = (system ? ODBC_ADD_SYS_DSN : ODBC_ADD_DSN);
            msiInstall.LogInfo(_T(__FUNCTION__), L"Creating " + type + L" DSN: " + name);
        }
        else if (operation == L"remove") 
        {
            request = (system ? ODBC_REMOVE_SYS_DSN : ODBC_REMOVE_DSN);
            msiInstall.LogInfo(_T(__FUNCTION__), L"Removing " + type + L" DSN: " + name);
        }
        else if (operation == L"config") 
        {
            request = (system ? ODBC_CONFIG_SYS_DSN : ODBC_CONFIG_DSN);
            msiInstall.LogInfo(_T(__FUNCTION__), L"Configuring " + type + L" DSN: " + name);
        }

        AppSecInc::Databases::ODBC::ODBCDataSource::Configure(
            request, driver, value);
    }

    MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}
