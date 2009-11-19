/*!
\brief Process local groups (immediate).
This is a table-driven custom action. 
Use in combination with \ref AppSecInc.Wix.Extensions.UserPrivilegesExtension.
*/
CA_API UINT __stdcall LocalGroups_Immediate(MSIHANDLE hInstall);

/*!
\brief Process local groups (deferred).
This is a table-driven custom action. 
Use in combination with \ref AppSecInc.Wix.Extensions.UserPrivilegesExtension.
*/
CA_API UINT __stdcall LocalGroups_Deferred(MSIHANDLE hInstall);
