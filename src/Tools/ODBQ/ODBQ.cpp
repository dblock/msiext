#include <StdAfx.h>
#include "ODBQCmdEngine.h"

/*! \page odbq_exe ODBQ Execution Tool

ODBQ.exe exposes functionality provided by the Wix::Extensions::DataSource::ODBCExecute and the
Wix::Extensions::DataSource::ODBCExecuteFile MSI extensions to the command line.

\section odbq_exe_usage Usage:

\code
USAGE:

   ODBQ.exe  {--sql <string> ... |--file <file> ... |--datafile <datafile>
             ... } [--outputfile <file>] [--delimiter <string>]
             [--connectionstring <string>] [--noresults] [--nosql]
             [--nologo] [--] [--version] [-h]


Where:

   --sql  (accepted multiple times)
     (OR required)  SQL query to execute, eg. "SELECT @@VERSION".
         -- OR --
   --file  (accepted multiple times)
     (OR required)  File(s) containing SQL statements, may be a wildcard.
         -- OR --
   --datafile  (accepted multiple times)
     (OR required)  XML file containing data sets to insert.


   --outputfile
     Xml output file for messages and dataset results.

   --delimiter
     Delimiter for splitting SQL statements, eg. "GO".

   --connectionstring
     Driver-specific connection string to use to connect to the server,
     eg. "Driver=SQL Server;Server=.;Trusted_Connection=yes"

   --noresults
     Suppress results output to console.

   --nosql
     Suppress SQL statements output to console.

   --nologo
     Suppress logo and messages, raw output only.

   --,  --ignore_rest
     Ignores the rest of the labeled arguments following this flag.

   --version
     Displays version information and exits.

   -h,  --help
     Displays usage information and exits.

\endcode

\section odbq_exe_examples Examples:

\subsection odbq_exe_examples_localhost_statement Executing a statement on a local SQL server.

\code
$ odbq.exe --sql "PRINT @@VERSION"

ODBQ 1.0.2758.0 - Copyright (c) Application Security Inc.

- Connecting with "Driver=SQL Server;Server=.;Trusted_Connection=yes;""
> PRINT @@VERSION
< Microsoft SQL Server 2005 - 9.00.3068.00 (Intel X86)
        Feb 26 2008 18:15:01
        Copyright (c) 1988-2005 Microsoft Corporation
        Standard Edition on Windows NT 5.1 (Build 2600: Service Pack 3)
\endcode

\subsection odbq_exe_examples_resultsxml Executing a statement and writing results to an xml output file.

\code
$ odbq.exe --sql "SELECT @@VERSION" --outputfile Version.xml

ODBQ 1.0.2758.0 - Copyright (c) Application Security Inc.

- Connecting with "Driver=SQL Server;Server=.;Trusted_Connection=yes;""
> SELECT @@VERSION
< 1x1
Column1
-------
Microsoft SQL Server 2005 - 9.00.3068.00 (Intel X86)
        Feb 26 2008 18:15:01
        Copyright (c) 1988-2005 Microsoft Corporation
        Standard Edition on Windows NT 5.1 (Build 2600: Service Pack 3)
- Writing "F:\source\commoncomponents\Msi\trunk\target\Debug\bin\Version.xml"
\endcode

The resulting version.xml is:

\code
<Data>
 <DataSet columns="1" rows="1">
  <Query>SELECT @@VERSION</Query> 
  <RowSet>
   <Row>
    <Column1 type="nvarchar">Microsoft SQL Server 2005 - 9.00.3068.00 (Intel X86) Feb 26 2008 18:15:01 Copyright (c) 1988-2005 Microsoft Corporation Developer Edition on Windows NT 6.0 (Build 6001: Service Pack 1)</Column1> 
   </Row>
  </RowSet>
  <Messages /> 
 </DataSet>
</Data>
\endcode

\subsection odbq_exe_examples_importxml Importing data from xml.

You can use the files exported from ODBQ.exe with --outputfile with some modifications: you must
add the table name to the RowSet node.

\code
<Data>
 <DataSet columns="6" rows="6">
  <RowSet table="MyDatabase.dbo.SomeTable">
   <Row>
    <EntryID type="integer">1</EntryID> 
    <Key type="nvarchar">key</Key> 
    <Value type="ntext">value</Value> 
    <Value2 type="text">NULL</Value2> 
    <Value3 type="varchar">NULL</Value3> 
    <SomeNumber type="integer">2</SomeNumber> 
   </Row>
   <Row>
    <EntryID type="integer">2</EntryID> 
    <Key type="nvarchar">key1</Key> 
    <Value type="ntext">value1</Value> 
    <Value2 type="text">NULL</Value2> 
    <Value3 type="varchar">NULL</Value3> 
    <SomeNumber type="integer">2</SomeNumber> 
   </Row>
  </RowSet>
 </DataSet>
</Data>
\endcode

\code
$ odbq.exe --datafile Data.xml --outputfile Results.xml
\endcode

The resulting out xml contains any messages from the ODBC driver and the number of rows affected.

\code
<Data>
 <DataSet table="MyDatabase.dbo.SomeTable" rowsaffected="2">
  <Messages /> 
 </DataSet>
</Data>
\endcode

\subsection odbq_exe_examples_multiple Executing multiple statements with a connection string specified. 

Note that if you choose to mix --sql and --file options, 
SQL queries are executed first, followed by execution of file contents.

\code
$ odbq.exe --sql "SELECT @@VERSION" --sql "PRINT 'Hello World'" --connectionstring "Driver=SQL Server;Server=.;Trusted_Connection=yes"

ODBQ 1.0.2758.0 - Copyright (c) Application Security Inc.

- Connecting with "Driver=SQL Server;Server=.;Trusted_Connection=yes"
> SELECT @@VERSION
< 1x1
Column1
-------
Microsoft SQL Server 2005 - 9.00.3068.00 (Intel X86)
        Feb 26 2008 18:15:01
        Copyright (c) 1988-2005 Microsoft Corporation
        Standard Edition on Windows NT 5.1 (Build 2600: Service Pack 3)
> PRINT 'Hello World'
< Hello World
\endcode

*/

void logo()
{
	std::wcout << L"ODBQ " << _T(VERSION_VALUE) << L" - " << _T(VERSION_LEGALCOPYRIGHT_VALUE) << std::endl;
}

int wmain(int argc, wchar_t * argv[])
{
    try
    {
        AppSecInc::Com::CCoInitialize coinit;
        ODBQCmdEngine engine(argc, argv);
		if (! engine._nologo.getValue()) logo();
        engine.Execute();
    }
    catch(TCLAP::ArgException& ex)
    {
		logo();
        std::wcerr << std::endl << L"! " << ex.argId() << L": " << ex.error();
        return -1;
    }
    catch(std::exception& ex)
    {
        std::wcerr << std::endl << L"! " << ex.what();
        return -1;
    }
}
