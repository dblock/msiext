
#ifndef __DTS_H_
#define __DTS_H_

#define OBJID_TYPELIB_DTS L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000032C8}"



#define OBJID_DtsActiveScriptTask L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B8E}"
#define OBJID_DtsCreateProcessTask L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B91}"
#define OBJID_DtsCreateTableTask L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B92}"
#define OBJID_DtsCustomTask L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B93}"
#define OBJID_DtsDataPumpTask L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B94}"
#define OBJID_DtsExecuteSQLTask L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B95}"
#define OBJID_DtsConnection L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B9A}"
#define OBJID_DtsNode L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B9C}"
#define OBJID_DtsTransformationPackage L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000032D9}"
#define OBJID_DtsTransferObjectsTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000032DA}"
#define OBJID_DtsRemoteCommandExecutionTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000032DB}"
#define OBJID_DtsSendMailTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000032DC}"
#define OBJID_DtsDataDrivenQueryTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000032DD}"
#define OBJID_DtsTransformationTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000032DE}"
#define OBJID_DtsTransformationStep L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000032DF}"
#define OBJID_DtsTransformationLookup L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000032E0}"
#define OBJID_DtsTransformation L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000032F0}"
#define OBJID_DtsOLEDBProperty L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},00003300}"
#define OBJID_DtsScriptTransformation L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},00003309}"
#define OBJID_DtsCopyTransformation L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},0000330A}"
#define OBJID_DtsStepExecution L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},0000334E}"
#define OBJID_DtsBulkInsertTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},0000334F}"
#define OBJID_DtsTransformationSet L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},00003366}"
#define OBJID_DtsDynamicPropertiesTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},00003367}"
#define OBJID_DtsDynamicPropertiesTaskAssignment L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},00003368}"
#define OBJID_DtsSimpleStringTransformation L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000033D1}"
#define OBJID_DtsMQMessage L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000033D2}"
#define OBJID_DtsReadFileTransformation L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000033D3}"
#define OBJID_DtsFTPTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000033D4}"
#define OBJID_DtsWriteFileTransformation L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000033D5}"
#define OBJID_DtsExecutePackageTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000033D6}"
#define OBJID_DtsMessageQueueTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000033D7}"
#define OBJID_DtsDateTimeTransformation L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000033D8}"
#define OBJID_DtsParallelDataPumpTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000033E2}"
#define DISPID_IDtsDataPumpTask_InsertCommitSize 11095
#define DISPID_IDtsDataPumpTask_UseFastLoad 11098
#define DISPID_IDtsDataPumpTask_AllowIdentityInsert 13070
#define DISPID_IDtsDataPumpTask_FastLoadOptions 13107
#define IOID_IDtsDataPumpTask L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B55}"
DEFINE_GUID(IID_IDtsDataPumpTask,
0x7fcf788d, 0xaf00, 0x11d1, 0x8c, 0x1e, 0x00, 0xaa, 0x00, 0xa1, 0x4d, 0x34);

#define DISPID_IDtsTransformationPackage_PackageID 11100
#define DISPID_IDtsTransformationPackage_ExceptionLog 11102
#define DISPID_IDtsTransformationPackage_MaxConcurrentSteps 11103
#define DISPID_IDtsTransformationPackage_Priority 11104
#define DISPID_IDtsTransformationPackage_LineageOptions 13090
#define DISPID_IDtsTransformationPackage_UseTransaction 13102
#define DISPID_IDtsTransformationPackage_AutoCommitTransaction 13103
#define DISPID_IDtsTransformationPackage_TransactionIsolationLevel 13104
#define DISPID_IDtsTransformationPackage_RepositoryMetadataOptions 13105
#define DISPID_IDtsTransformationPackage_ExecutedPackage 13274
#define DISPID_IDtsTransformationPackage_ExecutePackageTask 13275
#define IOID_IDtsTransformationPackage L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000032CA}"
DEFINE_GUID(IID_IDtsTransformationPackage,
0xebb9995f, 0xba15, 0x11d1, 0x90, 0x1b, 0x00, 0x00, 0xf8, 0x7a, 0x3b, 0x33);

#define IOID_IDtsActiveScriptTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000032CB}"
DEFINE_GUID(IID_IDtsActiveScriptTask,
0xebb99960, 0xba15, 0x11d1, 0x90, 0x1b, 0x00, 0x00, 0xf8, 0x7a, 0x3b, 0x33);

