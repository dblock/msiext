#include "StdAfx.h"
#include "ServiceImpl.h"
#include "FlagMaps.h"

CA_API UINT __stdcall Service_RenameRegistryEntry(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;

    MsiInstall msiInstall(hInstall);

    std::wstring service_name_from = msiInstall.GetProperty(L"SERVICE_RENAME_REGISTRY_ENTRY_FROM");
    std::wstring service_name_to = msiInstall.GetProperty(L"SERVICE_RENAME_REGISTRY_ENTRY_TO");

	if (service_name_to.length() == 0)
    {
		service_name_to = service_name_from + L"_TEMP";
    }

	AppSecInc::Registry::CopyBranch(
		HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\" + service_name_from, 
		HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\" + service_name_to);
	AppSecInc::Registry::DeleteBranch(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Services\\" + service_name_from);

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Service_ChangeBinaryPathName(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;

    MsiInstall msiInstall(hInstall);

    std::wstring service_name = msiInstall.GetProperty(L"SERVICE_CHANGE_SERVICE_NAME");
    std::wstring service_binary_path = msiInstall.GetProperty(L"SERVICE_CHANGE_BINARY_PATH_NAME");

    AppSecInc::Service::ServiceManager scm;
    scm.Open();
    AppSecInc::Service::ServiceInstance service;
    service.Open(scm, service_name, SERVICE_CHANGE_CONFIG);

    // Change the binary path name
	CHECK_WIN32_BOOL(::ChangeServiceConfig(service.GetHandle(), SERVICE_NO_CHANGE, SERVICE_NO_CHANGE, SERVICE_NO_CHANGE, 
        service_binary_path.c_str(), NULL, NULL, NULL, NULL, NULL, NULL), 
        L"ChangeServiceConfig failed");

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Service_ChangeDisplayName(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;

    MsiInstall msiInstall(hInstall);

    std::wstring service_name = msiInstall.GetProperty(L"SERVICE_CHANGE_SERVICE_NAME");
    std::wstring service_display_name = msiInstall.GetProperty(L"SERVICE_CHANGE_DISPLAY_NAME");

    AppSecInc::Service::ServiceManager scm;
    scm.Open();
    AppSecInc::Service::ServiceInstance service;
    service.Open(scm, service_name, SERVICE_CHANGE_CONFIG);

    // Change the display name
	CHECK_WIN32_BOOL(::ChangeServiceConfig(service.GetHandle(), SERVICE_NO_CHANGE, SERVICE_NO_CHANGE, SERVICE_NO_CHANGE, 
        NULL, NULL, NULL, NULL, NULL, NULL, service_display_name.c_str()), 
        L"ChangeServiceConfig failed");

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Service_ChangeDescription(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;

    MsiInstall msiInstall(hInstall);

    std::wstring service_name = msiInstall.GetProperty(L"SERVICE_CHANGE_SERVICE_NAME");
	std::wstring service_description = msiInstall.GetProperty(L"SERVICE_CHANGE_DESCRIPTION");

    AppSecInc::Service::ServiceManager scm;
    scm.Open();
    AppSecInc::Service::ServiceInstance service;
    service.Open(scm, service_name, SERVICE_CHANGE_CONFIG);

    // Change the display name
    SERVICE_DESCRIPTION sd = { 0 };
	sd.lpDescription = const_cast<LPWSTR>(service_description.c_str());
	CHECK_WIN32_BOOL(::ChangeServiceConfig2(service.GetHandle(), SERVICE_CONFIG_DESCRIPTION, &sd), 
        L"ChangeServiceConfig2 failed");

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Service_Control(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::wstring service_name = msiInstall.GetProperty(L"SERVICE_NAME");
    DWORD service_control = GetPropertyValue(msiInstall, L"SERVICE_CONTROL", s_ServiceControl);

    AppSecInc::Service::ServiceManager scm;
    scm.Open();
    AppSecInc::Service::ServiceInstance service;
    service.Open(scm, service_name, SERVICE_ALL_ACCESS);
    service.Control(service_control);
    service.Wait();

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Service_Delete(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::wstring service_name = msiInstall.GetProperty(L"SERVICE_NAME");

    AppSecInc::Service::ServiceManager scm;
    scm.Open();
    AppSecInc::Service::ServiceInstance service;
    service.Open(scm, service_name, SERVICE_ALL_ACCESS);
    service.Delete();

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Service_GetConfig(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::wstring service_name = msiInstall.GetProperty(L"SERVICE_NAME");

    AppSecInc::Service::ServiceManager scm;
    scm.Open(STANDARD_RIGHTS_READ);
    AppSecInc::Service::ServiceInstance service;
    service.Open(scm, service_name, SERVICE_QUERY_CONFIG);

	AppSecInc::Service::ServiceConfig config = service.GetConfig();
	msiInstall.SetProperty(L"SERVICE_BINARY_PATH_NAME", config.binary_path_name);
	msiInstall.SetProperty(L"SERVICE_ERROR_CONTROL", AppSecInc::Msi::Flags::GetFlagName(
		config.error_control, s_ServiceErrorControl));
	msiInstall.SetProperty(L"SERVICE_LOAD_ORDER_GROUP", config.load_order_group);
	msiInstall.SetProperty(L"SERVICE_DISPLAY_NAME", config.display_name);
	msiInstall.SetProperty(L"SERVICE_START_NAME", config.service_start_name);
	msiInstall.SetProperty(L"SERVICE_TYPE", AppSecInc::Msi::Flags::GetFlagName(
		config.service_type, s_ServiceType));
	msiInstall.SetProperty(L"SERVICE_START_TYPE", AppSecInc::Msi::Flags::GetFlagName(
		config.start_type, s_ServiceStartType));
	msiInstall.SetProperty(L"SERVICE_TAG_ID", AppSecInc::StringUtils::toWString(config.tag_id));
	msiInstall.SetProperty(L"SERVICE_DEPENDENCIES", AppSecInc::StringUtils::join(config.dependencies, L","));
	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Service_Exists(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);
    std::wstring service_name = msiInstall.GetProperty(L"SERVICE_NAME");
    AppSecInc::Service::ServiceManager scm;
    scm.Open(STANDARD_RIGHTS_READ);
	msiInstall.SetProperty(L"SERVICE_EXISTS", scm.ServiceExists(service_name) ? L"1" : L"0");
	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}


using AppSecInc::Service::ServiceStatusProcess;

static std::shared_ptr<ServiceStatusProcess> getServiceStatus(const std::wstring& service_name)
{
	AppSecInc::Service::ServiceManager scm;
	scm.Open(SC_MANAGER_CONNECT|SC_MANAGER_ENUMERATE_SERVICE);
	std::list<ServiceStatusProcess> &services = scm.GetServices();

	for each(const ServiceStatusProcess& sp in services) {
		if (sp.name == service_name) {
			return std::shared_ptr<ServiceStatusProcess>(new ServiceStatusProcess( sp ));
		}
	}
	return std::shared_ptr<ServiceStatusProcess>();
}


static std::wstring serviceStatusString(DWORD dwCurrentState)
{
	const wchar_t* st = L"Unknown";

	switch (dwCurrentState) {
		case SERVICE_STOPPED:          st = L"Stopped";  break;
		case SERVICE_START_PENDING:    st = L"Starting"; break;
		case SERVICE_STOP_PENDING:     st = L"Stopping"; break;
		case SERVICE_RUNNING:          st = L"Running";  break;
		case SERVICE_CONTINUE_PENDING: st = L"Resuming"; break;
		case SERVICE_PAUSE_PENDING:    st = L"Pausing";  break;
		case SERVICE_PAUSED:           st = L"Paused";   break;
	}
	return st;
}

CA_API UINT __stdcall Service_GetStatus(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
	MsiInstall msiInstall(hInstall);

	std::wstring service_name = msiInstall.GetProperty(L"SERVICE_NAME");
	std::shared_ptr<ServiceStatusProcess> pst = getServiceStatus( service_name );
	if (pst) {
		msiInstall.SetProperty(L"SERVICE_STATUS", serviceStatusString(pst->status_process.dwCurrentState));
	}
	else {
		msiInstall.SetProperty(L"SERVICE_STATUS", L"Absent");
	}

	MSI_EXCEPTION_HANDLER_EPILOG;
	return ERROR_SUCCESS;
}

