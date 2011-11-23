#include "StdAfxUnitTests.h"
#include "UserInfoUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::UserPrivileges::UserInfoUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::UserPrivileges;

void UserInfoUnitTests::Test_GetUserInfo()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"UserPrivileges.dll", L"GetUserInfo"));
    std::wstring userfqn = msiInstall.GetProperty(L"USER_FQN");
    std::wstring username = msiInstall.GetProperty(L"USER_NAME");
    std::wstring userdomain = msiInstall.GetProperty(L"USER_DOMAIN");
    std::wstring sid = msiInstall.GetProperty(L"USER_SID");
    CPPUNIT_ASSERT(username.length() > 0);
    CPPUNIT_ASSERT(sid.length() > 0);
	std::wcout << std::endl << username << L" (domain: " << userdomain << L") [" << sid << L"]";
}

void UserInfoUnitTests::Test_GetUserNameFormatted()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
	msiInstall.SetProperty(L"USERNAME_FORMAT", L"NameSamCompatible");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"UserPrivileges.dll", L"GetUserNameFormatted"));
	std::wstring userfqn = msiInstall.GetProperty(L"USER_FQN");
	CPPUNIT_ASSERT(userfqn.length() > 0);
	std::wcout << std::endl << L"NameSamCompatible: " << userfqn;
}

void UserInfoUnitTests::Test_GetUserNameFormattedDomain()
{
	CPPUNIT_IGNORE(NetSetupDomainName != AppSecInc::Net::DirectoryServices::GetJoinStatus().join_status);

	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

	LPCWSTR usernameformats[] =
	{
		L"NameFullyQualifiedDN",
		L"NameSamCompatible",
		L"NameDisplay", 
		L"NameUniqueId",
		L"NameCanonical",
		L"NameUserPrincipal",
		L"NameCanonicalEx",
		// L"NameServicePrincipal", \todo fails with "No mapping between account names and security IDs was done." (?)
		L"NameDnsDomain"
	};

	for (int i = 0; i < ARRAYSIZE(usernameformats); i++)
	{
		msiInstall.SetProperty(L"USERNAME_FORMAT", usernameformats[i]);
		CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"UserPrivileges.dll", L"GetUserNameFormatted"));
		std::wstring userfqn = msiInstall.GetProperty(L"USER_FQN");
		CPPUNIT_ASSERT(userfqn.length() > 0);
		std::wcout << std::endl << usernameformats[i] << L": " << userfqn;
	}
}

void UserInfoUnitTests::Test_GetAccountSid()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
	msiInstall.SetProperty(L"ACCOUNT_NAME", L"BUILTIN\\Administrators");
	msiInstall.SetProperty(L"ACCOUNT_SID_FORMAT", L"SidString");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"UserPrivileges.dll", L"GetAccountSid"));
	std::wstring accountSid = msiInstall.GetProperty(L"ACCOUNT_SID");
	CPPUNIT_ASSERT(accountSid.length() > 0);
	CPPUNIT_ASSERT(accountSid == L"S-1-5-32-544");
	std::wcout << std::endl << L"Account SID: " << accountSid;

	msiInstall.SetProperty(L"ACCOUNT_SID_FORMAT", L"SidStringHex");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"UserPrivileges.dll", L"GetAccountSid"));
	std::wstring accountSidHex = msiInstall.GetProperty(L"ACCOUNT_SID");
	CPPUNIT_ASSERT(accountSidHex.length() > 0);
	CPPUNIT_ASSERT(accountSidHex == L"0x01020000000000052000000020020000");
	std::wcout << std::endl << L"Account SID (HEX): " << accountSidHex;
}

void UserInfoUnitTests::Test_GetAccountSid_DefaultParam()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
	msiInstall.SetProperty(L"ACCOUNT_NAME", L"BUILTIN\\Administrators");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"UserPrivileges.dll", L"GetAccountSid"));
	std::wstring accountSid = msiInstall.GetProperty(L"ACCOUNT_SID");
	CPPUNIT_ASSERT(accountSid.length() > 0);
	CPPUNIT_ASSERT(accountSid == L"S-1-5-32-544");
	std::wcout << std::endl << L"Account SID: " << accountSid;
}

void UserInfoUnitTests::Test_TranslateNameFormatted()
{
	CPPUNIT_IGNORE(NetSetupDomainName != AppSecInc::Net::DirectoryServices::GetJoinStatus().join_status);

	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

	LPCWSTR usernameformats[] =
	{
		L"NameFullyQualifiedDN",
		L"NameSamCompatible",
		L"NameDisplay", 
		L"NameUniqueId",
		L"NameCanonical",
		L"NameUserPrincipal",
		L"NameCanonicalEx"
		// L"NameServicePrincipal", \todo fails with "No mapping between account names and security IDs was done." (?)
		//L"NameDnsDomain" \todo fails with "Error translating from format 0 to 12, error fetching result size: The specified account does not exist."
	};
	
	msiInstall.SetProperty(L"USERNAME_FORMAT", L"NameSamCompatible");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"UserPrivileges.dll", L"GetUserNameFormatted"));
	std::wstring username = msiInstall.GetProperty(L"USER_FQN");
	CPPUNIT_ASSERT(username.length() > 0);

	for (int i = 0; i < ARRAYSIZE(usernameformats); i++)
	{
		msiInstall.SetProperty(L"ACCOUNT_NAME", username);
		msiInstall.SetProperty(L"ACCOUNT_NAME_FORMAT", usernameformats[i]);
		CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"UserPrivileges.dll", L"TranslateNameFormatted"));
		std::wstring userfqn = msiInstall.GetProperty(L"ACCOUNT_NAME");
		CPPUNIT_ASSERT(userfqn.length() > 0);
		std::wcout << std::endl << usernameformats[i] << L": " << userfqn;
	}
}

void UserInfoUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"UserPrivileges.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing UserPrivileges.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "GetUserInfo"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "GetUserNameFormatted"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "GetAccountSid"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "TranslateNameFormatted"));
	::FreeModule(h);
}
