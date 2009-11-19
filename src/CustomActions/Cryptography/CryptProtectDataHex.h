#pragma once

/*!
\brief CryptProtectDataHex protects the data with a user or machine key and returns hex-encoded value of the data.

\param CRYPTPROTECT_DATA Data to protect.
\param CRYPTPROTECT_ENTROPY Optional entropy.
\param CRYPTPROTECT_FLAGS Flags to pass to CryptProtectData.
    \li CRYPTPROTECT_LOCAL_MACHINE When this flag is set, 
        it associates the data encrypted with the current computer instead of with an individual user. 
        Any user on the computer on which CryptProtectData is called can use CryptUnprotectData to decrypt the data.
    \li CRYPTPROTECT_UI_FORBIDDEN This flag is used for remote situations where presenting a user interface (UI) 
        is not an option. When this flag is set and a UI is specified for either the protect or unprotect operation,
        the operation fails.
    \li CRYPTPROTECT_AUDIT This flag generates an audit on protect and unprotect operations.
    \li CRYPTPROTECT_VERIFY_PROTECTION This flag verifies the protection of a protected BLOB.
\param CRYPTPROTECT_DESCRIPTION Optional description of protect data (stored in clear).
\return CRYPTPROTECT_RESULT Hex-encoded protected data.

\par Example:

\code

	<Binary Id="Cryptography" SourceFile="relative path to Cryptography.dll"/>
	<Property Id="CRYPTPROTECT_DATA" Hidden="yes" />
	<Property Id="CRYPTPROTECT_FLAGS" Value="CRYPTPROTECT_LOCAL_MACHINE CRYPTPROTECT_UI_FORBIDDEN" />
	<CustomAction Id="EncryptPassword" BinaryKey="Cryptography" DllEntry="CryptProtectDataHex"Execute="immediate" />
	<CustomAction Id="SetDBUSERsPASSWORDForEncryption"Property="CRYPTPROTECT_DATA" Value="[PASSWORD]" />
	<InstallExecuteSequence> 
	  <Custom Action="SetDBUSERsPASSWORDForEncryption" After="InstallInitialize" />
	  <Custom Action="EncryptPassword" After="SetDBUSERsPASSWORDForEncryption" />
	</InstallExecuteSequence>

\endcode


*/
CA_API UINT __stdcall CryptProtectDataHex(MSIHANDLE hInstall);

/*!
\brief CryptUnprotectDataHex unprotects hex-encoded data with a user or machine key and returns value of the data.

\param CRYPTUNPROTECT_DATA Data to unprotect.
\param CRYPTUNPROTECT_ENTROPY Optional entropy.
\param CRYPTUNPROTECT_FLAGS Flags to pass to CryptUnrotectData.
    \li CRYPTPROTECT_LOCAL_MACHINE When this flag is set, 
        it associates the data encrypted with the current computer instead of with an individual user. 
        Any user on the computer on which CryptProtectData is called can use CryptUnprotectData to decrypt the data.
    \li CRYPTPROTECT_UI_FORBIDDEN This flag is used for remote situations where presenting a user interface (UI) 
        is not an option. When this flag is set and a UI is specified for either the protect or unprotect operation,
        the operation fails.
    \li CRYPTPROTECT_AUDIT This flag generates an audit on protect and unprotect operations.
    \li CRYPTPROTECT_VERIFY_PROTECTION This flag verifies the protection of a protected BLOB.
\return CRYPTUNPROTECT_RESULT Unprotected data.
\return CRYPTUNPROTECT_DESCRIPTION Associated description.

\par Example:

\code

	<Binary Id="Cryptography" SourceFile="relative path to Cryptography.dll"/>
	<Property Id="CRYPTUNPROTECT_FLAGS" Value="CRYPTPROTECT_LOCAL_MACHINE|CRYPTPROTECT_UI_FORBIDDEN" />
	<CustomAction Id="DecryptPassword" BinaryKey="Cryptography" DllEntry="CryptUnProtectDataHex"Execute="immediate" />
	<CustomAction Id="SetDBUSERsDecryptedPASSWORD"Property="PASSWORD" Value="[CRYPTUNPROTECT_RESULT]"/>
	<InstallExecuteSequence> 
	  <Custom Action="DecryptPassword" After="InstallInitialize"/>
	  <Custom Action="SetDBUSERsDecryptedPASSWORD" After="DecryptPassword"/>
	</InstallExecuteSequence>

\endcode

*/
CA_API UINT __stdcall CryptUnprotectDataHex(MSIHANDLE hInstall);

