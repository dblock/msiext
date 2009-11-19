#include "StdAfxUnitTests.h"
#include "HandleUnitTests.h"

using namespace AppSecInc::Databases::ODBC;
using namespace AppSecInc::Databases::MSSQL;
using namespace AppSecInc::UnitTests::Databases::ODBC;

CPPUNIT_TEST_SUITE_REGISTRATION(ODBCHandleUnitTests);

void ODBCHandleUnitTests::testAllocateStatementHandle()
{
	MSSQLConnectionInfo info(L"localhost");
	ODBCConnection conn;
	conn.Connect(info);
    ODBCHandle statement;
    try { statement.Release(); throw "Expected exception"; } catch (std::exception&) { }
    statement.Allocate(SQL_HANDLE_STMT, (SQLHANDLE) conn);
    statement.Release();
    try { statement.Release(); throw "Expected exception"; } catch (std::exception&) { }
}
