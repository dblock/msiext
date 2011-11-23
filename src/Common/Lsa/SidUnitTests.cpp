#include "StdAfxUnitTests.h"
#include "SidUnitTests.h"
#include "Sid.h"

using namespace AppSecInc::LSA;
using namespace AppSecInc::UnitTests::LSA;

CPPUNIT_TEST_SUITE_REGISTRATION(SidUnitTests);

void SidUnitTests::testSidConstructorsAndOperators()
{
	std::wstring sid_administrators_s(L"S-1-5-32-544");
	Sid sid_administrators(sid_administrators_s, SidTypeGroup);
	CPPUNIT_ASSERT(sid_administrators.GetUse() == SidTypeGroup);
	CPPUNIT_ASSERT(sid_administrators.ToString() == sid_administrators_s);
	Sid sid_copy(sid_administrators);
	CPPUNIT_ASSERT(sid_copy.GetUse() == SidTypeGroup);
	CPPUNIT_ASSERT(sid_copy.ToString() == sid_administrators_s);
	Sid sid_bytes(sid_administrators.GetPSID(), sid_administrators.GetUse());
	CPPUNIT_ASSERT(sid_bytes.GetUse() == SidTypeGroup);
	CPPUNIT_ASSERT(sid_bytes.ToString() == sid_administrators_s);
	CPPUNIT_ASSERT(sid_administrators == sid_copy);
	CPPUNIT_ASSERT(sid_administrators == sid_bytes);
}

void SidUnitTests::testSidToString()
{
	struct TestData
	{
		LPCWSTR sid;
	};

	LPCWSTR testdata[] = 
	{
		{ L"S-1-5-32-545" }, // Users
		{ L"S-1-5-32-544" }, // Administrators
	};

	for (int i = 0; i < ARRAYSIZE(testdata); i++)
	{
		AppSecInc::LSA::Sid sid(testdata[i]);
		std::wcout << std::endl << testdata[i] << L" => " << sid.GetLength() << " byte(s)";
		CPPUNIT_ASSERT(::GetLengthSid(sid.GetPSID()) == sid.GetLength());
		CPPUNIT_ASSERT(testdata[i] == sid.ToString());
	}
}

void SidUnitTests::testSidToHexString()
{
	struct TestData
	{
		LPCWSTR sid;
	};

	LPCWSTR testdata[] = 
	{
		{ L"S-1-5-32-545" }, // Users
		{ L"S-1-5-32-544" }, // Administrators
	};

	LPCWSTR testresults[] = 
	{
		{L"0x01020000000000052000000021020000"}, //Users
		{L"0x01020000000000052000000020020000"}, //Administrators
	};

	for (int i = 0; i < ARRAYSIZE(testdata); i++)
	{
		AppSecInc::LSA::Sid sid(testdata[i]);
		std::wcout << std::endl << testdata[i] << L" => " << sid.GetLength() << " byte(s)";
		CPPUNIT_ASSERT(::GetLengthSid(sid.GetPSID()) == sid.GetLength());
		CPPUNIT_ASSERT(testresults[i] == sid.ToHexString());
	}
}
