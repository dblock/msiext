#include "StdAfxUnitTests.h"
#include "SqlDMOUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::DataSource::SQLDMOUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::DataSource;

void SQLDMOUnitTests::Test_SQLDMO_ListAvailableSQLServers()
{
	AppSecInc::Msi::MsiShim hInstall;
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_DataSourceUnitTests", L"ComboBox.idt"); 
    MsiInstall msiInstall(hInstall);

    msiInstall.SetProperty("SQLDMO_LIST_PROPERTY", "SQLDMO_TEST");
    msiInstall.SetProperty("SQLDMO_LIST_TYPE", "ComboBox");
    msiInstall.SetProperty("SQLDMO_LIST_INDEX", "1");
    msiInstall.SetProperty("SQLDMO_LIST_LOCAL", "");

	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"DataSource.dll", L"SQLDMO_ListAvailableSQLServers"));
    AppSecInc::Xml::XmlDocument listxml;
    listxml.LoadXml(msiInstall.GetViewData(L"SELECT * FROM `ComboBox`"));
	MSXML2::IXMLDOMNodeListPtr rows = listxml.SelectNodes(L"//Row");
    long rowcount = rows->length;
    std::wcout << std::endl << L"Rows: " << rowcount;
    CPPUNIT_ASSERT(rowcount > 0);
	MSXML2::IXMLDOMNodePtr row = NULL;
	// make sure there're no dups
	std::vector<std::wstring> values;
	while (NULL != (row = rows->nextNode()))
	{
		std::wstring value = listxml.SelectNodeValue(L"Data[@Column='Value']", row);
		std::wcout << std::endl << L" " << value;
		values.push_back(value);
	}
	std::sort(values.begin(), values.end());
	std::vector<std::wstring>::iterator unique = std::unique(values.begin(), values.end());
	values.erase(unique, values.end());
	std::wcout << std::endl << L"Unique rows: " << values.size();
	CPPUNIT_ASSERT(values.size() == rowcount);
}

void SQLDMOUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"DataSource.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing DataSource.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "SQLDMO_ListAvailableSQLServers"));
	::FreeModule(h);
}