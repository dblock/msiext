#include "StdAfxUnitTests.h"
#include "MsiFlagUnitTest.h"

using namespace AppSecInc;
using namespace AppSecInc::UnitTests;
using namespace AppSecInc::UnitTests::Msi;
using namespace AppSecInc::Msi;
using namespace AppSecInc::Msi::Flags;

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::Msi::MsiFlagUnitTest);

void MsiFlagUnitTest::MsiFlag_GetFlagValue_Test()
{
    const FlagMapEntry flags[] =
    {
        { L"1", 1 },
        { L"2", 2 },
    };

    for (int i = 0; i < ARRAYSIZE(flags); i++)
    {
        ULONG value = AppSecInc::Msi::Flags::GetFlagValue(flags[i].name, flags);
		std::wcout << std::endl << flags[i].name << L" => " << value;
        CPPUNIT_ASSERT(value == flags[i].value);
    }
}

void MsiFlagUnitTest::MsiFlag_GetFlagName_Test()
{
    const FlagMapEntry flags[] =
    {
        { L"1", 1 },
        { L"2", 2 },
    };

    for (int i = 0; i < ARRAYSIZE(flags); i++)
    {
		std::wstring name = AppSecInc::Msi::Flags::GetFlagName(flags[i].value, flags);
		std::wcout << std::endl << flags[i].value << L" => " << name;
        CPPUNIT_ASSERT(name == flags[i].name);
    }
}

void MsiFlagUnitTest::MsiFlag_GetStringFlagsValue_Test()
{
    const FlagMapEntry flags[] =
    {
        { L"1", 1 },
        { L"2", 2 },
    };

    const FlagMapEntry maps[] =
    {
        { L"", 0 },
        { L"1", 1 },
        { L"2", 2 },
        { L"1|2", 3 },
        { L"1|2|2|||", 3 }
    };

    for (int i = 0; i < ARRAYSIZE(maps); i++)
    {
        ULONG value = AppSecInc::Msi::Flags::GetStringFlagsValue(maps[i].name, flags);
		std::wcout << std::endl << maps[i].name << L" => " << value;
        CPPUNIT_ASSERT(value == maps[i].value);
    }
}