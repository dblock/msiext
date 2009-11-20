#include "StdAfxUnitTests.h"
#include "AccountUnitTests.h"
#include "Account.h"

using namespace AppSecInc::LSA;
using namespace AppSecInc::UnitTests::LSA;

#define UnitTest_User _T("AccountUnitTest_User")
#define UnitTest_DomainUser _T("nycapt35k.com\\buildapp")
#define UnitTest_Password _T("Password123!%")

CPPUNIT_TEST_SUITE_REGISTRATION(AccountUnitTests);

void AccountUnitTests::setUp()
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

void AccountUnitTests::tearDown()
{
	DWORD dwResult = NetUserDel(NULL, UnitTest_User);
	std::stringstream error; error << "NetUserDel failed: " << AppSecInc::Formatter::FormatMessageFromLastErrorCodeA(dwResult);
	CPPUNIT_ASSERT_MESSAGE(error.str().c_str(), NERR_Success == dwResult);
}

void AccountUnitTests::testLookupAccount()
{
    Account account;
    account.LookupAccount(UnitTest_User);
    std::wcout << std::endl << L"Domain: " << account.GetDomain();
    std::wcout << std::endl << L"Sid: " << account.GetSid().ToString();
	CPPUNIT_ASSERT(account.GetDomain().length() == wcslen(account.GetDomain().c_str()));
    CPPUNIT_ASSERT(account.GetSid().GetUse() == SidTypeUser);
    CPPUNIT_ASSERT(account.GetSid().IsValid());
}

void AccountUnitTests::testLookupSid()
{
    Account account_user;
    account_user.LookupAccount(UnitTest_User);
	Account account_sid;
	account_sid.LookupSid(static_cast<PSID>(account_user.GetSid()));
	std::wcout << std::endl << account_sid.GetUserName();
	CPPUNIT_ASSERT(account_sid.GetUserName().length() == wcslen(account_sid.GetUserName().c_str()));
	CPPUNIT_ASSERT(account_sid.GetDomain().length() == wcslen(account_sid.GetDomain().c_str()));
	CPPUNIT_ASSERT(account_sid.GetUserName() == UnitTest_User);
}

void AccountUnitTests::testGetAddRemoveUserRights()
{
    Account account;
    account.LookupAccount(UnitTest_User);
    CPPUNIT_ASSERT(account.GetSid().GetUse() == SidTypeUser);
    std::wcout << std::endl << L"Domain: " << account.GetDomain();
    std::vector<std::wstring> rights;
    account.GetUserRights(rights);
    CPPUNIT_ASSERT(rights.size() == 0);
    // grant the user a privilege
    account.AddUserRight(L"SeServiceLogonRight");
    account.GetUserRights(rights);
    CPPUNIT_ASSERT(rights.size() == 1);
    for each(const std::wstring& right in rights)
    {
        std::wcout << std::endl << L" " << right;
    }
	account.RemoveUserRight(L"SeServiceLogonRight");
    account.GetUserRights(rights);
    CPPUNIT_ASSERT(rights.size() == 0);
}

void AccountUnitTests::testGetAddRemoveUserRights_Domain()
{
    Account account;
    account.LookupAccount(UnitTest_DomainUser);
    CPPUNIT_ASSERT(account.GetSid().GetUse() == SidTypeUser);
    std::wcout << std::endl << L"Domain: " << account.GetDomain();
    std::vector<std::wstring> rights_before;
    account.GetUserRights(rights_before);
    // grant the user a privilege
    account.AddUserRight(L"SeDenyServiceLogonRight");
	std::vector<std::wstring> rights_after;
    account.GetUserRights(rights_after);
    CPPUNIT_ASSERT(rights_after.size() == rights_before.size() + 1);
    for each(const std::wstring& right in rights_after)
    {
        std::wcout << std::endl << L" " << right;
    }
	account.RemoveUserRight(L"SeDenyServiceLogonRight");
	std::vector<std::wstring> rights_after_remove;
    account.GetUserRights(rights_after_remove);
    CPPUNIT_ASSERT(rights_before.size() == rights_after_remove.size());
}

void AccountUnitTests::testGetCurrentUserName()
{
    std::wstring username = Account::GetCurrentUserName();
    
    wchar_t pszUsername[256];
    DWORD dwBuffer = sizeof(pszUsername);
    CPPUNIT_ASSERT(::GetUserNameW(pszUsername, & dwBuffer));

    std::wcout << std::endl << L"Username: " << username;
    CPPUNIT_ASSERT(username == pszUsername);
}

void AccountUnitTests::testGetCurrentUserNameFormat()
{
	std::wstring username = Account::GetCurrentUserName(NameSamCompatible);
    
	wchar_t pszUsername[256];
	DWORD dwBuffer = sizeof(pszUsername);
	CPPUNIT_ASSERT(::GetUserNameExW(NameSamCompatible, pszUsername, & dwBuffer));

	std::wcout << L" => " << username;
	CPPUNIT_ASSERT(username == pszUsername);
}

