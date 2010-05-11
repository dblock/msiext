#include "StdAfxUnitTests.h"
#include "StringUtils.h"
#include "StringUtilsUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::String::StringUtilsUnitTests);

using namespace AppSecInc::UnitTests::String;

void StringUtilsUnitTests::testTrim()
{
	typedef struct  
	{
		LPCSTR testIn;
        LPCSTR testWhitespace;
		LPCSTR testOut;
        LPCSTR testOutL;
        LPCSTR testOutR;
	} TrimTestData;

	TrimTestData testData[] = 
	{
		{ "", "", "", "", "" },
        { "x", "x", "", "", "" },
        { "xxxxx", "x", "", "", "" },
        { "xxyyxx", "x", "yy", "yyxx", "xxyy" },
        { "\r\n\r", "\r", "\n", "\n\r", "\r\n" },
	};

	for( unsigned int i = 0; i < ARRAYSIZE(testData); i++ )
	{
        std::string s = testData[i].testIn;
        StringUtils::lrtrim(s, testData[i].testWhitespace);
		CPPUNIT_ASSERT(s == testData[i].testOut);

        std::string sL = testData[i].testIn;
        StringUtils::ltrim(sL, testData[i].testWhitespace);
        CPPUNIT_ASSERT(sL == testData[i].testOutL);
        
        std::string sR = testData[i].testIn;
        StringUtils::rtrim(sR, testData[i].testWhitespace);
        CPPUNIT_ASSERT(sR == testData[i].testOutR);
	}
}

void StringUtilsUnitTests::teststringToLong()
{
	typedef struct  
	{
		LPCSTR testIn;
        long defaultOnError;
        long testOut;
		int base;
	} TestData;

	TestData testData[] = 
	{
		{ NULL, -1, -1 , 10},
		{ "-2147483647", -1, LONG_MIN + 1 , 10},
		{ "2147483646", -1, LONG_MAX - 1 , 10},
		{ "0", 0, 0 , 10},
		{ "", 0, 0 , 10},
		{ "-65", 0, -65 , 10},
		{ "65", 0, 65 , 10},
		{ "65y", 0, 0 , 10},
		{ "-", 0, 0 , 10},
		{ "9-9", 0, 0 , 10},
		{ "-1", 0, -1 , 10},
		{ "q", 0, 0 , 10},
		{ "66-", 0, 0 , 10},
		{ "0.9", 0, 0 , 10},
		{ " ", 0, 0 , 10},
		{ "\n", 0, 0 , 10},
        // with default on error changed
		{ "0", -1, 0 , 10},
		{ "", -1, -1 , 10},
		{ "-65", -1, -65 , 10},
		{ "65", -1, 65 , 10},
		{ "65y", -1, -1 , 10},
		{ "y65y", -1, -1 , 10},
		{ "-", -1, -1 , 10},
		{ "9-9", -1, -1 , 10},
		{ "-2", -1, -2 , 10},
		{ "q", -1, -1 , 10},
		{ "66-", -1, -1 , 10},
		{ "0.9", -1, -1 , 10},
		{ "9.9", -1, -1 , 10},
		{ " ", -1, -1 , 10},
		{ "\n", -1, -1 , 10},
		// base 2
		{ NULL, -1, -1 , 2},
		{ "1100100", -1, 100, 2 },
		{ "1100100y", -1, -1, 2 },
		{ "0", -1, 0, 2 },
		{ "-0", -1, 0, 2 },
		{ "", -1, -1, 2 },
		{ " ", -1, -1, 2 },
		{ "-100", -1, -4, 2 },
		{ "Y56", -1, -1, 2 },
		//base 8
		{ NULL, -1, -1 , 8},
		{ "40", -1, 32, 8 },
		{ "0", -1, 0, 8 },
		{ "", -1, -1, 8 },
		{ " ", -1, -1, 8 },
		{ "-40", -1, -32, 8 },
		{ "40www", -1, -1, 8 },
		{ "-", -1, -1, 8 },
		{ "y40", -1, -1, 8 },
		{ "40.0", -1, -1, 8 },
		{ "0xDEADBEEF", -1, -1, 8 },
		//base 16
		{ NULL, -1, -1 , 16},
		{ "40", -1, 64, 16 },
		{ "0xDEADBEEF", -1, -1, 16 },
		{ "-0xDEADBEEF", -1, -1, 16 },
		{ "0xBAADF00D", -1, -1, 16 },
		{ "0x", -1, -1, 16 },
		{ "0", -1, 0, 16 },
		{ "", -1, -1, 16 },
		{ " ", -1, -1, 16 },
		{ "-", -1, -1, 16 },
		{ "-0x", -1, -1, 16 },
		{ "0xYY", -1, -1, 16 },
		{ "0xabcd", -1, 43981, 16 },
	};

	for (unsigned int i = 0; i < ARRAYSIZE(testData); i++)
	{
        int result = StringUtils::stringToLong(testData[i].testIn, testData[i].defaultOnError, testData[i].base);
		std::stringstream s;
		s << "[" << (testData[i].testIn ? testData[i].testIn : "NULL") << "] => [" << result << "] (expected: " 
			<< testData[i].testOut << " with default " << testData[i].defaultOnError << " Base: " << testData[i].base << ")";
		CPPUNIT_ASSERT_MESSAGE(s.str().c_str(), result == testData[i].testOut);
	}
}

