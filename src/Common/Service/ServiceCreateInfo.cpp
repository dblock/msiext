#include "StdAfx.h"
#include "ServiceCreateInfo.h"

AppSecInc::Service::ServiceCreateInfo::ServiceCreateInfo()
	: desired_access(SC_MANAGER_ALL_ACCESS)
	, service_type(SERVICE_WIN32_OWN_PROCESS)
	, start_type(SERVICE_DEMAND_START)
	, error_control(SERVICE_ERROR_NORMAL)
{

}

