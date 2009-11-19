#pragma once

/*! 

\brief Saves a binary stream into a file.

\param BINARYWRITE_PROPERTYNAME The name of the Binary property that contains the data.
\param BINARYWRITE_TARGETFILENAME The output filename

\par Example:

\code
<Binary Id="TestData" SourceFile="TestData.txt" />
<Binary Id="MsiTools" SourceFile="$(var.BinDir)\MsiTools.dll" />
<CustomAction Id="BinaryWrite" BinaryKey="MsiTools" DllEntry="BinaryWrite" Execute="immediate" Return="check" />
<CustomAction Id="SetBinaryWrite_PropertyName" Property="BINARYWRITE_PROPERTYNAME" Value="TestData" />
<CustomAction Id="SetBinaryWrite_TargetFileName" Property="BINARYWRITE_TARGETFILENAME" Value="[SourceDir]TestData.txt" />
<InstallUISequence>
 <Custom Action="SetBinaryWrite_PropertyName" After="CostInitialize">1</Custom>
 <Custom Action="SetBinaryWrite_TargetFileName" After="SetBinaryWrite_PropertyName">1</Custom>
 <Custom Action="BinaryWrite" After="SetBinaryWrite_TargetFileName">1</Custom>
</InstallUISequence>
\endcode

*/
CA_API UINT __stdcall BinaryWrite(MSIHANDLE hInstall);
