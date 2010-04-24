#pragma once

/*!
\brief Generate a GUID string.
\return WIN32_GUID_STRING A GUID in the {GUID} format.
*/
CA_API UINT __stdcall Win32_GenerateGuidString(MSIHANDLE hInstall);

/*!
\brief Check whether a GUID is valid.
\param WIN32_GUID_STRING The value of a GUID to check.
\return WIN32_GUID_VALID 1 if the GUID is valid, 0 otherwise.

Note that valid GUIDs are always included in { }.
*/
CA_API UINT __stdcall Win32_IsValidGuid(MSIHANDLE hInstall);
