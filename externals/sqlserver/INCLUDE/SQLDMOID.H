#ifndef SQLDMOID_H_
#define SQLDMOID_H_

// ***************************************************************************
//               Copyright (C) 1985-1999 Microsoft Corporation.
// @File: dmo_iid.h
//
// Purpose: object GUIDs
//
//
// Notes:
//
// History:
//
//   @Version: Shiloh
//   49129 WG   12/07/99 CTS tracking
//
//
// @EndHeader@
// ***************************************************************************


/////////////////////////////////////////////////////////////////////////////////////////
// Header file for SQLDMO Component Object GUIDs.
// Copyright 1994-1997 Microsoft Corporation.
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////
// Define the SQL-DMO GUIDGEN templates.
/////////////////////////////////////////////////////////////////////////////////
#ifdef _SQLDMO_ODL_
#define SubDefine #define
#define DEFINE_SQLDMOGUID(name, lval) \
      SubDefine name lval##-E260-11cf-AE68-00AA004A34D5
#else
#define DEFINE_SQLDMOGUID(name, lval) \
      DEFINE_GUID(name, 0x##lval, 0xe260, 0x11cf, 0xae, 0x68, 0x0, 0xaa, 0x0, 0x4a, 0x34, 0xd5);
#endif


/////////////////////////////////////////////////////////////////////////////////
// Objects have the following GUID assignments:
// CoClass, if any
// Collection Ansi, Uni, OleAut interface IID (if any)
// Singleton Ansi, Uni, OleAut interface IID (or IIDs if multi-interface coclass)
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
// Naming prefix convention:
// LIBID* - Library ID
// CLSID* - CoClass
// IID_IA* - C++ Ansi interfaces
// IID_IW* - C++ Unicode interfaces
// IID_IV* - OleAut (VB/VBA) dual Interfaces
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
//	SQLDMO Library UUID
/////////////////////////////////////////////////////////////////////////////////
DEFINE_SQLDMOGUID(LIBID_SQLDMOLibrary, 10010001)

/////////////////////////////////////////////////////////////////////////////////
//	SQLDMO backward compatible UUID
/////////////////////////////////////////////////////////////////////////////////
DEFINE_SQLDMOGUID(IID_SQLDMOObsoleteConnect, 1001000B)

/////////////////////////////////////////////////////////////////////////////////
// Internal base interfaces.
/////////////////////////////////////////////////////////////////////////////////
DEFINE_SQLDMOGUID(IID_ISQLDMOAnsiUniInternal, 10010002)
DEFINE_SQLDMOGUID(IID_ISQLDMOPrivate, 10010003)
DEFINE_SQLDMOGUID(IID_ISQLDMOInternal, 1001004)

// DEFINE_SQLDMOGUID(IID_IASQLDMOStdObject, 10010005)
DEFINE_SQLDMOGUID(IID_IWSQLDMOStdObject, 10010006)
DEFINE_SQLDMOGUID(IID_IVSQLDMOStdObject, 10010007)

// DEFINE_SQLDMOGUID(IID_IASQLDMOStdCollection, 10010008)
DEFINE_SQLDMOGUID(IID_IWSQLDMOStdCollection, 10010009)
DEFINE_SQLDMOGUID(IID_IVSQLDMOStdCollection, 1001000A)

/////////////////////////////////////////////////////////////////////////////////
//	SQLDMO internal pConn UUID
/////////////////////////////////////////////////////////////////////////////////
DEFINE_SQLDMOGUID(IID_SQLDMOInternalConn, 1001000C)

/////////////////////////////////////////////////////////////////////////////////
//	SQLDMO internal single object scripting UUID
/////////////////////////////////////////////////////////////////////////////////
DEFINE_SQLDMOGUID(IID_SQLDMOSingleScript, 1001000D)

/////////////////////////////////////////////////////////////////////////////////
//	SQLDMO internal configurable quoting characters scripting UUID
/////////////////////////////////////////////////////////////////////////////////
DEFINE_SQLDMOGUID(IID_SQLDMOQIScript, 1001000E)

// ***************************************************************************
//               Copyright (C) 1985-1999 Microsoft Corporation.
// @File: core_iid.h
//
// Purpose: IID
//
//
// Notes:
//
// History:
//
//   @Version: Shiloh
//   60740 WG   05/08/00 New dboptions for recovery
//   59129 WG   04/03/00 Login2 IID bug
//   53792 TCH  02/09/00 222285: coclasses from xxx2 interfaces
//   52521 WG   01/24/00 Backup and Restore
//   52513 WG   01/24/00 GrantedGranted
//   51899 WG   01/18/00 DatabaseRole
//   51623 WG   01/17/00 IsDeleted
//   50625 WG   01/04/00 Syntax check for default and rule
//   49129 WG   12/07/99 CTS tracking
//
//
// @EndHeader@
// ***************************************************************************



/////////////////////////////////////////////////////////////////////////////////
// Automation generic-property interfaces
/////////////////////////////////////////////////////////////////////////////////
DEFINE_SQLDMOGUID(IID_IVSQLDMOProperties, 10020001)
DEFINE_SQLDMOGUID(IID_IVSQLDMOProperty, 10020002)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOApplication, 10020100)

// No collection

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOApplication, 10020105)
DEFINE_SQLDMOGUID(IID_IVSQLDMOApplication, 10020106)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOServer, 10020200)
DEFINE_SQLDMOGUID(CLSID_SQLDMOServer2, 100202c1)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMOServers, 10020202)
DEFINE_SQLDMOGUID(IID_IVSQLDMOServers, 10020203)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOServer, 10020205)
DEFINE_SQLDMOGUID(IID_IVSQLDMOServer, 10020206)

DEFINE_SQLDMOGUID(IID_IWSQLDMOServer2, 10020215)
DEFINE_SQLDMOGUID(IID_IVSQLDMOServer2, 10020216)

// Interface (event sink)
DEFINE_SQLDMOGUID(IID_IWSQLDMOServerSink, 10020208)
DEFINE_SQLDMOGUID(IID_IVSQLDMOServerSink, 10020209)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMODatabase, 10020300)
DEFINE_SQLDMOGUID(CLSID_SQLDMODatabase2, 100203c1)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMODatabases, 10020302)
DEFINE_SQLDMOGUID(IID_IVSQLDMODatabases, 10020303)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMODatabase, 10020305)
DEFINE_SQLDMOGUID(IID_IVSQLDMODatabase, 10020306)

