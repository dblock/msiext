#include "StdAfxUnitTests.h"
#include "CheckMembershipUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::UserPrivileges::CheckMembershipUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::UserPrivileges;

#define UnitTest_User _T("AdseUnitTest_User")
#define UnitTest_Password _T("Admin123!%")

void CheckMembershipUnitTests::Test_CheckMembership()
{
	MsiShim hInstall;
	MsiInstall msiInstall(hInstall);
	msiInstall.SetProperty(L"IMPERSONATE_LOGON_TYPE", L"LOGON32_LOGON_NETWORK");
	msiInstall.SetProperty(L"IMPERSONATE_USERNAME", UnitTest_User);
	msiInstall.SetProperty(L"IMPERSONATE_PASSWORD", UnitTest_Password);	
	
	struct TestData
	{
		LPCWSTR sid;
		LPCWSTR member;
	};

	TestData testdata[] = 
	{
		{ L"S-1-5-32-545", L"1" }, // Users
		{ L"S-1-5-32-544", L"0" }, // Administrators
	};

	for (int i = 0; i < ARRAYSIZE(testdata); i++)
	{
		msiInstall.SetProperty(L"SID", testdata[i].sid);
		CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"UserPrivileges.dll", L"CheckMembership"));
		std::wstring isMember = msiInstall.GetProperty(L"LOGON_IS_MEMBER");
		std::wcout << std::endl << L"LOGON_IS_MEMBER: " << isMember;
		CPPUNIT_ASSERT(isMember == testdata[i].member);
	}
}

void CheckMembershipUnitTests::setUp()
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

void CheckMembershipUnitTests::tearDown()
{
	DWORD dwResult = NetUserDel(NULL, UnitTest_User);
	std::stringstream error; error << "NetUserDel failed: " << AppSecInc::Formatter::FormatMessageFromLastErrorCodeA(dwResult);
	CPPUNIT_ASSERT_MESSAGE(error.str().c_str(), NERR_Success == dwResult);
}

void CheckMembershipUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"UserPrivileges.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing UserPrivileges.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "CheckMembership"));
	::FreeModule(h);
}