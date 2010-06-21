#include "StdAfxUnitTests.h"
#include "ConnectionUnitTests.h"

using namespace AppSecInc::Databases::ODBC;
using namespace AppSecInc::Databases::MSSQL;
using namespace AppSecInc::Databases::Access;
using namespace AppSecInc::UnitTests::Databases::ODBC;

CPPUNIT_TEST_SUITE_REGISTRATION(ODBCConnectionUnitTests);

void ODBCConnectionUnitTests::testConstructorDestructor()
{
	{
		ODBCConnection conn;
	}

	{
		ODBCConnection * p = new ODBCConnection();
		delete p;
	}
}

void ODBCConnectionUnitTests::testInitialize()
{
	ODBCConnection conn;
	conn.Initialize();
    try
    {
        conn.Initialize();
        throw "Expected exception";
    }
    catch(std::exception)
    {

    }
	conn.Terminate();
}

void ODBCConnectionUnitTests::testGetError()
{
	ODBCConnection conn;
	// no error
    try { conn.GetError(); throw "Expected exception"; } catch (std::exception&) { }
	// connect to a server that doesn't exist
	MSSQLConnectionInfo info(L"127.0.0.1", -2);
    try { conn.Connect(info); throw "Expected exception"; } catch (std::exception&) { }
    std::wcout << std::endl << L"Error => {" << std::endl << conn.GetError() << L"}";
	CPPUNIT_ASSERT(conn.GetError() == 
		L"SQLSTATE: 08001, Native error: 17, Message: [Microsoft][ODBC SQL Server Driver][DBNETLIB]" \
			L"SQL Server does not exist or access denied.\n" \
		L"SQLSTATE: 01000, Native error: 53, Message: [Microsoft][ODBC SQL Server Driver][DBNETLIB]" \
			L"ConnectionOpen (Connect()).");
    std::vector<ODBCError> errors = conn.GetErrors();
	CPPUNIT_ASSERT(2 == errors.size());
	CPPUNIT_ASSERT(errors[0].state == L"08001");
	CPPUNIT_ASSERT(errors[0].native_error == 17);
    std::wcout << std::endl << errors[0].message;
	CPPUNIT_ASSERT(errors[0].message == L"[Microsoft][ODBC SQL Server Driver][DBNETLIB]" \
		L"SQL Server does not exist or access denied.");
	CPPUNIT_ASSERT(errors[1].state == L"01000");
	CPPUNIT_ASSERT(errors[1].native_error == 53);
	std::wcout << std::endl << errors[1].message;
	CPPUNIT_ASSERT(errors[1].message == L"[Microsoft][ODBC SQL Server Driver][DBNETLIB]" \
		L"ConnectionOpen (Connect()).");
}

void ODBCConnectionUnitTests::testConnectWithODBCConnectionInfo()
{
	MSSQLConnectionInfo info(L"localhost");

	std::wstring connection_string = info.GetConnectionString();
    std::wcout << std::endl << connection_string;

	ODBCConnection conn;
	conn.Connect(info);
    try { conn.Connect(info); throw "Expected exception"; } catch (std::exception&) { }
    conn.Disconnect();
    try { conn.Disconnect(); throw "Expected exception"; } catch (std::exception&) { }
}

void ODBCConnectionUnitTests::testGetScalar()
{
	MSSQLConnectionInfo info(L"localhost");
    info.SetTrustedAuth(true);

	ODBCConnection conn;
	conn.Connect(info);

    long long_result = conn.GetScalar(L"SELECT COUNT(*) FROM [master].dbo.sysobjects");
    std::cout << std::endl << L" [master].dbo.sysobjects: " << long_result;
    CPPUNIT_ASSERT(long_result > 0);
}

void ODBCConnectionUnitTests::testGetString()
{
	MSSQLConnectionInfo info(L"localhost");
	ODBCConnection conn;
    conn.Connect(info);

    std::string result = conn.GetString(L"SELECT @@VERSION");
    std::cout << std::endl << " version: " << result;
    CPPUNIT_ASSERT(result.length() > 0);
    CPPUNIT_ASSERT(strlen(result.c_str()) == result.length());
    // a string longer than the output
    result = conn.GetString(L"SELECT @@SERVERNAME");
    std::cout << std::endl << " servername: " << result;
    CPPUNIT_ASSERT(result.length() > 0);
    CPPUNIT_ASSERT(strlen(result.c_str()) == result.length());

	// tests ODBC_SQL_FLAG_NO_ROWS_RETURN_EMPTY flag
    result = conn.GetString(L"SELECT 'nothing' WHERE @@VERSION = 'invalid'",
		ODBC_SQL_FLAG_NO_ROWS_RETURN_EMPTY);
    CPPUNIT_ASSERT(result.length() == 0);

	try 
	{
		conn.GetString(L"SELECT 'nothing' WHERE @@VERSION = 'invalid'");
		throw "expected std::exception";
	}
	catch(std::exception&) { }
}

void ODBCConnectionUnitTests::testGetWString()
{
	MSSQLConnectionInfo info(L"localhost");
	ODBCConnection conn;
    conn.Connect(info);

    std::wstring result = conn.GetWString(L"SELECT SERVERPROPERTY('Collation')");
    std::wcout << std::endl << L" Collation: " << result;
    CPPUNIT_ASSERT(result.length() > 0);
    CPPUNIT_ASSERT(wcslen(result.c_str()) == result.length());

	// tests ODBC_SQL_FLAG_NO_ROWS_RETURN_EMPTY flag
    result = conn.GetWString(L"SELECT 'nothing' WHERE @@VERSION = 'invalid'",
		ODBC_SQL_FLAG_NO_ROWS_RETURN_EMPTY);
    CPPUNIT_ASSERT(result.length() == 0);

	try 
	{
		conn.GetWString(L"SELECT 'nothing' WHERE @@VERSION = 'invalid'");
		throw "expected std::exception";
	}
	catch(std::exception&) { }
}

