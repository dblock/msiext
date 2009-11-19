#include "StdAfxUnitTests.h"
#include "PrivilegeUnitTests.h"
#include "Privilege.h"

using namespace AppSecInc::LSA;
using namespace AppSecInc::UnitTests::LSA;

#define UnitTest_User _T("PrivilegeUT_User")
#define UnitTest_Password _T("Admin123!%")

CPPUNIT_TEST_SUITE_REGISTRATION(PrivilegeUnitTests);

void PrivilegeUnitTests::setUp()
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

void PrivilegeUnitTests::tearDown()
{
	DWORD dwResult = NetUserDel(NULL, UnitTest_User);
	std::stringstream error; error << "NetUserDel failed: " << AppSecInc::Formatter::FormatMessageFromLastErrorCodeA(dwResult);
	CPPUNIT_ASSERT_MESSAGE(error.str().c_str(), NERR_Success == dwResult);
}

void PrivilegeUnitTests::testPrivileges()
{
	LoggedOnUser user;
	user.Logon(UnitTest_User, UnitTest_Password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT);
	std::vector<Privilege> privileges = user.GetPrivileges();
	for(unsigned int i = 0; i < privileges.size(); i++)
	{
		std::wcout << std::endl << privileges[i].Name << L" (" << privileges[i].DisplayName << L"): " 
			<< ((privileges[i].Attributes & SE_PRIVILEGE_ENABLED) ? L"enabled" : L"disabled");
		CPPUNIT_ASSERT(user.HasPrivilege(privileges[i].Luid));
		// convert and compare in all directions
		CPPUNIT_ASSERT(AppSecInc::LSA::Privileges::GetPrivilege(privileges[i].Name).HighPart == privileges[i].Luid.HighPart);
		CPPUNIT_ASSERT(AppSecInc::LSA::Privileges::GetPrivilege(privileges[i].Name).LowPart == privileges[i].Luid.LowPart);
		CPPUNIT_ASSERT(AppSecInc::LSA::Privileges::GetPrivilegeName(privileges[i].Luid) == privileges[i].Name);
		CPPUNIT_ASSERT(AppSecInc::LSA::Privileges::GetPrivilegeDisplayName(privileges[i].Name) == privileges[i].DisplayName);
	}
}