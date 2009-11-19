/////////////////////////////////////////////////////////////////////////////////////////
// Header file for SQLDMO C/C++ Client Component Object interfaces.
// Copyright 1994-2000 Microsoft Corporation.
/////////////////////////////////////////////////////////////////////////////////////////


#ifndef _SQLDMO_H_
#define _SQLDMO_H_

// ***************************************************************************
//               Copyright (C) 1985-1999 Microsoft Corporation.
// @File: dmo_itf.h
//
// Purpose: c and c++ object interfaces
//
//
// Notes:
//
// History:
//
//   @Version: Shiloh
//   55901 WG   02/28/00 Copyright
//   52941 WG   01/31/00 UDF and UDDT backward compatible
//   52126 WG   01/19/00 Comments
//   49129 WG   12/07/99 CTS tracking
//
//
// @EndHeader@
// ***************************************************************************


// SQLDMO versions supported for this header file.
#define SQLDMOVERSION_750		0x07320000
#define SQLDMOVERSION_800		0x08000000

// Current version of SQLDMO for this header file (matches sp_MSSQLDMO_version).
// #define SQLDMOVERSION_CURRENT	SQLDMOVERSION_750
#define SQLDMOVERSION_CURRENT	SQLDMOVERSION_800

/////////////////////////////////////////////////////////////////////////////////////////
// Constant enumerations.
/////////////////////////////////////////////////////////////////////////////////////////
#ifndef _SQLDMO_CONSTANTS_
#define _SQLDMO_CONSTANTS_

#ifdef _SQLDMO_ODL_		// Generate helpids if in ODL file.
#define SQLDMO_HELPID(id) [helpcontext(H_##id)]
#else
#define SQLDMO_HELPID(id)
#endif


typedef SQLDMO_HELPID(SQLDMO_OBJECT_TYPE) enum {
	SQLDMOObj_Unknown = 16384,		// Make it the only bit set
	SQLDMOObj_Application = 0,

	// Database objects, value is power(2, sysobjects.sysstat & 0x0f), plus UDDTs in 0.
	// These values can be bitmasked together for object listings.

   // !!! 8.0, UDF is using 1, but 1 has been used by UDDT in pre-80 DMO, due to backward compatible reason,
   // !!! we had to use 4096 for UDF, and swap the value dynamically
   // !!! becasue of this change, the values for SQLDMOObj_AllDatabaseUserObjects, SQLDMOObj_AllDatabaseObjects
   // !!! and SQLDMOObj_AllButSystemObjects are also affected
	SQLDMOObj_UserDefinedDatatype =           0x00000001,    // 1
	SQLDMOObj_SystemTable =                   0x00000002,    // 2
	SQLDMOObj_View =                          0x00000004,    // 4
	SQLDMOObj_UserTable =                     0x00000008,    // 8
	SQLDMOObj_StoredProcedure =               0x00000010,    // 16
	SQLDMOObj_Default =                       0x00000040,    // 64
	SQLDMOObj_Rule =                          0x00000080,    // 128
	SQLDMOObj_Trigger =                       0x00000100,    // 256
	SQLDMOObj_UserDefinedFunction =           0x00001000,    // 4096 (512 - 2048 are used already), this is new for 8.0
                                                            // But power(2, ...) is 1

	SQLDMOObj_AllDatabaseUserObjects =        0x000011fd,    // All but system tables
	SQLDMOObj_AllDatabaseObjects =            0x000011ff,    // All including system tables
	SQLDMOObj_AllButSystemObjects =           0x000013ff,    // All but system objects


// ***************************************************************************
//               Copyright (C) 1985-1999 Microsoft Corporation.
// @File: core_itf.h
//
// Purpose: CORE defines and interfaces
//
//
// Notes:
//
// History:
//
//   @Version: Shiloh
//   65649 IXL  07/08/00 remove job server from job script
//   61175 WG   05/10/00 VIA Netlibs
//   60740 WG   05/08/00 New dboptions for recovery
//   60549 WG   05/01/00 New ServerRole bulkadmin
//   60311 WG   04/27/00 Encrypted UDF checking
//   55928 WG   02/28/00 Compatibility level
//   54473 WG   02/11/00 New script option
//   54427 WG   02/11/00 Restore BackupSetName
//   54311 WG   02/10/00 Extended Property
//   53618 WG   02/03/00 UDF ListPermission
//   53312 WG   01/31/00 Transferrable encryption
//   53089 WG   01/28/00 New Backup Restore option
//   52952 WG   01/27/00 Linked Server option
//   52788 WG   01/26/00 Linked Server options
//   52521 WG   01/24/00 Backup and Restore
//   52513 WG   01/24/00 GrantedGranted
//   52356 WG   01/21/00 ProductLevel
//   51928 WG   01/18/00 EnumAvailableMedia
//   51899 WG   01/18/00 DatabaseRole
//   51623 WG   01/17/00 IsDeleted
//   51534 WG   01/13/00 CheckSyntax
//   50625 WG   01/04/00 Syntax check for default and rule
//   50559 WG   01/03/00 Language ID on fulltext column
//   50447 WG   12/29/99 EnumDependencies with system objects
//   49768 WG   12/14/99 Support bigint in QueryResult
//   49712 WG   12/13/99 Refresh for LinkedServer
//   49522 WG   12/10/99 Script Job with enable flag
//   49452 WG   12/10/99 EnumParameters for UDF
//   49129 WG   12/07/99 CTS tracking
//
//
// @EndHeader@
// ***************************************************************************




        // Other Database objects (not in sysobjects)
        SQLDMOObj_SystemDatatype =                0x00001000,
        SQLDMOObj_User =                          0x00002000,
        SQLDMOObj_Group =                         0x00003000,
        SQLDMOObj_Index =                         0x00004000,
        SQLDMOObj_Key =                           0x00005000,
        SQLDMOObj_Column =                        0x00006000,
        SQLDMOObj_DBObject =                      0x00007000,
        SQLDMOObj_DBOption =                      0x00008000,
        SQLDMOObj_ProcedureParameter =            0x00009000,
        SQLDMOObj_Permission =                    0x0000A000,
        SQLDMOObj_IntegratedSecurity =            0x0000B000,
        SQLDMOObj_Check =                         0x0000C000,
        SQLDMOObj_DRIDefault =                    0x0000D000,

        // Objects not in databases.
        SQLDMOObj_SQLServer =                     0x00020000,
        SQLDMOObj_Database =                      0x00021000,
        SQLDMOObj_BackupDevice =                  0x00022000,
        SQLDMOObj_Login =                         0x00023000,
        SQLDMOObj_Language =                      0x00024000,
        SQLDMOObj_RemoteServer =                  0x00025000,
        SQLDMOObj_RemoteLogin =                   0x00026000,
        SQLDMOObj_Configuration =                 0x00027000,
        SQLDMOObj_ConfigValue =                   0x00028000,
        SQLDMOObj_QueryResults =                  0x00029000,
        SQLDMOObj_TransactionLog =                0x0002A000,
        SQLDMOObj_Registry =                      0x0002B000,
        SQLDMOObj_Transfer =                      0x0002C000,
        SQLDMOObj_Backup =                        0x0002D000,
        SQLDMOObj_AutoProperty =                  0x0002E000,
        SQLDMOObj_ServerGroup =                   0x0002F000,
        SQLDMOObj_RegisteredServer =              0x00031000,
        SQLDMOObj_BulkCopy =                      0x00032000,
        SQLDMOObj_FileGroup =                     0x00033000,
        SQLDMOObj_DBFile =                        0x00034000,
        SQLDMOObj_LogFile =                       0x00035000,
        SQLDMOObj_ServerRole =                    0x00036000,
        SQLDMOObj_DatabaseRole =                  0x00037000,
        SQLDMOObj_Restore =                       0x00038000,
        SQLDMOObj_LinkedServer =                  0x00039000,
        SQLDMOObj_LinkedServerLogin =             0x00040000,
        SQLDMOObj_FullTextCatalog =               0x00041000,
        SQLDMOObj_FullTextService =               0x00042000,








   // Replication Objects
	SQLDMOObj_TransPublication =      		0x00101000,
	SQLDMOObj_TransArticle =          		0x00102000,
	SQLDMOObj_TransSubscription =     		0x00103000,
	SQLDMOObj_TransPullSubscription =		0x00104000,
	SQLDMOObj_MergePublication =         	0x00105000,
	SQLDMOObj_MergeArticle = 				0x00106000,
	SQLDMOObj_MergeSubscription =        	0x00107000,
	SQLDMOObj_MergePullSubscription =		0x00108000,
	SQLDMOObj_Replication =                 0x00109000,
	SQLDMOObj_Publisher =                   0x0010A000,
	SQLDMOObj_Subscriber =                  0x0010B000,
	SQLDMOObj_Distributor =                 0x0010C000,
	SQLDMOObj_ReplicationSecurity =         0x0010D000,
	SQLDMOObj_DistributionPublisher =       0x0010E000,
	SQLDMOObj_RegisteredSubscriber =        0x0010F000,
	SQLDMOObj_ReplicationDatabase =         0x00110000,
	SQLDMOObj_DistributionDatabase =        0x00111000,
	SQLDMOObj_ReplicationTable =            0x00112000,
	SQLDMOObj_ReplicationStoredProcedure =  0x00113000,
	SQLDMOObj_DistributionPublication =     0x00114000,
	SQLDMOObj_DistributionArticle =         0x00115000,
	SQLDMOObj_DistributionSubscription =    0x00116000,
	SQLDMOObj_MergeSubsetFilter = 			0x00117000,
    SQLDMOObj_MergeDynamicSnapshotJob =     0x00118000,




// ***************************************************************************
//               Copyright (C) 1985-1999 Microsoft Corporation.
// @File: agen_itf.h
//
// Purpose: Agent defines and interfaces
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




   // SQL JobServer Objects
        SQLDMOObj_AlertSystem =                   0x00201000,
        SQLDMOObj_JobServer =                     0x00202000,
        SQLDMOObj_Alert =                         0x00203000,
        SQLDMOObj_Operator =                      0x00204000,
        SQLDMOObj_Job =                           0x00205000,
        SQLDMOObj_JobStep =                       0x00206000,
        SQLDMOObj_TargetServer =                  0x00207000,
        SQLDMOObj_TargetServerGroup =             0x00208000,
        SQLDMOObj_Category =                      0x00209000,
        SQLDMOObj_Schedule =                      0x00210000,
        SQLDMOObj_JobFilter =                     0x00211000,
        SQLDMOObj_JobHistoryFilter =              0x00212000,
        SQLDMOObj_JobSchedule =                   0x00213000,








   SQLDMOObj_Last =                          0x10000000     // End of enumeration.

} SQLDMO_OBJECT_TYPE;

// ***************************************************************************
//               Copyright (C) 1985-1999 Microsoft Corporation.
// @File: core_itf.h
//
// Purpose: CORE defines and interfaces
//
//
// Notes:
//
// History:
//
//   @Version: Shiloh
//   65649 IXL  07/08/00 remove job server from job script
//   61175 WG   05/10/00 VIA Netlibs
//   60740 WG   05/08/00 New dboptions for recovery
//   60549 WG   05/01/00 New ServerRole bulkadmin
//   60311 WG   04/27/00 Encrypted UDF checking
//   55928 WG   02/28/00 Compatibility level
//   54473 WG   02/11/00 New script option
//   54427 WG   02/11/00 Restore BackupSetName
//   54311 WG   02/10/00 Extended Property
//   53618 WG   02/03/00 UDF ListPermission
//   53312 WG   01/31/00 Transferrable encryption
//   53089 WG   01/28/00 New Backup Restore option
//   52952 WG   01/27/00 Linked Server option
//   52788 WG   01/26/00 Linked Server options
//   52521 WG   01/24/00 Backup and Restore
//   52513 WG   01/24/00 GrantedGranted
//   52356 WG   01/21/00 ProductLevel
//   51928 WG   01/18/00 EnumAvailableMedia
//   51899 WG   01/18/00 DatabaseRole
//   51623 WG   01/17/00 IsDeleted
//   51534 WG   01/13/00 CheckSyntax
//   50625 WG   01/04/00 Syntax check for default and rule
//   50559 WG   01/03/00 Language ID on fulltext column
//   50447 WG   12/29/99 EnumDependencies with system objects
//   49768 WG   12/14/99 Support bigint in QueryResult
//   49712 WG   12/13/99 Refresh for LinkedServer
//   49522 WG   12/10/99 Script Job with enable flag
//   49452 WG   12/10/99 EnumParameters for UDF
//   49129 WG   12/07/99 CTS tracking
//
//
// @EndHeader@
// ***************************************************************************




typedef SQLDMO_HELPID(SQLDMO_KEY_TYPE) enum {
        SQLDMOKey_Unknown = 0,
        SQLDMOKey_Primary = 1,
        SQLDMOKey_Unique = 2,
        SQLDMOKey_Foreign = 3
} SQLDMO_KEY_TYPE;

typedef SQLDMO_HELPID(SQLDMO_DEVICE_TYPE) enum {
        SQLDMODevice_Unknown = 100,
        SQLDMODevice_DiskDump = 2,
        SQLDMODevice_FloppyADump = 3,
        SQLDMODevice_FloppyBDump = 4,
        SQLDMODevice_TapeDump = 5,
        SQLDMODevice_PipeDump = 6,
        SQLDMODevice_CDROM = 7
} SQLDMO_DEVICE_TYPE;

typedef SQLDMO_HELPID(SQLDMO_PRIVILEGE_TYPE) enum {
        SQLDMOPriv_Unknown = 0,

        // Privilege values, different from sysprotects as we need to bitmask.
        // Object privileges.
        SQLDMOPriv_Select = 1,
        SQLDMOPriv_Insert = 2,
        SQLDMOPriv_Update = 4,
        SQLDMOPriv_Delete = 8,
        SQLDMOPriv_Execute = 16,
        SQLDMOPriv_References = 32,
        SQLDMOPriv_AllObjectPrivs = 63,

        // Database (statement) privileges.
        SQLDMOPriv_CreateTable = 128,
        SQLDMOPriv_CreateDatabase = 256,
        SQLDMOPriv_CreateView = 512,
        SQLDMOPriv_CreateProcedure = 1024,
        SQLDMOPriv_DumpDatabase = 2048,
        SQLDMOPriv_CreateDefault = 4096,
        SQLDMOPriv_DumpTransaction = 8192,
        SQLDMOPriv_CreateRule = 16384,
        SQLDMOPriv_DumpTable = 32768,
        SQLDMOPriv_CreateFunction = 65536,
        SQLDMOPriv_AllDatabasePrivs = 130944
} SQLDMO_PRIVILEGE_TYPE;

typedef SQLDMO_HELPID(SQLDMO_PROCEDURE_TYPE) enum {
        SQLDMOProc_Unknown = 0,
        SQLDMOProc_Standard = 1,
        SQLDMOProc_Extended = 2,
        SQLDMOProc_Macro = 3,
        SQLDMOProc_ReplicationFilter = 4
} SQLDMO_PROCEDURE_TYPE;

// Trigger types may be OR'd together.
typedef SQLDMO_HELPID(SQLDMO_TRIGGER_TYPE) enum {
        SQLDMOTrig_Unknown = 0,
        SQLDMOTrig_Insert = 1,
        SQLDMOTrig_Update = 2,
        SQLDMOTrig_Delete = 4,
        SQLDMOTrig_All = 7
} SQLDMO_TRIGGER_TYPE;

typedef SQLDMO_HELPID(SQLDMO_INDEX_TYPE) enum {                                                 // SQLDMO Internal:  sync with ntinc\index.h
        // Index type values as in sysindexes.status.
        SQLDMOIndex_Default = 0x0000,
        SQLDMOIndex_IgnoreDupKey = 0x0001,
        SQLDMOIndex_Unique = 0x0002,
//        SQLDMOIndex_IgnoreDupRow = 0x0004,      // obsolete in 7.0
        SQLDMOIndex_Clustered = 0x0010,
//        SQLDMOIndex_AllowDupRow = 0x0040,       // obsolete in 7.0
        SQLDMOIndex_PadIndex = 0x0100,          // new for 7.0, fillfactor applies to index nodes also
        SQLDMOIndex_SortedData = 0x0200,
        SQLDMOIndex_SortedDataReorg = 0x2000,   // 6.0-only; sorted-data with reorganization
        SQLDMOIndex_DropExist = 0x8000,         // new for 7.0, Drop the existing index
//        SQLDMOIndex_Valid = 0xA357,             // Any of foregoing (writable) types
        SQLDMOIndex_Valid = 0xA313,             // Any of foregoing (writable) types
        SQLDMOIndex_Hypothetical = 0x0020,      // new for 7.0, statistics only index, we get this for both 'CREATE STATISTICS' and 'CREATE INDEX...WITH STATISTICS_ONLY'
        SQLDMOIndex_DRIPrimaryKey = 0x0800,     // 6.0-only, readonly; DRI-generated types
        SQLDMOIndex_DRIUniqueKey = 0x1000,
        SQLDMOIndex_DRIIndex = 0x1800,          // Index implements DRI (DRIPrimaryKey | DRIUniqueKey)
        SQLDMOIndex_NoRecompute = 0x01000000,   // new for 7.0
} SQLDMO_INDEX_TYPE;

typedef SQLDMO_HELPID(SQLDMO_QUERY_DATATYPE) enum {
   // Indexed as per ..\common\inc\sql.hpp and sql.h sqlext.h datatype constants.
        SQLDMO_DTypeUnknown     = 0,
        SQLDMO_DTypeChar        = 1,                         // SQL_CHAR
        SQLDMO_DTypeText        = -1,                        // SQL_LONGVARCHAR
        SQLDMO_DTypeVarchar     = 12,                        // SQL_VARCHAR
        SQLDMO_DTypeVarBinary   = -3,                        // SQL_VARBINARY
        SQLDMO_DTypeBinary      = -2,                        // SQL_BINARY
        SQLDMO_DTypeImage       = -4,                        // SQL_LONGVARBINARY
        SQLDMO_DTypeFloat4      = 7,                         // SQL_REAL
        SQLDMO_DTypeFloat8      = 8,                         // SQL_DOUBLE
        SQLDMO_DTypeInt1        = -6,                        // SQL_TINYINT
        SQLDMO_DTypeInt2        = 5,                         // SQL_SMALLINT
        SQLDMO_DTypeInt4        = 4,                         // SQL_INTEGER
        SQLDMO_DTypeMoney4      = 3,                         // SQL_DECIMAL
        SQLDMO_DTypeMoney       = 3,                         // SQL_DECIMAL
        SQLDMO_DTypeDateTime    = -2,                        // SQL_BINARY
        SQLDMO_DTypeDateTime4   = 93,                        // SQL_TYPE_TIMESTAMP
        SQLDMO_DTypeBit         = -7,                        // SQL_BIT
        SQLDMO_DTypeUChar       = -8,                        // SQL_WCHAR
        SQLDMO_DTypeUVarchar    = -9,                        // SQL_WVARCHAR
        SQLDMO_DTypeGUID        = -11,                       // SQL_GUID
        SQLDMO_DTypeNText       = -10,                       // SQL_WLONGVARCHAR
        SQLDMO_DTypeBigint      = -5,                        // SQL_BIGINT
        SQLDMO_DTypeSQLVariant  = -150,                      // SQL_VARIANT
} SQLDMO_QUERY_DATATYPE;

typedef SQLDMO_HELPID(SQLDMO_AUDIT_TYPE) enum {
        SQLDMOAudit_None = 0,
        SQLDMOAudit_Success = 1,
        SQLDMOAudit_Failure = 2,
        SQLDMOAudit_All = 3
} SQLDMO_AUDIT_TYPE;

typedef SQLDMO_HELPID(SQLDMO_SECURITY_TYPE) enum {
        SQLDMOSecurity_Min = 0,
        SQLDMOSecurity_Normal = 0,
        SQLDMOSecurity_Integrated = 1,
        SQLDMOSecurity_Mixed = 2,
        SQLDMOSecurity_Max = 2,
        SQLDMOSecurity_Unknown = 9
} SQLDMO_SECURITY_TYPE;

typedef SQLDMO_HELPID(SQLDMO_MEDIA_TYPE) enum {
        SQLDMOMedia_Floppy = 1,
        SQLDMOMedia_FixedDisk = 2,
        SQLDMOMedia_Tape = 4,
        SQLDMOMedia_CDROM = 8,
        SQLDMOMedia_All = 15,
        SQLDMOMedia_SharedFixedDisk = 16
} SQLDMO_MEDIA_TYPE;

typedef SQLDMO_HELPID(SQLDMO_PERFMON_TYPE) enum {
        SQLDMOPerfmon_None = 1000,                                      // No perfmon integration
        SQLDMOPerfmon_MinSet = 0,
        SQLDMOPerfmon_Continuous = 0,
        SQLDMOPerfmon_OnDemand = 1,
        SQLDMOPerfmon_MaxSet = 1
} SQLDMO_PERFMON_TYPE;

typedef SQLDMO_HELPID(SQLDMO_DBSTATUS_TYPE) enum {
        SQLDMODBStat_Normal = 0x0000,
        SQLDMODBStat_Loading = 0x0020,              // isinload
        SQLDMODBStat_Recovering = 0x00c0,           // 0x40 | 0x080, isinrecovery, isnotrecovered
        SQLDMODBStat_Suspect = 0x0100,              // issuspect, isshutdown (IsSuspect for recovery failure, IsShutdown for missing files)
        SQLDMODBStat_Offline = 0x0200,              // isoffline, isdetached
        SQLDMODBStat_Inaccessible = 0x03e0,         // Loading | Recovering | Suspect | Offline
        SQLDMODBStat_EmergencyMode = 0x8000,        // isemergencymode
        SQLDMODBStat_Standby = 0x0400,              // online as readonly, with restore log allowed
        SQLDMODBStat_All = 0x87e0
} SQLDMO_DBSTATUS_TYPE;

typedef SQLDMO_HELPID(SQLDMO_COPYDATA_TYPE) enum {
        SQLDMOCopyData_False = 0,
        SQLDMOCopyData_Replace = 1,
        SQLDMOCopyData_Append = 2
} SQLDMO_COPYDATA_TYPE;

typedef SQLDMO_HELPID(SQLDMO_DATAFILE_TYPE) enum {
        // Bulk-copy datafile options (Table/View.Export and Table.Import).  These are mutually exclusive.
        SQLDMODataFile_CommaDelimitedChar =             0x00000001,     // ColumnDelimiter == Comma, RowDelimiter == <CRLF>
        SQLDMODataFile_Default =                                        0x00000001,     // Default == csv
        SQLDMODataFile_TabDelimitedChar =                       0x00000002,     // ColumnDelimiter == <TAB>, RowDelimiter == <CRLF>
        SQLDMODataFile_SpecialDelimitedChar =           0x00000003,     // Set BulkCopy.ColumnDelimiter and .RowDelimiter
        SQLDMODataFile_NativeFormat =                           0x00000004,     // Use native datatype formats
        SQLDMODataFile_UseFormatFile =                          0x00000005,     // Use an existing format file.
} SQLDMO_DATAFILE_TYPE;

typedef SQLDMO_HELPID(SQLDMO_STATUSINFO_TYPE) enum {
        SQLDMOStatInfo_Unknown = 0,                                     // Initialization value, not valid as a parameter
        SQLDMOStatInfo_DatabaseStatus = 0x0001,         // Database.Status
        SQLDMOStatInfo_DatabaseSpace = 0x0002,          // Database.SpaceAvailable
        SQLDMOStatInfo_AutoVerifyConnection = 0x0004,   // Server.VerifyConnection done automatically.
        SQLDMOStatInfo_All = 0x0007                                     // All the foregoing
} SQLDMO_STATUSINFO_TYPE;

typedef SQLDMO_HELPID(SQLDMO_SCRIPT_TYPE) enum {
        // What's included in the Script method output.
        SQLDMOScript_None                  = 0x0000,   // Skip all the flags from SQLDMO_SCRIPT_TYPE
        SQLDMOScript_Default               = 0x0004,   // Object creation only
        SQLDMOScript_Drops                 = 0x0001,   // Include object drops
        SQLDMOScript_ObjectPermissions     = 0x0002,   // Include object permissions
        SQLDMOScript_PrimaryObject         = 0x0004,   // Include object creation
        SQLDMOScript_ClusteredIndexes      = 0x0008,   // Include clustered index creation (table and view only)
        SQLDMOScript_Triggers              = 0x0010,   // Include trigger creation (table and view only)
        SQLDMOScript_DatabasePermissions   = 0x0020,   // Database (statement) permissions
        SQLDMOScript_Permissions           = 0x0022,   // Both database and object permissions (for scripting users).
        SQLDMOScript_ToFileOnly            = 0x0040,   // If not set, a string is returned (if file nonnull, both are done)
        SQLDMOScript_Bindings              = 0x0080,   // Include rule/default bindings (table only)
        SQLDMOScript_AppendToFile          = 0x0100,   // Append to output file if it already exists.
        SQLDMOScript_NoDRI                 = 0x0200,   // Do not include DRI (intended for use if targeting pre-6.0 server with scripts)
        SQLDMOScript_UDDTsToBaseType       = 0x0400,   // Convert UserDefinedDatatypes to base type when creating columns (table only)
		// 0x0800 available.
        SQLDMOScript_IncludeIfNotExists    = 0x1000,   // Include "if not exists" on object creation.
        SQLDMOScript_NonClusteredIndexes   = 0x2000,   // Include nonclustered index creation (table and view only)
        SQLDMOScript_Indexes               = 0x12008,  // Include all index creation (table and view only)
        SQLDMOScript_Aliases               = 0x4000,   // For users, script aliases
        SQLDMOScript_NoCommandTerm         = 0x8000,   // Do not append "GO" to commands.
        SQLDMOScript_DRIIndexes            = 0x10000,  // Script DRI-generated indexes as indexes if NoDRI is specified.
        SQLDMOScript_IncludeHeaders        = 0x20000,  // Include descriptive header in individual object script output.
        SQLDMOScript_OwnerQualify          = 0x40000,  // Owner-qualify DROP statements (and CREATE where possible).
        SQLDMOScript_TimestampToBinary     = 0x80000,  // Convert timestamp columns to binary(8) (for replication, etc.).
        SQLDMOScript_SortedData            = 0x100000, // If the index or constraint was clustered, append sorted_data
        SQLDMOScript_SortedDataReorg       = 0x200000, // Same as SQLDMOScript_SortedData, but Reorg is used to preserve fillfactor.
        SQLDMOScript_TransferDefault       = 0x670ff,  // The default script type for Transfer. This is combination of following flags:
                                                       // SQLDMOScript_PrimaryObject | SQLDMOScript_Bindings | SQLDMOScript_ClusteredIndexes | SQLDMOScript_NonClusteredIndexes |
                                                       // SQLDMOScript_Triggers| SQLDMOScript_ToFileOnly|SQLDMOScript_Permissions| SQLDMOScript_IncludeHeaders|
                                                       // SQLDMOScript_Aliases|SQLDMOScript_IncludeIfNotExists|SQLDMOScript_OwnerQualify|SQLDMOScript_Drops
        // DRI-restrictive flags.  These may be combined with PrimaryObject as desired.
        // These are to be used to include or exclude specific DRI components, such
        // as for multi-pass scripting.
        SQLDMOScript_DRI_NonClustered     = 0x00400000,
        SQLDMOScript_DRI_Clustered        = 0x00800000,
        SQLDMOScript_DRI_Checks           = 0x01000000,
        SQLDMOScript_DRI_Defaults         = 0x02000000,
        SQLDMOScript_DRI_UniqueKeys       = 0x04000000,
        SQLDMOScript_DRI_ForeignKeys      = 0x08000000,
        SQLDMOScript_DRI_PrimaryKey       = 0x10000000,
        SQLDMOScript_DRI_AllKeys          = 0x1c000000,  // Bitmask of all key types (PK, FK, Unique).
        SQLDMOScript_DRI_AllConstraints   = 0x1f000000,  // Bitmask of all constraint types (PK, FK, Unique, Check, Default).
        SQLDMOScript_DRI_All              = 0x1fc00000,  // All the foregoing (specifying this and not PrimaryObject gets just DRI output).
        SQLDMOScript_DRIWithNoCheck       = 0x20000000,  // Script DRI with nocheck (not included in _DRI_All).
        SQLDMOScript_NoIdentity           = 0x40000000,  // Script with no IDENTITY attribute (e.g. for Replication).

        SQLDMOScript_UseQuotedIdentifiers = 0x80000000,  // Scripts with quoted identifiers. Also will cause Transfer to SET QUOTED_IDENTIFIER ON on the destination.
                                                         // !!! This is a backward compatible flag, when scripting from post 6.5 server, this flag would be igored.
                                                         // !!! When scripting out from 7.0: StoreProcedure, View and Trigger carry their own QI and AnsiNulls setting
                                                         //     (based on the setting when the original object was created), and this flag does not affect them anymore.
                                                         //     At the end of these object scripting, they set QI to the setting according to this flag,
                                                         //     and AnsiNulls to ON (ODBC default).
} SQLDMO_SCRIPT_TYPE;

typedef SQLDMO_HELPID(SQLDMO_SCRIPT2_TYPE) enum {
        // Optional Script parameter.
        SQLDMOScript2_Default          = 0x0000,   // Default
        SQLDMOScript2_AnsiPadding      = 0x0001,   // Explicitly SET ANSI PADDING on or off before the create table
        SQLDMOScript2_AnsiFile         = 0x0002,   // Generate ANSI output file
        SQLDMOScript2_UnicodeFile      = 0x0004,   // Generate UNICODE output file
        SQLDMOScript2_NonStop          = 0x0008,   // When error during script file generation, log error and continue.
                                                   // This is a special case for Convert(scptxfr70.exe), not a general purpose flag
                                                   // If client uses this flag to generate output files, they are running on their own risk
                                                   // This flag affects script out (and only the part used by Convert), it does not affect transfer in.
        SQLDMOScript2_NoFG             = 0x0010,   // Do not generate 'ON <filegroup>'. For Replication
        SQLDMOScript2_MarkTriggers     = 0x0020,   // Mark system triggers. For Replication single table script only.
        SQLDMOScript2_OnlyUserTriggers = 0x0040,   // Only script user triggers. For Replication single table script only.
        SQLDMOScript2_EncryptPWD       = 0x0080,   // Script encrypted password for logins
        SQLDMOScript2_SeparateXPs      = 0x0100,   // Script XP to a separate file (Convert)
        SQLDMOScript2_NoWhatIfIndexes  = 0x0200,   // Do not script What-If indexes (default: script out)
        // Following are SQLAgent related scripting flags
        SQLDMOScript2_AgentNotify      = 0x0400,   // Script Notification for SQLAgent alert object
        SQLDMOScript2_AgentAlertJob    = 0x0800,   // Include Job in Alert scripting
        // Monarch full-text flag
        SQLDMOScript2_FullTextIndex    = 0x80000,   // Include full-text index scripting (table only)
        SQLDMOScript2_LoginSID         = 0x100000,  // Include the SID for standard SQLServer logins
        SQLDMOScript2_FullTextCat      = 0x200000,  // Include full-text catelog scripting
        // Extended property
        SQLDMOScript2_ExtendedProperty = 0x400000,  // Include extended property scripting as part of object scripting
        SQLDMOScript2_NoCollation      = 0x800000,  // Do not script the collation clause (if source is on 7.x server).
                                                    // Default is to generate collation clause if server is on 7.x server
        SQLDMOScript2_70Only           = 0x1000000, // Flag to turn off the post-7.0 features, so the output is compatible to 7.0 server.  Default is OFF
        SQLDMOScript2_JobDisable       = 0x2000000, // If specified, we would script TSQL to disable the job at the end of job creation
        SQLDMOScript2_ExtendedOnly     = 0x4000000, // Generate extended property only, no object creation, drop, permission, or binding would be generated.
        SQLDMOScript2_DontScriptJobServer = 0x8000000 // Don't script job server for a job script
} SQLDMO_SCRIPT2_TYPE;

typedef SQLDMO_HELPID(SQLDMO_XFRSCRIPTMODE_TYPE) enum {
        // How many files the XFR Script is to written to.
        SQLDMOXfrFile_Default             = 0x0001,          // Default to summary files
        SQLDMOXfrFile_SummaryFiles        = 0x0001,          // One files per class of objects transferred/dropped
        SQLDMOXfrFile_SingleFile          = 0x0002,          // All scripts go to same file
        SQLDMOXfrFile_SingleFilePerObject = 0x0004,          // One file per object
        SQLDMOXfrFile_SingleSummaryFile   = 0x0008,          // One file with summary file format
} SQLDMO_XFRSCRIPTMODE_TYPE;

typedef SQLDMO_HELPID(SQLDMO_DEPENDENCY_TYPE) enum {
        SQLDMODep_Parents = 0,                      // Default:  return all parents of input object
        SQLDMODep_FullHierarchy = 0x10000,          // Return full hierarchy; multiple rows of object and parents/children
        SQLDMODep_OrderDescending = 0x20000,        // Order return in descending order
        SQLDMODep_Children = 0x40000,               // Return children of input object
        SQLDMODep_ReturnInputObject = 0x80000,      // Include input object in the return set
        SQLDMODep_FirstLevelOnly = 0x100000,        // Return only immediate parents/children
        SQLDMODep_DRIOnly = 0x200000,               // Return DRI dependencies only.
        SQLDMODep_IncludeSystem = 0x400000,         // Include system objects
        SQLDMODep_Valid = 0x7f0000                  // All valid options.
} SQLDMO_DEPENDENCY_TYPE;

typedef SQLDMO_HELPID(SQLDMO_OBJSORT_TYPE) enum {
        SQLDMOObjSort_Name = 0,
        SQLDMOObjSort_Type = 1,
        SQLDMOObjSort_Owner = 2,
        SQLDMOObjSort_Date = 3
} SQLDMO_OBJSORT_TYPE;

typedef SQLDMO_HELPID(SQLDMO_SVCSTATUS_TYPE) enum {
        SQLDMOSvc_Unknown = 0,
        SQLDMOSvc_Running = 1,
        SQLDMOSvc_Paused = 2,
        SQLDMOSvc_Stopped = 3,
        SQLDMOSvc_Starting = 4,
        SQLDMOSvc_Stopping = 5,
        SQLDMOSvc_Continuing = 6,
        SQLDMOSvc_Pausing = 7
} SQLDMO_SVCSTATUS_TYPE;

typedef SQLDMO_HELPID(SQLDMO_SRVOPTION_TYPE) enum {
        SQLDMOSrvOpt_Unknown             = 0x0000,
        SQLDMOSrvOpt_RPC                 = 0x0001,   // For both remote and linked server, through sp_serveroption
        SQLDMOSrvOpt_Publisher           = 0x0002,
        SQLDMOSrvOpt_Subscriber          = 0x0004,
        SQLDMOSrvOpt_Distributor         = 0x0008,
        SQLDMOSrvOpt_DistPublisher       = 0x0010,   // Separate from Publisher and Distributor; dpub bit set
//        SQLDMOSrvOpt_ODBCDatasource = 0x0020,   // Server is an ODBC datasource
//        SQLDMOSrvOpt_Valid = 0x0021,            // Only valid to set the RPC and ODBCDataSource options
        // Following are new linked server options
        SQLDMOSrvOpt_RPC_out             = 0x0040,   // Through sp_serveroption
        SQLDMOSrvOpt_DataAccess          = 0x0080,   // Through sp_serveroption
        SQLDMOSrvOpt_CollationCompatible = 0x0100,   // Through sp_serveroption
        SQLDMOSrvOpt_UseRemoteCollation  = 0x0400,   // Through sp_serveroption, new for 8.0 server
        SQLDMOSrvOpt_LazySchemaValid     = 0x0800,   // Through sp_serveroption, new for 8.0 server
        // Changed the following enum values to avoid conflicts between bit settings from sp_serveroption and registry settings
        SQLDMOSrvOpt_NonTransacted       = 0x1000,   // Through registry
        SQLDMOSrvOpt_InProcess           = 0x2000,   // Through registry
        SQLDMOSrvOpt_IndexAsAccessPath   = 0x4000,   // Through registry
        SQLDMOSrvOpt_LevelZeroOnly       = 0x8000,   // Through registry
        SQLDMOSrvOpt_NestedQueries       = 0x10000,  // Through registry
        SQLDMOSrvOpt_DynamicParameters   = 0x20000,  // Through registry
} SQLDMO_SRVOPTION_TYPE;

typedef SQLDMO_HELPID(SQLDMO_TABLEATT_TYPE) enum {
        // Values from sysobjects.category.
        SQLDMOTabAtt_Identity =         0x0001,         // Table has an identity column
        SQLDMOTabAtt_SystemObject =     0x0002,         // Table is a Microsoft system-required object
        SQLDMOTabAtt_ForeignKey =       0x0004,         // Table has a foreign key
        SQLDMOTabAtt_Referenced =       0x0008,         // Table is referenced by another table's foreign key
        SQLDMOTabAtt_Published =        0x0020,         // Table is published
        SQLDMOTabAtt_Replicated =       0x0040,         // Table has an active subscriber
        SQLDMOTabAtt_Check =            0x0080,         // Table has a check constraint
        SQLDMOTabAtt_Replica =          0x0100,         // Table is actively subscribed to a publisher
        SQLDMOTabAtt_PrimaryKey =       0x0200,         // Table has a primary key
        SQLDMOTabAtt_Unique =           0x0400,         // Table has a unique constraint
        SQLDMOTabAtt_Default =          0x0800,         // Table has a DRI default
        SQLDMOTabAtt_ReplCheck =        0x1000,         // Table has a check constraint that excludes replication
        SQLDMOTabAtt_HasConstraint =0x1c84              // Table has at least one DRI constraint
} SQLDMO_TABLEATT_TYPE;

typedef SQLDMO_HELPID(SQLDMO_INTSECLOGIN_TYPE) enum {
        SQLDMOIntSecLogin_Unknown = 0,
        SQLDMOIntSecLogin_Min = 1,
        SQLDMOIntSecLogin_Admin = 1,
        SQLDMOIntSecLogin_User = 2,
        SQLDMOIntSecLogin_Replication = 3,
        SQLDMOIntSecLogin_Max = 3
} SQLDMO_INTSECLOGIN_TYPE;

typedef SQLDMO_HELPID(SQLDMO_VERIFYCONN_TYPE) enum {
        SQLDMOConn_LastState = 0x0001,                  // State of conn at end of last operation.
        SQLDMOConn_CurrentState = 0x0002,               // Actual current state (checks pipe, etc.)
        SQLDMOConn_ReconnectIfDead = 0x0006,    // Reconnect if we've been disconnected (0x0004 | CurrentState)..
        SQLDMOConn_Valid = 0x0007                               // All valid conn operations.
} SQLDMO_VERIFYCONN_TYPE;

typedef SQLDMO_HELPID(SQLDMO_EXEC_TYPE) enum {
        // For ExecuteImmediate, tells how to handle multi-batch commands.
        SQLDMOExec_Default = 0x0000,                    // None of the following
        SQLDMOExec_NoCommandTerm = 0x0001,              // No command-terminator parsing (i.e. don't check for "GO"; exec as single batch)
        SQLDMOExec_ContinueOnError = 0x0002,    // Continue batch on all but broken-connection errors.
        SQLDMOExec_NoExec = 0x0004,                             // SET NOEXEC ON/OFF
        SQLDMOExec_ParseOnly = 0x0008,                   // SET PARSEONLY ON/OFF
        SQLDMOExec_QI_ON = 0x0010               // SET QI ON before execution, special work around for Quoted Identifier, set QI OFF before return
} SQLDMO_EXEC_TYPE;

typedef SQLDMO_HELPID(SQLDMO_CONFIGVALUE_TYPE) enum {
        SQLDMOConfig_RecoveryInterval = 101,
        SQLDMOConfig_AllowUpdates = 102,
        SQLDMOConfig_UserConnections = 103,
        SQLDMOConfig_Locks = 106,
        SQLDMOConfig_OpenObjects = 107,
        SQLDMOConfig_FillFactor = 109,
        SQLDMOConfig_NestedTriggers = 115,
        SQLDMOConfig_RemoteAccess = 117,
        SQLDMOConfig_DefaultLanguage = 124,
        SQLDMOConfig_LanguageInCache = 125,
        SQLDMOConfig_MaxAsyncIO = 502,
        SQLDMOConfig_MaxWorkerThreads = 503,
        SQLDMOConfig_NetworkPacketSize = 505,
        SQLDMOConfig_ShowAdvancedOption = 518,
        SQLDMOConfig_RemoteProcTrans = 542,
        SQLDMOConfig_RemoteConnTimeout = 543,
        SQLDMOConfig_DefaultSortorderId = 1123,
        SQLDMOConfig_PriorityBoost = 1517,
        SQLDMOConfig_RemoteLoginTimeout = 1519,
        SQLDMOConfig_RemoteQueryTimeout = 1520,
        SQLDMOConfig_CursorThreshold = 1531,
        SQLDMOConfig_SetWorkingSetSize = 1532,
        SQLDMOConfig_UserOptions = 1534,
        SQLDMOConfig_ProcessorAffinityMask = 1535,
        SQLDMOConfig_MaxTextReplSize = 1536,
        // New for 7.0
        SQLDMOConfig_UnicodeLocalID = 1124,
        SQLDMOConfig_UnicodeComparisonStyle = 1125,
        SQLDMOConfig_LanguageNeutral = 1126,
        SQLDMOConfig_TwoDigitYearCutoff = 1127,
        SQLDMOConfig_IndexCreateMem = 1505,
        SQLDMOConfig_MediaRetention = 1537,
        SQLDMOConfig_CostThresholdForParallelism = 1538,
        SQLDMOConfig_MaxDegreeOfParallelism = 1539,
        SQLDMOConfig_MimMemoryPerQuery = 1540,
        SQLDMOConfig_QueryWait = 1541,
        SQLDMOConfig_VLMSize = 1542,
        SQLDMOConfig_MinMemory = 1543,
        SQLDMOConfig_MaxMemory = 1544,
        SQLDMOConfig_QueryMaxTime = 1545,
        SQLDMOConfig_LightweightPooling = 1546,
        SQLDMOConfig_ScanStartup = 1547,

/** obsolete in 7.0
        SQLDMOConfig_Memory = 104,
        SQLDMOConfig_OpenDatabases = 105,
        SQLDMOConfig_ProcedureCache = 108,
        SQLDMOConfig_DatabaseSize = 111,
        SQLDMOConfig_MediaRetention = 112,
        SQLDMOConfig_RecoveryFlags = 113,
        SQLDMOConfig_TempdbInRamMB = 501,
        SQLDMOConfig_RAWorkerThreads = 508,
        SQLDMOConfig_BackupThreads = 540,
        SQLDMOConfig_BackupBufferSize = 541,
        SQLDMOConfig_RemoteSites = 1119,
        SQLDMOConfig_RASlotsPerThread = 1509,
        SQLDMOConfig_RAPrefetches = 1510,
        SQLDMOConfig_RADelay = 1511,
        SQLDMOConfig_RACacheMissLimit = 1512,
        SQLDMOConfig_RACacheHitLimit = 1513,
        SQLDMOConfig_LogwriteSleepMS = 1530,
        SQLDMOConfig_SortPages = 1505,
**/

/** obsolete in 8.0
        SQLDMOConfig_TimeSlice = 1110,
        SQLDMOConfig_SpinCounter = 1514,
        SQLDMOConfig_ResourceTimeout = 1533,
**/
} SQLDMO_CONFIGVALUE_TYPE;

typedef SQLDMO_HELPID(SQLDMO_SRVUSERPROFILE_TYPE) enum {
        // Output from Server.GetUserProfile
        SQLDMOSrvUserProf_None = 0x0000,
        SQLDMOSrvUserProf_SaLogin = 0x0001,                                             // User is System Administrator
        SQLDMOSrvUserProf_CreateDatabase = 0x0002,                              // User has privilege to do this
        SQLDMOSrvUserProf_CreateXP = 0x0004,                                    // User can create Extended Stored Procedures

        SQLDMOSrvUserProf_AllProfileBits = 0x0007                               // All server profile bits
} SQLDMO_SRVUSERPROFILE_TYPE;

typedef SQLDMO_HELPID(SQLDMO_DBUSERPROFILE_TYPE) enum {
        // Output from Database.GetUserProfile
        SQLDMODbUserProf_None = 0x0000,
        SQLDMODbUserProf_DboLogin = 0x0001,                                             // User is Database Owner
        SQLDMODbUserProf_CreateTable = 0x0002,                                  // User has these privileges
        SQLDMODbUserProf_CreateView = 0x0004,
        SQLDMODbUserProf_CreateProcedure = 0x0008,
        SQLDMODbUserProf_DumpDatabase = 0x0010,
        SQLDMODbUserProf_CreateDefault = 0x0020,
        SQLDMODbUserProf_DumpTransaction = 0x0040,
        SQLDMODbUserProf_CreateRule = 0x0080,
        SQLDMODbUserProf_DumpTable = 0x0100,
        SQLDMODbUserProf_CreateFunction = 0x0200,

        SQLDMODbUserProf_AllProfileBits = 0x03ff,                               // All DB-valid profile bits

        SQLDMODbUserProf_InvalidLogin = 0x40000000,                             // Current login not a valid user in this database.
        SQLDMODbUserProf_InaccessibleDb = 0x80000000,                   // Database Loading | Recovering | Suspect | Offline
        SQLDMODbUserProf_DbNotAvailable = 0xc0000000                    // All Database-not-accessible bits.
} SQLDMO_DBUSERPROFILE_TYPE;

typedef SQLDMO_HELPID(SQLDMO_OS_TYPE) enum {
        SQLDMO_WIN95 = 1,
        SQLDMO_WINNT = 2
} SQLDMO_OS_TYPE;

typedef SQLDMO_HELPID(SQLDMO_PACKAGE_TYPE) enum {
        SQLDMO_Unknown    = 0,
        SQLDMO_OFFICE     = 1,
        SQLDMO_STANDARD   = 2,
        SQLDMO_ENTERPRISE = 3,
        SQLDMO_MSDE       = 4
} SQLDMO_PACKAGE_TYPE;

// Constant values.
typedef SQLDMO_HELPID(SQLDMO_CONSTANTS_TYPE) enum {
        SQLDMO_NOENDDATE =                              99991231,       // For task dates/times
        SQLDMO_NOENDTIME =                              235959,         // For task dates/times
        SQLDMO_USEEXISTINGFILLFACTOR =  0                       // For Table.RebuildIndexes
} SQLDMO_CONSTANTS_TYPE;

typedef SQLDMO_HELPID(SQLDMO_LOGIN_TYPE) enum {
        SQLDMOLogin_NTUser   = 0,
        SQLDMOLogin_NTGroup  = 1,
        SQLDMOLogin_Standard = 2,
} SQLDMO_LOGIN_TYPE;

typedef SQLDMO_HELPID(SQLDMO_ROLE_TYPE) enum {
        SQLDMORole_Server    = 0x0001,
        SQLDMORole_Database  = 0x0002,
        SQLDMORole_All       = 0x0003,
} SQLDMO_ROLE_TYPE;

typedef SQLDMO_HELPID(SQLDMO_GRANTED_TYPE) enum {
        SQLDMOGranted_GrantGrant   = 204,
        SQLDMOGranted_Grant        = 205,
        SQLDMOGranted_Deny         = 206,
} SQLDMO_GRANTED_TYPE;

typedef SQLDMO_HELPID(SQLDMO_BACKUP_LOG_TYPE) enum {
        SQLDMOBackup_Log_Truncate        = 0,       // Default, truncate the log up to the beginning of the active portion of the log.
        SQLDMOBackup_Log_NoTruncate      = 1,       // Back up the log without truncating it.
        SQLDMOBackup_Log_NoLog           = 2,       // Removes the inactive part of the log without making a backup copy of it and truncates the log
        SQLDMOBackup_Log_TruncateOnly    = 3,       // Truncates the log without making a backup copy if it
        SQLDMOBackup_Log_NoOption        = 4,       // Generate "BACKUP LOG database_name", no optional parameter would be specified
} SQLDMO_BACKUP_LOG_TYPE;

typedef SQLDMO_HELPID(SQLDMO_BACKUP_TYPE) enum {
        SQLDMOBackup_Database      = 0,              // Default
        SQLDMOBackup_Differential  = 1,
        SQLDMOBackup_Files         = 2,
        SQLDMOBackup_Log           = 3,
} SQLDMO_BACKUP_TYPE;

typedef SQLDMO_HELPID(SQLDMO_RESTORE_TYPE) enum {
        SQLDMORestore_Database     = 0,              // Default
        SQLDMORestore_Files        = 1,
        SQLDMORestore_Log          = 2,
} SQLDMO_RESTORE_TYPE;

typedef SQLDMO_HELPID(SQLDMO_DBUSERROLE_TYPE) enum {
        SQLDMORole_db_None              = 0x0000,         // Default
        // Server Role
        SQLDMORole_dbcreator            = 0x0001,
        SQLDMORole_diskadmin            = 0x0002,
        SQLDMORole_processadmin         = 0x0004,
        SQLDMORole_securityadmin        = 0x0008,
        SQLDMORole_serveradmin          = 0x0010,
        SQLDMORole_setupadmin           = 0x0020,
        SQLDMORole_sysadmin             = 0x0040,
        // Database Role
        SQLDMORole_db_accessadmin       = 0x0080,
        SQLDMORole_db_datareader        = 0x0100,
        SQLDMORole_db_ddladmin          = 0x0200,
        SQLDMORole_db_denydatareader    = 0x0400,
        SQLDMORole_db_denydatawriter    = 0x0800,
        SQLDMORole_db_backupoperator    = 0x1000,
        SQLDMORole_db_owner             = 0x2000,
        SQLDMORole_db_securityadmin     = 0x4000,
        SQLDMORole_db_datawriter        = 0x8000,
        // New Server Role
        SQLDMORole_bulkadmin            = 0x10000,

        SQLDMORole_Unknown              = 0xffffffff,         // Unknown
} SQLDMO_DBUSERROLE_TYPE;

typedef SQLDMO_HELPID(SQLDMO_GROWTH_TYPE) enum {
        SQLDMOGrowth_MB       = 0,      // Default for database file
        SQLDMOGrowth_Percent  = 1,      // Default for log file
        SQLDMOGrowth_Invalid  = 99,     // Invalid type, internal use
} SQLDMO_GROWTH_TYPE;

typedef SQLDMO_HELPID(SQLDMO_STAT_SCAN_TYPE) enum {
        SQLDMOStatistic_Sample         = 0,  // Defualt
        SQLDMOStatistic_Percent        = 1,
        SQLDMOStatistic_Rows           = 2,
        SQLDMOStatistic_FullScan       = 3,
} SQLDMO_STAT_SCAN_TYPE;

typedef SQLDMO_HELPID(SQLDMO_STAT_AFFECT_TYPE) enum {
        SQLDMOStatistic_AffectIndex    = 0,    // Default
        SQLDMOStatistic_AffectColumn   = 1,
        SQLDMOStatistic_AffectAll      = 2,
} SQLDMO_STAT_AFFECT_TYPE;

typedef SQLDMO_HELPID(SQLDMO_FULLTEXTSTATUS_TYPE) enum {
        SQLDMOFullText_Idle            = 0,
        SQLDMOFullText_CrawlinProgress = 1,
        SQLDMOFullText_Paused          = 2,
        SQLDMOFullText_Throttled       = 3,
        SQLDMOFullText_Recovering      = 4,
        SQLDMOFullText_Shutdown        = 5,
        SQLDMOFullText_Incremental     = 6,   // This is for 7.0 backward compatibility only, should not be used against post 7.0 server
        SQLDMOFullText_UpdatingIndex   = 7,
        SQLDMOFullText_DiskFullPause   = 8,
        SQLDMOFullText_Notifications   = 9,
} SQLDMO_FULLTEXTSTATUS_TYPE;

typedef SQLDMO_HELPID(SQLDMO_FULLTEXT_START_TYPE) enum {
        SQLDMOFullText_Full            = 0,
        SQLDMOFullText_Inc             = 1,
} SQLDMO_FULLTEXT_START_TYPE;

typedef SQLDMO_HELPID(SQLDMO_LINKEDTABLE_TYPE) enum {
        SQLDMOLinkedTable_Default          = 0,
        SQLDMOLinkedTable_Alias            = 1,
        SQLDMOLinkedTable_GlobalTemporary  = 2,
        SQLDMOLinkedTable_LocalTemporary   = 3,
        SQLDMOLinkedTable_SystemTable      = 4,
        SQLDMOLinkedTable_Table            = 5,
        SQLDMOLinkedTable_View             = 6,
        SQLDMOLinkedTable_SystemView       = 7,
} SQLDMO_LINKEDTABLE_TYPE;

typedef SQLDMO_HELPID(SQLDMO_SQL_VER) enum {
        SQLDMOSQLVer_Unknown          = 0x0000,
        SQLDMOSQLVer_Pre_60           = 0x0001,
        SQLDMOSQLVer_60               = 0x0002,
        SQLDMOSQLVer_65               = 0x0004,
        SQLDMOSQLVer_70               = 0x0008,
        SQLDMOSQLVer_80               = 0x0010,
} SQLDMO_SQL_VER;

typedef SQLDMO_HELPID(SQLDMO_DBCC_REPAIR_TYPE) enum {
        SQLDMORepair_None           = 0,
        SQLDMORepair_Fast           = 1,
        SQLDMORepair_Rebuild        = 2,
        SQLDMORepair_Allow_DataLoss = 3,
} SQLDMO_DBCC_REPAIR_TYPE;

typedef SQLDMO_HELPID(SQLDMO_BCP_CODEPAGE_TYPE) enum {
        SQLDMOBCP_RAW           = -1,        // Use server code page
        SQLDMOBCP_ACP           = 0,         // MS Windows code page of the client
        SQLDMOBCP_OEM           = 1,         // default, use OEM code page of the client
        SQLDMOBCP_User          = 2,         // Caller provide code page
} SQLDMO_BCP_CODEPAGE_TYPE;

typedef SQLDMO_HELPID(SQLDMO_SERVERBCP_DATAFILE_TYPE) enum {
        // Available datafile type for server side BCP.
        SQLDMOBCPDataFile_Char =        0x00000001,     // Using character character data type
        SQLDMOBCPDataFile_Default =     0x00000001,     // Default == using character data type
        SQLDMOBCPDataFile_Native =      0x00000002,     // Using native data type
        SQLDMOBCPDataFile_WideChar =    0x00000004,     // Using unicode data type
        SQLDMOBCPDataFile_WideNative =  0x00000008,     // Same as native, except char, varchar, and text are saved as unicode
} SQLDMO_SERVERBCP_DATAFILE_TYPE;

typedef SQLDMO_HELPID(SQLDMO_COMP_LEVEL_TYPE) enum {
        // Available compatibility level.
        SQLDMOCompLevel_Unknown =  0,      // No idea what level
        SQLDMOCompLevel_60      =  60,
        SQLDMOCompLevel_65      =  65,
        SQLDMOCompLevel_70      =  70,
        SQLDMOCompLevel_80      =  80,     // Default
} SQLDMO_COMP_LEVEL_TYPE;

typedef SQLDMO_HELPID(SQLDMO_SHRINK_TYPE) enum {
        SQLDMOShrink_Default        = 0,       // Default, reallocate data in pages and the files are truncated.
        SQLDMOShrink_NoTruncate     = 1,       // Data in pages is reallocated and the files are not truncated.
        SQLDMOShrink_TruncateOnly   = 2,       // Data in pages is not reallocated.  Files are truncated for any usused space free at the end of any file.
        SQLDMOShrink_EmptyFile      = 3,       // DBFile and LogFile only.  Migrate all data from the specified file to other files in the same filegroup.
} SQLDMO_SHRINK_TYPE;

typedef SQLDMO_HELPID(SQLDMO_NTACCESS_TYPE) enum {
        SQLDMONTAccess_Unknown    = 0,     // This NT login is getting permission via a group.  Permission unknown
        SQLDMONTAccess_Grant      = 1,     // This NT login has grant permission
        SQLDMONTAccess_Deny       = 2,     // This NT login has deny permission
        SQLDMONTAccess_NonNTLogin = 99,    // Not a NT login
} SQLDMO_NTACCESS_TYPE;

typedef SQLDMO_HELPID(SQLDMO_FULLTEXT_POPULATE_TYPE) enum {
        SQLDMOFullText_PopuFull   = 0,     // Start a full population for the table
        SQLDMOFullText_PopuInc    = 1,     // Start an incremental population for the table
        SQLDMOFullText_PopuStop   = 2,     // Stop a full or incremental population
} SQLDMO_FULLTEXT_POPULATE_TYPE;

typedef SQLDMO_HELPID(SQLDMO_FULLTEXT_POPULATE_STATUS) enum {
        SQLDMOFullText_Popu_No   = 0,     // No propagation
        SQLDMOFullText_Popu_Full = 1,     // Full
        SQLDMOFullText_Popu_Inc  = 2,     // Incremental
} SQLDMO_FULLTEXT_POPULATE_STATUS;

typedef SQLDMO_HELPID(SQLDMO_UDF_TYPE) enum {
        SQLDMOUDF_Unknown  = 0,     // Unknown
        SQLDMOUDF_Scalar   = 1,     // Scalar function
        SQLDMOUDF_Table    = 2,     // Table function
        SQLDMOUDF_Inline   = 3,     // Inline function
} SQLDMO_UDF_TYPE;

typedef SQLDMO_HELPID(SQLDMO_RECOVERY_TYPE) enum {
        SQLDMORECOVERY_Simple     = 0,       // Default
        SQLDMORECOVERY_BulkLogged = 1,
        SQLDMORECOVERY_Full       = 2,
        SQLDMORECOVERY_Unknown    = 3,
} SQLDMO_RECOVERY_TYPE;






typedef SQLDMO_HELPID(SQLDMO_SUBSCRIBER_TYPE) enum {
	SQLDMOSubInfo_SQLServer       = 0x00000000,	// Microsoft SQL Server.
	SQLDMOSubInfo_ODBCDatasource  = 0x00000001,	// ODBC Datasource
	SQLDMOSubInfo_JetDatabase     = 0x00000002,	// JET_DATABASE 3.5 using ODBC without DSN
	SQLDMOSubInfo_OLEDBDatasource = 0x00000003,	// OLEDB Datasource, Jet Database 4.0
	SQLDMOSubInfo_ExchangeServer  = 0x00000004	// Exchange server
} SQLDMO_SUBSCRIBER_TYPE;

typedef SQLDMO_HELPID(SQLDMO_INITIALSYNC_TYPE) enum {
	SQLDMOInitSync_Unknown = 10,        // Pick your favourite invalid number
	SQLDMOInitSync_Min = 0,
	SQLDMOInitSync_Default = 0,
	SQLDMOInitSync_BCPNative = 0,       // native mode BCP
	SQLDMOInitSync_BCPChar = 1,         // character mode BCP

    // Post-7.0 additions
    SQLDMOInitSync_Concurrent = 3,      // Concurrent snapshot, native mode
    SQLDMOInitSync_ConcurrentChar = 4,  // Concurrent snapshot, char mode, use with AllowDTS,  because DTS requires that 

	SQLDMOInitSync_Max = 4
} SQLDMO_INITIALSYNC_TYPE;

typedef SQLDMO_HELPID(SQLDMO_REPFREQ_TYPE) enum {
	SQLDMORepFreq_Unknown = 1000,		// Tinyint out-of-range
	SQLDMORepFreq_Min = 0,
	SQLDMORepFreq_Continuous = 0,
	SQLDMORepFreq_Snapshot = 1,
	SQLDMORepFreq_Max = 1
} SQLDMO_REPFREQ_TYPE;

typedef SQLDMO_HELPID(SQLDMO_PUBLICATION_TYPE) enum {
	SQLDMOPublication_Unknown 		= 1000,		// Tinyint out-of-range
	SQLDMOPublication_Min 			= 0,
	SQLDMOPublication_Transactional = 0,
	SQLDMOPublication_Snapshot 		= 1,
	SQLDMOPublication_Merge 		= 2,
	SQLDMOPublication_Max 			= 2
} SQLDMO_PUBLICATION_TYPE;

typedef SQLDMO_HELPID(SQLDMO_ARTICLE_TYPE) enum {
	SQLDMORep_Min 						= 0,
	SQLDMORep_LogBased 					= 0x0001,	// Base for all LogBased replication types.
	SQLDMORep_ManualFilterProc 			= 0x0002,	// Bit for manually created (not auto-generated) filter proc
	SQLDMORep_LogBasedManualFilterProc 	= 0x0003,	// Log based, with manually created filter proc.
	SQLDMORep_ManualSyncView 			= 0x0004,	// Bit for manually created (not auto-generated) sync view.
	SQLDMORep_LogBasedManualSyncView 	= 0x0005,	// Log based, with manually created sync view.
	SQLDMORep_LogBasedVerticalPartition	= 0x0006,	// Log based, with vertical partition.
	SQLDMORep_LogBasedManualBoth 		= 0x0007,	// Log based, with manually created sync view and filter proc.
    SQLDMORep_ProcExecution             = 0x0008,   // stored proc execution
    SQLDMORep_SerializableProcExecution = 0x0018,  	// stored proc exec, must be within serializable xact
	SQLDMORep_TableBased 				= 0x000a,	// Table based article.
    SQLDMORep_ProcSchemaOnly            = 0x0020,   // stored proc, schema only
    SQLDMORep_ViewSchemaOnly            = 0x0040,   // view schema only
    SQLDMORep_FuncSchemaOnly            = 0x0080,   // User-defined function, schema only
    SQLDMORep_IndexedView               = 0x0100,   // This bit indicates that the article is an indexed view
    SQLDMORep_IndexedViewLogBased       = 0x0101,   // Indexed view replicated as a table, log based 
    SQLDMORep_IndexedViewLogBasedManualFilterProc
                                        = 0x0103,   // Indexed view replicated as a table, log based, with manual filter
    SQLDMORep_IndexedViewLogBasedManualSyncView 
                                        = 0x0105,   // Indexed view replicated as a table, log based, with manually created sync view
    SQLDMORep_IndexedViewLogBasedManualBoth 
                                        = 0x0107,   // Indexed view replicated as a table, log based, with manually created sync view and filter proc
    SQLDMORep_IndexedViewSchemaOnly     = 0x0140,   // Schema-bound view, replicate schema only
	SQLDMORep_Max 						= 0x0140
} SQLDMO_ARTICLE_TYPE;

typedef SQLDMO_HELPID(SQLDMO_SUBSYNC_TYPE) enum {
	SQLDMOSubSync_Unknown = 1000,		// Tinyint out-of-range
	SQLDMOSubSync_Manual 	= 0,		// not used in 7.0, for upgrade, this will translate to SQLDMOSubSync_Auto
	SQLDMOSubSync_Min 		= 1,
	SQLDMOSubSync_Auto 		= 1,
	SQLDMOSubSync_Default 	= 1,		// Auto is default.
	SQLDMOSubSync_None 		= 2,
	SQLDMOSubSync_Max 		= 2
} SQLDMO_SUBSYNC_TYPE;

typedef SQLDMO_HELPID(SQLDMO_PREARTICLE_TYPE) enum {
	// Article pre-creation methods on destination table.
	SQLDMOPreArt_Min = 0,
	SQLDMOPreArt_None = 0,				// Do nothing
	SQLDMOPreArt_DropTable = 1,			// Drop and re-create table
	SQLDMOPreArt_DeleteRows = 2,		// Delete rows (logged)
	SQLDMOPreArt_TruncateTable = 3,		// Truncate table (nonlogged)
	SQLDMOPreArt_Max = 3
} SQLDMO_PREARTICLE_TYPE;

typedef SQLDMO_HELPID(SQLDMO_ARTSTATUS_TYPE) enum {
	SQLDMOArtStat_Min 		  = 0,
	SQLDMOArtStat_Inactive 	  = 0,
	SQLDMOArtStat_Unsynced 	  = 1,
	SQLDMOArtStat_Active 	  = 2,
	SQLDMOArtStat_Conflicts   = 3,
	SQLDMOArtStat_Errors 	  = 4,
    SQLDMOArtStat_NewInactive = 5,
    SQLDMOArtStat_NewActive   = 6,
	SQLDMOArtStat_Max 		  = 6
} SQLDMO_ARTSTATUS_TYPE;

typedef SQLDMO_HELPID(SQLDMO_SUBSTATUS_TYPE) enum {
	SQLDMOSubStat_Unknown = 1000,		// Tinyint out-of-range
	SQLDMOSubStat_Default = 1000,		// Use default
	SQLDMOSubStat_Min = 0,
	SQLDMOSubStat_Inactive = 0,
	SQLDMOSubStat_Unsynced = 1,
	SQLDMOSubStat_Active = 2,
	SQLDMOSubStat_Max = 2
} SQLDMO_SUBSTATUS_TYPE;

typedef SQLDMO_HELPID(SQLDMO_PUBSTATUS_TYPE) enum {
	SQLDMOPubStat_Unknown = 1000,		// Tinyint out-of-range
	SQLDMOPubStat_Default = 1000,		// Use default
	SQLDMOPubStat_Min = 0,
	SQLDMOPubStat_Inactive = 0,
	SQLDMOPubStat_Active = 1,
	SQLDMOPubStat_Max = 1
} SQLDMO_PUBSTATUS_TYPE;

typedef SQLDMO_HELPID(SQLDMO_REPLICATION_TYPE) enum {
	SQLDMORepType_Unknown 			= 0x100, 	// Tinyint out-of-range
	SQLDMORepType_Transactional 	= 0x0001, 	// Trans replication
	SQLDMORepType_Merge 			= 0x0002, 	// Merge replication
	SQLDMORepType_TransactionalMerge= 0x0003, 	// Both forms of replication
	SQLDMORepType_Default 			= 0x0001
} SQLDMO_REPLICATION_TYPE;

typedef SQLDMO_HELPID(SQLDMO_RESOLVECONFLICT_TYPE) enum {
	SQLDMOResolveConflict_Unknown = 0x100, 		// Tinyint out-of-range
	SQLDMOResolveConflict_Resubmit = 0x0001, 	// Resubmit conflict table row
	SQLDMOResolveConflict_Discard = 0x0002, 	// Discard conflict table row
	SQLDMOResolveConflict_Default = 0x0001
} SQLDMO_RESOLVECONFLICT_TYPE;

typedef SQLDMO_HELPID(SQLDMO_TRANSUBSCRIBER_TYPE) enum {
	SQLDMOTranSubscriber_Unknown 		= 0x100,	// Tinyint out-of-range
	SQLDMOTranSubscriber_Min 			= 0,
	SQLDMOTranSubscriber_ReadOnly 		= 0, 		// Trans readonly subscriber (default)
	SQLDMOTranSubscriber_Synchronous	= 1,		// Trans synchronous subscriber
	SQLDMOTranSubscriber_Queued         = 2,		// Trans queued subscriber
	SQLDMOTranSubscriber_Failover       = 3,		// Trans synchronous subscriber with capability to fail over to queued subscriber 
	SQLDMOTranSubscriber_Default 		= 0,
	SQLDMOTranSubscriber_Max 			= 3
} SQLDMO_TRANSUBSCRIBER_TYPE;

typedef SQLDMO_HELPID(SQLDMO_MERGESUBSCRIBER_TYPE) enum {
	SQLDMOMergeSubscriber_Unknown 		= 0x100,	// Tinyint out-of-range
	SQLDMOMergeSubscriber_Min 			= 1,
	SQLDMOMergeSubscriber_Global 		= 1,		// Global Merge subscriber
	SQLDMOMergeSubscriber_Local 		= 2, 		// Local Merge subscriber (default)
	SQLDMOMergeSubscriber_Anonymous 	= 3,		// Anonymous Merge subscriber
	SQLDMOMergeSubscriber_Republishing 	= 4,		// Republishing Merge subscriber
	SQLDMOMergeSubscriber_Default 		= 2,
	SQLDMOMergeSubscriber_Max 			= 4
} SQLDMO_MERGESUBSCRIBER_TYPE;

// bit-mask
typedef SQLDMO_HELPID(SQLDMO_REPSCRIPT_TYPE) enum {
	SQLDMORepScript_Default 			    = 0x00000100,	// Default script options
	SQLDMORepScript_NoSubscription		    = 0x00000080,   // Script publication's creation without subscriptions
	SQLDMORepScript_InstallDistributor 	    = 0x00000100,	// Script install of distributor
	SQLDMORepScript_UninstallDistributor    = 0x00000200,	// Script uninstall of distributor
	SQLDMORepScript_InstallPublisher 	    = 0x00000400,	// Script install of publisher
	SQLDMORepScript_UninstallPublisher      = 0x00000800,	// Script uninstall of publisher
	SQLDMORepScript_ToFileOnly 			    = 0x00001000,	// If not set, a string is returned (if file nonnull, both are done)
	SQLDMORepScript_AppendToFile 		    = 0x00002000,	// Append to output file if it already exists.
	SQLDMORepScript_Creation			    = 0x00004000,	// Script the object's creation
	SQLDMORepScript_Deletion			    = 0x00008000,	// Script the object's deletion
	SQLDMORepScript_PublicationCreation	    = 0x00010000,	// Script the object's creation
	SQLDMORepScript_PublicationDeletion	    = 0x00020000,	// Script the object's deletion
	SQLDMORepScript_SubscriptionCreation    = 0x00040000,	// obsolete
	SQLDMORepScript_SubscriptionDeletion    = 0x00080000,	// obsolete
	SQLDMORepScript_PullSubscriptionCreation= 0x00040000,   // Script pull subscription creation
	SQLDMORepScript_PullSubscriptionDeletion= 0x00080000,   // Script pull subscription deletion
	SQLDMORepScript_InstallReplication 	    = 0x00100000,	// Script install of replication
	SQLDMORepScript_UninstallReplication    = 0x00200000,	// Script uninstall of replication
	SQLDMORepScript_ReplicationJobs         = 0x00400000,	// Script replication related jobs

	/* Output control options */
    SQLDMORepScript_AnsiFile 		        = 0x01000000, 	// Generate ANSI output file
    SQLDMORepScript_UnicodeFile 		    = 0x02000000, 	// Generate UNICODE output file
	SQLDMORepScript_EnableReplicationDB	    = 0x04000000,	// Script enabling of replication database
	SQLDMORepScript_DisableReplicationDB    = 0x08000000,	// Script disabling of replication database
	SQLDMORepScript_NoCommandTerm		    = 0x10000000	// Do not add command terminator 
} SQLDMO_REPSCRIPT_TYPE;

// bit-mask
typedef SQLDMO_HELPID(SQLDMO_CREATIONSCRIPT_TYPE) enum {
	SQLDMOCreationScript_DisableScripting 	= 0x00000000,	// Disable the scripting of the object
    SQLDMOCreationScript_PrimaryObject 		= 0x00000001,   // Include object creation
    SQLDMOCreationScript_CustomProcs		= 0x00000002,   // Generates custom stored procedures for the article if defined, trans only
	SQLDMOCreationScript_ClusteredIndexes 	= 0x00000010,	// Include clustered index creation (table only)
	SQLDMOCreationScript_UDDTsToBaseTypes	= 0x00000020,	// Convert UserDefinedDatatypes to base type when creating columns (table only)
	SQLDMOCreationScript_NonClusteredIndexes = 0x00000040,	// Include nonclustered index creation (table only)
	SQLDMOCreationScript_DRI_PrimaryKey 	= 0x00000080, 	// Include DRI on Primary keys
    SQLDMOCreationScript_UserTriggers       = 0x00000100,   // Enable trigger scripting if set (table only) 
    SQLDMOCreationScript_DRI_ForeignKeys    = 0x00000200,   // Include foreign keys (table only)
    SQLDMOCreationScript_DRI_Checks         = 0x00000400,   // Replicate check constraints to the subscriber (table only)     
    SQLDMOCreationScript_DRI_Defaults       = 0x00000800,   // Replicate column defaults to the subscriber (table only)
    SQLDMOCreationScript_Collation          = 0x00001000,   // Replicate column-level collation 
    SQLDMOCreationScript_ExtendedProperties = 0x00002000,   // Replicate extended properties 
    SQLDMOCreationScript_DRI_UniqueKeys     = 0x00004000,   // Replicate unique key 
    SQLDMOCreationScript_PKUKAsConstraints  = 0x00008000    // Replicate primary key and unique keys as constraints instead of indexes.
} SQLDMO_CREATIONSCRIPT_TYPE;

typedef SQLDMO_HELPID(SQLDMO_COMMANDOPTION_TYPE) enum {
    SQLDMOCommandOption_IncludeInsertColumnNames	= 0x00000008,   // Include column names in destination-table INSERT statements
    SQLDMOCommandOption_BinaryParameters			= 0x00000010,	// Send the stored procedure parameters in binary format.
    SQLDMOCommandOption_DTSHorizontalPartition		= 0x00000040	// Users can set up DTS transformation servers to do horizontal partitions and take care of rows moving into or out of a partition 
} SQLDMO_COMMANDOPTION_TYPE;

typedef SQLDMO_HELPID(SQLDMO_SUBSCRIPTION_TYPE) enum {
	SQLDMOSubscription_Unknown = 0x100,		// Tinyint out-of-range
	SQLDMOSubscription_Min = 0,
	SQLDMOSubscription_Push = 0x0000, 		// Push subscription
	SQLDMOSubscription_Pull = 0x0001,		// Pull subscription
	SQLDMOSubscription_Anonymous = 0x0002,	// Anonymous subscription
	SQLDMOSubscription_All = 0x0003, 		// All subscriptions
	SQLDMOSubscription_Default = 0x0000,
	SQLDMOSubscription_Max = 3
} SQLDMO_SUBSCRIPTION_TYPE;

// bit-mask
typedef SQLDMO_HELPID(SQLDMO_PUBATTRIB_TYPE) enum {
	SQLDMOPubAttrib_Unknown 		        = 0x100,	// Tinyint out-of-range
	SQLDMOPubAttrib_Min 			        = 0,
	SQLDMOPubAttrib_AllowPush 		        = 0x0001, 	// Allow Push
	SQLDMOPubAttrib_AllowPull 		        = 0x0002,	// Allow Pull
	SQLDMOPubAttrib_AllowAnonymous 	        = 0x0004,	// Anonymous PubAttrib
	SQLDMOPubAttrib_InternetEnabled         = 0x0008,	// Internet enabled
	SQLDMOPubAttrib_ImmediateSync 	        = 0x0010,	// Immediate Sync
	SQLDMOPubAttrib_IndependentAgent        = 0x0020,	// Independent agent
    SQLDMOPubAttrib_SnapshotInDefaultFolder = 0x0040,   // Keep snapshot copy in default folder
    SQLDMOPubAttrib_CompressSnapshot        = 0x0080,   // Compress snapshot files
    SQLDMOPubAttrib_AllowSubscriptionCopy   = 0x0100,   // Allow copying subscription database and attaching to other subscribers
	SQLDMOPubAttrib_Default 		        = 0x0001,
	SQLDMOPubAttrib_Valid 			        = 0x01ff
} SQLDMO_PUBATTRIB_TYPE;

typedef SQLDMO_HELPID(SQLDMO_TASKSTATUS_TYPE) enum {
    SQLDMOTask_Pending 		= 0,
    SQLDMOTask_Starting 	= 1,
    SQLDMOTask_Succeeded 	= 2,
    SQLDMOTask_Running 		= 3,
    SQLDMOTask_Idle 		= 4,
    SQLDMOTask_Retry 		= 5,
    SQLDMOTask_Failed 		= 6
} SQLDMO_TASKSTATUS_TYPE;

typedef SQLDMO_HELPID(SQLDMO_SESSION_TYPE) enum {
	SQLDMOSession_Unknown 	= 0x100, 	// Tinyint out-of-range
	SQLDMOSession_All		= 0x0001,	
	SQLDMOSession_Errors	= 0x0002	
} SQLDMO_SESSION_TYPE;


typedef SQLDMO_HELPID(SQLDMO_REPLAGENT_TYPE) enum {
	SQLDMOReplAgent_Default			= 0, 	
	SQLDMOReplAgent_Publishers		= -1, 	
	SQLDMOReplAgent_All				= 0, 	
	SQLDMOReplAgent_Snapshot		= 1, 	
	SQLDMOReplAgent_LogReader		= 2, 	
	SQLDMOReplAgent_Distribution	= 3, 	
	SQLDMOReplAgent_Merge			= 4, 	
	SQLDMOReplAgent_Miscellaneous	= 5, 	
	SQLDMOReplAgent_QueueReader		= 9 	
} SQLDMO_REPLAGENT_TYPE;

typedef SQLDMO_HELPID(SQLDMO_REPLSECURITY_TYPE) enum {
    SQLDMOReplSecurity_Min = 0,
    SQLDMOReplSecurity_Normal = 0,
    SQLDMOReplSecurity_Integrated = 1,
    SQLDMOReplSecurity_PredefinedServer = 2,
    SQLDMOReplSecurity_Max = 2
} SQLDMO_REPLSECURITY_TYPE;

typedef SQLDMO_HELPID(SQLDMO_REPLDTSLOC_TYPE) enum {
    SQLDMOReplDTSPackageLocation_Distributor = 0,
    SQLDMOReplDTSPackageLocation_Subscriber = 1
} SQLDMO_REPLDTSLOC_TYPE;

typedef SQLDMO_HELPID(SQLDMO_CONFLICTPOLICY_TYPE) enum {
    SQLDMOConflictPolicy_PublisherWin = 1,
    SQLDMOConflictPolicy_SubscriberWin = 2,
    SQLDMOConflictPolicy_ReinitSubscription = 3
} SQLDMO_CONFLICTPOLICY_TYPE;

typedef SQLDMO_HELPID(SQLDMO_VERIFYSIGNATURE_TYPE) enum {
    SQLDMOVerifySignature_NoVerification = 0,
    SQLDMOVerifySignature_TrustedAuthority = 1
} SQLDMO_VERIFYSIGNATURE_TYPE;

typedef SQLDMO_HELPID(SQLDMO_REPLFAILOVER_TYPE) enum {
    SQLDMOReplFailOver_Immediate = 0,
    SQLDMOReplFailOver_Queued = 1
} SQLDMO_REPLFAILOVER_TYPE;

// bit-mask
typedef SQLDMO_HELPID(SQLDMO_THIRDPARTYOPTION_TYPE) enum {
    SQLDMOThirdPartyOption_Default = 0x0000,            // default, no action
    SQLDMOThirdPartyOption_SuppressDisplay = 0x0001     // Suppress display of publication in Replication folder in SQL Enterprise Manager. Setting this value prevents the publication from showing up in the Replication->Heterogenous Publications folder SEM MMC snap-in.
} SQLDMO_THIRDPARTYOPTION_TYPE;

typedef SQLDMO_HELPID(SQLDMO_REPLQUEUE_TYPE) enum {
    SQLDMOReplQueue_MSMQ = 1,
    SQLDMOReplQueue_SQL = 2
} SQLDMO_REPLQUEUE_TYPE;

typedef SQLDMO_HELPID(SQLDMO_REPLCOMPLEVEL_TYPE) enum {
    SQLDMOReplCompatibilityLevel_70         = 10, // No newer than 7.0 features is used
    SQLDMOReplCompatibilityLevel_70SP1      = 20, // No newer than 7.0 SP1 features is used
    SQLDMOReplCompatibilityLevel_70SP2      = 30, // No newer than 7.0 SP2 features is used
    SQLDMOReplCompatibilityLevel_80         = 40  // No newer than 8.0 features is used
} SQLDMO_REPLCOMPLEVEL_TYPE;

typedef SQLDMO_HELPID(SQLDMO_VALIDATIONOPTION_TYPE) enum {
    SQLDMOValidationOption_70Checksum           = 0, // Do a 7.0 compatible checksum which do not have functionality for vertical partitions, or logical table structures where column offsets differ
    SQLDMOValidationOption_RowCountOnly         = 1, // Do a rowcount check only
    SQLDMOValidationOption_80Checksum           = 2  // Use new 8.0 checksum functionality
} SQLDMO_VALIDATIONOPTION_TYPE;

typedef SQLDMO_HELPID(SQLDMO_VALIDATIONMETHOD_TYPE) enum {
    SQLDMOValidationMethod_FullCount            = 0, // full, does COUNT(*)
    SQLDMOValidationMethod_FastCount            = 1, // fast, uses sysindexes.rows if table (not view)
    SQLDMOValidationMethod_ConditionalFast      = 2  // conditional fast, first tries fast method, but reverts to full if fast method shows differences
} SQLDMO_VALIDATIONMETHOD_TYPE;

typedef SQLDMO_HELPID(SQLDMO_RESYNC_TYPE) enum {
    SQLDMOResync_SinceLastSnapshotApplied       = 0, // resynchronize subscription with all changes since last snapshot was applied
    SQLDMOResync_SinceLastSuccessfulValidation  = 1, // resynchronize subscription with all changes since last successful validation
    SQLDMOResync_SinceAGivenDateTime            = 2  // resynchronize subscription with all changes since a given datetime
} SQLDMO_RESYNC_TYPE;

// bit-mask
typedef SQLDMO_HELPID(SQLDMO_CHECKPERMISSIONS_TYPE) enum {
    SQLDMOCheckPermissions_NoCheck          = 0x00, // No checking permissions
    SQLDMOCheckPermissions_InsertCheck      = 0x01, // Check permissions at Publisher before a Subscriber insert can be uploaded
    SQLDMOCheckPermissions_UpdateCheck      = 0x02, // Check permissions at Publisher before a Subscriber update can be uploaded
    SQLDMOCheckPermissions_DeleteCheck      = 0x04  // Check permissions at Publisher before a Subscriber delete can be uploaded
} SQLDMO_CHECKPERMISSIONS_TYPE;

// Constant values.
typedef SQLDMO_HELPID(SQLDMO_REPLCONSTANTS_TYPE) enum {
		SQLDMO_DEFAULTRETENTION = 14    // Default retention period
} SQLDMO_REPLCONSTANTS_TYPE;



// ***************************************************************************
//               Copyright (C) 1985-1999 Microsoft Corporation.
// @File: agen_itf.h
//
// Purpose: Agent defines and interfaces
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




// May be bitmasked.
typedef SQLDMO_HELPID(SQLDMO_COMPLETION_TYPE) enum {
        SQLDMOComp_Unknown = 0x1000,            // Only bit set
        SQLDMOComp_None = 0x0000,
        SQLDMOComp_Success = 0x0001,
        SQLDMOComp_Failure = 0x0002,
        SQLDMOComp_Always = 0x0003,
        SQLDMOComp_All = 0x0006
} SQLDMO_COMPLETION_TYPE;

typedef SQLDMO_HELPID(SQLDMO_JOBOUTCOME_TYPE) enum {
        SQLDMOJobOutcome_Failed = 0x0,
        SQLDMOJobOutcome_Succeeded = 0x1,
        // NOTE: 0x2 is deliberately ommitted
        SQLDMOJobOutcome_Cancelled = 0x3,
        SQLDMOJobOutcome_InProgress = 0x4,
        SQLDMOJobOutcome_Unknown = 0x5
} SQLDMO_JOBOUTCOME_TYPE;

typedef SQLDMO_HELPID(SQLDMO_EVENT_TYPE) enum {
        SQLDMOEvent_Unknown = 0x0000,
        SQLDMOEvent_Info = 0x0001,
        SQLDMOEvent_Warning = 0x0002,
        SQLDMOEvent_Error = 0x0004,
        SQLDMOEvent_AuditSuccess = 0x0008,
        SQLDMOEvent_AuditFailure = 0x0010,
        SQLDMOEvent_All = 0x001f
} SQLDMO_EVENT_TYPE;

typedef SQLDMO_HELPID(SQLDMO_FREQUENCY_TYPE) enum {                    // SQLDMO Internal:  sync with qsched.h
        SQLDMOFreq_Unknown = 0x0000,
        SQLDMOFreq_OneTime = 0x0001,
//        SQLDMOFreq_OnDemand = 0x0002,                 // Obsolete in 7.0
        SQLDMOFreq_Daily = 0x0004,
        SQLDMOFreq_Weekly = 0x0008,
        SQLDMOFreq_Monthly = 0x0010,
        SQLDMOFreq_MonthlyRelative = 0x0020,
        SQLDMOFreq_Autostart = 0x0040,
        SQLDMOFreq_OnIdle = 0x0080,
        SQLDMOFreq_Valid = 0x00ff                       // All valid frequency types
} SQLDMO_FREQUENCY_TYPE;

typedef SQLDMO_HELPID(SQLDMO_FREQSUB_TYPE) enum {                      // SQLDMO Internal:  sync with qsched.h
        SQLDMOFreqSub_Unknown = 0x0000,
        SQLDMOFreqSub_Once = 0x0001,
        SQLDMOFreqSub_Minute = 0x0004,
        SQLDMOFreqSub_Hour = 0x0008,
        SQLDMOFreqSub_Valid = 0x000d                    // All valid frequency subtypes
} SQLDMO_FREQSUB_TYPE;

typedef SQLDMO_HELPID(SQLDMO_FREQRELATIVE_TYPE) enum {                 // SQLDMO Internal:  sync with qsched.h
        SQLDMOFreqRel_Unknown = 0x0000,
        SQLDMOFreqRel_First = 0x0001,
        SQLDMOFreqRel_Second = 0x0002,
        SQLDMOFreqRel_Third = 0x0004,
        SQLDMOFreqRel_Fourth = 0x0008,
        SQLDMOFreqRel_Last = 0x0010,
        SQLDMOFreqRel_Valid = 0x001f                    // All valid Relative frequencies.
} SQLDMO_FREQRELATIVE_TYPE;

typedef SQLDMO_HELPID(SQLDMO_WEEKDAY_TYPE) enum {                      // SQLDMO Internal:  sync with qsched.h
        // Specify for SQLDMOFreq_Weekly; bitmask
        SQLDMOWeek_Unknown = 0x0000,
        SQLDMOWeek_Sunday = 0x0001,
        SQLDMOWeek_Monday = 0x0002,
        SQLDMOWeek_Tuesday = 0x0004,
        SQLDMOWeek_Wednesday = 0x0008,
        SQLDMOWeek_Thursday = 0x0010,
        SQLDMOWeek_Friday = 0x0020,
        SQLDMOWeek_Saturday = 0x0040,
        SQLDMOWeek_WeekDays = 0x003e,                  // Monday - Friday
        SQLDMOWeek_WeekEnds = 0x0041,                  // Saturday - Sunday
        SQLDMOWeek_EveryDay = 0x007f
} SQLDMO_WEEKDAY_TYPE;

typedef SQLDMO_HELPID(SQLDMO_MONTHDAY_TYPE) enum {                     // SQLDMO Internal:  sync with qsched.h
        // Specify for SQLDMOFreq_MonthlyRelative; single-value.
        // This is the relative interval SQLDMO_FREQRELATIVE_TYPE;
        // e.g., on the xth Monday of the month.
        SQLDMOMonth_Unknown = 0,
        SQLDMOMonth_MinValid = 1,
        SQLDMOMonth_Sunday = 1,
        SQLDMOMonth_Monday = 2,
        SQLDMOMonth_Tuesday = 3,
        SQLDMOMonth_Wednesday = 4,
        SQLDMOMonth_Thursday = 5,
        SQLDMOMonth_Friday = 6,
        SQLDMOMonth_Saturday = 7,
        SQLDMOMonth_Day = 8,                          // xth day
        SQLDMOMonth_WeekDay = 9,                      // xth weekday
        SQLDMOMonth_WeekEndDay = 10,                  // xth weekendday
        SQLDMOMonth_MaxValid = 10
} SQLDMO_MONTHDAY_TYPE;

typedef SQLDMO_HELPID(SQLDMO_RUNPRIORITY_TYPE) enum {
        // These must match the NT ThreadPriority values.
        SQLDMORunPri_Unknown = 100,                   // Invalid ThreadPriority
        SQLDMORunPri_Min = 1,
        SQLDMORunPri_Idle = -15,
        SQLDMORunPri_Lowest = -2,
        SQLDMORunPri_BelowNormal = -1,
        SQLDMORunPri_Normal = 0,
        SQLDMORunPri_AboveNormal = 1,
        SQLDMORunPri_Highest = 2,
        SQLDMORunPri_TimeCritical = 15,
} SQLDMO_RUNPRIORITY_TYPE;

typedef SQLDMO_HELPID(SQLDMO_NOTIFY_TYPE) enum {
        SQLDMONotify_None    = 0x0000,
        SQLDMONotify_Email   = 0x0001,
        SQLDMONotify_Pager   = 0x0002,
        SQLDMONotify_NetSend = 0x0004,
        SQLDMONotify_All     = 0x0007
} SQLDMO_NOTIFY_TYPE;

typedef SQLDMO_HELPID(SQLDMO_ENUMNOTIFY_TYPE) enum {
        SQLDMOEnumNotify_Min = 1,
        SQLDMOEnumNotify_All = 1,                     // All operators/alerts
        SQLDMOEnumNotify_Actual = 2,                  // Only operators/alerts receiving notifications for this alert/operator
        SQLDMOEnumNotify_Target = 3,                  // Specifically named target alert/operator(s)
        SQLDMOEnumNotify_Max = 3
} SQLDMO_ENUMNOTIFY_TYPE;

typedef SQLDMO_HELPID(SQLDMO_JOBEXECUTION_STATUS) enum {
        SQLDMOJobExecution_Unknown                = 0,
        SQLDMOJobExecution_Executing              = 1,
        SQLDMOJobExecution_WaitingForWorkerThread = 2,
        SQLDMOJobExecution_BetweenRetries         = 3,
        SQLDMOJobExecution_Idle                   = 4,
        SQLDMOJobExecution_Suspended              = 5,
        SQLDMOJobExecution_WaitingForStepToFinish = 6,
        SQLDMOJobExecution_PerformingCompletionActions = 7
} SQLDMO_JOBEXECUTION_STATUS;

typedef SQLDMO_HELPID(SQLDMO_FIND_OPERAND) enum {
        SQLDMOFindOperand_Unknown                 = 0,
        SQLDMOFindOperand_EqualTo                 = 1,
        SQLDMOFindOperand_GreaterThan             = 2,
        SQLDMOFindOperand_LessThan                = 3,
} SQLDMO_FIND_OPERAND;

typedef SQLDMO_HELPID(SQLDMO_JOBSTEPACTION_TYPE) enum {
        SQLDMOJobStepAction_Unknown               = 0,
        SQLDMOJobStepAction_QuitWithSuccess       = 1,
        SQLDMOJobStepAction_QuitWithFailure       = 2,
        SQLDMOJobStepAction_GotoNextStep          = 3,
        SQLDMOJobStepAction_GotoStep              = 4
} SQLDMO_JOBSTEPACTION_TYPE;

typedef SQLDMO_HELPID(SQLDMO_CATEGORYTYPE_TYPE) enum {
        SQLDMOCategoryType_Unknown               = 0,
        SQLDMOCategoryType_LocalJob              = 1,
        SQLDMOCategoryType_MultiServerJob        = 2,
        SQLDMOCategoryType_None                  = 3
} SQLDMO_CATEGORYTYPE_TYPE;

typedef SQLDMO_HELPID(SQLDMO_TARGETSERVERSTATUS_TYPE) enum {
        SQLDMOTargetServerStatus_Unknown           = 0x00,
        SQLDMOTargetServerStatus_Normal            = 0x01,
        SQLDMOTargetServerStatus_SuspectedOffline  = 0x02,
        SQLDMOTargetServerStatus_Blocked           = 0x04,
} SQLDMO_TARGETSERVERSTATUS_TYPE;

typedef SQLDMO_HELPID(SQLDMO_JOB_TYPE) enum {
        SQLDMOJob_Unknown               = 0,
        SQLDMOJob_Local                 = 1,
        SQLDMOJob_MultiServer           = 2
} SQLDMO_JOB_TYPE;

typedef SQLDMO_HELPID(SQLDMO_JOBSERVER_TYPE) enum {
        SQLDMOJobServer_StandAlone = 1,
		  SQLDMOJobServer_TSX        = 2,
		  SQLDMOJobServer_MSX        = 3,
		  SQLDMOJobServer_Unknown    = 0
} SQLDMO_JOBSERVER_TYPE;

typedef SQLDMO_HELPID(SQLDMO_ALERT_TYPE) enum {
        SQLDMOAlert_SQLServerEvent                 = 0x1,
		  SQLDMOAlert_SQLServerPerformanceCondition  = 0x2,
		  SQLDMOAlert_NonSQLServerEvent              = 0x3
} SQLDMO_ALERT_TYPE;







// ***************************************************************************
//               Copyright (C) 1985-1999 Microsoft Corporation.
// @File: errid.h
//
// Purpose: Error IDs
//
//
// Notes:
//
// History:
//
//   @Version: Shiloh
//   61657 WG   05/17/00 Wrong message
//   60604 px   05/02/00 To get more errors from server
//   56016 WG   02/29/00 Encrypted SP
//   54429 WG   02/11/00 New error message for restore object
//   53293 RAM  02/03/00 Dynamic Snapshot Application UI support
//   50172 RAM  01/09/00 Dynamic snapshot UI integration
//   49936 px   12/16/99 Add DMO publish in Active Directory support
//   49775 px   12/14/99 Do not allow adding regsub to SQL DistPublisher
//   49253 WG   12/07/99 CTS tracking
//
//
// @EndHeader@
// ***************************************************************************



// SQLDMO Error enumeration.

typedef SQLDMO_HELPID(SQLDMO_ERROR_TYPE) enum {
        // Error values.  (MS-Internal:  See usa.rc for the string representation of these (OSQL_S_*)).
        // DBLib uses 10000 (0x2710) to 10200 (0x27D8).
        SQLDMO_E_DBLIBFIRSTERROR = 0x2710,
        SQLDMO_E_DBLIBLASTERROR = 0x27D8,

        // SQL Server itself sends errors back which may be up to 20000 (0x4E20).
        // SQLDMO-detected errors are in the range SQLDMO_E_FIRSTERROR to SQLDMO_E_LASTERROR.
        // Each SQLDMO_ECAT (Error CATegory) summarizes its specific errorcodes.
        SQLDMO_E_FIRSTERROR = 0x5000,

// All error categories masked off by this.
SQLDMO_ECAT_MASK = 0x5F00,

// Errors indicating an operation that is valid but not in the given context.
SQLDMO_ECAT_INVALIDCONTEXT = 0x5000,
        SQLDMO_E_ALREADYCONN = 0x5000,
        SQLDMO_E_ALREADYCOLL = 0x5001,
        SQLDMO_E_NOTCONN = 0x5002,
        SQLDMO_E_CANTDROPSERVER = 0x5003,
        SQLDMO_E_NOCOMPLEXALTER = 0x5004,
        SQLDMO_E_PROPNEEDSCREATE = 0x5005,
        SQLDMO_E_COLTYPEFIXED = 0x5006,
        SQLDMO_E_COLTYPENONNULL = 0x5007,
        SQLDMO_E_CANTCHANGEUDDT = 0x5008,
        SQLDMO_E_BASETYPEFIXED = 0x5009,
        SQLDMO_E_BASETYPENONNULL = 0x500A,
        SQLDMO_E_ENUMORDINAL = 0x500B,
        SQLDMO_E_CANTRENAMEUSER = 0x500C,
        SQLDMO_E_CANTRENAMEGROUP = 0x500D,
        SQLDMO_E_CANTRENAMELOGIN = 0x500E,
        SQLDMO_E_CANTRENAMEDEVICE = 0x500F,
        SQLDMO_E_NOTDUMPPROP = 0x5010,
        SQLDMO_E_NOSERVERASSOC = 0x5011,
        SQLDMO_E_NOTCOLLTYPE = 0x5012,
        SQLDMO_E_CANTMODIFYDRIINDEX = 0x5013,
        SQLDMO_E_CANTCHANGEPROCTYPE = 0x5014,
        SQLDMO_E_CANTMODIFYINDEX = 0x5015,
        SQLDMO_E_INVALIDPRIVOBJ = 0x5016,
        SQLDMO_E_CANTCHANGETRIGTYPE = 0x5017,
        SQLDMO_E_NOVIEWCOLALTER = 0x5018,
        SQLDMO_E_CANTRENAMELANGUAGE = 0x5019,
        SQLDMO_E_CANTRENAMERSERVER = 0x501A,
        SQLDMO_E_CANTRENAMERLOGIN = 0x501B,
        SQLDMO_E_MUSTBEDBDEV = 0x501C,
        SQLDMO_E_NOINACTIVEMIRROR = 0x501D,
        SQLDMO_E_NOACTIVEMIRROR = 0x501E,
        SQLDMO_E_NOMIRROR = 0x501F,
        SQLDMO_E_SERVERDISCONNECTED = 0x5020,
        SQLDMO_E_CANTRENAMESERVER = 0x5021,
        SQLDMO_E_CANTMODIFYTEXT = 0x5022,
        SQLDMO_E_CANTMODIFYSYSTABLE = 0x5023,
        SQLDMO_E_LOGINALREADYALIASED = 0x5024,
        SQLDMO_E_LOGINALREADYUSER = 0x5025,
        SQLDMO_E_CACHENORESULTS = 0x5026,
        SQLDMO_E_ALREADYCREATED = 0x5027,
        SQLDMO_E_NOTDISCONN = 0x5028,
        SQLDMO_E_CANTMODIFYARTTABLE = 0x5029,
        SQLDMO_E_PROPERTYCANNOTBEMODIFIED = 0x502A,
        SQLDMO_E_BASETYPENOTNUMERIC = 0x502B,
        SQLDMO_E_TOFILEBUTNOFILENAME = 0x502C,
        SQLDMO_E_CANTMODIFYKEY = 0x502E,
        SQLDMO_E_LISTCANTREFRESH = 0x502F,
        SQLDMO_E_NOCOLTABLE = 0x5030,
        SQLDMO_E_MUSTBEINALTER = 0x5031,
        SQLDMO_E_CANTUNDEDICATELOGDEVICE = 0x5032,
        SQLDMO_E_CANTRENAMESERVERGROUP = 0x5033,
        SQLDMO_E_CANTRENAMEREGISTEREDSERVER = 0x5034,
        SQLDMO_E_INDEXREBUILDKEYTYPE = 0x5035,
        SQLDMO_E_REBUILDINDEXOPTIONS = 0x5036,
        SQLDMO_E_IMPERSONATEXPONLY = 0x5037,
        SQLDMO_E_CANTRENAMEPUBLICATION = 0x5038,
        SQLDMO_E_CANTMODIFYSPARTTYPE = 0x5039,
		SQLDMO_E_INVALIDDISTDB = 0x503a,
        SQLDMO_E_CANTMODIFYTABLE = 0x503B,
        SQLDMO_E_CANTDROPFILEGROUP = 0x503C,
        SQLDMO_E_DEFAULTFILEGROUP = 0x503D,
        SQLDMO_E_NOTDEFAULTFILEGROUP = 0x503E,
        SQLDMO_E_CANTRESETLOGINTYPE = 0x503F,
        SQLDMO_E_CANTRESETPASSWORD = 0x5040,
        SQLDMO_E_PRESQL70          = 0x5041,
        SQLDMO_E_PROPBEFORECREATE  = 0x5042,
        SQLDMO_E_CANTRENAMEROLE = 0x5043,
        SQLDMO_E_CANTDROPFIXEDROLE = 0x5044,
        SQLDMO_E_CANTADDTOAPPROLE = 0x5045,
        SQLDMO_E_CANTGETROLE = 0x5046,
        SQLDMO_E_USERDBROLE = 0x5047,
        SQLDMO_E_FIXEDDBROLE = 0x5048,
        SQLDMO_E_CANTMODIFYFILTER = 0x5049,
        SQLDMO_E_INVALIDACTION = 0x504a,
        SQLDMO_E_DBOPTION = 0x504b,
        SQLDMO_E_USEALTER = 0x504c,
        SQLDMO_E_CREATEDBPERM = 0x504d,
        SQLDMO_E_CANTCHECKFK = 0x504e,
        SQLDMO_E_NOTINMB = 0x504f,
        SQLDMO_E_CANTRENAMELSERVER = 0x5050,
        SQLDMO_E_CANTRENAMELLOGIN = 0x5051,
        SQLDMO_E_CANTRENAMEFULLTEXT = 0x5052,
        SQLDMO_E_NOFULLTEXT = 0x5053,
        SQLDMO_E_ACTIVATEFULLTEXT = 0x5054,
        SQLDMO_E_NOTFULLTEXTENABLED = 0x5055,
        SQLDMO_E_CANTDROPLOGFILE = 0x5056,
        SQLDMO_E_CANTDROPLSLOGIN = 0x5057,
        SQLDMO_E_SCRIPTPWD = 0x5058,
        SQLDMO_E_DISTRIBUTORNOTINSTALLED = 0x5059,
        SQLDMO_E_CANTRENAMESTAT = 0x505a,
        SQLDMO_E_CANTDROPAUTOINDEX = 0x505b,
        SQLDMO_E_FROMGUEST = 0x505c,
        SQLDMO_E_INVALIDPROPDISTNOTLOCAL = 0x5060,
        SQLDMO_E_INVALIDREMOVE = 0x5061,
        SQLDMO_E_CANTRENAMEPRIMARY = 0x5062,
        SQLDMO_E_CANTMODIFYNONTABLEARTTYPE = 0x5064,
        SQLDMO_E_CANTMODIFYARTTYPE = 0x5065,
        SQLDMO_E_REGERROR = 0x5066,
        SQLDMO_E_NOCOLUMNALTER = 0x5067,
        SQLDMO_E_INVALIDRESTORE = 0x5068,
        SQLDMO_E_NONTRANSFERENCRYPTED = 0x5069,
        SQLDMO_E_UDFSCRIPTERR = 0x506a,

// Errors indicating that the OLE object is not (or is no longer) valid in SQLDMO.
SQLDMO_ECAT_INVALIDOBJECT = 0x5100,
        SQLDMO_E_OBJECTDROPPED = 0x5100,
        SQLDMO_E_NOTSQLDMOOBJECT = 0x5101,
        SQLDMO_E_OBJECTDETACHED = 0x5102,
        SQLDMO_E_SERVERCLOSED = 0x5103,
        SQLDMO_E_PRESQL75     = 0x5104,
        SQLDMO_E_CANTRENAMEUDF = 0x5105,
        SQLDMO_E_PRESQL80     = 0x5106,

// Errors indicating that an attempt was made to create an object (usually to add an object
// to a collection) but that its definition (property settings) were incomplete or inconsistent.
SQLDMO_ECAT_INVALIDOBJECTDEFINITION = 0x5200,
        SQLDMO_E_NOCOLUMNSADDED = 0x5200,
        SQLDMO_E_COLUMNINCOMPLETE = 0x5201,
        SQLDMO_E_TABLEINCOMPLETE = 0x5202,
        SQLDMO_E_UDDTINCOMPLETE = 0x5203,
        SQLDMO_E_RULEINCOMPLETE = 0x5204,
        SQLDMO_E_DEFAULTINCOMPLETE = 0x5205,
        SQLDMO_E_VIEWINCOMPLETE = 0x5206,
        SQLDMO_E_USERINCOMPLETE = 0x5207,
        SQLDMO_E_GROUPINCOMPLETE = 0x5208,
        SQLDMO_E_PROCINCOMPLETE = 0x5209,
        SQLDMO_E_USERALREADYEXISTS = 0x520A,
        SQLDMO_E_GROUPALREADYEXISTS = 0x520B,
        SQLDMO_E_COLUMNALREADYEXISTS = 0x520C,
        SQLDMO_E_OBJECTALREADYEXISTS = 0x520D,
        SQLDMO_E_INDEXALREADYEXISTS = 0x520E,
        SQLDMO_E_DBALREADYEXISTS = 0x520F,
        SQLDMO_E_LOGINALREADYEXISTS = 0x5210,
        SQLDMO_E_DEVICEALREADYEXISTS = 0x5211,
        SQLDMO_E_SKIPONLYTAPE = 0x5212,
        SQLDMO_E_DEVICEINCOMPLETE = 0x5213,
        SQLDMO_E_PROCALREADYEXISTS = 0x5214,
        SQLDMO_E_UDDTALREADYEXISTS = 0x5215,
        SQLDMO_E_TABLEALREADYEXISTS = 0x5216,
        SQLDMO_E_RULEALREADYEXISTS = 0x5217,
        SQLDMO_E_DEFAULTALREADYEXISTS = 0x5218,
        SQLDMO_E_VIEWALREADYEXISTS = 0x5219,
        SQLDMO_E_INDEXINCOMPLETE = 0x521A,
        SQLDMO_E_TRIGINCOMPLETE = 0x521B,
        SQLDMO_E_TRIGALREADYEXISTS = 0x521C,
        SQLDMO_E_LANGUAGEINCOMPLETE = 0x521D,
        SQLDMO_E_LANGUAGEALREADYEXISTS = 0x521E,
        SQLDMO_E_LOGININCOMPLETE = 0x521F,
        SQLDMO_E_RSERVERINCOMPLETE = 0x5220,
        SQLDMO_E_RSERVERALREADYEXISTS = 0x5221,
        SQLDMO_E_NULLRLOGINALREADYEXISTS = 0x5222,
        SQLDMO_E_RLOGINALREADYEXISTS = 0x5223,
        SQLDMO_E_REMOTENEEDSLOCAL = 0x5224,
        SQLDMO_E_BACKUPNEEDSDEVICE = 0x5225,
        SQLDMO_E_NEEDMANUALFILTERNAME = 0x5226,
        SQLDMO_E_TASKINCOMPLETE = 0x5227,
        SQLDMO_E_ARTINCOMPLETE = 0x5228,
        SQLDMO_E_PUBINCOMPLETE = 0x5229,
        SQLDMO_E_SUBINCOMPLETE = 0x522A,
        SQLDMO_E_ALERTINCOMPLETE = 0x522B,
        SQLDMO_E_OPERATORINCOMPLETE = 0x522C,
        SQLDMO_E_NAMEMUSTMATCH = 0x522D,
        SQLDMO_E_TRIGREQTABLENAME = 0x522E,
        SQLDMO_E_MUSTBESYNCTASK = 0x522F,
        SQLDMO_E_NOEVENTCOMPLETION = 0x5230,
        SQLDMO_E_FKEYINCOMPLETE = 0x5231,
        SQLDMO_E_KEYINCOMPLETE = 0x5232,
        SQLDMO_E_KEYALREADYEXISTS = 0x5233,
        SQLDMO_E_CHECKINCOMPLETE = 0x5234,
        SQLDMO_E_DRIDEFAULTINCOMPLETE = 0x5235,
        SQLDMO_E_CHECKALREADYEXISTS = 0x5236,
        SQLDMO_E_ONLYONEPRIMARYKEY = 0x5237,
        SQLDMO_E_NEEDMANUALVIEWNAME = 0x5238,
        SQLDMO_E_SERVERGROUPINCOMPLETE = 0x5239,
        SQLDMO_E_REGISTEREDSERVERINCOMPLETE = 0x523A,
        SQLDMO_E_SERVERGROUPALREADYEXISTS = 0x523B,
        SQLDMO_E_REGISTEREDSERVERALREADYEXISTS = 0x523C,
        SQLDMO_E_NEEDLOADTABLENAME = 0x523D,
        SQLDMO_E_DISTDBALREADYEXISTS = 0x523E,
        SQLDMO_E_DISTPUBALREADYEXISTS = 0x523F,
        SQLDMO_E_JOBSTEPINCOMPLETE = 0x5240,
        SQLDMO_E_TARGETSERVERINCOMPLETE = 0x5241,
        SQLDMO_E_TARGETSERVERGROUPINCOMPLETE = 0x5242,
        SQLDMO_E_JOBINCOMPLETE = 0x5243,
        SQLDMO_E_MUSTBESYNCJOB = 0x5244,
        SQLDMO_E_JOBCATEGORYINCOMPLETE = 0x5245,
        SQLDMO_E_REGPUBINCOMPLETE = 0x5246,
        SQLDMO_E_REGSUBINCOMPLETE = 0x5247,
        SQLDMO_E_DISTPUBINCOMPLETE = 0x5248,
        SQLDMO_E_DISTDBINCOMPLETE = 0x5249,
        SQLDMO_E_FILEGROUPINCOMPLETE = 0x524A,
        SQLDMO_E_DBFILEINCOMPLETE = 0x524B,
        SQLDMO_E_LOGFILEINCOMPLETE = 0x524C,
        SQLDMO_E_FILEGROUPALREADYEXISTS = 0x524D,
        SQLDMO_E_DATABASEINCOMPLETE = 0x5250,
        SQLDMO_E_DATABASEROLEALREADYEXISTS = 0x5251,
        SQLDMO_E_DATABASEROLEINCOMPLETE = 0x5252,
        SQLDMO_E_SERVERROLEINCOMPLETE = 0x5253,
        SQLDMO_E_DSNINFOINCOMPLETE = 0x5254,
        SQLDMO_E_FILTERINCOMPLETE = 0x5255,
        SQLDMO_E_OWNERMUSTMATCH = 0x5256,
        SQLDMO_E_BACKUPNEEDSFILE = 0x5257,
        SQLDMO_E_BACKUPNEEDSMEDIA = 0x5258,
        SQLDMO_E_COLUMNCOMPUTEDINCOMPLETE = 0x5259,
        SQLDMO_E_REMAPFILEINCOMPLETE = 0x525A,
        SQLDMO_E_SMALLMAXSIZE = 0x525B,
        SQLDMO_E_FILEALREADYEXISTS = 0x525C,
        SQLDMO_E_BADFILEGROUPNAME = 0x525D,
        SQLDMO_E_LINKEDSERVERINCOMPLETE = 0x525E,
        SQLDMO_E_LINKEDPROVIDERINCOMPLETE = 0x525F,
        SQLDMO_E_FULLTEXTINCOMPLETE = 0x5260,
        SQLDMO_E_CATALOGALREADYEXISTS = 0x5261,
        SQLDMO_E_CATALOGINCOMPLETE = 0x5262,
        SQLDMO_E_BACKUPINIT = 0x5263,
        SQLDMO_E_LINKEDSERVERLOGININCOMPLETE = 0x5264,
        SQLDMO_E_NOSERVERBCP6 = 0x5265,
        SQLDMO_E_JOBSTEPNAMEINCOMPLETE = 0x5266,
        SQLDMO_E_MDFINCOMPLETE = 0x5267,
        SQLDMO_E_UDFINCOMPLETE = 0x5268,
        SQLDMO_E_FULLTEXTCOLUMNINCOMPLETE = 0x5269,
        SQLDMO_E_CANTADDREGSUBTOSQLDISTPUBSHR = 0x5270,
        SQLDMO_E_SNAPSHOTPUBCANNOTPUBWIN = 0x5271,
        SQLDMO_E_DYNAMICSNAPSHOTJOBINCOMPLETE = 0x5272,

// Errors indicating an invalid parameter passed to a method or property, or other unexpected condition.
SQLDMO_ECAT_INVALIDPARAMETER = 0x5300,
        SQLDMO_E_BADCOLLEN = 0x5300,
        SQLDMO_E_INVALIDPERFMONSET = 0x5301,
        SQLDMO_E_BADDEVICETYPE = 0x5302,
        SQLDMO_E_SIZEGREATERTHAN0 = 0x5303,
        SQLDMO_E_RESULTSETOUTOFRANGE = 0x5304,
        SQLDMO_E_OUTPUTPARAMREQUIRED = 0x5305,
        SQLDMO_E_PROPTEXTNONNULL = 0x5306,
        SQLDMO_E_BADPROCTYPE = 0x5307,
        SQLDMO_E_BADFILLFACTOR = 0x5308,
        SQLDMO_E_INVALIDINDEXTYPE = 0x5309,
        SQLDMO_E_INVALIDPRIVTYPE = 0x530A,
        SQLDMO_E_BADTRIGTYPE = 0x530B,
        SQLDMO_E_INVALIDDAYOFWEEK = 0x530C,
        SQLDMO_E_INVALIDMONTH = 0x530D,
        SQLDMO_E_BADDAYCOUNT = 0x530E,
        SQLDMO_E_BADMONTHCOUNT = 0x530F,
        SQLDMO_E_BADCONFIGVALUE = 0x5310,
        SQLDMO_E_INVALIDPARAMINDEX = 0x5311,
        SQLDMO_E_INVALIDPARAMRANGE = 0x5312,
        SQLDMO_E_INVALIDDBOBJTYPE = 0x5313,
        SQLDMO_E_ROWCOLOUTOFRANGE = 0x5314,
        SQLDMO_E_NONUNIQUENAME = 0x5315,
        SQLDMO_E_NOTIMESTAMPUDDT = 0x5316,
        SQLDMO_E_INVALIDNAME = 0x5317,
        SQLDMO_E_INVALIDCOMPLETION = 0x5318,
        SQLDMO_E_NAMETOOLONG = 0x5319,
        SQLDMO_E_INVALIDFREQTYPE = 0x531A,
        SQLDMO_E_INVALIDFREQSUBDAY = 0x531B,
        SQLDMO_E_INVALIDFREQRELINTERVAL = 0x531C,
        SQLDMO_E_BADWEEKLYINTERVAL = 0x531D,
        SQLDMO_E_BADMONTHLYINTERVAL = 0x531E,
        SQLDMO_E_BADMONTHLYRELINTERVAL = 0x531F,
        SQLDMO_E_INVALIDSRVOPTION = 0x5320,
        SQLDMO_E_INVALIDRUNPRIORITY = 0x5321,
        SQLDMO_E_DBNAMEREQUIRED = 0x5322,
        SQLDMO_E_PUBNAMEREQUIRED = 0x5323,
        SQLDMO_E_PROPINDEXOUTOFRANGE = 0x5324,
        SQLDMO_E_INVALIDNOTIFYTYPE = 0x5325,
        SQLDMO_E_INVALIDENUMNOTIFYTYPE = 0x5326,
        SQLDMO_E_INVALIDWEEKDAY = 0x5327,
        SQLDMO_E_INVALIDOBJECTTYPE = 0x5328,
        SQLDMO_E_OBJECTREQUIRED = 0x5329,
        SQLDMO_E_INVALIDEVENTTYPE = 0x532A,
        SQLDMO_E_INVALIDCOMPLETIONTYPE = 0x532B,
        SQLDMO_E_INVALIDKEYTYPE = 0x532C,
        SQLDMO_E_TABLEMUSTBECREATED = 0x532D,
        SQLDMO_E_INVALIDPREARTICLE = 0x532E,
        SQLDMO_E_INVALIDSECURITYMODE = 0x532F,
        SQLDMO_E_INVALIDPREC = 0x5330,
        SQLDMO_E_INVALIDDEPENDENCYTYPE = 0x5331,
        SQLDMO_E_INVALIDVERIFYCONNTYPE = 0x5332,
        SQLDMO_E_INVALIDSTATUSINFOTYPE = 0x5333,
        SQLDMO_E_INVALIDFORWARDINGSEVERITY = 0x5334,
        SQLDMO_E_INVALIDFORWARDINGSERVER = 0x5335,
        SQLDMO_E_INVALIDRESTARTINTERVAL = 0x5336,
        SQLDMO_E_INVALIDHISTORYROWSMAX = 0x5337,
        SQLDMO_E_NAMETOOSHORT = 0x5338,
        SQLDMO_E_UNEXPECTED = 0x5339,
        SQLDMO_E_INVALIDHISTORYROWSPERTASKMAX = 0x533A,
        SQLDMO_E_INVALIDOBJSORTTYPE = 0x533B,
        SQLDMO_E_INVALIDEXECTYPE = 0x533C,
        SQLDMO_E_INVALIDSUBSETFILTER = 0x533D,
        SQLDMO_E_INCOMPATIBLEPROPS = 0x533E,    //Some of the bcp object properties are incompatible.
        SQLDMO_E_FILEPATHREQUIRED = 0x533F,             //User should specify path for script file
        SQLDMO_E_INVALIDPROPALTER = 0x5340,             //The given property cannot be altered outside Alter block
        SQLDMO_E_INVALIDALTERDISTINSTALLED = 0x5341,//The given property must not be altered
        SQLDMO_E_SERVERNAMEREQUIRED = 0x5342,   //The server name must be provided
        SQLDMO_E_DISTSERVERNAMEREQUIRED = 0x5343,//The distribution server name must be provided
        SQLDMO_E_WORKINGDIRREQUIRED = 0x5344,   //The distribution server name must be provided
        SQLDMO_E_DISTDBREQUIRED = 0x5345,               //Atleast one distributor database must be provided
        SQLDMO_E_INVALIDHISTORYROWSPERJOBMAX = 0x5348,
        SQLDMO_E_INVALIDPUBATTRIB = 0x5349,
        SQLDMO_E_INVALIDREPLICATIONTYPE = 0x534A,
        SQLDMO_E_INVALIDSCHEMAOPTION = 0x534B,
		  SQLDMO_E_INVALIDFORREMDISTRIBUTOR = 0x534C,
        SQLDMO_E_INVALIDARTICLETYPE = 0x534D,
        SQLDMO_E_SIZEGREATERTHANNEG = 0x534E,
        SQLDMO_E_INVALIDLOGINTYPE = 0x534F,
        SQLDMO_E_CANTMODIFYAFTERCREATE = 0x5350,
        SQLDMO_E_INVALIDDSN = 0x5351,
        SQLDMO_E_INVALIDNAME70 = 0x5352,
        SQLDMO_E_MUSTEVEN = 0x5353,
        SQLDMO_E_MISSINGALTER = 0x5354,
        SQLDMO_E_NOTGUID = 0x5355,
        SQLDMO_E_DESTSERVERREQUIRED = 0x5356,   //The dest server name must be provided for transfer
        SQLDMO_E_CANTSHRINK = 0x5357,
        SQLDMO_E_CANTDEFAULTOFF = 0x5358,
        SQLDMO_E_INVALIDNTNAME = 0x5359,        // Name contain illegal character for NT file name
        SQLDMO_E_INVALIDOUTCOMETYPE = 0x535A,
        SQLDMO_E_NEEDSCOLUMNNAME = 0x535B,
        SQLDMO_E_INVALIDHYPOINDEXTYPE = 0x535C,
        SQLDMO_E_INVALIDPING = 0x535D,
        SQLDMO_E_USEFTPORALTSNAPSHOTFOLDER = 0x535E,
        SQLDMO_E_INTERNETENABLEDORALTFOLDER = 0x535F,
        SQLDMO_E_NOTSQLVARIANT = 0x5361,
        SQLDMO_E_CANTCONVERTVARIANT = 0x5362,
        SQLDMO_E_USEFTPORDYNAMICSNAPSHOT = 0x5363,
        SQLDMO_E_ALTSNAPSHOTFOLDERORDYNSNAP = 0x5364,

// Errors indicating that either the connected SQL Server is an invalid version,
// or the client platform is invalid, or a combination of those; or that the
// server has not been set up properly for SQLDMO (the required stored procedures
// are not installed)..
SQLDMO_ECAT_INVALIDPLATFORM = 0x5400,
        SQLDMO_E_BACKUPSQL60ONLY = 0x5400,
        SQLDMO_E_MSSQLONLY = 0x5401,
        SQLDMO_E_WIN95REQUIRESCONN = 0x5402,
        SQLDMO_E_NOTONWIN95 = 0x5403,
        SQLDMO_E_SQL60ONLY = 0x5404,
        SQLDMO_E_REPLSQL60ONLY = 0x5405,
        SQLDMO_E_STARTUPPROCSQL60ONLY = 0x5406,
        SQLDMO_E_NEEDSQLDMOPROCS = 0x5407,
        SQLDMO_E_ALTERSQL60ONLY = 0x5408,
        SQLDMO_E_SORTEDDATAREORGSQL60ONLY = 0x5409,
        SQLDMO_E_MSSQLNTONLY = 0x540A,
        SQLDMO_E_WIN95REQUIRESSQL60 = 0x540B,
        SQLDMO_E_BACKUPSQL65ONLY = 0x540C,
        SQLDMO_E_SQL65ONLY = 0x540D,
        SQLDMO_E_ALERTSQL65ONLY = 0x540E,
        SQLDMO_E_REMOTESQL65ONLY = 0x540F,
        SQLDMO_E_PIPEDEVSQL60ONLY = 0x5410,
        SQLDMO_E_FKEYSQL65ONLY = 0x5411,
        SQLDMO_E_XPIMPERSONATESQL65ONLY = 0x5412,
        SQLDMO_E_SQL70ONLY = 0x5413,
        SQLDMO_E_FKEYSQL70ONLY = 0x5414,
        SQLDMO_E_BACKUPSQL70ONLY = 0x5415,
        SQLDMO_E_NEEDSQLDMOUPGRADE = 0x5416,
        SQLDMO_E_NEEDSERVERBUILDUPGRADE = 0x5417,
        SQLDMO_E_SQL75ONLY = 0x5418,
        SQLDMO_E_SQL80ONLY = 0x5419,


// Errors indicating that the named object was not found in the collection, or
// that the ordinal passed as a collection index was out of range.
SQLDMO_ECAT_ITEMNOTFOUND = 0x5500,
        SQLDMO_E_RULENOTFOUND = 0x5500,
        SQLDMO_E_DEFAULTNOTFOUND = 0x5501,
        SQLDMO_E_TYPENOTFOUND = 0x5502,
        SQLDMO_E_LOGINNOTFOUND = 0x5503,
        SQLDMO_E_GROUPNOTFOUND = 0x5504,
        SQLDMO_E_LANGNOTFOUND = 0x5505,
        SQLDMO_E_DBNOTFOUND = 0x5506,
        SQLDMO_E_DEVICENOTFOUND = 0x5507,
        SQLDMO_E_COLUMNNOTFOUND = 0x5508,
        SQLDMO_E_ORDOUTOFRANGE = 0x5509,
        SQLDMO_E_NAMENOTFOUND = 0x550A,
        SQLDMO_E_USERNOTFOUND = 0x550B,
        SQLDMO_E_NAMENOTINCACHE = 0x550C,
        SQLDMO_E_PROPNAMENOTFOUND = 0x550D,
        SQLDMO_E_IDNOTFOUND = 0x550E,
        SQLDMO_E_DATABASEROLENOTFOUND = 0x550F,
        SQLDMO_E_NAMENOTFOUNDQI = 0x5510,
        SQLDMO_E_COLLATIONNOTFOUND = 0x5511,
        SQLDMO_E_SERVERNOTFOUND = 0x5512,

// Errors indicating that the current login does not have sufficient privilege
// to perform the requested operation.
SQLDMO_ECAT_UNPRIVILEGEDLOGIN = 0x5600,
        SQLDMO_E_MUSTBESAORDBO = 0x5600,
        SQLDMO_E_MUSTBESAORLOGIN = 0x5601,
        SQLDMO_E_MUSTBESA = 0x5602,
        SQLDMO_E_MUSTBESAORORSECORLOGIN = 0x5603,
        SQLDMO_E_MUSTBESAORSEC = 0x5604,
        SQLDMO_E_MUSTBESAORDBC = 0x5605,
        SQLDMO_E_MUSTBESAORSRV = 0x5606,
        SQLDMO_E_MUSTBESAORPRC = 0x5607,

// Errors indicating a query execution error or an inaccessible database.
SQLDMO_ECAT_EXECUTION = 0x5700,
        SQLDMO_E_SYSPROCERROR = 0x5700,
        SQLDMO_E_CACHEEXECERROR = 0x5701,
        SQLDMO_E_INACCESSIBLEDB = 0x5702,
        SQLDMO_E_BATCHCOMPLETEWITHERRORS = 0x5703,
        SQLDMO_E_BCPCOLFMTFAILED = 0x5704,              //dblib bcp_colfmt failed.
        SQLDMO_E_SUSPENDINDEX = 0x5705,                 //Error trying to suspend indexing
        SQLDMO_E_RESUMEINDEX = 0x5706,                  //Error trying to resume suspended indexing
        SQLDMO_E_BCPEXECFAILED  = 0x5707,               //dblib bcp_exec function failed
        SQLDMO_E_BCPINITFAILED = 0x5708,                //dblib bcp_init function failed
        SQLDMO_E_BCPCONTROLFAILED = 0x5709,             //dblib bcp_control function failed
        SQLDMO_E_USERABORTED = 0x570A,                  //User aborted transfer
        SQLDMO_E_QIERROR = 0x570B,                      // Failed to set QI
        SQLDMO_E_REGIONALERROR = 0x570C,                // Failed to set regional setting
        SQLDMO_E_SINGLEUSERDB = 0x570D,                 // DB in single user mode, and someone is in there
        SQLDMO_E_CANNOTCREATEARTICLEVIEW = 0x570E,      // sp_articleview returns failure
        SQLDMO_E_CANNOTCREATEARTICLEFILTER = 0x570F,    // sp_articlefilter returns failure

// Errors indicating the connection to SQL Server cannot be restored.  SQLDMO will
// automatically reconnect (as determined by the SQLServer.AutoReconnect property)
// but the network may be down or the server not started.
SQLDMO_ECAT_CONNECTION = 0x5800,
        SQLDMO_E_CANTRECONNDEADCONN = 0x5800,

// Errors indicating insufficient resources either locally or on the server.
SQLDMO_ECAT_RESOURCE = 0x5900,
        SQLDMO_E_OUTOFMEMORY = 0x5900,
        SQLDMO_E_NOMOREDEVNOS = 0x5901,
        SQLDMO_E_SERVERLOCKTIMEDOUT = 0x5902,
        SQLDMO_E_APPLOCKTIMEDOUT = 0x5903,

        SQLDMO_E_LASTERROR = 0x5AFF
} SQLDMO_ERROR_TYPE;

// SQLDMO_ERROR #defines.  These are categories, not severities; there is no
// mathematical relationship between groupings.
#ifndef _SQLDMO_ODL_            // Not done in .ODL file.

// Switch on SQLDMO_ECAT to determine the category of a returned error code.
// Use long cast as lint can complain about an enum-vs.-int.
#define SQLDMO_ECAT(scode) (scode & (long)SQLDMO_ECAT_MASK)

#endif



#endif	// _SQLDMO_CONSTANTS_

/////////////////////////////////////////////////////////////////////////////////////////
// Interface definitions.
/////////////////////////////////////////////////////////////////////////////////////////
#ifndef _SQLDMO_ODL_		// Skip if in .odl file.

// Optional parameter definitions.  For C explicit values will have to be specified,
// as indicated within the CPPDEFAULT() expansion.
//
// SQLDMO Parameter sequencing is as follows ("optional" in accordance with C++ usage):
// 	Nonoptional parameters
//		Nonoptional Return value if any
//		Optional additional parameters
//		Optional return value, if any
//
#ifdef __cplusplus
#define CPPDEFAULT(DefaultParamValue)	DefaultParamValue
#else
#define CPPDEFAULT(DefaultParamValue)
#endif

// Windows.h should define these...
typedef BOOL *LPBOOL;
typedef float *LPFLOAT;
typedef double *LPDOUBLE;

///////////////////////////////////////////////////////////////////////////////////////
// Forward declarations and typedefs, allowing for UNICODE clients.
///////////////////////////////////////////////////////////////////////////////////////
#undef SQLDMO_LPCSTR
#undef SQLDMO_BSTR
#undef SQLDMO_LPBSTR
#undef SQLDMOFreeString

// Carry over the Ansi definition of BSTR.
typedef CHAR __RPC_FAR * BSTRA;
typedef BSTRA __RPC_FAR *LPBSTRA;

#define SQLDMO_UNICODE

#define SQLDMO_LPCSTR   LPCOLESTR
// #define SQLDMO_LPCSTR   LPCWSTR
#define SQLDMO_BSTR     BSTR
#define SQLDMO_LPBSTR   LPBSTR
#define SQLDMOFreeString(bstr) SysFreeString(bstr)

#ifdef __cplusplus
#define TYPEDEFINTERFACE typedef
#else
#define TYPEDEFINTERFACE typedef interface
#endif

// Forward declarations.  Base classes...
#undef LPSQLDMOSTDOBJECT
#undef ISQLDMOStdObject
#undef IID_ISQLDMOStdObject
interface IWSQLDMOStdObject;			TYPEDEFINTERFACE IWSQLDMOStdObject *				LPWSQLDMOSTDOBJECT;
#define LPSQLDMOSTDOBJECT LPWSQLDMOSTDOBJECT
#define ISQLDMOStdObject IWSQLDMOStdObject
#define IID_ISQLDMOStdObject IID_IWSQLDMOStdObject

#undef LPSQLDMOSTDCOLLECTION
#undef ISQLDMOStdCollection
#undef IID_ISQLDMOStdCollection
TYPEDEFINTERFACE IWSQLDMOStdObject * LPWSQLDMOSTDCOLLECTION;	// Auto-documenting for collection management
#define LPSQLDMOSTDCOLLECTION LPWSQLDMOSTDCOLLECTION
#define ISQLDMOStdCollection IWSQLDMOStdCollection
#define IID_ISQLDMOStdCollection IID_IWSQLDMOStdCollection

// ... and derived classes.

// ***************************************************************************
//               Copyright (C) 1985-1999 Microsoft Corporation.
// @File: core_itf.h
//
// Purpose: CORE defines and interfaces
//
//
// Notes:
//
// History:
//
//   @Version: Shiloh
//   65649 IXL  07/08/00 remove job server from job script
//   61175 WG   05/10/00 VIA Netlibs
//   60740 WG   05/08/00 New dboptions for recovery
//   60549 WG   05/01/00 New ServerRole bulkadmin
//   60311 WG   04/27/00 Encrypted UDF checking
//   55928 WG   02/28/00 Compatibility level
//   54473 WG   02/11/00 New script option
//   54427 WG   02/11/00 Restore BackupSetName
//   54311 WG   02/10/00 Extended Property
//   53618 WG   02/03/00 UDF ListPermission
//   53312 WG   01/31/00 Transferrable encryption
//   53089 WG   01/28/00 New Backup Restore option
//   52952 WG   01/27/00 Linked Server option
//   52788 WG   01/26/00 Linked Server options
//   52521 WG   01/24/00 Backup and Restore
//   52513 WG   01/24/00 GrantedGranted
//   52356 WG   01/21/00 ProductLevel
//   51928 WG   01/18/00 EnumAvailableMedia
//   51899 WG   01/18/00 DatabaseRole
//   51623 WG   01/17/00 IsDeleted
//   51534 WG   01/13/00 CheckSyntax
//   50625 WG   01/04/00 Syntax check for default and rule
//   50559 WG   01/03/00 Language ID on fulltext column
//   50447 WG   12/29/99 EnumDependencies with system objects
//   49768 WG   12/14/99 Support bigint in QueryResult
//   49712 WG   12/13/99 Refresh for LinkedServer
//   49522 WG   12/10/99 Script Job with enable flag
//   49452 WG   12/10/99 EnumParameters for UDF
//   49129 WG   12/07/99 CTS tracking
//
//
// @EndHeader@
// ***************************************************************************





#undef LPSQLDMOAPPLICATION
#undef ISQLDMOApplication
#undef IID_ISQLDMOApplication
interface IWSQLDMOApplication;          TYPEDEFINTERFACE IWSQLDMOApplication *                  LPWSQLDMOAPPLICATION;
#define LPSQLDMOAPPLICATION LPWSQLDMOAPPLICATION
#define ISQLDMOApplication IWSQLDMOApplication
#define IID_ISQLDMOApplication IID_IWSQLDMOApplication

#undef LPSQLDMOSERVERS
#undef ISQLDMOServers
#undef IID_ISQLDMOServers
interface IWSQLDMOServers;                      TYPEDEFINTERFACE IWSQLDMOServers *                              LPWSQLDMOSERVERS;
#define LPSQLDMOSERVERS LPWSQLDMOSERVERS
#define ISQLDMOServers IWSQLDMOServers
#define IID_ISQLDMOServers IID_IWSQLDMOServers

#undef LPSQLDMOSERVER
#undef ISQLDMOServer
#undef IID_ISQLDMOServer
interface IWSQLDMOServer;                       TYPEDEFINTERFACE IWSQLDMOServer *                                       LPWSQLDMOSERVER;
#define LPSQLDMOSERVER LPWSQLDMOSERVER
#define ISQLDMOServer IWSQLDMOServer
#define IID_ISQLDMOServer IID_IWSQLDMOServer

#undef LPSQLDMOSERVER2
#undef ISQLDMOServer2
#undef IID_ISQLDMOServer2
interface IWSQLDMOServer2;                       TYPEDEFINTERFACE IWSQLDMOServer2 *                                       LPWSQLDMOSERVER2;
#define LPSQLDMOSERVER2 LPWSQLDMOSERVER2
#define ISQLDMOServer2 IWSQLDMOServer2
#define IID_ISQLDMOServer2 IID_IWSQLDMOServer2

#undef LPSQLDMODATABASES
#undef ISQLDMODatabases
#undef IID_ISQLDMODatabases
interface IWSQLDMODatabases;                    TYPEDEFINTERFACE IWSQLDMODatabases *                            LPWSQLDMODATABASES;
#define LPSQLDMODATABASES LPWSQLDMODATABASES
#define ISQLDMODatabases IWSQLDMODatabases
#define IID_ISQLDMODatabases IID_IWSQLDMODatabases

#undef LPSQLDMODATABASE
#undef ISQLDMODatabase
#undef IID_ISQLDMODatabase
interface IWSQLDMODatabase;                     TYPEDEFINTERFACE IWSQLDMODatabase *                             LPWSQLDMODATABASE;
#define LPSQLDMODATABASE LPWSQLDMODATABASE
#define ISQLDMODatabase IWSQLDMODatabase
#define IID_ISQLDMODatabase IID_IWSQLDMODatabase

#undef LPSQLDMODATABASE2
#undef ISQLDMODatabase2
#undef IID_ISQLDMODatabase2
interface IWSQLDMODatabase2;                     TYPEDEFINTERFACE IWSQLDMODatabase2 *                             LPWSQLDMODATABASE2;
#define LPSQLDMODATABASE2 LPWSQLDMODATABASE2
#define ISQLDMODatabase2 IWSQLDMODatabase2
#define IID_ISQLDMODatabase2 IID_IWSQLDMODatabase2

#undef LPSQLDMOBACKUPDEVICES
#undef ISQLDMOBackupDevices
#undef IID_ISQLDMOBackupDevices
interface IWSQLDMOBackupDevices;                TYPEDEFINTERFACE IWSQLDMOBackupDevices *                   LPWSQLDMOBACKUPDEVICES;
#define LPSQLDMOBACKUPDEVICES LPWSQLDMOBACKUPDEVICES
#define ISQLDMOBackupDevices IWSQLDMOBackupDevices
#define IID_ISQLDMOBackupDevices IID_IWSQLDMOBackupDevices

#undef LPSQLDMOBACKUPDEVICE
#undef ISQLDMOBackupDevice
#undef IID_ISQLDMOBackupDevice
interface IWSQLDMOBackupDevice;                 TYPEDEFINTERFACE IWSQLDMOBackupDevice *                    LPWSQLDMOBACKUPDEVICE;
#define LPSQLDMOBACKUPDEVICE LPWSQLDMOBACKUPDEVICE
#define ISQLDMOBackupDevice IWSQLDMOBackupDevice
#define IID_ISQLDMOBackupDevice IID_IWSQLDMOBackupDevice

/** Need to take out when BillPos is ready **/
#undef LPSQLDMODEVICES
#undef ISQLDMODevices
#undef IID_ISQLDMODevices
#define LPSQLDMODEVICES LPWSQLDMOBACKUPDEVICES
#define ISQLDMODevices IWSQLDMOBackupDevices
#define IID_ISQLDMODevices IID_IWSQLDMOBackupDevices

#undef LPSQLDMODEVICE
#undef ISQLDMODevice
#undef IID_ISQLDMODevice
#define LPSQLDMODEVICE LPWSQLDMOBACKUPDEVICE
#define ISQLDMODevice IWSQLDMOBackupDevice
#define IID_ISQLDMODevice IID_IWSQLDMOBackupDevice
/**/

#undef LPSQLDMOLOGINS
#undef ISQLDMOLogins
#undef IID_ISQLDMOLogins
interface IWSQLDMOLogins;                       TYPEDEFINTERFACE IWSQLDMOLogins *                                       LPWSQLDMOLOGINS;
#define LPSQLDMOLOGINS LPWSQLDMOLOGINS
#define ISQLDMOLogins IWSQLDMOLogins
#define IID_ISQLDMOLogins IID_IWSQLDMOLogins

#undef LPSQLDMOLOGIN
#undef ISQLDMOLogin
#undef IID_ISQLDMOLogin
interface IWSQLDMOLogin;                                TYPEDEFINTERFACE IWSQLDMOLogin *                                        LPWSQLDMOLOGIN;
#define LPSQLDMOLOGIN LPWSQLDMOLOGIN
#define ISQLDMOLogin IWSQLDMOLogin
#define IID_ISQLDMOLogin IID_IWSQLDMOLogin

#undef LPSQLDMOLOGIN2
#undef ISQLDMOLogin2
#undef IID_ISQLDMOLogin2
interface IWSQLDMOLogin2;                                TYPEDEFINTERFACE IWSQLDMOLogin2 *                                        LPWSQLDMOLOGIN2;
#define LPSQLDMOLOGIN2 LPWSQLDMOLOGIN2
#define ISQLDMOLogin2 IWSQLDMOLogin2
#define IID_ISQLDMOLogin2 IID_IWSQLDMOLogin2

#undef LPSQLDMOLANGUAGES
#undef ISQLDMOLanguages
#undef IID_ISQLDMOLanguages
interface IWSQLDMOLanguages;                    TYPEDEFINTERFACE IWSQLDMOLanguages *                            LPWSQLDMOLANGUAGES;
#define LPSQLDMOLANGUAGES LPWSQLDMOLANGUAGES
#define ISQLDMOLanguages IWSQLDMOLanguages
#define IID_ISQLDMOLanguages IID_IWSQLDMOLanguages

#undef LPSQLDMOLANGUAGE
#undef ISQLDMOLanguage
#undef IID_ISQLDMOLanguage
interface IWSQLDMOLanguage;                     TYPEDEFINTERFACE IWSQLDMOLanguage *                             LPWSQLDMOLANGUAGE;
#define LPSQLDMOLANGUAGE LPWSQLDMOLANGUAGE
#define ISQLDMOLanguage IWSQLDMOLanguage
#define IID_ISQLDMOLanguage IID_IWSQLDMOLanguage

#undef LPSQLDMOREMOTESERVERS
#undef ISQLDMORemoteServers
#undef IID_ISQLDMORemoteServers
interface IWSQLDMORemoteServers;                TYPEDEFINTERFACE IWSQLDMORemoteServers *                        LPWSQLDMOREMOTESERVERS;
#define LPSQLDMOREMOTESERVERS LPWSQLDMOREMOTESERVERS
#define ISQLDMORemoteServers IWSQLDMORemoteServers
#define IID_ISQLDMORemoteServers IID_IWSQLDMORemoteServers

#undef LPSQLDMOREMOTESERVER
#undef ISQLDMORemoteServer
#undef IID_ISQLDMORemoteServer
interface IWSQLDMORemoteServer;         TYPEDEFINTERFACE IWSQLDMORemoteServer *                 LPWSQLDMOREMOTESERVER;
#define LPSQLDMOREMOTESERVER LPWSQLDMOREMOTESERVER
#define ISQLDMORemoteServer IWSQLDMORemoteServer
#define IID_ISQLDMORemoteServer IID_IWSQLDMORemoteServer

#undef LPSQLDMOREMOTESERVER2
#undef ISQLDMORemoteServer2
#undef IID_ISQLDMORemoteServer2
interface IWSQLDMORemoteServer2;         TYPEDEFINTERFACE IWSQLDMORemoteServer2 *                 LPWSQLDMOREMOTESERVER2;
#define LPSQLDMOREMOTESERVER2 LPWSQLDMOREMOTESERVER2
#define ISQLDMORemoteServer2 IWSQLDMORemoteServer2
#define IID_ISQLDMORemoteServer2 IID_IWSQLDMORemoteServer2

#undef LPSQLDMOTABLES
#undef ISQLDMOTables
#undef IID_ISQLDMOTables
interface IWSQLDMOTables;                       TYPEDEFINTERFACE IWSQLDMOTables *                                       LPWSQLDMOTABLES;
#define LPSQLDMOTABLES LPWSQLDMOTABLES
#define ISQLDMOTables IWSQLDMOTables
#define IID_ISQLDMOTables IID_IWSQLDMOTables

#undef LPSQLDMOTABLE
#undef ISQLDMOTable
#undef IID_ISQLDMOTable
interface IWSQLDMOTable;                                TYPEDEFINTERFACE IWSQLDMOTable *                                        LPWSQLDMOTABLE;
#define LPSQLDMOTABLE LPWSQLDMOTABLE
#define ISQLDMOTable IWSQLDMOTable
#define IID_ISQLDMOTable IID_IWSQLDMOTable

#undef LPSQLDMOTABLE2
#undef ISQLDMOTable2
#undef IID_ISQLDMOTable2
interface IWSQLDMOTable2;                                TYPEDEFINTERFACE IWSQLDMOTable2 *                                        LPWSQLDMOTABLE2;
#define LPSQLDMOTABLE2 LPWSQLDMOTABLE2
#define ISQLDMOTable2 IWSQLDMOTable2
#define IID_ISQLDMOTable2 IID_IWSQLDMOTable2

#undef LPSQLDMOCOLUMNS
#undef ISQLDMOColumns
#undef IID_ISQLDMOColumns
interface IWSQLDMOColumns;                      TYPEDEFINTERFACE IWSQLDMOColumns *                              LPWSQLDMOCOLUMNS;
#define LPSQLDMOCOLUMNS LPWSQLDMOCOLUMNS
#define ISQLDMOColumns IWSQLDMOColumns
#define IID_ISQLDMOColumns IID_IWSQLDMOColumns

#undef LPSQLDMOCOLUMN
#undef ISQLDMOColumn
#undef IID_ISQLDMOColumn
interface IWSQLDMOColumn;                       TYPEDEFINTERFACE IWSQLDMOColumn *                                       LPWSQLDMOCOLUMN;
#define LPSQLDMOCOLUMN LPWSQLDMOCOLUMN
#define ISQLDMOColumn IWSQLDMOColumn
#define IID_ISQLDMOColumn IID_IWSQLDMOColumn

#undef LPSQLDMOCOLUMN2
#undef ISQLDMOColumn2
#undef IID_ISQLDMOColumn2
interface IWSQLDMOColumn2;                       TYPEDEFINTERFACE IWSQLDMOColumn2 *                                       LPWSQLDMOCOLUMN2;
#define LPSQLDMOCOLUMN2 LPWSQLDMOCOLUMN2
#define ISQLDMOColumn2 IWSQLDMOColumn2
#define IID_ISQLDMOColumn2 IID_IWSQLDMOColumn2

#undef LPSQLDMORULES
#undef ISQLDMORules
#undef IID_ISQLDMORules
interface IWSQLDMORules;                                TYPEDEFINTERFACE IWSQLDMORules *                                        LPWSQLDMORULES;
#define LPSQLDMORULES LPWSQLDMORULES
#define ISQLDMORules IWSQLDMORules
#define IID_ISQLDMORules IID_IWSQLDMORules

#undef LPSQLDMORULE
#undef ISQLDMORule
#undef IID_ISQLDMORule
interface IWSQLDMORule;                         TYPEDEFINTERFACE IWSQLDMORule *                                 LPWSQLDMORULE;
#define LPSQLDMORULE LPWSQLDMORULE
#define ISQLDMORule IWSQLDMORule
#define IID_ISQLDMORule IID_IWSQLDMORule

#undef LPSQLDMORULE2
#undef ISQLDMORule2
#undef IID_ISQLDMORule2
interface IWSQLDMORule2;                         TYPEDEFINTERFACE IWSQLDMORule2 *                                 LPWSQLDMORULE2;
#define LPSQLDMORULE2 LPWSQLDMORULE2
#define ISQLDMORule2 IWSQLDMORule2
#define IID_ISQLDMORule2 IID_IWSQLDMORule2

#undef LPSQLDMODEFAULTS
#undef ISQLDMODefaults
#undef IID_ISQLDMODefaults
interface IWSQLDMODefaults;                     TYPEDEFINTERFACE IWSQLDMODefaults *                             LPWSQLDMODEFAULTS;
#define LPSQLDMODEFAULTS LPWSQLDMODEFAULTS
#define ISQLDMODefaults IWSQLDMODefaults
#define IID_ISQLDMODefaults IID_IWSQLDMODefaults

#undef LPSQLDMODEFAULT
#undef ISQLDMODefault
#undef IID_ISQLDMODefault
interface IWSQLDMODefault;                      TYPEDEFINTERFACE IWSQLDMODefault *                              LPWSQLDMODEFAULT;
#define LPSQLDMODEFAULT LPWSQLDMODEFAULT
#define ISQLDMODefault IWSQLDMODefault
#define IID_ISQLDMODefault IID_IWSQLDMODefault

#undef LPSQLDMODEFAULT2
#undef ISQLDMODefault2
#undef IID_ISQLDMODefault2
interface IWSQLDMODefault2;                      TYPEDEFINTERFACE IWSQLDMODefault2 *                              LPWSQLDMODEFAULT2;
#define LPSQLDMODEFAULT2 LPWSQLDMODEFAULT2
#define ISQLDMODefault2 IWSQLDMODefault2
#define IID_ISQLDMODefault2 IID_IWSQLDMODefault2

#undef LPSQLDMOUSERDEFINEDDATATYPES
#undef ISQLDMOUserDefinedDatatypes
#undef IID_ISQLDMOUserDefinedDatatypes
interface IWSQLDMOUserDefinedDatatypes; TYPEDEFINTERFACE IWSQLDMOUserDefinedDatatypes * LPWSQLDMOUSERDEFINEDDATATYPES;
#define LPSQLDMOUSERDEFINEDDATATYPES LPWSQLDMOUSERDEFINEDDATATYPES
#define ISQLDMOUserDefinedDatatypes IWSQLDMOUserDefinedDatatypes
#define IID_ISQLDMOUserDefinedDatatypes IID_IWSQLDMOUserDefinedDatatypes

#undef LPSQLDMOUSERDEFINEDDATATYPE
#undef ISQLDMOUserDefinedDatatype
#undef IID_ISQLDMOUserDefinedDatatype
interface IWSQLDMOUserDefinedDatatype;  TYPEDEFINTERFACE IWSQLDMOUserDefinedDatatype *  LPWSQLDMOUSERDEFINEDDATATYPE;
#define LPSQLDMOUSERDEFINEDDATATYPE LPWSQLDMOUSERDEFINEDDATATYPE
#define ISQLDMOUserDefinedDatatype IWSQLDMOUserDefinedDatatype
#define IID_ISQLDMOUserDefinedDatatype IID_IWSQLDMOUserDefinedDatatype

#undef LPSQLDMOUSERDEFINEDDATATYPE2
#undef ISQLDMOUserDefinedDatatype2
#undef IID_ISQLDMOUserDefinedDatatype2
interface IWSQLDMOUserDefinedDatatype2;  TYPEDEFINTERFACE IWSQLDMOUserDefinedDatatype2 *  LPWSQLDMOUSERDEFINEDDATATYPE2;
#define LPSQLDMOUSERDEFINEDDATATYPE2 LPWSQLDMOUSERDEFINEDDATATYPE2
#define ISQLDMOUserDefinedDatatype2 IWSQLDMOUserDefinedDatatype2
#define IID_ISQLDMOUserDefinedDatatype2 IID_IWSQLDMOUserDefinedDatatype2

#undef LPSQLDMOSYSTEMDATATYPES
#undef ISQLDMOSystemDatatypes
#undef IID_ISQLDMOSystemDatatypes
interface IWSQLDMOSystemDatatypes;      TYPEDEFINTERFACE IWSQLDMOSystemDatatypes *              LPWSQLDMOSYSTEMDATATYPES;
#define LPSQLDMOSYSTEMDATATYPES LPWSQLDMOSYSTEMDATATYPES
#define ISQLDMOSystemDatatypes IWSQLDMOSystemDatatypes
#define IID_ISQLDMOSystemDatatypes IID_IWSQLDMOSystemDatatypes

#undef LPSQLDMOSYSTEMDATATYPE
#undef ISQLDMOSystemDatatype
#undef IID_ISQLDMOSystemDatatype
interface IWSQLDMOSystemDatatype;       TYPEDEFINTERFACE IWSQLDMOSystemDatatype *                       LPWSQLDMOSYSTEMDATATYPE;
#define LPSQLDMOSYSTEMDATATYPE LPWSQLDMOSYSTEMDATATYPE
#define ISQLDMOSystemDatatype IWSQLDMOSystemDatatype
#define IID_ISQLDMOSystemDatatype IID_IWSQLDMOSystemDatatype

#undef LPSQLDMOSYSTEMDATATYPE2
#undef ISQLDMOSystemDatatype2
#undef IID_ISQLDMOSystemDatatype2
interface IWSQLDMOSystemDatatype2;       TYPEDEFINTERFACE IWSQLDMOSystemDatatype2 *                       LPWSQLDMOSYSTEMDATATYPE2;
#define LPSQLDMOSYSTEMDATATYPE2 LPWSQLDMOSYSTEMDATATYPE2
#define ISQLDMOSystemDatatype2 IWSQLDMOSystemDatatype2
#define IID_ISQLDMOSystemDatatype2 IID_IWSQLDMOSystemDatatype2

#undef LPSQLDMOVIEWS
#undef ISQLDMOViews
#undef IID_ISQLDMOViews
interface IWSQLDMOViews;                                TYPEDEFINTERFACE IWSQLDMOViews *                                        LPWSQLDMOVIEWS;
#define LPSQLDMOVIEWS LPWSQLDMOVIEWS
#define ISQLDMOViews IWSQLDMOViews
#define IID_ISQLDMOViews IID_IWSQLDMOViews

#undef LPSQLDMOVIEW
#undef ISQLDMOView
#undef IID_ISQLDMOView
interface IWSQLDMOView;                         TYPEDEFINTERFACE IWSQLDMOView *                                 LPWSQLDMOVIEW;
#define LPSQLDMOVIEW LPWSQLDMOVIEW
#define ISQLDMOView IWSQLDMOView
#define IID_ISQLDMOView IID_IWSQLDMOView

#undef LPSQLDMOVIEW2
#undef ISQLDMOView2
#undef IID_ISQLDMOView2
interface IWSQLDMOView2;                         TYPEDEFINTERFACE IWSQLDMOView2 *                                 LPWSQLDMOVIEW2;
#define LPSQLDMOVIEW2 LPWSQLDMOVIEW2
#define ISQLDMOView2 IWSQLDMOView2
#define IID_ISQLDMOView2 IID_IWSQLDMOView2

#undef LPSQLDMOSTOREDPROCEDURES
#undef ISQLDMOStoredProcedures
#undef IID_ISQLDMOStoredProcedures
interface IWSQLDMOStoredProcedures;     TYPEDEFINTERFACE IWSQLDMOStoredProcedures *             LPWSQLDMOSTOREDPROCEDURES;
#define LPSQLDMOSTOREDPROCEDURES LPWSQLDMOSTOREDPROCEDURES
#define ISQLDMOStoredProcedures IWSQLDMOStoredProcedures
#define IID_ISQLDMOStoredProcedures IID_IWSQLDMOStoredProcedures

#undef LPSQLDMOSTOREDPROCEDURE
#undef ISQLDMOStoredProcedure
#undef IID_ISQLDMOStoredProcedure
interface IWSQLDMOStoredProcedure;      TYPEDEFINTERFACE IWSQLDMOStoredProcedure *              LPWSQLDMOSTOREDPROCEDURE;
#define LPSQLDMOSTOREDPROCEDURE LPWSQLDMOSTOREDPROCEDURE
#define ISQLDMOStoredProcedure IWSQLDMOStoredProcedure
#define IID_ISQLDMOStoredProcedure IID_IWSQLDMOStoredProcedure

#undef LPSQLDMOSTOREDPROCEDURE2
#undef ISQLDMOStoredProcedure2
#undef IID_ISQLDMOStoredProcedure2
interface IWSQLDMOStoredProcedure2;      TYPEDEFINTERFACE IWSQLDMOStoredProcedure2 *              LPWSQLDMOSTOREDPROCEDURE2;
#define LPSQLDMOSTOREDPROCEDURE2 LPWSQLDMOSTOREDPROCEDURE2
#define ISQLDMOStoredProcedure2 IWSQLDMOStoredProcedure2
#define IID_ISQLDMOStoredProcedure2 IID_IWSQLDMOStoredProcedure2

#undef LPSQLDMOTRIGGERS
#undef ISQLDMOTriggers
#undef IID_ISQLDMOTriggers
interface IWSQLDMOTriggers;                     TYPEDEFINTERFACE IWSQLDMOTriggers *                             LPWSQLDMOTRIGGERS;
#define LPSQLDMOTRIGGERS LPWSQLDMOTRIGGERS
#define ISQLDMOTriggers IWSQLDMOTriggers
#define IID_ISQLDMOTriggers IID_IWSQLDMOTriggers

#undef LPSQLDMOTRIGGER
#undef ISQLDMOTrigger
#undef IID_ISQLDMOTrigger
interface IWSQLDMOTrigger;                      TYPEDEFINTERFACE IWSQLDMOTrigger *                              LPWSQLDMOTRIGGER;
#define LPSQLDMOTRIGGER LPWSQLDMOTRIGGER
#define ISQLDMOTrigger IWSQLDMOTrigger
#define IID_ISQLDMOTrigger IID_IWSQLDMOTrigger

#undef LPSQLDMOTRIGGER2
#undef ISQLDMOTrigger2
#undef IID_ISQLDMOTrigger2
interface IWSQLDMOTrigger2;                      TYPEDEFINTERFACE IWSQLDMOTrigger2 *                              LPWSQLDMOTRIGGER2;
#define LPSQLDMOTRIGGER2 LPWSQLDMOTRIGGER2
#define ISQLDMOTrigger2 IWSQLDMOTrigger2
#define IID_ISQLDMOTrigger2 IID_IWSQLDMOTrigger2

#undef LPSQLDMOUSERS
#undef ISQLDMOUsers
#undef IID_ISQLDMOUsers
interface IWSQLDMOUsers;                                TYPEDEFINTERFACE IWSQLDMOUsers *                                        LPWSQLDMOUSERS;
#define LPSQLDMOUSERS LPWSQLDMOUSERS
#define ISQLDMOUsers IWSQLDMOUsers
#define IID_ISQLDMOUsers IID_IWSQLDMOUsers

#undef LPSQLDMOUSER
#undef ISQLDMOUser
#undef IID_ISQLDMOUser
interface IWSQLDMOUser;                         TYPEDEFINTERFACE IWSQLDMOUser *                                 LPWSQLDMOUSER;
#define LPSQLDMOUSER LPWSQLDMOUSER
#define ISQLDMOUser IWSQLDMOUser
#define IID_ISQLDMOUser IID_IWSQLDMOUser

#undef LPSQLDMOUSER2
#undef ISQLDMOUser2
#undef IID_ISQLDMOUser2
interface IWSQLDMOUser2;                         TYPEDEFINTERFACE IWSQLDMOUser2 *                                 LPWSQLDMOUSER2;
#define LPSQLDMOUSER2 LPWSQLDMOUSER2
#define ISQLDMOUser2 IWSQLDMOUser2
#define IID_ISQLDMOUser2 IID_IWSQLDMOUser2

#undef LPSQLDMOGROUPS
#undef ISQLDMOGroups
#undef IID_ISQLDMOGroups
interface IWSQLDMOGroups;                       TYPEDEFINTERFACE IWSQLDMOGroups *                                       LPWSQLDMOGROUPS;
#define LPSQLDMOGROUPS LPWSQLDMOGROUPS
#define ISQLDMOGroups IWSQLDMOGroups
#define IID_ISQLDMOGroups IID_IWSQLDMOGroups

#undef LPSQLDMOGROUP
#undef ISQLDMOGroup
#undef IID_ISQLDMOGroup
interface IWSQLDMOGroup;                                TYPEDEFINTERFACE IWSQLDMOGroup *                                        LPWSQLDMOGROUP;
#define LPSQLDMOGROUP LPWSQLDMOGROUP
#define ISQLDMOGroup IWSQLDMOGroup
#define IID_ISQLDMOGroup IID_IWSQLDMOGroup

#undef LPSQLDMOINDEXES
#undef ISQLDMOIndexes
#undef IID_ISQLDMOIndexes
interface IWSQLDMOIndexes;                      TYPEDEFINTERFACE IWSQLDMOIndexes *                              LPWSQLDMOINDEXES;
#define LPSQLDMOINDEXES LPWSQLDMOINDEXES
#define ISQLDMOIndexes IWSQLDMOIndexes
#define IID_ISQLDMOIndexes IID_IWSQLDMOIndexes

#undef LPSQLDMOINDEX
#undef ISQLDMOIndex
#undef IID_ISQLDMOIndex
interface IWSQLDMOIndex;                                TYPEDEFINTERFACE IWSQLDMOIndex *                                        LPWSQLDMOINDEX;
#define LPSQLDMOINDEX LPWSQLDMOINDEX
#define ISQLDMOIndex IWSQLDMOIndex
#define IID_ISQLDMOIndex IID_IWSQLDMOIndex

#undef LPSQLDMOINDEX2
#undef ISQLDMOIndex2
#undef IID_ISQLDMOIndex2
interface IWSQLDMOIndex2;                                TYPEDEFINTERFACE IWSQLDMOIndex2 *                                        LPWSQLDMOINDEX2;
#define LPSQLDMOINDEX2 LPWSQLDMOINDEX2
#define ISQLDMOIndex2 IWSQLDMOIndex2
#define IID_ISQLDMOIndex2 IID_IWSQLDMOIndex2

#undef LPSQLDMOREMOTELOGINS
#undef ISQLDMORemoteLogins
#undef IID_ISQLDMORemoteLogins
interface IWSQLDMORemoteLogins;         TYPEDEFINTERFACE IWSQLDMORemoteLogins *                 LPWSQLDMOREMOTELOGINS;
#define LPSQLDMOREMOTELOGINS LPWSQLDMOREMOTELOGINS
#define ISQLDMORemoteLogins IWSQLDMORemoteLogins
#define IID_ISQLDMORemoteLogins IID_IWSQLDMORemoteLogins

#undef LPSQLDMOREMOTELOGIN
#undef ISQLDMORemoteLogin
#undef IID_ISQLDMORemoteLogin
interface IWSQLDMORemoteLogin;          TYPEDEFINTERFACE IWSQLDMORemoteLogin *                  LPWSQLDMOREMOTELOGIN;
#define LPSQLDMOREMOTELOGIN LPWSQLDMOREMOTELOGIN
#define ISQLDMORemoteLogin IWSQLDMORemoteLogin
#define IID_ISQLDMORemoteLogin IID_IWSQLDMORemoteLogin

#undef LPSQLDMODBOBJECTS
#undef ISQLDMODBObjects
#undef IID_ISQLDMODBObjects
interface IWSQLDMODBObjects;                    TYPEDEFINTERFACE IWSQLDMODBObjects *                            LPWSQLDMODBOBJECTS;
#define LPSQLDMODBOBJECTS LPWSQLDMODBOBJECTS
#define ISQLDMODBObjects IWSQLDMODBObjects
#define IID_ISQLDMODBObjects IID_IWSQLDMODBObjects

#undef LPSQLDMODBOBJECT
#undef ISQLDMODBObject
#undef IID_ISQLDMODBObject
interface IWSQLDMODBObject;                     TYPEDEFINTERFACE IWSQLDMODBObject *                             LPWSQLDMODBOBJECT;
#define LPSQLDMODBOBJECT LPWSQLDMODBOBJECT
#define ISQLDMODBObject IWSQLDMODBObject
#define IID_ISQLDMODBObject IID_IWSQLDMODBObject

#undef LPSQLDMODBOBJECT2
#undef ISQLDMODBObject2
#undef IID_ISQLDMODBObject2
interface IWSQLDMODBObject2;                     TYPEDEFINTERFACE IWSQLDMODBObject2 *                             LPWSQLDMODBOBJECT2;
#define LPSQLDMODBOBJECT2 LPWSQLDMODBOBJECT2
#define ISQLDMODBObject2 IWSQLDMODBObject2
#define IID_ISQLDMODBObject2 IID_IWSQLDMODBObject2

#undef LPSQLDMODBOPTION
#undef ISQLDMODBOption
#undef IID_ISQLDMODBOption
interface IWSQLDMODBOption;                     TYPEDEFINTERFACE IWSQLDMODBOption *                             LPWSQLDMODBOPTION;
#define LPSQLDMODBOPTION LPWSQLDMODBOPTION
#define ISQLDMODBOption IWSQLDMODBOption
#define IID_ISQLDMODBOption IID_IWSQLDMODBOption

#undef LPSQLDMODBOPTION2
#undef ISQLDMODBOption2
#undef IID_ISQLDMODBOption2
interface IWSQLDMODBOption2;                     TYPEDEFINTERFACE IWSQLDMODBOption2 *                             LPWSQLDMODBOPTION2;
#define LPSQLDMODBOPTION2 LPWSQLDMODBOPTION2
#define ISQLDMODBOption2 IWSQLDMODBOption2
#define IID_ISQLDMODBOption2 IID_IWSQLDMODBOption2

#undef LPSQLDMOCONFIGURATION
#undef ISQLDMOConfiguration
#undef IID_ISQLDMOConfiguration
interface IWSQLDMOConfiguration;                TYPEDEFINTERFACE IWSQLDMOConfiguration *                        LPWSQLDMOCONFIGURATION;
#define LPSQLDMOCONFIGURATION LPWSQLDMOCONFIGURATION
#define ISQLDMOConfiguration IWSQLDMOConfiguration
#define IID_ISQLDMOConfiguration IID_IWSQLDMOConfiguration

#undef LPSQLDMOCONFIGVALUES
#undef ISQLDMOConfigValues
#undef IID_ISQLDMOConfigValues
interface IWSQLDMOConfigValues;         TYPEDEFINTERFACE IWSQLDMOConfigValues *                         LPWSQLDMOCONFIGVALUES;
#define LPSQLDMOCONFIGVALUES LPWSQLDMOCONFIGVALUES
#define ISQLDMOConfigValues IWSQLDMOConfigValues
#define IID_ISQLDMOConfigValues IID_IWSQLDMOConfigValues

#undef LPSQLDMOCONFIGVALUE
#undef ISQLDMOConfigValue
#undef IID_ISQLDMOConfigValue
interface IWSQLDMOConfigValue;          TYPEDEFINTERFACE IWSQLDMOConfigValue *                          LPWSQLDMOCONFIGVALUE;
#define LPSQLDMOCONFIGVALUE LPWSQLDMOCONFIGVALUE
#define ISQLDMOConfigValue IWSQLDMOConfigValue
#define IID_ISQLDMOConfigValue IID_IWSQLDMOConfigValue

#undef LPSQLDMOQUERYRESULTS
#undef ISQLDMOQueryResults
#undef IID_ISQLDMOQueryResults
interface IWSQLDMOQueryResults;         TYPEDEFINTERFACE IWSQLDMOQueryResults *                 LPWSQLDMOQUERYRESULTS;
#define LPSQLDMOQUERYRESULTS LPWSQLDMOQUERYRESULTS
#define ISQLDMOQueryResults IWSQLDMOQueryResults
#define IID_ISQLDMOQueryResults IID_IWSQLDMOQueryResults

#undef LPSQLDMOQUERYRESULTS2
#undef ISQLDMOQueryResults2
#undef IID_ISQLDMOQueryResults2
interface IWSQLDMOQueryResults2;         TYPEDEFINTERFACE IWSQLDMOQueryResults2 *                 LPWSQLDMOQUERYRESULTS2;
#define LPSQLDMOQUERYRESULTS2 LPWSQLDMOQUERYRESULTS2
#define ISQLDMOQueryResults2 IWSQLDMOQueryResults2
#define IID_ISQLDMOQueryResults2 IID_IWSQLDMOQueryResults2

#undef LPSQLDMOTRANSACTIONLOG
#undef ISQLDMOTransactionLog
#undef IID_ISQLDMOTransactionLog
interface IWSQLDMOTransactionLog;       TYPEDEFINTERFACE IWSQLDMOTransactionLog *                       LPWSQLDMOTRANSACTIONLOG;
#define LPSQLDMOTRANSACTIONLOG LPWSQLDMOTRANSACTIONLOG
#define ISQLDMOTransactionLog IWSQLDMOTransactionLog
#define IID_ISQLDMOTransactionLog IID_IWSQLDMOTransactionLog

#undef LPSQLDMOTRANSACTIONLOG2
#undef ISQLDMOTransactionLog2
#undef IID_ISQLDMOTransactionLog2
interface IWSQLDMOTransactionLog2;       TYPEDEFINTERFACE IWSQLDMOTransactionLog2 *                       LPWSQLDMOTRANSACTIONLOG2;
#define LPSQLDMOTRANSACTIONLOG2 LPWSQLDMOTRANSACTIONLOG2
#define ISQLDMOTransactionLog2 IWSQLDMOTransactionLog2
#define IID_ISQLDMOTransactionLog2 IID_IWSQLDMOTransactionLog2

#undef LPSQLDMOREGISTRY
#undef ISQLDMORegistry
#undef IID_ISQLDMORegistry
interface IWSQLDMORegistry;                     TYPEDEFINTERFACE IWSQLDMORegistry *                             LPWSQLDMOREGISTRY;
#define LPSQLDMOREGISTRY LPWSQLDMOREGISTRY
#define ISQLDMORegistry IWSQLDMORegistry
#define IID_ISQLDMORegistry IID_IWSQLDMORegistry

#undef LPSQLDMOREGISTRY2
#undef ISQLDMORegistry2
#undef IID_ISQLDMORegistry2
interface IWSQLDMORegistry2;                     TYPEDEFINTERFACE IWSQLDMORegistry2 *                             LPWSQLDMOREGISTRY2;
#define LPSQLDMOREGISTRY2 LPWSQLDMOREGISTRY2
#define ISQLDMORegistry2 IWSQLDMORegistry2
#define IID_ISQLDMORegistry2 IID_IWSQLDMORegistry2

#undef LPSQLDMOBACKUP
#undef ISQLDMOBackup
#undef IID_ISQLDMOBackup
interface IWSQLDMOBackup;                       TYPEDEFINTERFACE IWSQLDMOBackup *                                       LPWSQLDMOBACKUP;
#define LPSQLDMOBACKUP LPWSQLDMOBACKUP
#define ISQLDMOBackup IWSQLDMOBackup
#define IID_ISQLDMOBackup IID_IWSQLDMOBackup

#undef LPSQLDMOBACKUP2
#undef ISQLDMOBackup2
#undef IID_ISQLDMOBackup2
interface IWSQLDMOBackup2;                       TYPEDEFINTERFACE IWSQLDMOBackup2 *                                       LPWSQLDMOBACKUP2;
#define LPSQLDMOBACKUP2 LPWSQLDMOBACKUP2
#define ISQLDMOBackup2 IWSQLDMOBackup2
#define IID_ISQLDMOBackup2 IID_IWSQLDMOBackup2

#undef LPSQLDMOBULKCOPY
#undef ISQLDMOBulkCopy
#undef IID_ISQLDMOBulkCopy
interface IWSQLDMOBulkCopy;                     TYPEDEFINTERFACE IWSQLDMOBulkCopy *                                     LPWSQLDMOBULKCOPY;
#define LPSQLDMOBULKCOPY LPWSQLDMOBULKCOPY
#define ISQLDMOBulkCopy IWSQLDMOBulkCopy
#define IID_ISQLDMOBulkCopy IID_IWSQLDMOBulkCopy

#undef LPSQLDMOBULKCOPY2
#undef ISQLDMOBulkCopy2
#undef IID_ISQLDMOBulkCopy2
interface IWSQLDMOBulkCopy2;                     TYPEDEFINTERFACE IWSQLDMOBulkCopy2 *                                     LPWSQLDMOBULKCOPY2;
#define LPSQLDMOBULKCOPY2 LPWSQLDMOBULKCOPY2
#define ISQLDMOBulkCopy2 IWSQLDMOBulkCopy2
#define IID_ISQLDMOBulkCopy2 IID_IWSQLDMOBulkCopy2

#undef LPSQLDMOOBJECTLIST
#undef ISQLDMOObjectList
#undef IID_ISQLDMOObjectList
interface IWSQLDMOObjectList;           TYPEDEFINTERFACE IWSQLDMOObjectList *                           LPWSQLDMOOBJECTLIST;
#define LPSQLDMOOBJECTLIST LPWSQLDMOOBJECTLIST
#define ISQLDMOObjectList IWSQLDMOObjectList
#define IID_ISQLDMOObjectList IID_IWSQLDMOObjectList

#undef LPSQLDMONAMES
#undef ISQLDMONames
#undef IID_ISQLDMONames
interface IWSQLDMONames;                TYPEDEFINTERFACE IWSQLDMONames *                                LPWSQLDMONAMES;
#define LPSQLDMONAMES LPWSQLDMONAMES
#define ISQLDMONames IWSQLDMONames
#define IID_ISQLDMONames IID_IWSQLDMONames

#undef LPSQLDMONAMELIST
#undef ISQLDMONameList
#undef IID_ISQLDMONameList
interface IWSQLDMONameList;             TYPEDEFINTERFACE IWSQLDMONameList *                             LPWSQLDMONAMELIST;
#define LPSQLDMONAMELIST LPWSQLDMONAMELIST
#define ISQLDMONameList IWSQLDMONameList
#define IID_ISQLDMONameList IID_IWSQLDMONameList

#undef LPSQLDMOPERMISSION
#undef ISQLDMOPermission
#undef IID_ISQLDMOPermission
interface IWSQLDMOPermission;           TYPEDEFINTERFACE IWSQLDMOPermission *                           LPWSQLDMOPERMISSION;
#define LPSQLDMOPERMISSION LPWSQLDMOPERMISSION
#define ISQLDMOPermission IWSQLDMOPermission
#define IID_ISQLDMOPermission IID_IWSQLDMOPermission

#undef LPSQLDMOPERMISSION2
#undef ISQLDMOPermission2
#undef IID_ISQLDMOPermission2
interface IWSQLDMOPermission2;           TYPEDEFINTERFACE IWSQLDMOPermission2 *                           LPWSQLDMOPERMISSION2;
#define LPSQLDMOPERMISSION2 LPWSQLDMOPERMISSION2
#define ISQLDMOPermission2 IWSQLDMOPermission2
#define IID_ISQLDMOPermission2 IID_IWSQLDMOPermission2

#undef LPSQLDMOINTEGRATEDSECURITY
#undef ISQLDMOIntegratedSecurity
#undef IID_ISQLDMOIntegratedSecurity
interface IWSQLDMOIntegratedSecurity;   TYPEDEFINTERFACE IWSQLDMOIntegratedSecurity *   LPWSQLDMOINTEGRATEDSECURITY;
#define LPSQLDMOINTEGRATEDSECURITY LPWSQLDMOINTEGRATEDSECURITY
#define ISQLDMOIntegratedSecurity IWSQLDMOIntegratedSecurity
#define IID_ISQLDMOIntegratedSecurity IID_IWSQLDMOIntegratedSecurity

#undef LPSQLDMOKEYS
#undef ISQLDMOKeys
#undef IID_ISQLDMOKeys
interface IWSQLDMOKeys;                 TYPEDEFINTERFACE IWSQLDMOKeys *                                 LPWSQLDMOKEYS;
#define LPSQLDMOKEYS LPWSQLDMOKEYS
#define ISQLDMOKeys IWSQLDMOKeys
#define IID_ISQLDMOKeys IID_IWSQLDMOKeys

#undef LPSQLDMOKEY
#undef ISQLDMOKey
#undef IID_ISQLDMOKey
interface IWSQLDMOKey;                          TYPEDEFINTERFACE IWSQLDMOKey *                                  LPWSQLDMOKEY;
#define LPSQLDMOKEY LPWSQLDMOKEY
#define ISQLDMOKey IWSQLDMOKey
#define IID_ISQLDMOKey IID_IWSQLDMOKey

#undef LPSQLDMOCHECKS
#undef ISQLDMOChecks
#undef IID_ISQLDMOChecks
interface IWSQLDMOChecks;                       TYPEDEFINTERFACE IWSQLDMOChecks *                                       LPWSQLDMOCHECKS;
#define LPSQLDMOCHECKS LPWSQLDMOCHECKS
#define ISQLDMOChecks IWSQLDMOChecks
#define IID_ISQLDMOChecks IID_IWSQLDMOChecks

#undef LPSQLDMOCHECK
#undef ISQLDMOCheck
#undef IID_ISQLDMOCheck
interface IWSQLDMOCheck;                                TYPEDEFINTERFACE IWSQLDMOCheck *                                        LPWSQLDMOCHECK;
#define LPSQLDMOCHECK LPWSQLDMOCHECK
#define ISQLDMOCheck IWSQLDMOCheck
#define IID_ISQLDMOCheck IID_IWSQLDMOCheck

#undef LPSQLDMODRIDEFAULT
#undef ISQLDMODRIDefault
#undef IID_ISQLDMODRIDefault
interface IWSQLDMODRIDefault;                           TYPEDEFINTERFACE IWSQLDMODRIDefault *                                   LPWSQLDMODRIDEFAULT;
#define LPSQLDMODRIDEFAULT LPWSQLDMODRIDEFAULT
#define ISQLDMODRIDefault IWSQLDMODRIDefault
#define IID_ISQLDMODRIDefault IID_IWSQLDMODRIDefault

#undef LPSQLDMOSERVERGROUPS
#undef ISQLDMOServerGroups
#undef IID_ISQLDMOServerGroups
interface IWSQLDMOServerGroups;                 TYPEDEFINTERFACE IWSQLDMOServerGroups *                                 LPWSQLDMOSERVERGROUPS;
#define LPSQLDMOSERVERGROUPS LPWSQLDMOSERVERGROUPS
#define ISQLDMOServerGroups IWSQLDMOServerGroups
#define IID_ISQLDMOServerGroups IID_IWSQLDMOServerGroups

#undef LPSQLDMOSERVERGROUP
#undef ISQLDMOServerGroup
#undef IID_ISQLDMOServerGroup
interface IWSQLDMOServerGroup;                          TYPEDEFINTERFACE IWSQLDMOServerGroup *                                  LPWSQLDMOSERVERGROUP;
#define LPSQLDMOSERVERGROUP LPWSQLDMOSERVERGROUP
#define ISQLDMOServerGroup IWSQLDMOServerGroup
#define IID_ISQLDMOServerGroup IID_IWSQLDMOServerGroup

#undef LPSQLDMOREGISTEREDSERVERS
#undef ISQLDMORegisteredServers
#undef IID_ISQLDMORegisteredServers
interface IWSQLDMORegisteredServers;                    TYPEDEFINTERFACE IWSQLDMORegisteredServers *                                    LPWSQLDMOREGISTEREDSERVERS;
#define LPSQLDMOREGISTEREDSERVERS LPWSQLDMOREGISTEREDSERVERS
#define ISQLDMORegisteredServers IWSQLDMORegisteredServers
#define IID_ISQLDMORegisteredServers IID_IWSQLDMORegisteredServers

#undef LPSQLDMOREGISTEREDSERVER
#undef ISQLDMORegisteredServer
#undef IID_ISQLDMORegisteredServer
interface IWSQLDMORegisteredServer;                             TYPEDEFINTERFACE IWSQLDMORegisteredServer *                                     LPWSQLDMOREGISTEREDSERVER;
#define LPSQLDMOREGISTEREDSERVER LPWSQLDMOREGISTEREDSERVER
#define ISQLDMORegisteredServer IWSQLDMORegisteredServer
#define IID_ISQLDMORegisteredServer IID_IWSQLDMORegisteredServer

#undef LPSQLDMOTRANSFER
#undef ISQLDMOTransfer
#undef IID_ISQLDMOTransfer
interface IWSQLDMOTransfer;                                             TYPEDEFINTERFACE IWSQLDMOTransfer *                             LPWSQLDMOTRANSFER;
#define LPSQLDMOTRANSFER LPWSQLDMOTRANSFER
#define ISQLDMOTransfer IWSQLDMOTransfer
#define IID_ISQLDMOTransfer IID_IWSQLDMOTransfer

#undef LPSQLDMOTRANSFER2
#undef ISQLDMOTransfer2
#undef IID_ISQLDMOTransfer2
interface IWSQLDMOTransfer2;                                             TYPEDEFINTERFACE IWSQLDMOTransfer2 *                             LPWSQLDMOTRANSFER2;
#define LPSQLDMOTRANSFER2 LPWSQLDMOTRANSFER2
#define ISQLDMOTransfer2 IWSQLDMOTransfer2
#define IID_ISQLDMOTransfer2 IID_IWSQLDMOTransfer2

// 7.0 new objects
#undef LPSQLDMOFILEGROUPS
#undef ISQLDMOFileGroups
#undef IID_ISQLDMOFileGroups
interface IWSQLDMOFileGroups;                    TYPEDEFINTERFACE IWSQLDMOFileGroups *                                    LPWSQLDMOFILEGROUPS;
#define LPSQLDMOFILEGROUPS LPWSQLDMOFILEGROUPS
#define ISQLDMOFileGroups IWSQLDMOFileGroups
#define IID_ISQLDMOFileGroups IID_IWSQLDMOFileGroups

#undef LPSQLDMOFILEGROUP
#undef ISQLDMOFileGroup
#undef IID_ISQLDMOFileGroup
interface IWSQLDMOFileGroup;                             TYPEDEFINTERFACE IWSQLDMOFileGroup *                                     LPWSQLDMOFILEGROUP;
#define LPSQLDMOFILEGROUP LPWSQLDMOFILEGROUP
#define ISQLDMOFileGroup IWSQLDMOFileGroup
#define IID_ISQLDMOFileGroup IID_IWSQLDMOFileGroup

#undef LPSQLDMOFILEGROUP2
#undef ISQLDMOFileGroup2
#undef IID_ISQLDMOFileGroup2
interface IWSQLDMOFileGroup2;                             TYPEDEFINTERFACE IWSQLDMOFileGroup2 *                                     LPWSQLDMOFILEGROUP2;
#define LPSQLDMOFILEGROUP2 LPWSQLDMOFILEGROUP2
#define ISQLDMOFileGroup2 IWSQLDMOFileGroup2
#define IID_ISQLDMOFileGroup2 IID_IWSQLDMOFileGroup2

#undef LPSQLDMODBFILES
#undef ISQLDMODBFiles
#undef IID_ISQLDMODBFiles
interface IWSQLDMODBFiles;                    TYPEDEFINTERFACE IWSQLDMODBFiles *                                    LPWSQLDMODBFILES;
#define LPSQLDMODBFILES LPWSQLDMODBFILES
#define ISQLDMODBFiles IWSQLDMODBFiles
#define IID_ISQLDMODBFiles IID_IWSQLDMODBFiles

#undef LPSQLDMODBFILE
#undef ISQLDMODBFile
#undef IID_ISQLDMODBFile
interface IWSQLDMODBFile;                             TYPEDEFINTERFACE IWSQLDMODBFile *                                     LPWSQLDMODBFILE;
#define LPSQLDMODBFILE LPWSQLDMODBFILE
#define ISQLDMODBFile IWSQLDMODBFile
#define IID_ISQLDMODBFile IID_IWSQLDMODBFile

#undef LPSQLDMOLOGFILES
#undef ISQLDMOLogFiles
#undef IID_ISQLDMOLogFiles
interface IWSQLDMOLogFiles;                    TYPEDEFINTERFACE IWSQLDMOLogFiles *                                    LPWSQLDMOLOGFILES;
#define LPSQLDMOLOGFILES LPWSQLDMOLOGFILES
#define ISQLDMOLogFiles IWSQLDMOLogFiles
#define IID_ISQLDMOLogFiles IID_IWSQLDMOLogFiles

#undef LPSQLDMOLOGFILES2
#undef ISQLDMOLogFiles2
#undef IID_ISQLDMOLogFiles2
interface IWSQLDMOLogFiles2;                    TYPEDEFINTERFACE IWSQLDMOLogFiles2 *                                    LPWSQLDMOLOGFILES2;
#define LPSQLDMOLOGFILES2 LPWSQLDMOLOGFILES2
#define ISQLDMOLogFiles2 IWSQLDMOLogFiles2
#define IID_ISQLDMOLogFiles2 IID_IWSQLDMOLogFiles2

#undef LPSQLDMOLOGFILE
#undef ISQLDMOLogFile
#undef IID_ISQLDMOLogFile
interface IWSQLDMOLogFile;                             TYPEDEFINTERFACE IWSQLDMOLogFile *                                     LPWSQLDMOLOGFILE;
#define LPSQLDMOLOGFILE LPWSQLDMOLOGFILE
#define ISQLDMOLogFile IWSQLDMOLogFile
#define IID_ISQLDMOLogFile IID_IWSQLDMOLogFile

#undef LPSQLDMOLOGFILE2
#undef ISQLDMOLogFile2
#undef IID_ISQLDMOLogFile2
interface IWSQLDMOLogFile2;                             TYPEDEFINTERFACE IWSQLDMOLogFile2 *                                     LPWSQLDMOLOGFILE2;
#define LPSQLDMOLOGFILE2 LPWSQLDMOLOGFILE2
#define ISQLDMOLogFile2 IWSQLDMOLogFile2
#define IID_ISQLDMOLogFile2 IID_IWSQLDMOLogFile2

#undef LPSQLDMOSERVERROLES
#undef ISQLDMOServerRoles
#undef IID_ISQLDMOServerRoles
interface IWSQLDMOServerRoles;                    TYPEDEFINTERFACE IWSQLDMOServerRoles *                                    LPWSQLDMOSERVERROLES;
#define LPSQLDMOSERVERROLES LPWSQLDMOSERVERROLES
#define ISQLDMOServerRoles IWSQLDMOServerRoles
#define IID_ISQLDMOServerRoles IID_IWSQLDMOServerRoles

#undef LPSQLDMOSERVERROLE
#undef ISQLDMOServerRole
#undef IID_ISQLDMOServerRole
interface IWSQLDMOServerRole;                             TYPEDEFINTERFACE IWSQLDMOServerRole *                                     LPWSQLDMOSERVERROLE;
#define LPSQLDMOSERVERROLE LPWSQLDMOSERVERROLE
#define ISQLDMOServerRole IWSQLDMOServerRole
#define IID_ISQLDMOServerRole IID_IWSQLDMOServerRole

#undef LPSQLDMODATABASEROLES
#undef ISQLDMODatabaseRoles
#undef IID_ISQLDMODatabaseRoles
interface IWSQLDMODatabaseRoles;                    TYPEDEFINTERFACE IWSQLDMODatabaseRoles *                                    LPWSQLDMODATABASEROLES;
#define LPSQLDMODATABASEROLES LPWSQLDMODATABASEROLES
#define ISQLDMODatabaseRoles IWSQLDMODatabaseRoles
#define IID_ISQLDMODatabaseRoles IID_IWSQLDMODatabaseRoles

#undef LPSQLDMODATABASEROLE
#undef ISQLDMODatabaseRole
#undef IID_ISQLDMODatabaseRole
interface IWSQLDMODatabaseRole;                             TYPEDEFINTERFACE IWSQLDMODatabaseRole *                                     LPWSQLDMODATABASEROLE;
#define LPSQLDMODATABASEROLE LPWSQLDMODATABASEROLE
#define ISQLDMODatabaseRole IWSQLDMODatabaseRole
#define IID_ISQLDMODatabaseRole IID_IWSQLDMODatabaseRole

#undef LPSQLDMODATABASEROLE2
#undef ISQLDMODatabaseRole2
#undef IID_ISQLDMODatabaseRole2
interface IWSQLDMODatabaseRole2;                             TYPEDEFINTERFACE IWSQLDMODatabaseRole2 *                                     LPWSQLDMODATABASEROLE2;
#define LPSQLDMODATABASEROLE2 LPWSQLDMODATABASEROLE2
#define ISQLDMODatabaseRole2 IWSQLDMODatabaseRole2
#define IID_ISQLDMODatabaseRole2 IID_IWSQLDMODatabaseRole2

#undef LPSQLDMORESTORE
#undef ISQLDMORestore
#undef IID_ISQLDMORestore
interface IWSQLDMORestore;                       TYPEDEFINTERFACE IWSQLDMORestore *                                       LPWSQLDMORESTORE;
#define LPSQLDMORESTORE LPWSQLDMORESTORE
#define ISQLDMORestore IWSQLDMORestore
#define IID_ISQLDMORestore IID_IWSQLDMORestore

#undef LPSQLDMORESTORE2
#undef ISQLDMORestore2
#undef IID_ISQLDMORestore2
interface IWSQLDMORestore2;                       TYPEDEFINTERFACE IWSQLDMORestore2 *                                       LPWSQLDMORESTORE2;
#define LPSQLDMORESTORE2 LPWSQLDMORESTORE2
#define ISQLDMORestore2 IWSQLDMORestore2
#define IID_ISQLDMORestore2 IID_IWSQLDMORestore2

#undef LPSQLDMOLINKEDSERVERS
#undef ISQLDMOLinkedServers
#undef IID_ISQLDMOLinkedServers
interface IWSQLDMOLinkedServers;                TYPEDEFINTERFACE IWSQLDMOLinkedServers *                        LPWSQLDMOLINKEDSERVERS;
#define LPSQLDMOLINKEDSERVERS LPWSQLDMOLINKEDSERVERS
#define ISQLDMOLinkedServers IWSQLDMOLinkedServers
#define IID_ISQLDMOLinkedServers IID_IWSQLDMOLinkedServers

#undef LPSQLDMOLINKEDSERVER
#undef ISQLDMOLinkedServer
#undef IID_ISQLDMOLinkedServer
interface IWSQLDMOLinkedServer;         TYPEDEFINTERFACE IWSQLDMOLinkedServer *                 LPWSQLDMOLINKEDSERVER;
#define LPSQLDMOLINKEDSERVER LPWSQLDMOLINKEDSERVER
#define ISQLDMOLinkedServer IWSQLDMOLinkedServer
#define IID_ISQLDMOLinkedServer IID_IWSQLDMOLinkedServer

#undef LPSQLDMOLINKEDSERVER2
#undef ISQLDMOLinkedServer2
#undef IID_ISQLDMOLinkedServer2
interface IWSQLDMOLinkedServer2;         TYPEDEFINTERFACE IWSQLDMOLinkedServer2 *                 LPWSQLDMOLINKEDSERVER2;
#define LPSQLDMOLINKEDSERVER2 LPWSQLDMOLINKEDSERVER2
#define ISQLDMOLinkedServer2 IWSQLDMOLinkedServer2
#define IID_ISQLDMOLinkedServer2 IID_IWSQLDMOLinkedServer2

#undef LPSQLDMOLINKEDSERVERLOGINS
#undef ISQLDMOLinkedServerLogins
#undef IID_ISQLDMOLinkedServerLogins
interface IWSQLDMOLinkedServerLogins;                TYPEDEFINTERFACE IWSQLDMOLinkedServerLogins *                        LPWSQLDMOLINKEDSERVERLOGINS;
#define LPSQLDMOLINKEDSERVERLOGINS LPWSQLDMOLINKEDSERVERLOGINS
#define ISQLDMOLinkedServerLogins IWSQLDMOLinkedServerLogins
#define IID_ISQLDMOLinkedServerLogins IID_IWSQLDMOLinkedServerLogins

#undef LPSQLDMOLINKEDSERVERLOGIN
#undef ISQLDMOLinkedServerLOGIN
#undef IID_ISQLDMOLinkedServerLogin
interface IWSQLDMOLinkedServerLogin;         TYPEDEFINTERFACE IWSQLDMOLinkedServerLogin *                 LPWSQLDMOLINKEDSERVERLOGIN;
#define LPSQLDMOLINKEDSERVERLOGIN LPWSQLDMOLINKEDSERVERLOGIN
#define ISQLDMOLinkedServerLogin IWSQLDMOLinkedServerLogin
#define IID_ISQLDMOLinkedServerLogin IID_IWSQLDMOLinkedServerLogin

#undef LPSQLDMOFULLTEXTCATALOGS
#undef ISQLDMOFullTextCatalogs
#undef IID_ISQLDMOFullTextCatalogs
interface IWSQLDMOFullTextCatalogs;                    TYPEDEFINTERFACE IWSQLDMOFullTextCatalogs *           LPWSQLDMOFULLTEXTCATALOGS;
#define LPSQLDMOFULLTEXTCATALOGS LPWSQLDMOFULLTEXTCATALOGS
#define ISQLDMOFullTextCatalogs IWSQLDMOFullTextCatalogs
#define IID_ISQLDMOFullTextCatalogs IID_IWSQLDMOFullTextCatalogs

#undef LPSQLDMOFULLTEXTCATALOG
#undef ISQLDMOFullTextCatalog
#undef IID_ISQLDMOFullTextCatalog
interface IWSQLDMOFullTextCatalog;                     TYPEDEFINTERFACE IWSQLDMOFullTextCatalog *             LPWSQLDMOFULLTEXTCATALOG;
#define LPSQLDMOFULLTEXTCATALOG LPWSQLDMOFULLTEXTCATALOG
#define ISQLDMOFullTextCatalog IWSQLDMOFullTextCatalog
#define IID_ISQLDMOFullTextCatalog IID_IWSQLDMOFullTextCatalog

#undef LPSQLDMOFULLTEXTCATALOG2
#undef ISQLDMOFullTextCatalog2
#undef IID_ISQLDMOFullTextCatalog2
interface IWSQLDMOFullTextCatalog2;                     TYPEDEFINTERFACE IWSQLDMOFullTextCatalog2 *             LPWSQLDMOFULLTEXTCATALOG2;
#define LPSQLDMOFULLTEXTCATALOG2 LPWSQLDMOFULLTEXTCATALOG2
#define ISQLDMOFullTextCatalog2 IWSQLDMOFullTextCatalog2
#define IID_ISQLDMOFullTextCatalog2 IID_IWSQLDMOFullTextCatalog2

#undef LPSQLDMOFULLTEXTSERVICE
#undef ISQLDMOFullTextService
#undef IID_ISQLDMOFullTextService
interface IWSQLDMOFullTextService;                     TYPEDEFINTERFACE IWSQLDMOFullTextService *             LPWSQLDMOFULLTEXTSERVICE;
#define LPSQLDMOFULLTEXTSERVICE LPWSQLDMOFULLTEXTSERVICE
#define ISQLDMOFullTextService IWSQLDMOFullTextService
#define IID_ISQLDMOFullTextService IID_IWSQLDMOFullTextService

// 8.0 new objects
#undef LPSQLDMOUSERDEFINEDFUNCTIONS
#undef ISQLDMOUserDefinedFunctions
#undef IID_ISQLDMOUserDefinedFunctions
interface IWSQLDMOUserDefinedFunctions;     TYPEDEFINTERFACE IWSQLDMOUserDefinedFunctions *             LPWSQLDMOUSERDEFINEDFUNCTIONS;
#define LPSQLDMOUSERDEFINEDFUNCTIONS LPWSQLDMOUSERDEFINEDFUNCTIONS
#define ISQLDMOUserDefinedFunctions IWSQLDMOUserDefinedFunctions
#define IID_ISQLDMOUserDefinedFunctions IID_IWSQLDMOUserDefinedFunctions

#undef LPSQLDMOUSERDEFINEDFUNCTION
#undef ISQLDMOUserDefinedFunction
#undef IID_ISQLDMOUserDefinedFunction
interface IWSQLDMOUserDefinedFunction;      TYPEDEFINTERFACE IWSQLDMOUserDefinedFunction *              LPWSQLDMOUSERDEFINEDFUNCTION;
#define LPSQLDMOUSERDEFINEDFUNCTION LPWSQLDMOUSERDEFINEDFUNCTION
#define ISQLDMOUserDefinedFunction IWSQLDMOUserDefinedFunction
#define IID_ISQLDMOUserDefinedFunction IID_IWSQLDMOUserDefinedFunction

////////////////////////////////////////////////////////////////////////////////////////
// Event Sink Interfaces
////////////////////////////////////////////////////////////////////////////////////////
#undef LPSQLDMOTRANSFERSINK
#undef ISQLDMOTransferSink
#undef IID_ISQLDMOTransferSink
interface IWSQLDMOTransferSink;                                         TYPEDEFINTERFACE IWSQLDMOTransferSink *                         LPWSQLDMOTRANSFERSINK;
#define LPSQLDMOTRANSFERSINK LPWSQLDMOTRANSFERSINK
#define ISQLDMOTransferSink IWSQLDMOTransferSink
#define IID_ISQLDMOTransferSink IID_IWSQLDMOTransferSink

#undef LPSQLDMOSERVERSINK
#undef ISQLDMOServerSink
#undef IID_ISQLDMOServerSink
interface IWSQLDMOServerSink;                                           TYPEDEFINTERFACE IWSQLDMOServerSink *                           LPWSQLDMOSERVERSINK;
#define LPSQLDMOSERVERSINK LPWSQLDMOSERVERSINK
#define ISQLDMOServerSink IWSQLDMOServerSink
#define IID_ISQLDMOServerSink IID_IWSQLDMOServerSink

#undef LPSQLDMOBACKUPSINK
#undef ISQLDMOBackupSink
#undef IID_ISQLDMOBackupSink
interface IWSQLDMOBackupSink;                                           TYPEDEFINTERFACE IWSQLDMOBackupSink *                           LPWSQLDMOBACKUPSINK;
#define LPSQLDMOBACKUPSINK LPWSQLDMOBACKUPSINK
#define ISQLDMOBackupSink IWSQLDMOBackupSink
#define IID_ISQLDMOBackupSink IID_IWSQLDMOBackupSink

#undef LPSQLDMOBULKCOPYSINK
#undef ISQLDMOBulkCopySink
#undef IID_ISQLDMOBulkCopySink
interface IWSQLDMOBulkCopySink;                                         TYPEDEFINTERFACE IWSQLDMOBulkCopySink *                         LPWSQLDMOBULKCOPYSINK;
#define LPSQLDMOBULKCOPYSINK LPWSQLDMOBULKCOPYSINK
#define ISQLDMOBulkCopySink IWSQLDMOBulkCopySink
#define IID_ISQLDMOBulkCopySink IID_IWSQLDMOBulkCopySink

// 7.0 new sink objects
#undef LPSQLDMORESTORESINK
#undef ISQLDMORestoreSink
#undef IID_ISQLDMORestoreSink
interface IWSQLDMORestoreSink;                                           TYPEDEFINTERFACE IWSQLDMORestoreSink *                           LPWSQLDMORESTORESINK;
#define LPSQLDMORESTORESINK LPWSQLDMORESTORESINK
#define ISQLDMORestoreSink IWSQLDMORestoreSink
#define IID_ISQLDMORestoreSink IID_IWSQLDMORestoreSink

// Auto-documenting names for these... They return an LPSQLDMOOBJECTLIST
// of the specified <objecttype>LIST objects.. e.g. LPSQLDMOCOLUMNLIST
// returns a list of LPSQLDMOCOLUMN objects.
#undef LPSQLDMODBOBJECTLIST
#define LPSQLDMODBOBJECTLIST LPSQLDMOOBJECTLIST
#define LPWSQLDMODBOBJECTLIST LPWSQLDMOOBJECTLIST
#define LPASQLDMODBOBJECTLIST LPASQLDMOOBJECTLIST
#undef LPSQLDMOPERMISSIONLIST
#define LPSQLDMOPERMISSIONLIST LPSQLDMOOBJECTLIST
#define LPWSQLDMOPERMISSIONLIST LPWSQLDMOOBJECTLIST
#define LPASQLDMOPERMISSIONLIST LPASQLDMOOBJECTLIST
#undef LPSQLDMOCONFIGVALUELIST
#define LPSQLDMOCONFIGVALUELIST LPSQLDMOOBJECTLIST
#define LPWSQLDMOCONFIGVALUELIST LPWSQLDMOOBJECTLIST
#define LPASQLDMOCONFIGVALUELIST LPASQLDMOOBJECTLIST
#undef LPSQLDMOBACKUPDEVICELIST
#define LPSQLDMOBACKUPDEVICELIST LPSQLDMOOBJECTLIST
#define LPWSQLDMOBACKUPDEVICELIST LPWSQLDMOOBJECTLIST
#define LPASQLDMOBACKUPDEVICELIST LPASQLDMOOBJECTLIST
#undef LPSQLDMOCOLUMNLIST
#define LPSQLDMOCOLUMNLIST LPSQLDMOOBJECTLIST
#define LPWSQLDMOCOLUMNLIST LPWSQLDMOOBJECTLIST
#define LPASQLDMOCOLUMNLIST LPASQLDMOOBJECTLIST
#undef LPSQLDMOUSERDEFINEDDATATYPELIST
#define LPSQLDMOUSERDEFINEDDATATYPELIST LPSQLDMOOBJECTLIST
#define LPWSQLDMOUSERDEFINEDDATATYPELIST LPWSQLDMOOBJECTLIST
#define LPASQLDMOUSERDEFINEDDATATYPELIST LPASQLDMOOBJECTLIST
#undef LPSQLDMOSTOREDPROCEDURELIST
#define LPSQLDMOSTOREDPROCEDURELIST LPSQLDMOOBJECTLIST
#define LPWSQLDMOSTOREDPROCEDURELIST LPWSQLDMOOBJECTLIST
#define LPASQLDMOSTOREDPROCEDURELIST LPASQLDMOOBJECTLIST
#undef LPSQLDMOLOGINLIST
#define LPSQLDMOLOGINLIST LPSQLDMOOBJECTLIST
#define LPWSQLDMOLOGINLIST LPWSQLDMOOBJECTLIST
#define LPASQLDMOLOGINLIST LPASQLDMOOBJECTLIST
#undef LPSQLDMOUSERLIST
#define LPSQLDMOUSERLIST LPSQLDMOOBJECTLIST
#define LPWSQLDMOUSERLIST LPWSQLDMOOBJECTLIST
#define LPASQLDMOUSERLIST LPASQLDMOOBJECTLIST
#undef LPSQLDMODATABASELIST
#define LPSQLDMODATABASELIST LPSQLDMOOBJECTLIST
#define LPWSQLDMODATABASELIST LPWSQLDMOOBJECTLIST
#define LPASQLDMODATABASELIST LPASQLDMOOBJECTLIST
#undef LPSQLDMOKEYLIST
#define LPSQLDMOKEYLIST LPSQLDMOOBJECTLIST
#define LPWSQLDMOKEYLIST LPWSQLDMOOBJECTLIST
#define LPASQLDMOKEYLIST LPASQLDMOOBJECTLIST






#undef LPSQLDMOTRANSPUBLICATIONS
#undef ISQLDMOTransPublications
#undef IID_ISQLDMOTransPublications
interface IWSQLDMOTransPublications;			TYPEDEFINTERFACE IWSQLDMOTransPublications *					LPWSQLDMOTRANSPUBLICATIONS;
#define LPSQLDMOTRANSPUBLICATIONS LPWSQLDMOTRANSPUBLICATIONS
#define ISQLDMOTransPublications IWSQLDMOTransPublications
#define IID_ISQLDMOTransPublications IID_IWSQLDMOTransPublications

#undef LPSQLDMOTRANSPUBLICATION
#undef ISQLDMOTransPublication
#undef IID_ISQLDMOTransPublication
interface IWSQLDMOTransPublication;				TYPEDEFINTERFACE IWSQLDMOTransPublication *					LPWSQLDMOTRANSPUBLICATION;
#define LPSQLDMOTRANSPUBLICATION LPWSQLDMOTRANSPUBLICATION
#define ISQLDMOTransPublication IWSQLDMOTransPublication
#define IID_ISQLDMOTransPublication IID_IWSQLDMOTransPublication

#undef LPSQLDMOTRANSPUBLICATION2
#undef ISQLDMOTransPublication2
#undef IID_ISQLDMOTransPublication2
interface IWSQLDMOTransPublication2;				TYPEDEFINTERFACE IWSQLDMOTransPublication2 *					LPWSQLDMOTRANSPUBLICATION2;
#define LPSQLDMOTRANSPUBLICATION2 LPWSQLDMOTRANSPUBLICATION2
#define ISQLDMOTransPublication2 IWSQLDMOTransPublication2
#define IID_ISQLDMOTransPublication2 IID_IWSQLDMOTransPublication2

#undef LPSQLDMOTRANSARTICLES
#undef ISQLDMOTransArticles
#undef IID_ISQLDMOTransArticles
interface IWSQLDMOTransArticles;			TYPEDEFINTERFACE IWSQLDMOTransArticles *					LPWSQLDMOTRANSARTICLES;
#define LPSQLDMOTRANSARTICLES LPWSQLDMOTRANSARTICLES
#define ISQLDMOTransArticles IWSQLDMOTransArticles
#define IID_ISQLDMOTransArticles IID_IWSQLDMOTransArticles

#undef LPSQLDMOTRANSARTICLE
#undef ISQLDMOTransArticle
#undef IID_ISQLDMOTransArticle
interface IWSQLDMOTransArticle;				TYPEDEFINTERFACE IWSQLDMOTransArticle *					LPWSQLDMOTRANSARTICLE;
#define LPSQLDMOTRANSARTICLE LPWSQLDMOTRANSARTICLE
#define ISQLDMOTransArticle IWSQLDMOTransArticle
#define IID_ISQLDMOTransArticle IID_IWSQLDMOTransArticle

#undef LPSQLDMOTRANSARTICLE2
#undef ISQLDMOTransArticle2
#undef IID_ISQLDMOTransArticle2
interface IWSQLDMOTransArticle2;				TYPEDEFINTERFACE IWSQLDMOTransArticle2 *					LPWSQLDMOTRANSARTICLE2;
#define LPSQLDMOTRANSARTICLE2 LPWSQLDMOTRANSARTICLE2
#define ISQLDMOTransArticle2 IWSQLDMOTransArticle2
#define IID_ISQLDMOTransArticle2 IID_IWSQLDMOTransArticle2

#undef LPSQLDMOTRANSSUBSCRIPTIONS
#undef ISQLDMOTransSubscriptions
#undef IID_ISQLDMOTransSubscriptions
interface IWSQLDMOTransSubscriptions;			TYPEDEFINTERFACE IWSQLDMOTransSubscriptions *					LPWSQLDMOTRANSSUBSCRIPTIONS;
#define LPSQLDMOTRANSSUBSCRIPTIONS LPWSQLDMOTRANSSUBSCRIPTIONS
#define ISQLDMOTransSubscriptions IWSQLDMOTransSubscriptions
#define IID_ISQLDMOTransSubscriptions IID_IWSQLDMOTransSubscriptions

#undef LPSQLDMOTRANSSUBSCRIPTION
#undef ISQLDMOTransSubscription
#undef IID_ISQLDMOTransSubscription
interface IWSQLDMOTransSubscription;				TYPEDEFINTERFACE IWSQLDMOTransSubscription *					LPWSQLDMOTRANSSUBSCRIPTION;
#define LPSQLDMOTRANSSUBSCRIPTION LPWSQLDMOTRANSSUBSCRIPTION
#define ISQLDMOTransSubscription IWSQLDMOTransSubscription
#define IID_ISQLDMOTransSubscription IID_IWSQLDMOTransSubscription

#undef LPSQLDMOTRANSSUBSCRIPTION2
#undef ISQLDMOTransSubscription2
#undef IID_ISQLDMOTransSubscription2
interface IWSQLDMOTransSubscription2;				TYPEDEFINTERFACE IWSQLDMOTransSubscription2 *					LPWSQLDMOTRANSSUBSCRIPTION2;
#define LPSQLDMOTRANSSUBSCRIPTION2 LPWSQLDMOTRANSSUBSCRIPTION2
#define ISQLDMOTransSubscription2 IWSQLDMOTransSubscription2
#define IID_ISQLDMOTransSubscription2 IID_IWSQLDMOTransSubscription2

#undef LPSQLDMOTRANSPULLSUBSCRIPTIONS
#undef ISQLDMOTransPullSubscriptions
#undef IID_ISQLDMOTransPullSubscriptions
interface IWSQLDMOTransPullSubscriptions;			TYPEDEFINTERFACE IWSQLDMOTransPullSubscriptions *					LPWSQLDMOTRANSPULLSUBSCRIPTIONS;
#define LPSQLDMOTRANSPULLSUBSCRIPTIONS LPWSQLDMOTRANSPULLSUBSCRIPTIONS
#define ISQLDMOTransPullSubscriptions IWSQLDMOTransPullSubscriptions
#define IID_ISQLDMOTransPullSubscriptions IID_IWSQLDMOTransPullSubscriptions

#undef LPSQLDMOTRANSPULLSUBSCRIPTION
#undef ISQLDMOTransPullSubscription
#undef IID_ISQLDMOTransPullSubscription
interface IWSQLDMOTransPullSubscription;				TYPEDEFINTERFACE IWSQLDMOTransPullSubscription *					LPWSQLDMOTRANSPULLSUBSCRIPTION;
#define LPSQLDMOTRANSPULLSUBSCRIPTION LPWSQLDMOTRANSPULLSUBSCRIPTION
#define ISQLDMOTransPullSubscription IWSQLDMOTransPullSubscription
#define IID_ISQLDMOTransPullSubscription IID_IWSQLDMOTransPullSubscription

#undef LPSQLDMOTRANSPULLSUBSCRIPTION2
#undef ISQLDMOTransPullSubscription2
#undef IID_ISQLDMOTransPullSubscription2
interface IWSQLDMOTransPullSubscription2;				TYPEDEFINTERFACE IWSQLDMOTransPullSubscription2 *					LPWSQLDMOTRANSPULLSUBSCRIPTION2;
#define LPSQLDMOTRANSPULLSUBSCRIPTION2 LPWSQLDMOTRANSPULLSUBSCRIPTION2
#define ISQLDMOTransPullSubscription2 IWSQLDMOTransPullSubscription2
#define IID_ISQLDMOTransPullSubscription2 IID_IWSQLDMOTransPullSubscription2

#undef LPSQLDMOMERGEPUBLICATIONS
#undef ISQLDMOMergePublications
#undef IID_ISQLDMOMergePublications
interface IWSQLDMOMergePublications;			TYPEDEFINTERFACE IWSQLDMOMergePublications *					LPWSQLDMOMERGEPUBLICATIONS;
#define LPSQLDMOMERGEPUBLICATIONS LPWSQLDMOMERGEPUBLICATIONS
#define ISQLDMOMergePublications IWSQLDMOMergePublications
#define IID_ISQLDMOMergePublications IID_IWSQLDMOMergePublications

#undef LPSQLDMOMERGEPUBLICATION
#undef ISQLDMOMergePublication
#undef IID_ISQLDMOMergePublication
interface IWSQLDMOMergePublication;				TYPEDEFINTERFACE IWSQLDMOMergePublication *					LPWSQLDMOMERGEPUBLICATION;
#define LPSQLDMOMERGEPUBLICATION LPWSQLDMOMERGEPUBLICATION
#define ISQLDMOMergePublication IWSQLDMOMergePublication
#define IID_ISQLDMOMergePublication IID_IWSQLDMOMergePublication

#undef LPSQLDMOMERGEPUBLICATION2
#undef ISQLDMOMergePublication2
#undef IID_ISQLDMOMergePublication2
interface IWSQLDMOMergePublication2;				TYPEDEFINTERFACE IWSQLDMOMergePublication2 *					LPWSQLDMOMERGEPUBLICATION2;
#define LPSQLDMOMERGEPUBLICATION2 LPWSQLDMOMERGEPUBLICATION2
#define ISQLDMOMergePublication2 IWSQLDMOMergePublication2
#define IID_ISQLDMOMergePublication2 IID_IWSQLDMOMergePublication2

#undef LPSQLDMOMERGEARTICLES
#undef ISQLDMOMergeArticles
#undef IID_ISQLDMOMergeArticles
interface IWSQLDMOMergeArticles;			TYPEDEFINTERFACE IWSQLDMOMergeArticles *					LPWSQLDMOMERGEARTICLES;
#define LPSQLDMOMERGEARTICLES LPWSQLDMOMERGEARTICLES
#define ISQLDMOMergeArticles IWSQLDMOMergeArticles
#define IID_ISQLDMOMergeArticles IID_IWSQLDMOMergeArticles

#undef LPSQLDMOMERGEARTICLE
#undef ISQLDMOMergeArticle
#undef IID_ISQLDMOMergeArticle
interface IWSQLDMOMergeArticle;				TYPEDEFINTERFACE IWSQLDMOMergeArticle *					LPWSQLDMOMERGEARTICLE;
#define LPSQLDMOMERGEARTICLE LPWSQLDMOMERGEARTICLE
#define ISQLDMOMergeArticle IWSQLDMOMergeArticle
#define IID_ISQLDMOMergeArticle IID_IWSQLDMOMergeArticle

#undef LPSQLDMOMERGEARTICLE2
#undef ISQLDMOMergeArticle2
#undef IID_ISQLDMOMergeArticle2
interface IWSQLDMOMergeArticle2;				TYPEDEFINTERFACE IWSQLDMOMergeArticle2 *					LPWSQLDMOMERGEARTICLE2;
#define LPSQLDMOMERGEARTICLE2 LPWSQLDMOMERGEARTICLE2
#define ISQLDMOMergeArticle2 IWSQLDMOMergeArticle2
#define IID_ISQLDMOMergeArticle2 IID_IWSQLDMOMergeArticle2

#undef LPSQLDMOMERGESUBSCRIPTIONS
#undef ISQLDMOMergeSubscriptions
#undef IID_ISQLDMOMergeSubscriptions
interface IWSQLDMOMergeSubscriptions;			TYPEDEFINTERFACE IWSQLDMOMergeSubscriptions *					LPWSQLDMOMERGESUBSCRIPTIONS;
#define LPSQLDMOMERGESUBSCRIPTIONS LPWSQLDMOMERGESUBSCRIPTIONS
#define ISQLDMOMergeSubscriptions IWSQLDMOMergeSubscriptions
#define IID_ISQLDMOMergeSubscriptions IID_IWSQLDMOMergeSubscriptions

#undef LPSQLDMOMERGESUBSCRIPTION
#undef ISQLDMOMergeSubscription
#undef IID_ISQLDMOMergeSubscription
interface IWSQLDMOMergeSubscription;				TYPEDEFINTERFACE IWSQLDMOMergeSubscription *					LPWSQLDMOMERGESUBSCRIPTION;
#define LPSQLDMOMERGESUBSCRIPTION LPWSQLDMOMERGESUBSCRIPTION
#define ISQLDMOMergeSubscription IWSQLDMOMergeSubscription
#define IID_ISQLDMOMergeSubscription IID_IWSQLDMOMergeSubscription

#undef LPSQLDMOMERGESUBSCRIPTION2
#undef ISQLDMOMergeSubscription2
#undef IID_ISQLDMOMergeSubscription2
interface IWSQLDMOMergeSubscription2;				TYPEDEFINTERFACE IWSQLDMOMergeSubscription2 *					LPWSQLDMOMERGESUBSCRIPTION2;
#define LPSQLDMOMERGESUBSCRIPTION2 LPWSQLDMOMERGESUBSCRIPTION2
#define ISQLDMOMergeSubscription2 IWSQLDMOMergeSubscription2
#define IID_ISQLDMOMergeSubscription2 IID_IWSQLDMOMergeSubscription2

#undef LPSQLDMOMERGEPULLSUBSCRIPTIONS
#undef ISQLDMOMergePullSubscriptions
#undef IID_ISQLDMOMergePullSubscriptions
interface IWSQLDMOMergePullSubscriptions;			TYPEDEFINTERFACE IWSQLDMOMergePullSubscriptions *					LPWSQLDMOMERGEPULLSUBSCRIPTIONS;
#define LPSQLDMOMERGEPULLSUBSCRIPTIONS LPWSQLDMOMERGEPULLSUBSCRIPTIONS
#define ISQLDMOMergePullSubscriptions IWSQLDMOMergePullSubscriptions
#define IID_ISQLDMOMergePullSubscriptions IID_IWSQLDMOMergePullSubscriptions

#undef LPSQLDMOMERGEPULLSUBSCRIPTION
#undef ISQLDMOMergePullSubscription
#undef IID_ISQLDMOMergePullSubscription
interface IWSQLDMOMergePullSubscription;				TYPEDEFINTERFACE IWSQLDMOMergePullSubscription *					LPWSQLDMOMERGEPULLSUBSCRIPTION;
#define LPSQLDMOMERGEPULLSUBSCRIPTION LPWSQLDMOMERGEPULLSUBSCRIPTION
#define ISQLDMOMergePullSubscription IWSQLDMOMergePullSubscription
#define IID_ISQLDMOMergePullSubscription IID_IWSQLDMOMergePullSubscription

#undef LPSQLDMOMERGEPULLSUBSCRIPTION2
#undef ISQLDMOMergePullSubscription2
#undef IID_ISQLDMOMergePullSubscription2
interface IWSQLDMOMergePullSubscription2;				TYPEDEFINTERFACE IWSQLDMOMergePullSubscription2 *					LPWSQLDMOMERGEPULLSUBSCRIPTION2;
#define LPSQLDMOMERGEPULLSUBSCRIPTION2 LPWSQLDMOMERGEPULLSUBSCRIPTION2
#define ISQLDMOMergePullSubscription2 IWSQLDMOMergePullSubscription2
#define IID_ISQLDMOMergePullSubscription2 IID_IWSQLDMOMergePullSubscription2

#undef LPSQLDMOMERGESUBSETFILTERS
#undef ISQLDMOMergeSubsetFilters
#undef IID_ISQLDMOMergeSubsetFilters
interface IWSQLDMOMergeSubsetFilters;			TYPEDEFINTERFACE IWSQLDMOMergeSubsetFilters *					LPWSQLDMOMERGESUBSETFILTERS;
#define LPSQLDMOMERGESUBSETFILTERS LPWSQLDMOMERGESUBSETFILTERS
#define ISQLDMOMergeSubsetFilters IWSQLDMOMergeSubsetFilters
#define IID_ISQLDMOMergeSubsetFilters IID_IWSQLDMOMergeSubsetFilters

#undef LPSQLDMOMERGESUBSETFILTER
#undef ISQLDMOMergeSubsetFilter
#undef IID_ISQLDMOMergeSubsetFilter
interface IWSQLDMOMergeSubsetFilter;				TYPEDEFINTERFACE IWSQLDMOMergeSubsetFilter *					LPWSQLDMOMERGESUBSETFILTER;
#define LPSQLDMOMERGESUBSETFILTER LPWSQLDMOMERGESUBSETFILTER
#define ISQLDMOMergeSubsetFilter IWSQLDMOMergeSubsetFilter
#define IID_ISQLDMOMergeSubsetFilter IID_IWSQLDMOMergeSubsetFilter

#undef LPSQLDMOREPLICATION
#undef ISQLDMOReplication
#undef IID_ISQLDMOReplication
interface IWSQLDMOReplication;				TYPEDEFINTERFACE IWSQLDMOReplication *					LPWSQLDMOREPLICATION;
#define LPSQLDMOREPLICATION LPWSQLDMOREPLICATION
#define ISQLDMOReplication IWSQLDMOReplication
#define IID_ISQLDMOReplication IID_IWSQLDMOReplication

#undef LPSQLDMOREPLICATION2
#undef ISQLDMOReplication2
#undef IID_ISQLDMOReplication2
interface IWSQLDMOReplication2;				TYPEDEFINTERFACE IWSQLDMOReplication2 *					LPWSQLDMOREPLICATION2;
#define LPSQLDMOREPLICATION2 LPWSQLDMOREPLICATION2
#define ISQLDMOReplication2 IWSQLDMOReplication2
#define IID_ISQLDMOReplication2 IID_IWSQLDMOReplication2

#undef LPSQLDMOPUBLISHER
#undef ISQLDMOPublisher
#undef IID_ISQLDMOPublisher
interface IWSQLDMOPublisher;				TYPEDEFINTERFACE IWSQLDMOPublisher *					LPWSQLDMOPUBLISHER;
#define LPSQLDMOPUBLISHER LPWSQLDMOPUBLISHER
#define ISQLDMOPublisher IWSQLDMOPublisher
#define IID_ISQLDMOPublisher IID_IWSQLDMOPublisher

#undef LPSQLDMOPUBLISHER2
#undef ISQLDMOPublisher2
#undef IID_ISQLDMOPublisher2
interface IWSQLDMOPublisher2;				TYPEDEFINTERFACE IWSQLDMOPublisher2 *					LPWSQLDMOPUBLISHER2;
#define LPSQLDMOPUBLISHER2 LPWSQLDMOPUBLISHER2
#define ISQLDMOPublisher2 IWSQLDMOPublisher2
#define IID_ISQLDMOPublisher2 IID_IWSQLDMOPublisher2

#undef LPSQLDMOSUBSCRIBER
#undef ISQLDMOSubscriber
#undef IID_ISQLDMOSubscriber
interface IWSQLDMOSubscriber;				TYPEDEFINTERFACE IWSQLDMOSubscriber *					LPWSQLDMOSUBSCRIBER;
#define LPSQLDMOSUBSCRIBER LPWSQLDMOSUBSCRIBER
#define ISQLDMOSubscriber IWSQLDMOSubscriber
#define IID_ISQLDMOSubscriber IID_IWSQLDMOSubscriber

#undef LPSQLDMOSUBSCRIBER2
#undef ISQLDMOSubscriber2
#undef IID_ISQLDMOSubscriber2
interface IWSQLDMOSubscriber2;				TYPEDEFINTERFACE IWSQLDMOSubscriber2 *					LPWSQLDMOSUBSCRIBER2;
#define LPSQLDMOSUBSCRIBER2 LPWSQLDMOSUBSCRIBER2
#define ISQLDMOSubscriber2 IWSQLDMOSubscriber2
#define IID_ISQLDMOSubscriber2 IID_IWSQLDMOSubscriber2

#undef LPSQLDMODISTRIBUTOR
#undef ISQLDMODistributor
#undef IID_ISQLDMODistributor
interface IWSQLDMODistributor;				TYPEDEFINTERFACE IWSQLDMODistributor *					LPWSQLDMODISTRIBUTOR;
#define LPSQLDMODISTRIBUTOR LPWSQLDMODISTRIBUTOR
#define ISQLDMODistributor IWSQLDMODistributor
#define IID_ISQLDMODistributor IID_IWSQLDMODistributor

#undef LPSQLDMODISTRIBUTOR2
#undef ISQLDMODistributor2
#undef IID_ISQLDMODistributor2
interface IWSQLDMODistributor2;				TYPEDEFINTERFACE IWSQLDMODistributor2 *					LPWSQLDMODISTRIBUTOR2;
#define LPSQLDMODISTRIBUTOR2 LPWSQLDMODISTRIBUTOR2
#define ISQLDMODistributor2 IWSQLDMODistributor2
#define IID_ISQLDMODistributor2 IID_IWSQLDMODistributor2

#undef LPSQLDMOREPLICATIONSECURITY
#undef ISQLDMOReplicationSecurity
#undef IID_ISQLDMOReplicationSecurity
interface IWSQLDMOReplicationSecurity;				TYPEDEFINTERFACE IWSQLDMOReplicationSecurity *					LPWSQLDMOREPLICATIONSECURITY;
#define LPSQLDMOREPLICATIONSECURITY LPWSQLDMOREPLICATIONSECURITY
#define ISQLDMOReplicationSecurity IWSQLDMOReplicationSecurity
#define IID_ISQLDMOReplicationSecurity IID_IWSQLDMOReplicationSecurity

#undef LPSQLDMOREGISTEREDSUBSCRIBER
#undef ISQLDMORegisteredSubscriber
#undef IID_ISQLDMORegisteredSubscriber
interface IWSQLDMORegisteredSubscriber;				TYPEDEFINTERFACE IWSQLDMORegisteredSubscriber *					LPWSQLDMOREGISTEREDSUBSCRIBER;
#define LPSQLDMOREGISTEREDSUBSCRIBER LPWSQLDMOREGISTEREDSUBSCRIBER
#define ISQLDMORegisteredSubscriber IWSQLDMORegisteredSubscriber
#define IID_ISQLDMORegisteredSubscriber IID_IWSQLDMORegisteredSubscriber

#undef LPSQLDMOREGISTEREDSUBSCRIBERS
#undef ISQLDMORegisteredSubscribers
#undef IID_ISQLDMORegisteredSubscribers
interface IWSQLDMORegisteredSubscribers;				TYPEDEFINTERFACE IWSQLDMORegisteredSubscribers *					LPWSQLDMOREGISTEREDSUBSCRIBERS;
#define LPSQLDMOREGISTEREDSUBSCRIBERS LPWSQLDMOREGISTEREDSUBSCRIBERS
#define ISQLDMORegisteredSubscribers IWSQLDMORegisteredSubscribers
#define IID_ISQLDMORegisteredSubscribers IID_IWSQLDMORegisteredSubscribers

#undef LPSQLDMOREPLICATIONDATABASE
#undef ISQLDMOReplicationDatabase
#undef IID_ISQLDMOReplicationDatabase
interface IWSQLDMOReplicationDatabase;			TYPEDEFINTERFACE IWSQLDMOReplicationDatabase *				LPWSQLDMOREPLICATIONDATABASE;
#define LPSQLDMOREPLICATIONDATABASE LPWSQLDMOREPLICATIONDATABASE
#define ISQLDMOReplicationDatabase IWSQLDMOReplicationDatabase
#define IID_ISQLDMOReplicationDatabase IID_IWSQLDMOReplicationDatabase

#undef LPSQLDMOREPLICATIONDATABASE2
#undef ISQLDMOReplicationDatabase2
#undef IID_ISQLDMOReplicationDatabase2
interface IWSQLDMOReplicationDatabase2;			TYPEDEFINTERFACE IWSQLDMOReplicationDatabase2 *				LPWSQLDMOREPLICATIONDATABASE2;
#define LPSQLDMOREPLICATIONDATABASE2 LPWSQLDMOREPLICATIONDATABASE2
#define ISQLDMOReplicationDatabase2 IWSQLDMOReplicationDatabase2
#define IID_ISQLDMOReplicationDatabase2 IID_IWSQLDMOReplicationDatabase2

#undef LPSQLDMOREPLICATIONDATABASES
#undef ISQLDMOReplicationDatabases
#undef IID_ISQLDMOReplicationDatabases
interface IWSQLDMOReplicationDatabases;			TYPEDEFINTERFACE IWSQLDMOReplicationDatabases *				LPWSQLDMOREPLICATIONDATABASES;
#define LPSQLDMOREPLICATIONDATABASES LPWSQLDMOREPLICATIONDATABASES
#define ISQLDMOReplicationDatabases IWSQLDMOReplicationDatabases
#define IID_ISQLDMOReplicationDatabases IID_IWSQLDMOReplicationDatabases

#undef LPSQLDMODISTRIBUTIONPUBLISHER
#undef ISQLDMODistributionPublisher
#undef IID_ISQLDMODistributionPublisher
interface IWSQLDMODistributionPublisher;				TYPEDEFINTERFACE IWSQLDMODistributionPublisher *					LPWSQLDMODISTRIBUTIONPUBLISHER;
#define LPSQLDMODISTRIBUTIONPUBLISHER LPWSQLDMODISTRIBUTIONPUBLISHER
#define ISQLDMODistributionPublisher IWSQLDMODistributionPublisher
#define IID_ISQLDMODistributionPublisher IID_IWSQLDMODistributionPublisher

#undef LPSQLDMODISTRIBUTIONPUBLISHER2
#undef ISQLDMODistributionPublisher2
#undef IID_ISQLDMODistributionPublisher2
interface IWSQLDMODistributionPublisher2;				TYPEDEFINTERFACE IWSQLDMODistributionPublisher2 *					LPWSQLDMODISTRIBUTIONPUBLISHER2;
#define LPSQLDMODISTRIBUTIONPUBLISHER2 LPWSQLDMODISTRIBUTIONPUBLISHER2
#define ISQLDMODistributionPublisher2 IWSQLDMODistributionPublisher2
#define IID_ISQLDMODistributionPublisher2 IID_IWSQLDMODistributionPublisher2

#undef LPSQLDMODISTRIBUTIONPUBLISHERS
#undef ISQLDMODistributionPublishers
#undef IID_ISQLDMODistributionPublishers
interface IWSQLDMODistributionPublishers;				TYPEDEFINTERFACE IWSQLDMODistributionPublishers *					LPWSQLDMODISTRIBUTIONPUBLISHERS;
#define LPSQLDMODISTRIBUTIONPUBLISHERS LPWSQLDMODISTRIBUTIONPUBLISHERS
#define ISQLDMODistributionPublishers IWSQLDMODistributionPublishers
#define IID_ISQLDMODistributionPublishers IID_IWSQLDMODistributionPublishers

#undef LPSQLDMODISTRIBUTIONDATABASE
#undef ISQLDMODistributionDatabase
#undef IID_ISQLDMODistributionDatabase
interface IWSQLDMODistributionDatabase;				TYPEDEFINTERFACE IWSQLDMODistributionDatabase *					LPWSQLDMODISTRIBUTIONDATABASE;
#define LPSQLDMODISTRIBUTIONDATABASE LPWSQLDMODISTRIBUTIONDATABASE
#define ISQLDMODistributionDatabase IWSQLDMODistributionDatabase
#define IID_ISQLDMODistributionDatabase IID_IWSQLDMODistributionDatabase

#undef LPSQLDMODISTRIBUTIONDATABASE2
#undef ISQLDMODistributionDatabase2
#undef IID_ISQLDMODistributionDatabase2
interface IWSQLDMODistributionDatabase2;				TYPEDEFINTERFACE IWSQLDMODistributionDatabase2 *					LPWSQLDMODISTRIBUTIONDATABASE2;
#define LPSQLDMODISTRIBUTIONDATABASE2 LPWSQLDMODISTRIBUTIONDATABASE2
#define ISQLDMODistributionDatabase2 IWSQLDMODistributionDatabase2
#define IID_ISQLDMODistributionDatabase2 IID_IWSQLDMODistributionDatabase2

#undef LPSQLDMODISTRIBUTIONDATABASES
#undef ISQLDMODistributionDatabases
#undef IID_ISQLDMODistributionDatabases
interface IWSQLDMODistributionDatabases;				TYPEDEFINTERFACE IWSQLDMODistributionDatabases *					LPWSQLDMODISTRIBUTIONDATABASES;
#define LPSQLDMODISTRIBUTIONDATABASES LPWSQLDMODISTRIBUTIONDATABASES
#define ISQLDMODistributionDatabases IWSQLDMODistributionDatabases
#define IID_ISQLDMODistributionDatabases IID_IWSQLDMODistributionDatabases

#undef LPSQLDMOREPLICATIONTABLE
#undef ISQLDMOReplicationTable
#undef IID_ISQLDMOReplicationTable
interface IWSQLDMOReplicationTable;			TYPEDEFINTERFACE IWSQLDMOReplicationTable *				LPWSQLDMOREPLICATIONTABLE;
#define LPSQLDMOREPLICATIONTABLE LPWSQLDMOREPLICATIONTABLE
#define ISQLDMOReplicationTable IWSQLDMOReplicationTable
#define IID_ISQLDMOReplicationTable IID_IWSQLDMOReplicationTable

#undef LPSQLDMOREPLICATIONTABLE2
#undef ISQLDMOReplicationTable2
#undef IID_ISQLDMOReplicationTable2
interface IWSQLDMOReplicationTable2;			TYPEDEFINTERFACE IWSQLDMOReplicationTable2 *				LPWSQLDMOREPLICATIONTABLE2;
#define LPSQLDMOREPLICATIONTABLE2 LPWSQLDMOREPLICATIONTABLE2
#define ISQLDMOReplicationTable2 IWSQLDMOReplicationTable2
#define IID_ISQLDMOReplicationTable2 IID_IWSQLDMOReplicationTable2

#undef LPSQLDMOREPLICATIONTABLES
#undef ISQLDMOReplicationTables
#undef IID_ISQLDMOReplicationTables
interface IWSQLDMOReplicationTables;			TYPEDEFINTERFACE IWSQLDMOReplicationTables *				LPWSQLDMOREPLICATIONTABLES;
#define LPSQLDMOREPLICATIONTABLES LPWSQLDMOREPLICATIONTABLES
#define ISQLDMOReplicationTables IWSQLDMOReplicationTables
#define IID_ISQLDMOReplicationTables IID_IWSQLDMOReplicationTables

#undef LPSQLDMOREPLICATIONSTOREDPROCEDURE
#undef ISQLDMOReplicationStoredProcedure
#undef IID_ISQLDMOReplicationStoredProcedure
interface IWSQLDMOReplicationStoredProcedure;			TYPEDEFINTERFACE IWSQLDMOReplicationStoredProcedure *				LPWSQLDMOREPLICATIONSTOREDPROCEDURE;
#define LPSQLDMOREPLICATIONSTOREDPROCEDURE LPWSQLDMOREPLICATIONSTOREDPROCEDURE
#define ISQLDMOReplicationStoredProcedure IWSQLDMOReplicationStoredProcedure
#define IID_ISQLDMOReplicationStoredProcedure IID_IWSQLDMOReplicationStoredProcedure

#undef LPSQLDMOREPLICATIONSTOREDPROCEDURE2
#undef ISQLDMOReplicationStoredProcedure2
#undef IID_ISQLDMOReplicationStoredProcedure2
interface IWSQLDMOReplicationStoredProcedure2;			TYPEDEFINTERFACE IWSQLDMOReplicationStoredProcedure2 *				LPWSQLDMOREPLICATIONSTOREDPROCEDURE2;
#define LPSQLDMOREPLICATIONSTOREDPROCEDURE2 LPWSQLDMOREPLICATIONSTOREDPROCEDURE2
#define ISQLDMOReplicationStoredProcedure2 IWSQLDMOReplicationStoredProcedure2
#define IID_ISQLDMOReplicationStoredProcedure2 IID_IWSQLDMOReplicationStoredProcedure2

#undef LPSQLDMOREPLICATIONSTOREDPROCEDURES
#undef ISQLDMOReplicationStoredProcedures
#undef IID_ISQLDMOReplicationStoredProcedures
interface IWSQLDMOReplicationStoredProcedures;			TYPEDEFINTERFACE IWSQLDMOReplicationStoredProcedures *				LPWSQLDMOREPLICATIONSTOREDPROCEDURES;
#define LPSQLDMOREPLICATIONSTOREDPROCEDURES LPWSQLDMOREPLICATIONSTOREDPROCEDURES
#define ISQLDMOReplicationStoredProcedures IWSQLDMOReplicationStoredProcedures
#define IID_ISQLDMOReplicationStoredProcedures IID_IWSQLDMOReplicationStoredProcedures

#undef LPSQLDMODISTRIBUTIONPUBLICATIONS
#undef ISQLDMODistributionPublications
#undef IID_ISQLDMODistributionPublications
interface IWSQLDMODistributionPublications;			TYPEDEFINTERFACE IWSQLDMODistributionPublications *					LPWSQLDMODISTRIBUTIONPUBLICATIONS;
#define LPSQLDMODISTRIBUTIONPUBLICATIONS LPWSQLDMODISTRIBUTIONPUBLICATIONS
#define ISQLDMODistributionPublications IWSQLDMODistributionPublications
#define IID_ISQLDMODistributionPublications IID_IWSQLDMODistributionPublications

#undef LPSQLDMODISTRIBUTIONPUBLICATION
#undef ISQLDMODistributionPublication
#undef IID_ISQLDMODistributionPublication
interface IWSQLDMODistributionPublication;				TYPEDEFINTERFACE IWSQLDMODistributionPublication *					LPWSQLDMODISTRIBUTIONPUBLICATION;
#define LPSQLDMODISTRIBUTIONPUBLICATION LPWSQLDMODISTRIBUTIONPUBLICATION
#define ISQLDMODistributionPublication IWSQLDMODistributionPublication
#define IID_ISQLDMODistributionPublication IID_IWSQLDMODistributionPublication

#undef LPSQLDMODISTRIBUTIONPUBLICATION2
#undef ISQLDMODistributionPublication2
#undef IID_ISQLDMODistributionPublication2
interface IWSQLDMODistributionPublication2;				TYPEDEFINTERFACE IWSQLDMODistributionPublication2 *					LPWSQLDMODISTRIBUTIONPUBLICATION2;
#define LPSQLDMODISTRIBUTIONPUBLICATION2 LPWSQLDMODISTRIBUTIONPUBLICATION2
#define ISQLDMODistributionPublication2 IWSQLDMODistributionPublication2
#define IID_ISQLDMODistributionPublication2 IID_IWSQLDMODistributionPublication2

#undef LPSQLDMODISTRIBUTIONARTICLES
#undef ISQLDMODistributionArticles
#undef IID_ISQLDMODistributionArticles
interface IWSQLDMODistributionArticles;			TYPEDEFINTERFACE IWSQLDMODistributionArticles *					LPWSQLDMODISTRIBUTIONARTICLES;
#define LPSQLDMODISTRIBUTIONARTICLES LPWSQLDMODISTRIBUTIONARTICLES
#define ISQLDMODistributionArticles IWSQLDMODistributionArticles
#define IID_ISQLDMODistributionArticles IID_IWSQLDMODistributionArticles

#undef LPSQLDMODISTRIBUTIONARTICLE
#undef ISQLDMODistributionArticle
#undef IID_ISQLDMODistributionArticle
interface IWSQLDMODistributionArticle;				TYPEDEFINTERFACE IWSQLDMODistributionArticle *					LPWSQLDMODISTRIBUTIONARTICLE;
#define LPSQLDMODISTRIBUTIONARTICLE LPWSQLDMODISTRIBUTIONARTICLE
#define ISQLDMODistributionArticle IWSQLDMODistributionArticle
#define IID_ISQLDMODistributionArticle IID_IWSQLDMODistributionArticle

#undef LPSQLDMODISTRIBUTIONARTICLE2
#undef ISQLDMODistributionArticle2
#undef IID_ISQLDMODistributionArticle2
interface IWSQLDMODistributionArticle2;				TYPEDEFINTERFACE IWSQLDMODistributionArticle2 *					LPWSQLDMODISTRIBUTIONARTICLE2;
#define LPSQLDMODISTRIBUTIONARTICLE2 LPWSQLDMODISTRIBUTIONARTICLE2
#define ISQLDMODistributionArticle2 IWSQLDMODistributionArticle2
#define IID_ISQLDMODistributionArticle2 IID_IWSQLDMODistributionArticle2

#undef LPSQLDMODISTRIBUTIONSUBSCRIPTIONS
#undef ISQLDMODistributionSubscriptions
#undef IID_ISQLDMODistributionSubscriptions
interface IWSQLDMODistributionSubscriptions;			TYPEDEFINTERFACE IWSQLDMODistributionSubscriptions *					LPWSQLDMODISTRIBUTIONSUBSCRIPTIONS;
#define LPSQLDMODISTRIBUTIONSUBSCRIPTIONS LPWSQLDMODISTRIBUTIONSUBSCRIPTIONS
#define ISQLDMODistributionSubscriptions IWSQLDMODistributionSubscriptions
#define IID_ISQLDMODistributionSubscriptions IID_IWSQLDMODistributionSubscriptions

#undef LPSQLDMODISTRIBUTIONSUBSCRIPTION
#undef ISQLDMODistributionSubscription
#undef IID_ISQLDMODistributionSubscription
interface IWSQLDMODistributionSubscription;				TYPEDEFINTERFACE IWSQLDMODistributionSubscription *					LPWSQLDMODISTRIBUTIONSUBSCRIPTION;
#define LPSQLDMODISTRIBUTIONSUBSCRIPTION LPWSQLDMODISTRIBUTIONSUBSCRIPTION
#define ISQLDMODistributionSubscription IWSQLDMODistributionSubscription
#define IID_ISQLDMODistributionSubscription IID_IWSQLDMODistributionSubscription

#undef LPSQLDMODISTRIBUTIONSUBSCRIPTION2
#undef ISQLDMODistributionSubscription2
#undef IID_ISQLDMODistributionSubscription2
interface IWSQLDMODistributionSubscription2;				TYPEDEFINTERFACE IWSQLDMODistributionSubscription2 *					LPWSQLDMODISTRIBUTIONSUBSCRIPTION2;
#define LPSQLDMODISTRIBUTIONSUBSCRIPTION2 LPWSQLDMODISTRIBUTIONSUBSCRIPTION2
#define ISQLDMODistributionSubscription2 IWSQLDMODistributionSubscription2
#define IID_ISQLDMODistributionSubscription2 IID_IWSQLDMODistributionSubscription2

// 8.0 new objects
#undef LPSQLDMOMERGEDYNAMICSNAPSHOTJOBS
#undef ISQLDMOMergeDynamicSnapshotJobs
#undef IID_ISQLDMOMergeDynamicSnapshotJobs
interface IWSQLDMOMergeDynamicSnapshotJobs;				TYPEDEFINTERFACE IWSQLDMOMergeDynamicSnapshotJobs *					LPWSQLDMOMERGEDYNAMICSNAPSHOTJOBS;
#define LPSQLDMOMERGEDYNAMICSNAPSHOTJOBS LPWSQLDMOMERGEDYNAMICSNAPSHOTJOBS
#define ISQLDMOMergeDynamicSnapshotJobs IWSQLDMOMergeDynamicSnapshotJobs
#define IID_ISQLDMOMergeDynamicSnapshotJobs IID_IWSQLDMOMergeDynamicSnapshotJobs

#undef LPSQLDMOMERGEDYNAMICSNAPSHOTJOB
#undef ISQLDMOMergeDynamicSnapshotJob
#undef IID_ISQLDMOMergeDynamicSnapshotJob
interface IWSQLDMOMergeDynamicSnapshotJob;				TYPEDEFINTERFACE IWSQLDMOMergeDynamicSnapshotJob *					LPWSQLDMOMERGEDYNAMICSNAPSHOTJOB;
#define LPSQLDMOMERGEDYNAMICSNAPSHOTJOB LPWSQLDMOMERGEDYNAMICSNAPSHOTJOB
#define ISQLDMOMergeDynamicSnapshotJob IWSQLDMOMergeDynamicSnapshotJob
#define IID_ISQLDMOMergeDynamicSnapshotJob IID_IWSQLDMOMergeDynamicSnapshotJob


////////////////////////////////////////////////////////////////////////////////////////
// Event Sink Interfaces
////////////////////////////////////////////////////////////////////////////////////////
#undef LPSQLDMOREPLICATIONSINK
#undef ISQLDMOReplicationSink
#undef IID_ISQLDMOReplicationSink
interface IWSQLDMOReplicationSink;                                         TYPEDEFINTERFACE IWSQLDMOReplicationSink *                         LPWSQLDMOREPLICATIONSINK;
#define LPSQLDMOREPLICATIONSINK LPWSQLDMOREPLICATIONSINK
#define ISQLDMOReplicationSink IWSQLDMOReplicationSink
#define IID_ISQLDMOReplicationSink IID_IWSQLDMOReplicationSink


// ***************************************************************************
//               Copyright (C) 1985-1999 Microsoft Corporation.
// @File: agen_itf.h
//
// Purpose: Agent defines and interfaces
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





#undef LPSQLDMOALERTS
#undef ISQLDMOAlerts
#undef IID_ISQLDMOAlerts
interface IWSQLDMOAlerts;                   TYPEDEFINTERFACE IWSQLDMOAlerts *             LPWSQLDMOALERTS;
#define LPSQLDMOALERTS    LPWSQLDMOALERTS
#define ISQLDMOAlerts     IWSQLDMOAlerts
#define IID_ISQLDMOAlerts IID_IWSQLDMOAlerts

#undef LPSQLDMOALERT
#undef ISQLDMOAlert
#undef IID_ISQLDMOAlert
interface IWSQLDMOAlert;                    TYPEDEFINTERFACE IWSQLDMOAlert *              LPWSQLDMOALERT;
#define LPSQLDMOALERT    LPWSQLDMOALERT
#define ISQLDMOAlert     IWSQLDMOAlert
#define IID_ISQLDMOAlert IID_IWSQLDMOAlert

#undef LPSQLDMOOPERATORS
#undef ISQLDMOOperators
#undef IID_ISQLDMOOperators
interface IWSQLDMOOperators;                TYPEDEFINTERFACE IWSQLDMOOperators *          LPWSQLDMOOPERATORS;
#define LPSQLDMOOPERATORS    LPWSQLDMOOPERATORS
#define ISQLDMOOperators     IWSQLDMOOperators
#define IID_ISQLDMOOperators IID_IWSQLDMOOperators

#undef LPSQLDMOOPERATOR
#undef ISQLDMOOperator
#undef IID_ISQLDMOOperator
interface IWSQLDMOOperator;                 TYPEDEFINTERFACE IWSQLDMOOperator *           LPWSQLDMOOPERATOR;
#define LPSQLDMOOPERATOR    LPWSQLDMOOPERATOR
#define ISQLDMOOperator     IWSQLDMOOperator
#define IID_ISQLDMOOperator IID_IWSQLDMOOperator

#undef LPSQLDMOJOBHISTORYFILTER
#undef ISQLDMOJobHistoryFilter
#undef IID_ISQLDMOJobHistoryFilter
interface IWSQLDMOJobHistoryFilter;         TYPEDEFINTERFACE IWSQLDMOJobHistoryFilter *   LPWSQLDMOJOBHISTORYFILTER;
#define LPSQLDMOJOBHISTORYFILTER    LPWSQLDMOJOBHISTORYFILTER
#define ISQLDMOJobHistoryFilter     IWSQLDMOJobHistoryFilter
#define IID_ISQLDMOJobHistoryFilter IID_IWSQLDMOJobHistoryFilter

#undef LPSQLDMOJOBSERVER
#undef ISQLDMOJobServer
#undef IID_ISQLDMOJobServer
interface IWSQLDMOJobServer;                TYPEDEFINTERFACE IWSQLDMOJobServer *          LPWSQLDMOJOBSERVER;
#define LPSQLDMOJOBSERVER    LPWSQLDMOJOBSERVER
#define ISQLDMOJobServer     IWSQLDMOJobServer
#define IID_ISQLDMOJobServer IID_IWSQLDMOJobServer

#undef LPSQLDMOJOBSERVER2
#undef ISQLDMOJobServer2
#undef IID_ISQLDMOJobServer2
interface IWSQLDMOJobServer2;                TYPEDEFINTERFACE IWSQLDMOJobServer2 *          LPWSQLDMOJOBSERVER2;
#define LPSQLDMOJOBSERVER2    LPWSQLDMOJOBSERVER2
#define ISQLDMOJobServer2     IWSQLDMOJobServer2
#define IID_ISQLDMOJobServer2 IID_IWSQLDMOJobServer2

#undef LPSQLDMOALERTSYSTEM
#undef ISQLDMOAlertSystem
#undef IID_ISQLDMOAlertSystem
interface IWSQLDMOAlertSystem;              TYPEDEFINTERFACE IWSQLDMOAlertSystem *        LPWSQLDMOALERTSYSTEM;
#define LPSQLDMOALERTSYSTEM    LPWSQLDMOALERTSYSTEM
#define ISQLDMOAlertSystem     IWSQLDMOAlertSystem
#define IID_ISQLDMOAlertSystem IID_IWSQLDMOAlertSystem

#undef LPSQLDMOJOBS
#undef ISQLDMOJobs
#undef IID_ISQLDMOJobs
interface IWSQLDMOJobs;                     TYPEDEFINTERFACE IWSQLDMOJobs *               LPWSQLDMOJOBS;
#define LPSQLDMOJOBS    LPWSQLDMOJOBS
#define ISQLDMOJobs     IWSQLDMOJobs
#define IID_ISQLDMOJobs IID_IWSQLDMOJobs

#undef LPSQLDMOJOB
#undef ISQLDMOJob
#undef IID_ISQLDMOJob
interface IWSQLDMOJob;                      TYPEDEFINTERFACE IWSQLDMOJob *                LPWSQLDMOJOB;
#define LPSQLDMOJOB    LPWSQLDMOJOB
#define ISQLDMOJob     IWSQLDMOJob
#define IID_ISQLDMOJob IID_IWSQLDMOJob

#undef LPSQLDMOJOBSTEPS
#undef ISQLDMOJobSteps
#undef IID_ISQLDMOJobSteps
interface IWSQLDMOJobSteps;                 TYPEDEFINTERFACE IWSQLDMOJobSteps *           LPWSQLDMOJOBSTEPS;
#define LPSQLDMOJOBSTEPS    LPWSQLDMOJOBSTEPS
#define ISQLDMOJobSteps     IWSQLDMOJobSteps
#define IID_ISQLDMOJobSteps IID_IWSQLDMOJobSteps

#undef LPSQLDMOJOBSTEP
#undef ISQLDMOJobStep
#undef IID_ISQLDMOJobStep
interface IWSQLDMOJobStep;                  TYPEDEFINTERFACE IWSQLDMOJobStep *            LPWSQLDMOJOBSTEP;
#define LPSQLDMOJOBSTEP    LPWSQLDMOJOBSTEP
#define ISQLDMOJobStep     IWSQLDMOJobStep
#define IID_ISQLDMOJobStep IID_IWSQLDMOJobStep

#undef LPSQLDMOTARGETSERVERS
#undef ISQLDMOTargetServers
#undef IID_ISQLDMOTargetServers
interface IWSQLDMOTargetServers;            TYPEDEFINTERFACE IWSQLDMOTargetServers *      LPWSQLDMOTARGETSERVERS;
#define LPSQLDMOTARGETSERVERS    LPWSQLDMOTARGETSERVERS
#define ISQLDMOTargetServers     IWSQLDMOTargetServers
#define IID_ISQLDMOTargetServers IID_IWSQLDMOTargetServers

#undef LPSQLDMOTARGETSERVER
#undef ISQLDMOTargetServer
#undef IID_ISQLDMOTargetServer
interface IWSQLDMOTargetServer;             TYPEDEFINTERFACE IWSQLDMOTargetServer *       LPWSQLDMOTARGETSERVER;
#define LPSQLDMOTARGETSERVER    LPWSQLDMOTARGETSERVER
#define ISQLDMOTargetServer     IWSQLDMOTargetServer
#define IID_ISQLDMOTargetServer IID_IWSQLDMOTargetServer

#undef LPSQLDMOTARGETSERVERGROUPS
#undef ISQLDMOTargetServerGroups
#undef IID_ISQLDMOTargetServerGroups
interface IWSQLDMOTargetServerGroups;       TYPEDEFINTERFACE IWSQLDMOTargetServerGroups * LPWSQLDMOTARGETSERVERGROUPS;
#define LPSQLDMOTARGETSERVERGROUPS    LPWSQLDMOTARGETSERVERGROUPS
#define ISQLDMOTargetServerGroups     IWSQLDMOTargetServerGroups
#define IID_ISQLDMOTargetServerGroups IID_IWSQLDMOTargetServerGroups

#undef LPSQLDMOTARGETSERVERGROUP
#undef ISQLDMOTargetServerGroup
#undef IID_ISQLDMOTargetServerGroup
interface IWSQLDMOTargetServerGroup;        TYPEDEFINTERFACE IWSQLDMOTargetServerGroup *  LPWSQLDMOTARGETSERVERGROUP;
#define LPSQLDMOTARGETSERVERGROUP    LPWSQLDMOTARGETSERVERGROUP
#define ISQLDMOTargetServerGroup     IWSQLDMOTargetServerGroup
#define IID_ISQLDMOTargetServerGroup IID_IWSQLDMOTargetServerGroup

#undef LPSQLDMOJOBCATEGORIES
#undef ISQLDMOJobCategories
#undef IID_ISQLDMOJobCategories
interface IWSQLDMOJobCategories;            TYPEDEFINTERFACE IWSQLDMOJobCategories *      LPWSQLDMOJOBCATEGORIES;
#define LPSQLDMOJOBCATEGORIES    LPWSQLDMOJOBCATEGORIES
#define ISQLDMOJobCategories     IWSQLDMOJobCategories
#define IID_ISQLDMOJobCategories IID_IWSQLDMOJobCategories

#undef LPSQLDMOALERTCATEGORIES
#undef ISQLDMOAlertCategories
#undef IID_ISQLDMOAlertCategories
interface IWSQLDMOAlertCategories;            TYPEDEFINTERFACE IWSQLDMOAlertCategories *      LPWSQLDMOALERTCATEGORIES;
#define LPSQLDMOALERTCATEGORIES    LPWSQLDMOALERTCATEGORIES
#define ISQLDMOAlertCategories     IWSQLDMOAlertCategories
#define IID_ISQLDMOAlertCategories IID_IWSQLDMOAlertCategories

#undef LPSQLDMOOPERATORCATEGORIES
#undef ISQLDMOOperatorCategories
#undef IID_ISQLDMOOperatorCategories
interface IWSQLDMOOperatorCategories;            TYPEDEFINTERFACE IWSQLDMOOperatorCategories *      LPWSQLDMOOPERATORCATEGORIES;
#define LPSQLDMOOPERATORCATEGORIES    LPWSQLDMOOPERATORCATEGORIES
#define ISQLDMOOperatorCategories     IWSQLDMOOperatorCategories
#define IID_ISQLDMOOperatorCategories IID_IWSQLDMOOperatorCategories

#undef LPSQLDMOCATEGORY
#undef ISQLDMOCategory
#undef IID_ISQLDMOCategory
interface IWSQLDMOCategory;              TYPEDEFINTERFACE IWSQLDMOCategory *        LPWSQLDMOCATEGORY;
#define LPSQLDMOCATEGORY    LPWSQLDMOCATEGORY
#define ISQLDMOCategory     IWSQLDMOCategory
#define IID_ISQLDMOCategory IID_IWSQLDMOCategory

#undef LPSQLDMOSCHEDULE
#undef ISQLDMOSchedule
#undef IID_ISQLDMOSchedule
interface IWSQLDMOSchedule;                 TYPEDEFINTERFACE IWSQLDMOSchedule *           LPWSQLDMOSCHEDULE;
#define LPSQLDMOSCHEDULE    LPWSQLDMOSCHEDULE
#define ISQLDMOSchedule     IWSQLDMOSchedule
#define IID_ISQLDMOSchedule IID_IWSQLDMOSchedule

#undef LPSQLDMOJOBFILTER
#undef ISQLDMOJobFilter
#undef IID_ISQLDMOJobFilter
interface IWSQLDMOJobFilter;                TYPEDEFINTERFACE IWSQLDMOJobFilter *          LPWSQLDMOJOBFILTER;
#define LPSQLDMOJOBFILTER    LPWSQLDMOJOBFILTER
#define ISQLDMOJobFilter     IWSQLDMOJobFilter
#define IID_ISQLDMOJobFilter IID_IWSQLDMOJobFilter

#undef LPSQLDMOJOBSCHEDULES
#undef ISQLDMOJobSchedules
#undef IID_ISQLDMOJobSchedules
interface IWSQLDMOJobSchedules;             TYPEDEFINTERFACE IWSQLDMOJobSchedules *       LPWSQLDMOJOBSCHEDULES;
#define LPSQLDMOJOBSCHEDULES    LPWSQLDMOJOBSCHEDULES
#define ISQLDMOJobSchedules     IWSQLDMOJobSchedules
#define IID_ISQLDMOJobSchedules IID_IWSQLDMOJobSchedules

#undef LPSQLDMOJOBSCHEDULE
#undef ISQLDMOJobSchedule
#undef IID_ISQLDMOJobSchedule
interface IWSQLDMOJobSchedule;              TYPEDEFINTERFACE IWSQLDMOJobSchedule *        LPWSQLDMOJOBSCHEDULE;
#define LPSQLDMOJOBSCHEDULE    LPWSQLDMOJOBSCHEDULE
#define ISQLDMOJobSchedule     IWSQLDMOJobSchedule
#define IID_ISQLDMOJobSchedule IID_IWSQLDMOJobSchedule

// Auto-documenting names for these... They return an LPSQLDMOOBJECTLIST
// of the specified <objecttype>LIST objects.. e.g. LPSQLDMOCOLUMNLIST
// returns a list of LPSQLDMOCOLUMN objects.

#define SQLDMOCategory_UseDefault    TEXT("[DEFAULT]")
#define SQLDMOTargetServer_Local     TEXT("(local)")
#define SQLDMOAlert_NoJob            TEXT("00000000000000000000000000000000")





////////////////////////////
// Interface definitions.
////////////////////////////

// This is the base class for all SQLDMO objects.  It is never instantiated by itself.
// The members must be copied into all derived classes so that C clients can reference
// them, since the DECLARE_INTERFACE_ macro doesn't provide inheritance in C.  The
// undef/def of INTERFACE is likewise required for C programmers.
#undef INTERFACE
#define INTERFACE ISQLDMOStdObject
DECLARE_INTERFACE_(INTERFACE, IUnknown)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;
};

#ifdef __cplusplus
#ifndef CTEMPOLEREF_DEFINED
#define CTEMPOLEREF_DEFINED
// This is a utility class that takes an IUnknown-derived pointer as input and automatically
// Release()s it in dtor.  Use this as a stack variable which will hold objects and
// Release() them when they go out of scope; useful if multiple exit points.
template < class OLEPTR> class CTempOLERef {
	OLEPTR m_oleptr;

	// Private copy operators -- we don't want these used due to refcounting issues.
	// Since they can't therefore be called, no need to assign a body.
	CTempOLERef(const CTempOLERef<OLEPTR>& Src);
	OLEPTR  operator = (const CTempOLERef<OLEPTR>& Src);

public:
	CTempOLERef() {m_oleptr = NULL;}
	CTempOLERef(OLEPTR pIn) {m_oleptr = pIn;}
	~CTempOLERef() {if (m_oleptr) m_oleptr->Release();}
	OLEPTR p() {return m_oleptr;}				// Alternative to casting (better for cut 'n paste).

	operator OLEPTR () {return m_oleptr;}		// Return the input pointer on a cast
	operator LPUNKNOWN () {return m_oleptr;}
	operator void *() {return (void *)m_oleptr;}
	operator BOOL () {return m_oleptr ? TRUE : FALSE;}
	OLEPTR  operator = (OLEPTR pIn) {if (m_oleptr) m_oleptr->Release(); return m_oleptr = pIn;}
	OLEPTR * operator & () {return &m_oleptr;}	// Overload address-of operator
	BOOL operator ! () {return m_oleptr ? FALSE : TRUE;}
	OLEPTR operator -> () {return m_oleptr;}	// Pass operator-> thru to m_oleptr; allows tempxxxRef->xxxSpecificMember();

	// Apps should not Release() this object directly as it is intended to do so as it goes out of scope,
	// hence as a safety feature to avoid double-Release() clear the pointer if it's called directly.
	void Release() {if (m_oleptr) m_oleptr->Release(); m_oleptr = NULL;}
};

// Similar to above, for use with SQLDMO_BSTR's
class CTempBSTR {
	SQLDMO_BSTR m_bstr;

	// Private copy operators -- we don't want these used due to refcounting issues.
	// Since they can't therefore be called, no need to assign a body.
	CTempBSTR(const CTempBSTR& Src);
	SQLDMO_BSTR  operator = (const CTempBSTR& Src);

public:
	CTempBSTR() {m_bstr = NULL;}
	CTempBSTR(SQLDMO_BSTR bstrIn) {m_bstr = bstrIn;}
	~CTempBSTR() {Free();}
	void Free() {if (m_bstr) {SQLDMOFreeString(m_bstr); m_bstr = NULL;}}
	SQLDMO_BSTR b() {return m_bstr;}

	operator SQLDMO_LPCSTR () {return (SQLDMO_LPCSTR)m_bstr;}
	operator void *() {return (void *)m_bstr;}
	SQLDMO_BSTR operator = (SQLDMO_BSTR bstrIn) {Free(); return m_bstr = bstrIn;}
	SQLDMO_BSTR * operator & () {return &m_bstr;}		// Overload address-of operator
	BOOL operator ! () {return m_bstr ? FALSE : TRUE;}
};

#endif  // CTEMPOLEREF_DEFINED
#endif	// __cplusplus

// ***************************************************************************
//               Copyright (C) 1985-1999 Microsoft Corporation.
// @File: core_itf.h
//
// Purpose: CORE defines and interfaces
//
//
// Notes:
//
// History:
//
//   @Version: Shiloh
//   65649 IXL  07/08/00 remove job server from job script
//   61175 WG   05/10/00 VIA Netlibs
//   60740 WG   05/08/00 New dboptions for recovery
//   60549 WG   05/01/00 New ServerRole bulkadmin
//   60311 WG   04/27/00 Encrypted UDF checking
//   55928 WG   02/28/00 Compatibility level
//   54473 WG   02/11/00 New script option
//   54427 WG   02/11/00 Restore BackupSetName
//   54311 WG   02/10/00 Extended Property
//   53618 WG   02/03/00 UDF ListPermission
//   53312 WG   01/31/00 Transferrable encryption
//   53089 WG   01/28/00 New Backup Restore option
//   52952 WG   01/27/00 Linked Server option
//   52788 WG   01/26/00 Linked Server options
//   52521 WG   01/24/00 Backup and Restore
//   52513 WG   01/24/00 GrantedGranted
//   52356 WG   01/21/00 ProductLevel
//   51928 WG   01/18/00 EnumAvailableMedia
//   51899 WG   01/18/00 DatabaseRole
//   51623 WG   01/17/00 IsDeleted
//   51534 WG   01/13/00 CheckSyntax
//   50625 WG   01/04/00 Syntax check for default and rule
//   50559 WG   01/03/00 Language ID on fulltext column
//   50447 WG   12/29/99 EnumDependencies with system objects
//   49768 WG   12/14/99 Support bigint in QueryResult
//   49712 WG   12/13/99 Refresh for LinkedServer
//   49522 WG   12/10/99 Script Job with enable flag
//   49452 WG   12/10/99 EnumParameters for UDF
//   49129 WG   12/07/99 CTS tracking
//
//
// @EndHeader@
// ***************************************************************************






////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// Generic enumerator object.
#undef INTERFACE
#define INTERFACE ISQLDMOObjectList
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties.  The object returned must be
    //*** cast to the appropriate object type; the type to cast to is indicated
    //*** by the LPSQLDMO<objecttype>LIST typedef of the returned list object.
    //*** e.g. LPSQLDMOCOLUMNLIST returns a list of objects which cast to LPSQLDMOCOLUMN.
        STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOSTDOBJECT *ppObject) PURE;
        STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOSTDOBJECT *ppObject) PURE;
        STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;
        STDMETHOD(Refresh)(THIS) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// Names collection object (LPSQLDMONAMES).
#undef INTERFACE
#define INTERFACE ISQLDMONames
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
        STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, SQLDMO_LPBSTR pRetVal) PURE;
        STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
        STDMETHOD(Add)(THIS_ SQLDMO_LPCSTR szName) PURE;
        STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
        STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
        STDMETHOD(Refresh)(THIS) PURE;
        STDMETHOD(InsertByOrd)(THIS_ SQLDMO_LPCSTR szName, long lOrdinal) PURE;
        STDMETHOD(InsertByName)(THIS_ SQLDMO_LPCSTR szName, SQLDMO_LPCSTR szBeforeName) PURE;
        STDMETHOD(ReplaceByOrd)(THIS_ SQLDMO_LPCSTR szName, long lOrdinal) PURE;
        STDMETHOD(ReplaceByName)(THIS_ SQLDMO_LPCSTR szName, SQLDMO_LPCSTR szReplaceName) PURE;
        STDMETHOD(FindName)(THIS_ SQLDMO_LPCSTR szName, LPLONG pRetVal) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// Names enumerator object (LPSQLDMONAMELIST).
#undef INTERFACE
#define INTERFACE ISQLDMONameList
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
        STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, SQLDMO_LPBSTR pRetVal) PURE;
        STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
        STDMETHOD(Refresh)(THIS) PURE;
        STDMETHOD(FindName)(THIS_ SQLDMO_LPCSTR szName, LPLONG pRetVal) PURE;

};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOApplication
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(GetFullName)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(GetODBCVersionString)(THIS_ SQLDMO_LPBSTR pbstrVersion) PURE;
    STDMETHOD(GetVersionMajor)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetVersionMinor)(THIS_ LPLONG pRetVal) PURE;

        // Collection properties
    STDMETHOD(GetSQLServers)(THIS_ LPSQLDMOSERVERS *pServers) PURE;
    STDMETHOD(GetSQLServerByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOSERVER *ppSQLServer) PURE;
    STDMETHOD(GetSQLServerByOrd)(THIS_ long lOrdinal, LPSQLDMOSERVER *ppSQLServer) PURE;
    STDMETHOD(RemoveSQLServerByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveSQLServerByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddSQLServer)(THIS_ LPSQLDMOSERVER pSQLServer) PURE;
    STDMETHOD(GetSQLServerCount)(THIS_ LPLONG plCount) PURE;

        //*** methods
    STDMETHOD(Quit)(THIS) PURE;

   // Post-6.0 additions.
    STDMETHOD(GetGroupRegistrationServer)(THIS_ SQLDMO_LPBSTR pbstrVersion) PURE;
    STDMETHOD(SetGroupRegistrationServer)(THIS_ SQLDMO_LPCSTR pbstrVersion) PURE;
    STDMETHOD(GetGroupRegistrationVersion)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetUseCurrentUserServerGroups)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetUseCurrentUserServerGroups)(THIS_ BOOL pRetVal) PURE;
    STDMETHOD(GetVersionBuild)(THIS_ LPLONG pRetVal) PURE;

    STDMETHOD(GetServerGroups)(THIS_ LPSQLDMOSERVERGROUPS *ppServerGroups) PURE;
    STDMETHOD(GetServerGroupByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOSERVERGROUP *ppServerGroup) PURE;
    STDMETHOD(GetServerGroupByOrd)(THIS_ long lOrdinal, LPSQLDMOSERVERGROUP *ppServerGroup) PURE;
    STDMETHOD(RemoveServerGroupByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveServerGroupByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddServerGroup)(THIS_ LPSQLDMOSERVERGROUP pServerGroup) PURE;
    STDMETHOD(GetServerGroupCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(ListAvailableSQLServers)(THIS_ LPSQLDMONAMELIST *ppServerNames) PURE;

        // Post-6.5
    STDMETHOD(GetBlockingTimeout)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetBlockingTimeout)(THIS_ long NewValue) PURE;

};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOServers
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
        STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOSERVER *ppObj) PURE;
        STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOSERVER *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOSERVER *ppObj) PURE;
        STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOServer
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetApplicationName)(THIS_ SQLDMO_LPBSTR pbstrAppName) PURE;
    STDMETHOD(SetApplicationName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetConnectionID)(THIS_ LPLONG plConnectionID) PURE;
    STDMETHOD(GetHostName)(THIS_ SQLDMO_LPBSTR pbstrHostName) PURE;
    STDMETHOD(SetHostName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetLanguage)(THIS_ SQLDMO_LPBSTR pbstrLanguage) PURE;
    STDMETHOD(SetLanguage)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetLogin)(THIS_ SQLDMO_LPBSTR pbstrLogin) PURE;
    STDMETHOD(SetLogin)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetNextDeviceNumber)(THIS_ LPLONG plNextDeviceNumber) PURE;
    STDMETHOD(GetQueryTimeout)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetQueryTimeout)(THIS_ long NewValue) PURE;
    STDMETHOD(GetLoginTimeout)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetLoginTimeout)(THIS_ long NewValue) PURE;
    STDMETHOD(GetLoginSecure)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetLoginSecure)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetNetPacketSize)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetNetPacketSize)(THIS_ long NewValue) PURE;
    STDMETHOD(GetPassword)(THIS_ SQLDMO_LPBSTR pbstrPassword) PURE;
    STDMETHOD(SetPassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetProcessID)(THIS_ LPLONG plProcessID) PURE;
    STDMETHOD(GetStatus)(THIS_ SQLDMO_SVCSTATUS_TYPE *pStatus) PURE;
    STDMETHOD(GetUserProfile)(THIS_ SQLDMO_SRVUSERPROFILE_TYPE *pProfileBits) PURE;
    STDMETHOD(GetMaxNumericPrecision)(THIS_ LPLONG pMaxPrec) PURE;
    STDMETHOD(GetTrueLogin)(THIS_ SQLDMO_LPBSTR pbstrTrueLogin) PURE;
    STDMETHOD(GetTrueName)(THIS_ SQLDMO_LPBSTR pbstrTrueName) PURE;
    STDMETHOD(GetVersionString)(THIS_ SQLDMO_LPBSTR pbstrVersion) PURE;
    STDMETHOD(GetVersionMajor)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetVersionMinor)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetCommandTerminator)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(SetCommandTerminator)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetProcessInputBuffer)(THIS_ long lProcessID, SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetProcessOutputBuffer)(THIS_ long lProcessID, SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetAutoReConnect)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAutoReConnect)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetStatusInfoRefetchInterval)(THIS_ SQLDMO_STATUSINFO_TYPE StatusInfoType, LPLONG pRefetchSeconds) PURE;
    STDMETHOD(SetStatusInfoRefetchInterval)(THIS_ SQLDMO_STATUSINFO_TYPE StatusInfoType, long RefetchSeconds) PURE;
    STDMETHOD(GetSaLogin)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetAnsiNulls)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAnsiNulls)(THIS_ BOOL NewValue) PURE;

        //*** Object properties
    STDMETHOD(GetConfiguration)(THIS_ LPSQLDMOCONFIGURATION *ppConfig) PURE;
    STDMETHOD(GetIntegratedSecurity)(THIS_ LPSQLDMOINTEGRATEDSECURITY *ppIntSec) PURE;
    STDMETHOD(GetRegistry)(THIS_ LPSQLDMOREGISTRY *ppRegistry) PURE;
    STDMETHOD(GetJobServer)(THIS_ LPSQLDMOJOBSERVER *ppJobServer) PURE;

        //*** collection properties
    STDMETHOD(GetDatabases)(THIS_ LPSQLDMODATABASES *ppDatabases) PURE;
    STDMETHOD(GetDatabaseByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMODATABASE *ppDatabase, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetDatabaseByOrd)(THIS_ long lOrdinal, LPSQLDMODATABASE *ppDatabase) PURE;
    STDMETHOD(RemoveDatabaseByName)(THIS_ SQLDMO_LPCSTR szName, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RemoveDatabaseByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddDatabase)(THIS_ LPSQLDMODATABASE pDatabase) PURE;
    STDMETHOD(GetDatabaseCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetBackupDevices)(THIS_ LPSQLDMOBACKUPDEVICES *ppBackupDevices) PURE;
    STDMETHOD(GetBackupDeviceByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOBACKUPDEVICE *ppBackupDevice) PURE;
    STDMETHOD(GetBackupDeviceByOrd)(THIS_ long lOrdinal, LPSQLDMOBACKUPDEVICE *ppBackupDevice) PURE;
    STDMETHOD(RemoveBackupDeviceByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveBackupDeviceByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddBackupDevice)(THIS_ LPSQLDMOBACKUPDEVICE pBackupDevice) PURE;
    STDMETHOD(GetBackupDeviceCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetLogins)(THIS_ LPSQLDMOLOGINS *ppLogins) PURE;
    STDMETHOD(GetLoginByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOLOGIN *ppLogin) PURE;
    STDMETHOD(GetLoginByOrd)(THIS_ long lOrdinal, LPSQLDMOLOGIN *ppLogin) PURE;
    STDMETHOD(RemoveLoginByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveLoginByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddLogin)(THIS_ LPSQLDMOLOGIN pLogin) PURE;
    STDMETHOD(GetLoginCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetLanguages)(THIS_ LPSQLDMOLANGUAGES *ppLanguages) PURE;
    STDMETHOD(GetLanguageByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOLANGUAGE *ppLanguage) PURE;
    STDMETHOD(GetLanguageByOrd)(THIS_ long lOrdinal, LPSQLDMOLANGUAGE *ppLanguage) PURE;
    STDMETHOD(GetLanguageCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetRemoteServers)(THIS_ LPSQLDMOREMOTESERVERS *ppRemoteServers) PURE;
    STDMETHOD(GetRemoteServerByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOREMOTESERVER *ppRemoteServer) PURE;
    STDMETHOD(GetRemoteServerByOrd)(THIS_ long lOrdinal, LPSQLDMOREMOTESERVER *ppRemoteServer) PURE;
    STDMETHOD(RemoveRemoteServerByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveRemoteServerByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddRemoteServer)(THIS_ LPSQLDMOREMOTESERVER pRemoteServer) PURE;
    STDMETHOD(GetRemoteServerCount)(THIS_ LPLONG plCount) PURE;

        //*** methods
    STDMETHOD(Connect)(THIS_ SQLDMO_LPCSTR szServerName CPPDEFAULT(= NULL), SQLDMO_LPCSTR szLogin CPPDEFAULT(= NULL), SQLDMO_LPCSTR szPassword CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(Close)(THIS) PURE;
    STDMETHOD(DisConnect)(THIS) PURE;
    STDMETHOD(ReConnect)(THIS) PURE;
    STDMETHOD(KillProcess)(THIS_ long lProcessID) PURE;
    STDMETHOD(ExecuteImmediate)(THIS_ SQLDMO_LPCSTR Command, SQLDMO_EXEC_TYPE ExecType CPPDEFAULT(= SQLDMOExec_Default), long lLength CPPDEFAULT(= 0)) PURE;
    STDMETHOD(ExecuteWithResults)(THIS_ SQLDMO_LPCSTR Command, LPSQLDMOQUERYRESULTS *ppResults, long lLength CPPDEFAULT(= 0)) PURE;
    STDMETHOD(UnloadODSDLL)(THIS_ SQLDMO_LPCSTR DLLName) PURE;
    STDMETHOD(KillDatabase)(THIS_ SQLDMO_LPCSTR DatabaseName) PURE;
    STDMETHOD(ReadErrorLog)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, long lLogNumber CPPDEFAULT(= 0)) PURE;
    STDMETHOD(EnumErrorLogs)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumProcesses)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPCSTR szWho CPPDEFAULT(= NULL), long lWho CPPDEFAULT(= -1)) PURE;
    STDMETHOD(EnumLocks)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, long lWho CPPDEFAULT(= -1)) PURE;
    STDMETHOD(ReadBackupHeader)(THIS_ LPSQLDMORESTORE LoadSpec, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumAvailableMedia)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_MEDIA_TYPE MediaType CPPDEFAULT(= SQLDMOMedia_All)) PURE;
    STDMETHOD(EnumDirectories)(THIS_ SQLDMO_LPCSTR PathName, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumServerAttributes)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumVersionInfo)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPCSTR szPrefixes CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(BeginTransaction)(THIS_ SQLDMO_LPCSTR szTransactionName CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(CommitTransaction)(THIS_ SQLDMO_LPCSTR TransactionName CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(SaveTransaction)(THIS_ SQLDMO_LPCSTR SavepointName) PURE;
    STDMETHOD(RollbackTransaction)(THIS_ SQLDMO_LPCSTR TransactionOrSavepointName CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(CommandShellImmediate)(THIS_ SQLDMO_LPCSTR Command) PURE;
    STDMETHOD(CommandShellWithResults)(THIS_ SQLDMO_LPCSTR Command, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(Pause)(THIS) PURE;
    STDMETHOD(Continue)(THIS) PURE;
    STDMETHOD(Shutdown)(THIS_ BOOL Wait CPPDEFAULT(= TRUE)) PURE;
    STDMETHOD(Start)(THIS_ BOOL fConnect, SQLDMO_LPCSTR Server CPPDEFAULT(= NULL), SQLDMO_LPCSTR Login CPPDEFAULT(= NULL), SQLDMO_LPCSTR Password CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(VerifyConnection)(THIS_ LPBOOL pRetVal, SQLDMO_VERIFYCONN_TYPE VerifyType CPPDEFAULT(= SQLDMOConn_ReconnectIfDead)) PURE;
    STDMETHOD(IsOS)(THIS_ SQLDMO_OS_TYPE lType, LPBOOL pRetVal) PURE;
    STDMETHOD(AddStartParameter)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

        // List methods
    STDMETHOD(ListStartupProcedures)(THIS_ LPSQLDMOSTOREDPROCEDURELIST * ppList) PURE;

        // Post-6.0 additions
    STDMETHOD(ExecuteWithResultsAndMessages)(THIS_ SQLDMO_LPCSTR Command, LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPBSTR ppszMessages CPPDEFAULT(= 0), long lLength CPPDEFAULT(= 0)) PURE;
    STDMETHOD(GetNetName)(THIS_ SQLDMO_LPBSTR pbstrNetName) PURE;
    STDMETHOD(EnumLoginMappings)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;

    // Post-6.5 additions to object properties
    STDMETHOD(GetReplication)(THIS_ LPSQLDMOREPLICATION *ppReplication) PURE;
    STDMETHOD(GetEnableBcp)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetEnableBcp)(THIS_ BOOL NewValue) PURE;

    STDMETHOD(GetBlockingTimeout)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetBlockingTimeout)(THIS_ long NewValue) PURE;

    // 7.0 collection properties
    STDMETHOD(GetServerRoles)(THIS_ LPSQLDMOSERVERROLES *ppServerRoles) PURE;
    STDMETHOD(GetServerRoleByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOSERVERROLE *ppServerRole) PURE;
    STDMETHOD(GetServerRoleByOrd)(THIS_ long lOrdinal, LPSQLDMOSERVERROLE *ppServerRole) PURE;
    STDMETHOD(GetServerRoleCount)(THIS_ LPLONG plCount) PURE;
    STDMETHOD(EnumNTDomainGroups)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPCSTR Domain CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(EnumAccountInfo)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPCSTR Account CPPDEFAULT(= NULL), BOOL ListAll CPPDEFAULT(= FALSE)) PURE;
    STDMETHOD(ListMembers)(THIS_ SQLDMO_ROLE_TYPE Type, LPSQLDMONAMELIST *ppResults) PURE;
    STDMETHOD(IsLogin)(THIS_ SQLDMO_LPCSTR LoginName, LPBOOL pRetVal) PURE;
    STDMETHOD(Abort)(THIS) PURE;
    STDMETHOD(GetIsdbcreator)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsdiskadmin)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsprocessadmin)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIssecurityadmin)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsserveradmin)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIssetupadmin)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIssysadmin)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(DetachDB)(THIS_ SQLDMO_LPCSTR DBName, SQLDMO_LPBSTR pResult, BOOL bCheck CPPDEFAULT(= TRUE)) PURE;
    STDMETHOD(AttachDB)(THIS_ SQLDMO_LPCSTR DBName, SQLDMO_LPCSTR DataFiles, SQLDMO_LPBSTR pResult) PURE;
//    STDMETHOD(RemapFile)(THIS_ SQLDMO_LPCSTR DBName, SQLDMO_LPCSTR LogicalName, SQLDMO_LPCSTR NewPhysicalPath, SQLDMO_LPBSTR pResult) PURE;
//    STDMETHOD(ClearMap)(THIS_ SQLDMO_LPBSTR pResult) PURE;
    STDMETHOD(GetQuotedIdentifier)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetQuotedIdentifier)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetLinkedServers)(THIS_ LPSQLDMOLINKEDSERVERS *ppLinkedServers) PURE;
    STDMETHOD(GetLinkedServerByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOLINKEDSERVER *ppLinkedServer) PURE;
    STDMETHOD(GetLinkedServerByOrd)(THIS_ long lOrdinal, LPSQLDMOLINKEDSERVER *ppLinkedServer) PURE;
    STDMETHOD(RemoveLinkedServerByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveLinkedServerByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddLinkedServer)(THIS_ LPSQLDMOLINKEDSERVER pLinkedServer) PURE;
    STDMETHOD(GetLinkedServerCount)(THIS_ LPLONG plCount) PURE;
    STDMETHOD(SetCodePageOverride)(THIS_ long NewValue) PURE;
    STDMETHOD(GetFullTextService)(THIS_ LPSQLDMOFULLTEXTSERVICE *ppFullTextService) PURE;
    STDMETHOD(GetODBCPrefix)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetODBCPrefix)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(Stop)(THIS) PURE;
    STDMETHOD(PingSQLServerVersion)(THIS_ SQLDMO_SQL_VER *pRetVal, SQLDMO_LPCSTR szServerName CPPDEFAULT(= NULL), SQLDMO_LPCSTR szLogin CPPDEFAULT(= NULL), SQLDMO_LPCSTR szPassword CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(IsPackage)(THIS_ SQLDMO_PACKAGE_TYPE *pRetVal) PURE;
    STDMETHOD(GetRegionalSetting)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetRegionalSetting)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCodePage)(THIS_ LPLONG plCount) PURE;
    STDMETHOD(AttachDBWithSingleFile)(THIS_ SQLDMO_LPCSTR DBName, SQLDMO_LPCSTR DataFile, SQLDMO_LPBSTR pResult) PURE;
    STDMETHOD(IsNTGroupMember)(THIS_ SQLDMO_LPCSTR NTGroup, SQLDMO_LPCSTR NTUser, LPBOOL pRetVal) PURE;
    STDMETHOD(GetServerTime)(THIS_ SQLDMO_LPBSTR pbstrServerTime) PURE;
    STDMETHOD(GetTranslateChar)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetTranslateChar)(THIS_ BOOL NewValue) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOServer2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOServer)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetApplicationName)(THIS_ SQLDMO_LPBSTR pbstrAppName) PURE;
    STDMETHOD(SetApplicationName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetConnectionID)(THIS_ LPLONG plConnectionID) PURE;
    STDMETHOD(GetHostName)(THIS_ SQLDMO_LPBSTR pbstrHostName) PURE;
    STDMETHOD(SetHostName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetLanguage)(THIS_ SQLDMO_LPBSTR pbstrLanguage) PURE;
    STDMETHOD(SetLanguage)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetLogin)(THIS_ SQLDMO_LPBSTR pbstrLogin) PURE;
    STDMETHOD(SetLogin)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetNextDeviceNumber)(THIS_ LPLONG plNextDeviceNumber) PURE;
    STDMETHOD(GetQueryTimeout)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetQueryTimeout)(THIS_ long NewValue) PURE;
    STDMETHOD(GetLoginTimeout)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetLoginTimeout)(THIS_ long NewValue) PURE;
    STDMETHOD(GetLoginSecure)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetLoginSecure)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetNetPacketSize)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetNetPacketSize)(THIS_ long NewValue) PURE;
    STDMETHOD(GetPassword)(THIS_ SQLDMO_LPBSTR pbstrPassword) PURE;
    STDMETHOD(SetPassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetProcessID)(THIS_ LPLONG plProcessID) PURE;
    STDMETHOD(GetStatus)(THIS_ SQLDMO_SVCSTATUS_TYPE *pStatus) PURE;
    STDMETHOD(GetUserProfile)(THIS_ SQLDMO_SRVUSERPROFILE_TYPE *pProfileBits) PURE;
    STDMETHOD(GetMaxNumericPrecision)(THIS_ LPLONG pMaxPrec) PURE;
    STDMETHOD(GetTrueLogin)(THIS_ SQLDMO_LPBSTR pbstrTrueLogin) PURE;
    STDMETHOD(GetTrueName)(THIS_ SQLDMO_LPBSTR pbstrTrueName) PURE;
    STDMETHOD(GetVersionString)(THIS_ SQLDMO_LPBSTR pbstrVersion) PURE;
    STDMETHOD(GetVersionMajor)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetVersionMinor)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetCommandTerminator)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(SetCommandTerminator)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetProcessInputBuffer)(THIS_ long lProcessID, SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetProcessOutputBuffer)(THIS_ long lProcessID, SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetAutoReConnect)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAutoReConnect)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetStatusInfoRefetchInterval)(THIS_ SQLDMO_STATUSINFO_TYPE StatusInfoType, LPLONG pRefetchSeconds) PURE;
    STDMETHOD(SetStatusInfoRefetchInterval)(THIS_ SQLDMO_STATUSINFO_TYPE StatusInfoType, long RefetchSeconds) PURE;
    STDMETHOD(GetSaLogin)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetAnsiNulls)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAnsiNulls)(THIS_ BOOL NewValue) PURE;

        //*** Object properties
    STDMETHOD(GetConfiguration)(THIS_ LPSQLDMOCONFIGURATION *ppConfig) PURE;
    STDMETHOD(GetIntegratedSecurity)(THIS_ LPSQLDMOINTEGRATEDSECURITY *ppIntSec) PURE;
    STDMETHOD(GetRegistry)(THIS_ LPSQLDMOREGISTRY *ppRegistry) PURE;
    STDMETHOD(GetJobServer)(THIS_ LPSQLDMOJOBSERVER *ppJobServer) PURE;

        //*** collection properties
    STDMETHOD(GetDatabases)(THIS_ LPSQLDMODATABASES *ppDatabases) PURE;
    STDMETHOD(GetDatabaseByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMODATABASE *ppDatabase, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetDatabaseByOrd)(THIS_ long lOrdinal, LPSQLDMODATABASE *ppDatabase) PURE;
    STDMETHOD(RemoveDatabaseByName)(THIS_ SQLDMO_LPCSTR szName, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RemoveDatabaseByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddDatabase)(THIS_ LPSQLDMODATABASE pDatabase) PURE;
    STDMETHOD(GetDatabaseCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetBackupDevices)(THIS_ LPSQLDMOBACKUPDEVICES *ppBackupDevices) PURE;
    STDMETHOD(GetBackupDeviceByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOBACKUPDEVICE *ppBackupDevice) PURE;
    STDMETHOD(GetBackupDeviceByOrd)(THIS_ long lOrdinal, LPSQLDMOBACKUPDEVICE *ppBackupDevice) PURE;
    STDMETHOD(RemoveBackupDeviceByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveBackupDeviceByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddBackupDevice)(THIS_ LPSQLDMOBACKUPDEVICE pBackupDevice) PURE;
    STDMETHOD(GetBackupDeviceCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetLogins)(THIS_ LPSQLDMOLOGINS *ppLogins) PURE;
    STDMETHOD(GetLoginByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOLOGIN *ppLogin) PURE;
    STDMETHOD(GetLoginByOrd)(THIS_ long lOrdinal, LPSQLDMOLOGIN *ppLogin) PURE;
    STDMETHOD(RemoveLoginByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveLoginByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddLogin)(THIS_ LPSQLDMOLOGIN pLogin) PURE;
    STDMETHOD(GetLoginCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetLanguages)(THIS_ LPSQLDMOLANGUAGES *ppLanguages) PURE;
    STDMETHOD(GetLanguageByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOLANGUAGE *ppLanguage) PURE;
    STDMETHOD(GetLanguageByOrd)(THIS_ long lOrdinal, LPSQLDMOLANGUAGE *ppLanguage) PURE;
    STDMETHOD(GetLanguageCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetRemoteServers)(THIS_ LPSQLDMOREMOTESERVERS *ppRemoteServers) PURE;
    STDMETHOD(GetRemoteServerByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOREMOTESERVER *ppRemoteServer) PURE;
    STDMETHOD(GetRemoteServerByOrd)(THIS_ long lOrdinal, LPSQLDMOREMOTESERVER *ppRemoteServer) PURE;
    STDMETHOD(RemoveRemoteServerByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveRemoteServerByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddRemoteServer)(THIS_ LPSQLDMOREMOTESERVER pRemoteServer) PURE;
    STDMETHOD(GetRemoteServerCount)(THIS_ LPLONG plCount) PURE;

        //*** methods
    STDMETHOD(Connect)(THIS_ SQLDMO_LPCSTR szServerName CPPDEFAULT(= NULL), SQLDMO_LPCSTR szLogin CPPDEFAULT(= NULL), SQLDMO_LPCSTR szPassword CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(Close)(THIS) PURE;
    STDMETHOD(DisConnect)(THIS) PURE;
    STDMETHOD(ReConnect)(THIS) PURE;
    STDMETHOD(KillProcess)(THIS_ long lProcessID) PURE;
    STDMETHOD(ExecuteImmediate)(THIS_ SQLDMO_LPCSTR Command, SQLDMO_EXEC_TYPE ExecType CPPDEFAULT(= SQLDMOExec_Default), long lLength CPPDEFAULT(= 0)) PURE;
    STDMETHOD(ExecuteWithResults)(THIS_ SQLDMO_LPCSTR Command, LPSQLDMOQUERYRESULTS *ppResults, long lLength CPPDEFAULT(= 0)) PURE;
    STDMETHOD(UnloadODSDLL)(THIS_ SQLDMO_LPCSTR DLLName) PURE;
    STDMETHOD(KillDatabase)(THIS_ SQLDMO_LPCSTR DatabaseName) PURE;
    STDMETHOD(ReadErrorLog)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, long lLogNumber CPPDEFAULT(= 0)) PURE;
    STDMETHOD(EnumErrorLogs)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumProcesses)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPCSTR szWho CPPDEFAULT(= NULL), long lWho CPPDEFAULT(= -1)) PURE;
    STDMETHOD(EnumLocks)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, long lWho CPPDEFAULT(= -1)) PURE;
    STDMETHOD(ReadBackupHeader)(THIS_ LPSQLDMORESTORE LoadSpec, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumAvailableMedia)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_MEDIA_TYPE MediaType CPPDEFAULT(= SQLDMOMedia_All)) PURE;
    STDMETHOD(EnumDirectories)(THIS_ SQLDMO_LPCSTR PathName, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumServerAttributes)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumVersionInfo)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPCSTR szPrefixes CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(BeginTransaction)(THIS_ SQLDMO_LPCSTR szTransactionName CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(CommitTransaction)(THIS_ SQLDMO_LPCSTR TransactionName CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(SaveTransaction)(THIS_ SQLDMO_LPCSTR SavepointName) PURE;
    STDMETHOD(RollbackTransaction)(THIS_ SQLDMO_LPCSTR TransactionOrSavepointName CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(CommandShellImmediate)(THIS_ SQLDMO_LPCSTR Command) PURE;
    STDMETHOD(CommandShellWithResults)(THIS_ SQLDMO_LPCSTR Command, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(Pause)(THIS) PURE;
    STDMETHOD(Continue)(THIS) PURE;
    STDMETHOD(Shutdown)(THIS_ BOOL Wait CPPDEFAULT(= TRUE)) PURE;
    STDMETHOD(Start)(THIS_ BOOL fConnect, SQLDMO_LPCSTR Server CPPDEFAULT(= NULL), SQLDMO_LPCSTR Login CPPDEFAULT(= NULL), SQLDMO_LPCSTR Password CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(VerifyConnection)(THIS_ LPBOOL pRetVal, SQLDMO_VERIFYCONN_TYPE VerifyType CPPDEFAULT(= SQLDMOConn_ReconnectIfDead)) PURE;
    STDMETHOD(IsOS)(THIS_ SQLDMO_OS_TYPE lType, LPBOOL pRetVal) PURE;
    STDMETHOD(AddStartParameter)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

        // List methods
    STDMETHOD(ListStartupProcedures)(THIS_ LPSQLDMOSTOREDPROCEDURELIST * ppList) PURE;

        // Post-6.0 additions
    STDMETHOD(ExecuteWithResultsAndMessages)(THIS_ SQLDMO_LPCSTR Command, LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPBSTR ppszMessages CPPDEFAULT(= 0), long lLength CPPDEFAULT(= 0)) PURE;
    STDMETHOD(GetNetName)(THIS_ SQLDMO_LPBSTR pbstrNetName) PURE;
    STDMETHOD(EnumLoginMappings)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;

    // Post-6.5 additions to object properties
    STDMETHOD(GetReplication)(THIS_ LPSQLDMOREPLICATION *ppReplication) PURE;
    STDMETHOD(GetEnableBcp)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetEnableBcp)(THIS_ BOOL NewValue) PURE;

    STDMETHOD(GetBlockingTimeout)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetBlockingTimeout)(THIS_ long NewValue) PURE;

    // 7.0 collection properties
    STDMETHOD(GetServerRoles)(THIS_ LPSQLDMOSERVERROLES *ppServerRoles) PURE;
    STDMETHOD(GetServerRoleByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOSERVERROLE *ppServerRole) PURE;
    STDMETHOD(GetServerRoleByOrd)(THIS_ long lOrdinal, LPSQLDMOSERVERROLE *ppServerRole) PURE;
    STDMETHOD(GetServerRoleCount)(THIS_ LPLONG plCount) PURE;
    STDMETHOD(EnumNTDomainGroups)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPCSTR Domain CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(EnumAccountInfo)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPCSTR Account CPPDEFAULT(= NULL), BOOL ListAll CPPDEFAULT(= FALSE)) PURE;
    STDMETHOD(ListMembers)(THIS_ SQLDMO_ROLE_TYPE Type, LPSQLDMONAMELIST *ppResults) PURE;
    STDMETHOD(IsLogin)(THIS_ SQLDMO_LPCSTR LoginName, LPBOOL pRetVal) PURE;
    STDMETHOD(Abort)(THIS) PURE;
    STDMETHOD(GetIsdbcreator)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsdiskadmin)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsprocessadmin)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIssecurityadmin)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsserveradmin)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIssetupadmin)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIssysadmin)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(DetachDB)(THIS_ SQLDMO_LPCSTR DBName, SQLDMO_LPBSTR pResult, BOOL bCheck CPPDEFAULT(= TRUE)) PURE;
    STDMETHOD(AttachDB)(THIS_ SQLDMO_LPCSTR DBName, SQLDMO_LPCSTR DataFiles, SQLDMO_LPBSTR pResult) PURE;
//    STDMETHOD(RemapFile)(THIS_ SQLDMO_LPCSTR DBName, SQLDMO_LPCSTR LogicalName, SQLDMO_LPCSTR NewPhysicalPath, SQLDMO_LPBSTR pResult) PURE;
//    STDMETHOD(ClearMap)(THIS_ SQLDMO_LPBSTR pResult) PURE;
    STDMETHOD(GetQuotedIdentifier)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetQuotedIdentifier)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetLinkedServers)(THIS_ LPSQLDMOLINKEDSERVERS *ppLinkedServers) PURE;
    STDMETHOD(GetLinkedServerByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOLINKEDSERVER *ppLinkedServer) PURE;
    STDMETHOD(GetLinkedServerByOrd)(THIS_ long lOrdinal, LPSQLDMOLINKEDSERVER *ppLinkedServer) PURE;
    STDMETHOD(RemoveLinkedServerByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveLinkedServerByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddLinkedServer)(THIS_ LPSQLDMOLINKEDSERVER pLinkedServer) PURE;
    STDMETHOD(GetLinkedServerCount)(THIS_ LPLONG plCount) PURE;
    STDMETHOD(SetCodePageOverride)(THIS_ long NewValue) PURE;
    STDMETHOD(GetFullTextService)(THIS_ LPSQLDMOFULLTEXTSERVICE *ppFullTextService) PURE;
    STDMETHOD(GetODBCPrefix)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetODBCPrefix)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(Stop)(THIS) PURE;
    STDMETHOD(PingSQLServerVersion)(THIS_ SQLDMO_SQL_VER *pRetVal, SQLDMO_LPCSTR szServerName CPPDEFAULT(= NULL), SQLDMO_LPCSTR szLogin CPPDEFAULT(= NULL), SQLDMO_LPCSTR szPassword CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(IsPackage)(THIS_ SQLDMO_PACKAGE_TYPE *pRetVal) PURE;
    STDMETHOD(GetRegionalSetting)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetRegionalSetting)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCodePage)(THIS_ LPLONG plCount) PURE;
    STDMETHOD(AttachDBWithSingleFile)(THIS_ SQLDMO_LPCSTR DBName, SQLDMO_LPCSTR DataFile, SQLDMO_LPBSTR pResult) PURE;
    STDMETHOD(IsNTGroupMember)(THIS_ SQLDMO_LPCSTR NTGroup, SQLDMO_LPCSTR NTUser, LPBOOL pRetVal) PURE;
    STDMETHOD(GetServerTime)(THIS_ SQLDMO_LPBSTR pbstrServerTime) PURE;
    STDMETHOD(GetTranslateChar)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetTranslateChar)(THIS_ BOOL NewValue) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(GetAutoStart)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAutoStart)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetStartupAccount)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(IsDetachedPrimaryFile)(THIS_ SQLDMO_LPCSTR MDFName, LPBOOL pRetVal) PURE;
    STDMETHOD(ListDetachedDBFiles)(THIS_ SQLDMO_LPCSTR MDFName, LPSQLDMONAMELIST *ppFileNames) PURE;
    STDMETHOD(DetachedDBInfo)(THIS_ SQLDMO_LPCSTR MDFName, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(ListCompatibilityLevels)(THIS_ LPSQLDMONAMELIST *ppNames) PURE;
    STDMETHOD(ListCollations)(THIS_ LPSQLDMONAMELIST *ppNames) PURE;
    STDMETHOD(ListDetachedLogFiles)(THIS_ SQLDMO_LPCSTR MDFName, LPSQLDMONAMELIST *ppFileNames) PURE;
    STDMETHOD(ServerLoginMode)(THIS_ SQLDMO_LPCSTR ServerName, SQLDMO_SECURITY_TYPE *pRetVal) PURE;
    STDMETHOD(GetInstanceName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetServiceName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetPID)(THIS_ LPLONG plPID) PURE;
    STDMETHOD(GetIsClustered)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetCollation)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetIsFullTextInstalled)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(AttachDBWithSingleFile2)(THIS_ SQLDMO_LPCSTR DBName, SQLDMO_LPCSTR DataFile, LPBOOL pRetVal) PURE;
    STDMETHOD(ListInstalledInstances)(THIS_ LPSQLDMONAMELIST *ppServerNames, SQLDMO_LPCSTR ServerName CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(InstalledInstanceInfo)(THIS_ SQLDMO_LPCSTR ServerName, LPLONG plMajor, LPLONG plMinor) PURE;
    STDMETHOD(EnumCollations)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(GetProductLevel)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetIsbulkadmin)(THIS_ LPBOOL pRetVal) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOServerSink
DECLARE_INTERFACE_(INTERFACE, IUnknown)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** Sink properties and methods.
    STDMETHOD(QueryTimeout)(THIS_ SQLDMO_LPCSTR Message, LPBOOL Continue) PURE;
    STDMETHOD(ServerMessage)(THIS_ long Severity, long MessageNumber, long MessageState, SQLDMO_LPCSTR Message) PURE;
    STDMETHOD(ConnectionBroken)(THIS_ SQLDMO_LPCSTR Message, LPBOOL Retry) PURE;
    STDMETHOD(RemoteLoginFailed)(THIS_ long Severity, long MessageNumber, long MessageState, SQLDMO_LPCSTR Message) PURE;
        STDMETHOD(CommandSent)(THIS_ SQLDMO_LPCSTR szSQL) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMORegistry
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetAutostartMail)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAutostartMail)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetAutostartServer)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAutostartServer)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCaseSensitive)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetCharacterSet)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetErrorLogPath)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetErrorLogPath)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetMailAccountName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetMailAccountName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetMailPassword)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetMailPassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetMasterDBPath)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetMasterDBPath)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetNTEventLogging)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetNumberOfProcessors)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetPerfMonMode)(THIS_ SQLDMO_PERFMON_TYPE *pRetVal) PURE;
    STDMETHOD(SetPerfMonMode)(THIS_ SQLDMO_PERFMON_TYPE NewValue) PURE;
    STDMETHOD(GetPhysicalMemory)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetAutostartLicensing)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAutostartLicensing)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetRegisteredOrganization)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetRegisteredOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetSortOrder)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetSQLRootPath)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSQLRootPath)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSQLDataRoot)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSQLDataRoot)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetTapeLoadWaitTime)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetTapeLoadWaitTime)(THIS_ long NewValue) PURE;
    STDMETHOD(GetReplicationInstalled)(THIS_ LPBOOL pRetVal) PURE;

    // 7.0
    STDMETHOD(GetAutostartDTC)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAutostartDTC)(THIS_ BOOL NewValue) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMORegistry2
DECLARE_INTERFACE_(INTERFACE, ISQLDMORegistry)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetAutostartMail)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAutostartMail)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetAutostartServer)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAutostartServer)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCaseSensitive)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetCharacterSet)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetErrorLogPath)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetErrorLogPath)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetMailAccountName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetMailAccountName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetMailPassword)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetMailPassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetMasterDBPath)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetMasterDBPath)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetNTEventLogging)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetNumberOfProcessors)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetPerfMonMode)(THIS_ SQLDMO_PERFMON_TYPE *pRetVal) PURE;
    STDMETHOD(SetPerfMonMode)(THIS_ SQLDMO_PERFMON_TYPE NewValue) PURE;
    STDMETHOD(GetPhysicalMemory)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetAutostartLicensing)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAutostartLicensing)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetRegisteredOrganization)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetRegisteredOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetSortOrder)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetSQLRootPath)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSQLRootPath)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSQLDataRoot)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSQLDataRoot)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetTapeLoadWaitTime)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetTapeLoadWaitTime)(THIS_ long NewValue) PURE;
    STDMETHOD(GetReplicationInstalled)(THIS_ LPBOOL pRetVal) PURE;

    // 7.0
    STDMETHOD(GetAutostartDTC)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAutostartDTC)(THIS_ BOOL NewValue) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(GetBackupDirectory)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetBackupDirectory)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetAgentLogFile)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetAgentLogFile)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

    // Server Network Utility Protocols
    STDMETHOD(GetSuperSocketEncrypt)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetSuperSocketEncrypt)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetSuperSocketList)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSuperSocketList)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetNP)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetNP)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetTcpFlag)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetTcpFlag)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetTcpPort)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetTcpPort)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSpxFlag)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetSpxFlag)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetSpxPort)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetSpxPort)(THIS_ long NewValue) PURE;
    STDMETHOD(GetSpxServiceName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSpxServiceName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetAdsp)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetAdsp)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetRpcEncrypt)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetRpcEncrypt)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetRpcList)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetRpcList)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetRpcMinCalls)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetRpcMinCalls)(THIS_ long NewValue) PURE;
    STDMETHOD(GetRpcMaxCalls)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetRpcMaxCalls)(THIS_ long NewValue) PURE;
    STDMETHOD(GetVinesItemName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetVinesItemName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetVinesGroupName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetVinesGroupName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetVinesOrgName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetVinesOrgName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetWSProxyPort)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetWSProxyPort)(THIS_ long NewValue) PURE;
    STDMETHOD(GetWSProxyAddress)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetWSProxyAddress)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    // Server Network Utility Misc.
    STDMETHOD(GetSQLCurrentVersion)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetSNMP)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetSNMPCurrentVersion)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSNMPCurrentVersion)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSNMPExtensionAgents)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetSNMPExtensionAgentsData)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSNMPExtensionAgentsData)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(EnumFullTextLanguages)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    // Server Network Utility new Protocol
    STDMETHOD(GetViaVendor)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetViaVendor)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetViaListenInfo)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetViaListenInfo)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetViaRecognizedVendors)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMODatabases
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
        STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMODATABASE *ppObj) PURE;
        STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMODATABASE *ppObj, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMODATABASE *ppObj) PURE;
        STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
        STDMETHOD(Add)(THIS_ LPSQLDMODATABASE Object) PURE;
        STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
        STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
        STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMODatabase
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetOwner)(THIS_ SQLDMO_LPCSTR NewValue, BOOL bTransferAliases CPPDEFAULT(= FALSE), BOOL bOverrideIfAlreadyUser CPPDEFAULT(= FALSE)) PURE;
    STDMETHOD(GetVersion)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetCreateDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetUserName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetUserName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSize)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetSpaceAvailable)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetSystemObject)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetUserProfile)(THIS_ SQLDMO_DBUSERPROFILE_TYPE *pProfileBits) PURE;
    STDMETHOD(GetDataSpaceUsage)(THIS_ LPFLOAT pRetVal) PURE;
    STDMETHOD(GetStatus)(THIS_ SQLDMO_DBSTATUS_TYPE *pRetVal) PURE;
    STDMETHOD(GetIndexSpaceUsage)(THIS_ LPFLOAT pRetVal) PURE;
    STDMETHOD(GetSpaceAvailableInMB)(THIS_ LPFLOAT pRetVal) PURE;
    STDMETHOD(GetCreateForAttach)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCreateForAttach)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetDboLogin)(THIS_ LPBOOL pRetVal) PURE;

        //*** Object Properties
    STDMETHOD(GetDBOption)(THIS_ LPSQLDMODBOPTION *ppDBOption) PURE;
    STDMETHOD(GetTransactionLog)(THIS_ LPSQLDMOTRANSACTIONLOG * ppTransactionLog) PURE;

        //*** Collection properties
    STDMETHOD(GetTables)(THIS_ LPSQLDMOTABLES * ppTables) PURE;
    STDMETHOD(GetTableByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTABLE *ppTable, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetTableByOrd)(THIS_ long lOrdinal, LPSQLDMOTABLE *ppTable) PURE;
    STDMETHOD(RemoveTableByName)(THIS_ SQLDMO_LPCSTR szName, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RemoveTableByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddTable)(THIS_ LPSQLDMOTABLE pTable) PURE;
    STDMETHOD(GetTableCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetViews)(THIS_ LPSQLDMOVIEWS * ppViews) PURE;
    STDMETHOD(GetViewByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOVIEW *ppView, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetViewByOrd)(THIS_ long lOrdinal, LPSQLDMOVIEW *ppView) PURE;
    STDMETHOD(RemoveViewByName)(THIS_ SQLDMO_LPCSTR szName, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RemoveViewByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddView)(THIS_ LPSQLDMOVIEW pView) PURE;
    STDMETHOD(GetViewCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetStoredProcedures)(THIS_ LPSQLDMOSTOREDPROCEDURES * ppProcs) PURE;
    STDMETHOD(GetStoredProcedureByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOSTOREDPROCEDURE *ppProc, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetStoredProcedureByOrd)(THIS_ long lOrdinal, LPSQLDMOSTOREDPROCEDURE *ppProc) PURE;
    STDMETHOD(RemoveStoredProcedureByName)(THIS_ SQLDMO_LPCSTR szName, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RemoveStoredProcedureByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddStoredProcedure)(THIS_ LPSQLDMOSTOREDPROCEDURE pProc) PURE;
    STDMETHOD(GetStoredProcedureCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetDefaults)(THIS_ LPSQLDMODEFAULTS * ppDefaults) PURE;
    STDMETHOD(GetDefaultByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMODEFAULT *ppDefault, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetDefaultByOrd)(THIS_ long lOrdinal, LPSQLDMODEFAULT *ppDefault) PURE;
    STDMETHOD(RemoveDefaultByName)(THIS_ SQLDMO_LPCSTR szName, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RemoveDefaultByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddDefault)(THIS_ LPSQLDMODEFAULT pDefault) PURE;
    STDMETHOD(GetDefaultCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetRules)(THIS_ LPSQLDMORULES * ppRules) PURE;
    STDMETHOD(GetRuleByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMORULE *ppRule, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetRuleByOrd)(THIS_ long lOrdinal, LPSQLDMORULE *ppRule) PURE;
    STDMETHOD(RemoveRuleByName)(THIS_ SQLDMO_LPCSTR szName, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RemoveRuleByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddRule)(THIS_ LPSQLDMORULE pRule) PURE;
    STDMETHOD(GetRuleCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetUserDefinedDatatypes)(THIS_ LPSQLDMOUSERDEFINEDDATATYPES * ppUDDTs) PURE;
    STDMETHOD(GetUserDefinedDatatypeByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOUSERDEFINEDDATATYPE *ppUDDT, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetUserDefinedDatatypeByOrd)(THIS_ long lOrdinal, LPSQLDMOUSERDEFINEDDATATYPE *ppUDDT) PURE;
    STDMETHOD(RemoveUserDefinedDatatypeByName)(THIS_ SQLDMO_LPCSTR szName, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RemoveUserDefinedDatatypeByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddUserDefinedDatatype)(THIS_ LPSQLDMOUSERDEFINEDDATATYPE pUDDT) PURE;
    STDMETHOD(GetUserDefinedDatatypeCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetUsers)(THIS_ LPSQLDMOUSERS * ppUsers) PURE;
    STDMETHOD(GetUserByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOUSER *ppUser) PURE;
    STDMETHOD(GetUserByOrd)(THIS_ long lOrdinal, LPSQLDMOUSER *ppUser) PURE;
    STDMETHOD(RemoveUserByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveUserByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddUser)(THIS_ LPSQLDMOUSER pUser) PURE;
    STDMETHOD(GetUserCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetGroups)(THIS_ LPSQLDMOGROUPS * ppGroups) PURE;
    STDMETHOD(GetGroupByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOGROUP *ppGroup) PURE;
    STDMETHOD(GetGroupByOrd)(THIS_ long lOrdinal, LPSQLDMOGROUP *ppGroup) PURE;
    STDMETHOD(RemoveGroupByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveGroupByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddGroup)(THIS_ LPSQLDMOGROUP pGroup) PURE;
    STDMETHOD(GetGroupCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetSystemDatatypes)(THIS_ LPSQLDMOSYSTEMDATATYPES * ppSDTs) PURE;
    STDMETHOD(GetSystemDatatypeByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOSYSTEMDATATYPE *ppSDT) PURE;
    STDMETHOD(GetSystemDatatypeByOrd)(THIS_ long lOrdinal, LPSQLDMOSYSTEMDATATYPE *ppSDT) PURE;
    STDMETHOD(GetSystemDatatypeCount)(THIS_ LPLONG plCount) PURE;

        //*** Methods
    STDMETHOD(Grant)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR GranteeNames) PURE;
    STDMETHOD(Revoke)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR RevokeeNames) PURE;
    STDMETHOD(ExecuteImmediate)(THIS_ SQLDMO_LPCSTR Command, SQLDMO_EXEC_TYPE ExecType CPPDEFAULT(= SQLDMOExec_Default), long lLength CPPDEFAULT(= 0)) PURE;
    STDMETHOD(ExecuteWithResults)(THIS_ SQLDMO_LPCSTR Command, LPSQLDMOQUERYRESULTS *ppResults, long lLength CPPDEFAULT(= 0)) PURE;
    STDMETHOD(Checkpoint)(THIS) PURE;
    STDMETHOD(CheckTables)(THIS_ SQLDMO_LPBSTR pResult, SQLDMO_DBCC_REPAIR_TYPE lType CPPDEFAULT(= SQLDMORepair_None)) PURE;
    STDMETHOD(CheckAllocations)(THIS_ SQLDMO_LPBSTR pResult, SQLDMO_DBCC_REPAIR_TYPE lType CPPDEFAULT(= SQLDMORepair_None)) PURE;
    STDMETHOD(CheckCatalog)(THIS_ SQLDMO_LPBSTR pResult) PURE;
    STDMETHOD(GetMemoryUsage)(THIS_ SQLDMO_LPBSTR pResult) PURE;
    STDMETHOD(EnumLocks)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, long lWho CPPDEFAULT(= -1)) PURE;
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(GetObjectByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMODBOBJECT *ppDBObject, SQLDMO_OBJECT_TYPE lType CPPDEFAULT(= SQLDMOObj_AllDatabaseObjects), SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetDatatypeByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOSTDOBJECT *ppDBObject) PURE;
    STDMETHOD(EnumCandidateKeys)(THIS_ LPSQLDMOQUERYRESULTS * ppResults) PURE;
    STDMETHOD(IsValidKeyDatatype)(THIS_ SQLDMO_LPCSTR szKeyColType, LPBOOL pRetVal, SQLDMO_LPCSTR szReferencingColType CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RecalcSpaceUsage)(THIS) PURE;
    STDMETHOD(EnumDependencies)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_DEPENDENCY_TYPE DependencyType CPPDEFAULT(= SQLDMODep_Parents)) PURE;

        //*** List methods
    STDMETHOD(ListObjectPermissions)(THIS_ LPSQLDMOPERMISSIONLIST * ppList, SQLDMO_PRIVILEGE_TYPE lPrivilegeTypes CPPDEFAULT(= SQLDMOPriv_AllObjectPrivs)) PURE;
    STDMETHOD(ListDatabasePermissions)(THIS_ LPSQLDMOPERMISSIONLIST * ppList, SQLDMO_PRIVILEGE_TYPE lPrivilegeTypes CPPDEFAULT(= SQLDMOPriv_AllDatabasePrivs)) PURE;
    STDMETHOD(ListObjects)(THIS_ LPSQLDMODBOBJECTLIST * ppList, SQLDMO_OBJECT_TYPE lObjectTypes CPPDEFAULT(= SQLDMOObj_AllDatabaseObjects), SQLDMO_OBJSORT_TYPE SortBy CPPDEFAULT(= SQLDMOObjSort_Name)) PURE;

        // Post-6.0 additions
    STDMETHOD(Transfer)(THIS_ LPSQLDMOTRANSFER TransferSpec) PURE;
    STDMETHOD(ScriptTransfer)(THIS_ LPSQLDMOTRANSFER TransferSpec, SQLDMO_XFRSCRIPTMODE_TYPE ScriptFileMode CPPDEFAULT(= SQLDMOXfrFile_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
        STDMETHOD(CheckIdentityValues)(THIS) PURE;
    STDMETHOD(ExecuteWithResultsAndMessages)(THIS_ SQLDMO_LPCSTR Command, LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPBSTR ppszMessages CPPDEFAULT(= 0), long lLength CPPDEFAULT(= 0)) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
    STDMETHOD(CheckTablesDataOnly)(THIS_ SQLDMO_LPBSTR pResult) PURE;
    STDMETHOD(CheckAllocationsDataOnly)(THIS_ SQLDMO_LPBSTR pResult) PURE;
        STDMETHOD(UpdateIndexStatistics)(THIS) PURE;
    STDMETHOD(EnumLoginMappings)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;

    // 7.0
    STDMETHOD(GetPrimaryFilePath)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetFileGroups)(THIS_ LPSQLDMOFILEGROUPS * ppFileGroups) PURE;
    STDMETHOD(GetFileGroupByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOFILEGROUP *ppFileGroup) PURE;
    STDMETHOD(GetFileGroupByOrd)(THIS_ long lOrdinal, LPSQLDMOFILEGROUP *ppFileGroup) PURE;
    STDMETHOD(RemoveFileGroupByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveFileGroupByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddFileGroup)(THIS_ LPSQLDMOFILEGROUP pFileGroup) PURE;
    STDMETHOD(GetFileGroupCount)(THIS_ LPLONG plCount) PURE;
    STDMETHOD(GetDatabaseRoles)(THIS_ LPSQLDMODATABASEROLES * ppDatabaseRoles) PURE;
    STDMETHOD(GetDatabaseRoleByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMODATABASEROLE *ppDatabaseRole) PURE;
    STDMETHOD(GetDatabaseRoleByOrd)(THIS_ long lOrdinal, LPSQLDMODATABASEROLE *ppDatabaseRole) PURE;
    STDMETHOD(RemoveDatabaseRoleByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveDatabaseRoleByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddDatabaseRole)(THIS_ LPSQLDMODATABASEROLE pDatabaseRole) PURE;
    STDMETHOD(GetDatabaseRoleCount)(THIS_ LPLONG plCount) PURE;
    STDMETHOD(GetPermissions)(THIS_ SQLDMO_PRIVILEGE_TYPE *Permissions) PURE;
    STDMETHOD(EnumFiles)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumFileGroups)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumUsers)(THIS_ LPSQLDMOQUERYRESULTS * ppResults, LPCOLESTR UserName CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(EnumNTGroups)(THIS_ LPSQLDMOQUERYRESULTS * ppResults, LPCOLESTR GroupName CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(Deny)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR DenyeeNames) PURE;
    STDMETHOD(IsUser)(THIS_ SQLDMO_LPCSTR UserName, LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsdb_accessadmin)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsdb_datareader)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsdb_ddladmin)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsdb_denydatareader)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsdb_denydatawriter)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsdb_backupoperator)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsdb_owner)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsdb_securityadmin)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsdb_datawriter)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GenerateSQL)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(Shrink)(THIS_ long lFreeSpaceInPercent, SQLDMO_SHRINK_TYPE Truncate) PURE;
    // Following CheckTextAllocsXXXX are for backward compatible
    STDMETHOD(CheckTextAllocsFast)(THIS_ SQLDMO_LPBSTR pResult) PURE;
    STDMETHOD(CheckTextAllocsFull)(THIS_ SQLDMO_LPBSTR pResult) PURE;
    STDMETHOD(EnumMatchingSPs)(THIS_ LPCOLESTR Text, LPSQLDMOQUERYRESULTS * ppResults, BOOL IncSys CPPDEFAULT (= FALSE)) PURE;
    STDMETHOD(EnableFullTextCatalogs)(THIS) PURE;
    STDMETHOD(RemoveFullTextCatalogs)(THIS) PURE;
    STDMETHOD(FullTextIndexScript)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetIsFullTextEnabled)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetFullTextCatalogs)(THIS_ LPSQLDMOFULLTEXTCATALOGS * ppFullTextCatalogs) PURE;
    STDMETHOD(GetFullTextCatalogByName)(THIS_ LPCOLESTR szName, LPSQLDMOFULLTEXTCATALOG *ppFullTextCatalog) PURE;
    STDMETHOD(GetFullTextCatalogByOrd)(THIS_ long lOrdinal, LPSQLDMOFULLTEXTCATALOG *ppFullTextCatalog) PURE;
    STDMETHOD(RemoveFullTextCatalogByName)(THIS_ LPCOLESTR szName) PURE;
    STDMETHOD(RemoveFullTextCatalogByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddFullTextCatalog)(THIS_ LPSQLDMOFULLTEXTCATALOG pFullTextCatalog) PURE;
    STDMETHOD(GetFullTextCatalogCount)(THIS_ LPLONG plCount) PURE;
    STDMETHOD(DisableFullTextCatalogs)(THIS) PURE;
    STDMETHOD(GetCompatibilityLevel)(THIS_ SQLDMO_COMP_LEVEL_TYPE * pRetVal) PURE;
    STDMETHOD(SetCompatibilityLevel)(THIS_ SQLDMO_COMP_LEVEL_TYPE NewValue) PURE;
    STDMETHOD(GetUseServerName)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(SetUseServerName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMODatabase2
DECLARE_INTERFACE_(INTERFACE, ISQLDMODatabase)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetOwner)(THIS_ SQLDMO_LPCSTR NewValue, BOOL bTransferAliases CPPDEFAULT(= FALSE), BOOL bOverrideIfAlreadyUser CPPDEFAULT(= FALSE)) PURE;
    STDMETHOD(GetVersion)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetCreateDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetUserName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetUserName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSize)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetSpaceAvailable)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetSystemObject)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetUserProfile)(THIS_ SQLDMO_DBUSERPROFILE_TYPE *pProfileBits) PURE;
    STDMETHOD(GetDataSpaceUsage)(THIS_ LPFLOAT pRetVal) PURE;
    STDMETHOD(GetStatus)(THIS_ SQLDMO_DBSTATUS_TYPE *pRetVal) PURE;
    STDMETHOD(GetIndexSpaceUsage)(THIS_ LPFLOAT pRetVal) PURE;
    STDMETHOD(GetSpaceAvailableInMB)(THIS_ LPFLOAT pRetVal) PURE;
    STDMETHOD(GetCreateForAttach)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCreateForAttach)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetDboLogin)(THIS_ LPBOOL pRetVal) PURE;

        //*** Object Properties
    STDMETHOD(GetDBOption)(THIS_ LPSQLDMODBOPTION *ppDBOption) PURE;
    STDMETHOD(GetTransactionLog)(THIS_ LPSQLDMOTRANSACTIONLOG * ppTransactionLog) PURE;

        //*** Collection properties
    STDMETHOD(GetTables)(THIS_ LPSQLDMOTABLES * ppTables) PURE;
    STDMETHOD(GetTableByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTABLE *ppTable, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetTableByOrd)(THIS_ long lOrdinal, LPSQLDMOTABLE *ppTable) PURE;
    STDMETHOD(RemoveTableByName)(THIS_ SQLDMO_LPCSTR szName, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RemoveTableByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddTable)(THIS_ LPSQLDMOTABLE pTable) PURE;
    STDMETHOD(GetTableCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetViews)(THIS_ LPSQLDMOVIEWS * ppViews) PURE;
    STDMETHOD(GetViewByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOVIEW *ppView, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetViewByOrd)(THIS_ long lOrdinal, LPSQLDMOVIEW *ppView) PURE;
    STDMETHOD(RemoveViewByName)(THIS_ SQLDMO_LPCSTR szName, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RemoveViewByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddView)(THIS_ LPSQLDMOVIEW pView) PURE;
    STDMETHOD(GetViewCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetStoredProcedures)(THIS_ LPSQLDMOSTOREDPROCEDURES * ppProcs) PURE;
    STDMETHOD(GetStoredProcedureByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOSTOREDPROCEDURE *ppProc, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetStoredProcedureByOrd)(THIS_ long lOrdinal, LPSQLDMOSTOREDPROCEDURE *ppProc) PURE;
    STDMETHOD(RemoveStoredProcedureByName)(THIS_ SQLDMO_LPCSTR szName, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RemoveStoredProcedureByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddStoredProcedure)(THIS_ LPSQLDMOSTOREDPROCEDURE pProc) PURE;
    STDMETHOD(GetStoredProcedureCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetDefaults)(THIS_ LPSQLDMODEFAULTS * ppDefaults) PURE;
    STDMETHOD(GetDefaultByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMODEFAULT *ppDefault, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetDefaultByOrd)(THIS_ long lOrdinal, LPSQLDMODEFAULT *ppDefault) PURE;
    STDMETHOD(RemoveDefaultByName)(THIS_ SQLDMO_LPCSTR szName, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RemoveDefaultByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddDefault)(THIS_ LPSQLDMODEFAULT pDefault) PURE;
    STDMETHOD(GetDefaultCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetRules)(THIS_ LPSQLDMORULES * ppRules) PURE;
    STDMETHOD(GetRuleByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMORULE *ppRule, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetRuleByOrd)(THIS_ long lOrdinal, LPSQLDMORULE *ppRule) PURE;
    STDMETHOD(RemoveRuleByName)(THIS_ SQLDMO_LPCSTR szName, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RemoveRuleByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddRule)(THIS_ LPSQLDMORULE pRule) PURE;
    STDMETHOD(GetRuleCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetUserDefinedDatatypes)(THIS_ LPSQLDMOUSERDEFINEDDATATYPES * ppUDDTs) PURE;
    STDMETHOD(GetUserDefinedDatatypeByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOUSERDEFINEDDATATYPE *ppUDDT, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetUserDefinedDatatypeByOrd)(THIS_ long lOrdinal, LPSQLDMOUSERDEFINEDDATATYPE *ppUDDT) PURE;
    STDMETHOD(RemoveUserDefinedDatatypeByName)(THIS_ SQLDMO_LPCSTR szName, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RemoveUserDefinedDatatypeByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddUserDefinedDatatype)(THIS_ LPSQLDMOUSERDEFINEDDATATYPE pUDDT) PURE;
    STDMETHOD(GetUserDefinedDatatypeCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetUsers)(THIS_ LPSQLDMOUSERS * ppUsers) PURE;
    STDMETHOD(GetUserByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOUSER *ppUser) PURE;
    STDMETHOD(GetUserByOrd)(THIS_ long lOrdinal, LPSQLDMOUSER *ppUser) PURE;
    STDMETHOD(RemoveUserByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveUserByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddUser)(THIS_ LPSQLDMOUSER pUser) PURE;
    STDMETHOD(GetUserCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetGroups)(THIS_ LPSQLDMOGROUPS * ppGroups) PURE;
    STDMETHOD(GetGroupByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOGROUP *ppGroup) PURE;
    STDMETHOD(GetGroupByOrd)(THIS_ long lOrdinal, LPSQLDMOGROUP *ppGroup) PURE;
    STDMETHOD(RemoveGroupByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveGroupByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddGroup)(THIS_ LPSQLDMOGROUP pGroup) PURE;
    STDMETHOD(GetGroupCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetSystemDatatypes)(THIS_ LPSQLDMOSYSTEMDATATYPES * ppSDTs) PURE;
    STDMETHOD(GetSystemDatatypeByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOSYSTEMDATATYPE *ppSDT) PURE;
    STDMETHOD(GetSystemDatatypeByOrd)(THIS_ long lOrdinal, LPSQLDMOSYSTEMDATATYPE *ppSDT) PURE;
    STDMETHOD(GetSystemDatatypeCount)(THIS_ LPLONG plCount) PURE;

        //*** Methods
    STDMETHOD(Grant)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR GranteeNames) PURE;
    STDMETHOD(Revoke)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR RevokeeNames) PURE;
    STDMETHOD(ExecuteImmediate)(THIS_ SQLDMO_LPCSTR Command, SQLDMO_EXEC_TYPE ExecType CPPDEFAULT(= SQLDMOExec_Default), long lLength CPPDEFAULT(= 0)) PURE;
    STDMETHOD(ExecuteWithResults)(THIS_ SQLDMO_LPCSTR Command, LPSQLDMOQUERYRESULTS *ppResults, long lLength CPPDEFAULT(= 0)) PURE;
    STDMETHOD(Checkpoint)(THIS) PURE;
    STDMETHOD(CheckTables)(THIS_ SQLDMO_LPBSTR pResult, SQLDMO_DBCC_REPAIR_TYPE lType CPPDEFAULT(= SQLDMORepair_None)) PURE;
    STDMETHOD(CheckAllocations)(THIS_ SQLDMO_LPBSTR pResult, SQLDMO_DBCC_REPAIR_TYPE lType CPPDEFAULT(= SQLDMORepair_None)) PURE;
    STDMETHOD(CheckCatalog)(THIS_ SQLDMO_LPBSTR pResult) PURE;
    STDMETHOD(GetMemoryUsage)(THIS_ SQLDMO_LPBSTR pResult) PURE;
    STDMETHOD(EnumLocks)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, long lWho CPPDEFAULT(= -1)) PURE;
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(GetObjectByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMODBOBJECT *ppDBObject, SQLDMO_OBJECT_TYPE lType CPPDEFAULT(= SQLDMOObj_AllDatabaseObjects), SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetDatatypeByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOSTDOBJECT *ppDBObject) PURE;
    STDMETHOD(EnumCandidateKeys)(THIS_ LPSQLDMOQUERYRESULTS * ppResults) PURE;
    STDMETHOD(IsValidKeyDatatype)(THIS_ SQLDMO_LPCSTR szKeyColType, LPBOOL pRetVal, SQLDMO_LPCSTR szReferencingColType CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RecalcSpaceUsage)(THIS) PURE;
    STDMETHOD(EnumDependencies)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_DEPENDENCY_TYPE DependencyType CPPDEFAULT(= SQLDMODep_Parents)) PURE;

        //*** List methods
    STDMETHOD(ListObjectPermissions)(THIS_ LPSQLDMOPERMISSIONLIST * ppList, SQLDMO_PRIVILEGE_TYPE lPrivilegeTypes CPPDEFAULT(= SQLDMOPriv_AllObjectPrivs)) PURE;
    STDMETHOD(ListDatabasePermissions)(THIS_ LPSQLDMOPERMISSIONLIST * ppList, SQLDMO_PRIVILEGE_TYPE lPrivilegeTypes CPPDEFAULT(= SQLDMOPriv_AllDatabasePrivs)) PURE;
    STDMETHOD(ListObjects)(THIS_ LPSQLDMODBOBJECTLIST * ppList, SQLDMO_OBJECT_TYPE lObjectTypes CPPDEFAULT(= SQLDMOObj_AllDatabaseObjects), SQLDMO_OBJSORT_TYPE SortBy CPPDEFAULT(= SQLDMOObjSort_Name)) PURE;

        // Post-6.0 additions
    STDMETHOD(Transfer)(THIS_ LPSQLDMOTRANSFER TransferSpec) PURE;
    STDMETHOD(ScriptTransfer)(THIS_ LPSQLDMOTRANSFER TransferSpec, SQLDMO_XFRSCRIPTMODE_TYPE ScriptFileMode CPPDEFAULT(= SQLDMOXfrFile_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
        STDMETHOD(CheckIdentityValues)(THIS) PURE;
    STDMETHOD(ExecuteWithResultsAndMessages)(THIS_ SQLDMO_LPCSTR Command, LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPBSTR ppszMessages CPPDEFAULT(= 0), long lLength CPPDEFAULT(= 0)) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
    STDMETHOD(CheckTablesDataOnly)(THIS_ SQLDMO_LPBSTR pResult) PURE;
    STDMETHOD(CheckAllocationsDataOnly)(THIS_ SQLDMO_LPBSTR pResult) PURE;
        STDMETHOD(UpdateIndexStatistics)(THIS) PURE;
    STDMETHOD(EnumLoginMappings)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;

    // 7.0
    STDMETHOD(GetPrimaryFilePath)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetFileGroups)(THIS_ LPSQLDMOFILEGROUPS * ppFileGroups) PURE;
    STDMETHOD(GetFileGroupByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOFILEGROUP *ppFileGroup) PURE;
    STDMETHOD(GetFileGroupByOrd)(THIS_ long lOrdinal, LPSQLDMOFILEGROUP *ppFileGroup) PURE;
    STDMETHOD(RemoveFileGroupByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveFileGroupByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddFileGroup)(THIS_ LPSQLDMOFILEGROUP pFileGroup) PURE;
    STDMETHOD(GetFileGroupCount)(THIS_ LPLONG plCount) PURE;
    STDMETHOD(GetDatabaseRoles)(THIS_ LPSQLDMODATABASEROLES * ppDatabaseRoles) PURE;
    STDMETHOD(GetDatabaseRoleByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMODATABASEROLE *ppDatabaseRole) PURE;
    STDMETHOD(GetDatabaseRoleByOrd)(THIS_ long lOrdinal, LPSQLDMODATABASEROLE *ppDatabaseRole) PURE;
    STDMETHOD(RemoveDatabaseRoleByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveDatabaseRoleByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddDatabaseRole)(THIS_ LPSQLDMODATABASEROLE pDatabaseRole) PURE;
    STDMETHOD(GetDatabaseRoleCount)(THIS_ LPLONG plCount) PURE;
    STDMETHOD(GetPermissions)(THIS_ SQLDMO_PRIVILEGE_TYPE *Permissions) PURE;
    STDMETHOD(EnumFiles)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumFileGroups)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumUsers)(THIS_ LPSQLDMOQUERYRESULTS * ppResults, LPCOLESTR UserName CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(EnumNTGroups)(THIS_ LPSQLDMOQUERYRESULTS * ppResults, LPCOLESTR GroupName CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(Deny)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR DenyeeNames) PURE;
    STDMETHOD(IsUser)(THIS_ SQLDMO_LPCSTR UserName, LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsdb_accessadmin)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsdb_datareader)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsdb_ddladmin)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsdb_denydatareader)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsdb_denydatawriter)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsdb_backupoperator)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsdb_owner)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsdb_securityadmin)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsdb_datawriter)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GenerateSQL)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(Shrink)(THIS_ long lFreeSpaceInPercent, SQLDMO_SHRINK_TYPE Truncate) PURE;
    // Following CheckTextAllocsXXXX are for backward compatible
    STDMETHOD(CheckTextAllocsFast)(THIS_ SQLDMO_LPBSTR pResult) PURE;
    STDMETHOD(CheckTextAllocsFull)(THIS_ SQLDMO_LPBSTR pResult) PURE;
    STDMETHOD(EnumMatchingSPs)(THIS_ LPCOLESTR Text, LPSQLDMOQUERYRESULTS * ppResults, BOOL IncSys CPPDEFAULT (= FALSE)) PURE;
    STDMETHOD(EnableFullTextCatalogs)(THIS) PURE;
    STDMETHOD(RemoveFullTextCatalogs)(THIS) PURE;
    STDMETHOD(FullTextIndexScript)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetIsFullTextEnabled)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetFullTextCatalogs)(THIS_ LPSQLDMOFULLTEXTCATALOGS * ppFullTextCatalogs) PURE;
    STDMETHOD(GetFullTextCatalogByName)(THIS_ LPCOLESTR szName, LPSQLDMOFULLTEXTCATALOG *ppFullTextCatalog) PURE;
    STDMETHOD(GetFullTextCatalogByOrd)(THIS_ long lOrdinal, LPSQLDMOFULLTEXTCATALOG *ppFullTextCatalog) PURE;
    STDMETHOD(RemoveFullTextCatalogByName)(THIS_ LPCOLESTR szName) PURE;
    STDMETHOD(RemoveFullTextCatalogByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddFullTextCatalog)(THIS_ LPSQLDMOFULLTEXTCATALOG pFullTextCatalog) PURE;
    STDMETHOD(GetFullTextCatalogCount)(THIS_ LPLONG plCount) PURE;
    STDMETHOD(DisableFullTextCatalogs)(THIS) PURE;
    STDMETHOD(GetCompatibilityLevel)(THIS_ SQLDMO_COMP_LEVEL_TYPE * pRetVal) PURE;
    STDMETHOD(SetCompatibilityLevel)(THIS_ SQLDMO_COMP_LEVEL_TYPE NewValue) PURE;
    STDMETHOD(GetUseServerName)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(SetUseServerName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(CheckTablesWithResult)(THIS_ LPSQLDMOQUERYRESULTS * ppResults, SQLDMO_DBCC_REPAIR_TYPE lType CPPDEFAULT(= SQLDMORepair_None)) PURE;
    STDMETHOD(CheckAllocationsWithResult)(THIS_ LPSQLDMOQUERYRESULTS * ppResults, SQLDMO_DBCC_REPAIR_TYPE lType CPPDEFAULT(= SQLDMORepair_None)) PURE;
    STDMETHOD(CheckCatalogWithResult)(THIS_ LPSQLDMOQUERYRESULTS * ppResults) PURE;
    STDMETHOD(CheckTablesDataOnlyWithResult)(THIS_ LPSQLDMOQUERYRESULTS * ppResults) PURE;
    STDMETHOD(CheckAllocationsDataOnlyWithResult)(THIS_ LPSQLDMOQUERYRESULTS * ppResults) PURE;
    STDMETHOD(SetCurrentCompatibility)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetCurrentCompatibility)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;

    STDMETHOD(GetUserDefinedFunctions)(THIS_ LPSQLDMOUSERDEFINEDFUNCTIONS * ppProcs) PURE;
    STDMETHOD(GetUserDefinedFunctionByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOUSERDEFINEDFUNCTION *ppProc, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetUserDefinedFunctionByOrd)(THIS_ long lOrdinal, LPSQLDMOUSERDEFINEDFUNCTION *ppProc) PURE;
    STDMETHOD(RemoveUserDefinedFunctionByName)(THIS_ SQLDMO_LPCSTR szName, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RemoveUserDefinedFunctionByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddUserDefinedFunction)(THIS_ LPSQLDMOUSERDEFINEDFUNCTION pProc) PURE;
    STDMETHOD(GetUserDefinedFunctionCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetCollation)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetCollation)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetReplicationStatus)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetStdCreateDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE; //RJZ
    STDMETHOD(GetSizeInKB)(THIS_ LPFLOAT pRetVal) PURE;
    STDMETHOD(CheckRuleSyntax)(THIS_ LPSQLDMORULE Rule) PURE;
    STDMETHOD(CheckDefaultSyntax)(THIS_ LPSQLDMODEFAULT Default) PURE;
    STDMETHOD(GetIsDeleted)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(IsObjectDeleted)(THIS_ SQLDMO_OBJECT_TYPE ObjectType, SQLDMO_LPCSTR ObjName, LPBOOL pRetVal, SQLDMO_LPCSTR ObjOwner CPPDEFAULT(= NULL)) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOBackupDevices
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
        STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOBACKUPDEVICE *ppObj) PURE;
        STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOBACKUPDEVICE *ppObj) PURE;
        STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
        STDMETHOD(Add)(THIS_ LPSQLDMOBACKUPDEVICE Object) PURE;
        STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
        STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
        STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOBackupDevice
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPhysicalLocation)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPhysicalLocation)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetType)(THIS_ SQLDMO_DEVICE_TYPE *pRetVal) PURE;
    STDMETHOD(SetType)(THIS_ SQLDMO_DEVICE_TYPE NewValue) PURE;
    STDMETHOD(GetStatus)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetDeviceNumber)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetSkipTapeLabel)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetSkipTapeLabel)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetSystemObject)(THIS_ LPBOOL pRetVal) PURE;

        //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(ReadBackupHeader)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;

        // Post-6.0 Additions
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPCSTR NewPhysicalLocation CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;

    // 7.0
    STDMETHOD(ReadMediaHeader)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOLogins
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
        STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOLOGIN *ppObj) PURE;
        STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOLOGIN *ppObj) PURE;
        STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
        STDMETHOD(Add)(THIS_ LPSQLDMOLOGIN Object) PURE;
        STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
        STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
        STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOLogin
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
//    STDMETHOD(GetID)(THIS_ LPLONG plID) PURE;
    STDMETHOD(GetSystemObject)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetLanguage)(THIS_ SQLDMO_LPBSTR pbstrLanguage) PURE;
    STDMETHOD(SetLanguage)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDatabase)(THIS_ SQLDMO_LPBSTR pbstrDatabase) PURE;
    STDMETHOD(SetDatabase)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

   //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
    STDMETHOD(SetPassword)(THIS_ SQLDMO_LPCSTR OldValue, SQLDMO_LPCSTR NewValue) PURE;

        // Post-6.0 additions
    STDMETHOD(EnumDatabaseMappings)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;

    // 7.0
    STDMETHOD(GetType)(THIS_ SQLDMO_LOGIN_TYPE *pRetVal) PURE;
    STDMETHOD(SetType)(THIS_ SQLDMO_LOGIN_TYPE NewValue) PURE;
    STDMETHOD(GetDenyNTLogin)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetDenyNTLogin)(THIS_ BOOL NewVal) PURE;
    STDMETHOD(ListMembers)(THIS_ LPSQLDMONAMELIST *ppList) PURE;
    STDMETHOD(IsMember)(THIS_ SQLDMO_LPCSTR ServerRole, LPBOOL pRetVal) PURE;
    STDMETHOD(GetUserName)(THIS_ SQLDMO_LPCSTR DatabaseName, SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetAliasName)(THIS_ SQLDMO_LPCSTR DatabaseName, SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetLanguageAlias)(THIS_ SQLDMO_LPBSTR pbstrLanguageAlias) PURE;
    STDMETHOD(GetNTLoginAccessType)(THIS_ SQLDMO_NTACCESS_TYPE *pRetVal) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOLogin2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOLogin)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
//    STDMETHOD(GetID)(THIS_ LPLONG plID) PURE;
    STDMETHOD(GetSystemObject)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetLanguage)(THIS_ SQLDMO_LPBSTR pbstrLanguage) PURE;
    STDMETHOD(SetLanguage)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDatabase)(THIS_ SQLDMO_LPBSTR pbstrDatabase) PURE;
    STDMETHOD(SetDatabase)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

   //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
    STDMETHOD(SetPassword)(THIS_ SQLDMO_LPCSTR OldValue, SQLDMO_LPCSTR NewValue) PURE;

        // Post-6.0 additions
    STDMETHOD(EnumDatabaseMappings)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;

    // 7.0
    STDMETHOD(GetType)(THIS_ SQLDMO_LOGIN_TYPE *pRetVal) PURE;
    STDMETHOD(SetType)(THIS_ SQLDMO_LOGIN_TYPE NewValue) PURE;
    STDMETHOD(GetDenyNTLogin)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetDenyNTLogin)(THIS_ BOOL NewVal) PURE;
    STDMETHOD(ListMembers)(THIS_ LPSQLDMONAMELIST *ppList) PURE;
    STDMETHOD(IsMember)(THIS_ SQLDMO_LPCSTR ServerRole, LPBOOL pRetVal) PURE;
    STDMETHOD(GetUserName)(THIS_ SQLDMO_LPCSTR DatabaseName, SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetAliasName)(THIS_ SQLDMO_LPCSTR DatabaseName, SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetLanguageAlias)(THIS_ SQLDMO_LPBSTR pbstrLanguageAlias) PURE;
    STDMETHOD(GetNTLoginAccessType)(THIS_ SQLDMO_NTACCESS_TYPE *pRetVal) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(GetIsDeleted)(THIS_ LPBOOL pRetVal) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOLanguages
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
    STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOLANGUAGE *ppObj) PURE;
    STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOLANGUAGE *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOLANGUAGE *ppObj) PURE;
    STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
    STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOLanguage
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG plID) PURE;
    STDMETHOD(GetUpgrade)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetAlias)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetAlias)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetMonths)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetShortMonths)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetDays)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetLangDateFormat)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetFirstDayOfWeek)(THIS_ LPINT pRetVal) PURE;
    STDMETHOD(GetMonth)(THIS_ int iMonth, SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetShortMonth)(THIS_ int iMonth, SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetDay)(THIS_ int iDay, SQLDMO_LPBSTR pRetVal) PURE;

   //*** methods
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOConfiguration
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetShowAdvancedOptions)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetShowAdvancedOptions)(THIS_ BOOL NewValue) PURE;

        //*** collection properties
    STDMETHOD(GetConfigValues)(THIS_ LPSQLDMOCONFIGVALUES * ppRemoteLogins) PURE;
    STDMETHOD(GetConfigValueByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOCONFIGVALUE *ppRemoteLogin) PURE;
    STDMETHOD(GetConfigValueByOrd)(THIS_ long lOrdinal, LPSQLDMOCONFIGVALUE *ppRemoteLogin) PURE;
    STDMETHOD(GetConfigValueCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetParameters)(THIS_ LPSQLDMONAMES *ppParameters) PURE;

        //*** methods
    STDMETHOD(ReconfigureCurrentValues)(THIS) PURE;
    STDMETHOD(ReconfigureWithOverride)(THIS) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOConfigValues
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
        STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOCONFIGVALUE *ppObj) PURE;
        STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOCONFIGVALUE *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOCONFIGVALUE *ppObj) PURE;
        STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;
    STDMETHOD(Refresh)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOConfigValue
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetMinimumValue)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetMaximumValue)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetDynamicReconfigure)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetCurrentValue)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetCurrentValue)(THIS_ long NewValue) PURE;
    STDMETHOD(GetRunningValue)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetDescription)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetID)(THIS_ SQLDMO_CONFIGVALUE_TYPE *pRetVal) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOIntegratedSecurity
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetMapUnderscore)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetMapUnderscore)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetMapDollarSign)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetMapDollarSign)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetMapPoundSign)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetMapPoundSign)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

    STDMETHOD(GetSecurityMode)(THIS_ SQLDMO_SECURITY_TYPE * pRetVal) PURE;
    STDMETHOD(SetSecurityMode)(THIS_ SQLDMO_SECURITY_TYPE NewValue) PURE;
    STDMETHOD(GetDefaultLogin)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDefaultLogin)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDefaultDomain)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDefaultDomain)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetAuditLevel)(THIS_ SQLDMO_AUDIT_TYPE * pRetVal) PURE;
    STDMETHOD(SetAuditLevel)(THIS_ SQLDMO_AUDIT_TYPE NewValue) PURE;
    STDMETHOD(GetSetHostName)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetSetHostName)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetImpersonateClient)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetImpersonateClient)(THIS_ BOOL NewValue) PURE;

   //*** methods
    STDMETHOD(Refresh)(THIS) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOTables
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
        STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOTABLE *ppObj) PURE;
        STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTABLE *ppObj, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOTABLE *ppObj) PURE;
        STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
        STDMETHOD(Add)(THIS_ LPSQLDMOTABLE Object) PURE;
        STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
        STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
        STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOTable
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG plID) PURE;
    STDMETHOD(GetOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetCreateDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetSystemObject)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetRows)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetDataSpaceUsed)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetIndexSpaceUsed)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetAttributes)(THIS_ SQLDMO_TABLEATT_TYPE *pRetVal) PURE;
    STDMETHOD(GetPrimaryKey)(THIS_ LPSQLDMOKEY *ppPrimaryKey) PURE;
    STDMETHOD(GetClusteredIndex)(THIS_ LPSQLDMOINDEX *ppPrimaryKey) PURE;

        // Collection properties
    STDMETHOD(GetColumns)(THIS_ LPSQLDMOCOLUMNS *ppColumns) PURE;
    STDMETHOD(GetColumnByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOCOLUMN *ppColumn) PURE;
    STDMETHOD(GetColumnByOrd)(THIS_ long lOrdinal, LPSQLDMOCOLUMN *ppColumn) PURE;
    STDMETHOD(RemoveColumnByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveColumnByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddColumn)(THIS_ LPSQLDMOCOLUMN pColumn) PURE;
    STDMETHOD(GetColumnCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetKeys)(THIS_ LPSQLDMOKEYS *ppKeys) PURE;
    STDMETHOD(GetKeyByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOKEY *ppKey) PURE;
    STDMETHOD(GetKeyByOrd)(THIS_ long lOrdinal, LPSQLDMOKEY *ppKey) PURE;
    STDMETHOD(RemoveKeyByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveKeyByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddKey)(THIS_ LPSQLDMOKEY pKey) PURE;
    STDMETHOD(GetKeyCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetChecks)(THIS_ LPSQLDMOCHECKS *ppChecks) PURE;
    STDMETHOD(GetCheckByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOCHECK *ppCheck) PURE;
    STDMETHOD(GetCheckByOrd)(THIS_ long lOrdinal, LPSQLDMOCHECK *ppCheck) PURE;
    STDMETHOD(RemoveCheckByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveCheckByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddCheck)(THIS_ LPSQLDMOCHECK pCheck) PURE;
    STDMETHOD(GetCheckCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetIndexes)(THIS_ LPSQLDMOINDEXES *ppIndexes) PURE;
    STDMETHOD(GetIndexByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOINDEX *ppIndex) PURE;
    STDMETHOD(GetIndexByOrd)(THIS_ long lOrdinal, LPSQLDMOINDEX *ppIndex) PURE;
    STDMETHOD(RemoveIndexByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveIndexByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddIndex)(THIS_ LPSQLDMOINDEX pIndex) PURE;
    STDMETHOD(GetIndexCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetTriggers)(THIS_ LPSQLDMOTRIGGERS *ppTriggers) PURE;
    STDMETHOD(GetTriggerByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTRIGGER *ppTrigger, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetTriggerByOrd)(THIS_ long lOrdinal, LPSQLDMOTRIGGER *ppTrigger) PURE;
    STDMETHOD(RemoveTriggerByName)(THIS_ SQLDMO_LPCSTR szName, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RemoveTriggerByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddTrigger)(THIS_ LPSQLDMOTRIGGER pTrigger) PURE;
    STDMETHOD(GetTriggerCount)(THIS_ LPLONG plCount) PURE;

        //*** methods
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(DoAlterWithNoCheck)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(Grant)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR GranteeNames, SQLDMO_LPCSTR ColumnNames CPPDEFAULT(= NULL), BOOL GrantGrant CPPDEFAULT(=FALSE), SQLDMO_LPCSTR AsRole CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(Revoke)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR RevokeeNames, SQLDMO_LPCSTR ColumnNames CPPDEFAULT(= NULL), BOOL GrantGrant CPPDEFAULT(=FALSE), BOOL RevokeGrantOption CPPDEFAULT(=FALSE), SQLDMO_LPCSTR AsRole CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(CheckTable)(THIS_ SQLDMO_LPBSTR pResult) PURE;
    STDMETHOD(TruncateData)(THIS) PURE;
    STDMETHOD(UpdateStatistics)(THIS) PURE;
    STDMETHOD(ReCompileReferences)(THIS) PURE;
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Refresh)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPCSTR NewName CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
    STDMETHOD(EnumReferencedKeys)(THIS_ LPSQLDMOQUERYRESULTS * ppResults, SQLDMO_LPCSTR ReferencedTableName CPPDEFAULT(= NULL), BOOL IncludeAllCandidates CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(EnumReferencedTables)(THIS_ LPSQLDMOQUERYRESULTS * ppResults, BOOL IncludeAllCandidates CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(EnumReferencingKeys)(THIS_ LPSQLDMOQUERYRESULTS * ppResults, SQLDMO_LPCSTR ReferencingTableName CPPDEFAULT(= NULL), BOOL IncludeAllCandidates CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(EnumReferencingTables)(THIS_ LPSQLDMOQUERYRESULTS * ppResults, BOOL IncludeAllCandidates CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(InsertColumn)(THIS_ LPSQLDMOCOLUMN pNewColumn, SQLDMO_LPCSTR BeforeColumnName) PURE;
    STDMETHOD(RecalcSpaceUsage)(THIS) PURE;
    STDMETHOD(EnumDependencies)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_DEPENDENCY_TYPE DependencyType CPPDEFAULT(= SQLDMODep_Parents)) PURE;
    STDMETHOD(EnumLastStatisticsUpdates)(THIS_ LPSQLDMOQUERYRESULTS * ppResults, SQLDMO_LPCSTR IndexName CPPDEFAULT(= NULL)) PURE;

        // List methods
    STDMETHOD(ListPermissions)(THIS_ LPSQLDMOPERMISSIONLIST * ppList, SQLDMO_PRIVILEGE_TYPE lPrivilegeTypes CPPDEFAULT(= SQLDMOPriv_AllObjectPrivs)) PURE;
    STDMETHOD(ListUserPermissions)(THIS_ SQLDMO_LPCSTR UserName, LPSQLDMOPERMISSIONLIST * ppList) PURE;

        // Post-6.0 additions.
    STDMETHOD(CheckIdentityValue)(THIS) PURE;
    STDMETHOD(RebuildIndexes)(THIS_ SQLDMO_INDEX_TYPE SortedDataType CPPDEFAULT(= SQLDMOIndex_Default), long lFillFactor CPPDEFAULT(= SQLDMO_USEEXISTINGFILLFACTOR)) PURE;
    STDMETHOD(ImportData)(THIS_ LPSQLDMOBULKCOPY Bcp, LPLONG plRowsImported CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(ExportData)(THIS_ LPSQLDMOBULKCOPY Bcp, LPLONG plRowsExported CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(CheckTableDataOnly)(THIS_ SQLDMO_LPBSTR pResult) PURE;
    STDMETHOD(InAlter)(THIS_ LPBOOL pRetVal) PURE;

    // 7.0
    STDMETHOD(GetFileGroup)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(SetFileGroup)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetTextFileGroup)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(SetTextFileGroup)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(Deny)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR DenyeeNames, SQLDMO_LPCSTR ColumnNames CPPDEFAULT(= NULL), BOOL GrantGrant CPPDEFAULT(=FALSE)) PURE;
    STDMETHOD(SetOwner)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GenerateSQL)(THIS_ LPSQLDMODATABASE pDB, SQLDMO_LPBSTR pRetVal) PURE;
    // Following CheckTextAllocsXXXX are for backward compatible
    STDMETHOD(CheckTextAllocsFast)(THIS_ SQLDMO_LPBSTR pResult) PURE;
    STDMETHOD(CheckTextAllocsFull)(THIS_ SQLDMO_LPBSTR pResult) PURE;
    STDMETHOD(UpdateStatisticsWith)(THIS_ SQLDMO_STAT_AFFECT_TYPE AffectType, SQLDMO_STAT_SCAN_TYPE ScanType, long ScanNumber CPPDEFAULT(=0), BOOL ReCompute CPPDEFAULT(=TRUE)) PURE;
    STDMETHOD(GetFullTextIndex)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetFullTextIndex)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetUniqueIndexForFullText)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(SetUniqueIndexForFullText)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetFullTextCatalogName)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(SetFullTextCatalogName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetFullTextIndexActive)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetFullTextIndexActive)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetFullTextKeyColumn)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(ListAvailableUniqueIndexesForFullText)(THIS_ LPSQLDMONAMELIST *ppUniqueIndexNames) PURE;
    STDMETHOD(FullTextIndexScript)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetHasClusteredIndex)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetHasIndex)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetFakeSystemTable)(THIS_ LPBOOL pRetVal) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOTable2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOTable)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG plID) PURE;
    STDMETHOD(GetOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetCreateDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetSystemObject)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetRows)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetDataSpaceUsed)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetIndexSpaceUsed)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetAttributes)(THIS_ SQLDMO_TABLEATT_TYPE *pRetVal) PURE;
    STDMETHOD(GetPrimaryKey)(THIS_ LPSQLDMOKEY *ppPrimaryKey) PURE;
    STDMETHOD(GetClusteredIndex)(THIS_ LPSQLDMOINDEX *ppPrimaryKey) PURE;

        // Collection properties
    STDMETHOD(GetColumns)(THIS_ LPSQLDMOCOLUMNS *ppColumns) PURE;
    STDMETHOD(GetColumnByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOCOLUMN *ppColumn) PURE;
    STDMETHOD(GetColumnByOrd)(THIS_ long lOrdinal, LPSQLDMOCOLUMN *ppColumn) PURE;
    STDMETHOD(RemoveColumnByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveColumnByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddColumn)(THIS_ LPSQLDMOCOLUMN pColumn) PURE;
    STDMETHOD(GetColumnCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetKeys)(THIS_ LPSQLDMOKEYS *ppKeys) PURE;
    STDMETHOD(GetKeyByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOKEY *ppKey) PURE;
    STDMETHOD(GetKeyByOrd)(THIS_ long lOrdinal, LPSQLDMOKEY *ppKey) PURE;
    STDMETHOD(RemoveKeyByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveKeyByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddKey)(THIS_ LPSQLDMOKEY pKey) PURE;
    STDMETHOD(GetKeyCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetChecks)(THIS_ LPSQLDMOCHECKS *ppChecks) PURE;
    STDMETHOD(GetCheckByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOCHECK *ppCheck) PURE;
    STDMETHOD(GetCheckByOrd)(THIS_ long lOrdinal, LPSQLDMOCHECK *ppCheck) PURE;
    STDMETHOD(RemoveCheckByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveCheckByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddCheck)(THIS_ LPSQLDMOCHECK pCheck) PURE;
    STDMETHOD(GetCheckCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetIndexes)(THIS_ LPSQLDMOINDEXES *ppIndexes) PURE;
    STDMETHOD(GetIndexByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOINDEX *ppIndex) PURE;
    STDMETHOD(GetIndexByOrd)(THIS_ long lOrdinal, LPSQLDMOINDEX *ppIndex) PURE;
    STDMETHOD(RemoveIndexByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveIndexByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddIndex)(THIS_ LPSQLDMOINDEX pIndex) PURE;
    STDMETHOD(GetIndexCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetTriggers)(THIS_ LPSQLDMOTRIGGERS *ppTriggers) PURE;
    STDMETHOD(GetTriggerByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTRIGGER *ppTrigger, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetTriggerByOrd)(THIS_ long lOrdinal, LPSQLDMOTRIGGER *ppTrigger) PURE;
    STDMETHOD(RemoveTriggerByName)(THIS_ SQLDMO_LPCSTR szName, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RemoveTriggerByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddTrigger)(THIS_ LPSQLDMOTRIGGER pTrigger) PURE;
    STDMETHOD(GetTriggerCount)(THIS_ LPLONG plCount) PURE;

        //*** methods
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(DoAlterWithNoCheck)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(Grant)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR GranteeNames, SQLDMO_LPCSTR ColumnNames CPPDEFAULT(= NULL), BOOL GrantGrant CPPDEFAULT(=FALSE), SQLDMO_LPCSTR AsRole CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(Revoke)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR RevokeeNames, SQLDMO_LPCSTR ColumnNames CPPDEFAULT(= NULL), BOOL GrantGrant CPPDEFAULT(=FALSE), BOOL RevokeGrantOption CPPDEFAULT(=FALSE), SQLDMO_LPCSTR AsRole CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(CheckTable)(THIS_ SQLDMO_LPBSTR pResult) PURE;
    STDMETHOD(TruncateData)(THIS) PURE;
    STDMETHOD(UpdateStatistics)(THIS) PURE;
    STDMETHOD(ReCompileReferences)(THIS) PURE;
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Refresh)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPCSTR NewName CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
    STDMETHOD(EnumReferencedKeys)(THIS_ LPSQLDMOQUERYRESULTS * ppResults, SQLDMO_LPCSTR ReferencedTableName CPPDEFAULT(= NULL), BOOL IncludeAllCandidates CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(EnumReferencedTables)(THIS_ LPSQLDMOQUERYRESULTS * ppResults, BOOL IncludeAllCandidates CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(EnumReferencingKeys)(THIS_ LPSQLDMOQUERYRESULTS * ppResults, SQLDMO_LPCSTR ReferencingTableName CPPDEFAULT(= NULL), BOOL IncludeAllCandidates CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(EnumReferencingTables)(THIS_ LPSQLDMOQUERYRESULTS * ppResults, BOOL IncludeAllCandidates CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(InsertColumn)(THIS_ LPSQLDMOCOLUMN pNewColumn, SQLDMO_LPCSTR BeforeColumnName) PURE;
    STDMETHOD(RecalcSpaceUsage)(THIS) PURE;
    STDMETHOD(EnumDependencies)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_DEPENDENCY_TYPE DependencyType CPPDEFAULT(= SQLDMODep_Parents)) PURE;
    STDMETHOD(EnumLastStatisticsUpdates)(THIS_ LPSQLDMOQUERYRESULTS * ppResults, SQLDMO_LPCSTR IndexName CPPDEFAULT(= NULL)) PURE;

        // List methods
    STDMETHOD(ListPermissions)(THIS_ LPSQLDMOPERMISSIONLIST * ppList, SQLDMO_PRIVILEGE_TYPE lPrivilegeTypes CPPDEFAULT(= SQLDMOPriv_AllObjectPrivs)) PURE;
    STDMETHOD(ListUserPermissions)(THIS_ SQLDMO_LPCSTR UserName, LPSQLDMOPERMISSIONLIST * ppList) PURE;

        // Post-6.0 additions.
    STDMETHOD(CheckIdentityValue)(THIS) PURE;
    STDMETHOD(RebuildIndexes)(THIS_ SQLDMO_INDEX_TYPE SortedDataType CPPDEFAULT(= SQLDMOIndex_Default), long lFillFactor CPPDEFAULT(= SQLDMO_USEEXISTINGFILLFACTOR)) PURE;
    STDMETHOD(ImportData)(THIS_ LPSQLDMOBULKCOPY Bcp, LPLONG plRowsImported CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(ExportData)(THIS_ LPSQLDMOBULKCOPY Bcp, LPLONG plRowsExported CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(CheckTableDataOnly)(THIS_ SQLDMO_LPBSTR pResult) PURE;
    STDMETHOD(InAlter)(THIS_ LPBOOL pRetVal) PURE;

    // 7.0
    STDMETHOD(GetFileGroup)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(SetFileGroup)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetTextFileGroup)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(SetTextFileGroup)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(Deny)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR DenyeeNames, SQLDMO_LPCSTR ColumnNames CPPDEFAULT(= NULL), BOOL GrantGrant CPPDEFAULT(=FALSE)) PURE;
    STDMETHOD(SetOwner)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GenerateSQL)(THIS_ LPSQLDMODATABASE pDB, SQLDMO_LPBSTR pRetVal) PURE;
    // Following CheckTextAllocsXXXX are for backward compatible
    STDMETHOD(CheckTextAllocsFast)(THIS_ SQLDMO_LPBSTR pResult) PURE;
    STDMETHOD(CheckTextAllocsFull)(THIS_ SQLDMO_LPBSTR pResult) PURE;
    STDMETHOD(UpdateStatisticsWith)(THIS_ SQLDMO_STAT_AFFECT_TYPE AffectType, SQLDMO_STAT_SCAN_TYPE ScanType, long ScanNumber CPPDEFAULT(=0), BOOL ReCompute CPPDEFAULT(=TRUE)) PURE;
    STDMETHOD(GetFullTextIndex)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetFullTextIndex)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetUniqueIndexForFullText)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(SetUniqueIndexForFullText)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetFullTextCatalogName)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(SetFullTextCatalogName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetFullTextIndexActive)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetFullTextIndexActive)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetFullTextKeyColumn)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(ListAvailableUniqueIndexesForFullText)(THIS_ LPSQLDMONAMELIST *ppUniqueIndexNames) PURE;
    STDMETHOD(FullTextIndexScript)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetHasClusteredIndex)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetHasIndex)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetFakeSystemTable)(THIS_ LPBOOL pRetVal) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(CheckTableWithResult)(THIS_ LPSQLDMOQUERYRESULTS * ppResults) PURE;
    STDMETHOD(CheckTableDataOnlyWithResult)(THIS_ LPSQLDMOQUERYRESULTS * ppResults) PURE;
    STDMETHOD(ListUserColumnPermissions)(THIS_ SQLDMO_LPCSTR UserName, LPSQLDMOPERMISSIONLIST * ppList) PURE;
    STDMETHOD(ListColumnPermissions)(THIS_ LPSQLDMOPERMISSIONLIST * ppList) PURE;
    STDMETHOD(ListPartialPermissions)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(GetTableFullTextChangeTrackingOn)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetTableFullTextChangeTrackingOn)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetTableFullTextUpdateIndexOn)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetTableFullTextUpdateIndexOn)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(FullTextUpdateIndex)(THIS) PURE;
    STDMETHOD(FullTextPopulation)(THIS_ SQLDMO_FULLTEXT_POPULATE_TYPE NewType) PURE;
    STDMETHOD(GetFullTextPopulateStatus)(THIS_ SQLDMO_FULLTEXT_POPULATE_STATUS *pRetVal) PURE;
    STDMETHOD(GetQuotedIdentifierStatus)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetAnsiNullsStatus)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsDeleted)(THIS_ LPBOOL pRetVal) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOViews
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
        STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOVIEW *ppObj) PURE;
        STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOVIEW *ppObj, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOVIEW *ppObj) PURE;
        STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
        STDMETHOD(Add)(THIS_ LPSQLDMOVIEW Object) PURE;
        STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
        STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
        STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOView
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG plID) PURE;
    STDMETHOD(GetOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetCreateDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetText)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetText)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSystemObject)(THIS_ LPBOOL pRetVal) PURE;

        //*** methods
    STDMETHOD(Grant)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR GranteeNames, SQLDMO_LPCSTR ColumnNames CPPDEFAULT(= NULL), BOOL GrantGrant CPPDEFAULT(=FALSE), SQLDMO_LPCSTR AsRole CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(Revoke)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR RevokeeNames, SQLDMO_LPCSTR ColumnNames CPPDEFAULT(= NULL), BOOL GrantGrant CPPDEFAULT(=FALSE), BOOL RevokeGrantOption CPPDEFAULT(=FALSE), SQLDMO_LPCSTR AsRole CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
    STDMETHOD(EnumDependencies)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_DEPENDENCY_TYPE DependencyType CPPDEFAULT(= SQLDMODep_Parents)) PURE;

    // List methods
    STDMETHOD(ListPermissions)(THIS_ LPSQLDMOPERMISSIONLIST * ppList, SQLDMO_PRIVILEGE_TYPE lPrivilegeTypes CPPDEFAULT(= SQLDMOPriv_AllObjectPrivs)) PURE;
    STDMETHOD(ListUserPermissions)(THIS_ SQLDMO_LPCSTR UserName, LPSQLDMOPERMISSIONLIST * ppList) PURE;
    STDMETHOD(ListColumns)(THIS_ LPSQLDMOCOLUMNLIST * ppList) PURE;

        // Post-6.0 additions.
    STDMETHOD(ExportData)(THIS_ LPSQLDMOBULKCOPY Bcp, LPLONG plRowsExported CPPDEFAULT(= NULL)) PURE;

    // 7.0
    STDMETHOD(Deny)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR DenyeeNames, SQLDMO_LPCSTR ColumnNames CPPDEFAULT(= NULL), BOOL GrantGrant CPPDEFAULT(=FALSE)) PURE;
    STDMETHOD(SetOwner)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(Alter)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetQuotedIdentifierStatus)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetAnsiNullsStatus)(THIS_ LPBOOL pRetVal) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOView2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOView)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG plID) PURE;
    STDMETHOD(GetOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetCreateDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetText)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetText)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSystemObject)(THIS_ LPBOOL pRetVal) PURE;

        //*** methods
    STDMETHOD(Grant)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR GranteeNames, SQLDMO_LPCSTR ColumnNames CPPDEFAULT(= NULL), BOOL GrantGrant CPPDEFAULT(=FALSE), SQLDMO_LPCSTR AsRole CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(Revoke)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR RevokeeNames, SQLDMO_LPCSTR ColumnNames CPPDEFAULT(= NULL), BOOL GrantGrant CPPDEFAULT(=FALSE), BOOL RevokeGrantOption CPPDEFAULT(=FALSE), SQLDMO_LPCSTR AsRole CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
    STDMETHOD(EnumDependencies)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_DEPENDENCY_TYPE DependencyType CPPDEFAULT(= SQLDMODep_Parents)) PURE;

    // List methods
    STDMETHOD(ListPermissions)(THIS_ LPSQLDMOPERMISSIONLIST * ppList, SQLDMO_PRIVILEGE_TYPE lPrivilegeTypes CPPDEFAULT(= SQLDMOPriv_AllObjectPrivs)) PURE;
    STDMETHOD(ListUserPermissions)(THIS_ SQLDMO_LPCSTR UserName, LPSQLDMOPERMISSIONLIST * ppList) PURE;
    STDMETHOD(ListColumns)(THIS_ LPSQLDMOCOLUMNLIST * ppList) PURE;

        // Post-6.0 additions.
    STDMETHOD(ExportData)(THIS_ LPSQLDMOBULKCOPY Bcp, LPLONG plRowsExported CPPDEFAULT(= NULL)) PURE;

    // 7.0
    STDMETHOD(Deny)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR DenyeeNames, SQLDMO_LPCSTR ColumnNames CPPDEFAULT(= NULL), BOOL GrantGrant CPPDEFAULT(=FALSE)) PURE;
    STDMETHOD(SetOwner)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(Alter)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetQuotedIdentifierStatus)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetAnsiNullsStatus)(THIS_ LPBOOL pRetVal) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(SetAnsiNullsStatus)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(ListUserColumnPermissions)(THIS_ SQLDMO_LPCSTR UserName, LPSQLDMOPERMISSIONLIST * ppList) PURE;
    STDMETHOD(ListColumnPermissions)(THIS_ LPSQLDMOPERMISSIONLIST * ppList) PURE;
    STDMETHOD(ListPartialPermissions)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    // Collection properties
    STDMETHOD(GetIndexes)(THIS_ LPSQLDMOINDEXES *ppIndexes) PURE;
    STDMETHOD(GetIndexByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOINDEX *ppIndex) PURE;
    STDMETHOD(GetIndexByOrd)(THIS_ long lOrdinal, LPSQLDMOINDEX *ppIndex) PURE;
    STDMETHOD(RemoveIndexByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveIndexByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddIndex)(THIS_ LPSQLDMOINDEX pIndex) PURE;
    STDMETHOD(GetIndexCount)(THIS_ LPLONG plCount) PURE;
    STDMETHOD(GetClusteredIndex)(THIS_ LPSQLDMOINDEX *ppIndex) PURE;
    STDMETHOD(GetIsSchemaBound)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetTriggers)(THIS_ LPSQLDMOTRIGGERS *ppTriggers) PURE;
    STDMETHOD(GetTriggerByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTRIGGER *ppTrigger, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetTriggerByOrd)(THIS_ long lOrdinal, LPSQLDMOTRIGGER *ppTrigger) PURE;
    STDMETHOD(RemoveTriggerByName)(THIS_ SQLDMO_LPCSTR szName, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RemoveTriggerByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddTrigger)(THIS_ LPSQLDMOTRIGGER pTrigger) PURE;
    STDMETHOD(GetTriggerCount)(THIS_ LPLONG plCount) PURE;
    STDMETHOD(GetIsDeleted)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetEncrypted)(THIS_ LPBOOL pRetVal) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMORules
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
        STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMORULE *ppObj) PURE;
        STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMORULE *ppObj, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMORULE *ppObj) PURE;
        STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
        STDMETHOD(Add)(THIS_ LPSQLDMORULE Object) PURE;
        STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
        STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
        STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMORule
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetCreateDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetText)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetText)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

        //*** methods
    STDMETHOD(BindToColumn)(THIS_ SQLDMO_LPCSTR TableName, SQLDMO_LPCSTR ColumnName) PURE;
    STDMETHOD(BindToDatatype)(THIS_ SQLDMO_LPCSTR DatatypeName, BOOL bFutureOnly CPPDEFAULT(= FALSE)) PURE;
    STDMETHOD(UnbindFromColumn)(THIS_ SQLDMO_LPCSTR TableName, SQLDMO_LPCSTR ColumnName) PURE;
    STDMETHOD(UnbindFromDatatype)(THIS_ SQLDMO_LPCSTR DatatypeName, BOOL bFutureOnly CPPDEFAULT(= FALSE)) PURE;
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;

        // List methods
    STDMETHOD(ListBoundColumns)(THIS_ LPSQLDMOCOLUMNLIST * ppList) PURE;
    STDMETHOD(ListBoundDatatypes)(THIS_ LPSQLDMOUSERDEFINEDDATATYPELIST * ppList) PURE;

    // 7.0
    STDMETHOD(SetOwner)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMORule2
DECLARE_INTERFACE_(INTERFACE, ISQLDMORule)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetCreateDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetText)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetText)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

        //*** methods
    STDMETHOD(BindToColumn)(THIS_ SQLDMO_LPCSTR TableName, SQLDMO_LPCSTR ColumnName) PURE;
    STDMETHOD(BindToDatatype)(THIS_ SQLDMO_LPCSTR DatatypeName, BOOL bFutureOnly CPPDEFAULT(= FALSE)) PURE;
    STDMETHOD(UnbindFromColumn)(THIS_ SQLDMO_LPCSTR TableName, SQLDMO_LPCSTR ColumnName) PURE;
    STDMETHOD(UnbindFromDatatype)(THIS_ SQLDMO_LPCSTR DatatypeName, BOOL bFutureOnly CPPDEFAULT(= FALSE)) PURE;
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;

        // List methods
    STDMETHOD(ListBoundColumns)(THIS_ LPSQLDMOCOLUMNLIST * ppList) PURE;
    STDMETHOD(ListBoundDatatypes)(THIS_ LPSQLDMOUSERDEFINEDDATATYPELIST * ppList) PURE;

    // 7.0
    STDMETHOD(SetOwner)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(GetIsDeleted)(THIS_ LPBOOL pRetVal) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMODefaults
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
        STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMODEFAULT *ppObj) PURE;
        STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMODEFAULT *ppObj, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMODEFAULT *ppObj) PURE;
        STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
        STDMETHOD(Add)(THIS_ LPSQLDMODEFAULT Object) PURE;
        STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
        STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
        STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMODefault
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetCreateDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetText)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetText)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

        //*** methods
    STDMETHOD(BindToColumn)(THIS_ SQLDMO_LPCSTR TableName, SQLDMO_LPCSTR ColumnName) PURE;
    STDMETHOD(BindToDatatype)(THIS_ SQLDMO_LPCSTR DatatypeName, BOOL bFutureOnly CPPDEFAULT(= FALSE)) PURE;
    STDMETHOD(UnbindFromColumn)(THIS_ SQLDMO_LPCSTR TableName, SQLDMO_LPCSTR ColumnName) PURE;
    STDMETHOD(UnbindFromDatatype)(THIS_ SQLDMO_LPCSTR DatatypeName, BOOL bFutureOnly CPPDEFAULT(= FALSE)) PURE;
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;

        // List methods
    STDMETHOD(ListBoundColumns)(THIS_ LPSQLDMOCOLUMNLIST * ppList) PURE;
    STDMETHOD(ListBoundDatatypes)(THIS_ LPSQLDMOUSERDEFINEDDATATYPELIST * ppList) PURE;

    // 7.0
    STDMETHOD(SetOwner)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMODefault2
DECLARE_INTERFACE_(INTERFACE, ISQLDMODefault)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetCreateDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetText)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetText)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

        //*** methods
    STDMETHOD(BindToColumn)(THIS_ SQLDMO_LPCSTR TableName, SQLDMO_LPCSTR ColumnName) PURE;
    STDMETHOD(BindToDatatype)(THIS_ SQLDMO_LPCSTR DatatypeName, BOOL bFutureOnly CPPDEFAULT(= FALSE)) PURE;
    STDMETHOD(UnbindFromColumn)(THIS_ SQLDMO_LPCSTR TableName, SQLDMO_LPCSTR ColumnName) PURE;
    STDMETHOD(UnbindFromDatatype)(THIS_ SQLDMO_LPCSTR DatatypeName, BOOL bFutureOnly CPPDEFAULT(= FALSE)) PURE;
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;

        // List methods
    STDMETHOD(ListBoundColumns)(THIS_ LPSQLDMOCOLUMNLIST * ppList) PURE;
    STDMETHOD(ListBoundDatatypes)(THIS_ LPSQLDMOUSERDEFINEDDATATYPELIST * ppList) PURE;

    // 7.0
    STDMETHOD(SetOwner)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(GetIsDeleted)(THIS_ LPBOOL pRetVal) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOColumns
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
        STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOCOLUMN *ppObj) PURE;
        STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOCOLUMN *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOCOLUMN *ppObj) PURE;
        STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
        STDMETHOD(Add)(THIS_ LPSQLDMOCOLUMN Object) PURE;
        STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
        STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
        STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOColumn
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDatatype)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDatatype)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPhysicalDatatype)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetLength)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetLength)(THIS_ long NewValue) PURE;
    STDMETHOD(GetDefault)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDefault)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetRule)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetRule)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetAllowNulls)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAllowNulls)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetIdentity)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetIdentity)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetNumericPrecision)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetNumericPrecision)(THIS_ long NewValue) PURE;
    STDMETHOD(GetNumericScale)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetNumericScale)(THIS_ long NewValue) PURE;
    STDMETHOD(GetIdentitySeed)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetIdentitySeed)(THIS_ long NewValue) PURE;
    STDMETHOD(GetIdentityIncrement)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetIdentityIncrement)(THIS_ long NewValue) PURE;
    STDMETHOD(GetDRIDefault)(THIS_ LPSQLDMODRIDEFAULT *ppDRIDefault) PURE;
    STDMETHOD(GetInPrimaryKey)(THIS_ LPBOOL pRetVal) PURE;

   //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(ListKeys)(THIS_ LPSQLDMOKEYLIST * ppList) PURE;

    // 7.0
    STDMETHOD(GetIsRowGuidCol)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetIsRowGuidCol)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetIsComputed)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetIsComputed)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetComputedText)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetComputedText)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetNotForRepl)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetNotForRepl)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(UpdateStatisticsWith)(THIS_ SQLDMO_STAT_SCAN_TYPE ScanType, long ScanNumber CPPDEFAULT(=0), BOOL ReCompute CPPDEFAULT(=TRUE)) PURE;
    STDMETHOD(GetFullTextIndex)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetFullTextIndex)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetAnsiPaddingStatus)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetDefaultOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetRuleOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(BindDefault)(THIS_ SQLDMO_LPCSTR DefaultOwner, SQLDMO_LPCSTR DefaultName, BOOL Bind) PURE;
    STDMETHOD(BindRule)(THIS_ SQLDMO_LPCSTR RuleOwner, SQLDMO_LPCSTR RuleName, BOOL Bind) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOColumn2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOColumn)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDatatype)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDatatype)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPhysicalDatatype)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetLength)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetLength)(THIS_ long NewValue) PURE;
    STDMETHOD(GetDefault)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDefault)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetRule)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetRule)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetAllowNulls)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAllowNulls)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetIdentity)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetIdentity)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetNumericPrecision)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetNumericPrecision)(THIS_ long NewValue) PURE;
    STDMETHOD(GetNumericScale)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetNumericScale)(THIS_ long NewValue) PURE;
    STDMETHOD(GetIdentitySeed)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetIdentitySeed)(THIS_ long NewValue) PURE;
    STDMETHOD(GetIdentityIncrement)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetIdentityIncrement)(THIS_ long NewValue) PURE;
    STDMETHOD(GetDRIDefault)(THIS_ LPSQLDMODRIDEFAULT *ppDRIDefault) PURE;
    STDMETHOD(GetInPrimaryKey)(THIS_ LPBOOL pRetVal) PURE;

   //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(ListKeys)(THIS_ LPSQLDMOKEYLIST * ppList) PURE;

    // 7.0
    STDMETHOD(GetIsRowGuidCol)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetIsRowGuidCol)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetIsComputed)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetIsComputed)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetComputedText)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetComputedText)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetNotForRepl)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetNotForRepl)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(UpdateStatisticsWith)(THIS_ SQLDMO_STAT_SCAN_TYPE ScanType, long ScanNumber CPPDEFAULT(=0), BOOL ReCompute CPPDEFAULT(=TRUE)) PURE;
    STDMETHOD(GetFullTextIndex)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetFullTextIndex)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetAnsiPaddingStatus)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetDefaultOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetRuleOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(BindDefault)(THIS_ SQLDMO_LPCSTR DefaultOwner, SQLDMO_LPCSTR DefaultName, BOOL Bind) PURE;
    STDMETHOD(BindRule)(THIS_ SQLDMO_LPCSTR RuleOwner, SQLDMO_LPCSTR RuleName, BOOL Bind) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(GetCollation)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetCollation)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(SetFullTextIndexWithOptions)(THIS_ BOOL Index, long LanguageID CPPDEFAULT(=-1), SQLDMO_LPCSTR ColumnType CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetFullTextImageColumnType)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetFullTextColumnLanguageID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(AlterDataType)(THIS_ SQLDMO_LPCSTR DataType, long Length CPPDEFAULT(=-1), long Precision CPPDEFAULT(=-1),
                     long Scale CPPDEFAULT(=-1)) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOIndexes
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
        STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOINDEX *ppObj) PURE;
        STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOINDEX *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOINDEX *ppObj) PURE;
        STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
        STDMETHOD(Add)(THIS_ LPSQLDMOINDEX Object) PURE;
        STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
        STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
        STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOIndex
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetType)(THIS_ SQLDMO_INDEX_TYPE *pRetVal) PURE;
    STDMETHOD(SetType)(THIS_ SQLDMO_INDEX_TYPE NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetFillFactor)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetFillFactor)(THIS_ long lNewValue) PURE;
    STDMETHOD(GetSpaceUsed)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetIndexedColumns)(THIS_ SQLDMO_LPCSTR ColumnNames) PURE;

    //*** methods
    STDMETHOD(UpdateStatistics)(THIS) PURE;
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
    STDMETHOD(Rebuild)(THIS) PURE;
    STDMETHOD(RecalcSpaceUsage)(THIS) PURE;
    STDMETHOD(EnumStatistics)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(GenerateCreationSQL)(THIS_ LPSQLDMOTABLE TargetTable, SQLDMO_LPBSTR pSQLStatement) PURE;

        // List methods
    STDMETHOD(ListIndexedColumns)(THIS_ LPSQLDMOCOLUMNLIST * ppList) PURE;

        // Post-6.0 additions.
    STDMETHOD(CheckIndex)(THIS_ SQLDMO_LPBSTR pResult) PURE;

    // 7.0
    STDMETHOD(GetFileGroup)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(SetFileGroup)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GenerateSQL)(THIS_ LPSQLDMOTABLE pTable, SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(UpdateStatisticsWith)(THIS_ SQLDMO_STAT_SCAN_TYPE ScanType, long ScanNumber CPPDEFAULT(=0), BOOL ReCompute CPPDEFAULT(=TRUE)) PURE;
    STDMETHOD(GetIsFullTextKey)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetNoRecompute)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetNoRecompute)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetStatisticsIndex)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetStatisticsIndex)(THIS_ BOOL NewValue) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOIndex2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOIndex)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetType)(THIS_ SQLDMO_INDEX_TYPE *pRetVal) PURE;
    STDMETHOD(SetType)(THIS_ SQLDMO_INDEX_TYPE NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetFillFactor)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetFillFactor)(THIS_ long lNewValue) PURE;
    STDMETHOD(GetSpaceUsed)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetIndexedColumns)(THIS_ SQLDMO_LPCSTR ColumnNames) PURE;

    //*** methods
    STDMETHOD(UpdateStatistics)(THIS) PURE;
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
    STDMETHOD(Rebuild)(THIS) PURE;
    STDMETHOD(RecalcSpaceUsage)(THIS) PURE;
    STDMETHOD(EnumStatistics)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(GenerateCreationSQL)(THIS_ LPSQLDMOTABLE TargetTable, SQLDMO_LPBSTR pSQLStatement) PURE;

        // List methods
    STDMETHOD(ListIndexedColumns)(THIS_ LPSQLDMOCOLUMNLIST * ppList) PURE;

        // Post-6.0 additions.
    STDMETHOD(CheckIndex)(THIS_ SQLDMO_LPBSTR pResult) PURE;

    // 7.0
    STDMETHOD(GetFileGroup)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(SetFileGroup)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GenerateSQL)(THIS_ LPSQLDMOTABLE pTable, SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(UpdateStatisticsWith)(THIS_ SQLDMO_STAT_SCAN_TYPE ScanType, long ScanNumber CPPDEFAULT(=0), BOOL ReCompute CPPDEFAULT(=TRUE)) PURE;
    STDMETHOD(GetIsFullTextKey)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetNoRecompute)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetNoRecompute)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetStatisticsIndex)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetStatisticsIndex)(THIS_ BOOL NewValue) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(CheckIndexWithResult)(THIS_ LPSQLDMOQUERYRESULTS * ppResults) PURE;
    STDMETHOD(SetIndexedColumnDESC)(THIS_ SQLDMO_LPCSTR ColumnName, BOOL NewValue) PURE;
    STDMETHOD(GetIndexedColumnDESC)(THIS_ SQLDMO_LPCSTR ColumnName, LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsOnComputed)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GenerateCreationSQLOnView)(THIS_ LPSQLDMOVIEW TargetView, SQLDMO_LPBSTR pSQLStatement) PURE;
    STDMETHOD(GenerateSQLOnView)(THIS_ LPSQLDMOVIEW pView, SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetIndexOnTable)(THIS_ LPBOOL pRetVal) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOKeys
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
        STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOKEY *ppObj) PURE;
        STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOKEY *ppObj) PURE;
        STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
        STDMETHOD(Add)(THIS_ LPSQLDMOKEY Object) PURE;
        STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
        STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
        STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOKey
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetType)(THIS_ SQLDMO_KEY_TYPE *pRetVal) PURE;
    STDMETHOD(SetType)(THIS_ SQLDMO_KEY_TYPE NewValue) PURE;
    STDMETHOD(GetClustered)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetClustered)(THIS_ BOOL bNewValue) PURE;
    STDMETHOD(GetFillFactor)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetFillFactor)(THIS_ long lNewValue) PURE;
    STDMETHOD(GetReferencedTable)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetReferencedTable)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetReferencedKey)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;

        //*** Collection properties
    STDMETHOD(GetKeyColumns)(THIS_ LPSQLDMONAMES *ppColumnNames) PURE;
    STDMETHOD(GetReferencedColumns)(THIS_ LPSQLDMONAMES *ppColumnNames) PURE;

    //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;

        // Post-6.0 additions.
    STDMETHOD(RebuildIndex)(THIS) PURE;
    STDMETHOD(GetExcludeReplication)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetExcludeReplication)(THIS_ BOOL NewValue) PURE;

    // 7.0
    STDMETHOD(GetFileGroup)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(SetFileGroup)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetChecked)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetChecked)(THIS_ BOOL NewValue) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOStoredProcedures
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
        STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOSTOREDPROCEDURE *ppObj) PURE;
        STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOSTOREDPROCEDURE *ppObj, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOSTOREDPROCEDURE *ppObj) PURE;
        STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
        STDMETHOD(Add)(THIS_ LPSQLDMOSTOREDPROCEDURE Object) PURE;
        STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
        STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
        STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOStoredProcedure
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetCreateDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetText)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetText)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetType)(THIS_ SQLDMO_PROCEDURE_TYPE *pRetVal) PURE;
    STDMETHOD(SetType)(THIS_ SQLDMO_PROCEDURE_TYPE NewValue) PURE;
    STDMETHOD(GetStartup)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetStartup)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetSystemObject)(THIS_ LPBOOL pRetVal) PURE;

        //*** methods
    STDMETHOD(Grant)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR GranteeNames, BOOL GrantGrant CPPDEFAULT(=FALSE), SQLDMO_LPCSTR AsRole CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(Revoke)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR RevokeeNames, BOOL GrantGrant CPPDEFAULT(=FALSE), BOOL RevokeGrantOption CPPDEFAULT(=FALSE), SQLDMO_LPCSTR AsRole CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(EnumParameters)(THIS_ LPSQLDMOQUERYRESULTS * ppResults) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
    STDMETHOD(EnumDependencies)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_DEPENDENCY_TYPE DependencyType CPPDEFAULT(= SQLDMODep_Parents)) PURE;

        // List methods
    STDMETHOD(ListPermissions)(THIS_ LPSQLDMOPERMISSIONLIST * ppList, SQLDMO_PRIVILEGE_TYPE lPrivilegeTypes CPPDEFAULT(= SQLDMOPriv_Execute)) PURE;
    STDMETHOD(ListUserPermissions)(THIS_ SQLDMO_LPCSTR UserName, LPSQLDMOPERMISSIONLIST * ppList) PURE;

    // 7.0
    STDMETHOD(Deny)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR DenyeeNames, BOOL GrantGrant CPPDEFAULT(=FALSE)) PURE;
    STDMETHOD(SetOwner)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(Alter)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetQuotedIdentifierStatus)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetAnsiNullsStatus)(THIS_ LPBOOL pRetVal) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOStoredProcedure2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStoredProcedure)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetCreateDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetText)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetText)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetType)(THIS_ SQLDMO_PROCEDURE_TYPE *pRetVal) PURE;
    STDMETHOD(SetType)(THIS_ SQLDMO_PROCEDURE_TYPE NewValue) PURE;
    STDMETHOD(GetStartup)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetStartup)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetSystemObject)(THIS_ LPBOOL pRetVal) PURE;

        //*** methods
    STDMETHOD(Grant)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR GranteeNames, BOOL GrantGrant CPPDEFAULT(=FALSE), SQLDMO_LPCSTR AsRole CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(Revoke)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR RevokeeNames, BOOL GrantGrant CPPDEFAULT(=FALSE), BOOL RevokeGrantOption CPPDEFAULT(=FALSE), SQLDMO_LPCSTR AsRole CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(EnumParameters)(THIS_ LPSQLDMOQUERYRESULTS * ppResults) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
    STDMETHOD(EnumDependencies)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_DEPENDENCY_TYPE DependencyType CPPDEFAULT(= SQLDMODep_Parents)) PURE;

        // List methods
    STDMETHOD(ListPermissions)(THIS_ LPSQLDMOPERMISSIONLIST * ppList, SQLDMO_PRIVILEGE_TYPE lPrivilegeTypes CPPDEFAULT(= SQLDMOPriv_Execute)) PURE;
    STDMETHOD(ListUserPermissions)(THIS_ SQLDMO_LPCSTR UserName, LPSQLDMOPERMISSIONLIST * ppList) PURE;

    // 7.0
    STDMETHOD(Deny)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR DenyeeNames, BOOL GrantGrant CPPDEFAULT(=FALSE)) PURE;
    STDMETHOD(SetOwner)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(Alter)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetQuotedIdentifierStatus)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetAnsiNullsStatus)(THIS_ LPBOOL pRetVal) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(SetAnsiNullsStatus)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetIsDeleted)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetEncrypted)(THIS_ LPBOOL pRetVal) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOUserDefinedDatatypes
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
        STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOUSERDEFINEDDATATYPE *ppObj) PURE;
        STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOUSERDEFINEDDATATYPE *ppObj, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOUSERDEFINEDDATATYPE *ppObj) PURE;
        STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
        STDMETHOD(Add)(THIS_ LPSQLDMOUSERDEFINEDDATATYPE Object) PURE;
        STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
        STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
        STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOUserDefinedDatatype
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetAllowNulls)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAllowNulls)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetBaseType)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetBaseType)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetLength)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetLength)(THIS_ long NewValue) PURE;
    STDMETHOD(GetDefault)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDefault)(THIS_ SQLDMO_LPCSTR NewValue, BOOL bFutureOnly CPPDEFAULT(= FALSE)) PURE;
    STDMETHOD(GetRule)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetRule)(THIS_ SQLDMO_LPCSTR NewValue, BOOL bFutureOnly CPPDEFAULT(= FALSE)) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetNumericPrecision)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetNumericPrecision)(THIS_ long NewValue) PURE;
    STDMETHOD(GetNumericScale)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetNumericScale)(THIS_ long NewValue) PURE;
    STDMETHOD(GetAllowIdentity)(THIS_ LPBOOL pRetVal) PURE;

        //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;

        // List methods
    STDMETHOD(ListBoundColumns)(THIS_ LPSQLDMOCOLUMNLIST * ppList) PURE;

    // 7.0
    STDMETHOD(GetIsVariableLength)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GenerateSQL)(THIS_ LPSQLDMODATABASE pDB, SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetMaxSize)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetDefaultOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetRuleOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(BindDefault)(THIS_ SQLDMO_LPCSTR DefaultOwner, SQLDMO_LPCSTR DefaultName, BOOL Bind, BOOL bFutureOnly CPPDEFAULT(= FALSE)) PURE;
    STDMETHOD(BindRule)(THIS_ SQLDMO_LPCSTR RuleOwner, SQLDMO_LPCSTR RuleName, BOOL Bind, BOOL bFutureOnly CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOUserDefinedDatatype2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOUserDefinedDatatype)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetAllowNulls)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAllowNulls)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetBaseType)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetBaseType)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetLength)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetLength)(THIS_ long NewValue) PURE;
    STDMETHOD(GetDefault)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDefault)(THIS_ SQLDMO_LPCSTR NewValue, BOOL bFutureOnly CPPDEFAULT(= FALSE)) PURE;
    STDMETHOD(GetRule)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetRule)(THIS_ SQLDMO_LPCSTR NewValue, BOOL bFutureOnly CPPDEFAULT(= FALSE)) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetNumericPrecision)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetNumericPrecision)(THIS_ long NewValue) PURE;
    STDMETHOD(GetNumericScale)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetNumericScale)(THIS_ long NewValue) PURE;
    STDMETHOD(GetAllowIdentity)(THIS_ LPBOOL pRetVal) PURE;

        //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;

        // List methods
    STDMETHOD(ListBoundColumns)(THIS_ LPSQLDMOCOLUMNLIST * ppList) PURE;

    // 7.0
    STDMETHOD(GetIsVariableLength)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GenerateSQL)(THIS_ LPSQLDMODATABASE pDB, SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetMaxSize)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetDefaultOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetRuleOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(BindDefault)(THIS_ SQLDMO_LPCSTR DefaultOwner, SQLDMO_LPCSTR DefaultName, BOOL Bind, BOOL bFutureOnly CPPDEFAULT(= FALSE)) PURE;
    STDMETHOD(BindRule)(THIS_ SQLDMO_LPCSTR RuleOwner, SQLDMO_LPCSTR RuleName, BOOL Bind, BOOL bFutureOnly CPPDEFAULT(= FALSE)) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(GetCollation)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetIsDeleted)(THIS_ LPBOOL pRetVal) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOUsers
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
        STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOUSER *ppObj) PURE;
        STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOUSER *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOUSER *ppObj) PURE;
        STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
        STDMETHOD(Add)(THIS_ LPSQLDMOUSER Object) PURE;
        STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
        STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
        STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOUser
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetLogin)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetLogin)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetGroup)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetGroup)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetSystemObject)(THIS_ LPBOOL pRetVal) PURE;

        //*** methods
    STDMETHOD(AddAlias)(THIS_ SQLDMO_LPCSTR LoginNames) PURE;
    STDMETHOD(RemoveAlias)(THIS_ SQLDMO_LPCSTR LoginNames) PURE;
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;

        // List methods
    STDMETHOD(ListAliases)(THIS_ LPSQLDMOLOGINLIST * ppList) PURE;
    STDMETHOD(ListOwnedObjects)(THIS_ LPSQLDMODBOBJECTLIST * ppList, SQLDMO_OBJECT_TYPE lObjectTypes CPPDEFAULT(= SQLDMOObj_AllDatabaseObjects), SQLDMO_OBJSORT_TYPE SortBy CPPDEFAULT(= SQLDMOObjSort_Name)) PURE;
    STDMETHOD(ListDatabasePermissions)(THIS_ LPSQLDMOPERMISSIONLIST * ppList, SQLDMO_PRIVILEGE_TYPE lPrivilegeTypes CPPDEFAULT(= SQLDMOPriv_AllDatabasePrivs)) PURE;
    STDMETHOD(ListObjectPermissions)(THIS_ LPSQLDMOPERMISSIONLIST * ppList, SQLDMO_PRIVILEGE_TYPE lPrivilegeTypes CPPDEFAULT(= SQLDMOPriv_AllObjectPrivs)) PURE;

    // 7.0
    STDMETHOD(ListMembers)(THIS_ LPSQLDMONAMELIST *ppList) PURE;
    STDMETHOD(GetRole)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetRole)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(IsMember)(THIS_ SQLDMO_LPCSTR DatabaseRole, LPBOOL pRetVal) PURE;
    STDMETHOD(GetHasDBAccess)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GrantNTUserDBAccess)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOUser2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOUser)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetLogin)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetLogin)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetGroup)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetGroup)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetSystemObject)(THIS_ LPBOOL pRetVal) PURE;

        //*** methods
    STDMETHOD(AddAlias)(THIS_ SQLDMO_LPCSTR LoginNames) PURE;
    STDMETHOD(RemoveAlias)(THIS_ SQLDMO_LPCSTR LoginNames) PURE;
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;

        // List methods
    STDMETHOD(ListAliases)(THIS_ LPSQLDMOLOGINLIST * ppList) PURE;
    STDMETHOD(ListOwnedObjects)(THIS_ LPSQLDMODBOBJECTLIST * ppList, SQLDMO_OBJECT_TYPE lObjectTypes CPPDEFAULT(= SQLDMOObj_AllDatabaseObjects), SQLDMO_OBJSORT_TYPE SortBy CPPDEFAULT(= SQLDMOObjSort_Name)) PURE;
    STDMETHOD(ListDatabasePermissions)(THIS_ LPSQLDMOPERMISSIONLIST * ppList, SQLDMO_PRIVILEGE_TYPE lPrivilegeTypes CPPDEFAULT(= SQLDMOPriv_AllDatabasePrivs)) PURE;
    STDMETHOD(ListObjectPermissions)(THIS_ LPSQLDMOPERMISSIONLIST * ppList, SQLDMO_PRIVILEGE_TYPE lPrivilegeTypes CPPDEFAULT(= SQLDMOPriv_AllObjectPrivs)) PURE;

    // 7.0
    STDMETHOD(ListMembers)(THIS_ LPSQLDMONAMELIST *ppList) PURE;
    STDMETHOD(GetRole)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetRole)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(IsMember)(THIS_ SQLDMO_LPCSTR DatabaseRole, LPBOOL pRetVal) PURE;
    STDMETHOD(GetHasDBAccess)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GrantNTUserDBAccess)(THIS) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(ListObjectColumnPermissions)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(ListPartialPermissions)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(GetIsDeleted)(THIS_ LPBOOL pRetVal) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOGroups
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
        STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOGROUP *ppObj) PURE;
        STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOGROUP *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOGROUP *ppObj) PURE;
        STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
        STDMETHOD(Add)(THIS_ LPSQLDMOGROUP Object) PURE;
        STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
        STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
        STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOGroup
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetSystemObject)(THIS_ LPBOOL pRetVal) PURE;

        //*** methods
    STDMETHOD(Remove)(THIS) PURE;

        // List methods
    STDMETHOD(ListUsers)(THIS_ LPSQLDMOUSERLIST * ppList) PURE;
    STDMETHOD(ListDatabasePermissions)(THIS_ LPSQLDMOPERMISSIONLIST * ppList, SQLDMO_PRIVILEGE_TYPE lPrivilegeTypes CPPDEFAULT(= SQLDMOPriv_AllDatabasePrivs)) PURE;
    STDMETHOD(ListObjectPermissions)(THIS_ LPSQLDMOPERMISSIONLIST * ppList, SQLDMO_PRIVILEGE_TYPE lPrivilegeTypes CPPDEFAULT(= SQLDMOPriv_AllObjectPrivs)) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOTriggers
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
        STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOTRIGGER *ppObj) PURE;
        STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTRIGGER *ppObj, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOTRIGGER *ppObj) PURE;
        STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
        STDMETHOD(Add)(THIS_ LPSQLDMOTRIGGER Object) PURE;
        STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
        STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
        STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOTrigger
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetCreateDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetText)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetText)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetType)(THIS_ SQLDMO_TRIGGER_TYPE *pRetVal) PURE;
    STDMETHOD(GetSystemObject)(THIS_ LPBOOL pRetVal) PURE;

        //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
    STDMETHOD(EnumDependencies)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_DEPENDENCY_TYPE DependencyType CPPDEFAULT(= SQLDMODep_Parents)) PURE;

    // 7.0
    STDMETHOD(SetOwner)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(Alter)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetEnabled)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetEnabled)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetQuotedIdentifierStatus)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetAnsiNullsStatus)(THIS_ LPBOOL pRetVal) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOTrigger2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOTrigger)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetCreateDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetText)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetText)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetType)(THIS_ SQLDMO_TRIGGER_TYPE *pRetVal) PURE;
    STDMETHOD(GetSystemObject)(THIS_ LPBOOL pRetVal) PURE;

        //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
    STDMETHOD(EnumDependencies)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_DEPENDENCY_TYPE DependencyType CPPDEFAULT(= SQLDMODep_Parents)) PURE;

    // 7.0
    STDMETHOD(SetOwner)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(Alter)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetEnabled)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetEnabled)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetQuotedIdentifierStatus)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetAnsiNullsStatus)(THIS_ LPBOOL pRetVal) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(SetAnsiNullsStatus)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetInsteadOfTrigger)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetAfterTrigger)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsDeleted)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetEncrypted)(THIS_ LPBOOL pRetVal) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMORemoteServers
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
        STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOREMOTESERVER *ppObj) PURE;
        STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOREMOTESERVER *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOREMOTESERVER *ppObj) PURE;
        STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
        STDMETHOD(Add)(THIS_ LPSQLDMOREMOTESERVER Object) PURE;
        STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
        STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
        STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMORemoteServer
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetNetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetNetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetOptions)(THIS_ SQLDMO_SRVOPTION_TYPE *pRetVal) PURE;
    STDMETHOD(GetTopologyX)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetTopologyY)(THIS_ LPLONG pRetVal) PURE;

       //*** collection properties
    STDMETHOD(GetRemoteLogins)(THIS_ LPSQLDMOREMOTELOGINS * ppRemoteLogins) PURE;
    STDMETHOD(GetRemoteLoginByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOREMOTELOGIN *ppRemoteLogin) PURE;
    STDMETHOD(GetRemoteLoginByOrd)(THIS_ long lOrdinal, LPSQLDMOREMOTELOGIN *ppRemoteLogin) PURE;
    STDMETHOD(RemoveRemoteLoginByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveRemoteLoginByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddRemoteLogin)(THIS_ LPSQLDMOREMOTELOGIN pRemoteLogin) PURE;
    STDMETHOD(GetRemoteLoginCount)(THIS_ LPLONG plCount) PURE;

        //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(ExecuteImmediate)(THIS_ SQLDMO_LPCSTR Command, long lLength CPPDEFAULT(= 0)) PURE;
    STDMETHOD(ExecuteWithResults)(THIS_ SQLDMO_LPCSTR Command, LPSQLDMOQUERYRESULTS *ppResults, long lLength CPPDEFAULT(= 0)) PURE;
    STDMETHOD(SetOptions)(THIS_ SQLDMO_SRVOPTION_TYPE Options, BOOL NewValue) PURE;
//    STDMETHOD(EnumTasks)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPCSTR TaskName CPPDEFAULT(= NULL), long TaskID CPPDEFAULT(= 0)) PURE;
    STDMETHOD(SetTopologyXY)(THIS_ long X, long Y) PURE;

        // Post-6.0 additions
    STDMETHOD(ExecuteWithResultsAndMessages)(THIS_ SQLDMO_LPCSTR Command, LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPBSTR ppszMessages CPPDEFAULT(= 0), long lLength CPPDEFAULT(= 0)) PURE;
};

/**
#undef INTERFACE
#define INTERFACE ISQLDMORemoteServer2
DECLARE_INTERFACE_(INTERFACE, ISQLDMORemoteServer)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetNetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetNetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetOptions)(THIS_ SQLDMO_SRVOPTION_TYPE *pRetVal) PURE;
    STDMETHOD(GetTopologyX)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetTopologyY)(THIS_ LPLONG pRetVal) PURE;

       //*** collection properties
    STDMETHOD(GetRemoteLogins)(THIS_ LPSQLDMOREMOTELOGINS * ppRemoteLogins) PURE;
    STDMETHOD(GetRemoteLoginByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOREMOTELOGIN *ppRemoteLogin) PURE;
    STDMETHOD(GetRemoteLoginByOrd)(THIS_ long lOrdinal, LPSQLDMOREMOTELOGIN *ppRemoteLogin) PURE;
    STDMETHOD(RemoveRemoteLoginByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveRemoteLoginByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddRemoteLogin)(THIS_ LPSQLDMOREMOTELOGIN pRemoteLogin) PURE;
    STDMETHOD(GetRemoteLoginCount)(THIS_ LPLONG plCount) PURE;

        //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(ExecuteImmediate)(THIS_ SQLDMO_LPCSTR Command, long lLength CPPDEFAULT(= 0)) PURE;
    STDMETHOD(ExecuteWithResults)(THIS_ SQLDMO_LPCSTR Command, LPSQLDMOQUERYRESULTS *ppResults, long lLength CPPDEFAULT(= 0)) PURE;
    STDMETHOD(SetOptions)(THIS_ SQLDMO_SRVOPTION_TYPE Options, BOOL NewValue) PURE;
//    STDMETHOD(EnumTasks)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPCSTR TaskName CPPDEFAULT(= NULL), long TaskID CPPDEFAULT(= 0)) PURE;
    STDMETHOD(SetTopologyXY)(THIS_ long X, long Y) PURE;

        // Post-6.0 additions
    STDMETHOD(ExecuteWithResultsAndMessages)(THIS_ SQLDMO_LPCSTR Command, LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPBSTR ppszMessages CPPDEFAULT(= 0), long lLength CPPDEFAULT(= 0)) PURE;
#endif // NO_BASEINTERFACE_FUNCS
};
**/

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMORemoteLogins
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
        STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOREMOTELOGIN *ppObj) PURE;
        STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOREMOTELOGIN *ppObj) PURE;
        STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
        STDMETHOD(Add)(THIS_ LPSQLDMOREMOTELOGIN Object) PURE;
        STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
        STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
        STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMORemoteLogin
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetLocalName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetLocalName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetRemoteName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetRemoteName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetTrusted)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetTrusted)(THIS_ BOOL NewValue) PURE;

        //*** methods
    STDMETHOD(Remove)(THIS) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOSystemDatatypes
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
        STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOSYSTEMDATATYPE *ppObj) PURE;
        STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOSYSTEMDATATYPE *ppObj) PURE;
        STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOSystemDatatype
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetMaximumLength)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetAllowNulls)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsNumeric)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetAllowIdentity)(THIS_ LPBOOL pRetVal) PURE;

    // 7.0
    STDMETHOD(GetIsVariableLength)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetAllowLength)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetMaximumChar)(THIS_ LPLONG pRetVal) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOSystemDatatype2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOSystemDatatype)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetMaximumLength)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetAllowNulls)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsNumeric)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetAllowIdentity)(THIS_ LPBOOL pRetVal) PURE;

    // 7.0
    STDMETHOD(GetIsVariableLength)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetAllowLength)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetMaximumChar)(THIS_ LPLONG pRetVal) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(GetCollation)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOChecks
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
        STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOCHECK *ppObj) PURE;
        STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOCHECK *ppObj) PURE;
        STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
        STDMETHOD(Add)(THIS_ LPSQLDMOCHECK Object) PURE;
        STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
        STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
        STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOCheck
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetText)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetText)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetExcludeReplication)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetExcludeReplication)(THIS_ BOOL NewValue) PURE;

        //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;

    // 7.0
    STDMETHOD(GetChecked)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetChecked)(THIS_ BOOL NewValue) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOServerGroups
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
        STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOSERVERGROUP *ppObj) PURE;
    STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOSERVERGROUP *ppObj) PURE;
    STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
    STDMETHOD(Add)(THIS_ LPSQLDMOSERVERGROUP Object) PURE;
    STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOServerGroup
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

        //*** Collection Properties
    STDMETHOD(GetRegisteredServers)(THIS_ LPSQLDMOREGISTEREDSERVERS *ppRegisteredServers) PURE;
    STDMETHOD(GetRegisteredServerByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOREGISTEREDSERVER *ppRegisteredServer) PURE;
    STDMETHOD(GetRegisteredServerByOrd)(THIS_ long lOrdinal, LPSQLDMOREGISTEREDSERVER *ppRegisteredServer) PURE;
    STDMETHOD(RemoveRegisteredServerByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveRegisteredServerByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddRegisteredServer)(THIS_ LPSQLDMOREGISTEREDSERVER pRegisteredServer) PURE;
    STDMETHOD(GetRegisteredServerCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetServerGroups)(THIS_ LPSQLDMOSERVERGROUPS *ppServerGroups) PURE;
    STDMETHOD(GetServerGroupByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOSERVERGROUP *ppServerGroup) PURE;
    STDMETHOD(GetServerGroupByOrd)(THIS_ long lOrdinal, LPSQLDMOSERVERGROUP *ppServerGroup) PURE;
    STDMETHOD(RemoveServerGroupByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveServerGroupByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddServerGroup)(THIS_ LPSQLDMOSERVERGROUP pServerGroup) PURE;
    STDMETHOD(GetServerGroupCount)(THIS_ LPLONG plCount) PURE;

        //*** methods
    STDMETHOD(Remove)(THIS) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMORegisteredServers
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
    STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOREGISTEREDSERVER *ppObj) PURE;
    STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOREGISTEREDSERVER *ppObj) PURE;
    STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

//*** SQLDMO standard collection methods
    STDMETHOD(Add)(THIS_ LPSQLDMOREGISTEREDSERVER Object) PURE;
    STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMORegisteredServer
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetLogin)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetLogin)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPassword)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetUseTrustedConnection)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetUseTrustedConnection)(THIS_ LONG NewValue) PURE;
    STDMETHOD(GetVersionMajor)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetVersionMinor)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetSaLogin)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetPersistFlags)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetPersistFlags)(THIS_ LONG NewValue) PURE;

        //*** methods
    STDMETHOD(Remove)(THIS) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOQueryResults
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetResultSets)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetCurrentResultSet)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetCurrentResultSet)(THIS_ long NewValue) PURE;
    STDMETHOD(GetRows)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetColumns)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetColumnName)(THIS_ long lColumn, SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetColumnType)(THIS_ long lColumn, SQLDMO_QUERY_DATATYPE *pRetVal) PURE;
    STDMETHOD(GetColumnMaxLength)(THIS_ long lColumn, LPLONG pRetVal) PURE;

        //*** methods
    STDMETHOD(GetColumnLong)(THIS_ long lRow, long lColumn, LPLONG pRetVal) PURE;
    STDMETHOD(GetColumnBool)(THIS_ long lRow, long lColumn, LPBOOL pRetVal) PURE;
    STDMETHOD(GetColumnFloat)(THIS_ long lRow, long lColumn, LPFLOAT pRetVal) PURE;
    STDMETHOD(GetColumnDouble)(THIS_ long lRow, long lColumn, LPDOUBLE pRetVal) PURE;
    STDMETHOD(GetColumnString)(THIS_ long lRow, long lColumn, SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetRangeString)(THIS_ SQLDMO_LPBSTR pRetVal, long Top CPPDEFAULT(= 0), long Left CPPDEFAULT(= 0),
                                                                long Bottom CPPDEFAULT(= -1), long Right CPPDEFAULT(= -1),
                                                                SQLDMO_LPCSTR RowDelim CPPDEFAULT(= NULL), SQLDMO_LPCSTR ColDelim CPPDEFAULT(= NULL),
                                                                SQLDMO_LPCSTR ColWidths CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(Refresh)(THIS) PURE;

        // Post-6.0 additions
    STDMETHOD(GetColumnDate)(THIS_ long lRow, long lColumn, LPSYSTEMTIME pSystemTime) PURE;
    STDMETHOD(GetColumnBinary)(THIS_ long lRow, long lColumn, LPVOID *pvData) PURE;

    // 7.0
    STDMETHOD(GetColumnBinaryLength)(THIS_ long lRow, long lColumn, LPLONG pRetLen) PURE;
    STDMETHOD(GetColumnGUID)(THIS_ long lRow, long lColumn, LPVOID *pvData) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOQueryResults2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOQueryResults)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetResultSets)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetCurrentResultSet)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetCurrentResultSet)(THIS_ long NewValue) PURE;
    STDMETHOD(GetRows)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetColumns)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetColumnName)(THIS_ long lColumn, SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetColumnType)(THIS_ long lColumn, SQLDMO_QUERY_DATATYPE *pRetVal) PURE;
    STDMETHOD(GetColumnMaxLength)(THIS_ long lColumn, LPLONG pRetVal) PURE;

        //*** methods
    STDMETHOD(GetColumnLong)(THIS_ long lRow, long lColumn, LPLONG pRetVal) PURE;
    STDMETHOD(GetColumnBool)(THIS_ long lRow, long lColumn, LPBOOL pRetVal) PURE;
    STDMETHOD(GetColumnFloat)(THIS_ long lRow, long lColumn, LPFLOAT pRetVal) PURE;
    STDMETHOD(GetColumnDouble)(THIS_ long lRow, long lColumn, LPDOUBLE pRetVal) PURE;
    STDMETHOD(GetColumnString)(THIS_ long lRow, long lColumn, SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetRangeString)(THIS_ SQLDMO_LPBSTR pRetVal, long Top CPPDEFAULT(= 0), long Left CPPDEFAULT(= 0),
                                                                long Bottom CPPDEFAULT(= -1), long Right CPPDEFAULT(= -1),
                                                                SQLDMO_LPCSTR RowDelim CPPDEFAULT(= NULL), SQLDMO_LPCSTR ColDelim CPPDEFAULT(= NULL),
                                                                SQLDMO_LPCSTR ColWidths CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(Refresh)(THIS) PURE;

        // Post-6.0 additions
    STDMETHOD(GetColumnDate)(THIS_ long lRow, long lColumn, LPSYSTEMTIME pSystemTime) PURE;
    STDMETHOD(GetColumnBinary)(THIS_ long lRow, long lColumn, LPVOID *pvData) PURE;

    // 7.0
    STDMETHOD(GetColumnBinaryLength)(THIS_ long lRow, long lColumn, LPLONG pRetLen) PURE;
    STDMETHOD(GetColumnGUID)(THIS_ long lRow, long lColumn, LPVOID *pvData) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(GetColumnSQLVARIANT)(THIS_ long lRow, long lColumn, LPVOID *pvData) PURE;
    STDMETHOD(GetColumnSQLVARIANTDataType)(THIS_ long lRow, long lColumn, SQLDMO_LPCSTR ObjName, SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetColumnSQLVARIANTLength)(THIS_ long lRow, long lColumn, SQLDMO_LPCSTR ObjName, LPLONG pRetLen) PURE;
    STDMETHOD(GetColumnSQLVARIANTToString)(THIS_ long lRow, long lColumn, SQLDMO_LPCSTR ObjName, SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetColumnBigInt)(THIS_ long lRow, long lColumn, PLONGLONG pRetVal) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOTransactionLog
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetCreateDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetLastBackup)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetSize)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetSpaceAvailable)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetSpaceAvailableInMB)(THIS_ LPFLOAT pRetVal) PURE;
    STDMETHOD(GetSpaceAllocatedOnFiles)(THIS_ SQLDMO_LPCSTR DatabaseName, LPLONG pRetVal) PURE;

        //*** methods
    STDMETHOD(Truncate)(THIS) PURE;

    // 7.0
    //*** Collection properties
    STDMETHOD(GetLogFiles)(THIS_ LPSQLDMOLOGFILES * ppLogFiles) PURE;
    STDMETHOD(GetLogFileByOrd)(THIS_ long lOrdinal, LPSQLDMOLOGFILE *ppLogFile) PURE;
    STDMETHOD(AddLogFile)(THIS_ LPSQLDMOLOGFILE pLogFile) PURE;
    STDMETHOD(GetLogFileCount)(THIS_ LPLONG plCount) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOTransactionLog2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOTransactionLog)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetCreateDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetLastBackup)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetSize)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetSpaceAvailable)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetSpaceAvailableInMB)(THIS_ LPFLOAT pRetVal) PURE;
    STDMETHOD(GetSpaceAllocatedOnFiles)(THIS_ SQLDMO_LPCSTR DatabaseName, LPLONG pRetVal) PURE;

        //*** methods
    STDMETHOD(Truncate)(THIS) PURE;

    // 7.0
    //*** Collection properties
    STDMETHOD(GetLogFiles)(THIS_ LPSQLDMOLOGFILES * ppLogFiles) PURE;
    STDMETHOD(GetLogFileByOrd)(THIS_ long lOrdinal, LPSQLDMOLOGFILE *ppLogFile) PURE;
    STDMETHOD(AddLogFile)(THIS_ LPSQLDMOLOGFILE pLogFile) PURE;
    STDMETHOD(GetLogFileCount)(THIS_ LPLONG plCount) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(RemoveLogFileByOrd)(THIS_ long lOrdinal) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOPermission
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetPrivilegeTypeName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetPrivilegeType)(THIS_ SQLDMO_PRIVILEGE_TYPE *pRetVal) PURE;
    STDMETHOD(GetObjectName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetObjectOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetObjectTypeName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetObjectType)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetObjectID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetGrantee)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetGranted)(THIS_ LPBOOL pRetVal) PURE;

        //*** methods
        // List methods
    STDMETHOD(ListPrivilegeColumns)(THIS_ LPSQLDMOCOLUMNLIST * ppList) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOPermission2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOPermission)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetPrivilegeTypeName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetPrivilegeType)(THIS_ SQLDMO_PRIVILEGE_TYPE *pRetVal) PURE;
    STDMETHOD(GetObjectName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetObjectOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetObjectTypeName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetObjectType)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetObjectID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetGrantee)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetGranted)(THIS_ LPBOOL pRetVal) PURE;

        //*** methods
        // List methods
    STDMETHOD(ListPrivilegeColumns)(THIS_ LPSQLDMOCOLUMNLIST * ppList) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(GetGrantedGranted)(THIS_ LPBOOL pRetVal) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMODBOption
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetSelectIntoBulkCopy)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetSelectIntoBulkCopy)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetDBOUseOnly)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetDBOUseOnly)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetReadOnly)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetReadOnly)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetSingleUser)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetSingleUser)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetTruncateLogOnCheckpoint)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetTruncateLogOnCheckpoint)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetColumnsNullByDefault)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetColumnsNullByDefault)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetOffline)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetOffline)(THIS_ BOOL NewValue) PURE;

        //*** methods
    STDMETHOD(Refresh)(THIS) PURE;

    // 7.0
    STDMETHOD(GetRecursiveTriggers)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetRecursiveTriggers)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetAutoShrink)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAutoShrink)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCompareNull)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCompareNull)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetContactNull)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetContactNull)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCursorCloseOnCommit)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCursorCloseOnCommit)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetDefaultCursor)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetDefaultCursor)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetQuoteDelimiter)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetQuoteDelimiter)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetAssignmentDiag)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAssignmentDiag)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetTornPageDetection)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetTornPageDetection)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetAutoClose)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAutoClose)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetAutoCreateStat)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAutoCreateStat)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetAutoUpdateStat)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAutoUpdateStat)(THIS_ BOOL NewValue) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMODBOption2
DECLARE_INTERFACE_(INTERFACE, ISQLDMODBOption)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetSelectIntoBulkCopy)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetSelectIntoBulkCopy)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetDBOUseOnly)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetDBOUseOnly)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetReadOnly)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetReadOnly)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetSingleUser)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetSingleUser)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetTruncateLogOnCheckpoint)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetTruncateLogOnCheckpoint)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetColumnsNullByDefault)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetColumnsNullByDefault)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetOffline)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetOffline)(THIS_ BOOL NewValue) PURE;

        //*** methods
    STDMETHOD(Refresh)(THIS) PURE;

    // 7.0
    STDMETHOD(GetRecursiveTriggers)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetRecursiveTriggers)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetAutoShrink)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAutoShrink)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCompareNull)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCompareNull)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetContactNull)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetContactNull)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCursorCloseOnCommit)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCursorCloseOnCommit)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetDefaultCursor)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetDefaultCursor)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetQuoteDelimiter)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetQuoteDelimiter)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetAssignmentDiag)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAssignmentDiag)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetTornPageDetection)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetTornPageDetection)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetAutoClose)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAutoClose)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetAutoCreateStat)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAutoCreateStat)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetAutoUpdateStat)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAutoUpdateStat)(THIS_ BOOL NewValue) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(GetRecoveryModel)(THIS_ SQLDMO_RECOVERY_TYPE *pRetVal) PURE;
    STDMETHOD(SetRecoveryModel)(THIS_ SQLDMO_RECOVERY_TYPE NewValue) PURE;
};


////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMODBObject
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetTypeName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetType)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetCreateDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetSystemObject)(THIS_ LPBOOL pRetVal) PURE;

    //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
    STDMETHOD(EnumDependencies)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_DEPENDENCY_TYPE DependencyType CPPDEFAULT(= SQLDMODep_Parents)) PURE;

        // List methods
    STDMETHOD(ListPermissions)(THIS_ LPSQLDMOPERMISSIONLIST * ppList, SQLDMO_PRIVILEGE_TYPE lPrivilegeTypes CPPDEFAULT(= SQLDMOPriv_AllObjectPrivs)) PURE;
    STDMETHOD(ListUserPermissions)(THIS_ SQLDMO_LPCSTR UserName, LPSQLDMOPERMISSIONLIST * ppList) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMODBObject2
DECLARE_INTERFACE_(INTERFACE, ISQLDMODBObject)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetTypeName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetType)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetCreateDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetSystemObject)(THIS_ LPBOOL pRetVal) PURE;

    //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
    STDMETHOD(EnumDependencies)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_DEPENDENCY_TYPE DependencyType CPPDEFAULT(= SQLDMODep_Parents)) PURE;

        // List methods
    STDMETHOD(ListPermissions)(THIS_ LPSQLDMOPERMISSIONLIST * ppList, SQLDMO_PRIVILEGE_TYPE lPrivilegeTypes CPPDEFAULT(= SQLDMOPriv_AllObjectPrivs)) PURE;
    STDMETHOD(ListUserPermissions)(THIS_ SQLDMO_LPCSTR UserName, LPSQLDMOPERMISSIONLIST * ppList) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(ListColumnPermissions)(THIS_ LPSQLDMOPERMISSIONLIST * ppList) PURE;
    STDMETHOD(ListPartialPermissions)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMODRIDefault
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetText)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetText)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

        //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOTransfer
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetDestServer)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDestServer)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDestLogin)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDestLogin)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDestPassword)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDestPassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDestDatabase)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDestDatabase)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDestUseTrustedConnection)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetDestUseTrustedConnection)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCopyData)(THIS_ SQLDMO_COPYDATA_TYPE *pRetVal) PURE;
    STDMETHOD(SetCopyData)(THIS_ SQLDMO_COPYDATA_TYPE NewValue) PURE;
    STDMETHOD(GetCopySchema)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCopySchema)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCopyAllObjects)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCopyAllObjects)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCopyAllTables)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCopyAllTables)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCopyAllViews)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCopyAllViews)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCopyAllStoredProcedures)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCopyAllStoredProcedures)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCopyAllUserDefinedDatatypes)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCopyAllUserDefinedDatatypes)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCopyAllRules)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCopyAllRules)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCopyAllDefaults)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCopyAllDefaults)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCopyAllTriggers)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCopyAllTriggers)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetIncludeDependencies)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetIncludeDependencies)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetIncludeUsers)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetIncludeUsers)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetIncludeGroups)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetIncludeGroups)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetIncludeLogins)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetIncludeLogins)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetDropDestObjectsFirst)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetDropDestObjectsFirst)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetScriptType)(THIS_ SQLDMO_SCRIPT_TYPE * pRetVal) PURE;
    STDMETHOD(SetScriptType)(THIS_ SQLDMO_SCRIPT_TYPE NewValue) PURE;

    //*** methods
    STDMETHOD(AddObjectByName)(THIS_ SQLDMO_LPCSTR ObjectName, SQLDMO_OBJECT_TYPE ObjectType, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(AddObject)(THIS_ LPSQLDMODBOBJECT DBObject) PURE;
    STDMETHOD(ListObjectNames)(THIS_ SQLDMO_OBJECT_TYPE ObjectType, LPSQLDMONAMELIST * ppList) PURE;
    STDMETHOD(Abort)(THIS) PURE;

    // 7.0
    STDMETHOD(GetScript2Type)(THIS_ SQLDMO_SCRIPT2_TYPE * pRetVal) PURE;
    STDMETHOD(SetScript2Type)(THIS_ SQLDMO_SCRIPT2_TYPE NewValue) PURE;
    STDMETHOD(RetrieveErrors)(THIS_ SQLDMO_LPBSTR pbstrMsg) PURE;
    STDMETHOD(RetrieveWriteFileErrors)(THIS_ SQLDMO_LPBSTR pbstrMsg) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOTransfer2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOTransfer)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetDestServer)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDestServer)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDestLogin)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDestLogin)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDestPassword)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDestPassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDestDatabase)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDestDatabase)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDestUseTrustedConnection)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetDestUseTrustedConnection)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCopyData)(THIS_ SQLDMO_COPYDATA_TYPE *pRetVal) PURE;
    STDMETHOD(SetCopyData)(THIS_ SQLDMO_COPYDATA_TYPE NewValue) PURE;
    STDMETHOD(GetCopySchema)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCopySchema)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCopyAllObjects)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCopyAllObjects)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCopyAllTables)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCopyAllTables)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCopyAllViews)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCopyAllViews)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCopyAllStoredProcedures)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCopyAllStoredProcedures)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCopyAllUserDefinedDatatypes)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCopyAllUserDefinedDatatypes)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCopyAllRules)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCopyAllRules)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCopyAllDefaults)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCopyAllDefaults)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCopyAllTriggers)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCopyAllTriggers)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetIncludeDependencies)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetIncludeDependencies)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetIncludeUsers)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetIncludeUsers)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetIncludeGroups)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetIncludeGroups)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetIncludeLogins)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetIncludeLogins)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetDropDestObjectsFirst)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetDropDestObjectsFirst)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetScriptType)(THIS_ SQLDMO_SCRIPT_TYPE * pRetVal) PURE;
    STDMETHOD(SetScriptType)(THIS_ SQLDMO_SCRIPT_TYPE NewValue) PURE;

    //*** methods
    STDMETHOD(AddObjectByName)(THIS_ SQLDMO_LPCSTR ObjectName, SQLDMO_OBJECT_TYPE ObjectType, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(AddObject)(THIS_ LPSQLDMODBOBJECT DBObject) PURE;
    STDMETHOD(ListObjectNames)(THIS_ SQLDMO_OBJECT_TYPE ObjectType, LPSQLDMONAMELIST * ppList) PURE;
    STDMETHOD(Abort)(THIS) PURE;

    // 7.0
    STDMETHOD(GetScript2Type)(THIS_ SQLDMO_SCRIPT2_TYPE * pRetVal) PURE;
    STDMETHOD(SetScript2Type)(THIS_ SQLDMO_SCRIPT2_TYPE NewValue) PURE;
    STDMETHOD(RetrieveErrors)(THIS_ SQLDMO_LPBSTR pbstrMsg) PURE;
    STDMETHOD(RetrieveWriteFileErrors)(THIS_ SQLDMO_LPBSTR pbstrMsg) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(GetSourceTranslateChar)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetSourceTranslateChar)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetDestTranslateChar)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetDestTranslateChar)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetIncludeDB)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetIncludeDB)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCopyAllFunctions)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCopyAllFunctions)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(RemoveAllObjects)(THIS) PURE;
    STDMETHOD(GetUseCollation)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetUseCollation)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetUseDestTransaction)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetUseDestTransaction)(THIS_ BOOL NewValue) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOTransferSink
DECLARE_INTERFACE_(INTERFACE, IUnknown)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** Sink properties and methods.
    STDMETHOD(StatusMessage)(THIS_ SQLDMO_LPCSTR szMessage) PURE;
    STDMETHOD(PercentCompleteAtStep)(THIS_ SQLDMO_LPCSTR szMessage, long Percent) PURE;
    STDMETHOD(ScriptTransferPercentComplete)(THIS_ SQLDMO_LPCSTR szMessage, long Percent) PURE;
    STDMETHOD(TransferPercentComplete)(THIS_ SQLDMO_LPCSTR szMessage, long Percent) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOBackup
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetPercentCompleteNotification)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetPercentCompleteNotification)(THIS_ long NewValue) PURE;
    STDMETHOD(GetSkipTapeHeader)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetSkipTapeHeader)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetUnloadTapeAfter)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetUnloadTapeAfter)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetDatabase)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDatabase)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetFiles)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetFiles)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDatabaseFileGroups)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDatabaseFileGroups)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDatabaseFiles)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDatabaseFiles)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetAction)(THIS_ SQLDMO_BACKUP_TYPE * pRetVal) PURE;
    STDMETHOD(SetAction)(THIS_ SQLDMO_BACKUP_TYPE NewValue) PURE;
    STDMETHOD(GetBackupSetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetBackupSetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetBackupSetDescription)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetBackupSetDescription)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetRestart)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetRestart)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetTruncateLog)(THIS_ SQLDMO_BACKUP_LOG_TYPE * pRetVal) PURE;
    STDMETHOD(SetTruncateLog)(THIS_ SQLDMO_BACKUP_LOG_TYPE NewValue) PURE;
    STDMETHOD(GetBlockSize)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetBlockSize)(THIS_ long NewValue) PURE;
    STDMETHOD(GetFormatMedia)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetFormatMedia)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetMediaName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetMediaName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetMediaDescription)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetMediaDescription)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDevices)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDevices)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetTapes)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetTapes)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPipes)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPipes)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetExpirationDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetExpirationDate)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetInitialize)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetInitialize)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetRetainDays)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetRetainDays)(THIS_ long NewValue) PURE;

        // methods
    STDMETHOD(Abort)(THIS) PURE;
    STDMETHOD(SQLBackup)(THIS_ LPSQLDMOSERVER ServerObject) PURE;
    STDMETHOD(GenerateSQL)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOBackup2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOBackup)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetPercentCompleteNotification)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetPercentCompleteNotification)(THIS_ long NewValue) PURE;
    STDMETHOD(GetSkipTapeHeader)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetSkipTapeHeader)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetUnloadTapeAfter)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetUnloadTapeAfter)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetDatabase)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDatabase)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetFiles)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetFiles)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDatabaseFileGroups)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDatabaseFileGroups)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDatabaseFiles)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDatabaseFiles)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetAction)(THIS_ SQLDMO_BACKUP_TYPE * pRetVal) PURE;
    STDMETHOD(SetAction)(THIS_ SQLDMO_BACKUP_TYPE NewValue) PURE;
    STDMETHOD(GetBackupSetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetBackupSetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetBackupSetDescription)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetBackupSetDescription)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetRestart)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetRestart)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetTruncateLog)(THIS_ SQLDMO_BACKUP_LOG_TYPE * pRetVal) PURE;
    STDMETHOD(SetTruncateLog)(THIS_ SQLDMO_BACKUP_LOG_TYPE NewValue) PURE;
    STDMETHOD(GetBlockSize)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetBlockSize)(THIS_ long NewValue) PURE;
    STDMETHOD(GetFormatMedia)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetFormatMedia)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetMediaName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetMediaName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetMediaDescription)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetMediaDescription)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDevices)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDevices)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetTapes)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetTapes)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPipes)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPipes)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetExpirationDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetExpirationDate)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetInitialize)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetInitialize)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetRetainDays)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetRetainDays)(THIS_ long NewValue) PURE;

    // methods
    STDMETHOD(Abort)(THIS) PURE;
    STDMETHOD(SQLBackup)(THIS_ LPSQLDMOSERVER ServerObject) PURE;
    STDMETHOD(GenerateSQL)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(GetPassword)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetMediaPassword)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetMediaPassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetNoRewind)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetNoRewind)(THIS_ BOOL NewValue) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOBackupSink
DECLARE_INTERFACE_(INTERFACE, IUnknown)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** Sink properties and methods.
    STDMETHOD(PercentComplete)(THIS_ SQLDMO_LPCSTR Message, long Percent) PURE;
    STDMETHOD(NextMedia)(THIS_ SQLDMO_LPCSTR Message) PURE;
    STDMETHOD(Complete)(THIS_ SQLDMO_LPCSTR Message) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOBulkCopy
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetDataFilePath)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDataFilePath)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetFormatFilePath)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetFormatFilePath)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetErrorFilePath)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetErrorFilePath)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetLogFilePath)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetLogFilePath)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetColumnDelimiter)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetColumnDelimiter)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetRowDelimiter)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetRowDelimiter)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDataFileType)(THIS_ SQLDMO_DATAFILE_TYPE FAR* pRetVal) PURE;
    STDMETHOD(SetDataFileType)(THIS_ SQLDMO_DATAFILE_TYPE NewValue) PURE;
    STDMETHOD(GetFirstRow)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetFirstRow)(THIS_ long NewValue) PURE;
    STDMETHOD(GetLastRow)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetLastRow)(THIS_ long NewValue) PURE;
    STDMETHOD(GetMaximumErrorsBeforeAbort)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetMaximumErrorsBeforeAbort)(THIS_ long NewValue) PURE;
    STDMETHOD(GetIncludeIdentityValues)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetIncludeIdentityValues)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetImportRowsPerBatch)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetImportRowsPerBatch)(THIS_ long NewValue) PURE;
    STDMETHOD(GetUseBulkCopyOption)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetUseBulkCopyOption)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetSuspendIndexing)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetSuspendIndexing)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetTruncateLog)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetTruncateLog)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetUseExistingConnection)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetUseExistingConnection)(THIS_ BOOL NewValue) PURE;

    // 7.0
    STDMETHOD(GetUse6xCompatible)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetUse6xCompatible)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCodePage)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetCodePage)(THIS_ SQLDMO_BCP_CODEPAGE_TYPE NewValue, long UserCodePage CPPDEFAULT(= SQLDMOBCP_OEM)) PURE;
    STDMETHOD(GetUseServerSideBCP)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetUseServerSideBCP)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetServerBCPDataFileType)(THIS_ SQLDMO_SERVERBCP_DATAFILE_TYPE FAR* pRetVal) PURE;
    STDMETHOD(SetServerBCPDataFileType)(THIS_ SQLDMO_SERVERBCP_DATAFILE_TYPE NewValue) PURE;
    STDMETHOD(GetServerBCPKeepIdentity)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetServerBCPKeepIdentity)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetServerBCPKeepNulls)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetServerBCPKeepNulls)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetExportWideChar)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetExportWideChar)(THIS_ BOOL NewValue) PURE;

    // Methods
    STDMETHOD(Abort)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOBulkCopy2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOBulkCopy)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetDataFilePath)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDataFilePath)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetFormatFilePath)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetFormatFilePath)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetErrorFilePath)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetErrorFilePath)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetLogFilePath)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetLogFilePath)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetColumnDelimiter)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetColumnDelimiter)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetRowDelimiter)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetRowDelimiter)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDataFileType)(THIS_ SQLDMO_DATAFILE_TYPE FAR* pRetVal) PURE;
    STDMETHOD(SetDataFileType)(THIS_ SQLDMO_DATAFILE_TYPE NewValue) PURE;
    STDMETHOD(GetFirstRow)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetFirstRow)(THIS_ long NewValue) PURE;
    STDMETHOD(GetLastRow)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetLastRow)(THIS_ long NewValue) PURE;
    STDMETHOD(GetMaximumErrorsBeforeAbort)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetMaximumErrorsBeforeAbort)(THIS_ long NewValue) PURE;
    STDMETHOD(GetIncludeIdentityValues)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetIncludeIdentityValues)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetImportRowsPerBatch)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetImportRowsPerBatch)(THIS_ long NewValue) PURE;
    STDMETHOD(GetUseBulkCopyOption)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetUseBulkCopyOption)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetSuspendIndexing)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetSuspendIndexing)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetTruncateLog)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetTruncateLog)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetUseExistingConnection)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetUseExistingConnection)(THIS_ BOOL NewValue) PURE;

    // 7.0
    STDMETHOD(GetUse6xCompatible)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetUse6xCompatible)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCodePage)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetCodePage)(THIS_ SQLDMO_BCP_CODEPAGE_TYPE NewValue, long UserCodePage CPPDEFAULT(= SQLDMOBCP_OEM)) PURE;
    STDMETHOD(GetUseServerSideBCP)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetUseServerSideBCP)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetServerBCPDataFileType)(THIS_ SQLDMO_SERVERBCP_DATAFILE_TYPE FAR* pRetVal) PURE;
    STDMETHOD(SetServerBCPDataFileType)(THIS_ SQLDMO_SERVERBCP_DATAFILE_TYPE NewValue) PURE;
    STDMETHOD(GetServerBCPKeepIdentity)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetServerBCPKeepIdentity)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetServerBCPKeepNulls)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetServerBCPKeepNulls)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetExportWideChar)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetExportWideChar)(THIS_ BOOL NewValue) PURE;

    // Methods
    STDMETHOD(Abort)(THIS) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(GetTableLock)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetTableLock)(THIS_ BOOL NewValue) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOBulkCopySink
DECLARE_INTERFACE_(INTERFACE, IUnknown)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** Sink properties and methods.
    STDMETHOD(RowsCopied)(THIS_ SQLDMO_LPCSTR Message, long Rows) PURE;
    STDMETHOD(BatchImported)(THIS_ SQLDMO_LPCSTR Message) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// 7.0 new objects

#undef INTERFACE
#define INTERFACE ISQLDMOFileGroups
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
    STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOFILEGROUP *ppObj) PURE;
    STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOFILEGROUP *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOFILEGROUP *ppObj) PURE;
    STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

//*** SQLDMO standard collection methods
    STDMETHOD(Add)(THIS_ LPSQLDMOFILEGROUP Object) PURE;
    STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOFileGroup
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSize)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetReadOnly)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetReadOnly)(THIS_ BOOL pRetVal) PURE;
    STDMETHOD(GetDefault)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetDefault)(THIS_ BOOL pRetVal) PURE;

        // Collection properties
    STDMETHOD(GetDBFiles)(THIS_ LPSQLDMODBFILES *ppDBFiles) PURE;
    STDMETHOD(GetDBFileByOrd)(THIS_ long lOrdinal, LPSQLDMODBFILE *ppDBFile) PURE;
    STDMETHOD(RemoveDBFileByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddDBFile)(THIS_ LPSQLDMODBFILE pDBFile) PURE;
    STDMETHOD(GetDBFileCount)(THIS_ LPLONG plCount) PURE;

        //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(EnumObjects)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumFiles)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(CheckFilegroup)(THIS_ SQLDMO_LPBSTR pResult) PURE;
    STDMETHOD(CheckFilegroupDataOnly)(THIS_ SQLDMO_LPBSTR pResult) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOFileGroup2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOFileGroup)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSize)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetReadOnly)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetReadOnly)(THIS_ BOOL pRetVal) PURE;
    STDMETHOD(GetDefault)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetDefault)(THIS_ BOOL pRetVal) PURE;

        // Collection properties
    STDMETHOD(GetDBFiles)(THIS_ LPSQLDMODBFILES *ppDBFiles) PURE;
    STDMETHOD(GetDBFileByOrd)(THIS_ long lOrdinal, LPSQLDMODBFILE *ppDBFile) PURE;
    STDMETHOD(RemoveDBFileByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddDBFile)(THIS_ LPSQLDMODBFILE pDBFile) PURE;
    STDMETHOD(GetDBFileCount)(THIS_ LPLONG plCount) PURE;

        //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(EnumObjects)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumFiles)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(CheckFilegroup)(THIS_ SQLDMO_LPBSTR pResult) PURE;
    STDMETHOD(CheckFilegroupDataOnly)(THIS_ SQLDMO_LPBSTR pResult) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(CheckFilegroupWithResult)(THIS_ LPSQLDMOQUERYRESULTS * ppResults) PURE;
    STDMETHOD(CheckFilegroupDataOnlyWithResult)(THIS_ LPSQLDMOQUERYRESULTS * ppResults) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMODBFiles
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
    STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMODBFILE *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMODBFILE *ppObj) PURE;
    STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

//*** SQLDMO standard collection methods
    STDMETHOD(Add)(THIS_ LPSQLDMODBFILE Object) PURE;
    STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMODBFile
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPhysicalName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPhysicalName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPrimaryFile)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetPrimaryFile)(THIS_ BOOL pRetVal) PURE;
    STDMETHOD(GetFileGrowth)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetFileGrowth)(THIS_ long NewValue) PURE;
    STDMETHOD(GetMaximumSize)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetMaximumSize)(THIS_ long NewValue) PURE;
    STDMETHOD(GetSpaceAvailableInMB)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetSize)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetSize)(THIS_ long NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetFileGrowthType)(THIS_ SQLDMO_GROWTH_TYPE * pRetVal) PURE;
    STDMETHOD(SetFileGrowthType)(THIS_ SQLDMO_GROWTH_TYPE NewValue) PURE;
    STDMETHOD(GetFileGrowthInKB)(THIS_ LPFLOAT pRetVal) PURE;
    STDMETHOD(GetSizeInKB)(THIS_ LPFLOAT pRetVal) PURE;

        //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Shrink)(THIS_ long lNewSizeInMB, SQLDMO_SHRINK_TYPE Truncate) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOLogFiles
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
    STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOLOGFILE *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOLOGFILE *ppObj) PURE;
    STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

//*** SQLDMO standard collection methods
    STDMETHOD(Add)(THIS_ LPSQLDMOLOGFILE Object) PURE;
    STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOLogFiles2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOLogFiles)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
    STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOLOGFILE *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOLOGFILE *ppObj) PURE;
    STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

//*** SQLDMO standard collection methods
    STDMETHOD(Add)(THIS_ LPSQLDMOLOGFILE Object) PURE;
    STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOLogFile
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPhysicalName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPhysicalName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSize)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetSize)(THIS_ long NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetFileGrowth)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetFileGrowth)(THIS_ long NewValue) PURE;
    STDMETHOD(GetFileGrowthType)(THIS_ SQLDMO_GROWTH_TYPE * pRetVal) PURE;
    STDMETHOD(SetFileGrowthType)(THIS_ SQLDMO_GROWTH_TYPE NewValue) PURE;
    STDMETHOD(GetFileGrowthInKB)(THIS_ LPFLOAT pRetVal) PURE;
    STDMETHOD(GetMaximumSize)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetMaximumSize)(THIS_ long NewValue) PURE;
    STDMETHOD(GetSizeInKB)(THIS_ LPFLOAT pRetVal) PURE;

        //*** methods
    STDMETHOD(Shrink)(THIS_ long lNewSizeInMB, SQLDMO_SHRINK_TYPE Truncate) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOLogFile2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOLogFile)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPhysicalName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPhysicalName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSize)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetSize)(THIS_ long NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetFileGrowth)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetFileGrowth)(THIS_ long NewValue) PURE;
    STDMETHOD(GetFileGrowthType)(THIS_ SQLDMO_GROWTH_TYPE * pRetVal) PURE;
    STDMETHOD(SetFileGrowthType)(THIS_ SQLDMO_GROWTH_TYPE NewValue) PURE;
    STDMETHOD(GetFileGrowthInKB)(THIS_ LPFLOAT pRetVal) PURE;
    STDMETHOD(GetMaximumSize)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetMaximumSize)(THIS_ long NewValue) PURE;
    STDMETHOD(GetSizeInKB)(THIS_ LPFLOAT pRetVal) PURE;

        //*** methods
    STDMETHOD(Shrink)(THIS_ long lNewSizeInMB, SQLDMO_SHRINK_TYPE Truncate) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(Remove)(THIS) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOServerRoles
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
    STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOSERVERROLE *ppObj) PURE;
    STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOSERVERROLE *ppObj) PURE;
    STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

//*** SQLDMO standard collection methods
    STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOServerRole
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetFullName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetDescription)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;

        //*** methods
    STDMETHOD(EnumServerRolePermission)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumServerRoleMember)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(AddMember)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(DropMember)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMODatabaseRoles
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
    STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMODATABASEROLE *ppObj) PURE;
    STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMODATABASEROLE *ppObj) PURE;
    STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

//*** SQLDMO standard collection methods
    STDMETHOD(Add)(THIS_ LPSQLDMODATABASEROLE Object) PURE;
    STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMODatabaseRole
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPassword)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetAppRole)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAppRole)(THIS_ BOOL NewValue) PURE;

        //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(EnumDatabaseRoleMember)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(AddMember)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(DropMember)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
    STDMETHOD(EnumFixedDatabaseRolePermission)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(IsFixedRole)(THIS_ LPBOOL pRetVal) PURE;

    // List methods
    STDMETHOD(ListDatabasePermissions)(THIS_ LPSQLDMOPERMISSIONLIST * ppList, SQLDMO_PRIVILEGE_TYPE lPrivilegeTypes CPPDEFAULT(= SQLDMOPriv_AllDatabasePrivs)) PURE;
    STDMETHOD(ListObjectPermissions)(THIS_ LPSQLDMOPERMISSIONLIST * ppList, SQLDMO_PRIVILEGE_TYPE lPrivilegeTypes CPPDEFAULT(= SQLDMOPriv_AllObjectPrivs)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMODatabaseRole2
DECLARE_INTERFACE_(INTERFACE, ISQLDMODatabaseRole)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPassword)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetAppRole)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAppRole)(THIS_ BOOL NewValue) PURE;

        //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(EnumDatabaseRoleMember)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(AddMember)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(DropMember)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
    STDMETHOD(EnumFixedDatabaseRolePermission)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(IsFixedRole)(THIS_ LPBOOL pRetVal) PURE;

    // List methods
    STDMETHOD(ListDatabasePermissions)(THIS_ LPSQLDMOPERMISSIONLIST * ppList, SQLDMO_PRIVILEGE_TYPE lPrivilegeTypes CPPDEFAULT(= SQLDMOPriv_AllDatabasePrivs)) PURE;
    STDMETHOD(ListObjectPermissions)(THIS_ LPSQLDMOPERMISSIONLIST * ppList, SQLDMO_PRIVILEGE_TYPE lPrivilegeTypes CPPDEFAULT(= SQLDMOPriv_AllObjectPrivs)) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(ListPartialPermissions)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(GetIsDeleted)(THIS_ LPBOOL pRetVal) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMORestore
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetPercentCompleteNotification)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetPercentCompleteNotification)(THIS_ long NewValue) PURE;
    STDMETHOD(GetUnloadTapeAfter)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetUnloadTapeAfter)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetDatabase)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDatabase)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDevices)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDevices)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetFiles)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetFiles)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetTapes)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetTapes)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPipes)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPipes)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDatabaseFileGroups)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDatabaseFileGroups)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDatabaseFiles)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDatabaseFiles)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetAction)(THIS_ SQLDMO_RESTORE_TYPE * pRetVal) PURE;
    STDMETHOD(SetAction)(THIS_ SQLDMO_RESTORE_TYPE NewValue) PURE;
    STDMETHOD(GetBackupSetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetBackupSetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetRelocateFiles)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetRelocateFiles)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetReplaceDatabase)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetReplaceDatabase)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetLastRestore)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetLastRestore)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetRestart)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetRestart)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetMediaName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetMediaName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetLoadHistory)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetLoadHistory)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetFileNumber)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetFileNumber)(THIS_ long NewValue) PURE;
    STDMETHOD(GetToPointInTime)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetToPointInTime)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetStandbyFiles)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetStandbyFiles)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

    // Methods
    STDMETHOD(Abort)(THIS) PURE;
    STDMETHOD(SQLRestore)(THIS_ LPSQLDMOSERVER ServerObject) PURE;
    STDMETHOD(SQLVerify)(THIS_ LPSQLDMOSERVER ServerObject) PURE;
    STDMETHOD(GenerateSQL)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(ReadBackupHeader)(THIS_ LPSQLDMOSERVER ServerObject, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(ReadFileList)(THIS_ LPSQLDMOSERVER ServerObject, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(ReadMediaHeader)(THIS_ LPSQLDMOSERVER ServerObject, LPSQLDMOQUERYRESULTS *ppResults) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMORestore2
DECLARE_INTERFACE_(INTERFACE, ISQLDMORestore)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

        //*** properties
    STDMETHOD(GetPercentCompleteNotification)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetPercentCompleteNotification)(THIS_ long NewValue) PURE;
    STDMETHOD(GetUnloadTapeAfter)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetUnloadTapeAfter)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetDatabase)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDatabase)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDevices)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDevices)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetFiles)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetFiles)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetTapes)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetTapes)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPipes)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPipes)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDatabaseFileGroups)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDatabaseFileGroups)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDatabaseFiles)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDatabaseFiles)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetAction)(THIS_ SQLDMO_RESTORE_TYPE * pRetVal) PURE;
    STDMETHOD(SetAction)(THIS_ SQLDMO_RESTORE_TYPE NewValue) PURE;
    STDMETHOD(GetBackupSetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetBackupSetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetRelocateFiles)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetRelocateFiles)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetReplaceDatabase)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetReplaceDatabase)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetLastRestore)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetLastRestore)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetRestart)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetRestart)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetMediaName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetMediaName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetLoadHistory)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetLoadHistory)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetFileNumber)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetFileNumber)(THIS_ long NewValue) PURE;
    STDMETHOD(GetToPointInTime)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetToPointInTime)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetStandbyFiles)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetStandbyFiles)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

    // Methods
    STDMETHOD(Abort)(THIS) PURE;
    STDMETHOD(SQLRestore)(THIS_ LPSQLDMOSERVER ServerObject) PURE;
    STDMETHOD(SQLVerify)(THIS_ LPSQLDMOSERVER ServerObject) PURE;
    STDMETHOD(GenerateSQL)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(ReadBackupHeader)(THIS_ LPSQLDMOSERVER ServerObject, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(ReadFileList)(THIS_ LPSQLDMOSERVER ServerObject, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(ReadMediaHeader)(THIS_ LPSQLDMOSERVER ServerObject, LPSQLDMOQUERYRESULTS *ppResults) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(GetPassword)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetMediaPassword)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetMediaPassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetKeepReplication)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetKeepReplication)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetNoRewind)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetNoRewind)(THIS_ BOOL NewValue) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMORestoreSink
DECLARE_INTERFACE_(INTERFACE, IUnknown)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** Sink properties and methods.
    STDMETHOD(PercentComplete)(THIS_ SQLDMO_LPCSTR Message, long Percent) PURE;
    STDMETHOD(NextMedia)(THIS_ SQLDMO_LPCSTR Message) PURE;
    STDMETHOD(Complete)(THIS_ SQLDMO_LPCSTR Message) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOLinkedServers
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
    STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOLINKEDSERVER *ppObj) PURE;
    STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOLINKEDSERVER *ppObj) PURE;
    STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
    STDMETHOD(Add)(THIS_ LPSQLDMOLINKEDSERVER Object) PURE;
    STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOLinkedServer
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetProductName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetProductName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetProviderName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetProviderName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDataSource)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDataSource)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetLocation)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetLocation)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetProviderString)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetProviderString)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetOptions)(THIS_ SQLDMO_SRVOPTION_TYPE *pRetVal) PURE;

    //*** collection properties
    STDMETHOD(GetLinkedServerLogins)(THIS_ LPSQLDMOLINKEDSERVERLOGINS * ppLinkedServerLogins) PURE;
    STDMETHOD(GetLinkedServerLoginByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOLINKEDSERVERLOGIN *ppLinkedServerLogin) PURE;
    STDMETHOD(GetLinkedServerLoginByOrd)(THIS_ long lOrdinal, LPSQLDMOLINKEDSERVERLOGIN *ppLinkedServerLogin) PURE;
    STDMETHOD(RemoveLinkedServerLoginByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveLinkedServerLoginByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddLinkedServerLogin)(THIS_ LPSQLDMOLINKEDSERVERLOGIN pLinkedServerLogin) PURE;
    STDMETHOD(GetLinkedServerLoginCount)(THIS_ LPLONG plCount) PURE;

    //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(ExecuteImmediate)(THIS_ SQLDMO_LPCSTR Command, long lLength CPPDEFAULT(= 0)) PURE;
    STDMETHOD(ExecuteWithResults)(THIS_ SQLDMO_LPCSTR Command, LPSQLDMOQUERYRESULTS *ppResults, long lLength CPPDEFAULT(= 0)) PURE;
    STDMETHOD(ExecuteWithResultsAndMessages)(THIS_ SQLDMO_LPCSTR Command, LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPBSTR ppszMessages CPPDEFAULT(= 0), long lLength CPPDEFAULT(= 0)) PURE;
    STDMETHOD(SetOptions)(THIS_ SQLDMO_SRVOPTION_TYPE Options, BOOL NewValue) PURE;

    STDMETHOD(GetCatalog)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetCatalog)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

    STDMETHOD(EnumTables)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPCSTR TableName CPPDEFAULT(= NULL), SQLDMO_LPCSTR SchemaName CPPDEFAULT(= NULL), SQLDMO_LPCSTR CatalogName CPPDEFAULT(= NULL), SQLDMO_LINKEDTABLE_TYPE TableType CPPDEFAULT(= SQLDMOLinkedTable_Default)) PURE;
    STDMETHOD(EnumColumns)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPCSTR TableName CPPDEFAULT(= NULL), SQLDMO_LPCSTR SchemaName CPPDEFAULT(= NULL), SQLDMO_LPCSTR CatalogName CPPDEFAULT(= NULL), SQLDMO_LPCSTR ColumnName CPPDEFAULT(= NULL)) PURE;

    STDMETHOD(GetDropLogins)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetDropLogins)(THIS_ BOOL NewValue) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOLinkedServer2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOLinkedServer)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetProductName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetProductName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetProviderName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetProviderName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDataSource)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDataSource)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetLocation)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetLocation)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetProviderString)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetProviderString)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetOptions)(THIS_ SQLDMO_SRVOPTION_TYPE *pRetVal) PURE;

    //*** collection properties
    STDMETHOD(GetLinkedServerLogins)(THIS_ LPSQLDMOLINKEDSERVERLOGINS * ppLinkedServerLogins) PURE;
    STDMETHOD(GetLinkedServerLoginByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOLINKEDSERVERLOGIN *ppLinkedServerLogin) PURE;
    STDMETHOD(GetLinkedServerLoginByOrd)(THIS_ long lOrdinal, LPSQLDMOLINKEDSERVERLOGIN *ppLinkedServerLogin) PURE;
    STDMETHOD(RemoveLinkedServerLoginByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveLinkedServerLoginByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddLinkedServerLogin)(THIS_ LPSQLDMOLINKEDSERVERLOGIN pLinkedServerLogin) PURE;
    STDMETHOD(GetLinkedServerLoginCount)(THIS_ LPLONG plCount) PURE;

    //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(ExecuteImmediate)(THIS_ SQLDMO_LPCSTR Command, long lLength CPPDEFAULT(= 0)) PURE;
    STDMETHOD(ExecuteWithResults)(THIS_ SQLDMO_LPCSTR Command, LPSQLDMOQUERYRESULTS *ppResults, long lLength CPPDEFAULT(= 0)) PURE;
    STDMETHOD(ExecuteWithResultsAndMessages)(THIS_ SQLDMO_LPCSTR Command, LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPBSTR ppszMessages CPPDEFAULT(= 0), long lLength CPPDEFAULT(= 0)) PURE;
    STDMETHOD(SetOptions)(THIS_ SQLDMO_SRVOPTION_TYPE Options, BOOL NewValue) PURE;

    STDMETHOD(GetCatalog)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetCatalog)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

    STDMETHOD(EnumTables)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPCSTR TableName CPPDEFAULT(= NULL), SQLDMO_LPCSTR SchemaName CPPDEFAULT(= NULL), SQLDMO_LPCSTR CatalogName CPPDEFAULT(= NULL), SQLDMO_LINKEDTABLE_TYPE TableType CPPDEFAULT(= SQLDMOLinkedTable_Default)) PURE;
    STDMETHOD(EnumColumns)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPCSTR TableName CPPDEFAULT(= NULL), SQLDMO_LPCSTR SchemaName CPPDEFAULT(= NULL), SQLDMO_LPCSTR CatalogName CPPDEFAULT(= NULL), SQLDMO_LPCSTR ColumnName CPPDEFAULT(= NULL)) PURE;

    STDMETHOD(GetDropLogins)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetDropLogins)(THIS_ BOOL NewValue) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(GetCollationName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetCollationName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(Refresh)(THIS) PURE;
    STDMETHOD(GetConnectTimeout)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetConnectTimeout)(THIS_ long NewValue) PURE;
    STDMETHOD(GetQueryTimeout)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetQueryTimeout)(THIS_ long NewValue) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOLinkedServerLogins
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
    STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOLINKEDSERVERLOGIN *ppObj) PURE;
    STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOLINKEDSERVERLOGIN *ppObj) PURE;
    STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
    STDMETHOD(Add)(THIS_ LPSQLDMOLINKEDSERVERLOGIN Object) PURE;
    STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOLinkedServerLogin
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** properties
    STDMETHOD(GetLocalLogin)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetLocalLogin)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetRemoteUser)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetRemoteUser)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(SetRemotePassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetImpersonate)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetImpersonate)(THIS_ BOOL NewValue) PURE;

    //*** methods
    STDMETHOD(Remove)(THIS) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOFullTextCatalogs
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
    STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOFULLTEXTCATALOG *ppObj) PURE;
    STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOFULLTEXTCATALOG *ppObj) PURE;
    STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
    STDMETHOD(Add)(THIS_ LPSQLDMOFULLTEXTCATALOG Object) PURE;
    STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOFullTextCatalog
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetRootPath)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetRootPath)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetItemCount)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetPopulateStatus)(THIS_ SQLDMO_FULLTEXTSTATUS_TYPE *pRetVal) PURE;
    STDMETHOD(GetFullTextIndexSize)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetUniqueKeyCount)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetPopulateCompletionDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetErrorLogSize)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetHasFullTextIndexedTables)(THIS_ LPBOOL pRetVal) PURE;

    //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Start)(THIS_ SQLDMO_FULLTEXT_START_TYPE StartType) PURE;
    STDMETHOD(Stop)(THIS) PURE;
    STDMETHOD(GenerateSQL)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
    STDMETHOD(Rebuild)(THIS) PURE;

    STDMETHOD(GetFullTextCatalogID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetPopulateCompletionAge)(THIS_ LPLONG pRetVal) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOFullTextCatalog2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOFullTextCatalog)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetRootPath)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetRootPath)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetItemCount)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetPopulateStatus)(THIS_ SQLDMO_FULLTEXTSTATUS_TYPE *pRetVal) PURE;
    STDMETHOD(GetFullTextIndexSize)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetUniqueKeyCount)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetPopulateCompletionDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetErrorLogSize)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetHasFullTextIndexedTables)(THIS_ LPBOOL pRetVal) PURE;

    //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Start)(THIS_ SQLDMO_FULLTEXT_START_TYPE StartType) PURE;
    STDMETHOD(Stop)(THIS) PURE;
    STDMETHOD(GenerateSQL)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
    STDMETHOD(Rebuild)(THIS) PURE;

    STDMETHOD(GetFullTextCatalogID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetPopulateCompletionAge)(THIS_ LPLONG pRetVal) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(Refresh)(THIS) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOFullTextService
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
    //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** properties
    STDMETHOD(GetStatus)(THIS_ SQLDMO_SVCSTATUS_TYPE *pRetVal) PURE;
    STDMETHOD(GetDefaultPath)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetResourceUsage)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetResourceUsage)(THIS_ long NewValue) PURE;
    STDMETHOD(GetConnectTimeout)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetConnectTimeout)(THIS_ long NewValue) PURE;
    STDMETHOD(GetIsFullTextInstalled)(THIS_ LPBOOL pRetVal) PURE;

    //*** methods
    STDMETHOD(Start)(THIS) PURE;
    STDMETHOD(Stop)(THIS) PURE;
    STDMETHOD(CleanUp)(THIS) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// 8.0 new objects

#undef INTERFACE
#define INTERFACE ISQLDMOUserDefinedFunctions
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
    STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOUSERDEFINEDFUNCTION *ppObj) PURE;
    STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOUSERDEFINEDFUNCTION *ppObj, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOUSERDEFINEDFUNCTION *ppObj) PURE;
    STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
    STDMETHOD(Add)(THIS_ LPSQLDMOUSERDEFINEDFUNCTION Object) PURE;
    STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOUserDefinedFunction
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetOwner)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetCreateDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetText)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetText)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSystemObject)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetQuotedIdentifierStatus)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetAnsiNullsStatus)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAnsiNullsStatus)(THIS_ BOOL NewValue) PURE;

     //*** methods
    STDMETHOD(Grant)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR GranteeNames, BOOL GrantGrant CPPDEFAULT(=FALSE), SQLDMO_LPCSTR AsRole CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(Revoke)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR RevokeeNames, BOOL GrantGrant CPPDEFAULT(=FALSE), BOOL RevokeGrantOption CPPDEFAULT(=FALSE), SQLDMO_LPCSTR AsRole CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(EnumParameters)(THIS_ LPSQLDMOQUERYRESULTS * ppResults) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
    STDMETHOD(EnumDependencies)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_DEPENDENCY_TYPE DependencyType CPPDEFAULT(= SQLDMODep_Parents)) PURE;
    STDMETHOD(Deny)(THIS_ SQLDMO_PRIVILEGE_TYPE iPrivileges, SQLDMO_LPCSTR DenyeeNames, BOOL GrantGrant CPPDEFAULT(=FALSE)) PURE;
    STDMETHOD(Alter)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

    // List methods
    STDMETHOD(ListPermissions)(THIS_ LPSQLDMOPERMISSIONLIST * ppList, SQLDMO_PRIVILEGE_TYPE lPrivilegeTypes CPPDEFAULT(= SQLDMOPriv_AllObjectPrivs)) PURE;
    STDMETHOD(ListUserPermissions)(THIS_ SQLDMO_LPCSTR UserName, LPSQLDMOPERMISSIONLIST * ppList) PURE;

    STDMETHOD(GetType)(THIS_ SQLDMO_UDF_TYPE *pRetVal) PURE;
    STDMETHOD(GetIsDeterministic)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetIsSchemaBound)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(EnumOutputs)(THIS_ LPSQLDMOQUERYRESULTS * ppResults) PURE;
    STDMETHOD(GetIsDeleted)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetEncrypted)(THIS_ LPBOOL pRetVal) PURE;
};







////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOTransPublications
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
	STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOTRANSPUBLICATION *ppObj) PURE;
	STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTRANSPUBLICATION *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOTRANSPUBLICATION *ppObj) PURE;
	STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
	STDMETHOD(Add)(THIS_ LPSQLDMOTRANSPUBLICATION Object) PURE;
	STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
	STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
	STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;

	//*** Collection specific methods
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOTransPublication
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetDescription)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDescription)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetEnabled)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetEnabled)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetRetentionPeriod)(THIS_ LPDWORD pRetVal) PURE;
    STDMETHOD(SetRetentionPeriod)(THIS_ DWORD NewValue) PURE;
    STDMETHOD(GetSnapshotMethod)(THIS_ SQLDMO_INITIALSYNC_TYPE *pRetVal) PURE;
    STDMETHOD(SetSnapshotMethod)(THIS_ SQLDMO_INITIALSYNC_TYPE NewValue) PURE;
    STDMETHOD(GetSnapshotAvailable)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetSnapshotAvailable)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetSnapshotSchedule)(THIS_ LPSQLDMOSCHEDULE *ppSchedule) PURE;
    STDMETHOD(GetSnapshotJobID)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetPublicationAttributes)(THIS_ SQLDMO_PUBATTRIB_TYPE *pRetVal) PURE;
    STDMETHOD(SetPublicationAttributes)(THIS_ SQLDMO_PUBATTRIB_TYPE NewValue) PURE;
    STDMETHOD(GetHasSubscription)(THIS_ LPBOOL pRetVal) PURE;

    STDMETHOD(GetAllowSynchronousTransactions)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAllowSynchronousTransactions)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetAutogenerateSyncProcedures)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAutogenerateSyncProcedures)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetReplicationFrequency)(THIS_ SQLDMO_REPFREQ_TYPE *pRetVal) PURE;
    STDMETHOD(SetReplicationFrequency)(THIS_ SQLDMO_REPFREQ_TYPE NewValue) PURE;
    
	//*** Collection properties
    STDMETHOD(GetTransArticles)(THIS_ LPSQLDMOTRANSARTICLES * ppArticles) PURE;
    STDMETHOD(GetTransArticleByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTRANSARTICLE *ppArticle) PURE;
    STDMETHOD(GetTransArticleByOrd)(THIS_ long lOrdinal, LPSQLDMOTRANSARTICLE *ppArticle) PURE;
    STDMETHOD(RemoveTransArticleByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveTransArticleByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddTransArticle)(THIS_ LPSQLDMOTRANSARTICLE pArticle) PURE;
    STDMETHOD(GetTransArticleCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetTransSubscriptions)(THIS_ LPSQLDMOTRANSSUBSCRIPTIONS * ppSubscriptions) PURE;
    STDMETHOD(GetTransSubscriptionByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTRANSSUBSCRIPTION *ppSubscription) PURE;
    STDMETHOD(GetTransSubscriptionByOrd)(THIS_ long lOrdinal, LPSQLDMOTRANSSUBSCRIPTION *ppSubscription) PURE;
    STDMETHOD(RemoveTransSubscriptionByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveTransSubscriptionByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddTransSubscription)(THIS_ LPSQLDMOTRANSSUBSCRIPTION pSubscription) PURE;
    STDMETHOD(GetTransSubscriptionCount)(THIS_ LPLONG plCount) PURE;

	//*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(ActivateSubscriptions)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(EnumSubscriptions)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
	STDMETHOD(RefreshChildren)(THIS) PURE;
    STDMETHOD(ReInitializeAllSubscriptions)(THIS) PURE;
    STDMETHOD(EnumPublicationAccesses)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, BOOL bReturnGranted CPPDEFAULT(= TRUE)) PURE;
    STDMETHOD(GrantPublicationAccess)(THIS_ SQLDMO_LPCSTR szLoginName) PURE;
    STDMETHOD(RevokePublicationAccess)(THIS_ SQLDMO_LPCSTR szLoginName) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOTransPublication2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOTransPublication)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetDescription)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDescription)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetEnabled)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetEnabled)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetRetentionPeriod)(THIS_ LPDWORD pRetVal) PURE;
    STDMETHOD(SetRetentionPeriod)(THIS_ DWORD NewValue) PURE;
    STDMETHOD(GetSnapshotMethod)(THIS_ SQLDMO_INITIALSYNC_TYPE *pRetVal) PURE;
    STDMETHOD(SetSnapshotMethod)(THIS_ SQLDMO_INITIALSYNC_TYPE NewValue) PURE;
    STDMETHOD(GetSnapshotAvailable)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetSnapshotAvailable)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetSnapshotSchedule)(THIS_ LPSQLDMOSCHEDULE *ppSchedule) PURE;
    STDMETHOD(GetSnapshotJobID)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetPublicationAttributes)(THIS_ SQLDMO_PUBATTRIB_TYPE *pRetVal) PURE;
    STDMETHOD(SetPublicationAttributes)(THIS_ SQLDMO_PUBATTRIB_TYPE NewValue) PURE;
    STDMETHOD(GetHasSubscription)(THIS_ LPBOOL pRetVal) PURE;

    STDMETHOD(GetAllowSynchronousTransactions)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAllowSynchronousTransactions)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetAutogenerateSyncProcedures)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAutogenerateSyncProcedures)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetReplicationFrequency)(THIS_ SQLDMO_REPFREQ_TYPE *pRetVal) PURE;
    STDMETHOD(SetReplicationFrequency)(THIS_ SQLDMO_REPFREQ_TYPE NewValue) PURE;
    
	//*** Collection properties
    STDMETHOD(GetTransArticles)(THIS_ LPSQLDMOTRANSARTICLES * ppArticles) PURE;
    STDMETHOD(GetTransArticleByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTRANSARTICLE *ppArticle) PURE;
    STDMETHOD(GetTransArticleByOrd)(THIS_ long lOrdinal, LPSQLDMOTRANSARTICLE *ppArticle) PURE;
    STDMETHOD(RemoveTransArticleByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveTransArticleByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddTransArticle)(THIS_ LPSQLDMOTRANSARTICLE pArticle) PURE;
    STDMETHOD(GetTransArticleCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetTransSubscriptions)(THIS_ LPSQLDMOTRANSSUBSCRIPTIONS * ppSubscriptions) PURE;
    STDMETHOD(GetTransSubscriptionByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTRANSSUBSCRIPTION *ppSubscription) PURE;
    STDMETHOD(GetTransSubscriptionByOrd)(THIS_ long lOrdinal, LPSQLDMOTRANSSUBSCRIPTION *ppSubscription) PURE;
    STDMETHOD(RemoveTransSubscriptionByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveTransSubscriptionByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddTransSubscription)(THIS_ LPSQLDMOTRANSSUBSCRIPTION pSubscription) PURE;
    STDMETHOD(GetTransSubscriptionCount)(THIS_ LPLONG plCount) PURE;

	//*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(ActivateSubscriptions)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(EnumSubscriptions)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
	STDMETHOD(RefreshChildren)(THIS) PURE;
    STDMETHOD(ReInitializeAllSubscriptions)(THIS) PURE;
    STDMETHOD(EnumPublicationAccesses)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, BOOL bReturnGranted CPPDEFAULT(= TRUE)) PURE;
    STDMETHOD(GrantPublicationAccess)(THIS_ SQLDMO_LPCSTR szLoginName) PURE;
    STDMETHOD(RevokePublicationAccess)(THIS_ SQLDMO_LPCSTR szLoginName) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    // Properties
    STDMETHOD(GetAllowQueuedTransactions)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAllowQueuedTransactions)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetAltSnapshotFolder)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetAltSnapshotFolder)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPreSnapshotScript)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPreSnapshotScript)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPostSnapshotScript)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPostSnapshotScript)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetFTPAddress)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetFTPAddress)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetFTPPort)(THIS_ LPDWORD pRetVal) PURE;
    STDMETHOD(SetFTPPort)(THIS_ DWORD NewValue) PURE;
    STDMETHOD(GetFTPSubdirectory)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetFTPSubdirectory)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetFTPLogin)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetFTPLogin)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(SetFTPPassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetAllowDTS)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAllowDTS)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCentralizedConflicts)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCentralizedConflicts)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetConflictRetention)(THIS_ LPDWORD pRetVal) PURE;
    STDMETHOD(SetConflictRetention)(THIS_ DWORD NewValue) PURE;
    STDMETHOD(GetConflictPolicy)(THIS_ SQLDMO_CONFLICTPOLICY_TYPE *pRetVal) PURE;
    STDMETHOD(SetConflictPolicy)(THIS_ SQLDMO_CONFLICTPOLICY_TYPE NewValue) PURE;
    STDMETHOD(GetQueueType)(THIS_ SQLDMO_REPLQUEUE_TYPE *pRetVal) PURE;
    STDMETHOD(SetQueueType)(THIS_ SQLDMO_REPLQUEUE_TYPE NewValue) PURE;
    STDMETHOD(GetCompatibilityLevel)(THIS_ SQLDMO_REPLCOMPLEVEL_TYPE *pRetVal) PURE;
    STDMETHOD(GetInActiveDirectory)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetInActiveDirectory)(THIS_ BOOL NewValue) PURE;

    // Methods
    STDMETHOD(BrowseSnapshotFolder)(THIS_ SQLDMO_LPBSTR pszSnapshotFolder,
                                        SQLDMO_LPCSTR szSubscriberName CPPDEFAULT(= NULL),
                                        SQLDMO_LPCSTR szSubscriberDB   CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(ValidatePublication)(THIS_ SQLDMO_VALIDATIONOPTION_TYPE ValidationOption CPPDEFAULT(= SQLDMOValidationOption_RowCountOnly),
                                        SQLDMO_VALIDATIONMETHOD_TYPE ValidationMethod CPPDEFAULT(= SQLDMOValidationMethod_ConditionalFast),
                                        BOOL fShutDownAgent CPPDEFAULT(= FALSE)) PURE;
    STDMETHOD(ValidateSubscriptions)(THIS_ SQLDMO_LPCSTR szSuscriberNames,
                                        SQLDMO_LPCSTR szSubscriberDBs,
                                        SQLDMO_VALIDATIONOPTION_TYPE ValidationOption CPPDEFAULT(= SQLDMOValidationOption_RowCountOnly),
                                        SQLDMO_VALIDATIONMETHOD_TYPE ValidationMethod CPPDEFAULT(= SQLDMOValidationMethod_ConditionalFast),
                                        BOOL fShutDownAgent CPPDEFAULT(= FALSE)) PURE;
    STDMETHOD(ReplicateUserDefinedScript)(THIS_ SQLDMO_LPCSTR szScriptFilePath) PURE;
    STDMETHOD(CopySnapshot)(THIS_ SQLDMO_LPCSTR pszDestinationFolder,
                                        SQLDMO_LPCSTR szSubscriberName CPPDEFAULT(= NULL),
                                        SQLDMO_LPCSTR szSubscriberDB   CPPDEFAULT(= NULL)) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOTransArticles
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
	STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOTRANSARTICLE *ppObj) PURE;
	STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTRANSARTICLE *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOTRANSARTICLE *ppObj) PURE;
	STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
	STDMETHOD(Add)(THIS_ LPSQLDMOTRANSARTICLE Object) PURE;
	STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
	STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
	STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOTransArticle
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetSourceObjectOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSourceObjectOwner)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSourceObjectName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSourceObjectName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDescription)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDescription)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetReplicateAllColumns)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetSnapshotObjectOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSnapshotObjectOwner)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSnapshotObjectName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSnapshotObjectName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetArticleType)(THIS_ SQLDMO_ARTICLE_TYPE *pRetVal) PURE;
    STDMETHOD(SetArticleType)(THIS_ SQLDMO_ARTICLE_TYPE NewValue) PURE;
    STDMETHOD(GetInsertCommand)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetInsertCommand)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetUpdateCommand)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetUpdateCommand)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDeleteCommand)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDeleteCommand)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetReplicationFilterProcOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetReplicationFilterProcOwner)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetReplicationFilterProcName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetReplicationFilterProcName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetCreationScriptPath)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetCreationScriptPath)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDestinationOwnerName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDestinationOwnerName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDestinationObjectName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDestinationObjectName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPreCreationMethod)(THIS_ SQLDMO_PREARTICLE_TYPE *pRetVal) PURE;
    STDMETHOD(SetPreCreationMethod)(THIS_ SQLDMO_PREARTICLE_TYPE NewValue) PURE;
    STDMETHOD(GetFilterClause)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetFilterClause)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetCreationScriptOptions)(THIS_ SQLDMO_CREATIONSCRIPT_TYPE FAR * pRetVal) PURE;
    STDMETHOD(SetCreationScriptOptions)(THIS_ SQLDMO_CREATIONSCRIPT_TYPE NewValue) PURE;
    STDMETHOD(GetCommandOptions)(THIS_ SQLDMO_COMMANDOPTION_TYPE FAR * pRetVal) PURE;
    STDMETHOD(SetCommandOptions)(THIS_ SQLDMO_COMMANDOPTION_TYPE NewValue) PURE;

	//*** Collection Properties
    STDMETHOD(GetTransSubscriptions)(THIS_ LPSQLDMOTRANSSUBSCRIPTIONS * ppSubscriptions) PURE;
    STDMETHOD(GetTransSubscriptionByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTRANSSUBSCRIPTION *ppSubscription) PURE;
    STDMETHOD(GetTransSubscriptionByOrd)(THIS_ long lOrdinal, LPSQLDMOTRANSSUBSCRIPTION *ppSubscription) PURE;
    STDMETHOD(RemoveTransSubscriptionByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveTransSubscriptionByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddTransSubscription)(THIS_ LPSQLDMOTRANSSUBSCRIPTION pSubscription) PURE;
    STDMETHOD(GetTransSubscriptionCount)(THIS_ LPLONG plCount) PURE;

	//*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(ListReplicatedColumns)(THIS_ LPSQLDMOCOLUMNLIST *ppList) PURE;
    STDMETHOD(AddReplicatedColumns)(THIS_ SQLDMO_LPCSTR Columns) PURE;
    STDMETHOD(RemoveReplicatedColumns)(THIS_ SQLDMO_LPCSTR Columns) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(ScriptDestinationObject)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOTransArticle2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOTransArticle)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetSourceObjectOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSourceObjectOwner)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSourceObjectName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSourceObjectName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDescription)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDescription)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetReplicateAllColumns)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetSnapshotObjectOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSnapshotObjectOwner)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSnapshotObjectName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSnapshotObjectName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetArticleType)(THIS_ SQLDMO_ARTICLE_TYPE *pRetVal) PURE;
    STDMETHOD(SetArticleType)(THIS_ SQLDMO_ARTICLE_TYPE NewValue) PURE;
    STDMETHOD(GetInsertCommand)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetInsertCommand)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetUpdateCommand)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetUpdateCommand)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDeleteCommand)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDeleteCommand)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetReplicationFilterProcOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetReplicationFilterProcOwner)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetReplicationFilterProcName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetReplicationFilterProcName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetCreationScriptPath)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetCreationScriptPath)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDestinationOwnerName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDestinationOwnerName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDestinationObjectName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDestinationObjectName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPreCreationMethod)(THIS_ SQLDMO_PREARTICLE_TYPE *pRetVal) PURE;
    STDMETHOD(SetPreCreationMethod)(THIS_ SQLDMO_PREARTICLE_TYPE NewValue) PURE;
    STDMETHOD(GetFilterClause)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetFilterClause)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetCreationScriptOptions)(THIS_ SQLDMO_CREATIONSCRIPT_TYPE FAR * pRetVal) PURE;
    STDMETHOD(SetCreationScriptOptions)(THIS_ SQLDMO_CREATIONSCRIPT_TYPE NewValue) PURE;
    STDMETHOD(GetCommandOptions)(THIS_ SQLDMO_COMMANDOPTION_TYPE FAR * pRetVal) PURE;
    STDMETHOD(SetCommandOptions)(THIS_ SQLDMO_COMMANDOPTION_TYPE NewValue) PURE;

	//*** Collection Properties
    STDMETHOD(GetTransSubscriptions)(THIS_ LPSQLDMOTRANSSUBSCRIPTIONS * ppSubscriptions) PURE;
    STDMETHOD(GetTransSubscriptionByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTRANSSUBSCRIPTION *ppSubscription) PURE;
    STDMETHOD(GetTransSubscriptionByOrd)(THIS_ long lOrdinal, LPSQLDMOTRANSSUBSCRIPTION *ppSubscription) PURE;
    STDMETHOD(RemoveTransSubscriptionByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveTransSubscriptionByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddTransSubscription)(THIS_ LPSQLDMOTRANSSUBSCRIPTION pSubscription) PURE;
    STDMETHOD(GetTransSubscriptionCount)(THIS_ LPLONG plCount) PURE;

	//*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(ListReplicatedColumns)(THIS_ LPSQLDMOCOLUMNLIST *ppList) PURE;
    STDMETHOD(AddReplicatedColumns)(THIS_ SQLDMO_LPCSTR Columns) PURE;
    STDMETHOD(RemoveReplicatedColumns)(THIS_ SQLDMO_LPCSTR Columns) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(ScriptDestinationObject)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(GetAutoIdentityRange)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAutoIdentityRange)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetPublisherIdentityRangeSize)(THIS_ LONG64 *pRetVal) PURE;
    STDMETHOD(SetPublisherIdentityRangeSize)(THIS_ LONG64 NewValue) PURE;
    STDMETHOD(GetSubscriberIdentityRangeSize)(THIS_ LONG64 *pRetVal) PURE;
    STDMETHOD(SetSubscriberIdentityRangeSize)(THIS_ LONG64 NewValue) PURE;
    STDMETHOD(GetIdentityRangeThreshold)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetIdentityRangeThreshold)(THIS_ LONG NewValue) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOTransSubscriptions
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
	STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOTRANSSUBSCRIPTION *ppObj) PURE;
	STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTRANSSUBSCRIPTION *ppObj) PURE;
	STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
	STDMETHOD(Add)(THIS_ LPSQLDMOTRANSSUBSCRIPTION Object) PURE;
	STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
	STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
	STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;

	//*** Collection specific methods
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOTransSubscription
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetSubscriber)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSubscriber)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSubscriptionDB)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSubscriptionDB)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSyncType)(THIS_ SQLDMO_SUBSYNC_TYPE *pRetVal) PURE;
    STDMETHOD(SetSyncType)(THIS_ SQLDMO_SUBSYNC_TYPE NewValue) PURE;
    STDMETHOD(GetStatus)(THIS_ SQLDMO_SUBSTATUS_TYPE *pRetVal) PURE;
    STDMETHOD(SetStatus)(THIS_ SQLDMO_SUBSTATUS_TYPE NewValue) PURE;
    STDMETHOD(GetFullSubscription)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetDistributionSchedule)(THIS_ LPSQLDMOSCHEDULE *ppDistributionSchedule) PURE;
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetSubscriptionType)(THIS_ SQLDMO_SUBSCRIPTION_TYPE *pRetVal) PURE;
    STDMETHOD(GetSubscriberType)(THIS_ SQLDMO_TRANSUBSCRIBER_TYPE *pRetVal) PURE;
    STDMETHOD(SetSubscriberType)(THIS_ SQLDMO_TRANSUBSCRIBER_TYPE NewValue) PURE;
    STDMETHOD(GetDistributionJobID)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetEnabledForSyncMgr)(THIS_ BOOL NewValue) PURE;

	//*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(ReInitialize)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOTransSubscription2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOTransSubscription)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetSubscriber)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSubscriber)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSubscriptionDB)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSubscriptionDB)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSyncType)(THIS_ SQLDMO_SUBSYNC_TYPE *pRetVal) PURE;
    STDMETHOD(SetSyncType)(THIS_ SQLDMO_SUBSYNC_TYPE NewValue) PURE;
    STDMETHOD(GetStatus)(THIS_ SQLDMO_SUBSTATUS_TYPE *pRetVal) PURE;
    STDMETHOD(SetStatus)(THIS_ SQLDMO_SUBSTATUS_TYPE NewValue) PURE;
    STDMETHOD(GetFullSubscription)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetDistributionSchedule)(THIS_ LPSQLDMOSCHEDULE *ppDistributionSchedule) PURE;
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetSubscriptionType)(THIS_ SQLDMO_SUBSCRIPTION_TYPE *pRetVal) PURE;
    STDMETHOD(GetSubscriberType)(THIS_ SQLDMO_TRANSUBSCRIBER_TYPE *pRetVal) PURE;
    STDMETHOD(SetSubscriberType)(THIS_ SQLDMO_TRANSUBSCRIBER_TYPE NewValue) PURE;
    STDMETHOD(GetDistributionJobID)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetEnabledForSyncMgr)(THIS_ BOOL NewValue) PURE;

	//*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(ReInitialize)(THIS) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(GetAgentOffload)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAgentOffload)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetAgentOffloadServer)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetAgentOffloadServer)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDTSPackageName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDTSPackageName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(SetDTSPackagePassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDTSPackageLocation)(THIS_ SQLDMO_REPLDTSLOC_TYPE *pRetVal) PURE;
    STDMETHOD(SetDTSPackageLocation)(THIS_ SQLDMO_REPLDTSLOC_TYPE NewValue) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOTransPullSubscriptions
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
	STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOTRANSPULLSUBSCRIPTION *ppObj) PURE;
	STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTRANSPULLSUBSCRIPTION *ppObj) PURE;
	STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
	STDMETHOD(Add)(THIS_ LPSQLDMOTRANSPULLSUBSCRIPTION Object) PURE;
	STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
	STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
	STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;

	//*** Collection specific methods
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOTransPullSubscription
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetPublisher)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPublisher)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPublicationDB)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPublicationDB)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPublication)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPublication)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDescription)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDescription)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSubscriptionType)(THIS_ SQLDMO_SUBSCRIPTION_TYPE *pRetVal) PURE;
    STDMETHOD(SetSubscriptionType)(THIS_ SQLDMO_SUBSCRIPTION_TYPE NewValue) PURE;
    STDMETHOD(GetSubscriberType)(THIS_ SQLDMO_TRANSUBSCRIBER_TYPE *pRetVal) PURE;
    STDMETHOD(SetSubscriberType)(THIS_ SQLDMO_TRANSUBSCRIBER_TYPE NewValue) PURE;
    STDMETHOD(GetDistributor)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDistributor)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPublisherSecurity)(THIS_ LPSQLDMOREPLICATIONSECURITY *ppPublisherSecurity) PURE;
    STDMETHOD(GetDistributorSecurity)(THIS_ LPSQLDMOREPLICATIONSECURITY *ppDistributorSecurity) PURE;
    STDMETHOD(SetSubscriberSecurityMode)(THIS_ SQLDMO_SECURITY_TYPE NewValue) PURE;
    STDMETHOD(SetSubscriberLogin)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(SetSubscriberPassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetEnabledForSyncMgr)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetEnabledForSyncMgr)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetFTPAddress)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetFTPAddress)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetFTPPort)(THIS_ LPDWORD pRetVal) PURE;
    STDMETHOD(SetFTPPort)(THIS_ DWORD NewValue) PURE;
    STDMETHOD(GetFTPLogin)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetFTPLogin)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(SetFTPPassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

    STDMETHOD(GetDistributionSchedule)(THIS_ LPSQLDMOSCHEDULE *ppDistributionSchedule) PURE;
    STDMETHOD(GetDistributionJobID)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetLastDistributionDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetPublicationAttributes)(THIS_ SQLDMO_PUBATTRIB_TYPE *pRetVal) PURE;
    STDMETHOD(SetPublicationAttributes)(THIS_ SQLDMO_PUBATTRIB_TYPE NewValue) PURE;

	//*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(EnumJobInfo)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(ReInitialize)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOTransPullSubscription2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOTransPullSubscription)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetPublisher)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPublisher)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPublicationDB)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPublicationDB)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPublication)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPublication)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDescription)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDescription)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSubscriptionType)(THIS_ SQLDMO_SUBSCRIPTION_TYPE *pRetVal) PURE;
    STDMETHOD(SetSubscriptionType)(THIS_ SQLDMO_SUBSCRIPTION_TYPE NewValue) PURE;
    STDMETHOD(GetSubscriberType)(THIS_ SQLDMO_TRANSUBSCRIBER_TYPE *pRetVal) PURE;
    STDMETHOD(SetSubscriberType)(THIS_ SQLDMO_TRANSUBSCRIBER_TYPE NewValue) PURE;
    STDMETHOD(GetDistributor)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDistributor)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPublisherSecurity)(THIS_ LPSQLDMOREPLICATIONSECURITY *ppPublisherSecurity) PURE;
    STDMETHOD(GetDistributorSecurity)(THIS_ LPSQLDMOREPLICATIONSECURITY *ppDistributorSecurity) PURE;
    STDMETHOD(SetSubscriberSecurityMode)(THIS_ SQLDMO_SECURITY_TYPE NewValue) PURE;
    STDMETHOD(SetSubscriberLogin)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(SetSubscriberPassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetEnabledForSyncMgr)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetEnabledForSyncMgr)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetFTPAddress)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetFTPAddress)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetFTPPort)(THIS_ LPDWORD pRetVal) PURE;
    STDMETHOD(SetFTPPort)(THIS_ DWORD NewValue) PURE;
    STDMETHOD(GetFTPLogin)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetFTPLogin)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(SetFTPPassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

    STDMETHOD(GetDistributionSchedule)(THIS_ LPSQLDMOSCHEDULE *ppDistributionSchedule) PURE;
    STDMETHOD(GetDistributionJobID)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetLastDistributionDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetPublicationAttributes)(THIS_ SQLDMO_PUBATTRIB_TYPE *pRetVal) PURE;
    STDMETHOD(SetPublicationAttributes)(THIS_ SQLDMO_PUBATTRIB_TYPE NewValue) PURE;

	//*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(EnumJobInfo)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(ReInitialize)(THIS) PURE;
#endif // NO_BASEINTERFACE_FUNCS
    
    // 8.0
    STDMETHOD(GetAltSnapshotFolder)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetAltSnapshotFolder)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetWorkingDirectory)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetWorkingDirectory)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetUseFTP)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetUseFTP)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetPublicationType)(THIS_ SQLDMO_PUBLICATION_TYPE *pRetVal) PURE;
    STDMETHOD(SetPublicationType)(THIS_ SQLDMO_PUBLICATION_TYPE NewValue) PURE;
    STDMETHOD(GetDTSPackageName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDTSPackageName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(SetDTSPackagePassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDTSPackageLocation)(THIS_ SQLDMO_REPLDTSLOC_TYPE *pRetVal) PURE;
    STDMETHOD(SetDTSPackageLocation)(THIS_ SQLDMO_REPLDTSLOC_TYPE NewValue) PURE;
    STDMETHOD(GetAgentOffload)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAgentOffload)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetAgentOffloadServer)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetAgentOffloadServer)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSubscriptionID)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetLastDistributionStatus)(THIS_ SQLDMO_TASKSTATUS_TYPE *pRetVal) PURE;
    STDMETHOD(GetLastDistributionSummary)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetLastDistributionSummaryTime)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOMergePublications
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
	STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOMERGEPUBLICATION *ppObj) PURE;
	STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOMERGEPUBLICATION *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOMERGEPUBLICATION *ppObj) PURE;
	STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
	STDMETHOD(Add)(THIS_ LPSQLDMOMERGEPUBLICATION Object) PURE;
	STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
	STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
	STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;

    //*** Collection specific methods
	STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOMergePublication
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetID)(THIS_ long FAR* pRetVal) PURE;
    STDMETHOD(GetDescription)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDescription)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetEnabled)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetEnabled)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetRetentionPeriod)(THIS_ LPDWORD pRetVal) PURE;
    STDMETHOD(SetRetentionPeriod)(THIS_ DWORD NewValue) PURE;
    STDMETHOD(GetSnapshotMethod)(THIS_ SQLDMO_INITIALSYNC_TYPE *pRetVal) PURE;
    STDMETHOD(SetSnapshotMethod)(THIS_ SQLDMO_INITIALSYNC_TYPE NewValue) PURE;
    STDMETHOD(GetSnapshotAvailable)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetSnapshotAvailable)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetSnapshotSchedule)(THIS_ LPSQLDMOSCHEDULE *ppSchedule) PURE;
    STDMETHOD(GetSnapshotJobID)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetPublicationAttributes)(THIS_ SQLDMO_PUBATTRIB_TYPE *pRetVal) PURE;
    STDMETHOD(SetPublicationAttributes)(THIS_ SQLDMO_PUBATTRIB_TYPE NewValue) PURE;
    STDMETHOD(GetHasSubscription)(THIS_ LPBOOL pRetVal) PURE;

    STDMETHOD(GetCentralizedConflicts)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCentralizedConflicts)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetPriority)(THIS_ float *pRetVal) PURE;
    STDMETHOD(GetDynamicFilters)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetDynamicFilters)(THIS_ BOOL NewValue) PURE;

	//*** Collection properties
    STDMETHOD(GetMergeArticles)(THIS_ LPSQLDMOMERGEARTICLES * ppMergeArticles) PURE;
    STDMETHOD(GetMergeArticleByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOMERGEARTICLE *ppMergeArticle) PURE;
    STDMETHOD(GetMergeArticleByOrd)(THIS_ long lOrdinal, LPSQLDMOMERGEARTICLE *ppMergeArticle) PURE;
    STDMETHOD(RemoveMergeArticleByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveMergeArticleByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddMergeArticle)(THIS_ LPSQLDMOMERGEARTICLE pMergeArticle) PURE;
    STDMETHOD(GetMergeArticleCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetMergeSubscriptions)(THIS_ LPSQLDMOMERGESUBSCRIPTIONS * ppMergeSubscriptions) PURE;
    STDMETHOD(GetMergeSubscriptionByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOMERGESUBSCRIPTION *ppMergeSubscription) PURE;
    STDMETHOD(GetMergeSubscriptionByOrd)(THIS_ long lOrdinal, LPSQLDMOMERGESUBSCRIPTION *ppMergeSubscription) PURE;
    STDMETHOD(RemoveMergeSubscriptionByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveMergeSubscriptionByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddMergeSubscription)(THIS_ LPSQLDMOMERGESUBSCRIPTION pMergeSubscription) PURE;
    STDMETHOD(GetMergeSubscriptionCount)(THIS_ LPLONG plCount) PURE;


	//*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(EnumSubscriptions)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
	STDMETHOD(RefreshChildren)(THIS) PURE;
    STDMETHOD(EnumPublicationReferences)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(ReInitializeAllSubscriptions)(THIS) PURE;
    STDMETHOD(EnumPublicationAccesses)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, BOOL bReturnGranted CPPDEFAULT(= TRUE)) PURE;
    STDMETHOD(GrantPublicationAccess)(THIS_ SQLDMO_LPCSTR szLoginName) PURE;
    STDMETHOD(RevokePublicationAccess)(THIS_ SQLDMO_LPCSTR szLoginName) PURE;
    STDMETHOD(GenerateFilters)(THIS) PURE;
    STDMETHOD(EnumGeneratedSubsetFilters)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPCSTR szArticle, SQLDMO_LPCSTR szSubsetFilterClause) PURE;
    STDMETHOD(EnumAllSubsetFilters)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOMergePublication2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOMergePublication)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetID)(THIS_ long FAR* pRetVal) PURE;
    STDMETHOD(GetDescription)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDescription)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetEnabled)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetEnabled)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetRetentionPeriod)(THIS_ LPDWORD pRetVal) PURE;
    STDMETHOD(SetRetentionPeriod)(THIS_ DWORD NewValue) PURE;
    STDMETHOD(GetSnapshotMethod)(THIS_ SQLDMO_INITIALSYNC_TYPE *pRetVal) PURE;
    STDMETHOD(SetSnapshotMethod)(THIS_ SQLDMO_INITIALSYNC_TYPE NewValue) PURE;
    STDMETHOD(GetSnapshotAvailable)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetSnapshotAvailable)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetSnapshotSchedule)(THIS_ LPSQLDMOSCHEDULE *ppSchedule) PURE;
    STDMETHOD(GetSnapshotJobID)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetPublicationAttributes)(THIS_ SQLDMO_PUBATTRIB_TYPE *pRetVal) PURE;
    STDMETHOD(SetPublicationAttributes)(THIS_ SQLDMO_PUBATTRIB_TYPE NewValue) PURE;
    STDMETHOD(GetHasSubscription)(THIS_ LPBOOL pRetVal) PURE;

    STDMETHOD(GetCentralizedConflicts)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetCentralizedConflicts)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetPriority)(THIS_ float *pRetVal) PURE;
    STDMETHOD(GetDynamicFilters)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetDynamicFilters)(THIS_ BOOL NewValue) PURE;

	//*** Collection properties
    STDMETHOD(GetMergeArticles)(THIS_ LPSQLDMOMERGEARTICLES * ppMergeArticles) PURE;
    STDMETHOD(GetMergeArticleByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOMERGEARTICLE *ppMergeArticle) PURE;
    STDMETHOD(GetMergeArticleByOrd)(THIS_ long lOrdinal, LPSQLDMOMERGEARTICLE *ppMergeArticle) PURE;
    STDMETHOD(RemoveMergeArticleByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveMergeArticleByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddMergeArticle)(THIS_ LPSQLDMOMERGEARTICLE pMergeArticle) PURE;
    STDMETHOD(GetMergeArticleCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetMergeSubscriptions)(THIS_ LPSQLDMOMERGESUBSCRIPTIONS * ppMergeSubscriptions) PURE;
    STDMETHOD(GetMergeSubscriptionByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOMERGESUBSCRIPTION *ppMergeSubscription) PURE;
    STDMETHOD(GetMergeSubscriptionByOrd)(THIS_ long lOrdinal, LPSQLDMOMERGESUBSCRIPTION *ppMergeSubscription) PURE;
    STDMETHOD(RemoveMergeSubscriptionByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveMergeSubscriptionByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddMergeSubscription)(THIS_ LPSQLDMOMERGESUBSCRIPTION pMergeSubscription) PURE;
    STDMETHOD(GetMergeSubscriptionCount)(THIS_ LPLONG plCount) PURE;
    

	//*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(EnumSubscriptions)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
	STDMETHOD(RefreshChildren)(THIS) PURE;
    STDMETHOD(EnumPublicationReferences)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(ReInitializeAllSubscriptions)(THIS) PURE;
    STDMETHOD(EnumPublicationAccesses)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, BOOL bReturnGranted CPPDEFAULT(= TRUE)) PURE;
    STDMETHOD(GrantPublicationAccess)(THIS_ SQLDMO_LPCSTR szLoginName) PURE;
    STDMETHOD(RevokePublicationAccess)(THIS_ SQLDMO_LPCSTR szLoginName) PURE;
    STDMETHOD(GenerateFilters)(THIS) PURE;
    STDMETHOD(EnumGeneratedSubsetFilters)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPCSTR szArticle, SQLDMO_LPCSTR szSubsetFilterClause) PURE;
    STDMETHOD(EnumAllSubsetFilters)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    // Properties
    STDMETHOD(GetAltSnapshotFolder)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetAltSnapshotFolder)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPreSnapshotScript)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPreSnapshotScript)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPostSnapshotScript)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPostSnapshotScript)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetFTPAddress)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetFTPAddress)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetFTPPort)(THIS_ LPDWORD pRetVal) PURE;
    STDMETHOD(SetFTPPort)(THIS_ DWORD NewValue) PURE;
    STDMETHOD(GetFTPSubdirectory)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetFTPSubdirectory)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetFTPLogin)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetFTPLogin)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(SetFTPPassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetConflictRetention)(THIS_ LPDWORD pRetVal) PURE;
    STDMETHOD(SetConflictRetention)(THIS_ DWORD NewValue) PURE;
    STDMETHOD(GetKeepPartitionChanges)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetKeepPartitionChanges)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetAllowSyncToAlternate)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAllowSyncToAlternate)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCompatibilityLevel)(THIS_ SQLDMO_REPLCOMPLEVEL_TYPE *pRetVal) PURE;
    STDMETHOD(GetValidateSubscriberInfo)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetValidateSubscriberInfo)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetInActiveDirectory)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetInActiveDirectory)(THIS_ BOOL NewValue) PURE;

    STDMETHOD(GetMergeDynamicSnapshotJobs)(THIS_ LPSQLDMOMERGEDYNAMICSNAPSHOTJOBS *ppMergeDynamicSnapshotJobs) PURE;
    STDMETHOD(GetMergeDynamicSnapshotJobByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOMERGEDYNAMICSNAPSHOTJOB *ppMergeDynamicSnapshotJob) PURE;
    STDMETHOD(GetMergeDynamicSnapshotJobByOrd)(THIS_ long lOrdinal, LPSQLDMOMERGEDYNAMICSNAPSHOTJOB *ppMergeDynamicSnapshotJob) PURE;
    STDMETHOD(RemoveMergeDynamicSnapshotJobByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveMergeDynamicSnapshotJobByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddMergeDynamicSnapshotJob)(THIS_ LPSQLDMOMERGEDYNAMICSNAPSHOTJOB pMergeDynamicSnapshotJob) PURE;
    STDMETHOD(GetMergeDynamicSnapshotJobCount)(THIS_ LPLONG plCount) PURE;
    STDMETHOD(GetMaxConcurrentMerge)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetMaxConcurrentMerge)(THIS_ LONG NewValue) PURE;
    STDMETHOD(GetMaxConcurrentDynamicSnapshots)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetMaxConcurrentDynamicSnapshots)(THIS_ LONG NewValue) PURE;
    
    // Methods
    STDMETHOD(BrowseSnapshotFolder)(THIS_ SQLDMO_LPBSTR pszSnapshotFolder) PURE;
    STDMETHOD(AddAlternatePublisher)(THIS_ SQLDMO_LPCSTR pszAlternatePublisher, SQLDMO_LPCSTR pszAlternatePublicationDB, SQLDMO_LPCSTR pszAlternatePublication, SQLDMO_LPCSTR pszAlternateDistributor CPPDEFAULT(= NULL), SQLDMO_LPCSTR pszFriendlyName CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RemoveAlternatePublisher)(THIS_ SQLDMO_LPCSTR pszAlternatePublisher, SQLDMO_LPCSTR pszAlternatePublicationDB, SQLDMO_LPCSTR pszAlternatePublication) PURE;
    STDMETHOD(EnumAlternatePublishers)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(ReInitializeAllSubscriptions2)(THIS_ BOOL bUploadFirst CPPDEFAULT(= FALSE)) PURE;
    STDMETHOD(ValidatePublication)(THIS_ SQLDMO_VALIDATIONOPTION_TYPE ValidationOption CPPDEFAULT(= SQLDMOValidationOption_RowCountOnly)) PURE;
    STDMETHOD(ValidateSubscription)(THIS_ SQLDMO_LPCSTR pszSuscriberName,SQLDMO_LPCSTR pszSubscriberDB, SQLDMO_VALIDATIONOPTION_TYPE ValidationOption CPPDEFAULT(= SQLDMOValidationOption_RowCountOnly)) PURE;
    STDMETHOD(ReSynchronizeSubscription)(THIS_ SQLDMO_LPCSTR pszSuscriberName, SQLDMO_LPCSTR pszSubscriberDB, SQLDMO_RESYNC_TYPE ResyncType, SQLDMO_LPCSTR pszDateTime CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(ReadLastValidationDateTimes)(THIS_ SQLDMO_LPCSTR pszSuscriberName, SQLDMO_LPCSTR pszSubscriberDB, SQLDMO_LPBSTR pszSuccessfulDateTime, SQLDMO_LPBSTR pszAttemptedDateTime CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(ReplicateUserDefinedScript)(THIS_ SQLDMO_LPCSTR szScriptFilePath) PURE;
    STDMETHOD(CopySnapshot)(THIS_ SQLDMO_LPCSTR pszDestinationFolder) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOMergeArticles
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
	STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOMERGEARTICLE *ppObj) PURE;
	STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOMERGEARTICLE *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOMERGEARTICLE *ppObj) PURE;
	STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
	STDMETHOD(Add)(THIS_ LPSQLDMOMERGEARTICLE Object) PURE;
	STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
	STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
	STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOMergeArticle
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetSourceObjectOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSourceObjectOwner)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSourceObjectName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSourceObjectName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetStatus)(THIS_ SQLDMO_ARTSTATUS_TYPE *pRetVal) PURE;
    STDMETHOD(SetStatus)(THIS_ SQLDMO_ARTSTATUS_TYPE NewValue) PURE;
    STDMETHOD(GetDescription)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDescription)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetConflictTable)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetArticleResolver)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetArticleResolver)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSubsetFilterClause)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSubsetFilterClause)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPreCreationMethod)(THIS_ SQLDMO_PREARTICLE_TYPE FAR* pRetVal) PURE;
    STDMETHOD(SetPreCreationMethod)(THIS_ SQLDMO_PREARTICLE_TYPE NewValue) PURE;
    STDMETHOD(GetCreationScriptOptions)(THIS_ SQLDMO_CREATIONSCRIPT_TYPE FAR * pRetVal) PURE;
    STDMETHOD(SetCreationScriptOptions)(THIS_ SQLDMO_CREATIONSCRIPT_TYPE NewValue) PURE;
    STDMETHOD(GetArticleType)(THIS_ SQLDMO_ARTICLE_TYPE *pRetVal) PURE;
    STDMETHOD(SetArticleType)(THIS_ SQLDMO_ARTICLE_TYPE NewValue) PURE;
    STDMETHOD(GetColumnTracking)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetColumnTracking)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCreationScriptPath)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetCreationScriptPath)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSnapshotObjectOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetSnapshotObjectName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetResolverInfo)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetResolverInfo)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

	//*** Collection Properties
    STDMETHOD(GetMergeSubsetFilters)(THIS_ LPSQLDMOMERGESUBSETFILTERS * ppMergeSubsetFilters) PURE;
    STDMETHOD(GetMergeSubsetFilterByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOMERGESUBSETFILTER *ppMergeSubsetFilter) PURE;
    STDMETHOD(GetMergeSubsetFilterByOrd)(THIS_ long lOrdinal, LPSQLDMOMERGESUBSETFILTER *ppMergeSubsetFilter) PURE;
    STDMETHOD(RemoveMergeSubsetFilterByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveMergeSubsetFilterByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddMergeSubsetFilter)(THIS_ LPSQLDMOMERGESUBSETFILTER pMergeSubsetFilter) PURE;
    STDMETHOD(GetMergeSubsetFilterCount)(THIS_ LPLONG plCount) PURE;

	//*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), 
                        SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), 
                        SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(ScriptDestinationObject)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), 
                                        SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), 
                                        SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOMergeArticle2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOMergeArticle)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetSourceObjectOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSourceObjectOwner)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSourceObjectName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSourceObjectName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetStatus)(THIS_ SQLDMO_ARTSTATUS_TYPE *pRetVal) PURE;
    STDMETHOD(SetStatus)(THIS_ SQLDMO_ARTSTATUS_TYPE NewValue) PURE;
    STDMETHOD(GetDescription)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDescription)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetConflictTable)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetArticleResolver)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetArticleResolver)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSubsetFilterClause)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSubsetFilterClause)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPreCreationMethod)(THIS_ SQLDMO_PREARTICLE_TYPE FAR* pRetVal) PURE;
    STDMETHOD(SetPreCreationMethod)(THIS_ SQLDMO_PREARTICLE_TYPE NewValue) PURE;
    STDMETHOD(GetCreationScriptOptions)(THIS_ SQLDMO_CREATIONSCRIPT_TYPE FAR * pRetVal) PURE;
    STDMETHOD(SetCreationScriptOptions)(THIS_ SQLDMO_CREATIONSCRIPT_TYPE NewValue) PURE;
    STDMETHOD(GetArticleType)(THIS_ SQLDMO_ARTICLE_TYPE *pRetVal) PURE;
    STDMETHOD(SetArticleType)(THIS_ SQLDMO_ARTICLE_TYPE NewValue) PURE;
    STDMETHOD(GetColumnTracking)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetColumnTracking)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCreationScriptPath)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetCreationScriptPath)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSnapshotObjectOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetSnapshotObjectName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetResolverInfo)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetResolverInfo)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

	//*** Collection Properties
    STDMETHOD(GetMergeSubsetFilters)(THIS_ LPSQLDMOMERGESUBSETFILTERS * ppMergeSubsetFilters) PURE;
    STDMETHOD(GetMergeSubsetFilterByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOMERGESUBSETFILTER *ppMergeSubsetFilter) PURE;
    STDMETHOD(GetMergeSubsetFilterByOrd)(THIS_ long lOrdinal, LPSQLDMOMERGESUBSETFILTER *ppMergeSubsetFilter) PURE;
    STDMETHOD(RemoveMergeSubsetFilterByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveMergeSubsetFilterByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddMergeSubsetFilter)(THIS_ LPSQLDMOMERGESUBSETFILTER pMergeSubsetFilter) PURE;
    STDMETHOD(GetMergeSubsetFilterCount)(THIS_ LPLONG plCount) PURE;

	//*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), 
                        SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), 
                        SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(ScriptDestinationObject)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), 
                                        SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), 
                                        SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
#endif // NO_BASEINTERFACE_FUNCS
    
	// 8.0
    STDMETHOD(GetDestinationOwnerName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDestinationOwnerName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetAutoIdentityRange)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAutoIdentityRange)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetPublisherIdentityRangeSize)(THIS_ LONG64 *pRetVal) PURE;
    STDMETHOD(SetPublisherIdentityRangeSize)(THIS_ LONG64 NewValue) PURE;
    STDMETHOD(GetSubscriberIdentityRangeSize)(THIS_ LONG64 *pRetVal) PURE;
    STDMETHOD(SetSubscriberIdentityRangeSize)(THIS_ LONG64 NewValue) PURE;
    STDMETHOD(GetIdentityRangeThreshold)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetIdentityRangeThreshold)(THIS_ LONG NewValue) PURE;
    STDMETHOD(GetVerifyResolverSignature)(THIS_ SQLDMO_VERIFYSIGNATURE_TYPE FAR* pRetVal) PURE;
    STDMETHOD(SetVerifyResolverSignature)(THIS_ SQLDMO_VERIFYSIGNATURE_TYPE NewValue) PURE;
    STDMETHOD(GetDestinationObjectName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDestinationObjectName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetAllowInteractiveResolver)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAllowInteractiveResolver)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetMultipleColumnUpdate)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetMultipleColumnUpdate)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCheckPermissions)(THIS_ SQLDMO_CHECKPERMISSIONS_TYPE FAR* pRetVal) PURE;
    STDMETHOD(SetCheckPermissions)(THIS_ SQLDMO_CHECKPERMISSIONS_TYPE NewValue) PURE;

    STDMETHOD(ListReplicatedColumns)(THIS_ LPSQLDMOCOLUMNLIST *ppList) PURE;
    STDMETHOD(AddReplicatedColumns)(THIS_ SQLDMO_LPCSTR Columns) PURE;
    STDMETHOD(RemoveReplicatedColumns)(THIS_ SQLDMO_LPCSTR Columns) PURE;
    STDMETHOD(ScriptDestinationObject2)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), 
                                        SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), 
                                        SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default), 
                                        SQLDMO_LPCSTR pszDestinationObject CPPDEFAULT(= NULL)) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOMergeSubscriptions
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
	STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOMERGESUBSCRIPTION *ppObj) PURE;
	STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOMERGESUBSCRIPTION *ppObj) PURE;
	STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
	STDMETHOD(Add)(THIS_ LPSQLDMOMERGESUBSCRIPTION Object) PURE;
	STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
	STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
	STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;

	//*** Collection specific methods
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOMergeSubscription
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetSubscriber)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSubscriber)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSubscriptionDB)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSubscriptionDB)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetStatus)(THIS_ SQLDMO_SUBSTATUS_TYPE *pRetVal) PURE;
    STDMETHOD(SetStatus)(THIS_ SQLDMO_SUBSTATUS_TYPE NewValue) PURE;
    STDMETHOD(GetSubscriberType)(THIS_ SQLDMO_MERGESUBSCRIBER_TYPE *pRetVal) PURE;
    STDMETHOD(SetSubscriberType)(THIS_ SQLDMO_MERGESUBSCRIBER_TYPE NewValue) PURE;
    STDMETHOD(GetPriority)(THIS_ float *pRetVal) PURE;
    STDMETHOD(SetPriority)(THIS_ float NewValue) PURE;
    STDMETHOD(GetMergeSchedule)(THIS_ LPSQLDMOSCHEDULE *ppSchedule) PURE;
    STDMETHOD(GetSyncType)(THIS_ SQLDMO_SUBSYNC_TYPE *pRetVal) PURE;
    STDMETHOD(SetSyncType)(THIS_ SQLDMO_SUBSYNC_TYPE NewValue) PURE;
    STDMETHOD(GetSubscriptionType)(THIS_ SQLDMO_SUBSCRIPTION_TYPE *pRetVal) PURE;
    STDMETHOD(GetMergeJobID)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetDescription)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDescription)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(SetEnabledForSyncMgr)(THIS_ BOOL NewValue) PURE;

	//*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;

    STDMETHOD(ReInitialize)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOMergeSubscription2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOMergeSubscription)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetSubscriber)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSubscriber)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSubscriptionDB)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSubscriptionDB)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetStatus)(THIS_ SQLDMO_SUBSTATUS_TYPE *pRetVal) PURE;
    STDMETHOD(SetStatus)(THIS_ SQLDMO_SUBSTATUS_TYPE NewValue) PURE;
    STDMETHOD(GetSubscriberType)(THIS_ SQLDMO_MERGESUBSCRIBER_TYPE *pRetVal) PURE;
    STDMETHOD(SetSubscriberType)(THIS_ SQLDMO_MERGESUBSCRIBER_TYPE NewValue) PURE;
    STDMETHOD(GetPriority)(THIS_ float *pRetVal) PURE;
    STDMETHOD(SetPriority)(THIS_ float NewValue) PURE;
    STDMETHOD(GetMergeSchedule)(THIS_ LPSQLDMOSCHEDULE *ppSchedule) PURE;
    STDMETHOD(GetSyncType)(THIS_ SQLDMO_SUBSYNC_TYPE *pRetVal) PURE;
    STDMETHOD(SetSyncType)(THIS_ SQLDMO_SUBSYNC_TYPE NewValue) PURE;
    STDMETHOD(GetSubscriptionType)(THIS_ SQLDMO_SUBSCRIPTION_TYPE *pRetVal) PURE;
    STDMETHOD(GetMergeJobID)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetDescription)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDescription)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(SetEnabledForSyncMgr)(THIS_ BOOL NewValue) PURE;

	//*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;

    STDMETHOD(ReInitialize)(THIS) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(GetAgentOffload)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAgentOffload)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetAgentOffloadServer)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetAgentOffloadServer)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetUseInteractiveResolver)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetUseInteractiveResolver)(THIS_ BOOL NewValue) PURE;

    STDMETHOD(ReInitialize2)(THIS_ BOOL bUploadFirst CPPDEFAULT(= FALSE)) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOMergePullSubscriptions
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
	STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOMERGEPULLSUBSCRIPTION *ppObj) PURE;
	STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOMERGEPULLSUBSCRIPTION *ppObj) PURE;
	STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
	STDMETHOD(Add)(THIS_ LPSQLDMOMERGEPULLSUBSCRIPTION Object) PURE;
	STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
	STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
	STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;

	//*** Collection specific methods
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOMergePullSubscription
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetPublisher)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPublisher)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPublicationDB)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPublicationDB)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPublication)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPublication)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDescription)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDescription)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSubscriptionType)(THIS_ SQLDMO_SUBSCRIPTION_TYPE *pRetVal) PURE;
    STDMETHOD(SetSubscriptionType)(THIS_ SQLDMO_SUBSCRIPTION_TYPE NewValue) PURE;
    STDMETHOD(GetSubscriberType)(THIS_ SQLDMO_MERGESUBSCRIBER_TYPE *pRetVal) PURE;
    STDMETHOD(SetSubscriberType)(THIS_ SQLDMO_MERGESUBSCRIBER_TYPE NewValue) PURE;
    STDMETHOD(GetDistributor)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDistributor)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPublisherSecurity)(THIS_ LPSQLDMOREPLICATIONSECURITY *ppPublisherSecurity) PURE;
    STDMETHOD(GetDistributorSecurity)(THIS_ LPSQLDMOREPLICATIONSECURITY *ppDistributorSecurity) PURE;
    STDMETHOD(SetSubscriberSecurityMode)(THIS_ SQLDMO_SECURITY_TYPE NewValue) PURE;
    STDMETHOD(SetSubscriberLogin)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(SetSubscriberPassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetEnabledForSyncMgr)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetEnabledForSyncMgr)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetFTPAddress)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetFTPAddress)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetFTPPort)(THIS_ LPDWORD pRetVal) PURE;
    STDMETHOD(SetFTPPort)(THIS_ DWORD NewValue) PURE;
    STDMETHOD(GetFTPLogin)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetFTPLogin)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(SetFTPPassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

    STDMETHOD(GetMergeSchedule)(THIS_ LPSQLDMOSCHEDULE *ppMergeSchedule) PURE;
    STDMETHOD(GetMergeJobID)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetSyncType)(THIS_ SQLDMO_SUBSYNC_TYPE *pRetVal) PURE;
    STDMETHOD(SetSyncType)(THIS_ SQLDMO_SUBSYNC_TYPE NewValue) PURE;
    STDMETHOD(GetPriority)(THIS_ float *pRetVal) PURE;
    STDMETHOD(SetPriority)(THIS_ float NewValue) PURE;

	//*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(EnumJobInfo)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(ReInitialize)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOMergePullSubscription2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOMergePullSubscription)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetPublisher)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPublisher)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPublicationDB)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPublicationDB)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPublication)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPublication)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDescription)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDescription)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSubscriptionType)(THIS_ SQLDMO_SUBSCRIPTION_TYPE *pRetVal) PURE;
    STDMETHOD(SetSubscriptionType)(THIS_ SQLDMO_SUBSCRIPTION_TYPE NewValue) PURE;
    STDMETHOD(GetSubscriberType)(THIS_ SQLDMO_MERGESUBSCRIBER_TYPE *pRetVal) PURE;
    STDMETHOD(SetSubscriberType)(THIS_ SQLDMO_MERGESUBSCRIBER_TYPE NewValue) PURE;
    STDMETHOD(GetDistributor)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDistributor)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPublisherSecurity)(THIS_ LPSQLDMOREPLICATIONSECURITY *ppPublisherSecurity) PURE;
    STDMETHOD(GetDistributorSecurity)(THIS_ LPSQLDMOREPLICATIONSECURITY *ppDistributorSecurity) PURE;
    STDMETHOD(SetSubscriberSecurityMode)(THIS_ SQLDMO_SECURITY_TYPE NewValue) PURE;
    STDMETHOD(SetSubscriberLogin)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(SetSubscriberPassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetEnabledForSyncMgr)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetEnabledForSyncMgr)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetFTPAddress)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetFTPAddress)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetFTPPort)(THIS_ LPDWORD pRetVal) PURE;
    STDMETHOD(SetFTPPort)(THIS_ DWORD NewValue) PURE;
    STDMETHOD(GetFTPLogin)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetFTPLogin)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(SetFTPPassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

    STDMETHOD(GetMergeSchedule)(THIS_ LPSQLDMOSCHEDULE *ppMergeSchedule) PURE;
    STDMETHOD(GetMergeJobID)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetSyncType)(THIS_ SQLDMO_SUBSYNC_TYPE *pRetVal) PURE;
    STDMETHOD(SetSyncType)(THIS_ SQLDMO_SUBSYNC_TYPE NewValue) PURE;
    STDMETHOD(GetPriority)(THIS_ float *pRetVal) PURE;
    STDMETHOD(SetPriority)(THIS_ float NewValue) PURE;

	//*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(EnumJobInfo)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(ReInitialize)(THIS) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(GetLastMergedTime)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetAltSnapshotFolder)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetAltSnapshotFolder)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetWorkingDirectory)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetWorkingDirectory)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetUseFTP)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetUseFTP)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetAgentOffload)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAgentOffload)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetAgentOffloadServer)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetAgentOffloadServer)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetUseInteractiveResolver)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetUseInteractiveResolver)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetSubscriptionID)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetDynamicSnapshotLocation)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDynamicSnapshotLocation)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetLastMergedStatus)(THIS_ SQLDMO_TASKSTATUS_TYPE *pRetVal) PURE;
    STDMETHOD(GetLastMergedSummary)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;

    STDMETHOD(ReInitialize2)(THIS_ BOOL bUploadFirst CPPDEFAULT(= FALSE)) PURE;
    STDMETHOD(EnumAlternatePublishers)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOMergeSubsetFilters
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
	STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOMERGESUBSETFILTER *ppObj) PURE;
	STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOMERGESUBSETFILTER *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOMERGESUBSETFILTER *ppObj) PURE;
	STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
	STDMETHOD(Add)(THIS_ LPSQLDMOMERGESUBSETFILTER Object) PURE;
	STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
	STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
	STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;

};

#undef INTERFACE
#define INTERFACE ISQLDMOMergeSubsetFilter
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetJoinArticleName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetJoinArticleName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetJoinFilterClause)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetJoinFilterClause)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetJoinUniqueKey)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetJoinUniqueKey)(THIS_ BOOL NewValue) PURE;

	//*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
};


////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMODistributionPublishers
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
	STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMODISTRIBUTIONPUBLISHER *ppObj) PURE;
	STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMODISTRIBUTIONPUBLISHER *ppObj) PURE;
	STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
	STDMETHOD(Add)(THIS_ LPSQLDMODISTRIBUTIONPUBLISHER Object) PURE;
	STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
	STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
	STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;

	//*** Collection specific methods
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMODistributionPublisher
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDistributionDatabase)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDistributionDatabase)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPublisherSecurity)(THIS_ LPSQLDMOREPLICATIONSECURITY *ppPublisherSecurity) PURE;
    STDMETHOD(GetEnabled)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetDistributionWorkingDirectory)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDistributionWorkingDirectory)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetTrustedDistributorConnection)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetTrustedDistributorConnection)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetThirdParty)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetThirdParty)(THIS_ BOOL NewValue) PURE;

	//*** collection properties
    STDMETHOD(GetDistributionPublications)(THIS_ LPSQLDMODISTRIBUTIONPUBLICATIONS * ppDistributionPublications) PURE;
    STDMETHOD(GetDistributionPublicationByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMODISTRIBUTIONPUBLICATION *ppDistributionPublication, SQLDMO_LPCSTR szPubDB CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetDistributionPublicationByOrd)(THIS_ long lOrdinal, LPSQLDMODISTRIBUTIONPUBLICATION *ppDistributionPublication) PURE;
    STDMETHOD(RemoveDistributionPublicationByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveDistributionPublicationByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddDistributionPublication)(THIS_ LPSQLDMODISTRIBUTIONPUBLICATION pDistributionPublication) PURE;
    STDMETHOD(GetDistributionPublicationCount)(THIS_ LPLONG plCount) PURE;

	//*** Collection properties
    STDMETHOD(GetRegisteredSubscribers)(THIS_ LPSQLDMOREGISTEREDSUBSCRIBERS * ppRegisteredSubscribers) PURE;
    STDMETHOD(GetRegisteredSubscriberByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOREGISTEREDSUBSCRIBER *ppRegisteredSubscriber) PURE;
    STDMETHOD(GetRegisteredSubscriberByOrd)(THIS_ long lOrdinal, LPSQLDMOREGISTEREDSUBSCRIBER *ppRegisteredSubscriber) PURE;
    STDMETHOD(RemoveRegisteredSubscriberByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveRegisteredSubscriberByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddRegisteredSubscriber)(THIS_ LPSQLDMOREGISTEREDSUBSCRIBER pRegisteredSubscriber) PURE;
    STDMETHOD(GetRegisteredSubscriberCount)(THIS_ LPLONG plCount) PURE;

    //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Refresh)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;

	/* Monitoring methods */
    STDMETHOD(EnumSnapshotAgentSessions)(THIS_ SQLDMO_LPCSTR AgentName, SQLDMO_SESSION_TYPE SessionType,  long SessionDuration, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumLogReaderAgentSessions)(THIS_ SQLDMO_LPCSTR AgentName, SQLDMO_SESSION_TYPE SessionType,  long SessionDuration, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumDistributionAgentSessions)(THIS_ SQLDMO_LPCSTR AgentName, SQLDMO_SESSION_TYPE SessionType,  long SessionDuration, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumMergeAgentSessions)(THIS_ SQLDMO_LPCSTR AgentName, SQLDMO_SESSION_TYPE SessionType,  long SessionDuration, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumSnapshotAgentSessionDetails)(THIS_ SQLDMO_LPCSTR AgentName, SQLDMO_LPCSTR SessionID, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumLogReaderAgentSessionDetails)(THIS_ SQLDMO_LPCSTR AgentName, SQLDMO_LPCSTR SessionID,  LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumDistributionAgentSessionDetails)(THIS_ SQLDMO_LPCSTR AgentName,  SQLDMO_LPCSTR SessionID, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumMergeAgentSessionDetails)(THIS_ SQLDMO_LPCSTR AgentName,  SQLDMO_LPCSTR SessionID, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumAgentErrorRecords)(THIS_ LONG ErrorID, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(GetAgentsStatus)(THIS_ SQLDMO_TASKSTATUS_TYPE *pRetVal, SQLDMO_LPBSTR pRetValTimeStamp CPPDEFAULT(= NULL)) PURE;    
};

#undef INTERFACE
#define INTERFACE ISQLDMODistributionPublisher2
DECLARE_INTERFACE_(INTERFACE, ISQLDMODistributionPublisher)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDistributionDatabase)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDistributionDatabase)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPublisherSecurity)(THIS_ LPSQLDMOREPLICATIONSECURITY *ppPublisherSecurity) PURE;
    STDMETHOD(GetEnabled)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetDistributionWorkingDirectory)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDistributionWorkingDirectory)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetTrustedDistributorConnection)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetTrustedDistributorConnection)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetThirdParty)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetThirdParty)(THIS_ BOOL NewValue) PURE;

	//*** collection properties
    STDMETHOD(GetDistributionPublications)(THIS_ LPSQLDMODISTRIBUTIONPUBLICATIONS * ppDistributionPublications) PURE;
    STDMETHOD(GetDistributionPublicationByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMODISTRIBUTIONPUBLICATION *ppDistributionPublication, SQLDMO_LPCSTR szPubDB CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetDistributionPublicationByOrd)(THIS_ long lOrdinal, LPSQLDMODISTRIBUTIONPUBLICATION *ppDistributionPublication) PURE;
    STDMETHOD(RemoveDistributionPublicationByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveDistributionPublicationByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddDistributionPublication)(THIS_ LPSQLDMODISTRIBUTIONPUBLICATION pDistributionPublication) PURE;
    STDMETHOD(GetDistributionPublicationCount)(THIS_ LPLONG plCount) PURE;

	//*** Collection properties
    STDMETHOD(GetRegisteredSubscribers)(THIS_ LPSQLDMOREGISTEREDSUBSCRIBERS * ppRegisteredSubscribers) PURE;
    STDMETHOD(GetRegisteredSubscriberByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOREGISTEREDSUBSCRIBER *ppRegisteredSubscriber) PURE;
    STDMETHOD(GetRegisteredSubscriberByOrd)(THIS_ long lOrdinal, LPSQLDMOREGISTEREDSUBSCRIBER *ppRegisteredSubscriber) PURE;
    STDMETHOD(RemoveRegisteredSubscriberByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveRegisteredSubscriberByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddRegisteredSubscriber)(THIS_ LPSQLDMOREGISTEREDSUBSCRIBER pRegisteredSubscriber) PURE;
    STDMETHOD(GetRegisteredSubscriberCount)(THIS_ LPLONG plCount) PURE;

    //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Refresh)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;

	/* Monitoring methods */
    STDMETHOD(EnumSnapshotAgentSessions)(THIS_ SQLDMO_LPCSTR AgentName, SQLDMO_SESSION_TYPE SessionType,  long SessionDuration, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumLogReaderAgentSessions)(THIS_ SQLDMO_LPCSTR AgentName, SQLDMO_SESSION_TYPE SessionType,  long SessionDuration, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumDistributionAgentSessions)(THIS_ SQLDMO_LPCSTR AgentName, SQLDMO_SESSION_TYPE SessionType,  long SessionDuration, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumMergeAgentSessions)(THIS_ SQLDMO_LPCSTR AgentName, SQLDMO_SESSION_TYPE SessionType,  long SessionDuration, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumSnapshotAgentSessionDetails)(THIS_ SQLDMO_LPCSTR AgentName, SQLDMO_LPCSTR SessionID, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumLogReaderAgentSessionDetails)(THIS_ SQLDMO_LPCSTR AgentName, SQLDMO_LPCSTR SessionID,  LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumDistributionAgentSessionDetails)(THIS_ SQLDMO_LPCSTR AgentName,  SQLDMO_LPCSTR SessionID, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumMergeAgentSessionDetails)(THIS_ SQLDMO_LPCSTR AgentName,  SQLDMO_LPCSTR SessionID, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumAgentErrorRecords)(THIS_ LONG ErrorID, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(GetAgentsStatus)(THIS_ SQLDMO_TASKSTATUS_TYPE *pRetVal, SQLDMO_LPBSTR pRetValTimeStamp CPPDEFAULT(= NULL)) PURE;    
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(ReadAgentOffloadInfo)(THIS_ SQLDMO_LPCSTR pszJobID, LPBOOL pbAgentOffload CPPDEFAULT(= NULL), SQLDMO_LPBSTR pszServerNetworkName CPPDEFAULT(= NULL), LPBOOL pbIndependentAgent CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(EnableAgentOffload)(THIS_ SQLDMO_LPCSTR pszJobID, SQLDMO_LPCSTR pszServerNetworkName CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(DisableAgentOffload)(THIS_ SQLDMO_LPCSTR pszJobID) PURE;
    STDMETHOD(GetAgentsStatus2)(THIS_ BOOL fExcludeAnonymous, SQLDMO_TASKSTATUS_TYPE *pRetVal, SQLDMO_LPBSTR pRetValTimeStamp CPPDEFAULT(= NULL)) PURE;    
    STDMETHOD(EnumSnapshotAgentSessions2)(THIS_ SQLDMO_LPCSTR AgentName, SQLDMO_SESSION_TYPE SessionType, long SessionDuration, long lEstimatedNumRecords, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumLogReaderAgentSessions2)(THIS_ SQLDMO_LPCSTR AgentName, SQLDMO_SESSION_TYPE SessionType, long SessionDuration, long lEstimatedNumRecords, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumDistributionAgentSessions2)(THIS_ SQLDMO_LPCSTR AgentName, SQLDMO_SESSION_TYPE SessionType, long SessionDuration, long lEstimatedNumRecords, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumMergeAgentSessions2)(THIS_ SQLDMO_LPCSTR AgentName, SQLDMO_SESSION_TYPE SessionType, long SessionDuration, long lEstimatedNumRecords, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumSnapshotAgentSessionDetails2)(THIS_ SQLDMO_LPCSTR AgentName, SQLDMO_LPCSTR SessionID, long lEstimatedNumRecords, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumLogReaderAgentSessionDetails2)(THIS_ SQLDMO_LPCSTR AgentName, SQLDMO_LPCSTR SessionID, long lEstimatedNumRecords, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumDistributionAgentSessionDetails2)(THIS_ SQLDMO_LPCSTR AgentName, SQLDMO_LPCSTR SessionID, long lEstimatedNumRecords, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumMergeAgentSessionDetails2)(THIS_ SQLDMO_LPCSTR AgentName, SQLDMO_LPCSTR SessionID, long lEstimatedNumRecords, LPSQLDMOQUERYRESULTS *ppResults) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMORegisteredSubscribers
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
	STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOREGISTEREDSUBSCRIBER *ppObj) PURE;
	STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOREGISTEREDSUBSCRIBER *ppObj) PURE;
	STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
	STDMETHOD(Add)(THIS_ LPSQLDMOREGISTEREDSUBSCRIBER Object) PURE;
	STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
	STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
	STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;

	//*** Collection specific methods
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMORegisteredSubscriber
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetType)(THIS_ SQLDMO_SUBSCRIBER_TYPE *pRetVal) PURE;
    STDMETHOD(SetType)(THIS_ SQLDMO_SUBSCRIBER_TYPE NewValue) PURE;
    STDMETHOD(GetDescription)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDescription)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetReplicationSecurity)(THIS_ LPSQLDMOREPLICATIONSECURITY *ppReplicationSecurity) PURE;
    STDMETHOD(GetDefaultDistributionSchedule)(THIS_ LPSQLDMOSCHEDULE *ppDistributionSchedule) PURE;
    STDMETHOD(GetDefaultMergeSchedule)(THIS_ LPSQLDMOSCHEDULE *ppMergeSchedule) PURE;

	//*** methods
    STDMETHOD(Remove)(THIS) PURE;
	STDMETHOD(Refresh)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;

};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOReplicationDatabases
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
	STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOREPLICATIONDATABASE *ppObj) PURE;
	STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOREPLICATIONDATABASE *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOREPLICATIONDATABASE *ppObj) PURE;
	STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods 
	STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;

	//*** Collection specific methods
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOReplicationDatabase
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(GetEnableTransPublishing)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetEnableTransPublishing)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetEnableMergePublishing)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetEnableMergePublishing)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetDBOwner)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetAllowMergePublication)(THIS_ LPBOOL pRetVal) PURE;

	//*** Collection properties
    STDMETHOD(GetReplicationTables)(THIS_ LPSQLDMOREPLICATIONTABLES * ppReplicationTables) PURE;
    STDMETHOD(GetReplicationTableByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOREPLICATIONTABLE *ppReplicationTable, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetReplicationTableByOrd)(THIS_ long lOrdinal, LPSQLDMOREPLICATIONTABLE *ppReplicationTable) PURE;
    STDMETHOD(GetReplicationTableCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetReplicationStoredProcedures)(THIS_ LPSQLDMOREPLICATIONSTOREDPROCEDURES * ppReplicationStoredProcedures) PURE;
    STDMETHOD(GetReplicationStoredProcedureByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOREPLICATIONSTOREDPROCEDURE *ppReplicationStoredProcedure, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetReplicationStoredProcedureByOrd)(THIS_ long lOrdinal, LPSQLDMOREPLICATIONSTOREDPROCEDURE *ppReplicationStoredProcedure) PURE;
    STDMETHOD(GetReplicationStoredProcedureCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetTransPublications)(THIS_ LPSQLDMOTRANSPUBLICATIONS * ppTransPublications) PURE;
    STDMETHOD(GetTransPublicationByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTRANSPUBLICATION *ppTransPublication) PURE;
    STDMETHOD(GetTransPublicationByOrd)(THIS_ long lOrdinal, LPSQLDMOTRANSPUBLICATION *ppTransPublication) PURE;
    STDMETHOD(RemoveTransPublicationByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveTransPublicationByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddTransPublication)(THIS_ LPSQLDMOTRANSPUBLICATION pTransPublication) PURE;
    STDMETHOD(GetTransPublicationCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetMergePublications)(THIS_ LPSQLDMOMERGEPUBLICATIONS * ppMergePublications) PURE;
    STDMETHOD(GetMergePublicationByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOMERGEPUBLICATION *ppMergePublication) PURE;
    STDMETHOD(GetMergePublicationByOrd)(THIS_ long lOrdinal, LPSQLDMOMERGEPUBLICATION *ppMergePublication) PURE;
    STDMETHOD(RemoveMergePublicationByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveMergePublicationByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddMergePublication)(THIS_ LPSQLDMOMERGEPUBLICATION pMergePublication) PURE;
    STDMETHOD(GetMergePublicationCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetTransPullSubscriptions)(THIS_ LPSQLDMOTRANSPULLSUBSCRIPTIONS * ppTransPullSubscriptions) PURE;
    STDMETHOD(GetTransPullSubscriptionByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTRANSPULLSUBSCRIPTION *ppTransPullSubscription) PURE;
    STDMETHOD(GetTransPullSubscriptionByOrd)(THIS_ long lOrdinal, LPSQLDMOTRANSPULLSUBSCRIPTION *ppTransPullSubscription) PURE;
    STDMETHOD(RemoveTransPullSubscriptionByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveTransPullSubscriptionByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddTransPullSubscription)(THIS_ LPSQLDMOTRANSPULLSUBSCRIPTION pTransPullSubscription) PURE;
    STDMETHOD(GetTransPullSubscriptionCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetMergePullSubscriptions)(THIS_ LPSQLDMOMERGEPULLSUBSCRIPTIONS * ppMergePullSubscriptions) PURE;
    STDMETHOD(GetMergePullSubscriptionByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOMERGEPULLSUBSCRIPTION *ppMergePullSubscription) PURE;
    STDMETHOD(GetMergePullSubscriptionByOrd)(THIS_ long lOrdinal, LPSQLDMOMERGEPULLSUBSCRIPTION *ppMergePullSubscription) PURE;
    STDMETHOD(RemoveMergePullSubscriptionByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveMergePullSubscriptionByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddMergePullSubscription)(THIS_ LPSQLDMOMERGEPULLSUBSCRIPTION pMergePullSubscription) PURE;
    STDMETHOD(GetMergePullSubscriptionCount)(THIS_ LPLONG plCount) PURE;

	//*** Methods

	//*** Used to setup the publisher side handshake for PULL subscriptions
	STDMETHOD(EnableTransSubscription)(THIS_ SQLDMO_LPCSTR Subscriber, SQLDMO_LPCSTR SubscriptionDatabase,
		SQLDMO_LPCSTR Publication, SQLDMO_SUBSCRIPTION_TYPE SubscriptionType CPPDEFAULT(= SQLDMOSubscription_Pull), 
		SQLDMO_SUBSYNC_TYPE SyncType CPPDEFAULT(= SQLDMOSubSync_Auto), 
		SQLDMO_TRANSUBSCRIBER_TYPE SubscriberType CPPDEFAULT(= SQLDMOTranSubscriber_ReadOnly)) PURE;
	STDMETHOD(DisableTransSubscription)(THIS_ SQLDMO_LPCSTR Subscriber, SQLDMO_LPCSTR SubscriptionDatabase, SQLDMO_LPCSTR Publication) PURE;
	STDMETHOD(EnableMergeSubscription)(THIS_ SQLDMO_LPCSTR Subscriber, SQLDMO_LPCSTR SubscriptionDatabase,
		SQLDMO_LPCSTR Publication, SQLDMO_SUBSCRIPTION_TYPE SubscriptionType CPPDEFAULT(= SQLDMOSubscription_Pull), 
		SQLDMO_SUBSYNC_TYPE SyncType CPPDEFAULT(= SQLDMOSubSync_Auto), 
		SQLDMO_MERGESUBSCRIBER_TYPE SubscriberType CPPDEFAULT(= SQLDMOMergeSubscriber_Local), 
		float SubscriptionPriority CPPDEFAULT(= 0.0)) PURE;
	STDMETHOD(DisableMergeSubscription)(THIS_ SQLDMO_LPCSTR Subscriber, SQLDMO_LPCSTR SubscriptionDatabase, SQLDMO_LPCSTR Publication) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
	STDMETHOD(RefreshChildren)(THIS) PURE;
	STDMETHOD(EnumConflictTables)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPCSTR Publication CPPDEFAULT(= NULL)) PURE;
	STDMETHOD(EnumInitialAccesses)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOReplicationDatabase2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOReplicationDatabase)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(GetEnableTransPublishing)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetEnableTransPublishing)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetEnableMergePublishing)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetEnableMergePublishing)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetDBOwner)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetAllowMergePublication)(THIS_ LPBOOL pRetVal) PURE;

	//*** Collection properties
    STDMETHOD(GetReplicationTables)(THIS_ LPSQLDMOREPLICATIONTABLES * ppReplicationTables) PURE;
    STDMETHOD(GetReplicationTableByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOREPLICATIONTABLE *ppReplicationTable, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetReplicationTableByOrd)(THIS_ long lOrdinal, LPSQLDMOREPLICATIONTABLE *ppReplicationTable) PURE;
    STDMETHOD(GetReplicationTableCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetReplicationStoredProcedures)(THIS_ LPSQLDMOREPLICATIONSTOREDPROCEDURES * ppReplicationStoredProcedures) PURE;
    STDMETHOD(GetReplicationStoredProcedureByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOREPLICATIONSTOREDPROCEDURE *ppReplicationStoredProcedure, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(GetReplicationStoredProcedureByOrd)(THIS_ long lOrdinal, LPSQLDMOREPLICATIONSTOREDPROCEDURE *ppReplicationStoredProcedure) PURE;
    STDMETHOD(GetReplicationStoredProcedureCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetTransPublications)(THIS_ LPSQLDMOTRANSPUBLICATIONS * ppTransPublications) PURE;
    STDMETHOD(GetTransPublicationByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTRANSPUBLICATION *ppTransPublication) PURE;
    STDMETHOD(GetTransPublicationByOrd)(THIS_ long lOrdinal, LPSQLDMOTRANSPUBLICATION *ppTransPublication) PURE;
    STDMETHOD(RemoveTransPublicationByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveTransPublicationByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddTransPublication)(THIS_ LPSQLDMOTRANSPUBLICATION pTransPublication) PURE;
    STDMETHOD(GetTransPublicationCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetMergePublications)(THIS_ LPSQLDMOMERGEPUBLICATIONS * ppMergePublications) PURE;
    STDMETHOD(GetMergePublicationByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOMERGEPUBLICATION *ppMergePublication) PURE;
    STDMETHOD(GetMergePublicationByOrd)(THIS_ long lOrdinal, LPSQLDMOMERGEPUBLICATION *ppMergePublication) PURE;
    STDMETHOD(RemoveMergePublicationByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveMergePublicationByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddMergePublication)(THIS_ LPSQLDMOMERGEPUBLICATION pMergePublication) PURE;
    STDMETHOD(GetMergePublicationCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetTransPullSubscriptions)(THIS_ LPSQLDMOTRANSPULLSUBSCRIPTIONS * ppTransPullSubscriptions) PURE;
    STDMETHOD(GetTransPullSubscriptionByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTRANSPULLSUBSCRIPTION *ppTransPullSubscription) PURE;
    STDMETHOD(GetTransPullSubscriptionByOrd)(THIS_ long lOrdinal, LPSQLDMOTRANSPULLSUBSCRIPTION *ppTransPullSubscription) PURE;
    STDMETHOD(RemoveTransPullSubscriptionByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveTransPullSubscriptionByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddTransPullSubscription)(THIS_ LPSQLDMOTRANSPULLSUBSCRIPTION pTransPullSubscription) PURE;
    STDMETHOD(GetTransPullSubscriptionCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetMergePullSubscriptions)(THIS_ LPSQLDMOMERGEPULLSUBSCRIPTIONS * ppMergePullSubscriptions) PURE;
    STDMETHOD(GetMergePullSubscriptionByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOMERGEPULLSUBSCRIPTION *ppMergePullSubscription) PURE;
    STDMETHOD(GetMergePullSubscriptionByOrd)(THIS_ long lOrdinal, LPSQLDMOMERGEPULLSUBSCRIPTION *ppMergePullSubscription) PURE;
    STDMETHOD(RemoveMergePullSubscriptionByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveMergePullSubscriptionByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddMergePullSubscription)(THIS_ LPSQLDMOMERGEPULLSUBSCRIPTION pMergePullSubscription) PURE;
    STDMETHOD(GetMergePullSubscriptionCount)(THIS_ LPLONG plCount) PURE;

	//*** Methods

	//*** Used to setup the publisher side handshake for PULL subscriptions
	STDMETHOD(EnableTransSubscription)(THIS_ SQLDMO_LPCSTR Subscriber, SQLDMO_LPCSTR SubscriptionDatabase,
		SQLDMO_LPCSTR Publication, SQLDMO_SUBSCRIPTION_TYPE SubscriptionType CPPDEFAULT(= SQLDMOSubscription_Pull), 
		SQLDMO_SUBSYNC_TYPE SyncType CPPDEFAULT(= SQLDMOSubSync_Auto), 
		SQLDMO_TRANSUBSCRIBER_TYPE SubscriberType CPPDEFAULT(= SQLDMOTranSubscriber_ReadOnly)) PURE;
	STDMETHOD(DisableTransSubscription)(THIS_ SQLDMO_LPCSTR Subscriber, SQLDMO_LPCSTR SubscriptionDatabase, SQLDMO_LPCSTR Publication) PURE;
	STDMETHOD(EnableMergeSubscription)(THIS_ SQLDMO_LPCSTR Subscriber, SQLDMO_LPCSTR SubscriptionDatabase,
		SQLDMO_LPCSTR Publication, SQLDMO_SUBSCRIPTION_TYPE SubscriptionType CPPDEFAULT(= SQLDMOSubscription_Pull), 
		SQLDMO_SUBSYNC_TYPE SyncType CPPDEFAULT(= SQLDMOSubSync_Auto), 
		SQLDMO_MERGESUBSCRIBER_TYPE SubscriberType CPPDEFAULT(= SQLDMOMergeSubscriber_Local), 
		float SubscriptionPriority CPPDEFAULT(= 0.0)) PURE;
	STDMETHOD(DisableMergeSubscription)(THIS_ SQLDMO_LPCSTR Subscriber, SQLDMO_LPCSTR SubscriptionDatabase, SQLDMO_LPCSTR Publication) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
	STDMETHOD(RefreshChildren)(THIS) PURE;
	STDMETHOD(EnumConflictTables)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPCSTR Publication CPPDEFAULT(= NULL)) PURE;
	STDMETHOD(EnumInitialAccesses)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
#endif // NO_BASEINTERFACE_FUNCS

	// 8.0
    STDMETHOD(GetDBReadOnly)(THIS_ LPBOOL pRetVal) PURE;
	STDMETHOD(CopySubscriptionDatabase)(THIS_ SQLDMO_LPCSTR pszFilename, BOOL fOverWriteExistingFile CPPDEFAULT(= FALSE)) PURE;
	STDMETHOD(ReadReplicationFailOverMode)(THIS_ SQLDMO_LPCSTR pszPublisher, SQLDMO_LPCSTR pszPublicationDB, SQLDMO_LPCSTR pszPublication, SQLDMO_REPLFAILOVER_TYPE *pFailOverMode) PURE;
	STDMETHOD(WriteReplicationFailOverMode)(THIS_ SQLDMO_LPCSTR pszPublisher, SQLDMO_LPCSTR pszPublicationDB, SQLDMO_LPCSTR pszPublication, SQLDMO_REPLFAILOVER_TYPE FailOverMode) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMODistributionDatabases
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
	STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMODISTRIBUTIONDATABASE *ppObj) PURE;
	STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMODISTRIBUTIONDATABASE *ppObj) PURE;
	STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
	STDMETHOD(Add)(THIS_ LPSQLDMODISTRIBUTIONDATABASE Object) PURE;
	STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
	STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
	STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;

	//*** Collection specific methods
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMODistributionDatabase
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetMinDistributionRetention)(THIS_ LPDWORD pRetVal) PURE;
    STDMETHOD(SetMinDistributionRetention)(THIS_ DWORD NewValue) PURE;
    STDMETHOD(GetMaxDistributionRetention)(THIS_ LPDWORD pRetVal) PURE;
    STDMETHOD(SetMaxDistributionRetention)(THIS_ DWORD NewValue) PURE;
    STDMETHOD(GetHistoryRetention)(THIS_ LPDWORD pRetVal) PURE;
    STDMETHOD(SetHistoryRetention)(THIS_ DWORD NewValue) PURE;
    STDMETHOD(GetHistoryCleanupTaskName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetDistributionCleanupTaskName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetAgentsStatus)(THIS_ SQLDMO_TASKSTATUS_TYPE *pRetVal) PURE;
    STDMETHOD(GetDataFolder)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDataFolder)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDataFile)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDataFile)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDataFileSize)(THIS_ LPDWORD pRetVal) PURE;
    STDMETHOD(SetDataFileSize)(THIS_ DWORD NewValue) PURE;
    STDMETHOD(GetLogFolder)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetLogFolder)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetLogFile)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetLogFile)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetLogFileSize)(THIS_ LPDWORD pRetVal) PURE;
    STDMETHOD(SetLogFileSize)(THIS_ DWORD NewValue) PURE;
    STDMETHOD(SetSecurityMode)(THIS_ SQLDMO_SECURITY_TYPE NewValue) PURE;
    STDMETHOD(SetStandardLogin)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(SetStandardPassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

	//*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Refresh)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMODistributionDatabase2
DECLARE_INTERFACE_(INTERFACE, ISQLDMODistributionDatabase)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetMinDistributionRetention)(THIS_ LPDWORD pRetVal) PURE;
    STDMETHOD(SetMinDistributionRetention)(THIS_ DWORD NewValue) PURE;
    STDMETHOD(GetMaxDistributionRetention)(THIS_ LPDWORD pRetVal) PURE;
    STDMETHOD(SetMaxDistributionRetention)(THIS_ DWORD NewValue) PURE;
    STDMETHOD(GetHistoryRetention)(THIS_ LPDWORD pRetVal) PURE;
    STDMETHOD(SetHistoryRetention)(THIS_ DWORD NewValue) PURE;
    STDMETHOD(GetHistoryCleanupTaskName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetDistributionCleanupTaskName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetAgentsStatus)(THIS_ SQLDMO_TASKSTATUS_TYPE *pRetVal) PURE;
    STDMETHOD(GetDataFolder)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDataFolder)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDataFile)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDataFile)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDataFileSize)(THIS_ LPDWORD pRetVal) PURE;
    STDMETHOD(SetDataFileSize)(THIS_ DWORD NewValue) PURE;
    STDMETHOD(GetLogFolder)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetLogFolder)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetLogFile)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetLogFile)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetLogFileSize)(THIS_ LPDWORD pRetVal) PURE;
    STDMETHOD(SetLogFileSize)(THIS_ DWORD NewValue) PURE;
    STDMETHOD(SetSecurityMode)(THIS_ SQLDMO_SECURITY_TYPE NewValue) PURE;
    STDMETHOD(SetStandardLogin)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(SetStandardPassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

	//*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(Refresh)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(EnumQueueReaderAgentSessions)(THIS_ long lPublicationID, SQLDMO_SESSION_TYPE SessionType, long SessionDuration, long lEstimatedNumRecords, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumQueueReaderAgentSessionDetails)(THIS_ long lPublicationID, SQLDMO_LPCSTR SessionID, long lEstimatedNumRecords, LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumAgentErrorRecords)(THIS_ LONG ErrorID, LPSQLDMOQUERYRESULTS *ppResults) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOReplication
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetPublisher)(THIS_ LPSQLDMOPUBLISHER *pPublisher) PURE;
    STDMETHOD(GetSubscriber)(THIS_ LPSQLDMOSUBSCRIBER *pSubscriber) PURE;
    STDMETHOD(GetDistributor)(THIS_ LPSQLDMODISTRIBUTOR *pDistributor) PURE;

	//*** Collection properties
    STDMETHOD(GetReplicationDatabases)(THIS_ LPSQLDMOREPLICATIONDATABASES * ppReplicationDatabases) PURE;
    STDMETHOD(GetReplicationDatabaseByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOREPLICATIONDATABASE *ppReplicationDatabase) PURE;
    STDMETHOD(GetReplicationDatabaseByOrd)(THIS_ long lOrdinal, LPSQLDMOREPLICATIONDATABASE *ppReplicationDatabase) PURE;
    STDMETHOD(GetReplicationDatabaseCount)(THIS_ LPLONG plCount) PURE;

   	//*** methods
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
	STDMETHOD(EnumDataSourceNames)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(Uninstall)(THIS_ BOOL bIgnoreDistributor CPPDEFAULT(= FALSE)) PURE;
	STDMETHOD(EnumCustomResolvers)(THIS_ SQLDMO_LPCSTR Distributor, LPSQLDMOQUERYRESULTS *ppResults) PURE;
	STDMETHOD(ValidateDataSource)(THIS_ SQLDMO_LPCSTR DataSourceName, SQLDMO_LPCSTR Login, SQLDMO_LPCSTR Password, SQLDMO_SUBSCRIBER_TYPE SubscriberType CPPDEFAULT(= SQLDMOSubInfo_ODBCDatasource)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOReplication2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOReplication)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetPublisher)(THIS_ LPSQLDMOPUBLISHER *pPublisher) PURE;
    STDMETHOD(GetSubscriber)(THIS_ LPSQLDMOSUBSCRIBER *pSubscriber) PURE;
    STDMETHOD(GetDistributor)(THIS_ LPSQLDMODISTRIBUTOR *pDistributor) PURE;

	//*** Collection properties
    STDMETHOD(GetReplicationDatabases)(THIS_ LPSQLDMOREPLICATIONDATABASES * ppReplicationDatabases) PURE;
    STDMETHOD(GetReplicationDatabaseByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOREPLICATIONDATABASE *ppReplicationDatabase) PURE;
    STDMETHOD(GetReplicationDatabaseByOrd)(THIS_ long lOrdinal, LPSQLDMOREPLICATIONDATABASE *ppReplicationDatabase) PURE;
    STDMETHOD(GetReplicationDatabaseCount)(THIS_ LPLONG plCount) PURE;

   	//*** methods
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
	STDMETHOD(EnumDataSourceNames)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(Uninstall)(THIS_ BOOL bIgnoreDistributor CPPDEFAULT(= FALSE)) PURE;
	STDMETHOD(EnumCustomResolvers)(THIS_ SQLDMO_LPCSTR Distributor, LPSQLDMOQUERYRESULTS *ppResults) PURE;
	STDMETHOD(ValidateDataSource)(THIS_ SQLDMO_LPCSTR DataSourceName, SQLDMO_LPCSTR Login, SQLDMO_LPCSTR Password, SQLDMO_SUBSCRIBER_TYPE SubscriberType CPPDEFAULT(= SQLDMOSubInfo_ODBCDatasource)) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
	STDMETHOD(AttachSubscriptionDatabase)(THIS_ SQLDMO_LPCSTR pszDatabaseName, SQLDMO_LPCSTR pszFileName, SQLDMO_SECURITY_TYPE SubscriberSecurityType, SQLDMO_LPCSTR pszSubscriberLogin, SQLDMO_LPCSTR pszSubscriberPassword) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOPublisher
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** Collection properties
    STDMETHOD(GetRegisteredSubscribers)(THIS_ LPSQLDMOREGISTEREDSUBSCRIBERS * ppRegisteredSubscribers) PURE;
    STDMETHOD(GetRegisteredSubscriberByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOREGISTEREDSUBSCRIBER *ppRegisteredSubscriber) PURE;
    STDMETHOD(GetRegisteredSubscriberByOrd)(THIS_ long lOrdinal, LPSQLDMOREGISTEREDSUBSCRIBER *ppRegisteredSubscriber) PURE;
    STDMETHOD(RemoveRegisteredSubscriberByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveRegisteredSubscriberByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddRegisteredSubscriber)(THIS_ LPSQLDMOREGISTEREDSUBSCRIBER pRegisteredSubscriber) PURE;
    STDMETHOD(GetRegisteredSubscriberCount)(THIS_ LPLONG plCount) PURE;

   	//*** methods
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(Uninstall)(THIS) PURE;
    STDMETHOD(EnumPublications)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_REPLICATION_TYPE ReplicationType CPPDEFAULT(= SQLDMORepType_TransactionalMerge), SQLDMO_LPCSTR DatabaseName CPPDEFAULT(= NULL), SQLDMO_LPCSTR AgentLogin CPPDEFAULT(= NULL), BOOL bSecurityCheck CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOPublisher2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOPublisher)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** Collection properties
    STDMETHOD(GetRegisteredSubscribers)(THIS_ LPSQLDMOREGISTEREDSUBSCRIBERS * ppRegisteredSubscribers) PURE;
    STDMETHOD(GetRegisteredSubscriberByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOREGISTEREDSUBSCRIBER *ppRegisteredSubscriber) PURE;
    STDMETHOD(GetRegisteredSubscriberByOrd)(THIS_ long lOrdinal, LPSQLDMOREGISTEREDSUBSCRIBER *ppRegisteredSubscriber) PURE;
    STDMETHOD(RemoveRegisteredSubscriberByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveRegisteredSubscriberByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddRegisteredSubscriber)(THIS_ LPSQLDMOREGISTEREDSUBSCRIBER pRegisteredSubscriber) PURE;
    STDMETHOD(GetRegisteredSubscriberCount)(THIS_ LPLONG plCount) PURE;

   	//*** methods
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(Uninstall)(THIS) PURE;
    STDMETHOD(EnumPublications)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_REPLICATION_TYPE ReplicationType CPPDEFAULT(= SQLDMORepType_TransactionalMerge), SQLDMO_LPCSTR DatabaseName CPPDEFAULT(= NULL), SQLDMO_LPCSTR AgentLogin CPPDEFAULT(= NULL), BOOL bSecurityCheck CPPDEFAULT(= FALSE)) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
	STDMETHOD(CleanUpAnonymousAgentInfo)(THIS_ SQLDMO_LPCSTR pszSubscriptionID, SQLDMO_REPLICATION_TYPE ReplicationType) PURE;
    STDMETHOD(EnumPublications2)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_REPLICATION_TYPE ReplicationType CPPDEFAULT(= SQLDMORepType_TransactionalMerge), SQLDMO_LPCSTR DatabaseName CPPDEFAULT(= NULL), SQLDMO_LPCSTR PublicationName CPPDEFAULT(= NULL), SQLDMO_LPCSTR AgentLogin CPPDEFAULT(= NULL), BOOL bSecurityCheck CPPDEFAULT(= FALSE)) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOSubscriber
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** methods
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOSubscriber2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOSubscriber)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** methods
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
	STDMETHOD(EnumAllSubscriptions)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_SUBSCRIPTION_TYPE SubscriptionType CPPDEFAULT(= SQLDMOSubscription_Push), SQLDMO_LPCSTR pszSubscriptionDB CPPDEFAULT(= NULL)) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMODistributor
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
	STDMETHOD(GetDistributorInstalled)(THIS_ LPBOOL pbDistributorInstalled) PURE;
	STDMETHOD(GetDistributorAvailable)(THIS_ LPBOOL pbDistributorAvailable) PURE;
	STDMETHOD(GetDistributorLocal)(THIS_ LPBOOL pbDistributorLocal) PURE;
    STDMETHOD(GetDistributionServer)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDistributionServer)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDistributionDatabase)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetAgentCheckupInterval)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetAgentCheckupInterval)(THIS_ long lVal) PURE;
	STDMETHOD(GetIsDistributionPublisher)(THIS_ LPBOOL pIsDistributionPublisher) PURE;
	STDMETHOD(GetHasRemoteDistributionPublisher)(THIS_ LPBOOL pHasRemoteDistributionPublisher) PURE;

	//*** Collection properties
    STDMETHOD(GetDistributionPublishers)(THIS_ LPSQLDMODISTRIBUTIONPUBLISHERS * ppDistributionPublishers) PURE;
    STDMETHOD(GetDistributionPublisherByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMODISTRIBUTIONPUBLISHER *ppDistributionPublisher) PURE;
    STDMETHOD(GetDistributionPublisherByOrd)(THIS_ long lOrdinal, LPSQLDMODISTRIBUTIONPUBLISHER *ppDistributionPublisher) PURE;
    STDMETHOD(RemoveDistributionPublisherByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveDistributionPublisherByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddDistributionPublisher)(THIS_ LPSQLDMODISTRIBUTIONPUBLISHER pDistributionPublisher) PURE;
    STDMETHOD(GetDistributionPublisherCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetDistributionDatabases)(THIS_ LPSQLDMODISTRIBUTIONDATABASES * ppDistributionDatabases) PURE;
    STDMETHOD(GetDistributionDatabaseByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMODISTRIBUTIONDATABASE *ppDistributionDatabase) PURE;
    STDMETHOD(GetDistributionDatabaseByOrd)(THIS_ long lOrdinal, LPSQLDMODISTRIBUTIONDATABASE *ppDistributionDatabase) PURE;
    STDMETHOD(RemoveDistributionDatabaseByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveDistributionDatabaseByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddDistributionDatabase)(THIS_ LPSQLDMODISTRIBUTIONDATABASE pDistributionDatabase) PURE;
    STDMETHOD(GetDistributionDatabaseCount)(THIS_ LPLONG plCount) PURE;

   	//*** methods
    STDMETHOD(Refresh)(THIS) PURE;
    STDMETHOD(Install)(THIS) PURE;
    STDMETHOD(Uninstall)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_InstallDistributor), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;

    STDMETHOD(EnumSnapshotAgentViews)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumLogReaderAgentViews)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumDistributionAgentViews)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumMergeAgentViews)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumMiscellaneousAgentViews)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(CreateAgentProfile)(THIS_ SQLDMO_LPCSTR szName, SQLDMO_LPCSTR szDescription, SQLDMO_REPLAGENT_TYPE AgentType, long *plProfileID) PURE;
    STDMETHOD(DeleteAgentProfile)(THIS_ long lProfileID) PURE;
    STDMETHOD(ChangeAgentProfile)(THIS_ long lProfileID, SQLDMO_LPCSTR szDescription) PURE;
    STDMETHOD(EnumAgentProfiles)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_REPLAGENT_TYPE AgentType CPPDEFAULT(= SQLDMOReplAgent_All)) PURE;
    STDMETHOD(ChangeAgentParameter)(THIS_ long lProfileID, SQLDMO_LPCSTR szParameterName, SQLDMO_LPCSTR szParameterValue) PURE;
    STDMETHOD(EnumAgentParameters)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, long lProfileID) PURE;
    STDMETHOD(UpdateAgentProfile)(THIS_ SQLDMO_LPCSTR DistributionDBName, SQLDMO_REPLAGENT_TYPE AgentType, long lAgentID, long lProfileID) PURE;
    STDMETHOD(UpdateDefaultAgentProfile)(THIS_ long lProfileID) PURE;
    STDMETHOD(GetAgentsStatus)(THIS_ SQLDMO_REPLAGENT_TYPE AgentType, SQLDMO_TASKSTATUS_TYPE *pRetValStatus, SQLDMO_LPBSTR pRetValTimeStamp CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(CleanUpDistributionPublisherByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(SetUpDistributorPassword)(THIS_ SQLDMO_LPCSTR pszPassword) PURE;
    STDMETHOD(EnumThirdPartyPublications)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPCSTR pszDistributionDBName CPPDEFAULT(= NULL)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMODistributor2
DECLARE_INTERFACE_(INTERFACE, ISQLDMODistributor)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
	STDMETHOD(GetDistributorInstalled)(THIS_ LPBOOL pbDistributorInstalled) PURE;
	STDMETHOD(GetDistributorAvailable)(THIS_ LPBOOL pbDistributorAvailable) PURE;
	STDMETHOD(GetDistributorLocal)(THIS_ LPBOOL pbDistributorLocal) PURE;
    STDMETHOD(GetDistributionServer)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDistributionServer)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDistributionDatabase)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetAgentCheckupInterval)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetAgentCheckupInterval)(THIS_ long lVal) PURE;
	STDMETHOD(GetIsDistributionPublisher)(THIS_ LPBOOL pIsDistributionPublisher) PURE;
	STDMETHOD(GetHasRemoteDistributionPublisher)(THIS_ LPBOOL pHasRemoteDistributionPublisher) PURE;

	//*** Collection properties
    STDMETHOD(GetDistributionPublishers)(THIS_ LPSQLDMODISTRIBUTIONPUBLISHERS * ppDistributionPublishers) PURE;
    STDMETHOD(GetDistributionPublisherByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMODISTRIBUTIONPUBLISHER *ppDistributionPublisher) PURE;
    STDMETHOD(GetDistributionPublisherByOrd)(THIS_ long lOrdinal, LPSQLDMODISTRIBUTIONPUBLISHER *ppDistributionPublisher) PURE;
    STDMETHOD(RemoveDistributionPublisherByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveDistributionPublisherByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddDistributionPublisher)(THIS_ LPSQLDMODISTRIBUTIONPUBLISHER pDistributionPublisher) PURE;
    STDMETHOD(GetDistributionPublisherCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetDistributionDatabases)(THIS_ LPSQLDMODISTRIBUTIONDATABASES * ppDistributionDatabases) PURE;
    STDMETHOD(GetDistributionDatabaseByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMODISTRIBUTIONDATABASE *ppDistributionDatabase) PURE;
    STDMETHOD(GetDistributionDatabaseByOrd)(THIS_ long lOrdinal, LPSQLDMODISTRIBUTIONDATABASE *ppDistributionDatabase) PURE;
    STDMETHOD(RemoveDistributionDatabaseByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveDistributionDatabaseByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddDistributionDatabase)(THIS_ LPSQLDMODISTRIBUTIONDATABASE pDistributionDatabase) PURE;
    STDMETHOD(GetDistributionDatabaseCount)(THIS_ LPLONG plCount) PURE;

   	//*** methods
    STDMETHOD(Refresh)(THIS) PURE;
    STDMETHOD(Install)(THIS) PURE;
    STDMETHOD(Uninstall)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_REPSCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMORepScript_InstallDistributor), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL)) PURE;

    STDMETHOD(EnumSnapshotAgentViews)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumLogReaderAgentViews)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumDistributionAgentViews)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumMergeAgentViews)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumMiscellaneousAgentViews)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(CreateAgentProfile)(THIS_ SQLDMO_LPCSTR szName, SQLDMO_LPCSTR szDescription, SQLDMO_REPLAGENT_TYPE AgentType, long *plProfileID) PURE;
    STDMETHOD(DeleteAgentProfile)(THIS_ long lProfileID) PURE;
    STDMETHOD(ChangeAgentProfile)(THIS_ long lProfileID, SQLDMO_LPCSTR szDescription) PURE;
    STDMETHOD(EnumAgentProfiles)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_REPLAGENT_TYPE AgentType CPPDEFAULT(= SQLDMOReplAgent_All)) PURE;
    STDMETHOD(ChangeAgentParameter)(THIS_ long lProfileID, SQLDMO_LPCSTR szParameterName, SQLDMO_LPCSTR szParameterValue) PURE;
    STDMETHOD(EnumAgentParameters)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, long lProfileID) PURE;
    STDMETHOD(UpdateAgentProfile)(THIS_ SQLDMO_LPCSTR DistributionDBName, SQLDMO_REPLAGENT_TYPE AgentType, long lAgentID, long lProfileID) PURE;
    STDMETHOD(UpdateDefaultAgentProfile)(THIS_ long lProfileID) PURE;
    STDMETHOD(GetAgentsStatus)(THIS_ SQLDMO_REPLAGENT_TYPE AgentType, SQLDMO_TASKSTATUS_TYPE *pRetValStatus, SQLDMO_LPBSTR pRetValTimeStamp CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(CleanUpDistributionPublisherByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(SetUpDistributorPassword)(THIS_ SQLDMO_LPCSTR pszPassword) PURE;
    STDMETHOD(EnumThirdPartyPublications)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPCSTR pszDistributionDBName CPPDEFAULT(= NULL)) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(EnumQueueReaderAgentViews)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumThirdPartyVendorNames)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumThirdPartyPublications2)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPCSTR pszDistributionDBName CPPDEFAULT(= NULL), SQLDMO_LPCSTR pszVendorName CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RemoveDefunctAnonymousSubscription)(THIS_ SQLDMO_LPCSTR pszDistributionDBName, long lAgentID, SQLDMO_REPLICATION_TYPE ReplType) PURE;
    STDMETHOD(EnumDistributionAgentViews2)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, BOOL fExcludeAnonymous CPPDEFAULT(= FALSE)) PURE;
    STDMETHOD(EnumMergeAgentViews2)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, BOOL fExcludeAnonymous CPPDEFAULT(= FALSE)) PURE;
    STDMETHOD(GetAgentsStatus2)(THIS_ SQLDMO_REPLAGENT_TYPE AgentType, BOOL fExcludeAnonymous, SQLDMO_TASKSTATUS_TYPE *pRetValStatus, SQLDMO_LPBSTR pRetValTimeStamp CPPDEFAULT(= NULL)) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOReplicationSecurity
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
    STDMETHOD(GetSecurityMode)(THIS_ SQLDMO_REPLSECURITY_TYPE *pRetVal) PURE;
    STDMETHOD(SetSecurityMode)(THIS_ SQLDMO_REPLSECURITY_TYPE NewValue) PURE;
    STDMETHOD(GetStandardLogin)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetStandardLogin)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetStandardPassword)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetStandardPassword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOReplicationTables
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
	STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOREPLICATIONTABLE *ppObj) PURE;
	STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOREPLICATIONTABLE *ppObj, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
	STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
	STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOReplicationTable
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(GetOwner)(THIS_ SQLDMO_LPBSTR pbstrOwner) PURE;
    STDMETHOD(GetHasPrimaryKey)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetHasGuidColumn)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetHasTimeStampColumn)(THIS_ LPBOOL pRetVal) PURE;

	//*** Collection properties
    STDMETHOD(GetColumns)(THIS_ LPSQLDMOCOLUMNS * ppColumns) PURE;
    STDMETHOD(GetColumnByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOCOLUMN *ppColumn) PURE;
    STDMETHOD(GetColumnByOrd)(THIS_ long lOrdinal, LPSQLDMOCOLUMN *ppColumn) PURE;
    STDMETHOD(GetColumnCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(EnumPublicationArticles)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOReplicationTable2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOReplicationTable)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(GetOwner)(THIS_ SQLDMO_LPBSTR pbstrOwner) PURE;
    STDMETHOD(GetHasPrimaryKey)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetHasGuidColumn)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetHasTimeStampColumn)(THIS_ LPBOOL pRetVal) PURE;

	//*** Collection properties
    STDMETHOD(GetColumns)(THIS_ LPSQLDMOCOLUMNS * ppColumns) PURE;
    STDMETHOD(GetColumnByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOCOLUMN *ppColumn) PURE;
    STDMETHOD(GetColumnByOrd)(THIS_ long lOrdinal, LPSQLDMOCOLUMN *ppColumn) PURE;
    STDMETHOD(GetColumnCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(EnumPublicationArticles)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetHasRowVersionColumn)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetHasIdentityColumn)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetHasSQLVariantColumn)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetHasBigIntColumn)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetHasBigIntIdentityColumn)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetPublishedInMerge)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetPublishedInQueuedTransactions)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetHasIdentityNotForReplColumn)(THIS_ LPBOOL pRetVal) PURE;

    STDMETHOD(EnumIdentityRangeInfo)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(ReplicationAddColumn)(THIS_ SQLDMO_LPCSTR pszColumnName, SQLDMO_LPCSTR pszTypeText, SQLDMO_LPCSTR pszPublicationName, SQLDMO_LPCSTR pszSchemaChangeScript CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(ReplicationDropColumn)(THIS_ SQLDMO_LPCSTR pszColumnName, SQLDMO_LPCSTR pszSchemaChangeScript CPPDEFAULT(= NULL)) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOReplicationStoredProcedures
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
	STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOREPLICATIONSTOREDPROCEDURE *ppObj) PURE;
	STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOREPLICATIONSTOREDPROCEDURE *ppObj, SQLDMO_LPCSTR szOwner CPPDEFAULT(= NULL)) PURE;
	STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
	STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOReplicationStoredProcedure
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(GetSystemObject)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetOwner)(THIS_ SQLDMO_LPBSTR pbstrOwner) PURE;

   	STDMETHOD(EnumPublicationArticles)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumDependencies)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_DEPENDENCY_TYPE DependencyType CPPDEFAULT(= SQLDMODep_Parents)) PURE;

};

#undef INTERFACE
#define INTERFACE ISQLDMOReplicationStoredProcedure2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOReplicationStoredProcedure)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pbstrName) PURE;
    STDMETHOD(GetSystemObject)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetOwner)(THIS_ SQLDMO_LPBSTR pbstrOwner) PURE;

   	STDMETHOD(EnumPublicationArticles)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumDependencies)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_DEPENDENCY_TYPE DependencyType CPPDEFAULT(= SQLDMODep_Parents)) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(GetEncrypted)(THIS_ LPBOOL pRetVal) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMODistributionPublications
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
	STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMODISTRIBUTIONPUBLICATION *ppObj) PURE;
	STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMODISTRIBUTIONPUBLICATION *ppObj, SQLDMO_LPCSTR szPubDB CPPDEFAULT(= NULL)) PURE;
	STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
	STDMETHOD(Add)(THIS_ LPSQLDMODISTRIBUTIONPUBLICATION Object) PURE;
	STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
	STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
	STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMODistributionPublication
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** Object properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetPublicationDB)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPublicationDB)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPublicationType)(THIS_ SQLDMO_PUBLICATION_TYPE FAR* pRetVal) PURE;
    STDMETHOD(SetPublicationType)(THIS_ SQLDMO_PUBLICATION_TYPE NewValue) PURE;
    STDMETHOD(GetPublicationAttributes)(THIS_ SQLDMO_PUBATTRIB_TYPE *pRetVal) PURE;
    STDMETHOD(SetPublicationAttributes)(THIS_ SQLDMO_PUBATTRIB_TYPE NewValue) PURE;
    STDMETHOD(GetSnapshotAgent)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSnapshotAgent)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetLogReaderAgent)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetLogReaderAgent)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDescription)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDescription)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetVendorName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetVendorName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

	//*** Collection properties
    STDMETHOD(GetDistributionArticles)(THIS_ LPSQLDMODISTRIBUTIONARTICLES * ppDistributionArticles) PURE;
    STDMETHOD(GetDistributionArticleByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMODISTRIBUTIONARTICLE *ppDistributionArticle) PURE;
    STDMETHOD(GetDistributionArticleByOrd)(THIS_ long lOrdinal, LPSQLDMODISTRIBUTIONARTICLE *ppDistributionArticle) PURE;
    STDMETHOD(RemoveDistributionArticleByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveDistributionArticleByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddDistributionArticle)(THIS_ LPSQLDMODISTRIBUTIONARTICLE pDistributionArticle) PURE;
    STDMETHOD(GetDistributionArticleCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetDistributionSubscriptions)(THIS_ LPSQLDMODISTRIBUTIONSUBSCRIPTIONS * ppDistributionSubscriptions) PURE;
    STDMETHOD(GetDistributionSubscriptionByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMODISTRIBUTIONSUBSCRIPTION *ppDistributionSubscription) PURE;
    STDMETHOD(GetDistributionSubscriptionByOrd)(THIS_ long lOrdinal, LPSQLDMODISTRIBUTIONSUBSCRIPTION *ppDistributionSubscription) PURE;
    STDMETHOD(RemoveDistributionSubscriptionByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveDistributionSubscriptionByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddDistributionSubscription)(THIS_ LPSQLDMODISTRIBUTIONSUBSCRIPTION pDistributionSubscription) PURE;
    STDMETHOD(GetDistributionSubscriptionCount)(THIS_ LPLONG plCount) PURE;

	//*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(EnumSubscriptionViews)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumSnapshotAgentView)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumLogReaderAgentView)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(GetAgentsStatus)(THIS_ SQLDMO_TASKSTATUS_TYPE FAR* pRetValStatus, SQLDMO_LPBSTR pRetValTimeStamp CPPDEFAULT(= NULL)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMODistributionPublication2
DECLARE_INTERFACE_(INTERFACE, ISQLDMODistributionPublication)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** Object properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetPublicationDB)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPublicationDB)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPublicationType)(THIS_ SQLDMO_PUBLICATION_TYPE FAR* pRetVal) PURE;
    STDMETHOD(SetPublicationType)(THIS_ SQLDMO_PUBLICATION_TYPE NewValue) PURE;
    STDMETHOD(GetPublicationAttributes)(THIS_ SQLDMO_PUBATTRIB_TYPE *pRetVal) PURE;
    STDMETHOD(SetPublicationAttributes)(THIS_ SQLDMO_PUBATTRIB_TYPE NewValue) PURE;
    STDMETHOD(GetSnapshotAgent)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSnapshotAgent)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetLogReaderAgent)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetLogReaderAgent)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDescription)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDescription)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetVendorName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetVendorName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

	//*** Collection properties
    STDMETHOD(GetDistributionArticles)(THIS_ LPSQLDMODISTRIBUTIONARTICLES * ppDistributionArticles) PURE;
    STDMETHOD(GetDistributionArticleByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMODISTRIBUTIONARTICLE *ppDistributionArticle) PURE;
    STDMETHOD(GetDistributionArticleByOrd)(THIS_ long lOrdinal, LPSQLDMODISTRIBUTIONARTICLE *ppDistributionArticle) PURE;
    STDMETHOD(RemoveDistributionArticleByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveDistributionArticleByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddDistributionArticle)(THIS_ LPSQLDMODISTRIBUTIONARTICLE pDistributionArticle) PURE;
    STDMETHOD(GetDistributionArticleCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetDistributionSubscriptions)(THIS_ LPSQLDMODISTRIBUTIONSUBSCRIPTIONS * ppDistributionSubscriptions) PURE;
    STDMETHOD(GetDistributionSubscriptionByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMODISTRIBUTIONSUBSCRIPTION *ppDistributionSubscription) PURE;
    STDMETHOD(GetDistributionSubscriptionByOrd)(THIS_ long lOrdinal, LPSQLDMODISTRIBUTIONSUBSCRIPTION *ppDistributionSubscription) PURE;
    STDMETHOD(RemoveDistributionSubscriptionByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveDistributionSubscriptionByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddDistributionSubscription)(THIS_ LPSQLDMODISTRIBUTIONSUBSCRIPTION pDistributionSubscription) PURE;
    STDMETHOD(GetDistributionSubscriptionCount)(THIS_ LPLONG plCount) PURE;

	//*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(EnumSubscriptionViews)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumSnapshotAgentView)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumLogReaderAgentView)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(GetAgentsStatus)(THIS_ SQLDMO_TASKSTATUS_TYPE FAR* pRetValStatus, SQLDMO_LPBSTR pRetValTimeStamp CPPDEFAULT(= NULL)) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(GetThirdPartyOptions)(THIS_ SQLDMO_THIRDPARTYOPTION_TYPE *pRetVal) PURE;
    STDMETHOD(SetThirdPartyOptions)(THIS_ SQLDMO_THIRDPARTYOPTION_TYPE NewValue) PURE;
    STDMETHOD(GetSnapshotJobID)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(EnumQueueReaderAgentView)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(EnumSubscriptionViews2)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, BOOL fExcludeAnonymous CPPDEFAULT(= FALSE)) PURE;
    STDMETHOD(GetAgentsStatus2)(THIS_ BOOL fExcludeAnonymous, SQLDMO_TASKSTATUS_TYPE FAR* pRetValStatus, SQLDMO_LPBSTR pRetValTimeStamp CPPDEFAULT(= NULL)) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMODistributionArticles
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
	STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMODISTRIBUTIONARTICLE *ppObj) PURE;
	STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMODISTRIBUTIONARTICLE *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMODISTRIBUTIONARTICLE *ppObj) PURE;
	STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
	STDMETHOD(Add)(THIS_ LPSQLDMODISTRIBUTIONARTICLE Object) PURE;
	STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
	STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
	STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMODistributionArticle
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetSourceObjectOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSourceObjectOwner)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSourceObjectName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSourceObjectName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDescription)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDescription)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

	//*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;

};

#undef INTERFACE
#define INTERFACE ISQLDMODistributionArticle2
DECLARE_INTERFACE_(INTERFACE, ISQLDMODistributionArticle)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetSourceObjectOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSourceObjectOwner)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSourceObjectName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSourceObjectName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDescription)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDescription)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

	//*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(SetID)(THIS_ LONG lNewValue) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMODistributionSubscriptions
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
	STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMODISTRIBUTIONSUBSCRIPTION *ppObj) PURE;
	STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMODISTRIBUTIONSUBSCRIPTION *ppObj) PURE;
	STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
	STDMETHOD(Add)(THIS_ LPSQLDMODISTRIBUTIONSUBSCRIPTION Object) PURE;
	STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
	STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
	STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;

};

#undef INTERFACE
#define INTERFACE ISQLDMODistributionSubscription
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetSubscriber)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSubscriber)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSubscriptionDB)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSubscriptionDB)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetStatus)(THIS_ SQLDMO_SUBSTATUS_TYPE FAR* pRetVal) PURE;
    STDMETHOD(SetStatus)(THIS_ SQLDMO_SUBSTATUS_TYPE NewValue) PURE;
    STDMETHOD(GetSyncType)(THIS_ SQLDMO_SUBSYNC_TYPE FAR* pRetVal) PURE;
    STDMETHOD(SetSyncType)(THIS_ SQLDMO_SUBSYNC_TYPE NewValue) PURE;
    STDMETHOD(GetSubscriptionType)(THIS_ SQLDMO_SUBSCRIPTION_TYPE *pRetVal) PURE;
    STDMETHOD(SetSubscriptionType)(THIS_ SQLDMO_SUBSCRIPTION_TYPE NewValue) PURE;
    STDMETHOD(GetDistributionSchedule)(THIS_ LPSQLDMOSCHEDULE *ppDistributionSchedule) PURE;
    STDMETHOD(GetDistributionAgent)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;

	//*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
};


#undef INTERFACE
#define INTERFACE ISQLDMODistributionSubscription2
DECLARE_INTERFACE_(INTERFACE, ISQLDMODistributionSubscription)
{
#ifndef NO_BASEINTERFACE_FUNCS
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

	//*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

	//*** properties
    STDMETHOD(GetName)(THIS_ LPBSTR pRetVal) PURE;
    STDMETHOD(GetSubscriber)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSubscriber)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSubscriptionDB)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSubscriptionDB)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetStatus)(THIS_ SQLDMO_SUBSTATUS_TYPE FAR* pRetVal) PURE;
    STDMETHOD(SetStatus)(THIS_ SQLDMO_SUBSTATUS_TYPE NewValue) PURE;
    STDMETHOD(GetSyncType)(THIS_ SQLDMO_SUBSYNC_TYPE FAR* pRetVal) PURE;
    STDMETHOD(SetSyncType)(THIS_ SQLDMO_SUBSYNC_TYPE NewValue) PURE;
    STDMETHOD(GetSubscriptionType)(THIS_ SQLDMO_SUBSCRIPTION_TYPE *pRetVal) PURE;
    STDMETHOD(SetSubscriptionType)(THIS_ SQLDMO_SUBSCRIPTION_TYPE NewValue) PURE;
    STDMETHOD(GetDistributionSchedule)(THIS_ LPSQLDMOSCHEDULE *ppDistributionSchedule) PURE;
    STDMETHOD(GetDistributionAgent)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;

	//*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    STDMETHOD(GetDistributionJobID)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOMergeDynamicSnapshotJobs
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
    //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef) (THIS) PURE;
    STDMETHOD_(ULONG, Release) (THIS) PURE;
    
    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
    STDMETHOD(GetItemByOrd)(THIS_ long Ordinal, LPSQLDMOMERGEDYNAMICSNAPSHOTJOB *ppObj) PURE;
    STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOMERGEDYNAMICSNAPSHOTJOB *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOMERGEDYNAMICSNAPSHOTJOB *ppObj) PURE;
    STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;
    
    //*** SQLDMO standard collection methods
    STDMETHOD(Add)(THIS_ LPSQLDMOMERGEDYNAMICSNAPSHOTJOB Object) PURE;
    STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;

};

#undef INTERFACE
#define INTERFACE ISQLDMOMergeDynamicSnapshotJob
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
    //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    
    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;
    
    //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDynamicSnapshotJobID)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetDynamicFilterLogin)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDynamicFilterLogin)(THIS_ SQLDMO_LPCSTR NewValue) PURE; 
    STDMETHOD(GetDynamicFilterHostName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDynamicFilterHostName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDynamicSnapshotLocation)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDynamicSnapshotLocation)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetSnapshotSchedule)(THIS_ LPSQLDMOSCHEDULE *pRetVal) PURE;

    //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOReplicationSink
DECLARE_INTERFACE_(INTERFACE, IUnknown)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** Sink properties and methods.
    STDMETHOD(StatusMessage)(THIS_ SQLDMO_LPCSTR szMessage) PURE;
    STDMETHOD(PercentComplete)(THIS_ SQLDMO_LPCSTR szMessage, long Percent) PURE;
};


// ***************************************************************************
//               Copyright (C) 1985-1999 Microsoft Corporation.
// @File: agen_itf.h
//
// Purpose: Agent defines and interfaces
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






////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOJobServer
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
    //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** properties
    STDMETHOD(GetStatus)(THIS_ SQLDMO_SVCSTATUS_TYPE *pRetVal) PURE;
    STDMETHOD(GetAutoStart)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAutoStart)(THIS_ BOOL NewValue) PURE;

    STDMETHOD(GetAlertSystem)(THIS_ LPSQLDMOALERTSYSTEM * ppAlertSystem) PURE;
    STDMETHOD(GetJobFilter)(THIS_ LPSQLDMOJOBFILTER * ppJobFilter) PURE;
    STDMETHOD(GetJobHistoryFilter)(THIS_ LPSQLDMOJOBHISTORYFILTER * ppJobHistoryFilter) PURE;
    STDMETHOD(GetMSXServerName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetType)(THIS_ SQLDMO_JOBSERVER_TYPE * pRetVal) PURE;
    STDMETHOD(GetStartupAccount)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;

    //*** Collection properties
    STDMETHOD(GetAlerts)(THIS_ LPSQLDMOALERTS *ppAlerts) PURE;
    STDMETHOD(GetAlertByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOALERT *ppAlert) PURE;
    STDMETHOD(GetAlertByOrd)(THIS_ long lOrdinal, LPSQLDMOALERT *ppAlert) PURE;
    STDMETHOD(RemoveAlertByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveAlertByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddAlert)(THIS_ LPSQLDMOALERT pAlert) PURE;
    STDMETHOD(GetAlertCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetOperators)(THIS_ LPSQLDMOOPERATORS *ppOperators) PURE;
    STDMETHOD(GetOperatorByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOOPERATOR *ppOperator) PURE;
    STDMETHOD(GetOperatorByOrd)(THIS_ long lOrdinal, LPSQLDMOOPERATOR *ppOperator) PURE;
    STDMETHOD(RemoveOperatorByName)(THIS_ SQLDMO_LPCSTR szName, SQLDMO_LPCSTR szReassignName CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RemoveOperatorByOrd)(THIS_ long lOrdinal, SQLDMO_LPCSTR szReassignName CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(AddOperator)(THIS_ LPSQLDMOOPERATOR pOperator) PURE;
    STDMETHOD(GetOperatorCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetJobs)(THIS_ LPSQLDMOJOBS * ppJobs) PURE;
    STDMETHOD(GetJobByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOJOB *ppJob) PURE;
    STDMETHOD(GetJobByOrd)(THIS_ long lOrdinal, LPSQLDMOJOB *ppJob) PURE;
    STDMETHOD(RemoveJobByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveJobByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddJob)(THIS_ LPSQLDMOJOB pJob) PURE;
    STDMETHOD(GetJobCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetTargetServers)(THIS_ LPSQLDMOTARGETSERVERS * ppTargetServers) PURE;
    STDMETHOD(GetTargetServerByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTARGETSERVER *ppTargetServer) PURE;
    STDMETHOD(GetTargetServerByOrd)(THIS_ long lOrdinal, LPSQLDMOTARGETSERVER *ppTargetServer) PURE;
    STDMETHOD(RemoveTargetServerByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveTargetServerByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddTargetServer)(THIS_ LPSQLDMOTARGETSERVER pTargetServer) PURE;
    STDMETHOD(GetTargetServerCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetTargetServerGroups)(THIS_ LPSQLDMOTARGETSERVERGROUPS * ppTargetServerGroups) PURE;
    STDMETHOD(GetTargetServerGroupByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTARGETSERVERGROUP *ppTargetServerGroup) PURE;
    STDMETHOD(GetTargetServerGroupByOrd)(THIS_ long lOrdinal, LPSQLDMOTARGETSERVERGROUP *ppTargetServerGroup) PURE;
    STDMETHOD(RemoveTargetServerGroupByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveTargetServerGroupByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddTargetServerGroup)(THIS_ LPSQLDMOTARGETSERVERGROUP pTargetServerGroup) PURE;
    STDMETHOD(GetTargetServerGroupCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetJobCategories)(THIS_ LPSQLDMOJOBCATEGORIES * ppJobCategories) PURE;
    STDMETHOD(GetJobCategoryByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOCATEGORY *ppCategory) PURE;
    STDMETHOD(GetJobCategoryByOrd)(THIS_ long lOrdinal, LPSQLDMOCATEGORY *ppCategory) PURE;
    STDMETHOD(RemoveJobCategoryByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveJobCategoryByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddJobCategory)(THIS_ LPSQLDMOCATEGORY pCategory) PURE;
    STDMETHOD(GetJobCategoryCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetAlertCategories)(THIS_ LPSQLDMOALERTCATEGORIES * ppAlertCategories) PURE;
    STDMETHOD(GetAlertCategoryByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOCATEGORY *ppCategory) PURE;
    STDMETHOD(GetAlertCategoryByOrd)(THIS_ long lOrdinal, LPSQLDMOCATEGORY *ppCategory) PURE;
    STDMETHOD(RemoveAlertCategoryByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveAlertCategoryByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddAlertCategory)(THIS_ LPSQLDMOCATEGORY pCategory) PURE;
    STDMETHOD(GetAlertCategoryCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetOperatorCategories)(THIS_ LPSQLDMOOPERATORCATEGORIES * ppOperatorCategories) PURE;
    STDMETHOD(GetOperatorCategoryByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOCATEGORY *ppCategory) PURE;
    STDMETHOD(GetOperatorCategoryByOrd)(THIS_ long lOrdinal, LPSQLDMOCATEGORY *ppCategory) PURE;
    STDMETHOD(RemoveOperatorCategoryByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveOperatorCategoryByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddOperatorCategory)(THIS_ LPSQLDMOCATEGORY pCategory) PURE;
    STDMETHOD(GetOperatorCategoryCount)(THIS_ LPLONG plCount) PURE;

    //*** methods
    STDMETHOD(Stop)(THIS) PURE;
    STDMETHOD(Start)(THIS) PURE;
    STDMETHOD(EnumSubSystems)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(ReAssignJobsByLogin)(THIS_ SQLDMO_LPCSTR szOldLogin, SQLDMO_LPCSTR szNewLogin) PURE;
    STDMETHOD(RemoveJobsByLogin)(THIS_ SQLDMO_LPCSTR szLogin) PURE;
    STDMETHOD(Refresh)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(EnumJobHistory)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, LPSQLDMOJOBHISTORYFILTER pFilter CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(PurgeJobHistory)(THIS_ LPSQLDMOJOBHISTORYFILTER pFilter CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(EnumJobs)(THIS_ LPSQLDMOQUERYRESULTS *ppRetVal, LPSQLDMOJOBFILTER pJobFilter CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RemoveJobsByServer)(THIS_ SQLDMO_LPCSTR szServer) PURE;
    STDMETHOD(MSXEnlist)(THIS_ SQLDMO_LPCSTR szServer, SQLDMO_LPCSTR szLocation) PURE;
    STDMETHOD(MSXDefect)(THIS) PURE;
    STDMETHOD(RemoveJobByID)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(StartMonitor)(THIS_ SQLDMO_LPCSTR szNetSendAddress, long lRestartAttempts) PURE;
    STDMETHOD(StopMonitor)(THIS) PURE;
    STDMETHOD(GetJobByID)(THIS_ SQLDMO_LPCSTR NewValue, LPSQLDMOJOB *ppJob, BOOL bFlag CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOJobServer2
DECLARE_INTERFACE_(INTERFACE, ISQLDMOJobServer)
{
#ifndef NO_BASEINTERFACE_FUNCS
    //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** properties
    STDMETHOD(GetStatus)(THIS_ SQLDMO_SVCSTATUS_TYPE *pRetVal) PURE;
    STDMETHOD(GetAutoStart)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetAutoStart)(THIS_ BOOL NewValue) PURE;

    STDMETHOD(GetAlertSystem)(THIS_ LPSQLDMOALERTSYSTEM * ppAlertSystem) PURE;
    STDMETHOD(GetJobFilter)(THIS_ LPSQLDMOJOBFILTER * ppJobFilter) PURE;
    STDMETHOD(GetJobHistoryFilter)(THIS_ LPSQLDMOJOBHISTORYFILTER * ppJobHistoryFilter) PURE;
    STDMETHOD(GetMSXServerName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetType)(THIS_ SQLDMO_JOBSERVER_TYPE * pRetVal) PURE;
    STDMETHOD(GetStartupAccount)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;

    //*** Collection properties
    STDMETHOD(GetAlerts)(THIS_ LPSQLDMOALERTS *ppAlerts) PURE;
    STDMETHOD(GetAlertByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOALERT *ppAlert) PURE;
    STDMETHOD(GetAlertByOrd)(THIS_ long lOrdinal, LPSQLDMOALERT *ppAlert) PURE;
    STDMETHOD(RemoveAlertByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveAlertByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddAlert)(THIS_ LPSQLDMOALERT pAlert) PURE;
    STDMETHOD(GetAlertCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetOperators)(THIS_ LPSQLDMOOPERATORS *ppOperators) PURE;
    STDMETHOD(GetOperatorByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOOPERATOR *ppOperator) PURE;
    STDMETHOD(GetOperatorByOrd)(THIS_ long lOrdinal, LPSQLDMOOPERATOR *ppOperator) PURE;
    STDMETHOD(RemoveOperatorByName)(THIS_ SQLDMO_LPCSTR szName, SQLDMO_LPCSTR szReassignName CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RemoveOperatorByOrd)(THIS_ long lOrdinal, SQLDMO_LPCSTR szReassignName CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(AddOperator)(THIS_ LPSQLDMOOPERATOR pOperator) PURE;
    STDMETHOD(GetOperatorCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetJobs)(THIS_ LPSQLDMOJOBS * ppJobs) PURE;
    STDMETHOD(GetJobByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOJOB *ppJob) PURE;
    STDMETHOD(GetJobByOrd)(THIS_ long lOrdinal, LPSQLDMOJOB *ppJob) PURE;
    STDMETHOD(RemoveJobByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveJobByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddJob)(THIS_ LPSQLDMOJOB pJob) PURE;
    STDMETHOD(GetJobCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetTargetServers)(THIS_ LPSQLDMOTARGETSERVERS * ppTargetServers) PURE;
    STDMETHOD(GetTargetServerByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTARGETSERVER *ppTargetServer) PURE;
    STDMETHOD(GetTargetServerByOrd)(THIS_ long lOrdinal, LPSQLDMOTARGETSERVER *ppTargetServer) PURE;
    STDMETHOD(RemoveTargetServerByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveTargetServerByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddTargetServer)(THIS_ LPSQLDMOTARGETSERVER pTargetServer) PURE;
    STDMETHOD(GetTargetServerCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetTargetServerGroups)(THIS_ LPSQLDMOTARGETSERVERGROUPS * ppTargetServerGroups) PURE;
    STDMETHOD(GetTargetServerGroupByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTARGETSERVERGROUP *ppTargetServerGroup) PURE;
    STDMETHOD(GetTargetServerGroupByOrd)(THIS_ long lOrdinal, LPSQLDMOTARGETSERVERGROUP *ppTargetServerGroup) PURE;
    STDMETHOD(RemoveTargetServerGroupByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveTargetServerGroupByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddTargetServerGroup)(THIS_ LPSQLDMOTARGETSERVERGROUP pTargetServerGroup) PURE;
    STDMETHOD(GetTargetServerGroupCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetJobCategories)(THIS_ LPSQLDMOJOBCATEGORIES * ppJobCategories) PURE;
    STDMETHOD(GetJobCategoryByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOCATEGORY *ppCategory) PURE;
    STDMETHOD(GetJobCategoryByOrd)(THIS_ long lOrdinal, LPSQLDMOCATEGORY *ppCategory) PURE;
    STDMETHOD(RemoveJobCategoryByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveJobCategoryByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddJobCategory)(THIS_ LPSQLDMOCATEGORY pCategory) PURE;
    STDMETHOD(GetJobCategoryCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetAlertCategories)(THIS_ LPSQLDMOALERTCATEGORIES * ppAlertCategories) PURE;
    STDMETHOD(GetAlertCategoryByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOCATEGORY *ppCategory) PURE;
    STDMETHOD(GetAlertCategoryByOrd)(THIS_ long lOrdinal, LPSQLDMOCATEGORY *ppCategory) PURE;
    STDMETHOD(RemoveAlertCategoryByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveAlertCategoryByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddAlertCategory)(THIS_ LPSQLDMOCATEGORY pCategory) PURE;
    STDMETHOD(GetAlertCategoryCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetOperatorCategories)(THIS_ LPSQLDMOOPERATORCATEGORIES * ppOperatorCategories) PURE;
    STDMETHOD(GetOperatorCategoryByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOCATEGORY *ppCategory) PURE;
    STDMETHOD(GetOperatorCategoryByOrd)(THIS_ long lOrdinal, LPSQLDMOCATEGORY *ppCategory) PURE;
    STDMETHOD(RemoveOperatorCategoryByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveOperatorCategoryByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddOperatorCategory)(THIS_ LPSQLDMOCATEGORY pCategory) PURE;
    STDMETHOD(GetOperatorCategoryCount)(THIS_ LPLONG plCount) PURE;

    //*** methods
    STDMETHOD(Stop)(THIS) PURE;
    STDMETHOD(Start)(THIS) PURE;
    STDMETHOD(EnumSubSystems)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
    STDMETHOD(ReAssignJobsByLogin)(THIS_ SQLDMO_LPCSTR szOldLogin, SQLDMO_LPCSTR szNewLogin) PURE;
    STDMETHOD(RemoveJobsByLogin)(THIS_ SQLDMO_LPCSTR szLogin) PURE;
    STDMETHOD(Refresh)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(EnumJobHistory)(THIS_ LPSQLDMOQUERYRESULTS *ppResults, LPSQLDMOJOBHISTORYFILTER pFilter CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(PurgeJobHistory)(THIS_ LPSQLDMOJOBHISTORYFILTER pFilter CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(EnumJobs)(THIS_ LPSQLDMOQUERYRESULTS *ppRetVal, LPSQLDMOJOBFILTER pJobFilter CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RemoveJobsByServer)(THIS_ SQLDMO_LPCSTR szServer) PURE;
    STDMETHOD(MSXEnlist)(THIS_ SQLDMO_LPCSTR szServer, SQLDMO_LPCSTR szLocation) PURE;
    STDMETHOD(MSXDefect)(THIS) PURE;
    STDMETHOD(RemoveJobByID)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(StartMonitor)(THIS_ SQLDMO_LPCSTR szNetSendAddress, long lRestartAttempts) PURE;
    STDMETHOD(StopMonitor)(THIS) PURE;
    STDMETHOD(GetJobByID)(THIS_ SQLDMO_LPCSTR NewValue, LPSQLDMOJOB *ppJob, BOOL bFlag CPPDEFAULT(= FALSE)) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    // 8.0
    STDMETHOD(GetServiceName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOAlerts
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

        //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
    STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOALERT *ppObj) PURE;
    STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOALERT *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOALERT *ppObj) PURE;
    STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
    STDMETHOD(Add)(THIS_ LPSQLDMOALERT Object) PURE;
    STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
    // 7.0
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOAlert
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetEventSource)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetEventCategoryID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetEventID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetMessageID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetMessageID)(THIS_ long NewValue) PURE;
    STDMETHOD(GetSeverity)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetSeverity)(THIS_ long NewValue) PURE;
    STDMETHOD(GetEnabled)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetEnabled)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetDelayBetweenResponses)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetDelayBetweenResponses)(THIS_ long NewValue) PURE;
    STDMETHOD(GetLastOccurrenceDate)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetLastOccurrenceDate)(THIS_ long NewValue) PURE;
    STDMETHOD(GetLastOccurrenceTime)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetLastOccurrenceTime)(THIS_ long NewValue) PURE;
    STDMETHOD(GetLastResponseDate)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetLastResponseDate)(THIS_ long NewValue) PURE;
    STDMETHOD(GetLastResponseTime)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetLastResponseTime)(THIS_ long NewValue) PURE;
    STDMETHOD(GetNotificationMessage)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetNotificationMessage)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetIncludeEventDescription)(THIS_ SQLDMO_NOTIFY_TYPE *pRetVal) PURE;
    STDMETHOD(SetIncludeEventDescription)(THIS_ SQLDMO_NOTIFY_TYPE NewValue) PURE;
    STDMETHOD(GetDatabaseName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDatabaseName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetEventDescriptionKeyword)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetEventDescriptionKeyword)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetOccurrenceCount)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetCountResetDate)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetCountResetTime)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetJobName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetHasNotification)(THIS_ LPLONG pRetVal) PURE;

    //*** methods
    STDMETHOD(AddNotification)(THIS_ SQLDMO_LPCSTR OperatorName, SQLDMO_NOTIFY_TYPE NotifyMethod) PURE;
    STDMETHOD(UpdateNotification)(THIS_ SQLDMO_LPCSTR OperatorName, SQLDMO_NOTIFY_TYPE NotifyMethod) PURE;
    STDMETHOD(RemoveNotification)(THIS_ SQLDMO_LPCSTR OperatorName) PURE;
    STDMETHOD(EnumNotifications)(THIS_ SQLDMO_NOTIFY_TYPE NotifyMethod, SQLDMO_ENUMNOTIFY_TYPE EnumNotifyType, LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPCSTR OperatorName CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(Refresh)(THIS) PURE;

    // Post-6.0 additions.
    STDMETHOD(GetRaiseSNMPTrap)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetRaiseSNMPTrap)(THIS_ BOOL NewValue) PURE;

    // 7.0
    STDMETHOD(GetPerformanceCondition)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPerformanceCondition)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetJobID)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetJobID)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetCategory)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetCategory)(THIS_ SQLDMO_LPCSTR NewVal) PURE;
    STDMETHOD(GetType)(THIS_ SQLDMO_ALERT_TYPE *pRetVal) PURE;
    STDMETHOD(ResetOccurrenceCount)(THIS) PURE;
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOOperators
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
    STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOOPERATOR *ppObj) PURE;
    STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOOPERATOR *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOOPERATOR *ppObj) PURE;
    STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
    STDMETHOD(Add)(THIS_ LPSQLDMOOPERATOR Object) PURE;
    STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal, SQLDMO_LPCSTR NewName CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName, SQLDMO_LPCSTR NewName CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
    // 7.0
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOOperator
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetEnabled)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetEnabled)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetEmailAddress)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetEmailAddress)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetLastEmailDate)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetLastEmailTime)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetPagerAddress)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPagerAddress)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetLastPageDate)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetLastPageTime)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetWeekdayPagerStartTime)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetWeekdayPagerStartTime)(THIS_ long NewValue) PURE;
    STDMETHOD(GetWeekdayPagerEndTime)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetWeekdayPagerEndTime)(THIS_ long NewValue) PURE;
    STDMETHOD(GetSaturdayPagerStartTime)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetSaturdayPagerStartTime)(THIS_ long NewValue) PURE;
    STDMETHOD(GetSaturdayPagerEndTime)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetSaturdayPagerEndTime)(THIS_ long NewValue) PURE;
    STDMETHOD(GetSundayPagerStartTime)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetSundayPagerStartTime)(THIS_ long NewValue) PURE;
    STDMETHOD(GetSundayPagerEndTime)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetSundayPagerEndTime)(THIS_ long NewValue) PURE;
    STDMETHOD(GetPagerDays)(THIS_ SQLDMO_WEEKDAY_TYPE *pRetVal) PURE;
    STDMETHOD(SetPagerDays)(THIS_ SQLDMO_WEEKDAY_TYPE NewValue) PURE;
    STDMETHOD(GetCategory)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetCategory)(THIS_ SQLDMO_LPCSTR NewVal) PURE;
    STDMETHOD(GetNetSendAddress)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetNetSendAddress)(THIS_ SQLDMO_LPCSTR NewVal) PURE;
    STDMETHOD(GetLastNetSendDate)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetLastNetSendTime)(THIS_ LPLONG pRetVal) PURE;

    //*** methods
    STDMETHOD(AddNotification)(THIS_ SQLDMO_LPCSTR AlertName, SQLDMO_NOTIFY_TYPE NotifyMethod) PURE;
    STDMETHOD(UpdateNotification)(THIS_ SQLDMO_LPCSTR AlertName, SQLDMO_NOTIFY_TYPE NotifyMethod) PURE;
    STDMETHOD(RemoveNotification)(THIS_ SQLDMO_LPCSTR AlertName) PURE;
    STDMETHOD(EnumNotifications)(THIS_ SQLDMO_NOTIFY_TYPE NotifyMethod, SQLDMO_ENUMNOTIFY_TYPE EnumNotifyType, LPSQLDMOQUERYRESULTS *ppResults, SQLDMO_LPCSTR AlertName CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(Remove)(THIS_ SQLDMO_LPCSTR NewName CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(Refresh)(THIS) PURE;
    // 7.0
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
    STDMETHOD(EnumJobNotifications)(THIS_ LPSQLDMOQUERYRESULTS *ppResults) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOAlertSystem
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
    //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** properties
    STDMETHOD(GetFailSafeOperator)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetFailSafeOperator)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetNotificationMethod)(THIS_ SQLDMO_NOTIFY_TYPE *pRetVal) PURE;
    STDMETHOD(SetNotificationMethod)(THIS_ SQLDMO_NOTIFY_TYPE NewValue) PURE;
    STDMETHOD(GetForwardingServer)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetForwardingServer)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetForwardingSeverity)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetForwardingSeverity)(THIS_ long NewValue) PURE;
    STDMETHOD(GetPagerToTemplate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPagerToTemplate)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPagerCCTemplate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPagerCCTemplate)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPagerSubjectTemplate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetPagerSubjectTemplate)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetPagerSendSubjectOnly)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetPagerSendSubjectOnly)(THIS_ BOOL NewValue) PURE;

    // 7.0
    STDMETHOD(GetForwardAlways)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetForwardAlways)(THIS_ BOOL NewValue) PURE;

    //*** methods
    STDMETHOD(Refresh)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOJobHistoryFilter
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** properties
    STDMETHOD(GetJobName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetJobName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetStartRunDate)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetStartRunDate)(THIS_ long NewValue) PURE;
    STDMETHOD(GetStartRunTime)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetStartRunTime)(THIS_ long NewValue) PURE;
    STDMETHOD(GetOutcomeTypes)(THIS_ SQLDMO_JOBOUTCOME_TYPE *pRetVal) PURE;
    STDMETHOD(SetOutcomeTypes)(THIS_ SQLDMO_JOBOUTCOME_TYPE NewValue) PURE;
    STDMETHOD(GetSQLMessageID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetSQLMessageID)(THIS_ long NewValue) PURE;
    STDMETHOD(GetSQLSeverity)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetSQLSeverity)(THIS_ long NewValue) PURE;
    STDMETHOD(GetMinimumRunDuration)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetMinimumRunDuration)(THIS_ long NewValue) PURE;
    STDMETHOD(GetMinimumRetries)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetMinimumRetries)(THIS_ long NewValue) PURE;
    STDMETHOD(GetOldestFirst)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetOldestFirst)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetEndRunDate)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetEndRunDate)(THIS_ long NewValue) PURE;
    STDMETHOD(GetEndRunTime)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetEndRunTime)(THIS_ long NewValue) PURE;
    STDMETHOD(GetJobID)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetJobID)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOJobs
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
    //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
    STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOJOB *ppObj) PURE;
    STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOJOB *ppObj) PURE;
    STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
    STDMETHOD(Add)(THIS_ LPSQLDMOJOB Object) PURE;
    STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
    // 7.0
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
	 // Collection method
};

#undef INTERFACE
#define INTERFACE ISQLDMOJob
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetEnabled)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetEnabled)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetJobID)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetOriginatingServer)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetStartStepID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetStartStepID)(THIS_ LONG NewVal) PURE;
    STDMETHOD(GetDescription)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDescription)(THIS_ SQLDMO_LPCSTR NewVal) PURE;
    STDMETHOD(GetCategory)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetCategory)(THIS_ SQLDMO_LPCSTR NewVal) PURE;
    STDMETHOD(GetOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetOwner)(THIS_ SQLDMO_LPCSTR NewVal) PURE;
    STDMETHOD(GetEventlogLevel)(THIS_ SQLDMO_COMPLETION_TYPE *pRetVal) PURE;
    STDMETHOD(SetEventlogLevel)(THIS_ SQLDMO_COMPLETION_TYPE NewVal) PURE;
    STDMETHOD(GetEmailLevel)(THIS_ SQLDMO_COMPLETION_TYPE *pRetVal) PURE;
    STDMETHOD(SetEmailLevel)(THIS_ SQLDMO_COMPLETION_TYPE NewVal) PURE;
    STDMETHOD(GetOperatorToEmail)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetOperatorToEmail)(THIS_ SQLDMO_LPCSTR NewVal) PURE;
    STDMETHOD(GetDateCreated)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetDateLastModified)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetLastRunDate)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetLastRunTime)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetLastRunOutcome)(THIS_ SQLDMO_JOBOUTCOME_TYPE *pRetVal) PURE;
    STDMETHOD(GetCurrentRunStatus)(THIS_ SQLDMO_JOBEXECUTION_STATUS *pRetVal) PURE;
    STDMETHOD(GetCurrentRunStep)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetNetSendLevel)(THIS_ SQLDMO_COMPLETION_TYPE *pRetVal) PURE;
    STDMETHOD(SetNetSendLevel)(THIS_ SQLDMO_COMPLETION_TYPE NewVal) PURE;
    STDMETHOD(GetDeleteLevel)(THIS_ SQLDMO_COMPLETION_TYPE *pRetVal) PURE;
    STDMETHOD(SetDeleteLevel)(THIS_ SQLDMO_COMPLETION_TYPE NewVal) PURE;
    STDMETHOD(GetHasStep)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetHasServer)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetType)(THIS_ SQLDMO_JOB_TYPE *pRetVal) PURE;
    STDMETHOD(GetHasSchedule)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(GetVersionNumber)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetNextRunDate)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetNextRunTime)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetCurrentRunRetryAttempt)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetNextRunScheduleID)(THIS_ LPLONG pRetVal) PURE;

    //*** Collection properties
    STDMETHOD(GetJobSteps)(THIS_ LPSQLDMOJOBSTEPS *ppJobSteps) PURE;
    STDMETHOD(GetJobStepByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOJOBSTEP *ppJobStep) PURE;
    STDMETHOD(GetJobStepByOrd)(THIS_ long lOrdinal, LPSQLDMOJOBSTEP *ppJobStep) PURE;
    STDMETHOD(RemoveJobStepByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveJobStepByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddJobStep)(THIS_ LPSQLDMOJOBSTEP pJobStep) PURE;
    STDMETHOD(GetJobStepCount)(THIS_ LPLONG plCount) PURE;

    STDMETHOD(GetJobSchedules)(THIS_ LPSQLDMOJOBSCHEDULES *ppJobSchedules) PURE;
    STDMETHOD(GetJobScheduleByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOJOBSCHEDULE *ppJobSchedule) PURE;
    STDMETHOD(GetJobScheduleByOrd)(THIS_ long lOrdinal, LPSQLDMOJOBSCHEDULE *ppJobSchedule) PURE;
    STDMETHOD(RemoveJobScheduleByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(RemoveJobScheduleByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(AddJobSchedule)(THIS_ LPSQLDMOJOBSCHEDULE pJobSchedule) PURE;
    STDMETHOD(GetJobScheduleCount)(THIS_ LPLONG plCount) PURE;

    //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(Refresh)(THIS) PURE;
    STDMETHOD(ApplyToTargetServer)(THIS_ SQLDMO_LPCSTR NewVal) PURE;
    STDMETHOD(RemoveFromTargetServer)(THIS_ SQLDMO_LPCSTR NewVal) PURE;
    STDMETHOD(EnumTargetServers)(THIS_ LPSQLDMOQUERYRESULTS *ppRetVal) PURE;
    STDMETHOD(ApplyToTargetServerGroup)(THIS_ SQLDMO_LPCSTR NewVal) PURE;
    STDMETHOD(EnumHistory)(THIS_ LPSQLDMOQUERYRESULTS *ppRetVal, LPSQLDMOJOBHISTORYFILTER pJobHistoryFilter CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(PurgeHistory)(THIS) PURE;
    STDMETHOD(Invoke)(THIS) PURE;
    STDMETHOD(AddStepToJob)(THIS_ LPSQLDMOJOBSTEP pJobStep) PURE;
    STDMETHOD(RemoveFromTargetServerGroup)(THIS_ SQLDMO_LPCSTR NewVal) PURE;
    STDMETHOD(RemoveAllJobSteps)(THIS) PURE;
    STDMETHOD(Start)(THIS_ SQLDMO_LPCSTR NewVal CPPDEFAULT(= NULL)) PURE;
    STDMETHOD(Stop)(THIS) PURE;
    STDMETHOD(RemoveAllJobSchedules)(THIS) PURE;

    // 7.0 After Beta 1
    STDMETHOD(GetPageLevel)(THIS_ SQLDMO_COMPLETION_TYPE *pRetVal) PURE;
    STDMETHOD(SetPageLevel)(THIS_ SQLDMO_COMPLETION_TYPE NewVal) PURE;
    STDMETHOD(GetOperatorToNetSend)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetOperatorToNetSend)(THIS_ SQLDMO_LPCSTR NewVal) PURE;
    STDMETHOD(GetOperatorToPage)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetOperatorToPage)(THIS_ SQLDMO_LPCSTR NewVal) PURE;
    STDMETHOD(EnumAlerts)(THIS_ LPSQLDMOQUERYRESULTS *ppRetVal) PURE;
    // 7.0 after Beta 3
    STDMETHOD(Script)(THIS_ SQLDMO_SCRIPT_TYPE ScriptType CPPDEFAULT(= SQLDMOScript_Default), SQLDMO_LPCSTR ScriptFilePath CPPDEFAULT(= NULL), SQLDMO_LPBSTR ScriptText CPPDEFAULT(= NULL), SQLDMO_SCRIPT2_TYPE Script2Type CPPDEFAULT(= SQLDMOScript2_Default)) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOJobSteps
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
    //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
    STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOJOBSTEP *ppObj) PURE;
    STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOJOBSTEP *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOJOBSTEP *ppObj) PURE;
    STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
    STDMETHOD(Add)(THIS_ LPSQLDMOJOBSTEP Object) PURE;
    STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOJobStep
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** properties
    STDMETHOD(GetStepID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetStepID)(THIS_ LONG lNewVal) PURE;
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewVal) PURE;
    STDMETHOD(GetSubSystem)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetSubSystem)(THIS_ SQLDMO_LPCSTR NewVal) PURE;
    STDMETHOD(GetCommand)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetCommand)(THIS_ SQLDMO_LPCSTR NewVal) PURE;
    STDMETHOD(GetFlags)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetFlags)(THIS_ LONG lNewVal) PURE;
    STDMETHOD(GetAdditionalParameters)(THIS_ SQLDMO_LPBSTR RetVal) PURE;
    STDMETHOD(SetAdditionalParameters)(THIS_ SQLDMO_LPCSTR NewVal) PURE;
    STDMETHOD(GetCmdExecSuccessCode)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetCmdExecSuccessCode)(THIS_ LONG lNewVal) PURE;
    STDMETHOD(GetOnSuccessAction)(THIS_ SQLDMO_JOBSTEPACTION_TYPE *pRetVal) PURE;
    STDMETHOD(SetOnSuccessAction)(THIS_ SQLDMO_JOBSTEPACTION_TYPE NewValue) PURE;
    STDMETHOD(GetOnSuccessStep)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetOnSuccessStep)(THIS_ LONG lNewVal) PURE;
    STDMETHOD(GetOnFailAction)(THIS_ SQLDMO_JOBSTEPACTION_TYPE *pRetVal) PURE;
    STDMETHOD(SetOnFailAction)(THIS_ SQLDMO_JOBSTEPACTION_TYPE NewValue) PURE;
    STDMETHOD(GetOnFailStep)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetOnFailStep)(THIS_ LONG lNewVal) PURE;
    STDMETHOD(GetServer)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetServer)(THIS_ SQLDMO_LPCSTR NewVal) PURE;
    STDMETHOD(GetDatabaseName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDatabaseName)(THIS_ SQLDMO_LPCSTR NewVal) PURE;
    STDMETHOD(GetDatabaseUserName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDatabaseUserName)(THIS_ SQLDMO_LPCSTR NewVal) PURE;
    STDMETHOD(GetRetryAttempts)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetRetryAttempts)(THIS_ LONG lNewVal) PURE;
    STDMETHOD(GetRetryInterval)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetRetryInterval)(THIS_ LONG lNewVal) PURE;
    STDMETHOD(GetOSRunPriority)(THIS_ SQLDMO_RUNPRIORITY_TYPE *pRetVal) PURE;
    STDMETHOD(SetOSRunPriority)(THIS_ SQLDMO_RUNPRIORITY_TYPE NewValue) PURE;
    STDMETHOD(GetLastRunOutcome)(THIS_ SQLDMO_JOBOUTCOME_TYPE *pRetVal) PURE;
    STDMETHOD(GetLastRunDuration)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetLastRunRetries)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetLastRunDate)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetLastRunTime)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetOutputFileName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetOutputFileName)(THIS_ SQLDMO_LPCSTR NewVal) PURE;

    //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(Refresh)(THIS) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOTargetServers
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
    //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
    STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOTARGETSERVER *ppObj) PURE;
    STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTARGETSERVER *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOTARGETSERVER *ppObj) PURE;
        STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
    STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOTargetServer
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
    //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** properties
    STDMETHOD(GetServerID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetServerName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetEnlistDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetLastPollDate)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetStatus)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetLocation)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetLocation)(THIS_ SQLDMO_LPCSTR NewVal) PURE;
    STDMETHOD(GetTimeZoneAdjustment)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetPendingInstructions)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetLocalTime)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetPollingInterval)(THIS_ LPLONG pRetVal) PURE;

    //*** methods
    STDMETHOD(Refresh)(THIS) PURE;
};


////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOTargetServerGroups
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
    //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
    STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOTARGETSERVERGROUP *ppObj) PURE;
    STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOTARGETSERVERGROUP *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOTARGETSERVERGROUP *ppObj) PURE;
    STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
    STDMETHOD(Add)(THIS_ LPSQLDMOTARGETSERVERGROUP Object) PURE;
    STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOTargetServerGroup
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
    //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** properties
    STDMETHOD(GetGroupID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

    //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(Refresh)(THIS) PURE;
    STDMETHOD(AddMemberServer)(THIS_ SQLDMO_LPCSTR Value) PURE;
    STDMETHOD(RemoveMemberServer)(THIS_ SQLDMO_LPCSTR Value) PURE;

    //*** List methods
    STDMETHOD(ListMemberServers)(THIS_ LPSQLDMONAMELIST * ppList) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOJobCategories
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
    //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
    STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOCATEGORY *ppObj) PURE;
    STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOCATEGORY *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOCATEGORY *ppObj) PURE;
    STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
    STDMETHOD(Add)(THIS_ LPSQLDMOCATEGORY Object) PURE;
    STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
	 // Collection method
};

#undef INTERFACE
#define INTERFACE ISQLDMOAlertCategories
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
    //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
    STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOCATEGORY *ppObj) PURE;
    STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOCATEGORY *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOCATEGORY *ppObj) PURE;
    STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
    STDMETHOD(Add)(THIS_ LPSQLDMOCATEGORY Object) PURE;
    STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOOperatorCategories
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
    //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
    STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOCATEGORY *ppObj) PURE;
    STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOCATEGORY *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOCATEGORY *ppObj) PURE;
    STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
    STDMETHOD(Add)(THIS_ LPSQLDMOCATEGORY Object) PURE;
    STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOCategory
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
    //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** properties
    STDMETHOD(GetID)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(GetType)(THIS_ SQLDMO_CATEGORYTYPE_TYPE FAR* pRetVal) PURE;
    STDMETHOD(SetType)(THIS_ SQLDMO_CATEGORYTYPE_TYPE NewValue) PURE;
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;

    //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(Refresh)(THIS) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOJobSchedules
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
    //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** SQLDMO standard enumeration properties
    STDMETHOD(GetItemByOrd)(THIS_ long lOrdinal, LPSQLDMOJOBSCHEDULE *ppObj) PURE;
    STDMETHOD(GetItemByName)(THIS_ SQLDMO_LPCSTR szName, LPSQLDMOJOBSCHEDULE *ppObj) PURE;
    STDMETHOD(GetItemByID)(THIS_ long lID, LPSQLDMOJOBSCHEDULE *ppObj) PURE;
    STDMETHOD(GetCount)(THIS_ LPLONG plCount) PURE;

    //*** SQLDMO standard collection methods
    STDMETHOD(Add)(THIS_ LPSQLDMOJOBSCHEDULE Object) PURE;
    STDMETHOD(RemoveByOrd)(THIS_ long lOrdinal) PURE;
    STDMETHOD(RemoveByName)(THIS_ SQLDMO_LPCSTR szName) PURE;
    STDMETHOD(Refresh)(THIS_ BOOL bReleaseMemberObjects CPPDEFAULT(= FALSE)) PURE;
};

#undef INTERFACE
#define INTERFACE ISQLDMOJobSchedule
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
   //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** properties
    STDMETHOD(GetName)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetName)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetEnabled)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetEnabled)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetSchedule)(THIS_ LPSQLDMOSCHEDULE * ppSchedule) PURE;
    STDMETHOD(GetDateCreated)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(GetScheduleID)(THIS_ LPLONG pRetVal) PURE;

    //*** methods
    STDMETHOD(Remove)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
    STDMETHOD(Refresh)(THIS) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOSchedule
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
    //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** properties
    STDMETHOD(GetFrequencyType)(THIS_ SQLDMO_FREQUENCY_TYPE *pRetVal) PURE;
    STDMETHOD(SetFrequencyType)(THIS_ SQLDMO_FREQUENCY_TYPE NewValue) PURE;
    STDMETHOD(GetFrequencyInterval)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetFrequencyInterval)(THIS_ long NewValue) PURE;
    STDMETHOD(GetFrequencySubDay)(THIS_ SQLDMO_FREQSUB_TYPE *pRetVal) PURE;
    STDMETHOD(SetFrequencySubDay)(THIS_ SQLDMO_FREQSUB_TYPE NewValue) PURE;
    STDMETHOD(GetFrequencySubDayInterval)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetFrequencySubDayInterval)(THIS_ long NewValue) PURE;
    STDMETHOD(GetFrequencyRelativeInterval)(THIS_ SQLDMO_FREQRELATIVE_TYPE *pRetVal) PURE;
    STDMETHOD(SetFrequencyRelativeInterval)(THIS_ SQLDMO_FREQRELATIVE_TYPE NewValue) PURE;
    STDMETHOD(GetFrequencyRecurrenceFactor)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetFrequencyRecurrenceFactor)(THIS_ long NewValue) PURE;
    STDMETHOD(GetActiveStartDate)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetActiveStartDate)(THIS_ long NewValue) PURE;
    STDMETHOD(GetActiveEndDate)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetActiveEndDate)(THIS_ long NewValue) PURE;
    STDMETHOD(GetActiveStartTimeOfDay)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetActiveStartTimeOfDay)(THIS_ long NewValue) PURE;
    STDMETHOD(GetActiveEndTimeOfDay)(THIS_ LPLONG pRetVal) PURE;
    STDMETHOD(SetActiveEndTimeOfDay)(THIS_ long NewValue) PURE;

    //*** methods
    STDMETHOD(Refresh)(THIS) PURE;
    STDMETHOD(BeginAlter)(THIS) PURE;
    STDMETHOD(DoAlter)(THIS) PURE;
    STDMETHOD(CancelAlter)(THIS) PURE;
};

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

#undef INTERFACE
#define INTERFACE ISQLDMOJobFilter
DECLARE_INTERFACE_(INTERFACE, ISQLDMOStdObject)
{
    //*** IUnknown methods
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    //*** SQLDMO standard object properties.
    STDMETHOD(GetApplication)(THIS_ LPSQLDMOAPPLICATION *ppApp) PURE;
    STDMETHOD(GetParent)(THIS_ LPSQLDMOSTDOBJECT *ppParent) PURE;
    STDMETHOD(GetTypeOf)(THIS_ SQLDMO_OBJECT_TYPE *pRetVal) PURE;
    STDMETHOD(GetUserData)(THIS_ LPVOID *pRetVal) PURE;
    STDMETHOD(SetUserData)(THIS_ LPVOID lpvNewValue) PURE;

    //*** properties
    STDMETHOD(GetCurrentExecutionStatus)(THIS_ SQLDMO_JOBEXECUTION_STATUS *pRetVal) PURE;
    STDMETHOD(SetCurrentExecutionStatus)(THIS_ SQLDMO_JOBEXECUTION_STATUS NewValue) PURE;
    STDMETHOD(GetEnabled)(THIS_ LPBOOL pRetVal) PURE;
    STDMETHOD(SetEnabled)(THIS_ BOOL NewValue) PURE;
    STDMETHOD(GetCategory)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetCategory)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetOwner)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetOwner)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetStepSubsystem)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetStepSubsystem)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDateJobCreated)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDateJobCreated)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDateJobLastModified)(THIS_ SQLDMO_LPBSTR pRetVal) PURE;
    STDMETHOD(SetDateJobLastModified)(THIS_ SQLDMO_LPCSTR NewValue) PURE;
    STDMETHOD(GetDateFindOperand)(THIS_ SQLDMO_FIND_OPERAND *pRetVal) PURE;
    STDMETHOD(SetDateFindOperand)(THIS_ SQLDMO_FIND_OPERAND NewValue) PURE;
    STDMETHOD(GetType)(THIS_ SQLDMO_JOB_TYPE *pRetVal) PURE;
    STDMETHOD(SetType)(THIS_ SQLDMO_JOB_TYPE NewValue) PURE;

    //*** methods
};





/////////////////////////////////////////////////////////////////////////////
//		SQLDMO Connection Point Sink Interfaces
/////////////////////////////////////////////////////////////////////////////

#ifdef _SQLDMO_INTERNAL_
#endif

#endif	// !_SQLDMO_ODL_
#endif	// _SQLDMO_H_
