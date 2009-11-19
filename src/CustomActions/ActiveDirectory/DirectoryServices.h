#pragma once

/*! 
\brief The DsGetDcName function returns the name of a domain controller in a specified domain. 

The DsGetDcName function returns the name of a domain controller in a specified domain. 
This function accepts additional domain controller selection criteria to indicate preference 
for a domain controller with particular characteristics.

\param DS_COMPUTERNAME Optional string that specifies the name of the server to process this function.
\param DS_DOMAINNAME Optional string that specifies the name of the domain or application partition to query.
\param DS_SITENAME Optional string that specifies the name of the site where the returned domain controller should physically exist. 
\param DS_FLAGS Contains a set of flags that provide additional data used to process the request.

\return DS_DOMAINCONTROLLER_NAME Specifies the computer name of the discovered domain controller, stripped from heading backslashes.
\return DS_DOMAINCONTROLLER_ADDRESS Specifies the address of the discovered domain controller, stripped from heading backslashes.
\return DS_DOMAIN_NAME Specifies the name of the domain.

See http://msdn.microsoft.com/en-us/library/ms675912(VS.85).aspx for details about flags and parameters.

\par Example:

\code
<Binary Id="ActiveDirectory" SourceFile="$(var.BinDir)\ActiveDirectory.dll" />
<CustomAction Id="SetDSFlags" Property="DS_FLAGS" Value="DS_IP_REQUIRED|DS_ONLY_LDAP_NEEDED|DS_RETURN_DNS_NAME" />
<CustomAction Id="FindActiveDirectory" BinaryKey="ActiveDirectory" DllEntry="DirectoryGetDcName" Execute="immediate" Return="check" />
<CustomAction Id="SetActiveDirectoryProperty" Property="ACTIVE_DIRECTORY_SERVER_DISPLAYED" Value="[DS_DOMAINCONTROLLER_NAME]" />
<InstallUISequence>
 <Custom Action="SetDSFlags" After="CostInitialize">1</Custom>
 <Custom Action="FindActiveDirectory" After="SetDSFlags">1</Custom>
 <Custom Action="SetActiveDirectoryProperty" After="FindActiveDirectory">1</Custom>
</InstallUISequence>
\endcode

*/
CA_API UINT __stdcall DirectoryGetDcName(MSIHANDLE hInstall);
