#include "StdAfxUnitTests.h"
#include "SqlODBCUnitTests.h"
#include "BinaryIdPathResolver.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::DataSource::SQLODBCUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::DataSource;

void SQLODBCUnitTests::Test_SQLODBC_Connect()
{
	AppSecInc::Msi::MsiShim hInstall;
	MsiInstall msiInstall(hInstall);

	AppSecInc::Databases::MSSQL::MSSQLConnectionInfo info(L"localhost");
	std::wstring connection_string = info.GetConnectionString();
	std::wcout << std::endl << connection_string;

	msiInstall.SetProperty(L"ODBC_CONNECTION_STRING", connection_string);
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"ODBC_Connect"));
	std::wstring connection_established = msiInstall.GetProperty(L"ODBC_CONNECTION_ESTABLISHED");
	std::wstring connection_error = msiInstall.GetProperty(L"ODBC_ERROR");
	CPPUNIT_ASSERT_MESSAGE(StringUtils::wc2mb(connection_error).c_str(), L"1" == connection_established);
}

void SQLODBCUnitTests::Test_SQLODBC_Execute()
{
	AppSecInc::Msi::MsiShim hInstall;
	MsiInstall msiInstall(hInstall);

	AppSecInc::Databases::MSSQL::MSSQLConnectionInfo info(L"localhost");
	std::wstring connection_string = info.GetConnectionString();
	std::wcout << std::endl << connection_string;

	msiInstall.SetProperty(L"ODBC_CONNECTION_STRING", connection_string);
	msiInstall.SetProperty(L"ODBC_SQL_QUERY", L"SELECT @@VERSION");

	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"ODBC_Execute"));
}

void SQLODBCUnitTests::Test_SQLODBC_GetString()
{
	AppSecInc::Msi::MsiShim hInstall;
	MsiInstall msiInstall(hInstall);

	AppSecInc::Databases::MSSQL::MSSQLConnectionInfo info(L"localhost");
	std::wstring connection_string = info.GetConnectionString();
	std::wcout << std::endl << connection_string;

	msiInstall.SetProperty(L"ODBC_CONNECTION_STRING", connection_string);
	msiInstall.SetProperty(L"ODBC_SQL_QUERY", L"SELECT @@VERSION");

	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"ODBC_GetString"));

    std::wstring version = msiInstall.GetProperty(L"ODBC_SQL_RESULT");
    std::wcout << std::endl << L"Result: " << version;
    CPPUNIT_ASSERT(! version.empty());
}

void SQLODBCUnitTests::Test_SQLODBC_GetString_Empty()
{
	AppSecInc::Msi::MsiShim hInstall;
	MsiInstall msiInstall(hInstall);

	AppSecInc::Databases::MSSQL::MSSQLConnectionInfo info(L"localhost");
	std::wstring connection_string = info.GetConnectionString();

	msiInstall.SetProperty(L"ODBC_CONNECTION_STRING", connection_string);
	msiInstall.SetProperty(L"ODBC_SQL_QUERY",  L"SELECT 'nothing' WHERE @@VERSION = 'invalid'");
	msiInstall.SetProperty(L"ODBC_SQL_RESULT", L"previous value" );
	msiInstall.SetProperty(L"ODBC_SQL_FLAGS",  L"ODBC_SQL_FLAG_NO_ROWS_RETURN_EMPTY" );

	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"ODBC_GetString"));

    std::wstring result = msiInstall.GetProperty(L"ODBC_SQL_RESULT");
    CPPUNIT_ASSERT(result.empty());
}

void SQLODBCUnitTests::Test_SQLODBC_GetString_Empty_Error()
{
	AppSecInc::Msi::MsiShim hInstall;
	MsiInstall msiInstall(hInstall);

	AppSecInc::Databases::MSSQL::MSSQLConnectionInfo info(L"localhost");
	std::wstring connection_string = info.GetConnectionString();

	msiInstall.SetProperty(L"ODBC_CONNECTION_STRING", connection_string);
	msiInstall.SetProperty(L"ODBC_SQL_QUERY", L"SELECT 'nothing' WHERE @@VERSION = 'invalid'");
	msiInstall.SetProperty(L"ODBC_SQL_RESULT", L"previous value" );

	// action should fail
	CPPUNIT_ASSERT(ERROR_SUCCESS != hInstall.ExecuteCA(L"DataSource.dll", L"ODBC_GetString"));

	// nevertheless result should be empty
    std::wstring result = msiInstall.GetProperty(L"ODBC_SQL_RESULT");
    CPPUNIT_ASSERT(result.empty());
}

