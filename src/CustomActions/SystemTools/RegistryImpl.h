#pragma once

/*! 

\brief Copy a full registry branch
\param REGISTRY_ROOT One of HKEY_LOCAL_MACHINE, HKEY_CURRENT_USER, etc
\param REGISTRY_PATH_SOURCE A registry path under REGISTRY_ROOT to copy from
\param REGISTRY_ROOT_TARGET An optional registry target, one of HKEY_LOCAL_MACHINE, HKEY_CURRENT_USER, etc.
\param REGISTRY_PATH_TARGET A registry path under REGISTRY_ROOT to copy to
\return check CA_ERROR on function failure

*/
CA_API UINT __stdcall Registry_CopyBranch(MSIHANDLE hInstall);

/*! 

\brief Move a full registry branch
\param REGISTRY_ROOT One of HKEY_LOCAL_MACHINE, HKEY_CURRENT_USER, etc
\param REGISTRY_PATH_SOURCE A registry path under REGISTRY_ROOT to move from
\param REGISTRY_ROOT_TARGET An optional registry target, one of HKEY_LOCAL_MACHINE, HKEY_CURRENT_USER, etc.
\param REGISTRY_PATH_TARGET A registry path under REGISTRY_ROOT to move to
\return check CA_ERROR on function failure

*/
CA_API UINT __stdcall Registry_MoveBranch(MSIHANDLE hInstall);

/*! 

\brief Delete a full registry branch
\param REGISTRY_ROOT One of HKEY_LOCAL_MACHINE, HKEY_CURRENT_USER, etc
\param REGISTRY_PATH A registry path under REGISTRY_ROOT to delete
\return check CA_ERROR on function failure

*/
CA_API UINT __stdcall Registry_DeleteBranch(MSIHANDLE hInstall);

/*! 

\brief Creates a registry key
\param REGISTRY_ROOT One of HKEY_LOCAL_MACHINE, HKEY_CURRENT_USER, etc
\param REGISTRY_PATH A registry path under REGISTRY_ROOT that has to be created
\return check CA_ERROR on function failure

*/
CA_API UINT __stdcall Registry_CreateKey(MSIHANDLE hInstall);

/*! 

\brief Delete a full registry branch
\param REGISTRY_ROOT One of HKEY_LOCAL_MACHINE, HKEY_CURRENT_USER, etc
\param REGISTRY_PATH A registry path under REGISTRY_ROOT where the name has to be set
\param REGISTRY_NAME The name for which the value has to be set
\param REGISTRY_VALUE The value
\return check CA_ERROR on function failure

*/
CA_API UINT __stdcall Registry_SetStringValue(MSIHANDLE hInstall);

/*! 

\brief Check if a registry key exists
\param REGISTRY_ROOT One of HKEY_LOCAL_MACHINE, HKEY_CURRENT_USER, etc
\param REGISTRY_PATH A registry path under REGISTRY_ROOT
\param REGISTRY_NAME Name. Set it to an empty value for checking only the key.
\return check CA_ERROR on function failure

*/
CA_API UINT __stdcall Registry_KeyExists(MSIHANDLE hInstall);

/*! 
\brief Copy registry keys.
This is a table-driven custom action. 
Use in combination with \ref AppSecInc.Wix.Extensions.SystemToolsExtension.
*/
CA_API UINT __stdcall Win32_RegistryCopy_Immediate(MSIHANDLE hInstall);
CA_API UINT __stdcall Win32_RegistryCopy_Deferred(MSIHANDLE hInstall);
