
#ifndef __EQM_H_
#define __EQM_H_

#define OBJID_TYPELIB_EQM L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00000003}"



#define OBJID_EqmModel L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00000021}"
#define OBJID_EqmPhrasingValueFieldDependency L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00000022}"
#define OBJID_EqmPhrasingWordFieldDependency L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00000023}"
#define OBJID_EqmDatabaseConnection L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00000024}"
#define OBJID_EqmDefaultCondition L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00000025}"
#define OBJID_EqmDefaultSet L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00000026}"
#define OBJID_EqmDefaultUnless L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00000027}"
#define OBJID_EqmEntity L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00000028}"
#define OBJID_EqmEntityDefault L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00000029}"
#define OBJID_EqmFieldRef L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},0000002A}"
#define OBJID_EqmDatabaseRship L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00004285}"
#define OBJID_EqmUseOfEntityAsDefaultID L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},0000002C}"
#define OBJID_EqmUseOfEntityAsDefaultName L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},0000002D}"
#define OBJID_EqmUseOfEntityAsDefaultSelf L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},0000002E}"
#define OBJID_EqmUseOfFieldAsAmountField L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},0000002F}"
#define OBJID_EqmUseOfFieldAsQuantityField L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00000030}"
#define OBJID_EqmUseOfNumbersInFieldByEntity L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00000031}"
#define OBJID_EqmUseOfRshipByEntityDefault L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00000032}"
#define OBJID_EqmUseOfTableRefForNameMemorization L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00004284}"
#define OBJID_EqmRegression L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},0000429D}"
#define OBJID_EqmQuestion L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},0000429E}"
#define OBJID_EqmAnswer L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},0000429F}"
#define OBJID_EqmEntityAttributeOfEntity L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},000042A1}"
#define DISPID_IEqmModel_PrivateData 17000
#define DISPID_IEqmModel_DateOfLastRegression 17001
#define DISPID_IEqmModel_RegressionSaveFile 17002
#define DISPID_IEqmModel_RegressionQuestFile 17003
#define DISPID_IEqmModel_RegressionOutFile 17004
#define DISPID_IEqmModel_OwnedDefaultSet 17016
#define DISPID_IEqmModel_OwningModel 17017
#define DISPID_IEqmModel_OwnedDbConnection 17018
#define DISPID_IEqmModel_regression 17045
#define DISPID_IEqmModel_model 17046
#define IOID_IEqmModel L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00000004}"
DEFINE_GUID(IID_IEqmModel,
0x83bb083e, 0x1b6c, 0x11d2, 0xbc, 0xda, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x82);

#define DISPID_IEqmDatabaseConnection_JoinsByDefaultAreOuterFlag 17005
#define DISPID_IEqmDatabaseConnection_LoadWords 17006
#define DISPID_IEqmDatabaseConnection_DBMaxRows 17007
#define DISPID_IEqmDatabaseConnection_ID 17008
#define DISPID_IEqmDatabaseConnection_DbmsType 17009
#define DISPID_IEqmDatabaseConnection_DbmsVersion 17010
#define DISPID_IEqmDatabaseConnection_LoadSamples 17031
#define DISPID_IEqmDatabaseConnection_OwnedDbConnection 17018
#define DISPID_IEqmDatabaseConnection_OwningModel 17019
#define IOID_IEqmDatabaseConnection L"{{314FE626-EFED-11d1-BD7C-00C04FB6F948},00000007}"
DEFINE_GUID(IID_IEqmDatabaseConnection,
0x314fe62c, 0xefed, 0x11d1, 0xbd, 0x7c, 0x00, 0xc0, 0x4f, 0xb6, 0xf9, 0x48);

#define DISPID_IEqmEntityDefault_InverseFlag 17058
#define DISPID_IEqmEntityDefault_OwnedEntityDefaults 17020
#define DISPID_IEqmEntityDefault_OwningEntity 17021
#define IOID_IEqmEntityDefault L"{{314FE626-EFED-11d1-BD7C-00C04FB6F948},0000001B}"
DEFINE_GUID(IID_IEqmEntityDefault,
0x314fe636, 0xefed, 0x11d1, 0xbd, 0x7c, 0x00, 0xc0, 0x4f, 0xb6, 0xf9, 0x48);

