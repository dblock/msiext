#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace LSA
		{
			class LSAPolicyUnitTests :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( LSAPolicyUnitTests );
				CPPUNIT_TEST( testConstructorDestructor );
                CPPUNIT_TEST( testOpenClose );
				CPPUNIT_TEST_SUITE_END();
			public:
				void testConstructorDestructor();
                void testOpenClose();
			};
		}
	}
}
