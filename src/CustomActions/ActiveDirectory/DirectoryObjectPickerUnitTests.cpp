#include "StdAfxUnitTests.h"
#include "DirectoryObjectPickerUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::ActiveDirectory::DirectoryObjectPickerUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::ActiveDirectory;

void DirectoryObjectPickerUnitTests::Test_DirectoryObjectPicker_Users()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
    msiInstall.SetProperty(L"DSOP_SCOPE_TYPES", L"DSOP_SCOPE_TYPE_TARGET_COMPUTER|DSOP_SCOPE_TYPE_EXTERNAL_UPLEVEL_DOMAIN|DSOP_SCOPE_TYPE_ENTERPRISE_DOMAIN");
    msiInstall.SetProperty(L"DSOP_SCOPE_FLAGS", L"DSOP_SCOPE_FLAG_STARTING_SCOPE|DSOP_SCOPE_FLAG_DEFAULT_FILTER_USERS");
    msiInstall.SetProperty(L"DSOP_SCOPE_FILTER_FLAGS", L"DSOP_FILTER_USERS");
    msiInstall.SetProperty(L"DSOP_DOWNLEVEL_SCOPE_FILTER_FLAGS", L"DSOP_DOWNLEVEL_FILTER_USERS");

	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"ActiveDirectory.dll", L"DirectoryObjectPicker"));

    std::wstring dsop_name;
    std::wstring dsop_class;
    std::wstring dsop_adspath;
    std::wstring dsop_upn;

    dsop_name = msiInstall.GetProperty(L"DSOP_NAME");
    dsop_class = msiInstall.GetProperty(L"DSOP_CLASS"); 
    dsop_adspath = msiInstall.GetProperty(L"DSOP_ADSPATH"); 
    dsop_upn = msiInstall.GetProperty(L"DSOP_UPN");

	std::wcout << std::endl << dsop_class << L": " << dsop_name << L" (" << dsop_adspath << L") [" << dsop_upn << L"]";
	std::wcout << std::endl << L"Retained: " << (dsop_upn.length() ? dsop_upn : dsop_name);
}

void DirectoryObjectPickerUnitTests::Test_DirectoryObjectPicker_Computers()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
    msiInstall.SetProperty(L"DSOP_SCOPE_TYPES", L"DSOP_SCOPE_TYPE_USER_ENTERED_UPLEVEL_SCOPE|DSOP_SCOPE_TYPE_USER_ENTERED_DOWNLEVEL_SCOPE|DSOP_SCOPE_TYPE_GLOBAL_CATALOG|DSOP_SCOPE_TYPE_EXTERNAL_UPLEVEL_DOMAIN|DSOP_SCOPE_TYPE_EXTERNAL_DOWNLEVEL_DOMAIN|DSOP_SCOPE_TYPE_WORKGROUP|DSOP_SCOPE_TYPE_UPLEVEL_JOINED_DOMAIN|DSOP_SCOPE_TYPE_DOWNLEVEL_JOINED_DOMAIN");
    msiInstall.SetProperty(L"DSOP_SCOPE_FLAGS", L"");
    msiInstall.SetProperty(L"DSOP_SCOPE_FILTER_FLAGS", L"DSOP_FILTER_COMPUTERS");
    msiInstall.SetProperty(L"DSOP_DOWNLEVEL_SCOPE_FILTER_FLAGS", L"DSOP_DOWNLEVEL_FILTER_COMPUTERS|DSOP_DOWNLEVEL_FILTER_GLOBAL_GROUPS|DSOP_DOWNLEVEL_FILTER_ALL_WELLKNOWN_SIDS");

	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"ActiveDirectory.dll", L"DirectoryObjectPicker"));

    std::wstring dsop_name;
    std::wstring dsop_class;
    std::wstring dsop_adspath;
    std::wstring dsop_upn;

    dsop_name = msiInstall.GetProperty(L"DSOP_NAME");
    dsop_class = msiInstall.GetProperty(L"DSOP_CLASS"); 
    dsop_adspath = msiInstall.GetProperty(L"DSOP_ADSPATH"); 
    dsop_upn = msiInstall.GetProperty(L"DSOP_UPN");

    std::wcout << std::endl << dsop_class << L": " << dsop_name << L" (" << dsop_adspath << L") [" << dsop_upn << L"]";
	std::wcout << std::endl << L"Retained: " << (dsop_upn.length() ? dsop_upn : dsop_name);
}

void DirectoryObjectPickerUnitTests::Test_DirectoryObjectPicker_Raw()
{
    CComPtr<IDsObjectPicker> p = NULL;

    CPPUNIT_ASSERT(S_OK == CoCreateInstance(CLSID_DsObjectPicker, NULL, CLSCTX_INPROC_SERVER, 
		IID_IDsObjectPicker, reinterpret_cast<LPVOID *>(& p)));

    DSOP_INIT_INFO InitInfo;
    DSOP_SCOPE_INIT_INFO Scopes[] =
    {
        {
            sizeof(DSOP_SCOPE_INIT_INFO),
            DSOP_SCOPE_TYPE_USER_ENTERED_UPLEVEL_SCOPE |
            DSOP_SCOPE_TYPE_USER_ENTERED_DOWNLEVEL_SCOPE |
            DSOP_SCOPE_TYPE_GLOBAL_CATALOG |
            DSOP_SCOPE_TYPE_EXTERNAL_UPLEVEL_DOMAIN |
            DSOP_SCOPE_TYPE_EXTERNAL_DOWNLEVEL_DOMAIN |
            DSOP_SCOPE_TYPE_WORKGROUP |
            DSOP_SCOPE_TYPE_UPLEVEL_JOINED_DOMAIN |
            DSOP_SCOPE_TYPE_DOWNLEVEL_JOINED_DOMAIN,
            0,
            {
                {
                    DSOP_FILTER_COMPUTERS,
                    0,
                    0
                },
                DSOP_DOWNLEVEL_FILTER_COMPUTERS |
                DSOP_DOWNLEVEL_FILTER_GLOBAL_GROUPS |
                DSOP_DOWNLEVEL_FILTER_ALL_WELLKNOWN_SIDS
            },
            NULL,
            NULL,
            S_OK
        },
    };

    InitInfo.cbSize = sizeof(InitInfo);
    InitInfo.pwzTargetComputer = NULL;
    InitInfo.cDsScopeInfos = sizeof(Scopes) / sizeof(Scopes[0]);
    InitInfo.aDsScopeInfos = Scopes;
    InitInfo.flOptions = DSOP_SCOPE_TYPE_TARGET_COMPUTER;
    InitInfo.cAttributesToFetch = 0;
    InitInfo.apwzAttributeNames = NULL;

    CPPUNIT_ASSERT(S_OK == p->Initialize(& InitInfo));

    HWND hwndParent = ::GetConsoleWindow();
    if (hwndParent == NULL) hwndParent = ::GetForegroundWindow();

    CComPtr<IDataObject> pdo;
    CPPUNIT_ASSERT(SUCCEEDED(p->InvokeDialog(hwndParent, &pdo)));
}

void DirectoryObjectPickerUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"ActiveDirectory.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing ActiveDirectory.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "DirectoryObjectPicker"));
	::FreeLibrary(h);
}
