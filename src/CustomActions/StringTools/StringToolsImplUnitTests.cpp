#include "StdAfxUnitTests.h"
#include "StringToolsImplUnitTests.h"
#include <String/StringUtils.h>

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::StringTools::StringToolsImplUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::StringTools;

void StringToolsImplUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"StringTools.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing StringTools.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "String_Replace"));
	CPPUNIT_ASSERT_MESSAGE("Missing String_ToLower", NULL != GetProcAddress(h, "String_ToLower"));
	CPPUNIT_ASSERT_MESSAGE("Missing String_ToLower", NULL != GetProcAddress(h, "String_ToUpper"));
	::FreeLibrary(h);
}

void StringToolsImplUnitTests::Test_StringReplace()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

	typedef struct  
	{
		LPCSTR testIn;
		LPCSTR testFrom;
		LPCSTR testTo;
		int testExpectedResult;
		LPCSTR testExpectedOutput;
	} TestData;

	TestData testData[] = 
	{
		{ "", "", "", 0, "" },
		{ "x", "x", "y", 1, "y" },
		{ "x", "xx", "y", 0, "x" },
		{ "foo", "fo", "f", 1, "fo" },
		{ "{source}\r", "source", "target", 1, "{target}\r" },
		{ "{source}\r", "source", "target", 1, "{target}\r" },
		{ "\n{source}\r", "source", "target", 1, "\n{target}\r" },
		{ "\n{source}{source}\r", "source", "target", 2, "\n{target}{target}\r" },
		{ "\n{source}XZY{source}\r", "source", "target", 2, "\n{target}XZY{target}\r" }
	};

	for( unsigned int i = 0; i < ARRAYSIZE(testData); i++ )
	{
		std::stringstream message;
		message << "'" << testData[i].testIn << "'.replace('" << 
			testData[i].testFrom << "', '" << testData[i].testTo << "') didn't return '" << 
			testData[i].testExpectedResult << "'";
		
		msiInstall.SetProperty("STRING_VALUE_FROM", testData[i].testIn);
		msiInstall.SetProperty("STRING_REPLACE_FROM", testData[i].testFrom);
		msiInstall.SetProperty("STRING_REPLACE_TO", testData[i].testTo);

		CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"StringTools.dll", L"String_Replace"));

		int replacement_count = atoi(msiInstall.GetProperty("STRING_REPLACE_COUNT").c_str());
		std::string output = msiInstall.GetProperty("STRING_VALUE_TO");

		CPPUNIT_ASSERT_MESSAGE(message.str().c_str(),
			testData[i].testExpectedResult == replacement_count);

		message << "'" << testData[i].testIn << "'.replace('" << 
			testData[i].testFrom << "', '" << testData[i].testTo << "') didn't return '" << 
			testData[i].testExpectedOutput << "' (returned '" << output << "')";

		CPPUNIT_ASSERT_MESSAGE(message.str().c_str(),
			testData[i].testExpectedOutput == output);
	}
}

void StringToolsImplUnitTests::Test_StringTrim()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

	typedef struct  
	{
		LPCSTR testInput;
		LPCSTR testWhitespaces;
		LPCSTR testExpectedResult;
	} TestData;

	TestData testData[] = 
	{
		{ "     this is a string whith whitespaces\t     ", "", "this is a string whith whitespaces" },
		{ "     this is a string whith whitespaces     ", " ", "this is a string whith whitespaces" },
		{ "this string doesn't have whitespaces", "", "this string doesn't have whitespaces" },
		{ "%%test string%%", "%", "test string" },
		{ " test string     ", "", "test string" }
	};

	for( unsigned int i = 0; i < ARRAYSIZE(testData); i++ )
	{		
		msiInstall.SetProperty("STRING_TRIM_INPUT", testData[i].testInput);
		msiInstall.SetProperty("STRING_TRIM_WHITESPACES", testData[i].testWhitespaces);

		CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"StringTools.dll", L"String_Trim"));

		std::string stringTrimResult = msiInstall.GetProperty("STRING_TRIM_RESULT");
		std::stringstream message;

		message << "StringTrim('" << testData[i].testInput <<
			"', '" << testData[i].testWhitespaces << "') returned '" << stringTrimResult <<
			"'. It was expected: '" << testData[i].testExpectedResult << "'";

		CPPUNIT_ASSERT_MESSAGE(message.str().c_str(), testData[i].testExpectedResult == stringTrimResult);
	}
}

