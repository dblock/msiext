#include "StdAfxUnitTests.h"
#include "LSAPolicyUnitTests.h"
#include "LSAPolicy.h"

using namespace AppSecInc::LSA;
using namespace AppSecInc::UnitTests::LSA;

CPPUNIT_TEST_SUITE_REGISTRATION(LSAPolicyUnitTests);

void LSAPolicyUnitTests::testConstructorDestructor()
{
    {
        LSAPolicy policy;
        CPPUNIT_ASSERT(! policy.IsOpen());
    }
}

void LSAPolicyUnitTests::testOpenClose()
{
    LSA_OBJECT_ATTRIBUTES attr = { 0 };
    LSAPolicy policy;
    policy.Open();
    CPPUNIT_ASSERT(policy.IsOpen());
    policy.Close();
    CPPUNIT_ASSERT(! policy.IsOpen());
    policy.Open();
    CPPUNIT_ASSERT(policy.IsOpen());
}