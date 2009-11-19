#include "StdAfxUnitTests.h"
#include "MsiImpersonatedInstallUnitTests.h"

using namespace AppSecInc;
using namespace AppSecInc::UnitTests;
using namespace AppSecInc::UnitTests::Msi;
using namespace AppSecInc::Msi;

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::Msi::MsiImpersonatedInstallUnitTests);

#define UnitTest_User _T("MsiIInstall_User")
#define UnitTest_Password _T("Admin123!%")

void MsiImpersonatedInstallUnitTests::testImpersonated()
{
    MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
    msiInstall.SetProperty(L"IMPERSONATE_USERNAME", UnitTest_User);
    msiInstall.SetProperty(L"IMPERSONATE_PASSWORD", UnitTest_Password);

    {
        MsiImpersonatedInstall msiImpersonatedInstall(hInstall);
        // test that impersonator impersonated
        std::wstring username = AppSecInc::LSA::Account::GetCurrentUserName();
        std::wcout << std::endl << L"Username: " << username;
        CPPUNIT_ASSERT(username == UnitTest_User);
    }

    // test that impersonator reverted to self
    CPPUNIT_ASSERT(AppSecInc::LSA::Account::GetCurrentUserName() != UnitTest_User);
}

void MsiImpersonatedInstallUnitTests::setUp()
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

void MsiImpersonatedInstallUnitTests::tearDown()
{
	DWORD dwResult = NetUserDel(NULL, UnitTest_User);
	std::stringstream error; error << "NetUserDel failed: " << AppSecInc::Formatter::FormatMessageFromLastErrorCodeA(dwResult);
	CPPUNIT_ASSERT_MESSAGE(error.str().c_str(), NERR_Success == dwResult);
}
