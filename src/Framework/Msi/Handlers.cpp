#include "StdAfx.h"
#include "Handlers.h"

DWORD AppSecInc::Msi::Exceptions::MSI_COM_EXCEPTION_HANDLER_BLOCK_impl(MSIHANDLE hInstall, LPCTSTR func, _com_error& e) 
{
    EXCEPTION_HANDLER_PROLOG;
	std::wstringstream os;
    if (func && wcslen(func)) os << L"[" << func << L"] ";
	os << L"_com_error: [";
	os << e.WCode()
		<< L"] "
		<< e.ErrorMessage()
		<< L".";

    MsiInstall msiInstall(hInstall);
    msiInstall.LogInfo(func, os.str());
    if (! ::MsiGetMode(hInstall, MSIRUNMODE_SCHEDULED))
        msiInstall.SetProperty(L"CA_ERROR", e.ErrorMessage());
    EXCEPTION_HANDLER_EPILOG;
    // http://msdn.microsoft.com/en-us/library/5xyy99wb.aspx
    // If the HRESULT is within the range 0x80040200 to 0x8004FFFF, the WCode method returns the HRESULT minus 0x80040200; otherwise, it returns zero.
    return e.WCode() == 0 ? AppSecInc::Msi::Exceptions::default_error_code : e.WCode();
}

DWORD AppSecInc::Msi::Exceptions::MSI_STD_EXCEPTION_HANDLER_BLOCK_impl(MSIHANDLE hInstall, LPCTSTR func, std::exception& e) 
{
    EXCEPTION_HANDLER_PROLOG;
    std::wstringstream os;
    if (func && wcslen(func)) os << L"[" << func << L"] ";
    os << L"std::exception: ";
    os << AppSecInc::StringUtils::mb2wc(e.what());
    MsiInstall msiInstall(hInstall);
    msiInstall.LogInfo(func, os.str());
    if (! ::MsiGetMode(hInstall, MSIRUNMODE_SCHEDULED))
        msiInstall.SetProperty("CA_ERROR", e.what());
    EXCEPTION_HANDLER_EPILOG;
    return AppSecInc::Msi::Exceptions::default_error_code;
}

DWORD AppSecInc::Msi::Exceptions::MSI_ELLIPSIS_EXCEPTION_HANDLER_BLOCK_impl(MSIHANDLE hInstall, LPCTSTR func)
{
    EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);
    std::wstringstream os;
    if (func && wcslen(func)) os << L"[" << func << L"] ";
	std::wstring error = L"unknown C++ exception";
    os << error;
    msiInstall.LogInfo(func, os.str());
    if (! ::MsiGetMode(hInstall, MSIRUNMODE_SCHEDULED))
        msiInstall.SetProperty(L"CA_ERROR", error);
    EXCEPTION_HANDLER_EPILOG;
    return AppSecInc::Msi::Exceptions::default_error_code;
}

void AppSecInc::Msi::Exceptions::MSI_EXCEPTION_HANDLER_PROLOG_impl(MSIHANDLE hInstall, LPCTSTR func)
{
    MsiInstall msiInstall(hInstall);
    std::wstringstream version;
    version << VERSION_PRODUCTNAME_VALUE << L" " << VERSION_VALUE;
    msiInstall.LogInfo(func, version.str());
    if (! ::MsiGetMode(hInstall, MSIRUNMODE_SCHEDULED) && ! msiInstall.GetProperty(L"CA_ERROR").empty())
        msiInstall.SetProperty(L"CA_ERROR", L"");
}