void AccountUnitTests::testGetCurrentUserNameFormatDomain()
{
	CPPUNIT_IGNORE(NetSetupDomainName != AppSecInc::Net::DirectoryServices::GetJoinStatus().join_status);

	EXTENDED_NAME_FORMAT usernameformats[] =
	{
		NameSamCompatible,
		NameFullyQualifiedDN,
		NameDisplay, 
		NameUniqueId,
		NameCanonical,
		NameUserPrincipal,
		NameCanonicalEx,
		// NameServicePrincipal, // \todo fails with "No mapping between account names and security IDs was done." (?)
		NameDnsDomain
	};

	for (int i = 0; i < ARRAYSIZE(usernameformats); i++)
	{
		std::wcout << std::endl << usernameformats[i];
		std::wstring username = Account::GetCurrentUserName(usernameformats[i]);
	    
		wchar_t pszUsername[256];
		DWORD dwBuffer = sizeof(pszUsername);
		CPPUNIT_ASSERT(::GetUserNameExW(usernameformats[i], pszUsername, & dwBuffer));

		std::wcout << L" => " << username;
		CPPUNIT_ASSERT(username == pszUsername);
	}
}

void AccountUnitTests::testCreate()
{
    std::wstring username = L"UnitTest_User_Create";
    // create a user
    Account::Create(username, AppSecInc::Com::GenerateGUIDStringW());
    // can't create the same user twice
    try
    {
        Account::Create(username, AppSecInc::Com::GenerateGUIDStringW());
        throw "Expected std::exception";
    }
    catch(std::exception& ex)
    {
        std::cout << std::endl << "Expected exception: " << ex.what();
    }
    CPPUNIT_ASSERT(Account::Exists(username));
    // delete the user
    Account::Delete(username);
    CPPUNIT_ASSERT(! Account::Exists(username));    
}

void AccountUnitTests::testDelete()
{
    std::wstring username = L"UnitTest_User_Delete";
    // create a user
    Account::Create(username, AppSecInc::Com::GenerateGUIDStringW());
    // delete the user
    Account::Delete(username);
    CPPUNIT_ASSERT(! Account::Exists(username));        
    // can't delete the user twice
    try
    {
        Account::Delete(username);
        throw "Expected std::exception";
    }
    catch(std::exception& ex)
    {
        std::cout << std::endl << "Expected exception: " << ex.what();
    }
}

void AccountUnitTests::testExists()
{
    // user setup in setUp returns true
    CPPUNIT_ASSERT(Account::Exists(UnitTest_User));
    // blank username doesn't exist, consistent with NetUser API
    CPPUNIT_ASSERT(! Account::Exists(L""));
    // user that doesn't exist returns false
    std::wstring username = L"UnitTest_User_Exists";
    CPPUNIT_ASSERT(! Account::Exists(username));
    // create a user
    Account::Create(username, AppSecInc::Com::GenerateGUIDStringW());
    CPPUNIT_ASSERT(Account::Exists(username));
    // delete the user
    Account::Delete(username);
    CPPUNIT_ASSERT(! Account::Exists(username));
}

void AccountUnitTests::testGetFQN()
{
	struct TestData
	{
		LPCWSTR input;
		LPCWSTR domain;
		LPCWSTR username;
		LPCWSTR fqn;
	};

	TestData testdata[] = 
	{
		{ L"", L"", L"", L"" },
		{ L"username", L"", L"username", L"username" },
		{ L"domain\\", L"domain", L"", L"domain\\" },
		{ L"domain\\username", L"domain", L"username", L"domain\\username" },
		{ L"username@domain", L"domain", L"username", L"domain\\username" },
	};

	for (int i = 0; i < ARRAYSIZE(testdata); i++)
	{
		AppSecInc::LSA::Account acct;
		acct.SetFQN(testdata[i].fqn);
		CPPUNIT_ASSERT(acct.GetUserName() == testdata[i].username);
		CPPUNIT_ASSERT(acct.GetDomain() == testdata[i].domain);
		CPPUNIT_ASSERT(acct.GetFQN() == testdata[i].fqn);
	}
}

void AccountUnitTests::testTranslateDomain()
{
	CPPUNIT_IGNORE(NetSetupDomainName != AppSecInc::Net::DirectoryServices::GetJoinStatus().join_status);

	EXTENDED_NAME_FORMAT usernameformats[] =
	{
		NameFullyQualifiedDN,
		NameSamCompatible,
		NameDisplay, 
		NameUniqueId,
		NameCanonical,
		NameUserPrincipal,
		// NameCanonicalEx,
		// NameServicePrincipal, // \todo fails with "No mapping between account names and security IDs was done." (?)
		// NameDnsDomain, // \todo fails with "0x80070525: The specified user does not exist."
	};

	std::wstring username = Account::GetCurrentUserName(NameSamCompatible);
	std::wcout << std::endl << L"Translating: " << username;

	for (int i = 0; i < ARRAYSIZE(usernameformats); i++)
	{
		std::wcout << std::endl << L" " << usernameformats[i] << L": ";
		std::wstring translated_username = Account::Translate(username, NameSamCompatible, usernameformats[i]);
		std::wcout << translated_username;
		std::wstring expected_username = Account::GetCurrentUserName(usernameformats[i]);
		CPPUNIT_ASSERT(AppSecInc::StringUtils::comparei(translated_username, expected_username));
	}
}
