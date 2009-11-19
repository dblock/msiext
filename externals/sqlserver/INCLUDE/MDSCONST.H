
#ifndef __MDS_H_
#define __MDS_H_

#define OBJID_TYPELIB_MDS L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},000036B4}"



#define OBJID_MdsDimLevel L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},000036C9}"
#define OBJID_MdsDimHierarchy L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},000036CA}"
#define OBJID_MdsMeasure L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},000036CB}"
#define OBJID_MdsPartition L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},000036CC}"
#define OBJID_MdsCube L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},000036CF}"
#define OBJID_MdsAggregation L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},000036D0}"
#define OBJID_MdsDimension L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},000036E9}"
#define OBJID_MdsPhysicalCube L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},000036EC}"
#define OBJID_MdsVirtualCube L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},000036ED}"
#define OBJID_MdsDatasource L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},00003705}"
#define OBJID_MdsDatabase L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},00003725}"
#define OBJID_MdsCubeDimension L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},00003726}"
#define OBJID_MdsAggregationDimension L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},00003727}"
#define OBJID_MdsPartitionDimension L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},00003728}"
#define OBJID_MdsCubeLevel L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},00003729}"
#define OBJID_MdsPartitionLevel L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},0000372A}"
#define OBJID_MdsAggregationLevel L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},0000372B}"
#define OBJID_MdsServer L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},00003735}"
#define OBJID_MdsMemberProperty L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},00003768}"
#define OBJID_MdsRole L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},00003795}"
#define OBJID_MdsCommand L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},00003796}"
#define OBJID_MdsColumn L"{{B101373A-D760-4297-AA04-9FC34367F65D},0007A14C}"
#define OBJID_MdsMiningModel L"{{B101373A-D760-4297-AA04-9FC34367F65D},0007A14B}"
#define OBJID_MdsCustomProperty L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},000037C3}"
#define DISPID_IMdsStore_SourceTableFilter 14006
#define DISPID_IMdsStore_SourceTable 14134
#define DISPID_IMdsStore_IsDefault 14007
#define DISPID_IMdsStore_FromClause 14089
#define DISPID_IMdsStore_LastUpdated 14090
#define DISPID_IMdsStore_AggregationPrefix 14128
#define DISPID_IMdsStore_AllowDrillThrough 14147
#define DISPID_IMdsStore_ApplicationURL 14148
#define DISPID_IMdsStore_ConnectionURL 14149
#define DISPID_IMdsStore_DrillThroughColumns 14150
#define DISPID_IMdsStore_DrillThroughFilter 14151
#define DISPID_IMdsStore_DrillThroughFrom 14152
#define DISPID_IMdsStore_DrillThroughJoins 14153
#define DISPID_IMdsStore_InformationURL 14154
#define DISPID_IMdsStore_IsIndexingComplete 14155
#define DISPID_IMdsStore_IsVisible 14156
#define DISPID_IMdsStore_RemoteServer 14185
#define DISPID_IMdsStore_SourceTableAlias 14186
#define DISPID_IMdsStore_DefaultMeasure 14187
#define DISPID_IMdsStore_ProcessingKeyErrorLimit 14251
#define DISPID_IMdsStore_ProcessingKeyErrorLogFileName 14252
#define DISPID_IMdsStore_ProcessOptimizationMode 14253
#define DISPID_IMdsStore_EnableRealTimeUpdates 14277
#define DISPID_IMdsStore_Datasources 14087
#define DISPID_IMdsStore_Stores 14088
#define IOID_IMdsStore L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},000036B5}"
DEFINE_GUID(IID_IMdsStore,
0x265e2f81, 0xffa8, 0x11d1, 0xb7, 0x7c, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IMdsDimLevel_LevelType 14009
#define DISPID_IMdsDimLevel_IsUnique 14011
#define DISPID_IMdsDimLevel_Ordering 14070
#define DISPID_IMdsDimLevel_ColumnSize 14071
#define DISPID_IMdsDimLevel_ColumnType 14072
#define DISPID_IMdsDimLevel_IsAll 14073
#define DISPID_IMdsDimLevel_ActualSize 14074
#define IOID_IMdsDimLevel L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},000036B8}"
DEFINE_GUID(IID_IMdsDimLevel,
0x265e2f82, 0xffa8, 0x11d1, 0xb7, 0x7c, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IMdsDimHierarchy_IsShared 14013
#define IOID_IMdsDimHierarchy L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},000036BC}"
DEFINE_GUID(IID_IMdsDimHierarchy,
0x265e2f83, 0xffa8, 0x11d1, 0xb7, 0x7c, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IMdsMeasure_FormatString 14015
#define DISPID_IMdsMeasure_IsInternal 14016
#define DISPID_IMdsMeasure_SourceColumn 14136
#define DISPID_IMdsMeasure_SourceColumnType 14137
#define DISPID_IMdsMeasure_SourceName 14211
#define DISPID_IMdsMeasure_IsVisible 14157
#define DISPID_IMdsMeasure_ColumnType 14212
#define DISPID_IMdsMeasure_Format 14213
#define DISPID_IMdsMeasure_Num 14238
#define DISPID_IMdsMeasure_AggregationFunction 14245
#define IOID_IMdsMeasure L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},000036BE}"
DEFINE_GUID(IID_IMdsMeasure,
0x265e2f84, 0xffa8, 0x11d1, 0xb7, 0x7c, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IMdsPartition_AggregationSize 14138
#define DISPID_IMdsPartition_FactTableSize 14139
#define DISPID_IMdsPartition_FactTable 14140
#define IOID_IMdsPartition L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},000036C1}"
DEFINE_GUID(IID_IMdsPartition,
0x265e2f85, 0xffa8, 0x11d1, 0xb7, 0x7c, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IMdsCube_DefaultFactTableSize 14091
#define DISPID_IMdsCube_DefaultFactTable 14124
#define DISPID_IMdsCube_SecurityRoles 14240
#define DISPID_IMdsCube_cubes 14241
#define IOID_IMdsCube L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},000036C5}"
DEFINE_GUID(IID_IMdsCube,
0x265e2f88, 0xffa8, 0x11d1, 0xb7, 0x7c, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IMdsAggregation_GroupByClause 14038
#define DISPID_IMdsAggregation_AggNum 14141
#define DISPID_IMdsAggregation_DatasetName 14146
#define IOID_IMdsAggregation L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},000036C7}"
DEFINE_GUID(IID_IMdsAggregation,
0x265e2f8a, 0xffa8, 0x11d1, 0xb7, 0x7c, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IMdsDimension_IsShared 14056
#define DISPID_IMdsDimension_DimensionNum 14080
#define DISPID_IMdsDimension_FromClause 14081
#define DISPID_IMdsDimension_JoinClause 14082
#define DISPID_IMdsDimension_LastUpdated 14083
#define DISPID_IMdsDimension_AreMemberKeysUnique 14158
#define DISPID_IMdsDimension_AreMemberNamesUnique 14159
#define DISPID_IMdsDimension_DefaultMember 14160
#define DISPID_IMdsDimension_DependsOnDimension 14161
#define DISPID_IMdsDimension_IsReadWrite 14162
#define DISPID_IMdsDimension_IsChanging 14163
#define DISPID_IMdsDimension_IsRelatedToFactTable 14164
#define DISPID_IMdsDimension_IsVisible 14165
#define DISPID_IMdsDimension_IsVirtual 14166
#define DISPID_IMdsDimension_SourceTableFilter 14167
#define DISPID_IMdsDimension_StorageMode 14168
#define DISPID_IMdsDimension_EnableRealTimeUpdates 14278
#define DISPID_IMdsDimension_AllowSiblingsWithSameName 14188
#define DISPID_IMdsDimension_DataMemberCaptionTemplate 14189
#define DISPID_IMdsDimension_MembersWithData 14190
#define DISPID_IMdsDimension_SourceTableAlias 14191
#define DISPID_IMdsDimension_DimensionTable 14214
#define DISPID_IMdsDimension_AggregationUsage 14231
#define DISPID_IMdsDimension_Datasource 14144
#define DISPID_IMdsDimension_Dimensions 14145
#define IOID_IMdsDimension L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},000036E7}"
DEFINE_GUID(IID_IMdsDimension,
0x5c86286e, 0x1829, 0x11d2, 0xbc, 0xd9, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x82);

#define IOID_IMdsPhysicalCube L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},000036EA}"
DEFINE_GUID(IID_IMdsPhysicalCube,
0x687b75b4, 0x1a83, 0x11d2, 0xbc, 0xd9, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x82);

#define IOID_IMdsVirtualCube L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},000036EB}"
DEFINE_GUID(IID_IMdsVirtualCube,
0x687b75b5, 0x1a83, 0x11d2, 0xbc, 0xd9, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x82);

#define DISPID_IMdsDatasource_AutoConnect 14077
#define DISPID_IMdsDatasource_ConnectionType 14078
#define DISPID_IMdsDatasource_Datasources 14087
#define DISPID_IMdsDatasource_Stores 14088
#define DISPID_IMdsDatasource_Datasource 14144
#define DISPID_IMdsDatasource_Dimensions 14145
#define DISPID_IMdsDatasource_MiningModel 14269
#define IOID_IMdsDatasource L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},000036FC}"
DEFINE_GUID(IID_IMdsDatasource,
0x4b2e3306, 0xc139, 0x11d2, 0xb8, 0x32, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IMdsCommon_SubClassType 14075
#define DISPID_IMdsCommon_Version 14142
#define DISPID_IMdsCommon_ID 14247
#define IOID_IMdsCommon L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},00003704}"
DEFINE_GUID(IID_IMdsCommon,
0x4b2e3307, 0xc139, 0x11d2, 0xb8, 0x32, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IMdsDatabase_SecurityRoles 14243
#define DISPID_IMdsDatabase_databases 14244
#define IOID_IMdsDatabase L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},0000370C}"
DEFINE_GUID(IID_IMdsDatabase,
0xaf79c7ec, 0xc50d, 0x11d2, 0xb8, 0x36, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IMdsCubeDimension_DimTable 14097
#define IOID_IMdsCubeDimension L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},0000370D}"
DEFINE_GUID(IID_IMdsCubeDimension,
0xaf79c7ed, 0xc50d, 0x11d2, 0xb8, 0x36, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define IOID_IMdsAggregationDimension L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},00003712}"
DEFINE_GUID(IID_IMdsAggregationDimension,
0xaf79c7ee, 0xc50d, 0x11d2, 0xb8, 0x36, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define IOID_IMdsPartitionDimension L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},00003715}"
DEFINE_GUID(IID_IMdsPartitionDimension,
0xaf79c7ef, 0xc50d, 0x11d2, 0xb8, 0x36, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IMdsCubeLevel_EnableAggregation 14108
#define IOID_IMdsCubeLevel L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},00003716}"
DEFINE_GUID(IID_IMdsCubeLevel,
0xaf79c7f0, 0xc50d, 0x11d2, 0xb8, 0x36, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define IOID_IMdsPartitionLevel L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},0000371D}"
DEFINE_GUID(IID_IMdsPartitionLevel,
0xaf79c7f1, 0xc50d, 0x11d2, 0xb8, 0x36, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define IOID_IMdsAggregationLevel L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},00003721}"
DEFINE_GUID(IID_IMdsAggregationLevel,
0xaf79c7f2, 0xc50d, 0x11d2, 0xb8, 0x36, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IMdsServer_Timeout 14131
#define DISPID_IMdsServer_RepositoryVersion 14132
#define DISPID_IMdsServer_ApplicationURL 14169
#define DISPID_IMdsServer_InformationURL 14170
#define DISPID_IMdsServer_ConnectionURL 14171
#define DISPID_IMdsServer_ServiceUserName 14246
#define DISPID_IMdsServer_ProcessingLogFileName 14280
#define IOID_IMdsServer L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},00003732}"
DEFINE_GUID(IID_IMdsServer,
0x4ce6c52, 0xcaa4, 0x11d2, 0xb8, 0x3a, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IMdsMemberProperty_Caption 14173
#define DISPID_IMdsMemberProperty_ClassType 14174
#define DISPID_IMdsMemberProperty_SubClassType 14175
#define DISPID_IMdsMemberProperty_OrdinalPosition 14176
#define DISPID_IMdsMemberProperty_Parent 14177
#define DISPID_IMdsMemberProperty_SourceColumn 14178
#define DISPID_IMdsMemberProperty_ColumnSize 14179
#define DISPID_IMdsMemberProperty_ColumnType 14180
#define DISPID_IMdsMemberProperty_IsVisible 14181
#define DISPID_IMdsMemberProperty_Language 14182
#define DISPID_IMdsMemberProperty_PropertyType 14183
#define DISPID_IMdsMemberProperty_Num 14215
#define IOID_IMdsMemberProperty L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},0000375C}"
DEFINE_GUID(IID_IMdsMemberProperty,
0xaa5b958e, 0x1cfd, 0x11d3, 0xb2, 0x18, 0x00, 0xc0, 0x4f, 0x68, 0x6c, 0x16);

#define DISPID_IMdsLevel_FromClause 14194
#define DISPID_IMdsLevel_JoinClause 14195
#define DISPID_IMdsLevel_LevelNum 14196
#define DISPID_IMdsLevel_AreMemberKeysUnique 14197
#define DISPID_IMdsLevel_AreMemberNamesUnique 14198
#define DISPID_IMdsLevel_CustomRollupColumn 14199
#define DISPID_IMdsLevel_CustomRollupExpression 14200
#define DISPID_IMdsLevel_Disabled 14216
#define DISPID_IMdsLevel_GroupBoundaries 14201
#define DISPID_IMdsLevel_Grouping 14202
#define DISPID_IMdsLevel_GroupNames 14203
#define DISPID_IMdsLevel_EnableAggregations 14217
#define DISPID_IMdsLevel_HideMemberIf 14204
#define DISPID_IMdsLevel_IsVisible 14205
#define DISPID_IMdsLevel_LevelNamingTemplate 14206
#define DISPID_IMdsLevel_OrderingMemberProperty 14207
#define DISPID_IMdsLevel_ParentKeyColumn 14208
#define DISPID_IMdsLevel_RootMemberIf 14209
#define DISPID_IMdsLevel_SliceValue 14219
#define DISPID_IMdsLevel_SkippedLevelsColumn 14210
#define DISPID_IMdsLevel_UnaryOperatorColumn 14254
#define DISPID_IMdsLevel_CustomRollupPropertiesColumn 14279
#define IOID_IMdsLevel L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},00003770}"
DEFINE_GUID(IID_IMdsLevel,
0xa4780e40, 0x8148, 0x4933, 0x9c, 0xe9, 0xec, 0x15, 0xb6, 0x23, 0xcb, 0x66);

#define DISPID_IMdsCommand_CommandType 14221
#define DISPID_IMdsCommand_Num 14223
#define DISPID_IMdsCommand_CommandText 14276
#define DISPID_IMdsCommand_Commands 14249
#define DISPID_IMdsCommand_SecurityRoles 14250
#define IOID_IMdsCommand L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},0000378C}"
DEFINE_GUID(IID_IMdsCommand,
0xdfb4a1a0, 0xdb58, 0x43f2, 0xb3, 0xd8, 0x72, 0xcd, 0xec, 0xea, 0xc2, 0xfa);

#define DISPID_IMdsRole_Permissions 14228
#define DISPID_IMdsRole_UsersList 14237
#define DISPID_IMdsRole_SecurityRoles 14240
#define DISPID_IMdsRole_cubes 14241
#define DISPID_IMdsRole_databases 14244
#define DISPID_IMdsRole_Commands 14249
#define DISPID_IMdsRole_MiningModels 500047
#define IOID_IMdsRole L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},00003792}"
DEFINE_GUID(IID_IMdsRole,
0x8164f8bc, 0x28f6, 0x4cb0, 0x9d, 0x94, 0x65, 0x5e, 0x01, 0x15, 0x09, 0x56);

#define DISPID_IMdsMiningModel_LastProcessed 500003
#define DISPID_IMdsMiningModel_LastUpdated 500004
#define DISPID_IMdsMiningModel_IsVisible 500005
#define DISPID_IMdsMiningModel_MiningAlgorithm 500006
#define DISPID_IMdsMiningModel_TrainingQuery 500007
#define DISPID_IMdsMiningModel_XML 500008
#define DISPID_IMdsMiningModel_FromClause 500030
#define DISPID_IMdsMiningModel_JoinClause 500031
#define DISPID_IMdsMiningModel_Filter 500032
#define DISPID_IMdsMiningModel_CaseLevel 500026
#define DISPID_IMdsMiningModel_CaseDimension 500027
#define DISPID_IMdsMiningModel_SourceCube 500028
#define DISPID_IMdsMiningModel_AlgorithmParameters 14266
#define DISPID_IMdsMiningModel_AreKeysUnique 14270
#define DISPID_IMdsMiningModel_SecurityRoles 500046
#define DISPID_IMdsMiningModel_MiningModels 500047
#define DISPID_IMdsMiningModel_Datasource 14268
#define DISPID_IMdsMiningModel_MiningModel 14269
#define IOID_IMdsMiningModel L"{{B101373A-D760-4297-AA04-9FC34367F65D},0007A121}"
DEFINE_GUID(IID_IMdsMiningModel,
0x2ac433da, 0x52e8, 0x40d3, 0xa4, 0x20, 0xac, 0x99, 0x2c, 0xeb, 0x2e, 0xc0);

#define DISPID_IMdsColumn_Parent 500012
#define DISPID_IMdsColumn_IsKey 14256
#define DISPID_IMdsColumn_IsParentKey 14257
#define DISPID_IMdsColumn_IsVisible 500013
#define DISPID_IMdsColumn_Distribution 500021
#define DISPID_IMdsColumn_IsDisabled 500035
#define DISPID_IMdsColumn_JoinClause 500038
#define DISPID_IMdsColumn_FromClause 500037
#define DISPID_IMdsColumn_Filter 500039
#define DISPID_IMdsColumn_SourceColumn 500015
#define DISPID_IMdsColumn_IsPredictable 500023
#define DISPID_IMdsColumn_IsInput 500022
#define DISPID_IMdsColumn_RelatedColumn 500019
#define DISPID_IMdsColumn_ColumnDataType 500017
#define DISPID_IMdsColumn_ContentType 500020
#define DISPID_IMdsColumn_SpecialFlag 14255
#define DISPID_IMdsColumn_ModelingFlags 14260
#define DISPID_IMdsColumn_SourceObjectClassType 14261
#define DISPID_IMdsColumn_SourceObjectMeasure 14262
#define DISPID_IMdsColumn_SourceObjectDimension 14263
#define DISPID_IMdsColumn_SourceObjectLevel 14264
#define DISPID_IMdsColumn_SourceObjectMemberProperty 14265
#define DISPID_IMdsColumn_AreKeysUnique 14271
#define DISPID_IMdsColumn_ColumnNum 14272
#define IOID_IMdsColumn L"{{B101373A-D760-4297-AA04-9FC34367F65D},0007A129}"
DEFINE_GUID(IID_IMdsColumn,
0xc52843da, 0x7bee, 0x485b, 0xb6, 0x44, 0x57, 0xf5, 0x2b, 0x5d, 0x1b, 0xb8);

#define DISPID_IMdsCustomProperty_CustomProperty 14274
#define IOID_IMdsCustomProperty L"{{265E2F7F-FFA8-11d1-B77C-00C04F8EF296},000037C1}"
DEFINE_GUID(IID_IMdsCustomProperty,
0xbebc0ecc, 0x6ab9, 0x4cb1, 0xb0, 0x4c, 0x90, 0xf8, 0x93, 0x2f, 0x84, 0xd4);


#endif // __MDS_H_
