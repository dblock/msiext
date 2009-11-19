#include "StdAfxUnitTests.h"
#include "AccessDatabaseUnitTests.h"

using namespace AppSecInc::Databases::ODBC;
using namespace AppSecInc::Databases::Access;
using namespace AppSecInc::UnitTests::Databases::Access;

CPPUNIT_TEST_SUITE_REGISTRATION(AccessDatabaseUnitTests);

void AccessDatabaseUnitTests::testConstructorDestructor()
{
	{
		AccessDatabase info;
	}

	{
		AccessDatabase * p = new AccessDatabase();
		delete p;
	}
}

void AccessDatabaseUnitTests::testCreate()
{
    std::list<std::wstring> dbqs;
    dbqs.push_back(AppSecInc::File::DirectoryCombine(
        AppSecInc::File::GetTemporaryDirectoryW(), 
        AppSecInc::Com::GenerateGUIDStringW() + L".dbq"));
    dbqs.push_back(AppSecInc::File::DirectoryCombine(
        AppSecInc::File::GetTemporaryDirectoryW(), 
        AppSecInc::Com::GenerateGUIDStringW() + L" Space.dbq"));

    for each(const std::wstring& dbq in dbqs)
    {
        std::wcout << std::endl << L"Creating: " << dbq;
        AccessConnectionInfo connection_info;
        connection_info.SetDBQ(dbq);
        AccessDatabase database(connection_info);
        database.SetDBQ(dbq);
        CPPUNIT_ASSERT(! database.Exists());
        database.DropIfExists();
        database.Create();
		// make sure the connection string can be used in an ODBC connection
		ODBCConnection conn;
		conn.Connect(connection_info);
		conn.Execute(L"CREATE TABLE t1 ( t1_id INTEGER )");
		conn.Disconnect();
        CPPUNIT_ASSERT(database.Exists());
        database.CreateIfNotExists();
        std::wcout << std::endl << L"Dropping: " << dbq;
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
}

void AccessDatabaseUnitTests::testLoadSave()
{
    AccessDatabase database1;
    database1.SetDBQ(L"test");

    AppSecInc::Xml::XmlDocument doc;
    doc.Create();
    MSXML2::IXMLDOMNodePtr root = doc.AppendChild(L"Databases");
    MSXML2::IXMLDOMNodePtr database_root = database1.Save(doc, root);

    std::wcout << std::endl << doc.GetXml();

    AccessDatabase database2;
    database2.Load(doc, database_root);

    CPPUNIT_ASSERT(database2.GetDBQ() == database1.GetDBQ());
}
