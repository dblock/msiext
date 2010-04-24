#include "StdAfxUnitTests.h"
#include "ComImplUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::Win32::ComImplUnitTests);

using namespace AppSecInc::Msi;
using namespace AppSecInc::UnitTests::Win32;

void ComImplUnitTests::Test_Win32_GenerateGuidString()
{
	AppSecInc::Msi::MsiShim hInstall;
    MsiInstall msiInstall(hInstall);
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_GenerateGuidString"));
	std::wstring guid1 = msiInstall.GetProperty(L"WIN32_GUID_STRING");
	CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_GenerateGuidString"));
	std::wstring guid2 = msiInstall.GetProperty(L"WIN32_GUID_STRING");
	CPPUNIT_ASSERT(guid1 != guid2);
	CPPUNIT_ASSERT(AppSecInc::Com::IsValidGUID(guid1));
	CPPUNIT_ASSERT(AppSecInc::Com::IsValidGUID(guid2));
}

void ComImplUnitTests::Test_Win32_IsValidGuid()
{
	typedef struct
	{
		LPCWSTR guid;
		LPCWSTR expected_result;
	} TestData;

	TestData data[] = 
	{
		{ L"", L"0" },
		{ L"a", L"0" },
		{ L"Some.Nonsense", L"0" },
		{ L"{13709620-C279-11CE-A49E-444553540000}", L"1" },
		{ L"EAB22AC3-30C1-11CF-A7EB-0000C05BAE0B", L"0" }
	};

	AppSecInc::Msi::MsiShim hInstall;
	MsiInstall msiInstall(hInstall);

	for(int i = 0; i < ARRAYSIZE(data); i++)
	{
		msiInstall.SetProperty(L"WIN32_GUID_STRING", data[i].guid);
		CPPUNIT_ASSERT(ERROR_SUCCESS == hInstall.ExecuteCA(L"SystemTools.dll", L"Win32_IsValidGuid"));
		std::wstring valid = msiInstall.GetProperty(L"WIN32_GUID_VALID");
		CPPUNIT_ASSERT(valid == data[i].expected_result);
	}
}

void ComImplUnitTests::Test_EntryPoints()
{
	HMODULE h = ::LoadLibrary(L"SystemTools.dll");
	CPPUNIT_ASSERT_MESSAGE("Missing SystemTools.dll", h != NULL);
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Win32_GenerateGuidString"));
	CPPUNIT_ASSERT(NULL != GetProcAddress(h, "Win32_IsValidGuid"));
	::FreeLibrary(h);
}
