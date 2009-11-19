Attribute VB_Name = "RepEng"
' ------------------------------------------------------------------------
' Copyright (c) 1998-1999 Microsoft Corporation.  All rights reserved.
'
' This software is provided as is without warranty of any kind.  The entire
' risk as to the results and performance of this software is assumed by the user.
' Microsoft disclaims all warranties, either express or implied, including but
' not limited, the implied warranties of merchantability, fitness for a
' particular purpose, title and noninfringement, with respect to this software.
' ------------------------------------------------------------------------
'$include 'odbcor_g.bi'
'$include 'odbext_g.bi'
'
' ------------------------------------------------------------------------
' This file contains a bunch of variant declarations for variables that
' represent object identifiers for repository Type Information Model objects.
'   (For more information about Type Information Model objects, see the
'    Repository Programmer's Guide in Visual Basic Books Online.)
' A pile of error number constants for repository specific errors are also defined.
'
' Two subroutines (DEFINE_OBJID and InitRepository) and one function (InitGuid)
' are also contained in this file.
' ------------------------------------------------------------------------


' repodbc error code
Public const EREP_BADPARAMS = &H80041000
Public const EREP_BADNAME = &H80041001
Public const EREP_BADDRIVER = &H80041002
Public const EREP_BADERROR = &H80041003
Public const EREP_BUFFER_OVERFLOW = &H80041004
Public const EREP_NAMETOOLONG = &H80041005
Public const EREP_NOROWSFOUND = &H80041011
Public const EREP_ODBC_CERROR = &H80041012
Public const EREP_ODBC_MDBNOTFOUND = &H80041013
Public const EREP_NEED_DATA = &H80041014
Public const EREP_ODBC_UNKNOWNDRIVER = &H80041015
Public const EREP_ODBC_CREATEFAILED = &H80041016
Public const EREP_ODBC_WARNINGS = &H80041017
Public const EREP_STILL_EXECUTING = &H80041018
Public const EREP_ODBC_NOTCAPABLE = &H80041019
Public const EREP_DB_EXISTS = &H80041030
Public const EREP_DB_NOTCONNECTED = &H80041031
Public const EREP_DB_ALREADYCONNECTED = &H80041032
Public const EREP_DB_DBMSONETHREAD = &H80041033
Public const EREP_DB_CORRUPT = &H80041034
Public const EREP_DB_NOSCHEMA = &H80041035
Public const EREP_DB_DBMSOLD = &H80041036
Public const EREP_DB_READONLY = &H80041037
Public const EREP_DB_INCOMPATIBLEVERSION = &H80041038
Public const EREP_DB_UPGRADE = &H80041039
Public const EREP_TXN_NOTXNACTIVE = &H80041041
Public const EREP_TXN_AUTOABORT = &H80041042
Public const EREP_TXN_TOOMANY = &H80041043
Public const EREP_TXN_TIMEOUT = &H80041044
Public const EREP_TXN_NODATA = &H80041045
Public const EREP_TXN_NOSETINTXN = &H80041046
Public const EREP_TXN_OBJABORTED = &H80041047
Public const EREP_TXN_COLABORTED = &H80041048
Public const EREP_REPOS_CACHEFULL = &H80041070
Public const EREP_REPOS_NONEXTDISPID = &H80041071
Public const EREP_REPOS_DUPEDISPID = &H80041072
Public const EREP_RELSHIP_EXISTS = &H80041100
Public const EREP_RELSHIP_INVALID_PAIR = &H80041101
Public const EREP_RELSHIP_NOTFOUND = &H80041102
Public const EREP_RELSHIP_ORGONLY = &H80041105
Public const EREP_RELSHIP_OUTOFDATE = &H80041106
Public const EREP_RELSHIP_INVALIDFLAGS = &H80041107
Public const EREP_RELSHIP_NAMEINVALID = &H80041108
Public const EREP_RELSHIP_DUPENAME = &H80041109
Public const EREP_RELSHIP_NONNAMINGCOL = &H80041110
Public const EREP_TYPE_TABLEMISMATCH = &H80041120
Public const EREP_TYPE_COLMISMATCH = &H80041121
Public const EREP_TYPE_NOTNULLABLE = &H80041122
Public const EREP_TYPE_MULTIDEFIFACES = &H80041123
Public const EREP_TYPE_INVERTEDNOTALLOWED = &H80041124
Public const EREP_TYPE_INVALIDSCALE = &H80041125
Public const EREP_TYPE_BADTABLENAME = &H80041126
Public const EREP_TYPE_MULTIPLEANCESTORS = &H80041127
Public const EREP_LOCK_TIMEOUT = &H80041200
Public const EREP_QRY_BADCOLUMNS = &H80041250
Public const EREP_OBJ_NOTINITIALIZED = &H80041300
Public const EREP_OBJ_NOTFOUND = &H80041301
Public const EREP_OBJ_NONAMINGRELSHIP = &H80041302
Public const EREP_OBJ_EXISTS = &H80041303
Public const EREP_VERSION_NOTFOUND = &H80041304
Public const EREP_PROP_MISMATCH = &H80041400
Public const EREP_PROP_SETINVALID = &H80041401
Public const EREP_PROP_CANTSETREPTIM = &H80041403
Public const EREP_PROP_READONLY = &H80041404
Public const EREP_PROP_NOTEXISTS = &H80041405
Public const EREP_TIM_INVALIDFLAGS = &H80041500
Public const EREP_TIM_FLAGSDEST = &H80041501
Public const EREP_TIM_RELTYPEINVALID = &H80041502
Public const EREP_TIM_CTYPEINVALID = &H80041503
Public const EREP_TIM_TOOMANYCOLS = &H80041504
Public const EREP_TIM_SQLTYPEINVALID = &H80041505
Public const EREP_TIM_SQLSIZEINVALID = &H80041506
Public const EREP_VM_CANTSETFROZEN = &H80041600
Public const EREP_VM_MERGETOFROZEN = &H80041601
Public const EREP_VM_MERGEFROMUNFROZEN = &H80041602
Public const EREP_VM_UNFROZENVERSION = &H80041603
Public const EREP_VM_FROZENVERSION = &H80041604
Public const EREP_VM_CHECKEDOUTVERSION = &H80041605
Public const EREP_VM_DUPBRANCHID = &H80041606
Public const EREP_VM_SUCCESSOREXISTS = &H80041607
Public const EREP_REL_ORGFROZEN = &H80041700
Public const EREP_REL_ORGCLONE = &H80041701
Public const EREP_REL_NONSEQONLY = &H80041702
Public const EREP_REL_ORGPIN = &H80041703
Public const EREP_REL_NOTPINNED = &H80041704
Public const EREP_WKS_ITEMEXISTS = &H80041800
Public const EREP_WKS_ITEMNOTEXISTS = &H80041801
Public const EREP_NOTWORKSPACEITEM = &H80041802
Public const EREP_ITEMNOTCHECKEDOUT = &H80041803
Public const EREP_VCOL_VERSIONNOTMEMBER = &H80041900
Public const EREP_VCOL_INVALIDOP = &H80041901
Public const EREP_COL_NOTSEQUENCED = &H80041950
Public const EREP_VM_DIFFERENTTYPES = &H80042000
Public const EREP_BLOB_SEEKPASTEND = &H80041A01
Public const EREP_BLOB_TEMPFILE = &H80041A02
Public const EREP_BLOB_USERFILE = &H80041A03
Public const EREP_BLOB_CANNOTSETPOS = &H80041A04
Public const EREP_MEMDEL_COLNOTDEFINED = &H80041B00
Public const EREP_MEMDEL_BASEIFACENOTIMPL = &H80041B01
Public const EREP_MEMDEL_BASECOLVIRTUAL = &H80041B02
Public const EREP_MEMDEL_MULTIPLEBASES = &H80041B03
Public const EREP_MEMDEL_CIRCULARCOLS = &H80041B04
Public const EREP_MEMDEL_DELCOLINVALID = &H80041B05
Public const EREP_COL_OBJECTNAMING = &H80041C00
Public const EREP_COL_OBJECTNOTNAMED = &H80041C01
Public const EREP_INVALIDDEPENDENCY = &H80041C02
Public const EREP_UNKNOWNPROPERTY = &H80041D00
Public const EREP_MISSINGLEFTBRACKET = &H80041D01
Public const EREP_MISSINGRIGHTBRACKET = &H80041D02
Public const EREP_MISSINGLEFTPARENTHESIS = &H80041D03
Public const EREP_MISSINGRIGHTPARENTHESIS = &H80041D04
Public const EREP_MISSINGCOMMA = &H80041D05
Public const EREP_PROPERTYNOTFOUND = &H80041D06
Public const EREP_INVALIDFILTER = &H80041D07
Public const EREP_SCRIPT_NESTEDCALL = &H80041D08
Public const EREP_SCRIPT_NOTFOUND = &H80041D09
Public const EREP_SCRIPT_INVALIDLANGUAGE = &H80041D0A
Public const EREP_VIRTUAL_ALIAS = &H80041D0B
Public const EREP_VIRTUAL_CALL = &H80041D0C
Public const EREP_CLASS_TOOCOMPLEX = &H80041E00
Public const EREP_RTIM_CLASS_IS_NOT_CREATEABLE = &H80041E02
Public const EREP_NAME_NOTUNIQUE = &H80041E03

