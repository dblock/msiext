#pragma once

/*! 

\brief Create, configure or remove a Microsoft Access DSN using Microsoft Access Driver (*.MDB)

\param DSN_NAME Name for the new DSN
\param DSN_ACCESS_DBQ Complete path to the .mdb database file. 
 Note that creating the DSN will succeed with the wrong path, but the database will be inaccessible.
\param DSN_ACCESS_UID Optional database username.
\param DSN_ACCESS_PWD Optional database password.
\param ODBC_FLAG ODBC flag for SQLConfigDataSource, one of the following:
    \li ODBC_ADD_DSN: create a user DSN
    \li ODBC_CONFIG_DSN: configure a user DSN
    \li ODBC_REMOVE_DSN: remove a user DSN
    \li ODBC_ADD_SYS_DSN: create a system DSN
    \li ODBC_CONFIG_SYS_DSN: configure a system DSN
    \li ODBC_REMOVE_SYS_DSN: remove a system DSN
    \li ODBC_REMOVE_DEFAULT_DSN: remove the default DSN

*/
CA_API UINT __stdcall ConfigDataSource_Access(MSIHANDLE hInstall);

/*!
\brief Table-driven immediate custom action that creates Microsoft Access database.
Use in combination with \ref AppSecInc.Wix.Extensions.DataSourceExtension.
*/
CA_API UINT __stdcall CreateDatabases_Access_Immediate(MSIHANDLE hInstall);

/*! 
\brief Table-driven deferred custom action that creates Microsoft Access database.
Use in combination with \ref AppSecInc.Wix.Extensions.DataSourceExtension.
*/
CA_API UINT __stdcall CreateDatabases_Access_Deferred(MSIHANDLE hInstall);

