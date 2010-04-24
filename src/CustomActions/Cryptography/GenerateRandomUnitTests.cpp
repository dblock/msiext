#include "StdAfxUnitTests.h"
#include "GenerateRandomUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::Cryptography::GenerateRandomUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::Cryptography;

void GenerateRandomUnitTests::Test_GenerateRandom()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

	msiInstall.SetProperty(L"GENERATE_RANDOM_LENGTH", L"10");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"Cryptography.dll", L"GenerateRandomString"));
	std::wstring result1 = msiInstall.GetProperty(L"GENERATE_RANDOM_RESULT");
	std::wcout << std::endl << L"Random 1: " << result1;
	CPPUNIT_ASSERT(result1.length() >= 10);
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"Cryptography.dll", L"GenerateRandomString"));
	std::wstring result2 = msiInstall.GetProperty(L"GENERATE_RANDOM_RESULT");
	std::wcout << std::endl << L"Random 2: " << result2;
	CPPUNIT_ASSERT(result2.length() >= 10);
	CPPUNIT_ASSERT(result1 != result2);
}

void GenerateRandomUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"Cryptography.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing Cryptography.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "GenerateRandomString"));
	::FreeModule(h);
}