#define DISPID_IDtsCreateProcessTask_SuccessReturnCode 13037
#define IOID_IDtsCreateProcessTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000032CC}"
DEFINE_GUID(IID_IDtsCreateProcessTask,
0xebb99961, 0xba15, 0x11d1, 0x90, 0x1b, 0x00, 0x00, 0xf8, 0x7a, 0x3b, 0x33);

#define IOID_IDtsCustomTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000032CD}"
DEFINE_GUID(IID_IDtsCustomTask,
0xebb99962, 0xba15, 0x11d1, 0x90, 0x1b, 0x00, 0x00, 0xf8, 0x7a, 0x3b, 0x33);

#define IOID_IDtsExecuteSQLTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000032CE}"
DEFINE_GUID(IID_IDtsExecuteSQLTask,
0xebb99963, 0xba15, 0x11d1, 0x90, 0x1b, 0x00, 0x00, 0xf8, 0x7a, 0x3b, 0x33);

#define IOID_IDtsCreateTableTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000032CF}"
DEFINE_GUID(IID_IDtsCreateTableTask,
0xebb99964, 0xba15, 0x11d1, 0x90, 0x1b, 0x00, 0x00, 0xf8, 0x7a, 0x3b, 0x33);

#define DISPID_IDtsSendMailTask_Profile 13093
#define DISPID_IDtsSendMailTask_Password 13094
#define DISPID_IDtsSendMailTask_ToLine 13095
#define DISPID_IDtsSendMailTask_CCline 13096
#define DISPID_IDtsSendMailTask_FileAttachments 13097
#define DISPID_IDtsSendMailTask_Subject 13098
#define DISPID_IDtsSendMailTask_Message 13099
#define DISPID_IDtsSendMailTask_IsNTService 13100
#define DISPID_IDtsSendMailTask_SaveMailInSentItemsFolder 13101
#define IOID_IDtsSendMailTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000032D0}"
DEFINE_GUID(IID_IDtsSendMailTask,
0xebb99965, 0xba15, 0x11d1, 0x90, 0x1b, 0x00, 0x00, 0xf8, 0x7a, 0x3b, 0x33);

#define IOID_IDtsRemoteCommandExecutionTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000032D2}"
DEFINE_GUID(IID_IDtsRemoteCommandExecutionTask,
0xebb99967, 0xba15, 0x11d1, 0x90, 0x1b, 0x00, 0x00, 0xf8, 0x7a, 0x3b, 0x33);

#define IOID_IDtsDataDrivenQueryTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000032D3}"
DEFINE_GUID(IID_IDtsDataDrivenQueryTask,
0xebb99968, 0xba15, 0x11d1, 0x90, 0x1b, 0x00, 0x00, 0xf8, 0x7a, 0x3b, 0x33);

#define DISPID_IDtsTransformationTask_Timeout 11075
#define DISPID_IDtsTransformationTask_FailOnTimeout 11076
#define DISPID_IDtsTransformationTask_TerminateOnTimeout 11077
#define DISPID_IDtsTransformationTask_ExceptionLog 11078
#define DISPID_IDtsTransformationTask_ServerID 11205
#define DISPID_IDtsTransformationTask_Connection 13032
#define DISPID_IDtsTransformationTask_SourceTasks 13033
#define DISPID_IDtsTransformationTask_TargetConnection 13035
#define DISPID_IDtsTransformationTask_TargetTasks 13036
#define IOID_IDtsTransformationTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000032D4}"
DEFINE_GUID(IID_IDtsTransformationTask,
0xebb99969, 0xba15, 0x11d1, 0x90, 0x1b, 0x00, 0x00, 0xf8, 0x7a, 0x3b, 0x33);

#define DISPID_IDtsTransformationStep_ExecuteInMainThread 11082
#define DISPID_IDtsTransformationStep_Priority 11083
#define DISPID_IDtsTransformationStep_RollbackOnFailure 11084
#define DISPID_IDtsTransformationStep_CloseConnectionOnCompletion 13014
#define DISPID_IDtsTransformationStep_CommitTransactionOnSuccess 13015
#define DISPID_IDtsTransformationStep_IsPackageRowset 13043
#define DISPID_IDtsTransformationStep_Language 13059
#define DISPID_IDtsTransformationStep_JoinTransactionIfPresent 13106
#define IOID_IDtsTransformationStep L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000032D5}"
DEFINE_GUID(IID_IDtsTransformationStep,
0xebb9996a, 0xba15, 0x11d1, 0x90, 0x1b, 0x00, 0x00, 0xf8, 0x7a, 0x3b, 0x33);

