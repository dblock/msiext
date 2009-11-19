#include "StdAfx.h"
#include "DirectoryServices.h"
#include "FlagMaps.h"

CA_API UINT __stdcall DirectoryGetDcName(MSIHANDLE hInstall)
{
	DWORD rc = ERROR_SUCCESS;
	MSI_EXCEPTION_HANDLER_PROLOG;

    MsiInstall msiInstall(hInstall);
	
	std::wstring computername = msiInstall.GetProperty(L"DS_COMPUTERNAME");
	std::wstring domainname = msiInstall.GetProperty(L"DS_DOMAINNAME");
	std::wstring sitename = msiInstall.GetProperty(L"DS_SITENAME");

	ULONG ulFlags = GetPropertyValue(msiInstall, L"DS_FLAGS", s_DirectoryServicesGetDcNameFlags);

	PDOMAIN_CONTROLLER_INFO pDcInfo = NULL;
	boost::shared_ptr<void> pDcInfoPtr(pDcInfo, ::NetApiBufferFree);

    CHECK_WIN32_DWORD(::DsGetDcName(
		    computername.empty() ? NULL : computername.c_str(),
		    domainname.empty() ? NULL : domainname.c_str(),
		    NULL, //! \todo implement domain guid, get DS_DOMAINGUID and convert
		    sitename.empty() ? NULL : sitename.c_str(),
		    ulFlags,
		    & pDcInfo),
	    L"Error in DsGetDcName");

	//! \todo support other return values
	std::wstring DomainControllerName;
	std::wstring DomainControllerAddress;
	std::wstring DomainName;
	
	if (pDcInfo)
	{
		DomainControllerName = pDcInfo->DomainControllerName;
		AppSecInc::StringUtils::ltrim(DomainControllerName, L"\\");
		DomainControllerAddress = pDcInfo->DomainControllerAddress;
		AppSecInc::StringUtils::ltrim(DomainControllerAddress, L"\\");
		DomainName = pDcInfo->DomainName;
	}

	msiInstall.SetProperty(L"DS_DOMAINCONTROLLER_NAME", DomainControllerName);
	msiInstall.SetProperty(L"DS_DOMAINCONTROLLER_ADDRESS", DomainControllerAddress);
	msiInstall.SetProperty(L"DS_DOMAIN_NAME", DomainName);

	MSI_EXCEPTION_HANDLER_EPILOG;
	return ERROR_SUCCESS;
}

