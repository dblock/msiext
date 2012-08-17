#include "StdAfx.h"
#include "NetBIOS.h"

std::wstring AppSecInc::TcpIp::NetBIOS::GetComputerName()
{
	wchar_t computername[MAX_COMPUTERNAME_LENGTH + 1] = { 0 };
	DWORD size = MAX_COMPUTERNAME_LENGTH + 1;

	CHECK_BOOL(::GetComputerNameW(computername, & size), 
		L"Could not get NetBIOS computer name" );

	return computername;
}
