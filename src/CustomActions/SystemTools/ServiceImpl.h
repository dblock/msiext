#pragma once

/*! 

\brief Renames the registry entry of a service

Renames HKLM\SYSTEM\CurrentControlSet\Services\SERVICE_RENAME_REGISTRY_ENTRY_FROM to 
HKLM\SYSTEM\CurrentControlSet\Services\SERVICE_RENAME_REGISTRY_ENTRY_TO.

\param SERVICE_RENAME_REGISTRY_ENTRY_FROM current service name in the registry
\param SERVICE_RENAME_REGISTRY_ENTRY_TO new service name in the registry

\return check CA_ERROR on function failure

*/
CA_API UINT __stdcall Service_RenameRegistryEntry(MSIHANDLE hInstall);

/*! 

\brief Change the path to the service binary file of a service

The path to the service binary file of the service specified in
SERVICE_CHANGE_SERVICE_NAME is set to SERVICE_CHANGE_BINARY_PATH_NAME.

\param SERVICE_CHANGE_SERVICE_NAME name of the service
\param SERVICE_CHANGE_BINARY_PATH_NAME new fully qualified path to the service binary file.

\return check CA_ERROR on function failure

*/
CA_API UINT __stdcall Service_ChangeBinaryPathName(MSIHANDLE hInstall);

/*! 

\brief Change the display name of a service

Changes the display name of the service specified in SERVICE_CHANGE_SERVICE_NAME.
The display name is changed to SERVICE_CHANGE_DISPLAY_NAME.

\param SERVICE_CHANGE_SERVICE_NAME name of the service
\param SERVICE_CHANGE_DISPLAY_NAME new display name

\return check CA_ERROR on function failure

*/
CA_API UINT __stdcall Service_ChangeDisplayName(MSIHANDLE hInstall);

/*! 

\brief Change the description of a service

Changes the description of the service specified in SERVICE_CHANGE_SERVICE_NAME.
The description is changed to SERVICE_CHANGE_DESCRIPTION.

\param SERVICE_CHANGE_SERVICE_NAME name of the service
\param SERVICE_CHANGE_DESCRIPTION new description

\return check CA_ERROR on function failure

*/
CA_API UINT __stdcall Service_ChangeDescription(MSIHANDLE hInstall);

/*! 

\brief Control (start/stop/pause/continue) a service
\param SERVICE_NAME service name
\param SERVICE_CONTROL action, one of SERVICE_CONTROL_START, SERVICE_CONTROL_STOP, SERVICE_CONTROL_PAUSE, SERVICE_CONTROL_CONTINUE

*/
CA_API UINT __stdcall Service_Control(MSIHANDLE hInstall);

/*! 

\brief Delete a service
\param SERVICE_NAME service name

*/
CA_API UINT __stdcall Service_Delete(MSIHANDLE hInstall);

/*! 

\brief Get service configuration
\param SERVICE_NAME service name
\return SERVICE_BINARY_PATH_NAME fully qualified path to the service binary file
\return SERVICE_ERROR_CONTROL severity of the error and action taken, one of SERVICE_ERROR_IGNORE, SERVICE_ERROR_NORMAL, SERVICE_ERROR_SEVERE or SERVICE_ERROR_CRITICAL
\return SERVICE_LOAD_ORDER_GROUP the load ordering group to which this service belongs
\return SERVICE_DISPLAY_NAME the display name to be used by service control programs to identify the service
\return SERVICE_START_NAME name of the account that the service process will be logged on as when it runs or the driver object name which the I/O system uses to load the device driver
\return SERVICE_TYPE type of service, one of SERVICE_FILE_SYSTEM_DRIVER, SERVICE_KERNEL_DRIVER, SERVICE_WIN32_OWN_PROCESS, SERVICE_WIN32_SHARE_PROCESS or SERVICE_INTERACTIVE_PROCESS
\return SERVICE_START_TYPE service start time, one of SERVICE_AUTO_START, SERVICE_BOOT_START, SERVICE_DEMAND_START, SERVICE_DISABLED or SERVICE_SYSTEM_START
\return SERVICE_TAG_ID unique tag value for this service in the group 
\return SERVICE_DEPENDENCIES comma-separated list of dependencies
*/
CA_API UINT __stdcall Service_GetConfig(MSIHANDLE hInstall);

/*! 

\brief Check whether a service exists
\param SERVICE_NAME service name
\return SERVICE_EXISTS set to "1" if service exists, "0" otherwise
*/
CA_API UINT __stdcall Service_Exists(MSIHANDLE hInstall);

/*! 

\brief Get status of a service
\param SERVICE_NAME service name
\return SERVICE_STATUS set to one of: Stopped, Starting, Stopping, Running, Resuming, Pausing, Paused depending on the current service state. If service does not exist SERVICE_STATUS is set to Absent.
*/
CA_API UINT __stdcall Service_GetStatus(MSIHANDLE hInstall);