void ODBCConnectionUnitTests::testGetXml()
{
    struct testGetXml_TestData
    {
        LPCWSTR query;
        int expected_columns;
        int expected_rows;
        int expected_messages;
    };

    testGetXml_TestData testdata[] =
    {
        { L"SELECT @@VERSION", 1, 1, 0 },
        { L"PRINT 'Hello World'", 0, 0, 1 },
        { L"SELECT TOP 10 name, usertype, id FROM [master].dbo.syscolumns ORDER BY [name] DESC", 3, 10, 0 },
        { L"SELECT TOP 10 name, usertype, id FROM [master].dbo.syscolumns WHERE [name] = 'ThisColumnDoesntExist'", 3, 0, 0 },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
	    MSSQLConnectionInfo info(L"localhost");

        ODBCConnection conn;
        conn.Connect(info);

        std::wstring xml = conn.GetXml(testdata[i].query);
        std::wcout << std::endl << xml;
        CPPUNIT_ASSERT(! xml.empty());
        AppSecInc::Xml::XmlDocument xmldoc;
        xmldoc.LoadXml(xml);
        CPPUNIT_ASSERT(testdata[i].expected_columns == AppSecInc::StringUtils::stringToLong(
            xmldoc.GetAttributeValue(L"/DataSet", L"columns")));
        CPPUNIT_ASSERT(testdata[i].expected_rows == AppSecInc::StringUtils::stringToLong(
            xmldoc.GetAttributeValue(L"/DataSet", L"rows")));
        CPPUNIT_ASSERT(testdata[i].expected_messages == 
            xmldoc.SelectNodes(L"/DataSet/Messages/Message")->length);
    }
}

void ODBCConnectionUnitTests::testExecuteExplicitBind()
{
	MSSQLConnectionInfo info(L"localhost");

    ODBCConnection conn;
    conn.Connect(info);

	ODBCRowSet results;
	results.AddColumn(L"name", SQL_CHAR, 128);
	results.AddColumn(L"usertype", SQL_INTEGER);
	results.AddColumn(L"id", SQL_INTEGER);
    conn.Execute(L"SELECT TOP 10 name, usertype, id " \
		L"FROM [master].dbo.syscolumns ORDER BY [name] DESC", results);

	SQLSMALLINT columns = results.GetNumResultCols();
    std::wcout << std::endl << L"Columns: " << columns;
	CPPUNIT_ASSERT(columns == 3);
	
	SQLINTEGER rows = results.GetSQLRowCount();
    std::wcout << std::endl << L"Rows: " << rows;
	CPPUNIT_ASSERT(rows == -1); // the number of affected rows is not available

    int count = 0;
    bool has_usertype = false;
    bool has_name = false;
	while(results.Fetch())
	{
        std::string r_name = results[L"name"]->GetStringValue();
        int r_id = results[L"id"]->GetIntValue();
        CPPUNIT_ASSERT(r_id != 0);
        int r_usertype = results[L"usertype"]->GetIntValue();
        has_usertype = has_usertype || r_usertype > 0;
        has_name = has_name || r_name.length() > 0;
        std::cout << std::endl << " " << r_id << ": " << r_name << " (" << r_usertype << ")";
        count ++;
	}
    CPPUNIT_ASSERT(count == 10);
    CPPUNIT_ASSERT(has_name);
    CPPUNIT_ASSERT(has_usertype);
}

void ODBCConnectionUnitTests::testExecuteAutoBind()
{
	MSSQLConnectionInfo info(L"localhost");

    ODBCConnection conn;
    conn.Connect(info);

	ODBCRowSet results;
    conn.Execute(L"SELECT TOP 10 name, usertype, id " \
		L"FROM [master].dbo.syscolumns ORDER BY [name] DESC", results);

	SQLSMALLINT columns = results.GetNumResultCols();
    std::wcout << std::endl << L"Columns: " << columns;
	CPPUNIT_ASSERT(columns == 3);
	
	SQLINTEGER rows = results.GetSQLRowCount();
    std::wcout << std::endl << L"Rows: " << rows;
	CPPUNIT_ASSERT(rows == -1); // the number of affected rows is not available

    int count = 0;
    bool has_usertype = false;
    bool has_name = false;
	while(results.Fetch())
	{
        std::wstring r_name = results[L"name"]->GetWStringValue();
        int r_id = results[L"id"]->GetIntValue();
        CPPUNIT_ASSERT(r_id != 0);
        int r_usertype = results[L"usertype"]->GetIntValue();
        has_usertype = has_usertype || r_usertype > 0;
        has_name = has_name || r_name.length() > 0;
        std::wcout << std::endl << L" " << r_id << L": " << r_name << L" (" << r_usertype << L")";
        count ++;
	}
    CPPUNIT_ASSERT(count == 10);
    CPPUNIT_ASSERT(has_name);
    CPPUNIT_ASSERT(has_usertype);
}

void ODBCConnectionUnitTests::testExecuteStoredProcedure_sp_helprotect()
{
	MSSQLConnectionInfo info(L"localhost");

    ODBCConnection conn;
    conn.Connect(info);

	ODBCRowSet results;
	results.AddColumn(L"owner", SQL_CHAR, 128);
	results.AddColumn(L"Object", SQL_CHAR, 128);
	results.AddColumn(L"Grantee", SQL_CHAR, 128);
	results.AddColumn(L"Grantor", SQL_CHAR, 128);
	results.AddColumn(L"ProtectType", SQL_CHAR, 128);
	results.AddColumn(L"Action", SQL_CHAR, 128);
	results.AddColumn(L"Column", SQL_CHAR, 128);
    conn.Execute(L"EXECUTE [master].dbo.sp_helprotect", results);

    int count = 0;
	bool finished = false;
	while(results.Fetch())
	{
        std::string r_object = results[L"Object"]->GetStringValue();
        std::cout << std::endl << " " << r_object;
		if (count++ == 10) break;
	}
}

