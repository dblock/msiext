#include "StdAfxUnitTests.h"
#include "MsiPackageUnitTests.h"

using namespace AppSecInc;
using namespace AppSecInc::UnitTests;
using namespace AppSecInc::UnitTests::Msi;
using namespace AppSecInc::Msi;

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::Msi::MsiPackageUnitTests);

void MsiPackageUnitTests::testConstructorDestructor()
{
    {
        MsiPackage package;
        CPPUNIT_ASSERT((MSIHANDLE) package == NULL);
    }

    {
        MsiPackage * p = new MsiPackage();
        delete p;
    }
}

void MsiPackageUnitTests::testOpenPackage()
{
    std::wstring filename = AppSecInc::File::GetTemporaryFileNameW();
    std::wcout << std::endl << L"Creating " << filename;
    MsiDatabase database;
    database.Create(filename);
    std::wcout << std::endl << L"Database handle " << std::hex << (MSIHANDLE) database;

    MsiDatabaseSummaryEntry summary_entries[] = 
    {
        { PID_TITLE, VT_LPSTR, L"Installation Database Title" },
        { PID_SUBJECT, VT_LPSTR, L"Installation Database Subject" },
        { PID_AUTHOR, VT_LPSTR, L"AppSecInc." },
        { PID_TEMPLATE, VT_LPSTR, ";1033" },
        { PID_REVNUMBER, VT_LPSTR, "{00869AA3-A32E-4398-89B2-5C5DC7328C7C}" },
        { PID_PAGECOUNT, VT_I4, 100 },
        { PID_WORDCOUNT, VT_I4, 100 },
    };

    database.SetSummary(summary_entries, ARRAYSIZE(summary_entries));
    database.Commit();

    database.Close();

    MsiPackage package;
    package.Open(filename);
    std::wcout << std::endl << L"Package handle " << std::hex << (MSIHANDLE) package;

    package.Close();

    AppSecInc::File::FileDelete(filename);
}
