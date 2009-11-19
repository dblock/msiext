#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace DataSource
		{
			class SQLDMOUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( SQLDMOUnitTests );
				CPPUNIT_TEST( Test_SQLDMO_ListAvailableSQLServers );
				CPPUNIT_TEST( Test_EntryPoints );
                CPPUNIT_TEST_SUITE_END();
			public:
                void Test_SQLDMO_ListAvailableSQLServers();
				void Test_EntryPoints();
			};
        }
	}
}
