#include "StdAfxUnitTests.h"
#include "MSSQLConnectionInfoUnitTests.h"

using namespace AppSecInc::Databases::ODBC;
using namespace AppSecInc::Databases::MSSQL;
using namespace AppSecInc::UnitTests::Databases::MSSQL;

CPPUNIT_TEST_SUITE_REGISTRATION(MSSQLConnectionInfoUnitTests);

void MSSQLConnectionInfoUnitTests::testConstructorDestructor()
{
	{
		MSSQLConnectionInfo info;
	}

	{
		MSSQLConnectionInfo * p = new MSSQLConnectionInfo();
		delete p;
	}
}

void MSSQLConnectionInfoUnitTests::testCopyAndAssignment()
{
	// default constructor properties
	MSSQLConnectionInfo info1;
	CPPUNIT_ASSERT(info1.GetTrustedAuth() == TRUE);
	CPPUNIT_ASSERT(info1.GetUsername().length() == 0);
	CPPUNIT_ASSERT(info1.GetPassword().length() == 0);
	CPPUNIT_ASSERT(info1.GetDatabase().length() == 0);
	CPPUNIT_ASSERT(info1.GetIPAddress() == MSSQLConnectionInfo::DEFAULT_IPADDRESS);
	CPPUNIT_ASSERT(info1.GetPort() == MSSQLConnectionInfo::DEFAULT_PORT);
	// generate an ip/port
	std::wstring ip = L"127.0.0.1";
	srand(::GetTickCount());
	const int port = rand();
    std::wcout << std::endl << L"Ip: " << ip << L":" << port;
	// constructor with ip/port
	MSSQLConnectionInfo info2(ip, port);
	CPPUNIT_ASSERT(info2.GetIPAddress() == ip);
	CPPUNIT_ASSERT(info2.GetPort() == port);
	// assignment with ip/port
	info1 = info2;
	CPPUNIT_ASSERT(info1.GetIPAddress() == ip);
	CPPUNIT_ASSERT(info1.GetPort() == port);
	// copy constructor
	MSSQLConnectionInfo info3(info2);
	CPPUNIT_ASSERT(info3.GetIPAddress() == ip);
	CPPUNIT_ASSERT(info3.GetPort() == port);
}

void MSSQLConnectionInfoUnitTests::testGetConnectionString()
{
	typedef struct 
	{
		LPCWSTR ip;
		int port;
		LPCWSTR database;
		bool trusted_auth;
		LPCWSTR username;
		LPCWSTR password;
		LPCWSTR appname;
		LPCWSTR namedpipe;
		ODBCConnectionProtocol protocol;
		LPCWSTR connection_string;
	} TestData;

	TestData testdata[] = 
	{
		{ L"localhost", 1433, L"", TRUE, L"", L"", L"", L"", ODBC_CONNECTION_UNSPECIFIED, L"Driver={SQL Server};Server=localhost,1433;App=APPDETECTIVE;Trusted_Connection=Yes;" },
		{ L"localhost", 1444, L"", TRUE, L"", L"", L"", L"", ODBC_CONNECTION_UNSPECIFIED, L"Driver={SQL Server};Server=localhost,1444;App=APPDETECTIVE;Trusted_Connection=Yes;" },
		{ L"myServerAddress", 1433, L"myDataBase", FALSE, L"myUsername", L"myPassword", L"myApp", L"", ODBC_CONNECTION_UNSPECIFIED, L"Driver={SQL Server};Server=myServerAddress,1433;Database=myDataBase;App=myApp;Uid=myUsername;Pwd=myPassword;" },
		{ L"myServerAddress", 1433, L"myDataBase", TRUE, L"", L"", L"", L"", ODBC_CONNECTION_UNSPECIFIED, L"Driver={SQL Server};Server=myServerAddress,1433;Database=myDataBase;App=APPDETECTIVE;Trusted_Connection=Yes;" },
		{ L"localhost", 1433, L"", TRUE, L"", L"", L"", L"", ODBC_CONNECTION_SPX, L"Driver={SQL Server};Server=spx:localhost,1433;App=APPDETECTIVE;Trusted_Connection=Yes;" },
		{ L"localhost", 1444, L"", TRUE, L"", L"", L"", L"", ODBC_CONNECTION_SPX, L"Driver={SQL Server};Server=spx:localhost,1444;App=APPDETECTIVE;Trusted_Connection=Yes;" },
		{ L"myServerAddress", 1433, L"myDataBase", FALSE, L"myUsername", L"myPassword", L"myApp", L"", ODBC_CONNECTION_SPX, L"Driver={SQL Server};Server=spx:myServerAddress,1433;Database=myDataBase;App=myApp;Uid=myUsername;Pwd=myPassword;" },
		{ L"myServerAddress", 1433, L"myDataBase", TRUE, L"", L"", L"", L"", ODBC_CONNECTION_SPX, L"Driver={SQL Server};Server=spx:myServerAddress,1433;Database=myDataBase;App=APPDETECTIVE;Trusted_Connection=Yes;" },
		{ L"localhost", 1433, L"", TRUE, L"", L"", L"", L"", ODBC_CONNECTION_NAMEDPIPES, L"Driver={SQL Server};Server=np:\\\\.\\pipe\\sql\\query;App=APPDETECTIVE;Trusted_Connection=Yes;" },
		{ L"localhost", 1433, L"", TRUE, L"", L"", L"", L"\\\\WIN2k3\\pipe\\sql\\query2", ODBC_CONNECTION_NAMEDPIPES, L"Driver={SQL Server};Server=np:\\\\WIN2k3\\pipe\\sql\\query2;App=APPDETECTIVE;Trusted_Connection=Yes;" },
	};

	for (unsigned int i = 0; i < ARRAYSIZE(testdata); i++)
	{
		TestData * entry = & testdata[i];
		std::wcout << std::endl << entry->database << L" @ Ip: " << entry->ip << L":" << entry->port;
		MSSQLConnectionInfo info(entry->ip, entry->port);
		info.SetDatabase(entry->database);
		info.SetAppName(entry->appname != L"" ? entry->appname : L"APPDETECTIVE");
		info.SetTrustedAuth(entry->trusted_auth);
		info.SetUsername(entry->username);
		info.SetPassword(entry->password);
		info.SetProtocol(entry->protocol);
		info.SetNamedPipeValue(entry->namedpipe);
		std::wstring connection_string = info.GetConnectionString();
        std::wcout << std::endl << L"Connection string expected => " << entry->connection_string;
		std::wcout << std::endl << L"Connection string result   => " << connection_string;
		CPPUNIT_ASSERT(connection_string.length() > 0);
		CPPUNIT_ASSERT(connection_string == entry->connection_string);
	}
}
