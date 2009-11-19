/*!
\brief Process local users (immediate).
This is a table-driven custom action. 
Use in combination with \ref AppSecInc.Wix.Extensions.UserPrivilegesExtension.
*/
CA_API UINT __stdcall LocalUsers_Immediate(MSIHANDLE hInstall);

/*!
\brief Process local users (deferred).
This is a table-driven custom action. 
Use in combination with \ref AppSecInc.Wix.Extensions.UserPrivilegesExtension.
*/
CA_API UINT __stdcall LocalUsers_Deferred(MSIHANDLE hInstall);
