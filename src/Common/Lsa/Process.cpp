#include "StdAfx.h"
#include "Process.h"
#include <boost/shared_ptr.hpp>

using namespace AppSecInc::LSA;

Process::Process()
    : m_h(NULL)
{

}

void Process::Open(DWORD processid, DWORD access, BOOL inherit)
{
    if (IsOpen())
    {
        Close();
    }

    m_h = ::OpenProcess(access, inherit, processid);

    CHECK_WIN32_BOOL(m_h != NULL,
        L"Error opening process for " << std::hex << processid);
}

void Process::Open(const std::wstring& name, DWORD access, BOOL inherit)
{
    HANDLE snapshot_h = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    CHECK_WIN32_BOOL(snapshot_h != NULL,
        L"CreateToolhelp32Snapshot failed");

    boost::shared_ptr<void> snapshot_h_ptr(snapshot_h, ::CloseHandle);

    PROCESSENTRY32 pe32 = { 0 };
    pe32.dwSize = sizeof(pe32);

    BOOL fProcess = ::Process32First(snapshot_h, & pe32);
    while (fProcess && (lstrcmpi(pe32.szExeFile, name.c_str()) != 0))
    {
	    fProcess = Process32Next(snapshot_h, &pe32);
    }

    CHECK_WIN32_BOOL(fProcess,
        L"Error in Process32First/Process32Next");

    Open(pe32.th32ProcessID, access, inherit);
}

Process::~Process()
{
    if (IsOpen())
    {
        Close();
    }
}

void Process::Close()
{
    CHECK_BOOL(IsOpen(),
        L"Process not open");

    CHECK_WIN32_BOOL(::CloseHandle(m_h),
        L"Error closing process  handle");

    m_h = NULL;
}