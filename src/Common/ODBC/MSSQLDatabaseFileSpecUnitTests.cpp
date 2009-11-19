#include "StdAfxUnitTests.h"
#include "MSSQLDatabaseFileSpecUnitTests.h"

using namespace AppSecInc::Databases::ODBC;
using namespace AppSecInc::Databases::MSSQL;
using namespace AppSecInc::UnitTests::Databases::MSSQL;

CPPUNIT_TEST_SUITE_REGISTRATION(MSSQLDatabaseFileSpecUnitTests);

void MSSQLDatabaseFileSpecUnitTests::testConstructorDestructor()
{
	{
		MSSQLDatabaseFileSpec info;
	}

	{
		MSSQLDatabaseFileSpec * p = new MSSQLDatabaseFileSpec();
		delete p;
	}

    {
        MSSQLDatabaseFileSpec spec1;
        spec1.SetType(L"PRIMARY");
        spec1.SetFilename(L"filename");
        spec1.SetName(L"name");
        spec1.SetGrowthSize(L"1MB");
        spec1.SetMaxSize(L"2MB");
        spec1.SetSize(L"3MB");

        MSSQLDatabaseFileSpec spec2(spec1);
        CPPUNIT_ASSERT(spec1.GetType() == spec2.GetType());
        CPPUNIT_ASSERT(spec1.GetFilename() == spec2.GetFilename());
        CPPUNIT_ASSERT(spec1.GetName() == spec2.GetName());
        CPPUNIT_ASSERT(spec1.GetGrowthSize() == spec2.GetGrowthSize());
        CPPUNIT_ASSERT(spec1.GetMaxSize() == spec2.GetMaxSize());
        CPPUNIT_ASSERT(spec1.GetSize() == spec2.GetSize());

        MSSQLDatabaseFileSpec spec3 = spec1;
        CPPUNIT_ASSERT(spec3.GetType() == spec2.GetType());
        CPPUNIT_ASSERT(spec3.GetFilename() == spec2.GetFilename());
        CPPUNIT_ASSERT(spec3.GetName() == spec2.GetName());
        CPPUNIT_ASSERT(spec3.GetGrowthSize() == spec2.GetGrowthSize());
        CPPUNIT_ASSERT(spec3.GetMaxSize() == spec2.GetMaxSize());
        CPPUNIT_ASSERT(spec3.GetSize() == spec2.GetSize());

    }
}

void MSSQLDatabaseFileSpecUnitTests::testGetCreateString()
{
    struct TestData
    {
        LPCWSTR type;
        LPCWSTR filename;
        LPCWSTR name;
        LPCWSTR size;
        LPCWSTR maxsize;
        LPCWSTR growthsize;
        LPCWSTR expected_spec;
    };

    TestData testdata[] = 
    {
        { L"", L"", L"", L"", L"", L"", L"" },
        { L"", L"filename", L"", L"", L"", L"", L"( FILENAME = 'filename' )" },
        { L"PRIMARY", L"filename", L"name", L"1MB", L"2MB", L"3MB", L"PRIMARY ( NAME = [name], FILENAME = 'filename', SIZE = 1MB, MAXSIZE = 2MB, FILEGROWTH = 3MB )" },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        MSSQLDatabaseFileSpec spec;
        spec.SetType(testdata[i].type);
        spec.SetFilename(testdata[i].filename);
        spec.SetName(testdata[i].name);
        spec.SetGrowthSize(testdata[i].growthsize);
        spec.SetMaxSize(testdata[i].maxsize);
        spec.SetSize(testdata[i].size);

        std::wcout << std::endl << spec.GetCreateQuery();
        CPPUNIT_ASSERT(spec.GetCreateQuery() == testdata[i].expected_spec);
    }
}

void MSSQLDatabaseFileSpecUnitTests::testLoadSave()
{
    struct TestData
    {
        LPCWSTR type;
        LPCWSTR filename;
        LPCWSTR name;
        LPCWSTR size;
        LPCWSTR maxsize;
        LPCWSTR growthsize;
    };

    TestData testdata[] = 
    {
        { L"", L"filename", L"", L"", L"", L"" },
        { L"PRIMARY", L"filename", L"name", L"1MB", L"2MB", L"3MB" },
    };

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        MSSQLDatabaseFileSpec spec;
        spec.SetType(testdata[i].type);
        spec.SetFilename(testdata[i].filename);
        spec.SetName(testdata[i].name);
        spec.SetGrowthSize(testdata[i].growthsize);
        spec.SetMaxSize(testdata[i].maxsize);
        spec.SetSize(testdata[i].size);

        AppSecInc::Xml::XmlDocument doc;
        doc.Create();
        MSXML2::IXMLDOMNodePtr root = doc.AppendChild(L"Specs");
        MSXML2::IXMLDOMNodePtr spec_root = spec.Save(doc, root);

        std::wcout << std::endl << doc.GetXml();

        MSSQLDatabaseFileSpec spec_copy;
        spec_copy.Load(doc, spec_root);

        CPPUNIT_ASSERT(spec.GetType() == spec_copy.GetType());
        CPPUNIT_ASSERT(spec.GetFilename() == spec_copy.GetFilename());
        CPPUNIT_ASSERT(spec.GetName() == spec_copy.GetName());
        CPPUNIT_ASSERT(spec.GetGrowthSize() == spec_copy.GetGrowthSize());
        CPPUNIT_ASSERT(spec.GetMaxSize() == spec_copy.GetMaxSize());
        CPPUNIT_ASSERT(spec.GetSize() == spec_copy.GetSize());
    }
}
