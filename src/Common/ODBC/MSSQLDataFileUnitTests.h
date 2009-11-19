#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Databases
		{
			namespace MSSQL
			{
				class MSSQLDataFileUnitTests :  public CPPUNIT_NS::TestFixture
				{
					CPPUNIT_TEST_SUITE( MSSQLDataFileUnitTests );
					CPPUNIT_TEST(testConstructorDestructor);
                    CPPUNIT_TEST(testGetInsertString);
                    CPPUNIT_TEST(testLoadSave);
					CPPUNIT_TEST_SUITE_END();
				public:
					void testConstructorDestructor();
                    void testGetInsertString();
                    void testLoadSave();
				};
			}
		}
	}
}
