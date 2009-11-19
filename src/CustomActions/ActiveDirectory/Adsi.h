#pragma once

/*! 
\brief Get an attribute value from Active Directory

\param ADSI_LDAP_PATH  The path used to bind to the object in the underlying directory service, defaults to LDAP://RootDSE.
\param ADSI_PROPERTY_NAME The property to fetch.

\return ADSI_PROPERTY_VALUE The value of the Active Directory property.

\par Example:

The following example uses DirectoryGetDcName to find a domain controller and ADSI_GetAttributeValue to get its
distinguishedName property value.

\code
 <!-- find active directory -->
 <CustomAction Id="SetDSFlags" Property="DS_FLAGS" Value="DS_IP_REQUIRED|DS_ONLY_LDAP_NEEDED|DS_RETURN_DNS_NAME" />
 <CustomAction Id="FindActiveDirectory" BinaryKey="ActiveDirectory" DllEntry="DirectoryGetDcName" Execute="immediate" Return="check" />
 <!-- find distinguishedName -->
 <CustomAction Id="SetLdapPath" Property="ADSI_LDAP_PATH" Value="LDAP://[DS_DOMAINCONTROLLER_NAME]" />
 <CustomAction Id="SetAdsiPropertyName" Property="ADSI_PROPERTY_NAME" Value="distinguishedName" />
 <CustomAction Id="GetAdsiPropertyValue" BinaryKey="ActiveDirectory" DllEntry="ADSI_GetAttributeValue" Execute="immediate" Return="check" />
 <CustomAction Id="SetDN" Property="ACTIVE_DIRECTORY_SERVER_DN" Value="[ADSI_PROPERTY_VALUE]" />
 <InstallUISequence>
  <!-- find active directory -->
  <Custom Action="SetDSFlags" After="CostInitialize">1</Custom>
  <Custom Action="FindActiveDirectory" After="SetDSFlags">1</Custom>
  <!-- find distinguishedName -->
  <Custom Action="SetLdapPath" After="SetActiveDirectory">1</Custom>
  <Custom Action="SetAdsiPropertyName" After="SetLdapPath">1</Custom>
  <Custom Action="GetAdsiPropertyValue" After="SetAdsiPropertyName">1</Custom>
  <Custom Action="SetDN" After="SetAdsiPropertyName">1</Custom>
 </InstallUISequence>
\endcode

*/
CA_API UINT __stdcall ADSI_GetAttributeValue(MSIHANDLE hInstall);