Public CLSID_RepositoryObject As Variant

'Repository Type Information Model Object IDs
Public OBJID_ClassDef As Variant
Public OBJID_InterfaceDef As Variant
Public OBJID_CollectionDef As Variant
Public OBJID_MethodDef As Variant
Public OBJID_PropertyDef As Variant
Public OBJID_RelationshipDef As Variant
Public OBJID_ReposTypeLib As Variant
Public OBJID_ReposRoot As Variant
Public OBJID_IUnknown As Variant
Public OBJID_IDispatch As Variant
Public OBJID_IReposDispatch As Variant
Public OBJID_IReposTypeInfo As Variant
Public OBJID_IClassDef As Variant
Public OBJID_IInterfaceDef As Variant
Public OBJID_IInterfaceMember As Variant
Public OBJID_IPropertyDef As Variant
Public OBJID_ICollectionDef As Variant
Public OBJID_IRepositoryItem As Variant
Public OBJID_IRepositoryObject As Variant
Public OBJID_IRelationship As Variant
Public OBJID_IAnnotationalProps As Variant
Public OBJID_ISummaryInfo As Variant
Public OBJID_INamedObject As Variant
Public OBJID_IManageReposTypeLib As Variant
Public OBJID_IReposTypeLib As Variant
Public OBJID_IReposRoot As Variant
Public OBJID_RClassImplIface As Variant
Public OBJID_RIfaceInheritsFromIface As Variant
Public OBJID_RIfaceHasMembers As Variant
Public OBJID_RColContainsItems As Variant
Public OBJID_RContainerContextForReposTLBs As Variant
Public OBJID_RReposTLBScopeForReposTypeInfo As Variant
Public OBJID_Ifaces As Variant
Public OBJID_Classes As Variant
Public OBJID_Ancestor As Variant
Public OBJID_Descendants As Variant
Public OBJID_Members As Variant
Public OBJID_Iface As Variant
Public OBJID_CollectionItem As Variant
Public OBJID_ItemInCollections As Variant
Public OBJID_ReposTypeLibs As Variant
Public OBJID_ReposTLBContexts As Variant
Public OBJID_ReposTypeInfos As Variant
Public OBJID_ReposTypeLibScopes As Variant
Public OBJID_ReposRootObj As Variant
Public OBJID_ReposTIM As Variant
Public OBJID_ClassID As Variant
Public OBJID_PropDescs As Variant
Public OBJID_InterfaceID As Variant
Public OBJID_TableName As Variant
Public OBJID_InterfaceFlags As Variant
Public OBJID_DispID As Variant
Public OBJID_InterfaceMemberFlags As Variant
Public OBJID_RelshipTypeID As Variant
Public OBJID_CollectionFlags As Variant
Public OBJID_MinCount As Variant
Public OBJID_MaxCount As Variant
Public OBJID_IsOrigin As Variant
Public OBJID_ColumnName As Variant
Public OBJID_APIType As Variant
Public OBJID_SQLType As Variant
Public OBJID_SQLSize As Variant
Public OBJID_SQLScale As Variant
Public OBJID_TypeLibID As Variant
Public OBJID_TypeID As Variant
Public OBJID_Comments As Variant
Public OBJID_ShortDescription As Variant
Public OBJID_ObjectName As Variant
Public OBJID_RelationshipTgtName As Variant
Public OBJID_ImplementsOptions As Variant
Public OBJID_NULL As Variant
Public OBJID_IReposVersion As Variant
Public OBJID_IVersionCol As Variant
Public OBJID_IVersionedRelship As Variant
Public OBJID_Workspace As Variant
Public OBJID_IWorkspaceItem As Variant
Public OBJID_IWorkspace As Variant
Public OBJID_IVersionAdminInfo As Variant
Public OBJID_VersionCreateTime As Variant
Public OBJID_VersionModifyTime As Variant
Public OBJID_CreateByUser As Variant
Public OBJID_ModifyByUser As Variant
Public OBJID_IWorkspaceContainer As Variant
Public OBJID_RWksContainerContainsWorkspaces As Variant
Public OBJID_ContainedWorkspaces As Variant
Public OBJID_WorkspaceContainers As Variant
Public OBJID_InsertSProcName As Variant
Public EXTVERSIONID_NULL As Variant
Public OBJID_SQLBlobSize As Variant
Public OBJID_IPropertyDef2 As Variant
Public OBJID_Alias As Variant
Public OBJID_IVersionAdminInfo2 As Variant
Public OBJID_IIfaceDef2 As Variant
Public OBJID_IIfaceMember2 As Variant
Public OBJID_RInterfaceImpliesInterface As Variant
Public OBJID_RBaseMemberServicesDerivedMembers As Variant
Public OBJID_Implies As Variant
Public OBJID_ImpliedBy As Variant
Public OBJID_ServicesDerivedMembers As Variant
Public OBJID_ServicedByBaseMember As Variant
Public OBJID_VersionLabel As Variant
Public OBJID_VersionComments As Variant
Public OBJID_VersionShortDesc As Variant
Public OBJID_RInterfaceMemberHasParameters As Variant
Public OBJID_Member As Variant
Public OBJID_Parameters As Variant
Public OBJID_IMethodDef As Variant
Public OBJID_IParameterDef As Variant
Public OBJID_ParDefFlags As Variant
Public OBJID_ParDefType As Variant
Public OBJID_ParDefDesc As Variant
Public OBJID_ParDefDefault As Variant
Public OBJID_ParDefGUID As Variant
Public OBJID_ParameterDef As Variant
Public OBJID_CreateParDef As Variant
Public OBJID_CreateParDefObjID As Variant
Public OBJID_CreateParDefName As Variant
Public OBJID_CreateParDefType As Variant
Public OBJID_CreateParDefFlags As Variant
Public OBJID_CreateParDefDesc As Variant
Public OBJID_CreateParDefDefault As Variant
Public OBJID_CreateParDefParDef As Variant
Public OBJID_RepositoryObject As Variant
Public OBJID_RepositoryObjectVersion As Variant
Public OBJID_Relationship As Variant
Public OBJID_VersionedRelationship As Variant
Public OBJID_ReposProperty As Variant
Public OBJID_ReposProperties As Variant
Public OBJID_RelationshipCol As Variant
Public OBJID_ObjectCol As Variant
Public OBJID_VersionCol As Variant
Public OBJID_Repository As Variant
Public OBJID_IPropDef2 As Variant
Public OBJID_IRepository As Variant
Public OBJID_IReposProperties As Variant
Public OBJID_IReposProperty As Variant
Public OBJID_IReposPropertyLarge As Variant
Public OBJID_IRepositoryTransaction As Variant
Public OBJID_IObjectCol As Variant
Public OBJID_ITargetObjectCol As Variant
Public OBJID_IRepositoryObjectStorage As Variant
Public OBJID_IRelationshipCol As Variant
Public OBJID_IObjectCol2 As Variant
Public OBJID_IRepository2 As Variant
Public OBJID_IRepositoryODBC As Variant
Public OBJID_IRepositoryODBC2 As Variant
Public OBJID_IReposTypeLib2 As Variant
Public OBJID_ReposPropLargeSize As Variant
Public OBJID_ReposPropLargeCurrentPosition As Variant
Public OBJID_RepositoryItemType As Variant
Public OBJID_RepositoryItemName As Variant
Public OBJID_Create As Variant
Public OBJID_Open As Variant
Public OBJID_CreateObject As Variant
Public OBJID_IRepositoryRefresh As Variant
Public OBJID_ObjectIDToInternalID As Variant
Public OBJID_InternalIDToObjectID As Variant
Public OBJID_Refresh As Variant
Public OBJID_Delete As Variant
Public OBJID_Lock As Variant
Public OBJID_Begin As Variant
Public OBJID_Commit As Variant
Public OBJID_Abort As Variant
Public OBJID_GetOption As Variant
Public OBJID_SetOption As Variant
Public OBJID_Flush As Variant
Public OBJID_IVersionColRefresh As Variant
Public OBJID_IVersionColAdd As Variant
Public OBJID_IVersionColRemove As Variant
Public OBJID_CreateVersion As Variant
Public OBJID_FreezeVersion As Variant
Public OBJID_MergeVersion As Variant
Public OBJID_Checkout As Variant
Public OBJID_Checkin As Variant
Public OBJID_IObjectColRefresh As Variant
Public OBJID_ITargetObjectColAdd As Variant
Public OBJID_ITargetObjectColRemove As Variant
Public OBJID_ITargetObjectColInsert As Variant
Public OBJID_ITargetObjectColMove As Variant
Public OBJID_InitNew As Variant
Public OBJID_Load As Variant
Public OBJID_Pin As Variant
Public OBJID_Unpin As Variant
Public OBJID_IRelationshipColAdd As Variant
Public OBJID_IRelationshipColRemove As Variant
Public OBJID_IRelationshipColInsert As Variant
Public OBJID_IRelationshipColMove As Variant
Public OBJID_IRelationshipColRefresh As Variant
Public OBJID_Cancel As Variant
Public OBJID_VersionIDToInternalID As Variant
Public OBJID_InternalIDToVersionID As Variant
Public OBJID_CreateObjectEx As Variant
Public OBJID_GetNewConnection As Variant
Public OBJID_FreeConnection As Variant
Public OBJID_ExecuteQuery As Variant
Public OBJID_IRepositoryODBC2GetOption As Variant
Public OBJID_IRepositoryODBC2SetOption As Variant
Public OBJID_CreateRelationshipColDef As Variant
Public OBJID_CreatePropertyDef As Variant
Public OBJID_CreateMethodDef As Variant
Public OBJID_IInterfaceDefObjectInstances As Variant
Public OBJID_AddInterface As Variant
Public OBJID_IClassDefCreateInterfaceDef As Variant
Public OBJID_IClassDefObjectInstances As Variant
Public OBJID_CreateAlias As Variant
Public OBJID_CreateClassDef As Variant
Public OBJID_CreateInterfaceDef As Variant
Public OBJID_CreateRelationshipDef As Variant
Public OBJID_CreateTypeLib As Variant
Public OBJID_RepositoryPropertyLargeRead As Variant
Public OBJID_RepositoryPropertyLargeWrite As Variant
Public OBJID_RepositoryPropertyLargeClose As Variant
Public OBJID_RepositoryPropertyLargeReadFromFile As Variant
Public OBJID_RepositoryPropertyLargeWriteToFile As Variant
Public OBJID_CreateConnect As Variant
Public OBJID_CreateUser As Variant
Public OBJID_CreatePassword As Variant
Public OBJID_CreateFlags As Variant
Public OBJID_CreateRoot As Variant
Public OBJID_OpenConnect As Variant
Public OBJID_OpenUser As Variant
Public OBJID_OpenPassword As Variant
Public OBJID_OpenFlags As Variant
Public OBJID_OpenRoot As Variant
Public OBJID_CreateObjectTypeID As Variant
Public OBJID_CreateObjectObjID As Variant
Public OBJID_CreateObjectReposObj As Variant
Public OBJID_IRepositoryRefreshMilliseconds As Variant
Public OBJID_ObjectIDToInternalIDObjID As Variant
Public OBJID_ObjectIDToInternalIDIntID As Variant
Public OBJID_InternalIDToObjectIDIntID As Variant
Public OBJID_InternalIDToObjectIDObjID As Variant
Public OBJID_RefreshMilliseconds As Variant
Public OBJID_GetOptionOption As Variant
Public OBJID_GetOptionValue As Variant
Public OBJID_SetOptionOption As Variant
Public OBJID_SetOptionValue As Variant
Public OBJID_IVersionColRefreshMilliseconds As Variant
Public OBJID_IVersionColRemoveItem As Variant
Public OBJID_CreateVersionVersoinID As Variant
Public OBJID_CreateVersionCreatedVersion As Variant
Public OBJID_MergeVersionOtherVersion As Variant
Public OBJID_MergeVersionFlags As Variant
Public OBJID_IObjectColRefreshMilliseconds As Variant
Public OBJID_ITargetObjectColAddReposObj As Variant
Public OBJID_ITargetObjectColAddNamel As Variant
Public OBJID_ITargetObjectColAddRelship As Variant
Public OBJID_ITargetObjectColRemoveItem As Variant
Public OBJID_ITargetObjectColInsertReposObj As Variant
Public OBJID_ITargetObjectColInsertIndex As Variant
Public OBJID_ITargetObjectColInsertName As Variant
Public OBJID_ITargetObjectColInsertRelship As Variant
Public OBJID_ITargetObjectColMoveIndexFrom As Variant
Public OBJID_ITargetObjectColMoveIndexTo As Variant
Public OBJID_InitNewRepos As Variant
Public OBJID_InitNewCookie As Variant
Public OBJID_LoadRepos As Variant
Public OBJID_LoadCookie As Variant
Public OBJID_PinReposVersion As Variant
Public OBJID_IRelationshipColAddReposObj As Variant
Public OBJID_IRelationshipColAddName As Variant
Public OBJID_IRelationshipColAddRemove As Variant
Public OBJID_IRelationshipColInsertReposObj As Variant
Public OBJID_IRelationshipColInsertIndex As Variant
Public OBJID_IRelationshipColInsertName As Variant
Public OBJID_IRelationshipColInsertRelship As Variant
Public OBJID_IRelationshipColMoveIndexFrom As Variant
Public OBJID_IRelationshipColMoveIndexTo As Variant
Public OBJID_IRelationshipColRefreshMilliseconds As Variant
Public OBJID_VersionIDToInternalIDExtVersionID As Variant
Public OBJID_VersionIDToInternalIDIntVersionID As Variant
Public OBJID_InternalIDToVersionIDIntVersionID As Variant
Public OBJID_InternalIDToVersionIDExtVersionID As Variant
Public OBJID_GetNewConnectionHdbc As Variant
Public OBJID_FreeConnecionHdbc As Variant
Public OBJID_ExecuteQueryQuery As Variant
Public OBJID_ExecuteQueryCol As Variant
Public OBJID_IRepositoryODBC2GetOptionOption As Variant
Public OBJID_IRepositoryODBC2GetOptionValue As Variant
Public OBJID_IRepositoryODBC2SetOptionOption As Variant
Public OBJID_IRepositoryODBC2SetOptionValue As Variant
Public OBJID_CreateRelationshipColDefObjID As Variant
Public OBJID_CreateRelationshipColDefName As Variant
Public OBJID_CreateRelationshipColDefDispID As Variant
Public OBJID_CreateRelationshipColDefIsOrigin As Variant
Public OBJID_CreateRelationshipColDefFlags As Variant
Public OBJID_CreateRelationshipColDefRelshipDef As Variant
Public OBJID_CreateRelationshipColDefColDef As Variant
Public OBJID_CreatePropertyDefObjID As Variant
Public OBJID_CreatePropertyDefName As Variant
Public OBJID_CreatePropertyDefDispID As Variant
Public OBJID_CreatePropertyDefType As Variant
Public OBJID_CreatePropertyDefPropDef As Variant
Public OBJID_CreateMethodDefObjID As Variant
Public OBJID_CreateMethodDefName As Variant
Public OBJID_CreateMethodDefDispID As Variant
Public OBJID_CreateMethodDefMethodDef As Variant
Public OBJID_IInterfaceDefObjectInstancesObject As Variant
Public OBJID_AddInterfaceInterfaceDef As Variant
Public OBJID_AddInterfaceFlags As Variant
Public OBJID_ClassDefCreateInterfaceDefObjID As Variant
Public OBJID_ClassDefCreateInterfaceDefName As Variant
Public OBJID_ClassDefCreateInterfaceDefIID As Variant
Public OBJID_ClassDefCreateInterfaceDefAncestor As Variant
Public OBJID_ClassDefCreateInterfaceDefFlags As Variant
Public OBJID_ClassDefCreateInterfaceDefIfaceDef As Variant
Public OBJID_IClassDefObjectInstancesObjectCol As Variant
Public OBJID_CreateAliasObjID As Variant
Public OBJID_CreateAliasName As Variant
Public OBJID_CreateAliasDispID As Variant
Public OBJID_CreateAliasBase As Variant
Public OBJID_CreateAliasAlias As Variant
Public OBJID_CreateClassDefObjID As Variant
Public OBJID_CreateClassDefName As Variant
Public OBJID_CreateClassDefClassID As Variant
Public OBJID_CreateClassDefClassDef As Variant
Public OBJID_CreateInterfaceDefObjID As Variant
Public OBJID_CreateInterfaceDefName As Variant
Public OBJID_CreateInterfaceDefIID As Variant
Public OBJID_CreateInterfaceDefAncestor As Variant
Public OBJID_CreateInterfaceDefIfaceDef As Variant
Public OBJID_CreateRelationshipDefObjID As Variant
Public OBJID_CreateRelationshipDefName As Variant
Public OBJID_CreateRelationshipDefRelshipDef As Variant
Public OBJID_CreateTypeLibObjID As Variant
Public OBJID_CreateTypeLibName As Variant
Public OBJID_CreateTypeLibTypeLibID As Variant
Public OBJID_CreateTypeLibTypeLib As Variant
Public OBJID_IRepositoryPropertyLargeReadChunkSize As Variant
Public OBJID_IRepositoryPropertyLargeReadSizeRead As Variant
Public OBJID_IRepositoryPropertyLargeReadBlob As Variant
Public OBJID_IRepositoryPropertyLargeWriteBlob As Variant
Public OBJID_IRepositoryPropertyLargeReadFromFileFileName As Variant
Public OBJID_IRepositoryPropertyLargeWriteToFileFileName As Variant
Public OBJID_RReposTypeLib2Dependency As Variant
Public OBJID_IReposTypeLib2DependsOn As Variant
Public OBJID_IReposTypeLib2UsedBy As Variant
Public OBJID_IReposOptions As Variant
Public OBJID_IReposOptionsGetOption As Variant
Public OBJID_IReposOptionsSetOption As Variant
Public OBJID_IReposOptionsResetOptions As Variant
Public OBJID_IReposOptionsGetOptionOption As Variant
Public OBJID_IReposOptionsGetOptionValue As Variant
Public OBJID_IReposOptionsSetOptionOption As Variant
Public OBJID_IReposOptionsSetOptionValue As Variant
Public OBJID_ScriptDef As Variant
Public OBJID_IScriptDef As Variant
Public OBJID_IScriptDefLanguage As Variant
Public OBJID_IScriptDefBody As Variant
Public OBJID_IScriptDefValidateScript As Variant
Public OBJID_RClassUsesScript As Variant
Public OBJID_UsingClasses As Variant
Public OBJID_ScriptsUsedByClass As Variant
Public OBJID_RInterafceUsesScript As Variant
Public OBJID_UsingInterfaces As Variant
Public OBJID_ScriptsUsedByInterface As Variant
Public OBJID_RMemberUsesScript As Variant
Public OBJID_UsingMember As Variant
Public OBJID_ScriptsUsedByMember As Variant
Public OBJID_IRepositoryTransaction2 As Variant
Public OBJID_IRepositoryTransaction2Transaction As Variant
Public OBJID_IRepositoryTransaction2JoinTransaction As Variant
Public OBJID_IReposProperty2 As Variant
Public OBJID_IReposObj2 As Variant
Public OBJID_EnumerationDef As Variant
Public OBJID_IEnumerationDef As Variant
Public OBJID_IEnumerationDefIsFlag As Variant
Public OBJID_IEnumerationDefValues As Variant
Public OBJID_IEnumerationDefEnumFor As Variant
Public OBJID_REnumerationValues As Variant
Public OBJID_EnumerationValueDef As Variant
Public OBJID_IEnumerationValueDef As Variant
Public OBJID_IEnumerationValueDefValue As Variant
Public OBJID_IEnumerationValueDefValueOf As Variant
Public OBJID_PropDefEnumerationDef As Variant
Public OBJID_REnumerationForProperty As Variant
Public OBJID_IViewClassDef As Variant
Public OBJID_IViewClassDefFlags As Variant
Public OBJID_IViewClassDefViewName As Variant
Public OBJID_IViewInterfaceDef As Variant
Public OBJID_IViewInterfaceDefFlags As Variant
Public OBJID_IViewInterfaceDefViewName As Variant
Public OBJID_IViewRelationshipDef As Variant
Public OBJID_IViewRelationshipDefFlags As Variant
Public OBJID_IViewRelationshipDefColumnNamePrefix As Variant
Public OBJID_IViewRelationshipDefJunctionViewName As Variant
Public OBJID_IViewPropertyDef As Variant
Public OBJID_IViewPropertyDefViewColumnName As Variant
Public OBJID_TransientObjCol As Variant
Public OBJID_ITransientObjCol As Variant
Public OBJID_ITransientObjColAdd As Variant
Public OBJID_ITransientObjColRemove As Variant
Public OBJID_ITransientObjColAddReposObj As Variant
Public OBJID_ITransientObjColRemoveItem As Variant
Public OBJID_IReposQueryGetCollection As Variant

