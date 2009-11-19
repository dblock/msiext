#include "StdAfxUnitTests.h"
#include "CryptoPPCryptProviderUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::Crypt::CryptoPPCryptProviderUnitTests);

using namespace AppSecInc::UnitTests::Crypt;

void CryptoPPCryptProviderUnitTests::testGenerateKey(void)
{
    AppSecInc::Crypt::CryptoPPCryptProvider provider;
	std::string key = provider.GenerateKey();
	CPPUNIT_ASSERT(key.length() > 0);
}

void CryptoPPCryptProviderUnitTests::testEncryptDecrypt(void)
{
	char * testdata[] = 
	{
		"",
		"foo",
		"barbar",
	    "xxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyyyyyyyyyyyyyyzzzzzzzzzzzzzzzzzzzzzzzzzz",
	};

	for (int i = 0; i < sizeof(testdata) / sizeof(testdata[0]); i++)
	{
		AppSecInc::Crypt::CryptoPPCryptProvider provider;
        std::string encrypted = provider.Encrypt(testdata[i], "password");
        std::string decrypted = provider.Decrypt(encrypted, "password");
		CPPUNIT_ASSERT(strcmp(decrypted.c_str(), testdata[i]) == 0);
		CPPUNIT_ASSERT(decrypted.length() == strlen(testdata[i]));
	}
}

void CryptoPPCryptProviderUnitTests::testProtectUnprotect(void)
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
		AppSecInc::Crypt::CryptoPPCryptProvider provider;
        std::string encrypted = provider.Protect(testdata[i]);
        std::string decrypted = provider.Unprotect(encrypted);
		CPPUNIT_ASSERT(strcmp(decrypted.c_str(), testdata[i]) == 0);
		CPPUNIT_ASSERT(decrypted.length() == strlen(testdata[i]));
	}
}		
