#include "StdAfxUnitTests.h"
#include "CompareVersionImplUnitTests.h"
#include "CompareVersionImpl.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::CompareVersion::CompareVersionImplUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::CompareVersion;

struct TestData
{
    std::wstring property_name;
    std::wstring expected_version;
};

TestData testdata[] = 
{
    { L"VERSIONPROPERTY_380_380", L"3.8.0" },
    { L"VERSIONPROPERTY_381_380", L"3.8.1" },
    { L"VERSIONPROPERTY_390_380", L"3.9.0" },
    { L"VERSIONPROPERTY_400_380", L"4.0.0" },
    { L"VERSIONPROPERTY_380_480", L"" },
    { L"VERSIONPROPERTY_3818_38", L"3.8.18" },
    { L"VERSIONPROPERTY_380_380_380", L"3.8.0" },
    { L"VERSIONPROPERTY_381_380_382", L"3.8.1" },
    { L"VERSIONPROPERTY_380_383_382", L"" },
};

void CompareVersionImplUnitTests::Test_CompareVersions()
{
    AppSecInc::Msi::MsiShim hInstall;
    AppSecInc::Xml::XmlDocument xmlDoc;
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_SystemToolsUnitTests", L"CompareVersions.idt"); 

    MsiInstall msiInstall(hInstall);

    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"CompareVersions"));

    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
	    std::wstring test_version = msiInstall.GetProperty(testdata[i].property_name);
        std::wcout << std::endl << testdata[i].property_name << L": " << test_version << " vs. " << testdata[i].expected_version;
	    CPPUNIT_ASSERT(StringUtils::comparei(test_version, testdata[i].expected_version));
    }
}

void CompareVersionImplUnitTests::Test_CompareVersion()
{
    AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
    AppSecInc::Xml::XmlDocument xmlDoc;
    xmlDoc.Load(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_SystemToolsUnitTests\\Version.xml");

    MSXML2::IXMLDOMNodeListPtr rows = xmlDoc->selectNodes(L"//Row");
    CHECK_BOOL(NULL != rows, L"Missing data rows");
    MSXML2::IXMLDOMNodePtr row = rows->nextNode();
    for (int i = 0; i < ARRAYSIZE(testdata); i++)
    {
        CPPUNIT_ASSERT(row != NULL);

        msiInstall.SetProperty(L"VERSION_INSTALLED", xmlDoc.SelectNodeValue(L"Data[@Column =\"InstalledVersion\"]", row));
        msiInstall.SetProperty(L"VERSION_MINIMUM", xmlDoc.SelectNodeValue(L"Data[@Column =\"MinimumVersion\"]", row));
		msiInstall.SetProperty(L"VERSION_MAXIMUM", xmlDoc.SelectNodeValue(L"Data[@Column =\"MaximumVersion\"]", row, L""));
		msiInstall.SetProperty(L"VERSION_PROPERTY", xmlDoc.SelectNodeValue(L"Data[@Column =\"Property\"]", row));

        CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"CompareVersion"));

        std::wstring test_version = msiInstall.GetProperty(xmlDoc.SelectNodeValue(L"Data[@Column =\"Property\"]", row));
        std::wcout << std::endl << testdata[i].property_name << L": " << test_version << " vs. " << testdata[i].expected_version;
	    CPPUNIT_ASSERT(StringUtils::comparei(test_version, testdata[i].expected_version));

        row = rows->nextNode();
    }
}

void CompareVersionImplUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"SystemTools.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing SystemTools.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "CompareVersions"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "CompareVersion"));
	::FreeLibrary(h);
}