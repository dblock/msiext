#include "StdAfx.h"
#include "ComImpl.h"

CA_API UINT __stdcall Win32_GenerateGuidString(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);
	msiInstall.SetProperty(L"WIN32_GUID_STRING", AppSecInc::Com::GenerateGUIDStringW());
	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

CA_API UINT __stdcall Win32_IsValidGuid(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);
	std::wstring guid = msiInstall.GetProperty(L"WIN32_GUID_STRING");
	msiInstall.SetProperty(L"WIN32_GUID_VALID", AppSecInc::Com::IsValidGUID(guid) ? L"1" : L"0");
	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}