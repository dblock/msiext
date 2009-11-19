#include "StdAfxUnitTests.h"
#include "SocketUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AppSecInc::UnitTests::TcpIp::SocketUnitTest);

using namespace AppSecInc::UnitTests;
using namespace AppSecInc::UnitTests::TcpIp;

void SocketUnitTest::testConstructorDestructor()
{
	AppSecInc::TcpIp::Sockets::Socket sock;

	{
		AppSecInc::TcpIp::Sockets::Socket * p = new AppSecInc::TcpIp::Sockets::Socket();
		delete p;
	}
}

void SocketUnitTest::testOptions()
{
	AppSecInc::TcpIp::CWSAStartup wsa;
	AppSecInc::TcpIp::Sockets::Socket sock;
	std::wstring ip = AppSecInc::TcpIp::DNS::GetHostIpAddresses(L"www.codeplex.com")[0];
	std::wcout << std::endl << "Connecting: " << ip;
	sock.Connect(ip, 80);
	sock.SetHardClose();
	sock.SetGracefulClose();
	sock.Disconnect();
}

void SocketUnitTest::testConnectDisconnectValidHost()
{
	AppSecInc::TcpIp::CWSAStartup wsa;
	std::wstring ip = AppSecInc::TcpIp::DNS::GetHostIpAddresses(L"www.codeplex.com")[0];
	int port = 80;

	AppSecInc::TcpIp::Sockets::Socket sock;
	CPPUNIT_ASSERT_MESSAGE("Socket should not be created.", ! sock.IsCreated());
	CPPUNIT_ASSERT_MESSAGE("Socket should be disconnected.", ! sock.IsConnected());
	sock.Connect(ip, port);
	CPPUNIT_ASSERT_MESSAGE("Socket should be created.", sock.IsCreated());
	CPPUNIT_ASSERT_MESSAGE("Socket should be connected.", sock.IsConnected());
	sock.Disconnect();
	CPPUNIT_ASSERT_MESSAGE("Socket should not be created.", ! sock.IsCreated());
	CPPUNIT_ASSERT_MESSAGE("Socket should be disconnected.", ! sock.IsConnected());
}

void SocketUnitTest::testConnectDisconnectInvalidHost()
{
	AppSecInc::TcpIp::CWSAStartup wsa;
	AppSecInc::TcpIp::Sockets::Socket sock;
	CPPUNIT_ASSERT_MESSAGE("Socket should not be created.", ! sock.IsCreated());
	CPPUNIT_ASSERT_MESSAGE("Socket should be disconnected.", ! sock.IsConnected());
	try
	{
		sock.Connect("1.2.3.4", 444);
		throw "expected exception";
	}
	catch(std::exception&) { }
	CPPUNIT_ASSERT_MESSAGE("Socket should still be created.", sock.IsCreated());
	CPPUNIT_ASSERT_MESSAGE("Socket should be disconnected.", ! sock.IsConnected());
}

void SocketUnitTest::testError()
{
	AppSecInc::TcpIp::CWSAStartup wsa;
	AppSecInc::TcpIp::Sockets::Socket sock;
	CPPUNIT_ASSERT(sock.GetError() == 0);
	try
	{
		sock.Connect("1.2.3.4", 444);
		throw "expected exception";
	}
	catch(std::exception&) { }
	CPPUNIT_ASSERT(sock.GetError() == WSAETIMEDOUT);
}

void SocketUnitTest::testReconnect()
{	
	AppSecInc::TcpIp::CWSAStartup wsa;
	AppSecInc::TcpIp::Sockets::Socket sock;

	for (int i = 1; i <= 2; i++)
	{
		std::cout << std::endl << "Retry attempt: " << i;
		try
		{
			sock.Connect("1.2.3.4", 444);
			throw "expected exception";
		}
		catch(std::exception&) { }
		CPPUNIT_ASSERT(sock.GetError() == WSAETIMEDOUT);
	}
}

void SocketUnitTest::testBind()
{
	typedef struct  
	{
		std::string testIP;
		unsigned int testPort;
	} TestData;

	TestData testData[] = 
	{
		{ "127.0.0.1", 46544 },
		{ "127.0.0.1", 12333 },
		{ "127.0.0.1", 25499 },
		{ "127.0.0.1", 31112 }
	};

	AppSecInc::TcpIp::CWSAStartup wsa;
	for(unsigned int i = 0; i < ARRAYSIZE(testData); i++)
	{
		std::cout << std::endl << "Binding: " << testData[i].testIP << ":" << testData[i].testPort;
		AppSecInc::TcpIp::Sockets::Socket socket;
		socket.Bind(testData[i].testIP, testData[i].testPort);

		try
		{
			AppSecInc::TcpIp::Sockets::Socket socket2;
			socket2.Bind(testData[i].testIP, testData[i].testPort);
			throw "expected exception on second bind";
		} 
		catch (std::exception& ex) 
		{ 
			std::cout << std::endl << "Second bind: " << ex.what();
		} 
	}
}