#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Databases
		{
			namespace MSSQL
			{
				class MSSQLConnectionInfoUnitTests :  public CPPUNIT_NS::TestFixture
				{
					CPPUNIT_TEST_SUITE( MSSQLConnectionInfoUnitTests );
					CPPUNIT_TEST(testConstructorDestructor);
					CPPUNIT_TEST(testCopyAndAssignment);
					CPPUNIT_TEST(testGetConnectionString);
					CPPUNIT_TEST_SUITE_END();
				public:
					void testConstructorDestructor();
					void testCopyAndAssignment();
					void testGetConnectionString();
				};
			}
		}
	}
}
