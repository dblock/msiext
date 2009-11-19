#pragma once

namespace AppSecInc 
{
    namespace Service 
    {
		//! service status information
		struct ServiceStatusProcess
		{
			std::wstring name;
			std::wstring display_name;
			SERVICE_STATUS_PROCESS status_process;
		};
	}
}