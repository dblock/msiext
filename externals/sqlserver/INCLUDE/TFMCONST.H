
#ifndef __TFM_H_
#define __TFM_H_

#define OBJID_TYPELIB_TFM L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B3D}"



#define OBJID_TfmTransformationConstraint L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B87}"
#define OBJID_TfmTransformableObjectSet L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B88}"
#define OBJID_TfmTransformationConversion L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B89}"
#define OBJID_TfmTransformationStep L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B8A}"
#define OBJID_TfmCodeDecodeValue L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B8B}"
#define OBJID_TfmCodeDecodeSet L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B8C}"
#define OBJID_TfmTransformationTask L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B8D}"
#define OBJID_TfmTransformationPackage L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B8F}"
#define OBJID_TfmTransformation L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B97}"
#define OBJID_TfmPrecedenceConstraint L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B98}"
#define OBJID_TfmTransformationUses L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002BBE}"
#define OBJID_TfmAttribute L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002BC7}"
#define OBJID_TfmPackageExecution L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B96}"
#define OBJID_DbmDeployedTable L"{{391881E3-F894-11d0-8E76-00A0C905A4DB},000013B8}"
#define OBJID_DbmDeployedView L"{{391881E3-F894-11d0-8E76-00A0C905A4DB},000013BA}"
#define OBJID_DbmDeployedMaterializedView L"{{391881E3-F894-11d0-8E76-00A0C905A4DB},000013BE}"
#define OBJID_DbmDeployedColumn L"{{391881E3-F894-11d0-8E76-00A0C905A4DB},0000148A}"
#define OBJID_TfmQuery L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002BCC}"
#define OBJID_TfmStepExecution L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002BD4}"
#define DISPID_ITfmTransformableObject_TransformObjects 11168
#define DISPID_ITfmTransformableObject_TransformSets 11169
#define IOID_ITfmTransformableObject L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B3E}"
DEFINE_GUID(IID_ITfmTransformableObject,
0x7fcf7884, 0xaf00, 0x11d1, 0x8c, 0x1e, 0x00, 0xaa, 0x00, 0xa1, 0x4d, 0x34);

#define IOID_ITfmTransformationConversion L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B3F}"
DEFINE_GUID(IID_ITfmTransformationConversion,
0x7fcf7885, 0xaf00, 0x11d1, 0x8c, 0x1e, 0x00, 0xaa, 0x00, 0xa1, 0x4d, 0x34);

#define IOID_ITfmTransformationConstraint L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B40}"
DEFINE_GUID(IID_ITfmTransformationConstraint,
0x7fcf7886, 0xaf00, 0x11d1, 0x8c, 0x1e, 0x00, 0xaa, 0x00, 0xa1, 0x4d, 0x34);

#define DISPID_ITfmTransformationTask_Language 11074
#define DISPID_ITfmTransformationTask_OriginalTransformation 11171
#define DISPID_ITfmTransformationTask_InverseTransformation 11172
#define DISPID_ITfmTransformationTask_Task 11200
#define DISPID_ITfmTransformationTask_Steps 11201
#define IOID_ITfmTransformationTask L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B41}"
DEFINE_GUID(IID_ITfmTransformationTask,
0x7fcf7887, 0xaf00, 0x11d1, 0x8c, 0x1e, 0x00, 0xaa, 0x00, 0xa1, 0x4d, 0x34);

#define DISPID_ITfmTransformationStep_Task 11200
#define DISPID_ITfmTransformationStep_Steps 11201
#define DISPID_ITfmTransformationStep_Step 11224
#define DISPID_ITfmTransformationStep_StepExecutions 11225
#define IOID_ITfmTransformationStep L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B47}"
DEFINE_GUID(IID_ITfmTransformationStep,
0x7fcf7888, 0xaf00, 0x11d1, 0x8c, 0x1e, 0x00, 0xaa, 0x00, 0xa1, 0x4d, 0x34);

#define DISPID_ITfmCodeDecodeSet_DecodeColumn 11174
#define DISPID_ITfmCodeDecodeSet_DecodeSets 11175
#define DISPID_ITfmCodeDecodeSet_CodeColumn 11177
#define DISPID_ITfmCodeDecodeSet_CodeSets 11178
#define IOID_ITfmCodeDecodeSet L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B4D}"
DEFINE_GUID(IID_ITfmCodeDecodeSet,
0x7fcf7889, 0xaf00, 0x11d1, 0x8c, 0x1e, 0x00, 0xaa, 0x00, 0xa1, 0x4d, 0x34);

#define DISPID_ITfmCodeDecodeValue_BeginDate 11087
#define DISPID_ITfmCodeDecodeValue_EndDate 11088
#define IOID_ITfmCodeDecodeValue L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B4E}"
DEFINE_GUID(IID_ITfmCodeDecodeValue,
0x7fcf788a, 0xaf00, 0x11d1, 0x8c, 0x1e, 0x00, 0xaa, 0x00, 0xa1, 0x4d, 0x34);

