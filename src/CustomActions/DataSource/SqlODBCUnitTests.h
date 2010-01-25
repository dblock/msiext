#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace DataSource
		{
			class SQLODBCUnitTests : public CPPUNIT_NS::TestFixture
			{
				CPPUNIT_TEST_SUITE( SQLODBCUnitTests );
				CPPUNIT_TEST( Test_SQLODBC_Connect );
                CPPUNIT_TEST( Test_SQLODBC_Execute );
                CPPUNIT_TEST( Test_SQLODBC_GetString );
				CPPUNIT_TEST( Test_SQLODBC_GetString_Empty );
				CPPUNIT_TEST( Test_SQLODBC_GetString_Empty_Error );
                CPPUNIT_TEST( Test_SQLODBC_GetScalar );
                CPPUNIT_TEST( Test_SQLODBC_GetXml );
                CPPUNIT_TEST( Test_Execute_ODBC );
                CPPUNIT_TEST( Test_DataSource_ODBC );
                CPPUNIT_TEST( Test_BinaryIdPathResolver_pathToId );
                CPPUNIT_TEST( Test_BinaryIdPathResolver_readContent );
                CPPUNIT_TEST( Test_BinaryIdPathResolver_processInserts );
				CPPUNIT_TEST( Test_EntryPoints );
                CPPUNIT_TEST_SUITE_END();
			public:
                void Test_SQLODBC_Connect();
                void Test_SQLODBC_Execute();
                void Test_SQLODBC_GetString();
                void Test_SQLODBC_GetString_Empty();
                void Test_SQLODBC_GetString_Empty_Error();
                void Test_SQLODBC_GetScalar();
                void Test_SQLODBC_GetXml();
				void Test_EntryPoints();
                void Test_Execute_ODBC();
                void Test_DataSource_ODBC();
                void Test_BinaryIdPathResolver_pathToId();
                void Test_BinaryIdPathResolver_readContent();
                void Test_BinaryIdPathResolver_processInserts();
			};
        }
	}
}
