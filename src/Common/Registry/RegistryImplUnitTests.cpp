#include "StdAfxUnitTests.h"
#include "RegistryImplUnitTests.h"
#include "Registry.h"

using namespace AppSecInc::UnitTests::Registry;

CPPUNIT_TEST_SUITE_REGISTRATION(RegistryUnitTests);

void RegistryUnitTests::testGetStringValue()
{
	std::wstring version = AppSecInc::Registry::GetStringValue(HKEY_LOCAL_MACHINE, 
		L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v2.0.50727", L"Version");
	std::wcout << std::endl << ".NET 2.0 version: " << version;
	CPPUNIT_ASSERT(StringUtils::startsWith(version, L"2."));
}

void RegistryUnitTests::testCopyDeleteBranch()
{
    std::wstring _guid = AppSecInc::Com::GenerateGUIDStringW();
	std::wstring basepath = L"SOFTWARE\\UNITTEST\\";
	std::wstring path = basepath + _guid;

	// copy a well known registry hive
	AppSecInc::Registry::CopyBranch(
		HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\NET Framework Setup", 
		HKEY_LOCAL_MACHINE, path);

	// compare a value from the original branch with a value from the copied branch
	std::wstring originalValue = AppSecInc::Registry::GetStringValue(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v2.0.50727", L"Version");
	std::wstring copiedValue = AppSecInc::Registry::GetStringValue(HKEY_LOCAL_MACHINE, path + L"\\NDP\\v2.0.50727", L"Version");
	CPPUNIT_ASSERT(originalValue == copiedValue);
	
	// Testing nested copy and paste where the target is below the source.
	// No infinite trees should be created.	
	AppSecInc::Registry::CopyBranch(
		HKEY_LOCAL_MACHINE, path,  
		HKEY_LOCAL_MACHINE, path + L"\\" + _guid + L"_backup");

	// compare a value from the original branch with a value from the copied branch
	originalValue = AppSecInc::Registry::GetStringValue(HKEY_LOCAL_MACHINE, path + L"\\NDP\\v2.0.50727", L"Version");
	copiedValue = AppSecInc::Registry::GetStringValue(HKEY_LOCAL_MACHINE, path + L"\\" + _guid + L"_backup" + L"\\NDP\\v2.0.50727", L"Version");
	CPPUNIT_ASSERT(originalValue == copiedValue);

	// check for inifinite tree
	CPPUNIT_ASSERT(! AppSecInc::Registry::KeyExists(HKEY_LOCAL_MACHINE, (path + L"\\" + _guid + L"_backup\\" + _guid + L"_backup")));	
	
	// delete the copied branch
	AppSecInc::Registry::DeleteBranch(HKEY_LOCAL_MACHINE, basepath);
    CPPUNIT_ASSERT(! AppSecInc::Registry::KeyExists(HKEY_LOCAL_MACHINE, basepath));
}

void RegistryUnitTests::testKeyExists()
{
    std::wstring guid = AppSecInc::Com::GenerateGUIDStringW();
    std::wstring path = L"SOFTWARE\\" + guid;
	// copy a well known registry key
    CPPUNIT_ASSERT(! AppSecInc::Registry::KeyExists(HKEY_LOCAL_MACHINE, path));
	AppSecInc::Registry::CopyBranch(
		HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\NET Framework Setup", 
		HKEY_LOCAL_MACHINE, path);
    CPPUNIT_ASSERT(AppSecInc::Registry::KeyExists(HKEY_LOCAL_MACHINE, path));
    CPPUNIT_ASSERT(AppSecInc::Registry::KeyExists(HKEY_LOCAL_MACHINE, path + L"\\NDP\\v2.0.50727"));
    CPPUNIT_ASSERT(AppSecInc::Registry::KeyExists(HKEY_LOCAL_MACHINE, path + L"\\NDP\\v2.0.50727", L"Version"));
    CPPUNIT_ASSERT(AppSecInc::Registry::KeyExists(HKEY_LOCAL_MACHINE, path + L"\\NDP\\v2.0.50727", L""));
    CPPUNIT_ASSERT(! AppSecInc::Registry::KeyExists(HKEY_LOCAL_MACHINE, path + L"\\NDP\\v2.0.50727\\" + guid, L""));
    CPPUNIT_ASSERT(! AppSecInc::Registry::KeyExists(HKEY_LOCAL_MACHINE, path + L"\\NDP\\v2.0.50727", guid));
    AppSecInc::Registry::DeleteBranch(HKEY_LOCAL_MACHINE, path);
}

void RegistryUnitTests::testCreateKey()
{
	std::wstring _guid = AppSecInc::Com::GenerateGUIDStringW();
	std::wstring path = L"SOFTWARE\\UNITTEST\\" + _guid;	
	
	AppSecInc::Registry::CreateKey(HKEY_LOCAL_MACHINE, path);
	CPPUNIT_ASSERT( AppSecInc::Registry::KeyExists(HKEY_LOCAL_MACHINE, path));

	AppSecInc::Registry::DeleteBranch(HKEY_LOCAL_MACHINE, L"SOFTWARE\\UNITTEST");
    CPPUNIT_ASSERT(! AppSecInc::Registry::KeyExists(HKEY_LOCAL_MACHINE, L"SOFTWARE\\UNITTEST"));
}

void RegistryUnitTests::testSetStringValue()
{
	std::wstring _guid = AppSecInc::Com::GenerateGUIDStringW();
	std::wstring path = L"SOFTWARE\\UNITTEST\\" + _guid;
	
	AppSecInc::Registry::CreateKey(HKEY_LOCAL_MACHINE, path);
	CPPUNIT_ASSERT( AppSecInc::Registry::KeyExists(HKEY_LOCAL_MACHINE, path));
	
	// Test with values
	std::wstring name = L"Developer";
	std::wstring value = L"abc";

	AppSecInc::Registry::SetStringValue(HKEY_LOCAL_MACHINE, path, name, value);
	std::wstring regvalue = AppSecInc::Registry::GetStringValue(HKEY_LOCAL_MACHINE, path, name);
	CPPUNIT_ASSERT(regvalue == value);

	// Test empty value
	name = L"Blank";
	value = L"";
	
	AppSecInc::Registry::SetStringValue(HKEY_LOCAL_MACHINE, path, name, value);
	regvalue = AppSecInc::Registry::GetStringValue(HKEY_LOCAL_MACHINE, path, name);
	CPPUNIT_ASSERT(regvalue == value);

	AppSecInc::Registry::DeleteBranch(HKEY_LOCAL_MACHINE, L"SOFTWARE\\UNITTEST");
    CPPUNIT_ASSERT(! AppSecInc::Registry::KeyExists(HKEY_LOCAL_MACHINE, L"SOFTWARE\\UNITTEST"));
}