void StringUtilsUnitTests::testTokenizeJoin()
{

	typedef struct  
	{

		LPCSTR testStr;
		LPCSTR testDelim;

		int numParts;

	} TokenizeTestData;

	TokenizeTestData testData[] = 
	{

		{ "t.$.y.$.x.$f", ".$.", 3 },
		{ "4<<8<>15<>16<>23<>42", "<>", 5 },
		{ ";;t;;o;;k;;e;;n;;i;;z;;e;;", ";;", 10 },
		{ ";;t;;o;;k;;e;;n;;i;;z;;e", ";;", 9 },
		{ "t;;o;;k;;e;;n;;i;;z;;e;;", ";;", 9 },

	};

	std::vector<std::string> parts;

	for( int i = 0; i < sizeof(testData)/sizeof(TokenizeTestData); i++ )
	{
		parts.clear();
		StringUtils::tokenize(testData[i].testStr, parts, testData[i].testDelim);
		CPPUNIT_ASSERT_MESSAGE(testData[i].testStr, parts.size() == testData[i].numParts);
		std::string s = StringUtils::join(parts, testData[i].testDelim);
		std::cout << std::endl << testData[i].testStr << " vs. " << s.c_str();
		CPPUNIT_ASSERT_MESSAGE(s.c_str(), s == testData[i].testStr);
	}

	//Test that correct tokens are returned
	std::string sTest, delim1, delim2;

	sTest = "ServerName;WINGMAN;InstanceName;APPSECINC;IsClustered;No;Version;8.00.194;tcp;1091;np;\\\\WINGMAN\\pipe\\MSSQL$APPSECINC\\sql\\query;;";
	delim1 = ";;";
	delim2 = ";";

	StringUtils::tokenize( sTest, parts, delim1 );

	CPPUNIT_ASSERT( parts[0] == "ServerName;WINGMAN;InstanceName;APPSECINC;IsClustered;No;Version;8.00.194;tcp;1091;np;\\\\WINGMAN\\pipe\\MSSQL$APPSECINC\\sql\\query" );
	CPPUNIT_ASSERT( parts[1] == "" );

	sTest = parts[0];
	StringUtils::tokenize( sTest, parts, delim2 );

	CPPUNIT_ASSERT( parts[0] == "ServerName" );
	CPPUNIT_ASSERT( parts[1] == "WINGMAN" );
	CPPUNIT_ASSERT( parts[2] == "InstanceName" );
	CPPUNIT_ASSERT( parts[3] == "APPSECINC" );
	CPPUNIT_ASSERT( parts[4] == "IsClustered" );
	CPPUNIT_ASSERT( parts[5] == "No" );
	CPPUNIT_ASSERT( parts[6] == "Version" );
	CPPUNIT_ASSERT( parts[7] == "8.00.194" );
	CPPUNIT_ASSERT( parts[8] == "tcp" );
	CPPUNIT_ASSERT( parts[9] == "1091" );
	CPPUNIT_ASSERT( parts[10] == "np" );
	CPPUNIT_ASSERT( parts[11] == "\\\\WINGMAN\\pipe\\MSSQL$APPSECINC\\sql\\query" );
}

