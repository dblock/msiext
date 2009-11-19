#include "StdAfxUnitTests.h"
#include "RegistryImplUnitTests.h"
#include <boost/smart_ptr.hpp>

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::Registry::RegistryImplUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::Registry;

void RegistryImplUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"SystemTools.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing SystemTools.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Registry_CopyBranch"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Registry_DeleteBranch"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Registry_MoveBranch"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Registry_CreateKey"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Registry_SetStringValue"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Registry_KeyExists"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Win32_RegistryCopy_Immediate"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Win32_RegistryCopy_Deferred"));
	::FreeLibrary(h);
}

void RegistryImplUnitTests::Test_Registry_CopyDeleteBranch()
{
    AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

	std::wstring _guid = AppSecInc::Com::GenerateGUIDStringW();
	std::wstring basepath = L"SOFTWARE\\UNITTEST\\";
	std::wstring path = basepath + _guid;

	// copy a well known registry hive
	msiInstall.SetProperty(L"REGISTRY_ROOT", L"HKEY_LOCAL_MACHINE");
	msiInstall.SetProperty(L"REGISTRY_PATH_SOURCE", L"SOFTWARE\\Microsoft\\NET Framework Setup");
	msiInstall.SetProperty(L"REGISTRY_PATH_TARGET", path);
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Registry_CopyBranch"));

	// compare a value from the original branch with a value from the copied branch
	std::wstring originalValue = AppSecInc::Registry::GetStringValue(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v2.0.50727", L"Version");
	std::wstring copiedValue = AppSecInc::Registry::GetStringValue(HKEY_LOCAL_MACHINE, path + L"\\NDP\\v2.0.50727", L"Version");
	CPPUNIT_ASSERT(originalValue == copiedValue);
	
	// Testing nested copy and paste where the target is below the source.
	// No infinite trees should be created.
	msiInstall.SetProperty(L"REGISTRY_ROOT", L"HKEY_LOCAL_MACHINE");
	msiInstall.SetProperty(L"REGISTRY_PATH_SOURCE", path);
	msiInstall.SetProperty(L"REGISTRY_PATH_TARGET", path + L"\\" + _guid + L"_backup");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Registry_CopyBranch"));

	// compare a value from the original branch with a value from the copied branch
	originalValue = AppSecInc::Registry::GetStringValue(HKEY_LOCAL_MACHINE, path + L"\\NDP\\v2.0.50727", L"Version");
	copiedValue = AppSecInc::Registry::GetStringValue(HKEY_LOCAL_MACHINE, path + L"\\" + _guid + L"_backup" + L"\\NDP\\v2.0.50727", L"Version");
	CPPUNIT_ASSERT(originalValue == copiedValue);

	// check for inifinite tree
	{
		// the key should not exist
		HKEY reg = NULL;
		std::wstring testPath = path + L"\\" + _guid + L"_backup\\" + _guid + L"_backup";
		CPPUNIT_ASSERT(ERROR_FILE_NOT_FOUND == RegOpenKeyEx(HKEY_LOCAL_MACHINE,  testPath.c_str(), 0, KEY_READ, & reg));
	}

	// delete the copied branch
	msiInstall.SetProperty(L"REGISTRY_ROOT", L"HKEY_LOCAL_MACHINE");
	msiInstall.SetProperty(L"REGISTRY_PATH", basepath);
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Registry_DeleteBranch"));

	HKEY reg = NULL;
    boost::shared_ptr<void> reg_ptr(reg, ::RegCloseKey);
	CPPUNIT_ASSERT(ERROR_FILE_NOT_FOUND == RegOpenKeyEx(HKEY_LOCAL_MACHINE, basepath.c_str(), 0, KEY_READ, & reg));

}

void RegistryImplUnitTests::Test_Registry_MoveBranch()
{
    AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

	// copy a well known registry hive
	AppSecInc::Registry::CopyBranch(
		HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\NET Framework Setup", 
		HKEY_LOCAL_MACHINE, L"SOFTWARE\\RegistryUnitTests");

	// move the copied hive
	msiInstall.SetProperty(L"REGISTRY_ROOT", L"HKEY_LOCAL_MACHINE");
	msiInstall.SetProperty(L"REGISTRY_PATH_SOURCE", L"SOFTWARE\\RegistryUnitTests");
	msiInstall.SetProperty(L"REGISTRY_PATH_TARGET", L"SOFTWARE\\MovedRegistryUnitTests");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Registry_MoveBranch"));

	{
		// the source doesn't exist any more
		HKEY reg = NULL;
		boost::shared_ptr<void> reg_ptr(reg, ::RegCloseKey);
		CPPUNIT_ASSERT(ERROR_FILE_NOT_FOUND == RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"SOFTWARE\\RegistryUnitTests", 0, KEY_READ, & reg));
	}

	{
		// the target exists
		HKEY reg = NULL;
		boost::shared_ptr<void> reg_ptr(reg, ::RegCloseKey);
		CPPUNIT_ASSERT(ERROR_SUCCESS == RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"SOFTWARE\\MovedRegistryUnitTests", 0, KEY_READ, & reg));
	}

	AppSecInc::Registry::DeleteBranch(HKEY_LOCAL_MACHINE, L"SOFTWARE\\MovedRegistryUnitTests");
}

