#include "StdAfx.h"
#include "ServiceInstance.h"

using namespace AppSecInc::Service;

ServiceInstance::ServiceInstance() 
    : m_h(NULL)
{
}

ServiceInstance::~ServiceInstance()
{
    if (IsOpen())
    {
        Close();
    }
}

void ServiceInstance::Close()
{
    CHECK_WIN32_BOOL(::CloseServiceHandle(m_h),
        L"Error closing service object");

    m_h = NULL;
}

void ServiceInstance::Open(const ServiceManager& scm, const std::wstring& service_name, DWORD access)
{
    if (IsOpen())
    {
        Close();
    }

    m_h = ::OpenServiceW(scm.GetHandle(), service_name.c_str(), access);
    CHECK_WIN32_BOOL(NULL != m_h,
        L"Error opening " << service_name << L" service");
}

void ServiceInstance::Delete()
{
	CHECK_BOOL(IsOpen(),
		L"Service must be opened first");

	CHECK_WIN32_BOOL(::DeleteService(m_h),
		L"Error deleting service");

	Close();
}

void ServiceInstance::Create(const ServiceManager& scm, const ServiceCreateInfo& info)
{
    if (IsOpen())
    {
        Close();
    }

    m_h = ::CreateService(
		scm.GetHandle(), 
		info.name.c_str(),
		info.display_name.length() ? info.display_name.c_str() : NULL,
		info.desired_access,
		info.service_type,
		info.start_type,
		info.error_control,
		info.binary_path_name.c_str(),
		info.order_group.length() ? info.order_group.c_str() : NULL,
		NULL, // \todo: implement tag id
		NULL, // \todo: implement dependencies
		info.service_start_username.length() ? info.service_start_username.c_str() : NULL,
		info.service_start_password.length() ? info.service_start_password.c_str() : NULL);

    CHECK_WIN32_BOOL(NULL != m_h,
        L"Error creating " << info.name << L" service");
}

void ServiceInstance::GetServiceProcessStatus(LPSERVICE_STATUS_PROCESS lp) const
{
    CHECK_BOOL(IsOpen(),
        L"Service has not been opened");

    DWORD dwBytes;
    CHECK_WIN32_BOOL(QueryServiceStatusEx(m_h, SC_STATUS_PROCESS_INFO, reinterpret_cast<LPBYTE>(lp), sizeof(SERVICE_STATUS_PROCESS), & dwBytes),
        L"Error quering service process info");
}

void ServiceInstance::Control(DWORD control)
{
    CHECK_BOOL(IsOpen(),
        L"Service has not been opened");

    if (control == SERVICE_CONTROL_START)
    {
        CHECK_WIN32_BOOL(::StartServiceW(m_h, 0, NULL),
            L"Error starting service");
    }
    else
    {
        SERVICE_STATUS status = { 0 };
        CHECK_WIN32_BOOL(::ControlService(m_h, control, & status),
            L"Error controlling service");
    }
}

void ServiceInstance::Stop() 
{ 
    Control(SERVICE_CONTROL_STOP); 
}

void ServiceInstance::Start() 
{ 
    Control(SERVICE_CONTROL_START);
}

void ServiceInstance::Restart() 
{ 
    Stop();
    Start(); 
}

void ServiceInstance::Pause() 
{ 
    Control(SERVICE_CONTROL_PAUSE); 
}

void ServiceInstance::Continue() 
{ 
    Control(SERVICE_CONTROL_CONTINUE); 
}

DWORD ServiceInstance::GetServiceState() const
{
    SERVICE_STATUS_PROCESS status = { 0 };
    GetServiceProcessStatus(& status);
    return status.dwCurrentState;
}

bool ServiceInstance::Wait(DWORD timeout) const
{
    DWORD slept = 0;
    WORD sleep = 100;
    while(slept < timeout || timeout == INFINITE)
    {
        switch(GetServiceState())
        {
        case SERVICE_START_PENDING:
        case SERVICE_STOP_PENDING:
        case SERVICE_CONTINUE_PENDING:
        case SERVICE_PAUSE_PENDING:
            break;
        default:
            return true;
        }

        ::Sleep(sleep);
        slept += sleep;
    }

    THROW("Error waiting for service");
}

std::wstring ServiceInstance::GetDescription() const
{
	CHECK_BOOL(IsOpen(),
		L"Service must be opened first");

	DWORD dwBytes = 0;
	::QueryServiceConfig2(m_h, SERVICE_CONFIG_DESCRIPTION, NULL, 0, & dwBytes);
	CHECK_WIN32_BOOL(dwBytes >= 0, L"Invalid number of bytes returned from QueryServiceConfig2");

	std::vector<byte> buffer;
	std::wstring result;
	if (dwBytes > 0)
	{
		buffer.resize(dwBytes);
		CHECK_WIN32_BOOL(::QueryServiceConfig2(m_h, SERVICE_CONFIG_DESCRIPTION, & * buffer.begin(), buffer.size(), & dwBytes),
			L"Error in QueryServiceConfig2");
		
		SERVICE_DESCRIPTION * p = (SERVICE_DESCRIPTION *) & * buffer.begin();
		if (p->lpDescription != NULL) result = p->lpDescription;
	}

	return result;
}

ServiceConfig ServiceInstance::GetConfig() const
{
	CHECK_BOOL(IsOpen(),
		L"Service must be opened first");

	DWORD dwBytes = 0;
	::QueryServiceConfig(m_h, NULL, 0, & dwBytes);
	CHECK_WIN32_BOOL(dwBytes > 0, L"Invalid number of bytes returned from QueryServiceConfig");

	std::vector<char> buffer;
	buffer.resize(dwBytes);
	CHECK_WIN32_BOOL(::QueryServiceConfig(m_h, reinterpret_cast<LPQUERY_SERVICE_CONFIG>(& * buffer.begin()), buffer.size(), & dwBytes),
		L"Error in QueryServiceConfig");

	LPQUERY_SERVICE_CONFIG p = reinterpret_cast<LPQUERY_SERVICE_CONFIG>(& * buffer.begin());

	ServiceConfig result;
	result.binary_path_name = p->lpBinaryPathName;
	result.error_control = p->dwErrorControl;
	result.load_order_group = p->lpLoadOrderGroup;
	result.display_name = p->lpDisplayName;
	result.service_start_name = p->lpServiceStartName;
	result.service_type = p->dwServiceType;
	result.start_type = p->dwStartType;
	result.tag_id = p->dwTagId;

	LPWSTR dependency = p->lpDependencies;
	while(dependency != NULL && * dependency)
	{
		result.dependencies.push_back(dependency);
		dependency += (wcslen(dependency) + 1);
	}

	return result;
}