#define DISPID_IDtsTransformationLookup_MaxCacheRows 13044
#define IOID_IDtsTransformationLookup L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000032D8}"
DEFINE_GUID(IID_IDtsTransformationLookup,
0xebb9996b, 0xba15, 0x11d1, 0x90, 0x1b, 0x00, 0x00, 0xf8, 0x7a, 0x3b, 0x33);

#define DISPID_IDtsTransformation_ServerID 13039
#define DISPID_IDtsTransformation_ForceBlobsInMemory 13067
#define DISPID_IDtsTransformation_ForceSourceBlobsBuffered 13068
#define DISPID_IDtsTransformation_InMemoryBlobSize 13069
#define IOID_IDtsTransformation L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000032EE}"
DEFINE_GUID(IID_IDtsTransformation,
0xa3b100a3, 0xc4f0, 0x11d1, 0xbd, 0x44, 0x00, 0x00, 0xc0, 0xed, 0x9b, 0xe8);

#define DISPID_IDtsDataTransformationTask_FetchBufferSize 13046
#define DISPID_IDtsDataTransformationTask_MaximumErrorCount 13047
#define DISPID_IDtsDataTransformationTask_ProgressRowCount 13048
#define DISPID_IDtsDataTransformationTask_ExceptionFileColumnDelimiter 13049
#define DISPID_IDtsDataTransformationTask_ExceptionFileRowDelimiter 13050
#define IOID_IDtsDataTransformationTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000032F5}"
DEFINE_GUID(IID_IDtsDataTransformationTask,
0x25d705e8, 0xe48c, 0x11d1, 0xb0, 0x69, 0x00, 0x00, 0xf8, 0x7a, 0x57, 0xee);

#define DISPID_IDtsOLEDBProperty_PropertySet 13052
#define DISPID_IDtsOLEDBProperty_PropertyFlags 13053
#define DISPID_IDtsOLEDBProperty_PropertyId 13054
#define DISPID_IDtsOLEDBProperty_VariantType 13055
#define IOID_IDtsOLEDBProperty L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000032FB}"
DEFINE_GUID(IID_IDtsOLEDBProperty,
0x25d705e9, 0xe48c, 0x11d1, 0xb0, 0x69, 0x00, 0x00, 0xf8, 0x7a, 0x57, 0xee);

#define IOID_IDtsCopyTransformation L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},00003301}"
DEFINE_GUID(IID_IDtsCopyTransformation,
0xef1afa82, 0xe549, 0x11d1, 0xb0, 0x69, 0x00, 0x00, 0xf8, 0x7a, 0x57, 0xee);

#define IOID_IDtsScriptTransformation L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},00003302}"
DEFINE_GUID(IID_IDtsScriptTransformation,
0xef1afa83, 0xe549, 0x11d1, 0xb0, 0x69, 0x00, 0x00, 0xf8, 0x7a, 0x57, 0xee);

#define DISPID_IDtsNode_Location 11133
#define DISPID_IDtsNode_NetworkAddress 11134
#define DISPID_IDtsNode_ProcessorCount 11135
#define DISPID_IDtsNode_ProcessorType 11136
#define DISPID_IDtsNode_MemorySize 11137
#define DISPID_IDtsNode_DiskCapacity 11138
#define DISPID_IDtsNode_OSVersion 11139
#define DISPID_IDtsNode_NodeID 11140
#define DISPID_IDtsNode_Connections 13061
#define DISPID_IDtsNode_Node 13062
#define IOID_IDtsNode L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B7C}"
DEFINE_GUID(IID_IDtsNode,
0x7fcf7895, 0xaf00, 0x11d1, 0x8c, 0x1e, 0x00, 0xaa, 0x00, 0xa1, 0x4d, 0x34);

#define DISPID_IDtsConnection_ID 13041
#define DISPID_IDtsConnection_UseTrustedConnection 13042
#define DISPID_IDtsConnection_ConnectImmediate 13063
#define DISPID_IDtsConnection_Connection 13032
#define DISPID_IDtsConnection_SourceTasks 13033
#define DISPID_IDtsConnection_TargetConnection 13035
#define DISPID_IDtsConnection_TargetTasks 13036
#define DISPID_IDtsConnection_Connections 13061
#define DISPID_IDtsConnection_Node 13062
#define DISPID_IDtsConnection_QueryConnection 13162
#define DISPID_IDtsConnection_TaskAssignments 13163
#define IOID_IDtsConnection L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000032C9}"
DEFINE_GUID(IID_IDtsConnection,
0xebb9995e, 0xba15, 0x11d1, 0x90, 0x1b, 0x00, 0x00, 0xf8, 0x7a, 0x3b, 0x33);

