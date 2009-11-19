#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Databases
		{
			namespace ODBC
			{
				class ODBCRowSetUnitTests :  public CPPUNIT_NS::TestFixture
				{
					CPPUNIT_TEST_SUITE( ODBCRowSetUnitTests );
                    CPPUNIT_TEST(testConstructorDestructor);
                    CPPUNIT_TEST(testFetch);
                    CPPUNIT_TEST(testBind);
                    CPPUNIT_TEST(testExecute);
                    CPPUNIT_TEST(testAddColumn);
					CPPUNIT_TEST_SUITE_END();
				public:
                    void testConstructorDestructor();
                    void testFetch();
                    void testBind();
                    void testExecute();
                    void testAddColumn();
				};
			}
		}
	}
}
