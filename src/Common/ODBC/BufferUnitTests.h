#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Databases
		{
			namespace ODBC
			{
				class ODBCBufferUnitTests :  public CPPUNIT_NS::TestFixture
				{
					CPPUNIT_TEST_SUITE( ODBCBufferUnitTests );
                    CPPUNIT_TEST(testConstructorDestructor);
                    CPPUNIT_TEST(testSQLTypeToString);
					CPPUNIT_TEST_SUITE_END();
				public:
                    void testConstructorDestructor();
                    void testSQLTypeToString();
				};
			}
		}
	}
}
