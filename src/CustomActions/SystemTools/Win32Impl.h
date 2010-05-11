#pragma once

using namespace AppSecInc::Msi::Flags;

typedef enum e_Win32CopyFile_Overwrite
{
    WIN32COPYFILE_OVERWRITEYES = 0,
    WIN32COPYFILE_OVERWRITENO = 1,
    WIN32COPYFILE_OVERWRITEERROR = 2
};

static const FlagMapEntry s_Win32CopyFile_Overwrite[] = 
{
    { L"", WIN32COPYFILE_OVERWRITEYES },
    { L"yes", WIN32COPYFILE_OVERWRITEYES },
    { L"no", WIN32COPYFILE_OVERWRITENO },
    { L"error", WIN32COPYFILE_OVERWRITEERROR },
};

/*!
\brief Copy a file.
\param WIN32_SOURCE_FILENAME Fully qualified path to the file to copy.
\param WIN32_TARGET_FILENAME Fully qualified path to the target file.
\param WIN32_TARGET_OVERWRITE One of "yes", "no", "error".

Unlike wix built-in custom actions the files copied with Win32_CopyFile are not tracked by MSI. Use Win32_CopyFile to copy 
a configuration file that will be preserved on uninstall for example.

*/
CA_API UINT __stdcall Win32_CopyFile(MSIHANDLE hInstall);

/*!
\brief Move a file.
\param WIN32_SOURCE_FILENAME Fully qualified path to the file to move.
\param WIN32_TARGET_FILENAME Fully qualified path to the target file.
\param WIN32_TARGET_OVERWRITE One of "yes", "no", "error".

Unlike wix built-in custom actions the files being moved with Win32_MoveFile are not tracked by MSI. Do not use 
Win32_MoveFile to copy a file that belongs to a component.

*/
CA_API UINT __stdcall Win32_MoveFile(MSIHANDLE hInstall);

/*!
\brief Delete a file.
\param WIN32_FILENAME Fully qualified path to the file to delete.

Unlike Wix FileCopy the files deleted by Win32_DeleteFile are not tracked by MSI. Do not delete a file that belongs to
a component.

*/
CA_API UINT __stdcall Win32_DeleteFile(MSIHANDLE hInstall);

/*!
\brief Create a directory.
\param WIN32_PATH Fully qualified path to the directory to create; may contain several levels of directories to make.
\return WIN32_PATH_CREATED Full qualified path that has been created first; this is the top level directory that didn't exist.

*/
CA_API UINT __stdcall Win32_CreateDirectory(MSIHANDLE hInstall);

/*!
\brief Delete a directory with all subdirectories and files.
\param WIN32_PATH Fully qualified path to the directory to delete.

*/
CA_API UINT __stdcall Win32_DeleteDirectory(MSIHANDLE hInstall);

/*!
\brief Copy files.
This is a table-driven custom action. 
Use in combination with \ref AppSecInc.Wix.Extensions.SystemToolsExtension.
*/
CA_API UINT __stdcall Win32_CopyFiles_Immediate(MSIHANDLE hInstall);
CA_API UINT __stdcall Win32_CopyFiles_Deferred(MSIHANDLE hInstall);

/*!
\brief Move files.
This is a table-driven custom action. 
Use in combination with \ref AppSecInc.Wix.Extensions.SystemToolsExtension.
*/
CA_API UINT __stdcall Win32_MoveFiles_Immediate(MSIHANDLE hInstall);
CA_API UINT __stdcall Win32_MoveFiles_Deferred(MSIHANDLE hInstall);

/*!
\brief Delete files.
This is a table-driven custom action. 
Use in combination with \ref AppSecInc.Wix.Extensions.SystemToolsExtension.
*/
CA_API UINT __stdcall Win32_DeleteFiles_Immediate(MSIHANDLE hInstall);
CA_API UINT __stdcall Win32_DeleteFiles_Deferred(MSIHANDLE hInstall);

/*!
\brief Execute commands (immediate).
This is a table-driven custom action. 
Use in combination with \ref AppSecInc.Wix.Extensions.SystemToolsExtension.
*/
CA_API UINT __stdcall Win32_Execute_Immediate(MSIHANDLE hInstall);

/*!
\brief Execute commands (deferred).
This is a table-driven custom action. 
Use in combination with \ref AppSecInc.Wix.Extensions.SystemToolsExtension.
*/
CA_API UINT __stdcall Win32_Execute_Deferred(MSIHANDLE hInstall);

/*!
\brief Execute commands (rollback).
This is a table-driven custom action. 
Use in combination with \ref AppSecInc.Wix.Extensions.SystemToolsExtension.
*/
CA_API UINT __stdcall Win32_Execute_Rollback(MSIHANDLE hInstall);

