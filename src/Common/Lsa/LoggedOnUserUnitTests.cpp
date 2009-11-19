#include "StdAfxUnitTests.h"
#include "LoggedOnUserUnitTests.h"
#include "LoggedOnUser.h"

using namespace AppSecInc::LSA;
using namespace AppSecInc::UnitTests::LSA;

#define UnitTest_User _T("LoggedOnUserUT_User")
#define UnitTest_Password _T("Admin123!%")

CPPUNIT_TEST_SUITE_REGISTRATION(LoggedOnUserUnitTests);

void LoggedOnUserUnitTests::setUp()
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

void LoggedOnUserUnitTests::tearDown()
{
	DWORD dwResult = NetUserDel(NULL, UnitTest_User);
	std::stringstream error; error << "NetUserDel failed: " << AppSecInc::Formatter::FormatMessageFromLastErrorCodeA(dwResult);
	CPPUNIT_ASSERT_MESSAGE(error.str().c_str(), NERR_Success == dwResult);
}

void LoggedOnUserUnitTests::testLogonLogout()
{
    LoggedOnUser user;
    CPPUNIT_ASSERT(! user.IsLoggedOn());
    user.Logon(UnitTest_User, L"", UnitTest_Password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT);
    CPPUNIT_ASSERT(user.IsLoggedOn());
    user.Logout();
    CPPUNIT_ASSERT(! user.IsLoggedOn());
}

void LoggedOnUserUnitTests::testLogonSyntax()
{
    LoggedOnUser user;
    user.Logon(UnitTest_User, UnitTest_Password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT);
    user.Logon(std::wstring(L".\\") + UnitTest_User, UnitTest_Password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT);
    user.Logon(UnitTest_User + std::wstring(L"@."), UnitTest_Password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT);
}

void LoggedOnUserUnitTests::testLogonGetSid()
{
    LoggedOnUser user;
    user.Logon(UnitTest_User, UnitTest_Password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT);
	std::wstring sid = user.GetSid().ToString();
	std::wcout << std::endl << L"Logon Sid: " << sid;
	CPPUNIT_ASSERT(sid.size() > 0);
	CPPUNIT_ASSERT(AppSecInc::StringUtils::startsWith(sid, L"S-"));
	// match SID with the looked up SID
	Account account;
	account.LookupAccount(UnitTest_User);
	std::wcout << std::endl << L"Lookup Sid: " << account.GetSid();
	CPPUNIT_ASSERT(sid == account.GetSid().ToString());
}

void LoggedOnUserUnitTests::testLogonGetPrivileges()
{
	LoggedOnUser user;
	user.Logon(UnitTest_User, UnitTest_Password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT);
	std::vector<Privilege> privileges = user.GetPrivileges();
	for(unsigned int i = 0; i < privileges.size(); i++)
	{
		std::wcout << std::endl << privileges[i].Name << L" (" << privileges[i].DisplayName << L"): " 
			<< ((privileges[i].Attributes & SE_PRIVILEGE_ENABLED) ? L"enabled" : L"disabled");
		CPPUNIT_ASSERT(wcslen(privileges[i].Name.c_str()) == privileges[i].Name.size());
		CPPUNIT_ASSERT(wcslen(privileges[i].DisplayName.c_str()) == privileges[i].DisplayName.size());
		CPPUNIT_ASSERT(user.HasPrivilege(privileges[i].Luid));
	}
}

void LoggedOnUserUnitTests::testLogonGetGroups()
{
	LoggedOnUser user;
	user.Logon(UnitTest_User, UnitTest_Password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT);
	std::vector<Sid> groups = user.GetGroups();
	CPPUNIT_ASSERT(groups.size() > 0);
	for(unsigned int i = 0; i < groups.size(); i++)
	{
		std::wcout << std::endl << groups[i].ToString();
	}
}