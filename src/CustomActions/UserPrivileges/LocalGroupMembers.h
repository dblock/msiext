/*!
\brief Process local group members (immediate).
This is a table-driven custom action. 
Use in combination with \ref AppSecInc.Wix.Extensions.UserPrivilegesExtension.
*/
CA_API UINT __stdcall LocalGroupMembers_Immediate(MSIHANDLE hInstall);

/*!
\brief Process local group members (deferred).
This is a table-driven custom action. 
Use in combination with \ref AppSecInc.Wix.Extensions.UserPrivilegesExtension.
*/
CA_API UINT __stdcall LocalGroupMembers_Deferred(MSIHANDLE hInstall);