DEFINE_SQLDMOGUID(IID_IWSQLDMODatabase2, 10020315)
DEFINE_SQLDMOGUID(IID_IVSQLDMODatabase2, 10020316)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOTable, 10020400)
DEFINE_SQLDMOGUID(CLSID_SQLDMOTable2, 100204c1)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMOTables, 10020402)
DEFINE_SQLDMOGUID(IID_IVSQLDMOTables, 10020403)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOTable, 10020405)
DEFINE_SQLDMOGUID(IID_IVSQLDMOTable, 10020406)

DEFINE_SQLDMOGUID(IID_IWSQLDMOTable2, 10020415)
DEFINE_SQLDMOGUID(IID_IVSQLDMOTable2, 10020416)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOColumn, 10020500)
DEFINE_SQLDMOGUID(CLSID_SQLDMOColumn2, 100205c1)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMOColumns, 10020502)
DEFINE_SQLDMOGUID(IID_IVSQLDMOColumns, 10020503)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOColumn, 10020505)
DEFINE_SQLDMOGUID(IID_IVSQLDMOColumn, 10020506)

DEFINE_SQLDMOGUID(IID_IWSQLDMOColumn2, 10020515)
DEFINE_SQLDMOGUID(IID_IVSQLDMOColumn2, 10020516)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOView, 10020700)
DEFINE_SQLDMOGUID(CLSID_SQLDMOView2, 100207c1)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMOViews, 10020702)
DEFINE_SQLDMOGUID(IID_IVSQLDMOViews, 10020703)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOView, 10020705)
DEFINE_SQLDMOGUID(IID_IVSQLDMOView, 10020706)

DEFINE_SQLDMOGUID(IID_IWSQLDMOView2, 10020715)
DEFINE_SQLDMOGUID(IID_IVSQLDMOView2, 10020716)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOUserDefinedDatatype, 10020800)
DEFINE_SQLDMOGUID(CLSID_SQLDMOUserDefinedDatatype2, 100208c1)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMOUserDefinedDatatypes, 10020802)
DEFINE_SQLDMOGUID(IID_IVSQLDMOUserDefinedDatatypes, 10020803)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOUserDefinedDatatype, 10020805)
DEFINE_SQLDMOGUID(IID_IVSQLDMOUserDefinedDatatype, 10020806)

DEFINE_SQLDMOGUID(IID_IWSQLDMOUserDefinedDatatype2, 10020815)
DEFINE_SQLDMOGUID(IID_IVSQLDMOUserDefinedDatatype2, 10020816)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMODefault, 10020900)
DEFINE_SQLDMOGUID(CLSID_SQLDMODefault2, 100209c1)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMODefaults, 10020902)
DEFINE_SQLDMOGUID(IID_IVSQLDMODefaults, 10020903)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMODefault, 10020905)
DEFINE_SQLDMOGUID(IID_IVSQLDMODefault, 10020906)

DEFINE_SQLDMOGUID(IID_IWSQLDMODefault2, 10020915)
DEFINE_SQLDMOGUID(IID_IVSQLDMODefault2, 10020916)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMORule, 10020a00)
DEFINE_SQLDMOGUID(CLSID_SQLDMORule2, 10020ac1)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMORules, 10020a02)
DEFINE_SQLDMOGUID(IID_IVSQLDMORules, 10020a03)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMORule, 10020a05)
DEFINE_SQLDMOGUID(IID_IVSQLDMORule, 10020a06)

DEFINE_SQLDMOGUID(IID_IWSQLDMORule2, 10020a15)
DEFINE_SQLDMOGUID(IID_IVSQLDMORule2, 10020a16)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOUser, 10020b00)
DEFINE_SQLDMOGUID(CLSID_SQLDMOUser2, 10020bc1)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMOUsers, 10020b02)
DEFINE_SQLDMOGUID(IID_IVSQLDMOUsers, 10020b03)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOUser, 10020b05)
DEFINE_SQLDMOGUID(IID_IVSQLDMOUser, 10020b06)

DEFINE_SQLDMOGUID(IID_IWSQLDMOUser2, 10020b15)
DEFINE_SQLDMOGUID(IID_IVSQLDMOUser2, 10020b16)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOGroup, 10020c00)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMOGroups, 10020c02)
DEFINE_SQLDMOGUID(IID_IVSQLDMOGroups, 10020c03)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOGroup, 10020c05)
DEFINE_SQLDMOGUID(IID_IVSQLDMOGroup, 10020c06)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOStoredProcedure, 10020d00)
DEFINE_SQLDMOGUID(CLSID_SQLDMOStoredProcedure2, 10020dc1)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMOStoredProcedures, 10020d02)
DEFINE_SQLDMOGUID(IID_IVSQLDMOStoredProcedures, 10020d03)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOStoredProcedure, 10020d05)
DEFINE_SQLDMOGUID(IID_IVSQLDMOStoredProcedure, 10020d06)

DEFINE_SQLDMOGUID(IID_IWSQLDMOStoredProcedure2, 10020d15)
DEFINE_SQLDMOGUID(IID_IVSQLDMOStoredProcedure2, 10020d16)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOIndex, 10020e00)
DEFINE_SQLDMOGUID(CLSID_SQLDMOIndex2, 10020ec1)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMOIndexes, 10020e02)
DEFINE_SQLDMOGUID(IID_IVSQLDMOIndexes, 10020e03)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOIndex, 10020e05)
DEFINE_SQLDMOGUID(IID_IVSQLDMOIndex, 10020e06)

DEFINE_SQLDMOGUID(IID_IWSQLDMOIndex2, 10020e15)
DEFINE_SQLDMOGUID(IID_IVSQLDMOIndex2, 10020e16)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOKey, 10020f00)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMOKeys, 10020f02)
DEFINE_SQLDMOGUID(IID_IVSQLDMOKeys, 10020f03)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOKey, 10020f05)
DEFINE_SQLDMOGUID(IID_IVSQLDMOKey, 10020f06)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOTrigger, 10021000)
DEFINE_SQLDMOGUID(CLSID_SQLDMOTrigger2, 100210c1)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMOTriggers, 10021002)
DEFINE_SQLDMOGUID(IID_IVSQLDMOTriggers, 10021003)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOTrigger, 10021005)
DEFINE_SQLDMOGUID(IID_IVSQLDMOTrigger, 10021006)

