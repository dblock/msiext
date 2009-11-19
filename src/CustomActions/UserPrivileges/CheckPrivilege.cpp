#include "StdAfx.h"
#include "CheckPrivilege.h"

CA_API UINT __stdcall CheckPrivilege(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;

    MsiImpersonatedInstall msiInstall(hInstall);
    msiInstall.LogInfo(_T(__FUNCTION__), L"Checking privilege");

    msiInstall.SetProperty(L"LOGON_HAS_PRIVILEGE", L"0");
	std::wstring computername = msiInstall.GetProperty(L"ComputerName");
	std::wstring username = msiInstall.GetProperty(L"LOGON_USERNAME");
	std::wstring privilege = msiInstall.GetProperty(L"LOGON_PRIVILEGE");

    AppSecInc::LSA::LSAPolicy policy;
    LSA_OBJECT_ATTRIBUTES attr = { 0 };
    policy.Open(computername, attr, POLICY_ALL_ACCESS);

    AppSecInc::LSA::Account account;
    account.LookupAccount(username, computername);

    std::vector<std::wstring> rights;
    account.GetUserRights(rights);

    for (UINT i = 0; i < rights.size(); ++ i)
    {			
        if (rights[i] == privilege)
	    {
            msiInstall.SetProperty(L"LOGON_HAS_PRIVILEGE", L"1");
            break;
	    }
    }

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}