void StringUtilsUnitTests::testTokenizeOnChar()
{

	typedef struct  
	{

		LPCSTR testStr;
		LPCSTR testDelim;

		int numParts;

	} TokenizeTestData;

	TokenizeTestData testData[] = 
	{

		{ "t.y.x.f", ".", 4 },
		{ "4<8<15<16<23<42", "<", 6 },
		{ "798910", "9", 3 },
		{ "5,6,7,8,9,1,2,3,", ",", 9 },
		{ "5", "5", 2 },
		{ "4??3??2??1", "?", 7 },
		{ "4!?3!?2!?1", "?!", 7 },
		{ ".5", ".", 2 },
		{ ".", ".", 2 },
		{ "", "", 1 },
		{ "", "qw3ert", 1 },
		{ "qw3ert", "", 1 },
		{ "q\tw\t3\te\tr\tt", "\t", 6 },
		{ "\x01\x0A", "\x0A", 2 },

	};

	std::vector<std::string> parts;

	for( int i = 0; i < sizeof(testData)/sizeof(TokenizeTestData); i++ )
	{
		parts.clear();
		StringUtils::tokenizeOnChar(testData[i].testStr, parts, testData[i].testDelim);
		CPPUNIT_ASSERT(parts.size() == testData[i].numParts);
	}

	//Test that correct tokens are returned
	std::string version, delims;

	version = "t.y.x.f";
	delims = ".";
	StringUtils::tokenizeOnChar( version, parts, delims );
	CPPUNIT_ASSERT(parts[0] == "t");
	CPPUNIT_ASSERT(parts[1] == "y");
	CPPUNIT_ASSERT(parts[2] == "x");
	CPPUNIT_ASSERT(parts[3] == "f");

	version = "5,6,7,8,9,1,2,3,";
	delims = ",";
	StringUtils::tokenizeOnChar( version, parts, delims );
	CPPUNIT_ASSERT(parts[0] == "5");
	CPPUNIT_ASSERT(parts[1] == "6");
	CPPUNIT_ASSERT(parts[2] == "7");
	CPPUNIT_ASSERT(parts[3] == "8");
	CPPUNIT_ASSERT(parts[4] == "9");
	CPPUNIT_ASSERT(parts[5] == "1");
	CPPUNIT_ASSERT(parts[6] == "2");
	CPPUNIT_ASSERT(parts[7] == "3");
	CPPUNIT_ASSERT(parts[8] == "");

	version = "k";
	delims = "k";
	StringUtils::tokenizeOnChar( version, parts, delims );
	CPPUNIT_ASSERT(parts[0] == "");
	CPPUNIT_ASSERT(parts[1] == "");

	version = "q\tw\n3\te\nr\t";
	delims = "\t\n";
	StringUtils::tokenizeOnChar( version, parts, delims );
	CPPUNIT_ASSERT(parts[0] == "q");
	CPPUNIT_ASSERT(parts[1] == "w");
	CPPUNIT_ASSERT(parts[2] == "3");
	CPPUNIT_ASSERT(parts[3] == "e");
	CPPUNIT_ASSERT(parts[4] == "r");
	CPPUNIT_ASSERT(parts[5] == "");

	version = "dharma";
	delims = "";
	StringUtils::tokenizeOnChar( version, parts, delims );
	CPPUNIT_ASSERT(parts[0] == "dharma");
}

void StringUtilsUnitTests::testStartsWith()
{
	typedef struct  
	{
		LPCSTR testIn;
		LPCSTR testWhat;
        bool testExpectedResult;
	} TestData;

	TestData testData[] = 
	{
		{ "", "", true },
		{ "x", "x", true },
		{ "x", "X", false },
		{ "X", "x", false },
		{ "x", "y", false },
		{ "xx", "xy", false },
		{ "xx", "yx", false },
		{ "xxx", "", true },
		{ "x x x", "x x", true },
		{ "123", "231", false },
	};

	for( unsigned int i = 0; i < ARRAYSIZE(testData); i++ )
	{
		std::stringstream message;
		message << "'" << testData[i].testIn << "'.startsWith('" << 
			testData[i].testWhat << "') didn't return '" << 
			(testData[i].testExpectedResult ? "true" : "false") << "'";
		
		CPPUNIT_ASSERT_MESSAGE(message.str().c_str(),
			testData[i].testExpectedResult == StringUtils::startsWith(
				testData[i].testIn, testData[i].testWhat));
	}
}

