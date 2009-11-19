#include "StdAfxUnitTests.h"
#include "DirectoryServicesUnitTests.h"
#include "DirectoryServices.h"

using namespace AppSecInc::Net::DirectoryServices;
using namespace AppSecInc::UnitTests::Net;

CPPUNIT_TEST_SUITE_REGISTRATION(DirectoryServicesUnitTests);

void DirectoryServicesUnitTests::testGetJoinStatus()
{
	NetJoinStatus join_status = AppSecInc::Net::DirectoryServices::GetJoinStatus();
	std::wcout << std::endl << join_status.netbios_name << L" (" << join_status.join_status << L")";
	CPPUNIT_ASSERT(join_status.join_status != NetSetupUnknownStatus);
	CPPUNIT_ASSERT(join_status.netbios_name.length() > 0);
}
