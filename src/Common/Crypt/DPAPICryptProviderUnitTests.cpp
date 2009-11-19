#include "StdAfxUnitTests.h"
#include "DPAPICryptProviderUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION( AppSecInc::UnitTests::Crypt::DPAPICryptProviderUnitTests );

using namespace AppSecInc::UnitTests::Crypt;

void DPAPICryptProviderUnitTests::testProtectUnprotect(void)
{
	char * testdata[] = 
	{
		"",
		"hello World",
		"HeLlO 7452397-0340234=124 random #$_)sdsdsd*_)*#",
	    "xxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyyyyyyyyyyyyyyzzzzzzzzzzzzzzzzzzzzzzzzzz"
	};

	for (int i = 0; i < sizeof(testdata) / sizeof(testdata[0]); i++)
	{
		AppSecInc::Crypt::DPAPICryptProvider provider;
        std::string encrypted = provider.Protect(testdata[i]);
        CPPUNIT_ASSERT(AppSecInc::StringUtils::startsWith(encrypted, AppSecInc::Crypt::DPAPICryptProvider::DPAPI_ENCRYPTED_PREFIX));
		CPPUNIT_ASSERT(strncmp(encrypted.c_str(), AppSecInc::Crypt::DPAPICryptProvider::DPAPI_ENCRYPTED_PREFIX.c_str(), AppSecInc::Crypt::DPAPICryptProvider::DPAPI_ENCRYPTED_PREFIX.length()) == 0);
        std::string decrypted = provider.Unprotect(encrypted);
		CPPUNIT_ASSERT(strcmp(decrypted.c_str(), testdata[i]) == 0);
		CPPUNIT_ASSERT(decrypted.length() == strlen(testdata[i]));
	}
}		
