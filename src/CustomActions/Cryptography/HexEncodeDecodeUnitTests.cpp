#include "StdAfxUnitTests.h"
#include "HexEncodeDecodeUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::Cryptography::EncodeDecodeUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::Cryptography;

void EncodeDecodeUnitTests::Test_HexEncodeDecodeW()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

    typedef struct
    {
        LPCWSTR input;
        LPCWSTR output;
    } TestData;

    TestData testdata[] =
    {
        { L"", L"" },
        { L"test", L"7400650073007400" }
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        // encode
        msiInstall.SetProperty(L"HEXENCODE_DATA", testdata[i].input);
        CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"Cryptography.dll", L"HexEncodeW"));
        std::wstring encoded_output = msiInstall.GetProperty(L"HEXENCODE_RESULT");
        CPPUNIT_ASSERT(encoded_output == testdata[i].output);
        // decode
        msiInstall.SetProperty(L"HEXDECODE_DATA", encoded_output);
        CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"Cryptography.dll", L"HexDecodeW"));
        std::wstring decoded_output = msiInstall.GetProperty(L"HEXDECODE_RESULT");
        if (wcslen(testdata[i].input)) std::wcout << std::endl << testdata[i].input << L" => " << encoded_output << L" => " << decoded_output;
        CPPUNIT_ASSERT(decoded_output == testdata[i].input);
    }
}

void EncodeDecodeUnitTests::Test_HexEncodeDecodeA()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

    typedef struct
    {
        LPCSTR input;
        LPCSTR output;
    } TestData;

    TestData testdata[] =
    {
        { "", "" },
        { "test", "74657374" }
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        // encode
        msiInstall.SetProperty(L"HEXENCODE_DATA", StringUtils::mb2wc(testdata[i].input));
        CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"Cryptography.dll", L"HexEncodeA"));
        std::wstring encoded_output = msiInstall.GetProperty(L"HEXENCODE_RESULT");
        std::string encoded_output_a = StringUtils::wc2mb(encoded_output);
        CPPUNIT_ASSERT(encoded_output_a == testdata[i].output);
        // decode
        msiInstall.SetProperty(L"HEXDECODE_DATA", encoded_output);
        CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"Cryptography.dll", L"HexDecodeA"));
        std::wstring decoded_output = msiInstall.GetProperty(L"HEXDECODE_RESULT");
        std::string decoded_output_a = StringUtils::wc2mb(decoded_output);
        if (strlen(testdata[i].input))std::cout << std::endl << testdata[i].input << " => " << encoded_output_a << " => " << decoded_output_a;
        CPPUNIT_ASSERT(decoded_output_a == testdata[i].input);
    }
}

void EncodeDecodeUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"Cryptography.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing Cryptography.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "HexDecodeA"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "HexEncodeA"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "HexDecodeW"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "HexEncodeW"));
	::FreeModule(h);
}
