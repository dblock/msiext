using System;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

using Microsoft.Tools.WindowsInstallerXml;
using AppSecInc.Wix.Extensions;

[assembly: AssemblyTitle("AppSecInc WIX Common UI Extension")]
[assembly: AssemblyDefaultWixExtension(typeof(CommonUiExtension))]
