#pragma once

/** \file Socket.h
	A basic blocking socket.
*/

namespace AppSecInc
{
	namespace TcpIp
	{
		namespace Sockets
		{
			/**	\class Socket
				\ingroup Communications
				\brief A basic blocking socket

				A basic blocking socket that is bound to a specific transport-service provider.
			*/
			class Socket
			{
			protected:
				SOCKET m_socket;
				int m_error;
				bool m_connected;
				//! Set a socket option.
				virtual void InternalSetSockOpt(int level, int optname, const char * optval, int optlen);
				//! Control socket IO.
				virtual void InternalIoCtlSocket(long cmd, u_long * argp);
				//! Create a socket. See WSASocket or ::socket for more information.
				virtual void InternalCreate(int af = AF_INET, int type = SOCK_STREAM, int protocol = IPPROTO_IP, LPWSAPROTOCOL_INFO lpProtocolInfo = NULL, GROUP g = NULL, DWORD dwFlags = 0);
				//! Connect a socket. See WSAConnect or ::connect for more information.
				virtual void InternalConnect(const struct sockaddr * name, int namelen, LPWSABUF lpCallerData = NULL, LPWSABUF lpCalleeData = NULL, LPQOS lpSQOS = NULL, LPQOS lpGQOS = NULL);
				//! Shutdown a socket.
				virtual void InternalShutdown(int how);
				//! Close a socket.
				virtual void InternalClose();
			public:
				//! Returns the error from any last failed operation on this socket, equivalent to calling WSAGetLastError().
				//! \note The error is not cleared on a successful operation.
				int GetError() const { return m_error; }
				//! Clear the error from the last failed operation on this socket
				void ClearError() { m_error = 0; }
				//! \deprecated Returns the socket handle. Provided for backwards compatibility only.
				SOCKET Peek() const { return m_socket; }
				//! Returns true if the socket has been created.
				bool IsCreated() const { return (m_socket != INVALID_SOCKET); }
				//! Returns true if the socket has been successfuly connected.
				bool IsConnected() const { return m_connected; }
				//! The select function determines the status of the socket, waiting if necessary, to perform synchronous I/O.
				void Select(bool read, bool write, bool except, const int timeout_in_seconds, bool& timed_out);
				//! Turn on the linger option. Closing a socket does not wait for for the session to breakdown, unless you have requested it by setting the linger socket option.
				void SetHardClose(unsigned short timeout = 0);
				//! Turn off the linger option. Closing a socket does not wait for for the session to breakdown, unless you have requested it by setting the linger socket option.
				void SetGracefulClose();
				//! Turn on the resue address option. Allows the socket to be bound to an address that is already in use. 
				void SetSocketReuse();
				//! Initialize the socket and connect to a destination. Defaults to TCP, specify SOCK_DGRAM for UDP. See WSASocket reference for more information.
				void Socket::Connect(const std::wstring& ip_addr, unsigned port, int type = SOCK_STREAM, int protocol = IPPROTO_IP);
				//! Initialize the socket and connect to a destination. Defaults to TCP, specify SOCK_DGRAM for UDP. See WSASocket reference for more information.
				void Connect(const std::string& ip_addr, unsigned port, int type = SOCK_STREAM, int protocol = IPPROTO_IP);
				//! \deprecated Initialize the socket and connect to a destination. Provided for backwards compatibility only.
				void Connect(const struct sockaddr * name, int namelen);
				//! Shutdown, receive out-of-band data and close the socket (disconnect from a remote host).
				void Disconnect();
				//! Bind the socket to an address
				void Bind(const std::string& ip_addr, unsigned port, int type = SOCK_STREAM, int protocol = IPPROTO_IP);
				//! constructor
				Socket();
				virtual ~Socket();
			};
		}
	}
}