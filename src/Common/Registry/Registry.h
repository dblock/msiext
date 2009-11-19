#pragma once

namespace AppSecInc
{
	//! Win32 Registry support functions
	namespace Registry
	{
        /*
            \fn KeyExists
            \brief Checks whether a registry key, and optionally registry value, exists
            \param root HKEY_LOCAL_MACHINE, etc.
            \param key path to the registry key
            \param name name of the value to check, if blank only checks the key
        */
        bool KeyExists(HKEY root, const std::wstring& key, const std::wstring& name = L"");

        /*
            \fn GetStringValue
            \brief Get a string value from registry
            \param root HKEY_LOCAL_MACHINE, etc.
            \param key path to the registry key
            \param name name of the value to fetch
        */
        std::wstring GetStringValue(HKEY root, const std::wstring& key, const std::wstring& name = L"");

        /*
            \fn CopyBranch
            \brief Copy an entire branch of the registry from one location to another
            \param sourceRoot HKEY_LOCAL_MACHINE, etc.
            \param keySrcRoot source path to the registry key that is being copied
			\param targetRoot HKEY_LOCAL_MACHINE, etc.
            \param keyDestRoot destination path to the registry key that will be created
        */
		void CopyBranch(HKEY sourceRoot, const std::wstring& keySrcRoot, HKEY destRoot, const std::wstring& keyDestRoot);

        /*
            \fn DeleteBranch
            \brief Delete an entire branch of the registry
            \param root HKEY_LOCAL_MACHINE, etc.
            \param key path to the registry key to be deleted
        */
		void DeleteBranch(HKEY root, const std::wstring& key);
		
		/*
            \fn CreateKey
            \brief Create a registry key
            \param root HKEY_LOCAL_MACHINE, etc.
            \param key path to the registry key to be added
        */
		void CreateKey(HKEY root, const std::wstring& key);

		/*
            \fn SetStringValue
            \brief Creates a string name / value pair
            \param root HKEY_LOCAL_MACHINE, etc.
            \param key path to the registry key where the name / value is to be set
			\param name 
			\param value
        */
		void SetStringValue(HKEY root, const std::wstring& key, const std::wstring &name, const std::wstring& value);
	}
}
