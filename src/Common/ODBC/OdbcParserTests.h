#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Databases
		{
			namespace ODBC
			{
				class OdbcParserUnitTests : public CPPUNIT_NS::TestFixture
				{
					CPPUNIT_TEST_SUITE( OdbcParserUnitTests );
					CPPUNIT_TEST(testCommandSetSqlServer);
					CPPUNIT_TEST(testCommandSetDelimiters);
					CPPUNIT_TEST(testCommandSetFindCommand);
					CPPUNIT_TEST(testCommandSetFindCommandForDelimiters);
					CPPUNIT_TEST(testOdbcParserSplitting);
					CPPUNIT_TEST(testOdbcParserInsert);
					CPPUNIT_TEST(testOdbcParserInsertNotTerminating);
					CPPUNIT_TEST(testOdbcParserNoDelims);
					CPPUNIT_TEST(testOdbcParserExitOnErrorFlag);
					CPPUNIT_TEST_SUITE_END();
				public:
					void testCommandSetSqlServer();
					void testCommandSetDelimiters();
					void testCommandSetFindCommand();
					void testCommandSetFindCommandForDelimiters();
					void testOdbcParserSplitting();
					void testOdbcParserInsert();
					void testOdbcParserInsertNotTerminating();
					void testOdbcParserNoDelims();
					void testOdbcParserExitOnErrorFlag();
				};
			}
		}
	}
}