void StringUtilsUnitTests::testEndsWith()
{
	typedef struct  
	{
		LPCSTR testIn;
		LPCSTR testWhat;
        bool testExpectedResult;
	} TestData;

	TestData testData[] = 
	{
		{ "", "", true },
		{ "x", "x", true },
		{ "X", "x", false },
		{ "x", "X", false },
		{ "x", "y", false },
		{ "xx", "xy", false },
		{ "xx", "yx", false },
		{ "xxx", "", true },
		{ "x x x", "x x", true },
		{ "xyz", "yz", true },
		{ "xyz", "xxxxxxxxxxyz", false },
		{ "123", "231", false },
	};

	for( unsigned int i = 0; i < ARRAYSIZE(testData); i++ )
	{
		std::stringstream message;
		message << "'" << testData[i].testIn << "'.endsWith('" << 
			testData[i].testWhat << "') didn't return '" << 
			(testData[i].testExpectedResult ? "true" : "false") << "'";
		
		CPPUNIT_ASSERT_MESSAGE(message.str().c_str(),
			testData[i].testExpectedResult == StringUtils::endsWith(
				testData[i].testIn, testData[i].testWhat));
	}
}

void StringUtilsUnitTests::testReplace()
{
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
		
		std::string output = testData[i].testIn;
		CPPUNIT_ASSERT_MESSAGE(message.str().c_str(),
			testData[i].testExpectedResult == StringUtils::replace(
				output, testData[i].testFrom, testData[i].testTo));

		message << "'" << testData[i].testIn << "'.replace('" << 
			testData[i].testFrom << "', '" << testData[i].testTo << "') didn't return '" << 
			testData[i].testExpectedOutput << "' (returned '" << output << "')";

		CPPUNIT_ASSERT_MESSAGE(message.str().c_str(),
			testData[i].testExpectedOutput == output);
	}
}

void StringUtilsUnitTests::testWc2Mb()
{
	typedef struct  
	{
		LPCWSTR testIn;
		LPCSTR testOut;
	} TestData;

	TestData testData[] = 
	{
		{ L"", "" },
		{ L"x", "x" },
		{ L"hello world", "hello world" },
	};

	for( unsigned int i = 0; i < ARRAYSIZE(testData); i++ )
	{
		std::stringstream message;
		USES_CONVERSION;
		message << "wc2mb('" << W2A(testData[i].testIn) << "')" << 
			" != '" << testData[i].testOut << "'";
		
		std::string output = StringUtils::wc2mb(testData[i].testIn);
		CPPUNIT_ASSERT_MESSAGE(message.str().c_str(), testData[i].testOut == output);
	}
}

void StringUtilsUnitTests::testMb2Wc()
{
	typedef struct  
	{
		LPCSTR testIn;
		LPCWSTR testOut;
	} TestData;

	TestData testData[] = 
	{
		{ "", L"" },
		{ "x", L"x" },
		{ "hello world", L"hello world" },
	};

	for( unsigned int i = 0; i < ARRAYSIZE(testData); i++ )
	{
		std::stringstream message;
		USES_CONVERSION;
		message << "mb2wc('" << testData[i].testIn << "')" << 
			" != '" << W2A(testData[i].testOut) << "'";
		
		std::wstring output = StringUtils::mb2wc(testData[i].testIn);
		CPPUNIT_ASSERT_MESSAGE(message.str().c_str(), testData[i].testOut == output);
	}
}

