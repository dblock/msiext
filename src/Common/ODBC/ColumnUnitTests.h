#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Databases
		{
			namespace ODBC
			{
				class ODBCColumnUnitTests :  public CPPUNIT_NS::TestFixture
				{
					CPPUNIT_TEST_SUITE( ODBCColumnUnitTests );
                    CPPUNIT_TEST(testConstructorDestructor);
					CPPUNIT_TEST_SUITE_END();
				public:
                    void testConstructorDestructor();
				};
			}
		}
	}
}