void ODBCConnectionUnitTests::testExecuteStoredProcedure_sp_helpuser()
{
	MSSQLConnectionInfo info(L"localhost");

    ODBCConnection conn;
    conn.Connect(info);

	ODBCRowSet results;
	results.AddColumn(L"UserName", SQL_WCHAR, 128);
	results.AddColumn(L"GroupName", SQL_WCHAR, 128);
	results.AddColumn(L"LoginName", SQL_WCHAR, 128);
	results.AddColumn(L"DefDbName", SQL_WCHAR, 128);
    results.AddColumn(L"DefSchemaName", SQL_CHAR, 128);
	results.AddColumn(L"UserID", SQL_SMALLINT);
	results.AddColumn(L"SID", SQL_CHAR, 0);
    conn.Execute(L"EXECUTE [master].dbo.sp_helpuser", results);

	while(results.Fetch())
	{
        std::wcout << std::endl << L" " << results[L"UserName"]->GetWStringValue() 
			<< " (" << results[L"GroupName"]->GetWStringValue() << L")";
	}
}

void ODBCConnectionUnitTests::testConnect_ODBC_CONNECTION()
{
    typedef struct
    {
        ODBCConnectionProtocol protocol;
        LPCSTR transport;
    } ProtocolConnectionData;

    ProtocolConnectionData testdata[] = 
    {
        { ODBC_CONNECTION_TCPIP, "TCP" },
        { ODBC_CONNECTION_NAMEDPIPES, "Named pipe" },
        // { ODBC_CONNECTION_RPC, "" },
        // { ODBC_CONNECTION_LPC, "" },
        // { ODBC_CONNECTION_SPX, "" },
        // { ODBC_CONNECTION_VINES, "" },
        // { ODBC_CONNECTION_ADSP, "" }
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        MSSQLConnectionInfo conn_info(L"localhost"); // ODBCAliasConnectionInfo conn_info("localhost");
        conn_info.SetProtocol(testdata[i].protocol);
        ODBCConnection conn;
        std::wstring connection_string = conn_info.GetConnectionString();
        std::wcout << std::endl << L"Connection string: " << connection_string;
        conn.Connect(conn_info);
        std::string net_transport = conn.GetString(L"SELECT net_transport FROM sys.dm_exec_connections WHERE session_id = @@SPID;");
        std::cout << std::endl << "Transport: " << net_transport;
        CPPUNIT_ASSERT(net_transport == testdata[i].transport);
    }
}

void ODBCConnectionUnitTests::testExecuteWithParametersAndResults_sp_helpuser()
{
	MSSQLConnectionInfo info(L"localhost");

    ODBCConnection conn;
    conn.Connect(info);

	ODBCRowSet results;
	results.AddColumn(L"UserName", SQL_WCHAR, 128);
	results.AddColumn(L"GroupName", SQL_WCHAR, 128);
	results.AddColumn(L"LoginName", SQL_WCHAR, 128);
	results.AddColumn(L"DefDbName", SQL_WCHAR, 128);
    results.AddColumn(L"DefSchemaName", SQL_CHAR, 128);
	results.AddColumn(L"UserID", SQL_SMALLINT);
	results.AddColumn(L"SID", SQL_CHAR, 0);

	ODBCParameters parameters;
	parameters.AddParameter(ODBCParameter(L"name_in_db", std::wstring(L"dbo"), SQL_PARAM_INPUT));

    conn.Execute(L"EXECUTE [master].dbo.sp_helpuser @name_in_db = ?", parameters, results);

	// there should be only one, and it's dbo
	CPPUNIT_ASSERT(results.Fetch());
    std::wcout << std::endl << L" " << results[L"UserName"]->GetWStringValue() << L" (" << 
        results[L"GroupName"]->GetWStringValue() << L")";
	CPPUNIT_ASSERT(results[L"UserName"]->GetWStringValue() == L"dbo");
    // no more results
	CPPUNIT_ASSERT(! results.Fetch());
}

void ODBCConnectionUnitTests::testGetDiagFields()
{
	MSSQLConnectionInfo info(L"localhost");

    ODBCConnection conn;
    conn.Connect(info);

	ODBCHandle results;
    conn.Execute(L"PRINT 'hello world'", results);
	std::vector<std::wstring> messages = results.GetDiagFields(SQL_DIAG_MESSAGE_TEXT);
	CPPUNIT_ASSERT(messages.size() == 1);
	std::wcout << messages[0];
	CPPUNIT_ASSERT(AppSecInc::StringUtils::endsWith(messages[0], L"hello world"));
}

void ODBCConnectionUnitTests::testGetDiagMessages()
{
	MSSQLConnectionInfo info(L"localhost");

    ODBCConnection conn;
    conn.Connect(info);

	ODBCHandle results;
    conn.Execute(L"PRINT 'hello world'", results);
	std::vector<ODBCDiagnosticsMessage> messages = results.GetDiagMessages();
	CPPUNIT_ASSERT(messages.size() == 1);
	std::wcout << std::endl << messages[0].vendor 
		<< L", " << messages[0].component 
		<< L", " << messages[0].datasource 
		<< L", " << messages[0].text;
	CPPUNIT_ASSERT(messages[0].component.length() > 0);
	CPPUNIT_ASSERT(messages[0].datasource.length() > 0);
	CPPUNIT_ASSERT(messages[0].vendor.length() > 0);
	CPPUNIT_ASSERT(messages[0].text == L"hello world");
}

