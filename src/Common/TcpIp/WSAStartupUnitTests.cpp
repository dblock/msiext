#include "StdAfxUnitTests.h"
#include "WSAStartupUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::TcpIp::WSAStartupUnitTest);

using namespace AppSecInc::TcpIp;
using namespace AppSecInc::UnitTests;
using namespace AppSecInc::UnitTests::TcpIp;

WORD WSAStartupUnitTest::negotiateVersion(WORD version)
{
	WORD ret = 0;
	CWSAStartup wsa(version);
	if (wsa.initialized()) 
	{
		ret = wsa.negotiatedVersion();
	}
	return ret;
}

WORD WSAStartupUnitTest::highestSupportedVersion()
{
	CWSAStartup wsa(vdefault);
	return wsa.highestSupportedVersion();
}

bool WSAStartupUnitTest::supportsWinsock2(WORD version)
{
	CWSAStartup wsa(version);
	std::vector<WSAPROTOCOL_INFOA> protocols;
	DWORD dwLen = 0;
	WSAEnumProtocolsA(NULL, NULL, & dwLen);
	CPPUNIT_ASSERT(dwLen > 0);
	protocols.resize(dwLen / sizeof(WSAPROTOCOL_INFOA));
	int rc = WSAEnumProtocolsA(NULL, & * protocols.begin(), & dwLen);
	for each(WSAPROTOCOL_INFOA info in protocols)
	{
		std::cout << std::endl << info.szProtocol << ", version " << info.iVersion;
	}
	return (rc != SOCKET_ERROR);
}

///////////////////////////////////////////////////////////
// Unit Tests
///////////////////////////////////////////////////////////
void WSAStartupUnitTest::basicTest()
{
	// Make sure the default version can be initialized
	CWSAStartup wsa(vdefault);
	CPPUNIT_ASSERT(wsa.initialized());
	CPPUNIT_ASSERT(wsa.wasRequestedVersionNegotiated());
	CPPUNIT_ASSERT(vdefault == wsa.negotiatedVersion());

	// The error code should be 0. 
	// The error message is something like "The operation completed successfully."
	CPPUNIT_ASSERT(0 == wsa.ErrorCode());
	std::wstring msg = wsa.ErrorMessage();
	std::wcout << std::endl << L"Message: [" << msg << L"]";

	// Test version number functions
	BYTE bMajor = wsa.negotiatedMajorVersion();
	BYTE defaultMajor = CWSAStartup::majorVersion(vdefault);
	CPPUNIT_ASSERT(defaultMajor == bMajor);

	BYTE bMinor = wsa.negotiatedMinorVersion();
	BYTE defaultMinor = CWSAStartup::minorVersion(vdefault);
	CPPUNIT_ASSERT(defaultMinor == bMinor);

	WORD version = wsa.negotiatedVersion();
	CPPUNIT_ASSERT(vdefault == version);

	WORD defaultVersion = CWSAStartup::packVersion(wsa.negotiatedMajorVersion(), wsa.negotiatedMinorVersion());
	CPPUNIT_ASSERT(vdefault == defaultVersion);

	int iMajor, iMinor;
	wsa.negotiatedVersion(iMajor, iMinor);
	CPPUNIT_ASSERT(iMajor == defaultMajor);
	CPPUNIT_ASSERT(iMinor == defaultMinor);

	// Test highest supported version functions
	WORD wHigh = wsa.highestSupportedVersion();
	WORD wMajor, wMinor;
	wsa.highestSupportedVersion(wMajor, wMinor);
	wsa.highestSupportedVersion(iMajor, iMinor);
	CPPUNIT_ASSERT(wMajor == iMajor);
	CPPUNIT_ASSERT(wMinor == iMinor);
	WORD packed = CWSAStartup::packVersion(iMajor, iMinor);
	CPPUNIT_ASSERT(packed == wHigh);
	packed = CWSAStartup::packVersion(wMajor, wMinor);
	CPPUNIT_ASSERT(packed == wHigh);

	const int error = WSAEBADF;
	WSASetLastError(error);
	CPPUNIT_ASSERT(error == WSAGetLastError());
}

void WSAStartupUnitTest::simpleVersionTests()
{
	// Make sure the other reasonable versions can be initialized
	CPPUNIT_ASSERT(v21 == negotiateVersion(v21));
	CPPUNIT_ASSERT(v11 == negotiateVersion(v11));

	// Get the highest supported version for further tests
	WORD high = highestSupportedVersion();
	CPPUNIT_ASSERT(high == negotiateVersion(high));

	// Try a higher version than available. It should return the highest available version.
	int major = CWSAStartup::majorVersion(high);
	int minor = CWSAStartup::minorVersion(high);
	WORD toohigh = CWSAStartup::packVersion(major + 1, minor + 1);
	CWSAStartup wsa5(toohigh);
	CPPUNIT_ASSERT(high == negotiateVersion(toohigh));
	CPPUNIT_ASSERT(!wsa5.wasRequestedVersionNegotiated());

	// Try version 1.0 -- that old win 3.1 clunker
	CPPUNIT_ASSERT(v10 == negotiateVersion(v10));
}

void WSAStartupUnitTest::testNegotiation()
{
	// Winsock 2 is supported even though we negotiate for version 1.1.
	// This is because we linked to version 2.x, so the call is available if both
	// (1) the driver and (2) the headers and LIB we link to support the call.
	CWSAStartup wsa11(v11);
	CPPUNIT_ASSERT(supportsWinsock2(v11));

	CWSAStartup wsa21(v21);
	CPPUNIT_ASSERT(supportsWinsock2(v21));
}

void WSAStartupUnitTest::testUnloadedDriver()
{
	int rc = ::WSACleanup();
	if (SOCKET_ERROR == rc) 
	{
		int err = ::WSAGetLastError();
	}
}
