#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace String
		{            
			class StringFormatterUnitTests :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( StringFormatterUnitTests );
				CPPUNIT_TEST(testFormatMessageA);
				CPPUNIT_TEST(testFormatMessageW);
				CPPUNIT_TEST(testFormatMessageFromLastErrorCode);
				CPPUNIT_TEST(testFormatMessageFromHR);
				CPPUNIT_TEST(testFormatHexView);
				CPPUNIT_TEST(testFormatHexString);
                CPPUNIT_TEST(testFormatTemplate);
				CPPUNIT_TEST_SUITE_END();

			public:
				void testFormatMessageA();
				void testFormatMessageW();
				void testFormatMessageFromLastErrorCode();
				void testFormatMessageFromHR();
				void testFormatHexView();
				void testFormatHexString();
                void testFormatTemplate();
			};
		}
	}
}