#define DISPID_IEqmDefaultCondition_Operator 17011
#define DISPID_IEqmDefaultCondition_Value 17012
#define IOID_IEqmDefaultCondition L"{{314FE626-EFED-11d1-BD7C-00C04FB6F948},0000001C}"
DEFINE_GUID(IID_IEqmDefaultCondition,
0x314fe637, 0xefed, 0x11d1, 0xbd, 0x7c, 0x00, 0xc0, 0x4f, 0xb6, 0xf9, 0x48);

#define DISPID_IEqmDefaultSet_OwnedDefaultSet 17016
#define DISPID_IEqmDefaultSet_OwningModel 17017
#define IOID_IEqmDefaultSet L"{{314FE626-EFED-11d1-BD7C-00C04FB6F948},00000054}"
DEFINE_GUID(IID_IEqmDefaultSet,
0x314fe656, 0xefed, 0x11d1, 0xbd, 0x7c, 0x00, 0xc0, 0x4f, 0xb6, 0xf9, 0x48);

#define DISPID_IEqmFieldRef_AggregateType 17013
#define DISPID_IEqmFieldRef_AggregatingFields 17022
#define DISPID_IEqmFieldRef_AggregatedField 17023
#define DISPID_IEqmFieldRef_ReplicatedField 17024
#define DISPID_IEqmFieldRef_ReplicatingFields 17025
#define IOID_IEqmFieldRef L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00000010}"
DEFINE_GUID(IID_IEqmFieldRef,
0x83bb083f, 0x1b6c, 0x11d2, 0xbc, 0xda, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x82);

#define DISPID_IEqmEntity_InverseFlag 17014
#define DISPID_IEqmEntity_OwnedEntityDefaults 17020
#define DISPID_IEqmEntity_OwningEntity 17021
#define IOID_IEqmEntity L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00000011}"
DEFINE_GUID(IID_IEqmEntity,
0x83bb0840, 0x1b6c, 0x11d2, 0xbc, 0xda, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x82);

#define IOID_IEqmDefaultUnless L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00000013}"
DEFINE_GUID(IID_IEqmDefaultUnless,
0x83bb0841, 0x1b6c, 0x11d2, 0xbc, 0xda, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x82);

#define IOID_IEqmUseOfRshipByEntityDefault L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00000014}"
DEFINE_GUID(IID_IEqmUseOfRshipByEntityDefault,
0x83bb0842, 0x1b6c, 0x11d2, 0xbc, 0xda, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x82);

#define IOID_IEqmUseOfEntityByDefaultSet L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00000015}"
DEFINE_GUID(IID_IEqmUseOfEntityByDefaultSet,
0x83bb0843, 0x1b6c, 0x11d2, 0xbc, 0xda, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x82);

#define IOID_IEqmUseOfEntityAsDefaultSelf L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00000016}"
DEFINE_GUID(IID_IEqmUseOfEntityAsDefaultSelf,
0x83bb0844, 0x1b6c, 0x11d2, 0xbc, 0xda, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x82);

#define IOID_IEqmUseOfEntityAsDefaultName L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00000017}"
DEFINE_GUID(IID_IEqmUseOfEntityAsDefaultName,
0x83bb0845, 0x1b6c, 0x11d2, 0xbc, 0xda, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x82);

#define IOID_IEqmUseOfEntityAsDefaultID L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00000018}"
DEFINE_GUID(IID_IEqmUseOfEntityAsDefaultID,
0x83bb0846, 0x1b6c, 0x11d2, 0xbc, 0xda, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x82);

#define IOID_IEqmPhrasingValueFieldDependency L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00000019}"
DEFINE_GUID(IID_IEqmPhrasingValueFieldDependency,
0x83bb0847, 0x1b6c, 0x11d2, 0xbc, 0xda, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x82);

#define IOID_IEqmPhrasingWordFieldDependency L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},0000001A}"
DEFINE_GUID(IID_IEqmPhrasingWordFieldDependency,
0x83bb0848, 0x1b6c, 0x11d2, 0xbc, 0xda, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x82);

