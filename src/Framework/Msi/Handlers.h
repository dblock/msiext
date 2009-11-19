#pragma once

namespace AppSecInc
{
    namespace Msi
    {
	    namespace Exceptions
	    {
            void MSI_EXCEPTION_HANDLER_PROLOG_impl(MSIHANDLE h, LPCTSTR func);
		    DWORD MSI_COM_EXCEPTION_HANDLER_BLOCK_impl(MSIHANDLE h, LPCTSTR func, _com_error& e);
		    DWORD MSI_STD_EXCEPTION_HANDLER_BLOCK_impl(MSIHANDLE h, LPCTSTR func, std::exception& e);
		    DWORD MSI_ELLIPSIS_EXCEPTION_HANDLER_BLOCK_impl(MSIHANDLE h, LPCTSTR func);
		    const DWORD default_error_code = ERROR_FUNCTION_FAILED;
	    }
    }
}

#define MSI_STD_EXCEPTION_HANDLER_BLOCK catch (std::exception& e) \
{ \
    return AppSecInc::Msi::Exceptions::MSI_STD_EXCEPTION_HANDLER_BLOCK_impl(hInstall, _T(__FUNCTION__), e); \
}

#define MSI_COM_EXCEPTION_HANDLER_BLOCK catch (_com_error& e) \
{ \
    return AppSecInc::Msi::Exceptions::MSI_COM_EXCEPTION_HANDLER_BLOCK_impl(hInstall, _T(__FUNCTION__), e); \
}

#define MSI_ELLIPSIS_EXCEPTION_HANDLER_BLOCK catch (...) \
{ \
    return AppSecInc::Msi::Exceptions::MSI_ELLIPSIS_EXCEPTION_HANDLER_BLOCK_impl(hInstall, _T(__FUNCTION__)); \
}

#define MSI_EXCEPTION_HANDLER_PROLOG try { \
    AppSecInc::Msi::Exceptions::MSI_EXCEPTION_HANDLER_PROLOG_impl(hInstall, _T(__FUNCTION__));

#define MSI_EXCEPTION_HANDLER_EPILOG } \
    MSI_STD_EXCEPTION_HANDLER_BLOCK \
    MSI_COM_EXCEPTION_HANDLER_BLOCK \
    MSI_ELLIPSIS_EXCEPTION_HANDLER_BLOCK
