#include "StdAfxUnitTests.h"
#include "CreateDatabasesUnitTests.h"
#include "SqlServer.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::DataSource::CreateDatabasesUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::DataSource;

void CreateDatabasesUnitTests::Test_CreateDatabases_SQLServer()
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
	msiInstall.SetProperty(L"INSTALLLOCATION", AppSecInc::File::GetSpecialFolderPath(CSIDL_COMMON_APPDATA) + L"\\");

    AppSecInc::Xml::XmlDocument xml;

    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"CreateDatabases_SQLServer_Immediate"));
    xml.LoadXml(msiInstall.GetProperty(L"CreateDatabases_SQLServer_Deferred_Install"));

    // two databases, both have create actions, one is checkIfExists
    CPPUNIT_ASSERT(2 == xml.SelectNodes(L"/MSSQLDatabases/MSSQLDatabase")->length);
    CPPUNIT_ASSERT(2 == xml.SelectNodes(L"/MSSQLDatabases/MSSQLDatabase[@actions='create']")->length);
    CPPUNIT_ASSERT(1 == xml.SelectNodes(L"/MSSQLDatabases/MSSQLDatabase[@checkIfExists='false']")->length);
    CPPUNIT_ASSERT(1 == xml.SelectNodes(L"/MSSQLDatabases/MSSQLDatabase[@checkIfExists='true']")->length);
    // only the first database has options, but each have two file specs
    CPPUNIT_ASSERT(1 == xml.SelectNodes(L"/MSSQLDatabases/MSSQLDatabase/MSSQLDatabaseOptions/MSSQLDatabaseOption")->length);
    CPPUNIT_ASSERT(4 == xml.SelectNodes(L"/MSSQLDatabases/MSSQLDatabase/MSSQLDatabaseFileSpecs/MSSQLDatabaseFileSpec")->length);

    // create the databases
    msiInstall.SetProperty(L"CustomActionData", msiInstall.GetProperty(L"CreateDatabases_SQLServer_Deferred_Install"));
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"CreateDatabases_SQLServer_Deferred"));

    // check that both databases exist
    AppSecInc::Databases::MSSQL::MSSQLConnectionInfo connection_info;
    connection_info.SetIPAddress(L"localhost");
    AppSecInc::Databases::MSSQL::MSSQLDatabase database(connection_info);   
    database.Connect();
    // check the first database
    database.SetName(databasename);
    CPPUNIT_ASSERT(database.Exists());
    // check the second database
    database.SetName(databasename + L"2");
    CPPUNIT_ASSERT(database.Exists());

    // drop the created databases
    MSXML2::IXMLDOMNodePtr mssqldatabase_node;
    MSXML2::IXMLDOMNodeListPtr mssqldatabase_nodes = xml.SelectNodes(L"/MSSQLDatabases/MSSQLDatabase");
    while(NULL != (mssqldatabase_node = mssqldatabase_nodes->nextNode()))
        xml.SetAttribute(L"actions", L"drop", mssqldatabase_node); 

    msiInstall.SetProperty(L"CustomActionData", xml.GetXml());
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"CreateDatabases_SQLServer_Deferred"));
}

void CreateDatabasesUnitTests::Test_CreateDatabases_Access()
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
    std::wstring dbq = AppSecInc::File::DirectoryCombine(
        AppSecInc::File::GetTemporaryDirectoryW(),
        AppSecInc::Com::GenerateGUIDStringW() + L".dbq");
    std::wcout << std::endl << L"DBQ: " << dbq;
    msiInstall.SetProperty(L"ACCESS_DATABASE_DBQ", dbq);
	msiInstall.SetProperty(L"INSTALLLOCATION", AppSecInc::File::GetSpecialFolderPath(CSIDL_COMMON_APPDATA) + L"\\");

    AppSecInc::Xml::XmlDocument xml;

    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"CreateDatabases_Access_Immediate"));
    xml.LoadXml(msiInstall.GetProperty(L"CreateDatabases_Access_Deferred_Install"));

    // two databases, both have create actions, one is checkIfExists
    CPPUNIT_ASSERT(1 == xml.SelectNodes(L"/AccessDatabases/AccessDatabase")->length);
    CPPUNIT_ASSERT(1 == xml.SelectNodes(L"/AccessDatabases/AccessDatabase[@actions='create']")->length);
    CPPUNIT_ASSERT(1 == xml.SelectNodes(L"/AccessDatabases/AccessDatabase[@checkIfExists='false']")->length);
    CPPUNIT_ASSERT(0 == xml.SelectNodes(L"/AccessDatabases/AccessDatabase[@checkIfExists='true']")->length);

    // create the databases
    msiInstall.SetProperty(L"CustomActionData", msiInstall.GetProperty(L"CreateDatabases_Access_Deferred_Install"));
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"CreateDatabases_Access_Deferred"));

    // check that the database exists
    AppSecInc::Databases::Access::AccessDatabase database;
    database.SetDBQ(dbq);
    CPPUNIT_ASSERT(database.Exists());

    // drop the created databases
    MSXML2::IXMLDOMNodePtr Accessdatabase_node;
    MSXML2::IXMLDOMNodeListPtr Accessdatabase_nodes = xml.SelectNodes(L"/AccessDatabases/AccessDatabase");
    while(NULL != (Accessdatabase_node = Accessdatabase_nodes->nextNode()))
        xml.SetAttribute(L"actions", L"drop", Accessdatabase_node); 

    msiInstall.SetProperty(L"CustomActionData", xml.GetXml());
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"CreateDatabases_Access_Deferred"));
}

void CreateDatabasesUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"DataSource.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing DataSource.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "CreateDatabases_SQLServer_Immediate"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "CreateDatabases_SQLServer_Deferred"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "CreateDatabases_Access_Immediate"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "CreateDatabases_Access_Deferred"));
 	// CPPUNIT_ASSERT(NULL != GetProcAddress(h, "CreateDatabases_Oracle"));
	::FreeModule(h);
}