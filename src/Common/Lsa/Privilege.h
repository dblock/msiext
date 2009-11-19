#pragma once

namespace AppSecInc 
{
    namespace LSA
    {
		struct Privilege
		{
			std::wstring Name;
			std::wstring DisplayName;
			LUID Luid;
			DWORD Attributes;
		};

		namespace Privileges
		{
			//! lookup a privilege name from a LUID on the current system
			std::wstring GetPrivilegeName(LUID luid);
			//! lookup privilege display name from a LUID on the current system
			std::wstring GetPrivilegeDisplayName(const std::wstring& privilege_name);
			//! lookup the LUID from a privilege name
			LUID GetPrivilege(const std::wstring& privilege_name);
		}
    }
}

