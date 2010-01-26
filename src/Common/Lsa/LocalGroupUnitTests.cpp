#include "StdAfxUnitTests.h"
#include "LocalGroupUnitTests.h"
#include "LocalGroup.h"
#include "Account.h"

using namespace AppSecInc::LSA;
using namespace AppSecInc::UnitTests::LSA;

#define UnitTest_DomainUser_Netbios _T("NYCAPT35K\\buildapp")
#define UnitTest_DomainUser_Dns _T("nycapt35k.com\\buildapp")

CPPUNIT_TEST_SUITE_REGISTRATION(GroupUnitTests);

void GroupUnitTests::testCreate()
{
    std::wstring name = AppSecInc::Com::GenerateGUIDStringW();
    // create a user
    LocalGroup::Create(name);
    // can't create the same user twice
    try
    {
        LocalGroup::Create(name);
        throw "Expected std::exception";
    }
    catch(std::exception& ex)
    {
        std::cout << std::endl << "Expected exception: " << ex.what();
    }
    CPPUNIT_ASSERT(LocalGroup::Exists(name));
    // delete the user
    LocalGroup::Delete(name);
    CPPUNIT_ASSERT(! LocalGroup::Exists(name));    
}

void GroupUnitTests::testDelete()
{
    std::wstring name = AppSecInc::Com::GenerateGUIDStringW();
    // create a user
    LocalGroup::Create(name);
    // delete the user
    LocalGroup::Delete(name);
    CPPUNIT_ASSERT(! LocalGroup::Exists(name));        
    // can't delete the user twice
    try
    {
        LocalGroup::Delete(name);
        throw "Expected std::exception";
    }
    catch(std::exception& ex)
    {
        std::cout << std::endl << "Expected exception: " << ex.what();
    }
}

void GroupUnitTests::testExists()
{
    // blank name doesn't exist, consistent with NetUser API
    CPPUNIT_ASSERT(! LocalGroup::Exists(L""));
    // user that doesn't exist returns false
    std::wstring name = AppSecInc::Com::GenerateGUIDStringW();
    CPPUNIT_ASSERT(! LocalGroup::Exists(name));
    // create a user
    LocalGroup::Create(name);
    CPPUNIT_ASSERT(LocalGroup::Exists(name));
    // delete the user
    LocalGroup::Delete(name);
    CPPUNIT_ASSERT(! LocalGroup::Exists(name));
}

void GroupUnitTests::testMember()
{
    std::wstring groupname = AppSecInc::Com::GenerateGUIDStringW();
    std::wstring username = L"GroupUnitTests_User"; // \todo: derive a random/unique username

	if (Account::Exists(username)) Account::Delete(username);
	Account::Create(username, AppSecInc::Com::GenerateGUIDStringW());
    LocalGroup::Create(groupname);

    CPPUNIT_ASSERT(! LocalGroup::IsMember(groupname, username));
    CPPUNIT_ASSERT(LocalGroup::GetMembers(groupname).size() == 0);
    LocalGroup::AddMember(groupname, username);
    CPPUNIT_ASSERT(LocalGroup::IsMember(groupname, username));
    std::vector<Account> members = LocalGroup::GetMembers(groupname);
    for each(const Account& member in members)
    {
        std::wcout << std::endl << L" " << member.GetUserName();
    }
    CPPUNIT_ASSERT(members.size() == 1);
    CPPUNIT_ASSERT(members[0].GetUserName() == username);
    // adding the same member the second time doesn't work
    try
    {
        LocalGroup::AddMember(groupname, username);
        throw "Expected std::exception";
    }
    catch(std::exception& ex)
    {
        std::cout << std::endl << "Expected exception: " << ex.what();
    }

    LocalGroup::DeleteMember(groupname, username);
    CPPUNIT_ASSERT(! LocalGroup::IsMember(groupname, username));
    LocalGroup::Delete(groupname);
    Account::Delete(username);
}

void GroupUnitTests::testDomainMember()
{
	CPPUNIT_IGNORE(NetSetupDomainName != AppSecInc::Net::DirectoryServices::GetJoinStatus().join_status);

	std::wstring username = UnitTest_DomainUser_Netbios;
	std::wstring dns_username = UnitTest_DomainUser_Dns;
	std::wstring groupname = AppSecInc::Com::GenerateGUIDStringW();
    LocalGroup::Create(groupname);
    CPPUNIT_ASSERT(! LocalGroup::IsMember(groupname, username));
    CPPUNIT_ASSERT(LocalGroup::GetMembers(groupname).size() == 0);
    LocalGroup::AddMember(groupname, username);
    CPPUNIT_ASSERT(LocalGroup::IsMember(groupname, username));
	CPPUNIT_ASSERT(LocalGroup::IsMember(groupname, dns_username));
    std::vector<Account> members = LocalGroup::GetMembers(groupname);
    for each(const Account& member in members)
    {
        std::wcout << std::endl << L" " << member.GetFQN();
    }
    CPPUNIT_ASSERT(members.size() == 1);
	CPPUNIT_ASSERT(AppSecInc::StringUtils::comparei(members[0].GetFQN(), username));
    LocalGroup::Delete(groupname);
}