void StringToolsImplUnitTests::Test_RegexMatch()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

	typedef struct  
	{
		LPCSTR testInputString;
		LPCSTR testExpression;
		LPCSTR testExpectedResult;
	} TestData;

	TestData testData[] = 
	{
		{ "<TAG>one<TAG>two</TAG>one</TAG>", "<TAG\\b[^>]*>(.*?)</TAG>", "1" },
		{ "<TAG>one<TAG>two</TAG>one", "<TAG\\b[^>]*>(.*?)</TAG>", "0" },
		{ "125", "^([1-9]|[1-9][0-9]|[1-9][0-9][0-9])$", "1" },
		{ "1005", "^([1-9]|[1-9][0-9]|[1-9][0-9][0-9])$", "0" },
		{ "2008-07-31", "(19|20)\\d\\d[- /.](0[1-9]|1[012])[- /.](0[1-9]|[12][0-9]|3[01])", "1" },
		{ "2008-15-20", "(19|20)\\d\\d[- /.](0[1-9]|1[012])[- /.](0[1-9]|[12][0-9]|3[01])", "0" },
		{ "myname@host.com", "\\b[a-z0-9._%+-]+@[a-z0-9.-]+\\.[a-z]{2,4}\\b", "1" },
		{ "invalid email@host.com", "\\b[a-z0-9._%+-]+@[a-z0-9.-]+\\.[a-z]{2,4}\\b", "0" }
	};

	for( unsigned int i = 0; i < ARRAYSIZE(testData); i++ )
	{		
		msiInstall.SetProperty("REGEX_MATCH_INPUT_STRING", testData[i].testInputString);
		msiInstall.SetProperty("REGEX_MATCH_EXPRESSION", testData[i].testExpression);

		CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"StringTools.dll", L"Regex_Match"));

		std::string regexMatchResult = msiInstall.GetProperty("REGEX_MATCH_RESULT");
		std::stringstream message;

		message << "RegexMatch('" << testData[i].testInputString <<
			"', '" << testData[i].testExpression << "') returned '" << regexMatchResult <<
			"'. It was expected: '" << testData[i].testExpectedResult << "'";

		CPPUNIT_ASSERT_MESSAGE(message.str().c_str(), testData[i].testExpectedResult == regexMatchResult);
	}
}

void StringToolsImplUnitTests::Test_RegexReplace()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

	typedef struct  
	{
		LPCSTR testInputString;
		LPCSTR testExpression;
		LPCSTR testFormat;
		LPCSTR testExpectedResult;
	} TestData;

	TestData testData[] = 
	{
		{ "I have a dog. Also a machine.", "\\b(cat|dog)\\b", "pet", "I have a pet. Also a machine." },
		{ "I have a spider. Also a machine.", "\\b(cat|dog)\\b", "pet", "I have a spider. Also a machine." },
		{ "user@domain", "([^@]*)@(.*)", "$2\\\\$1", "domain\\user" }
	};

	for( unsigned int i = 0; i < ARRAYSIZE(testData); i++ )
	{		
		msiInstall.SetProperty("REGEX_REPLACE_INPUT_STRING", testData[i].testInputString);
		msiInstall.SetProperty("REGEX_REPLACE_EXPRESSION", testData[i].testExpression);
		msiInstall.SetProperty("REGEX_REPLACE_FORMAT", testData[i].testFormat);

		CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"StringTools.dll", L"Regex_Replace"));

		std::string regexReplaceResult = msiInstall.GetProperty("REGEX_REPLACE_RESULT");
		std::stringstream message;

		message << "RegexReplace('" << testData[i].testInputString <<
			"', '" << testData[i].testExpression <<
			"', '" << testData[i].testFormat <<
			"') returned: '" << regexReplaceResult <<
			"'. It was expected: " << testData[i].testExpectedResult << "'";

		CPPUNIT_ASSERT_MESSAGE(message.str().c_str(), testData[i].testExpectedResult == regexReplaceResult);
	}
}


void StringToolsImplUnitTests::Test_StringToLower()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
    
	typedef struct  
	{
		LPCTSTR input;
		LPCTSTR expected;
	} TestData;

	TestData testData[] = 
	{
		{ L"ABCdeF123", L"abcdef123" },
		//{ L"ÏÐÈÌÅÐ×ÈÊ", L"ïðèìåð÷èê" }, // not supported by AppSecInc::StringUtils::lowercase
		{ L"", L"" }
	};

	for( unsigned int i = 0; i < ARRAYSIZE(testData); i++ )
	{		
		msiInstall.SetProperty(L"STRING_TOLOWER_INPUT", testData[i].input);
		CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"StringTools.dll", L"String_ToLower"));

		std::wstring result = msiInstall.GetProperty(L"STRING_TOLOWER_RESULT");
		std::wstring expected( testData[i].expected );
//		std::wstring expected( testData[i].input );
//	    AppSecInc::StringUtils::lowercase( expected );
		
		CPPUNIT_ASSERT(expected == result);
	}
}

void StringToolsImplUnitTests::Test_StringToUpper()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
    
	typedef struct  
	{
		LPCTSTR input;
		LPCTSTR expected;
	} TestData;

	TestData testData[] = 
	{
		{ L"ABCdeF123", L"ABCDEF123" },
//		{ L"ïðèìåð÷èê", L"ÏÐÈÌÅÐ×ÈÊ" }, // not supported by AppSecInc::StringUtils::uppercase
		{ L"", L"" }
	};

	for( unsigned int i = 0; i < ARRAYSIZE(testData); i++ )
	{		
		msiInstall.SetProperty(L"STRING_TOUPPER_INPUT", testData[i].input);
		CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"StringTools.dll", L"String_ToUpper"));

		std::wstring result = msiInstall.GetProperty(L"STRING_TOUPPER_RESULT");
		std::wstring expected( testData[i].expected );
//		std::wstring expected( testData[i].input );
//	    AppSecInc::StringUtils::uppercase( expected );

		CPPUNIT_ASSERT(expected == result);
	}
}
