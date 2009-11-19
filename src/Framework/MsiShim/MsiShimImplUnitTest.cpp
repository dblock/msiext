#include "StdAfxUnitTests.h"
#include "MsiShim.h"
#include "MsiShimImplUnitTest.h"
#include <Msi/MsiHandle.h>

using namespace AppSecInc;
using namespace AppSecInc::UnitTests;
using namespace AppSecInc::UnitTests::MsiShim;

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::MsiShim::MsiShimUnitTest);

void MsiShimUnitTest::RecordTest()
{
	// Create a record and print it
	MsiHandle hRecord(MsiCreateRecord(2));
	CPPUNIT_ASSERT(ERROR_SUCCESS == MsiRecordSetString(hRecord, 0, L"The answer to [1] is [2]"));
	CPPUNIT_ASSERT(ERROR_SUCCESS == MsiRecordSetInteger(hRecord, 2, 42));
	CPPUNIT_ASSERT(ERROR_SUCCESS == MsiRecordSetString(hRecord, 1, L"life the universe and everything"));

	// Make sure an incorrect field number returns the right error code
	CPPUNIT_ASSERT(ERROR_SUCCESS != MsiRecordSetString(hRecord, 3, L"This won't work"));
	
	// To display the record, we need a package handle, so allocate one and print it.
    AppSecInc::Msi::MsiShim shim;
	CPPUNIT_ASSERT(ERROR_SUCCESS == MsiProcessMessage(shim, INSTALLMESSAGE_INFO, hRecord));
}

void MsiShimUnitTest::PropertiesTest()
{
    AppSecInc::Msi::MsiShim shim;

	// Add three values. We'll reuse the first one, so just point to the string literal.
	const wchar_t *value1    = L"value1";
	const wchar_t *property1 = L"property1";
	CPPUNIT_ASSERT(ERROR_SUCCESS == MsiSetProperty(shim, property1, value1));
	CPPUNIT_ASSERT(ERROR_SUCCESS == MsiSetProperty(shim, L"property2", L"value2"));
	CPPUNIT_ASSERT(ERROR_SUCCESS == MsiSetProperty(shim, L"property3", L"value3"));

	// Test getting a property: that the return value and length are what we expect
	wchar_t buf[100] = L"garbage";
	DWORD len = 0;
	CPPUNIT_ASSERT(ERROR_MORE_DATA == MsiGetProperty(shim, property1, L"", &len));
	CPPUNIT_ASSERT(wcslen(value1) == len);
    std::cout << std::endl << "Data length: " << len;

    len++;
	CPPUNIT_ASSERT(ERROR_SUCCESS == MsiGetProperty(shim, property1, buf, & len));
	CPPUNIT_ASSERT(wcslen(value1) == len);
	CPPUNIT_ASSERT(0 == wcscmp(value1, buf));

	len = ARRAYSIZE(buf) - 1;
	CPPUNIT_ASSERT(ERROR_SUCCESS == MsiGetProperty(shim, property1, buf, &len));
	CPPUNIT_ASSERT(wcslen(value1) == len);
	CPPUNIT_ASSERT(0 == wcscmp(value1, buf));

	// Parameter error occurs with bad handle, empty name, or NULL for length.
	len = ARRAYSIZE(buf) - 1;
	CPPUNIT_ASSERT(ERROR_INVALID_PARAMETER == MsiGetProperty(shim, NULL, buf, &len));
	CPPUNIT_ASSERT(ERROR_INVALID_PARAMETER == MsiGetProperty(shim, property1, buf, NULL));

	// Setting a property to NULL or L"" removes it.
	// To check, we'll have to get the map again--Properties() returns a copy.
	CPPUNIT_ASSERT(ERROR_SUCCESS == MsiSetProperty(shim, L"property2", NULL));
	//m = shim.Properties();
	//CPPUNIT_ASSERT(2 == m.size());

	// A property that doesn't exist returns an empty string, but doesn't become a new property.
	len = 1;
	//! \todo Should this return ERROR_MORE_DATA or bad parameter or just write an empty string?
	CPPUNIT_ASSERT(ERROR_SUCCESS == MsiGetProperty(shim, L"property7", buf, &len));
	CPPUNIT_ASSERT(0 == len);
	CPPUNIT_ASSERT(0 == wcscmp(L"", buf));
}

void MsiShimUnitTest::TwoInstallationsTest()
{
    AppSecInc::Msi::MsiShim one;

    try
    {
        AppSecInc::Msi::MsiShim other;
    }
    catch(std::exception& ex)
    {
        std::cout << std::endl << ex.what();
    }
}