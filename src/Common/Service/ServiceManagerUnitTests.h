#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Service
		{
			class ServiceManagerUnitTests :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( ServiceManagerUnitTests );
				CPPUNIT_TEST( testConstructorDestructor );
                CPPUNIT_TEST( testOpenClose );
				CPPUNIT_TEST( testGetServices );
				CPPUNIT_TEST_SUITE_END();
			public:
				void testConstructorDestructor();
                void testOpenClose();
				void testGetServices();
			};
		}
	}
}