DEFINE_SQLDMOGUID(IID_IWSQLDMOTrigger2, 10021015)
DEFINE_SQLDMOGUID(IID_IVSQLDMOTrigger2, 10021016)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOBackupDevice, 10021100)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMOBackupDevices, 10021102)
DEFINE_SQLDMOGUID(IID_IVSQLDMOBackupDevices, 10021103)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOBackupDevice, 10021105)
DEFINE_SQLDMOGUID(IID_IVSQLDMOBackupDevice, 10021106)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOLogin, 10021300)
DEFINE_SQLDMOGUID(CLSID_SQLDMOLogin2, 100213c1)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMOLogins, 10021302)
DEFINE_SQLDMOGUID(IID_IVSQLDMOLogins, 10021303)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOLogin, 10021305)
DEFINE_SQLDMOGUID(IID_IVSQLDMOLogin, 10021306)

DEFINE_SQLDMOGUID(IID_IWSQLDMOLogin2, 10021315)
DEFINE_SQLDMOGUID(IID_IVSQLDMOLogin2, 10021316)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOLanguage, 10021400)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMOLanguages, 10021402)
DEFINE_SQLDMOGUID(IID_IVSQLDMOLanguages, 10021403)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOLanguage, 10021405)
DEFINE_SQLDMOGUID(IID_IVSQLDMOLanguage, 10021406)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMORemoteServer, 10021500)
DEFINE_SQLDMOGUID(CLSID_SQLDMORemoteServer2, 100215c1)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMORemoteServers, 10021502)
DEFINE_SQLDMOGUID(IID_IVSQLDMORemoteServers, 10021503)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMORemoteServer, 10021505)
DEFINE_SQLDMOGUID(IID_IVSQLDMORemoteServer, 10021506)

DEFINE_SQLDMOGUID(IID_IWSQLDMORemoteServer2, 10021515)
DEFINE_SQLDMOGUID(IID_IVSQLDMORemoteServer2, 10021516)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMORemoteLogin, 10021600)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMORemoteLogins, 10021602)
DEFINE_SQLDMOGUID(IID_IVSQLDMORemoteLogins, 10021603)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMORemoteLogin, 10021605)
DEFINE_SQLDMOGUID(IID_IVSQLDMORemoteLogin, 10021606)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOCheck, 10021700)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMOChecks, 10021702)
DEFINE_SQLDMOGUID(IID_IVSQLDMOChecks, 10021703)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOCheck, 10021705)
DEFINE_SQLDMOGUID(IID_IVSQLDMOCheck, 10021706)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOServerGroup, 10021800)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMOServerGroups, 10021802)
DEFINE_SQLDMOGUID(IID_IVSQLDMOServerGroups, 10021803)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOServerGroup, 10021805)
DEFINE_SQLDMOGUID(IID_IVSQLDMOServerGroup, 10021806)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMORegisteredServer, 10021900)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMORegisteredServers, 10021902)
DEFINE_SQLDMOGUID(IID_IVSQLDMORegisteredServers, 10021903)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMORegisteredServer, 10021905)
DEFINE_SQLDMOGUID(IID_IVSQLDMORegisteredServer, 10021906)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// NO CLSID (persistent collection, predefined objects)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMOSystemDatatypes, 10021a02)
DEFINE_SQLDMOGUID(IID_IVSQLDMOSystemDatatypes, 10021a03)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOSystemDatatype, 10021a05)
DEFINE_SQLDMOGUID(IID_IVSQLDMOSystemDatatype, 10021a06)

DEFINE_SQLDMOGUID(IID_IWSQLDMOSystemDatatype2, 10021a15)
DEFINE_SQLDMOGUID(IID_IVSQLDMOSystemDatatype2, 10021a16)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// NO CLSID (persistent collection, predefined objects)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMOConfigValues, 10021b02)
DEFINE_SQLDMOGUID(IID_IVSQLDMOConfigValues, 10021b03)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOConfigValue, 10021b05)
DEFINE_SQLDMOGUID(IID_IVSQLDMOConfigValue, 10021b06)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOBulkCopy, 10021c00)
DEFINE_SQLDMOGUID(CLSID_SQLDMOBulkCopy2, 10021cc1)

// NO Collection

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOBulkCopy, 10021c05)
DEFINE_SQLDMOGUID(IID_IVSQLDMOBulkCopy, 10021c06)

DEFINE_SQLDMOGUID(IID_IWSQLDMOBulkCopy2, 10021c15)
DEFINE_SQLDMOGUID(IID_IVSQLDMOBulkCopy2, 10021c16)

// Interface (event sink)
DEFINE_SQLDMOGUID(IID_IWSQLDMOBulkCopySink, 10021c08)
DEFINE_SQLDMOGUID(IID_IVSQLDMOBulkCopySink, 10021c09)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// No CLSID

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMONames, 10021d02)
DEFINE_SQLDMOGUID(IID_IVSQLDMONames, 10021d03)

// No interface (returns strings)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOTransfer, 10021e00)
DEFINE_SQLDMOGUID(CLSID_SQLDMOTransfer2, 10021ec1)

// No Collection

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOTransfer, 10021e05)
DEFINE_SQLDMOGUID(IID_IVSQLDMOTransfer, 10021e06)

DEFINE_SQLDMOGUID(IID_IWSQLDMOTransfer2, 10021e15)
DEFINE_SQLDMOGUID(IID_IVSQLDMOTransfer2, 10021e16)

// Interface (event sink)
DEFINE_SQLDMOGUID(IID_IWSQLDMOTransferSink, 10021e08)
DEFINE_SQLDMOGUID(IID_IVSQLDMOTransferSink, 10021e09)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOBackup, 10021f00)
DEFINE_SQLDMOGUID(CLSID_SQLDMOBackup2, 10021fc1)

// No Collection

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOBackup, 10021f05)
DEFINE_SQLDMOGUID(IID_IVSQLDMOBackup, 10021f06)

DEFINE_SQLDMOGUID(IID_IWSQLDMOBackup2, 10021f15)
DEFINE_SQLDMOGUID(IID_IVSQLDMOBackup2, 10021f16)

// Interface (event sink)
DEFINE_SQLDMOGUID(IID_IWSQLDMOBackupSink, 10021f08)
DEFINE_SQLDMOGUID(IID_IVSQLDMOBackupSink, 10021f09)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// No CLSID

// No Collection

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMODBObject, 10022105)
DEFINE_SQLDMOGUID(IID_IVSQLDMODBObject, 10022106)

DEFINE_SQLDMOGUID(IID_IWSQLDMODBObject2, 10022115)
// No Automation changes:  DEFINE_SQLDMOGUID(IID_IVSQLDMODBObject2, 10022116)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// No CLSID

