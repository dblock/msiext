#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace LSA
		{
			class ProcessTokenUnitTests :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( ProcessTokenUnitTests );
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
