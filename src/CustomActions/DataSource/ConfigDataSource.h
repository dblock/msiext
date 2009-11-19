#pragma once

/*!

\brief Create, remove or configure a DSN
\param DSN_ATTRIBUTES DSN Attributes for SQLConfigDataSource
\param DSN_NAME DSN Name, used only if DSN_ATTRIBUTES not specified
\param ODBC_DRIVER ODBC driver for SQLConfigDataSource
\param ODBC_FLAG ODBC flag for SQLConfigDataSource, one of the following:
    \li ODBC_ADD_DSN: create a user DSN
    \li ODBC_CONFIG_DSN: configure a user DSN
    \li ODBC_REMOVE_DSN: remove a user DSN
    \li ODBC_ADD_SYS_DSN: create a system DSN
    \li ODBC_CONFIG_SYS_DSN: configure a system DSN
    \li ODBC_REMOVE_SYS_DSN: remove a system DSN
    \li ODBC_REMOVE_DEFAULT_DSN: remove the default DSN

*/
CA_API UINT __stdcall ConfigDataSource(MSIHANDLE hInstall);
