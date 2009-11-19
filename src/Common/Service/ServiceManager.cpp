#include "StdAfx.h"
#include "ServiceManager.h"

using namespace AppSecInc::Service;
	
ServiceManager::ServiceManager() 
    : m_h(NULL)
{
}

ServiceManager::~ServiceManager()
{
    if (IsOpen())
    {
        Close();
    }
}

void ServiceManager::Close()
{
    CHECK_WIN32_BOOL(::CloseServiceHandle(m_h),
        L"Error closing service manager");

    m_h = NULL;
}

void ServiceManager::Open(DWORD access)
{
    Open(L"", L"", access);
}

void ServiceManager::Open(const std::wstring& computer_name, const std::wstring& database_name, DWORD access)
{
    if (IsOpen())
    {
        Close();
    }

    // open service manager
    m_h = ::OpenSCManagerW(
        computer_name.empty() ? NULL : computer_name.c_str(),
        database_name.empty() ? NULL : database_name.c_str(),
        access);

    CHECK_WIN32_BOOL(NULL != m_h,
        L"Error opening service manager");
}

std::list<ServiceStatusProcess> ServiceManager::GetServices(DWORD service_type, DWORD service_state, LPCTSTR service_group_name) const
{
	CHECK_BOOL(IsOpen(), L"Service manager not open");
	DWORD dwBuffer = 0;
	DWORD dwCount = 0;
	DWORD dwResumeHandle = NULL;

	CHECK_WIN32_BOOL(! EnumServicesStatusEx(m_h, SC_ENUM_PROCESS_INFO, service_type, service_state, NULL, 0, 
		& dwBuffer, & dwCount, NULL, service_group_name), L"EnumServicesStatusEx was expected to fail");

	DWORD rc = ::GetLastError();
	if (rc != ERROR_MORE_DATA)
	{
		CHECK_WIN32_DWORD(rc, L"EnumServicesStatusEx failed to enumerate services");
	}

	std::vector<byte> buffer;
	std::list<ServiceStatusProcess> services;
	do
	{
		buffer.resize(dwBuffer);
		dwBuffer = buffer.size();
		if (! EnumServicesStatusEx(m_h, SC_ENUM_PROCESS_INFO, service_type, service_state, buffer.size() ? & * buffer.begin() : NULL, buffer.size(), 
			& dwBuffer, & dwCount, & dwResumeHandle, service_group_name))
		{
			DWORD rc = ::GetLastError();
			if (rc != ERROR_MORE_DATA || dwResumeHandle == NULL)
			{
				CHECK_WIN32_BOOL(rc, L"EnumServicesStatusEx failed to enumerate services");
			}
		}

		LPENUM_SERVICE_STATUS_PROCESS service_status = reinterpret_cast<LPENUM_SERVICE_STATUS_PROCESS>(
			& * buffer.begin());
 
		for(unsigned int i = 0; i < dwCount; i++)
		{
			ServiceStatusProcess service;
			service.name = service_status[i].lpServiceName;
			service.display_name = service_status[i].lpDisplayName;
			service.status_process = service_status[i].ServiceStatusProcess;
			services.push_back(service);
		}

	} while (dwResumeHandle != NULL);

	return services;
}