// No Collection

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMODBOption, 10022205)
DEFINE_SQLDMOGUID(IID_IVSQLDMODBOption, 10022206)

DEFINE_SQLDMOGUID(IID_IWSQLDMODBOption2, 10022215)
DEFINE_SQLDMOGUID(IID_IVSQLDMODBOption2, 10022216)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// No CLSID

// No Collection

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOConfiguration, 10022305)
DEFINE_SQLDMOGUID(IID_IVSQLDMOConfiguration, 10022306)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// No CLSID

// No Collection

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMONameList, 10022405)
DEFINE_SQLDMOGUID(IID_IVSQLDMONameList, 10022406)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// No CLSID

// No Collection

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOQueryResults, 10022505)
DEFINE_SQLDMOGUID(IID_IVSQLDMOQueryResults, 10022506)

DEFINE_SQLDMOGUID(IID_IWSQLDMOQueryResults2, 10022515)
DEFINE_SQLDMOGUID(IID_IVSQLDMOQueryResults2, 10022516)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// No CLSID

// No Collection

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOTransactionLog, 10022605)
DEFINE_SQLDMOGUID(IID_IVSQLDMOTransactionLog, 10022606)

DEFINE_SQLDMOGUID(IID_IWSQLDMOTransactionLog2, 10022615)
// No Automation changes:  DEFINE_SQLDMOGUID(IID_IVSQLDMOTransactionLog2, 10022616)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// No CLSID

// No Collection

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMORegistry, 10022705)
DEFINE_SQLDMOGUID(IID_IVSQLDMORegistry, 10022706)

DEFINE_SQLDMOGUID(IID_IWSQLDMORegistry2, 10022715)
DEFINE_SQLDMOGUID(IID_IVSQLDMORegistry2, 10022716)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// No CLSID

// No Collection

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOObjectList, 10022805)
DEFINE_SQLDMOGUID(IID_IVSQLDMOObjectList, 10022806)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// No CLSID

// No Collection

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOPermission, 10022905)
DEFINE_SQLDMOGUID(IID_IVSQLDMOPermission, 10022906)

DEFINE_SQLDMOGUID(IID_IWSQLDMOPermission2, 10022915)
DEFINE_SQLDMOGUID(IID_IVSQLDMOPermission2, 10022916)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// No CLSID

// No Collection

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOIntegratedSecurity, 10022a05)
DEFINE_SQLDMOGUID(IID_IVSQLDMOIntegratedSecurity, 10022a06)
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// No CLSID

// No Collection

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMODRIDefault, 10022b05)
DEFINE_SQLDMOGUID(IID_IVSQLDMODRIDefault, 10022b06)


/////////////////////////////////////////////////////////////////////////////////
// 7.0 new objects
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOFileGroup, 10022c00)
DEFINE_SQLDMOGUID(CLSID_SQLDMOFileGroup2, 10022cc1)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMOFileGroups, 10022c02)
DEFINE_SQLDMOGUID(IID_IVSQLDMOFileGroups, 10022c03)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOFileGroup, 10022c05)
DEFINE_SQLDMOGUID(IID_IVSQLDMOFileGroup, 10022c06)

DEFINE_SQLDMOGUID(IID_IWSQLDMOFileGroup2, 10022c15)
DEFINE_SQLDMOGUID(IID_IVSQLDMOFileGroup2, 10022c16)


/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMODBFile, 10022d00)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMODBFiles, 10022d02)
DEFINE_SQLDMOGUID(IID_IVSQLDMODBFiles, 10022d03)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMODBFile, 10022d05)
DEFINE_SQLDMOGUID(IID_IVSQLDMODBFile, 10022d06)


/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOLogFile, 10022e00)
DEFINE_SQLDMOGUID(CLSID_SQLDMOLogFile2, 10022ec1)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMOLogFiles, 10022e02)
DEFINE_SQLDMOGUID(IID_IVSQLDMOLogFiles, 10022e03)

DEFINE_SQLDMOGUID(IID_IWSQLDMOLogFiles2, 10022e12)
DEFINE_SQLDMOGUID(IID_IVSQLDMOLogFiles2, 10022e13)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOLogFile, 10022e05)
DEFINE_SQLDMOGUID(IID_IVSQLDMOLogFile, 10022e06)

DEFINE_SQLDMOGUID(IID_IWSQLDMOLogFile2, 10022e15)
DEFINE_SQLDMOGUID(IID_IVSQLDMOLogFile2, 10022e16)


/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOServerRole, 10022f00)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMOServerRoles, 10022f02)
DEFINE_SQLDMOGUID(IID_IVSQLDMOServerRoles, 10022f03)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOServerRole, 10022f05)
DEFINE_SQLDMOGUID(IID_IVSQLDMOServerRole, 10022f06)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMODatabaseRole, 10023100)
DEFINE_SQLDMOGUID(CLSID_SQLDMODatabaseRole2, 100231c1)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMODatabaseRoles, 10023102)
DEFINE_SQLDMOGUID(IID_IVSQLDMODatabaseRoles, 10023103)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMODatabaseRole, 10023105)
DEFINE_SQLDMOGUID(IID_IVSQLDMODatabaseRole, 10023106)

DEFINE_SQLDMOGUID(IID_IWSQLDMODatabaseRole2, 10023115)
DEFINE_SQLDMOGUID(IID_IVSQLDMODatabaseRole2, 10023116)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMORestore, 10023200)
DEFINE_SQLDMOGUID(CLSID_SQLDMORestore2, 100232c1)

// No Collection

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMORestore, 10023202)
DEFINE_SQLDMOGUID(IID_IVSQLDMORestore, 10023203)

DEFINE_SQLDMOGUID(IID_IWSQLDMORestore2, 10023212)
DEFINE_SQLDMOGUID(IID_IVSQLDMORestore2, 10023213)

// Interface (event sink)
DEFINE_SQLDMOGUID(IID_IWSQLDMORestoreSink, 10023205)
DEFINE_SQLDMOGUID(IID_IVSQLDMORestoreSink, 10023206)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOLinkedServer, 10023300)
DEFINE_SQLDMOGUID(CLSID_SQLDMOLinkedServer2, 100233c1)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMOLinkedServers, 10023302)
DEFINE_SQLDMOGUID(IID_IVSQLDMOLinkedServers, 10023303)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOLinkedServer, 10023305)
DEFINE_SQLDMOGUID(IID_IVSQLDMOLinkedServer, 10023306)

