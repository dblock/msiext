#pragma once

/*! 
\brief Custom action to determine whether a specified security identifier (SID) is enabled in the impersonation token of the calling thread.
\param SID Sid to check. The function checks for the presence of this SID in the user and group SIDs of the impersonation token of the calling thread.
\return LOGON_IS_MEMBER 1 if the SID is present and has the SE_GROUP_ENABLED attribute, 0 otherwise.
\return CA_ERROR system error when available.

For a list of well known SIDs on Windows, refer to http://support.microsoft.com/kb/243330

\par Example:

The following code includes the UserPrivileges custom action binary and declares the CheckMembership custom action.

\code
<CustomAction Id="CheckMembership" BinaryKey="UserPrivileges" DllEntry="CheckMembership" Execute="immediate" Return="check" />
<Binary Id="UserPrivileges" SourceFile="$(var.BinDir)\UserPrivileges.dll" />
\endcode

The following code checks whether a user is a member of the Administrators local group.

\code
<Control Id="Test" Type="PushButton" X="40" Y="200" Width="100" Height="17" Text="&amp;Test Membership">
 <!-- check whether this user is an administrator -->
 <Publish Property="IMPERSONATE_USERNAME" Value="[SCANENGINE_SERVICE_USERNAME]">1</Publish>
 <Publish Property="IMPERSONATE_PASSWORD" Value="[SCANENGINE_SERVICE_PASSWORD]">1</Publish>
 <Publish Property="SID" Value="S-1-5-32-544">1</Publish>
 <Publish Event="DoAction" Value="Service_CheckMembership">1</Publish>
 <Publish Property="LOGON_ERROR" Value="The specified account is not a member of the Administrators group."><![CDATA[LOGON_IS_MEMBER = "0"]]></Publish>
</Control>
\endcode

This custom action supports impersonation, see \ref impersonate.

*/
CA_API UINT __stdcall CheckMembership(MSIHANDLE hInstall);
