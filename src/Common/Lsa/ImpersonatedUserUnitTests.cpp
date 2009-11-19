#include "StdAfxUnitTests.h"
#include "ImpersonatedUserUnitTests.h"
#include "LoggedOnUser.h"
#include "ImpersonatedUser.h"

using namespace AppSecInc::LSA;
using namespace AppSecInc::UnitTests::LSA;

#define UnitTest_User _T("ImpersUserUT_User")
#define UnitTest_Password _T("Admin123!%")

CPPUNIT_TEST_SUITE_REGISTRATION(ImpersonatedUserUnitTests);

void ImpersonatedUserUnitTests::setUp()
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

void ImpersonatedUserUnitTests::tearDown()
{
	DWORD dwResult = NetUserDel(NULL, UnitTest_User);
	std::stringstream error; error << "NetUserDel failed: " << AppSecInc::Formatter::FormatMessageFromLastErrorCodeA(dwResult);
	CPPUNIT_ASSERT_MESSAGE(error.str().c_str(), NERR_Success == dwResult);
}

void ImpersonatedUserUnitTests::testImpersonate()
{
    ImpersonatedUser user;
    CPPUNIT_ASSERT(! user.IsImpersonated());
    user.Logon(UnitTest_User, L"", UnitTest_Password, LOGON32_LOGON_NETWORK, LOGON32_PROVIDER_DEFAULT);
    CPPUNIT_ASSERT(user.IsLoggedOn());
    user.Impersonate();
    CPPUNIT_ASSERT(user.IsImpersonated());
    user.RevertToSelf();
    CPPUNIT_ASSERT(! user.IsImpersonated());
    user.Logout();
    CPPUNIT_ASSERT(! user.IsImpersonated());
}

