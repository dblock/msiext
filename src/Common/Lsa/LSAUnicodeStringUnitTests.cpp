#include "StdAfxUnitTests.h"
#include "LSAUnicodeStringUnitTests.h"
#include "LSAUnicodeString.h"

using namespace AppSecInc::LSA;
using namespace AppSecInc::UnitTests::LSA;

CPPUNIT_TEST_SUITE_REGISTRATION(LSAUnicodeStringUnitTests);

void LSAUnicodeStringUnitTests::testConstructorDestructor()
{
    {
        LSAUnicodeString s;
        CPPUNIT_ASSERT(0 == s.Length());
        CPPUNIT_ASSERT(0 == s.MaximumLength());
    }

    {
        LSAUnicodeString * ps = new LSAUnicodeString();
        CPPUNIT_ASSERT(ps != NULL);
        CPPUNIT_ASSERT(0 == ps->Length());
        CPPUNIT_ASSERT(0 == ps->MaximumLength());
        delete ps;
    }
}

void LSAUnicodeStringUnitTests::testProperties()
{
    std::wstring guid = AppSecInc::Com::GenerateGUIDStringW();
    LSAUnicodeString s(guid);
    CPPUNIT_ASSERT(s.Length() == sizeof(wchar_t) * guid.length()); 
    CPPUNIT_ASSERT(s.MaximumLength() == sizeof(wchar_t) * guid.length()); 
}