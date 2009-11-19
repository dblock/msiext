#pragma once

namespace AppSecInc
{
	namespace Net
	{
		namespace DirectoryServices
		{
			struct NetJoinStatus
			{
				NETSETUP_JOIN_STATUS join_status;
				std::wstring netbios_name;
			};

			//! retrieves join status information for the specified computer
			NetJoinStatus GetJoinStatus(const std::wstring& server_name = L"");
		}
	}
}