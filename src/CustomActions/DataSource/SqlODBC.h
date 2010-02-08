#pragma once

/*! 

\brief Test an ODBC connection.

\param ODBC_CONNECTION_STRING Connection string.
\return ODBC_CONNECTION_ESTABLISHED Set to 1 if connection was successfully established.
\return ODBC_ERROR Driver error when available.

This custom action supports impersonation, see \ref impersonate.

\par Example:

\code
<Dialog Id="InvalidLogonDlg" Width="260" Height="85" Title="Invalid Logon">
 <Control Id="Return" Type="PushButton" X="102" Y="57" Width="56" Height="17" Default="yes" Cancel="yes" Text="OK">
  <Publish Event="EndDialog" Value="Return">1</Publish>
 </Control>
 <Control Id="Text" Type="Text" X="48" Y="15" Width="194" Height="30" Text="[LOGON_ERROR]" />
 <Control Id="Icon" Type="Icon" X="15" Y="15" Width="24" Height="24" FixedSize="yes" IconSize="32" Text="WixUI_Ico_Exclam" />
</Dialog>
...
<Control Id="TestButton" Type="PushButton" X="40" Y="215" Width="100" Height="17" Text="Test Connection">
 <Publish Property="ODBC_SERVER" Value="[DATABASE_SERVER]" Order="1">1</Publish>
 <Publish Property="ODBC_SERVER" Value="[ComputerName]" Order="1"><![CDATA[DATABASE_SERVER = "(local)"]]></Publish>
 <Publish Property="ODBC_CONNECTION_STRING" Value="Driver=SQL Server;Server=[ODBC_SERVER],1433;Uid=[DATABASE_USERNAME];Pwd=[DATABASE_PASSWORD]" Order="2">1</Publish>
 <Publish Event="DoAction" Value="ODBC_Connect" Order="3">1</Publish>
 <Publish Property="LOGON_VALID" Value="1" Order="4"><![CDATA[ODBC_CONNECTION_ESTABLISHED]]></Publish>
 <Publish Property="LOGON_VALID" Value="0" Order="4"><![CDATA[NOT ODBC_CONNECTION_ESTABLISHED]]></Publish>
 <Publish Property="LOGON_ERROR" Value="Unexpected Error" Order="4"><![CDATA[(NOT ODBC_CONNECTION_ESTABLISHED) AND (ODBC_ERROR = "")]]></Publish>
 <Publish Property="LOGON_ERROR" Value="[ODBC_ERROR]" Order="4"><![CDATA[NOT ODBC_CONNECTION_ESTABLISHED]]></Publish>
 <Publish Event="SpawnDialog" Value="InvalidLogonDlg" Order="5"><![CDATA[NOT ODBC_CONNECTION_ESTABLISHED]]></Publish>
</Control>
\endcode
*/
CA_API UINT __stdcall ODBC_Connect(MSIHANDLE hInstall);

/*! 

\brief Execute a SQL query, no result set.

\param ODBC_CONNECTION_STRING Connection string.
\param ODBC_SQL_QUERY Query to execute.
\param ODBC_SQL_DELIMITER Batch delimiter. The contents of the SQL file will be split and executed one-by-one. Delimiter is case-insensitive, recognized only at the beginning of line. Either Type or Delimiter may be specified, not both.
\param ODBC_SQL_TYPE Type of the sql script (SqlServer, Oracle, ...). This will set appropriate delimiters for sql splitting, e.g. 'go' for SqlServer; also.will provide support for insertion commands, e.g. ':r' for SqlServer.

This custom action supports impersonation, see \ref impersonate.

*/
CA_API UINT __stdcall ODBC_Execute(MSIHANDLE hInstall);