void SQLODBCUnitTests::Test_SQLODBC_GetScalar()
{
	AppSecInc::Msi::MsiShim hInstall;
	MsiInstall msiInstall(hInstall);

	AppSecInc::Databases::MSSQL::MSSQLConnectionInfo info(L"localhost");
	std::wstring connection_string = info.GetConnectionString();
	std::wcout << std::endl << connection_string;

	msiInstall.SetProperty(L"ODBC_CONNECTION_STRING", connection_string);
	msiInstall.SetProperty(L"ODBC_SQL_QUERY", L"SELECT COUNT(*) FROM [master].dbo.syscolumns");

	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"ODBC_GetScalar"));

    long count = AppSecInc::StringUtils::stringToLong(msiInstall.GetProperty(L"ODBC_SQL_RESULT"));
    std::wcout << std::endl << L"Result: " << count;
    CPPUNIT_ASSERT(count > 0);
}

void SQLODBCUnitTests::Test_SQLODBC_GetXml()
{
	AppSecInc::Msi::MsiShim hInstall;
	MsiInstall msiInstall(hInstall);

	AppSecInc::Databases::MSSQL::MSSQLConnectionInfo info(L"localhost");
	std::wstring connection_string = info.GetConnectionString();
	std::wcout << std::endl << connection_string;

	msiInstall.SetProperty(L"ODBC_CONNECTION_STRING", connection_string);
	msiInstall.SetProperty(L"ODBC_SQL_QUERY", L"SELECT TOP 10 name, usertype, id " \
		L"FROM [master].dbo.syscolumns ORDER BY [name] DESC");

	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"ODBC_GetXml"));

    std::wstring xml = msiInstall.GetProperty(L"ODBC_SQL_RESULT");
    std::wcout << std::endl << L"Result: " << xml;

    CPPUNIT_ASSERT(! xml.empty());
    AppSecInc::Xml::XmlDocument xmldoc;
    xmldoc.LoadXml(xml);
    CPPUNIT_ASSERT(L"3" == xmldoc.SelectNodeAttributeValue(L"/DataSet", L"columns"));
    CPPUNIT_ASSERT(L"10" == xmldoc.SelectNodeAttributeValue(L"/DataSet", L"rows"));
}

void SQLODBCUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"DataSource.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing DataSource.dll", h != NULL);
    // immedate custom actions
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "ODBC_Connect"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "ODBC_Execute"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "ODBC_GetScalar"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "ODBC_GetString"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "ODBC_GetXml"));
    // deferred table-driven custom actions
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Execute_ODBC_Immediate"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Execute_ODBC_Deferred"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "DataSource_ODBC_Immediate"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "DataSource_ODBC_Deferred"));
	::FreeLibrary(h);
}

