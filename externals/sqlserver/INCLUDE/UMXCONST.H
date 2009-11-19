
#ifndef __UMX_H_
#define __UMX_H_

#define OBJID_TYPELIB_UMX L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B58}"



#define OBJID_UmxAttribute L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B77}"
#define OBJID_UmxImport L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B78}"
#define OBJID_UmxModuleSpec L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B79}"
#define OBJID_UmxModuleOperation L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B7A}"
#define OBJID_UmxModule L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B7B}"
#define OBJID_UmxLibrary L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B7C}"
#define OBJID_UmxProjection L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B7D}"
#define OBJID_UmxAssociationRoleProjection L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B7E}"
#define OBJID_UmxRelationshipProjection L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B7F}"
#define OBJID_UmxLine L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B80}"
#define OBJID_UmxPoint L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B81}"
#define OBJID_UmxMultiplicityProjection L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B82}"
#define OBJID_UmxApplication L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B83}"
#define OBJID_UmxMemberVariable L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B8F}"
#define OBJID_UmxCall L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B95}"
#define OBJID_UmxProject L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B96}"
#define OBJID_UmxFile L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B97}"
#define OBJID_UmxVariantTaggedValue L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B9E}"
#define OBJID_UmxTaggedValue L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001BA2}"
#define OBJID_UmxTaggedValueSet L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001BA3}"
#define OBJID_UmxDerivation L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001BA8}"
#define DISPID_IUmxAttribute_IsNullable 7002
#define DISPID_IUmxAttribute_IsReadOnly 7003
#define DISPID_IUmxAttribute_IsConstant 7004
#define DISPID_IUmxAttribute_AverageLength 7056
#define DISPID_IUmxAttribute_MinimumLength 7057
#define DISPID_IUmxAttribute_OctetLength 7081
#define DISPID_IUmxAttribute_Length 7082
#define DISPID_IUmxAttribute_NumericScale 7083
#define DISPID_IUmxAttribute_NumericPrecision 7084
#define DISPID_IUmxAttribute_TimePrecision 7085
#define DISPID_IUmxAttribute_DerivedAttributes 7065
#define DISPID_IUmxAttribute_BasedAttributes 7066
#define IOID_IUmxAttribute L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B59}"
DEFINE_GUID(IID_IUmxAttribute,
0x30346487, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IUmxImport L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B5D}"
DEFINE_GUID(IID_IUmxImport,
0x30346488, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IUmxModuleSpec L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B5E}"
DEFINE_GUID(IID_IUmxModuleSpec,
0x30346489, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmxModuleOperation_EntryIDString 7008
#define DISPID_IUmxModuleOperation_EntryIDOrdinal 7009
#define DISPID_IUmxModuleOperation_Body 7067
#define IOID_IUmxModuleOperation L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B5F}"
DEFINE_GUID(IID_IUmxModuleOperation,
0x3034648a, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IUmxModule L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B62}"
DEFINE_GUID(IID_IUmxModule,
0x3034648b, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IUmxLibrary L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B63}"
DEFINE_GUID(IID_IUmxLibrary,
0x3034648c, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmxGraphicElement_BackgroundColor 7013
#define IOID_IUmxGraphicElement L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B64}"
DEFINE_GUID(IID_IUmxGraphicElement,
0x3034648d, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmxLine_Lines 7045
#define DISPID_IUmxLine_LineContainer 7046
#define IOID_IUmxLine L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B66}"
DEFINE_GUID(IID_IUmxLine,
0x3034648e, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmxLineContainer_Lines 7045
#define DISPID_IUmxLineContainer_LineContainer 7046
#define IOID_IUmxLineContainer L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B67}"
DEFINE_GUID(IID_IUmxLineContainer,
0x3034648f, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmxAssociationRoleProjection_MultiplicityProjection 7048
#define DISPID_IUmxAssociationRoleProjection_AssociationRoleProjection 7049
#define IOID_IUmxAssociationRoleProjection L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B68}"
DEFINE_GUID(IID_IUmxAssociationRoleProjection,
0x30346490, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmxFont_Name 7018
#define DISPID_IUmxFont_FontSize 7019
#define DISPID_IUmxFont_Style 7020
#define DISPID_IUmxFont_Color 7021
#define DISPID_IUmxFont_Alignment 7022
#define IOID_IUmxFont L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B69}"
DEFINE_GUID(IID_IUmxFont,
0x30346491, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmxPoint_Points 7051
#define DISPID_IUmxPoint_PointContainer 7052
#define IOID_IUmxPoint L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B6F}"
DEFINE_GUID(IID_IUmxPoint,
0x30346492, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmxPointContainer_Points 7051
#define DISPID_IUmxPointContainer_PointContainer 7052
#define IOID_IUmxPointContainer L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B70}"
DEFINE_GUID(IID_IUmxPointContainer,
0x30346493, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmxMultiplicityProjection_MultiplicityProjection 7048
#define DISPID_IUmxMultiplicityProjection_AssociationRoleProjection 7049
#define IOID_IUmxMultiplicityProjection L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B71}"
DEFINE_GUID(IID_IUmxMultiplicityProjection,
0x30346494, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmxLineProperties_Style 7027
#define DISPID_IUmxLineProperties_Width 7028
#define DISPID_IUmxLineProperties_Color 7029
#define IOID_IUmxLineProperties L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B72}"
DEFINE_GUID(IID_IUmxLineProperties,
0x30346495, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IUmxApplication L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B76}"
DEFINE_GUID(IID_IUmxApplication,
0x30346496, 0xee3d, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmxMemberVariable_Offset 7054
#define IOID_IUmxMemberVariable L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B8D}"
DEFINE_GUID(IID_IUmxMemberVariable,
0x3fe06f64, 0xef11, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IUmxProject L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B92}"
DEFINE_GUID(IID_IUmxProject,
0x8028d8e3, 0x25f9, 0x11d1, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IUmxFile L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B93}"
DEFINE_GUID(IID_IUmxFile,
0x8028d8e4, 0x25f9, 0x11d1, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IUmxCall L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B94}"
DEFINE_GUID(IID_IUmxCall,
0x8028d8e5, 0x25f9, 0x11d1, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmxVariantTaggedValue_VariantValue 7071
#define IOID_IUmxVariantTaggedValue L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001B9C}"
DEFINE_GUID(IID_IUmxVariantTaggedValue,
0xebb99948, 0xba15, 0x11d1, 0x90, 0x1b, 0x00, 0x00, 0xf8, 0x7a, 0x3b, 0x33);

#define DISPID_IUmxTaggedValueSet_TaggedValues 7077
#define DISPID_IUmxTaggedValueSet_TaggedValueSet 7078
#define IOID_IUmxTaggedValueSet L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001BA0}"
DEFINE_GUID(IID_IUmxTaggedValueSet,
0x25d705e2, 0xe48c, 0x11d1, 0xb0, 0x69, 0x00, 0x00, 0xf8, 0x7a, 0x57, 0xee);

#define DISPID_IUmxTaggedValue_TaggedValues 7077
#define DISPID_IUmxTaggedValue_TaggedValueSet 7078
#define IOID_IUmxTaggedValue L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001BA1}"
DEFINE_GUID(IID_IUmxTaggedValue,
0x25d705e3, 0xe48c, 0x11d1, 0xb0, 0x69, 0x00, 0x00, 0xf8, 0x7a, 0x57, 0xee);

#define IOID_IUmxDerivation L"{{30346485-EE3D-11d0-8E76-00A0C905A4DB},00001BA7}"
DEFINE_GUID(IID_IUmxDerivation,
0xd8264e1e, 0xeb69, 0x11d1, 0x90, 0x29, 0x00, 0x00, 0xf8, 0x7a, 0x3b, 0x33);


#endif // __UMX_H_
