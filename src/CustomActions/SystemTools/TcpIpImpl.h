#pragma once

/*! 

\brief Attempts to bind a socket

Attempts to bind a socket, useful for checking whether the socket can or cannot be bound to.

\param TCP_IPADDRESS local TCP/IP address to bind to
\param TCP_PORT local TCP port to bind to

\return TCPIP_BIND_SUCCEEDED. Set to 1 if bind succeeded.
\return check CA_ERROR on function failure

*/
CA_API UINT __stdcall TcpIp_BindSocket(MSIHANDLE hInstall);

/*! 

\brief Attempts to connect to a remote server

Attempts to connect to a remote server, useful for checking whether there's a listening server.
See http://msdn.microsoft.com/en-us/library/ms742212(VS.85).aspx for parameter details.

\param TCP_IPADDRESS remote TCP/IP address to connect to
\param TCP_PORT remote TCP port to connect to
\param TCP_SOCKET_TYPE socket type, one of SOCK_STREAM, SOCK_DGRAM or SOCK_RAW
\param TCP_PROTOCOL, one of IPPROTO_TCP or IPPROTO_UDP

\return TCPIP_CONNECTION_ESTABLISHED. Set to 1 if connection was successfully established.
\return check CA_ERROR on function failure

*/
CA_API UINT __stdcall TcpIp_Connect(MSIHANDLE hInstall);

/*! 

\brief Lists IP address assigned to this host

\param IP_LIST_TYPE List type to populate with data.
\param IP_LIST_PROPERTY The property associated with the list.
\param IP_LIST_INDEX Optional index to start adding items at, default is 2 (assumes one item in the list already).

\return check CA_ERROR on function failure

This function populates an MSI list attached to a property IP_LIST_PROPERTY and of type IP_LIST_TYPE,
beginning with index IP_LIST_INDEX (default is 2, assuming there's one item). It executes SELECT * FROM 
[IP_LIST_TYPE] WHERE Property=[IP_LIST_PROPERTY] to locate the target.

This custom action can be used in combination with a combo box. Call the CA in the InstallUISequence.

\code
<CustomAction Id="SetIpIndex" Property="IP_LIST_INDEX" Value="2" Execute="immediate" />
<CustomAction Id="SetIpProperty" Property="IP_LIST_PROPERTY" Value="BIND_ADDRESS" Execute="immediate" />
<CustomAction Id="SetIpType" Property="IP_LIST_TYPE" Value="ComboBox" Execute="immediate" />
<InstallUISequence>
  <Custom Action="SetIpListProperty" After="CostInitialize" />
  <Custom Action="SetIpListType" After="SetIpListProperty" />
  <Custom Action="SetIpListIndex" After="SetIpListType" />
  <Custom Action="TcpIp_ListAddresses" After="SetIpListIndex">NOT Installed</Custom>
</InstallUISequence>
\endcode

Use a ComboBox control in the UI.

\code
<Control Id="Server" Type="ComboBox" X="30" Y="65" Width="200" Height="18" Property="BIND_ADDRESS">
  <ComboBox Property="BIND_ADDRESS">
    <ListItem Text="0.0.0.0" Value="0.0.0.0" />
  </ComboBox>
</Control>
\endcode

*/
CA_API UINT __stdcall TcpIp_ListAddresses(MSIHANDLE hInstall);