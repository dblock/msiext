#include "StdAfxUnitTests.h"
#include "LocalGroupsUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::UserPrivileges::LocalGroupsUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::UserPrivileges;

void LocalGroupsUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"UserPrivileges.dll");
    boost::shared_ptr<void> h_ptr(h, ::FreeLibrary);
	CPPUNIT_ASSERT_MESSAGE("Missing UserPrivileges.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "LocalGroups_Immediate"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "LocalGroups_Deferred"));
}

void LocalGroupsUnitTests::Test_LocalGroups()
{
    AppSecInc::Msi::MsiShim hInstall;
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_UserPrivilegesUnitTests", L"LocalGroups.idt");

    MsiInstall msiInstall(hInstall);

    if (AppSecInc::LSA::LocalGroup::Exists(L"DemoLocalGroup1"))
        AppSecInc::LSA::LocalGroup::Delete(L"DemoLocalGroup1");
    
    if (AppSecInc::LSA::LocalGroup::Exists(L"DemoLocalGroup2"))
        AppSecInc::LSA::LocalGroup::Delete(L"DemoLocalGroup2");

    // execute the immediate CA that processes the LocalGroups table and sets 
    // CreateLocalGroups_Deferred and DeleteLocalGroups_Deferred property
    AppSecInc::Xml::XmlDocument deferred_xml;
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"UserPrivileges.dll", L"LocalGroups_Immediate"));
    deferred_xml.LoadXml(msiInstall.GetProperty(L"CreateLocalGroups_Deferred"));

    // there're 2 groups
    CPPUNIT_ASSERT(2 == deferred_xml.SelectNodes(L"//LocalGroup")->length);
    // both need to be created
    CPPUNIT_ASSERT(2 == deferred_xml.SelectNodes(L"//LocalGroup[@create='true']")->length);
    CPPUNIT_ASSERT(2 == deferred_xml.SelectNodes(L"//LocalGroup[@delete='false']")->length);
    // both are to be checked before they are created
    CPPUNIT_ASSERT(2 == deferred_xml.SelectNodes(L"//LocalGroup[@check='true']")->length);

    // execute the deferred CA
    msiInstall.SetProperty(L"CustomActionData", deferred_xml.GetXml());
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"UserPrivileges.dll", L"LocalGroups_Deferred"));

    CPPUNIT_ASSERT(AppSecInc::LSA::LocalGroup::Exists(L"DemoLocalGroup1"));
    CPPUNIT_ASSERT(AppSecInc::LSA::LocalGroup::Exists(L"DemoLocalGroup2"));

    AppSecInc::LSA::LocalGroup::Delete(L"DemoLocalGroup1");
    AppSecInc::LSA::LocalGroup::Delete(L"DemoLocalGroup2");
}
