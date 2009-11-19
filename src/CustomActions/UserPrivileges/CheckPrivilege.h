#pragma once

/*! 
\brief Custom action to verify whether user has a certain privilege.
\param ComputerName Local computer name, inherited from MSI properties.
\param LOGON_USERNAME Username
\param LOGON_PRIVILEGE Privilege, eg. SeServiceLogonRight
\return LOGON_HAS_PRIVILEGE 1 if user has the privilege, 0 otherwise
\return CA_ERROR system error when available

\par Example:

The following code includes the UserPrivileges custom action binary and declares the CheckPrivilege custom action.

\code
<CustomAction Id="CheckPrivilege" BinaryKey="UserPrivileges" DllEntry="CheckPrivilege" Execute="immediate" Return="check" />
<Binary Id="UserPrivileges" SourceFile="$(var.BinDir)\UserPrivileges.dll" />
\endcode

The following code checks whether a user has logon as a service privilege.

\code
<Control Id="Test" Type="PushButton" X="40" Y="200" Width="100" Height="17" Text="&amp;Test Credentials">
 <Publish Property="LOGON_USERNAME" Value="[SERVICE_USERNAME]" Order="1">1</Publish>
 <Publish Property="LOGON_PRIVILEGE" Value="SeServiceLogonRight" Order="1">1</Publish>
 <Publish Event="DoAction" Value="CheckPrivilege" Order="2">1</Publish>
 <Publish Property="LOGON_ERROR" Value="This account does not have logon as a service right. [CA_ERROR]" Order="3"><![CDATA[LOGON_HAS_PRIVILEGE = "0"]]></Publish>
</Control>
\endcode

This custom action supports impersonation, see \ref impersonate.

*/
CA_API UINT __stdcall CheckPrivilege(MSIHANDLE hInstall);
