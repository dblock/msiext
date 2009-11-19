#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace AtlCom
		{
			class ComUtilsUnitTest :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE(ComUtilsUnitTest);
				CPPUNIT_TEST(testCLSIDFrom);
				CPPUNIT_TEST_SUITE_END();
			public:
				void testCLSIDFrom();
			};
		}
	}
}