void ODBCConnectionUnitTests::testExecuteSelectAllSupportedTypes()
{
    std::wstring databasename = AppSecInc::Com::GenerateGUIDStringW();
    AppSecInc::StringUtils::lrtrim(databasename, L"{}");
    std::wcout << std::endl << L"Creating: " << databasename;
    MSSQLConnectionInfo connection_info;
    connection_info.SetIPAddress(L"localhost");
    MSSQLDatabase database(connection_info);   
    database.SetName(databasename);
    database.Connect();
    database.Create();
    ODBCConnection conn;
    conn.Connect(connection_info);
    
    // create a table representing all supported types
    conn.Execute(
        L"CREATE TABLE [" + databasename + L"].[dbo].[TestTable](" \
	     L"[bigint_value] [bigint] NULL," 
	     L"[binary_value] [binary] (512) NULL," 
	     L"[bit_value] [bit] NULL," 
	     L"[char_value] [char] NULL," 
	     L"[datetime_value] [datetime] NULL," 
	     L"[decimal_value] [decimal] (18, 0) NULL," 
	     // L"[float_value] [float] NULL," 
	     L"[image_value] [image] NULL," 
	     L"[int_value] [int] NULL," 
	     L"[money_value] [money] NULL," 
	     L"[nchar_value] [nchar] NULL," 
	     L"[ntext_value] [ntext] NULL," 
	     // L"[numeric_value] [numeric] (18, 0) NULL," 
	     L"[nvarchar_value] [nvarchar] (512) NULL," 
	     L"[nvarchar_max_value] [nvarchar] (MAX) NULL," 
	     L"[real_value] [real] NULL," 
	     L"[smalldatetime_value] [smalldatetime] NULL," 
	     L"[smallint_value] [smallint] NULL," 
	     L"[smallmoney_value] [smallmoney] NULL," 
	     // L"[sql_variant_value] [sql_variant] NULL," 
	     L"[text_value] [text] NULL," 
	     // L"[timestamp_value] [timestamp] NULL," 
	     L"[tinyint_value] [tinyint] NULL," 
	     // L"[uniqueidentifier_value] [uniqueidentifier] NULL," 
	     L"[varbinary_value] [varbinary] (512) NULL," 
	     L"[varbinary_max_value] [varbinary] (MAX) NULL," 
	     L"[varchar_value] [varchar] (512) NULL," 
	     L"[varchar_max_value] [varchar] (MAX) NULL," 
	     L"[xml_value] [xml] NULL," 
        L")");
    
    LONGLONG bigint_value = 0;
    std::wstring binary_value = L"0xab";
    bool bit_value = false;
    char char_value = 'a';
    std::wstring datetime_value = L"2018-02-03 12:34:56.123";
    int decimal_value = 0;
    // float float_value = (float) 1.1;
    std::wstring image_value = L""; // \todo
    int int_value = 1;
    int money_value = 5;
    wchar_t nchar_value = L'a';
    std::wstring ntext_value = L"very long text"; // \todo
    // int numeric_value = 3;
    std::wstring nvarchar_value = L"nvarchar text";
    std::wstring nvarchar_max_value = L"nvarchar max text";
    float real_value = (float) 3.4;
    std::wstring smalldatetime_value = L"2008-01-01 13:11:00.000";
    int smallint_value = 4;
    int smallmoney_value = 6;
    std::wstring text_value = L"text value";
    // std::wstring timestamp_value = L""; // \todo: default value for timestamp
    int tinyint_value = 1;
    // std::wstring uniqueidentifier_value = AppSecInc::Com::GenerateGUIDStringW();
    std::wstring varbinary_value = L"0xcd";
    std::wstring varbinary_max_value = L"0xef";
    std::string varchar_value = "varchar value";
    std::string varchar_max_value = "varchar max value";
    std::wstring xml_value = L"<xml />";

    try
    {
        conn.Execute(
            L"INSERT INTO [" + databasename + L"].[dbo].[TestTable] VALUES (" \
	         + L"'" + AppSecInc::StringUtils::toWString(bigint_value) + L"'"
	         + L", " + binary_value
	         + L", " + AppSecInc::StringUtils::toWString(bit_value)
	         + L", '" + AppSecInc::StringUtils::toWString(char_value) + L"'"
	         + L", '" + datetime_value + L"'"
	         + L", " + AppSecInc::StringUtils::toWString(decimal_value)
	         // + L", " + AppSecInc::StringUtils::toWString(float_value) 
	         + L", '" + image_value + L"'"
	         + L", " + AppSecInc::StringUtils::toWString(int_value)
	         + L", " + AppSecInc::StringUtils::toWString(money_value)
	         + L", '" + AppSecInc::StringUtils::toWString(nchar_value) + L"'"
	         + L", '" + ntext_value + L"'"
	         // + L", " + AppSecInc::StringUtils::toWString(numeric_value)
	         + L", '" + nvarchar_value + L"'"
	         + L", '" + nvarchar_max_value + L"'"
	         + L", '" + AppSecInc::StringUtils::toWString(real_value) + L"'"
	         + L", '" + smalldatetime_value + L"'"
	         + L", '" + AppSecInc::StringUtils::toWString(smallint_value) + L"'"
             + L", " + AppSecInc::StringUtils::toWString(smallmoney_value)
	         // + L", '" + AppSecInc::StringUtils::toWString(sql_variant_value) + L"'"
	         + L", '" + text_value + L"'"
	         // + L", '" + timestamp_value + L"'"
	         + L", '" + AppSecInc::StringUtils::toWString(tinyint_value) + L"'"
	         // + L", '" + uniqueidentifier_value + L"'"
	         + L", " + varbinary_value
	         + L", " + varbinary_max_value
             + L", '" + AppSecInc::StringUtils::mb2wc(varchar_value) + L"'"
	         + L", '" + AppSecInc::StringUtils::mb2wc(varchar_max_value) + L"'"
	         + L", '" + xml_value + L"'"
            L")");

	    ODBCRowSet results;
        conn.Execute(L"SELECT * FROM [" + databasename + L"].[dbo].[TestTable]", results);
        CPPUNIT_ASSERT(results.Fetch());
        std::wcout << std::endl << L"Columns: " << results.GetColumnCount();

	    CPPUNIT_ASSERT(results[L"bigint_value"]->GetLongLongValue() == bigint_value);
	    CPPUNIT_ASSERT(L"0x" + results[L"binary_value"]->ToWString() == binary_value);
	    CPPUNIT_ASSERT(results[L"bit_value"]->GetBoolValue() == bit_value);
	    CPPUNIT_ASSERT(results[L"char_value"]->GetCharValue() == char_value);
        CPPUNIT_ASSERT(results[L"datetime_value"]->ToWString() == datetime_value);
	    CPPUNIT_ASSERT(results[L"decimal_value"]->GetFloatValue() == decimal_value);
	    // CPPUNIT_ASSERT(results[L"float_value"]-> == float_value);
	    // CPPUNIT_ASSERT(results[L"image_value"]-> == image_value);
	    CPPUNIT_ASSERT(results[L"int_value"]->GetIntValue() == int_value);
	    CPPUNIT_ASSERT(results[L"money_value"]->GetIntValue() == money_value);
	    CPPUNIT_ASSERT(results[L"nchar_value"]->GetCharValue() == nchar_value); 
	    CPPUNIT_ASSERT(results[L"ntext_value"]->GetWStringValue() == ntext_value); 
	    // CPPUNIT_ASSERT(results[L"numeric_value"]-> == numeric_value);
	    CPPUNIT_ASSERT(results[L"nvarchar_value"]->GetWStringValue() == nvarchar_value); 
	    CPPUNIT_ASSERT(results[L"nvarchar_max_value"]->GetWStringValue() == nvarchar_max_value); 
        CPPUNIT_ASSERT(results[L"real_value"]->GetFloatValue() == real_value);
        CPPUNIT_ASSERT(results[L"smalldatetime_value"]->ToWString() == smalldatetime_value);
        CPPUNIT_ASSERT(results[L"smallint_value"]->GetIntValue() == smallint_value);
        CPPUNIT_ASSERT(results[L"smallmoney_value"]->GetIntValue() == smallmoney_value);
        // CPPUNIT_ASSERT(results[L"sql_variant_value"]-> == sql_variant_value);
        CPPUNIT_ASSERT(results[L"text_value"]->ToWString() == text_value);
        // CPPUNIT_ASSERT(results["timestamp_value"]-> == timestamp_value);
        CPPUNIT_ASSERT(results[L"tinyint_value"]->GetShortValue() == tinyint_value);
        // CPPUNIT_ASSERT(results["uniqueidentifier_value"]-> == uniqueidentifier_value);
	    CPPUNIT_ASSERT(L"0x" + results[L"varbinary_value"]->ToWString() == varbinary_value);
	    CPPUNIT_ASSERT(L"0x" + results[L"varbinary_max_value"]->ToWString() == varbinary_max_value);
        CPPUNIT_ASSERT(results[L"varchar_value"]->GetStringValue() == varchar_value);
        CPPUNIT_ASSERT(results[L"varchar_max_value"]->GetStringValue() == varchar_max_value);
        // CPPUNIT_ASSERT(results[L"xml_value"]->GetWStringValue() == xml_value);
    }
    catch(std::exception&)
    {
        // drop the database
        std::wcout << std::endl << L"Dropping: " << databasename;
        database.Drop();
        throw;
    }

    // drop the database
    std::wcout << std::endl << L"Dropping: " << databasename;
    database.Drop();
}

