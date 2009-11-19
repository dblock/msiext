#include "StdAfxUnitTests.h"
#include "LocalGroupMembersUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::UserPrivileges::LocalGroupMembersUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::UserPrivileges;

void LocalGroupMembersUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"UserPrivileges.dll");
    boost::shared_ptr<void> h_ptr(h, ::FreeLibrary);
	CPPUNIT_ASSERT_MESSAGE("Missing UserPrivileges.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "LocalGroupMembers_Immediate"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "LocalGroupMembers_Deferred"));
}

void LocalGroupMembersUnitTests::Test_LocalGroupMembers()
{
    AppSecInc::Msi::MsiShim hInstall;
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_UserPrivilegesUnitTests", L"LocalGroups.idt");
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_UserPrivilegesUnitTests", L"LocalUsers.idt");
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_UserPrivilegesUnitTests", L"LocalGroupMembers.idt");

    MsiInstall msiInstall(hInstall);

    AppSecInc::Xml::XmlDocument deferred_xml;
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"UserPrivileges.dll", L"LocalGroupMembers_Immediate"));
    deferred_xml.LoadXml(msiInstall.GetProperty(L"AddLocalGroupMembers_Deferred"));

    // there're 3 group members
    CPPUNIT_ASSERT(3 == deferred_xml.SelectNodes(L"//LocalGroupMembers/LocalGroupMember")->length);
    // all need to be added
    CPPUNIT_ASSERT(3 == deferred_xml.SelectNodes(L"//LocalGroupMember[@add='true']")->length);
    CPPUNIT_ASSERT(3 == deferred_xml.SelectNodes(L"//LocalGroupMember[@remove='false']")->length);
    CPPUNIT_ASSERT(3 == deferred_xml.SelectNodes(L"//LocalGroupMember[@check='true']")->length);

    // delete users and groups from previous runs
    if (AppSecInc::LSA::Account::Exists(L"DemoLocalUser1")) AppSecInc::LSA::Account::Delete(L"DemoLocalUser1");
    if (AppSecInc::LSA::Account::Exists(L"DemoLocalUser2")) AppSecInc::LSA::Account::Delete(L"DemoLocalUser2");
    if (AppSecInc::LSA::LocalGroup::Exists(L"DemoLocalGroup1")) AppSecInc::LSA::LocalGroup::Delete(L"DemoLocalGroup1");
    if (AppSecInc::LSA::LocalGroup::Exists(L"DemoLocalGroup2")) AppSecInc::LSA::LocalGroup::Delete(L"DemoLocalGroup2");

    // create the users and groups
    AppSecInc::LSA::Account::Create(L"DemoLocalUser1", AppSecInc::Com::GenerateGUIDStringW());
    AppSecInc::LSA::Account::Create(L"DemoLocalUser2", AppSecInc::Com::GenerateGUIDStringW());
    AppSecInc::LSA::LocalGroup::Create(L"DemoLocalGroup1");
    AppSecInc::LSA::LocalGroup::Create(L"DemoLocalGroup2");

    // execute the deferred CA
    msiInstall.SetProperty(L"CustomActionData", deferred_xml.GetXml());
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"UserPrivileges.dll", L"LocalGroupMembers_Deferred"));

    std::wcout << std::endl << L"DemoLocalGroup1";
    std::vector<AppSecInc::LSA::Account> demolocalgroup1_members = AppSecInc::LSA::LocalGroup::GetMembers(L"DemoLocalGroup1");
    for each(const AppSecInc::LSA::Account& user in demolocalgroup1_members)
        std::wcout << std::endl << L" " << user.GetUserName() << L" " << user.GetSid();
    CPPUNIT_ASSERT(demolocalgroup1_members.size() == 2);

    std::wcout << std::endl << L"DemoLocalGroup2";
    std::vector<AppSecInc::LSA::Account> demolocalgroup2_members = AppSecInc::LSA::LocalGroup::GetMembers(L"DemoLocalGroup2");
    for each(const AppSecInc::LSA::Account& user in demolocalgroup2_members)
        std::wcout << std::endl << L" " << user.GetUserName() << L" " << user.GetSid();;
    CPPUNIT_ASSERT(demolocalgroup2_members.size() == 1);

    CPPUNIT_ASSERT(AppSecInc::LSA::LocalGroup::IsMember(L"DemoLocalGroup1", L"DemoLocalUser1"));
    CPPUNIT_ASSERT(AppSecInc::LSA::LocalGroup::IsMember(L"DemoLocalGroup1", L"DemoLocalUser2"));
    CPPUNIT_ASSERT(AppSecInc::LSA::LocalGroup::IsMember(L"DemoLocalGroup2", L"DemoLocalUser1"));

    AppSecInc::LSA::Account::Delete(L"DemoLocalUser1");
    AppSecInc::LSA::Account::Delete(L"DemoLocalUser2");
    AppSecInc::LSA::LocalGroup::Delete(L"DemoLocalGroup1");
    AppSecInc::LSA::LocalGroup::Delete(L"DemoLocalGroup2");
}