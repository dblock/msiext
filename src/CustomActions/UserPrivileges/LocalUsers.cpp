#include "StdAfx.h"
#include "LocalUsers.h"

CA_API UINT __stdcall LocalUsers_Immediate(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    typedef enum LocalUserAttributes
    {
        CreateOnInstall = 1,
        CreateOnUnInstall = 2,
        DeleteOnInstall = 4,
        DeleteOnUnInstall = 8,
        CheckIfExists = 16
    };

	// combined xml document
	AppSecInc::Xml::XmlDocument combined_xml_document;
	combined_xml_document.Create();
	MSXML2::IXMLDOMNodePtr combined_xml_root = combined_xml_document.AppendChild(L"LocalUsers");

	// local users
    AppSecInc::Xml::XmlDocument localusers_xml_document;
    localusers_xml_document.LoadXml(msiInstall.GetViewData(L"SELECT * FROM `LocalUsers`"));
    MSXML2::IXMLDOMNodeListPtr localusers_rows = localusers_xml_document.SelectNodes(L"//Row");
    MSXML2::IXMLDOMNodePtr localusers_row = NULL;
    while (NULL != (localusers_row = localusers_rows->nextNode()))
    {
		std::wstring localusers_id = localusers_xml_document.SelectNodeValue(L"Data[@Column=\"Id\"]", localusers_row);
		std::wstring localuserscomponent_id = localusers_xml_document.SelectNodeValue(L"Data[@Column=\"ComponentId\"]", localusers_row, L"");
        std::wstring username = localusers_xml_document.SelectNodeValue(L"Data[@Column=\"Username\"]", localusers_row);
        std::wstring password = localusers_xml_document.SelectNodeValue(L"Data[@Column=\"Password\"]", localusers_row, L"");
        long attributes = AppSecInc::StringUtils::stringToLong(localusers_xml_document.SelectNodeValue(L"Data[@Column=\"Attributes\"]", localusers_row));

        // execute on install
        bool execute_per_component_install = (localuserscomponent_id.empty() || msiInstall.IsComponentInstalling(localuserscomponent_id));
        // execute on uninstall
        bool execute_per_component_uninstall = (localuserscomponent_id.empty() || msiInstall.IsComponentUnInstalling(localuserscomponent_id));

        bool create_user = (
            (execute_per_component_install && (attributes & CreateOnInstall) && msiInstall.IsInstalling()) 
            || (execute_per_component_uninstall && (attributes & CreateOnUnInstall) && msiInstall.IsUnInstalling())
            );

        bool delete_user = (
            (execute_per_component_install && (attributes & DeleteOnInstall) && msiInstall.IsInstalling()) 
            || (execute_per_component_uninstall && (attributes & DeleteOnUnInstall) && msiInstall.IsUnInstalling())
            );

        // write the odbc query to xml
        MSXML2::IXMLDOMNodePtr combined_xml_localusers_root = combined_xml_document.AppendChild(L"LocalUser", combined_xml_root);
        combined_xml_document.SetAttribute(L"create", create_user ? L"true" : L"false", combined_xml_localusers_root);
        combined_xml_document.SetAttribute(L"delete", delete_user ? L"true" : L"false", combined_xml_localusers_root);
        combined_xml_document.SetAttribute(L"check", (attributes & CheckIfExists) ? L"true" : L"false", combined_xml_localusers_root);
        combined_xml_document.SetAttribute(L"id", localusers_id, combined_xml_localusers_root);
        combined_xml_document.AppendChild(L"Username", combined_xml_localusers_root)->text = _bstr_t(username.c_str());
        combined_xml_document.AppendChild(L"Password", combined_xml_localusers_root)->text = _bstr_t(password.c_str());
    }

    msiInstall.SetActionData(L"CreateLocalUsers_Deferred", combined_xml_document.GetXml());
    msiInstall.SetActionData(L"DeleteLocalUsers_Deferred", combined_xml_document.GetXml());

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall LocalUsers_Deferred(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    AppSecInc::Xml::XmlDocument xmlDocument;
    xmlDocument.LoadXml(msiInstall.GetActionData());

    MSXML2::IXMLDOMNodeListPtr rows = xmlDocument.SelectNodes(L"/LocalUsers/LocalUser");
    MSXML2::IXMLDOMNodePtr row = NULL;
    while (NULL != (row = rows->nextNode()))
    {
        std::wstring id = xmlDocument.SelectAttributeValue(L"id", row);
        std::wstring username = xmlDocument.SelectNodeValue(L"Username", row);
        std::wstring password = xmlDocument.SelectNodeValue(L"Password", row, L"");
        bool create_user = xmlDocument.SelectAttributeBoolValue(L"create", row);
        bool delete_user = xmlDocument.SelectAttributeBoolValue(L"delete", row);
        bool check = xmlDocument.SelectAttributeBoolValue(L"check", row);

        if (delete_user && (! check || AppSecInc::LSA::Account::Exists(username)))
        {
            msiInstall.LogInfo(_T(__FUNCTION__), L"Deleting user \"" + username + L"\"");
            AppSecInc::LSA::Account::Delete(username);
        }

        if (create_user && (! check || ! AppSecInc::LSA::Account::Exists(username)))
        {
            msiInstall.LogInfo(_T(__FUNCTION__), L"Creating user \"" + username + L"\"");
            AppSecInc::LSA::Account::Create(username, password);
        }
    }

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}
