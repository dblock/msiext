#include "StdAfxUnitTests.h"
#include "DnsUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::TcpIp::DNS::DnsUnitTests);

using namespace AppSecInc::UnitTests::TcpIp::DNS;

void DnsUnitTests::testGetHostByAddress()
{
	AppSecInc::TcpIp::CWSAStartup wsa;

	struct TestData
	{
		LPCSTR ip;
		LPCSTR host;
	};

	TestData testdata[] = 
	{
		{ "207.97.227.239", "github.com" }
	};

	for (int i = 0; i < ARRAYSIZE(testdata); i++)
	{		
		std::string host = AppSecInc::TcpIp::DNS::GetHostByAddress(testdata[i].ip);
		std::cout << std::endl << testdata[i].ip << " -> " << host;
		CPPUNIT_ASSERT(host == testdata[i].host);
	}
}

void DnsUnitTests::testGetHostByInvalidAddress()
{
	AppSecInc::TcpIp::CWSAStartup wsa;

	LPCSTR testdata[] =
	{
		{ "abcdefgh" },
	};

	for (int i = 0; i < ARRAYSIZE(testdata); i++)
	{	
		try
		{
			AppSecInc::TcpIp::DNS::GetHostByAddress(testdata[i]);
			throw "Expected std::exception";
		}
		catch(std::exception& ex)
		{
			std::cout << std::endl << "Expected exception for " << testdata[i] << ": " << ex.what();
		}
	}
}

void DnsUnitTests::testGetHostByName()
{
	AppSecInc::TcpIp::CWSAStartup wsa;

	struct TestData
	{
		LPCSTR ip;
		LPCSTR host;
	};

	TestData testdata[] = 
	{
		{ "207.97.227.239", "github.com" },
		{ "www.codeplex.com", "lb.codeplex.com.microsoft.akadns.net" },
	};

	for (int i = 0; i < ARRAYSIZE(testdata); i++)
	{		
		std::string host = AppSecInc::TcpIp::DNS::GetHostByName(testdata[i].ip);
		std::cout << std::endl << testdata[i].ip << " -> " << host;
		CPPUNIT_ASSERT(host == testdata[i].host);
	}
}

void DnsUnitTests::testGetHostIpAddresses()
{
	AppSecInc::TcpIp::CWSAStartup wsa;

	struct TestData
	{
		LPCSTR host;
		LPCSTR ip;
	};

	TestData testdata[] = 
	{
		{ "207.97.227.239", "207.97.227.239" },
		{ "www.github.com", "207.97.227.239" },
	};

	for (int i = 0; i < ARRAYSIZE(testdata); i++)
	{		
		std::string ip = AppSecInc::TcpIp::DNS::GetHostIpAddresses(testdata[i].ip)[0];
		std::cout << std::endl << testdata[i].host << " -> " << ip;
		CPPUNIT_ASSERT(ip == testdata[i].ip);
	}
}

void DnsUnitTests::testGetHostInfo()
{
	AppSecInc::TcpIp::CWSAStartup wsa;

	struct TestData
	{
		LPCSTR host;
		LPCSTR hostname; // expected host name
	};

	TestData testdata[] = 
	{
		{ "www.codeplex.com", "lb.codeplex.com.microsoft.akadns.net" },
	};

	for (int i = 0; i < ARRAYSIZE(testdata); i++)
	{		
		std::string hostname;
		std::vector<std::string> aliases;
		std::vector<std::string> addresses;
		AppSecInc::TcpIp::DNS::GetHostInfo(testdata[i].host, hostname, aliases, addresses);

		std::cout << std::endl << testdata[i].host << " -> " << hostname;
		CPPUNIT_ASSERT(hostname == testdata[i].hostname);

		for each (const std::string& alias in aliases)
			std::cout << std::endl << " alias: " << alias;

		for each (const std::string& address in addresses)
			std::cout << std::endl << " address: " << address;
	}
}

void DnsUnitTests::testGetLocal()
{
	AppSecInc::TcpIp::CWSAStartup wsa;

	std::wstring computername = AppSecInc::TcpIp::NetBIOS::GetComputerName();
	std::wcout << std::endl << L"Host: " << computername;

	std::wstring tcpaddress = AppSecInc::TcpIp::DNS::GetHostIpAddresses(computername)[0];
	std::wcout << std::endl << L"Ip: " << tcpaddress;
	CPPUNIT_ASSERT(! tcpaddress.empty());

	std::wstring host = AppSecInc::TcpIp::DNS::GetHostByName(computername);
	std::wcout << std::endl << L"Host: " << host;
	CPPUNIT_ASSERT(! host.empty());
}

void DnsUnitTests::testGetHostName()
{
	std::wstring computername = AppSecInc::TcpIp::NetBIOS::GetComputerName();
	std::wcout << std::endl << L"Computer: " << computername;
    std::wstring hostname = AppSecInc::TcpIp::DNS::GetHostNameW();
	std::wcout << std::endl << L"Host: " << hostname;    
    CPPUNIT_ASSERT(computername == hostname);
}

void DnsUnitTests::testIsIpAddress()
{
	AppSecInc::TcpIp::CWSAStartup wsa;

	struct TestData
	{
		LPCSTR ip;
		bool isIp; // expected true/false
	};

	TestData testdata[] = 
	{
		{ "", false },
		{ "127.0.0.1", true },
		{ "localhost", false },
		{ "0", false },
		{ "192.168.0.1", true },
		{ "10.10.10.10", true },
		{ "fe80::8081:ade5:e522:4a3c%14", false }, // IPv6 is not supported by this function
	};

	for (int i = 0; i < ARRAYSIZE(testdata); i++)
	{		
		bool ip = AppSecInc::TcpIp::DNS::IsIpAddress(testdata[i].ip);
		std::cout << std::endl << testdata[i].ip << " -> " << (ip ? "ip" : "not ip");
		CPPUNIT_ASSERT(ip == testdata[i].isIp);
	}
}