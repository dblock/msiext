#pragma once

/*!
\brief Process templace files (immediate).
This is a table-driven custom action. 
Use in combination with \ref AppSecInc.Wix.Extensions.SystemToolsExtension.
*/
CA_API UINT __stdcall TemplateFiles_Immediate(MSIHANDLE hInstall);

/*!
\brief Process templace files (deferred).
This is a table-driven custom action. 
Use in combination with \ref AppSecInc.Wix.Extensions.SystemToolsExtension.
*/
CA_API UINT __stdcall TemplateFiles_Deferred(MSIHANDLE hInstall);

