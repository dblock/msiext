#pragma once

/*!
\brief Compares dotted version strings.

Compares the version string specfied by InstalledVersion to the version specified by MinimumVersion and optionally, MaximumVersion. 
If InstalledVersion lies between these two versions, then the property specified by the Property is set.

\param InstalledVersion version to compare
\param MinimumVersion mimumum allowed version
\param MaximumVersion optional paramater specifying the maximum version allowed
\param Property property to set if the version check passes

This is a table-driven custom action. It requires the following artifacts:

<ol>
 <li>A custom table called CompareVersions.
    \code
    <CustomTable Id="CompareVersions">
     <Column Id="Id" PrimaryKey="yes" Type="string" />
     <Column Id="InstalledVersion" Type="string" />
     <Column Id="MinimumVersion" Type="string" />
     <Column Id="MaximumVersion" Type="string" />
     <Column Id="Property" Type="string" />
    </CustomTable>
    \endcode
 <li>An immediate CompareVersions custom action.
    \code
     <CustomAction Id="CompareVersions" BinaryKey="SystemTools" DllEntry="CompareVersions" Execute="immediate" Return="check" />
    \endcode
 <li>An execution sequence that schedules the above custom actions before LaunchConditions.
    \code
    <InstallExecuteSequence>
     <Custom Action="CompareVersions" Before="LaunchConditions" Overridable="yes" />
    </InstallExecuteSequence>
    <InstallUISequence>
     <Custom Action="CompareVersions" Before="LaunchConditions" Overridable="yes" />
    </InstallUISequence>
    \endcode
</ol>
*/
CA_API UINT __stdcall CompareVersions(MSIHANDLE hInstall);

/*!
\brief Compares dotted version strings.

Compares the version string specfied by VERSION_INSTALLED to the version specified by VERSION_MINIMUM and optionally, VERSION_MAXIMUM. 
If VERSION_INSTALLED lies between these two versions, then the property specified by VERSION_PROPERTY is set.

\param VERSION_INSTALLED version to compare
\param VERSION_MINIMUM mimumum allowed version
\param VERSION_MAXIMUM optional paramater specifying the maximum version allowed
\param VERSION_PROPERTY property to set if the version check passes
*/
CA_API UINT __stdcall CompareVersion(MSIHANDLE hInstall);
