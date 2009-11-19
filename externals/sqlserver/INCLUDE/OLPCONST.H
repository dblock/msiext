
#ifndef __OLP_H_
#define __OLP_H_

#define OBJID_TYPELIB_OLP L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F5F}"



#define OBJID_OlpField L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F79}"
#define OBJID_OlpDeployedCatalog L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F7A}"
#define OBJID_OlpVirtualCube L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F7B}"
#define OBJID_OlpAggregation L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F7C}"
#define OBJID_OlpDimLevel L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F7D}"
#define OBJID_OlpDimHierarchy L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F7E}"
#define OBJID_OlpPartition L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F7F}"
#define OBJID_OlpMeasure L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F80}"
#define OBJID_OlpDimension L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F82}"
#define OBJID_OlpFieldToFieldDerivation L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F84}"
#define OBJID_OlpMapping L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F85}"
#define OBJID_OlpPhysicalCube L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F87}"
#define OBJID_OlpJoinRole L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F89}"
#define OBJID_OlpMappingLevelPair L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F8A}"
#define OBJID_OlpLevel L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002FC5}"
#define DISPID_IOlpAggregation_OwnedAggregations 12172
#define DISPID_IOlpAggregation_OwningPartition 12173
#define IOID_IOlpAggregation L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F60}"
DEFINE_GUID(IID_IOlpAggregation,
0xc6fbc53f, 0x1044, 0x11d2, 0xb7, 0x90, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IOlpVirtualCube_UsedCubes 12212
#define DISPID_IOlpVirtualCube_UsingVirtualCubes 12213
#define IOID_IOlpVirtualCube L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F61}"
DEFINE_GUID(IID_IOlpVirtualCube,
0xc6fbc540, 0x1044, 0x11d2, 0xb7, 0x90, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IOlpPartition_IsWriteable 12228
#define DISPID_IOlpPartition_OwnedPartitions 12175
#define DISPID_IOlpPartition_OwningCube 12176
#define DISPID_IOlpPartition_OwnedAggregations 12172
#define DISPID_IOlpPartition_OwningPartition 12173
#define IOID_IOlpPartition L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F62}"
DEFINE_GUID(IID_IOlpPartition,
0xc6fbc541, 0x1044, 0x11d2, 0xb7, 0x90, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IOlpCube_UsedCubes 12212
#define DISPID_IOlpCube_UsingVirtualCubes 12213
#define IOID_IOlpCube L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F63}"
DEFINE_GUID(IID_IOlpCube,
0xc6fbc542, 0x1044, 0x11d2, 0xb7, 0x90, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IOlpDimLevel_Levels 12178
#define DISPID_IOlpDimLevel_Hierarchy 12179
#define DISPID_IOlpDimLevel_MappedLevel 12181
#define DISPID_IOlpDimLevel_Mappings 12182
#define DISPID_IOlpDimLevel_JoinRoles 12184
#define DISPID_IOlpDimLevel_DimensionLevel 12185
#define DISPID_IOlpDimLevel_MemberKeyField 12216
#define DISPID_IOlpDimLevel_KeyedLevels 12217
#define DISPID_IOlpDimLevel_MemberNameField 12219
#define DISPID_IOlpDimLevel_NamedLevels 12220
#define IOID_IOlpDimLevel L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F64}"
DEFINE_GUID(IID_IOlpDimLevel,
0xc6fbc543, 0x1044, 0x11d2, 0xb7, 0x90, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IOlpDimHierarchy_Levels 12178
#define DISPID_IOlpDimHierarchy_Hierarchy 12179
#define DISPID_IOlpDimHierarchy_Mappings 12187
#define IOID_IOlpDimHierarchy L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F66}"
DEFINE_GUID(IID_IOlpDimHierarchy,
0xc6fbc544, 0x1044, 0x11d2, 0xb7, 0x90, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define IOID_IOlpMeasure L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F69}"
DEFINE_GUID(IID_IOlpMeasure,
0xc6fbc545, 0x1044, 0x11d2, 0xb7, 0x90, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IOlpStore_OlapMode 12140
#define DISPID_IOlpStore_JoinClause 12141
#define DISPID_IOlpStore_Mappings 12196
#define DISPID_IOlpStore_Store 12197
#define IOID_IOlpStore L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F6A}"
DEFINE_GUID(IID_IOlpStore,
0xc6fbc546, 0x1044, 0x11d2, 0xb7, 0x90, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IOlpField_MemberKeyField 12216
#define DISPID_IOlpField_KeyedLevels 12217
#define DISPID_IOlpField_MemberNameField 12219
#define DISPID_IOlpField_NamedLevels 12220
#define DISPID_IOlpField_KeyedMLPs 12223
#define IOID_IOlpField L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F6E}"
DEFINE_GUID(IID_IOlpField,
0xc6fbc547, 0x1044, 0x11d2, 0xb7, 0x90, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define IOID_IOlpCatalog L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F6F}"
DEFINE_GUID(IID_IOlpCatalog,
0xc6fbc548, 0x1044, 0x11d2, 0xb7, 0x90, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IOlpDimension_IsTime 12135
#define DISPID_IOlpDimension_DimensionType 12136
#define IOID_IOlpDimension L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F71}"
DEFINE_GUID(IID_IOlpDimension,
0xc6fbc54a, 0x1044, 0x11d2, 0xb7, 0x90, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IOlpMapping_Mappings 12196
#define DISPID_IOlpMapping_Store 12197
#define DISPID_IOlpMapping_Hierarchy 12188
#define DISPID_IOlpMapping_MappedLevels 12202
#define DISPID_IOlpMapping_Mapping 12203
#define IOID_IOlpMapping L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F72}"
DEFINE_GUID(IID_IOlpMapping,
0xc6fbc54b, 0x1044, 0x11d2, 0xb7, 0x90, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define IOID_IOlpFieldToFieldDerivation L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F73}"
DEFINE_GUID(IID_IOlpFieldToFieldDerivation,
0xc6fbc54c, 0x1044, 0x11d2, 0xb7, 0x90, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IOlpMappingLevelPair_IsDisabled 12214
#define DISPID_IOlpMappingLevelPair_MappedLevels 12202
#define DISPID_IOlpMappingLevelPair_Mapping 12203
#define DISPID_IOlpMappingLevelPair_MappedLevel 12181
#define DISPID_IOlpMappingLevelPair_Mappings 12182
#define DISPID_IOlpMappingLevelPair_MemberKeyField 12222
#define DISPID_IOlpMappingLevelPair_KeyedMLPs 12223
#define IOID_IOlpMappingLevelPair L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F74}"
DEFINE_GUID(IID_IOlpMappingLevelPair,
0xc6fbc54d, 0x1044, 0x11d2, 0xb7, 0x90, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IOlpPhysicalCube_OwnedPartitions 12175
#define DISPID_IOlpPhysicalCube_OwningCube 12176
#define IOID_IOlpPhysicalCube L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F75}"
DEFINE_GUID(IID_IOlpPhysicalCube,
0xc6fbc54e, 0x1044, 0x11d2, 0xb7, 0x90, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IOlpJoinRole_JoinRoles 12184
#define DISPID_IOlpJoinRole_DimensionLevel 12185
#define IOID_IOlpJoinRole L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002F78}"
DEFINE_GUID(IID_IOlpJoinRole,
0xc6fbc551, 0x1044, 0x11d2, 0xb7, 0x90, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IOlpLevel_MemberNameColumn 12224
#define DISPID_IOlpLevel_MemberKeyColumn 12225
#define IOID_IOlpLevel L"{{C6FBC53D-1044-11d2-B790-00C04F8EF296},00002FC3}"
DEFINE_GUID(IID_IOlpLevel,
0x3a5ef246, 0xca2d, 0x4948, 0xab, 0x51, 0x55, 0x28, 0x3b, 0x36, 0x71, 0x0c);


#endif // __OLP_H_
