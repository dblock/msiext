#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace LSA
		{
			class ImpersonatedUserUnitTests :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( ImpersonatedUserUnitTests );
                CPPUNIT_TEST( testImpersonate );
				CPPUNIT_TEST_SUITE_END();
			public:
                virtual void setUp();
                virtual void tearDown();
                void testImpersonate();
			};
		}
	}
}
