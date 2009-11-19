// ------------------------------------------------------------------------
// Copyright (c) 2000 by Microsoft Corporation, All Rights Reserved
// 
// This software is provided as is without warranty of any kind.  The entire
// risk as to the results and performance of this software is assumed by the user.
// Microsoft disclaims all warranties, either express or implied, including but
// not limited, the implied warranties of merchantability, fitness for a
// particular purpose, title and noninfringement, with respect to this software.
// ------------------------------------------------------------------------
//*****************************************************************************
// REPTIM3.H
//
// This module contains the declarations of the meta-meta model components.
// These can be used to browse the meta-meta model by ID, or might be required
// to create your own meta model in the Repository.
//
// Copyright (c) 1995-2000 by Microsoft Corporation, All Rights Reserved
//*****************************************************************************
#ifndef __REPTIM3_H__
#define __REPTIM3_H__

#include "reptim2.h"

// Local ID definitions
// NOTE: We are attempting to keep these declarations in the order below,
//		 If you add new LCLIDs and have to renumber than you must
//		 change the struct grsMMBaseObj which describes the type of the
//		 object.  


// Large blob support
#define LCLID_SQLBlobSize			87
#define LCLID_IPropDef2				88

// IVersionAdminInfo2
#define LCLID_IVersionAdminInfo2	89
#define LCLID_VersionLabel			90
#define LCLID_VersionShortDesc		91
#define LCLID_VersionComments		92

// IIfaceDef2
#define LCLID_IIfaceDef2			93

// InterfaceImpliesInterface
#define LCLID_RInterfaceImpliesInterface		94
#define LCLID_Implies				95
#define LCLID_ImpliedBy				96

// IfaceMember2
#define LCLID_IIfaceMember2			97

// BaseMemberServicesDerivedMembers
#define LCLID_RBaseMemberServicesDerivedMembers	98
#define LCLID_ServicesDerivedMembers	99
#define LCLID_ServicedByBaseMember	100

// IMethodDef
#define LCLID_IMethodDef			101

// IParameterDef
#define LCLID_IParameterDef			102
#define LCLID_ParDefFlags			103
#define LCLID_ParDefType			104
#define LCLID_ParDefDesc			105
#define LCLID_ParDefDefault			106
#define LCLID_ParDefGUID			107

// InterfaceMemberHasParameters
#define LCLID_RInterfaceMemberHasParameters	108
#define LCLID_Member				109
#define LCLID_Parameters			110

// CreateParameterDef
#define LCLID_CreateParDef			111
#define LCLID_CreateParDefObjID		112
#define LCLID_CreateParDefName		113
#define LCLID_CreateParDefType		114
#define LCLID_CreateParDefFlags		115
#define LCLID_CreateParDefDesc		116
#define LCLID_CreateParDefDefault	117
#define LCLID_CreateParDefParDef	118

// Class definitions.
#define LCLID_Alias										119
#define LCLID_ParameterDef								120
#define LCLID_RepositoryObject							121
#define LCLID_RepositoryObjectVersion					122
#define LCLID_Relationship								123
#define LCLID_VersionedRelationship						124
#define LCLID_ReposProperty								125
#define LCLID_ReposProperties							126
#define LCLID_RelationshipCol							127
#define LCLID_ObjectCol									128
#define LCLID_VersionCol								129
#define LCLID_Repository								130

// Interface definitions
#define LCLID_IRepository								131
#define LCLID_IReposProperties							132
#define LCLID_IReposProperty							133
#define LCLID_IReposPropertyLarge						134
#define LCLID_IRepositoryTransaction					135
#define LCLID_IObjectCol								136
#define LCLID_ITargetObjectCol							137
#define LCLID_IRepositoryObjectStorage					138
#define LCLID_IRelationshipCol							139
#define LCLID_IObjectCol2								140
#define LCLID_IRepository2								141
#define LCLID_IRepositoryODBC							142
#define LCLID_IRepositoryODBC2							143
#define LCLID_IReposTypeLib2							144

// Property definitions
#define LCLID_ReposPropLargeSize						145
#define LCLID_RepositoryItemType						146
#define LCLID_RepositoryItemName						147

// Method definitions
#define LCLID_Create									148
#define LCLID_Open 										149
#define LCLID_CreateObject 								150
#define LCLID_IRepositoryRefresh 						151
#define LCLID_ObjectIDToInternalID						152
#define LCLID_InternalIDToObjectID						153
#define LCLID_Refresh 									154
#define LCLID_Delete 									155
#define LCLID_Lock										156
#define LCLID_Begin 									157
#define LCLID_Commit									158
#define LCLID_Abort										159
#define LCLID_GetOption									160
#define LCLID_SetOption									161
#define LCLID_Flush										162
#define LCLID_IVersionColRefresh 						163
#define LCLID_IVersionColAdd							164
#define LCLID_IVersionColRemove							165
#define LCLID_CreateVersion 							166
#define LCLID_FreezeVersion								167
#define LCLID_MergeVersion								168
#define LCLID_Checkout 									169
#define LCLID_Checkin									170
#define LCLID_IObjectColRefresh 						171
#define LCLID_ITargetObjectColAdd 						172
#define LCLID_ITargetObjectColRemove					173
#define LCLID_ITargetObjectColInsert					174
#define LCLID_ITargetObjectColMove						175
#define LCLID_InitNew 									176
#define LCLID_Load										177
#define LCLID_Pin 										178
#define LCLID_Unpin										179
#define LCLID_IRelationshipColAdd 						180
#define LCLID_IRelationshipColRemove					181
#define LCLID_IRelationshipColInsert					182
#define LCLID_IRelationshipColMove						183
#define LCLID_IRelationshipColRefresh					184
#define LCLID_Cancel 									185
#define LCLID_VersionIDToInternalID 					186
#define LCLID_InternalIDToVersionID						187
#define LCLID_CreateObjectEx							188
#define LCLID_GetNewConnection 							189
#define LCLID_FreeConnection							190
#define LCLID_ExecuteQuery								191
#define LCLID_IRepositoryODBC2GetOption 				192
#define LCLID_IRepositoryODBC2SetOption					193
#define LCLID_CreateRelationshipColDef 					194
#define LCLID_CreatePropertyDef							195
#define LCLID_CreateMethodDef							196
#define LCLID_IInterfaceDefObjectInstances				197
#define LCLID_AddInterface 								198
#define LCLID_IClassDefCreateInterfaceDef				199
#define LCLID_IClassDefObjectInstances					200
#define LCLID_CreateAlias 								201
#define LCLID_CreateClassDef 							202
#define LCLID_CreateInterfaceDef						203
#define LCLID_CreateRelationshipDef						204
#define LCLID_CreateTypeLib 							205
#define LCLID_ReposPropLargeRead						206
#define LCLID_ReposPropLargeWrite						207
#define LCLID_ReposPropLargeClose						208

// Parameter definitions
// IRepository							
#define LCLID_CreateConnect								209
#define LCLID_CreateUser								210
#define LCLID_CreatePassword							211
#define LCLID_CreateFlags								212
#define LCLID_CreateRoot								213
#define LCLID_OpenConnect								214
#define LCLID_OpenUser									215
#define LCLID_OpenPassword								216
#define LCLID_OpenFlags									217
#define LCLID_OpenRoot									218
#define LCLID_CreateObjectTypeID						219
#define LCLID_CreateObjectObjID							220
#define LCLID_CreateObjectReposObj						221
#define LCLID_IRepositoryRefreshMilliseconds			222
#define LCLID_ObjectIDToInternalIDObjID					223
#define LCLID_ObjectIDToInternalIDIntID					224
#define LCLID_InternalIDToObjectIDIntID					225
#define LCLID_InternalIDToObjectIDObjID					226

// IRepositoryObject
#define LCLID_RefreshMilliseconds						227

// IRepositoryTransaction
#define LCLID_GetOptionOption							228
#define LCLID_GetOptionValue							229
#define LCLID_SetOptionOption							230
#define LCLID_SetOptionValue							231

// IVersionCol
#define LCLID_IVersionColRefreshMilliseconds			232
#define LCLID_IVersionColRemoveItem						233

// IRepositoryObject
#define LCLID_CreateVersionVersoinID					234
#define LCLID_CreateVersionCreatedVersion				235
#define LCLID_MergeVersionOtherVersion					236
#define LCLID_MergeVersionFlags							237

// IObjectCol
#define LCLID_IObjectColRefreshMilliseconds				238

// ITargetObjectCol 
#define LCLID_ITargetObjectColAddReposObj				239
#define LCLID_ITargetObjectColAddNamel					240
#define LCLID_ITargetObjectColAddRelship				241
#define LCLID_ITargetObjectColRemoveItem				242
#define LCLID_ITargetObjectColInsertReposObj			243
#define LCLID_ITargetObjectColInsertIndex				244
#define LCLID_ITargetObjectColInsertName				245
#define LCLID_ITargetObjectColInsertRelship				246
#define LCLID_ITargetObjectColMoveIndexFrom				247
#define LCLID_ITargetObjectColMoveIndexTo				248

// IRepositoryObjectStorage
#define LCLID_InitNewRepos								249
#define LCLID_InitNewCookie								250
#define LCLID_LoadRepos									251
#define LCLID_LoadCookie								252

// IVersionedRelationship
#define LCLID_PinReposVersion							253

// IRelationshipCol
#define LCLID_IRelationshipColAddReposObj				254
#define LCLID_IRelationshipColAddName					255
#define LCLID_IRelationshipColAddRemove					256
#define LCLID_IRelationshipColInsertReposObj			257
#define LCLID_IRelationshipColInsertIndex				258
#define LCLID_IRelationshipColInsertName				259
#define LCLID_IRelationshipColInsertRelship				260
#define LCLID_IRelationshipColMoveIndexFrom				261
#define LCLID_IRelationshipColMoveIndexTo				262
#define LCLID_IRelationshipColRefreshMilliseconds		263

// IRepository2
#define LCLID_VersionIDToInternalIDExtVersionID			264
#define LCLID_VersionIDToInternalIDIntVersionID			265
#define LCLID_InternalIDToVersionIDIntVersionID			266
#define LCLID_InternalIDToVersionIDExtVersionID			267

// IRepositoryODBC
#define LCLID_GetNewConnectionHdbc						268
#define LCLID_FreeConnecionHdbc							269
#define LCLID_ExecuteQueryQuery							270
#define LCLID_ExecuteQueryCol							271

// IRepositoryODBC2
#define LCLID_IRepositoryODBC2GetOptionOption			272
#define LCLID_IRepositoryODBC2GetOptionValue			273
#define LCLID_IRepositoryODBC2SetOptionOption			274
#define LCLID_IRepositoryODBC2SetOptionValue			275

// IInterfaceDef
#define LCLID_CreateRelationshipColDefObjID				276
#define LCLID_CreateRelationshipColDefName				277
#define LCLID_CreateRelationshipColDefDispID			278
#define LCLID_CreateRelationshipColDefIsOrigin			279
#define LCLID_CreateRelationshipColDefFlags				280
#define LCLID_CreateRelationshipColDefRelshipDef		281
#define LCLID_CreateRelationshipColDefColDef			282
#define LCLID_CreatePropertyDefObjID					283
#define LCLID_CreatePropertyDefName						284
#define LCLID_CreatePropertyDefDispID					285
#define LCLID_CreatePropertyDefType						286
#define LCLID_CreatePropertyDefPropDef					287
#define LCLID_CreateMethodDefObjID						288
#define LCLID_CreateMethodDefName						289
#define LCLID_CreateMethodDefDispID						290
#define LCLID_CreateMethodDefMethodDef					291
#define LCLID_IInterfaceDefObjectInstancesObject		292

// IClassDef
#define LCLID_AddInterfaceInterfaceDef					293
#define LCLID_AddInterfaceFlags							294
#define LCLID_ClassDefCreateInterfaceDefObjID			295
#define LCLID_ClassDefCreateInterfaceDefName			296
#define LCLID_ClassDefCreateInterfaceDefIID				297
#define LCLID_ClassDefCreateInterfaceDefAncestor		298
#define LCLID_ClassDefCreateInterfaceDefFlags			299
#define LCLID_ClassDefCreateInterfaceDefIfaceDef		300
#define LCLID_IClassDefObjectInstancesObjectCol			301

// IInterfaceDef2
#define LCLID_CreateAliasObjID							302
#define LCLID_CreateAliasName							303
#define LCLID_CreateAliasDispID							304
#define LCLID_CreateAliasBase							305
#define LCLID_CreateAliasAlias							306

// IReposTypeLib
#define LCLID_CreateClassDefObjID						307
#define LCLID_CreateClassDefName						308
#define LCLID_CreateClassDefClassID						309
#define LCLID_CreateClassDefClassDef					310
#define LCLID_CreateInterfaceDefObjID					311
#define LCLID_CreateInterfaceDefName					312
#define LCLID_CreateInterfaceDefIID						313
#define LCLID_CreateInterfaceDefAncestor				314
#define LCLID_CreateInterfaceDefIfaceDef				315
#define LCLID_CreateRelationshipDefObjID				316
#define LCLID_CreateRelationshipDefName					317
#define LCLID_CreateRelationshipDefRelshipDef			318

// IManageReposTypeLib
#define LCLID_CreateTypeLibObjID						319
#define LCLID_CreateTypeLibName							320
#define LCLID_CreateTypeLibTypeLibID					321
#define LCLID_CreateTypeLibTypeLib						322

