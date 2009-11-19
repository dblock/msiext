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
				CPPUNIT_TEST_SUITE_END();

			public:

				void teststringToLong(void);
				void testTokenizeJoin(void);
				void testTokenizeOnChar(void);
                void testTrim(void);
				void testStartsWith(void);
				void testEndsWith(void);
				void testReplace(void);
				void testMb2Wc(void);
				void testWc2Mb(void);
				void testBSTR2Mb(void);
				void testVARIANT2Mb(void);
				void testEbcdic(void);
				void testlongToString(void);
				void testlongToWString(void);
			};
		}
	}
}