static const FlagMapEntry s_Win32GetFileSize_Format[] = 
{
    { L"", (WORD) AppSecInc::File::FILESIZE_AUTO }, //! automatically adjust
    { L"AUTO", (WORD) AppSecInc::File::FILESIZE_AUTO }, //! automatically adjust
    { L"BYTES", (WORD) AppSecInc::File::FILESIZE_BYTES }, //! byte(s)
    { L"KB", (WORD) AppSecInc::File::FILESIZE_KBYTES }, //! Kb
    { L"MB", (WORD) AppSecInc::File::FILESIZE_MBYTES }, //! Mb
    { L"GB", (WORD) AppSecInc::File::FILESIZE_GBYTES }, //! Gb
};

/*!
\brief Get the size of a file.
\param WIN32_FILENAME Fully qualified path to the file to get the size of.
\param WIN32_FILESIZE_FORMAT File size format, "AUTO" (default) for automatic, "BYTES", "KB", "MB" or "GB".
\param WIN32_FILESIZE_PRECISION Number of decimal digits in the result, default is 0. Results are rounded to the number of decimal digits specified.
\return WIN32_FILESIZE String representing the size of the file, numbers only, without type (eg. 1.23)
\return WIN32_FILESIZE_FORMATTED String representing the size of the file, numbers and type only (eg. 1.23 GB).
\return WIN32_FILESIZE_BYTES String representing the size of the file in bytes, numbers only (eg. 12300000000).

\par Example:
\code
<CustomAction Id="Win32_GetFileSize_SetFilename" Property="WIN32_FILENAME" Value="[SystemFolder]\shell32.dll" />
<CustomAction Id="Win32_GetFileSize_SetFormat" Property="WIN32_FILESIZE_FORMAT" Value="MB" />
<CustomAction Id="Win32_GetFileSize_SetPrecision" Property="WIN32_FILESIZE_PRECISION" Value="2" />
<CustomAction Id="Win32_FileSize" Property="SHELL32FILE_SIZE" Value="[WIN32_FILESIZE_FORMATTED]" />
<InstallExecuteSequence>
  <Custom Action="Win32_GetFileSize_SetFilename" After="AppSearch">1</Custom>
  <Custom Action="Win32_GetFileSize_SetFormat" After="Win32_GetFileSize_SetFilename">1</Custom>
  <Custom Action="Win32_GetFileSize_SetPrecision" After="Win32_GetFileSize_SetFormat">1</Custom>
  <Custom Action="Win32_GetFileSize" After="Win32_GetFileSize_SetPrecision">1</Custom>
  <Custom Action="Win32_FileSize" After="Win32_GetFileSize" />
</InstallExecuteSequence>
\endcode
*/
CA_API UINT __stdcall Win32_GetFileSize(MSIHANDLE hInstall);

/*!
\brief Check if file exists.
\param WIN32_FILENAME Fully qualified path to the file to check
\return WIN32_FILE_EXISTS "1" if file exists; "0" otherwise.

\par Example:
\code
<CustomAction Id="Win32_FileExists_SetFilename" Property="WIN32_FILENAME" Value="[SystemFolder]\shell32.dll" />
<CustomAction Id="Win32_FileExists" DllEntry="Win32_FileSize" BinaryKey="SystemTools" />
<CustomAction Id="GetSizeIfExists" DllEntry="Win32_FileSize" BinaryKey="SystemTools" />
<InstallExecuteSequence>
  <Custom Action="Win32_FileExists_SetFilename" After="AppSearch">1</Custom>
  <Custom Action="Win32_FileExists" After="Win32_GetFileSize_SetFilename">1</Custom>
  <Custom Action="GetSizeIfExists" After="Win32_FileExists" >WIN32_FILE_EXISTS = "1"</Custom>
</InstallExecuteSequence>
\endcode
*/
CA_API UINT __stdcall Win32_FileExists(MSIHANDLE hInstall);

/*!
\brief Get the parent directory.
\param WIN32_DIRECTORY Fully qualified path to a directory
\return WIN32_PARENT_DIRECTORY Fully qualified path to the parent directory terminated with a backslash

The value returned is either blank or always terminated with a backslash. 
If the directory doesn't have a parent (eg. C:\), the same directory is returned.
If the directory is blank, a blank value is returned.

*/
CA_API UINT __stdcall Win32_GetParentDirectory(MSIHANDLE hInstall);

/*!
\brief Read contents of an ANSI file into a property.
\param WIN32_FILE_NAME Fully qualified path to the target file.
\return WIN32_FILE_DATA Data in the file.

If the file is in the UTF-8 format, the data is converted to UNICODE. 
*/
CA_API UINT __stdcall Win32_ReadFile(MSIHANDLE hInstall);

/*!
\brief Write to an ANSI text file.
\param WIN32_FILE_DATA Data to write to a file.
\param WIN32_FILE_NAME Fully qualified path to the target file.
\param WIN32_FILE_ENCODING Set to "UTF-8" to write a file in the UTF-8 format, "ANSI" to write the file in the ANSI format. Default is ANSI.
*/
CA_API UINT __stdcall Win32_WriteFile(MSIHANDLE hInstall);
