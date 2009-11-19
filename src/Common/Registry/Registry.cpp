#include "StdAfx.h"
#include "Registry.h"

bool AppSecInc::Registry::KeyExists(HKEY root, const std::wstring& key, const std::wstring& name)
{
    HKEY reg = NULL;
    DWORD dwErr = ::RegOpenKey(root, key.c_str(), & reg);
    boost::shared_ptr<void> reg_ptr(reg, ::CloseHandle);

    bool result = true;
    switch(dwErr)
    {
    case ERROR_SUCCESS:
        break;
    case ERROR_FILE_NOT_FOUND:
        result = false;
        break;
    default:
        CHECK_WIN32_DWORD(dwErr,
            L"Error checking whether \"" << key << L"\" exists");
        break;        
    }

    if (result && ! name.empty())
    {
        DWORD dwSize = 0;
        DWORD dwType = 0;
        dwErr = ::RegQueryValueEx(reg, name.c_str(), 0, & dwType, NULL, & dwSize);
        switch(dwErr)
        {
        case ERROR_SUCCESS:
        case ERROR_INSUFFICIENT_BUFFER:
            break;
        case ERROR_FILE_NOT_FOUND:
            result = false;
            break;
        default:
            CHECK_WIN32_DWORD(dwErr,
                L"Error checking whether \"" << key << L"\\" << name << L"\" exists");
            break;        
        }
    }

    return result;
}

std::wstring AppSecInc::Registry::GetStringValue(HKEY root, const std::wstring& key, const std::wstring& name)
{
    HKEY reg = NULL;

    CHECK_WIN32_DWORD(::RegOpenKey(root, key.c_str(), & reg), 
        L"Error opening " << key);

    boost::shared_ptr<void> reg_ptr(reg, ::CloseHandle);

    DWORD dwSize = 0;
    DWORD dwType = 0;

    CHECK_WIN32_DWORD(::RegQueryValueEx(reg, name.c_str(), 0, & dwType, NULL, & dwSize),
        L"Error quering " << key << L"\\" << name << L" value size");

	CHECK_BOOL(dwType == REG_SZ || dwType == REG_EXPAND_SZ,
		L"Invalid registry value type: " << dwType);

    std::wstring value;
    if (dwSize > 0)
    {
        value.resize(dwSize / sizeof(WCHAR));

        CHECK_WIN32_DWORD(::RegQueryValueEx(reg, name.c_str(), 0, & dwType, reinterpret_cast<LPBYTE>(& * value.begin()), & dwSize),
            L"Error quering " << key << L"\\" << name << L" data");

        value.resize((dwSize - 1) / sizeof(WCHAR));
    }

    return value;
}

void AppSecInc::Registry::CopyBranch(HKEY sourceRoot, const std::wstring& keySrcRoot, HKEY targetRoot, const std::wstring& keyDestRoot)
{
	DWORD index, subkeys, values, maxdata, type;
	DWORD namesize = MAX_PATH;
	TCHAR lpName[MAX_PATH] = {0};
	std::vector<char> data;

    HKEY hkeySrcRoot = NULL;
    HKEY hkeyDestRoot = NULL;

	CHECK_WIN32_DWORD(::RegOpenKeyEx(sourceRoot, keySrcRoot.c_str(), 0, KEY_READ, & hkeySrcRoot),
		L"Error opening " << keySrcRoot);

    boost::shared_ptr<void> hkeySrcRoot_ptr(hkeySrcRoot, ::RegCloseKey);

	// Get information, so that we know how much memory to allocate
	CHECK_WIN32_DWORD(::RegQueryInfoKey(hkeySrcRoot, NULL, NULL, NULL, & subkeys, NULL, NULL, & values, NULL, & maxdata, NULL, NULL),
		L"RegQueryInfoKey failed");

	data.resize(maxdata);

	// Walk through the values
	DWORD datasize = maxdata;

	CHECK_WIN32_DWORD(::RegCreateKeyEx(targetRoot, keyDestRoot.c_str(), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, & hkeyDestRoot, NULL),
	L"Error creating " << keyDestRoot);

	boost::shared_ptr<void> hkeyDestRoot_ptr(hkeyDestRoot, ::RegCloseKey);

	for (index = 0; index < values; index++)
	{
		CHECK_WIN32_DWORD(::RegEnumValue(hkeySrcRoot, index, lpName, & namesize, NULL, & type, reinterpret_cast<LPBYTE>(& * data.begin()), & datasize),
			L"RegEnumValue failed");

		CHECK_WIN32_DWORD(::RegSetValueEx(hkeyDestRoot, lpName, 0L, type, reinterpret_cast<LPBYTE>(& * data.begin()), datasize),
            L"RegSetValueEx failed");

		namesize = MAX_PATH;
		datasize = maxdata;
	}

	// Walk through all subkeys, and recursively call this function to copy the tree
	for (index = 0; index < subkeys; index++)
	{
		namesize = MAX_PATH;
		CHECK_WIN32_DWORD(RegEnumKeyEx(hkeySrcRoot, index, lpName, & namesize, NULL, NULL, NULL, NULL),
			"RegEnumKeyEx failed");
		AppSecInc::Registry::CopyBranch(sourceRoot, keySrcRoot + L"\\" + lpName, targetRoot, keyDestRoot + L"\\" + lpName);
	}
}

