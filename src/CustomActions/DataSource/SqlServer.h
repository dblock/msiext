#pragma once

/*! 

\brief Create a Microsoft MSSQL DSN using Microsoft MSSQL Driver (*.MDB)

See http://msdn2.microsoft.com/en-us/library/ms811006.aspx for specific parameters.

\param DSN_NAME Name for the new DSN.
\param DSN_MSSQL_SERVER The name or label for the connection entry.
\param DSN_MSSQL_NETWORK The name of the Net-Library module to use, in capital letters, without the .dll suffix (for example, DBMSSOCN, not dbmssocn.dll).
\param DSN_MSSQL_ADDRESS The network address of the Windows NT server running SQL Server.
\param DSN_MSSQL_DATABASE The default database for the ODBC data source.
\param DSN_MSSQL_TRUSTED_CONNECTION Specifies whether the data source should use trusted connections when connecting to SQL Server.
\param ODBC_FLAG ODBC flag for SQLConfigDataSource, one of the following:
    \li ODBC_ADD_DSN: create a user DSN
    \li ODBC_CONFIG_DSN: configure a user DSN
    \li ODBC_REMOVE_DSN: remove a user DSN
    \li ODBC_ADD_SYS_DSN: create a system DSN
    \li ODBC_CONFIG_SYS_DSN: configure a system DSN
    \li ODBC_REMOVE_SYS_DSN: remove a system DSN
    \li ODBC_REMOVE_DEFAULT_DSN: remove the default DSN

\note If ADDRESS is present, it is always used as the network address for the connection. If ADDRESS is not present, then SERVER is used as the network address for the connection. 

\todo The following parameters are not implemented:
\li LANGUAGE The default national language to use.
\li OEMTOANSI Specifies whether to convert extended characters to OEM values.
\li TRANSLATIONDLL The name of the ODBC translation DLL to use with the data source.
\li TRANSLATIONNAME The name of the translator to use with the data source.
\li TRANSLATIONOPTION Specifies whether translation should be done on the data going to SQL Server.
\li USEPROCFORPREPARE Specifies whether the driver generates stored procedures to support the ODBC SQLPrepare function.
\li QuotedID Specifies whether the driver should issue a SET QUOTED IDENTIFIERS ON option when connecting to a SQL Server version 6.0 or later database.
\li AnsiNPW Specifies whether the driver should SET ON the ANSI_NULLS, ANSI_PADDING, and ANSI_WARNINGS options when connecting to a SQL Server version 6.5 or later database.
\li QueryLogFile Specifies the file name the driver should use to log long-running queries.
\li QueryLog_ON Specifies whether the data source should do query profiling.
\li QueryLogTime Specifies the interval for long-running queries.
\li StatsLogFile Specifies the file name the driver should use to log long performance statistics.
\li StatsLog_On Specifies whether the data source should log performance statistics.

*/
CA_API UINT __stdcall ConfigDataSource_SQLServer(MSIHANDLE hInstall);

/*!
\brief Table-driven immediate custom action that creates Microsoft SQL Server database.
Use in combination with \ref AppSecInc.Wix.Extensions.DataSourceExtension.
*/
CA_API UINT __stdcall CreateDatabases_SQLServer_Immediate(MSIHANDLE hInstall);

/*! 
\brief Table-driven deferred custom action that creates Microsoft SQL Server database.
Use in combination with \ref AppSecInc.Wix.Extensions.DataSourceExtension.
*/
CA_API UINT __stdcall CreateDatabases_SQLServer_Deferred(MSIHANDLE hInstall);

/*! 
\brief Table-driven immediate custom action that BULK inserts MSSQL data.
Use in combination with \ref AppSecInc.Wix.Extensions.DataSourceExtension.
*/
CA_API UINT __stdcall DataFile_SQLServer_Immediate(MSIHANDLE hInstall);

/*! 
\brief Table-driven immediate custom action that BULK inserts MSSQL data.
Use in combination with \ref AppSecInc.Wix.Extensions.DataSourceExtension.
*/
CA_API UINT __stdcall DataFile_SQLServer_Deferred(MSIHANDLE hInstall);
