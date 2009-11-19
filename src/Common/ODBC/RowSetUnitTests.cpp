#include "StdAfxUnitTests.h"
#include "RowSetUnitTests.h"

using namespace AppSecInc::Databases::ODBC;
using namespace AppSecInc::UnitTests::Databases::ODBC;

CPPUNIT_TEST_SUITE_REGISTRATION(ODBCRowSetUnitTests);

void ODBCRowSetUnitTests::testConstructorDestructor()
{
	{
		ODBCRowSet info;
	}

	{
		ODBCRowSet * p = new ODBCRowSet();
		delete p;
	}
}

void ODBCRowSetUnitTests::testFetch()
{
    ODBCRowSet info;
    try { info.Fetch(); throw "Expected exception"; } catch (std::exception&) { }
}

void ODBCRowSetUnitTests::testBind()
{
    ODBCRowSet info;
    try { info.Bind(NULL); throw "Expected exception"; } catch (std::exception&) { }
}

void ODBCRowSetUnitTests::testExecute()
{
    ODBCRowSet info;
    try { info.ExecuteDirect(L"SELECT * FROM Table"); throw "Expected exception"; } catch (std::exception&) { }
}

void ODBCRowSetUnitTests::testAddColumn()
{
    // TODO
}
