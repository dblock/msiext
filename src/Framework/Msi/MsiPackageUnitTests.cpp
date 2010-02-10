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

	// A valid MSI must have a summary for MsiOpenPackage to succeed
    database.SetSummary(summary_entries, ARRAYSIZE(summary_entries));

	// Windows 7 requires a property table with a ProductCode value
	database.Execute(L"CREATE TABLE `Property` (`Property` CHAR(72) NOT NULL, `Value` CHAR(0) NOT NULL LOCALIZABLE PRIMARY KEY `Property`)");
	database.Execute(L"INSERT INTO `Property` (`Property`, `Value`) VALUES ('ProductCode', '{07F7FB1B-992E-4a2d-805C-C803C98CFC42}')");

	database.Commit();
    database.Close();

    MsiPackage package;
    package.Open(filename);
    std::wcout << std::endl << L"Package handle " << std::hex << (MSIHANDLE) package;

    package.Close();

    AppSecInc::File::FileDelete(filename);
}
