#include "StdAfxUnitTests.h"
#include "ComUtilsUnitTests.h"
#include <AtlCom/ComUtils.h>

using namespace AppSecInc::UnitTests;
using namespace AppSecInc::UnitTests::AtlCom;

CPPUNIT_TEST_SUITE_REGISTRATION( 
	AppSecInc::UnitTests::AtlCom::ComUtilsUnitTest);

void ComUtilsUnitTest::testCLSIDFrom()
{
	typedef struct
	{
		LPCSTR pszProgID;
		LPCSTR pszGuid;
		IID clsid;
	} TestData;

	TestData data[] = 
	{
		"Shell.Application.1", "{13709620-C279-11CE-A49E-444553540000}",
			{ 0x13709620, 0xC279, 0x11CE, { 0xA4, 0x9E, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00 } },
		"Shell.Explorer.1", "{EAB22AC3-30C1-11CF-A7EB-0000C05BAE0B}",
			{ 0xEAB22AC3, 0x30C1, 0x11CF, { 0xA7, 0xEB, 0x00, 0x00, 0xC0, 0x5B, 0xAE, 0x0B } }
	};

	// fails for a nonsense prog id
	try
	{
		CLSID clsid = AppSecInc::Com::CLSIDFromProgID("Some.Nonsense");
		throw "Expected exception";
	}
    catch(std::exception&)
	{
	}

	// works for any GUID
	CLSID clsid = AppSecInc::Com::CLSIDFromString("{6AF33B6F-DAF6-49aa-A597-AFE1E741D60C}");

	for (int i = 0; i < ARRAYSIZE(data); i++)
	{
		std::cout << std::endl << data[i].pszProgID << " " << data[i].pszGuid;
		
		CLSID clsid_fromprogid = AppSecInc::Com::CLSIDFromProgID(data[i].pszProgID);
		CPPUNIT_ASSERT(memcmp(& clsid_fromprogid, & data[i].clsid, sizeof(CLSID)) == 0);

		CLSID clsid_fromstring = AppSecInc::Com::CLSIDFromString(data[i].pszGuid);
		CPPUNIT_ASSERT(memcmp(& clsid_fromstring, & data[i].clsid, sizeof(CLSID)) == 0);

		CLSID iid_fromstring = AppSecInc::Com::IIDFromString(data[i].pszGuid);
		CPPUNIT_ASSERT(memcmp(& iid_fromstring, & data[i].clsid, sizeof(IID)) == 0);

		std::string progid_fromclsid = AppSecInc::Com::ProgIDFromCLSIDA(clsid_fromprogid);
		CPPUNIT_ASSERT(progid_fromclsid == data[i].pszProgID);		

		std::string string_fromclsid = AppSecInc::Com::StringFromCLSIDA(clsid_fromstring);
		CPPUNIT_ASSERT(string_fromclsid == data[i].pszGuid);		

		std::string string_fromguid2 = AppSecInc::Com::StringFromGUID2A(clsid_fromstring);
		CPPUNIT_ASSERT(string_fromguid2 == data[i].pszGuid);		

		std::string string_fromiid = AppSecInc::Com::StringFromIIDA(clsid_fromstring);
		CPPUNIT_ASSERT(string_fromiid == data[i].pszGuid);
	}
}
