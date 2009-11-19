#pragma once

namespace AppSecInc 
{
    namespace Service 
    {
		//! service creation information
		class ServiceCreateInfo
		{
		public:
			std::wstring name;
			std::wstring display_name;
			DWORD desired_access;
			DWORD service_type;
			DWORD start_type;
			DWORD error_control;
			std::wstring binary_path_name;
			std::wstring order_group;
			// std::vector<std::wstring> dependencies // \todo: implement dependencies
			std::wstring service_start_username;
			std::wstring service_start_password;
		public:
			ServiceCreateInfo();
		};
	}
}

