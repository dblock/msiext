#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Databases
		{
			namespace MSSQL
			{
				class MSSQLDatabaseFileSpecUnitTests :  public CPPUNIT_NS::TestFixture
				{
					CPPUNIT_TEST_SUITE( MSSQLDatabaseFileSpecUnitTests );
					CPPUNIT_TEST(testConstructorDestructor);
                    CPPUNIT_TEST(testGetCreateString);
                    CPPUNIT_TEST(testLoadSave);
					CPPUNIT_TEST_SUITE_END();
				public:
					void testConstructorDestructor();
                    void testGetCreateString();
                    void testLoadSave();
				};
			}
		}
	}
}
