#include "StdAfxUnitTests.h"
#include "TemplateFilesUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::TemplateFiles::TemplateFilesUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::TemplateFiles;

void TemplateFilesUnitTests::Test_TemplateFiles()
{
    AppSecInc::Msi::MsiShim hInstall;
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_SystemToolsUnitTests", L"TemplateFiles.idt");
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_SystemToolsUnitTests", L"TemplateFileProperties.idt");
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_SystemToolsUnitTests", L"Property.idt");

    MsiInstall msiInstall(hInstall);
    std::wstring source_location = AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_SystemToolsUnitTests\\";
    std::wstring install_location = AppSecInc::File::GetTemporaryDirectoryW();
    msiInstall.SetProperty(L"SOURCELOCATION", source_location);
    msiInstall.SetProperty(L"INSTALLLOCATION", install_location);
    
    std::wstring template_file_source = source_location + L"TemplateFile.template";
    std::wstring template_file_target = install_location + L"TemplateFile.txt";

    std::wstring template_file_source_utf8 = source_location + L"TemplateFile-UTF8.template";
    std::wstring template_file_target_utf8 = install_location + L"TemplateFile-UTF8.txt";

    // delete temporary files from previous runs
    ::DeleteFileW(template_file_target.c_str());
    ::DeleteFileW(template_file_target_utf8.c_str());

    // execute the immediate CA that processes the TemplateFiles table and sets TemplateFiles_Deferred property
    {
        CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"TemplateFiles_Immediate"));
        AppSecInc::Xml::XmlDocument deferred_xml;
        deferred_xml.LoadXml(msiInstall.GetProperty(L"TemplateFiles_Deferred"));

        // there's 1 file to process
        CPPUNIT_ASSERT(2 == deferred_xml.SelectNodes(L"//TemplateFile")->length);
        // there's 1 row that is going to be executed
        CPPUNIT_ASSERT(2 == deferred_xml.SelectNodes(L"//TemplateFile[@execute='true']")->length);
        CPPUNIT_ASSERT(0 == deferred_xml.SelectNodes(L"//TemplateFile[@execute='false']")->length);
        // there're 6 property nodes of built-in properties + 2 user-defined for the first template
        CPPUNIT_ASSERT(14 == deferred_xml.SelectNodes(L"/TemplateFiles/TemplateFile/Properties/Property")->length);
    }

    // execute the deferred CA that evalutes the template files
    msiInstall.SetProperty(L"CustomActionData", msiInstall.GetProperty(L"TemplateFiles_Deferred"));
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"TemplateFiles_Deferred"));

	// ANSI
    CPPUNIT_ASSERT(AppSecInc::File::FileExists(template_file_target));
    std::wstring data;
    CPPUNIT_ASSERT(! AppSecInc::File::ReadAndConvertToEnd(template_file_target, data));
    CPPUNIT_ASSERT(! data.empty());
    // test properties were evaluated
    CPPUNIT_ASSERT(data.find(L"TEST1=test1") != data.npos);
    CPPUNIT_ASSERT(data.find(L"TEST2=test2") != data.npos);
    // INSTALLLOCATION was globally set, but not passed to the template files action
    CPPUNIT_ASSERT(data.find(L"INSTALLLOCATION=[INSTALLLOCATION]") != data.npos);
    ::DeleteFileW(template_file_target.c_str());

	// UTF8
    CPPUNIT_ASSERT(AppSecInc::File::FileExists(template_file_target_utf8));
    std::wstring data_utf8;
    CPPUNIT_ASSERT(AppSecInc::File::ReadAndConvertToEnd(template_file_target_utf8, data_utf8));
    CPPUNIT_ASSERT(! data_utf8.empty());
    // test properties were evaluated
    // INSTALLLOCATION was globally set, but not passed to the template files action
    CPPUNIT_ASSERT(data_utf8.find(L"UTF8String=") != data_utf8.npos);
    ::DeleteFileW(template_file_target.c_str());
}

void TemplateFilesUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"SystemTools.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing SystemTools.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "TemplateFiles_Immediate"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "TemplateFiles_Deferred"));
	::FreeLibrary(h);
}
