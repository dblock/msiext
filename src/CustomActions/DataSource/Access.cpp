#include "StdAfx.h"
#include "ConfigDataSource.h"
#include "Access.h"
#include "FlagMaps.h"

CA_API UINT __stdcall ConfigDataSource_Access(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);
    msiInstall.LogInfo(L"ConfigDataSource_Access", L"Microsoft Access DSN.");
    DSNAttributes attributes(hInstall);
    attributes.AddPropertyValue(L"DSN_NAME", L"DSN");
    attributes.AddPropertyValue(L"DSN_ACCESS_DBQ", L"DBQ");
    attributes.AddPropertyValue(L"DSN_ACCESS_UID", L"UID");
    attributes.AddPropertyValue(L"DSN_ACCESS_PWD", L"PWD");
    WORD flag = GetPropertyValue<FlagMapEntry[ARRAYSIZE(s_ODBCDSNFlags)], WORD>(msiInstall, L"ODBC_FLAG", s_ODBCDSNFlags);
    AppSecInc::Databases::ODBC::ODBCDataSource::Configure(flag, L"Microsoft Access Driver (*.MDB)", attributes.GetAttributes());
	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

typedef enum AccessDatabaseAttributes
{
    CreateOnInstall = 1,
    DropOnUnInstall = 2,
    DropOnInstall = 4,
    CreateOnUnInstall = 16,
    CheckIfExists = 32
};

CA_API UINT __stdcall CreateDatabases_Access_Deferred(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

	// process SQL databases
    std::wstring xml = msiInstall.GetActionData();
    AppSecInc::Xml::XmlDocument xmlDocument;
    xmlDocument.LoadXml(xml);
	
	// process Access databases
    MSXML2::IXMLDOMNodeListPtr rows = xmlDocument.SelectNodes(L"/AccessDatabases/AccessDatabase");
    MSXML2::IXMLDOMNodePtr row = NULL;
    while (NULL != (row = rows->nextNode()))
    {
        AppSecInc::Databases::Access::AccessDatabase database;
        database.Load(xmlDocument, row);

        std::wstring actions_s = xmlDocument.SelectAttributeValue(L"actions", row); // actions
		if (actions_s.empty())
		{
			msiInstall.LogInfo(L"CreateDatabases_Access", L"Skipping " + database.GetDBQ());
			continue;
		}

        bool checkIfExists = xmlDocument.SelectAttributeBoolValue(L"checkIfExists", row); // actions
        std::vector<std::wstring> actions; 
        AppSecInc::StringUtils::tokenize(actions_s, actions, L",");

        msiInstall.LogInfo(L"CreateDatabases_Access", database.GetDBQ());
        for each (const std::wstring action in actions)
        {
			if (action.empty())
				continue;

            msiInstall.LogInfo(L"CreateDatabases_Access", database.GetDBQ() + L": " + action);

            if (action == L"create" && ! checkIfExists) 
            {
                msiInstall.LogInfo(L"Create", database.GetDBQ());  
                database.Create();
            }
            else if (action == L"create" && checkIfExists) 
            {
                msiInstall.LogInfo(L"CreateIfNotExists", database.GetDBQ());  
                database.CreateIfNotExists();
            }
            else if (action == L"drop" && ! checkIfExists) 
            {
                msiInstall.LogInfo(L"Drop", database.GetDBQ());  
                database.Drop();
            }
            else if (action == L"drop" && checkIfExists) 
            {
                msiInstall.LogInfo(L"DropIfExists", database.GetDBQ());
                database.DropIfExists();
            }
        }
    }

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall CreateDatabases_Access_Immediate(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    // immediate custom action, evaluate conditions and update the custom action table data

	/* 
		This produces an xml like this:

		 <AccessDatabases>
		  <AccessDatabase>
		   <DBQ />
           <ConnectionString />
           ...
		  </AccessDatabase>
         </AccessDatabases>

	*/

	// combined xml document
	AppSecInc::Xml::XmlDocument combined_xml_document;
	combined_xml_document.Create();
	MSXML2::IXMLDOMNodePtr combined_xml_root = combined_xml_document.AppendChild(L"AccessDatabases");

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

	// databases
    AppSecInc::Xml::XmlDocument accessdatabase_xml_document;
    accessdatabase_xml_document.LoadXml(msiInstall.GetViewData(L"SELECT * FROM `AccessDatabase`"));
    MSXML2::IXMLDOMNodeListPtr accessdatabase_rows = accessdatabase_xml_document.SelectNodes(L"//Row");
    MSXML2::IXMLDOMNodePtr accessdatabase_row = NULL;
    while (NULL != (accessdatabase_row = accessdatabase_rows->nextNode()))
    {
		std::wstring accessdatabase_id = accessdatabase_xml_document.SelectNodeValue(L"Data[@Column=\"Id\"]", accessdatabase_row);
		std::wstring Accessdatabasecomponent_id = accessdatabase_xml_document.SelectNodeValue(L"Data[@Column=\"ComponentId\"]", accessdatabase_row, L"");

        // connection string
        std::wstring connectionstring = accessdatabase_xml_document.SelectNodeValue(L"Data[@Column=\"ConnectionStringId\"]", accessdatabase_row);
        connectionstring = connectionstring_map[connectionstring];

        // database object with options options
        AppSecInc::Databases::ODBC::ODBCConnectionStringInfo connection(connectionstring);
        AppSecInc::Databases::Access::AccessDatabase database(connection);
        database.SetDBQ(accessdatabase_xml_document.SelectNodeValue(L"Data[@Column=\"DBQ\"]", accessdatabase_row));

        // operational attributes
        long attributes = AppSecInc::StringUtils::stringToLong(accessdatabase_xml_document.SelectNodeValue(L"Data[@Column=\"Attributes\"]", accessdatabase_row));

        std::list<std::wstring> actions;

		bool installactions = (Accessdatabasecomponent_id.empty() && msiInstall.IsInstalling()) 
			|| (! Accessdatabasecomponent_id.empty() && msiInstall.IsComponentInstalling(Accessdatabasecomponent_id));
		bool uninstallactions = (Accessdatabasecomponent_id.empty() && msiInstall.IsUnInstalling()) 
			|| (! Accessdatabasecomponent_id.empty() && msiInstall.IsComponentUnInstalling(Accessdatabasecomponent_id));
		
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
        MSXML2::IXMLDOMNodePtr combined_xml_accessdatabase_root = database.Save(combined_xml_document, combined_xml_root);
        // add processing attributes
        combined_xml_document.SetAttribute(L"actions", AppSecInc::StringUtils::join(actions, L","), combined_xml_accessdatabase_root);
        combined_xml_document.SetAttribute(L"checkIfExists", checkIfExists, combined_xml_accessdatabase_root);
    }

    std::wstring action = L"CreateDatabases_Access_Deferred_";
    action.append(msiInstall.IsInstalling() ? L"Install" : L"UnInstall");
    msiInstall.SetActionData(action, combined_xml_document.GetXml());

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}