void AppSecInc::Registry::DeleteBranch(HKEY root, const std::wstring& key)
{
	DWORD namesize, subkeys, maxkeyname;
	if (ERROR_SUCCESS != ::RegDeleteKey(root, key.c_str()))
	{
		HKEY reg = NULL;

		CHECK_WIN32_DWORD(::RegOpenKeyEx(root, key.c_str(), 0, KEY_READ, & reg), 
			L"Error opening " << key);

        boost::shared_ptr<void> reg_ptr(reg, ::RegCloseKey); 

		// Get information, so that we know how much memory to allocate
		CHECK_WIN32_DWORD(::RegQueryInfoKey(reg, NULL, NULL, NULL, & subkeys, & maxkeyname, NULL, NULL, NULL, NULL, NULL, NULL), 
			L"RegQueryInfoKey failed");

		// Walk through all subkeys, and recursively call this function to delete the tree
		TCHAR lpName[MAX_PATH] = {0};
		namesize = MAX_PATH;

		while (ERROR_SUCCESS == ::RegEnumKeyEx(reg, 0, lpName, & namesize, NULL, NULL, NULL, NULL))
		{
			AppSecInc::Registry::DeleteBranch(root, key + L"\\" + lpName);
			namesize = MAX_PATH;
		}

		CHECK_WIN32_DWORD(::RegDeleteKey(root, key.c_str()), L"Error deleting " << key);
	}
}

void AppSecInc::Registry::CreateKey(HKEY root, const std::wstring& srckey)
{
	HKEY hkeySrcRoot = NULL;

	CHECK_WIN32_DWORD(::RegCreateKeyEx(root, srckey.c_str(), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, & hkeySrcRoot, NULL),
		L"Error creating " << srckey);

    boost::shared_ptr<void> hkeySrcRoot_ptr(hkeySrcRoot, ::RegCloseKey);
}


void AppSecInc::Registry::SetStringValue(HKEY root, const std::wstring& srckey, const std::wstring &name, const std::wstring& value)
{
	HKEY hkeySrcRoot = NULL;

	CHECK_WIN32_DWORD(::RegCreateKeyEx(root, srckey.c_str(), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_SET_VALUE, NULL, & hkeySrcRoot, NULL),
		L"Error creating " << srckey);

    boost::shared_ptr<void> hkeySrcRoot_ptr(hkeySrcRoot, ::RegCloseKey);

	CHECK_WIN32_DWORD(::RegSetValueEx(hkeySrcRoot, name.c_str(), 0L, REG_SZ, reinterpret_cast<const byte *>(value.c_str()), (value.length() + 1) * sizeof(WCHAR)),
		L"Error creating " << srckey << "\\" << name);
}
