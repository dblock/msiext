#include "StdAfxUnitTests.h"
#include "AccessConnectionInfoUnitTests.h"

using namespace AppSecInc::Databases::ODBC;
using namespace AppSecInc::Databases::Access;
using namespace AppSecInc::UnitTests::Databases::Access;

CPPUNIT_TEST_SUITE_REGISTRATION(AccessConnectionInfoUnitTests);

void AccessConnectionInfoUnitTests::testConstructorDestructor()
{
	{
		AccessConnectionInfo info;
	}

	{
		AccessConnectionInfo * p = new AccessConnectionInfo();
		delete p;
	}
}

void AccessConnectionInfoUnitTests::testCopyAndAssignment()
{
	// default constructor properties
	AccessConnectionInfo info1;
	CPPUNIT_ASSERT(info1.GetUsername().length() == 0);
	CPPUNIT_ASSERT(info1.GetPassword().length() == 0);
	CPPUNIT_ASSERT(info1.GetDBQ().length() == 0);
	// generate a random DBQ filename
    std::wstring dbq = AppSecInc::File::DirectoryCombine(
        AppSecInc::File::GetTemporaryDirectoryW(),
        AppSecInc::Com::GenerateGUIDStringW() + L".dbq");
    std::wcout << std::endl << L"DBQ: " << dbq;
	// constructor with ip/port
	AccessConnectionInfo info2(dbq);
	CPPUNIT_ASSERT(info2.GetDBQ() == dbq);
	// assignment with ip/port
	info1 = info2;
	CPPUNIT_ASSERT(info1.GetDBQ() == dbq);
	// copy constructor
	AccessConnectionInfo info3(info2);
	CPPUNIT_ASSERT(info3.GetDBQ() == dbq);
}

void AccessConnectionInfoUnitTests::testGetConnectionString()
{
	typedef struct 
	{
		LPCWSTR dbq;
		LPCWSTR username;
		LPCWSTR password;
        LPCWSTR connection_string;
	} TestData;

	TestData testdata[] = 
	{
        { L"c:\\temp\\db.dbq", L"", L"", L"Driver={Microsoft Access Driver (*.mdb)};DBQ=c:\\temp\\db.dbq;" },
        { L"c:\\temp\\db.dbq", L"username", L"", L"Driver={Microsoft Access Driver (*.mdb)};DBQ=c:\\temp\\db.dbq;Uid=username;Pwd=;" },
        { L"c:\\temp\\db.dbq", L"username", L"password", L"Driver={Microsoft Access Driver (*.mdb)};DBQ=c:\\temp\\db.dbq;Uid=username;Pwd=password;" },
	};

	for (unsigned int i = 0; i < ARRAYSIZE(testdata); i++)
	{
		TestData * entry = & testdata[i];
		std::wcout << std::endl << entry->dbq;
		AccessConnectionInfo info;
		info.SetDBQ(entry->dbq);
		info.SetUsername(entry->username);
		info.SetPassword(entry->password);
		std::wstring connection_string = info.GetConnectionString();
        std::wcout << std::endl << L"Connection string expected => " << entry->connection_string;
		std::wcout << std::endl << L"Connection string result   => " << connection_string;
		CPPUNIT_ASSERT(connection_string.length() > 0);
		CPPUNIT_ASSERT(connection_string == entry->connection_string);
	}
}
