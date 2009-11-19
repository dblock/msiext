#pragma once

/*! 

\brief The directory object picker dialog box custom action enables a user to select one or more Active Directory objects.

\param DSOP_SCOPE_TYPES Comma-separated scope types. You can combine multiple scope types if all specified scopes use the same 
 settings. See http://msdn2.microsoft.com/en-us/library/ms676014(VS.85).aspx for details.
\param DSOP_SCOPE_FLAGS Comma-separated scope flags that indicate the format used to return ADsPath for objects selected from 
 this scope. See http://msdn2.microsoft.com/en-us/library/ms676014(VS.85).aspx for details.
\param DSOP_SCOPE_FILTER_FLAGS Comma-separated scope filter flags that indicate the types of objects presented to the user for a 
 specified scope or scopes. See http://msdn2.microsoft.com/en-us/library/ms676012(VS.85).aspx for details.
\param DSOP_DOWNLEVEL_SCOPE_FILTER_FLAGS Comma-separated downlevel scope filter flags.
 See http://msdn2.microsoft.com/en-us/library/ms676012(VS.85).aspx for details.

\return DSOP_NAME The object's relative distinguished name (RDN).
\return DSOP_CLASS The object's ADsPath.
\return DSOP_ADSPATH The value of the object's objectClass attribute.
\return DSOP_UPN Object's userPrincipalName attribute value.

The directory object picker dialog box enables a user to select one or more objects from either the global catalog, 
a Microsoft Windows 2000 domain or computer, a Microsoft Windows NT 4.0 domain or computer, or a workgroup. 
The object types from which a user can select include user, contact, group, and computer objects.
http://msdn2.microsoft.com/en-us/library/ms675899(VS.85).aspx

For users:

    DSOP_SCOPE_TYPES = DSOP_SCOPE_TYPE_TARGET_COMPUTER|DSOP_SCOPE_TYPE_EXTERNAL_UPLEVEL_DOMAIN|DSOP_SCOPE_TYPE_ENTERPRISE_DOMAIN
    DSOP_SCOPE_FLAGS = DSOP_SCOPE_FLAG_STARTING_SCOPE|DSOP_SCOPE_FLAG_DEFAULT_FILTER_USERS
    DSOP_SCOPE_FILTER_FLAGS = DSOP_FILTER_USERS
    DSOP_DOWNLEVEL_SCOPE_FILTER_FLAGS = DSOP_DOWNLEVEL_FILTER_USERS

For computers:

    DSOP_SCOPE_TYPES = DSOP_SCOPE_TYPE_USER_ENTERED_UPLEVEL_SCOPE|DSOP_SCOPE_TYPE_USER_ENTERED_DOWNLEVEL_SCOPE|DSOP_SCOPE_TYPE_GLOBAL_CATALOG|DSOP_SCOPE_TYPE_EXTERNAL_UPLEVEL_DOMAIN|DSOP_SCOPE_TYPE_EXTERNAL_DOWNLEVEL_DOMAIN|DSOP_SCOPE_TYPE_WORKGROUP|DSOP_SCOPE_TYPE_UPLEVEL_JOINED_DOMAIN|DSOP_SCOPE_TYPE_DOWNLEVEL_JOINED_DOMAIN
    DSOP_SCOPE_FLAGS = 
    DSOP_SCOPE_FILTER_FLAGS = DSOP_FILTER_COMPUTERS
    DSOP_DOWNLEVEL_SCOPE_FILTER_FLAGS = DSOP_DOWNLEVEL_FILTER_COMPUTERS

\par Example:

The following code includes the custom action binary and declares the custom action entry point.

\code
<CustomAction Id="DirectoryObjectPicker" BinaryKey="ActiveDirectory" DllEntry="DirectoryObjectPicker" Execute="immediate" Return="check" />
<Binary Id="ActiveDirectory" SourceFile="$(var.BinDir)\ActiveDirectory.dll" />
\endcode

The following code adds a Browse for users button to a Wix UI.

\code
<Control Id="UsernameBrowse" Type="PushButton" X="235" Y="120" Width="75" Height="17" Text="&amp;Browse ...">
 <Publish Property="DSOP_SCOPE_TYPES" Value="DSOP_SCOPE_TYPE_TARGET_COMPUTER|DSOP_SCOPE_TYPE_ENTERPRISE_DOMAIN" Order="1">1</Publish>
 <Publish Property="DSOP_SCOPE_FLAGS" Value="DSOP_SCOPE_FLAG_STARTING_SCOPE|DSOP_SCOPE_FLAG_DEFAULT_FILTER_USERS" Order="1">1</Publish>
 <Publish Property="DSOP_SCOPE_FILTER_FLAGS" Value="DSOP_FILTER_USERS" Order="1">1</Publish>
 <Publish Property="DSOP_DOWNLEVEL_SCOPE_FILTER_FLAGS" Value="DSOP_DOWNLEVEL_FILTER_USERS" Order="1">1</Publish>
 <Publish Event="DoAction" Value="DirectoryObjectPicker" Order="2">1</Publish>
 <Publish Property="SERVICE_USERNAME" Value="[DSOP_UPN]" Order="3"><![CDATA[DSOP_UPN <> ""]]></Publish>
 <Publish Property="SERVICE_USERNAME" Value="[DSOP_NAME]" Order="3"><![CDATA[DSOP_NAME <> "" AND DSOP_UPN = ""]]></Publish>
</Control>
\endcode

*/
CA_API UINT __stdcall DirectoryObjectPicker(MSIHANDLE hInstall);
