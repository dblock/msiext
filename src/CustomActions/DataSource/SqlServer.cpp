#include "StdAfx.h"
#include "ConfigDataSource.h"
#include "SqlServer.h"
#include "FlagMaps.h"

CA_API UINT __stdcall ConfigDataSource_SQLServer(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);
    msiInstall.LogInfo(L"ConfigDataSource_SQLServer", L"Microsoft SQL DSN.");
    DSNAttributes attributes(hInstall);
    attributes.AddPropertyValue(L"DSN_NAME", L"DSN");
    attributes.AddPropertyValue(L"DSN_MSSQL_SERVER", L"Server");
    attributes.AddPropertyValue(L"DSN_MSSQL_DESCRIPTION", L"Description");
    attributes.AddPropertyValue(L"DSN_MSSQL_NETWORK", L"Network");
    attributes.AddPropertyValue(L"DSN_MSSQL_ADDRESS", L"Address");
    attributes.AddPropertyValue(L"DSN_MSSQL_DATABASE", L"Database");
    attributes.AddPropertyValue(L"DSN_MSSQL_TRUSTED_CONNECTION", L"Trusted_Connection");
    WORD flag = GetPropertyValue<FlagMapEntry[ARRAYSIZE(s_ODBCDSNFlags)], WORD>(msiInstall, L"ODBC_FLAG", s_ODBCDSNFlags);
    AppSecInc::Databases::ODBC::ODBCDataSource::Configure(flag, L"SQL Server", attributes.GetAttributes());
	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

typedef enum MSSQLDatabaseAttributes
{
    CreateOnInstall = 1,
    DropOnUnInstall = 2,
    DropOnInstall = 4,
    CreateOnUnInstall = 16,
    CheckIfExists = 32
};

