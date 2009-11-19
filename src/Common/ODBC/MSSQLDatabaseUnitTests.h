#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Databases
		{
			namespace MSSQL
			{
				class MSSQLDatabaseUnitTests :  public CPPUNIT_NS::TestFixture
				{
					CPPUNIT_TEST_SUITE( MSSQLDatabaseUnitTests );
					CPPUNIT_TEST(testConstructorDestructor);
                    CPPUNIT_TEST(testGetCreateQuery);
					CPPUNIT_TEST(testCreate);
                    CPPUNIT_TEST(testLoadSave);
					CPPUNIT_TEST_SUITE_END();
				public:
                    void testGetCreateQuery();
					void testConstructorDestructor();
					void testCreate();
                    void testLoadSave();
				};
			}
		}
	}
}
