#include "StdAfxUnitTests.h"
#include "MSSQLDatabaseUnitTests.h"

using namespace AppSecInc::Databases::ODBC;
using namespace AppSecInc::Databases::MSSQL;
using namespace AppSecInc::UnitTests::Databases::MSSQL;

CPPUNIT_TEST_SUITE_REGISTRATION(MSSQLDatabaseUnitTests);

void MSSQLDatabaseUnitTests::testConstructorDestructor()
{
	{
		MSSQLDatabase info;
	}

	{
		MSSQLDatabase * p = new MSSQLDatabase();
		delete p;
	}
}

void MSSQLDatabaseUnitTests::testCreate()
{
    std::wstring databasename = AppSecInc::Com::GenerateGUIDStringW();
    AppSecInc::StringUtils::lrtrim(databasename, L"{}");
    std::wcout << std::endl << L"Creating: " << databasename;
    MSSQLConnectionInfo connection_info;
    connection_info.SetIPAddress(L"localhost");
    MSSQLDatabase database(connection_info);   
    database.SetName(databasename);
    database.Connect();
    CPPUNIT_ASSERT(! database.Exists());
    database.DropIfExists();
    database.Create();
    CPPUNIT_ASSERT(database.Exists());
    database.CreateIfNotExists();
    std::wcout << std::endl << L"Dropping: " << databasename;
    database.Drop();
    CPPUNIT_ASSERT(! database.Exists());
    database.CreateIfNotExists();
    CPPUNIT_ASSERT(database.Exists());
    database.CreateIfNotExists();
    CPPUNIT_ASSERT(database.Exists());
    database.DropIfExists();
    CPPUNIT_ASSERT(! database.Exists());
    database.DropIfExists();
}

void MSSQLDatabaseUnitTests::testGetCreateQuery()
{
    struct TestData
    {
        LPCWSTR name;
        LPCWSTR expected_query;        
    };

    TestData testdata[] = 
    {
        { L"", L"CREATE DATABASE []" },
        { L"name", L"CREATE DATABASE [name]" },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        MSSQLDatabase database;
        database.SetName(testdata[i].name);

        std::wcout << std::endl << database.GetCreateQuery();
        CPPUNIT_ASSERT(database.GetCreateQuery() == testdata[i].expected_query);
    }

    // with filespecs
    MSSQLDatabaseFileSpec spec1;
    spec1.SetType(L"PRIMARY");
    spec1.SetName(L"spec1");
    spec1.SetFilename(L"filename1");

    MSSQLDatabaseFileSpec spec2;
    spec2.SetType(L"LOG ON");
    spec2.SetName(L"spec1");
    spec2.SetFilename(L"filename1");

    MSSQLDatabase database1;
    database1.SetName(L"test");
    database1.AddFileSpec(spec1);
    database1.AddFileSpec(spec2);
    database1.SetCollate(L"French_CI_AI");
    database1.SetPurpose(L"ATTACH_REBUILD_LOG");
    database1.AddOption(L"TRUSTWORTHY ON");
    database1.AddOption(L"DB_CHAINING ON");

    std::wcout << std::endl << database1.GetCreateQuery();
    CPPUNIT_ASSERT(L"CREATE DATABASE [test] ON\n" \
        L" PRIMARY ( NAME = [spec1], FILENAME = 'filename1' )\n" \
        L" LOG ON ( NAME = [spec1], FILENAME = 'filename1' )\n" \
        L"COLLATE French_CI_AI\n" \
        L"FOR ATTACH_REBUILD_LOG\n" \
        L"WITH TRUSTWORTHY ON, DB_CHAINING ON" == database1.GetCreateQuery());
}

void MSSQLDatabaseUnitTests::testLoadSave()
{
    // with filespecs
    MSSQLDatabaseFileSpec spec1;
    spec1.SetType(L"PRIMARY");
    spec1.SetName(L"spec1");
    spec1.SetFilename(L"filename1");

    MSSQLDatabaseFileSpec spec2;
    spec2.SetType(L"LOG ON");
    spec2.SetName(L"spec1");
    spec2.SetFilename(L"filename1");

    MSSQLDatabase database1;
    database1.SetName(L"test");
    database1.AddFileSpec(spec1);
    database1.AddFileSpec(spec2);
    database1.SetCollate(L"French_CI_AI");
    database1.SetPurpose(L"ATTACH_REBUILD_LOG");
    database1.AddOption(L"TRUSTWORTHY ON");
    database1.AddOption(L"DB_CHAINING ON");

    AppSecInc::Xml::XmlDocument doc;
    doc.Create();
    MSXML2::IXMLDOMNodePtr root = doc.AppendChild(L"Databases");
    MSXML2::IXMLDOMNodePtr database_root = database1.Save(doc, root);

    std::wcout << std::endl << doc.GetXml();

    MSSQLDatabase database2;
    database2.Load(doc, database_root);

    CPPUNIT_ASSERT(database2.GetName() == database1.GetName());
    CPPUNIT_ASSERT(database2.GetCollate() == database1.GetCollate());
    CPPUNIT_ASSERT(database2.GetPurpose() == database1.GetPurpose());
    CPPUNIT_ASSERT(database2.GetOptions().size() == database1.GetOptions().size());
    CPPUNIT_ASSERT(database2.GetFileSpecs().size() == database1.GetFileSpecs().size());
}