void ODBCConnectionUnitTests::testSelectString()
{
    MSSQLConnectionInfo connection_info;
    connection_info.SetIPAddress(L"localhost");
    ODBCConnection conn;
    conn.Connect(connection_info);
    int cut = 256;
    // NULL string
    ODBCRowSet results;
    conn.Execute(L"SELECT NULL", results);
    CPPUNIT_ASSERT(results.Fetch());
    CPPUNIT_ASSERT(1 == results.GetColumnCount());
    CPPUNIT_ASSERT(0 == results[0]->GetDataSize());
    // ANSI string
    for (int i = 1; i <= 8192; i+=cut)
    {
        std::wstring random_string;
        for(int c = 0; c < i; c++) random_string.append(AppSecInc::StringUtils::toWString(c % 10));
        ODBCRowSet results;
        conn.Execute(L"SELECT '" + random_string + L"'", results);
        CPPUNIT_ASSERT(results.Fetch());
        CPPUNIT_ASSERT(1 == results.GetColumnCount());
        std::wcout << ".";
        CPPUNIT_ASSERT(results[0]->GetDataSize() == i * sizeof(char));
        CPPUNIT_ASSERT(results[0]->GetStringValue().length() == i);
        CPPUNIT_ASSERT(strlen(results[0]->GetStringValue().c_str()) == i);
        CPPUNIT_ASSERT(results[0]->ToWString() == random_string);
    }
    // Unicode string
    for (int i = 1; i <= 8192; i+=cut)
    {
        std::wstring random_string;
        for(int c = 0; c < i; c++) random_string.append(AppSecInc::StringUtils::toWString(c % 10));
        ODBCRowSet results;
        conn.Execute(L"SELECT N'" + random_string + L"'", results);
        CPPUNIT_ASSERT(results.Fetch());
        CPPUNIT_ASSERT(1 == results.GetColumnCount());
        std::wcout << ".";
        CPPUNIT_ASSERT(results[0]->GetDataSize() == i * sizeof(wchar_t));
        CPPUNIT_ASSERT(results[0]->GetWStringValue().length() == i);
        CPPUNIT_ASSERT(wcslen(results[0]->GetWStringValue().c_str()) == i);
        CPPUNIT_ASSERT(results[0]->ToWString() == random_string);
    }
}

