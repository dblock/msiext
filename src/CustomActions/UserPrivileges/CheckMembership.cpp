#include "StdAfx.h"
#include "CheckMembership.h"

CA_API UINT __stdcall CheckMembership(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
	MsiImpersonatedInstall msiInstall(hInstall);
	msiInstall.LogInfo(_T(__FUNCTION__), L"Checking membership");

	msiInstall.SetProperty(L"LOGON_IS_MEMBER", L"0");
	std::wstring stringSid = msiInstall.GetProperty(L"SID");

	PSID sid = NULL;
	BOOL isMember = FALSE;

	CHECK_WIN32_BOOL(::ConvertStringSidToSid(stringSid.c_str(), & sid), 
		L"ConvertStringSidToSid failed. Error converting: " << stringSid);

	boost::shared_ptr<void> sid_ptr(sid, ::FreeSid);

	CHECK_WIN32_BOOL(::CheckTokenMembership(NULL, sid, & isMember), 
		L"CheckTokenMembership failed.");

	if (isMember)
	{
		msiInstall.SetProperty(L"LOGON_IS_MEMBER", L"1");
	}

	MSI_EXCEPTION_HANDLER_EPILOG;
	return ERROR_SUCCESS;
}