// IRepositoryPropertyLarge
#define LCLID_IRepositoryPropertyLargeReadChunkSize		323
#define LCLID_IRepositoryPropertyLargeReadSizeRead		324
#define LCLID_IRepositoryPropertyLargeReadBlob			325
#define LCLID_IRepositoryPropertyLargeWriteBlob			326
#define LCLID_ReposPropLargeCurrentPosition				327
#define LCLID_ReposPropLargeReadFromFile				328
#define LCLID_ReposPropLargeWriteToFile					329
#define LCLID_IRepositoryPropertyLargeReadFromFileFileName		330
#define LCLID_IRepositoryPropertyLargeWriteToFileFileName		331

// IReposTypeLib2
#define LCLID_RReposTypeLib2Dependency					332
#define LCLID_IReposTypeLib2DependsOn					333
#define LCLID_IReposTypeLib2UsedBy						334				

// IReposOptions
#define LCLID_IReposOptions								335
#define LCLID_IReposOptionsGetOption					336
#define LCLID_IReposOptionsSetOption					337
#define LCLID_IReposOptionsResetOptions					338
#define LCLID_IReposOptionsGetOptionOption				339
#define LCLID_IReposOptionsGetOptionValue				340
#define LCLID_IReposOptionsSetOptionOption				341
#define LCLID_IReposOptionsSetOptionValue				342

// ScriptDef
#define LCLID_ScriptDef									343 // Class
#define	LCLID_IScriptDef								344 // Interface
#define	LCLID_IScriptDefLanguage						345 // Property
#define	LCLID_IScriptDefBody							346 // Property
#define	LCLID_IScriptDefValidateScript					347 // Method
#define	LCLID_RClassUsesScript							348 // Relationship
#define LCLID_UsingClasses								349 // Role
#define LCLID_ScriptsUsedByClass						350 // Role
#define	LCLID_RInterafceUsesScript						351 // Relationship
#define	LCLID_UsingInterfaces							352	// Role
#define	LCLID_ScriptsUsedByInterface					353 // Role
#define	LCLID_RMemberUsesScript							354 // Relationship
#define	LCLID_UsingMember								355 // Role
#define	LCLID_ScriptsUsedByMember						356 // Role
#define	LCLID_IClassDef2								357 // Interface

// IRepositoryTransaction2
#define LCLID_IRepositoryTransaction2					358
#define LCLID_IRepositoryTransaction2Transaction		359
#define LCLID_IRepositoryTransaction2JoinTransaction	360

// IReposProperty2
#define LCLID_IReposProperty2							361

// IReposObj2
#define LCLID_IReposObj2								362

// IEnumerationDef
#define LCLID_EnumerationDef							363
#define LCLID_IEnumerationDef							364
#define LCLID_IEnumerationDefIsFlag						365
#define LCLID_IEnumerationDefValues						366
#define LCLID_IEnumerationDefEnumFor					367
#define LCLID_REnumerationValues						368

// IEnumerationValueDef
#define LCLID_EnumerationValueDef						369
#define LCLID_IEnumerationValueDef						370
#define LCLID_IEnumerationValueDefValue					371
#define LCLID_IEnumerationValueDefValueOf				372

// IPropDef2
#define LCLID_PropDefEnumerationDef						373
#define	LCLID_REnumerationForProperty					374

// IViewClassDef
#define LCLID_IViewClassDef								375			
#define LCLID_IViewClassDefFlags						376		
#define LCLID_IViewClassDefViewName						377				

// IViewInterfaceDef
#define LCLID_IViewInterfaceDef							378		
#define LCLID_IViewInterfaceDefFlags					379	
#define LCLID_IViewInterfaceDefViewName					380			

// IViewRelationshipDef
#define LCLID_IViewRelationshipDef						381				
#define LCLID_IViewRelationshipDefFlags					382	
#define LCLID_IViewRelationshipDefColumnNamePrefix		383	
#define LCLID_IViewRelationshipDefJunctionViewName		384	

// IViewPropertyDef
#define LCLID_IViewPropertyDef							385	
#define LCLID_IViewPropertyDefViewColumnName			386	

// TransientRelationshipCol
#define	LCLID_TransientObjCol							387
#define	LCLID_ITransientObjCol							388
#define LCLID_ITransientObjColAdd						389
#define LCLID_ITransientObjColRemove					390
#define	LCLID_ITransientObjColAddReposObj				391
#define	LCLID_ITransientObjColRemoveItem				392

// TypeDef "Alias" 
#define LCLID_IReposTypeInfo2							393
#define LCLID_MemberSynonym								394
#define LCLID_Synonym									395

// IReposTypeLib2
#define LCLID_IReposTypeLib2Prefix						396

// IReposQuery
#define LCLID_IReposQuery								397
#define LCLID_IReposQueryGetCollection					398
#define LCLID_IReposQueryGetCollectionFilter			399
#define LCLID_IReposQueryGetCollectionfFlags			400
#define LCLID_IReposQueryGetCollectionObjCol			401

#define LCLID_RootVersionInternalID						402

// Some forgotten properties on IWorkspaceItem
#define LCLID_IsCheckedOut								403

// Last MetaMeta ID
#define LCLID_LastMetaMetaID							403

// Large Blob
const INTID INTID_SQLBlobSize		=	{SITEID_METAMETA, LCLID_SQLBlobSize}; 
const INTID INTID_IPropertyDef2		=	{SITEID_METAMETA, LCLID_IPropDef2};

// Internal ID definitions.
// Alias
const INTID	INTID_Alias						= {SITEID_METAMETA, LCLID_Alias};

// ParameterDef
const INTID	INTID_ParameterDef				= {SITEID_METAMETA, LCLID_ParameterDef};

// IVersionAdminInfo2
const INTID	INTID_IVersionAdminInfo2		= {SITEID_METAMETA, LCLID_IVersionAdminInfo2};
const INTID	INTID_IVersionLabel				= {SITEID_METAMETA, LCLID_VersionLabel};
const INTID	INTID_IVersionComments			= {SITEID_METAMETA, LCLID_VersionComments};
const INTID	INTID_IVersionShortDesc			= {SITEID_METAMETA, LCLID_VersionShortDesc};

// IIfaceDef2
const INTID INTID_IIfaceDef2				= {SITEID_METAMETA, LCLID_IIfaceDef2};
const INTID	INTID_IIfaceMember2				= {SITEID_METAMETA, LCLID_IIfaceMember2};

// RInterfaceImpliesInterface
const INTID INTID_RInterfaceImpliesInterface = {SITEID_METAMETA, LCLID_RInterfaceImpliesInterface};
const INTID INTID_Implies					= {SITEID_METAMETA, LCLID_Implies};
const INTID INTID_ImpliedBy					= {SITEID_METAMETA, LCLID_ImpliedBy};

// RBaseMemberServicesDerivedMembers
const INTID INTID_RBaseMemberServicesDerivedMembers	= {SITEID_METAMETA, LCLID_RBaseMemberServicesDerivedMembers};
const INTID INTID_ServicesDerivedMembers	= {SITEID_METAMETA, LCLID_ServicesDerivedMembers};
const INTID INTID_ServicedByBaseMember		= {SITEID_METAMETA, LCLID_ServicedByBaseMember};

// IMethodDef
const INTID INTID_IMethodDef				= {SITEID_METAMETA,LCLID_IMethodDef};

// IParameterDef
const INTID INTID_IParameterDef				= {SITEID_METAMETA,LCLID_IParameterDef};

// IParameterDef
const INTID INTID_ParDefFlags				= {SITEID_METAMETA,LCLID_ParDefFlags};
const INTID INTID_ParDefType				= {SITEID_METAMETA,LCLID_ParDefType};
const INTID INTID_ParDefDesc				= {SITEID_METAMETA,LCLID_ParDefDesc};
const INTID INTID_ParDefDefault				= {SITEID_METAMETA,LCLID_ParDefDefault};
const INTID INTID_ParDefGUID				= {SITEID_METAMETA,LCLID_ParDefGUID};

// MethodHasParameters
const INTID INTID_RInterfaceMemberHasParameters		= {SITEID_METAMETA,LCLID_RInterfaceMemberHasParameters};
const INTID INTID_Member					= {SITEID_METAMETA,LCLID_Member};
const INTID INTID_Parameters				= {SITEID_METAMETA,LCLID_Parameters};

// CreateParameterDef
const INTID INTID_CreateParDef				= {SITEID_METAMETA,LCLID_CreateParDef};
const INTID INTID_CreateParDefObjID			= {SITEID_METAMETA,LCLID_CreateParDefObjID};
const INTID INTID_CreateParDefName			= {SITEID_METAMETA,LCLID_CreateParDefName};
const INTID INTID_CreateParDefType			= {SITEID_METAMETA,LCLID_CreateParDefType};
const INTID INTID_CreateParDefFlags			= {SITEID_METAMETA,LCLID_CreateParDefFlags};
const INTID INTID_CreateParDefDesc			= {SITEID_METAMETA,LCLID_CreateParDefDesc};
const INTID INTID_CreateParDefDefault		= {SITEID_METAMETA,LCLID_CreateParDefDefault};
const INTID INTID_CreateParDefParDef		= {SITEID_METAMETA,LCLID_CreateParDefParDef};

// Class definitions
const INTID INTID_RepositoryObject							 = {SITEID_METAMETA, LCLID_RepositoryObject};
const INTID INTID_RepositoryObjectVersion					 = {SITEID_METAMETA, LCLID_RepositoryObjectVersion};
const INTID INTID_Relationship								 = {SITEID_METAMETA, LCLID_Relationship};
const INTID INTID_VersionedRelationship						 = {SITEID_METAMETA, LCLID_VersionedRelationship};
const INTID INTID_ReposProperty								 = {SITEID_METAMETA, LCLID_ReposProperty};
const INTID INTID_ReposProperties							 = {SITEID_METAMETA, LCLID_ReposProperties};
const INTID INTID_RelationshipCol							 = {SITEID_METAMETA, LCLID_RelationshipCol};
const INTID INTID_ObjectCol									 = {SITEID_METAMETA, LCLID_ObjectCol};
const INTID INTID_VersionCol								 = {SITEID_METAMETA, LCLID_VersionCol};
const INTID INTID_Repository								 = {SITEID_METAMETA, LCLID_Repository};

// Interface definitions	
const INTID INTID_IPropDef2									 = {SITEID_METAMETA, LCLID_IPropDef2};
const INTID INTID_IRepository								 = {SITEID_METAMETA, LCLID_IRepository};
const INTID INTID_IReposProperties							 = {SITEID_METAMETA, LCLID_IReposProperties};
const INTID INTID_IReposProperty							 = {SITEID_METAMETA, LCLID_IReposProperty};
const INTID INTID_IReposPropertyLarge						 = {SITEID_METAMETA, LCLID_IReposPropertyLarge};
const INTID INTID_IRepositoryTransaction					 = {SITEID_METAMETA, LCLID_IRepositoryTransaction};
const INTID INTID_IObjectCol								 = {SITEID_METAMETA, LCLID_IObjectCol};
const INTID INTID_ITargetObjectCol							 = {SITEID_METAMETA, LCLID_ITargetObjectCol};
const INTID INTID_IRepositoryObjectStorage					 = {SITEID_METAMETA, LCLID_IRepositoryObjectStorage};
const INTID INTID_IRelationshipCol							 = {SITEID_METAMETA, LCLID_IRelationshipCol};
const INTID INTID_IObjectCol2								 = {SITEID_METAMETA, LCLID_IObjectCol2};
const INTID INTID_IRepository2								 = {SITEID_METAMETA, LCLID_IRepository2};
const INTID INTID_IRepositoryODBC							 = {SITEID_METAMETA, LCLID_IRepositoryODBC};
const INTID INTID_IRepositoryODBC2							 = {SITEID_METAMETA, LCLID_IRepositoryODBC2};
const INTID INTID_IReposTypeLib2							 = {SITEID_METAMETA, LCLID_IReposTypeLib2};

// Property definitions
const INTID INTID_VersionLabel								 = {SITEID_METAMETA, LCLID_VersionLabel};
const INTID INTID_VersionShortDesc							 = {SITEID_METAMETA, LCLID_VersionShortDesc};
const INTID INTID_VersionComments							 = {SITEID_METAMETA, LCLID_VersionComments};

const INTID INTID_ReposPropLargeSize						 = {SITEID_METAMETA, LCLID_ReposPropLargeSize};
const INTID INTID_ReposPropLargePosition					 = {SITEID_METAMETA, LCLID_ReposPropLargeCurrentPosition};

