#include "StdAfxUnitTests.h"
#include "ColumnUnitTests.h"

using namespace AppSecInc::Databases::ODBC;
using namespace AppSecInc::UnitTests::Databases::ODBC;

CPPUNIT_TEST_SUITE_REGISTRATION(ODBCColumnUnitTests);

void ODBCColumnUnitTests::testConstructorDestructor()
{
	struct TestData
	{
		int type;
		int size;
	};

	TestData testdata[] = 
	{
		{ SQL_UNKNOWN_TYPE, ODBCColumn::INVALID_SIZE },
		{ SQL_CHAR, sizeof(SQLCHAR) },
		{ SQL_NUMERIC, sizeof(SQLNUMERIC) },
		{ SQL_DECIMAL, sizeof(SQLDECIMAL) },
		{ SQL_INTEGER, sizeof(SQLINTEGER) },
		{ SQL_SMALLINT, sizeof(SQLSMALLINT) },
		{ SQL_FLOAT, sizeof(SQLFLOAT) },
		{ SQL_REAL, sizeof(SQLREAL) },
		{ SQL_DOUBLE, sizeof(SQLDOUBLE) },
		{ SQL_DATETIME, sizeof(SQLDATE) },
		{ SQL_VARCHAR, sizeof(SQLVARCHAR) },
        { SQL_LONGVARCHAR, 0 },
        { SQL_WLONGVARCHAR, 0 }
	};

	for (int i = 0; i < ARRAYSIZE(testdata); i++)
	{
		std::wstringstream i_s;
		i_s << i;
		ODBCColumn col(i_s.str(), testdata[i].type);
		CPPUNIT_ASSERT(col.GetType() == testdata[i].type);
		CPPUNIT_ASSERT(col.GetDataSize() == testdata[i].size);		
		CPPUNIT_ASSERT(col.GetName() == i_s.str());
		CPPUNIT_ASSERT(! col.IsBound());
		ODBCColumn copy(col);
		CPPUNIT_ASSERT(copy.GetType() == testdata[i].type);
		CPPUNIT_ASSERT(copy.GetDataSize() == testdata[i].size);		
		CPPUNIT_ASSERT(copy.GetName() == i_s.str());
		CPPUNIT_ASSERT(! col.IsBound());
	}

	{
		ODBCColumn * p = new ODBCColumn(L"random", SQL_INTEGER);
		delete p;
	}
}
