#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Net
		{
			class DirectoryServicesUnitTests :  public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( DirectoryServicesUnitTests );
                CPPUNIT_TEST( testGetJoinStatus );
				CPPUNIT_TEST_SUITE_END();
			public:
                void testGetJoinStatus();
			};
		}
	}
}
