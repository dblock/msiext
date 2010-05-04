#include "StdAfx.h"
#include "Win32Impl.h"

CA_API UINT __stdcall Win32_CopyFile(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;

    MsiInstall msiInstall(hInstall);
	std::wstring source_filename = msiInstall.GetProperty(L"WIN32_SOURCE_FILENAME");
    CHECK_BOOL(source_filename.length() > 0, L"Missing WIN32_SOURCE_FILENAME");
	std::wstring target_filename = msiInstall.GetProperty(L"WIN32_TARGET_FILENAME");
    CHECK_BOOL(target_filename.length() > 0, L"Missing WIN32_TARGET_FILENAME");

    // overwrite can be one of "yes", "no", "error"
	std::wstring overwrite = msiInstall.GetProperty(L"WIN32_TARGET_OVERWRITE");
    ULONG file_overwrite = GetFlagValue(overwrite, s_Win32CopyFile_Overwrite);
	bool file_exists = AppSecInc::File::FileExists(target_filename);
    
	CHECK_BOOL(! (file_overwrite == WIN32COPYFILE_OVERWRITEERROR && file_exists), 
        L"Error copying " << source_filename << L" to " << target_filename << L", file exists.");

    if (file_overwrite == WIN32COPYFILE_OVERWRITEYES || ! file_exists)
    {
        CHECK_WIN32_BOOL(::CopyFile(source_filename.c_str(), target_filename.c_str(), FALSE),
            L"Error copying " << source_filename << L" to " << target_filename);
    }

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Win32_MoveFile(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;

    MsiInstall msiInstall(hInstall);
	std::wstring source_filename = msiInstall.GetProperty(L"WIN32_SOURCE_FILENAME");
    CHECK_BOOL(source_filename.length() > 0, L"Missing WIN32_SOURCE_FILENAME");
	std::wstring target_filename = msiInstall.GetProperty(L"WIN32_TARGET_FILENAME");
    CHECK_BOOL(target_filename.length() > 0, L"Missing WIN32_TARGET_FILENAME");

    // overwrite can be one of "yes", "no", "error"
	std::wstring overwrite = msiInstall.GetProperty(L"WIN32_TARGET_OVERWRITE");
    ULONG file_overwrite = GetFlagValue(overwrite, s_Win32CopyFile_Overwrite);
	bool file_exists = AppSecInc::File::FileExists(target_filename);
    
	CHECK_BOOL(! (file_overwrite == WIN32COPYFILE_OVERWRITEERROR && file_exists), 
        L"Error copying " << source_filename << L" to " << target_filename << L", file exists.");

    if (file_overwrite == WIN32COPYFILE_OVERWRITEYES || ! file_exists)
    {
        CHECK_WIN32_BOOL(::MoveFile(source_filename.c_str(), target_filename.c_str()),
            L"Error copying " << source_filename << L" to " << target_filename);
    }

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Win32_DeleteFile(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);
    std::wstring filename = msiInstall.GetProperty(L"WIN32_FILENAME");
    CHECK_BOOL(filename.length() > 0, L"Missing WIN32_FILENAME");
    CHECK_WIN32_BOOL(::DeleteFile(filename.c_str()),
        L"Error deleting " << filename);
	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Win32_DeleteDirectory(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);
    std::wstring path = msiInstall.GetProperty(L"WIN32_PATH");
    CHECK_BOOL(path.length() > 0, L"Missing WIN32_PATH");
	msiInstall.LogInfo(_T(__FUNCTION__), L"Deleting \"" + path + L"\""); 
	AppSecInc::File::DirectoryDelete(path);
	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Win32_CreateDirectory(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);
    std::wstring path = msiInstall.GetProperty(L"WIN32_PATH");
    CHECK_BOOL(path.length() > 0, L"Missing WIN32_PATH");
	msiInstall.LogInfo(_T(__FUNCTION__), L"Creating \"" + path + L"\""); 
	std::wstring path_created = AppSecInc::File::DirectoryCreate(path);
	msiInstall.SetProperty(L"WIN32_PATH_CREATED", path_created);
	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Win32_CopyFiles_Deferred(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::wstring xml = msiInstall.GetActionData();

    AppSecInc::Xml::XmlDocument xmlDocument;
    xmlDocument.LoadXml(xml);

    MSXML2::IXMLDOMNodeListPtr rows = xmlDocument.SelectNodes(L"//Row[@copy='true']");
    MSXML2::IXMLDOMNodePtr row = rows->nextNode();
    while (NULL != row)
    {
        MSXML2::IXMLDOMNodePtr source_node = row->selectSingleNode(L"Data[@Column=\"Source\"]");
        MSXML2::IXMLDOMNodePtr target_node = row->selectSingleNode(L"Data[@Column=\"Target\"]");
        MSXML2::IXMLDOMNodePtr wildcard_node = row->selectSingleNode(L"Data[@Column=\"Wildcard\"]");

        CHECK_BOOL(source_node != NULL && target_node != NULL,
            L"Invalid xml data, missing data column");

        // copy file(s) from source to target
        std::wstring source = source_node->text;
        std::wstring target = target_node->text;
        std::wstring wildcard = (wildcard_node != NULL) ? wildcard_node->text : L"";

        std::wstringstream status;
        if (! wildcard.empty())
        {
            if (! AppSecInc::StringUtils::endsWith(source, L"\\"))
                source += L"\\";
            if (! AppSecInc::StringUtils::endsWith(target, L"\\"))
                target += L"\\";
        }

        status << L"Copy: " << source << wildcard << L" -> " << target;

        // overwrite can be one of "yes", "no", "error"
        ULONG file_overwrite = WIN32COPYFILE_OVERWRITEYES;
        MSXML2::IXMLDOMNodePtr overwrite_node = row->selectSingleNode(L"Data[@Column=\"Overwrite\"]");
        if (overwrite_node != NULL) 
        {
            std::wstring overwrite = overwrite_node->text;
			file_overwrite = GetFlagValue(overwrite, s_Win32CopyFile_Overwrite);
            status << L", overwrite: " << overwrite << L" (" << file_overwrite << L")";
        }

        // recurse says whether we need to recurse into subdirectories
        bool recurse = xmlDocument.GetAttributeBoolValue(L"recurse", row);
        if (recurse) 
        {
            status << L", recurse";
        }

        msiInstall.LogInfo(_T(__FUNCTION__), status.str());

        // get the list of files to copy
        std::list<std::wstring> files;
        if (! wildcard.empty())
        {
            int file_flags = AppSecInc::File::GET_FILES_FILES;
            if (recurse) file_flags |= AppSecInc::File::GET_FILES_RECURSIVE;
            files = AppSecInc::File::GetFiles(source, wildcard, file_flags);
        }
        else
        {
            files.push_back(source);
        }

        for each(const std::wstring& source_file in files)
        {
            // make the target file name
            std::wstring target_file;
            if (! wildcard.empty())
            {
                // target is a directory, terminated by \\, in full source path replace by target path to make subdirectories
                target_file = source_file;
                AppSecInc::StringUtils::replace(target_file, source, target);
            }
            else
            {
                // target is whatever is defined
                target_file = target;
            }

            // copy the file
            
		    bool file_exists = AppSecInc::File::FileExists(target_file);

            CHECK_BOOL(! (file_overwrite == WIN32COPYFILE_OVERWRITEERROR && file_exists),
                L"Error copying " << source_file << L" => " << target_file << L", file exists.");

            if (file_overwrite == WIN32COPYFILE_OVERWRITEYES || ! file_exists)
            {
                // create the target directory if it doesn't exist
                std::wstring target_directory = AppSecInc::File::GetFileDirectoryW(target_file);
                if (! AppSecInc::File::DirectoryExists(target_directory))
                {
                    msiInstall.LogInfo(_T(__FUNCTION__), L"CreateDirectory: " + target_directory);
                    AppSecInc::File::DirectoryCreate(target_directory);
                }

                std::wstringstream copy_status;
                copy_status << L"Copy: " << source_file << " => " << target_file;
                msiInstall.LogInfo(_T(__FUNCTION__), copy_status.str());

                CHECK_WIN32_BOOL(::CopyFile(source_file.c_str(), target_file.c_str(), FALSE),
                    L"Error copying: " << source_file << L" => " << target_file);
            }
        }

        row = rows->nextNode();
    }

    MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

namespace Win32_CopyFiles
{
    enum CopyFilesAttributes
    {
        CopyOnInstall = 1,
        CopyOnUnInstall = 2,
        // CopyOnRollback = 4,
        // CopyOnReInstall = 8,
        CopyRecurse = 16,
    };
}

CA_API UINT __stdcall Win32_CopyFiles_Immediate(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    // evaluate conditions and update the custom action table data

    std::wstring xml = msiInstall.GetViewData(L"SELECT * FROM `Win32_CopyFiles`");
    AppSecInc::Xml::XmlDocument xmlDocument;
    xmlDocument.LoadXml(xml);

    MSXML2::IXMLDOMNodeListPtr rows = xmlDocument.SelectNodes(L"//Row");
    MSXML2::IXMLDOMNodePtr row = rows->nextNode();
    while (NULL != row)
    {
        // id
		std::wstring id = xmlDocument.GetNodeValue(L"Data[@Column=\"Id\"]", row, L"");
        // operational attributes
        long attributes = AppSecInc::StringUtils::stringToLong(xmlDocument.GetNodeValue(L"Data[@Column=\"Attributes\"]", row));
        // node condition
        std::wstring condition = xmlDocument.GetNodeValue(L"Data[@Column=\"Condition\"]", row);
        // no condition (executes by default) or condition evaluates to true
        bool copy_per_condition = condition.empty() || msiInstall.EvaluateCondition(condition);
		// evaluate copy
		bool copy = copy_per_condition && (
            ((attributes & Win32_CopyFiles::CopyOnInstall) && msiInstall.IsInstalling()) 
            || ((attributes & Win32_CopyFiles::CopyOnUnInstall) && msiInstall.IsUnInstalling())
            );

		xmlDocument.SetAttribute(L"copy", copy ? L"true" : L"false", row);
		xmlDocument.SetAttribute(L"recurse", (attributes & Win32_CopyFiles::CopyRecurse) ? L"true" : L"false", row);
        row = rows->nextNode();
    }

    std::wstring action = L"Win32_CopyFiles_Deferred_";
    action.append(msiInstall.IsInstalling() ? L"Install" : L"UnInstall");
    msiInstall.SetActionData(action, xmlDocument.GetXml());

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Win32_MoveFiles_Deferred(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::wstring xml = msiInstall.GetActionData();

    AppSecInc::Xml::XmlDocument xmlDocument;
    xmlDocument.LoadXml(xml);

    MSXML2::IXMLDOMNodeListPtr rows = xmlDocument.SelectNodes(L"//Row[@move='true']");
    MSXML2::IXMLDOMNodePtr row = rows->nextNode();
    while (NULL != row)
    {
        MSXML2::IXMLDOMNodePtr source_node = row->selectSingleNode(L"Data[@Column=\"Source\"]");
        MSXML2::IXMLDOMNodePtr target_node = row->selectSingleNode(L"Data[@Column=\"Target\"]");
        MSXML2::IXMLDOMNodePtr wildcard_node = row->selectSingleNode(L"Data[@Column=\"Wildcard\"]");

        CHECK_BOOL(source_node != NULL && target_node != NULL,
            L"Invalid xml data, missing data column");

        // move the file
        std::wstring source = source_node->text;
        std::wstring target = target_node->text;
        std::wstring wildcard = (wildcard_node != NULL) ? wildcard_node->text : L"";

        if (! wildcard.empty())
        {
            if (! AppSecInc::StringUtils::endsWith(source, L"\\"))
                source += L"\\";
            if (! AppSecInc::StringUtils::endsWith(target, L"\\"))
                target += L"\\";
        }

        std::wstringstream status;
        status << L"Move: " << source << wildcard << L" -> " << target;

        // overwrite can be one of "yes", "no", "error"
        ULONG file_overwrite = WIN32COPYFILE_OVERWRITEYES;
        MSXML2::IXMLDOMNodePtr overwrite_node = row->selectSingleNode(L"Data[@Column=\"Overwrite\"]");
        if (overwrite_node != NULL) 
        {
            std::wstring overwrite = overwrite_node->text;
			file_overwrite = GetFlagValue(overwrite, s_Win32CopyFile_Overwrite);
            status << L", overwrite: " << overwrite << L" (" << file_overwrite << L")";
        }

        // recurse says whether we need to recurse into subdirectories
        bool recurse = xmlDocument.GetAttributeBoolValue(L"recurse", row);
        if (recurse) 
        {
            status << L", recurse";
        }

        // deleteemptydirectories says whether we need to delete empty leftoever directories
        bool deleteemptydirectories = xmlDocument.GetAttributeBoolValue(L"deleteemptydirectories", row);
        if (deleteemptydirectories) 
        {
            status << L", delete empty directories";
        }

        msiInstall.LogInfo(_T(__FUNCTION__), status.str());

        // get the list of files to move
        std::list<std::wstring> files;
        if (! wildcard.empty())
        {
            int file_flags = AppSecInc::File::GET_FILES_FILES;
            if (recurse) file_flags |= AppSecInc::File::GET_FILES_RECURSIVE;
            files = AppSecInc::File::GetFiles(source, wildcard, file_flags);
        }
        else
        {
            files.push_back(source);
        }

        for each(const std::wstring& source_file in files)
        {
            // make the target file name
            std::wstring target_file;
            if (! wildcard.empty())
            {
                // target is a directory, terminated by \\, in full source path replace by target path to make subdirectories
                target_file = source_file;
                AppSecInc::StringUtils::replace(target_file, source, target);
            }
            else
            {
                // target is whatever is defined
                target_file = target;
            }

            // move the file
		    bool file_exists = AppSecInc::File::FileExists(target_file);

            CHECK_BOOL(! (file_overwrite == WIN32COPYFILE_OVERWRITEERROR && file_exists),
                L"Error moving " << source_file << L" => " << target_file << L", file exists.");

            if (file_overwrite == WIN32COPYFILE_OVERWRITEYES || ! file_exists)
            {
                std::wstringstream move_status;
                move_status << L"Move: " << source_file << " => " << target_file;
                msiInstall.LogInfo(_T(__FUNCTION__), move_status.str());

                // create the target directory if it doesn't exist
                std::wstring target_directory = AppSecInc::File::GetFileDirectoryW(target_file);
                if (! AppSecInc::File::DirectoryExists(target_directory))
                {
                    msiInstall.LogInfo(_T(__FUNCTION__), L"CreateDirectory: " + target_directory);
                    AppSecInc::File::DirectoryCreate(target_directory);
                }

                CHECK_WIN32_BOOL(::CopyFile(source_file.c_str(), target_file.c_str(), FALSE),
                    L"Error copying: " << source_file << L" => " << target_file);
                CHECK_WIN32_BOOL(::DeleteFile(source_file.c_str()),
                    L"Error deleting: " << source_file);
            }
        }

        if (deleteemptydirectories)
        {
            AppSecInc::File::DirectoryDelete(source, AppSecInc::File::DELETE_DIRECTORY_EMPTY);
        }

        row = rows->nextNode();
    }

    MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

namespace Win32_MoveFiles
{
    enum MoveFilesAttributes
    {
        MoveOnInstall = 1,
        MoveOnUnInstall = 2,
        // MoveOnRollback = 4,
        // MoveOnReInstall = 8,
        MoveRecurse = 16,
        DeleteEmptyDirectories = 32
    };
}

CA_API UINT __stdcall Win32_MoveFiles_Immediate(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::wstring xml = msiInstall.GetViewData(L"SELECT * FROM `Win32_MoveFiles`");
    AppSecInc::Xml::XmlDocument xmlDocument;
    xmlDocument.LoadXml(xml);

    MSXML2::IXMLDOMNodeListPtr rows = xmlDocument.SelectNodes(L"//Row");
    MSXML2::IXMLDOMNodePtr row = rows->nextNode();
    while (NULL != row)
    {
        // id
		std::wstring id = xmlDocument.GetNodeValue(L"Data[@Column=\"Id\"]", row, L"");
        // operational attributes
        long attributes = AppSecInc::StringUtils::stringToLong(xmlDocument.GetNodeValue(L"Data[@Column=\"Attributes\"]", row));
        // node condition
        std::wstring condition = xmlDocument.GetNodeValue(L"Data[@Column=\"Condition\"]", row);
        // no condition (executes by default) or condition evaluates to true
        bool move_per_condition = condition.empty() || msiInstall.EvaluateCondition(condition);
		// evaluate move
		bool move = move_per_condition && (
            ((attributes & Win32_MoveFiles::MoveOnInstall) && msiInstall.IsInstalling()) 
            || ((attributes & Win32_MoveFiles::MoveOnUnInstall) && msiInstall.IsUnInstalling())
            );

        bool recurse = ((attributes & Win32_MoveFiles::MoveRecurse) > 0);
        bool deleteemptydirectories = ((attributes & Win32_MoveFiles::DeleteEmptyDirectories) > 0);

		xmlDocument.SetAttribute(L"move", move ? L"true" : L"false", row);
        xmlDocument.SetAttribute(L"recurse", recurse ? L"true" : L"false", row);
        xmlDocument.SetAttribute(L"deleteemptydirectories", deleteemptydirectories ? L"true" : L"false", row);
        row = rows->nextNode();
    }

    std::wstring action = L"Win32_MoveFiles_Deferred_";
    action.append(msiInstall.IsInstalling() ? L"Install" : L"UnInstall");
    msiInstall.SetActionData(action, xmlDocument.GetXml());

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

namespace Win32_DeleteFiles
{
    enum DeleteFilesAttributes
    {
        DeleteOnInstall = 1,
        DeleteOnUnInstall = 2,
        // DeleteOnRollback = 4,
        // DeleteOnReInstall = 8,
        CheckIfExists = 16,
        DeleteRecurse = 32,
        DeleteEmptyDirectories = 64
    };
}

CA_API UINT __stdcall Win32_DeleteFiles_Deferred(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::wstring xml = msiInstall.GetActionData();

    AppSecInc::Xml::XmlDocument xmlDocument;
    xmlDocument.LoadXml(xml);

    MSXML2::IXMLDOMNodeListPtr rows = xmlDocument.SelectNodes(L"//Row[@delete='true']");
    MSXML2::IXMLDOMNodePtr row = rows->nextNode();
    while (NULL != row)
    {
        // copy the file
        std::wstring source = xmlDocument.GetNodeValue(L"Data[@Column=\"File\"]", row);
        std::wstring wildcard = xmlDocument.GetNodeValue(L"Data[@Column=\"Wildcard\"]", row, L"");

        std::wstringstream status;
        
        // deleting a collection of files
        if (! wildcard.empty())
        {
            if (! AppSecInc::StringUtils::endsWith(source, L"\\"))
                source += L"\\";
        }

        status << "Deleting " << source << wildcard;

        // recurse says whether we need to recurse into subdirectories
        bool recurse = xmlDocument.GetAttributeBoolValue(L"recurse", row);
        if (recurse) 
        {
            status << L", recurse";
        }

        bool check_exists = xmlDocument.GetAttributeBoolValue(L"check", row);
        if (check_exists) 
        {
            status << L", check if exists";
        }

        // deleteemptydirectories says whether we need to delete empty leftoever directories
        bool deleteemptydirectories = xmlDocument.GetAttributeBoolValue(L"deleteemptydirectories", row);
        if (deleteemptydirectories) 
        {
            status << L", delete empty directories";
        }

        msiInstall.LogInfo(_T(__FUNCTION__), status.str());

        std::list<std::wstring> files;
        if (! wildcard.empty())
        {
            int file_flags = AppSecInc::File::GET_FILES_FILES;
            if (recurse) file_flags |= AppSecInc::File::GET_FILES_RECURSIVE;
            files = AppSecInc::File::GetFiles(source, wildcard, file_flags);
        }
        else
        {
            files.push_back(source);
        }

        for each(const std::wstring& file in files)
        {
            if (! check_exists || AppSecInc::File::FileExists(file))
            {
                msiInstall.LogInfo(_T(__FUNCTION__), L"Delete: " + file);
                AppSecInc::File::FileDelete(file);
            }
        }

        if (deleteemptydirectories)
        {
            AppSecInc::File::DirectoryDelete(source, AppSecInc::File::DELETE_DIRECTORY_EMPTY);
        }

        row = rows->nextNode();
    }

    MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Win32_DeleteFiles_Immediate(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    // evaluate conditions and update the custom action table data

    std::wstring xml = msiInstall.GetViewData(L"SELECT * FROM `Win32_DeleteFiles`");
    AppSecInc::Xml::XmlDocument xmlDocument;
    xmlDocument.LoadXml(xml);

    MSXML2::IXMLDOMNodeListPtr rows = xmlDocument.SelectNodes(L"//Row");
    MSXML2::IXMLDOMNodePtr row = rows->nextNode();
    while (NULL != row)
    {
        // id
		std::wstring id = xmlDocument.GetNodeValue(L"Data[@Column=\"Id\"]", row, L"");
        // operational attributes
        long attributes = AppSecInc::StringUtils::stringToLong(xmlDocument.GetNodeValue(L"Data[@Column=\"Attributes\"]", row));
        // node condition
        std::wstring condition = xmlDocument.GetNodeValue(L"Data[@Column=\"Condition\"]", row);
        // no condition (executes by default) or condition evaluates to true
        bool delete_per_condition = condition.empty() || msiInstall.EvaluateCondition(condition);
		// evaluate delete
		bool delete_file = delete_per_condition && (
            ((attributes & Win32_DeleteFiles::DeleteOnInstall) && msiInstall.IsInstalling()) 
            || ((attributes & Win32_DeleteFiles::DeleteOnUnInstall) && msiInstall.IsUnInstalling())
            );

        bool check_file = ((attributes & Win32_DeleteFiles::CheckIfExists) > 0);
        bool recurse = ((attributes & Win32_DeleteFiles::DeleteRecurse) > 0);
        bool deleteemptydirectories = ((attributes & Win32_DeleteFiles::DeleteEmptyDirectories) > 0);

		xmlDocument.SetAttribute(L"check", check_file ? L"true" : L"false", row);
		xmlDocument.SetAttribute(L"delete", delete_file ? L"true" : L"false", row);
		xmlDocument.SetAttribute(L"recurse", recurse ? L"true" : L"false", row);
        xmlDocument.SetAttribute(L"deleteemptydirectories", deleteemptydirectories ? L"true" : L"false", row);
        row = rows->nextNode();
    }

    std::wstring action = L"Win32_DeleteFiles_Deferred_";
    action.append(msiInstall.IsInstalling() ? L"Install" : L"UnInstall");
    msiInstall.SetActionData(action, xmlDocument.GetXml());

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

enum ExecuteAttributes
{
    ContinueOnError = 1,
    ExecuteOnInstall = 2,
    ExecuteOnUnInstall = 4,
    // ExecuteOnRollback = 8,
    // ExecuteOnReInstall = 16,
    ScheduleIndependently = 32
};

CA_API UINT __stdcall Win32_Execute_Immediate(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::wstring xml = msiInstall.GetViewData(L"SELECT * FROM `Win32_Execute`");
    AppSecInc::Xml::XmlDocument xmlDocument;
    xmlDocument.LoadXml(xml);

    MSXML2::IXMLDOMNodeListPtr rows = xmlDocument.SelectNodes(L"//Row");
    MSXML2::IXMLDOMNodePtr row = NULL;
    while (NULL != (row = rows->nextNode()))
    {
        // id
		std::wstring id = xmlDocument.GetNodeValue(L"Data[@Column=\"Id\"]", row, L"");
        // component id
		std::wstring component_id = xmlDocument.GetNodeValue(L"Data[@Column=\"ComponentId\"]", row, L"");
        // node condition
        std::wstring condition = xmlDocument.GetNodeValue(L"Data[@Column=\"Condition\"]", row);
        // operational attributes
        long attributes = AppSecInc::StringUtils::stringToLong(xmlDocument.GetNodeValue(L"Data[@Column=\"Attributes\"]", row));
        // no condition (executes by default) or condition evaluates to true
        bool execute_per_condition = condition.empty() || msiInstall.EvaluateCondition(condition);
        // execute on install
        bool execute_per_component_install = (component_id.empty() || msiInstall.IsComponentInstalling(component_id));
        // execute on uninstall
        bool execute_per_component_uninstall = (component_id.empty() || msiInstall.IsComponentUnInstalling(component_id));

        bool execute = execute_per_condition && (
            (execute_per_component_install && (attributes & ExecuteOnInstall) && msiInstall.IsInstalling()) 
            || (execute_per_component_uninstall && (attributes & ExecuteOnUnInstall) && msiInstall.IsUnInstalling())
            );

        // xmlDocument.SetAttribute(L"rollback", attributes & ExecuteOnRollback ? L"true" : L"false");
        
        if (attributes & ScheduleIndependently)
        {
            xmlDocument.SetAttribute(L"execute", execute ? L"true" : L"false", row);
            // get the xml for this node alone
            CComBSTR actionxml;
            CHECK_HR(row->get_xml(& actionxml), L"Error getting row text.");
            // the id of the deferred CA is the id of this action
            msiInstall.SetProperty(id, static_cast<LPCWSTR>(actionxml));
            // don't execute in the standard deferred action
            xmlDocument.SetAttribute(L"execute", L"false", row);
        }
        else
        {
            xmlDocument.SetAttribute(L"execute", execute ? L"true" : L"false", row);
        }
    }

    msiInstall.SetActionData(L"Win32_Execute_Deferred", xmlDocument.GetXml());

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Win32_Execute_Rollback(MSIHANDLE hInstall)
{
    // \todo execute rollback actions
    return ERROR_NOT_SUPPORTED;
}

CA_API UINT __stdcall Win32_Execute_Deferred(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    AppSecInc::Xml::XmlDocument xmlDocument;
    xmlDocument.LoadXml(msiInstall.GetActionData());

    MSXML2::IXMLDOMNodeListPtr rows = xmlDocument.SelectNodes(L"//Row[@execute='true']"); // \todo //Row[@rollback='false']
    MSXML2::IXMLDOMNodePtr row = NULL;
    while (NULL != (row = rows->nextNode()))
    {
        std::wstring id = xmlDocument.GetNodeValue(L"Data[@Column=\"Id\"]", row);
        std::wstring directory = xmlDocument.GetNodeValue(L"Data[@Column=\"Directory\"]", row, L"");
        std::wstring commandline = xmlDocument.GetNodeValue(L"Data[@Column=\"CommandLine\"]", row);
        std::wstring errormessage = xmlDocument.GetNodeValue(L"Data[@Column=\"ErrorMessage\"]", row, L"");
        long returncode = AppSecInc::StringUtils::stringToLong(xmlDocument.GetNodeValue(L"Data[@Column=\"ReturnCode\"]", row, L"0"));
        long attributes = AppSecInc::StringUtils::stringToLong(xmlDocument.GetNodeValue(L"Data[@Column=\"Attributes\"]", row, L"0"));

		msiInstall.LogInfo(_T(__FUNCTION__), commandline);

        try
        {
            AppSecInc::File::Process p;
            p.CreateWithRedirectedOutput(commandline, directory);
            bool finished = false;
            while (! finished)
            {
                msiInstall.LogInfo(_T(__FUNCTION__), AppSecInc::StringUtils::mb2wc(p.ReadLine(finished)));
            }
            
            p.Wait();
            
            DWORD exitcode = p.GetExitCode();
            CHECK_BOOL(exitcode == returncode,
                L"Exit code for \"" << commandline << "\" was " << exitcode << ", expected " << returncode);
        }
        catch(std::exception& ex)
        {
            if (! errormessage.empty()) 
            {
                // popup the error
                std::wstringstream error;
                error << errormessage << L"\n" << AppSecInc::StringUtils::mb2wc(ex.what());
                msiInstall.LogError(error.str());
            }

            // deal with optional ignore
            if (attributes & ContinueOnError)
            {
                // log as info, continue
                msiInstall.LogInfo(_T(__FUNCTION__), L"ContinueOnError is set, ignoring error");
            }
            else 
            {
                throw ex;
            }
        }
    }

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Win32_GetFileSize(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);
	std::wstring filename = msiInstall.GetProperty(L"WIN32_FILENAME");
    AppSecInc::File::FILESIZE_STRING_TYPE format = (AppSecInc::File::FILESIZE_STRING_TYPE) GetPropertyValue(
        msiInstall, L"WIN32_FILESIZE_FORMAT", s_Win32GetFileSize_Format);
    long precision = AppSecInc::StringUtils::stringToLong(msiInstall.GetProperty(L"WIN32_FILESIZE_PRECISION"), 0);
    long size = AppSecInc::File::GetFileSize(filename);
    msiInstall.SetProperty(L"WIN32_FILESIZE_BYTES", AppSecInc::StringUtils::toWString(size));
    std::pair<std::wstring, std::wstring> size_pair = AppSecInc::File::SizeToStringPairW(size, format, (int) precision);
    msiInstall.SetProperty(L"WIN32_FILESIZE", size_pair.first);
    msiInstall.SetProperty(L"WIN32_FILESIZE_FORMATTED", size_pair.first + L" " + size_pair.second);
	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}


CA_API UINT __stdcall Win32_FileExists(MSIHANDLE hInstall)
{
    MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);
    std::wstring filename = msiInstall.GetProperty(L"WIN32_FILENAME");
    bool exists = AppSecInc::File::FileExists(filename);
    msiInstall.SetProperty(L"WIN32_FILE_EXISTS", (exists ? L"1": L"0"));
    MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Win32_GetParentDirectory(MSIHANDLE hInstall)
{
    MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);
    std::wstring directory = msiInstall.GetProperty(L"WIN32_DIRECTORY");
	std::wstring parent_directory = AppSecInc::File::GetParentDirectory(directory);
	msiInstall.SetProperty(L"WIN32_PARENT_DIRECTORY", parent_directory);
    MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Win32_WriteFile(MSIHANDLE hInstall)
{
    MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);
    std::wstring data = msiInstall.GetProperty(L"WIN32_FILE_DATA");
	std::wstring filename = msiInstall.GetProperty(L"WIN32_FILE_NAME");
	std::string char_data = AppSecInc::StringUtils::wc2mb(data);
	std::vector<char> binary_data;
	binary_data.assign(char_data.begin(), char_data.end());
	AppSecInc::File::FileWrite(filename, binary_data);
    MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Win32_ReadFile(MSIHANDLE hInstall)
{
    MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);
	std::wstring filename = msiInstall.GetProperty(L"WIN32_FILE_NAME");
	std::string data;
	AppSecInc::File::ReadToEnd(filename, data);
	msiInstall.SetProperty("WIN32_FILE_DATA", data);
	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}
