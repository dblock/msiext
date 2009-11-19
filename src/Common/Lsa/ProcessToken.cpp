#include "StdAfx.h"
#include "ProcessToken.h"

using namespace AppSecInc::LSA;

ProcessToken::ProcessToken()
    : m_h(NULL)
{

}

void ProcessToken::Open(HANDLE h, DWORD access)
{
    if (IsOpen())
    {
        Close();
    }

    CHECK_WIN32_BOOL(::OpenProcessToken(h, access, & m_h),
        L"Error opening process token for " << std::hex << h);
}

ProcessToken::~ProcessToken()
{
    if (IsOpen())
    {
        Close();
    }
}

void ProcessToken::Close()
{
    CHECK_BOOL(IsOpen(),
        L"Process token not open");

    CHECK_WIN32_BOOL(::CloseHandle(m_h),
        L"Error closing process token handle");

    m_h = NULL;
}

void ProcessToken::AdjustPrivilege(const std::wstring& privilege, DWORD type)
{
    CHECK_BOOL(IsOpen(),
        L"Process token not open");

    TOKEN_PRIVILEGES privileges = { 0 };
    CHECK_WIN32_BOOL(::LookupPrivilegeValue(NULL, privilege.c_str(), & privileges.Privileges[0].Luid),
        L"Error in LookupPrivilegeValue");

    privileges.Privileges[0].Attributes = type;
    privileges.PrivilegeCount = 1;

    CHECK_WIN32_BOOL(::AdjustTokenPrivileges(GetHandle(), FALSE, & privileges, 0, NULL, NULL),
        L"Error in AdjustTokenPrivileges");
}
