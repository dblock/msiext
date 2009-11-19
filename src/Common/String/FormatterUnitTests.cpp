#include "StdAfxUnitTests.h"
#include "StringUtils.h"
#include "Formatter.h"
#include "FormatterUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::String::StringFormatterUnitTests);

using namespace AppSecInc::UnitTests::String;

void StringFormatterUnitTests::testFormatMessageA()
{
	std::string result = AppSecInc::Formatter::FormatMessage(
		"Error executing: %s. Error Code: %d", "MessageFormatter", 100);	

	CPPUNIT_ASSERT(result.compare("Error executing: MessageFormatter. Error Code: 100") == 0);
}

void StringFormatterUnitTests::testFormatMessageW()
{
	std::wstring result = AppSecInc::Formatter::FormatMessage(
		L"Error executing: %s. Error Code: %d", L"MessageFormatter", 100);	

	CPPUNIT_ASSERT(result.compare(L"Error executing: MessageFormatter. Error Code: 100") == 0);
}

void StringFormatterUnitTests::testFormatMessageFromLastErrorCode()
{
	std::string expected = "The remote server has been paused or is in the process of being started.";
	int returnCode = 0;
	DWORD errorCode = ERROR_SHARING_PAUSED; // The remote server has been paused or is in the process of being started.
    std::string result = AppSecInc::Formatter::FormatMessageFromLastErrorCodeA(errorCode);	
	CPPUNIT_ASSERT_MESSAGE(result, result.compare(expected) == 0 );
}

void StringFormatterUnitTests::testFormatMessageFromHR()
{
	std::string expected = "The operation completed successfully.";
	int returnCode = 0;
	HRESULT hr = S_OK; // The operation completed successfully.
    std::string result = AppSecInc::Formatter::FormatMessageFromHRA(hr);	
	CPPUNIT_ASSERT_MESSAGE(result, result.compare(expected ) == 0 );
}

void StringFormatterUnitTests::testFormatHexView()
{
	typedef struct  
	{
		byte * buffer;
		unsigned long size;
		LPCSTR result;
	} TestData;

	byte one[] = { 0x01 };
	byte three[] = { 0x01, 0x02, 0xFF, 'A', 'b', 'c' };
	byte twolines[] = { 0x01, 0x02, 0xFF, 'A', 'b', 'c', 
		0x01, 0x02, 0xFF, 'A', 'b', 'c', 
		0x01, 0x02, 0xFF, 'A', 'b', 'c', 
		0x01, 0x02, 0xFF, 'A', 'b', 'c', 
		0x01, 0x02, 0xFF, 'A', 'b', 'c', 
		0x01, 0x02, 0xFF, 'A', 'b', 'c' };

	TestData testData[] = 
	{
		{ NULL, 0, "" },
		{ one, sizeof(one), "00000\t01                                               ." },
		{ three, sizeof(three), "00000\t01 02 ff 41 62 63                                ...Abc" },
		{ twolines, sizeof(twolines), 
				"00000\t01 02 ff 41 62 63 01 02 ff 41 62 63 01 02 ff 41  ...Abc...Abc...A" \
				"\n00010\t62 63 01 02 ff 41 62 63 01 02 ff 41 62 63 01 02  bc...Abc...Abc.." \
				"\n00020\tff 41 62 63                                      .Abc" }
	};

	for( unsigned int i = 0; i < ARRAYSIZE(testData); i++ )
	{
		std::string out = Formatter::FormatHexA(testData[i].buffer, testData[i].size);
		CPPUNIT_ASSERT(out == testData[i].result);

		std::wstring wout = Formatter::FormatHexW(testData[i].buffer, testData[i].size);
		CPPUNIT_ASSERT(wout == AppSecInc::StringUtils::mb2wc(testData[i].result));
	}
}

void StringFormatterUnitTests::testFormatHexString()
{
	typedef struct  
	{
		byte * buffer;
		unsigned long size;
		LPCSTR result;
	} TestData;

	byte one[] = { 0x01 };
	byte three[] = { 0x01, 0x02, 0xFF, 'A', 'b', 'c' };

	TestData testData[] = 
	{
		{ NULL, 0, "" },
		{ one, sizeof(one), "01" },
		{ three, sizeof(three), "0102ff416263" },
	};

	for( unsigned int i = 0; i < ARRAYSIZE(testData); i++ )
	{
		std::string out = Formatter::FormatHexStringA(testData[i].buffer, testData[i].size);
		CPPUNIT_ASSERT(out == testData[i].result);
		std::wstring wout = Formatter::FormatHexStringW(testData[i].buffer, testData[i].size);
		CPPUNIT_ASSERT(wout == AppSecInc::StringUtils::mb2wc(testData[i].result));
	}
}

void StringFormatterUnitTests::testFormatTemplate()
{
    typedef struct
    {
        LPCWSTR buffer;
        LPCWSTR left;
        LPCWSTR right;
        LPCWSTR result;
    } TestData;

    std::map<std::wstring, std::wstring> variables;
    variables[L"t1"] = L"v1";
    variables[L"t2"] = L"v2";
    variables[L"t-empty"] = L"";
    variables[L"t space"] = L"s1 s2";

    TestData testdata[] = 
    {
        { L"", L"[", L"]", L"" },
        { L"[]", L"[", L"]", L"[]" },
        { L"[t1]", L"[", L"]", L"v1" },
        { L"[unknown]", L"[", L"]", L"[unknown]" },
        { L"[t1][t1]", L"[", L"]", L"v1v1" },
        { L"[[t1]][[t1]]", L"[[", L"]]", L"v1v1" },
        { L"[t1][t2][t-empty][t space]", L"[", L"]", L"v1v2s1 s2" },
        { L"text[t1]text", L"[", L"]", L"textv1text" },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        std::wstring result = AppSecInc::Formatter::FormatTemplate(testdata[i].buffer, variables, testdata[i].left, testdata[i].right);
        std::wcout << std::endl << L" " << testdata[i].buffer << L" => " << result;
        CPPUNIT_ASSERT(result == testdata[i].result);
    }
}