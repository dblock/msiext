#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace LSA
		{
			class GroupUnitTests :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( GroupUnitTests );
                CPPUNIT_TEST( testCreate );
                CPPUNIT_TEST( testDelete );
                CPPUNIT_TEST( testExists );
                CPPUNIT_TEST( testMember );
                CPPUNIT_TEST( testDomainMember );
				CPPUNIT_TEST_SUITE_END();
			public:
                void testCreate();
                void testDelete();
                void testExists();
                void testMember();
                void testDomainMember();
			};
		}
	}
}
