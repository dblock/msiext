#include "StdAfxUnitTests.h"
#include "MsiDatabaseUnitTests.h"

using namespace AppSecInc;
using namespace AppSecInc::UnitTests;
using namespace AppSecInc::UnitTests::Msi;
using namespace AppSecInc::Msi;

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::Msi::MsiDatabaseUnitTests);

void MsiDatabaseUnitTests::testConstructorDestructor()
{
    {
        MsiDatabase database;
        CPPUNIT_ASSERT((MSIHANDLE) database == NULL);
    }

    {
        MsiDatabase * p = new MsiDatabase();
        delete p;
    }
}

void MsiDatabaseUnitTests::testCreateDatabase()
{
    std::wstring filename = AppSecInc::File::GetTemporaryFileNameW();
    std::wcout << std::endl << L"Creating " << filename;
    MsiDatabase database;
    database.Open(filename, MSIDBOPEN_CREATEDIRECT);
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

    AppSecInc::File::FileDelete(filename);
}

void MsiDatabaseUnitTests::testImport()
{
    std::wstring filename = AppSecInc::File::GetTemporaryFileNameW();
    std::wcout << std::endl << L"Creating " << filename;
    MsiDatabase database;
    database.Create(filename);
    std::wcout << std::endl << L"Database handle " << std::hex << (MSIHANDLE) database;

    std::wstring path = File::GetModuleDirectoryW() + L"\\TestData_MsiUnitTests";
	database.Import(path, L"Property.idt"); 
    database.Import(path, L"ComboBox.idt"); 
    database.Commit();
    database.Close();

    MsiPackage package(filename);
    MsiInstall install(package);

    AppSecInc::Xml::XmlDocument xmlDoc;
    xmlDoc.LoadXml(install.GetViewData(L"SELECT * FROM `ComboBox`"));
    std::wstring value = xmlDoc.SelectNodeValue(L"/Table/Row/Data[@Column=\"Property\"]");
    std::wcout << std::endl << L"Data: " << value;
    CPPUNIT_ASSERT(value == L"DATABASE_SERVER");
    package.Close();
    
    AppSecInc::File::FileDelete(filename);
}

void MsiDatabaseUnitTests::testExecute()
{
    std::wstring filename = AppSecInc::File::GetTemporaryFileNameW();
    std::wcout << std::endl << L"Creating " << filename;
    MsiDatabase database;
    database.Create(filename);
    std::wcout << std::endl << L"Database handle " << std::hex << (MSIHANDLE) database;

    std::wstring path = File::GetModuleDirectoryW() + L"\\TestData_MsiUnitTests";
	database.Execute(L"CREATE TABLE `Property` (`Property` CHAR(72) NOT NULL, `Value` CHAR(0) NOT NULL LOCALIZABLE PRIMARY KEY `Property`)");
	database.Execute(L"INSERT INTO `Property` (`Property`, `Value`) VALUES ('ProductCode', '{GUID}')");
    database.Commit();
    database.Close();

    MsiPackage package(filename);
    MsiInstall install(package);

    AppSecInc::Xml::XmlDocument xmlDoc;
    xmlDoc.LoadXml(install.GetViewData(L"SELECT `Value` FROM `Property` WHERE `Property`='ProductCode'"));
    std::wstring value = xmlDoc.SelectNodeValue(L"/Table/Row/Data[@Column=\"Value\"]");
    std::wcout << std::endl << L"Data: " << value;
    CPPUNIT_ASSERT(value == L"{GUID}");
    package.Close();
    
    AppSecInc::File::FileDelete(filename);
}
