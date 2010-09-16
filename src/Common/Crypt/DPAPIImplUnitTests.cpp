#include "StdAfxUnitTests.h"
#include "DPAPIImplUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION( AppSecInc::UnitTests::Crypt::DPAPIImplUnitTests );

using namespace AppSecInc::UnitTests::Crypt;

void DPAPIImplUnitTests::testProtectUnprotect(void)
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
        std::string encrypted = AppSecInc::Crypt::DPAPIImpl::Protect(testdata[i], "entropy");
        std::string decrypted = AppSecInc::Crypt::DPAPIImpl::UnProtect(encrypted, "entropy");
		CPPUNIT_ASSERT(strcmp(decrypted.c_str(), testdata[i]) == 0);
		CPPUNIT_ASSERT(decrypted.length() == strlen(testdata[i]));
	}
}

void DPAPIImplUnitTests::testProtectUnprotectW(void)
{
	wchar_t * testdata[] = 
	{
		L"",
		L"hello World",
		L"HeLlO 7452397-\u1234\uB0000340234=124 random #$_)sdsdsd*_)*#",
	    L"xxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyyyyyyyyyyyyyyzzzzzzzzzzzzzzzzzzzzzzzzzz\u4C21"
	};

	for (int i = 0; i < sizeof(testdata) / sizeof(testdata[0]); i++)
	{
        std::wstring encrypted = AppSecInc::Crypt::DPAPIImpl::Protect(testdata[i], L"entropy");
        std::wstring decrypted = AppSecInc::Crypt::DPAPIImpl::UnProtect(encrypted, L"entropy");
		CPPUNIT_ASSERT(wcscmp(decrypted.c_str(), testdata[i]) == 0);
		CPPUNIT_ASSERT(decrypted.length() == wcslen(testdata[i]));
	}
}

