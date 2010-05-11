#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace String
		{
			class StringUtilsUnitTests :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( StringUtilsUnitTests );
				CPPUNIT_TEST( teststringToLong );
				CPPUNIT_TEST( testTokenizeJoin );				
				CPPUNIT_TEST( testTokenizeOnChar );
                CPPUNIT_TEST( testTrim );
				CPPUNIT_TEST( testStartsWith );
				CPPUNIT_TEST( testEndsWith );
				CPPUNIT_TEST( testReplace );
				CPPUNIT_TEST( testMb2Wc );
				CPPUNIT_TEST( testWc2Mb );
				CPPUNIT_TEST( testBSTR2Mb );
				CPPUNIT_TEST( testVARIANT2Mb );
				CPPUNIT_TEST( testEbcdic );
				CPPUNIT_TEST( testlongToString );
				CPPUNIT_TEST( testlongToWString );
				CPPUNIT_TEST( testUTF8 );
				CPPUNIT_TEST_SUITE_END();
			public:
				void teststringToLong();
				void testTokenizeJoin();
				void testTokenizeOnChar();
                void testTrim();
				void testStartsWith();
				void testEndsWith();
				void testReplace();
				void testMb2Wc();
				void testWc2Mb();
				void testBSTR2Mb();
				void testVARIANT2Mb();
				void testEbcdic();
				void testlongToString();
				void testlongToWString();
				void testUTF8();
			};
		}
	}
}