void RegistryImplUnitTests::Test_Registry_CreateKey()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);

	std::wstring _guid = AppSecInc::Com::GenerateGUIDStringW();
	std::wstring path = L"SOFTWARE\\UNITTEST\\" + _guid;

	msiInstall.SetProperty(L"REGISTRY_ROOT", L"HKEY_LOCAL_MACHINE");
	msiInstall.SetProperty(L"REGISTRY_PATH", path);
	
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Registry_CreateKey"));

	{
		// check key if exists
		HKEY reg = NULL;
		boost::shared_ptr<void> reg_ptr(reg, ::RegCloseKey);
		CPPUNIT_ASSERT(ERROR_SUCCESS == RegOpenKeyEx(HKEY_LOCAL_MACHINE, path.c_str(), 0, KEY_READ, & reg));
	}

	AppSecInc::Registry::DeleteBranch(HKEY_LOCAL_MACHINE, L"SOFTWARE\\UNITTEST");
	CPPUNIT_ASSERT(! AppSecInc::Registry::KeyExists(HKEY_LOCAL_MACHINE, L"SOFTWARE\\UNITTEST"));
}

void RegistryImplUnitTests::Test_Registry_SetStringValue()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
		
    std::wstring _guid = AppSecInc::Com::GenerateGUIDStringW();
	std::wstring path = L"SOFTWARE\\UNITTEST\\" + _guid;

	// move the copied hive
	msiInstall.SetProperty(L"REGISTRY_ROOT", L"HKEY_LOCAL_MACHINE");
	msiInstall.SetProperty(L"REGISTRY_PATH", path);
	msiInstall.SetProperty(L"REGISTRY_NAME", L"Developer");
	msiInstall.SetProperty(L"REGISTRY_VALUE", L"abc");

	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Registry_SetStringValue"));

	{
		// check if key exists
		HKEY reg = NULL;
		boost::shared_ptr<void> reg_ptr(reg, ::RegCloseKey);
		CPPUNIT_ASSERT(ERROR_SUCCESS == RegOpenKeyEx(HKEY_LOCAL_MACHINE, path.c_str(), 0, KEY_READ, & reg));
	}

	std::wstring regvalue = AppSecInc::Registry::GetStringValue(HKEY_LOCAL_MACHINE, path, L"Developer");
	CPPUNIT_ASSERT(regvalue == L"abc");

	AppSecInc::Registry::DeleteBranch(HKEY_LOCAL_MACHINE, L"SOFTWARE\\UNITTEST");
	CPPUNIT_ASSERT(! AppSecInc::Registry::KeyExists(HKEY_LOCAL_MACHINE, L"SOFTWARE\\UNITTEST"));
}

