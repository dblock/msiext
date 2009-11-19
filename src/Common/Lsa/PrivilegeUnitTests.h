#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace LSA
		{
			class PrivilegeUnitTests :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( PrivilegeUnitTests );
				CPPUNIT_TEST( testPrivileges );
				CPPUNIT_TEST_SUITE_END();
			public:
                virtual void setUp();
                virtual void tearDown();
                void testPrivileges();
			};
		}
	}
}
