#include "StdAfxUnitTests.h"
#include "LocalUsersUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::UserPrivileges::LocalUsersUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::UserPrivileges;

void LocalUsersUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"UserPrivileges.dll");
    boost::shared_ptr<void> h_ptr(h, ::FreeLibrary);
	CPPUNIT_ASSERT_MESSAGE("Missing UserPrivileges.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "LocalUsers_Immediate"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "LocalUsers_Deferred"));
}

void LocalUsersUnitTests::Test_LocalUsers()
{
    AppSecInc::Msi::MsiShim hInstall;
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_UserPrivilegesUnitTests", L"LocalUsers.idt");

    MsiInstall msiInstall(hInstall);

    if (AppSecInc::LSA::Account::Exists(L"DemoLocalUser1"))
        AppSecInc::LSA::Account::Delete(L"DemoLocalUser1");
    
    if (AppSecInc::LSA::Account::Exists(L"DemoLocalUser2"))
        AppSecInc::LSA::Account::Delete(L"DemoLocalUser2");

    // execute the immediate CA that processes the LocalUsers table and sets 
    // CreateLocalUsers_Deferred and DeleteLocalUsers_Deferred property
    AppSecInc::Xml::XmlDocument deferred_xml;
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"UserPrivileges.dll", L"LocalUsers_Immediate"));
    deferred_xml.LoadXml(msiInstall.GetProperty(L"CreateLocalUsers_Deferred"));

    // there're 2 users
    CPPUNIT_ASSERT(2 == deferred_xml.SelectNodes(L"//LocalUser")->length);
    // both need to be created
    CPPUNIT_ASSERT(2 == deferred_xml.SelectNodes(L"//LocalUser[@create='true']")->length);
    CPPUNIT_ASSERT(2 == deferred_xml.SelectNodes(L"//LocalUser[@delete='false']")->length);
    // both are to be checked before they are created
    CPPUNIT_ASSERT(2 == deferred_xml.SelectNodes(L"//LocalUser[@check='true']")->length);

    // execute the deferred CA
    msiInstall.SetProperty(L"CustomActionData", deferred_xml.GetXml());
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"UserPrivileges.dll", L"LocalUsers_Deferred"));

    CPPUNIT_ASSERT(AppSecInc::LSA::Account::Exists(L"DemoLocalUser1"));
    CPPUNIT_ASSERT(AppSecInc::LSA::Account::Exists(L"DemoLocalUser2"));

    AppSecInc::LSA::Account::Delete(L"DemoLocalUser1");
    AppSecInc::LSA::Account::Delete(L"DemoLocalUser2");
}