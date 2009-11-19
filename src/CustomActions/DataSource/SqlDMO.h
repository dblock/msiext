#pragma once

/*! 

\brief Enumerate available SQL servers using Data Management Objects (DMO).

\param SQLDMO_LIST_TYPE List type to populate with data.
\param SQLDMO_LIST_PROPERTY The property associated with the list.
\param SQLDMO_LIST_INDEX Optional index to start adding items at, default is 2 (assumes one item in the list already).
\param SQLDMO_LIST_LOCAL Optional name to skip, eg. useful for local servers with "(local)".

This function populates an MSI list attached to a property SQLDMO_LIST_PROPERTY and of type SQLDMO_LIST_TYPE,
beginning with index SQLDMO_LIST_INDEX (default is 2, assuming there's one item). It executes SELECT * FROM 
[SQLDMO_LIST_TYPE] WHERE Property=[SQLDMO_LIST_PROPERTY] to locate the target.

See http://support.microsoft.com/kb/287737 for details about retreiving SQL servers with DMO.

This custom action can be used in combination with a combo box. Call the CA in the InstallUISequence.

\code
<CustomAction Id="SetSqlDmoListLocal" Property="SQLDMO_LIST_LOCAL" Value="(local)" Execute="immediate" />
<CustomAction Id="SetSqlDmoListIndex" Property="SQLDMO_LIST_INDEX" Value="2" Execute="immediate" />
<CustomAction Id="SetSqlDmoListProperty" Property="SQLDMO_LIST_PROPERTY" Value="DATABASE_SERVER" Execute="immediate" />
<CustomAction Id="SetSqlDmoListType" Property="SQLDMO_LIST_TYPE" Value="ComboBox" Execute="immediate" />
<InstallUISequence>
  <Custom Action="SetSqlDmoListProperty" After="CostInitialize" />
  <Custom Action="SetSqlDmoListType" After="SetSqlDmoListProperty" />
  <Custom Action="SetSqlDmoListIndex" After="SetSqlDmoListType" />
  <Custom Action="SetSqlDmoListLocal" After="SetSqlDmoListIndex" />
  <Custom Action="SQLDMO_ListAvailableSQLServers" After="SetSqlDmoListType">NOT Installed</Custom>
</InstallUISequence>
\endcode

Use a ComboBox control in the UI.

\code
<Control Id="Server" Type="ComboBox" X="30" Y="65" Width="200" Height="18" Property="DATABASE_SERVER">
  <ComboBox Property="DATABASE_SERVER">
    <ListItem Text="(local)" Value="(local)" />
  </ComboBox>
</Control>
\endcode

*/
CA_API UINT __stdcall SQLDMO_ListAvailableSQLServers(MSIHANDLE hInstall);
