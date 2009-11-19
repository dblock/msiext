#include "StdAfxUnitTests.h"
#include "ParameterUnitTests.h"

using namespace AppSecInc::Databases::ODBC;
using namespace AppSecInc::UnitTests::Databases::ODBC;

CPPUNIT_TEST_SUITE_REGISTRATION(ODBCParameterUnitTests);

void ODBCParameterUnitTests::testConstructorDestructor()
{
    struct testConstructorDestructor_ParameterTestData
    {
	    SQLSMALLINT iotype;
	    SQLSMALLINT valuetype;
	    SQLSMALLINT parametertype;
	    SQLINTEGER datasize;
    };

	testConstructorDestructor_ParameterTestData testdata[] = 
	{
		{ SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, sizeof(SQLCHAR) },
		{ SQL_PARAM_INPUT, SQL_C_NUMERIC, SQL_NUMERIC, sizeof(SQLNUMERIC) },
		{ SQL_PARAM_INPUT, SQL_C_NUMERIC, SQL_DECIMAL, sizeof(SQLDECIMAL) },
		{ SQL_PARAM_INPUT, SQL_C_NUMERIC, SQL_INTEGER, sizeof(SQLINTEGER) },
		{ SQL_PARAM_INPUT, SQL_C_NUMERIC, SQL_SMALLINT, sizeof(SQLSMALLINT) },
		{ SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_FLOAT, sizeof(SQLFLOAT) },
		{ SQL_PARAM_INPUT, SQL_C_FLOAT, SQL_REAL, sizeof(SQLREAL) },
		{ SQL_PARAM_INPUT, SQL_C_DOUBLE, SQL_DOUBLE, sizeof(SQLDOUBLE) },
		{ SQL_PARAM_INPUT, SQL_C_TIMESTAMP, SQL_DATETIME, sizeof(SQLDATE) },
		{ SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, sizeof(SQLCHAR) },
		{ SQL_PARAM_INPUT, SQL_C_WCHAR, SQL_VARCHAR, sizeof(SQLVARCHAR) }
	};

	for (int i = 0; i < ARRAYSIZE(testdata); i++)
	{
		std::wstringstream i_s;
		i_s << i;
		ODBCParameter param(i_s.str()
			, testdata[i].iotype
			, testdata[i].valuetype
			, testdata[i].parametertype
			, testdata[i].datasize);
		CPPUNIT_ASSERT(param.GetIOType() == testdata[i].iotype);
		CPPUNIT_ASSERT(param.GetParameterType() == testdata[i].parametertype);
		CPPUNIT_ASSERT(param.GetType() == testdata[i].valuetype);
		CPPUNIT_ASSERT(param.GetDataSize() == testdata[i].datasize);		
		CPPUNIT_ASSERT(param.GetName() == i_s.str());
		ODBCParameter copy(param);
		CPPUNIT_ASSERT(copy.GetIOType() == testdata[i].iotype);
		CPPUNIT_ASSERT(copy.GetParameterType() == testdata[i].parametertype);
		CPPUNIT_ASSERT(copy.GetType() == testdata[i].valuetype);
		CPPUNIT_ASSERT(copy.GetDataSize() == testdata[i].datasize);		
		CPPUNIT_ASSERT(copy.GetName() == i_s.str());
	}
}
