#pragma once

/*!
\brief Custom action to verify whether user logon credentials are valid via ::LogonUser.
\param LOGON_USERNAME Username
\param LOGON_PASSWORD Password
\param LOGON_TYPE Type of logon, default is LOGON32_LOGON_NETWORK
\return LOGON_VALID 1 if logon is valid, 0 otherwise
\return LOGON_ERROR an OS-formatted error string when available

\par Example:

The following code includes the UserPrivileges custom actoin binary and declares the CheckCredentials custom action.

\code
<CustomAction Id="CheckCredentials" BinaryKey="UserPrivileges" DllEntry="CheckCredentials" Execute="immediate" Return="check" />
<Binary Id="UserPrivileges" SourceFile="$(var.BinDir)\UserPrivileges.dll" />
\endcode

The following code checks user credentials.

\code
<Control Id="Test" Type="PushButton" X="40" Y="200" Width="100" Height="17" Text="&amp;Test Credentials">
 <Publish Property="LOGON_USERNAME" Value="[SERVICE_USERNAME]" Order="1">1</Publish>
 <Publish Property="LOGON_PASSWORD" Value="[SERVICE_PASSWORD]" Order="1">1</Publish>
 <Publish Event="DoAction" Value="CheckCredentials" Order="2">1</Publish>
 <Publish Property="LOGON_VALID" Value="[LOGON_VALID]" Order="3">1</Publish>
 <Publish Property="LOGON_ERROR" Value="Invalid Logon" Order="3"><![CDATA[LOGON_ERROR = "" AND LOGON_VALID = "0"]]></Publish>
</Control>
\endcode

The LOGON_VALID and LOGON_ERROR properties are helpful to trigger an error dialog where appropriate.

\code
<Dialog Id="InvalidLogonDlg" Width="260" Height="85" Title="Invalid Logon">
 <Control Id="Return" Type="PushButton" X="102" Y="57" Width="56" Height="17" Default="yes" Cancel="yes" Text="OK">
  <Publish Event="EndDialog" Value="Return">1</Publish>
 </Control>
 <Control Id="Text" Type="Text" X="48" Y="15" Width="194" Height="30" Text="[LOGON_ERROR]" />
 <Control Id="Icon" Type="Icon" X="15" Y="15" Width="24" Height="24" FixedSize="yes" IconSize="32" Text="WixUI_Ico_Exclam" />
</Dialog>
\endcode

\code
<Control Id="Test" Type="PushButton" X="40" Y="200" Width="100" Height="17" Text="&amp;Test Credentials">
 ...
 <Publish Event="SpawnDialog" Value="InvalidLogonDlg" Order="8"><![CDATA[LOGON_VALID = "0"]></Publish>
</Control>
\endcode

This custom action supports impersonation, see \ref impersonate.

*/
CA_API UINT __stdcall CheckCredentials(MSIHANDLE hInstall);
