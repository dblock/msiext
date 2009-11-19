#include "StdAfxUnitTests.h"
#include "VersionUnitTests.h"
#include "Version.h"

using namespace AppSecInc::UnitTests::File;

CPPUNIT_TEST_SUITE_REGISTRATION(VersionUnitTests);

void VersionUnitTests::testCompare()
{
    struct TestData
    {
        LPCWSTR version;
        LPCWSTR compare;
        int result;
    };

    TestData testdata[] = 
    {
        { L"", L"", 0 },
	    { L"1.0", L"1.0", 0 },
	    { L"1.1", L"1.0", 1 },
	    { L"1.1", L"",    1 },
	    { L"1.0", L"1.1", -1 },
	    { L"1.0.0", L"1.1", -1 },
	    { L"1.0.0", L"1.1.1.1", -1 },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        CPPUNIT_ASSERT(AppSecInc::Version::Compare(
            testdata[i].version, testdata[i].compare) == testdata[i].result);
    }
}

void VersionUnitTests::testIsWithinBounds()
{
    struct TestData
    {
        LPCWSTR version;
        LPCWSTR min;
        LPCWSTR max;
        bool result;
    };

    TestData testdata[] = 
    {
	    { L"1.1", L"1.0", L"2.0", true  },
	    { L"1.1", L"1.0", L""   , true  },
	    { L"1.1", L"",    L"2.0", true  },
	    { L"1.1", L"1.1", L"1.1", true  },
	    { L"1.0", L"1.1", L"1.1", false },
	    { L"1.2", L"1.1", L"1.1", false },
	    { L"1.0", L"1.1", L""   , false },
	    { L"1.0", L"",    L"1.1", true  },
	    { L"",    L"1.0", L"2.0", false },
	    { L"",    L"1.0", L""   , false },
	    { L"",    L"0.0", L""   , false },
	    { L"",    L"",    L"2.0", false },
	    { L"",    L"",    L""   , false }
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        CPPUNIT_ASSERT(AppSecInc::Version::IsWithinBounds(
            testdata[i].version, testdata[i].min, testdata[i].max) == testdata[i].result);
    }
}

