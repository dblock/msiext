#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace DataSource
		{
			class ConfigDataSourceUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( ConfigDataSourceUnitTests );
				CPPUNIT_TEST( Test_ConfigDataSource_SQLServer );
                CPPUNIT_TEST( Test_ConfigDataSource_Access );
                // CPPUNIT_TEST( Test_ConfigDataSource_Oracle );
				CPPUNIT_TEST( Test_ConfigDataSource );
                CPPUNIT_TEST( Test_EntryPoints );
                CPPUNIT_TEST_SUITE_END();
			public:
                void Test_ConfigDataSource();
                void Test_EntryPoints();
				void Test_ConfigDataSource_SQLServer();
                void Test_ConfigDataSource_Access();
                void Test_ConfigDataSource_Oracle();
			};
        }
	}
}