DEFINE_SQLDMOGUID(IID_IWSQLDMOLinkedServer2, 10023315)
DEFINE_SQLDMOGUID(IID_IVSQLDMOLinkedServer2, 10023316)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOLinkedServerLogin, 10023400)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMOLinkedServerLogins, 10023402)
DEFINE_SQLDMOGUID(IID_IVSQLDMOLinkedServerLogins, 10023403)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOLinkedServerLogin, 10023405)
DEFINE_SQLDMOGUID(IID_IVSQLDMOLinkedServerLogin, 10023406)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOFullTextCatalog, 10023500)
DEFINE_SQLDMOGUID(CLSID_SQLDMOFullTextCatalog2, 100235c1)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMOFullTextCatalogs, 10023502)
DEFINE_SQLDMOGUID(IID_IVSQLDMOFullTextCatalogs, 10023503)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOFullTextCatalog, 10023505)
DEFINE_SQLDMOGUID(IID_IVSQLDMOFullTextCatalog, 10023506)

DEFINE_SQLDMOGUID(IID_IWSQLDMOFullTextCatalog2, 10023515)
DEFINE_SQLDMOGUID(IID_IVSQLDMOFullTextCatalog2, 10023516)


/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID

// Collection

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOFullTextService, 10023605)
DEFINE_SQLDMOGUID(IID_IVSQLDMOFullTextService, 10023606)


/////////////////////////////////////////////////////////////////////////////////
// 8.0 new objects
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOUserDefinedFunction, 10023700)

// Collection
DEFINE_SQLDMOGUID(IID_IWSQLDMOUserDefinedFunctions, 10023702)
DEFINE_SQLDMOGUID(IID_IVSQLDMOUserDefinedFunctions, 10023703)

// Interface
DEFINE_SQLDMOGUID(IID_IWSQLDMOUserDefinedFunction, 10023705)
DEFINE_SQLDMOGUID(IID_IVSQLDMOUserDefinedFunction, 10023706)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOTransPublication, 10030100)
DEFINE_SQLDMOGUID(CLSID_SQLDMOTransPublication2, 100301c1)

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMOTransPublications, 10030101)
DEFINE_SQLDMOGUID(IID_IWSQLDMOTransPublications, 10030102)
DEFINE_SQLDMOGUID(IID_IVSQLDMOTransPublications, 10030103)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOTransPublication, 10030104)
DEFINE_SQLDMOGUID(IID_IWSQLDMOTransPublication, 10030105)
DEFINE_SQLDMOGUID(IID_IVSQLDMOTransPublication, 10030106)

DEFINE_SQLDMOGUID(IID_IWSQLDMOTransPublication2, 10030115)
DEFINE_SQLDMOGUID(IID_IVSQLDMOTransPublication2, 10030116)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOTransArticle, 10030200)
DEFINE_SQLDMOGUID(CLSID_SQLDMOTransArticle2, 100302c1)

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMOTransArticles, 10030201)
DEFINE_SQLDMOGUID(IID_IWSQLDMOTransArticles, 10030202)
DEFINE_SQLDMOGUID(IID_IVSQLDMOTransArticles, 10030203)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOTransArticle, 10030204)
DEFINE_SQLDMOGUID(IID_IWSQLDMOTransArticle, 10030205)
DEFINE_SQLDMOGUID(IID_IVSQLDMOTransArticle, 10030206)

DEFINE_SQLDMOGUID(IID_IWSQLDMOTransArticle2, 10030215)
DEFINE_SQLDMOGUID(IID_IVSQLDMOTransArticle2, 10030216)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOTransSubscription, 10030300)
DEFINE_SQLDMOGUID(CLSID_SQLDMOTransSubscription2, 100303c1)

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMOTransSubscriptions, 10030301)
DEFINE_SQLDMOGUID(IID_IWSQLDMOTransSubscriptions, 10030302)
DEFINE_SQLDMOGUID(IID_IVSQLDMOTransSubscriptions, 10030303)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOTransSubscription, 10030304)
DEFINE_SQLDMOGUID(IID_IWSQLDMOTransSubscription, 10030305)
DEFINE_SQLDMOGUID(IID_IVSQLDMOTransSubscription, 10030306)

DEFINE_SQLDMOGUID(IID_IWSQLDMOTransSubscription2, 10030315)
DEFINE_SQLDMOGUID(IID_IVSQLDMOTransSubscription2, 10030316)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOMergePublication, 10030400)
DEFINE_SQLDMOGUID(CLSID_SQLDMOMergePublication2, 100304c1)

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMOMergePublications, 10030401)
DEFINE_SQLDMOGUID(IID_IWSQLDMOMergePublications, 10030402)
DEFINE_SQLDMOGUID(IID_IVSQLDMOMergePublications, 10030403)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOMergePublication, 10030404)
DEFINE_SQLDMOGUID(IID_IWSQLDMOMergePublication, 10030405)
DEFINE_SQLDMOGUID(IID_IVSQLDMOMergePublication, 10030406)

DEFINE_SQLDMOGUID(IID_IWSQLDMOMergePublication2, 10030415)
DEFINE_SQLDMOGUID(IID_IVSQLDMOMergePublication2, 10030416)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOMergeArticle, 10030500)
DEFINE_SQLDMOGUID(CLSID_SQLDMOMergeArticle2, 100305c1)

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMOMergeArticles, 10030501)
DEFINE_SQLDMOGUID(IID_IWSQLDMOMergeArticles, 10030502)
DEFINE_SQLDMOGUID(IID_IVSQLDMOMergeArticles, 10030503)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOMergeArticle, 10030504)
DEFINE_SQLDMOGUID(IID_IWSQLDMOMergeArticle, 10030505)
DEFINE_SQLDMOGUID(IID_IVSQLDMOMergeArticle, 10030506)

DEFINE_SQLDMOGUID(IID_IWSQLDMOMergeArticle2, 10030515)
DEFINE_SQLDMOGUID(IID_IVSQLDMOMergeArticle2, 10030516)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOMergeSubscription, 10030600)
DEFINE_SQLDMOGUID(CLSID_SQLDMOMergeSubscription2, 100306c1)

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMOMergeSubscriptions, 10030601)
DEFINE_SQLDMOGUID(IID_IWSQLDMOMergeSubscriptions, 10030602)
DEFINE_SQLDMOGUID(IID_IVSQLDMOMergeSubscriptions, 10030603)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOMergeSubscription, 10030604)
DEFINE_SQLDMOGUID(IID_IWSQLDMOMergeSubscription, 10030605)
DEFINE_SQLDMOGUID(IID_IVSQLDMOMergeSubscription, 10030606)

