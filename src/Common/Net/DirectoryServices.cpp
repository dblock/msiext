#include "StdAfx.h"
#include "DirectoryServices.h"

using namespace AppSecInc::Net::DirectoryServices;

NetJoinStatus AppSecInc::Net::DirectoryServices::GetJoinStatus(const std::wstring& server_name)
{
	NetJoinStatus status;
	LPWSTR netbios_name = NULL;
	boost::shared_ptr<void> netbios_name_ptr(netbios_name, ::NetApiBufferFree);
	CHECK_WIN32_DWORD(::NetGetJoinInformation(server_name.length() ? server_name.c_str() : NULL, & netbios_name, & status.join_status),
            L"Error getting join status for \"" << (server_name.empty() ? L"." : server_name) << L"\"");
	status.netbios_name = netbios_name;
	return status;
}