void ODBCConnectionUnitTests::testInsertLargePayload_MSSQL()
{
    std::wstring databasename = AppSecInc::Com::GenerateGUIDStringW();
    AppSecInc::StringUtils::lrtrim(databasename, L"{}");
    std::wcout << std::endl << L"Creating: " << databasename;
    MSSQLConnectionInfo connection_info;
    connection_info.SetIPAddress(L"localhost");
    MSSQLDatabase database(connection_info);   
    database.SetName(databasename);
    database.Connect();
    database.Create();
    ODBCConnection conn;
    conn.Connect(connection_info);

	try
	{
		conn.Execute(
			L"CREATE TABLE [" + databasename + L"].[dbo].[TestTable](" \
			 L"[ntext_value] [ntext] NULL" 
			L")");

		// generate and insert a large payload
		std::wstring largepayload;
		int cap = 1024 * 1024;
		largepayload.reserve(cap);
		for (int i = 0; i < cap; i++)
		{
			largepayload.append(AppSecInc::StringUtils::toWString(i % 10));
		}
		std::wcout << std::endl << "Payload size: " << AppSecInc::File::SizeToStringW(largepayload.size());

		ODBCParameters parameters;
		parameters.AddParameter(ODBCParameter(L"value", largepayload, SQL_PARAM_INPUT));
		conn.Execute(L"INSERT INTO [" + databasename + L"].[dbo].[TestTable] VALUES ( ? )", parameters);
    
		ODBCRowSet results;
		conn.Execute(L"SELECT * FROM [" + databasename + L"].[dbo].[TestTable]", results);
		CPPUNIT_ASSERT(results.Fetch());
		std::wcout << std::endl << L"Columns: " << results.GetColumnCount();
		CPPUNIT_ASSERT(results[0]->GetWStringValue() == largepayload);
		CPPUNIT_ASSERT(! results.Fetch());
    }
    catch(std::exception&)
    {
        // drop the database
        std::wcout << std::endl << L"Dropping: " << databasename;
        database.Drop();
        throw;
    }

    // drop the database
    std::wcout << std::endl << L"Dropping: " << databasename;
    database.Drop();
}

void ODBCConnectionUnitTests::testInsertLargePayload_Access()
{
    std::wstring databasename = AppSecInc::Com::GenerateGUIDStringW();
    AppSecInc::StringUtils::lrtrim(databasename, L"{}");
	std::wstring dbq = AppSecInc::File::DirectoryCombine(AppSecInc::File::GetTemporaryDirectoryW(), databasename + L".mdb");
    std::wcout << std::endl << L"Creating: " << dbq;

    AccessConnectionInfo connection_info;
    connection_info.SetDBQ(dbq);
    AccessDatabase database(connection_info);   
    database.SetDBQ(dbq);
    database.Create();
    ODBCConnection conn;
    conn.Connect(connection_info);

	try
	{
		conn.Execute(
			L"CREATE TABLE TestTable (" \
			 L"text_value MEMO" 
			L")");

		// generate and insert a large payload

		std::wstring largepayload;
		int cap = 1024 * 1024;
		largepayload.reserve(cap);
		for (int i = 0; i < cap; i++)
		{
			largepayload.append(AppSecInc::StringUtils::toWString(i % 10));
		}
		std::wcout << std::endl << "Payload size: " << AppSecInc::File::SizeToStringW(largepayload.size());

		ODBCParameters parameters;
		parameters.AddParameter(ODBCParameter(L"", largepayload, SQL_PARAM_INPUT));
		conn.Execute(L"INSERT INTO TestTable VALUES ( ? )", parameters);
    
		ODBCRowSet results;
		conn.Execute(L"SELECT * FROM TestTable", results);
		CPPUNIT_ASSERT(results.Fetch());
		std::wcout << std::endl << L"Columns: " << results.GetColumnCount();
		CPPUNIT_ASSERT(results[0]->GetWStringValue() == largepayload);
		CPPUNIT_ASSERT(! results.Fetch());
    }
    catch(std::exception&)
    {
        // drop the database
        std::wcout << std::endl << L"Dropping: " << databasename;
        conn.Disconnect();
		database.Drop();
        throw;
    }

    // drop the database
    std::wcout << std::endl << L"Dropping: " << databasename;
    conn.Disconnect();
	database.Drop();
}

