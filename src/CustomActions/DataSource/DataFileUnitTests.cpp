#include "StdAfxUnitTests.h"
#include "DataFileUnitTests.h"
#include "SqlServer.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::DataSource::DataFileUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::DataSource;

void DataFileUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"DataSource.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing DataSource.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "DataFile_SQLServer_Immediate"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "DataFile_SQLServer_Deferred"));
 	// CPPUNIT_ASSERT(NULL != GetProcAddress(h, "DataFile_Oracle"));
	::FreeModule(h);
}

void DataFileUnitTests::Test_DataFile_SQLServer()
{
    AppSecInc::Msi::MsiShim hInstall;

    std::wstring testdatapath = AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_DataSourceUnitTests";
    for each(const std::wstring& idtfile in AppSecInc::File::GetFiles(testdatapath, L"*.idt"))
    {
        std::wstring idtfile_name = AppSecInc::File::GetFileNameW(idtfile);
        std::wcout << std::endl << L" Importing \"" << idtfile_name << L"\"";
        hInstall.Import(testdatapath, idtfile_name);
    }

    AppSecInc::Msi::MsiInstall msiInstall(hInstall);
    std::wstring databasename = AppSecInc::Com::GenerateGUIDStringW();
    AppSecInc::StringUtils::lrtrim(databasename, L"{}");
    std::wcout << std::endl << L"Database: " << databasename;
    msiInstall.SetProperty(L"MSSQL_DATABASE_NAME", databasename);
    msiInstall.SetProperty(L"INSTALLLOCATION", AppSecInc::File::GetTemporaryDirectoryW());
    msiInstall.SetProperty(L"SOURCELOCATION", testdatapath + L"\\");

    AppSecInc::Xml::XmlDocument xml;

    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"DataFile_SQLServer_Immediate"));
    xml.LoadXml(msiInstall.GetProperty(L"DataFile_SQLServer_Deferred_Install"));

    // two BULK INSERTs, both are executed
    CPPUNIT_ASSERT(2 == xml.SelectNodes(L"/MSSQLDataFiles/MSSQLDataFile")->length);
    CPPUNIT_ASSERT(2 == xml.SelectNodes(L"/MSSQLDataFiles/MSSQLDataFile[@execute='true']")->length);
    CPPUNIT_ASSERT(2 == xml.SelectNodes(L"/MSSQLDataFiles/MSSQLDataFile/Filename/text()")->length);
    CPPUNIT_ASSERT(2 == xml.SelectNodes(L"/MSSQLDataFiles/MSSQLDataFile/Database/text()")->length);
    CPPUNIT_ASSERT(2 == xml.SelectNodes(L"/MSSQLDataFiles/MSSQLDataFile/Table/text()")->length);
    // one deleteAfterExecute item (binary files are created in the immediate CA and deleted in deferred)
    CPPUNIT_ASSERT(1 == xml.SelectNodes(L"/MSSQLDataFiles/MSSQLDataFile[@deleteAfterExecute='true']")->length);
    CPPUNIT_ASSERT(1 == xml.SelectNodes(L"/MSSQLDataFiles/MSSQLDataFile[@deleteAfterExecute='false']")->length);
    // seven total parameters
    CPPUNIT_ASSERT(7 == xml.SelectNodes(L"/MSSQLDataFiles/MSSQLDataFile/MSSQLDataFileParameters/MSSQLDataFileParameter")->length);

    // create the database
    AppSecInc::Databases::MSSQL::MSSQLConnectionInfo connection_info;
    AppSecInc::Databases::MSSQL::MSSQLDatabase database(connection_info);   
    database.SetName(databasename);
    database.Connect();
    std::wcout << std::endl << L"Creating " << databasename;
    database.Create();
    std::wcout << std::endl << L"Creating BulkInsertTable";
    std::wstringstream createtable_s;
    createtable_s << L"CREATE TABLE [" << databasename << L"].[dbo].[BulkInsertTable] " \
        L"( [BulkInsertTable_Id] int IDENTITY(1,1) NOT NULL, " \
        L"[Number] int NOT NULL )";
    database.GetConnection().Execute(createtable_s.str());

    // bulk insert data
    msiInstall.SetProperty(L"CustomActionData", xml.GetXml());
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"DataFile_SQLServer_Deferred"));

    // check number of rows in the table, two sets of 3 were inserted
    int count = database.GetConnection().GetScalar(L"SELECT COUNT(*) FROM [" + databasename + L"].[dbo].[BulkInsertTable]");
    std::wcout << std::endl << L"Rows: " << count;
    CPPUNIT_ASSERT(6 == count);
    std::wcout << std::endl << L"Dropping " << databasename;
    database.Drop();
}
