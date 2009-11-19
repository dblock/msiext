#include "StdAfx.h"
#include "CheckCredentials.h"

CA_API UINT __stdcall CheckCredentials(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;

    MsiImpersonatedInstall msiInstall(hInstall);
    msiInstall.LogInfo(L"CheckCredentials", L"Checking credentials.");

    msiInstall.SetProperty(L"LOGON_VALID", L"0");
    msiInstall.SetProperty(L"LOGON_ERROR", L"");
	std::wstring username = msiInstall.GetProperty(L"LOGON_USERNAME");
	std::wstring password = msiInstall.GetProperty(L"LOGON_PASSWORD");
    std::wstring domain = L".";
	int logonType = GetPropertyValue(msiInstall, L"LOGON_TYPE", s_LogonTypeFlags);
	if (logonType == 0) logonType = LOGON32_LOGON_NETWORK;

    msiInstall.LogInfo(L"CheckCredentials", L"Username: " + username);
    msiInstall.LogInfo(L"CheckCredentials", L"Password: " + 
        password.length() > 0 ? std::wstring(L"*******") : std::wstring(L"<blank>"));

    try
    {
        AppSecInc::LSA::LoggedOnUser user;
        user.Logon(username, password, logonType, LOGON32_PROVIDER_DEFAULT);
        msiInstall.SetProperty(L"LOGON_VALID", L"1");
    }
    catch(std::exception& ex)
    {
        msiInstall.SetProperty("LOGON_ERROR", ex.what());
    }

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

