#include "StdAfxUnitTests.h"
#include "ProcessUnitTests.h"
#include "Process.h"

using namespace AppSecInc::LSA;
using namespace AppSecInc::UnitTests::LSA;

CPPUNIT_TEST_SUITE_REGISTRATION(ProcessUnitTests);

void ProcessUnitTests::testConstructorDestructor()
{
    {
        Process p;
        CPPUNIT_ASSERT(! p.IsOpen());
    }
}

void ProcessUnitTests::testOpenClose()
{
    Process p;
    p.Open(::GetCurrentProcessId(), PROCESS_ALL_ACCESS);
    CPPUNIT_ASSERT(p.IsOpen());
    p.Close();
    CPPUNIT_ASSERT(! p.IsOpen());
    p.Open(::GetCurrentProcessId(), PROCESS_QUERY_INFORMATION);
    CPPUNIT_ASSERT(p.IsOpen());
}

void ProcessUnitTests::testOpenCloseByName()
{
    Process p;
    p.Open(L"explorer.exe", PROCESS_QUERY_INFORMATION, FALSE);
    CPPUNIT_ASSERT(p.IsOpen());
    p.Close();
    CPPUNIT_ASSERT(! p.IsOpen());
}