// Method definitions
const INTID INTID_Create									 = {SITEID_METAMETA, LCLID_Create};
const INTID INTID_Open 										 = {SITEID_METAMETA, LCLID_Open};
const INTID INTID_CreateObject 								 = {SITEID_METAMETA, LCLID_CreateObject};
const INTID INTID_IRepositoryRefresh 						 = {SITEID_METAMETA, LCLID_IRepositoryRefresh};
const INTID INTID_ObjectIDToInternalID						 = {SITEID_METAMETA, LCLID_ObjectIDToInternalID};
const INTID INTID_InternalIDToObjectID						 = {SITEID_METAMETA, LCLID_InternalIDToObjectID};
const INTID INTID_Refresh 									 = {SITEID_METAMETA, LCLID_Refresh};
const INTID INTID_Delete 									 = {SITEID_METAMETA, LCLID_Delete};
const INTID INTID_Lock										 = {SITEID_METAMETA, LCLID_Lock};
const INTID INTID_Begin 									 = {SITEID_METAMETA, LCLID_Begin};
const INTID INTID_Commit									 = {SITEID_METAMETA, LCLID_Commit};
const INTID INTID_Abort										 = {SITEID_METAMETA, LCLID_Abort};
const INTID INTID_GetOption									 = {SITEID_METAMETA, LCLID_GetOption};
const INTID INTID_SetOption									 = {SITEID_METAMETA, LCLID_SetOption};
const INTID INTID_Flush										 = {SITEID_METAMETA, LCLID_Flush};
const INTID INTID_IVersionColRefresh 						 = {SITEID_METAMETA, LCLID_IVersionColRefresh};
const INTID INTID_IVersionColAdd							 = {SITEID_METAMETA, LCLID_IVersionColAdd};
const INTID INTID_IVersionColRemove							 = {SITEID_METAMETA, LCLID_IVersionColRemove};
const INTID INTID_CreateVersion 							 = {SITEID_METAMETA, LCLID_CreateVersion};
const INTID INTID_FreezeVersion								 = {SITEID_METAMETA, LCLID_FreezeVersion};
const INTID INTID_MergeVersion								 = {SITEID_METAMETA, LCLID_MergeVersion};
const INTID INTID_Checkout 									 = {SITEID_METAMETA, LCLID_Checkout};
const INTID INTID_Checkin									 = {SITEID_METAMETA, LCLID_Checkin};
const INTID INTID_IObjectColRefresh 						 = {SITEID_METAMETA, LCLID_IObjectColRefresh};
const INTID INTID_ITargetObjectColAdd 						 = {SITEID_METAMETA, LCLID_ITargetObjectColAdd};
const INTID INTID_ITargetObjectColRemove					 = {SITEID_METAMETA, LCLID_ITargetObjectColRemove};
const INTID INTID_ITargetObjectColInsert					 = {SITEID_METAMETA, LCLID_ITargetObjectColInsert};
const INTID INTID_ITargetObjectColMove						 = {SITEID_METAMETA, LCLID_ITargetObjectColMove};
const INTID INTID_InitNew 									 = {SITEID_METAMETA, LCLID_InitNew};
const INTID INTID_Load										 = {SITEID_METAMETA, LCLID_Load};
const INTID INTID_Pin 										 = {SITEID_METAMETA, LCLID_Pin};
const INTID INTID_Unpin										 = {SITEID_METAMETA, LCLID_Unpin};
const INTID INTID_IRelationshipColAdd 						 = {SITEID_METAMETA, LCLID_IRelationshipColAdd};
const INTID INTID_IRelationshipColRemove					 = {SITEID_METAMETA, LCLID_IRelationshipColRemove};
const INTID INTID_IRelationshipColInsert					 = {SITEID_METAMETA, LCLID_IRelationshipColInsert};
const INTID INTID_IRelationshipColMove						 = {SITEID_METAMETA, LCLID_IRelationshipColMove};
const INTID INTID_IRelationshipColRefresh					 = {SITEID_METAMETA, LCLID_IRelationshipColRefresh};
const INTID INTID_Cancel 									 = {SITEID_METAMETA, LCLID_Cancel};
const INTID INTID_VersionIDToInternalID 					 = {SITEID_METAMETA, LCLID_VersionIDToInternalID};
const INTID INTID_InternalIDToVersionID						 = {SITEID_METAMETA, LCLID_InternalIDToVersionID};
const INTID INTID_CreateObjectEx							 = {SITEID_METAMETA, LCLID_CreateObjectEx};
const INTID INTID_GetNewConnection 							 = {SITEID_METAMETA, LCLID_GetNewConnection};
const INTID INTID_FreeConnection							 = {SITEID_METAMETA, LCLID_FreeConnection};
const INTID INTID_ExecuteQuery								 = {SITEID_METAMETA, LCLID_ExecuteQuery};
const INTID INTID_IRepositoryODBC2GetOption					 = {SITEID_METAMETA, LCLID_IRepositoryODBC2GetOption};
const INTID INTID_IRepositoryODBC2SetOption					 = {SITEID_METAMETA, LCLID_IRepositoryODBC2SetOption};
const INTID INTID_CreateRelationshipColDef 					 = {SITEID_METAMETA, LCLID_CreateRelationshipColDef};
const INTID INTID_CreatePropertyDef							 = {SITEID_METAMETA, LCLID_CreatePropertyDef};
const INTID INTID_CreateMethodDef							 = {SITEID_METAMETA, LCLID_CreateMethodDef};
const INTID INTID_IInterfaceDefObjectInstances				 = {SITEID_METAMETA, LCLID_IInterfaceDefObjectInstances};
const INTID INTID_AddInterface 								 = {SITEID_METAMETA, LCLID_AddInterface};
const INTID INTID_IClassDefCreateInterfaceDef				 = {SITEID_METAMETA, LCLID_IClassDefCreateInterfaceDef};
const INTID INTID_IClassDefObjectInstances					 = {SITEID_METAMETA, LCLID_IClassDefObjectInstances};
const INTID INTID_CreateAlias 								 = {SITEID_METAMETA, LCLID_CreateAlias};
const INTID INTID_CreateClassDef 							 = {SITEID_METAMETA, LCLID_CreateClassDef};
const INTID INTID_CreateInterfaceDef						 = {SITEID_METAMETA, LCLID_CreateInterfaceDef};
const INTID INTID_CreateRelationshipDef						 = {SITEID_METAMETA, LCLID_CreateRelationshipDef};
const INTID INTID_CreateTypeLib 							 = {SITEID_METAMETA, LCLID_CreateTypeLib};
const INTID INTID_ReposPropLargeRead						 = {SITEID_METAMETA, LCLID_ReposPropLargeRead};
const INTID INTID_ReposPropLargeWrite						 = {SITEID_METAMETA, LCLID_ReposPropLargeWrite};
const INTID INTID_ReposPropLargeClose						 = {SITEID_METAMETA, LCLID_ReposPropLargeClose};
const INTID INTID_ReposPropLargeReadFromFile				 = {SITEID_METAMETA, LCLID_ReposPropLargeReadFromFile};
const INTID INTID_ReposPropLargeWriteToFile					 = {SITEID_METAMETA, LCLID_ReposPropLargeWriteToFile};

// Parameter definitions
// IRepository
const INTID INTID_CreateConnect								 = {SITEID_METAMETA, LCLID_CreateConnect};
const INTID INTID_CreateUser								 = {SITEID_METAMETA, LCLID_CreateUser};
const INTID INTID_CreatePassword							 = {SITEID_METAMETA, LCLID_CreatePassword};
const INTID INTID_CreateFlags								 = {SITEID_METAMETA, LCLID_CreateFlags};
const INTID INTID_CreateRoot								 = {SITEID_METAMETA, LCLID_CreateRoot};
const INTID INTID_OpenConnect								 = {SITEID_METAMETA, LCLID_OpenConnect};
const INTID INTID_OpenUser									 = {SITEID_METAMETA, LCLID_OpenUser};
const INTID INTID_OpenPassword								 = {SITEID_METAMETA, LCLID_OpenPassword};
const INTID INTID_OpenFlags									 = {SITEID_METAMETA, LCLID_OpenFlags};
const INTID INTID_OpenRoot									 = {SITEID_METAMETA, LCLID_OpenRoot};
const INTID INTID_CreateObjectTypeID						 = {SITEID_METAMETA, LCLID_CreateObjectTypeID};
const INTID INTID_CreateObjectObjID							 = {SITEID_METAMETA, LCLID_CreateObjectObjID};
const INTID INTID_CreateObjectReposObj						 = {SITEID_METAMETA, LCLID_CreateObjectReposObj};
const INTID INTID_IRepositoryRefreshMilliseconds			 = {SITEID_METAMETA, LCLID_IRepositoryRefreshMilliseconds};
const INTID INTID_ObjectIDToInternalIDObjID					 = {SITEID_METAMETA, LCLID_ObjectIDToInternalIDObjID};
const INTID INTID_ObjectIDToInternalIDIntID					 = {SITEID_METAMETA, LCLID_ObjectIDToInternalIDIntID};
const INTID INTID_InternalIDToObjectIDIntID					 = {SITEID_METAMETA, LCLID_InternalIDToObjectIDIntID};
const INTID INTID_InternalIDToObjectIDObjID					 = {SITEID_METAMETA, LCLID_InternalIDToObjectIDObjID};

// IRepositoryObject
const INTID INTID_RefreshMilliseconds						 = {SITEID_METAMETA, LCLID_RefreshMilliseconds};

// IRepositoryTransaction
const INTID INTID_GetOptionOption							 = {SITEID_METAMETA, LCLID_GetOptionOption};
const INTID INTID_GetOptionValue							 = {SITEID_METAMETA, LCLID_GetOptionValue};
const INTID INTID_SetOptionOption							 = {SITEID_METAMETA, LCLID_SetOptionOption};
const INTID INTID_SetOptionValue							 = {SITEID_METAMETA, LCLID_SetOptionValue};

// IVersionCol
const INTID INTID_IVersionColRefreshMilliseconds			 = {SITEID_METAMETA, LCLID_IVersionColRefreshMilliseconds};
const INTID INTID_IVersionColRemoveItem						 = {SITEID_METAMETA, LCLID_IVersionColRemoveItem};

// IRepositoryObject
const INTID INTID_CreateVersionVersoinID					 = {SITEID_METAMETA, LCLID_CreateVersionVersoinID};
const INTID INTID_CreateVersionCreatedVersion				 = {SITEID_METAMETA, LCLID_CreateVersionCreatedVersion};
const INTID INTID_MergeVersionOtherVersion					 = {SITEID_METAMETA, LCLID_MergeVersionOtherVersion};
const INTID INTID_MergeVersionFlags							 = {SITEID_METAMETA, LCLID_MergeVersionFlags};

// IObjectCol
const INTID INTID_IObjectColRefreshMilliseconds				 = {SITEID_METAMETA, LCLID_IObjectColRefreshMilliseconds};

// ITargetObjectCol
const INTID INTID_ITargetObjectColAddReposObj				 = {SITEID_METAMETA, LCLID_ITargetObjectColAddReposObj};
const INTID INTID_ITargetObjectColAddNamel					 = {SITEID_METAMETA, LCLID_ITargetObjectColAddNamel};
const INTID INTID_ITargetObjectColAddRelship				 = {SITEID_METAMETA, LCLID_ITargetObjectColAddRelship};
const INTID INTID_ITargetObjectColRemoveItem				 = {SITEID_METAMETA, LCLID_ITargetObjectColRemoveItem};
const INTID INTID_ITargetObjectColInsertReposObj			 = {SITEID_METAMETA, LCLID_ITargetObjectColInsertReposObj};
const INTID INTID_ITargetObjectColInsertIndex				 = {SITEID_METAMETA, LCLID_ITargetObjectColInsertIndex};
const INTID INTID_ITargetObjectColInsertName				 = {SITEID_METAMETA, LCLID_ITargetObjectColInsertName};
const INTID INTID_ITargetObjectColInsertRelship				 = {SITEID_METAMETA, LCLID_ITargetObjectColInsertRelship};
const INTID INTID_ITargetObjectColMoveIndexFrom				 = {SITEID_METAMETA, LCLID_ITargetObjectColMoveIndexFrom};
const INTID INTID_ITargetObjectColMoveIndexTo				 = {SITEID_METAMETA, LCLID_ITargetObjectColMoveIndexTo};

// IRepositoryObjectStorage
const INTID INTID_InitNewRepos								 = {SITEID_METAMETA, LCLID_InitNewRepos};
const INTID INTID_InitNewCookie								 = {SITEID_METAMETA, LCLID_InitNewCookie};
const INTID INTID_LoadRepos									 = {SITEID_METAMETA, LCLID_LoadRepos};
const INTID INTID_LoadCookie								 = {SITEID_METAMETA, LCLID_LoadCookie};

// IVersionedRelationship
const INTID INTID_PinReposVersion							 = {SITEID_METAMETA, LCLID_PinReposVersion};

// IRelationshipCol
const INTID INTID_IRelationshipColAddReposObj				 = {SITEID_METAMETA, LCLID_IRelationshipColAddReposObj};
const INTID INTID_IRelationshipColAddName					 = {SITEID_METAMETA, LCLID_IRelationshipColAddName};
const INTID INTID_IRelationshipColAddRemove					 = {SITEID_METAMETA, LCLID_IRelationshipColAddRemove};
const INTID INTID_IRelationshipColInsertReposObj			 = {SITEID_METAMETA, LCLID_IRelationshipColInsertReposObj};
const INTID INTID_IRelationshipColInsertIndex				 = {SITEID_METAMETA, LCLID_IRelationshipColInsertIndex};
const INTID INTID_IRelationshipColInsertName				 = {SITEID_METAMETA, LCLID_IRelationshipColInsertName};
const INTID INTID_IRelationshipColInsertRelship				 = {SITEID_METAMETA, LCLID_IRelationshipColInsertRelship};
const INTID INTID_IRelationshipColMoveIndexFrom				 = {SITEID_METAMETA, LCLID_IRelationshipColMoveIndexFrom};
const INTID INTID_IRelationshipColMoveIndexTo				 = {SITEID_METAMETA, LCLID_IRelationshipColMoveIndexTo};

