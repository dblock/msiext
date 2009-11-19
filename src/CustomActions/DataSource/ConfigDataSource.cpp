#include "StdAfx.h"
#include "ConfigDataSource.h"
#include "FlagMaps.h"

using namespace AppSecInc::Msi::Flags;

CA_API UINT __stdcall ConfigDataSource(MSIHANDLE hInstall)
{
	MSI_EXCEPTION_HANDLER_PROLOG;
    MsiInstall msiInstall(hInstall);

    std::wstring dsn_attributes = msiInstall.GetProperty(L"DSN_ATTRIBUTES");
    std::wstring odbc_driver = msiInstall.GetProperty(L"ODBC_DRIVER");

    if (! dsn_attributes.length())
    {
        // if DSN_ATTRIBUTES is not present, a DSN name may be specified
        // this is a shortcut for all delete operations

        std::wstring dsn_name = msiInstall.GetProperty(L"DSN_NAME");

        if (dsn_name.length())
        {
            dsn_attributes.append(L"DSN=" + dsn_name);
        }
    }

    WORD flag = GetPropertyValue<FlagMapEntry[ARRAYSIZE(s_ODBCDSNFlags)], WORD>(msiInstall, L"ODBC_FLAG", s_ODBCDSNFlags);
    AppSecInc::Databases::ODBC::ODBCDataSource::Configure(flag, odbc_driver, dsn_attributes);

	MSI_EXCEPTION_HANDLER_EPILOG;
    return ERROR_SUCCESS;
}

