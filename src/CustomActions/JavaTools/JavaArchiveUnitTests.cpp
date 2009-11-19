#include "StdAfxUnitTests.h"
#include "JavaArchiveUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::JavaTools::JavaArchiveUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::JavaTools;

void JavaArchiveUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"JavaTools.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing JavaTools.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "JavaArchive_Immediate"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "JavaArchive_Deferred"));
	::FreeLibrary(h);
}

void JavaArchiveUnitTests::Test_JavaArchive()
{
    // the test data contains two archives: one to compress, one to extract
    // both are optional and require JAVA_COMPRESS = 1 to compress and JAVA_EXTRACT to extract
    std::wstring source_location = AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_JavaToolsUnitTests\\";
	
    // expect to find a compressed JavaToolsUnitTestsCompress.jar when JAVA_COMPRESS
    std::wstring javatoolsunittestscompress_filename = source_location + L"\\JavaToolsUnitTestsCompress.jar";
    // expect to find an extracted JavaToolsMsi.txt when JAVA_EXTRACT
    std::wstring javatoolsunittestsmsitxt_filename = source_location + L"\\JavaToolsMsi.txt";

    AppSecInc::Msi::MsiShim hInstall;
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_JavaToolsUnitTests", L"JavaArchive.idt");
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_JavaToolsUnitTests", L"JavaArchiveFile.idt");

    AppSecInc::Msi::MsiInstall msiInstall(hInstall);
    msiInstall.SetProperty(L"SOURCELOCATION", source_location);

	// expect to find jar.exe in the JDK location
	std::wstring jdk_version = AppSecInc::Registry::GetStringValue(HKEY_LOCAL_MACHINE,
		L"SOFTWARE\\JavaSoft\\Java Development Kit", L"CurrentVersion");
	std::wstring jdk_javahome = AppSecInc::Registry::GetStringValue(HKEY_LOCAL_MACHINE,
		L"SOFTWARE\\JavaSoft\\Java Development Kit\\" + jdk_version, L"JavaHome");
	std::wstring jdk_javahomebin = AppSecInc::File::DirectoryCombine(jdk_javahome, L"bin\\");
	std::wcout << std::endl << L"JAVA_HOME\\bin: " << jdk_javahomebin;
	CPPUNIT_ASSERT(AppSecInc::File::DirectoryExists(jdk_javahomebin));
	msiInstall.SetProperty(L"JDKBINLOCATION", jdk_javahomebin);

    AppSecInc::Xml::XmlDocument xml;

    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"JavaTools.dll", L"JavaArchive_Immediate"));
    xml.LoadXml(msiInstall.GetProperty(L"JavaArchive_Deferred"));

    // delete files possibly leftoever from a previous run
    ::DeleteFileW(javatoolsunittestscompress_filename.c_str());
    ::DeleteFileW(javatoolsunittestsmsitxt_filename.c_str());

    // execute the deferred CA, expect to find neither compressed or extracted files
    msiInstall.SetProperty(L"CustomActionData", msiInstall.GetProperty(L"JavaArchive_Deferred"));
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"JavaTools.dll", L"JavaArchive_Deferred"));
    CPPUNIT_ASSERT(! AppSecInc::File::FileExists(javatoolsunittestscompress_filename));
    CPPUNIT_ASSERT(! AppSecInc::File::FileExists(javatoolsunittestsmsitxt_filename));

    // a single root JavaArchives node
    CPPUNIT_ASSERT(1 == xml.SelectNodes(L"/JavaArchives")->length);
    // 2 java archives (one extract, one compress)
    CPPUNIT_ASSERT(2 == xml.SelectNodes(L"/JavaArchives/JavaArchive")->length);
    CPPUNIT_ASSERT(1 == xml.SelectNodes(L"/JavaArchives/JavaArchive[@operation='xvf']")->length);
    CPPUNIT_ASSERT(1 == xml.SelectNodes(L"/JavaArchives/JavaArchive[@operation='cvf']")->length);
    // 2 files being compressed/extracted
    CPPUNIT_ASSERT(2 == xml.SelectNodes(L"//JavaArchiveFile")->length);
    // extraction and compression are conditional, condition is 0 by default of the extract and compress java archive
    CPPUNIT_ASSERT(2 == xml.SelectNodes(L"//JavaArchive[@condition='0']")->length);

    // set JAR_EXTRACT = 1, extract JARs
    msiInstall.SetProperty(L"JAR_EXTRACT", L"1");
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"JavaTools.dll", L"JavaArchive_Immediate"));
    xml.LoadXml(msiInstall.GetProperty(L"JavaArchive_Deferred"));
    CPPUNIT_ASSERT(1 == xml.SelectNodes(L"//JavaArchive[@condition='0']")->length);
    CPPUNIT_ASSERT(0 == xml.SelectNodes(L"//JavaArchiveFile[@condition='1']")->length);
    CPPUNIT_ASSERT(1 == xml.SelectNodes(L"//JavaArchive[@condition='1']")->length);

    // execute the deferred CA, expect to find the extracted file
    msiInstall.SetProperty(L"CustomActionData", msiInstall.GetProperty(L"JavaArchive_Deferred"));
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"JavaTools.dll", L"JavaArchive_Deferred"));
    CPPUNIT_ASSERT(! AppSecInc::File::FileExists(javatoolsunittestscompress_filename));
    CPPUNIT_ASSERT(AppSecInc::File::FileExists(javatoolsunittestsmsitxt_filename));
    ::DeleteFileW(javatoolsunittestsmsitxt_filename.c_str());

    // set JAR_COMPRESS = 1, compress JARs
    msiInstall.SetProperty(L"JAR_COMPRESS", L"1");
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"JavaTools.dll", L"JavaArchive_Immediate"));
    xml.LoadXml(msiInstall.GetProperty(L"JavaArchive_Deferred"));
    CPPUNIT_ASSERT(0 == xml.SelectNodes(L"//JavaArchive[@condition='0']")->length);
    CPPUNIT_ASSERT(2 == xml.SelectNodes(L"//JavaArchiveFile[@condition='1']")->length);
    CPPUNIT_ASSERT(2 == xml.SelectNodes(L"//JavaArchive[@condition='1']")->length);

    // execute the deferred CA, expect to find both extracted and compressed files
    msiInstall.SetProperty(L"CustomActionData", msiInstall.GetProperty(L"JavaArchive_Deferred"));
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"JavaTools.dll", L"JavaArchive_Deferred"));
    CPPUNIT_ASSERT(AppSecInc::File::FileExists(javatoolsunittestscompress_filename));
    CPPUNIT_ASSERT(AppSecInc::File::FileExists(javatoolsunittestsmsitxt_filename));
    ::DeleteFileW(javatoolsunittestscompress_filename.c_str());
    ::DeleteFileW(javatoolsunittestsmsitxt_filename.c_str());
}