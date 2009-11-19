#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace CppUnitTests
		{
			class CppUnitTestIgnoreUnitTest :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE(CppUnitTestIgnoreUnitTest);
				CPPUNIT_TEST(testIgnore);
				CPPUNIT_TEST_SUITE_END();
			public:
				void testIgnore();
			};
		}
	}
}