#define IOID_IEqmUseOfFieldByEntInRel L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},0000001B}"
DEFINE_GUID(IID_IEqmUseOfFieldByEntInRel,
0x83bb0849, 0x1b6c, 0x11d2, 0xbc, 0xda, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x82);

#define IOID_IEqmUseOfFieldAsAmountField L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},0000001C}"
DEFINE_GUID(IID_IEqmUseOfFieldAsAmountField,
0x83bb084a, 0x1b6c, 0x11d2, 0xbc, 0xda, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x82);

#define IOID_IEqmUseOfFieldAsQuantityField L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},0000001D}"
DEFINE_GUID(IID_IEqmUseOfFieldAsQuantityField,
0x83bb084b, 0x1b6c, 0x11d2, 0xbc, 0xda, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x82);

#define IOID_IEqmUseOfNumbersInFieldByEntity L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},0000001E}"
DEFINE_GUID(IID_IEqmUseOfNumbersInFieldByEntity,
0x83bb084c, 0x1b6c, 0x11d2, 0xbc, 0xda, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x82);

#define DISPID_IEqmDatabaseRship_SqlCondition 17015
#define DISPID_IEqmDatabaseRship_DefaultDateType 17026
#define IOID_IEqmDatabaseRship L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},0000001F}"
DEFINE_GUID(IID_IEqmDatabaseRship,
0x83bb084d, 0x1b6c, 0x11d2, 0xbc, 0xda, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x82);

#define IOID_IEqmUseOfTableRefForNameMemorization L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00004283}"
DEFINE_GUID(IID_IEqmUseOfTableRefForNameMemorization,
0x9728b360, 0x6482, 0x11d2, 0xbc, 0xf1, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x82);

#define DISPID_IEqmRegression_ID 17033
#define DISPID_IEqmRegression_QuestFile 17034
#define DISPID_IEqmRegression_OutFile 17035
#define DISPID_IEqmRegression_SaveFile 17036
#define DISPID_IEqmRegression_Date 17037
#define DISPID_IEqmRegression_regression 17045
#define DISPID_IEqmRegression_model 17046
#define DISPID_IEqmRegression_Questions 17048
#define IOID_IEqmRegression L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00004288}"
DEFINE_GUID(IID_IEqmRegression,
0x27433053, 0xd71, 0x44e9, 0xab, 0xb1, 0x70, 0x43, 0x34, 0xc1, 0x35, 0x14);

#define DISPID_IEqmQuestion_Clarification 17039
#define DISPID_IEqmQuestion_Restatement 17040
#define DISPID_IEqmQuestion_Answer 17051
#define DISPID_IEqmQuestion_Question 17052
#define DISPID_IEqmQuestion_Questions 17048
#define DISPID_IEqmQuestion_Regression 17049
#define IOID_IEqmQuestion L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},0000428E}"
DEFINE_GUID(IID_IEqmQuestion,
0x10db9669, 0xd687, 0x4881, 0x96, 0xb, 0x26, 0x9d, 0x3d, 0x43, 0xac, 0x55);

#define DISPID_IEqmAnswer_Query 17042
#define DISPID_IEqmAnswer_Results 17043
#define DISPID_IEqmAnswer_Answer 17051
#define DISPID_IEqmAnswer_Question 17052
#define IOID_IEqmAnswer L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},00004291}"
DEFINE_GUID(IID_IEqmAnswer,
0x19a7b068, 0x9e49, 0x4fba, 0xad, 0x97, 0xa7, 0xa4, 0x1e, 0x0a, 0xc4, 0x11);

#define IOID_IEqmEntityAttributeOfEntity L"{{83BB083C-1B6C-11d2-BCDA-00C04F8EF282},000042A0}"
DEFINE_GUID(IID_IEqmEntityAttributeOfEntity,
0xd703ddd0, 0xa798, 0x40a4, 0xa8, 0xa5, 0x23, 0x7a, 0x1d, 0x18, 0x92, 0xd9);


#endif // __EQM_H_