const INTID INTID_IRelationshipColRefreshMilliseconds					 = {SITEID_METAMETA, LCLID_IRelationshipColRefreshMilliseconds};

// IRepository2
const INTID INTID_VersionIDToInternalIDExtVersionID			 = {SITEID_METAMETA, LCLID_VersionIDToInternalIDExtVersionID};
const INTID INTID_VersionIDToInternalIDIntVersionID			 = {SITEID_METAMETA, LCLID_VersionIDToInternalIDIntVersionID};
const INTID INTID_InternalIDToVersionIDIntVersionID			 = {SITEID_METAMETA, LCLID_InternalIDToVersionIDIntVersionID};
const INTID INTID_InternalIDToVersionIDExtVersionID			 = {SITEID_METAMETA, LCLID_InternalIDToVersionIDExtVersionID};

// IRepositoryODBC
const INTID INTID_GetNewConnectionHdbc						 = {SITEID_METAMETA, LCLID_GetNewConnectionHdbc};
const INTID INTID_FreeConnecionHdbc							 = {SITEID_METAMETA, LCLID_FreeConnecionHdbc};
const INTID INTID_ExecuteQueryQuery							 = {SITEID_METAMETA, LCLID_ExecuteQueryQuery};
const INTID INTID_ExecuteQueryCol							 = {SITEID_METAMETA, LCLID_ExecuteQueryCol};

// IRepositoryODBC2
const INTID INTID_IRepositoryODBC2GetOptionOption			 = {SITEID_METAMETA, LCLID_IRepositoryODBC2GetOptionOption};
const INTID INTID_IRepositoryODBC2GetOptionValue			 = {SITEID_METAMETA, LCLID_IRepositoryODBC2GetOptionValue};
const INTID INTID_IRepositoryODBC2SetOptionOption			 = {SITEID_METAMETA, LCLID_IRepositoryODBC2SetOptionOption};
const INTID INTID_IRepositoryODBC2SetOptionValue			 = {SITEID_METAMETA, LCLID_IRepositoryODBC2SetOptionValue};

// IInterfaceDef
const INTID INTID_CreateRelationshipColDefObjID				 = {SITEID_METAMETA, LCLID_CreateRelationshipColDefObjID};
const INTID INTID_CreateRelationshipColDefName				 = {SITEID_METAMETA, LCLID_CreateRelationshipColDefName};
const INTID INTID_CreateRelationshipColDefDispID			 = {SITEID_METAMETA, LCLID_CreateRelationshipColDefDispID};
const INTID INTID_CreateRelationshipColDefIsOrigin			 = {SITEID_METAMETA, LCLID_CreateRelationshipColDefIsOrigin};
const INTID INTID_CreateRelationshipColDefFlags				 = {SITEID_METAMETA, LCLID_CreateRelationshipColDefFlags};
const INTID INTID_CreateRelationshipColDefRelshipDef		 = {SITEID_METAMETA, LCLID_CreateRelationshipColDefRelshipDef};
const INTID INTID_CreateRelationshipColDefColDef			 = {SITEID_METAMETA, LCLID_CreateRelationshipColDefColDef};
const INTID INTID_CreatePropertyDefObjID					 = {SITEID_METAMETA, LCLID_CreatePropertyDefObjID};
const INTID INTID_CreatePropertyDefName						 = {SITEID_METAMETA, LCLID_CreatePropertyDefName};
const INTID INTID_CreatePropertyDefDispID					 = {SITEID_METAMETA, LCLID_CreatePropertyDefDispID};
const INTID INTID_CreatePropertyDefType						 = {SITEID_METAMETA, LCLID_CreatePropertyDefType};
const INTID INTID_CreatePropertyDefPropDef					 = {SITEID_METAMETA, LCLID_CreatePropertyDefPropDef};
const INTID INTID_CreateMethodDefObjID						 = {SITEID_METAMETA, LCLID_CreateMethodDefObjID};
const INTID INTID_CreateMethodDefName						 = {SITEID_METAMETA, LCLID_CreateMethodDefName};
const INTID INTID_CreateMethodDefDispID						 = {SITEID_METAMETA, LCLID_CreateMethodDefDispID};
const INTID INTID_CreateMethodDefMethodDef					 = {SITEID_METAMETA, LCLID_CreateMethodDefMethodDef};
const INTID INTID_IInterfaceDefObjectInstancesObject		 = {SITEID_METAMETA, LCLID_IInterfaceDefObjectInstancesObject};

// IClassDef
const INTID INTID_AddInterfaceInterfaceDef					 = {SITEID_METAMETA, LCLID_AddInterfaceInterfaceDef};
const INTID INTID_AddInterfaceFlags							 = {SITEID_METAMETA, LCLID_AddInterfaceFlags};
const INTID INTID_ClassDefCreateInterfaceDefObjID			 = {SITEID_METAMETA, LCLID_ClassDefCreateInterfaceDefObjID};
const INTID INTID_ClassDefCreateInterfaceDefName			 = {SITEID_METAMETA, LCLID_ClassDefCreateInterfaceDefName};
const INTID INTID_ClassDefCreateInterfaceDefIID				 = {SITEID_METAMETA, LCLID_ClassDefCreateInterfaceDefIID};
const INTID INTID_ClassDefCreateInterfaceDefAncestor		 = {SITEID_METAMETA, LCLID_ClassDefCreateInterfaceDefAncestor};
const INTID INTID_ClassDefCreateInterfaceDefFlags			 = {SITEID_METAMETA, LCLID_ClassDefCreateInterfaceDefFlags};
const INTID INTID_ClassDefCreateInterfaceDefIfaceDef		 = {SITEID_METAMETA, LCLID_ClassDefCreateInterfaceDefIfaceDef};
const INTID INTID_IClassDefObjectInstancesObjectCol			 = {SITEID_METAMETA, LCLID_IClassDefObjectInstancesObjectCol};

// IInterfaceDef2
const INTID INTID_CreateAliasObjID							 = {SITEID_METAMETA, LCLID_CreateAliasObjID};
const INTID INTID_CreateAliasName							 = {SITEID_METAMETA, LCLID_CreateAliasName};
const INTID INTID_CreateAliasDispID							 = {SITEID_METAMETA, LCLID_CreateAliasDispID};
const INTID INTID_CreateAliasBase							 = {SITEID_METAMETA, LCLID_CreateAliasBase};
const INTID INTID_CreateAliasAlias							 = {SITEID_METAMETA, LCLID_CreateAliasAlias};

// IReposTypeLib
const INTID INTID_CreateClassDefObjID						 = {SITEID_METAMETA, LCLID_CreateClassDefObjID};
const INTID INTID_CreateClassDefName						 = {SITEID_METAMETA, LCLID_CreateClassDefName};
const INTID INTID_CreateClassDefClassID						 = {SITEID_METAMETA, LCLID_CreateClassDefClassID};
const INTID INTID_CreateClassDefClassDef					 = {SITEID_METAMETA, LCLID_CreateClassDefClassDef};
const INTID INTID_CreateInterfaceDefObjID					 = {SITEID_METAMETA, LCLID_CreateInterfaceDefObjID};
const INTID INTID_CreateInterfaceDefName					 = {SITEID_METAMETA, LCLID_CreateInterfaceDefName};
const INTID INTID_CreateInterfaceDefIID						 = {SITEID_METAMETA, LCLID_CreateInterfaceDefIID};
const INTID INTID_CreateInterfaceDefAncestor				 = {SITEID_METAMETA, LCLID_CreateInterfaceDefAncestor};
const INTID INTID_CreateInterfaceDefIfaceDef				 = {SITEID_METAMETA, LCLID_CreateInterfaceDefIfaceDef};
const INTID INTID_CreateRelationshipDefObjID				 = {SITEID_METAMETA, LCLID_CreateRelationshipDefObjID};
const INTID INTID_CreateRelationshipDefName					 = {SITEID_METAMETA, LCLID_CreateRelationshipDefName};
const INTID INTID_CreateRelationshipDefRelshipDef			 = {SITEID_METAMETA, LCLID_CreateRelationshipDefRelshipDef};

// IManageReposTypeLib
const INTID INTID_CreateTypeLibObjID						 = {SITEID_METAMETA, LCLID_CreateTypeLibObjID};
const INTID INTID_CreateTypeLibName							 = {SITEID_METAMETA, LCLID_CreateTypeLibName};
const INTID INTID_CreateTypeLibTypeLibID					 = {SITEID_METAMETA, LCLID_CreateTypeLibTypeLibID};
const INTID INTID_CreateTypeLibTypeLib						 = {SITEID_METAMETA, LCLID_CreateTypeLibTypeLib};

// IRepositoryPropertyLarge
const INTID INTID_IRepositoryPropertyLargeReadChunkSize		 = {SITEID_METAMETA, LCLID_IRepositoryPropertyLargeReadChunkSize};
const INTID INTID_IRepositoryPropertyLargeReadSizeRead		 = {SITEID_METAMETA, LCLID_IRepositoryPropertyLargeReadSizeRead};
const INTID INTID_IRepositoryPropertyLargeReadBlob			 = {SITEID_METAMETA, LCLID_IRepositoryPropertyLargeReadBlob};
const INTID INTID_IRepositoryPropertyLargeWriteBlob			 = {SITEID_METAMETA, LCLID_IRepositoryPropertyLargeWriteBlob};
const INTID INTID_IRepositoryPropertyLargeReadFromFileFileName = {SITEID_METAMETA, LCLID_IRepositoryPropertyLargeReadFromFileFileName};
const INTID INTID_IRepositoryPropertyLargeWriteToFileFileName = {SITEID_METAMETA, LCLID_IRepositoryPropertyLargeWriteToFileFileName};

// IReposTypeLib2
const INTID INTID_RReposTypeLib2Dependency					 = {SITEID_METAMETA, LCLID_RReposTypeLib2Dependency};
const INTID INTID_IReposTypeLib2DependsOn					 = {SITEID_METAMETA, LCLID_IReposTypeLib2DependsOn};
const INTID INTID_IReposTypeLib2UsedBy						 = {SITEID_METAMETA, LCLID_IReposTypeLib2UsedBy};

// IReposOptions
const INTID INTID_IReposOptions								 = {SITEID_METAMETA, LCLID_IReposOptions};
const INTID INTID_IReposOptionsGetOption					 = {SITEID_METAMETA, LCLID_IReposOptionsGetOption};
const INTID INTID_IReposOptionsSetOption					 = {SITEID_METAMETA, LCLID_IReposOptionsSetOption};
const INTID INTID_IReposOptionsResetOptions					 = {SITEID_METAMETA, LCLID_IReposOptionsResetOptions};
const INTID INTID_IReposOptionsGetOptionOption				 = {SITEID_METAMETA, LCLID_IReposOptionsGetOptionOption};
const INTID INTID_IReposOptionsGetOptionValue				 = {SITEID_METAMETA, LCLID_IReposOptionsGetOptionValue};
const INTID INTID_IReposOptionsSetOptionOption				 = {SITEID_METAMETA, LCLID_IReposOptionsSetOptionOption};
const INTID INTID_IReposOptionsSetOptionValue				 = {SITEID_METAMETA, LCLID_IReposOptionsSetOptionValue};

// ScriptDef
const INTID INTID_ScriptDef									= {SITEID_METAMETA, LCLID_ScriptDef};
const INTID INTID_IScriptDef								= {SITEID_METAMETA, LCLID_IScriptDef};
const INTID INTID_IScriptDefLanguage						= {SITEID_METAMETA, LCLID_IScriptDefLanguage};
const INTID INTID_IScriptDefBody							= {SITEID_METAMETA, LCLID_IScriptDefBody};
const INTID INTID_IScriptDefValidateScript					= {SITEID_METAMETA, LCLID_IScriptDefValidateScript};
const INTID INTID_RClassUsesScript							= {SITEID_METAMETA, LCLID_RClassUsesScript			};
const INTID INTID_UsingClasses								= {SITEID_METAMETA, LCLID_UsingClasses		};
const INTID INTID_ScriptsUsedByClass						= {SITEID_METAMETA, LCLID_ScriptsUsedByClass		};
const INTID INTID_RInterafceUsesScript						= {SITEID_METAMETA, LCLID_RInterafceUsesScript		};
const INTID INTID_UsingInterfaces							= {SITEID_METAMETA, LCLID_UsingInterfaces	};
const INTID INTID_ScriptsUsedByInterface					= {SITEID_METAMETA, LCLID_ScriptsUsedByInterface	};
const INTID INTID_RMemberUsesScript							= {SITEID_METAMETA, LCLID_RMemberUsesScript			};
const INTID INTID_UsingMember								= {SITEID_METAMETA, LCLID_UsingMember			};
const INTID INTID_ScriptsUsedByMember						= {SITEID_METAMETA, LCLID_ScriptsUsedByMember		};
const INTID INTID_IClassDef2								= {SITEID_METAMETA, LCLID_IClassDef2				};

// IRepositoryTransaction2
const INTID INTID_IRepositoryTransaction2					= {SITEID_METAMETA, LCLID_IRepositoryTransaction2};
const INTID INTID_IRepositoryTransaction2Transaction		= {SITEID_METAMETA, LCLID_IRepositoryTransaction2Transaction};
const INTID INTID_IRepositoryTransaction2JoinTransaction	= {SITEID_METAMETA, LCLID_IRepositoryTransaction2JoinTransaction};

