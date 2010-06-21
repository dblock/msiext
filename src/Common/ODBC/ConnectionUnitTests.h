#pragma once

namespace AppSecInc
{
	namespace UnitTests 
	{
		namespace Databases
		{
			namespace ODBC
			{
				class ODBCConnectionUnitTests : public CPPUNIT_NS::TestFixture
				{
					CPPUNIT_TEST_SUITE( ODBCConnectionUnitTests );
					CPPUNIT_TEST(testConstructorDestructor);
					CPPUNIT_TEST(testInitialize);
					CPPUNIT_TEST(testGetError);
					CPPUNIT_TEST(testGetDiagFields);
					CPPUNIT_TEST(testGetDiagMessages);
					CPPUNIT_TEST(testConnectWithODBCConnectionInfo);
                    CPPUNIT_TEST(testGetScalar);
                    CPPUNIT_TEST(testGetString);
                    CPPUNIT_TEST(testGetWString);
                    CPPUNIT_TEST(testExecuteAutoBind);
					CPPUNIT_TEST(testExecuteExplicitBind);
                    CPPUNIT_TEST(testGetXml);
					CPPUNIT_TEST(testExecuteStoredProcedure_sp_helprotect);
					CPPUNIT_TEST(testExecuteStoredProcedure_sp_helpuser);
					CPPUNIT_TEST(testExecuteStoredProcedure_xp_msver);
					CPPUNIT_TEST(testConnect_ODBC_CONNECTION);
                    CPPUNIT_TEST(testExecuteWithParametersAndResults_sp_helpuser);
                    CPPUNIT_TEST(testExecuteSelectAllSupportedTypes);
                    CPPUNIT_TEST(testSelectString);
					CPPUNIT_TEST(testInsertLargePayload_MSSQL);
					CPPUNIT_TEST(testInsertLargePayload_Access);
					CPPUNIT_TEST(testInsertXml);
					CPPUNIT_TEST(testSelectUTF8String);
					CPPUNIT_TEST_SUITE_END();
				public:
					void testConstructorDestructor();
					void testInitialize();
					void testGetError();
					void testGetDiagFields();
					void testGetDiagMessages();
                    void testGetScalar();
                    void testGetString();
                    void testGetWString();
                    void testGetCount();
					void testExecuteExplicitBind();
                    void testExecuteAutoBind();
                    void testGetXml();
					void testConnectWithODBCConnectionInfo();
					void testExecuteStoredProcedure_sp_helprotect();
					void testExecuteStoredProcedure_sp_helpuser();
					void testExecuteStoredProcedure_xp_msver();
                    void testExecuteWithParametersAndResults_sp_helpuser();
                    void testConnect_ODBC_CONNECTION();
                    void testExecuteSelectAllSupportedTypes();
                    void testSelectString();
					void testInsertLargePayload_MSSQL();
					void testInsertLargePayload_Access();
                    void testInsertXml();
					void testSelectUTF8String();
				};
			}
		}
	}
}
