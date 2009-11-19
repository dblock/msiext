
#ifndef __UML_H_
#define __UML_H_

#define OBJID_TYPELIB_UML L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000001}"



#define OBJID_UmlModel L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000002}"
#define OBJID_UmlPackage L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000003}"
#define OBJID_UmlSystem L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000005}"
#define OBJID_UmlReference L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000115}"
#define OBJID_UmlDependency L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000042}"
#define OBJID_UmlStereotype L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000043}"
#define OBJID_UmlNote L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000044}"
#define OBJID_UmlConstraint L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000045}"
#define OBJID_UmlTaggedValue L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000046}"
#define OBJID_UmlRefinement L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},0000011C}"
#define OBJID_UmlPrimitiveType L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000059}"
#define OBJID_UmlInstance L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},0000005A}"
#define OBJID_UmlValue L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},0000005C}"
#define OBJID_UmlUseCase L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000124}"
#define OBJID_UmlSignal L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000125}"
#define OBJID_UmlResponsibility L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000001C1}"
#define OBJID_UmlAssociationRole L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000079}"
#define OBJID_UmlAssociation L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},0000007A}"
#define OBJID_UmlGeneralization L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},0000007B}"
#define OBJID_UmlType L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000A4}"
#define OBJID_UmlAttribute L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000A5}"
#define OBJID_UmlOperation L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000A6}"
#define OBJID_UmlParameter L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000A7}"
#define OBJID_UmlSignalReference L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000137}"
#define OBJID_UmlName L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000139}"
#define OBJID_UmlClass L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000D9}"
#define OBJID_UmlActiveClass L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000DA}"
#define OBJID_UmlComponent L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000DB}"
#define OBJID_UmlNode L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000DC}"
#define OBJID_UmlMethod L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000DD}"
#define OBJID_UmlProjection L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000EA}"
#define OBJID_UmlClassDiagram L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000EB}"
#define OBJID_UmlComponentDiagram L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000EC}"
#define OBJID_UmlPoint L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000153}"
#define DISPID_IUmlSystem_System 18
#define DISPID_IUmlSystem_Models 19
#define DISPID_IUmlSystem_SuperSystem 21
#define DISPID_IUmlSystem_SubSystems 22
#define DISPID_IUmlSystem_Dependencies 25
#define DISPID_IUmlSystem_Stereotypes 28
#define IOID_IUmlSystem L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000010}"
DEFINE_GUID(IID_IUmlSystem,
0xd9e5df0, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlModel_System 18
#define DISPID_IUmlModel_Models 19
#define DISPID_IUmlModel_Packages 31
#define DISPID_IUmlModel_Model 32
#define IOID_IUmlModel L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},0000001D}"
DEFINE_GUID(IID_IUmlModel,
0xd9e5df1, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlPackage_Packages 31
#define DISPID_IUmlPackage_Model 32
#define DISPID_IUmlPackage_Package 35
#define DISPID_IUmlPackage_Elements 36
#define DISPID_IUmlPackage_ReferencingPackage 354
#define DISPID_IUmlPackage_ReferencedReferences 355
#define IOID_IUmlPackage L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000021}"
DEFINE_GUID(IID_IUmlPackage,
0xd9e5df2, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlViewElement_ViewElement 39
#define DISPID_IUmlViewElement_Projections 40
#define IOID_IUmlViewElement L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000025}"
DEFINE_GUID(IID_IUmlViewElement,
0xd9e5df3, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlModelElement_RefinedElement 363
#define DISPID_IUmlModelElement_RefiningElementRefinements 364
#define DISPID_IUmlModelElement_RefiningElement 366
#define DISPID_IUmlModelElement_RefinedElementRefinements 367
#define DISPID_IUmlModelElement_ImplementingComponents 43
#define DISPID_IUmlModelElement_ImplementedElements 44
#define DISPID_IUmlModelElement_ModelElement 46
#define DISPID_IUmlModelElement_Projections 47
#define IOID_IUmlModelElement L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000029}"
DEFINE_GUID(IID_IUmlModelElement,
0x45cc9f44, 0x6378, 0x11d0, 0xad, 0xb7, 0x00, 0xa0, 0xc9, 0x03, 0x95, 0xcc);

#define DISPID_IUmlElement_Visibility 49
#define DISPID_IUmlElement_Package 35
#define DISPID_IUmlElement_Elements 36
#define DISPID_IUmlElement_ReferencedElement 381
#define DISPID_IUmlElement_ReferencingReferences 382
#define DISPID_IUmlElement_Stereotype 52
#define DISPID_IUmlElement_TaggedValues 55
#define DISPID_IUmlElement_TargetElement 57
#define DISPID_IUmlElement_SourceDependencies 58
#define DISPID_IUmlElement_SourceElement 60
#define DISPID_IUmlElement_TargetDependencies 61
#define IOID_IUmlElement L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000030}"
DEFINE_GUID(IID_IUmlElement,
0xd9e5df4, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlReference_Visibility 443
#define DISPID_IUmlReference_Alias 444
#define DISPID_IUmlReference_ReferencingPackage 354
#define DISPID_IUmlReference_ReferencedReferences 355
#define DISPID_IUmlReference_ReferencedElement 381
#define DISPID_IUmlReference_ReferencingReferences 382
#define IOID_IUmlReference L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},0000011B}"
DEFINE_GUID(IID_IUmlReference,
0xd9e5dfa, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlDependency_System 24
#define DISPID_IUmlDependency_Dependencies 25
#define DISPID_IUmlDependency_TargetElement 57
#define DISPID_IUmlDependency_SourceDependencies 58
#define DISPID_IUmlDependency_SourceElement 60
#define DISPID_IUmlDependency_TargetDependencies 61
#define IOID_IUmlDependency L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000047}"
DEFINE_GUID(IID_IUmlDependency,
0xd9e5dfb, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlStereotype_Value 73
#define DISPID_IUmlStereotype_System 27
#define DISPID_IUmlStereotype_Stereotypes 28
#define DISPID_IUmlStereotype_Elements 51
#define DISPID_IUmlStereotype_Stereotype 52
#define IOID_IUmlStereotype L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000048}"
DEFINE_GUID(IID_IUmlStereotype,
0xd9e5dfc, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlTaggedValue_Value 75
#define DISPID_IUmlTaggedValue_Elements 54
#define DISPID_IUmlTaggedValue_TaggedValues 55
#define DISPID_IUmlTaggedValue_Tagset 77
#define IOID_IUmlTaggedValue L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},0000004A}"
DEFINE_GUID(IID_IUmlTaggedValue,
0xd9e5dfd, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IUmlConstraint L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},0000004F}"
DEFINE_GUID(IID_IUmlConstraint,
0xd9e5dfe, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlNote_Value 85
#define IOID_IUmlNote L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000054}"
DEFINE_GUID(IID_IUmlNote,
0xd9e5dff, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlRefinement_RefinedElement 363
#define DISPID_IUmlRefinement_RefiningElementRefinements 364
#define DISPID_IUmlRefinement_RefiningElement 366
#define DISPID_IUmlRefinement_RefinedElementRefinements 367
#define IOID_IUmlRefinement L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},0000011E}"
DEFINE_GUID(IID_IUmlRefinement,
0xd9e5e00, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlValue_Value 94
#define DISPID_IUmlValue_Instance 96
#define DISPID_IUmlValue_Values 97
#define DISPID_IUmlValue_Template 102
#define IOID_IUmlValue L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},0000005D}"
DEFINE_GUID(IID_IUmlValue,
0xd9e5e02, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlInstance_Instance 96
#define DISPID_IUmlInstance_Values 97
#define DISPID_IUmlInstance_Type 110
#define DISPID_IUmlInstance_Instances 111
#define DISPID_IUmlInstance_RoleInstances 113
#define DISPID_IUmlInstance_RoleTypes 114
#define IOID_IUmlInstance L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},0000006C}"
DEFINE_GUID(IID_IUmlInstance,
0xd9e5e03, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlPrimitiveType_Details 119
#define IOID_IUmlPrimitiveType L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000076}"
DEFINE_GUID(IID_IUmlPrimitiveType,
0xc21d0239, 0x70b8, 0x11d0, 0xbd, 0xef, 0x00, 0xc0, 0x4f, 0xc2, 0xf5, 0x1a);

#define IOID_IUmlUseCase L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},0000012A}"
DEFINE_GUID(IID_IUmlUseCase,
0xd9e5e08, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlSignal_Signal 405
#define DISPID_IUmlSignal_SignalReferences 406
#define IOID_IUmlSignal L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},0000012B}"
DEFINE_GUID(IID_IUmlSignal,
0xd9e5e09, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IUmlResponsibility L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000001C2}"
DEFINE_GUID(IID_IUmlResponsibility,
0x75e0d5ac, 0x89f5, 0x11d0, 0xbd, 0xf3, 0x00, 0xc0, 0x4f, 0xc2, 0xf5, 0x1a);

#define DISPID_IUmlAssociationRole_Multiplicity 125
#define DISPID_IUmlAssociationRole_IsNavigable 126
#define DISPID_IUmlAssociationRole_IsAggregate 127
#define DISPID_IUmlAssociationRole_IsChangeable 128
#define DISPID_IUmlAssociationRole_IsOrdered 129
#define DISPID_IUmlAssociationRole_Association 131
#define DISPID_IUmlAssociationRole_Roles 132
#define DISPID_IUmlAssociationRole_Type 135
#define DISPID_IUmlAssociationRole_AggregateRole 137
#define DISPID_IUmlAssociationRole_AggregatedTypes 138
#define DISPID_IUmlAssociationRole_QualifiedRole 140
#define DISPID_IUmlAssociationRole_QualifyingAttributes 141
#define IOID_IUmlAssociationRole L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},0000007C}"
DEFINE_GUID(IID_IUmlAssociationRole,
0xd9e5e0a, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlAssociation_Association 131
#define DISPID_IUmlAssociation_Roles 132
#define DISPID_IUmlAssociation_Class 144
#define IOID_IUmlAssociation L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},0000008E}"
DEFINE_GUID(IID_IUmlAssociation,
0xd9e5e0b, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IUmlRelationship L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000092}"
DEFINE_GUID(IID_IUmlRelationship,
0xd9e5e0c, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlGeneralization_Supertype 152
#define DISPID_IUmlGeneralization_Specializations 153
#define DISPID_IUmlGeneralization_Subtype 155
#define DISPID_IUmlGeneralization_Generalizations 156
#define DISPID_IUmlGeneralization_Generalization 158
#define DISPID_IUmlGeneralization_Powertype 159
#define IOID_IUmlGeneralization L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000096}"
DEFINE_GUID(IID_IUmlGeneralization,
0xd9e5e0d, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlGeneralizableElement_IsRoot 161
#define DISPID_IUmlGeneralizableElement_IsLeaf 162
#define DISPID_IUmlGeneralizableElement_IsAbstract 163
#define DISPID_IUmlGeneralizableElement_Supertype 152
#define DISPID_IUmlGeneralizableElement_Specializations 153
#define DISPID_IUmlGeneralizableElement_Subtype 155
#define DISPID_IUmlGeneralizableElement_Generalizations 156
#define IOID_IUmlGeneralizableElement L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000A0}"
DEFINE_GUID(IID_IUmlGeneralizableElement,
0xd9e5e0e, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlType_IsTemplate 169
#define DISPID_IUmlType_Visibility 170
#define DISPID_IUmlType_Multiplicity 171
#define DISPID_IUmlType_Type 110
#define DISPID_IUmlType_Instances 111
#define DISPID_IUmlType_RoleInstances 113
#define DISPID_IUmlType_RoleTypes 114
#define DISPID_IUmlType_Generalization 158
#define DISPID_IUmlType_Powertype 159
#define DISPID_IUmlType_Roles 134
#define DISPID_IUmlType_AggregateRole 137
#define DISPID_IUmlType_AggregatedTypes 138
#define DISPID_IUmlType_Members 174
#define DISPID_IUmlType_NestingType 176
#define DISPID_IUmlType_NestedTypes 177
#define DISPID_IUmlType_Template 102
#define DISPID_IUmlType_Values 103
#define DISPID_IUmlType_Parameters 189
#define DISPID_IUmlType_SignalReferences 414
#define DISPID_IUmlType_ExtensionPoints 420
#define IOID_IUmlType L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000A8}"
DEFINE_GUID(IID_IUmlType,
0x45cc9f56, 0x6378, 0x11d0, 0xad, 0xb7, 0x00, 0xa0, 0xc9, 0x03, 0x95, 0xcc);

#define DISPID_IUmlAttribute_InitialValue 191
#define DISPID_IUmlAttribute_TypeExpression 269
#define DISPID_IUmlAttribute_QualifiedRole 140
#define DISPID_IUmlAttribute_QualifyingAttributes 141
#define DISPID_IUmlAttribute_Type 423
#define DISPID_IUmlAttribute_Attributes 424
#define IOID_IUmlAttribute L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000BE}"
DEFINE_GUID(IID_IUmlAttribute,
0xd9e5e12, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlOperation_Concurrency 193
#define DISPID_IUmlOperation_IsPolymorphic 194
#define DISPID_IUmlOperation_IsQuery 195
#define DISPID_IUmlOperation_IsAbstract 196
#define DISPID_IUmlOperation_Operation 204
#define DISPID_IUmlOperation_Parameters 205
#define IOID_IUmlOperation L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000C0}"
DEFINE_GUID(IID_IUmlOperation,
0xd9e5e13, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlMember_IsTypeScope 207
#define DISPID_IUmlMember_Visibility 208
#define DISPID_IUmlMember_Direction 209
#define DISPID_IUmlMember_Type 173
#define DISPID_IUmlMember_Members 174
#define IOID_IUmlMember L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000CE}"
DEFINE_GUID(IID_IUmlMember,
0xd9e5e14, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlParameter_DefaultValue 212
#define DISPID_IUmlParameter_Kind 213
#define DISPID_IUmlParameter_TypeExpression 270
#define DISPID_IUmlParameter_Operation 204
#define DISPID_IUmlParameter_Parameters 205
#define DISPID_IUmlParameter_Template 188
#define DISPID_IUmlParameter_Type 435
#define IOID_IUmlParameter L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000D2}"
DEFINE_GUID(IID_IUmlParameter,
0xd9e5e15, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlSignalReference_Direction 445
#define DISPID_IUmlSignalReference_SignalReferences 414
#define DISPID_IUmlSignalReference_Type 415
#define DISPID_IUmlSignalReference_Signal 405
#define IOID_IUmlSignalReference L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},0000013F}"
DEFINE_GUID(IID_IUmlSignalReference,
0xd9e5e1b, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlObjectType_Type 423
#define DISPID_IUmlObjectType_Attributes 424
#define DISPID_IUmlObjectType_Parameters 436
#define IOID_IUmlObjectType L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000141}"
DEFINE_GUID(IID_IUmlObjectType,
0xd9e5e1d, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlName_ExtensionPoints 420
#define DISPID_IUmlName_Type 421
#define IOID_IUmlName L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000142}"
DEFINE_GUID(IID_IUmlName,
0xd9e5e1e, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlClass_Class 144
#define DISPID_IUmlClass_Association 145
#define IOID_IUmlClass L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000DE}"
DEFINE_GUID(IID_IUmlClass,
0xd9e5e1f, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlMethod_Body 224
#define IOID_IUmlMethod L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000DF}"
DEFINE_GUID(IID_IUmlMethod,
0xd9e5e20, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlNode_Nodes 227
#define DISPID_IUmlNode_Components 228
#define IOID_IUmlNode L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000E1}"
DEFINE_GUID(IID_IUmlNode,
0xd9e5e21, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlComponent_Nodes 227
#define DISPID_IUmlComponent_Components 228
#define DISPID_IUmlComponent_ImplementingComponents 43
#define DISPID_IUmlComponent_ImplementedElements 44
#define IOID_IUmlComponent L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000E5}"
DEFINE_GUID(IID_IUmlComponent,
0xd9e5e22, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IUmlActiveClass L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000E6}"
DEFINE_GUID(IID_IUmlActiveClass,
0xd9e5e23, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlProjection_Style 239
#define DISPID_IUmlProjection_ModelElement 46
#define DISPID_IUmlProjection_Projections 47
#define DISPID_IUmlProjection_ViewElement 39
#define DISPID_IUmlProjection_Points 441
#define DISPID_IUmlProjection_Projection 442
#define IOID_IUmlProjection L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000ED}"
DEFINE_GUID(IID_IUmlProjection,
0xd9e5e2d, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IUmlDiagram L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000F0}"
DEFINE_GUID(IID_IUmlDiagram,
0xd9e5e2e, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IUmlComponentDiagram L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000F1}"
DEFINE_GUID(IID_IUmlComponentDiagram,
0xd9e5e2f, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define IOID_IUmlClassDiagram L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},000000F2}"
DEFINE_GUID(IID_IUmlClassDiagram,
0xd9e5e30, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);

#define DISPID_IUmlPoint_X 446
#define DISPID_IUmlPoint_Y 447
#define DISPID_IUmlPoint_Z 448
#define DISPID_IUmlPoint_Points 441
#define DISPID_IUmlPoint_Projection 442
#define IOID_IUmlPoint L"{{FCBDE425-7166-11d0-ADC7-00A0C90395CC},00000154}"
DEFINE_GUID(IID_IUmlPoint,
0xd9e5e31, 0x88cd, 0x11d0, 0x8e, 0x76, 0x00, 0xa0, 0xc9, 0x05, 0xa4, 0xdb);


#endif // __UML_H_