void ODBCConnectionUnitTests::testInsertXml()
{
    std::wstring databasename = AppSecInc::Com::GenerateGUIDStringW();
    AppSecInc::StringUtils::lrtrim(databasename, L"{}");
    std::wcout << std::endl << L"Creating: " << databasename;
    MSSQLConnectionInfo connection_info;
    connection_info.SetIPAddress(L"localhost");
    MSSQLDatabase database(connection_info);   
    database.SetName(databasename);
    database.Connect();
    database.Create();
    ODBCConnection conn;
    conn.Connect(connection_info);
    
    // create a table representing all supported types
    conn.Execute(
        L"CREATE TABLE [" + databasename + L"].[dbo].[TestTable](" \
	     L"[bigint_value] [bigint] NULL," 
	     L"[binary_value] [binary] (512) NULL," 
	     L"[bit_value] [bit] NULL," 
	     L"[char_value] [char] NULL," 
	     L"[datetime_value] [datetime] NULL," 
	     L"[decimal_value] [decimal] (18, 0) NULL," 
	     // L"[float_value] [float] NULL," 
	     L"[image_value] [image] NULL," 
	     L"[int_value] [int] NULL," 
	     L"[money_value] [money] NULL," 
	     L"[nchar_value] [nchar] NULL," 
	     L"[ntext_value] [ntext] NULL," 
	     // L"[numeric_value] [numeric] (18, 0) NULL," 
	     L"[nvarchar_value] [nvarchar] (512) NULL," 
	     L"[nvarchar_max_value] [nvarchar] (MAX) NULL," 
	     L"[real_value] [real] NULL," 
	     L"[smalldatetime_value] [smalldatetime] NULL," 
	     L"[smallint_value] [smallint] NULL," 
	     L"[smallmoney_value] [smallmoney] NULL," 
	     // L"[sql_variant_value] [sql_variant] NULL," 
	     L"[text_value] [text] NULL," 
	     // L"[timestamp_value] [timestamp] NULL," 
	     L"[tinyint_value] [tinyint] NULL," 
	     // L"[uniqueidentifier_value] [uniqueidentifier] NULL," 
	     L"[varbinary_value] [varbinary] (512) NULL," 
	     L"[varbinary_max_value] [varbinary] (MAX) NULL," 
	     L"[varchar_value] [varchar] (512) NULL," 
	     L"[varchar_max_value] [varchar] (MAX) NULL," 
	     L"[xml_value] [xml] NULL," 
        L")");
    
    LONGLONG bigint_value = 0;
    std::wstring binary_value = L"0xab";
    bool bit_value = false;
    char char_value = 'a';
    std::wstring datetime_value = L"2018-02-03 12:34:56.123";
    int decimal_value = 0;
    // float float_value = (float) 1.1;
    std::wstring image_value = L""; // \todo
    int int_value = 1;
    int money_value = 5;
    wchar_t nchar_value = L'a';
    std::wstring ntext_value = L"very long text"; // \todo
    // int numeric_value = 3;
    std::wstring nvarchar_value = L"nvarchar text";
    std::wstring nvarchar_max_value = L"nvarchar max text";
    float real_value = (float) 3.4;
    std::wstring smalldatetime_value = L"2008-01-01 13:11:00.000";
    int smallint_value = 4;
    int smallmoney_value = 6;
    std::wstring text_value = L"text value";
    // std::wstring timestamp_value = L""; // \todo: default value for timestamp
    int tinyint_value = 1;
    // std::wstring uniqueidentifier_value = AppSecInc::Com::GenerateGUIDStringW();
    std::wstring varbinary_value = L"0xcd";
    std::wstring varbinary_max_value = L"0xef";
    std::string varchar_value = "varchar value";
    std::string varchar_max_value = "varchar max value";
    std::wstring xml_value = L"<xml />";

    try
    {
        std::wstring table_name = L"[" + databasename + L"].[dbo].[TestTable]";
        AppSecInc::Xml::XmlDocument data;
        data.LoadXml(L"<Data><DataSet><RowSet /></DataSet></Data>");
        // set the table name
        MSXML2::IXMLDOMNodePtr table = data.SelectNode(L"/Data/DataSet/RowSet");
        data.SetAttribute(L"table", table_name, table);
        // create a row of data
        MSXML2::IXMLDOMNodePtr row = data.AppendChild(L"Row", table);

#define testInsertXml_APPEND(name, value, type) \
        { \
            MSXML2::IXMLDOMNodePtr ptr = data.AppendChild(name, row); \
            ptr->text = _bstr_t(value.c_str()); \
            data.SetAttribute(L"type", type, ptr); \
        }
 
        // testInsertXml_APPEND(L"bigint_value", AppSecInc::StringUtils::toWString(bigint_value), L"bigint");
        // testInsertXml_APPEND(L"binary_value", binary_value, L"binary");
        testInsertXml_APPEND(L"bit_value", AppSecInc::StringUtils::toWString(bit_value), L"bit");
        testInsertXml_APPEND(L"char_value", AppSecInc::StringUtils::toWString(char_value), L"char");
        // testInsertXml_APPEND(L"datetime_value", datetime_value, L"datetime");
        testInsertXml_APPEND(L"decimal_value", AppSecInc::StringUtils::toWString(decimal_value), L"decimal");
        // testInsertXml_APPEND(L"float_value", AppSecInc::StringUtils::toWString(float_value), L"float");
        // testInsertXml_APPEND(L"image_value", image_value, L"image");
        testInsertXml_APPEND(L"int_value", AppSecInc::StringUtils::toWString(int_value), L"integer");
        // testInsertXml_APPEND(L"money_value", AppSecInc::StringUtils::toWString(money_value), L"money");
        testInsertXml_APPEND(L"nchar_value", AppSecInc::StringUtils::toWString(nchar_value), L"nchar");
        testInsertXml_APPEND(L"ntext_value", ntext_value, L"ntext");
        // testInsertXml_APPEND(L"numeric_value", AppSecInc::StringUtils::toWString(numeric_value), L"numeric");
        testInsertXml_APPEND(L"nvarchar_value", nvarchar_value, L"nvarchar");
        testInsertXml_APPEND(L"nvarchar_max_value", nvarchar_max_value, L"nvarchar");
        // testInsertXml_APPEND(L"real_value", AppSecInc::StringUtils::toWString(real_value), L"real");
        // testInsertXml_APPEND(L"smalldatetime_value", smalldatetime_value, L"smalldatetime");
        testInsertXml_APPEND(L"smallint_value", AppSecInc::StringUtils::toWString(smallint_value), L"smallint");
        // testInsertXml_APPEND(L"smallmoney_value", AppSecInc::StringUtils::toWString(smallmoney_value), L"smallmoney");
        // testInsertXml_APPEND(L"sql_variant_value", AppSecInc::StringUtils::toWString(sql_variant_value), L"sqlvariant");
        testInsertXml_APPEND(L"text_value", text_value, L"text");
        // testInsertXml_APPEND(L"timestamp_value", timestamp_value, L"timestamp");
        testInsertXml_APPEND(L"tinyint_value", AppSecInc::StringUtils::toWString(tinyint_value), L"tinyint");
        // testInsertXml_APPEND(L"uniqueidentifier_value", uniqueidentifier_value, L"uniqueidentifier");
        // testInsertXml_APPEND(L"varbinary_value", varbinary_value, L"varbinary");
        // testInsertXml_APPEND(L"varbinary_max_value", varbinary_max_value, L"varbinary");
        testInsertXml_APPEND(L"varchar_value", varchar_value, L"varchar");
        testInsertXml_APPEND(L"varchar_max_value", varchar_max_value, L"varchar");
        // testInsertXml_APPEND(L"xml_value", xml_value, L"xml");
    
        conn.InsertXml(data);

	    ODBCRowSet results;
        conn.Execute(L"SELECT * FROM " + table_name, results);
        CPPUNIT_ASSERT(results.Fetch());
        std::wcout << std::endl << L"Columns: " << results.GetColumnCount();

	    CPPUNIT_ASSERT(results[L"char_value"]->GetCharValue() == char_value);
	    // CPPUNIT_ASSERT(results[L"bigint_value"]->GetLongLongValue() == bigint_value);
	    // CPPUNIT_ASSERT(L"0x" + results[L"binary_value"]->ToWString() == binary_value);
	    CPPUNIT_ASSERT(results[L"bit_value"]->GetBoolValue() == bit_value);
        // CPPUNIT_ASSERT(results[L"datetime_value"]->ToWString() == datetime_value);
	    CPPUNIT_ASSERT(results[L"decimal_value"]->GetFloatValue() == decimal_value);
	    // CPPUNIT_ASSERT(results[L"float_value"]->GetFloatValue() == float_value);
	    // CPPUNIT_ASSERT(results[L"image_value"]->GetImageValue() == image_value);
	    CPPUNIT_ASSERT(results[L"int_value"]->GetIntValue() == int_value);
	    // CPPUNIT_ASSERT(results[L"money_value"]->GetIntValue() == money_value);
	    CPPUNIT_ASSERT(results[L"nchar_value"]->GetCharValue() == nchar_value); 
	    CPPUNIT_ASSERT(results[L"ntext_value"]->GetWStringValue() == ntext_value); 
	    // CPPUNIT_ASSERT(results[L"numeric_value"]->GetIntValue() == numeric_value);
	    CPPUNIT_ASSERT(results[L"nvarchar_value"]->GetWStringValue() == nvarchar_value); 
	    CPPUNIT_ASSERT(results[L"nvarchar_max_value"]->GetWStringValue() == nvarchar_max_value); 
        // CPPUNIT_ASSERT(results[L"real_value"]->GetFloatValue() == real_value);
        // CPPUNIT_ASSERT(results[L"smalldatetime_value"]->ToWString() == smalldatetime_value);
        CPPUNIT_ASSERT(results[L"smallint_value"]->GetIntValue() == smallint_value);
        // CPPUNIT_ASSERT(results[L"smallmoney_value"]->GetIntValue() == smallmoney_value);
        // CPPUNIT_ASSERT(results[L"sql_variant_value"]-> == sql_variant_value);
        CPPUNIT_ASSERT(results[L"text_value"]->ToWString() == text_value);
        // CPPUNIT_ASSERT(results[L"timestamp_value"]->GetTimestampValue() == timestamp_value);
        CPPUNIT_ASSERT(results[L"tinyint_value"]->GetShortValue() == tinyint_value);
        // CPPUNIT_ASSERT(results[L"uniqueidentifier_value"]-> == uniqueidentifier_value);
	    // CPPUNIT_ASSERT(L"0x" + results[L"varbinary_value"]->ToWString() == varbinary_value);
	    // CPPUNIT_ASSERT(L"0x" + results[L"varbinary_max_value"]->ToWString() == varbinary_max_value);
        CPPUNIT_ASSERT(results[L"varchar_value"]->GetStringValue() == varchar_value);
        CPPUNIT_ASSERT(results[L"varchar_max_value"]->GetStringValue() == varchar_max_value);
        // CPPUNIT_ASSERT(results[L"xml_value"]->GetWStringValue() == xml_value);
    }
    catch(std::exception&)
    {
        // drop the database
        std::wcout << std::endl << L"Dropping: " << databasename;
        database.Drop();
        throw;
    }

    // drop the database
    std::wcout << std::endl << L"Dropping: " << databasename;
    database.Drop();
}