#define DISPID_ITfmTransformableObjectSet_TransformSource 11180
#define DISPID_ITfmTransformableObjectSet_SourceOf 11181
#define DISPID_ITfmTransformableObjectSet_TargetOf 11183
#define DISPID_ITfmTransformableObjectSet_TransformTarget 11184
#define DISPID_ITfmTransformableObjectSet_TransformObjects 11168
#define DISPID_ITfmTransformableObjectSet_TransformSets 11169
#define IOID_ITfmTransformableObjectSet L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B51}"
DEFINE_GUID(IID_ITfmTransformableObjectSet,
0x7fcf788b, 0xaf00, 0x11d1, 0x8c, 0x1e, 0x00, 0xaa, 0x00, 0xa1, 0x4d, 0x34);

#define DISPID_ITfmTransformation_FunctionExpression 11091
#define DISPID_ITfmTransformation_IsControl 11092
#define DISPID_ITfmTransformation_Language 11194
#define DISPID_ITfmTransformation_TransformSource 11180
#define DISPID_ITfmTransformation_SourceOf 11181
#define DISPID_ITfmTransformation_TargetOf 11183
#define DISPID_ITfmTransformation_TransformTarget 11184
#define IOID_ITfmTransformation L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B52}"
DEFINE_GUID(IID_ITfmTransformation,
0x7fcf788c, 0xaf00, 0x11d1, 0x8c, 0x1e, 0x00, 0xaa, 0x00, 0xa1, 0x4d, 0x34);

#define DISPID_ITfmTransformationPackage_CreationDate 11101
#define DISPID_ITfmTransformationPackage_Executions 11209
#define DISPID_ITfmTransformationPackage_TransformationPackage 11210
#define IOID_ITfmTransformationPackage L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B5B}"
DEFINE_GUID(IID_ITfmTransformationPackage,
0x7fcf788e, 0xaf00, 0x11d1, 0x8c, 0x1e, 0x00, 0xaa, 0x00, 0xa1, 0x4d, 0x34);

#define DISPID_ITfmPrecedenceConstraint_PrecedenceBasis 11116
#define IOID_ITfmPrecedenceConstraint L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B6B}"
DEFINE_GUID(IID_ITfmPrecedenceConstraint,
0x7fcf7891, 0xaf00, 0x11d1, 0x8c, 0x1e, 0x00, 0xaa, 0x00, 0xa1, 0x4d, 0x34);

#define DISPID_ITfmColumn_DecodeColumn 11174
#define DISPID_ITfmColumn_DecodeSets 11175
#define DISPID_ITfmColumn_CodeColumn 11177
#define DISPID_ITfmColumn_CodeSets 11178
#define IOID_ITfmColumn L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B6D}"
DEFINE_GUID(IID_ITfmColumn,
0x7fcf7892, 0xaf00, 0x11d1, 0x8c, 0x1e, 0x00, 0xaa, 0x00, 0xa1, 0x4d, 0x34);

#define DISPID_ITfmTransformationUses_Type 11196
#define IOID_ITfmTransformationUses L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002BBB}"
DEFINE_GUID(IID_ITfmTransformationUses,
0xebb99955, 0xba15, 0x11d1, 0x90, 0x1b, 0x00, 0x00, 0xf8, 0x7a, 0x3b, 0x33);

#define IOID_ITfmAttribute L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002BC6}"
DEFINE_GUID(IID_ITfmAttribute,
0xc5e3c77e, 0xce83, 0x11d1, 0xb2, 0x9f, 0x00, 0xa0, 0xc9, 0x2d, 0xf6, 0x3a);

#define DISPID_ITfmPackageExecution_ExecutionId 11110
#define DISPID_ITfmPackageExecution_ShortExecutionId 11111
#define DISPID_ITfmPackageExecution_System 11112
#define DISPID_ITfmPackageExecution_Account 11113
#define DISPID_ITfmPackageExecution_WhenExecuted 11114
#define DISPID_ITfmPackageExecution_Executions 11209
#define DISPID_ITfmPackageExecution_TransformationPackage 11210
#define DISPID_ITfmPackageExecution_StepExecutions 11215
#define DISPID_ITfmPackageExecution_PackageExecution 11216
#define IOID_ITfmPackageExecution L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002B65}"
DEFINE_GUID(IID_ITfmPackageExecution,
0x7fcf7890, 0xaf00, 0x11d1, 0x8c, 0x1e, 0x00, 0xaa, 0x00, 0xa1, 0x4d, 0x34);

#define DISPID_ITfmStepExecution_WhenStarted 11217
#define DISPID_ITfmStepExecution_WhenEnded 11218
#define DISPID_ITfmStepExecution_Duration 11219
#define DISPID_ITfmStepExecution_Succeeded 11222
#define DISPID_ITfmStepExecution_StepExecutions 11215
#define DISPID_ITfmStepExecution_PackageExecution 11216
#define DISPID_ITfmStepExecution_Step 11224
#define IOID_ITfmStepExecution L"{{7FCF7882-AF00-11d1-8C1E-00AA00A14D34},00002BCD}"
DEFINE_GUID(IID_ITfmStepExecution,
0xe089e46, 0x2bb4, 0x11d2, 0xb7, 0x9f, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);


#endif // __TFM_H_
