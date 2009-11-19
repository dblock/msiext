#include "StdAfxUnitTests.h"
#include "DirectoryServicesUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::ActiveDirectory::DirectoryServicesUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::ActiveDirectory;

void DirectoryServicesUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"ActiveDirectory.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing ActiveDirectory.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "DirectoryGetDcName"));
	::FreeLibrary(h);
}

void DirectoryServicesUnitTests::Test_DirectoryGetDcName()
{
	CPPUNIT_IGNORE(NetSetupDomainName != AppSecInc::Net::DirectoryServices::GetJoinStatus().join_status);

	// find the domain controller
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
	//msiInstall.SetProperty(L"DS_COMPUTERNAME", L""); // local machine
	//msiInstall.SetProperty(L"DS_DOMAINNAME", L""); // local domain
	//msiInstall.SetProperty(L"DS_SITENAME", L""); // local site
	msiInstall.SetProperty(L"DS_FLAGS", L"DS_IP_REQUIRED|DS_ONLY_LDAP_NEEDED|DS_RETURN_DNS_NAME");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"ActiveDirectory.dll", L"DirectoryGetDcName"));

	std::wstring DomainControllerName = msiInstall.GetProperty(L"DS_DOMAINCONTROLLER_NAME");
	std::wstring DomainControllerAddress = msiInstall.GetProperty(L"DS_DOMAINCONTROLLER_ADDRESS");
	std::wstring DomainName = msiInstall.GetProperty(L"DS_DOMAIN_NAME");
	CPPUNIT_ASSERT(! DomainControllerName.empty());
	CPPUNIT_ASSERT(! DomainControllerAddress.empty());
	CPPUNIT_ASSERT(! DomainName.empty());

	std::wcout << std::endl << DomainControllerName << L" (" << DomainControllerAddress << L") @ " << DomainName;

	// connect to this DC and get its properties
	LPCWSTR properties[] = 
	{
		L"dc"
	};

	std::wstringstream ldap; ldap << L"LDAP://" << DomainControllerName;
	msiInstall.SetProperty(L"ADSI_LDAP_PATH", ldap.str());

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