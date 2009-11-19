#include "StdAfx.h"
#include <LSA/LSA.h>
#include "MsiImpersonatedInstall.h"
#include "FlagMaps.h"

MsiImpersonatedInstall::MsiImpersonatedInstall(MSIHANDLE h)
    : MsiInstall(h)
{
	std::wstring username = GetProperty(L"IMPERSONATE_USERNAME");
	std::wstring password = GetProperty(L"IMPERSONATE_PASSWORD");

    if (username.length())
    {
		LogInfo(_T(__FUNCTION__), L"Impersonating \"" + username + L"\"");

		MsiInstall msiInstall(h);

		int logonType = GetPropertyValue(msiInstall, L"IMPERSONATE_LOGON_TYPE", s_LogonTypeFlags);
		if (logonType == 0) logonType = LOGON32_LOGON_INTERACTIVE;

		int logonProvider = GetPropertyValue(msiInstall, L"IMPERSONATE_LOGON_PROVIDER", s_LogonProviderFlags);
		if (logonProvider == 0) logonProvider = LOGON32_PROVIDER_DEFAULT;

        m_impersonated_user.Logon(username, password, logonType, logonProvider); 
        m_impersonated_user.Impersonate();
    }
}

MsiImpersonatedInstall::~MsiImpersonatedInstall()
{

}