DEFINE_SQLDMOGUID(IID_IWSQLDMOMergeSubscription2, 10030615)
DEFINE_SQLDMOGUID(IID_IVSQLDMOMergeSubscription2, 10030616)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMODistributionPublisher, 10030700)
DEFINE_SQLDMOGUID(CLSID_SQLDMODistributionPublisher2, 100307c1)

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMODistributionPublishers, 10030701)
DEFINE_SQLDMOGUID(IID_IWSQLDMODistributionPublishers, 10030702)
DEFINE_SQLDMOGUID(IID_IVSQLDMODistributionPublishers, 10030703)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMODistributionPublisher, 10030704)
DEFINE_SQLDMOGUID(IID_IWSQLDMODistributionPublisher, 10030705)
DEFINE_SQLDMOGUID(IID_IVSQLDMODistributionPublisher, 10030706)

DEFINE_SQLDMOGUID(IID_IWSQLDMODistributionPublisher2, 10030715)
DEFINE_SQLDMOGUID(IID_IVSQLDMODistributionPublisher2, 10030716)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMORegisteredSubscriber, 10030900)

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMORegisteredSubscribers, 10030901)
DEFINE_SQLDMOGUID(IID_IWSQLDMORegisteredSubscribers, 10030902)
DEFINE_SQLDMOGUID(IID_IVSQLDMORegisteredSubscribers, 10030903)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMORegisteredSubscriber, 10030904)
DEFINE_SQLDMOGUID(IID_IWSQLDMORegisteredSubscriber, 10030905)
DEFINE_SQLDMOGUID(IID_IVSQLDMORegisteredSubscriber, 10030906)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// NO CLSID

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMOReplicationDatabases, 10030a01)
DEFINE_SQLDMOGUID(IID_IWSQLDMOReplicationDatabases, 10030a02)
DEFINE_SQLDMOGUID(IID_IVSQLDMOReplicationDatabases, 10030a03)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOReplicationDatabase, 10030a04)
DEFINE_SQLDMOGUID(IID_IWSQLDMOReplicationDatabase, 10030a05)
DEFINE_SQLDMOGUID(IID_IVSQLDMOReplicationDatabase, 10030a06)

DEFINE_SQLDMOGUID(IID_IWSQLDMOReplicationDatabase2, 10030a15)
DEFINE_SQLDMOGUID(IID_IVSQLDMOReplicationDatabase2, 10030a16)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOTransPullSubscription, 10030b00)
DEFINE_SQLDMOGUID(CLSID_SQLDMOTransPullSubscription2, 10030bc1)

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMOTransPullSubscriptions, 10030b01)
DEFINE_SQLDMOGUID(IID_IWSQLDMOTransPullSubscriptions, 10030b02)
DEFINE_SQLDMOGUID(IID_IVSQLDMOTransPullSubscriptions, 10030b03)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOTransPullSubscription, 10030b04)
DEFINE_SQLDMOGUID(IID_IWSQLDMOTransPullSubscription, 10030b05)
DEFINE_SQLDMOGUID(IID_IVSQLDMOTransPullSubscription, 10030b06)

DEFINE_SQLDMOGUID(IID_IWSQLDMOTransPullSubscription2, 10030b15)
DEFINE_SQLDMOGUID(IID_IVSQLDMOTransPullSubscription2, 10030b16)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// No CLSID

// No Collection

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOPublisher, 10030c04)
DEFINE_SQLDMOGUID(IID_IWSQLDMOPublisher, 10030c05)
DEFINE_SQLDMOGUID(IID_IVSQLDMOPublisher, 10030c06)

DEFINE_SQLDMOGUID(IID_IWSQLDMOPublisher2, 10030c15)
DEFINE_SQLDMOGUID(IID_IVSQLDMOPublisher2, 10030c16)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// No CLSID

// No Collection

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOSubscriber, 10030d04)
DEFINE_SQLDMOGUID(IID_IWSQLDMOSubscriber, 10030d05)
DEFINE_SQLDMOGUID(IID_IVSQLDMOSubscriber, 10030d06)

DEFINE_SQLDMOGUID(IID_IWSQLDMOSubscriber2, 10030d15)
DEFINE_SQLDMOGUID(IID_IVSQLDMOSubscriber2, 10030d16)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// No CLSID

// No Collection

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMODistributor, 10030e04)
DEFINE_SQLDMOGUID(IID_IWSQLDMODistributor, 10030e05)
DEFINE_SQLDMOGUID(IID_IVSQLDMODistributor, 10030e06)

DEFINE_SQLDMOGUID(IID_IWSQLDMODistributor2, 10030e15)
DEFINE_SQLDMOGUID(IID_IVSQLDMODistributor2, 10030e16)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOReplication, 10031000)
DEFINE_SQLDMOGUID(CLSID_SQLDMOReplication2, 100310c1)

// No Collection

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOReplication, 10031004)
DEFINE_SQLDMOGUID(IID_IWSQLDMOReplication, 10031005)
DEFINE_SQLDMOGUID(IID_IVSQLDMOReplication, 10031006)

DEFINE_SQLDMOGUID(IID_IWSQLDMOReplication2, 10031015)
DEFINE_SQLDMOGUID(IID_IVSQLDMOReplication2, 10031016)

// Interface (event sink)
DEFINE_SQLDMOGUID(IID_IWSQLDMOReplicationSink, 10031008)
DEFINE_SQLDMOGUID(IID_IVSQLDMOReplicationSink, 10031009)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOMergePullSubscription, 10031100)
DEFINE_SQLDMOGUID(CLSID_SQLDMOMergePullSubscription2, 100311c1)

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMOMergePullSubscriptions, 10031101)
DEFINE_SQLDMOGUID(IID_IWSQLDMOMergePullSubscriptions, 10031102)
DEFINE_SQLDMOGUID(IID_IVSQLDMOMergePullSubscriptions, 10031103)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOMergePullSubscription, 10031104)
DEFINE_SQLDMOGUID(IID_IWSQLDMOMergePullSubscription, 10031105)
DEFINE_SQLDMOGUID(IID_IVSQLDMOMergePullSubscription, 10031106)

DEFINE_SQLDMOGUID(IID_IWSQLDMOMergePullSubscription2, 10031115)
DEFINE_SQLDMOGUID(IID_IVSQLDMOMergePullSubscription2, 10031116)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOReplicationSecurity, 10031200)

