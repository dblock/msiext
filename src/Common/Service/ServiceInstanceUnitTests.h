#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Service
		{
			class ServiceInstanceUnitTests :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( ServiceInstanceUnitTests );
				CPPUNIT_TEST( testConstructorDestructor );
				CPPUNIT_TEST( testCreateDelete );
                CPPUNIT_TEST( testOpenClose );
                CPPUNIT_TEST( testGetServiceProcessStatus );
                CPPUNIT_TEST( testControl );
				CPPUNIT_TEST( testGetConfig );
				CPPUNIT_TEST( testGetDescription );
				CPPUNIT_TEST_SUITE_END();
			public:
				void testConstructorDestructor();
				void testCreateDelete();
                void testOpenClose();
                void testControl();
                void testGetServiceProcessStatus();
				void testGetConfig();
				void testGetDescription();
			};
		}
	}
}