void ODBCConnectionUnitTests::testSelectUTF8String()
{
	MSSQLConnectionInfo info(L"localhost");
	ODBCConnection conn;
    conn.Connect(info);
	const unsigned char s3[] = { 0x41, 0xc3, 0xaa, 0xc3, 0xb1, 0xc3, 0xbc, 0x43, 0x00 };
	std::wstring wctext = AppSecInc::StringUtils::utf82wc(reinterpret_cast<const char *>(s3));
    std::wstring result = conn.GetWString(L"SELECT '" + wctext + L"'");
	CPPUNIT_ASSERT(wctext == result);
	CPPUNIT_ASSERT(AppSecInc::StringUtils::wc2utf8(wctext) == reinterpret_cast<const char *>(s3));
}

void ODBCConnectionUnitTests::testExecuteStoredProcedure_xp_msver() 
{
	MSSQLConnectionInfo info(L"localhost");
    info.SetTrustedAuth(true);
	ODBCConnection conn;
	conn.Connect(info);
	
	std::wstring statement = 
		L"DECLARE @toexec varchar(max)\r\n" \
		L"DECLARE csr CURSOR LOCAL static FOR\r\n" \
		L"SELECT 'xp_msver'\r\n" \
		L"OPEN csr\r\n" \
		L"FETCH csr into @toexec\r\n" \
		L"WHILE @@FETCH_STATUS = 0\r\n" \
		L"BEGIN\r\n" \
		L"EXECUTE @toexec\r\n" \
		L"FETCH NEXT FROM csr into @toexec\r\n" \
		L"END\r\n" \
		L"CLOSE csr\r\n" \
		L"DEALLOCATE csr";
 	
 	ODBCRowSet results;
	conn.Execute(statement, results);
	SQLSMALLINT columns = results.GetNumResultCols();
	CPPUNIT_ASSERT(4 == columns);

    int count = 0;
	while(results.Fetch())
	{
        std::wstring name = results[L"Name"]->GetWStringValue();
		std::wstring value = results[L"Character_Value"]->GetBufferSize()
			? results[L"Character_Value"]->GetWStringValue()
			: L"NULL";
        std::wcout << std::endl << L" " << name << L": " << value;
	}
}