' -------------------------------------------------------------
' This function just stuffs the 16 byte values that you pass in
' into a contiguous GUID variant.
' -------------------------------------------------------------

Function InitGuid(a As Byte, b As Byte, c As Byte, d As Byte, _
e As Byte, f As Byte, g As Byte, h As Byte, _
i As Byte, j As Byte, k As Byte, l As Byte, _
m As Byte, n As Byte, o As Byte, p As Byte) As Variant

Dim Guid(0 to 15) As Byte

Guid(0) = a
Guid(1) = b
Guid(2) = c
Guid(3) = d
Guid(4) = e
Guid(5) = f
Guid(6) = g
Guid(7) = h
Guid(8) = i
Guid(9) = j
Guid(10) = k
Guid(11) = l
Guid(12) = m
Guid(13) = n
Guid(14) = o
Guid(15) = p

InitGuid = Guid
End Function

' -------------------------------------------------------------
' This sub sets up an object identifier with the unique value
' that you pass in placed in the correct part of the object id
' -------------------------------------------------------------

Sub DEFINE_OBJID(ByRef id As Variant, uniquifier As Long, base() As Long)
    base(4) = uniquifier
    id = base
End Sub

' -------------------------------------------------------------
' This sub initialize all of the object identifiers for Type
' Information Model definition objects to their correct values
' -------------------------------------------------------------

