#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace ActiveDirectory
		{
			class DirectoryServicesUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( DirectoryServicesUnitTests );
				CPPUNIT_TEST( Test_EntryPoints );
				CPPUNIT_TEST( Test_DirectoryGetDcName );
				CPPUNIT_TEST_SUITE_END();
			public:
				void Test_EntryPoints();
				void Test_DirectoryGetDcName();
			};
        }
	}
}
