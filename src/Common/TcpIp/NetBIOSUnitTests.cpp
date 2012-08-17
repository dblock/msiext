#include "StdAfxUnitTests.h"
#include "NetBIOSUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::TcpIp::NetBIOS::NetBIOSUnitTests);

using namespace AppSecInc::UnitTests::TcpIp::NetBIOS;

void NetBIOSUnitTests::testGetComputerName()
{
	wchar_t computername_env[MAX_COMPUTERNAME_LENGTH + 1] = { 0 };
	::GetEnvironmentVariableW(L"COMPUTERNAME", computername_env, sizeof(computername_env));
	std::wcout << std::endl << L"Computer name from environment: " << computername_env;
	std::wstring computername = AppSecInc::TcpIp::NetBIOS::GetComputerName();
	std::wcout << std::endl << L"Computer name from system: " << computername;
	CPPUNIT_ASSERT(wcslen(computername_env) == computername.length());
	CPPUNIT_ASSERT(computername == computername_env);
}
