#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace AtlCom
		{
			class CoInitializeUnitTest :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE(CoInitializeUnitTest);
				CPPUNIT_TEST(testCCoInitialize);
				CPPUNIT_TEST_SUITE_END();
			public:
				void testCCoInitialize();
			};
		}
	}
}