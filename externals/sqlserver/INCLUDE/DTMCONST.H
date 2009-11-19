
#ifndef __DTM_H_
#define __DTM_H_

#define OBJID_TYPELIB_DTM L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007D0}"



#define OBJID_DtmNumeric L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007F5}"
#define OBJID_DtmString L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007F6}"
#define OBJID_DtmBinary L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007F7}"
#define OBJID_DtmFloat L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007F8}"
#define OBJID_DtmBoolean L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007F9}"
#define OBJID_DtmDate L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007FA}"
#define OBJID_DtmTime L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007FB}"
#define OBJID_DtmDatetime L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007FC}"
#define OBJID_DtmAlias L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007FD}"
#define OBJID_DtmEnumeration L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007FE}"
#define OBJID_DtmPointer L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007FF}"
#define OBJID_DtmArray L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},00000800}"
#define OBJID_DtmUnion L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},00000801}"
#define OBJID_DtmStructure L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},00000802}"
#define OBJID_DtmUnionMember L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},00000803}"
#define OBJID_DtmCollectionType L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},00000804}"
#define OBJID_DtmVoid L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},00000805}"
#define OBJID_DtmDecimal L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},00000820}"
#define OBJID_DtmInteger L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},00000821}"
#define OBJID_DtmTinyInt L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},00000822}"
#define OBJID_DtmShortInt L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},00000823}"
#define OBJID_DtmLongInt L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},00000824}"
#define OBJID_DtmQuadInt L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},00000825}"
#define OBJID_DtmDouble L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},00000826}"
#define OBJID_DtmSingle L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},00000827}"
#define OBJID_DtmObjectTypeMapping L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},0000082F}"
#define DISPID_IDtmNumeric_NumericScale 2002
#define DISPID_IDtmNumeric_NumericPrecision 2003
#define DISPID_IDtmNumeric_IsSigned 2004
#define IOID_IDtmNumeric L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007D1}"
DEFINE_GUID(IID_IDtmNumeric,
0x303464b6, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IDtmString_IsVariable 2006
#define DISPID_IDtmString_Length 2007
#define DISPID_IDtmString_IsCaseSensitive 2008
#define DISPID_IDtmString_CharacterType 2069
#define IOID_IDtmString L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007D5}"
DEFINE_GUID(IID_IDtmString,
0x303464b7, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IDtmEnumeration_Type 2055
#define DISPID_IDtmEnumeration_Enumerations 2056
#define IOID_IDtmEnumeration L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007D9}"
DEFINE_GUID(IID_IDtmEnumeration,
0x303464b8, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IDtmBinary_Length 2011
#define DISPID_IDtmBinary_IsVariable 2012
#define IOID_IDtmBinary L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007DA}"
DEFINE_GUID(IID_IDtmBinary,
0x303464b9, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IDtmScalar L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007DD}"
DEFINE_GUID(IID_IDtmScalar,
0x303464ba, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IDtmBoolean L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007DE}"
DEFINE_GUID(IID_IDtmBoolean,
0x303464bb, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IDtmDate L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007DF}"
DEFINE_GUID(IID_IDtmDate,
0x303464bc, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IDtmFloat_FloatPrecision 2017
#define IOID_IDtmFloat L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007E0}"
DEFINE_GUID(IID_IDtmFloat,
0x303464bd, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IDtmTime_TimePrecision 2019
#define IOID_IDtmTime L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007E2}"
DEFINE_GUID(IID_IDtmTime,
0x303464be, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IDtmDatetime L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007E4}"
DEFINE_GUID(IID_IDtmDatetime,
0x303464bf, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IDtmAlias_Type 2058
#define DISPID_IDtmAlias_Aliases 2059
#define IOID_IDtmAlias L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007E5}"
DEFINE_GUID(IID_IDtmAlias,
0x303464c0, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IDtmObjectType_Type 2058
#define DISPID_IDtmObjectType_Aliases 2059
#define DISPID_IDtmObjectType_Pointers 2062
#define DISPID_IDtmObjectType_Collections 2065
#define DISPID_IDtmObjectType_Enumerations 2056
#define DISPID_IDtmObjectType_SwitchType 2067
#define DISPID_IDtmObjectType_UnionsForWhichSwitchType 2068
#define DISPID_IDtmObjectType_Types 2090
#define DISPID_IDtmObjectType_Namespace 2091
#define DISPID_IDtmObjectType_ExposedMappings 2103
#define DISPID_IDtmObjectType_UnderlyingType 2104
#define DISPID_IDtmObjectType_UnderlyingMappings 2106
#define DISPID_IDtmObjectType_ExposedType 2107
#define IOID_IDtmObjectType L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007E6}"
DEFINE_GUID(IID_IDtmObjectType,
0x303464c1, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IDtmPointer_Type 2061
#define DISPID_IDtmPointer_Pointers 2062
#define IOID_IDtmPointer L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007E7}"
DEFINE_GUID(IID_IDtmPointer,
0x303464c2, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IDtmCollectionType_UpperBound 2025
#define DISPID_IDtmCollectionType_IsSequenced 2026
#define DISPID_IDtmCollectionType_IsNamed 2027
#define DISPID_IDtmCollectionType_Type 2064
#define DISPID_IDtmCollectionType_Collections 2065
#define IOID_IDtmCollectionType L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007E8}"
DEFINE_GUID(IID_IDtmCollectionType,
0x303464c3, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IDtmArray_LowerBound 2029
#define IOID_IDtmArray L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007EC}"
DEFINE_GUID(IID_IDtmArray,
0x303464c4, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IDtmUnion_SwitchType 2067
#define DISPID_IDtmUnion_UnionsForWhichSwitchType 2068
#define IOID_IDtmUnion L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007EE}"
DEFINE_GUID(IID_IDtmUnion,
0x303464c5, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IDtmIntrinsicType_OctetLength 2070
#define DISPID_IDtmIntrinsicType_StorageExpression 2071
#define IOID_IDtmIntrinsicType L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007EF}"
DEFINE_GUID(IID_IDtmIntrinsicType,
0x303464c6, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IDtmStructure L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007F0}"
DEFINE_GUID(IID_IDtmStructure,
0x303464c7, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IDtmUnionMember_MemberCase 2034
#define DISPID_IDtmUnionMember_IsDefault 2035
#define IOID_IDtmUnionMember L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007F1}"
DEFINE_GUID(IID_IDtmUnionMember,
0x303464c8, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IDtmVoid L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},000007F4}"
DEFINE_GUID(IID_IDtmVoid,
0x303464c9, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IDtmInteger L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},00000818}"
DEFINE_GUID(IID_IDtmInteger,
0x98e70883, 0x29cc, 0x11d1, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IDtmShortInt L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},00000819}"
DEFINE_GUID(IID_IDtmShortInt,
0x98e70884, 0x29cc, 0x11d1, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IDtmDecimal L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},0000081A}"
DEFINE_GUID(IID_IDtmDecimal,
0x98e70885, 0x29cc, 0x11d1, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IDtmQuadInt L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},0000081B}"
DEFINE_GUID(IID_IDtmQuadInt,
0x98e70886, 0x29cc, 0x11d1, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IDtmLongInt L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},0000081C}"
DEFINE_GUID(IID_IDtmLongInt,
0x98e70887, 0x29cc, 0x11d1, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IDtmTinyInt L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},0000081D}"
DEFINE_GUID(IID_IDtmTinyInt,
0x98e70888, 0x29cc, 0x11d1, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IDtmSingle L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},0000081E}"
DEFINE_GUID(IID_IDtmSingle,
0x98e70889, 0x29cc, 0x11d1, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IDtmDouble L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},0000081F}"
DEFINE_GUID(IID_IDtmDouble,
0x98e7088a, 0x29cc, 0x11d1, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IDtmNamespace_Version 2092
#define DISPID_IDtmNamespace_Types 2090
#define DISPID_IDtmNamespace_Namespace 2091
#define IOID_IDtmNamespace L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},00000828}"
DEFINE_GUID(IID_IDtmNamespace,
0x8d593d6a, 0x2002, 0x11d2, 0xb7, 0x99, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IDtmObjectTypeMapping_BestMatch 2094
#define DISPID_IDtmObjectTypeMapping_ExposedMappings 2103
#define DISPID_IDtmObjectTypeMapping_UnderlyingType 2104
#define DISPID_IDtmObjectTypeMapping_UnderlyingMappings 2106
#define DISPID_IDtmObjectTypeMapping_ExposedType 2107
#define IOID_IDtmObjectTypeMapping L"{{303464B4-EE3D-11d0-8E76-00A0C905A4DB},0000082D}"
DEFINE_GUID(IID_IDtmObjectTypeMapping,
0x73ecf812, 0x20f2, 0x11d2, 0xb7, 0x9b, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);


#endif // __DTM_H_
