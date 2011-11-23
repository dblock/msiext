#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace LSA
		{
			class SidUnitTests :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( SidUnitTests );
				CPPUNIT_TEST( testSidConstructorsAndOperators );
				CPPUNIT_TEST( testSidToString );
				CPPUNIT_TEST( testSidToHexString );
				CPPUNIT_TEST_SUITE_END();
			public:
				void testSidConstructorsAndOperators();
                void testSidToString();
				void testSidToHexString();
			};
		}
	}
}