void SQLODBCUnitTests::Test_Execute_ODBC()
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
    // generate an MSSQL database name
    std::wstring databasename = AppSecInc::Com::GenerateGUIDStringW();
    AppSecInc::StringUtils::lrtrim(databasename, L"{}");
    std::wcout << std::endl << L"Database: " << databasename;
    msiInstall.SetProperty(L"MSSQL_DATABASE_NAME", databasename);
    // generate an Access database file name
    std::wstring dbq = AppSecInc::File::DirectoryCombine(
        AppSecInc::File::GetTemporaryDirectoryW(),
        AppSecInc::Com::GenerateGUIDStringW() + L".mdf");
    std::wcout << std::endl << L"DBQ: " << dbq;
    msiInstall.SetProperty(L"ACCESS_DATABASE_DBQ", dbq);
    // adjust path properties
    msiInstall.SetProperty(L"SOURCELOCATION", testdatapath);
	msiInstall.SetProperty(L"INSTALLLOCATION", AppSecInc::File::GetSpecialFolderPath(CSIDL_COMMON_APPDATA) + L"\\");

    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"Execute_ODBC_Immediate"));
    AppSecInc::Xml::XmlDocument xml;
    xml.LoadXml(msiInstall.GetProperty(L"Execute_ODBC_Deferred_Install"));

    CPPUNIT_ASSERT(14 == xml.SelectNodes(L"/ODBCExecutes/ODBCExecute")->length);
    CPPUNIT_ASSERT(13 == xml.SelectNodes(L"/ODBCExecutes/ODBCExecute/Sql/text()")->length);
    CPPUNIT_ASSERT(14 == xml.SelectNodes(L"/ODBCExecutes/ODBCExecute/ConnectionString/text()")->length);

    // Access database
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"CreateDatabases_Access_Immediate"));
    msiInstall.SetProperty(L"CustomActionData", msiInstall.GetProperty(L"CreateDatabases_Access_Deferred_Install"));
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"CreateDatabases_Access_Deferred"));

    // MSSQL database
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"CreateDatabases_SQLServer_Immediate"));
    msiInstall.SetProperty(L"CustomActionData", msiInstall.GetProperty(L"CreateDatabases_SQLServer_Deferred_Install"));
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"CreateDatabases_SQLServer_Deferred"));

    // one of the queries produces a Columns.xml file, delete it from a previous run
    std::wstring columnsxml = AppSecInc::File::DirectoryCombine(msiInstall.GetProperty(L"INSTALLLOCATION"), L"Columns.xml");
    if (AppSecInc::File::FileExists(columnsxml)) AppSecInc::File::FileDelete(columnsxml);

    // execute SQL
    msiInstall.SetProperty(L"CustomActionData", msiInstall.GetProperty(L"Execute_ODBC_Deferred_Install"));
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"Execute_ODBC_Deferred"));

    // check MSSQL tables
    AppSecInc::Databases::MSSQL::MSSQLConnectionInfo mssql_connection_info;
    mssql_connection_info.SetIPAddress(L"localhost");
    AppSecInc::Databases::ODBC::ODBCConnection mssql_connection;
    mssql_connection.Connect(mssql_connection_info);
    int tables = mssql_connection.GetScalar(L"SELECT COUNT(*) FROM [" + databasename + L"].sys.tables");
    std::wcout << std::endl << L" " << databasename << L": " << tables << L" table(s)";
    CPPUNIT_ASSERT(tables == 5);

    // check MSSQL columns.xml
    std::wcout << std::endl << columnsxml;
    AppSecInc::Xml::XmlDocument columnsxmldoc;
    columnsxmldoc.Load(columnsxml);
    long rows = columnsxmldoc.SelectNodes(L"/Data/DataSet/RowSet/Row")->length;
    int rows_expected = mssql_connection.GetScalar(L"SELECT COUNT(*) FROM [master].dbo.syscolumns");
    std::wcout << std::endl << L" [master].dbo.syscolumns: " << rows << L" vs. " << rows_expected;
    CPPUNIT_ASSERT(rows == rows_expected);

    // check access table
    AppSecInc::Databases::Access::AccessConnectionInfo access_connection_info;
    access_connection_info.SetDBQ(dbq);
    AppSecInc::Databases::ODBC::ODBCConnection access_connection;
    access_connection.Connect(access_connection_info);
    int access_table_not_encoded_rows = access_connection.GetScalar(L"SELECT COUNT(*) FROM TableNotEncoded");
    std::wcout << std::endl << L" " << dbq << L".TableNotEncoded: " << access_table_not_encoded_rows << L" row(s)";
    CPPUNIT_ASSERT(access_table_not_encoded_rows == 2);
    int access_table1_rows = access_connection.GetScalar(L"SELECT COUNT(*) FROM Table1");
    std::wcout << std::endl << L" " << dbq << L".Table1: " << access_table1_rows << L" row(s)";
    CPPUNIT_ASSERT(access_table1_rows == 0);

    // drop the created databases
    MSXML2::IXMLDOMNodePtr mssqldatabase_node;
    MSXML2::IXMLDOMNodeListPtr mssqldatabase_nodes = xml.SelectNodes(L"/MSSQLDatabases/MSSQLDatabase");
    while(NULL != (mssqldatabase_node = mssqldatabase_nodes->nextNode()))
        xml.SetAttribute(L"actions", L"drop", mssqldatabase_node); 

    MSXML2::IXMLDOMNodePtr accessdatabase_node;
    MSXML2::IXMLDOMNodeListPtr accessdatabase_nodes = xml.SelectNodes(L"/AccessDatabases/AccessDatabase");
    while(NULL != (accessdatabase_node = accessdatabase_nodes->nextNode()))
        xml.SetAttribute(L"actions", L"drop", accessdatabase_node); 

    msiInstall.SetProperty(L"CustomActionData", xml.GetXml());
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"CreateDatabases_SQLServer_Deferred"));
}