void StringUtilsUnitTests::testBSTR2Mb()
{
	typedef struct  
	{
		LPCWSTR testIn;
		LPCSTR testOut;
	} TestData;

	TestData testData[] = 
	{
		{ L"", "" },
		{ L"x", "x" },
		{ L"hello world", "hello world" },
	};

	for( unsigned int i = 0; i < ARRAYSIZE(testData); i++ )
	{
		std::stringstream message;
		USES_CONVERSION;
		message << "bstr2mb('" << W2A(testData[i].testIn) << "')" << 
			" != '" << testData[i].testOut << "'";
		
		CComBSTR bstr(testData[i].testIn);
		std::string output = StringUtils::bstr2mb(bstr);
		CPPUNIT_ASSERT_MESSAGE(message.str().c_str(), testData[i].testOut == output);
	}
}

void StringUtilsUnitTests::testEbcdic()
{
	typedef struct  
	{
		LPCSTR testIn;
		LPCSTR testOut;
	} TestData;

	TestData testData[] = 
	{
		// { "", "" },
		{ "x" },
		{ "hello world" },
	};

	for( unsigned int i = 0; i < ARRAYSIZE(testData); i++ )
	{
		std::string ss(testData[i].testIn);
		StringUtils::s2ebcdic(ss);

		CPPUNIT_ASSERT_MESSAGE("s2ebcdic() produced identical output", 
			ss != testData[i].testIn || 0 == strlen(testData[i].testIn) );

		StringUtils::ebcdic2s(ss);

		std::stringstream message;
		message << "s2ebcdic(ebcdic2s('" << testData[i].testIn << "'))" << 
			" != '" << testData[i].testIn << "' (output was '" << ss << "')";

		CPPUNIT_ASSERT_MESSAGE(message.str().c_str(), testData[i].testIn == ss);
	}
}

void StringUtilsUnitTests::testVARIANT2Mb()
{
	// multibyte character tests
	CPPUNIT_ASSERT(StringUtils::toString(CComVariant("hello!")) == "hello!");
	CPPUNIT_ASSERT(StringUtils::toString(CComVariant(true)) == "true");
	CPPUNIT_ASSERT(StringUtils::toString(CComVariant(false)) == "false");

	CPPUNIT_ASSERT(StringUtils::toString(CComVariant('a')) == "a");
	CPPUNIT_ASSERT(StringUtils::toString(CComVariant(static_cast<signed char>(-7))) == "-7");
	CPPUNIT_ASSERT(StringUtils::toString(CComVariant(static_cast<unsigned char>('z'))) == "122");

	CPPUNIT_ASSERT(StringUtils::toString(CComVariant(short(25555))) == "25555");
	CPPUNIT_ASSERT(StringUtils::toString(CComVariant(short(-25555))) == "-25555");
	CPPUNIT_ASSERT(StringUtils::toString(CComVariant(int(1800000000))) == "1800000000");
	CPPUNIT_ASSERT(StringUtils::toString(CComVariant(int(-1800000000))) == "-1800000000");
	CPPUNIT_ASSERT(StringUtils::toString(CComVariant(long(2000000000))) == "2000000000");
	CPPUNIT_ASSERT(StringUtils::toString(CComVariant(long(-2000000000))) == "-2000000000");

	CPPUNIT_ASSERT(StringUtils::toString(CComVariant(BYTE(73))) == "73");
	CPPUNIT_ASSERT(StringUtils::toString(CComVariant(unsigned short(23456))) == "23456");
	CPPUNIT_ASSERT(StringUtils::toString(CComVariant(unsigned long(3234567789))) == "3234567789");

	CPPUNIT_ASSERT(StringUtils::toString(CComVariant(float(2.0))) == "2");
	CPPUNIT_ASSERT(StringUtils::toString(CComVariant(double(55555.0))) == "55555");

#if (_WIN32_WINNT >= 0x0501) || defined(_ATL_SUPPORT_VT_I8)
	CPPUNIT_ASSERT(StringUtils::toString(CComVariant(LONGLONG(-9223372036854775800i64))) == "-9223372036854775800");
	CPPUNIT_ASSERT(StringUtils::toString(CComVariant(ULONGLONG(70000000UL))) == "70000000");
#endif

	CY cy;
	cy.int64 = 55500000UL;
	CPPUNIT_ASSERT(StringUtils::toString(CComVariant(cy)) == "55500000");

	IDispatch *pDispatch = reinterpret_cast<IDispatch*>(0);
	CPPUNIT_ASSERT(StringUtils::toString(CComVariant(pDispatch)) == "IDspatch: 0x00000000");

	IUnknown *pUnknown = reinterpret_cast<IUnknown*>(0);
	CPPUNIT_ASSERT(StringUtils::toString(CComVariant(pUnknown)) == "IUnknown: 0x00000000");

	CPPUNIT_ASSERT(StringUtils::toString(CComVariant(CComBSTR("Yo there"))) == "Yo there");
	// CPPUNIT_ASSERT(StringUtils::toString(CComVariant(double(5), VT_DATE)) == "Date: 5");
	CPPUNIT_ASSERT(StringUtils::toString(CComVariant(long(5), VT_ERROR)) == "Error: 5");

	// wide character tests
	CPPUNIT_ASSERT(StringUtils::toWString(CComVariant(L"hello!")) == L"hello!");
	CPPUNIT_ASSERT(StringUtils::toWString(CComVariant(L"hello\x01d\x201!")) == L"hello\x01d\x201!");

	try
	{
		// These tests should fail
		VARIANT v = { 0 };
		v.vt = VT_BLOB;
		v.ullVal = 0;
		std::string s;
		CPPUNIT_ASSERT(StringUtils::toString(v) != s);
		throw "Expected exception";
	}
	catch(std::exception&) { }

	// Still need to test SAFEARRAY
}

