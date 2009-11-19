#include "StdAfxUnitTests.h"
#include "AdsiUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::ActiveDirectory::AdsiUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::ActiveDirectory;

void AdsiUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"ActiveDirectory.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing ActiveDirectory.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "ADSI_GetAttributeValue"));
	::FreeLibrary(h);
}

void AdsiUnitTests::Test_ADSI_GetPropertyValue_RootDSE()
{
	CPPUNIT_IGNORE(NetSetupDomainName != AppSecInc::Net::DirectoryServices::GetJoinStatus().join_status);

	LPCWSTR properties[] = 
	{
		L"defaultNamingContext",
		L"rootDomainNamingContext"
	};

	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
	msiInstall.SetProperty(L"ADSI_LDAP_PATH", L"LDAP://RootDSE");

	for (int i = 0; i < ARRAYSIZE(properties); i++)
	{
		std::wstring property_name = properties[i];
		msiInstall.SetProperty(L"ADSI_PROPERTY_NAME", property_name);
		CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"ActiveDirectory.dll", L"ADSI_GetAttributeValue"));
		std::wstring property_value = msiInstall.GetProperty(L"ADSI_PROPERTY_VALUE");
		std::wcout << std::endl << property_name << L": " << property_value;
		CPPUNIT_ASSERT(property_value.length() > 0);
	}
}

void AdsiUnitTests::Test_ADSI_GetAttributeValue()
{
	CPPUNIT_IGNORE(NetSetupDomainName != AppSecInc::Net::DirectoryServices::GetJoinStatus().join_status);

    AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
	// get default naming context
	msiInstall.SetProperty(L"ADSI_LDAP_PATH", L"LDAP://RootDSE");
	msiInstall.SetProperty(L"ADSI_PROPERTY_NAME", L"defaultNamingContext");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"ActiveDirectory.dll", L"ADSI_GetAttributeValue"));
	std::wstring defaultNamingContext = msiInstall.GetProperty(L"ADSI_PROPERTY_VALUE");
	std::wcout << std::endl << L"defaultNamingContext: " << defaultNamingContext;
	// reconnect and get more
	std::wstring ldapPath = L"LDAP://" + defaultNamingContext;
	std::wcout << std::endl << ldapPath;
	msiInstall.SetProperty(L"ADSI_LDAP_PATH", ldapPath);

	LPCWSTR properties[] = 
	{
		L"dc", // DirectoryString
		L"instanceType", // Integer
		L"isCriticalSystemObject", // Boolean
	};

	for (int i = 0; i < ARRAYSIZE(properties); i++)
	{
		std::wstring property_name = properties[i];
		msiInstall.SetProperty(L"ADSI_PROPERTY_NAME", property_name);
		CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"ActiveDirectory.dll", L"ADSI_GetAttributeValue"));
		std::wstring property_value = msiInstall.GetProperty(L"ADSI_PROPERTY_VALUE");
		std::wcout << std::endl << property_name << L": " << property_value;
		CPPUNIT_ASSERT(property_value.length() > 0);
	}
}