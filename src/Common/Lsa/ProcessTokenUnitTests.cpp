#include "StdAfxUnitTests.h"
#include "ProcessTokenUnitTests.h"
#include "ProcessToken.h"

using namespace AppSecInc::LSA;
using namespace AppSecInc::UnitTests::LSA;

CPPUNIT_TEST_SUITE_REGISTRATION(ProcessTokenUnitTests);

void ProcessTokenUnitTests::testConstructorDestructor()
{
    {
        ProcessToken ptoken;
        CPPUNIT_ASSERT(! ptoken.IsOpen());
    }
}

void ProcessTokenUnitTests::testOpenClose()
{
    ProcessToken ptoken;
    ptoken.Open(::GetCurrentProcess(), TOKEN_ALL_ACCESS);
    CPPUNIT_ASSERT(ptoken.IsOpen());
    ptoken.Close();
    CPPUNIT_ASSERT(! ptoken.IsOpen());
    ptoken.Open(::GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES);
    CPPUNIT_ASSERT(ptoken.IsOpen());
}