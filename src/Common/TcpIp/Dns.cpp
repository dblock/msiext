#include "StdAfx.h"
#include "Dns.h"

std::wstring AppSecInc::TcpIp::DNS::GetHostByAddress(const std::wstring& ip_addr, int family)
{
	return AppSecInc::StringUtils::mb2wc(GetHostByAddress(
		AppSecInc::StringUtils::wc2mb(ip_addr), family));
}

std::string AppSecInc::TcpIp::DNS::GetHostByAddress(const std::string& ip_addr, int family)
{
	struct sockaddr_in saGNI;
	saGNI.sin_family = family;
    saGNI.sin_addr.s_addr = inet_addr(ip_addr.c_str());
	char hostname[NI_MAXHOST] = { 0 };
	char servInfo[NI_MAXSERV] = { 0 };

	CHECK_BOOL(saGNI.sin_addr.s_addr != INADDR_NONE && saGNI.sin_addr.s_addr != INADDR_ANY,
		L"Invalid IP address: " << AppSecInc::StringUtils::mb2wc(ip_addr));

	CHECK_BOOL(0 == getnameinfo(reinterpret_cast<struct sockaddr *>(& saGNI), sizeof (struct sockaddr), hostname, NI_MAXHOST, servInfo, NI_MAXSERV, NI_NUMERICSERV),
		CWSAStartup::ErrorMessage(WSAGetLastError()));

	return hostname;
}

void AppSecInc::TcpIp::DNS::GetHostInfo(const std::wstring& name, std::wstring& hostname, std::vector<std::wstring>& aliases, std::vector<std::wstring>& ipaddresses, int family)
{
	aliases.clear();
	ipaddresses.clear();
	std::vector<std::string> aliases_l;
	std::vector<std::string> ipaddresses_l;
	GetHostInfo(AppSecInc::StringUtils::wc2mb(name), AppSecInc::StringUtils::wc2mb(hostname), aliases_l, ipaddresses_l, family);
	for each(const std::string& alias in aliases_l) 
		aliases.push_back(AppSecInc::StringUtils::mb2wc(alias));
	for each(const std::string& ipaddress in ipaddresses_l) 
		ipaddresses.push_back(AppSecInc::StringUtils::mb2wc(ipaddress));
}

void AppSecInc::TcpIp::DNS::GetHostInfo(const std::string& name, std::string& hostname, std::vector<std::string>& aliases, std::vector<std::string>& ipaddresses, int family)
{
	CHECK_BOOL(! name.empty(),
		L"Missing host name");

	struct hostent * r = NULL;
	// check whether this is a well-formed IP address
	struct in_addr addr = { 0 };
	addr.s_addr = inet_addr(name.c_str());
	if (addr.s_addr == INADDR_NONE || addr.s_addr == INADDR_ANY)
	{
		// resolve the host name
		r = ::gethostbyname(name.c_str());
	}
	else
	{
		r = ::gethostbyaddr(reinterpret_cast<const char *>(& addr), 4, family);
	}

	CHECK_BOOL(NULL != r,
		CWSAStartup::ErrorMessage(WSAGetLastError()));

	hostname = r->h_name;
	
	aliases.empty();
	if (r->h_aliases)
	{
		for (int i = 0; r->h_aliases[i]; ++i)
		{
			aliases.push_back(r->h_aliases[i]);
		}
	}

	ipaddresses.empty();
	if (r->h_addr_list)
	{
		for (int i = 0; r->h_addr_list[i]; ++i)
		{
			ipaddresses.push_back(inet_ntoa( * reinterpret_cast<struct in_addr *>(r->h_addr_list[i])));
		}
	}
}

std::wstring AppSecInc::TcpIp::DNS::GetHostByName(const std::wstring& name, int family)
{
	return AppSecInc::StringUtils::mb2wc(GetHostByName(
		AppSecInc::StringUtils::wc2mb(name), family));
}

std::string AppSecInc::TcpIp::DNS::GetHostByName(const std::string& name, int family)
{
	std::string hostname;
	std::vector<std::string> aliases;
	std::vector<std::string> ipaddresses;

	GetHostInfo(name, hostname, aliases, ipaddresses, family);

	return hostname;
}

std::vector<std::wstring> AppSecInc::TcpIp::DNS::GetHostIpAddresses(const std::wstring& name, int family)
{
	std::vector<std::string> ipaddresses = GetHostIpAddresses(
		AppSecInc::StringUtils::wc2mb(name), family);
	std::vector<std::wstring> ipaddresses_l;
	for each(const std::string& ipaddress in ipaddresses)
		ipaddresses_l.push_back(AppSecInc::StringUtils::mb2wc(ipaddress));
	return ipaddresses_l;
}

std::vector<std::string> AppSecInc::TcpIp::DNS::GetHostIpAddresses(const std::string& name, int family)
{
	std::string hostname;
	std::vector<std::string> aliases;
	std::vector<std::string> ipaddresses;

	GetHostInfo(name, hostname, aliases, ipaddresses, family);

	CHECK_BOOL(ipaddresses.size() > 0,
		L"No IP address found for " << AppSecInc::StringUtils::mb2wc(name));

	return ipaddresses;
}

std::wstring AppSecInc::TcpIp::DNS::GetHostNameW(const std::wstring& defaultvalue)
{
    std::wstring hostname;
    static LPCWSTR s_parameters = L"SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters";
    static LPCWSTR s_hostname = L"Hostname";
    if (AppSecInc::Registry::KeyExists(HKEY_LOCAL_MACHINE, s_parameters, s_hostname))
    {
        hostname = AppSecInc::Registry::GetStringValue(HKEY_LOCAL_MACHINE, s_parameters, s_hostname);
    }
    if (hostname.empty()) hostname = defaultvalue;
    return hostname;
}

std::string AppSecInc::TcpIp::DNS::GetHostNameA(const std::string& defaultvalue)
{
    return AppSecInc::StringUtils::wc2mb(GetHostNameW(
        AppSecInc::StringUtils::mb2wc(defaultvalue)));
}

bool AppSecInc::TcpIp::DNS::IsIpAddress(const std::wstring& name, int family)
{
    return IsIpAddress(AppSecInc::StringUtils::wc2mb(name), family);
}

bool AppSecInc::TcpIp::DNS::IsIpAddress(const std::string& ip_addr, int family)
{
	struct sockaddr_in saGNI;
	saGNI.sin_family = family;
    saGNI.sin_addr.s_addr = inet_addr(ip_addr.c_str());

	return (saGNI.sin_addr.s_addr != INADDR_NONE 
		&& saGNI.sin_addr.s_addr != INADDR_ANY);
}