// No Collection

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOReplicationSecurity, 10031204)
DEFINE_SQLDMOGUID(IID_IWSQLDMOReplicationSecurity, 10031205)
DEFINE_SQLDMOGUID(IID_IVSQLDMOReplicationSecurity, 10031206)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMODistributionDatabase, 10031300)
DEFINE_SQLDMOGUID(CLSID_SQLDMODistributionDatabase2, 100313c1)

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMODistributionDatabases, 10031301)
DEFINE_SQLDMOGUID(IID_IWSQLDMODistributionDatabases, 10031302)
DEFINE_SQLDMOGUID(IID_IVSQLDMODistributionDatabases, 10031303)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMODistributionDatabase, 10031304)
DEFINE_SQLDMOGUID(IID_IWSQLDMODistributionDatabase, 10031305)
DEFINE_SQLDMOGUID(IID_IVSQLDMODistributionDatabase, 10031306)

DEFINE_SQLDMOGUID(IID_IWSQLDMODistributionDatabase2, 10031315)
DEFINE_SQLDMOGUID(IID_IVSQLDMODistributionDatabase2, 10031316)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// NO CLSID

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMOReplicationTables, 10031401)
DEFINE_SQLDMOGUID(IID_IWSQLDMOReplicationTables, 10031402)
DEFINE_SQLDMOGUID(IID_IVSQLDMOReplicationTables, 10031403)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOReplicationTable, 10031404)
DEFINE_SQLDMOGUID(IID_IWSQLDMOReplicationTable, 10031405)
DEFINE_SQLDMOGUID(IID_IVSQLDMOReplicationTable, 10031406)

DEFINE_SQLDMOGUID(IID_IWSQLDMOReplicationTable2, 10031415)
DEFINE_SQLDMOGUID(IID_IVSQLDMOReplicationTable2, 10031416)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
// NO CLSID

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMOReplicationStoredProcedures, 10031601)
DEFINE_SQLDMOGUID(IID_IWSQLDMOReplicationStoredProcedures, 10031602)
DEFINE_SQLDMOGUID(IID_IVSQLDMOReplicationStoredProcedures, 10031603)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOReplicationStoredProcedure, 10031604)
DEFINE_SQLDMOGUID(IID_IWSQLDMOReplicationStoredProcedure, 10031605)
DEFINE_SQLDMOGUID(IID_IVSQLDMOReplicationStoredProcedure, 10031606)

DEFINE_SQLDMOGUID(IID_IWSQLDMOReplicationStoredProcedure2, 10031615)
DEFINE_SQLDMOGUID(IID_IVSQLDMOReplicationStoredProcedure2, 10031616)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMODistributionPublication, 10032100)
DEFINE_SQLDMOGUID(CLSID_SQLDMODistributionPublication2, 100321c1)

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMODistributionPublications, 10032101)
DEFINE_SQLDMOGUID(IID_IWSQLDMODistributionPublications, 10032102)
DEFINE_SQLDMOGUID(IID_IVSQLDMODistributionPublications, 10032103)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMODistributionPublication, 10032104)
DEFINE_SQLDMOGUID(IID_IWSQLDMODistributionPublication, 10032105)
DEFINE_SQLDMOGUID(IID_IVSQLDMODistributionPublication, 10032106)

DEFINE_SQLDMOGUID(IID_IWSQLDMODistributionPublication2, 10032115)
DEFINE_SQLDMOGUID(IID_IVSQLDMODistributionPublication2, 10032116)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMODistributionArticle, 10033100)
DEFINE_SQLDMOGUID(CLSID_SQLDMODistributionArticle2, 100331c1)

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMODistributionArticles, 10033101)
DEFINE_SQLDMOGUID(IID_IWSQLDMODistributionArticles, 10033102)
DEFINE_SQLDMOGUID(IID_IVSQLDMODistributionArticles, 10033103)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMODistributionArticle, 10033104)
DEFINE_SQLDMOGUID(IID_IWSQLDMODistributionArticle, 10033105)
DEFINE_SQLDMOGUID(IID_IVSQLDMODistributionArticle, 10033106)

DEFINE_SQLDMOGUID(IID_IWSQLDMODistributionArticle2, 10033115)
DEFINE_SQLDMOGUID(IID_IVSQLDMODistributionArticle2, 10033116)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMODistributionSubscription, 10034100)
DEFINE_SQLDMOGUID(CLSID_SQLDMODistributionSubscription2, 100341c1)

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMODistributionSubscriptions, 10034101)
DEFINE_SQLDMOGUID(IID_IWSQLDMODistributionSubscriptions, 10034102)
DEFINE_SQLDMOGUID(IID_IVSQLDMODistributionSubscriptions, 10034103)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMODistributionSubscription, 10034104)
DEFINE_SQLDMOGUID(IID_IWSQLDMODistributionSubscription, 10034105)
DEFINE_SQLDMOGUID(IID_IVSQLDMODistributionSubscription, 10034106)

DEFINE_SQLDMOGUID(IID_IWSQLDMODistributionSubscription2, 10034115)
DEFINE_SQLDMOGUID(IID_IVSQLDMODistributionSubscription2, 10034116)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOMergeSubsetFilter, 10035100)

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMOMergeSubsetFilters, 10035101)
DEFINE_SQLDMOGUID(IID_IWSQLDMOMergeSubsetFilters, 10035102)
DEFINE_SQLDMOGUID(IID_IVSQLDMOMergeSubsetFilters, 10035103)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOMergeSubsetFilter, 10035104)
DEFINE_SQLDMOGUID(IID_IWSQLDMOMergeSubsetFilter, 10035105)
DEFINE_SQLDMOGUID(IID_IVSQLDMOMergeSubsetFilter, 10035106)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOMergeDynamicSnapshotJob, 10036100)

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMOMergeDynamicSnapshotJobs, 10036101)
DEFINE_SQLDMOGUID(IID_IWSQLDMOMergeDynamicSnapshotJobs, 10036102)
DEFINE_SQLDMOGUID(IID_IVSQLDMOMergeDynamicSnapshotJobs, 10036103)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOMergeDynamicSnapshotJob, 10036104)
DEFINE_SQLDMOGUID(IID_IWSQLDMOMergeDynamicSnapshotJob, 10036105)
DEFINE_SQLDMOGUID(IID_IVSQLDMOMergeDynamicSnapshotJob, 10036106)

