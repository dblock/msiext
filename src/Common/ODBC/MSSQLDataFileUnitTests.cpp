#include "StdAfxUnitTests.h"
#include "MSSQLDataFileUnitTests.h"

using namespace AppSecInc::Databases::ODBC;
using namespace AppSecInc::Databases::MSSQL;
using namespace AppSecInc::UnitTests::Databases::MSSQL;

CPPUNIT_TEST_SUITE_REGISTRATION(MSSQLDataFileUnitTests);

void MSSQLDataFileUnitTests::testConstructorDestructor()
{
	{
		MSSQLDataFile info;
	}

	{
		MSSQLDataFile * p = new MSSQLDataFile();
		delete p;
	}

    {
        MSSQLDataFile datafile1;
        datafile1.SetDatabase(L"database");
        datafile1.SetFilename(L"filename");
        datafile1.SetSchema(L"dbo");
        datafile1.SetTable(L"table");
        datafile1.AddParameter(L"BATCHSIZE", L"10");
        datafile1.AddParameter(L"CODEPAGE", L"'ACP'");

        MSSQLDataFile datafile2(datafile1);
        CPPUNIT_ASSERT(datafile1.GetDatabase() == datafile2.GetDatabase());
        CPPUNIT_ASSERT(datafile1.GetFilename() == datafile2.GetFilename());
        CPPUNIT_ASSERT(datafile1.GetSchema() == datafile2.GetSchema());
        CPPUNIT_ASSERT(datafile1.GetTable() == datafile2.GetTable());
        CPPUNIT_ASSERT(datafile1.GetParameters().size() == datafile2.GetParameters().size());

        MSSQLDataFile datafile3 = datafile1;
        CPPUNIT_ASSERT(datafile3.GetDatabase() == datafile2.GetDatabase());
        CPPUNIT_ASSERT(datafile3.GetFilename() == datafile2.GetFilename());
        CPPUNIT_ASSERT(datafile3.GetSchema() == datafile2.GetSchema());
        CPPUNIT_ASSERT(datafile3.GetTable() == datafile2.GetTable());
        CPPUNIT_ASSERT(datafile3.GetParameters().size() == datafile2.GetParameters().size());
    }
}

void MSSQLDataFileUnitTests::testGetInsertString()
{
    struct TestData
    {
        LPCWSTR database;
        LPCWSTR schema;
        LPCWSTR table;
        LPCWSTR filename;
        LPCWSTR option1;
        LPCWSTR option2;
        LPCWSTR expectedquery;
    };

    TestData testdata[] = 
    {
        { L"", L"", L"table", L"filename", NULL, NULL, L"BULK INSERT [table] FROM 'filename'" },
        { L"database", L"dbo", L"table", L"filename", L"option1 = value1", NULL, L"BULK INSERT [database].[dbo].[table] FROM 'filename' WITH ( option1 = value1 )" },
        { L"database", L"dbo", L"table", L"filename", L"option1 = value1", L"option2 = value2", L"BULK INSERT [database].[dbo].[table] FROM 'filename' WITH ( option1 = value1, option2 = value2 )" },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        MSSQLDataFile datafile;
        datafile.SetDatabase(testdata[i].database);
        datafile.SetFilename(testdata[i].filename);
        datafile.SetSchema(testdata[i].schema);
        datafile.SetTable(testdata[i].table);

        if (testdata[i].option1 != NULL) datafile.AddParameter(testdata[i].option1);
        if (testdata[i].option2 != NULL) datafile.AddParameter(testdata[i].option2);

        std::wcout << std::endl << datafile.GetInsertQuery();
        CPPUNIT_ASSERT(datafile.GetInsertQuery() == testdata[i].expectedquery);
    }
}

void MSSQLDataFileUnitTests::testLoadSave()
{
    struct TestData
    {
        LPCWSTR database;
        LPCWSTR schema;
        LPCWSTR table;
        LPCWSTR filename;
        LPCWSTR option1;
        LPCWSTR option2;
    };

    TestData testdata[] = 
    {
        { L"", L"", L"", L"", NULL, NULL },
        { L"database", L"dbo", L"table", L"filename", L"option1 = value1", NULL },
        { L"database", L"dbo", L"table", L"filename", L"option1 = value1", L"option2 = value2" },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        MSSQLDataFile datafile;
        datafile.SetDatabase(testdata[i].database);
        datafile.SetFilename(testdata[i].filename);
        datafile.SetSchema(testdata[i].schema);
        datafile.SetTable(testdata[i].table);

        AppSecInc::Xml::XmlDocument doc;
        doc.Create();
        MSXML2::IXMLDOMNodePtr root = doc.AppendChild(L"DataFiles");
        MSXML2::IXMLDOMNodePtr datafile_root = datafile.Save(doc, root);

        std::wcout << std::endl << doc.GetXml();

        MSSQLDataFile datafile_copy;
        datafile_copy.Load(doc, datafile_root);

        CPPUNIT_ASSERT(datafile.GetDatabase() == datafile_copy.GetDatabase());
        CPPUNIT_ASSERT(datafile.GetFilename() == datafile_copy.GetFilename());
        CPPUNIT_ASSERT(datafile.GetSchema() == datafile_copy.GetSchema());
        CPPUNIT_ASSERT(datafile.GetTable() == datafile_copy.GetTable());
        CPPUNIT_ASSERT(datafile.GetParameters().size() == datafile_copy.GetParameters().size());
    }
}
