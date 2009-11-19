#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Databases
		{
			namespace ODBC
			{
				class ODBCDataSourceUnitTests : public CPPUNIT_NS::TestFixture
				{
					CPPUNIT_TEST_SUITE( ODBCDataSourceUnitTests );
					CPPUNIT_TEST(testGetNoError);
                    CPPUNIT_TEST(testConfigureDataSource);
                    CPPUNIT_TEST(testConfigureDataSourceError);
					CPPUNIT_TEST_SUITE_END();
				public:
					void testGetNoError();
                    void testConfigureDataSource();
                    void testConfigureDataSourceError();
				};
			}
		}
	}
}