// ***************************************************************************
//               Copyright (C) 1985-1999 Microsoft Corporation.
// @File: agen_iid.h
//
// Purpose: IID
//
//
// Notes:
//
// History:
//
//   @Version: Shiloh
//   49246 WG   12/07/99 CTS tracking
//
//
// @EndHeader@
// ***************************************************************************




/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOOperator, 10040200)

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMOOperators, 10040201)
DEFINE_SQLDMOGUID(IID_IWSQLDMOOperators, 10040202)
DEFINE_SQLDMOGUID(IID_IVSQLDMOOperators, 10040203)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOOperator, 10040204)
DEFINE_SQLDMOGUID(IID_IWSQLDMOOperator, 10040205)
DEFINE_SQLDMOGUID(IID_IVSQLDMOOperator, 10040206)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// No CLSID

// No Collection

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOJobServer, 10040404)
DEFINE_SQLDMOGUID(IID_IWSQLDMOJobServer, 10040405)
DEFINE_SQLDMOGUID(IID_IVSQLDMOJobServer, 10040406)

DEFINE_SQLDMOGUID(IID_IWSQLDMOJobServer2, 10040415)
DEFINE_SQLDMOGUID(IID_IVSQLDMOJobServer2, 10040416)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// No CLSID

// No Collection

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOAlertSystem, 10040504)
DEFINE_SQLDMOGUID(IID_IWSQLDMOAlertSystem, 10040505)
DEFINE_SQLDMOGUID(IID_IVSQLDMOAlertSystem, 10040506)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOAlert, 10040600)

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMOAlerts, 10040601)
DEFINE_SQLDMOGUID(IID_IWSQLDMOAlerts, 10040602)
DEFINE_SQLDMOGUID(IID_IVSQLDMOAlerts, 10040603)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOAlert, 10040604)
DEFINE_SQLDMOGUID(IID_IWSQLDMOAlert, 10040605)
DEFINE_SQLDMOGUID(IID_IVSQLDMOAlert, 10040606)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOJob, 10040800)

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMOJobs, 10040801)
DEFINE_SQLDMOGUID(IID_IWSQLDMOJobs, 10040802)
DEFINE_SQLDMOGUID(IID_IVSQLDMOJobs, 10040803)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOJob, 10040804)
DEFINE_SQLDMOGUID(IID_IWSQLDMOJob, 10040805)
DEFINE_SQLDMOGUID(IID_IVSQLDMOJob, 10040806)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOJobStep, 10040900)

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMOJobSteps, 10040901)
DEFINE_SQLDMOGUID(IID_IWSQLDMOJobSteps, 10040902)
DEFINE_SQLDMOGUID(IID_IVSQLDMOJobSteps, 10040903)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOJobStep, 10040904)
DEFINE_SQLDMOGUID(IID_IWSQLDMOJobStep, 10040905)
DEFINE_SQLDMOGUID(IID_IVSQLDMOJobStep, 10040906)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOTargetServer, 10041000)

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMOTargetServers, 10041001)
DEFINE_SQLDMOGUID(IID_IWSQLDMOTargetServers, 10041002)
DEFINE_SQLDMOGUID(IID_IVSQLDMOTargetServers, 10041003)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOTargetServer, 10041004)
DEFINE_SQLDMOGUID(IID_IWSQLDMOTargetServer, 10041005)
DEFINE_SQLDMOGUID(IID_IVSQLDMOTargetServer, 10041006)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOTargetServerGroup, 10041100)

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMOTargetServerGroups, 10041101)
DEFINE_SQLDMOGUID(IID_IWSQLDMOTargetServerGroups, 10041102)
DEFINE_SQLDMOGUID(IID_IVSQLDMOTargetServerGroups, 10041103)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOTargetServerGroup, 10041104)
DEFINE_SQLDMOGUID(IID_IWSQLDMOTargetServerGroup, 10041105)
DEFINE_SQLDMOGUID(IID_IVSQLDMOTargetServerGroup, 10041106)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// No CLSID

// No Collection

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOSchedule, 10041204)
DEFINE_SQLDMOGUID(IID_IWSQLDMOSchedule, 10041205)
DEFINE_SQLDMOGUID(IID_IVSQLDMOSchedule, 10041206)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// No CLSID

// No Collection

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOJobFilter, 10041304)
DEFINE_SQLDMOGUID(IID_IWSQLDMOJobFilter, 10041305)
DEFINE_SQLDMOGUID(IID_IVSQLDMOJobFilter, 10041306)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID

// No Collection

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOJobHistoryFilter, 10041404)
DEFINE_SQLDMOGUID(IID_IWSQLDMOJobHistoryFilter, 10041405)
DEFINE_SQLDMOGUID(IID_IVSQLDMOJobHistoryFilter, 10041406)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOCategory, 10041500)

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMOJobCategories, 10041501)
DEFINE_SQLDMOGUID(IID_IWSQLDMOJobCategories, 10041502)
DEFINE_SQLDMOGUID(IID_IVSQLDMOJobCategories, 10041503)

// DEFINE_SQLDMOGUID(IID_IASQLDMOAlertCategories, 10041504)
DEFINE_SQLDMOGUID(IID_IWSQLDMOAlertCategories, 10041505)
DEFINE_SQLDMOGUID(IID_IVSQLDMOAlertCategories, 10041506)

// DEFINE_SQLDMOGUID(IID_IASQLDMOOperatorCategories, 10041507)
DEFINE_SQLDMOGUID(IID_IWSQLDMOOperatorCategories, 10041508)
DEFINE_SQLDMOGUID(IID_IVSQLDMOOperatorCategories, 10041509)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOCategory, 10041510)
DEFINE_SQLDMOGUID(IID_IWSQLDMOCategory, 10041511)
DEFINE_SQLDMOGUID(IID_IVSQLDMOCategory, 10041512)

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// CLSID
DEFINE_SQLDMOGUID(CLSID_SQLDMOJobSchedule, 10041600)

// Collection
// DEFINE_SQLDMOGUID(IID_IASQLDMOJobSchedules, 10041601)
DEFINE_SQLDMOGUID(IID_IWSQLDMOJobSchedules, 10041602)
DEFINE_SQLDMOGUID(IID_IVSQLDMOJobSchedules, 10041603)

// Interface
// DEFINE_SQLDMOGUID(IID_IASQLDMOJobSchedule, 10041604)
DEFINE_SQLDMOGUID(IID_IWSQLDMOJobSchedule, 10041605)
DEFINE_SQLDMOGUID(IID_IVSQLDMOJobSchedule, 10041606)



#endif


