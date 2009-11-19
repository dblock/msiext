#include "StdAfx.h"
#include "Privilege.h"

std::wstring AppSecInc::LSA::Privileges::GetPrivilegeName(LUID luid)
{
	DWORD dwSizeOrLen = 0;
	CHECK_WIN32_BOOL(! ::LookupPrivilegeName(NULL, & luid, NULL, & dwSizeOrLen),
		L"LookupPrivilegeName was expected to fail with ERROR_INSUFFICIENT_BUFFER");

	std::wstring privilege_name;
	// failed call returns the size of the buffer in TCHARs, including the NULL terminator
	privilege_name.resize(dwSizeOrLen);
	dwSizeOrLen = static_cast<DWORD>(privilege_name.size());
	CHECK_WIN32_BOOL(::LookupPrivilegeName(NULL, & luid, & * privilege_name.begin(), & dwSizeOrLen),
        L"LookupPrivilegeName failed");

	// successful call returns the length of the buffer in TCHARs not including the NULL terminator
	privilege_name.resize(dwSizeOrLen);
	return privilege_name;
}

std::wstring AppSecInc::LSA::Privileges::GetPrivilegeDisplayName(const std::wstring& privilege_name)
{
	DWORD dwSizeOrLen = 0;
	DWORD dwLanguageID = 0;
	CHECK_WIN32_BOOL(! ::LookupPrivilegeDisplayName(NULL, privilege_name.c_str(), NULL, & dwSizeOrLen, & dwLanguageID),
		L"LookupPrivilegeName was expected to fail with ERROR_INSUFFICIENT_BUFFER");

	std::wstring privilege_display_name;
	// failed call returns the size of the buffer in TCHARs, including the NULL terminator
	privilege_display_name.resize(dwSizeOrLen);
	dwSizeOrLen = static_cast<DWORD>(privilege_display_name.size());
	CHECK_WIN32_BOOL(::LookupPrivilegeDisplayName(NULL, privilege_name.c_str(), & * privilege_display_name.begin(), & dwSizeOrLen, & dwLanguageID),
        L"LookupPrivilegeName failed");

	// successful call returns the length of the buffer in TCHARs not including the NULL terminator
	privilege_display_name.resize(dwSizeOrLen);
	return privilege_display_name;
}

LUID AppSecInc::LSA::Privileges::GetPrivilege(const std::wstring& privilege_name)
{
	LUID luid = { 0 };
	CHECK_WIN32_BOOL(::LookupPrivilegeValue(NULL, privilege_name.c_str(), & luid),
		L"LookupPrivilegeValue failed");
	return luid;
}