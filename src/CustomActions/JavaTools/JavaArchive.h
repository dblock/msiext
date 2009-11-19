#pragma once

/*! 

\brief Java archive (immediate custom action)

Use in combination with \ref WixJavaArchiveExtension.

*/
CA_API UINT __stdcall JavaArchive_Immediate(MSIHANDLE hInstall);

/*! 

\brief Java archive (deferred custom action)

Use in combination with \ref WixJavaArchiveExtension.

*/
CA_API UINT __stdcall JavaArchive_Deferred(MSIHANDLE hInstall);