void SQLODBCUnitTests::Test_DataSource_ODBC()
{
    AppSecInc::Msi::MsiShim hInstall;

    std::wstring testdatapath = AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_DataSourceUnitTests";
    hInstall.Import(testdatapath, L"ODBCDataSourceConfig.idt");
    AppSecInc::Msi::MsiInstall msiInstall(hInstall);
    msiInstall.SetProperty(L"INSTALLLOCATION", AppSecInc::File::GetTemporaryDirectoryW());
    std::wstring dsn_name_sql = AppSecInc::Com::GenerateGUIDStringW();
    AppSecInc::StringUtils::lrtrim(dsn_name_sql, L"{}");
    AppSecInc::StringUtils::replace(dsn_name_sql, L"-", L"");
    std::wstring dsn_name_access = AppSecInc::Com::GenerateGUIDStringW();
    AppSecInc::StringUtils::lrtrim(dsn_name_access, L"{}");
    AppSecInc::StringUtils::replace(dsn_name_access, L"-", L"");
    msiInstall.SetProperty(L"DSN_NAME_SQL", dsn_name_sql);
    msiInstall.SetProperty(L"DSN_NAME_ACCESS", dsn_name_access);

    AppSecInc::Xml::XmlDocument xml;
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"DataSource_ODBC_Immediate"));
    xml.LoadXml(msiInstall.GetProperty(L"DataSource_ODBC_Deferred_Install"));

    // two total data sources
    CPPUNIT_ASSERT(2 == xml.SelectNodes(L"/Table/Row[@operation='create']")->length);

    msiInstall.SetProperty(L"CustomActionData", msiInstall.GetProperty(L"DataSource_ODBC_Deferred_Install"));
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"DataSource_ODBC_Deferred"));

    // delete the DSNs
    MSXML2::IXMLDOMNodeListPtr rows = xml.SelectNodes(L"/Table/Row[@operation='create']");
    MSXML2::IXMLDOMNodePtr row = NULL;
    while (NULL != (row = rows->nextNode()))
    {
        std::wstring name = xml.SelectNodeValue(L"Data[@Column=\"Name\"]", row);
        CPPUNIT_ASSERT(AppSecInc::Registry::KeyExists(HKEY_CURRENT_USER, L"Software\\ODBC\\ODBC.INI\\" + name));
        std::wstring driver = xml.SelectNodeValue(L"Data[@Column=\"Driver\"]", row);
        std::wcout << std::endl << L"Removing " << driver << L" DSN: " << name;
        AppSecInc::Databases::ODBC::ODBCDataSource::Configure(ODBC_REMOVE_DSN, driver, L"DSN=" + name);
    }
}


void SQLODBCUnitTests::Test_BinaryIdPathResolver_pathToId()
{
	AppSecInc::Databases::ODBC::BinaryIdPathResolver r(0);
	
	CPPUNIT_ASSERT(L"Binary_Id"     == r.pathToId(L"Binary_Id"));
	CPPUNIT_ASSERT(L"dir_file1_sql" == r.pathToId(L"..\\\\dir\\.\\file1.sql"));
}

void SQLODBCUnitTests::Test_BinaryIdPathResolver_readContent()
{
    AppSecInc::Msi::MsiShim hInstall;
    std::wstring testdatapath = AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_DataSourceUnitTests";
    hInstall.Import(testdatapath, L"Binary.idt");
    AppSecInc::Msi::MsiInstall msiInstall(hInstall);

	AppSecInc::Databases::ODBC::BinaryIdPathResolver r( &msiInstall );
	std::wstring result = r.readContent(L"v1_0_main_sql");
	CPPUNIT_ASSERT(L"DECLARE @a INT\r\n:r v1.0\\other.sql\r\nGO\r\n" == result);
	
	result = r.readContent(L"v1.0\\other.sql");
	CPPUNIT_ASSERT(L"DECLARE @b INT\r\n" == result);
}

void SQLODBCUnitTests::Test_BinaryIdPathResolver_processInserts()
{
    AppSecInc::Msi::MsiShim hInstall;
    std::wstring testdatapath = AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_DataSourceUnitTests";
    hInstall.Import(testdatapath, L"Binary.idt");
    AppSecInc::Msi::MsiInstall msiInstall(hInstall);

	AppSecInc::Databases::ODBC::BinaryIdPathResolver r( &msiInstall );
	AppSecInc::Databases::ODBC::OdbcParser parser;
	parser.setPathResolver(&r);
	parser.setSqlFlavour(L"mssql");
	parser.setSourcePath(L"v1_0_main_sql");
	
	std::wstring result = parser.processInsertsOnly();
	CPPUNIT_ASSERT(L"DECLARE @a INT\r\nDECLARE @b INT\r\nGO\r" == result);
}