#include "StdAfxUnitTests.h"
#include "ConfigDataSourceUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::DataSource::ConfigDataSourceUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::DataSource;

void ConfigDataSourceUnitTests::Test_ConfigDataSource()
{
    struct TestData
    {
        LPCWSTR driver;
        LPCWSTR name;
        LPCWSTR attributes;
    };

    TestData testdata[] = 
    {
        { L"SQL Server", L"LocalSQLServer", L"SERVER=localhost,1433;Description=local host dsn;Trusted_Connection=yes;" },
    };

	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        std::wcout << std::endl << L"Data source: " << testdata[i].name;
        std::wstringstream attributes;
        attributes << L"DSN=" << testdata[i].name << L";" << testdata[i].attributes;

        msiInstall.SetProperty(L"ODBC_DRIVER", testdata[i].driver);
        msiInstall.SetProperty(L"DSN_ATTRIBUTES", attributes.str());
        msiInstall.SetProperty(L"ODBC_FLAG", L"ODBC_ADD_DSN");
        CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"ConfigDataSource"));

        msiInstall.SetProperty(L"DSN_NAME", testdata[i].name);
        msiInstall.SetProperty(L"ODBC_FLAG", L"ODBC_CONFIG_DSN");
        CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"ConfigDataSource"));

        msiInstall.SetProperty(L"ODBC_FLAG", L"ODBC_REMOVE_DSN");
        CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"ConfigDataSource"));
    }
}

void ConfigDataSourceUnitTests::Test_ConfigDataSource_SQLServer()
{
    struct TestData
    {
        LPCWSTR name;
        LPCWSTR server;
        LPCWSTR description;
        LPCWSTR network;
        LPCWSTR address;
        LPCWSTR database;
        bool trusted;
    };

    TestData testdata[] = 
    {
        { L"Test_ConfigDataSource_SQLServer", L"localhost,1433", L"test dsn", L"", L"", L"master", true },
        { L"Test_ConfigDataSource_SQLServer", L"localhost\\instance", L"test dsn, instance name", L"DBMSSOCN", L"", L"master", false }
    };

	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        std::wcout << std::endl << L"Data source: " << testdata[i].name;

        msiInstall.SetProperty(L"DSN_NAME", testdata[i].name);
        msiInstall.SetProperty(L"DSN_MSSQL_SERVER", testdata[i].server);
        msiInstall.SetProperty(L"DSN_MSSQL_DESCRIPTION", testdata[i].description);
        msiInstall.SetProperty(L"DSN_MSSQL_NETWORK", testdata[i].network);
        msiInstall.SetProperty(L"DSN_MSSQL_ADDRESS", testdata[i].address);
        msiInstall.SetProperty(L"DSN_MSSQL_DATABASE", testdata[i].database);
        msiInstall.SetProperty(L"DSN_MSSQL_TRUSTED_CONNECTION", testdata[i].trusted ? L"true" : L"false");

        msiInstall.SetProperty(L"ODBC_FLAG", L"ODBC_ADD_DSN");
        CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"ConfigDataSource_SQLServer"));

        msiInstall.SetProperty(L"ODBC_FLAG", L"ODBC_CONFIG_DSN");
        CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"ConfigDataSource_SQLServer"));

        msiInstall.SetProperty(L"ODBC_FLAG", L"ODBC_REMOVE_DSN");
        CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"ConfigDataSource_SQLServer"));
    }
}

void ConfigDataSourceUnitTests::Test_ConfigDataSource_Access()
{
    struct TestData
    {
        LPCWSTR name;
        LPCWSTR dbq;
        LPCWSTR uid;
        LPCWSTR pwd;
    };

    TestData testdata[] = 
    {
        { L"MyAccessDB", L"C:\\temp\\database.mdb", L"username", L"password" }
    };

	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        std::wcout << std::endl << L"Data source: " << testdata[i].name;

        msiInstall.SetProperty(L"DSN_NAME", testdata[i].name);
        msiInstall.SetProperty(L"DSN_ACCESS_DBQ", testdata[i].dbq);
        msiInstall.SetProperty(L"DSN_ACCESS_UID", testdata[i].uid);
        msiInstall.SetProperty(L"DSN_ACCESS_PWD", testdata[i].pwd);

        msiInstall.SetProperty(L"ODBC_FLAG", L"ODBC_ADD_DSN");
        CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"ConfigDataSource_Access"));

        msiInstall.SetProperty(L"ODBC_FLAG", L"ODBC_CONFIG_DSN");
        CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"ConfigDataSource_Access"));

        msiInstall.SetProperty(L"ODBC_FLAG", L"ODBC_REMOVE_DSN");
        CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"ConfigDataSource_Access"));
    }
}

void ConfigDataSourceUnitTests::Test_ConfigDataSource_Oracle()
{
}

void ConfigDataSourceUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"DataSource.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing DataSource.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "ConfigDataSource"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "ConfigDataSource_SQLServer"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "ConfigDataSource_Access"));
 	// CPPUNIT_ASSERT(NULL != GetProcAddress(h, "ConfigDataSource_Oracle"));
	::FreeModule(h);
}