Sub InitRepository()

Dim objID(0 to 4) As Long

CLSID_RepositoryObject = InitGuid(&HFB, &H70, &H22, &H6E, &H99, &HF7, &HCF, &H11, &H92, &H27, 0, &HAA, 0, &HA1, &HEB, &H95)

'Set up the guid portion of the object IDs
ObjID(0) = &H90591B0C
ObjID(1) = &H11CF24F7
ObjID(2) = &HAA000A92
ObjID(3) = &H95EBA100

'Define Object IDs
Call DEFINE_OBJID(OBJID_ClassDef, 0, ObjID)
Call DEFINE_OBJID(OBJID_InterfaceDef, 1, ObjID)
Call DEFINE_OBJID(OBJID_CollectionDef, 2, ObjID)
Call DEFINE_OBJID(OBJID_MethodDef, 3, ObjID)
Call DEFINE_OBJID(OBJID_PropertyDef, 4, ObjID)
Call DEFINE_OBJID(OBJID_RelationshipDef, 5, ObjID)
Call DEFINE_OBJID(OBJID_ReposTypeLib, 6, ObjID)
Call DEFINE_OBJID(OBJID_ReposRoot, 7, ObjID)
Call DEFINE_OBJID(OBJID_IUnknown, 8, ObjID)
Call DEFINE_OBJID(OBJID_IDispatch, 9, ObjID)
Call DEFINE_OBJID(OBJID_IReposDispatch, 10, ObjID)
Call DEFINE_OBJID(OBJID_IReposTypeInfo, 11, ObjID)
Call DEFINE_OBJID(OBJID_IClassDef, 12, ObjID)
Call DEFINE_OBJID(OBJID_IInterfaceDef, 13, ObjID)
Call DEFINE_OBJID(OBJID_IInterfaceMember, 14, ObjID)
Call DEFINE_OBJID(OBJID_IPropertyDef, 15, ObjID)
Call DEFINE_OBJID(OBJID_ICollectionDef, 16, ObjID)
Call DEFINE_OBJID(OBJID_IRepositoryItem, 17, ObjID)
Call DEFINE_OBJID(OBJID_IRepositoryObject, 18, ObjID)
Call DEFINE_OBJID(OBJID_IRelationship, 19, ObjID)
Call DEFINE_OBJID(OBJID_IAnnotationalProps, 20, ObjID)
Call DEFINE_OBJID(OBJID_ISummaryInfo, 21, ObjID)
Call DEFINE_OBJID(OBJID_INamedObject, 22, ObjID)
Call DEFINE_OBJID(OBJID_IManageReposTypeLib, 23, ObjID)
Call DEFINE_OBJID(OBJID_IReposTypeLib, 24, ObjID)
Call DEFINE_OBJID(OBJID_IReposRoot, 25, ObjID)
Call DEFINE_OBJID(OBJID_RClassImplIface, 26, ObjID)
Call DEFINE_OBJID(OBJID_RIfaceInheritsFromIface, 27, ObjID)
Call DEFINE_OBJID(OBJID_RIfaceHasMembers, 28, ObjID)
Call DEFINE_OBJID(OBJID_RColContainsItems, 29, ObjID)
Call DEFINE_OBJID(OBJID_RContainerContextForReposTLBs, 30, ObjID)
Call DEFINE_OBJID(OBJID_RReposTLBScopeForReposTypeInfo, 31, ObjID)
Call DEFINE_OBJID(OBJID_Ifaces, 32, ObjID)
Call DEFINE_OBJID(OBJID_Classes, 33, ObjID)
Call DEFINE_OBJID(OBJID_Ancestor, 34, ObjID)
Call DEFINE_OBJID(OBJID_Descendants, 35, ObjID)
Call DEFINE_OBJID(OBJID_Members, 36, ObjID)
Call DEFINE_OBJID(OBJID_Iface, 37, ObjID)
Call DEFINE_OBJID(OBJID_CollectionItem, 38, ObjID)
Call DEFINE_OBJID(OBJID_ItemInCollections, 39, ObjID)
Call DEFINE_OBJID(OBJID_ReposTypeLibs, 40, ObjID)
Call DEFINE_OBJID(OBJID_ReposTLBContexts, 41, ObjID)
Call DEFINE_OBJID(OBJID_ReposTypeInfos, 42, ObjID)
Call DEFINE_OBJID(OBJID_ReposTypeLibScopes, 43, ObjID)
Call DEFINE_OBJID(OBJID_ReposRootObj, 44, ObjID)
Call DEFINE_OBJID(OBJID_ReposTIM, 45, ObjID)
Call DEFINE_OBJID(OBJID_ClassID, 46, ObjID)
Call DEFINE_OBJID(OBJID_PropDescs, 47, ObjID)
Call DEFINE_OBJID(OBJID_InterfaceID, 48, ObjID)
Call DEFINE_OBJID(OBJID_TableName, 49, ObjID)
Call DEFINE_OBJID(OBJID_InterfaceFlags, 50, ObjID)
Call DEFINE_OBJID(OBJID_DispID, 51, ObjID)
Call DEFINE_OBJID(OBJID_InterfaceMemberFlags, 52, ObjID)
Call DEFINE_OBJID(OBJID_RelshipTypeID, 53, ObjID)
Call DEFINE_OBJID(OBJID_CollectionFlags, 54, ObjID)
Call DEFINE_OBJID(OBJID_MinCount, 55, ObjID)
Call DEFINE_OBJID(OBJID_MaxCount, 56, ObjID)
Call DEFINE_OBJID(OBJID_IsOrigin, 57, ObjID)
Call DEFINE_OBJID(OBJID_ColumnName, 58, ObjID)
Call DEFINE_OBJID(OBJID_APIType, 59, ObjID)
Call DEFINE_OBJID(OBJID_SQLType, 60, ObjID)
Call DEFINE_OBJID(OBJID_SQLSize, 61, ObjID)
Call DEFINE_OBJID(OBJID_SQLScale, 62, ObjID)
Call DEFINE_OBJID(OBJID_TypeLibID, 64, ObjID)
Call DEFINE_OBJID(OBJID_TypeID, 65, ObjID)
Call DEFINE_OBJID(OBJID_Comments, 66, ObjID)
Call DEFINE_OBJID(OBJID_ShortDescription, 67, ObjID)
Call DEFINE_OBJID(OBJID_ObjectName, 68, ObjID)
Call DEFINE_OBJID(OBJID_RelationshipTgtName, 69, ObjID)
Call DEFINE_OBJID(OBJID_ImplementsOptions, 70, ObjID)
Call DEFINE_OBJID(OBJID_NULL, &HFFFFFFFF, ObjID)
Call DEFINE_OBJID(OBJID_IReposVersion, 71, ObjID)
Call DEFINE_OBJID(OBJID_IVersionCol, 72, ObjID)
Call DEFINE_OBJID(OBJID_IVersionedRelship, 73, ObjID)
Call DEFINE_OBJID(OBJID_Workspace, 74, ObjID)
Call DEFINE_OBJID(OBJID_IWorkspaceItem, 76, ObjID)
Call DEFINE_OBJID(OBJID_IWorkspace, 75, ObjID)
Call DEFINE_OBJID(OBJID_IVersionAdminInfo, 77, ObjID)
Call DEFINE_OBJID(OBJID_VersionCreateTime, 78, ObjID)
Call DEFINE_OBJID(OBJID_VersionModifyTime, 79, ObjID)
Call DEFINE_OBJID(OBJID_CreateByUser, 80, ObjID)
Call DEFINE_OBJID(OBJID_ModifyByUser, 81, ObjID)
Call DEFINE_OBJID(OBJID_IWorkspaceContainer, 82, ObjID)
Call DEFINE_OBJID(OBJID_RWksContainerContainsWorkspaces, 83, ObjID)
Call DEFINE_OBJID(OBJID_ContainedWorkspaces, 84, ObjID)
Call DEFINE_OBJID(OBJID_WorkspaceContainers, 85, ObjID)
Call DEFINE_OBJID(OBJID_InsertSProcName, 86, ObjID)
Call DEFINE_OBJID(EXTVERSIONID_NULL, &HFFFFFFFF, ObjID)
Call DEFINE_OBJID(OBJID_SQLBlobSize, 87, ObjID)
Call DEFINE_OBJID(OBJID_IPropertyDef2, 88, ObjID)
Call DEFINE_OBJID(OBJID_Alias, 119, ObjID)
Call DEFINE_OBJID(OBJID_IVersionAdminInfo2, 89, ObjID)
Call DEFINE_OBJID(OBJID_IIfaceDef2, 93, ObjID)
Call DEFINE_OBJID(OBJID_IIfaceMember2, 97, ObjID)
Call DEFINE_OBJID(OBJID_RInterfaceImpliesInterface, 94, ObjID)
Call DEFINE_OBJID(OBJID_RBaseMemberServicesDerivedMembers, 98, ObjID)
Call DEFINE_OBJID(OBJID_Implies, 95, ObjID)
Call DEFINE_OBJID(OBJID_ImpliedBy, 96, ObjID)
Call DEFINE_OBJID(OBJID_ServicesDerivedMembers, 99, ObjID)
Call DEFINE_OBJID(OBJID_ServicedByBaseMember, 100, ObjID)
Call DEFINE_OBJID(OBJID_VersionLabel, 90, ObjID)
Call DEFINE_OBJID(OBJID_VersionComments, 92, ObjID)
Call DEFINE_OBJID(OBJID_VersionShortDesc, 91, ObjID)
Call DEFINE_OBJID(OBJID_RInterfaceMemberHasParameters, 108, ObjID)
Call DEFINE_OBJID(OBJID_Member, 109, ObjID)
Call DEFINE_OBJID(OBJID_Parameters, 110, ObjID)
Call DEFINE_OBJID(OBJID_IMethodDef, 101, ObjID)
Call DEFINE_OBJID(OBJID_IParameterDef, 102, ObjID)
Call DEFINE_OBJID(OBJID_ParDefFlags, 103, ObjID)
Call DEFINE_OBJID(OBJID_ParDefType, 104, ObjID)
Call DEFINE_OBJID(OBJID_ParDefDesc, 105, ObjID)
Call DEFINE_OBJID(OBJID_ParDefDefault, 106, ObjID)
Call DEFINE_OBJID(OBJID_ParDefGUID, 107, ObjID)
Call DEFINE_OBJID(OBJID_ParameterDef, 120, ObjID)
Call DEFINE_OBJID(OBJID_CreateParDef, 111, ObjID)
Call DEFINE_OBJID(OBJID_CreateParDefObjID, 112, ObjID)
Call DEFINE_OBJID(OBJID_CreateParDefName, 113, ObjID)
Call DEFINE_OBJID(OBJID_CreateParDefType, 114, ObjID)
Call DEFINE_OBJID(OBJID_CreateParDefFlags, 115, ObjID)
Call DEFINE_OBJID(OBJID_CreateParDefDesc, 116, ObjID)
Call DEFINE_OBJID(OBJID_CreateParDefDefault, 117, ObjID)
Call DEFINE_OBJID(OBJID_CreateParDefParDef, 118, ObjID)
Call DEFINE_OBJID(OBJID_RepositoryObject, 121, ObjID)
Call DEFINE_OBJID(OBJID_RepositoryObjectVersion, 122, ObjID)
Call DEFINE_OBJID(OBJID_Relationship, 123, ObjID)
Call DEFINE_OBJID(OBJID_VersionedRelationship, 124, ObjID)
Call DEFINE_OBJID(OBJID_ReposProperty, 125, ObjID)
Call DEFINE_OBJID(OBJID_ReposProperties, 126, ObjID)
Call DEFINE_OBJID(OBJID_RelationshipCol, 127, ObjID)
Call DEFINE_OBJID(OBJID_ObjectCol, 128, ObjID)
Call DEFINE_OBJID(OBJID_VersionCol, 129, ObjID)
Call DEFINE_OBJID(OBJID_Repository, 130, ObjID)
Call DEFINE_OBJID(OBJID_IPropDef2, 88, ObjID)
Call DEFINE_OBJID(OBJID_IRepository, 131, ObjID)
Call DEFINE_OBJID(OBJID_IReposProperties, 132, ObjID)
Call DEFINE_OBJID(OBJID_IReposProperty, 133, ObjID)
Call DEFINE_OBJID(OBJID_IReposPropertyLarge, 134, ObjID)
Call DEFINE_OBJID(OBJID_IRepositoryTransaction, 135, ObjID)
Call DEFINE_OBJID(OBJID_IObjectCol, 136, ObjID)
Call DEFINE_OBJID(OBJID_ITargetObjectCol, 137, ObjID)
Call DEFINE_OBJID(OBJID_IRepositoryObjectStorage, 138, ObjID)
Call DEFINE_OBJID(OBJID_IRelationshipCol, 139, ObjID)
Call DEFINE_OBJID(OBJID_IObjectCol2, 140, ObjID)
Call DEFINE_OBJID(OBJID_IRepository2, 141, ObjID)
Call DEFINE_OBJID(OBJID_IRepositoryODBC, 142, ObjID)
Call DEFINE_OBJID(OBJID_IRepositoryODBC2, 143, ObjID)
Call DEFINE_OBJID(OBJID_IReposTypeLib2, 144, ObjID)
Call DEFINE_OBJID(OBJID_ReposPropLargeSize, 145, ObjID)
Call DEFINE_OBJID(OBJID_ReposPropLargeCurrentPosition, 327, ObjID)
Call DEFINE_OBJID(OBJID_RepositoryItemType, 146, ObjID)
Call DEFINE_OBJID(OBJID_RepositoryItemName, 147, ObjID)
Call DEFINE_OBJID(OBJID_Create, 148, ObjID)
Call DEFINE_OBJID(OBJID_Open, 149, ObjID)
Call DEFINE_OBJID(OBJID_CreateObject, 150, ObjID)
Call DEFINE_OBJID(OBJID_IRepositoryRefresh, 151, ObjID)
Call DEFINE_OBJID(OBJID_ObjectIDToInternalID, 152, ObjID)
Call DEFINE_OBJID(OBJID_InternalIDToObjectID, 153, ObjID)
Call DEFINE_OBJID(OBJID_Refresh, 154, ObjID)
Call DEFINE_OBJID(OBJID_Delete, 155, ObjID)
Call DEFINE_OBJID(OBJID_Lock, 156, ObjID)
Call DEFINE_OBJID(OBJID_Begin, 157, ObjID)
Call DEFINE_OBJID(OBJID_Commit, 158, ObjID)
Call DEFINE_OBJID(OBJID_Abort, 159, ObjID)
Call DEFINE_OBJID(OBJID_GetOption, 160, ObjID)
Call DEFINE_OBJID(OBJID_SetOption, 161, ObjID)
Call DEFINE_OBJID(OBJID_Flush, 162, ObjID)
Call DEFINE_OBJID(OBJID_IVersionColRefresh, 163, ObjID)
Call DEFINE_OBJID(OBJID_IVersionColAdd, 164, ObjID)
Call DEFINE_OBJID(OBJID_IVersionColRemove, 165, ObjID)
Call DEFINE_OBJID(OBJID_CreateVersion, 166, ObjID)
Call DEFINE_OBJID(OBJID_FreezeVersion, 167, ObjID)
Call DEFINE_OBJID(OBJID_MergeVersion, 168, ObjID)
Call DEFINE_OBJID(OBJID_Checkout, 169, ObjID)
Call DEFINE_OBJID(OBJID_Checkin, 170, ObjID)
Call DEFINE_OBJID(OBJID_IObjectColRefresh, 171, ObjID)
Call DEFINE_OBJID(OBJID_ITargetObjectColAdd, 172, ObjID)
Call DEFINE_OBJID(OBJID_ITargetObjectColRemove, 173, ObjID)
Call DEFINE_OBJID(OBJID_ITargetObjectColInsert, 174, ObjID)
Call DEFINE_OBJID(OBJID_ITargetObjectColMove, 175, ObjID)
Call DEFINE_OBJID(OBJID_InitNew, 176, ObjID)
Call DEFINE_OBJID(OBJID_Load, 177, ObjID)
Call DEFINE_OBJID(OBJID_Pin, 178, ObjID)
Call DEFINE_OBJID(OBJID_Unpin, 179, ObjID)
Call DEFINE_OBJID(OBJID_IRelationshipColAdd, 180, ObjID)
Call DEFINE_OBJID(OBJID_IRelationshipColRemove, 181, ObjID)
Call DEFINE_OBJID(OBJID_IRelationshipColInsert, 182, ObjID)
Call DEFINE_OBJID(OBJID_IRelationshipColMove, 183, ObjID)
Call DEFINE_OBJID(OBJID_IRelationshipColRefresh, 184, ObjID)
Call DEFINE_OBJID(OBJID_Cancel, 185, ObjID)
Call DEFINE_OBJID(OBJID_VersionIDToInternalID, 186, ObjID)
Call DEFINE_OBJID(OBJID_InternalIDToVersionID, 187, ObjID)
Call DEFINE_OBJID(OBJID_CreateObjectEx, 188, ObjID)
Call DEFINE_OBJID(OBJID_GetNewConnection, 189, ObjID)
Call DEFINE_OBJID(OBJID_FreeConnection, 190, ObjID)
Call DEFINE_OBJID(OBJID_ExecuteQuery, 191, ObjID)
Call DEFINE_OBJID(OBJID_IRepositoryODBC2GetOption, 192, ObjID)
Call DEFINE_OBJID(OBJID_IRepositoryODBC2SetOption, 193, ObjID)
Call DEFINE_OBJID(OBJID_CreateRelationshipColDef, 194, ObjID)
Call DEFINE_OBJID(OBJID_CreatePropertyDef, 195, ObjID)
Call DEFINE_OBJID(OBJID_CreateMethodDef, 196, ObjID)
Call DEFINE_OBJID(OBJID_IInterfaceDefObjectInstances, 197, ObjID)
Call DEFINE_OBJID(OBJID_AddInterface, 198, ObjID)
Call DEFINE_OBJID(OBJID_IClassDefCreateInterfaceDef, 199, ObjID)
Call DEFINE_OBJID(OBJID_IClassDefObjectInstances, 200, ObjID)
Call DEFINE_OBJID(OBJID_CreateAlias, 201, ObjID)
Call DEFINE_OBJID(OBJID_CreateClassDef, 202, ObjID)
Call DEFINE_OBJID(OBJID_CreateInterfaceDef, 203, ObjID)
Call DEFINE_OBJID(OBJID_CreateRelationshipDef, 204, ObjID)
Call DEFINE_OBJID(OBJID_CreateTypeLib, 205, ObjID)
Call DEFINE_OBJID(OBJID_RepositoryPropertyLargeRead, 206, ObjID)
Call DEFINE_OBJID(OBJID_RepositoryPropertyLargeWrite, 207, ObjID)
Call DEFINE_OBJID(OBJID_RepositoryPropertyLargeClose, 208, ObjID)
Call DEFINE_OBJID(OBJID_RepositoryPropertyLargeReadFromFile, 328, ObjID)
Call DEFINE_OBJID(OBJID_RepositoryPropertyLargeWriteToFile, 329, ObjID)
Call DEFINE_OBJID(OBJID_CreateConnect, 209, ObjID)
Call DEFINE_OBJID(OBJID_CreateUser, 210, ObjID)
Call DEFINE_OBJID(OBJID_CreatePassword, 211, ObjID)
Call DEFINE_OBJID(OBJID_CreateFlags, 212, ObjID)
Call DEFINE_OBJID(OBJID_CreateRoot, 213, ObjID)
Call DEFINE_OBJID(OBJID_OpenConnect, 214, ObjID)
Call DEFINE_OBJID(OBJID_OpenUser, 215, ObjID)
Call DEFINE_OBJID(OBJID_OpenPassword, 216, ObjID)
Call DEFINE_OBJID(OBJID_OpenFlags, 217, ObjID)
Call DEFINE_OBJID(OBJID_OpenRoot, 218, ObjID)
Call DEFINE_OBJID(OBJID_CreateObjectTypeID, 219, ObjID)
Call DEFINE_OBJID(OBJID_CreateObjectObjID, 220, ObjID)
Call DEFINE_OBJID(OBJID_CreateObjectReposObj, 221, ObjID)
Call DEFINE_OBJID(OBJID_IRepositoryRefreshMilliseconds, 222, ObjID)
Call DEFINE_OBJID(OBJID_ObjectIDToInternalIDObjID, 223, ObjID)
Call DEFINE_OBJID(OBJID_ObjectIDToInternalIDIntID, 224, ObjID)
Call DEFINE_OBJID(OBJID_InternalIDToObjectIDIntID, 225, ObjID)
Call DEFINE_OBJID(OBJID_InternalIDToObjectIDObjID, 226, ObjID)
Call DEFINE_OBJID(OBJID_RefreshMilliseconds, 227, ObjID)
Call DEFINE_OBJID(OBJID_GetOptionOption, 228, ObjID)
Call DEFINE_OBJID(OBJID_GetOptionValue, 229, ObjID)
Call DEFINE_OBJID(OBJID_SetOptionOption, 230, ObjID)
Call DEFINE_OBJID(OBJID_SetOptionValue, 231, ObjID)
Call DEFINE_OBJID(OBJID_IVersionColRefreshMilliseconds, 232, ObjID)
Call DEFINE_OBJID(OBJID_IVersionColRemoveItem, 233, ObjID)
Call DEFINE_OBJID(OBJID_CreateVersionVersoinID, 234, ObjID)
Call DEFINE_OBJID(OBJID_CreateVersionCreatedVersion, 235, ObjID)
Call DEFINE_OBJID(OBJID_MergeVersionOtherVersion, 236, ObjID)
Call DEFINE_OBJID(OBJID_MergeVersionFlags, 237, ObjID)
Call DEFINE_OBJID(OBJID_IObjectColRefreshMilliseconds, 238, ObjID)
Call DEFINE_OBJID(OBJID_ITargetObjectColAddReposObj, 239, ObjID)
Call DEFINE_OBJID(OBJID_ITargetObjectColAddNamel, 240, ObjID)
Call DEFINE_OBJID(OBJID_ITargetObjectColAddRelship, 241, ObjID)
Call DEFINE_OBJID(OBJID_ITargetObjectColRemoveItem, 242, ObjID)
Call DEFINE_OBJID(OBJID_ITargetObjectColInsertReposObj, 243, ObjID)
Call DEFINE_OBJID(OBJID_ITargetObjectColInsertIndex, 244, ObjID)
Call DEFINE_OBJID(OBJID_ITargetObjectColInsertName, 245, ObjID)
Call DEFINE_OBJID(OBJID_ITargetObjectColInsertRelship, 246, ObjID)
Call DEFINE_OBJID(OBJID_ITargetObjectColMoveIndexFrom, 247, ObjID)
Call DEFINE_OBJID(OBJID_ITargetObjectColMoveIndexTo, 248, ObjID)
Call DEFINE_OBJID(OBJID_InitNewRepos, 249, ObjID)
Call DEFINE_OBJID(OBJID_InitNewCookie, 250, ObjID)
Call DEFINE_OBJID(OBJID_LoadRepos, 251, ObjID)
Call DEFINE_OBJID(OBJID_LoadCookie, 252, ObjID)
Call DEFINE_OBJID(OBJID_PinReposVersion, 253, ObjID)
Call DEFINE_OBJID(OBJID_IRelationshipColAddReposObj, 254, ObjID)
Call DEFINE_OBJID(OBJID_IRelationshipColAddName, 255, ObjID)
Call DEFINE_OBJID(OBJID_IRelationshipColAddRemove, 256, ObjID)
Call DEFINE_OBJID(OBJID_IRelationshipColInsertReposObj, 257, ObjID)
Call DEFINE_OBJID(OBJID_IRelationshipColInsertIndex, 258, ObjID)
Call DEFINE_OBJID(OBJID_IRelationshipColInsertName, 259, ObjID)
Call DEFINE_OBJID(OBJID_IRelationshipColInsertRelship, 260, ObjID)
Call DEFINE_OBJID(OBJID_IRelationshipColMoveIndexFrom, 261, ObjID)
Call DEFINE_OBJID(OBJID_IRelationshipColMoveIndexTo, 262, ObjID)
Call DEFINE_OBJID(OBJID_IRelationshipColRefreshMilliseconds, 263, ObjID)
Call DEFINE_OBJID(OBJID_VersionIDToInternalIDExtVersionID, 264, ObjID)
Call DEFINE_OBJID(OBJID_VersionIDToInternalIDIntVersionID, 265, ObjID)
Call DEFINE_OBJID(OBJID_InternalIDToVersionIDIntVersionID, 266, ObjID)
Call DEFINE_OBJID(OBJID_InternalIDToVersionIDExtVersionID, 267, ObjID)
Call DEFINE_OBJID(OBJID_GetNewConnectionHdbc, 268, ObjID)
Call DEFINE_OBJID(OBJID_FreeConnecionHdbc, 269, ObjID)
Call DEFINE_OBJID(OBJID_ExecuteQueryQuery, 270, ObjID)
Call DEFINE_OBJID(OBJID_ExecuteQueryCol, 271, ObjID)
Call DEFINE_OBJID(OBJID_IRepositoryODBC2GetOptionOption, 272, ObjID)
Call DEFINE_OBJID(OBJID_IRepositoryODBC2GetOptionValue, 273, ObjID)
Call DEFINE_OBJID(OBJID_IRepositoryODBC2SetOptionOption, 274, ObjID)
Call DEFINE_OBJID(OBJID_IRepositoryODBC2SetOptionValue, 275, ObjID)
Call DEFINE_OBJID(OBJID_CreateRelationshipColDefObjID, 276, ObjID)
Call DEFINE_OBJID(OBJID_CreateRelationshipColDefName, 277, ObjID)
Call DEFINE_OBJID(OBJID_CreateRelationshipColDefDispID, 278, ObjID)
Call DEFINE_OBJID(OBJID_CreateRelationshipColDefIsOrigin, 279, ObjID)
Call DEFINE_OBJID(OBJID_CreateRelationshipColDefFlags, 280, ObjID)
Call DEFINE_OBJID(OBJID_CreateRelationshipColDefRelshipDef, 281, ObjID)
Call DEFINE_OBJID(OBJID_CreateRelationshipColDefColDef, 282, ObjID)
Call DEFINE_OBJID(OBJID_CreatePropertyDefObjID, 283, ObjID)
Call DEFINE_OBJID(OBJID_CreatePropertyDefName, 284, ObjID)
Call DEFINE_OBJID(OBJID_CreatePropertyDefDispID, 285, ObjID)
Call DEFINE_OBJID(OBJID_CreatePropertyDefType, 286, ObjID)
Call DEFINE_OBJID(OBJID_CreatePropertyDefPropDef, 287, ObjID)
Call DEFINE_OBJID(OBJID_CreateMethodDefObjID, 288, ObjID)
Call DEFINE_OBJID(OBJID_CreateMethodDefName, 289, ObjID)
Call DEFINE_OBJID(OBJID_CreateMethodDefDispID, 290, ObjID)
Call DEFINE_OBJID(OBJID_CreateMethodDefMethodDef, 291, ObjID)
Call DEFINE_OBJID(OBJID_IInterfaceDefObjectInstancesObject, 292, ObjID)
Call DEFINE_OBJID(OBJID_AddInterfaceInterfaceDef, 293, ObjID)
Call DEFINE_OBJID(OBJID_AddInterfaceFlags, 294, ObjID)
Call DEFINE_OBJID(OBJID_ClassDefCreateInterfaceDefObjID, 295, ObjID)
Call DEFINE_OBJID(OBJID_ClassDefCreateInterfaceDefName, 296, ObjID)
Call DEFINE_OBJID(OBJID_ClassDefCreateInterfaceDefIID, 297, ObjID)
Call DEFINE_OBJID(OBJID_ClassDefCreateInterfaceDefAncestor, 298, ObjID)
Call DEFINE_OBJID(OBJID_ClassDefCreateInterfaceDefFlags, 299, ObjID)
Call DEFINE_OBJID(OBJID_ClassDefCreateInterfaceDefIfaceDef, 300, ObjID)
Call DEFINE_OBJID(OBJID_IClassDefObjectInstancesObjectCol, 301, ObjID)
Call DEFINE_OBJID(OBJID_CreateAliasObjID, 302, ObjID)
Call DEFINE_OBJID(OBJID_CreateAliasName, 303, ObjID)
Call DEFINE_OBJID(OBJID_CreateAliasDispID, 304, ObjID)
Call DEFINE_OBJID(OBJID_CreateAliasBase, 305, ObjID)
Call DEFINE_OBJID(OBJID_CreateAliasAlias, 306, ObjID)
Call DEFINE_OBJID(OBJID_CreateClassDefObjID, 307, ObjID)
Call DEFINE_OBJID(OBJID_CreateClassDefName, 308, ObjID)
Call DEFINE_OBJID(OBJID_CreateClassDefClassID, 309, ObjID)
Call DEFINE_OBJID(OBJID_CreateClassDefClassDef, 310, ObjID)
Call DEFINE_OBJID(OBJID_CreateInterfaceDefObjID, 311, ObjID)
Call DEFINE_OBJID(OBJID_CreateInterfaceDefName, 312, ObjID)
Call DEFINE_OBJID(OBJID_CreateInterfaceDefIID, 313, ObjID)
Call DEFINE_OBJID(OBJID_CreateInterfaceDefAncestor, 314, ObjID)
Call DEFINE_OBJID(OBJID_CreateInterfaceDefIfaceDef, 315, ObjID)
Call DEFINE_OBJID(OBJID_CreateRelationshipDefObjID, 316, ObjID)
Call DEFINE_OBJID(OBJID_CreateRelationshipDefName, 317, ObjID)
Call DEFINE_OBJID(OBJID_CreateRelationshipDefRelshipDef, 318, ObjID)
Call DEFINE_OBJID(OBJID_CreateTypeLibObjID, 319, ObjID)
Call DEFINE_OBJID(OBJID_CreateTypeLibName, 320, ObjID)
Call DEFINE_OBJID(OBJID_CreateTypeLibTypeLibID, 321, ObjID)
Call DEFINE_OBJID(OBJID_CreateTypeLibTypeLib, 322, ObjID)
Call DEFINE_OBJID(OBJID_IRepositoryPropertyLargeReadChunkSize, 323, ObjID)
Call DEFINE_OBJID(OBJID_IRepositoryPropertyLargeReadSizeRead, 324, ObjID)
Call DEFINE_OBJID(OBJID_IRepositoryPropertyLargeReadBlob, 325, ObjID)
Call DEFINE_OBJID(OBJID_IRepositoryPropertyLargeWriteBlob, 326, ObjID)
Call DEFINE_OBJID(OBJID_IRepositoryPropertyLargeReadFromFileFileName, 330, ObjID)
Call DEFINE_OBJID(OBJID_IRepositoryPropertyLargeWriteToFileFileName, 331, ObjID)
Call DEFINE_OBJID(OBJID_RReposTypeLib2Dependency, 332, ObjID)
Call DEFINE_OBJID(OBJID_IReposTypeLib2DependsOn, 333, ObjID)
Call DEFINE_OBJID(OBJID_IReposTypeLib2UsedBy, 334, ObjID)
Call DEFINE_OBJID(OBJID_IReposOptions, 335, ObjID)
Call DEFINE_OBJID(OBJID_IReposOptionsGetOption, 336, ObjID)
Call DEFINE_OBJID(OBJID_IReposOptionsSetOption, 337, ObjID)
Call DEFINE_OBJID(OBJID_IReposOptionsResetOptions, 338, ObjID)
Call DEFINE_OBJID(OBJID_IReposOptionsGetOptionOption, 339, ObjID)
Call DEFINE_OBJID(OBJID_IReposOptionsGetOptionValue, 340, ObjID)
Call DEFINE_OBJID(OBJID_IReposOptionsSetOptionOption, 341, ObjID)
Call DEFINE_OBJID(OBJID_IReposOptionsSetOptionValue, 342, ObjID)
Call DEFINE_OBJID(OBJID_ScriptDef, 343, ObjID)
Call DEFINE_OBJID(OBJID_IScriptDef, 344, ObjID)
Call DEFINE_OBJID(OBJID_IScriptDefLanguage, 345, ObjID)
Call DEFINE_OBJID(OBJID_IScriptDefBody, 346, ObjID)
Call DEFINE_OBJID(OBJID_IScriptDefValidateScript, 347, ObjID)
Call DEFINE_OBJID(OBJID_RClassUsesScript, 348, ObjID)
Call DEFINE_OBJID(OBJID_UsingClasses, 349, ObjID)
Call DEFINE_OBJID(OBJID_ScriptsUsedByClass, 350, ObjID)
Call DEFINE_OBJID(OBJID_RInterafceUsesScript, 351, ObjID)
Call DEFINE_OBJID(OBJID_UsingInterfaces, 352, ObjID)
Call DEFINE_OBJID(OBJID_ScriptsUsedByInterface, 353, ObjID)
Call DEFINE_OBJID(OBJID_RMemberUsesScript, 354, ObjID)
Call DEFINE_OBJID(OBJID_UsingMember, 355, ObjID)
Call DEFINE_OBJID(OBJID_ScriptsUsedByMember, 356, ObjID)
Call DEFINE_OBJID(OBJID_IRepositoryTransaction2, 358, ObjID)
Call DEFINE_OBJID(OBJID_IRepositoryTransaction2Transaction, 359, ObjID)
Call DEFINE_OBJID(OBJID_IRepositoryTransaction2JoinTransaction, 360, ObjID)
Call DEFINE_OBJID(OBJID_IReposProperty2, 361, ObjID)
Call DEFINE_OBJID(OBJID_IReposObj2, 362, ObjID)
Call DEFINE_OBJID(OBJID_EnumerationDef, 363, ObjID)
Call DEFINE_OBJID(OBJID_IEnumerationDef, 364, ObjID)
Call DEFINE_OBJID(OBJID_IEnumerationDefIsFlag, 365, ObjID)
Call DEFINE_OBJID(OBJID_IEnumerationDefValues, 366, ObjID)
Call DEFINE_OBJID(OBJID_IEnumerationDefEnumFor, 367, ObjID)
Call DEFINE_OBJID(OBJID_REnumerationValues, 368, ObjID)
Call DEFINE_OBJID(OBJID_EnumerationValueDef, 369, ObjID)
Call DEFINE_OBJID(OBJID_IEnumerationValueDef, 370, ObjID)
Call DEFINE_OBJID(OBJID_IEnumerationValueDefValue, 371, ObjID)
Call DEFINE_OBJID(OBJID_IEnumerationValueDefValueOf, 372, ObjID)
Call DEFINE_OBJID(OBJID_PropDefEnumerationDef, 373, ObjID)
Call DEFINE_OBJID(OBJID_REnumerationForProperty, 374, ObjID)
Call DEFINE_OBJID(OBJID_IViewClassDef, 375, ObjID)
Call DEFINE_OBJID(OBJID_IViewClassDefFlags, 376, ObjID)
Call DEFINE_OBJID(OBJID_IViewClassDefViewName, 377, ObjID)
Call DEFINE_OBJID(OBJID_IViewInterfaceDef, 378, ObjID)
Call DEFINE_OBJID(OBJID_IViewInterfaceDefFlags, 379, ObjID)
Call DEFINE_OBJID(OBJID_IViewInterfaceDefViewName, 380, ObjID)
Call DEFINE_OBJID(OBJID_IViewRelationshipDef, 381, ObjID)
Call DEFINE_OBJID(OBJID_IViewRelationshipDefFlags, 382, ObjID)
Call DEFINE_OBJID(OBJID_IViewRelationshipDefColumnNamePrefix, 383, ObjID)
Call DEFINE_OBJID(OBJID_IViewRelationshipDefJunctionViewName, 384, ObjID)
Call DEFINE_OBJID(OBJID_IViewPropertyDef, 385, ObjID)
Call DEFINE_OBJID(OBJID_IViewPropertyDefViewColumnName, 386, ObjID)
Call DEFINE_OBJID(OBJID_TransientObjCol, 387, ObjID)
Call DEFINE_OBJID(OBJID_ITransientObjCol, 388, ObjID)
Call DEFINE_OBJID(OBJID_ITransientObjColAdd, 389, ObjID)
Call DEFINE_OBJID(OBJID_ITransientObjColRemove, 390, ObjID)
Call DEFINE_OBJID(OBJID_ITransientObjColAddReposObj, 391, ObjID)
Call DEFINE_OBJID(OBJID_ITransientObjColRemoveItem, 392, ObjID)
Call DEFINE_OBJID(OBJID_IReposQueryGetCollection, 398, ObjID)
End Sub