#define DISPID_IDtsTransferObjectsTask_SourceServer 13072
#define DISPID_IDtsTransferObjectsTask_SourceLogin 13073
#define DISPID_IDtsTransferObjectsTask_SourcePassword 13074
#define DISPID_IDtsTransferObjectsTask_SourceDB 13075
#define DISPID_IDtsTransferObjectsTask_CopySchema 13089
#define DISPID_IDtsTransferObjectsTask_DestinationServer 13076
#define DISPID_IDtsTransferObjectsTask_DestinationLogin 13077
#define DISPID_IDtsTransferObjectsTask_DestinationPassword 13078
#define DISPID_IDtsTransferObjectsTask_DestinationDB 13079
#define DISPID_IDtsTransferObjectsTask_ScriptDirectory 13080
#define DISPID_IDtsTransferObjectsTask_SourceTrustedLogin 13081
#define DISPID_IDtsTransferObjectsTask_DestinationTrustedLogin 13082
#define DISPID_IDtsTransferObjectsTask_IncludeDependencies 13083
#define DISPID_IDtsTransferObjectsTask_IncludeLogins 13084
#define DISPID_IDtsTransferObjectsTask_IncludeUsers 13085
#define DISPID_IDtsTransferObjectsTask_DropDestinationObjectsFirst 13086
#define DISPID_IDtsTransferObjectsTask_CopyDataOptions 13087
#define DISPID_IDtsTransferObjectsTask_CopyAllObjects 13088
#define DISPID_IDtsTransferObjectsTask_ScriptOptions 13091
#define DISPID_IDtsTransferObjectsTask_ScriptOptionsEx 13092
#define IOID_IDtsTransferObjectsTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},0000330F}"
DEFINE_GUID(IID_IDtsTransferObjectsTask,
0x9239e236, 0x1de0, 0x11d2, 0xb7, 0x98, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IDtsBulkInsertTask_Codepage 13109
#define DISPID_IDtsBulkInsertTask_FieldTerminator 13110
#define DISPID_IDtsBulkInsertTask_RowTerminator 13111
#define DISPID_IDtsBulkInsertTask_DataFile 13113
#define DISPID_IDtsBulkInsertTask_FormatFile 13114
#define DISPID_IDtsBulkInsertTask_SortedData 13115
#define DISPID_IDtsBulkInsertTask_CheckConstraints 13116
#define DISPID_IDtsBulkInsertTask_KeepIdentity 13117
#define DISPID_IDtsBulkInsertTask_KeepNulls 13118
#define DISPID_IDtsBulkInsertTask_TableLock 13119
#define DISPID_IDtsBulkInsertTask_ConnectionID 13120
#define DISPID_IDtsBulkInsertTask_BatchSize 13121
#define DISPID_IDtsBulkInsertTask_FirstRow 13122
#define DISPID_IDtsBulkInsertTask_LastRow 13123
#define DISPID_IDtsBulkInsertTask_MaximumErrors 13124
#define DISPID_IDtsBulkInsertTask_DataFileType 13125
#define IOID_IDtsBulkInsertTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},00003334}"
DEFINE_GUID(IID_IDtsBulkInsertTask,
0x8d6a0aa, 0x2d5e, 0x11d2, 0xb7, 0xa2, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IDtsStepExecution_ExecutionStatus 13127
#define DISPID_IDtsStepExecution_ExecutionResult 13128
#define DISPID_IDtsStepExecution_ErrorSource 13129
#define DISPID_IDtsStepExecution_ErrorDescription 13130
#define DISPID_IDtsStepExecution_ErrorCode 13131
#define DISPID_IDtsStepExecution_ErrorHelpFile 13132
#define DISPID_IDtsStepExecution_ErrorHelpContext 13133
#define IOID_IDtsStepExecution L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},00003346}"
DEFINE_GUID(IID_IDtsStepExecution,
0xa3628896, 0x306f, 0x11d2, 0xb7, 0xa4, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IDtsParallelDataPumpTask_TransformationSetOptions 13137
#define DISPID_IDtsParallelDataPumpTask_InputGlobalVariableNames 13290
#define IOID_IDtsParallelDataPumpTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},00003350}"
DEFINE_GUID(IID_IDtsParallelDataPumpTask,
0xae45c5e4, 0xff54, 0x11d2, 0x91, 0xbe, 0x00, 0x00, 0xf8, 0x1f, 0x5c, 0x3d);

#define IOID_IDtsTransformationSet L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},00003352}"
DEFINE_GUID(IID_IDtsTransformationSet,
0xae45c5e5, 0xff54, 0x11d2, 0x91, 0xbe, 0x00, 0x00, 0xf8, 0x1f, 0x5c, 0x3d);

#define IOID_IDtsDynamicPropertiesTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},00003353}"
DEFINE_GUID(IID_IDtsDynamicPropertiesTask,
0xae45c5e6, 0xff54, 0x11d2, 0x91, 0xbe, 0x00, 0x00, 0xf8, 0x1f, 0x5c, 0x3d);

#define DISPID_IDtsDynamicPropertiesTaskAssignment_SourceType 13141
#define DISPID_IDtsDynamicPropertiesTaskAssignment_SourceIniFileKey 13142
#define DISPID_IDtsDynamicPropertiesTaskAssignment_SourceIniFileSection 13143
#define DISPID_IDtsDynamicPropertiesTaskAssignment_SourceIniFileFileName 13144
#define DISPID_IDtsDynamicPropertiesTaskAssignment_SourceQuerySQL 13146
#define DISPID_IDtsDynamicPropertiesTaskAssignment_SourceGlobalVariable 13147
#define DISPID_IDtsDynamicPropertiesTaskAssignment_SourceEnvironmentVariable 13148
#define DISPID_IDtsDynamicPropertiesTaskAssignment_DestinationPropertyID 13149
#define DISPID_IDtsDynamicPropertiesTaskAssignment_SourceConstantValue 13276
#define DISPID_IDtsDynamicPropertiesTaskAssignment_SourceDataFileName 13277
#define DISPID_IDtsDynamicPropertiesTaskAssignment_QueryConnection 13162
#define DISPID_IDtsDynamicPropertiesTaskAssignment_TaskAssignments 13163
#define IOID_IDtsDynamicPropertiesTaskAssignment L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},00003354}"
DEFINE_GUID(IID_IDtsDynamicPropertiesTaskAssignment,
0xae45c5e7, 0xff54, 0x11d2, 0x91, 0xbe, 0x00, 0x00, 0xf8, 0x1f, 0x5c, 0x3d);

#define DISPID_IDtsTransformationPackage2_LogToSQLServer 13151
#define DISPID_IDtsTransformationPackage2_LogServerName 13152
#define DISPID_IDtsTransformationPackage2_LogServerUserName 13153
#define DISPID_IDtsTransformationPackage2_LogServerUserPassword 13154
#define DISPID_IDtsTransformationPackage2_LogServerFlags 13155
#define DISPID_IDtsTransformationPackage2_FailPackageOnLogFailure 13156
#define DISPID_IDtsTransformationPackage2_ExplicitGlobalVariables 13157
#define DISPID_IDtsTransformationPackage2_PackageType 13278
#define IOID_IDtsTransformationPackage2 L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},0000335E}"
DEFINE_GUID(IID_IDtsTransformationPackage2,
0xae45c5e8, 0xff54, 0x11d2, 0x91, 0xbe, 0x00, 0x00, 0xf8, 0x1f, 0x5c, 0x3d);

#define DISPID_IDtsMQMessage_MessageType 13189
#define DISPID_IDtsMQMessage_MessageString 13190
#define DISPID_IDtsMQMessage_MessageDataFile 13191
#define DISPID_IDtsMQMessage_MessageGlobalVariables 13192
#define DISPID_IDtsMQMessage_WaitForAcknowledgement 13193
#define DISPID_IDtsMQMessage_UseTransaction 13194
#define IOID_IDtsMQMessage L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},0000336D}"
DEFINE_GUID(IID_IDtsMQMessage,
0xf35e2891, 0xfac, 0x11d3, 0xb2, 0x12, 0x00, 0xc0, 0x4f, 0x68, 0x6c, 0x16);

#define DISPID_IDtsFTPTask_SourceLocation 13170
#define DISPID_IDtsFTPTask_SourceSite 13171
#define DISPID_IDtsFTPTask_SourceUserName 13172
#define DISPID_IDtsFTPTask_SourcePassword 13173
#define DISPID_IDtsFTPTask_SourceFileName 13174
#define DISPID_IDtsFTPTask_DestSite 13175
#define DISPID_IDtsFTPTask_NonOverWritable 13176
#define DISPID_IDtsFTPTask_NumRetriesOnSource 13177
#define IOID_IDtsFTPTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},00003371}"
DEFINE_GUID(IID_IDtsFTPTask,
0xce2840d6, 0xfae, 0x11d3, 0xb2, 0x12, 0x00, 0xc0, 0x4f, 0x68, 0x6c, 0x16);

#define DISPID_IDtsMessageQueueTask_TaskType 13179
#define DISPID_IDtsMessageQueueTask_QueuePath 13180
#define DISPID_IDtsMessageQueueTask_DTSMessagePackageID 13181
#define DISPID_IDtsMessageQueueTask_DSMessageVersionID 13182
#define DISPID_IDtsMessageQueueTask_DTSMessageLineageID 13183
#define DISPID_IDtsMessageQueueTask_StringCompareType 13184
#define DISPID_IDtsMessageQueueTask_StringCompareValue 13185
#define DISPID_IDtsMessageQueueTask_RemoveFromQueue 13186
#define DISPID_IDtsMessageQueueTask_ErrorIfReceiveMessageTimeout 13187
#define DISPID_IDtsMessageQueueTask_ReceiveMessageTimeout 13188
#define DISPID_IDtsMessageQueueTask_ReceiveMessageType 13287
#define DISPID_IDtsMessageQueueTask_SaveDataFileName 13288
#define DISPID_IDtsMessageQueueTask_DataFileNonOverwritable 13289
#define IOID_IDtsMessageQueueTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},0000337A}"
DEFINE_GUID(IID_IDtsMessageQueueTask,
0xce2840d7, 0xfae, 0x11d3, 0xb2, 0x12, 0x00, 0xc0, 0x4f, 0x68, 0x6c, 0x16);

#define DISPID_IDtsExecutePackageTask_ServerName 13196
#define DISPID_IDtsExecutePackageTask_ServerUserName 13197
#define DISPID_IDtsExecutePackageTask_ServerPassword 13198
#define DISPID_IDtsExecutePackageTask_UseTrustedConnection 13199
#define DISPID_IDtsExecutePackageTask_UseRepository 13200
#define DISPID_IDtsExecutePackageTask_RepositoryDatabaseName 13201
#define DISPID_IDtsExecutePackageTask_PackageName 13202
#define DISPID_IDtsExecutePackageTask_PackagePassword 13203
#define DISPID_IDtsExecutePackageTask_PackageID 13204
#define DISPID_IDtsExecutePackageTask_VersionID 13205
#define DISPID_IDtsExecutePackageTask_FileName 13206
#define DISPID_IDtsExecutePackageTask_InputGlobalVariableNames 13291
#define DISPID_IDtsExecutePackageTask_ExecutedPackage 13274
#define DISPID_IDtsExecutePackageTask_ExecutePackageTask 13275
#define IOID_IDtsExecutePackageTask L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},0000338B}"
DEFINE_GUID(IID_IDtsExecutePackageTask,
0xe35b7471, 0xfca, 0x11d3, 0xb2, 0x12, 0x00, 0xc0, 0x4f, 0x68, 0x6c, 0x16);

#define DISPID_IDtsReadFileTransformation_ErrorIfFileNotFound 13210
#define DISPID_IDtsReadFileTransformation_FilePath 13211
#define DISPID_IDtsReadFileTransformation_UnicodeFile 13283
#define DISPID_IDtsReadFileTransformation_OEMFile 13284
#define IOID_IDtsReadFileTransformation L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},00003399}"
DEFINE_GUID(IID_IDtsReadFileTransformation,
0xe35b7473, 0xfca, 0x11d3, 0xb2, 0x12, 0x00, 0xc0, 0x4f, 0x68, 0x6c, 0x16);

#define DISPID_IDtsWriteFileTransformation_ErrorIfFileExists 13213
#define DISPID_IDtsWriteFileTransformation_AppendIfFileExists 13214
#define DISPID_IDtsWriteFileTransformation_FilePath 13215
#define DISPID_IDtsWriteFileTransformation_FileColumnName 13216
#define DISPID_IDtsWriteFileTransformation_UnicodeFile 13285
#define DISPID_IDtsWriteFileTransformation_OEMFile 13286
#define IOID_IDtsWriteFileTransformation L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},0000339C}"
DEFINE_GUID(IID_IDtsWriteFileTransformation,
0xe35b7474, 0xfca, 0x11d3, 0xb2, 0x12, 0x00, 0xc0, 0x4f, 0x68, 0x6c, 0x16);

#define DISPID_IDtsDateTimeTransformation_Month1LongName 13218
#define DISPID_IDtsDateTimeTransformation_Month2LongName 13219
#define DISPID_IDtsDateTimeTransformation_Month3LongName 13220
#define DISPID_IDtsDateTimeTransformation_Month4LongName 13221
#define DISPID_IDtsDateTimeTransformation_Month5LongName 13222
#define DISPID_IDtsDateTimeTransformation_Month6LongName 13223
#define DISPID_IDtsDateTimeTransformation_Month7LongName 13224
#define DISPID_IDtsDateTimeTransformation_Month8LongName 13225
#define DISPID_IDtsDateTimeTransformation_Month9LongName 13226
#define DISPID_IDtsDateTimeTransformation_Month10LongName 13227
#define DISPID_IDtsDateTimeTransformation_Month11LongName 13228
#define DISPID_IDtsDateTimeTransformation_Month12LongName 13229
#define DISPID_IDtsDateTimeTransformation_Month1ShortName 13230
#define DISPID_IDtsDateTimeTransformation_Month2ShortName 13231
#define DISPID_IDtsDateTimeTransformation_Month3ShortName 13232
#define DISPID_IDtsDateTimeTransformation_Month4ShortName 13233
#define DISPID_IDtsDateTimeTransformation_Month5ShortName 13234
#define DISPID_IDtsDateTimeTransformation_Month6ShortName 13235
#define DISPID_IDtsDateTimeTransformation_Month7ShortName 13236
#define DISPID_IDtsDateTimeTransformation_Month8ShortName 13237
#define DISPID_IDtsDateTimeTransformation_Month9ShortName 13238
#define DISPID_IDtsDateTimeTransformation_Month10ShortName 13239
#define DISPID_IDtsDateTimeTransformation_Month11ShortName 13240
#define DISPID_IDtsDateTimeTransformation_Month12ShortName 13241
#define DISPID_IDtsDateTimeTransformation_Day1LongName 13242
#define DISPID_IDtsDateTimeTransformation_Day2LongName 13243
#define DISPID_IDtsDateTimeTransformation_Day3LongName 13244
#define DISPID_IDtsDateTimeTransformation_Day4LongName 13245
#define DISPID_IDtsDateTimeTransformation_Day5LongName 13246
#define DISPID_IDtsDateTimeTransformation_Day6LongName 13247
#define DISPID_IDtsDateTimeTransformation_Day7LongName 13248
#define DISPID_IDtsDateTimeTransformation_Day1ShortName 13249
#define DISPID_IDtsDateTimeTransformation_Day2ShortName 13250
#define DISPID_IDtsDateTimeTransformation_Day3ShortName 13251
#define DISPID_IDtsDateTimeTransformation_Day4ShortName 13252
#define DISPID_IDtsDateTimeTransformation_Day5ShortName 13253
#define DISPID_IDtsDateTimeTransformation_Day6ShortName 13254
#define DISPID_IDtsDateTimeTransformation_Day7ShortName 13255
#define DISPID_IDtsDateTimeTransformation_InputFormat 13256
#define DISPID_IDtsDateTimeTransformation_OutputFormat 13257
#define DISPID_IDtsDateTimeTransformation_AMSymbol 13258
#define DISPID_IDtsDateTimeTransformation_PMSymbol 13259
#define DISPID_IDtsDateTimeTransformation_ShortYear2000Cutoff 13260
#define IOID_IDtsDateTimeTransformation L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000033A1}"
DEFINE_GUID(IID_IDtsDateTimeTransformation,
0xe35b7475, 0xfca, 0x11d3, 0xb2, 0x12, 0x00, 0xc0, 0x4f, 0x68, 0x6c, 0x16);

#define DISPID_IDtsSimpleStringTransformation_StringTransformationName 13208
#define IOID_IDtsSimpleStringTransformation L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},00003397}"
DEFINE_GUID(IID_IDtsSimpleStringTransformation,
0xe35b7472, 0xfca, 0x11d3, 0xb2, 0x12, 0x00, 0xc0, 0x4f, 0x68, 0x6c, 0x16);

#define DISPID_IDtsTransferObjectsTask2_SourceTranslateChar 13280
#define DISPID_IDtsTransferObjectsTask2_DestTranslateChar 13281
#define DISPID_IDtsTransferObjectsTask2_UseDestTransaction 13292
#define DISPID_IDtsTransferObjectsTask2_UseCollation 13317
#define IOID_IDtsTransferObjectsTask2 L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000033DF}"
DEFINE_GUID(IID_IDtsTransferObjectsTask2,
0x9b58863e, 0x154e, 0x11d3, 0xb2, 0x16, 0x00, 0xc0, 0x4f, 0x68, 0x6c, 0x16);

#define DISPID_IDtsDataTransformationTask2_ExceptionFileOptions 13294
#define DISPID_IDtsDataTransformationTask2_ExceptionFileTextQualifier 13295
#define IOID_IDtsDataTransformationTask2 L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000033ED}"
DEFINE_GUID(IID_IDtsDataTransformationTask2,
0x40753f4c, 0x94e9, 0x4d37, 0xa1, 0x77, 0xa2, 0x24, 0x55, 0xd0, 0x3d, 0x27);

#define DISPID_IDtsDataDrivenQueryTask2_InputGlobalVariableNames 13297
#define IOID_IDtsDataDrivenQueryTask2 L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000033F0}"
DEFINE_GUID(IID_IDtsDataDrivenQueryTask2,
0xa1fd9a46, 0x3d3e, 0x4565, 0x88, 0x40, 0x30, 0xa1, 0xe4, 0x29, 0x83, 0xda);

#define DISPID_IDtsDataPumpTask2_InputGlobalVariableNames 13299
#define DISPID_IDtsDataPumpTask2_DataPumpOptions 13300
#define IOID_IDtsDataPumpTask2 L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000033F2}"
DEFINE_GUID(IID_IDtsDataPumpTask2,
0x3124b23b, 0xb5b4, 0x40c9, 0xa0, 0x8f, 0x44, 0x79, 0x7c, 0x77, 0xb2, 0xea);

#define DISPID_IDtsExecuteSQLTask2_InputGlobalVariableNames 13302
#define DISPID_IDtsExecuteSQLTask2_OutputGlobalVariableNames 13303
#define DISPID_IDtsExecuteSQLTask2_OutputAsRecordset 13304
#define IOID_IDtsExecuteSQLTask2 L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000033F5}"
DEFINE_GUID(IID_IDtsExecuteSQLTask2,
0xf2ddab1a, 0xbed4, 0x4844, 0x85, 0x20, 0x3f, 0x2e, 0xfe, 0xd4, 0x49, 0x83);

#define DISPID_IDtsTransformation2_TransformPhases 13306
#define IOID_IDtsTransformation2 L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000033F9}"
DEFINE_GUID(IID_IDtsTransformation2,
0xca173014, 0x640e, 0x45c6, 0x8b, 0xc3, 0x85, 0x11, 0x3f, 0x4d, 0xb3, 0x6d);

#define DISPID_IDtsScriptTransformation2_PreSourceDataFunctionEntry 13308
#define DISPID_IDtsScriptTransformation2_PostSourceDataFunctionEntry 13309
#define DISPID_IDtsScriptTransformation2_TransformFailureFunctionEntry 13310
#define DISPID_IDtsScriptTransformation2_InsertSuccessFunctionEntry 13311
#define DISPID_IDtsScriptTransformation2_InsertFailureFunctionEntry 13312
#define DISPID_IDtsScriptTransformation2_BatchCompleteFunctionEntry 13313
#define DISPID_IDtsScriptTransformation2_PumpCompleteFunctionEntry 13314
#define IOID_IDtsScriptTransformation2 L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},000033FB}"
DEFINE_GUID(IID_IDtsScriptTransformation2,
0xa40c0fd6, 0x54f5, 0x4d87, 0xa8, 0x5d, 0x05, 0xad, 0xe2, 0xed, 0x18, 0xb6);

#define DISPID_IDtsTransformationStep2_FailPackageOnError 13316
#define IOID_IDtsTransformationStep2 L"{{EBB9995C-BA15-11d1-901B-0000F87A3B33},00003403}"
DEFINE_GUID(IID_IDtsTransformationStep2,
0x9441f8d1, 0x245f, 0x429e, 0xaa, 0x99, 0x00, 0x82, 0xca, 0xfe, 0xd1, 0xb8);


#endif // __DTS_H_
