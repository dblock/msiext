#include "StdAfxUnitTests.h"
#include "CheckPrivilegeUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::UserPrivileges::CheckPrivilegeUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::UserPrivileges;

#define UnitTest_User _T("AdseUnitTest_User")
#define UnitTest_DomainUser _T("nycapt35k.com\\buildapp")
#define UnitTest_Password _T("Admin123!%")

void CheckPrivilegeUnitTests::Test_CheckPrivilege()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

    msiInstall.SetProperty(L"LOGON_USERNAME", UnitTest_User);
    msiInstall.SetProperty(L"LOGON_PRIVILEGE", L"SeServiceLogonRight");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"UserPrivileges.dll", L"CheckPrivilege"));
    std::wstring HasPrivilege = msiInstall.GetProperty(L"LOGON_HAS_PRIVILEGE");
	std::wcout << std::endl << L"HasPrivilege: " << HasPrivilege;
    CPPUNIT_ASSERT_MESSAGE("Expected to have HasPrivilege=0.", HasPrivilege == L"0");

    AppSecInc::LSA::Account account;
    account.LookupAccount(UnitTest_User);
    account.AddUserRight(L"SeServiceLogonRight");

	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"UserPrivileges.dll", L"CheckPrivilege"));
	HasPrivilege = msiInstall.GetProperty(L"LOGON_HAS_PRIVILEGE");
    std::wcout << std::endl << L"HasPrivilege: " << HasPrivilege;
    CPPUNIT_ASSERT_MESSAGE("Expected to have HasPrivilege=1.", HasPrivilege== L"1");
}

void CheckPrivilegeUnitTests::Test_CheckPrivilege_Domain()
{
	CPPUNIT_IGNORE(NetSetupDomainName != AppSecInc::Net::DirectoryServices::GetJoinStatus().join_status);

	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

    msiInstall.SetProperty(L"LOGON_USERNAME", UnitTest_DomainUser);
    msiInstall.SetProperty(L"LOGON_PRIVILEGE", L"SeDenyServiceLogonRight");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"UserPrivileges.dll", L"CheckPrivilege"));
    std::wstring HasPrivilege = msiInstall.GetProperty(L"LOGON_HAS_PRIVILEGE");
	std::wcout << std::endl << L"HasPrivilege: " << HasPrivilege;
    CPPUNIT_ASSERT_MESSAGE("Expected to have HasPrivilege=0.", HasPrivilege == L"0");

    AppSecInc::LSA::Account account;
    account.LookupAccount(UnitTest_DomainUser);
    account.AddUserRight(L"SeDenyServiceLogonRight");

	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"UserPrivileges.dll", L"CheckPrivilege"));
	HasPrivilege = msiInstall.GetProperty(L"LOGON_HAS_PRIVILEGE");
    std::wcout << std::endl << L"HasPrivilege: " << HasPrivilege;
    CPPUNIT_ASSERT_MESSAGE("Expected to have HasPrivilege=1.", HasPrivilege == L"1");

    account.RemoveUserRight(L"SeDenyServiceLogonRight");

	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"UserPrivileges.dll", L"CheckPrivilege"));
	HasPrivilege = msiInstall.GetProperty(L"LOGON_HAS_PRIVILEGE");
    std::wcout << std::endl << L"HasPrivilege: " << HasPrivilege;
    CPPUNIT_ASSERT_MESSAGE("Expected to have HasPrivilege=1.", HasPrivilege == L"0");
}

void CheckPrivilegeUnitTests::setUp()
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

void CheckPrivilegeUnitTests::tearDown()
{
	DWORD dwResult = NetUserDel(NULL, UnitTest_User);
	std::stringstream error; error << "NetUserDel failed: " << AppSecInc::Formatter::FormatMessageFromLastErrorCodeA(dwResult);
	CPPUNIT_ASSERT_MESSAGE(error.str().c_str(), NERR_Success == dwResult);
}

void CheckPrivilegeUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"UserPrivileges.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing UserPrivileges.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "CheckCredentials"));
	::FreeModule(h);
}

void CheckPrivilegeUnitTests::Test_CheckPrivilege_LogonUser()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
	// test user credentials
    msiInstall.SetProperty(L"LOGON_USERNAME", UnitTest_User);
    msiInstall.SetProperty(L"LOGON_PASSWORD", UnitTest_Password);
	// network logon
    msiInstall.SetProperty(L"LOGON_TYPE", L"LOGON32_LOGON_NETWORK");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"UserPrivileges.dll", L"CheckCredentials"));
    std::wstring logonValidNetwork = msiInstall.GetProperty(L"LOGON_VALID");
	std::wcout << std::endl << L"Logon valid (Network): " << logonValidNetwork;
    CPPUNIT_ASSERT_MESSAGE("Expected to have LOGON_VALID = 1.", logonValidNetwork == L"1");
	// service logon
    msiInstall.SetProperty(L"LOGON_TYPE", L"LOGON32_LOGON_SERVICE");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"UserPrivileges.dll", L"CheckCredentials"));
    std::wstring logonValidService = msiInstall.GetProperty(L"LOGON_VALID");
	std::wcout << std::endl << L"Logon valid (SeServiceLogonRight missing): " << logonValidService;
    CPPUNIT_ASSERT_MESSAGE("Expected to have LOGON_VALID = 0.", logonValidService == L"0");
	// grant the user SeServiceLogonRight
    AppSecInc::LSA::Account account;
    account.LookupAccount(UnitTest_User);
    account.AddUserRight(L"SeServiceLogonRight");
	// logon again
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"UserPrivileges.dll", L"CheckCredentials"));
    std::wstring logonValidServiceGranted = msiInstall.GetProperty(L"LOGON_VALID");
	std::wcout << std::endl << L"Logon valid (SeServiceLogonRight granted): " << logonValidServiceGranted;
    CPPUNIT_ASSERT_MESSAGE("Expected to have LOGON_VALID = 1.", logonValidServiceGranted == L"1");
}