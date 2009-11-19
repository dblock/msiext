#include "StdAfxUnitTests.h"
#include "DESEDE3UnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::Cryptography::DESEDE3UnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::Cryptography;

void DESEDE3UnitTests::Test_DESEDE3()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

    // generate a key
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"Cryptography.dll", L"DESEDE3_GenerateKey"));
    std::wstring key = msiInstall.GetProperty(L"DESEDE3_KEY");
    std::wcout << std::endl << key;

    typedef struct
    {
        LPCWSTR input;
    } TestData;

    TestData testdata[] =
    {
        { L"", },
        { L"test" },
        { L"12345678" }, // block size
        { L"1234567812345678" }, // twice block size
        { L"123456781234567812345678" }, // pad size
        { L"123456781234567812345678ABCDEF" },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        // encrypt
        msiInstall.SetProperty(L"DESEDE3_CLEARTEXT_DATA", testdata[i].input);
        CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"Cryptography.dll", L"DESEDE3_Encrypt"));
        std::wstring encrypted_output = msiInstall.GetProperty(L"DESEDE3_ENCRYPTED_DATA");
        // decrypt
        msiInstall.SetProperty(L"DESEDE3_CLEARTEXT_DATA", L""); // clear data
        CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"Cryptography.dll", L"DESEDE3_Decrypt"));
        std::wstring decrypted_output = msiInstall.GetProperty(L"DESEDE3_CLEARTEXT_DATA");
        std::wcout << std::endl << testdata[i].input << L" => " << encrypted_output << L" => " << decrypted_output;
        CPPUNIT_ASSERT(decrypted_output == testdata[i].input);
    }
}

void DESEDE3UnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"Cryptography.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing Cryptography.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "DESEDE3_Encrypt"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "DESEDE3_Decrypt"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "DESEDE3_GenerateKey"));
	::FreeModule(h);
}
