#include "StdAfxUnitTests.h"
#include "Base64EncodeDecodeUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::Cryptography::Base64EncodeDecodeUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::Cryptography;

void Base64EncodeDecodeUnitTests::Test_Base64EncodeDecodeW()
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
        { L"test", L"dABlAHMAdAA=" }
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        // encode
        msiInstall.SetProperty(L"BASE64ENCODE_DATA", testdata[i].input);
        CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"Cryptography.dll", L"Base64EncodeW"));
        std::wstring encoded_output = msiInstall.GetProperty(L"BASE64ENCODE_RESULT");
        CPPUNIT_ASSERT(encoded_output == testdata[i].output);
        // decode
        msiInstall.SetProperty(L"BASE64DECODE_DATA", encoded_output);
        CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"Cryptography.dll", L"Base64DecodeW"));
        std::wstring decoded_output = msiInstall.GetProperty(L"BASE64DECODE_RESULT");
        if (wcslen(testdata[i].input)) 
		{
			std::wcout << std::endl << testdata[i].input << L" => " << encoded_output << L" => " << decoded_output;
		}
        CPPUNIT_ASSERT(decoded_output == testdata[i].input);
    }
}

void Base64EncodeDecodeUnitTests::Test_Base64EncodeDecodeA()
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
        { "test", "dGVzdA==" }
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        // encode
        msiInstall.SetProperty("BASE64ENCODE_DATA", testdata[i].input);
        CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"Cryptography.dll", L"Base64EncodeA"));
        std::string encoded_output_a = msiInstall.GetProperty("BASE64ENCODE_RESULT");
		std::cout << std::endl << encoded_output_a;
        CPPUNIT_ASSERT(encoded_output_a == testdata[i].output);
        // decode
        msiInstall.SetProperty("BASE64DECODE_DATA", encoded_output_a);
        CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"Cryptography.dll", L"Base64DecodeA"));
        std::string decoded_output_a = msiInstall.GetProperty("BASE64DECODE_RESULT");
        if (strlen(testdata[i].input))
		{
			std::cout << std::endl << testdata[i].input << " => " << encoded_output_a << " => " << decoded_output_a;
		}
        CPPUNIT_ASSERT(decoded_output_a == testdata[i].input);
    }
}

void Base64EncodeDecodeUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"Cryptography.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing Cryptography.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Base64DecodeA"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Base64EncodeA"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Base64DecodeW"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Base64EncodeW"));
	::FreeModule(h);
}
