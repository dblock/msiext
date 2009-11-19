#include "StdAfxUnitTests.h"
#include "CryptProviderUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION( AppSecInc::UnitTests::Crypt::CryptProviderUnitTests );

using namespace AppSecInc::UnitTests::Crypt;

void CryptProviderUnitTests::testAllProvidersProtectUnprotect(void)
{
	AppSecInc::Crypt::CryptoPPCryptProvider cryptoPPCryptProvider;
	AppSecInc::Crypt::DPAPICryptProvider dpapiCryptProvider;

	AppSecInc::Crypt::CryptProvider * providers[] = 
	{
		& cryptoPPCryptProvider,
		& dpapiCryptProvider,
	};

	for (int i = 0; i < ARRAYSIZE(providers); i++)
	{
		testSpecificProviderProtectUnprotect(providers[i]);
	}
}

void CryptProviderUnitTests::testSpecificProviderProtectUnprotect(AppSecInc::Crypt::CryptProvider * p)
{
	int i;
	char * testdata[] = 
	{
		"",
		"foo",
		"barbar",
	    "xxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyyyyyyyyyyyyyyzzzzzzzzzzzzzzzzzzzzzzzzzz"
	};

	for (i = 0; i < ARRAYSIZE(testdata); i++)
	{
        std::string encrypted = p->Protect(testdata[i]);
		CPPUNIT_ASSERT(encrypted.size() >= strlen(testdata[i]));
        std::string decrypted = p->Unprotect(encrypted);
		CPPUNIT_ASSERT(decrypted.length() == strlen(testdata[i]));
		CPPUNIT_ASSERT(strcmp(testdata[i], decrypted.c_str()) == 0);
	}
}
