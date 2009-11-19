#include "StdAfxUnitTests.h"
#include "CryptProtectDataHexUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::Cryptography::CryptProtectDataHexUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::Cryptography;

void CryptProtectDataHexUnitTests::Test_HexCryptProtectDataHex()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

    typedef struct
    {
        LPCWSTR input;
        LPCWSTR entropy;
        LPCWSTR description;
        LPCWSTR flags;
    } TestData;

    TestData testdata[] =
    {
        { L"", L"", L"", L"" },
        { L"test", L"", L"description", L"" },
        { L"test", L"entropy", L"description", L"" },
        { L"", L"", L"", L"CRYPTPROTECT_LOCAL_MACHINE|CRYPTPROTECT_UI_FORBIDDEN" },
        { L"test", L"", L"description", L"CRYPTPROTECT_LOCAL_MACHINE|CRYPTPROTECT_UI_FORBIDDEN" },
        { L"", L"entropy", L"", L"CRYPTPROTECT_LOCAL_MACHINE|CRYPTPROTECT_UI_FORBIDDEN" },
        { L"test", L"entropy", L"description", L"CRYPTPROTECT_LOCAL_MACHINE|CRYPTPROTECT_UI_FORBIDDEN" }
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        // protect
        msiInstall.SetProperty(L"CRYPTPROTECT_DATA", testdata[i].input);
        msiInstall.SetProperty(L"CRYPTPROTECT_ENTROPY", testdata[i].entropy);
        msiInstall.SetProperty(L"CRYPTPROTECT_DESCRIPTION", testdata[i].description);
        msiInstall.SetProperty(L"CRYPTPROTECT_FLAGS", testdata[i].flags);
        CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"Cryptography.dll", L"CryptProtectDataHex"));
        std::wstring protected_output = msiInstall.GetProperty(L"CRYPTPROTECT_RESULT");
        // unprotect
        msiInstall.SetProperty(L"CRYPTUNPROTECT_DATA", protected_output);
        msiInstall.SetProperty(L"CRYPTUNPROTECT_ENTROPY", testdata[i].entropy);
        msiInstall.SetProperty(L"CRYPTUNPROTECT_FLAGS", testdata[i].flags);
        CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"Cryptography.dll", L"CryptUnprotectDataHex"));
        std::wstring unprotected_output = msiInstall.GetProperty(L"CRYPTUNPROTECT_RESULT");
		std::wcout << std::endl << testdata[i].input << L" => " << protected_output << L" => " << unprotected_output;
        CPPUNIT_ASSERT(unprotected_output == testdata[i].input);
        std::wstring unprotected_description = msiInstall.GetProperty(L"CRYPTUNPROTECT_DESCRIPTION");
        if (wcslen(testdata[i].description)) std::wcout << std::endl << L" description: " << testdata[i].description << L" => " << unprotected_description;
        CPPUNIT_ASSERT(unprotected_description == testdata[i].description);
    }
}

void CryptProtectDataHexUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"Cryptography.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing Cryptography.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "CryptProtectDataHex"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "CryptUnprotectDataHex"));
	::FreeLibrary(h);
}