// IReposProperty2
const INTID INTID_IReposProperty2							= {SITEID_METAMETA, LCLID_IReposProperty2};

// IReposObj2
const INTID INTID_IReposObj2								= {SITEID_METAMETA, LCLID_IReposObj2};

// IEnumerationDef
const INTID INTID_EnumerationDef							= {SITEID_METAMETA, LCLID_EnumerationDef};
const INTID INTID_IEnumerationDef							= {SITEID_METAMETA, LCLID_IEnumerationDef};
const INTID INTID_IEnumerationDefIsFlag						= {SITEID_METAMETA, LCLID_IEnumerationDefIsFlag};
const INTID INTID_IEnumerationDefValues						= {SITEID_METAMETA, LCLID_IEnumerationDefValues};
const INTID INTID_IEnumerationDefEnumFor					= {SITEID_METAMETA, LCLID_IEnumerationDefEnumFor};
const INTID INTID_REnumerationValues						= {SITEID_METAMETA, LCLID_REnumerationValues};

// IEnumerationValueDef
const INTID INTID_EnumerationValueDef						= {SITEID_METAMETA, LCLID_EnumerationValueDef};
const INTID INTID_IEnumerationValueDef						= {SITEID_METAMETA, LCLID_IEnumerationValueDef};
const INTID INTID_IEnumerationValueDefValue					= {SITEID_METAMETA, LCLID_IEnumerationValueDefValue};
const INTID INTID_IEnumerationValueDefValueOf				= {SITEID_METAMETA, LCLID_IEnumerationValueDefValueOf};

// IPropDef2
const INTID INTID_PropDefEnumerationDef						= {SITEID_METAMETA, LCLID_PropDefEnumerationDef};
const INTID INTID_REnumerationForProperty					= {SITEID_METAMETA, LCLID_REnumerationForProperty};

// IViewClassDef
const INTID INTID_IViewClassDef								= {SITEID_METAMETA, LCLID_IViewClassDef};
const INTID INTID_IViewClassDefFlags						= {SITEID_METAMETA, LCLID_IViewClassDefFlags};
const INTID INTID_IViewClassDefViewName						= {SITEID_METAMETA, LCLID_IViewClassDefViewName};

// IViewInterfaceDef
const INTID INTID_IViewInterfaceDef							= {SITEID_METAMETA, LCLID_IViewInterfaceDef};
const INTID INTID_IViewInterfaceDefFlags					= {SITEID_METAMETA, LCLID_IViewInterfaceDefFlags};
const INTID INTID_IViewInterfaceDefViewName					= {SITEID_METAMETA, LCLID_IViewInterfaceDefViewName};

// IViewRelationshipDef
const INTID INTID_IViewRelationshipDef						= {SITEID_METAMETA, LCLID_IViewRelationshipDef};		
const INTID INTID_IViewRelationshipDefFlags					= {SITEID_METAMETA, LCLID_IViewRelationshipDefFlags};
const INTID INTID_IViewRelationshipDefColumnNamePrefix		= {SITEID_METAMETA, LCLID_IViewRelationshipDefColumnNamePrefix};
const INTID INTID_IViewRelationshipDefJunctionViewName		= {SITEID_METAMETA, LCLID_IViewRelationshipDefJunctionViewName};

// IViewPropertyDef
const INTID INTID_IViewPropertyDef							= {SITEID_METAMETA, LCLID_IViewPropertyDef};
const INTID INTID_IViewPropertyDefViewColumnName			= {SITEID_METAMETA, LCLID_IViewPropertyDefViewColumnName};

// Always the last one
// TransientRelationshipCol
const INTID INTID_TransientObjCol							= {SITEID_METAMETA, LCLID_TransientObjCol};
const INTID INTID_ITransientObjCol							= {SITEID_METAMETA, LCLID_ITransientObjCol};
const INTID INTID_ITransientObjColAdd						= {SITEID_METAMETA, LCLID_ITransientObjColAdd};
const INTID INTID_ITransientObjColRemove					= {SITEID_METAMETA, LCLID_ITransientObjColRemove};
const INTID INTID_ITransientObjColAddReposObj				= {SITEID_METAMETA, LCLID_ITransientObjColAddReposObj};
const INTID INTID_ITransientObjColRemoveItem				= {SITEID_METAMETA, LCLID_ITransientObjColRemoveItem};

const INTID INTID_IReposTypeInfo2							= {SITEID_METAMETA, LCLID_IReposTypeInfo2};
const INTID INTID_MemberSynonym								= {SITEID_METAMETA, LCLID_MemberSynonym};
const INTID INTID_Synonym									= {SITEID_METAMETA, LCLID_Synonym};

const INTID	INTID_IReposQuery								= {SITEID_METAMETA, LCLID_IReposQuery};
const INTID	INTID_IReposQueryGetCollection					= {SITEID_METAMETA, LCLID_IReposQueryGetCollection};

const INTID INTID_RootVersionInternalID						= {SITEID_METAMETA, LCLID_RootVersionInternalID};

const INTID INTID_IsCheckedOut								= {SITEID_METAMETA, LCLID_IsCheckedOut};

const INTID INTID_LastMetaMetaID							= {SITEID_METAMETA, LCLID_LastMetaMetaID};

// DispatchID definitions.
#define DISPID_SQLBlobSize						LCLID_SQLBlobSize 
#define DISPID_Implies							LCLID_Implies
#define DISPID_ImpliedBy						LCLID_ImpliedBy
#define DISPID_ServicesDerivedMembers			LCLID_ServicesDerivedMembers
#define DISPID_ServicedByBaseMember				LCLID_ServicedByBaseMember
												
#define DISPID_VersionLabel						LCLID_VersionLabel
#define DISPID_VersionComments					LCLID_VersionComments
#define DISPID_VersionShortDesc					LCLID_VersionShortDesc
												
#define DISPID_ParDefFlags						LCLID_ParDefFlags
#define DISPID_ParDefType						LCLID_ParDefType
#define DISPID_ParDefDesc						LCLID_ParDefDesc
#define DISPID_ParDefDefault					LCLID_ParDefDefault
#define DISPID_ParDefGUID						LCLID_ParDefGUID
												
#define DISPID_Member							LCLID_Member
#define DISPID_Parameters						LCLID_Parameters
#define DISPID_CreateParDef						LCLID_CreateParDef

#define DISPID_IReposTypeLib2DependsOn			LCLID_IReposTypeLib2DependsOn
#define DISPID_IReposTypeLib2UsedBy				LCLID_IReposTypeLib2UsedBy
#define DISPID_IReposTypeLib2Prefix				LCLID_IReposTypeLib2Prefix

#define DISPID_AddInterface						1	// These DispIDs are from REPAUTO.ODL
#define DISPID_IClassDefCreateInterfaceDef		2
#define DISPID_IClassDefObjectInstances			3
#define DISPID_CreatePropertyDef				2
#define DISPID_CreateMethodDef					3
#define DISPID_CreateRelationshipColDef			1
#define DISPID_IInterfaceDefObjectInstances		4
#define DISPID_CreateTypeLib					1
#define DISPID_IReposItemDelete					4
#define DISPID_Lock								5
#define DISPID_Refresh							22
#define DISPID_CreateClassDef					1
#define DISPID_CreateInterfaceDef				2
#define DISPID_CreateRelationshipDef			3
#define DISPID_IVersionColRefresh				2
#define DISPID_IVersionColAdd     				3
#define DISPID_IVersionColRemove  				4
#define DISPID_IObjectColRefresh				2
#define DISPID_IObjectCol2Cancel				6
#define DISPID_IRelationshipColAdd				2
#define DISPID_IRelationshipColRemove 			3
#define DISPID_IRelationshipColInsert 			5
#define DISPID_IRelationshipColMove   			6
#define DISPID_IRelationshipColRefresh			7
#define DISPID_ITargetObjectColAdd    			20
#define DISPID_ITargetObjectColRemove 			21
#define DISPID_ITargetObjectColInsert 			22
#define DISPID_ITargetObjectColMove   			32
#define DISPID_GetNewConnection					2
#define DISPID_FreeConnection					3
#define DISPID_ExecuteQuery						5
#define DISPID_Begin     						1
#define DISPID_Commit    						2
#define DISPID_Abort     						3
#define DISPID_GetOption						5
#define DISPID_SetOption 						6
#define DISPID_Flush     						7
#define DISPID_IRepositoryTransaction2Transaction 8
#define DISPID_IRepositoryTransaction2JoinTransaction 9
#define DISPID_Create							1
#define DISPID_Open                           	2
#define DISPID_CreateObject                   	3
#define DISPID_IRepositoryRefresh             	6
#define DISPID_ObjectIDToInternalID				7
#define DISPID_InternalIDToObjectID				8
#define DISPID_LCLID_VersionIDToInternalID		12
#define DISPID_LCLID_InternalIDToVersionID		13
#define DISPID_InitNew							1
#define DISPID_Load   							2
#define DISPID_Checkout							61
#define DISPID_Checkin 							62
#define DISPID_CreateVersion					47
#define DISPID_FreezeVersion					48
#define DISPID_MergeVersion 					49
#define DISPID_Pin								31
#define DISPID_Unpin							32
#define DISPID_Cancel							6
#define DISPID_VersionIDToInternalID			12
#define DISPID_InternalIDToVersionID			13
#define DISPID_CreateObjectEx					16
#define DISPID_CreateAlias						5
#define DISPID_ReposPropLargeSize				32
#define DISPID_ReposPropLargeRead				30
#define DISPID_ReposPropLargeWrite				31
#define DISPID_ReposPropLargeClose				33
#define DISPID_ReposPropLargeReadFromFile		34
#define DISPID_ReposPropLargeWriteToFile		35
#define DISPID_IRepositoryODBC2GetOption		34
#define DISPID_IRepositoryODBC2SetOption		35
#define DISPID_IReposOptionsGetOption			1
#define DISPID_IReposOptionsSetOption			2
#define DISPID_IReposOptionsResetOptions		3
#define DISPID_IScriptDefLanguage				LCLID_IScriptDefLanguage			
#define DISPID_IScriptDefBody					LCLID_IScriptDefBody				
#define DISPID_IScriptDefValidateScript			LCLID_IScriptDefValidateScript		
#define DISPID_UsingClasses						LCLID_UsingClasses					
#define DISPID_ScriptsUsedByClass				LCLID_ScriptsUsedByClass			
#define	DISPID_UsingInterfaces					LCLID_UsingInterfaces				
#define	DISPID_ScriptsUsedByInterface			LCLID_ScriptsUsedByInterface		
#define	DISPID_UsingMember						LCLID_UsingMember					
#define	DISPID_ScriptsUsedByMember				LCLID_ScriptsUsedByMember
#define DISPID_IReposProp2PropType				40
#define DISPID_IReposProp2IsBaseMember			41
#define DISPID_IReposProp2APIType				42
#define DISPID_IReposProp2IsOriginCollection	43
#define DISPID_IReposObj2ClassType				30
#define DISPID_IReposObj2ClassName				31
#define DISPID_PropDefEnumerationDef			LCLID_PropDefEnumerationDef
#define DISPID_IEnumerationDefIsFlag			LCLID_IEnumerationDefIsFlag
#define DISPID_IEnumerationDefValues			LCLID_IEnumerationDefValues
#define DISPID_IEnumerationDefEnumFor			LCLID_IEnumerationDefEnumFor
#define DISPID_IEnumerationValueDefValue		LCLID_IEnumerationValueDefValue
#define DISPID_IEnumerationValueDefValueOf		LCLID_IEnumerationValueDefValueOf
#define DISPID_IViewClassDef					LCLID_IViewClassDef
#define DISPID_IViewClassDefFlags				LCLID_IViewClassDefFlags
#define DISPID_IViewClassDefViewName			LCLID_IViewClassDefViewName
#define DISPID_IViewInterfaceDef				LCLID_IViewInterfaceDef
#define DISPID_IViewInterfaceDefFlags			LCLID_IViewInterfaceDefFlags
#define DISPID_IViewInterfaceDefViewName		LCLID_IViewInterfaceDefViewName
#define DISPID_IViewRelationshipDef				LCLID_IViewRelationshipDef
#define DISPID_IViewRelationshipDefJunctionViewName	LCLID_IViewRelationshipDefJunctionViewName
#define DISPID_IViewRelationshipDefColumnNamePrefix	LCLID_IViewRelationshipDefColumnNamePrefix
#define DISPID_IViewRelationshipDefFlags		LCLID_IViewRelationshipDefFlags
#define DISPID_IViewPropertyDef					LCLID_IViewPropertyDef
#define DISPID_IViewPropertyDefViewColumnName	LCLID_IViewPropertyDefViewColumnName
#define DISPID_ITransientObjColAdd				20
#define DISPID_ITransientObjColRemove			21
#define DISPID_MemberSynonym					LCLID_MemberSynonym
#define DISPID_Synonym							LCLID_Synonym
#define DISPID_IReposQueryGetCollection			LCLID_IReposQueryGetCollection
#define DISPID_IsCheckedOut						65		

// Object ID definitions.
// Large Blob
DEFINE_OBJID(OBJID_SQLBlobSize, LCLID_SQLBlobSize, METAMETA_GUID); 
DEFINE_OBJID(OBJID_IPropertyDef2, LCLID_IPropDef2, METAMETA_GUID); 

