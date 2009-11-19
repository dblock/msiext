#include "StdAfxUnitTests.h"
#include "BufferUnitTests.h"

using namespace AppSecInc::Databases::ODBC;
using namespace AppSecInc::UnitTests::Databases::ODBC;

CPPUNIT_TEST_SUITE_REGISTRATION(ODBCBufferUnitTests);

void ODBCBufferUnitTests::testConstructorDestructor()
{
	struct TestData
	{
		int type;
		int size;
	};

	TestData testdata[] = 
	{
		{ SQL_UNKNOWN_TYPE, ODBCBuffer::INVALID_SIZE },
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
		ODBCBuffer col(testdata[i].type, 0);
		CPPUNIT_ASSERT(col.GetType() == testdata[i].type);
		CPPUNIT_ASSERT(col.GetDataSize() == testdata[i].size);		
		ODBCBuffer copy(col);
		CPPUNIT_ASSERT(copy.GetType() == testdata[i].type);
		CPPUNIT_ASSERT(copy.GetDataSize() == testdata[i].size);		
	}

	{
		ODBCBuffer * p = new ODBCBuffer(SQL_INTEGER);
		delete p;
	}
}

void ODBCBufferUnitTests::testSQLTypeToString()
{
	int testdata[] = 
	{
		{ SQL_CHAR },
        { SQL_NUMERIC },
        { SQL_DECIMAL },
        { SQL_INTEGER },
        { SQL_SMALLINT },
        { SQL_TINYINT },
        { SQL_FLOAT },
        { SQL_REAL },
        { SQL_DOUBLE },
        { SQL_DATETIME },
        { SQL_VARCHAR },
        { SQL_LONGVARCHAR },
        { SQL_WLONGVARCHAR }
	};

	for (int i = 0; i < ARRAYSIZE(testdata); i++)
	{
        std::wstring stringtype = ODBCBuffer::SQLTypeToString(testdata[i]);
        CPPUNIT_ASSERT(stringtype.length() > 0);
        std::wcout << std::endl << i << L": " << testdata[i] << L" -> " << stringtype;
        SQLSMALLINT inttype = ODBCBuffer::StringToSQLType(stringtype);
        CPPUNIT_ASSERT(inttype == testdata[i]);
	}
}
