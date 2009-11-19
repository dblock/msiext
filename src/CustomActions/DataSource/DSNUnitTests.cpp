#include "StdAfxUnitTests.h"
#include "DSNUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::DataSource::DSNUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::DataSource;

#include "ConfigDataSource.h"
#include "Access.h"
#include "Oracle.h"
#include "SqlServer.h"

std::wstring DSNUnitTests::GetUniqueName()
{
	std::wstring name = AppSecInc::Com::GenerateGUIDStringW();
    StringUtils::lrtrim(name, L"{}");
    StringUtils::replace(name, L"-", L"");
	std::wcout << std::endl << L"DSN: " << name;
	return name;
}

void DSNUnitTests::Test_CreateRemoveDSN()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

    std::wstring guid = GetUniqueName();

    msiInstall.SetProperty(L"DSN_ATTRIBUTES", L"DSN=" + guid);
    msiInstall.SetProperty(L"ODBC_FLAG", L"ODBC_ADD_DSN");
    msiInstall.SetProperty(L"ODBC_DRIVER", L"Microsoft Access Driver (*.MDB)"); 

	CPPUNIT_ASSERT(ERROR_SUCCESS == ConfigDataSource(hInstall));
    
    msiInstall.SetProperty(L"ODBC_FLAG", L"ODBC_REMOVE_DSN");
	CPPUNIT_ASSERT(ERROR_SUCCESS == ConfigDataSource(hInstall));
}

void DSNUnitTests::Test_CreateRemoveDSN_Access()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

    std::wstring guid = GetUniqueName();

    std::wstring mdb = AppSecInc::File::GetModuleDirectoryW();
    mdb.append(L"\\TestData_DataSourceUnitTests\\Test.mdb");
	std::wcout << std::endl << mdb;
    CPPUNIT_ASSERT(AppSecInc::File::FileExists(mdb));

    msiInstall.SetProperty(L"DSN_NAME", guid);
    msiInstall.SetProperty(L"DSN_ACCESS_DBQ", mdb);
    //! \todo Extend unit test for password protected MDB.
    // msiInstall.SetProperty(L"DSN_ACCESS_UID", L"");
    // msiInstall.SetProperty(L"DSN_ACCESS_PWD", L"");

    msiInstall.SetProperty(L"ODBC_FLAG", L"ODBC_ADD_DSN");
	CPPUNIT_ASSERT(ERROR_SUCCESS == ConfigDataSource_Access(hInstall));

    AppSecInc::Databases::ODBC::ODBCConnectionStringInfo info(L"DSN=" + guid);
    AppSecInc::Databases::ODBC::ODBCConnection conn;
	conn.Connect(info);

    std::string value1 = conn.GetString(L"SELECT Value FROM NameValueTable WHERE Name = 'Name1'");
    std::cout << std::endl << "Value: " << value1;
    CPPUNIT_ASSERT(value1 == "Value1");

    msiInstall.SetProperty(L"ODBC_FLAG", L"ODBC_REMOVE_DSN");
    msiInstall.SetProperty(L"DSN_ATTRIBUTES", L"DSN=" + guid);
	CPPUNIT_ASSERT(ERROR_SUCCESS == ConfigDataSource_Access(hInstall));
}

void DSNUnitTests::Test_CreateRemoveDSN_SQLServer()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

    std::wstring guid = GetUniqueName();

    msiInstall.SetProperty(L"DSN_NAME", guid);
    msiInstall.SetProperty(L"DSN_MSSQL_DATABASE", L"master");
    msiInstall.SetProperty(L"DSN_MSSQL_DESCRIPTION", L"test");
    msiInstall.SetProperty(L"DSN_MSSQL_SERVER", L"(local)");
    msiInstall.SetProperty(L"DSN_MSSQL_NETWORK", L"(default)");
    msiInstall.SetProperty(L"DSN_MSSQL_ADDRESS", L"(default)");
    msiInstall.SetProperty(L"DSN_MSSQL_TRUSTED_CONNECTION", L"yes");

    msiInstall.SetProperty(L"ODBC_FLAG", L"ODBC_ADD_DSN");
	CPPUNIT_ASSERT(ERROR_SUCCESS == ConfigDataSource_SQLServer(hInstall));

    AppSecInc::Databases::ODBC::ODBCConnectionStringInfo info(L"DSN=" + guid);
    AppSecInc::Databases::ODBC::ODBCConnection conn;
	conn.Connect(info);
    std::string version = conn.GetString(L"SELECT @@VERSION");
    std::cout << std::endl << "Version: " << std::endl << version;
    CPPUNIT_ASSERT(version.length() > 0);
    CPPUNIT_ASSERT(AppSecInc::StringUtils::startsWith(version, "Microsoft SQL Server"));

    msiInstall.SetProperty(L"ODBC_FLAG", L"ODBC_REMOVE_DSN");
    msiInstall.SetProperty(L"DSN_ATTRIBUTES", L"DSN=" + guid);
	CPPUNIT_ASSERT(ERROR_SUCCESS == ConfigDataSource_SQLServer(hInstall));
}

void DSNUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"DataSource.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing DataSource.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "ConfigDataSource"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "ConfigDataSource_Access"));
	// CPPUNIT_ASSERT(NULL != GetProcAddress(h, "ConfigDataSource_Oracle"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "ConfigDataSource_SQLServer"));
	::FreeLibrary(h);
}