/*! 

\brief Execute a SQL query, return a string.

\param ODBC_CONNECTION_STRING Connection string.
\param ODBC_SQL_QUERY Query to execute.
\param ODBC_SQL_FLAGS Optional, possible flags are: ODBC_SQL_FLAG_NO_ROWS_RETURN_EMPTY
\return ODBC_SQL_RESULT The returned record.

This custom action supports impersonation, see \ref impersonate.

\par Example: Implementing "Recommend Path" with Microsoft SQL Server

Sometimes your application needs to prompt the user for a specific directory where a database should be installed. 
Most of the time the users want to install the database in the default SQL Server directory. This value is stored
in HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Microsoft SQL Server\\MSSQL.1\\Setup on the server and can be obtained
with the the following T-SQL.

\code
DECLARE @data_dir varchar(500)
EXECUTE master.dbo.xp_instance_regread 'HKEY_LOCAL_MACHINE', 'SOFTWARE\Microsoft\MSSQLServer\Setup', 'SQLDataRoot', @param = @data_dir OUTPUT
SELECT @data_dir
\endcode

The query can be easily incorporated under a "Recommend Path" button in a wix UI using the ODBC_GetString custom action.

\code
<Dialog Id="MSSQLDatabaseRecommendPathDlg" Width="370" Height="270" Title="Database Path Options">
 ...
 <Control Id="DatabaseMDFPathLabel" Type="Text" X="20" Y="85" Height="15" Width="150" Text="Database data file path:" />
 <Control Id="DatabaseMDFPath" Type="Edit" X="30" Y="100" Height="17" Width="320" Property="MSSQL_DATABASE_MDF_PATH" />
 <Control Id="DatabaseLDFPathLabel" Type="Text" X="20" Y="120" Height="15" Width="150" Text="Database log file path:" />
 <Control Id="DatabaseLDFPath" Type="Edit" X="30" Y="135" Height="17" Width="320" Property="MSSQL_DATABASE_LDF_PATH" />
 <Control Id="RecommendPath" Type="PushButton" X="40" Y="155" Width="100" Height="17" Text="Recommend Path">
  <Publish Property="ODBC_CONNECTION_STRING" Value="Driver=SQL Server;Server=.;Trusted_Connection=yes;" Order="1">1</Publish>
  <Publish Property="ODBC_SQL_QUERY" Value="DECLARE @data_dir varchar(500); EXECUTE master.dbo.xp_instance_regread 'HKEY_LOCAL_MACHINE', 'SOFTWARE\Microsoft\MSSQLServer\Setup', 'SQLDataRoot', @param = @data_dir OUTPUT; SELECT @data_dir" Order="1">1</Publish>
  <Publish Event="DoAction" Value="ODBC_GetString" Order="3">1</Publish>
  <Publish Property="MSSQL_DATABASE_MDF_PATH" Value="[ODBC_SQL_RESULT]\[MSSQL_DATABASE_NAME].mdf" Order="4">1</Publish>
  <Publish Property="MSSQL_DATABASE_LDF_PATH" Value="[ODBC_SQL_RESULT]\[MSSQL_DATABASE_NAME].ldf" Order="4">1</Publish>
  <Publish Event="SpawnDialog" Value="CaErrorDlg" Order="5">CA_ERROR</Publish>
 </Control>
 ...
</Dialog>
\endcode

*/
CA_API UINT __stdcall ODBC_GetString(MSIHANDLE hInstall);

/*! 

\brief Execute a SQL query, return a scalar.

\param ODBC_CONNECTION_STRING Connection string.
\param ODBC_SQL_QUERY Query to execute.
\return ODBC_SQL_RESULT The returned scalar.

This custom action supports impersonation, see \ref impersonate.

*/
CA_API UINT __stdcall ODBC_GetScalar(MSIHANDLE hInstall);

/*! 

\brief Execute a SQL query, return xml data set.

\param ODBC_CONNECTION_STRING Connection string.
\param ODBC_SQL_QUERY Query to execute.
\return ODBC_SQL_RESULT The returned data set, in xml format.

The xml data returned looks like this:

\code
<Data columns="number of columns" rows="number of rows">
 <Query>query executed</Query>
 <DataSet>
  <Row>
   <column1>value of column 1</column1>
   <column2>value of column 2</column2>
   ...
  </Row>
  <Row>
   ...
  </Row>
 </DataSet>
</Data>
\endcode

This custom action supports impersonation, see \ref impersonate.

*/
CA_API UINT __stdcall ODBC_GetXml(MSIHANDLE hInstall);

/*! 
\brief Table-driven immediate custom action that executes ODBC statements.
Use in combination with \ref AppSecInc.Wix.Extensions.DataSourceExtension.
*/
CA_API UINT __stdcall Execute_ODBC_Immediate(MSIHANDLE hInstall);

/*! 
\brief Table-driven deferred custom action that executes ODBC statements.
Use in combination with \ref AppSecInc.Wix.Extensions.DataSourceExtension.
*/
CA_API UINT __stdcall Execute_ODBC_Deferred(MSIHANDLE hInstall);

/*! 
\brief Table-driven immediate custom action that manages ODBC datasources.
Use in combination with \ref AppSecInc.Wix.Extensions.DataSourceExtension.
*/
CA_API UINT __stdcall DataSource_ODBC_Immediate(MSIHANDLE hInstall);

/*! 
\brief Table-driven deferred custom action that manages ODBC datasources.
Use in combination with \ref AppSecInc.Wix.Extensions.DataSourceExtension.
*/
CA_API UINT __stdcall DataSource_ODBC_Deferred(MSIHANDLE hInstall);
