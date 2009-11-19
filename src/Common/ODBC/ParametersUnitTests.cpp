#include "StdAfxUnitTests.h"
#include "ParametersUnitTests.h"

using namespace AppSecInc::Databases::ODBC;
using namespace AppSecInc::UnitTests::Databases::ODBC;

CPPUNIT_TEST_SUITE_REGISTRATION(ODBCParametersUnitTests);

void ODBCParametersUnitTests::testConstructorDestructor()
{
	{
		ODBCParameters p;
	}

	{
		ODBCParameters * p = new ODBCParameters();
		delete p;
	}
}

void ODBCParametersUnitTests::testCollection()
{
	ODBCParameter parameter_wstring(L"wstring", std::wstring(L"value"));
	ODBCParameter parameter_string(L"string", std::string("value"));
    ODBCParameter parameter_int(L"int", (int) 65534);
    ODBCParameter parameter_short(L"short", (short) 1);
    ODBCParameter parameter_double(L"double", (double) 3.5);
    ODBCParameter parameter_float(L"float", (float) 4.5);

    ODBCParameters p;
    p.AddParameter(parameter_wstring);
    p.AddParameter(parameter_string);
    p.AddParameter(parameter_int);
    p.AddParameter(parameter_short);
    p.AddParameter(parameter_double);
    p.AddParameter(parameter_float);

    CPPUNIT_ASSERT(p[parameter_wstring.GetName()].GetWStringValue() == parameter_wstring.GetWStringValue());
    CPPUNIT_ASSERT(p[parameter_string.GetName()].GetStringValue() == parameter_string.GetStringValue());
    CPPUNIT_ASSERT(p[parameter_int.GetName()].GetIntValue() == parameter_int.GetIntValue());
    CPPUNIT_ASSERT(p[parameter_short.GetName()].GetShortValue() == parameter_short.GetShortValue());
    CPPUNIT_ASSERT(p[parameter_double.GetName()].GetDoubleValue() == parameter_double.GetDoubleValue());
    CPPUNIT_ASSERT(p[parameter_float.GetName()].GetFloatValue() == parameter_float.GetFloatValue());
}