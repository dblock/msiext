#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Databases
		{
			namespace ODBC
			{
				class ODBCHandleUnitTests :  public CPPUNIT_NS::TestFixture
				{
					CPPUNIT_TEST_SUITE( ODBCHandleUnitTests );
                    CPPUNIT_TEST(testAllocateStatementHandle);
					CPPUNIT_TEST_SUITE_END();
				public:
                    void testAllocateStatementHandle();
				};
			}
		}
	}
}
