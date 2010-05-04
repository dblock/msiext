#include "StdAfx.h"
#include "LocalGroups.h"

CA_API UINT __stdcall LocalGroups_Immediate(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    typedef enum LocalGroupAttributes
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
	MSXML2::IXMLDOMNodePtr combined_xml_root = combined_xml_document.AppendChild(L"LocalGroups");

	// local groups
    AppSecInc::Xml::XmlDocument localgroups_xml_document;
    localgroups_xml_document.LoadXml(msiInstall.GetViewData(L"SELECT * FROM `LocalGroups`"));
    MSXML2::IXMLDOMNodeListPtr localgroups_rows = localgroups_xml_document.SelectNodes(L"//Row");
    MSXML2::IXMLDOMNodePtr localgroups_row = NULL;
    while (NULL != (localgroups_row = localgroups_rows->nextNode()))
    {
		std::wstring localgroups_id = localgroups_xml_document.GetNodeValue(L"Data[@Column=\"Id\"]", localgroups_row);
		std::wstring localgroupscomponent_id = localgroups_xml_document.GetNodeValue(L"Data[@Column=\"ComponentId\"]", localgroups_row, L"");
        std::wstring name = localgroups_xml_document.GetNodeValue(L"Data[@Column=\"Name\"]", localgroups_row);
        std::wstring description = localgroups_xml_document.GetNodeValue(L"Data[@Column=\"Description\"]", localgroups_row, L"");
        long attributes = AppSecInc::StringUtils::stringToLong(localgroups_xml_document.GetNodeValue(L"Data[@Column=\"Attributes\"]", localgroups_row));

        // execute on install
        bool execute_per_component_install = (localgroupscomponent_id.empty() || msiInstall.IsComponentInstalling(localgroupscomponent_id));
        // execute on uninstall
        bool execute_per_component_uninstall = (localgroupscomponent_id.empty() || msiInstall.IsComponentUnInstalling(localgroupscomponent_id));

        bool create_group = (
            (execute_per_component_install && (attributes & CreateOnInstall) && msiInstall.IsInstalling()) 
            || (execute_per_component_uninstall && (attributes & CreateOnUnInstall) && msiInstall.IsUnInstalling())
            );

        bool delete_group = (
            (execute_per_component_install && (attributes & DeleteOnInstall) && msiInstall.IsInstalling()) 
            || (execute_per_component_uninstall && (attributes & DeleteOnUnInstall) && msiInstall.IsUnInstalling())
            );

        // write the odbc query to xml
        MSXML2::IXMLDOMNodePtr combined_xml_localgroups_root = combined_xml_document.AppendChild(L"LocalGroup", combined_xml_root);
        combined_xml_document.SetAttribute(L"create", create_group ? L"true" : L"false", combined_xml_localgroups_root);
        combined_xml_document.SetAttribute(L"delete", delete_group ? L"true" : L"false", combined_xml_localgroups_root);
        combined_xml_document.SetAttribute(L"check", (attributes & CheckIfExists) ? L"true" : L"false", combined_xml_localgroups_root);
        combined_xml_document.SetAttribute(L"id", localgroups_id, combined_xml_localgroups_root);
        combined_xml_document.AppendChild(L"Name", combined_xml_localgroups_root)->text = _bstr_t(name.c_str());
        combined_xml_document.AppendChild(L"Description", combined_xml_localgroups_root)->text = _bstr_t(description.c_str());
    }

    msiInstall.SetActionData(L"CreateLocalGroups_Deferred", combined_xml_document.GetXml());
    msiInstall.SetActionData(L"DeleteLocalGroups_Deferred", combined_xml_document.GetXml());

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall LocalGroups_Deferred(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    AppSecInc::Xml::XmlDocument xmlDocument;
    xmlDocument.LoadXml(msiInstall.GetActionData());

    MSXML2::IXMLDOMNodeListPtr rows = xmlDocument.SelectNodes(L"/LocalGroups/LocalGroup");
    MSXML2::IXMLDOMNodePtr row = NULL;
    while (NULL != (row = rows->nextNode()))
    {
        std::wstring id = xmlDocument.GetAttributeValue(L"id", row);
        std::wstring name = xmlDocument.GetNodeValue(L"Name", row);
        std::wstring description = xmlDocument.GetNodeValue(L"Description", row, L"");
        bool create_group = xmlDocument.GetAttributeBoolValue(L"create", row);
        bool delete_group = xmlDocument.GetAttributeBoolValue(L"delete", row);
        bool check = xmlDocument.GetAttributeBoolValue(L"check", row);

        if (delete_group && (! check || AppSecInc::LSA::LocalGroup::Exists(name)))
        {
            msiInstall.LogInfo(_T(__FUNCTION__), L"Deleting local group \"" + name + L"\"");
            AppSecInc::LSA::LocalGroup::Delete(name);
        }

        if (create_group && (! check || ! AppSecInc::LSA::LocalGroup::Exists(name)))
        {
            msiInstall.LogInfo(_T(__FUNCTION__), L"Creating local group \"" + name + L"\"");
            GROUP_INFO_1 gi = { 0 };
            gi.grpi1_name = const_cast<LPWSTR>(name.c_str());
            gi.grpi1_comment = const_cast<LPWSTR>(description.c_str());
            AppSecInc::LSA::LocalGroup::Create(gi);
        }
    }

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}
