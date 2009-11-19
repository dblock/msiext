#pragma once

namespace AppSecInc 
{
    namespace Service 
    {
		//! service configuration
		struct ServiceConfig
		{  
			DWORD service_type;
			DWORD start_type;
			DWORD error_control;
			std::wstring binary_path_name;
			std::wstring load_order_group;
			DWORD tag_id;
			std::wstring service_start_name; 
			std::wstring display_name;
			std::vector<std::wstring> dependencies;
		};
	}
}