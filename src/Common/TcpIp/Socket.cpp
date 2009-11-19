#include "StdAfx.h"
#include "Socket.h"

using namespace AppSecInc::TcpIp::Sockets;

Socket::Socket()
	: m_socket(INVALID_SOCKET)
	, m_error(0)
	, m_connected(false)
{

}

Socket::~Socket()
{
	if (m_socket != INVALID_SOCKET)
	{
		InternalClose();
	}
}

void Socket::InternalShutdown(int how)
{
	ATLASSERT(INVALID_SOCKET != m_socket);
	CHECK_BOOL(INVALID_SOCKET != m_socket, L"Invalid socket for InternalShutdown.");

	CHECK_BOOL(0 == ::shutdown(m_socket, how),
		L"Error in InternalShutdown: " << CWSAStartup::ErrorMessage(m_error = WSAGetLastError()));
}

void Socket::InternalSetSockOpt(int level, int optname, const char * optval, int optlen)
{
	ATLASSERT(INVALID_SOCKET != m_socket);
	CHECK_BOOL(INVALID_SOCKET != m_socket, L"Invalid socket for InternalSetSockOpt.");

	CHECK_BOOL(0 == ::setsockopt(m_socket, level, optname, optval, optlen),
		L"Error in InternalSetSockOpt: " << CWSAStartup::ErrorMessage(m_error = WSAGetLastError()));
}

void Socket::InternalIoCtlSocket(long cmd, u_long * argp)
{
	ATLASSERT(INVALID_SOCKET != m_socket);
	CHECK_BOOL(INVALID_SOCKET != m_socket, L"Invalid socket for InternalIoCtlSocket.");

	CHECK_BOOL(0 == ::ioctlsocket(m_socket, cmd, argp),
		L"Error in InternalIoCtlSocket: " << CWSAStartup::ErrorMessage(m_error = WSAGetLastError()));
}

void Socket::InternalClose()
{
	ATLASSERT(INVALID_SOCKET != m_socket);
	CHECK_BOOL(INVALID_SOCKET != m_socket, L"Invalid socket for InternalClose.");

	CHECK_BOOL(0 == ::closesocket(m_socket),
		L"Error in InternalClose: " << CWSAStartup::ErrorMessage(m_error = WSAGetLastError()));

	m_socket = INVALID_SOCKET;
}

void Socket::SetHardClose(unsigned short timeout)
{
	linger opt = { 1, timeout };
	InternalSetSockOpt(SOL_SOCKET, SO_LINGER, (const char *) & opt, sizeof(opt));
}

void Socket::SetGracefulClose()
{
	linger opt = { 0 };
	InternalSetSockOpt(SOL_SOCKET, SO_LINGER, (const char *) & opt, sizeof(opt));
}

void Socket::SetSocketReuse()
{
	int opt =  1 ;
	InternalSetSockOpt(SOL_SOCKET, SO_REUSEADDR, (const char *) & opt, sizeof(int));
}

void Socket::InternalCreate(int af, int type, int protocol, LPWSAPROTOCOL_INFO lpProtocolInfo, GROUP g, DWORD dwFlags)
{
	if (m_socket != INVALID_SOCKET)
	{
		InternalClose();
	}

	ATLASSERT(INVALID_SOCKET == m_socket);
	CHECK_BOOL(INVALID_SOCKET == m_socket, L"Invalid socket for InternalCreate.");

	CHECK_BOOL(INVALID_SOCKET != (m_socket = ::WSASocket(af, type, protocol, lpProtocolInfo, g, dwFlags)),
		L"Error in InternalCreate: " << CWSAStartup::ErrorMessage(m_error = WSAGetLastError()));
}

void Socket::InternalConnect(const struct sockaddr * name, int namelen, LPWSABUF lpCallerData, LPWSABUF lpCalleeData, LPQOS lpSQOS, LPQOS lpGQOS)
{
	ATLASSERT(INVALID_SOCKET != m_socket);
	ATLASSERT(false == m_connected);
	CHECK_BOOL(INVALID_SOCKET != m_socket, L"Invalid socket for InternalConnect.");

	CHECK_BOOL(0 == ::WSAConnect(m_socket, name, namelen, lpCallerData, lpCalleeData, lpSQOS, lpGQOS),
		L"Error in InternalConnect: " << CWSAStartup::ErrorMessage(m_error = WSAGetLastError()));

	m_connected = true;
}

void Socket::Connect(const std::wstring& ip_addr, unsigned port, int type, int protocol)
{
	Connect(AppSecInc::StringUtils::wc2mb(ip_addr), port, type, protocol);
}

void Socket::Connect(const std::string& ip_addr, unsigned port, int type, int protocol)
{
	InternalCreate(AF_INET, type, protocol, NULL, 0, 0);

	sockaddr_in	dest = { AF_INET, htons(port) };
	dest.sin_addr.S_un.S_addr = inet_addr( ip_addr.c_str() );

	InternalConnect(reinterpret_cast<struct sockaddr *>(& dest), sizeof(dest));
}

void Socket::Connect(const struct sockaddr * name, int namelen)
{
	InternalConnect(name, namelen);
}

void Socket::Disconnect()
{
	if (m_connected)
	{
		InternalShutdown(SD_SEND);

		// flush outstanding data
		std::vector<char> buffer(1024);
		DWORD dwReceived = 0;
		DWORD dwResult = 0;
		DWORD dwFlags = 0;
		do
		{
			WSABUF buf = { buffer.size(), & * buffer.begin() };
			dwResult = ::WSARecv(m_socket, & buf, 1, & dwReceived, & dwFlags, NULL, NULL);
		} while (dwReceived > 0 && dwResult == 0);

		m_connected = false;
	}

	InternalClose();
}

void Socket::Bind(const std::string& ip_addr, unsigned port, int type, int protocol)
{
	InternalCreate(AF_INET, type, protocol, NULL, 0, 0);

	sockaddr_in service;
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr(ip_addr.c_str());
	service.sin_port = htons(port);

	CHECK_BOOL(0 == ::bind(m_socket, (SOCKADDR *) & service, sizeof(service)),
		L"Error in bind: " << CWSAStartup::ErrorMessage(m_error = WSAGetLastError()));
}