void RegistryImplUnitTests::Test_Registry_KeyExists()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
		
  	std::wstring guid = AppSecInc::Com::GenerateGUIDStringW();
    std::wstring path = L"SOFTWARE\\" + guid;

	// copy a well known registry key
    CPPUNIT_ASSERT(! AppSecInc::Registry::KeyExists(HKEY_LOCAL_MACHINE, path));
	AppSecInc::Registry::CopyBranch(
		HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\NET Framework Setup", 
		HKEY_LOCAL_MACHINE, path);

	msiInstall.SetProperty(L"REGISTRY_ROOT", L"HKEY_LOCAL_MACHINE");
	msiInstall.SetProperty(L"REGISTRY_PATH", path);
	msiInstall.SetProperty(L"REGISTRY_NAME", L"");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Registry_KeyExists"));
	CPPUNIT_ASSERT(L"true" == msiInstall.GetProperty(L"REGISTRY_KEY_EXISTS"));
   
	msiInstall.SetProperty(L"REGISTRY_ROOT", L"HKEY_LOCAL_MACHINE");
	msiInstall.SetProperty(L"REGISTRY_PATH", (path + L"\\NDP\\v2.0.50727"));
	msiInstall.SetProperty(L"REGISTRY_NAME", L"Version");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Registry_KeyExists"));
	CPPUNIT_ASSERT(L"true" == msiInstall.GetProperty(L"REGISTRY_KEY_EXISTS"));

    msiInstall.SetProperty(L"REGISTRY_ROOT", L"HKEY_LOCAL_MACHINE");
	msiInstall.SetProperty(L"REGISTRY_PATH", (path + L"\\NDP\\v2.0.50727\\" + guid));
	msiInstall.SetProperty(L"REGISTRY_NAME", L"");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Registry_KeyExists"));
	CPPUNIT_ASSERT(L"false" == msiInstall.GetProperty(L"REGISTRY_KEY_EXISTS"));
    
    msiInstall.SetProperty(L"REGISTRY_ROOT", L"HKEY_LOCAL_MACHINE");
	msiInstall.SetProperty(L"REGISTRY_PATH", (path + L"\\NDP\\v2.0.50727\\" + guid));
	msiInstall.SetProperty(L"REGISTRY_NAME", guid);
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Registry_KeyExists"));
	CPPUNIT_ASSERT(L"false" == msiInstall.GetProperty(L"REGISTRY_KEY_EXISTS"));
    
	AppSecInc::Registry::DeleteBranch(HKEY_LOCAL_MACHINE, path);	
	CPPUNIT_ASSERT(! AppSecInc::Registry::KeyExists(HKEY_LOCAL_MACHINE, path));
}

void RegistryImplUnitTests::Test_Registry_Copy()
{
    AppSecInc::Msi::MsiShim hInstall;
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_SystemToolsUnitTests", L"Component.idt");
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_SystemToolsUnitTests", L"Registry.idt");
    hInstall.Import(AppSecInc::File::GetModuleDirectoryW() + L"\\TestData_SystemToolsUnitTests", L"RegistryCopy.idt");

	MsiInstall msiInstall(hInstall);
	msiInstall.SetProperty(L"RegistryBackupComponent_Installed", AppSecInc::StringUtils::toWString(INSTALLSTATE_ABSENT));
	msiInstall.SetProperty(L"RegistryBackupComponent_Action", AppSecInc::StringUtils::toWString(INSTALLSTATE_LOCAL));

	// this test copies a known registry hive to a new GUID-based location
	std::wstring registry_guid = AppSecInc::Com::GenerateGUIDStringW();
	msiInstall.SetProperty(L"GUID", registry_guid);

    // execute the immediate CA that processes the RegistryCopy table and sets deferred properties
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_RegistryCopy_Immediate"));
    AppSecInc::Xml::XmlDocument deferred_xml;
    deferred_xml.LoadXml(msiInstall.GetProperty(L"Win32_RegistryCopy_Deferred_Install"));
	// std::wcout << std::endl << deferred_xml.GetXml();

    // there's 1 copy to process
    CPPUNIT_ASSERT(1 == deferred_xml.SelectNodes(L"//RegistryKeyCopy")->length);
    // there's 1 row that is going to be executed
    CPPUNIT_ASSERT(1 == deferred_xml.SelectNodes(L"//RegistryKeyCopy[@copy='true']")->length);
    CPPUNIT_ASSERT(0 == deferred_xml.SelectNodes(L"//RegistryKeyCopy[@copy='false']")->length);

	// execute the deferred CA
    msiInstall.SetProperty(L"CustomActionData", deferred_xml.GetXml());
    CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_RegistryCopy_Deferred"));
	std::wstring target_registry_key = L"SOFTWARE\\AppSecInc\\" + registry_guid;
	std::wcout << std::endl << L"Registry key copy: " << target_registry_key;
	CPPUNIT_ASSERT(AppSecInc::Registry::KeyExists(HKEY_LOCAL_MACHINE, target_registry_key));
	AppSecInc::Registry::DeleteBranch(HKEY_LOCAL_MACHINE, target_registry_key);
}