DEFINE_OBJID(OBJID_Alias,			LCLID_Alias,	METAMETA_GUID);

DEFINE_OBJID(OBJID_IVersionAdminInfo2,		LCLID_IVersionAdminInfo2,	METAMETA_GUID);
DEFINE_OBJID(OBJID_IIfaceDef2,				LCLID_IIfaceDef2,			METAMETA_GUID);
DEFINE_OBJID(OBJID_IIfaceMember2,			LCLID_IIfaceMember2,		METAMETA_GUID);

DEFINE_OBJID(OBJID_RInterfaceImpliesInterface,				LCLID_RInterfaceImpliesInterface,		METAMETA_GUID);
DEFINE_OBJID(OBJID_RBaseMemberServicesDerivedMembers,		LCLID_RBaseMemberServicesDerivedMembers,METAMETA_GUID);

DEFINE_OBJID(OBJID_Implies,			LCLID_Implies,			METAMETA_GUID);
DEFINE_OBJID(OBJID_ImpliedBy,		LCLID_ImpliedBy,		METAMETA_GUID);
DEFINE_OBJID(OBJID_ServicesDerivedMembers,	LCLID_ServicesDerivedMembers,	METAMETA_GUID);
DEFINE_OBJID(OBJID_ServicedByBaseMember,	LCLID_ServicedByBaseMember,		METAMETA_GUID);

DEFINE_OBJID(OBJID_VersionLabel,	LCLID_VersionLabel,		METAMETA_GUID);
DEFINE_OBJID(OBJID_VersionComments, LCLID_VersionComments,	METAMETA_GUID);
DEFINE_OBJID(OBJID_VersionShortDesc,LCLID_VersionShortDesc, METAMETA_GUID);

DEFINE_OBJID(OBJID_RInterfaceMemberHasParameters,LCLID_RInterfaceMemberHasParameters,	METAMETA_GUID);
DEFINE_OBJID(OBJID_Member,				LCLID_Member,				METAMETA_GUID);
DEFINE_OBJID(OBJID_Parameters,			LCLID_Parameters,			METAMETA_GUID);

DEFINE_OBJID(OBJID_IMethodDef,			LCLID_IMethodDef,			METAMETA_GUID);

DEFINE_OBJID(OBJID_IParameterDef,	LCLID_IParameterDef,		METAMETA_GUID);
DEFINE_OBJID(OBJID_ParDefFlags,		LCLID_ParDefFlags,			METAMETA_GUID);
DEFINE_OBJID(OBJID_ParDefType,		LCLID_ParDefType,			METAMETA_GUID);
DEFINE_OBJID(OBJID_ParDefDesc,		LCLID_ParDefDesc,			METAMETA_GUID);
DEFINE_OBJID(OBJID_ParDefDefault,	LCLID_ParDefDefault,		METAMETA_GUID);
DEFINE_OBJID(OBJID_ParDefGUID,		LCLID_ParDefGUID,			METAMETA_GUID);

DEFINE_OBJID(OBJID_ParameterDef,	LCLID_ParameterDef,			METAMETA_GUID);

DEFINE_OBJID(OBJID_CreateParDef,		LCLID_CreateParDef,			METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateParDefObjID,	LCLID_CreateParDefObjID,	METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateParDefName,	LCLID_CreateParDefName,		METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateParDefType,	LCLID_CreateParDefType,		METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateParDefFlags,	LCLID_CreateParDefFlags,	METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateParDefDesc,	LCLID_CreateParDefDesc,		METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateParDefDefault, LCLID_CreateParDefDefault,	METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateParDefParDef,	LCLID_CreateParDefParDef,	METAMETA_GUID);

// Class definitions.
DEFINE_OBJID(OBJID_RepositoryObject					   , LCLID_RepositoryObject                    , METAMETA_GUID);
DEFINE_OBJID(OBJID_RepositoryObjectVersion			   , LCLID_RepositoryObjectVersion             , METAMETA_GUID);
DEFINE_OBJID(OBJID_Relationship						   , LCLID_Relationship                        , METAMETA_GUID);
DEFINE_OBJID(OBJID_VersionedRelationship			   , LCLID_VersionedRelationship               , METAMETA_GUID);
DEFINE_OBJID(OBJID_ReposProperty					   , LCLID_ReposProperty                       , METAMETA_GUID);
DEFINE_OBJID(OBJID_ReposProperties					   , LCLID_ReposProperties                     , METAMETA_GUID);
DEFINE_OBJID(OBJID_RelationshipCol					   , LCLID_RelationshipCol                     , METAMETA_GUID);
DEFINE_OBJID(OBJID_ObjectCol						   , LCLID_ObjectCol                           , METAMETA_GUID);
DEFINE_OBJID(OBJID_VersionCol						   , LCLID_VersionCol                          , METAMETA_GUID);
DEFINE_OBJID(OBJID_Repository						   , LCLID_Repository                          , METAMETA_GUID);

// Interface definitions
DEFINE_OBJID(OBJID_IPropDef2						   , LCLID_IPropDef2                           , METAMETA_GUID);
DEFINE_OBJID(OBJID_IRepository						   , LCLID_IRepository                         , METAMETA_GUID);
DEFINE_OBJID(OBJID_IReposProperties					   , LCLID_IReposProperties                    , METAMETA_GUID);
DEFINE_OBJID(OBJID_IReposProperty					   , LCLID_IReposProperty                      , METAMETA_GUID);
DEFINE_OBJID(OBJID_IReposPropertyLarge				   , LCLID_IReposPropertyLarge                 , METAMETA_GUID);
DEFINE_OBJID(OBJID_IRepositoryTransaction			   , LCLID_IRepositoryTransaction              , METAMETA_GUID);
DEFINE_OBJID(OBJID_IObjectCol						   , LCLID_IObjectCol                          , METAMETA_GUID);
DEFINE_OBJID(OBJID_ITargetObjectCol					   , LCLID_ITargetObjectCol                    , METAMETA_GUID);
DEFINE_OBJID(OBJID_IRepositoryObjectStorage			   , LCLID_IRepositoryObjectStorage            , METAMETA_GUID);
DEFINE_OBJID(OBJID_IRelationshipCol					   , LCLID_IRelationshipCol                    , METAMETA_GUID);
DEFINE_OBJID(OBJID_IObjectCol2						   , LCLID_IObjectCol2                         , METAMETA_GUID);
DEFINE_OBJID(OBJID_IRepository2						   , LCLID_IRepository2                        , METAMETA_GUID);
DEFINE_OBJID(OBJID_IRepositoryODBC					   , LCLID_IRepositoryODBC                     , METAMETA_GUID);
DEFINE_OBJID(OBJID_IRepositoryODBC2					   , LCLID_IRepositoryODBC2                    , METAMETA_GUID);
DEFINE_OBJID(OBJID_IReposTypeLib2					   , LCLID_IReposTypeLib2					   , METAMETA_GUID);

// Property definitions
DEFINE_OBJID(OBJID_ReposPropLargeSize				   , LCLID_ReposPropLargeSize                  , METAMETA_GUID);
DEFINE_OBJID(OBJID_ReposPropLargeCurrentPosition	   , LCLID_ReposPropLargeCurrentPosition       , METAMETA_GUID);
DEFINE_OBJID(OBJID_RepositoryItemType				   , LCLID_RepositoryItemType                  , METAMETA_GUID);
DEFINE_OBJID(OBJID_RepositoryItemName				   , LCLID_RepositoryItemName                  , METAMETA_GUID);

// Method definitions
DEFINE_OBJID(OBJID_Create							   , LCLID_Create                              , METAMETA_GUID);
DEFINE_OBJID(OBJID_Open 							   , LCLID_Open                                , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateObject 					   , LCLID_CreateObject                        , METAMETA_GUID);
DEFINE_OBJID(OBJID_IRepositoryRefresh 				   , LCLID_IRepositoryRefresh                  , METAMETA_GUID);
DEFINE_OBJID(OBJID_ObjectIDToInternalID				   , LCLID_ObjectIDToInternalID				   , METAMETA_GUID);
DEFINE_OBJID(OBJID_InternalIDToObjectID				   , LCLID_InternalIDToObjectID				   , METAMETA_GUID);
DEFINE_OBJID(OBJID_Refresh 							   , LCLID_Refresh                             , METAMETA_GUID);
DEFINE_OBJID(OBJID_Delete 							   , LCLID_Delete                              , METAMETA_GUID);
DEFINE_OBJID(OBJID_Lock								   , LCLID_Lock                                , METAMETA_GUID);
DEFINE_OBJID(OBJID_Begin 							   , LCLID_Begin                               , METAMETA_GUID);
DEFINE_OBJID(OBJID_Commit							   , LCLID_Commit                              , METAMETA_GUID);
DEFINE_OBJID(OBJID_Abort							   , LCLID_Abort                               , METAMETA_GUID);
DEFINE_OBJID(OBJID_GetOption						   , LCLID_GetOption                           , METAMETA_GUID);
DEFINE_OBJID(OBJID_SetOption						   , LCLID_SetOption                           , METAMETA_GUID);
DEFINE_OBJID(OBJID_Flush							   , LCLID_Flush                               , METAMETA_GUID);
DEFINE_OBJID(OBJID_IVersionColRefresh 				   , LCLID_IVersionColRefresh                  , METAMETA_GUID);
DEFINE_OBJID(OBJID_IVersionColAdd					   , LCLID_IVersionColAdd                      , METAMETA_GUID);
DEFINE_OBJID(OBJID_IVersionColRemove				   , LCLID_IVersionColRemove                   , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateVersion 					   , LCLID_CreateVersion                       , METAMETA_GUID);
DEFINE_OBJID(OBJID_FreezeVersion					   , LCLID_FreezeVersion                       , METAMETA_GUID);
DEFINE_OBJID(OBJID_MergeVersion						   , LCLID_MergeVersion                        , METAMETA_GUID);
DEFINE_OBJID(OBJID_Checkout 						   , LCLID_Checkout                            , METAMETA_GUID);
DEFINE_OBJID(OBJID_Checkin							   , LCLID_Checkin                             , METAMETA_GUID);
DEFINE_OBJID(OBJID_IObjectColRefresh 				   , LCLID_IObjectColRefresh                   , METAMETA_GUID);
DEFINE_OBJID(OBJID_ITargetObjectColAdd 				   , LCLID_ITargetObjectColAdd                 , METAMETA_GUID);
DEFINE_OBJID(OBJID_ITargetObjectColRemove			   , LCLID_ITargetObjectColRemove              , METAMETA_GUID);
DEFINE_OBJID(OBJID_ITargetObjectColInsert			   , LCLID_ITargetObjectColInsert              , METAMETA_GUID);
DEFINE_OBJID(OBJID_ITargetObjectColMove				   , LCLID_ITargetObjectColMove                , METAMETA_GUID);
DEFINE_OBJID(OBJID_InitNew 							   , LCLID_InitNew                             , METAMETA_GUID);
DEFINE_OBJID(OBJID_Load								   , LCLID_Load                                , METAMETA_GUID);
DEFINE_OBJID(OBJID_Pin 								   , LCLID_Pin                                 , METAMETA_GUID);
DEFINE_OBJID(OBJID_Unpin							   , LCLID_Unpin                               , METAMETA_GUID);
DEFINE_OBJID(OBJID_IRelationshipColAdd 				   , LCLID_IRelationshipColAdd                 , METAMETA_GUID);
DEFINE_OBJID(OBJID_IRelationshipColRemove			   , LCLID_IRelationshipColRemove              , METAMETA_GUID);
DEFINE_OBJID(OBJID_IRelationshipColInsert			   , LCLID_IRelationshipColInsert              , METAMETA_GUID);
DEFINE_OBJID(OBJID_IRelationshipColMove				   , LCLID_IRelationshipColMove                , METAMETA_GUID);
DEFINE_OBJID(OBJID_IRelationshipColRefresh			   , LCLID_IRelationshipColRefresh             , METAMETA_GUID);
DEFINE_OBJID(OBJID_Cancel 							   , LCLID_Cancel                              , METAMETA_GUID);
DEFINE_OBJID(OBJID_VersionIDToInternalID 			   , LCLID_VersionIDToInternalID               , METAMETA_GUID);
DEFINE_OBJID(OBJID_InternalIDToVersionID			   , LCLID_InternalIDToVersionID               , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateObjectEx					   , LCLID_CreateObjectEx                      , METAMETA_GUID);
DEFINE_OBJID(OBJID_GetNewConnection 				   , LCLID_GetNewConnection                    , METAMETA_GUID);
DEFINE_OBJID(OBJID_FreeConnection					   , LCLID_FreeConnection                      , METAMETA_GUID);
DEFINE_OBJID(OBJID_ExecuteQuery						   , LCLID_ExecuteQuery                        , METAMETA_GUID);
DEFINE_OBJID(OBJID_IRepositoryODBC2GetOption		   , LCLID_IRepositoryODBC2GetOption           , METAMETA_GUID);
DEFINE_OBJID(OBJID_IRepositoryODBC2SetOption		   , LCLID_IRepositoryODBC2SetOption           , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateRelationshipColDef 		   , LCLID_CreateRelationshipColDef            , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreatePropertyDef				   , LCLID_CreatePropertyDef                   , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateMethodDef					   , LCLID_CreateMethodDef                     , METAMETA_GUID);
DEFINE_OBJID(OBJID_IInterfaceDefObjectInstances		   , LCLID_IInterfaceDefObjectInstances        , METAMETA_GUID);
DEFINE_OBJID(OBJID_AddInterface 					   , LCLID_AddInterface                        , METAMETA_GUID);
DEFINE_OBJID(OBJID_IClassDefCreateInterfaceDef		   , LCLID_IClassDefCreateInterfaceDef         , METAMETA_GUID);
DEFINE_OBJID(OBJID_IClassDefObjectInstances			   , LCLID_IClassDefObjectInstances            , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateAlias 						   , LCLID_CreateAlias                         , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateClassDef 					   , LCLID_CreateClassDef                      , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateInterfaceDef				   , LCLID_CreateInterfaceDef                  , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateRelationshipDef			   , LCLID_CreateRelationshipDef               , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateTypeLib 					   , LCLID_CreateTypeLib                       , METAMETA_GUID);
DEFINE_OBJID(OBJID_RepositoryPropertyLargeRead 		   , LCLID_ReposPropLargeRead		           , METAMETA_GUID);
DEFINE_OBJID(OBJID_RepositoryPropertyLargeWrite		   , LCLID_ReposPropLargeWrite			       , METAMETA_GUID);
DEFINE_OBJID(OBJID_RepositoryPropertyLargeClose		   , LCLID_ReposPropLargeClose				   , METAMETA_GUID);
DEFINE_OBJID(OBJID_RepositoryPropertyLargeReadFromFile , LCLID_ReposPropLargeReadFromFile		   , METAMETA_GUID);
DEFINE_OBJID(OBJID_RepositoryPropertyLargeWriteToFile  , LCLID_ReposPropLargeWriteToFile		   , METAMETA_GUID);

