#pragma once

/*!

\brief Get current user information, including SID and DNS name

\return USER_FQN DNS domain name followed by a backward-slash and the SAM username
\return USER_NAME full username, includes the domain for domain users
\return USER_DOMAIN qualified domain from LookupAccountName
\return USER_SID user SID

This custom action supports impersonation, see \ref impersonate.

*/
CA_API UINT __stdcall GetUserInfo(MSIHANDLE hInstall);

/*!

\brief Get current user name in a specific format

\param USERNAME_FORMAT username format, one of EXTENDED_NAME_FORMAT, see http://msdn.microsoft.com/en-us/library/ms724268(VS.85).aspx
 \li \b NameFullyQualifiedDN The fully-qualified distinguished name (for example, CN=Jeff Smith,OU=Users,DC=Engineering,DC=Microsoft,DC=Com).
 \li \b NameSamCompatible A legacy account name (for example, Engineering\\JSmith). The domain-only version includes trailing backslashes (\\\\).
 \li \b NameDisplay A "friendly" display name (for example, Jeff Smith). The display name is not necessarily the defining relative distinguished name (RDN).
 \li \b NameUniqueId A GUID string that the IIDFromString function returns (for example, {4fa050f0-f561-11cf-bdd9-00aa003a77b6}).
 \li \b NameCanonical The complete canonical name (for example, engineering.microsoft.com/software/someone). The domain-only version includes a trailing forward slash (/).
 \li \b NameUserPrincipal The user principal name (for example, someone@example.com).
 \li \b NameCanonicalEx The same as NameCanonical except that the rightmost forward slash (/) is replaced with a new line character (\n), even in a domain-only case (for example, engineering.microsoft.com/software\\nJSmith).
 \li \b NameServicePrincipal The generalized service principal name (for example, www/www.microsoft.com@microsoft.com).
 \li \b NameDnsDomain The DNS domain name followed by a backward-slash and the SAM username.
\return USER_FQN fully qualified username

This custom action supports impersonation, see \ref impersonate.

\par Obtaining Full DNS Username

When trying to obtain the complete username for a user, call \ref GetUserInfo. If you want to get
the DNS username instead of the SAM username, also call \ref GetUserNameFormatted with 
<em>NameDnsDomain</em>. The latter call will fail for a local user, ignore its return code.

\code
<Binary Id="UserPrivileges" SourceFile="$(var.BinDir)\UserPrivileges.dll" />
<CustomAction Id="GetUserInfo" BinaryKey="UserPrivileges" DllEntry="GetUserInfo" Execute="immediate" Return="check" />
<CustomAction Id="GetUserNameFormatted" BinaryKey="UserPrivileges" DllEntry="GetUserNameFormat" Execute="immediate" Return="ignore" />

<!-- general username properties -->
<Publish Event="DoAction" Value="GetUserInfo" Order="1">1</Publish>
<!-- username in the DNS domain format -->
<Publish Property="USERNAME_FORMAT" Value="NameDnsDomain" Order="2">1</Publish>
<Publish Event="DoAction" Value="GetUserNameFormatted" Order="3">1</Publish>
<Publish Property="USERNAME_DNSDOMAIN" Value="[USER_FQN]" Order="4">1</Publish>
<!-- either keep USER_NAME or USERNAME_DNSDOMAIN -->
<Publish Property="USERNAME_FULL" Value="[USERNAME_DNSDOMAIN]" Order="5">1</Publish>
<Publish Property="USERNAME_FULL" Value="[USER_NAME]" Order="6">NOT USERNAME_FULL</Publish>
\endcode

*/
CA_API UINT __stdcall GetUserNameFormatted(MSIHANDLE hInstall);
