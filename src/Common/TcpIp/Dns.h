#pragma once

namespace AppSecInc
{
	namespace TcpIp
	{
		namespace DNS
		{
			//! get host name by IPv4 address
			std::wstring GetHostByAddress(const std::wstring& ip_addr, int family = AF_INET);
			//! get host name by IPv4 address
			std::string GetHostByAddress(const std::string& ip_addr, int family = AF_INET);
			//! get host name by DNS name or IPv4 address
			std::wstring GetHostByName(const std::wstring& name, int family = AF_INET);
			//! get host name by DNS name or IPv4 address
			std::string GetHostByName(const std::string& name, int family = AF_INET);
			//! returns true if this is an IPv4 address
			bool IsIpAddress(const std::wstring& name, int family = AF_INET);
			//! returns true if this is an IPv4 address
			bool IsIpAddress(const std::string& name, int family = AF_INET);
			//! get host IPv4 addresses
			std::vector<std::wstring> GetHostIpAddresses(const std::wstring& name, int family = AF_INET);
			//! get host IPv4 addresses
			std::vector<std::string> GetHostIpAddresses(const std::string& name, int family = AF_INET);
			//! get host IPv4 information
			void GetHostInfo(const std::wstring& name, std::wstring& hostname, std::vector<std::wstring>& aliases, std::vector<std::wstring>& ipaddresses, int family = AF_INET);
			//! get host IPv4 information
			void GetHostInfo(const std::string& name, std::string& hostname, std::vector<std::string>& aliases, std::vector<std::string>& ipaddresses, int family = AF_INET);
            //! get the local host name from tcp/ip registry configuration
            std::wstring GetHostNameW(const std::wstring& defaultvalue = L"localhost");
            //! get the local host name from tcp/ip registry configuration
            std::string GetHostNameA(const std::string& defaultvalue = "localhost");
		}
	}
}
