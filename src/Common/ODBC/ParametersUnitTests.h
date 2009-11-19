#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Databases
		{
			namespace ODBC
			{
				class ODBCParametersUnitTests :  public CPPUNIT_NS::TestFixture
				{
					CPPUNIT_TEST_SUITE( ODBCParametersUnitTests );
                    CPPUNIT_TEST(testConstructorDestructor);
                    CPPUNIT_TEST(testCollection);
					CPPUNIT_TEST_SUITE_END();
				public:
                    void testConstructorDestructor();
                    void testCollection();
				};
			}
		}
	}
}