void StringUtilsUnitTests::testlongToString()
{
	struct TestData 
	{
		unsigned long int testIn;
		std::string testOut;
	};
	
	TestData testData[] = {
		{0, "0"},
		{121, "121"},
		{111111118, "111111118"},
		{0x00, "0"},
		{0x11, "17"},
		{0xA, "10"}
	};
	
	for (int i=0; i < ARRAYSIZE(testData); i++)
	{
        std::string number = StringUtils::toString(testData[i].testIn);
        std::cout << std::endl << testData[i].testIn << " => " << number << " (expecting " << testData[i].testOut << ")";
		CPPUNIT_ASSERT(testData[i].testOut == number);
	}
}

void StringUtilsUnitTests::testlongToWString()
{
	struct TestData 
	{
		unsigned long int testIn;
        std::wstring testOut;
	};
	
	TestData testData[] = {
		{0, L"0"},
		{121, L"121"},
		{111111118, L"111111118"},
		{0x00, L"0"},
		{0x11, L"17"},
		{0xA, L"10"}
	};
	
	for (int i=0; i < ARRAYSIZE(testData); i++)
	{
        std::wstring number = StringUtils::toWString(testData[i].testIn);
        std::cout << std::endl << testData[i].testIn << " => " << StringUtils::wc2mb(number) << " (expecting " << StringUtils::wc2mb(testData[i].testOut) << ")";
		CPPUNIT_ASSERT(testData[i].testOut == number);
	}
}

void StringUtilsUnitTests::testUTF8()
{
	typedef struct  
	{
		LPCSTR testIn;
		LPCWSTR testOut;
	} TestData;

	const unsigned char s1[] = { 0xc3, 0x8a, 0x00 };
	const unsigned char s2[] = { 0xEF, 0x80, 0xBF, 0x00 };
	const unsigned char s3[] = { 0x41, 0xc3, 0xaa, 0xc3, 0xb1, 0xc3, 0xbc, 0x43, 0x00 };

	TestData testData[] = 
	{
		{ "", L"" },
		{ "x", L"x" },
		{ "hello world", L"hello world" },
		{ (char *) s1, L"\uCA" },
		{ (char *) s2, L"\uF03F" },
		{ (char *) s3, L"A\u00ea\u00f1\u00fcC" },
	};

	for( unsigned int i = 0; i < ARRAYSIZE(testData); i++ )
	{
		std::wstring unicode_string = StringUtils::utf82wc(testData[i].testIn);
		CPPUNIT_ASSERT(unicode_string.length() <= strlen(testData[i].testIn));
		std::string utf8_string = StringUtils::wc2utf8(unicode_string);
		CPPUNIT_ASSERT(utf8_string == testData[i].testIn);
	}
}
