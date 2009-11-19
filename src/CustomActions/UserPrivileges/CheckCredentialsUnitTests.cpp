#include "StdAfxUnitTests.h"
#include "CheckCredentialsUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::UserPrivileges::CheckCredentialsUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::UserPrivileges;

#define UnitTest_User _T("AdseUnitTest_User")
#define UnitTest_Password _T("Admin123!%")

void CheckCredentialsUnitTests::Test_CheckCredentials()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

    msiInstall.SetProperty(L"LOGON_USERNAME", UnitTest_User);
	msiInstall.SetProperty(L"LOGON_PASSWORD", UnitTest_Password);
	msiInstall.SetProperty(L"LOGON_TYPE", L"LOGON32_LOGON_NETWORK");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"UserPrivileges.dll", L"CheckCredentials"));
    std::wstring valid = msiInstall.GetProperty(L"LOGON_VALID");
	std::wcout << std::endl << L"Valid: " << valid;
    CPPUNIT_ASSERT_MESSAGE("Expected to have Valid=1.", valid == L"1");
}

void CheckCredentialsUnitTests::Test_CheckCredentials_Invalid()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

    msiInstall.SetProperty(L"LOGON_USERNAME", UnitTest_User);
	msiInstall.SetProperty(L"LOGON_PASSWORD", L"bogus");
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"UserPrivileges.dll", L"CheckCredentials"));
    std::wstring valid = msiInstall.GetProperty(L"LOGON_VALID");
    std::wcout << std::endl << L"Valid: " << valid;
    CPPUNIT_ASSERT_MESSAGE("Expected to have Valid=0.", valid == L"0");
}

void CheckCredentialsUnitTests::setUp()
{
	USER_INFO_1 ui;
	ui.usri1_name = UnitTest_User;
	ui.usri1_password = UnitTest_Password;
	ui.usri1_priv = USER_PRIV_USER;
	ui.usri1_home_dir = NULL;
	ui.usri1_comment = NULL;
	ui.usri1_flags = UF_SCRIPT;
	ui.usri1_script_path = NULL;
	DWORD dwResult = NetUserAdd(NULL, 1, reinterpret_cast<LPBYTE>(& ui), NULL);
	std::stringstream error; error << "NetUserAdd failed: " << AppSecInc::Formatter::FormatMessageFromLastErrorCodeA(dwResult);
	CPPUNIT_ASSERT_MESSAGE(error.str().c_str(), NERR_Success == dwResult);	
}

void CheckCredentialsUnitTests::tearDown()
{
	DWORD dwResult = NetUserDel(NULL, UnitTest_User);
	std::stringstream error; error << "NetUserDel failed: " << AppSecInc::Formatter::FormatMessageFromLastErrorCodeA(dwResult);
	CPPUNIT_ASSERT_MESSAGE(error.str().c_str(), NERR_Success == dwResult);
}

void CheckCredentialsUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"UserPrivileges.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing UserPrivileges.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "CheckPrivilege"));
	::FreeLibrary(h);
}
