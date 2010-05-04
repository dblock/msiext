#include "StdAfx.h"
#include "FlagMaps.h"
#include "RegistryImpl.h"

CA_API UINT __stdcall Registry_CopyBranch(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

	std::wstring sourceRoot_s = msiInstall.GetProperty(L"REGISTRY_ROOT");
	HKEY sourceRoot = (HKEY) GetFlagValue<FlagMapEntryHKEY[ARRAYSIZE(s_RegistryRoot)], HKEY>(sourceRoot_s, s_RegistryRoot);
	std::wstring targetRoot_s = msiInstall.GetProperty(L"REGISTRY_ROOT_TARGET");
	if (targetRoot_s.empty()) targetRoot_s = sourceRoot_s;
	HKEY targetRoot = (HKEY) GetFlagValue<FlagMapEntryHKEY[ARRAYSIZE(s_RegistryRoot)], HKEY>(targetRoot_s, s_RegistryRoot);
    std::wstring sourcePath = msiInstall.GetProperty(L"REGISTRY_PATH_SOURCE");
    std::wstring targetPath = msiInstall.GetProperty(L"REGISTRY_PATH_TARGET");

	msiInstall.LogInfo(_T(__FUNCTION__), L"Copying \"" + sourceRoot_s + L"\\" + sourcePath + L"\" to \"" + targetRoot_s + L"\\" + targetPath + L"\"");
	AppSecInc::Registry::CopyBranch(sourceRoot, sourcePath, targetRoot, targetPath);

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Registry_MoveBranch(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

	std::wstring sourceRoot_s = msiInstall.GetProperty(L"REGISTRY_ROOT");
	HKEY sourceRoot = (HKEY) GetFlagValue<FlagMapEntryHKEY[ARRAYSIZE(s_RegistryRoot)], HKEY>(sourceRoot_s, s_RegistryRoot);
	std::wstring targetRoot_s = msiInstall.GetProperty(L"REGISTRY_ROOT_TARGET");
	if (targetRoot_s.empty()) targetRoot_s = sourceRoot_s;
	HKEY targetRoot = (HKEY) GetFlagValue<FlagMapEntryHKEY[ARRAYSIZE(s_RegistryRoot)], HKEY>(targetRoot_s, s_RegistryRoot);
    std::wstring sourcePath = msiInstall.GetProperty(L"REGISTRY_PATH_SOURCE");
    std::wstring targetPath = msiInstall.GetProperty(L"REGISTRY_PATH_TARGET");

	msiInstall.LogInfo(_T(__FUNCTION__), L"Moving \"" + sourceRoot_s + L"\\" + sourcePath + L"\" to \"" + targetRoot_s + L"\\" + targetPath + L"\"");
	AppSecInc::Registry::CopyBranch(sourceRoot, sourcePath, targetRoot, targetPath);
	AppSecInc::Registry::DeleteBranch(sourceRoot, sourcePath);

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Registry_DeleteBranch(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

	std::wstring root_s = msiInstall.GetProperty(L"REGISTRY_ROOT");
	HKEY root = (HKEY) GetFlagValue<FlagMapEntryHKEY[ARRAYSIZE(s_RegistryRoot)], HKEY>(root_s, s_RegistryRoot);
    std::wstring path = msiInstall.GetProperty(L"REGISTRY_PATH");

	msiInstall.LogInfo(_T(__FUNCTION__), L"Deleting \"" + root_s + L"\\" + path + L"\"");
	AppSecInc::Registry::DeleteBranch(root, path);

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Registry_CreateKey(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

	std::wstring root_s = msiInstall.GetProperty(L"REGISTRY_ROOT");
	HKEY root = (HKEY) GetFlagValue<FlagMapEntryHKEY[ARRAYSIZE(s_RegistryRoot)], HKEY>(root_s, s_RegistryRoot);
    std::wstring path = msiInstall.GetProperty(L"REGISTRY_PATH");

	msiInstall.LogInfo(_T(__FUNCTION__), L"Creating \"" + root_s + L"\\" + path);
	AppSecInc::Registry::CreateKey(root, path);

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Registry_SetStringValue(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

	std::wstring root_s = msiInstall.GetProperty(L"REGISTRY_ROOT");
	HKEY root = (HKEY) GetFlagValue<FlagMapEntryHKEY[ARRAYSIZE(s_RegistryRoot)], HKEY>(root_s, s_RegistryRoot);
    std::wstring path = msiInstall.GetProperty(L"REGISTRY_PATH");
	std::wstring name = msiInstall.GetProperty(L"REGISTRY_NAME");
	std::wstring value = msiInstall.GetProperty(L"REGISTRY_VALUE");

	msiInstall.LogInfo(_T(__FUNCTION__), L"Setting value for \"" + root_s + L"\\" + path + L"\\" + name );
	AppSecInc::Registry::SetStringValue(root, path, name, value);

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Registry_KeyExists(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

	std::wstring root_s = msiInstall.GetProperty(L"REGISTRY_ROOT");
	HKEY root = (HKEY) GetFlagValue<FlagMapEntryHKEY[ARRAYSIZE(s_RegistryRoot)], HKEY>(root_s, s_RegistryRoot);
    std::wstring path = msiInstall.GetProperty(L"REGISTRY_PATH");
	std::wstring name = msiInstall.GetProperty(L"REGISTRY_NAME");
	
	msiInstall.LogInfo(_T(__FUNCTION__), L"Checking if key exists: \"" + root_s + L"\\" + path);

	if ( AppSecInc::Registry::KeyExists(root, path, name) )
	{
		msiInstall.SetProperty(L"REGISTRY_KEY_EXISTS", L"true");
	}
	else
	{
		msiInstall.SetProperty(L"REGISTRY_KEY_EXISTS", L"false");
	}

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Win32_RegistryCopy_Immediate(MSIHANDLE hInstall)
{
    MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

	// combined xml document
	AppSecInc::Xml::XmlDocument combined_xml_document;
	combined_xml_document.Create();
	MSXML2::IXMLDOMNodePtr combined_xml_root = combined_xml_document.AppendChild(L"RegistryKeys");

    AppSecInc::Xml::XmlDocument registry_xml_document;
    registry_xml_document.LoadXml(msiInstall.GetViewData(L"SELECT * FROM `Registry`"));

    typedef enum RegistryCopyAttributes
    {
        RegistryCopyOnInstall = 1,
        RegistryCopyOnUnInstall = 2,
        RegistryRestoreOnRollback = 4,
        // RegistryCopyOnReInstall = 8,
        RegistryCheckIfExists = 16,
        RegistryRemoveSource = 32,
        RegistryOverwrite = 64,
    };

	struct RegistryEntry
	{
		std::wstring id;
		int root;
		std::wstring key;
		std::wstring component;
	};

    std::map<std::wstring, RegistryEntry> registry_map;
    MSXML2::IXMLDOMNodeListPtr registry_rows = registry_xml_document.SelectNodes(L"//Row");
    MSXML2::IXMLDOMNodePtr registry_row = NULL;
    while (NULL != (registry_row = registry_rows->nextNode()))
    {
		RegistryEntry registry_key;
		registry_key.id = registry_xml_document.GetNodeValue(L"Data[@Column=\"Registry\"]", registry_row);
		registry_key.root = AppSecInc::StringUtils::stringToLong(registry_xml_document.GetNodeValue(L"Data[@Column=\"Root\"]", registry_row));
		registry_key.key = registry_xml_document.GetNodeValue(L"Data[@Column=\"Key\"]", registry_row);
		registry_key.component = registry_xml_document.GetNodeValue(L"Data[@Column=\"Component_\"]", registry_row);
        registry_map.insert(std::pair<std::wstring, RegistryEntry>(registry_key.id, registry_key));
    }

    AppSecInc::Xml::XmlDocument registry_copy_xml_document;
    registry_copy_xml_document.LoadXml(msiInstall.GetViewData(L"SELECT * FROM `RegistryCopy`"));

	{
		MSXML2::IXMLDOMNodeListPtr rows = registry_copy_xml_document.SelectNodes(L"//Row");
		MSXML2::IXMLDOMNodePtr row = NULL;
		while (NULL != (row = rows->nextNode()))
		{
            // id
		    std::wstring id = registry_copy_xml_document.GetNodeValue(L"Data[@Column=\"Id\"]", row, L"");
			// registry id
			std::wstring registry_id = registry_copy_xml_document.GetNodeValue(L"Data[@Column=\"RegistryId\"]", row, L"");
			std::map<std::wstring, RegistryEntry>::iterator registry_entry = registry_map.find(registry_id);
			if (registry_entry == registry_map.end()) THROW(L"Missing Registry \"" << registry_id << L"\"");
            // node condition
            std::wstring condition = registry_copy_xml_document.GetNodeValue(L"Data[@Column=\"Condition\"]", row);
            // operational attributes
            long attributes = AppSecInc::StringUtils::stringToLong(registry_copy_xml_document.GetNodeValue(L"Data[@Column=\"Attributes\"]", row));
            // no condition (executes by default) or condition evaluates to true
            bool execute_per_condition = condition.empty() || msiInstall.EvaluateCondition(condition);
            if (! condition.empty())
            {
                // set the evaluated value for debugging purposes
                registry_copy_xml_document.SelectNode(L"Data[@Column=\"Condition\"]", row)->text = _bstr_t(execute_per_condition ? L"1" : L"0");
            }
            // execute on install
            bool execute_per_component_install = (registry_entry->second.component.empty() || msiInstall.IsComponentInstalling(registry_entry->second.component));
            // execute on uninstall
            bool execute_per_component_uninstall = (registry_entry->second.component.empty() || msiInstall.IsComponentUnInstalling(registry_entry->second.component));

            bool execute = execute_per_condition && (
                (execute_per_component_install && (attributes & RegistryCopyOnInstall) && msiInstall.IsInstalling()) 
                || (execute_per_component_uninstall && (attributes & RegistryCopyOnUnInstall) && msiInstall.IsUnInstalling())
                );

		    MSXML2::IXMLDOMNodePtr registrykeycopy_node = combined_xml_document.AppendChild(L"RegistryKeyCopy", combined_xml_root);
		    combined_xml_document.SetAttribute(L"id", id, registrykeycopy_node);

            std::wstring target_path = registry_copy_xml_document.GetNodeValue(L"Data[@Column=\"TargetPath\"]", row);
            std::wstring target_root = registry_copy_xml_document.GetNodeValue(L"Data[@Column=\"TargetRoot\"]", row);
			HKEY target_root_hkey = GetFlagValue<FlagMapEntryHKEY[ARRAYSIZE(s_RegistryRoot)], HKEY>(target_root, s_RegistryRoot);
			int target_root_key = (reinterpret_cast<long>(target_root_hkey) - reinterpret_cast<long>(HKEY_CLASSES_ROOT));
			combined_xml_document.AppendChild(L"SourceRoot", registrykeycopy_node)->text = _bstr_t(AppSecInc::StringUtils::toWString(registry_entry->second.root).c_str());
		    combined_xml_document.AppendChild(L"SourcePath", registrykeycopy_node)->text = _bstr_t(registry_entry->second.key.c_str());
			combined_xml_document.AppendChild(L"TargetRoot", registrykeycopy_node)->text = _bstr_t(AppSecInc::StringUtils::toWString(target_root_key).c_str());
		    combined_xml_document.AppendChild(L"TargetPath", registrykeycopy_node)->text = _bstr_t(target_path.c_str());
            combined_xml_document.SetAttribute(L"copy", execute ? L"true" : L"false", registrykeycopy_node);
			combined_xml_document.SetAttribute(L"checkifexists", (attributes & RegistryCheckIfExists) ? L"true" : L"false", registrykeycopy_node);
			combined_xml_document.SetAttribute(L"overwrite", (attributes & RegistryOverwrite) ? L"true" : L"false", registrykeycopy_node);
			combined_xml_document.SetAttribute(L"removesource", (attributes & RegistryRemoveSource) ? L"true" : L"false", registrykeycopy_node);
			combined_xml_document.SetAttribute(L"restoreonrollback", (attributes & RegistryRestoreOnRollback) ? L"true" : L"false", registrykeycopy_node);
        }
    }

    std::wstring action = L"Win32_RegistryCopy_Deferred_";
    action.append(msiInstall.IsInstalling() ? L"Install" : L"UnInstall");
    msiInstall.SetActionData(action, combined_xml_document.GetXml());
    msiInstall.SetActionData(L"Win32_RegistryCopy_Rollback", combined_xml_document.GetXml());

    MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Win32_RegistryCopy_Deferred(MSIHANDLE hInstall)
{
    MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    AppSecInc::Xml::XmlDocument xmlDocument;
    xmlDocument.LoadXml(msiInstall.GetActionData());

    MSXML2::IXMLDOMNodeListPtr rows = xmlDocument.SelectNodes(L"//RegistryKeyCopy[@copy='true']");
    MSXML2::IXMLDOMNodePtr row = rows->nextNode();
    while (NULL != row)
    {
		HKEY source_root = (HKEY) (reinterpret_cast<long>(HKEY_CLASSES_ROOT) + AppSecInc::StringUtils::stringToLong(xmlDocument.GetNodeValue(L"SourceRoot", row)));
		std::wstring source_path = xmlDocument.GetNodeValue(L"SourcePath", row);
		std::wstring source_s = GetFlagName<FlagMapEntryHKEY[ARRAYSIZE(s_RegistryRoot)], HKEY>(source_root, s_RegistryRoot) + L"\\" + source_path;
		HKEY target_root = (HKEY) (reinterpret_cast<long>(HKEY_CLASSES_ROOT) + AppSecInc::StringUtils::stringToLong(xmlDocument.GetNodeValue(L"TargetRoot", row)));
		std::wstring target_path = xmlDocument.GetNodeValue(L"TargetPath", row);
		std::wstring target_s = GetFlagName<FlagMapEntryHKEY[ARRAYSIZE(s_RegistryRoot)], HKEY>(target_root, s_RegistryRoot) + L"\\" + target_path;
		bool check_if_exists = xmlDocument.GetAttributeBoolValue(L"checkifexists", row);
		bool overwrite = xmlDocument.GetAttributeBoolValue(L"overwrite", row);
		bool removesource = xmlDocument.GetAttributeBoolValue(L"removesource", row);
		bool restoreonrollback = xmlDocument.GetAttributeBoolValue(L"restoreonrollback", row);

		if (msiInstall.IsRollback() && restoreonrollback)
		{
			// invert source and target, this is a restore operation
			std::swap(source_root, target_root);
			std::swap(source_path, target_path);
			std::swap(source_s, target_s);

			msiInstall.LogInfo(_T(__FUNCTION__), L"Restoring \"" + target_s + L"\" from \"" + source_s + L"\".");
		}

		msiInstall.LogInfo(_T(__FUNCTION__), L"Copying \"" + source_s + L"\" to \"" + target_s + L"\".");

		if (msiInstall.IsRollback() && ! restoreonrollback)
		{
			// skip if no rollback set
			msiInstall.LogInfo(_T(__FUNCTION__), L"Skipped, RestoreOnRollback is not set.");
		}
		else if (check_if_exists && ! AppSecInc::Registry::KeyExists(source_root, source_path))
		{
			// skip if source key doesn't exist and check if exists is true
			msiInstall.LogInfo(_T(__FUNCTION__), L"Skipped, source \"" + source_s + L"\" doesn't exist.");
		}
		else if (! overwrite && AppSecInc::Registry::KeyExists(target_root, target_path))
		{
			// error if target exists and overwrite is false
			msiInstall.LogInfo(_T(__FUNCTION__), L"Skipped, target \"" + target_s + L"\" exist.");
		}
		else
		{
			AppSecInc::Registry::CopyBranch(source_root, source_path,  target_root, target_path);

			if (removesource)
			{
				msiInstall.LogInfo(_T(__FUNCTION__), L"Deleting \"" + source_s + L"\".");
				AppSecInc::Registry::DeleteBranch(source_root, source_path);
			}
		}

        row = rows->nextNode();
    }

    MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}