CA_API UINT __stdcall CreateDatabases_SQLServer_Deferred(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

	// process SQL databases
    std::wstring xml = msiInstall.GetActionData();
    AppSecInc::Xml::XmlDocument xmlDocument;
    xmlDocument.LoadXml(xml);
	
	// process MSSQL databases
    MSXML2::IXMLDOMNodeListPtr rows = xmlDocument.SelectNodes(L"/MSSQLDatabases/MSSQLDatabase");
    MSXML2::IXMLDOMNodePtr row = NULL;
    while (NULL != (row = rows->nextNode()))
    {
        AppSecInc::Databases::MSSQL::MSSQLDatabase database;
        database.Load(xmlDocument, row);

        std::wstring actions_s = xmlDocument.GetAttributeValue(L"actions", row); // actions
		if (actions_s.empty())
		{
			msiInstall.LogInfo(L"CreateDatabases_SQLServer", L"Skipping " + database.GetName());
			continue;
		}

        bool checkIfExists = xmlDocument.GetAttributeBoolValue(L"checkIfExists", row); // actions
        std::vector<std::wstring> actions; 
        AppSecInc::StringUtils::tokenize(actions_s, actions, L",");

        msiInstall.LogInfo(L"CreateDatabases_SQLServer", database.GetName());
        for each (const std::wstring action in actions)
        {
			if (action.empty())
				continue;

            msiInstall.LogInfo(L"CreateDatabases_SQLServer", database.GetName() + L": " + action);
            database.Connect();

            if (action == L"create" && ! checkIfExists) 
            {
                msiInstall.LogInfo(L"Create", database.GetCreateQuery());  
                database.Create();
            }
            else if (action == L"create" && checkIfExists) 
            {
                msiInstall.LogInfo(L"CreateIfNotExists", database.GetNotExistsQuery() + L" " + database.GetCreateQuery());  
                database.CreateIfNotExists();
            }
            else if (action == L"drop" && ! checkIfExists) 
            {
                msiInstall.LogInfo(L"Drop", database.GetDropQuery());  
                database.Drop();
            }
            else if (action == L"drop" && checkIfExists) 
            {
                msiInstall.LogInfo(L"DropIfExists", database.GetExistsQuery() + L" " + database.GetDropQuery());  
                database.DropIfExists();
            }
        }
    }

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall CreateDatabases_SQLServer_Immediate(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    // immediate custom action, evaluate conditions and update the custom action table data

	/* 
		This produces an xml like this:

		 <MSSQLDatabases>
		  <MSSQLDatabase>
		   <Name />
           <Attributes />
           <ConnectionString />
           ...
		  </MSSQLDatabase>
         </MSSQLDatabases>

	*/

	// combined xml document
	AppSecInc::Xml::XmlDocument combined_xml_document;
	combined_xml_document.Create();
	MSXML2::IXMLDOMNodePtr combined_xml_root = combined_xml_document.AppendChild(L"MSSQLDatabases");

	// connection strings
    AppSecInc::Xml::XmlDocument connectionstring_xml_document;
    connectionstring_xml_document.LoadXml(msiInstall.GetViewData(L"SELECT * FROM `DatabaseConnectionString`"));
    std::map<std::wstring, std::wstring> connectionstring_map;
    MSXML2::IXMLDOMNodeListPtr connectionstring_rows = connectionstring_xml_document.SelectNodes(L"//Row");
    MSXML2::IXMLDOMNodePtr connectionstring_row = NULL;
    while (NULL != (connectionstring_row = connectionstring_rows->nextNode()))
    {
		std::wstring connectionstring_id = connectionstring_xml_document.GetNodeValue(L"Data[@Column=\"Id\"]", connectionstring_row);
        std::wstring connectionstring = connectionstring_xml_document.GetNodeValue(L"Data[@Column=\"ConnectionString\"]", connectionstring_row);
        connectionstring_map.insert(std::pair<std::wstring, std::wstring>(connectionstring_id, connectionstring));
    }

    // database options
    AppSecInc::Xml::XmlDocument mssqldatabaseoption_xml_document;
    mssqldatabaseoption_xml_document.LoadXml(msiInstall.GetViewData(L"SELECT * FROM `MSSQLDatabaseOption`"));
    std::map<std::wstring, std::list<std::wstring>> mssqldatabaseoption_map;
    MSXML2::IXMLDOMNodeListPtr mssqldatabaseoption_rows = mssqldatabaseoption_xml_document.SelectNodes(L"//Row");
    MSXML2::IXMLDOMNodePtr mssqldatabaseoption_row = NULL;
    while (NULL != (mssqldatabaseoption_row = mssqldatabaseoption_rows->nextNode()))
    {
	    std::wstring mssqldatabaseoption_id = mssqldatabaseoption_xml_document.GetNodeValue(L"Data[@Column=\"Id\"]", mssqldatabaseoption_row);
        std::wstring mssqldatabaseoption_mssqldatabase = mssqldatabaseoption_xml_document.GetNodeValue(L"Data[@Column=\"MSSQLDatabaseId\"]", mssqldatabaseoption_row);
        std::wstring mssqldatabaseoption_value = mssqldatabaseoption_xml_document.GetNodeValue(L"Data[@Column=\"Value\"]", mssqldatabaseoption_row);
        mssqldatabaseoption_map[mssqldatabaseoption_mssqldatabase].push_back(mssqldatabaseoption_value);
    }

    // database file specs
    AppSecInc::Xml::XmlDocument mssqldatabasefilespec_xml_document;
    mssqldatabasefilespec_xml_document.LoadXml(msiInstall.GetViewData(L"SELECT * FROM `MSSQLDatabaseFileSpec`"));
    std::map<std::wstring, std::list<AppSecInc::Databases::MSSQL::MSSQLDatabaseFileSpec>> mssqldatabasefilespec_map;
    MSXML2::IXMLDOMNodeListPtr mssqldatabasefilespec_rows = mssqldatabasefilespec_xml_document.SelectNodes(L"//Row");
    MSXML2::IXMLDOMNodePtr mssqldatabasefilespec_row = NULL;
    while (NULL != (mssqldatabasefilespec_row = mssqldatabasefilespec_rows->nextNode()))
    {
        AppSecInc::Databases::MSSQL::MSSQLDatabaseFileSpec filespec;
	    std::wstring mssqldatabasefilespec_id = mssqldatabasefilespec_xml_document.GetNodeValue(L"Data[@Column=\"Id\"]", mssqldatabasefilespec_row);
        std::wstring mssqldatabasefilespec_mssqldatabase = mssqldatabasefilespec_xml_document.GetNodeValue(L"Data[@Column=\"MSSQLDatabaseId\"]", mssqldatabasefilespec_row);
        filespec.SetName(mssqldatabasefilespec_xml_document.GetNodeValue(L"Data[@Column=\"Name\"]", mssqldatabasefilespec_row));
        filespec.SetFilename(mssqldatabasefilespec_xml_document.GetNodeValue(L"Data[@Column=\"Filename\"]", mssqldatabasefilespec_row));
        filespec.SetType(mssqldatabasefilespec_xml_document.GetNodeValue(L"Data[@Column=\"Type\"]", mssqldatabasefilespec_row));
        filespec.SetSize(mssqldatabasefilespec_xml_document.GetNodeValue(L"Data[@Column=\"Size\"]", mssqldatabasefilespec_row));
        filespec.SetMaxSize(mssqldatabasefilespec_xml_document.GetNodeValue(L"Data[@Column=\"MaxSize\"]", mssqldatabasefilespec_row));
        filespec.SetGrowthSize(mssqldatabasefilespec_xml_document.GetNodeValue(L"Data[@Column=\"GrowthSize\"]", mssqldatabasefilespec_row));
        mssqldatabasefilespec_map[mssqldatabasefilespec_mssqldatabase].push_back(filespec);
    }

	// databases
    AppSecInc::Xml::XmlDocument mssqldatabase_xml_document;
    mssqldatabase_xml_document.LoadXml(msiInstall.GetViewData(L"SELECT * FROM `MSSQLDatabase`"));
    MSXML2::IXMLDOMNodeListPtr mssqldatabase_rows = mssqldatabase_xml_document.SelectNodes(L"//Row");
    MSXML2::IXMLDOMNodePtr mssqldatabase_row = NULL;
    while (NULL != (mssqldatabase_row = mssqldatabase_rows->nextNode()))
    {
		std::wstring mssqldatabase_id = mssqldatabase_xml_document.GetNodeValue(L"Data[@Column=\"Id\"]", mssqldatabase_row);
		std::wstring mssqldatabasecomponent_id = mssqldatabase_xml_document.GetNodeValue(L"Data[@Column=\"ComponentId\"]", mssqldatabase_row, L"");

        // connection string
        std::wstring connectionstring = mssqldatabase_xml_document.GetNodeValue(L"Data[@Column=\"ConnectionStringId\"]", mssqldatabase_row);
        connectionstring = connectionstring_map[connectionstring];

        // database object with options options
        AppSecInc::Databases::ODBC::ODBCConnectionStringInfo connection(connectionstring);
        AppSecInc::Databases::MSSQL::MSSQLDatabase database(connection);
        database.SetName(mssqldatabase_xml_document.GetNodeValue(L"Data[@Column=\"Name\"]", mssqldatabase_row));
        database.SetCollate(mssqldatabase_xml_document.GetNodeValue(L"Data[@Column=\"Collate\"]", mssqldatabase_row));
        database.SetPurpose(mssqldatabase_xml_document.GetNodeValue(L"Data[@Column=\"Purpose\"]", mssqldatabase_row));

        // database options
        for each (const std::wstring& option in mssqldatabaseoption_map[mssqldatabase_id])
            database.AddOption(option);

        // file specs
        for each (const AppSecInc::Databases::MSSQL::MSSQLDatabaseFileSpec& filespec in mssqldatabasefilespec_map[mssqldatabase_id])
            database.AddFileSpec(filespec);

        // operational attributes
        long attributes = AppSecInc::StringUtils::stringToLong(mssqldatabase_xml_document.GetNodeValue(L"Data[@Column=\"Attributes\"]", mssqldatabase_row));

        std::list<std::wstring> actions;

		bool installactions = (mssqldatabasecomponent_id.empty() && msiInstall.IsInstalling()) 
			|| (! mssqldatabasecomponent_id.empty() && msiInstall.IsComponentInstalling(mssqldatabasecomponent_id));
		bool uninstallactions = (mssqldatabasecomponent_id.empty() && msiInstall.IsUnInstalling()) 
			|| (! mssqldatabasecomponent_id.empty() && msiInstall.IsComponentUnInstalling(mssqldatabasecomponent_id));
		
		if (installactions)
		{
			if (attributes & DropOnInstall) actions.push_back(L"drop");
			if (attributes & CreateOnInstall) actions.push_back(L"create");
		}
		else if (uninstallactions)
		{
			if (attributes & DropOnUnInstall) actions.push_back(L"drop");
			if (attributes & CreateOnUnInstall) actions.push_back(L"create");
		}

        std::wstring checkIfExists = (attributes & CheckIfExists ? L"true" : L"false"); 

        // write the database to xml
        MSXML2::IXMLDOMNodePtr combined_xml_mssqldatabase_root = database.Save(combined_xml_document, combined_xml_root);
        // add processing attributes
        combined_xml_document.SetAttribute(L"actions", AppSecInc::StringUtils::join(actions, L","), combined_xml_mssqldatabase_root);
        combined_xml_document.SetAttribute(L"checkIfExists", checkIfExists, combined_xml_mssqldatabase_root);
    }

    std::wstring action = L"CreateDatabases_SQLServer_Deferred_";
    action.append(msiInstall.IsInstalling() ? L"Install" : L"UnInstall");
    msiInstall.SetActionData(action, combined_xml_document.GetXml());

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall DataFile_SQLServer_Immediate(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    typedef enum DataFileSQLServerAttributes
    {
        ExecuteOnInstall = 1,
        ExecuteOnUnInstall = 2,
        ExecuteOnReInstall = 4,
        EvaluateProperties = 8
    };

	AppSecInc::Xml::XmlDocument combined_xml_document;
	combined_xml_document.Create();
    // root node of the combined xml document
	MSXML2::IXMLDOMNodePtr combined_xml_root = combined_xml_document.AppendChild(L"MSSQLDataFiles");

	// connection strings
    AppSecInc::Xml::XmlDocument connectionstring_xml_document;
    connectionstring_xml_document.LoadXml(msiInstall.GetViewData(L"SELECT * FROM `DatabaseConnectionString`"));
    std::map<std::wstring, std::wstring> connectionstring_map;
    MSXML2::IXMLDOMNodeListPtr connectionstring_rows = connectionstring_xml_document.SelectNodes(L"//Row");
    MSXML2::IXMLDOMNodePtr connectionstring_row = NULL;
    while (NULL != (connectionstring_row = connectionstring_rows->nextNode()))
    {
		std::wstring connectionstring_id = connectionstring_xml_document.GetNodeValue(L"Data[@Column=\"Id\"]", connectionstring_row);
        std::wstring connectionstring = connectionstring_xml_document.GetNodeValue(L"Data[@Column=\"ConnectionString\"]", connectionstring_row);
        connectionstring_map.insert(std::pair<std::wstring, std::wstring>(connectionstring_id, connectionstring));
    }

	// data file parameters
    AppSecInc::Xml::XmlDocument mssqldatafileparameter_xml_document;
    mssqldatafileparameter_xml_document.LoadXml(msiInstall.GetViewData(L"SELECT * FROM `MSSQLDataFileParameter`"));
    std::map<std::wstring, std::list<std::wstring>> mssqldatafileparameter_map;
    MSXML2::IXMLDOMNodeListPtr mssqldatafileparameter_rows = mssqldatafileparameter_xml_document.SelectNodes(L"//Row");
    MSXML2::IXMLDOMNodePtr mssqldatafileparameter_row = NULL;
    while (NULL != (mssqldatafileparameter_row = mssqldatafileparameter_rows->nextNode()))
    {
	    std::wstring mssqldatafileparameter_id = mssqldatafileparameter_xml_document.GetNodeValue(L"Data[@Column=\"Id\"]", mssqldatafileparameter_row);
        std::wstring mssqldatafileparameter_mssqldatafile = mssqldatafileparameter_xml_document.GetNodeValue(L"Data[@Column=\"MSSQLDataFileId\"]", mssqldatafileparameter_row);
        std::wstring mssqldatafileparameter_value = mssqldatafileparameter_xml_document.GetNodeValue(L"Data[@Column=\"Value\"]", mssqldatafileparameter_row);
        mssqldatafileparameter_map[mssqldatafileparameter_mssqldatafile].push_back(mssqldatafileparameter_value);
    }
    
	// MSSQL BULK INSERT statements
    AppSecInc::Xml::XmlDocument mssqldatafile_xml_document;
    mssqldatafile_xml_document.LoadXml(msiInstall.GetViewData(L"SELECT * FROM `MSSQLDataFile`"));
    MSXML2::IXMLDOMNodeListPtr mssqldatafile_rows = mssqldatafile_xml_document.SelectNodes(L"//Row");
    MSXML2::IXMLDOMNodePtr mssqldatafile_row = NULL;
    while (NULL != (mssqldatafile_row = mssqldatafile_rows->nextNode()))
    {
		std::wstring mssqldatafile_id = mssqldatafile_xml_document.GetNodeValue(L"Data[@Column=\"Id\"]", mssqldatafile_row);
		std::wstring mssqldatafilecomponent_id = mssqldatafile_xml_document.GetNodeValue(L"Data[@Column=\"ComponentId\"]", mssqldatafile_row, L"");
        // connection string
        std::wstring connectionstring = mssqldatafile_xml_document.GetNodeValue(L"Data[@Column=\"ConnectionStringId\"]", mssqldatafile_row);
        connectionstring = connectionstring_map[connectionstring];
        std::wstring database = mssqldatafile_xml_document.GetNodeValue(L"Data[@Column=\"Database\"]", mssqldatafile_row, L"");
        std::wstring schema = mssqldatafile_xml_document.GetNodeValue(L"Data[@Column=\"Schema\"]", mssqldatafile_row, L"");
        std::wstring table = mssqldatafile_xml_document.GetNodeValue(L"Data[@Column=\"Table\"]", mssqldatafile_row, L"");
        std::wstring filename = mssqldatafile_xml_document.GetNodeValue(L"Data[@Column=\"Filename\"]", mssqldatafile_row, L"");
        std::wstring binaryid = mssqldatafile_xml_document.GetNodeValue(L"Data[@Column=\"BinaryId\"]", mssqldatafile_row, L"");
        std::wstring condition = mssqldatafile_xml_document.GetNodeValue(L"Data[@Column=\"Condition\"]", mssqldatafile_row);
        // operational attributes
        long attributes = AppSecInc::StringUtils::stringToLong(mssqldatafile_xml_document.GetNodeValue(L"Data[@Column=\"Attributes\"]", mssqldatafile_row));

        // no condition (executes by default) or condition evaluates to true
        bool execute_per_condition = condition.empty() || msiInstall.EvaluateCondition(condition);
        // execute on install
        bool execute_per_component_install = (mssqldatafilecomponent_id.empty() || msiInstall.IsComponentInstalling(mssqldatafilecomponent_id));
        // execute on uninstall
        bool execute_per_component_uninstall = (mssqldatafilecomponent_id.empty() || msiInstall.IsComponentUnInstalling(mssqldatafilecomponent_id));

        bool execute = execute_per_condition && (
            (execute_per_component_install && (attributes & ExecuteOnInstall) && msiInstall.IsInstalling()) 
            || (execute_per_component_uninstall && (attributes & ExecuteOnUnInstall) && msiInstall.IsUnInstalling())
            );

        // write the odbc query to xml
        MSXML2::IXMLDOMNodePtr combined_xml_mssqldatafile_root = combined_xml_document.AppendChild(L"MSSQLDataFile", combined_xml_root);
        combined_xml_document.SetAttribute(L"execute", execute ? L"true" : L"false", combined_xml_mssqldatafile_root);
        combined_xml_document.SetAttribute(L"id", mssqldatafile_id, combined_xml_mssqldatafile_root);
        
        // fetch the contents of the binary as SQL
        if (! binaryid.empty() && execute)
        {
            std::vector<char> data;
            msiInstall.GetBinaryData(binaryid, data);
            // store the binary file on disk
            filename = AppSecInc::File::GetTemporaryFileNameW();
            // evaluate properties for binary files
            if (attributes & EvaluateProperties)
            {
                // \todo This assumes UTF-8/RAW encoding of the file, add an attribute and process accordingly
                std::string char_data(& * data.begin(), data.size());
                std::wstring sql = AppSecInc::StringUtils::mb2wc(char_data);
                if (attributes & EvaluateProperties)
                {
                    sql = msiInstall.GetFormattedString(sql);
                }
                char_data = AppSecInc::StringUtils::wc2mb(sql);
                data.assign(char_data.begin(), char_data.end());
            }
            // write the data to a temporary file
            AppSecInc::File::FileWrite(filename, data);
            // set a property so to rememember to delete the temporary binary file
            combined_xml_document.SetAttribute(L"deleteAfterExecute", L"true", combined_xml_mssqldatafile_root);
        }
        else
        {
            combined_xml_document.SetAttribute(L"deleteAfterExecute", L"false", combined_xml_mssqldatafile_root);
        }

        combined_xml_document.AppendChild(L"Filename", combined_xml_mssqldatafile_root)->text = _bstr_t(filename.c_str());
        combined_xml_document.AppendChild(L"Database", combined_xml_mssqldatafile_root)->text = _bstr_t(database.c_str());
        combined_xml_document.AppendChild(L"Schema", combined_xml_mssqldatafile_root)->text = _bstr_t(schema.c_str());
        combined_xml_document.AppendChild(L"Table", combined_xml_mssqldatafile_root)->text = _bstr_t(table.c_str());
        combined_xml_document.AppendChild(L"ConnectionString", combined_xml_mssqldatafile_root)->text = _bstr_t(connectionstring.c_str());

        // append parameters
        MSXML2::IXMLDOMNodePtr parameters_node = combined_xml_document.AppendChild(L"MSSQLDataFileParameters", combined_xml_mssqldatafile_root);
        for each (const std::wstring& parameter in mssqldatafileparameter_map[mssqldatafile_id])
        {
            combined_xml_document.AppendChild(L"MSSQLDataFileParameter", parameters_node)->text = _bstr_t(parameter.c_str());
        }
    }

    std::wstring action = L"DataFile_SQLServer_Deferred_";
    action.append(msiInstall.IsInstalling() ? L"Install" : L"UnInstall");
    msiInstall.SetActionData(action, combined_xml_document.GetXml());

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall DataFile_SQLServer_Deferred(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

	// process SQL databases
    std::wstring xml = msiInstall.GetActionData();
    AppSecInc::Xml::XmlDocument xmlDocument;
    xmlDocument.LoadXml(xml);
	
	// process MSSQL databases
    MSXML2::IXMLDOMNodeListPtr rows = xmlDocument.SelectNodes(L"/MSSQLDataFiles/MSSQLDataFile");
    MSXML2::IXMLDOMNodePtr row = NULL;
    while (NULL != (row = rows->nextNode()))
    {
        bool execute = xmlDocument.GetAttributeBoolValue(L"execute", row);
        bool deleteAfterExecute = xmlDocument.GetAttributeBoolValue(L"deleteAfterExecute", row);
        
        if (execute)
        {
            AppSecInc::Databases::MSSQL::MSSQLDataFile datafile;
            datafile.Load(xmlDocument, row);
            msiInstall.LogInfo(_T(__FUNCTION__), datafile.GetInsertQuery());
            std::wstring connection_string = xmlDocument.GetNodeValue(L"ConnectionString", row);
            msiInstall.LogInfo(_T(__FUNCTION__), datafile.GetInsertQuery());
            AppSecInc::Databases::ODBC::ODBCConnectionStringInfo connection_info(connection_string);
            AppSecInc::Databases::ODBC::ODBCConnection connection;
            connection.Connect(connection_info);
            connection.Execute(datafile.GetInsertQuery());

            if (deleteAfterExecute) 
            {
                AppSecInc::File::FileDelete(datafile.GetFilename());
            }
        }
    }

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}
