#include <StdAfx.h>
#include "DSNCmdEngine.h"

/*! \page dsn_exe DSN Creation Tool

DSN.exe exposes functionality of the \ref ConfigDataSource, \ref ConfigDataSource_Access and \ref ConfigDataSource_SQLServer
immediate custom actions.

\par Usage:

\code
USAGE:

   dsn  {--system|--user} --driver <driver> [--nologo] [--] [--version]
        [-h] <operation> <name=value> ...


Where:

   --system
     (OR required)  Create a system DSN
         -- OR --
   --user
     (OR required)  Create a user DSN


   --driver
     (required)  Database driver, eg. "SQL Server"

   --nologo
     Suppress logo, raw output only.

   --,  --ignore_rest
     Ignores the rest of the labeled arguments following this flag.

   --version
     Displays version information and exits.

   -h,  --help
     Displays usage information and exits.

   <operation>
     (required)  Operation to perform: "add", "configure" or "remove".

   <name=value>  (accepted multiple times)
     (required)  DSN parameters, eg. Server=localhost

\endcode

\par Examples:

Creating a user DSN.

\code
$ DSN.exe --user add --driver "SQL Server" DSN=Test Server=localhost "Description=Test DSN" Database=master Trusted_Connection=yes

DSN 1.0.2291.0 - Copyright (c) Application Security Inc. 2008

Adding "SQL Server" DSN
 DSN=Test;Server=localhost;Description=Test DSN;Database=master;Trusted_Connection=yes
\endcode

Deleting the user DSN.

\code
$ DSN.exe --user remove --driver "SQL Server" DSN=Test

DSN 1.0.2291.0 - Copyright (c) Application Security Inc. 2008

Removing "SQL Server" DSN
 DSN=Test
\endcode

*/

void logo()
{
	std::wcout << L"DSN " << _T(VERSION_VALUE) << L" - " << _T(VERSION_LEGALCOPYRIGHT_VALUE) << std::endl;
}

int wmain(int argc, wchar_t * argv[])
{
    try
    {
        AppSecInc::Com::CCoInitialize coinit;
        DSNCmdEngine engine(argc, argv);
		if (! engine._nologo.getValue()) logo();
        engine.Execute();
    }
    catch(TCLAP::ArgException& ex)
    {
		logo();
        std::wcerr << std::endl << ex.argId() << L": " << ex.error();
        return -1;
    }
    catch(std::exception& ex)
    {
        std::wcerr << std::endl << ex.what();
        return -1;
    }
}
