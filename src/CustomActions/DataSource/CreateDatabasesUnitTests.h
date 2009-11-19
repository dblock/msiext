#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace DataSource
		{
			class CreateDatabasesUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( CreateDatabasesUnitTests );
				CPPUNIT_TEST( Test_CreateDatabases_SQLServer );
				CPPUNIT_TEST( Test_CreateDatabases_Access );
                CPPUNIT_TEST( Test_EntryPoints );
                CPPUNIT_TEST_SUITE_END();
			public:
                void Test_CreateDatabases();
                void Test_EntryPoints();
				void Test_CreateDatabases_SQLServer();
				void Test_CreateDatabases_Access();
			};
        }
	}
}