// Parameter definitions
// IRepository
DEFINE_OBJID(OBJID_CreateConnect					   , LCLID_CreateConnect					   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateUser						   , LCLID_CreateUser		                     , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreatePassword					   , LCLID_CreatePassword					     , METAMETA_GUID);  
DEFINE_OBJID(OBJID_CreateFlags						   , LCLID_CreateFlags						     , METAMETA_GUID);  
DEFINE_OBJID(OBJID_CreateRoot						   , LCLID_CreateRoot						     , METAMETA_GUID);  
DEFINE_OBJID(OBJID_OpenConnect						   , LCLID_OpenConnect						     , METAMETA_GUID);  
DEFINE_OBJID(OBJID_OpenUser							   , LCLID_OpenUser								 , METAMETA_GUID);  
DEFINE_OBJID(OBJID_OpenPassword						   , LCLID_OpenPassword							 , METAMETA_GUID);  
DEFINE_OBJID(OBJID_OpenFlags						   , LCLID_OpenFlags						   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_OpenRoot							   , LCLID_OpenRoot							     , METAMETA_GUID);  
DEFINE_OBJID(OBJID_CreateObjectTypeID				   , LCLID_CreateObjectTypeID				   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateObjectObjID				   , LCLID_CreateObjectObjID				   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateObjectReposObj				   , LCLID_CreateObjectReposObj				     , METAMETA_GUID);
DEFINE_OBJID(OBJID_IRepositoryRefreshMilliseconds	   , LCLID_IRepositoryRefreshMilliseconds	     , METAMETA_GUID);
DEFINE_OBJID(OBJID_ObjectIDToInternalIDObjID		   , LCLID_ObjectIDToInternalIDObjID		   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_ObjectIDToInternalIDIntID		   , LCLID_ObjectIDToInternalIDIntID		   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_InternalIDToObjectIDIntID		   , LCLID_InternalIDToObjectIDIntID		   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_InternalIDToObjectIDObjID		   , LCLID_InternalIDToObjectIDObjID		   	 , METAMETA_GUID);

// IRepositoryObject
DEFINE_OBJID(OBJID_RefreshMilliseconds				   , LCLID_RefreshMilliseconds			     , METAMETA_GUID);  

// IRepositoryTransaction
DEFINE_OBJID(OBJID_GetOptionOption					   , LCLID_GetOptionOption				     , METAMETA_GUID);  
DEFINE_OBJID(OBJID_GetOptionValue					   , LCLID_GetOptionValue					   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_SetOptionOption					   , LCLID_SetOptionOption				     , METAMETA_GUID);  
DEFINE_OBJID(OBJID_SetOptionValue					   , LCLID_SetOptionValue					   	 , METAMETA_GUID);

// IVersionCol
DEFINE_OBJID(OBJID_IVersionColRefreshMilliseconds	   , LCLID_IVersionColRefreshMilliseconds      , METAMETA_GUID);
DEFINE_OBJID(OBJID_IVersionColRemoveItem			   , LCLID_IVersionColRemoveItem			   	 , METAMETA_GUID);

// IRepositoryObject
DEFINE_OBJID(OBJID_CreateVersionVersoinID			   , LCLID_CreateVersionVersoinID			   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateVersionCreatedVersion		   , LCLID_CreateVersionCreatedVersion	     , METAMETA_GUID);  
DEFINE_OBJID(OBJID_MergeVersionOtherVersion			   , LCLID_MergeVersionOtherVersion		     , METAMETA_GUID);  
DEFINE_OBJID(OBJID_MergeVersionFlags				   , LCLID_MergeVersionFlags				   	 , METAMETA_GUID);

// IObjectCol
DEFINE_OBJID(OBJID_IObjectColRefreshMilliseconds	   , LCLID_IObjectColRefreshMilliseconds	 , METAMETA_GUID);

// ITargetObjectCol
DEFINE_OBJID(OBJID_ITargetObjectColAddReposObj		   , LCLID_ITargetObjectColAddReposObj	     , METAMETA_GUID);  
DEFINE_OBJID(OBJID_ITargetObjectColAddNamel			   , LCLID_ITargetObjectColAddNamel		     , METAMETA_GUID);  
DEFINE_OBJID(OBJID_ITargetObjectColAddRelship		   , LCLID_ITargetObjectColAddRelship	       	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_ITargetObjectColRemoveItem		   , LCLID_ITargetObjectColRemoveItem		   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_ITargetObjectColInsertReposObj	   , LCLID_ITargetObjectColInsertReposObj      , METAMETA_GUID);
DEFINE_OBJID(OBJID_ITargetObjectColInsertIndex		   , LCLID_ITargetObjectColInsertIndex	     , METAMETA_GUID);  
DEFINE_OBJID(OBJID_ITargetObjectColInsertName		   , LCLID_ITargetObjectColInsertName		   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_ITargetObjectColInsertRelship	   , LCLID_ITargetObjectColInsertRelship	   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_ITargetObjectColMoveIndexFrom	   , LCLID_ITargetObjectColMoveIndexFrom	   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_ITargetObjectColMoveIndexTo		   , LCLID_ITargetObjectColMoveIndexTo	     , METAMETA_GUID);  

// IRepositoryObjectStorage
DEFINE_OBJID(OBJID_InitNewRepos						   , LCLID_InitNewRepos					     , METAMETA_GUID);  
DEFINE_OBJID(OBJID_InitNewCookie					   , LCLID_InitNewCookie					   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_LoadRepos						   , LCLID_LoadRepos						   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_LoadCookie						   , LCLID_LoadCookie						   	 , METAMETA_GUID);

// IVersionedRelationship
DEFINE_OBJID(OBJID_PinReposVersion					   , LCLID_PinReposVersion				     , METAMETA_GUID);  

// IRelationshipCol
DEFINE_OBJID(OBJID_IRelationshipColAddReposObj		   , LCLID_IRelationshipColAddReposObj	     , METAMETA_GUID);  
DEFINE_OBJID(OBJID_IRelationshipColAddName			   , LCLID_IRelationshipColAddName		     , METAMETA_GUID);  
DEFINE_OBJID(OBJID_IRelationshipColAddRemove		   , LCLID_IRelationshipColAddRemove		   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_IRelationshipColInsertReposObj	   , LCLID_IRelationshipColInsertReposObj      , METAMETA_GUID);
DEFINE_OBJID(OBJID_IRelationshipColInsertIndex		   , LCLID_IRelationshipColInsertIndex	     , METAMETA_GUID);  
DEFINE_OBJID(OBJID_IRelationshipColInsertName		   , LCLID_IRelationshipColInsertName		   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_IRelationshipColInsertRelship	   , LCLID_IRelationshipColInsertRelship	   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_IRelationshipColMoveIndexFrom	   , LCLID_IRelationshipColMoveIndexFrom	   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_IRelationshipColMoveIndexTo		   , LCLID_IRelationshipColMoveIndexTo	     , METAMETA_GUID);  

DEFINE_OBJID(OBJID_IRelationshipColRefreshMilliseconds , LCLID_IRelationshipColRefreshMilliseconds , METAMETA_GUID);  

// IRepository2
DEFINE_OBJID(OBJID_VersionIDToInternalIDExtVersionID   , LCLID_VersionIDToInternalIDExtVersionID   , METAMETA_GUID);
DEFINE_OBJID(OBJID_VersionIDToInternalIDIntVersionID   , LCLID_VersionIDToInternalIDIntVersionID   , METAMETA_GUID);
DEFINE_OBJID(OBJID_InternalIDToVersionIDIntVersionID   , LCLID_InternalIDToVersionIDIntVersionID   , METAMETA_GUID);
DEFINE_OBJID(OBJID_InternalIDToVersionIDExtVersionID   , LCLID_InternalIDToVersionIDExtVersionID   , METAMETA_GUID);

// IRepositoryODBC
DEFINE_OBJID(OBJID_GetNewConnectionHdbc				   , LCLID_GetNewConnectionHdbc				 , METAMETA_GUID);  
DEFINE_OBJID(OBJID_FreeConnecionHdbc				   , LCLID_FreeConnecionHdbc				   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_ExecuteQueryQuery				   , LCLID_ExecuteQueryQuery				   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_ExecuteQueryCol					   , LCLID_ExecuteQueryCol				     , METAMETA_GUID);  

// IRepositoryODBC2
DEFINE_OBJID(OBJID_IRepositoryODBC2GetOptionOption	   , LCLID_IRepositoryODBC2GetOptionOption	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_IRepositoryODBC2GetOptionValue	   , LCLID_IRepositoryODBC2GetOptionValue	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_IRepositoryODBC2SetOptionOption	   , LCLID_IRepositoryODBC2SetOptionOption	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_IRepositoryODBC2SetOptionValue	   , LCLID_IRepositoryODBC2SetOptionValue	 , METAMETA_GUID);

// IInterfaceDef
DEFINE_OBJID(OBJID_CreateRelationshipColDefObjID	   , LCLID_CreateRelationshipColDefObjID	   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateRelationshipColDefName		   , LCLID_CreateRelationshipColDefName		 , METAMETA_GUID);  
DEFINE_OBJID(OBJID_CreateRelationshipColDefDispID	   , LCLID_CreateRelationshipColDefDispID	   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateRelationshipColDefIsOrigin	   , LCLID_CreateRelationshipColDefIsOrigin	 , METAMETA_GUID);  
DEFINE_OBJID(OBJID_CreateRelationshipColDefFlags	   , LCLID_CreateRelationshipColDefFlags	   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateRelationshipColDefRelshipDef  , LCLID_CreateRelationshipColDefRelshipDef  , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateRelationshipColDefColDef	   , LCLID_CreateRelationshipColDefColDef	   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreatePropertyDefObjID			   , LCLID_CreatePropertyDefObjID			   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreatePropertyDefName			   , LCLID_CreatePropertyDefName			   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreatePropertyDefDispID			   , LCLID_CreatePropertyDefDispID			 , METAMETA_GUID);  
DEFINE_OBJID(OBJID_CreatePropertyDefType			   , LCLID_CreatePropertyDefType			   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreatePropertyDefPropDef			   , LCLID_CreatePropertyDefPropDef			 , METAMETA_GUID);  
DEFINE_OBJID(OBJID_CreateMethodDefObjID				   , LCLID_CreateMethodDefObjID				 , METAMETA_GUID);  
DEFINE_OBJID(OBJID_CreateMethodDefName				   , LCLID_CreateMethodDefName				 , METAMETA_GUID);  
DEFINE_OBJID(OBJID_CreateMethodDefDispID			   , LCLID_CreateMethodDefDispID			   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateMethodDefMethodDef			   , LCLID_CreateMethodDefMethodDef			 , METAMETA_GUID);  
DEFINE_OBJID(OBJID_IInterfaceDefObjectInstancesObject  , LCLID_IInterfaceDefObjectInstancesObject  , METAMETA_GUID);

