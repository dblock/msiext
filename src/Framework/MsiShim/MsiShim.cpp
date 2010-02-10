#include "StdAfx.h"
#include "MsiShim.h"

MsiShim::MsiShim()
{
    _filename = AppSecInc::File::GetTemporaryFileNameW();
	AppSecInc::StringUtils::replace(_filename, L".tmp", L".msi");
    _database.Create(_filename);

    MsiDatabaseSummaryEntry summary_entries[] = 
    {
        { PID_TITLE, VT_LPSTR, L"MSI Shim Database" },
        { PID_SUBJECT, VT_LPSTR, L"MSI Shim Database" },
        { PID_AUTHOR, VT_LPSTR, L"AppSecInc." },
        { PID_TEMPLATE, VT_LPSTR, ";1033" },
        { PID_REVNUMBER, VT_LPSTR, "{00869AA3-A32E-4398-89B2-5C5DC7328C7C}" },
        { PID_PAGECOUNT, VT_I4, 100 },
        { PID_WORDCOUNT, VT_I4, 100 },
    };

	// A valid MSI must have a summary for MsiOpenPackage to succeed
    _database.SetSummary(summary_entries, ARRAYSIZE(summary_entries));
	
	// Windows 7 requires a property table with a ProductCode value
	_database.Execute(L"CREATE TABLE `Property` (`Property` CHAR(72) NOT NULL, `Value` CHAR(0) NOT NULL LOCALIZABLE PRIMARY KEY `Property`)");
	_database.Execute(L"INSERT INTO `Property` (`Property`, `Value`) VALUES ('ProductCode', '{07F7FB1B-992E-4a2d-805C-C803C98CFC42}')");
    
	_database.Commit();
    _database.Close();

    Open(_filename);

    ::MsiSetInternalUI(INSTALLUILEVEL_NONE, NULL);
}

void MsiShim::Import(const std::wstring& path, const std::wstring& file)
{
    Close();

    _database.Open(_filename, MSIDBOPEN_DIRECT);
    _database.Import(path, file);
    _database.Commit();
    _database.Close();

    Open(_filename);
}

MsiShim::~MsiShim()
{
    Close();
    AppSecInc::File::FileDelete(_filename);
}

int MsiShim::ExecuteCA(const std::wstring& dll, const std::wstring& name)
{
    std::wcout << std::endl << L"Executing \"" << name << L"\"";

    HMODULE h = NULL;

    CHECK_WIN32_BOOL(NULL != (h = ::LoadLibrary(dll.c_str())),
        L"Error loading " << dll);

    typedef int (__stdcall * LPCUSTOMACTION) (MSIHANDLE h);

    LPCUSTOMACTION lpCA = reinterpret_cast<LPCUSTOMACTION>(GetProcAddress(
        h, AppSecInc::StringUtils::wc2mb(name).c_str()));

    CHECK_WIN32_BOOL(lpCA != NULL,
        L"Error getting entry point for " << name);

    int rc = lpCA(m_h);

    if (rc != ERROR_SUCCESS)
    {
        MsiInstall msiInstall(m_h);
        std::wstring err = msiInstall.GetProperty(L"CA_ERROR");
        if (! err.empty()) std::wcout << std::endl << err;
    }

    ::FreeModule(h);
    return rc;
}
