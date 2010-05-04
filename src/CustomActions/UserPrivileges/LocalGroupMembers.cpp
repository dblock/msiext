#include "StdAfx.h"
#include "LocalGroupMembers.h"

CA_API UINT __stdcall LocalGroupMembers_Immediate(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    typedef enum LocalGroupMemberAttributes
    {
        AddOnInstall = 1,
        AddOnUnInstall = 2,
        RemoveOnInstall = 4,
        RemoveOnUnInstall = 8,
        CheckIfMember = 16
    };

    // local groups
    std::map<std::wstring, std::wstring> localgroups_map;
    AppSecInc::Xml::XmlDocument localgroups_xml_document;
    localgroups_xml_document.LoadXml(msiInstall.GetViewData(L"SELECT * FROM `LocalGroups`"));
    MSXML2::IXMLDOMNodeListPtr localgroups_rows = localgroups_xml_document.SelectNodes(L"//Row");
    MSXML2::IXMLDOMNodePtr localgroups_row = NULL;
    while (NULL != (localgroups_row = localgroups_rows->nextNode()))
    {
		std::wstring localgroup_id = localgroups_xml_document.GetNodeValue(L"Data[@Column=\"Id\"]", localgroups_row);
        std::wstring localgroup_name = localgroups_xml_document.GetNodeValue(L"Data[@Column=\"Name\"]", localgroups_row);
        localgroups_map[localgroup_id] = localgroup_name;
    }

    // local users
    std::map<std::wstring, std::wstring> localusers_map;
    AppSecInc::Xml::XmlDocument localusers_xml_document;
    localusers_xml_document.LoadXml(msiInstall.GetViewData(L"SELECT * FROM `LocalUsers`"));
    MSXML2::IXMLDOMNodeListPtr localusers_rows = localusers_xml_document.SelectNodes(L"//Row");
    MSXML2::IXMLDOMNodePtr localusers_row = NULL;
    while (NULL != (localusers_row = localusers_rows->nextNode()))
    {
		std::wstring localuser_id = localusers_xml_document.GetNodeValue(L"Data[@Column=\"Id\"]", localusers_row);
        std::wstring localuser_username = localusers_xml_document.GetNodeValue(L"Data[@Column=\"Username\"]", localusers_row);
        localusers_map[localuser_id] = localuser_username;
    }

	// combined xml document
	AppSecInc::Xml::XmlDocument combined_xml_document;
	combined_xml_document.Create();
	MSXML2::IXMLDOMNodePtr combined_xml_root = combined_xml_document.AppendChild(L"LocalGroupMembers");

	// local groups
    AppSecInc::Xml::XmlDocument localgroupmembers_xml_document;
    localgroupmembers_xml_document.LoadXml(msiInstall.GetViewData(L"SELECT * FROM `LocalGroupMembers`"));
    MSXML2::IXMLDOMNodeListPtr localgroupmembers_rows = localgroupmembers_xml_document.SelectNodes(L"//Row");
    MSXML2::IXMLDOMNodePtr localgroupmembers_row = NULL;
    while (NULL != (localgroupmembers_row = localgroupmembers_rows->nextNode()))
    {
		std::wstring localgroupmembers_id = localgroupmembers_xml_document.GetNodeValue(L"Data[@Column=\"Id\"]", localgroupmembers_row);
		std::wstring localgroupmemberscomponent_id = localgroupmembers_xml_document.GetNodeValue(L"Data[@Column=\"ComponentId\"]", localgroupmembers_row, L"");
        std::wstring localuser_id = localgroupmembers_xml_document.GetNodeValue(L"Data[@Column=\"LocalUserId\"]", localgroupmembers_row);
        std::wstring username = localusers_map[localuser_id];
        std::wstring localgroup_id = localgroupmembers_xml_document.GetNodeValue(L"Data[@Column=\"LocalGroupId\"]", localgroupmembers_row, L"");
        std::wstring groupname = localgroups_map[localgroup_id];
        long attributes = AppSecInc::StringUtils::stringToLong(localgroupmembers_xml_document.GetNodeValue(L"Data[@Column=\"Attributes\"]", localgroupmembers_row));

        // execute on install
        bool execute_per_component_install = (localgroupmemberscomponent_id.empty() || msiInstall.IsComponentInstalling(localgroupmemberscomponent_id));
        // execute on uninstall
        bool execute_per_component_uninstall = (localgroupmemberscomponent_id.empty() || msiInstall.IsComponentUnInstalling(localgroupmemberscomponent_id));

        bool add_member = (
            (execute_per_component_install && (attributes & AddOnInstall) && msiInstall.IsInstalling()) 
            || (execute_per_component_uninstall && (attributes & AddOnUnInstall) && msiInstall.IsUnInstalling())
            );

        bool remove_member = (
            (execute_per_component_install && (attributes & RemoveOnInstall) && msiInstall.IsInstalling()) 
            || (execute_per_component_uninstall && (attributes & RemoveOnUnInstall) && msiInstall.IsUnInstalling())
            );

        // write the odbc query to xml
        MSXML2::IXMLDOMNodePtr combined_xml_localgroupmembers_root = combined_xml_document.AppendChild(L"LocalGroupMember", combined_xml_root);
        combined_xml_document.SetAttribute(L"add", add_member ? L"true" : L"false", combined_xml_localgroupmembers_root);
        combined_xml_document.SetAttribute(L"remove", remove_member ? L"true" : L"false", combined_xml_localgroupmembers_root);
        combined_xml_document.SetAttribute(L"check", (attributes & CheckIfMember) ? L"true" : L"false", combined_xml_localgroupmembers_root);
        combined_xml_document.SetAttribute(L"id", localgroupmembers_id, combined_xml_localgroupmembers_root);
        combined_xml_document.AppendChild(L"Username", combined_xml_localgroupmembers_root)->text = _bstr_t(username.c_str());
        combined_xml_document.AppendChild(L"Group", combined_xml_localgroupmembers_root)->text = _bstr_t(groupname.c_str());
    }

    msiInstall.SetActionData(L"AddLocalGroupMembers_Deferred", combined_xml_document.GetXml());
    msiInstall.SetActionData(L"RemoveLocalGroupMembers_Deferred", combined_xml_document.GetXml());

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall LocalGroupMembers_Deferred(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    AppSecInc::Xml::XmlDocument xmlDocument;
    xmlDocument.LoadXml(msiInstall.GetActionData());

    MSXML2::IXMLDOMNodeListPtr rows = xmlDocument.SelectNodes(L"/LocalGroupMembers/LocalGroupMember");
    MSXML2::IXMLDOMNodePtr row = NULL;
    while (NULL != (row = rows->nextNode()))
    {
        std::wstring id = xmlDocument.GetAttributeValue(L"id", row);
        std::wstring username = xmlDocument.GetNodeValue(L"Username", row);
        std::wstring groupname = xmlDocument.GetNodeValue(L"Group", row, L"");
        bool add_member = xmlDocument.GetAttributeBoolValue(L"add", row);
        bool remove_member = xmlDocument.GetAttributeBoolValue(L"remove", row);
        bool check = xmlDocument.GetAttributeBoolValue(L"check", row);

        if (remove_member && (! check || AppSecInc::LSA::LocalGroup::IsMember(groupname, username)))
        {
            msiInstall.LogInfo(_T(__FUNCTION__), L"Removing \"" + username + L"\" from \"" + groupname + L"\"");
            AppSecInc::LSA::LocalGroup::DeleteMember(groupname, username);
        }

        if (add_member && (! check || ! AppSecInc::LSA::LocalGroup::IsMember(groupname, username)))
        {
            msiInstall.LogInfo(_T(__FUNCTION__), L"Adding \"" + username + L"\" to \"" + groupname + L"\"");
            AppSecInc::LSA::LocalGroup::AddMember(groupname, username);
        }
    }

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}