// IClassDef
DEFINE_OBJID(OBJID_AddInterfaceInterfaceDef			   , LCLID_AddInterfaceInterfaceDef			 , METAMETA_GUID);  
DEFINE_OBJID(OBJID_AddInterfaceFlags				   , LCLID_AddInterfaceFlags			       	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_ClassDefCreateInterfaceDefObjID	   , LCLID_ClassDefCreateInterfaceDefObjID	 , METAMETA_GUID);  
DEFINE_OBJID(OBJID_ClassDefCreateInterfaceDefName	   , LCLID_ClassDefCreateInterfaceDefName	   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_ClassDefCreateInterfaceDefIID	   , LCLID_ClassDefCreateInterfaceDefIID	   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_ClassDefCreateInterfaceDefAncestor  , LCLID_ClassDefCreateInterfaceDefAncestor  , METAMETA_GUID);
DEFINE_OBJID(OBJID_ClassDefCreateInterfaceDefFlags	   , LCLID_ClassDefCreateInterfaceDefFlags	 , METAMETA_GUID);  
DEFINE_OBJID(OBJID_ClassDefCreateInterfaceDefIfaceDef  , LCLID_ClassDefCreateInterfaceDefIfaceDef  , METAMETA_GUID);
DEFINE_OBJID(OBJID_IClassDefObjectInstancesObjectCol   , LCLID_IClassDefObjectInstancesObjectCol   , METAMETA_GUID);

// IInterfaceDef2
DEFINE_OBJID(OBJID_CreateAliasObjID					   , LCLID_CreateAliasObjID					 , METAMETA_GUID);  
DEFINE_OBJID(OBJID_CreateAliasName					   , LCLID_CreateAliasName					 , METAMETA_GUID);  
DEFINE_OBJID(OBJID_CreateAliasDispID				   , LCLID_CreateAliasDispID				   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateAliasBase					   , LCLID_CreateAliasBase				     , METAMETA_GUID);  
DEFINE_OBJID(OBJID_CreateAliasAlias					   , LCLID_CreateAliasAlias				     , METAMETA_GUID);  

// IReposTypeLib
DEFINE_OBJID(OBJID_CreateClassDefObjID				   , LCLID_CreateClassDefObjID				 , METAMETA_GUID);  
DEFINE_OBJID(OBJID_CreateClassDefName				   , LCLID_CreateClassDefName				   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateClassDefClassID			   , LCLID_CreateClassDefClassID			   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateClassDefClassDef			   , LCLID_CreateClassDefClassDef		       	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateInterfaceDefObjID			   , LCLID_CreateInterfaceDefObjID			 , METAMETA_GUID);  
DEFINE_OBJID(OBJID_CreateInterfaceDefName			   , LCLID_CreateInterfaceDefName			   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateInterfaceDefIID			   , LCLID_CreateInterfaceDefIID			   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateInterfaceDefAncestor		   , LCLID_CreateInterfaceDefAncestor		   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateInterfaceDefIfaceDef		   , LCLID_CreateInterfaceDefIfaceDef	       	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateRelationshipDefObjID		   , LCLID_CreateRelationshipDefObjID		   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateRelationshipDefName		   , LCLID_CreateRelationshipDefName		   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateRelationshipDefRelshipDef	   , LCLID_CreateRelationshipDefRelshipDef     , METAMETA_GUID);

// IManageReposTypeLib
DEFINE_OBJID(OBJID_CreateTypeLibObjID				   , LCLID_CreateTypeLibObjID				   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateTypeLibName				   , LCLID_CreateTypeLibName				   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateTypeLibTypeLibID			   , LCLID_CreateTypeLibTypeLibID			   	 , METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateTypeLibTypeLib				   , LCLID_CreateTypeLibTypeLib			     , METAMETA_GUID);

// IRepositoryPropertyLarge
DEFINE_OBJID(OBJID_IRepositoryPropertyLargeReadChunkSize   , LCLID_IRepositoryPropertyLargeReadChunkSize	, METAMETA_GUID);
DEFINE_OBJID(OBJID_IRepositoryPropertyLargeReadSizeRead	   , LCLID_IRepositoryPropertyLargeReadSizeRead		, METAMETA_GUID);
DEFINE_OBJID(OBJID_IRepositoryPropertyLargeReadBlob		   , LCLID_IRepositoryPropertyLargeReadBlob			, METAMETA_GUID);
DEFINE_OBJID(OBJID_IRepositoryPropertyLargeWriteBlob	   , LCLID_IRepositoryPropertyLargeWriteBlob	   	, METAMETA_GUID);
DEFINE_OBJID(OBJID_IRepositoryPropertyLargeReadFromFileFileName, LCLID_IRepositoryPropertyLargeReadFromFileFileName, METAMETA_GUID);
DEFINE_OBJID(OBJID_IRepositoryPropertyLargeWriteToFileFileName, LCLID_IRepositoryPropertyLargeWriteToFileFileName, METAMETA_GUID);

// IReposTypeLib2
DEFINE_OBJID(OBJID_RReposTypeLib2Dependency			   , LCLID_RReposTypeLib2Dependency				, METAMETA_GUID);
DEFINE_OBJID(OBJID_IReposTypeLib2DependsOn			   , LCLID_IReposTypeLib2DependsOn				, METAMETA_GUID);
DEFINE_OBJID(OBJID_IReposTypeLib2UsedBy				   , LCLID_IReposTypeLib2UsedBy					, METAMETA_GUID);

// IReposOptions
DEFINE_OBJID(OBJID_IReposOptions					   , LCLID_IReposOptions						, METAMETA_GUID);
DEFINE_OBJID(OBJID_IReposOptionsGetOption			   , LCLID_IReposOptionsGetOption				, METAMETA_GUID);
DEFINE_OBJID(OBJID_IReposOptionsSetOption			   , LCLID_IReposOptionsSetOption				, METAMETA_GUID);
DEFINE_OBJID(OBJID_IReposOptionsResetOptions		   , LCLID_IReposOptionsResetOptions			, METAMETA_GUID);
DEFINE_OBJID(OBJID_IReposOptionsGetOptionOption		   , LCLID_IReposOptionsGetOptionOption			, METAMETA_GUID);
DEFINE_OBJID(OBJID_IReposOptionsGetOptionValue		   , LCLID_IReposOptionsGetOptionValue			, METAMETA_GUID);
DEFINE_OBJID(OBJID_IReposOptionsSetOptionOption		   , LCLID_IReposOptionsSetOptionOption			, METAMETA_GUID);
DEFINE_OBJID(OBJID_IReposOptionsSetOptionValue		   , LCLID_IReposOptionsSetOptionValue			, METAMETA_GUID);

// ScriptDef
DEFINE_OBJID(OBJID_ScriptDef							, LCLID_ScriptDef							, METAMETA_GUID);
DEFINE_OBJID(OBJID_IScriptDef							, LCLID_IScriptDef							, METAMETA_GUID);
DEFINE_OBJID(OBJID_IScriptDefLanguage					, LCLID_IScriptDefLanguage					, METAMETA_GUID);
DEFINE_OBJID(OBJID_IScriptDefBody						, LCLID_IScriptDefBody						, METAMETA_GUID);
DEFINE_OBJID(OBJID_IScriptDefValidateScript				, LCLID_IScriptDefValidateScript			, METAMETA_GUID);
DEFINE_OBJID(OBJID_RClassUsesScript						, LCLID_RClassUsesScript					, METAMETA_GUID);
DEFINE_OBJID(OBJID_UsingClasses							, LCLID_UsingClasses						, METAMETA_GUID);
DEFINE_OBJID(OBJID_ScriptsUsedByClass					, LCLID_ScriptsUsedByClass					, METAMETA_GUID);
DEFINE_OBJID(OBJID_RInterafceUsesScript					, LCLID_RInterafceUsesScript				, METAMETA_GUID);
DEFINE_OBJID(OBJID_UsingInterfaces						, LCLID_UsingInterfaces						, METAMETA_GUID);
DEFINE_OBJID(OBJID_ScriptsUsedByInterface				, LCLID_ScriptsUsedByInterface				, METAMETA_GUID);
DEFINE_OBJID(OBJID_RMemberUsesScript					, LCLID_RMemberUsesScript					, METAMETA_GUID);
DEFINE_OBJID(OBJID_UsingMember							, LCLID_UsingMember							, METAMETA_GUID);
DEFINE_OBJID(OBJID_ScriptsUsedByMember					, LCLID_ScriptsUsedByMember					, METAMETA_GUID);

// IRepositoryTransaction2
DEFINE_OBJID(OBJID_IRepositoryTransaction2			   , LCLID_IRepositoryTransaction2              , METAMETA_GUID);
DEFINE_OBJID(OBJID_IRepositoryTransaction2Transaction  , LCLID_IRepositoryTransaction2Transaction   , METAMETA_GUID);
DEFINE_OBJID(OBJID_IRepositoryTransaction2JoinTransaction, LCLID_IRepositoryTransaction2JoinTransaction, METAMETA_GUID);

// IReposProperty2
DEFINE_OBJID(OBJID_IReposProperty2						, LCLID_IReposProperty2						, METAMETA_GUID);

// IReposObj2
DEFINE_OBJID(OBJID_IReposObj2							, LCLID_IReposObj2							, METAMETA_GUID);

// IEnumerationDef
DEFINE_OBJID(OBJID_EnumerationDef						, LCLID_EnumerationDef						, METAMETA_GUID);
DEFINE_OBJID(OBJID_IEnumerationDef						, LCLID_IEnumerationDef						, METAMETA_GUID);
DEFINE_OBJID(OBJID_IEnumerationDefIsFlag				, LCLID_IEnumerationDefIsFlag				, METAMETA_GUID);
DEFINE_OBJID(OBJID_IEnumerationDefValues				, LCLID_IEnumerationDefValues				, METAMETA_GUID);
DEFINE_OBJID(OBJID_IEnumerationDefEnumFor				, LCLID_IEnumerationDefEnumFor				, METAMETA_GUID);
DEFINE_OBJID(OBJID_REnumerationValues					, LCLID_REnumerationValues					, METAMETA_GUID);

// IEnumerationValueDef
DEFINE_OBJID(OBJID_EnumerationValueDef					, LCLID_EnumerationValueDef					, METAMETA_GUID);
DEFINE_OBJID(OBJID_IEnumerationValueDef					, LCLID_IEnumerationValueDef				, METAMETA_GUID);
DEFINE_OBJID(OBJID_IEnumerationValueDefValue			, LCLID_IEnumerationValueDefValue			, METAMETA_GUID);
DEFINE_OBJID(OBJID_IEnumerationValueDefValueOf			, LCLID_IEnumerationValueDefValueOf			, METAMETA_GUID);

// IPropDef2
DEFINE_OBJID(OBJID_PropDefEnumerationDef				, LCLID_PropDefEnumerationDef			, METAMETA_GUID);
DEFINE_OBJID(OBJID_REnumerationForProperty				, LCLID_REnumerationForProperty			, METAMETA_GUID);

// IViewClassDef
DEFINE_OBJID(OBJID_IViewClassDef						, LCLID_IViewClassDef						, METAMETA_GUID);
DEFINE_OBJID(OBJID_IViewClassDefFlags					, LCLID_IViewClassDefFlags					, METAMETA_GUID);
DEFINE_OBJID(OBJID_IViewClassDefViewName				, LCLID_IViewClassDefViewName				, METAMETA_GUID);

// IViewInterfaceDef
DEFINE_OBJID(OBJID_IViewInterfaceDef					, LCLID_IViewInterfaceDef					, METAMETA_GUID);
DEFINE_OBJID(OBJID_IViewInterfaceDefFlags				, LCLID_IViewInterfaceDefFlags				, METAMETA_GUID);
DEFINE_OBJID(OBJID_IViewInterfaceDefViewName			, LCLID_IViewInterfaceDefViewName			, METAMETA_GUID);

// IViewRelationshipDef
DEFINE_OBJID(OBJID_IViewRelationshipDef					, LCLID_IViewRelationshipDef				, METAMETA_GUID);
DEFINE_OBJID(OBJID_IViewRelationshipDefFlags			, LCLID_IViewRelationshipDefFlags			, METAMETA_GUID);
DEFINE_OBJID(OBJID_IViewRelationshipDefColumnNamePrefix	, LCLID_IViewRelationshipDefColumnNamePrefix, METAMETA_GUID);
DEFINE_OBJID(OBJID_IViewRelationshipDefJunctionViewName	, LCLID_IViewRelationshipDefJunctionViewName, METAMETA_GUID);

// IViewPropertyDef
DEFINE_OBJID(OBJID_IViewPropertyDef						, LCLID_IViewPropertyDef					, METAMETA_GUID);
DEFINE_OBJID(OBJID_IViewPropertyDefViewColumnName		, LCLID_IViewPropertyDefViewColumnName		, METAMETA_GUID);

// TransientRelationshipCol
DEFINE_OBJID(OBJID_TransientObjCol						, LCLID_TransientObjCol						, METAMETA_GUID);
DEFINE_OBJID(OBJID_ITransientObjCol						, LCLID_ITransientObjCol					, METAMETA_GUID);
DEFINE_OBJID(OBJID_ITransientObjColAdd					, LCLID_ITransientObjColAdd					, METAMETA_GUID);
DEFINE_OBJID(OBJID_ITransientObjColRemove				, LCLID_ITransientObjColRemove				, METAMETA_GUID);
DEFINE_OBJID(OBJID_ITransientObjColAddReposObj			, LCLID_ITransientObjColAddReposObj			, METAMETA_GUID);
DEFINE_OBJID(OBJID_ITransientObjColRemoveItem			, LCLID_ITransientObjColRemoveItem			, METAMETA_GUID);

// IReposQuery
DEFINE_OBJID(OBJID_IReposQueryGetCollection				, LCLID_IReposQueryGetCollection			, METAMETA_GUID);

#endif // __REPTIM3_H__

