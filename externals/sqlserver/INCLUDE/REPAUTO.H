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
// REPAUTO.H
// 
// This file contains the .odl generated interface definitions for the
// Repository engine.  The compiled type library can be found using the
// PROGID "Microsoft Repository".
//
// Copyright (c) 1995-2000 by Microsoft Corporation, All Rights Reserved
//*****************************************************************************
/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __repauto_h__
#define __repauto_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IRepository_FWD_DEFINED__
#define __IRepository_FWD_DEFINED__
typedef interface IRepository IRepository;
#endif 	/* __IRepository_FWD_DEFINED__ */


#ifndef __IRepositoryDispatch_FWD_DEFINED__
#define __IRepositoryDispatch_FWD_DEFINED__
typedef interface IRepositoryDispatch IRepositoryDispatch;
#endif 	/* __IRepositoryDispatch_FWD_DEFINED__ */


#ifndef __IRepositoryItem_FWD_DEFINED__
#define __IRepositoryItem_FWD_DEFINED__
typedef interface IRepositoryItem IRepositoryItem;
#endif 	/* __IRepositoryItem_FWD_DEFINED__ */


#ifndef __IRepositoryObject_FWD_DEFINED__
#define __IRepositoryObject_FWD_DEFINED__
typedef interface IRepositoryObject IRepositoryObject;
#endif 	/* __IRepositoryObject_FWD_DEFINED__ */


#ifndef __IReposProperties_FWD_DEFINED__
#define __IReposProperties_FWD_DEFINED__
typedef interface IReposProperties IReposProperties;
#endif 	/* __IReposProperties_FWD_DEFINED__ */


#ifndef __IVersionCol_FWD_DEFINED__
#define __IVersionCol_FWD_DEFINED__
typedef interface IVersionCol IVersionCol;
#endif 	/* __IVersionCol_FWD_DEFINED__ */


#ifndef __IObjectCol_FWD_DEFINED__
#define __IObjectCol_FWD_DEFINED__
typedef interface IObjectCol IObjectCol;
#endif 	/* __IObjectCol_FWD_DEFINED__ */


#ifndef __ITargetObjectCol_FWD_DEFINED__
#define __ITargetObjectCol_FWD_DEFINED__
typedef interface ITargetObjectCol ITargetObjectCol;
#endif 	/* __ITargetObjectCol_FWD_DEFINED__ */


#ifndef __IWorkspaceItem_FWD_DEFINED__
#define __IWorkspaceItem_FWD_DEFINED__
typedef interface IWorkspaceItem IWorkspaceItem;
#endif 	/* __IWorkspaceItem_FWD_DEFINED__ */


#ifndef __IRepositoryObject2_FWD_DEFINED__
#define __IRepositoryObject2_FWD_DEFINED__
typedef interface IRepositoryObject2 IRepositoryObject2;
#endif 	/* __IRepositoryObject2_FWD_DEFINED__ */


#ifndef __IRepositoryObjectVersion_FWD_DEFINED__
#define __IRepositoryObjectVersion_FWD_DEFINED__
typedef interface IRepositoryObjectVersion IRepositoryObjectVersion;
#endif 	/* __IRepositoryObjectVersion_FWD_DEFINED__ */


#ifndef __IRepositoryObjectStorage_FWD_DEFINED__
#define __IRepositoryObjectStorage_FWD_DEFINED__
typedef interface IRepositoryObjectStorage IRepositoryObjectStorage;
#endif 	/* __IRepositoryObjectStorage_FWD_DEFINED__ */


#ifndef __IWorkspace_FWD_DEFINED__
#define __IWorkspace_FWD_DEFINED__
typedef interface IWorkspace IWorkspace;
#endif 	/* __IWorkspace_FWD_DEFINED__ */


#ifndef __IWorkspaceContainer_FWD_DEFINED__
#define __IWorkspaceContainer_FWD_DEFINED__
typedef interface IWorkspaceContainer IWorkspaceContainer;
#endif 	/* __IWorkspaceContainer_FWD_DEFINED__ */


#ifndef __IRelationship_FWD_DEFINED__
#define __IRelationship_FWD_DEFINED__
typedef interface IRelationship IRelationship;
#endif 	/* __IRelationship_FWD_DEFINED__ */


#ifndef __IVersionedRelationship_FWD_DEFINED__
#define __IVersionedRelationship_FWD_DEFINED__
typedef interface IVersionedRelationship IVersionedRelationship;
#endif 	/* __IVersionedRelationship_FWD_DEFINED__ */


#ifndef __IReposProperty_FWD_DEFINED__
#define __IReposProperty_FWD_DEFINED__
typedef interface IReposProperty IReposProperty;
#endif 	/* __IReposProperty_FWD_DEFINED__ */


#ifndef __IReposPropertyLarge_FWD_DEFINED__
#define __IReposPropertyLarge_FWD_DEFINED__
typedef interface IReposPropertyLarge IReposPropertyLarge;
#endif 	/* __IReposPropertyLarge_FWD_DEFINED__ */


#ifndef __IReposProperty2_FWD_DEFINED__
#define __IReposProperty2_FWD_DEFINED__
typedef interface IReposProperty2 IReposProperty2;
#endif 	/* __IReposProperty2_FWD_DEFINED__ */


#ifndef __IRelationshipCol_FWD_DEFINED__
#define __IRelationshipCol_FWD_DEFINED__
typedef interface IRelationshipCol IRelationshipCol;
#endif 	/* __IRelationshipCol_FWD_DEFINED__ */


#ifndef __IObjectCol2_FWD_DEFINED__
#define __IObjectCol2_FWD_DEFINED__
typedef interface IObjectCol2 IObjectCol2;
#endif 	/* __IObjectCol2_FWD_DEFINED__ */


#ifndef __IRepositoryTransaction_FWD_DEFINED__
#define __IRepositoryTransaction_FWD_DEFINED__
typedef interface IRepositoryTransaction IRepositoryTransaction;
#endif 	/* __IRepositoryTransaction_FWD_DEFINED__ */


#ifndef __IRepositoryTransaction2_FWD_DEFINED__
#define __IRepositoryTransaction2_FWD_DEFINED__
typedef interface IRepositoryTransaction2 IRepositoryTransaction2;
#endif 	/* __IRepositoryTransaction2_FWD_DEFINED__ */


#ifndef __IRepository2_FWD_DEFINED__
#define __IRepository2_FWD_DEFINED__
typedef interface IRepository2 IRepository2;
#endif 	/* __IRepository2_FWD_DEFINED__ */


#ifndef __IRepositoryODBC_FWD_DEFINED__
#define __IRepositoryODBC_FWD_DEFINED__
typedef interface IRepositoryODBC IRepositoryODBC;
#endif 	/* __IRepositoryODBC_FWD_DEFINED__ */


#ifndef __IRepositoryODBC2_FWD_DEFINED__
#define __IRepositoryODBC2_FWD_DEFINED__
typedef interface IRepositoryODBC2 IRepositoryODBC2;
#endif 	/* __IRepositoryODBC2_FWD_DEFINED__ */


#ifndef __IReposOptions_FWD_DEFINED__
#define __IReposOptions_FWD_DEFINED__
typedef interface IReposOptions IReposOptions;
#endif 	/* __IReposOptions_FWD_DEFINED__ */


#ifndef __IAnnotationalProps_FWD_DEFINED__
#define __IAnnotationalProps_FWD_DEFINED__
typedef interface IAnnotationalProps IAnnotationalProps;
#endif 	/* __IAnnotationalProps_FWD_DEFINED__ */


#ifndef __ISummaryInformation_FWD_DEFINED__
#define __ISummaryInformation_FWD_DEFINED__
typedef interface ISummaryInformation ISummaryInformation;
#endif 	/* __ISummaryInformation_FWD_DEFINED__ */


#ifndef __INamedObject_FWD_DEFINED__
#define __INamedObject_FWD_DEFINED__
typedef interface INamedObject INamedObject;
#endif 	/* __INamedObject_FWD_DEFINED__ */


#ifndef __IVersionAdminInfo_FWD_DEFINED__
#define __IVersionAdminInfo_FWD_DEFINED__
typedef interface IVersionAdminInfo IVersionAdminInfo;
#endif 	/* __IVersionAdminInfo_FWD_DEFINED__ */


#ifndef __IVersionAdminInfo2_FWD_DEFINED__
#define __IVersionAdminInfo2_FWD_DEFINED__
typedef interface IVersionAdminInfo2 IVersionAdminInfo2;
#endif 	/* __IVersionAdminInfo2_FWD_DEFINED__ */


#ifndef __IReposQuery_FWD_DEFINED__
#define __IReposQuery_FWD_DEFINED__
typedef interface IReposQuery IReposQuery;
#endif 	/* __IReposQuery_FWD_DEFINED__ */


#ifndef __ITransientObjectCol_FWD_DEFINED__
#define __ITransientObjectCol_FWD_DEFINED__
typedef interface ITransientObjectCol ITransientObjectCol;
#endif 	/* __ITransientObjectCol_FWD_DEFINED__ */


#ifndef __RepositoryObject_FWD_DEFINED__
#define __RepositoryObject_FWD_DEFINED__

#ifdef __cplusplus
typedef class RepositoryObject RepositoryObject;
#else
typedef struct RepositoryObject RepositoryObject;
#endif /* __cplusplus */

#endif 	/* __RepositoryObject_FWD_DEFINED__ */


#ifndef __RepositoryObjectVersion_FWD_DEFINED__
#define __RepositoryObjectVersion_FWD_DEFINED__

#ifdef __cplusplus
typedef class RepositoryObjectVersion RepositoryObjectVersion;
#else
typedef struct RepositoryObjectVersion RepositoryObjectVersion;
#endif /* __cplusplus */

#endif 	/* __RepositoryObjectVersion_FWD_DEFINED__ */


#ifndef __Relationship_FWD_DEFINED__
#define __Relationship_FWD_DEFINED__

#ifdef __cplusplus
typedef class Relationship Relationship;
#else
typedef struct Relationship Relationship;
#endif /* __cplusplus */

#endif 	/* __Relationship_FWD_DEFINED__ */


#ifndef __VersionedRelationship_FWD_DEFINED__
#define __VersionedRelationship_FWD_DEFINED__

#ifdef __cplusplus
typedef class VersionedRelationship VersionedRelationship;
#else
typedef struct VersionedRelationship VersionedRelationship;
#endif /* __cplusplus */

#endif 	/* __VersionedRelationship_FWD_DEFINED__ */


#ifndef __ReposProperty_FWD_DEFINED__
#define __ReposProperty_FWD_DEFINED__

#ifdef __cplusplus
typedef class ReposProperty ReposProperty;
#else
typedef struct ReposProperty ReposProperty;
#endif /* __cplusplus */

#endif 	/* __ReposProperty_FWD_DEFINED__ */


#ifndef __ReposProperties_FWD_DEFINED__
#define __ReposProperties_FWD_DEFINED__

#ifdef __cplusplus
typedef class ReposProperties ReposProperties;
#else
typedef struct ReposProperties ReposProperties;
#endif /* __cplusplus */

#endif 	/* __ReposProperties_FWD_DEFINED__ */


#ifndef __RelationshipCol_FWD_DEFINED__
#define __RelationshipCol_FWD_DEFINED__

#ifdef __cplusplus
typedef class RelationshipCol RelationshipCol;
#else
typedef struct RelationshipCol RelationshipCol;
#endif /* __cplusplus */

#endif 	/* __RelationshipCol_FWD_DEFINED__ */


#ifndef __ObjectCol_FWD_DEFINED__
#define __ObjectCol_FWD_DEFINED__

#ifdef __cplusplus
typedef class ObjectCol ObjectCol;
#else
typedef struct ObjectCol ObjectCol;
#endif /* __cplusplus */

#endif 	/* __ObjectCol_FWD_DEFINED__ */


#ifndef __VersionCol_FWD_DEFINED__
#define __VersionCol_FWD_DEFINED__

#ifdef __cplusplus
typedef class VersionCol VersionCol;
#else
typedef struct VersionCol VersionCol;
#endif /* __cplusplus */

#endif 	/* __VersionCol_FWD_DEFINED__ */


#ifndef __TransientObjectCol_FWD_DEFINED__
#define __TransientObjectCol_FWD_DEFINED__

#ifdef __cplusplus
typedef class TransientObjectCol TransientObjectCol;
#else
typedef struct TransientObjectCol TransientObjectCol;
#endif /* __cplusplus */

#endif 	/* __TransientObjectCol_FWD_DEFINED__ */


#ifndef __Repository_FWD_DEFINED__
#define __Repository_FWD_DEFINED__

#ifdef __cplusplus
typedef class Repository Repository;
#else
typedef struct Repository Repository;
#endif /* __cplusplus */

#endif 	/* __Repository_FWD_DEFINED__ */


#ifndef __IReposTypeInfo_FWD_DEFINED__
#define __IReposTypeInfo_FWD_DEFINED__
typedef interface IReposTypeInfo IReposTypeInfo;
#endif 	/* __IReposTypeInfo_FWD_DEFINED__ */


#ifndef __IInterfaceDef_FWD_DEFINED__
#define __IInterfaceDef_FWD_DEFINED__
typedef interface IInterfaceDef IInterfaceDef;
#endif 	/* __IInterfaceDef_FWD_DEFINED__ */


#ifndef __IInterfaceMember_FWD_DEFINED__
#define __IInterfaceMember_FWD_DEFINED__
typedef interface IInterfaceMember IInterfaceMember;
#endif 	/* __IInterfaceMember_FWD_DEFINED__ */


#ifndef __IInterfaceMember2_FWD_DEFINED__
#define __IInterfaceMember2_FWD_DEFINED__
typedef interface IInterfaceMember2 IInterfaceMember2;
#endif 	/* __IInterfaceMember2_FWD_DEFINED__ */


#ifndef __IClassDef_FWD_DEFINED__
#define __IClassDef_FWD_DEFINED__
typedef interface IClassDef IClassDef;
#endif 	/* __IClassDef_FWD_DEFINED__ */


#ifndef __ICollectionDef_FWD_DEFINED__
#define __ICollectionDef_FWD_DEFINED__
typedef interface ICollectionDef ICollectionDef;
#endif 	/* __ICollectionDef_FWD_DEFINED__ */


#ifndef __IPropertyDef_FWD_DEFINED__
#define __IPropertyDef_FWD_DEFINED__
typedef interface IPropertyDef IPropertyDef;
#endif 	/* __IPropertyDef_FWD_DEFINED__ */


#ifndef __IPropertyDef2_FWD_DEFINED__
#define __IPropertyDef2_FWD_DEFINED__
typedef interface IPropertyDef2 IPropertyDef2;
#endif 	/* __IPropertyDef2_FWD_DEFINED__ */


#ifndef __IEnumerationDef_FWD_DEFINED__
#define __IEnumerationDef_FWD_DEFINED__
typedef interface IEnumerationDef IEnumerationDef;
#endif 	/* __IEnumerationDef_FWD_DEFINED__ */


#ifndef __IEnumerationValueDef_FWD_DEFINED__
#define __IEnumerationValueDef_FWD_DEFINED__
typedef interface IEnumerationValueDef IEnumerationValueDef;
#endif 	/* __IEnumerationValueDef_FWD_DEFINED__ */


#ifndef __IViewClassDef_FWD_DEFINED__
#define __IViewClassDef_FWD_DEFINED__
typedef interface IViewClassDef IViewClassDef;
#endif 	/* __IViewClassDef_FWD_DEFINED__ */


#ifndef __IInterfaceDef2_FWD_DEFINED__
#define __IInterfaceDef2_FWD_DEFINED__
typedef interface IInterfaceDef2 IInterfaceDef2;
#endif 	/* __IInterfaceDef2_FWD_DEFINED__ */


#ifndef __IViewInterfaceDef_FWD_DEFINED__
#define __IViewInterfaceDef_FWD_DEFINED__
typedef interface IViewInterfaceDef IViewInterfaceDef;
#endif 	/* __IViewInterfaceDef_FWD_DEFINED__ */


#ifndef __IViewPropertyDef_FWD_DEFINED__
#define __IViewPropertyDef_FWD_DEFINED__
typedef interface IViewPropertyDef IViewPropertyDef;
#endif 	/* __IViewPropertyDef_FWD_DEFINED__ */


#ifndef __IReposTypeLib_FWD_DEFINED__
#define __IReposTypeLib_FWD_DEFINED__
typedef interface IReposTypeLib IReposTypeLib;
#endif 	/* __IReposTypeLib_FWD_DEFINED__ */


#ifndef __IReposTypeLib2_FWD_DEFINED__
#define __IReposTypeLib2_FWD_DEFINED__
typedef interface IReposTypeLib2 IReposTypeLib2;
#endif 	/* __IReposTypeLib2_FWD_DEFINED__ */


#ifndef __IViewRelationshipDef_FWD_DEFINED__
#define __IViewRelationshipDef_FWD_DEFINED__
typedef interface IViewRelationshipDef IViewRelationshipDef;
#endif 	/* __IViewRelationshipDef_FWD_DEFINED__ */


#ifndef __IReposTypeInfo2_FWD_DEFINED__
#define __IReposTypeInfo2_FWD_DEFINED__
typedef interface IReposTypeInfo2 IReposTypeInfo2;
#endif 	/* __IReposTypeInfo2_FWD_DEFINED__ */


#ifndef __IManageReposTypeLib_FWD_DEFINED__
#define __IManageReposTypeLib_FWD_DEFINED__
typedef interface IManageReposTypeLib IManageReposTypeLib;
#endif 	/* __IManageReposTypeLib_FWD_DEFINED__ */


#ifndef __IReposRoot_FWD_DEFINED__
#define __IReposRoot_FWD_DEFINED__
typedef interface IReposRoot IReposRoot;
#endif 	/* __IReposRoot_FWD_DEFINED__ */


#ifndef __IParameterDef_FWD_DEFINED__
#define __IParameterDef_FWD_DEFINED__
typedef interface IParameterDef IParameterDef;
#endif 	/* __IParameterDef_FWD_DEFINED__ */


#ifndef __IMethodDef_FWD_DEFINED__
#define __IMethodDef_FWD_DEFINED__
typedef interface IMethodDef IMethodDef;
#endif 	/* __IMethodDef_FWD_DEFINED__ */


#ifndef __IScriptDef_FWD_DEFINED__
#define __IScriptDef_FWD_DEFINED__
typedef interface IScriptDef IScriptDef;
#endif 	/* __IScriptDef_FWD_DEFINED__ */


#ifndef __IClassDef2_FWD_DEFINED__
#define __IClassDef2_FWD_DEFINED__
typedef interface IClassDef2 IClassDef2;
#endif 	/* __IClassDef2_FWD_DEFINED__ */


#ifndef __ClassDef_FWD_DEFINED__
#define __ClassDef_FWD_DEFINED__

#ifdef __cplusplus
typedef class ClassDef ClassDef;
#else
typedef struct ClassDef ClassDef;
#endif /* __cplusplus */

#endif 	/* __ClassDef_FWD_DEFINED__ */


#ifndef __InterfaceDef_FWD_DEFINED__
#define __InterfaceDef_FWD_DEFINED__

#ifdef __cplusplus
typedef class InterfaceDef InterfaceDef;
#else
typedef struct InterfaceDef InterfaceDef;
#endif /* __cplusplus */

#endif 	/* __InterfaceDef_FWD_DEFINED__ */


#ifndef __CollectionDef_FWD_DEFINED__
#define __CollectionDef_FWD_DEFINED__

#ifdef __cplusplus
typedef class CollectionDef CollectionDef;
#else
typedef struct CollectionDef CollectionDef;
#endif /* __cplusplus */

#endif 	/* __CollectionDef_FWD_DEFINED__ */


#ifndef __MethodDef_FWD_DEFINED__
#define __MethodDef_FWD_DEFINED__

#ifdef __cplusplus
typedef class MethodDef MethodDef;
#else
typedef struct MethodDef MethodDef;
#endif /* __cplusplus */

#endif 	/* __MethodDef_FWD_DEFINED__ */


#ifndef __PropertyDef_FWD_DEFINED__
#define __PropertyDef_FWD_DEFINED__

#ifdef __cplusplus
typedef class PropertyDef PropertyDef;
#else
typedef struct PropertyDef PropertyDef;
#endif /* __cplusplus */

#endif 	/* __PropertyDef_FWD_DEFINED__ */


#ifndef __RelationshipDef_FWD_DEFINED__
#define __RelationshipDef_FWD_DEFINED__

#ifdef __cplusplus
typedef class RelationshipDef RelationshipDef;
#else
typedef struct RelationshipDef RelationshipDef;
#endif /* __cplusplus */

#endif 	/* __RelationshipDef_FWD_DEFINED__ */


#ifndef __ReposTypeLib_FWD_DEFINED__
#define __ReposTypeLib_FWD_DEFINED__

#ifdef __cplusplus
typedef class ReposTypeLib ReposTypeLib;
#else
typedef struct ReposTypeLib ReposTypeLib;
#endif /* __cplusplus */

#endif 	/* __ReposTypeLib_FWD_DEFINED__ */


#ifndef __ReposRoot_FWD_DEFINED__
#define __ReposRoot_FWD_DEFINED__

#ifdef __cplusplus
typedef class ReposRoot ReposRoot;
#else
typedef struct ReposRoot ReposRoot;
#endif /* __cplusplus */

#endif 	/* __ReposRoot_FWD_DEFINED__ */


#ifndef __Workspace_FWD_DEFINED__
#define __Workspace_FWD_DEFINED__

#ifdef __cplusplus
typedef class Workspace Workspace;
#else
typedef struct Workspace Workspace;
#endif /* __cplusplus */

#endif 	/* __Workspace_FWD_DEFINED__ */


#ifndef __Alias_FWD_DEFINED__
#define __Alias_FWD_DEFINED__

#ifdef __cplusplus
typedef class Alias Alias;
#else
typedef struct Alias Alias;
#endif /* __cplusplus */

#endif 	/* __Alias_FWD_DEFINED__ */


#ifndef __ParameterDef_FWD_DEFINED__
#define __ParameterDef_FWD_DEFINED__

#ifdef __cplusplus
typedef class ParameterDef ParameterDef;
#else
typedef struct ParameterDef ParameterDef;
#endif /* __cplusplus */

#endif 	/* __ParameterDef_FWD_DEFINED__ */


#ifndef __ScriptDef_FWD_DEFINED__
#define __ScriptDef_FWD_DEFINED__

#ifdef __cplusplus
typedef class ScriptDef ScriptDef;
#else
typedef struct ScriptDef ScriptDef;
#endif /* __cplusplus */

#endif 	/* __ScriptDef_FWD_DEFINED__ */


void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 


#ifndef __RepositoryTypeLib_LIBRARY_DEFINED__
#define __RepositoryTypeLib_LIBRARY_DEFINED__

/* library RepositoryTypeLib */
/* [version][lcid][helpstring][helpfile][uuid] */ 

typedef /* [helpstring][uuid] */ 
enum _ConnectionFlags
    {	REPOS_CONN_NEWCACHE	= 2,
	REPOS_CONN_UPGRADE	= 4,
	REPOS_CONN_RECOMPUTE	= 8
    }	ConnectionFlags;

typedef /* [helpstring][uuid] */ 
enum _TransactionFlags
    {	TXN_RESET_OPTIONS	= 1,
	TXN_NORMAL	= 2,
	TXN_EXCLUSIVE_WRITEBACK	= 3,
	TXN_EXCLUSIVE_WRITETHROUGH	= 4,
	TXN_TIMEOUT_DURATION	= 5,
	TXN_START_TIMEOUT	= 6,
	TXN_QUERY_TIMEOUT	= 7,
	TXN_DBMS_READONLY	= 8,
	TXN_USE_DTC	= 10
    }	TransactionFlags;

typedef /* [helpstring][uuid] */ 
enum _TransactionValues
    {	TXN_EXCL_NO	= 0,
	TXN_EXCL_YES	= 1
    }	TransactionValues;

typedef /* [helpstring][uuid] */ 
enum _InterfaceDefFlags
    {	INTERFACE_EXTENSIBLE	= 1,
	INTERFACE_HIDDEN	= 2
    }	InterfaceDefFlags;

typedef /* [helpstring][uuid] */ 
enum _InterfaceMemberFlags
    {	INTERFACEMEMBER_HIDDEN	= 1,
	INTERFACEMEMBER_READONLY	= 2,
	INTERFACEMEMBER_VIRTUAL	= 4,
	INTERFACEMEMBER_DERIVED	= 0x8000
    }	InterfaceMemberFlags;

typedef /* [helpstring][uuid] */ 
enum _PropertyDefFlags
    {	PROPERTY_INVERTED	= 1
    }	PropertyDefFlags;

typedef /* [helpstring][uuid] */ 
enum _CollectionDefFlags
    {	COLLECTION_NAMING	= 1,
	COLLECTION_UNIQUENAMING	= 2,
	COLLECTION_CASESENSITIVE	= 4,
	COLLECTION_SEQUENCED	= 8,
	COLLECTION_PROPAGATEDELETE	= 16,
	COLLECTION_NEWORGVERSIONSPARTICIPATE	= 32,
	COLLECTION_NEWORGVERSIONSDONOTPARTICIPATE	= 64,
	COLLECTION_MERGEWHOLE	= 128,
	COLLECTION_CONTAINING	= 256,
	COLLECTION_OBJECTNAMING	= 512,
	COLLECTION_NEWDESTVERSIONADD	= 1024,
	COLLECTION_NEWDESTVERSIONPROPAGATE	= 2048
    }	CollectionDefFlags;

typedef /* [helpstring][uuid] */ 
enum _VersionStates
    {	FROZEN	= 1,
	CHECKEDOUT	= 2,
	LATEST	= 4,
	LASTINBRANCH	= 128
    }	VersionStates;

typedef /* [helpstring][uuid] */ 
enum _MergeFlags
    {	PRIMARY	= 1,
	SECONDARY	= 2
    }	MergeFlags;

typedef /* [helpstring][uuid] */ 
enum _ResolutionTypes
    {	SPECIFIEDVERSION	= 1,
	LATESTVERSION	= 2,
	VERSIONINWORKSPACE	= 3,
	PINNEDVERSION	= 4
    }	ResolutionTypes;

typedef /* [helpstring][uuid] */ 
enum _LoadStatus
    {	READY	= 1,
	INPROGRESS	= 2,
	CANCELLED	= 3,
	FAILED	= 4
    }	LoadStatus;

typedef /* [helpstring][uuid] */ 
enum _RepODBCFlags
    {	RODBC_RESET_OPTIONS	= 1,
	RODBC_ASYNCH	= 2
    }	RepODBCFlags;

typedef /* [helpstring][uuid] */ 
enum _RepParamType
    {	PARAMTYPE_ARRAY	= VT_ARRAY,
	PARAMTYPE_BYTE	= VT_UI1,
	PARAMTYPE_BOOL	= VT_BOOL,
	PARAMTYPE_BSTR	= VT_BSTR,
	PARAMTYPE_CURRENCY	= VT_CY,
	PARAMTYPE_DATE	= VT_DATE,
	PARAMTYPE_SHORT	= VT_I2,
	PARAMTYPE_LONG	= VT_I4,
	PARAMTYPE_SINGLE	= VT_R4,
	PARAMTYPE_DOUBLE	= VT_R8,
	PARAMTYPE_DISPATCH	= VT_DISPATCH,
	PARAMTYPE_OBJECT	= VT_UNKNOWN,
	PARAMTYPE_VARIANT	= VT_VARIANT,
	PARAMTYPE_BYREF	= VT_BYREF
    }	RepParamType;

typedef /* [helpstring][uuid] */ 
enum _RepParamFlags
    {	PARAMFLAGS_IN	= 1,
	PARAMFLAGS_OUT	= 2,
	PARAMFLAGS_RETVAL	= 4,
	PARAMFLAGS_OPTIONAL	= 8
    }	RepParamFlags;

typedef /* [helpstring][uuid] */ 
enum _ReposQueryFlags
    {	FILTERCOL_SYNC	= 0,
	FILTERCOL_ASYNC	= 2
    }	ReposQueryFlags;

typedef /* [helpstring][uuid] */ 
enum _ViewDef
    {	GENERATE_RESOLVED_VIEW	= 1,
	GENERATE_NORESOLUTION_VIEW	= 2,
	GENERATE_WORKSPACE_VIEW	= 4,
	INCLUDE_VERSIONID_COLUMN	= 8,
	INCLUDE_VERSION_FLAGS_COLUMN	= 16,
	EXCLUDE_IMPLIED_INTERFACES	= 32,
	INCLUDE_PREVDSTID	= 64,
	INCLUDE_RELTYPEID	= 128,
	CHOOSE_ORIGIN	= 256,
	INCLUDE_LONGNAMES	= 512
    }	ViewDef;





















DEFINE_GUID(LIBID_RepositoryTypeLib,0x2DF7E2FB,0x60D2,0x11cf,0x92,0x0E,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#ifndef __IRepository_INTERFACE_DEFINED__
#define __IRepository_INTERFACE_DEFINED__

/* interface IRepository */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IRepository,0x6E2270FA,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E2270FA-F799-11cf-9227-00AA00A1EB95")
    IRepository : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Create( 
            /* [defaultvalue][in] */ BSTR Connect,
            /* [defaultvalue][in] */ BSTR User,
            /* [defaultvalue][in] */ BSTR Password,
            /* [defaultvalue][in] */ long fFlags,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIRoot) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [defaultvalue][in] */ BSTR Connect,
            /* [defaultvalue][in] */ BSTR User,
            /* [defaultvalue][in] */ BSTR Password,
            /* [defaultvalue][in] */ long fFlags,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIRoot) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateObject( 
            /* [in] */ VARIANT sTypeID,
            /* [optional][in] */ VARIANT sObjID,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIReposObj) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_RootObject( 
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIRoot) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Object( 
            /* [in] */ VARIANT sObjID,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIReposObj) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Refresh( 
            /* [in] */ long iMilliseconds) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ObjectIDToInternalID( 
            /* [in] */ VARIANT sObjID,
            /* [retval][out] */ VARIANT __RPC_FAR *psIntID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE InternalIDToObjectID( 
            /* [in] */ VARIANT sIntID,
            /* [retval][out] */ VARIANT __RPC_FAR *psObjID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Transaction( 
            /* [retval][out] */ IRepositoryTransaction __RPC_FAR *__RPC_FAR *ppITxn) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRepositoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRepository __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRepository __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRepository __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRepository __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRepository __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRepository __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRepository __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Create )( 
            IRepository __RPC_FAR * This,
            /* [defaultvalue][in] */ BSTR Connect,
            /* [defaultvalue][in] */ BSTR User,
            /* [defaultvalue][in] */ BSTR Password,
            /* [defaultvalue][in] */ long fFlags,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIRoot);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IRepository __RPC_FAR * This,
            /* [defaultvalue][in] */ BSTR Connect,
            /* [defaultvalue][in] */ BSTR User,
            /* [defaultvalue][in] */ BSTR Password,
            /* [defaultvalue][in] */ long fFlags,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIRoot);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateObject )( 
            IRepository __RPC_FAR * This,
            /* [in] */ VARIANT sTypeID,
            /* [optional][in] */ VARIANT sObjID,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIReposObj);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RootObject )( 
            IRepository __RPC_FAR * This,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIRoot);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Object )( 
            IRepository __RPC_FAR * This,
            /* [in] */ VARIANT sObjID,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIReposObj);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Refresh )( 
            IRepository __RPC_FAR * This,
            /* [in] */ long iMilliseconds);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ObjectIDToInternalID )( 
            IRepository __RPC_FAR * This,
            /* [in] */ VARIANT sObjID,
            /* [retval][out] */ VARIANT __RPC_FAR *psIntID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InternalIDToObjectID )( 
            IRepository __RPC_FAR * This,
            /* [in] */ VARIANT sIntID,
            /* [retval][out] */ VARIANT __RPC_FAR *psObjID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Transaction )( 
            IRepository __RPC_FAR * This,
            /* [retval][out] */ IRepositoryTransaction __RPC_FAR *__RPC_FAR *ppITxn);
        
        END_INTERFACE
    } IRepositoryVtbl;

    interface IRepository
    {
        CONST_VTBL struct IRepositoryVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRepository_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRepository_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRepository_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRepository_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRepository_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRepository_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRepository_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRepository_Create(This,Connect,User,Password,fFlags,ppIRoot)	\
    (This)->lpVtbl -> Create(This,Connect,User,Password,fFlags,ppIRoot)

#define IRepository_Open(This,Connect,User,Password,fFlags,ppIRoot)	\
    (This)->lpVtbl -> Open(This,Connect,User,Password,fFlags,ppIRoot)

#define IRepository_CreateObject(This,sTypeID,sObjID,ppIReposObj)	\
    (This)->lpVtbl -> CreateObject(This,sTypeID,sObjID,ppIReposObj)

#define IRepository_get_RootObject(This,ppIRoot)	\
    (This)->lpVtbl -> get_RootObject(This,ppIRoot)

#define IRepository_get_Object(This,sObjID,ppIReposObj)	\
    (This)->lpVtbl -> get_Object(This,sObjID,ppIReposObj)

#define IRepository_Refresh(This,iMilliseconds)	\
    (This)->lpVtbl -> Refresh(This,iMilliseconds)

#define IRepository_ObjectIDToInternalID(This,sObjID,psIntID)	\
    (This)->lpVtbl -> ObjectIDToInternalID(This,sObjID,psIntID)

#define IRepository_InternalIDToObjectID(This,sIntID,psObjID)	\
    (This)->lpVtbl -> InternalIDToObjectID(This,sIntID,psObjID)

#define IRepository_get_Transaction(This,ppITxn)	\
    (This)->lpVtbl -> get_Transaction(This,ppITxn)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IRepository_Create_Proxy( 
    IRepository __RPC_FAR * This,
    /* [defaultvalue][in] */ BSTR Connect,
    /* [defaultvalue][in] */ BSTR User,
    /* [defaultvalue][in] */ BSTR Password,
    /* [defaultvalue][in] */ long fFlags,
    /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIRoot);


void __RPC_STUB IRepository_Create_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRepository_Open_Proxy( 
    IRepository __RPC_FAR * This,
    /* [defaultvalue][in] */ BSTR Connect,
    /* [defaultvalue][in] */ BSTR User,
    /* [defaultvalue][in] */ BSTR Password,
    /* [defaultvalue][in] */ long fFlags,
    /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIRoot);


void __RPC_STUB IRepository_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRepository_CreateObject_Proxy( 
    IRepository __RPC_FAR * This,
    /* [in] */ VARIANT sTypeID,
    /* [optional][in] */ VARIANT sObjID,
    /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIReposObj);


void __RPC_STUB IRepository_CreateObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepository_get_RootObject_Proxy( 
    IRepository __RPC_FAR * This,
    /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIRoot);


void __RPC_STUB IRepository_get_RootObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepository_get_Object_Proxy( 
    IRepository __RPC_FAR * This,
    /* [in] */ VARIANT sObjID,
    /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIReposObj);


void __RPC_STUB IRepository_get_Object_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRepository_Refresh_Proxy( 
    IRepository __RPC_FAR * This,
    /* [in] */ long iMilliseconds);


void __RPC_STUB IRepository_Refresh_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRepository_ObjectIDToInternalID_Proxy( 
    IRepository __RPC_FAR * This,
    /* [in] */ VARIANT sObjID,
    /* [retval][out] */ VARIANT __RPC_FAR *psIntID);


void __RPC_STUB IRepository_ObjectIDToInternalID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRepository_InternalIDToObjectID_Proxy( 
    IRepository __RPC_FAR * This,
    /* [in] */ VARIANT sIntID,
    /* [retval][out] */ VARIANT __RPC_FAR *psObjID);


void __RPC_STUB IRepository_InternalIDToObjectID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepository_get_Transaction_Proxy( 
    IRepository __RPC_FAR * This,
    /* [retval][out] */ IRepositoryTransaction __RPC_FAR *__RPC_FAR *ppITxn);


void __RPC_STUB IRepository_get_Transaction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRepository_INTERFACE_DEFINED__ */


#ifndef __IRepositoryDispatch_INTERFACE_DEFINED__
#define __IRepositoryDispatch_INTERFACE_DEFINED__

/* interface IRepositoryDispatch */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IRepositoryDispatch,0x6E2270F6,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E2270F6-F799-11cf-9227-00AA00A1EB95")
    IRepositoryDispatch : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Properties( 
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRepositoryDispatchVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRepositoryDispatch __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRepositoryDispatch __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRepositoryDispatch __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRepositoryDispatch __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRepositoryDispatch __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRepositoryDispatch __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRepositoryDispatch __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IRepositoryDispatch __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        END_INTERFACE
    } IRepositoryDispatchVtbl;

    interface IRepositoryDispatch
    {
        CONST_VTBL struct IRepositoryDispatchVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRepositoryDispatch_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRepositoryDispatch_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRepositoryDispatch_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRepositoryDispatch_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRepositoryDispatch_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRepositoryDispatch_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRepositoryDispatch_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRepositoryDispatch_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepositoryDispatch_get_Properties_Proxy( 
    IRepositoryDispatch __RPC_FAR * This,
    /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);


void __RPC_STUB IRepositoryDispatch_get_Properties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRepositoryDispatch_INTERFACE_DEFINED__ */


#ifndef __IRepositoryItem_INTERFACE_DEFINED__
#define __IRepositoryItem_INTERFACE_DEFINED__

/* interface IRepositoryItem */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IRepositoryItem,0x6E2270F0,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E2270F0-F799-11cf-9227-00AA00A1EB95")
    IRepositoryItem : public IRepositoryDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ VARIANT __RPC_FAR *psTypeID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Repository( 
            /* [retval][out] */ IRepository __RPC_FAR *__RPC_FAR *ppIRepository) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR __RPC_FAR *pName) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR Name) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Interface( 
            /* [in] */ VARIANT Iface,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppIIface) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Lock( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRepositoryItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRepositoryItem __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRepositoryItem __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRepositoryItem __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRepositoryItem __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRepositoryItem __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRepositoryItem __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRepositoryItem __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IRepositoryItem __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Type )( 
            IRepositoryItem __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psTypeID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Repository )( 
            IRepositoryItem __RPC_FAR * This,
            /* [retval][out] */ IRepository __RPC_FAR *__RPC_FAR *ppIRepository);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IRepositoryItem __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pName);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Name )( 
            IRepositoryItem __RPC_FAR * This,
            /* [in] */ BSTR Name);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Interface )( 
            IRepositoryItem __RPC_FAR * This,
            /* [in] */ VARIANT Iface,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppIIface);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Delete )( 
            IRepositoryItem __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Lock )( 
            IRepositoryItem __RPC_FAR * This);
        
        END_INTERFACE
    } IRepositoryItemVtbl;

    interface IRepositoryItem
    {
        CONST_VTBL struct IRepositoryItemVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRepositoryItem_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRepositoryItem_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRepositoryItem_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRepositoryItem_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRepositoryItem_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRepositoryItem_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRepositoryItem_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRepositoryItem_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#define IRepositoryItem_get_Type(This,psTypeID)	\
    (This)->lpVtbl -> get_Type(This,psTypeID)

#define IRepositoryItem_get_Repository(This,ppIRepository)	\
    (This)->lpVtbl -> get_Repository(This,ppIRepository)

#define IRepositoryItem_get_Name(This,pName)	\
    (This)->lpVtbl -> get_Name(This,pName)

#define IRepositoryItem_put_Name(This,Name)	\
    (This)->lpVtbl -> put_Name(This,Name)

#define IRepositoryItem_get_Interface(This,Iface,ppIIface)	\
    (This)->lpVtbl -> get_Interface(This,Iface,ppIIface)

#define IRepositoryItem_Delete(This)	\
    (This)->lpVtbl -> Delete(This)

#define IRepositoryItem_Lock(This)	\
    (This)->lpVtbl -> Lock(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepositoryItem_get_Type_Proxy( 
    IRepositoryItem __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *psTypeID);


void __RPC_STUB IRepositoryItem_get_Type_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepositoryItem_get_Repository_Proxy( 
    IRepositoryItem __RPC_FAR * This,
    /* [retval][out] */ IRepository __RPC_FAR *__RPC_FAR *ppIRepository);


void __RPC_STUB IRepositoryItem_get_Repository_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepositoryItem_get_Name_Proxy( 
    IRepositoryItem __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pName);


void __RPC_STUB IRepositoryItem_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IRepositoryItem_put_Name_Proxy( 
    IRepositoryItem __RPC_FAR * This,
    /* [in] */ BSTR Name);


void __RPC_STUB IRepositoryItem_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepositoryItem_get_Interface_Proxy( 
    IRepositoryItem __RPC_FAR * This,
    /* [in] */ VARIANT Iface,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppIIface);


void __RPC_STUB IRepositoryItem_get_Interface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRepositoryItem_Delete_Proxy( 
    IRepositoryItem __RPC_FAR * This);


void __RPC_STUB IRepositoryItem_Delete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRepositoryItem_Lock_Proxy( 
    IRepositoryItem __RPC_FAR * This);


void __RPC_STUB IRepositoryItem_Lock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRepositoryItem_INTERFACE_DEFINED__ */


#ifndef __IRepositoryObject_INTERFACE_DEFINED__
#define __IRepositoryObject_INTERFACE_DEFINED__

/* interface IRepositoryObject */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IRepositoryObject,0x6E2270F2,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E2270F2-F799-11cf-9227-00AA00A1EB95")
    IRepositoryObject : public IRepositoryItem
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ObjectID( 
            /* [retval][out] */ VARIANT __RPC_FAR *psObjID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_InternalID( 
            /* [retval][out] */ VARIANT __RPC_FAR *psIntID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Refresh( 
            /* [in] */ long iMilliseconds) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRepositoryObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRepositoryObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRepositoryObject __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRepositoryObject __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRepositoryObject __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRepositoryObject __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRepositoryObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRepositoryObject __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IRepositoryObject __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Type )( 
            IRepositoryObject __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psTypeID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Repository )( 
            IRepositoryObject __RPC_FAR * This,
            /* [retval][out] */ IRepository __RPC_FAR *__RPC_FAR *ppIRepository);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IRepositoryObject __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pName);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Name )( 
            IRepositoryObject __RPC_FAR * This,
            /* [in] */ BSTR Name);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Interface )( 
            IRepositoryObject __RPC_FAR * This,
            /* [in] */ VARIANT Iface,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppIIface);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Delete )( 
            IRepositoryObject __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Lock )( 
            IRepositoryObject __RPC_FAR * This);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ObjectID )( 
            IRepositoryObject __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psObjID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_InternalID )( 
            IRepositoryObject __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psIntID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Refresh )( 
            IRepositoryObject __RPC_FAR * This,
            /* [in] */ long iMilliseconds);
        
        END_INTERFACE
    } IRepositoryObjectVtbl;

    interface IRepositoryObject
    {
        CONST_VTBL struct IRepositoryObjectVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRepositoryObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRepositoryObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRepositoryObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRepositoryObject_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRepositoryObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRepositoryObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRepositoryObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRepositoryObject_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#define IRepositoryObject_get_Type(This,psTypeID)	\
    (This)->lpVtbl -> get_Type(This,psTypeID)

#define IRepositoryObject_get_Repository(This,ppIRepository)	\
    (This)->lpVtbl -> get_Repository(This,ppIRepository)

#define IRepositoryObject_get_Name(This,pName)	\
    (This)->lpVtbl -> get_Name(This,pName)

#define IRepositoryObject_put_Name(This,Name)	\
    (This)->lpVtbl -> put_Name(This,Name)

#define IRepositoryObject_get_Interface(This,Iface,ppIIface)	\
    (This)->lpVtbl -> get_Interface(This,Iface,ppIIface)

#define IRepositoryObject_Delete(This)	\
    (This)->lpVtbl -> Delete(This)

#define IRepositoryObject_Lock(This)	\
    (This)->lpVtbl -> Lock(This)


#define IRepositoryObject_get_ObjectID(This,psObjID)	\
    (This)->lpVtbl -> get_ObjectID(This,psObjID)

#define IRepositoryObject_get_InternalID(This,psIntID)	\
    (This)->lpVtbl -> get_InternalID(This,psIntID)

#define IRepositoryObject_Refresh(This,iMilliseconds)	\
    (This)->lpVtbl -> Refresh(This,iMilliseconds)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepositoryObject_get_ObjectID_Proxy( 
    IRepositoryObject __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *psObjID);


void __RPC_STUB IRepositoryObject_get_ObjectID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepositoryObject_get_InternalID_Proxy( 
    IRepositoryObject __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *psIntID);


void __RPC_STUB IRepositoryObject_get_InternalID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRepositoryObject_Refresh_Proxy( 
    IRepositoryObject __RPC_FAR * This,
    /* [in] */ long iMilliseconds);


void __RPC_STUB IRepositoryObject_Refresh_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRepositoryObject_INTERFACE_DEFINED__ */


#ifndef __IReposProperties_INTERFACE_DEFINED__
#define __IReposProperties_INTERFACE_DEFINED__

/* interface IReposProperties */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IReposProperties,0x6E2270F5,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E2270F5-F799-11cf-9227-00AA00A1EB95")
    IReposProperties : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *piCount) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT sItem,
            /* [retval][out] */ IReposProperty __RPC_FAR *__RPC_FAR *ppIProp) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE _NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppIEnum) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ VARIANT __RPC_FAR *psTypeID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IReposPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IReposProperties __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IReposProperties __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IReposProperties __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IReposProperties __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IReposProperties __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IReposProperties __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IReposProperties __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IReposProperties __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *piCount);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IReposProperties __RPC_FAR * This,
            /* [in] */ VARIANT sItem,
            /* [retval][out] */ IReposProperty __RPC_FAR *__RPC_FAR *ppIProp);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *_NewEnum )( 
            IReposProperties __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppIEnum);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Type )( 
            IReposProperties __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psTypeID);
        
        END_INTERFACE
    } IReposPropertiesVtbl;

    interface IReposProperties
    {
        CONST_VTBL struct IReposPropertiesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IReposProperties_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IReposProperties_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IReposProperties_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IReposProperties_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IReposProperties_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IReposProperties_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IReposProperties_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IReposProperties_get_Count(This,piCount)	\
    (This)->lpVtbl -> get_Count(This,piCount)

#define IReposProperties_get_Item(This,sItem,ppIProp)	\
    (This)->lpVtbl -> get_Item(This,sItem,ppIProp)

#define IReposProperties__NewEnum(This,ppIEnum)	\
    (This)->lpVtbl -> _NewEnum(This,ppIEnum)

#define IReposProperties_get_Type(This,psTypeID)	\
    (This)->lpVtbl -> get_Type(This,psTypeID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IReposProperties_get_Count_Proxy( 
    IReposProperties __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *piCount);


void __RPC_STUB IReposProperties_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IReposProperties_get_Item_Proxy( 
    IReposProperties __RPC_FAR * This,
    /* [in] */ VARIANT sItem,
    /* [retval][out] */ IReposProperty __RPC_FAR *__RPC_FAR *ppIProp);


void __RPC_STUB IReposProperties_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IReposProperties__NewEnum_Proxy( 
    IReposProperties __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppIEnum);


void __RPC_STUB IReposProperties__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IReposProperties_get_Type_Proxy( 
    IReposProperties __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *psTypeID);


void __RPC_STUB IReposProperties_get_Type_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IReposProperties_INTERFACE_DEFINED__ */


#ifndef __IVersionCol_INTERFACE_DEFINED__
#define __IVersionCol_INTERFACE_DEFINED__

/* interface IVersionCol */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IVersionCol,0x820BD0D0,0xBA76,0x11d0,0xB0,0x34,0x00,0xA0,0xC9,0x0F,0xEE,0x3A);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("820BD0D0-BA76-11d0-B034-00A0C90FEE3A")
    IVersionCol : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *piCount) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT sItem,
            /* [retval][out] */ IRepositoryObjectVersion __RPC_FAR *__RPC_FAR *ppIReposVersion) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE _NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppIEnum) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Refresh( 
            /* [in] */ long iMilliseconds) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ IRepositoryObjectVersion __RPC_FAR *pIReposVersion,
            /* [retval][out] */ IRepositoryObjectVersion __RPC_FAR *__RPC_FAR *ppIAddedVersion) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ VARIANT sItem) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVersionColVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IVersionCol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IVersionCol __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IVersionCol __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IVersionCol __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IVersionCol __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IVersionCol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IVersionCol __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IVersionCol __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *piCount);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IVersionCol __RPC_FAR * This,
            /* [in] */ VARIANT sItem,
            /* [retval][out] */ IRepositoryObjectVersion __RPC_FAR *__RPC_FAR *ppIReposVersion);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *_NewEnum )( 
            IVersionCol __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppIEnum);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Refresh )( 
            IVersionCol __RPC_FAR * This,
            /* [in] */ long iMilliseconds);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IVersionCol __RPC_FAR * This,
            /* [in] */ IRepositoryObjectVersion __RPC_FAR *pIReposVersion,
            /* [retval][out] */ IRepositoryObjectVersion __RPC_FAR *__RPC_FAR *ppIAddedVersion);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove )( 
            IVersionCol __RPC_FAR * This,
            /* [in] */ VARIANT sItem);
        
        END_INTERFACE
    } IVersionColVtbl;

    interface IVersionCol
    {
        CONST_VTBL struct IVersionColVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVersionCol_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVersionCol_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVersionCol_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVersionCol_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IVersionCol_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IVersionCol_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IVersionCol_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IVersionCol_get_Count(This,piCount)	\
    (This)->lpVtbl -> get_Count(This,piCount)

#define IVersionCol_get_Item(This,sItem,ppIReposVersion)	\
    (This)->lpVtbl -> get_Item(This,sItem,ppIReposVersion)

#define IVersionCol__NewEnum(This,ppIEnum)	\
    (This)->lpVtbl -> _NewEnum(This,ppIEnum)

#define IVersionCol_Refresh(This,iMilliseconds)	\
    (This)->lpVtbl -> Refresh(This,iMilliseconds)

#define IVersionCol_Add(This,pIReposVersion,ppIAddedVersion)	\
    (This)->lpVtbl -> Add(This,pIReposVersion,ppIAddedVersion)

#define IVersionCol_Remove(This,sItem)	\
    (This)->lpVtbl -> Remove(This,sItem)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IVersionCol_get_Count_Proxy( 
    IVersionCol __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *piCount);


void __RPC_STUB IVersionCol_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IVersionCol_get_Item_Proxy( 
    IVersionCol __RPC_FAR * This,
    /* [in] */ VARIANT sItem,
    /* [retval][out] */ IRepositoryObjectVersion __RPC_FAR *__RPC_FAR *ppIReposVersion);


void __RPC_STUB IVersionCol_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IVersionCol__NewEnum_Proxy( 
    IVersionCol __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppIEnum);


void __RPC_STUB IVersionCol__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IVersionCol_Refresh_Proxy( 
    IVersionCol __RPC_FAR * This,
    /* [in] */ long iMilliseconds);


void __RPC_STUB IVersionCol_Refresh_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IVersionCol_Add_Proxy( 
    IVersionCol __RPC_FAR * This,
    /* [in] */ IRepositoryObjectVersion __RPC_FAR *pIReposVersion,
    /* [retval][out] */ IRepositoryObjectVersion __RPC_FAR *__RPC_FAR *ppIAddedVersion);


void __RPC_STUB IVersionCol_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IVersionCol_Remove_Proxy( 
    IVersionCol __RPC_FAR * This,
    /* [in] */ VARIANT sItem);


void __RPC_STUB IVersionCol_Remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVersionCol_INTERFACE_DEFINED__ */


#ifndef __IObjectCol_INTERFACE_DEFINED__
#define __IObjectCol_INTERFACE_DEFINED__

/* interface IObjectCol */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IObjectCol,0x6E2270F8,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E2270F8-F799-11cf-9227-00AA00A1EB95")
    IObjectCol : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *piCount) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT sItem,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIItem) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE _NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppIEnum) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Refresh( 
            /* [in] */ long iMilliseconds) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IObjectColVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IObjectCol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IObjectCol __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IObjectCol __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IObjectCol __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IObjectCol __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IObjectCol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IObjectCol __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IObjectCol __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *piCount);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IObjectCol __RPC_FAR * This,
            /* [in] */ VARIANT sItem,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIItem);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *_NewEnum )( 
            IObjectCol __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppIEnum);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Refresh )( 
            IObjectCol __RPC_FAR * This,
            /* [in] */ long iMilliseconds);
        
        END_INTERFACE
    } IObjectColVtbl;

    interface IObjectCol
    {
        CONST_VTBL struct IObjectColVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IObjectCol_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IObjectCol_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IObjectCol_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IObjectCol_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IObjectCol_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IObjectCol_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IObjectCol_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IObjectCol_get_Count(This,piCount)	\
    (This)->lpVtbl -> get_Count(This,piCount)

#define IObjectCol_get_Item(This,sItem,ppIItem)	\
    (This)->lpVtbl -> get_Item(This,sItem,ppIItem)

#define IObjectCol__NewEnum(This,ppIEnum)	\
    (This)->lpVtbl -> _NewEnum(This,ppIEnum)

#define IObjectCol_Refresh(This,iMilliseconds)	\
    (This)->lpVtbl -> Refresh(This,iMilliseconds)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IObjectCol_get_Count_Proxy( 
    IObjectCol __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *piCount);


void __RPC_STUB IObjectCol_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IObjectCol_get_Item_Proxy( 
    IObjectCol __RPC_FAR * This,
    /* [in] */ VARIANT sItem,
    /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIItem);


void __RPC_STUB IObjectCol_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IObjectCol__NewEnum_Proxy( 
    IObjectCol __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppIEnum);


void __RPC_STUB IObjectCol__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IObjectCol_Refresh_Proxy( 
    IObjectCol __RPC_FAR * This,
    /* [in] */ long iMilliseconds);


void __RPC_STUB IObjectCol_Refresh_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IObjectCol_INTERFACE_DEFINED__ */


#ifndef __ITargetObjectCol_INTERFACE_DEFINED__
#define __ITargetObjectCol_INTERFACE_DEFINED__

/* interface ITargetObjectCol */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_ITargetObjectCol,0x6E227115,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E227115-F799-11cf-9227-00AA00A1EB95")
    ITargetObjectCol : public IObjectCol
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ IDispatch __RPC_FAR *pIReposObj,
            /* [defaultvalue][in] */ BSTR Name,
            /* [retval][out] */ IRelationship __RPC_FAR *__RPC_FAR *ppIRelship) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ VARIANT sItem) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ VARIANT __RPC_FAR *psTypeID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Insert( 
            /* [in] */ IDispatch __RPC_FAR *pIReposObj,
            /* [in] */ long iIndex,
            /* [defaultvalue][in] */ BSTR Name,
            /* [retval][out] */ IRelationship __RPC_FAR *__RPC_FAR *ppIRelship) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Move( 
            /* [in] */ long iIndexFrom,
            /* [in] */ long iIndexTo) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Source( 
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIObj) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITargetObjectColVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITargetObjectCol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITargetObjectCol __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITargetObjectCol __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ITargetObjectCol __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ITargetObjectCol __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ITargetObjectCol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ITargetObjectCol __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            ITargetObjectCol __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *piCount);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            ITargetObjectCol __RPC_FAR * This,
            /* [in] */ VARIANT sItem,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIItem);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *_NewEnum )( 
            ITargetObjectCol __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppIEnum);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Refresh )( 
            ITargetObjectCol __RPC_FAR * This,
            /* [in] */ long iMilliseconds);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            ITargetObjectCol __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *pIReposObj,
            /* [defaultvalue][in] */ BSTR Name,
            /* [retval][out] */ IRelationship __RPC_FAR *__RPC_FAR *ppIRelship);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove )( 
            ITargetObjectCol __RPC_FAR * This,
            /* [in] */ VARIANT sItem);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Type )( 
            ITargetObjectCol __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psTypeID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Insert )( 
            ITargetObjectCol __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *pIReposObj,
            /* [in] */ long iIndex,
            /* [defaultvalue][in] */ BSTR Name,
            /* [retval][out] */ IRelationship __RPC_FAR *__RPC_FAR *ppIRelship);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Move )( 
            ITargetObjectCol __RPC_FAR * This,
            /* [in] */ long iIndexFrom,
            /* [in] */ long iIndexTo);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Source )( 
            ITargetObjectCol __RPC_FAR * This,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIObj);
        
        END_INTERFACE
    } ITargetObjectColVtbl;

    interface ITargetObjectCol
    {
        CONST_VTBL struct ITargetObjectColVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITargetObjectCol_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITargetObjectCol_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITargetObjectCol_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITargetObjectCol_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ITargetObjectCol_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ITargetObjectCol_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ITargetObjectCol_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ITargetObjectCol_get_Count(This,piCount)	\
    (This)->lpVtbl -> get_Count(This,piCount)

#define ITargetObjectCol_get_Item(This,sItem,ppIItem)	\
    (This)->lpVtbl -> get_Item(This,sItem,ppIItem)

#define ITargetObjectCol__NewEnum(This,ppIEnum)	\
    (This)->lpVtbl -> _NewEnum(This,ppIEnum)

#define ITargetObjectCol_Refresh(This,iMilliseconds)	\
    (This)->lpVtbl -> Refresh(This,iMilliseconds)


#define ITargetObjectCol_Add(This,pIReposObj,Name,ppIRelship)	\
    (This)->lpVtbl -> Add(This,pIReposObj,Name,ppIRelship)

#define ITargetObjectCol_Remove(This,sItem)	\
    (This)->lpVtbl -> Remove(This,sItem)

#define ITargetObjectCol_get_Type(This,psTypeID)	\
    (This)->lpVtbl -> get_Type(This,psTypeID)

#define ITargetObjectCol_Insert(This,pIReposObj,iIndex,Name,ppIRelship)	\
    (This)->lpVtbl -> Insert(This,pIReposObj,iIndex,Name,ppIRelship)

#define ITargetObjectCol_Move(This,iIndexFrom,iIndexTo)	\
    (This)->lpVtbl -> Move(This,iIndexFrom,iIndexTo)

#define ITargetObjectCol_get_Source(This,ppIObj)	\
    (This)->lpVtbl -> get_Source(This,ppIObj)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE ITargetObjectCol_Add_Proxy( 
    ITargetObjectCol __RPC_FAR * This,
    /* [in] */ IDispatch __RPC_FAR *pIReposObj,
    /* [defaultvalue][in] */ BSTR Name,
    /* [retval][out] */ IRelationship __RPC_FAR *__RPC_FAR *ppIRelship);


void __RPC_STUB ITargetObjectCol_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE ITargetObjectCol_Remove_Proxy( 
    ITargetObjectCol __RPC_FAR * This,
    /* [in] */ VARIANT sItem);


void __RPC_STUB ITargetObjectCol_Remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE ITargetObjectCol_get_Type_Proxy( 
    ITargetObjectCol __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *psTypeID);


void __RPC_STUB ITargetObjectCol_get_Type_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE ITargetObjectCol_Insert_Proxy( 
    ITargetObjectCol __RPC_FAR * This,
    /* [in] */ IDispatch __RPC_FAR *pIReposObj,
    /* [in] */ long iIndex,
    /* [defaultvalue][in] */ BSTR Name,
    /* [retval][out] */ IRelationship __RPC_FAR *__RPC_FAR *ppIRelship);


void __RPC_STUB ITargetObjectCol_Insert_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE ITargetObjectCol_Move_Proxy( 
    ITargetObjectCol __RPC_FAR * This,
    /* [in] */ long iIndexFrom,
    /* [in] */ long iIndexTo);


void __RPC_STUB ITargetObjectCol_Move_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE ITargetObjectCol_get_Source_Proxy( 
    ITargetObjectCol __RPC_FAR * This,
    /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIObj);


void __RPC_STUB ITargetObjectCol_get_Source_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITargetObjectCol_INTERFACE_DEFINED__ */


#ifndef __IWorkspaceItem_INTERFACE_DEFINED__
#define __IWorkspaceItem_INTERFACE_DEFINED__

/* interface IWorkspaceItem */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IWorkspaceItem,0x5B04093F,0xE9B1,0x11d0,0xA8,0x40,0x00,0xC0,0x4F,0xC2,0xF8,0x97);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5B04093F-E9B1-11d0-A840-00C04FC2F897")
    IWorkspaceItem : public IRepositoryObject
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Checkout( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Checkin( void) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Workspaces( 
            /* [retval][out] */ IVersionCol __RPC_FAR *__RPC_FAR *ppWorkspaces) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_CheckOutWorkspace( 
            /* [retval][out] */ IWorkspace __RPC_FAR *__RPC_FAR *ppIWorkspace) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_IsCheckedOut( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbCheckedOut) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWorkspaceItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IWorkspaceItem __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IWorkspaceItem __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IWorkspaceItem __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IWorkspaceItem __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IWorkspaceItem __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IWorkspaceItem __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IWorkspaceItem __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IWorkspaceItem __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Type )( 
            IWorkspaceItem __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psTypeID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Repository )( 
            IWorkspaceItem __RPC_FAR * This,
            /* [retval][out] */ IRepository __RPC_FAR *__RPC_FAR *ppIRepository);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IWorkspaceItem __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pName);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Name )( 
            IWorkspaceItem __RPC_FAR * This,
            /* [in] */ BSTR Name);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Interface )( 
            IWorkspaceItem __RPC_FAR * This,
            /* [in] */ VARIANT Iface,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppIIface);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Delete )( 
            IWorkspaceItem __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Lock )( 
            IWorkspaceItem __RPC_FAR * This);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ObjectID )( 
            IWorkspaceItem __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psObjID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_InternalID )( 
            IWorkspaceItem __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psIntID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Refresh )( 
            IWorkspaceItem __RPC_FAR * This,
            /* [in] */ long iMilliseconds);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Checkout )( 
            IWorkspaceItem __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Checkin )( 
            IWorkspaceItem __RPC_FAR * This);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Workspaces )( 
            IWorkspaceItem __RPC_FAR * This,
            /* [retval][out] */ IVersionCol __RPC_FAR *__RPC_FAR *ppWorkspaces);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CheckOutWorkspace )( 
            IWorkspaceItem __RPC_FAR * This,
            /* [retval][out] */ IWorkspace __RPC_FAR *__RPC_FAR *ppIWorkspace);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IsCheckedOut )( 
            IWorkspaceItem __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbCheckedOut);
        
        END_INTERFACE
    } IWorkspaceItemVtbl;

    interface IWorkspaceItem
    {
        CONST_VTBL struct IWorkspaceItemVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWorkspaceItem_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWorkspaceItem_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWorkspaceItem_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWorkspaceItem_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IWorkspaceItem_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IWorkspaceItem_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IWorkspaceItem_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IWorkspaceItem_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#define IWorkspaceItem_get_Type(This,psTypeID)	\
    (This)->lpVtbl -> get_Type(This,psTypeID)

#define IWorkspaceItem_get_Repository(This,ppIRepository)	\
    (This)->lpVtbl -> get_Repository(This,ppIRepository)

#define IWorkspaceItem_get_Name(This,pName)	\
    (This)->lpVtbl -> get_Name(This,pName)

#define IWorkspaceItem_put_Name(This,Name)	\
    (This)->lpVtbl -> put_Name(This,Name)

#define IWorkspaceItem_get_Interface(This,Iface,ppIIface)	\
    (This)->lpVtbl -> get_Interface(This,Iface,ppIIface)

#define IWorkspaceItem_Delete(This)	\
    (This)->lpVtbl -> Delete(This)

#define IWorkspaceItem_Lock(This)	\
    (This)->lpVtbl -> Lock(This)


#define IWorkspaceItem_get_ObjectID(This,psObjID)	\
    (This)->lpVtbl -> get_ObjectID(This,psObjID)

#define IWorkspaceItem_get_InternalID(This,psIntID)	\
    (This)->lpVtbl -> get_InternalID(This,psIntID)

#define IWorkspaceItem_Refresh(This,iMilliseconds)	\
    (This)->lpVtbl -> Refresh(This,iMilliseconds)


#define IWorkspaceItem_Checkout(This)	\
    (This)->lpVtbl -> Checkout(This)

#define IWorkspaceItem_Checkin(This)	\
    (This)->lpVtbl -> Checkin(This)

#define IWorkspaceItem_get_Workspaces(This,ppWorkspaces)	\
    (This)->lpVtbl -> get_Workspaces(This,ppWorkspaces)

#define IWorkspaceItem_get_CheckOutWorkspace(This,ppIWorkspace)	\
    (This)->lpVtbl -> get_CheckOutWorkspace(This,ppIWorkspace)

#define IWorkspaceItem_get_IsCheckedOut(This,pbCheckedOut)	\
    (This)->lpVtbl -> get_IsCheckedOut(This,pbCheckedOut)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IWorkspaceItem_Checkout_Proxy( 
    IWorkspaceItem __RPC_FAR * This);


void __RPC_STUB IWorkspaceItem_Checkout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IWorkspaceItem_Checkin_Proxy( 
    IWorkspaceItem __RPC_FAR * This);


void __RPC_STUB IWorkspaceItem_Checkin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IWorkspaceItem_get_Workspaces_Proxy( 
    IWorkspaceItem __RPC_FAR * This,
    /* [retval][out] */ IVersionCol __RPC_FAR *__RPC_FAR *ppWorkspaces);


void __RPC_STUB IWorkspaceItem_get_Workspaces_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IWorkspaceItem_get_CheckOutWorkspace_Proxy( 
    IWorkspaceItem __RPC_FAR * This,
    /* [retval][out] */ IWorkspace __RPC_FAR *__RPC_FAR *ppIWorkspace);


void __RPC_STUB IWorkspaceItem_get_CheckOutWorkspace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IWorkspaceItem_get_IsCheckedOut_Proxy( 
    IWorkspaceItem __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbCheckedOut);


void __RPC_STUB IWorkspaceItem_get_IsCheckedOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWorkspaceItem_INTERFACE_DEFINED__ */


#ifndef __IRepositoryObject2_INTERFACE_DEFINED__
#define __IRepositoryObject2_INTERFACE_DEFINED__

/* interface IRepositoryObject2 */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IRepositoryObject2,0xD3FD85C0,0x073D,0x11d3,0x83,0xD5,0x00,0xC0,0x4F,0x6E,0xA6,0x48);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D3FD85C0-073D-11d3-83D5-00C04F6EA648")
    IRepositoryObject2 : public IRepositoryObject
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ClassType( 
            /* [retval][out] */ VARIANT __RPC_FAR *pIClassDef) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ClassName( 
            /* [retval][out] */ BSTR __RPC_FAR *pClassName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRepositoryObject2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRepositoryObject2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRepositoryObject2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRepositoryObject2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRepositoryObject2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRepositoryObject2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRepositoryObject2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRepositoryObject2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IRepositoryObject2 __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Type )( 
            IRepositoryObject2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psTypeID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Repository )( 
            IRepositoryObject2 __RPC_FAR * This,
            /* [retval][out] */ IRepository __RPC_FAR *__RPC_FAR *ppIRepository);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IRepositoryObject2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pName);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Name )( 
            IRepositoryObject2 __RPC_FAR * This,
            /* [in] */ BSTR Name);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Interface )( 
            IRepositoryObject2 __RPC_FAR * This,
            /* [in] */ VARIANT Iface,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppIIface);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Delete )( 
            IRepositoryObject2 __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Lock )( 
            IRepositoryObject2 __RPC_FAR * This);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ObjectID )( 
            IRepositoryObject2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psObjID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_InternalID )( 
            IRepositoryObject2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psIntID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Refresh )( 
            IRepositoryObject2 __RPC_FAR * This,
            /* [in] */ long iMilliseconds);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ClassType )( 
            IRepositoryObject2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pIClassDef);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ClassName )( 
            IRepositoryObject2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pClassName);
        
        END_INTERFACE
    } IRepositoryObject2Vtbl;

    interface IRepositoryObject2
    {
        CONST_VTBL struct IRepositoryObject2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRepositoryObject2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRepositoryObject2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRepositoryObject2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRepositoryObject2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRepositoryObject2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRepositoryObject2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRepositoryObject2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRepositoryObject2_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#define IRepositoryObject2_get_Type(This,psTypeID)	\
    (This)->lpVtbl -> get_Type(This,psTypeID)

#define IRepositoryObject2_get_Repository(This,ppIRepository)	\
    (This)->lpVtbl -> get_Repository(This,ppIRepository)

#define IRepositoryObject2_get_Name(This,pName)	\
    (This)->lpVtbl -> get_Name(This,pName)

#define IRepositoryObject2_put_Name(This,Name)	\
    (This)->lpVtbl -> put_Name(This,Name)

#define IRepositoryObject2_get_Interface(This,Iface,ppIIface)	\
    (This)->lpVtbl -> get_Interface(This,Iface,ppIIface)

#define IRepositoryObject2_Delete(This)	\
    (This)->lpVtbl -> Delete(This)

#define IRepositoryObject2_Lock(This)	\
    (This)->lpVtbl -> Lock(This)


#define IRepositoryObject2_get_ObjectID(This,psObjID)	\
    (This)->lpVtbl -> get_ObjectID(This,psObjID)

#define IRepositoryObject2_get_InternalID(This,psIntID)	\
    (This)->lpVtbl -> get_InternalID(This,psIntID)

#define IRepositoryObject2_Refresh(This,iMilliseconds)	\
    (This)->lpVtbl -> Refresh(This,iMilliseconds)


#define IRepositoryObject2_get_ClassType(This,pIClassDef)	\
    (This)->lpVtbl -> get_ClassType(This,pIClassDef)

#define IRepositoryObject2_get_ClassName(This,pClassName)	\
    (This)->lpVtbl -> get_ClassName(This,pClassName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepositoryObject2_get_ClassType_Proxy( 
    IRepositoryObject2 __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pIClassDef);


void __RPC_STUB IRepositoryObject2_get_ClassType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepositoryObject2_get_ClassName_Proxy( 
    IRepositoryObject2 __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pClassName);


void __RPC_STUB IRepositoryObject2_get_ClassName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRepositoryObject2_INTERFACE_DEFINED__ */


#ifndef __IRepositoryObjectVersion_INTERFACE_DEFINED__
#define __IRepositoryObjectVersion_INTERFACE_DEFINED__

/* interface IRepositoryObjectVersion */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IRepositoryObjectVersion,0xEEB07500,0xA17D,0x11d0,0xB0,0x2C,0x00,0xA0,0xC9,0x0F,0xEE,0x3A);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EEB07500-A17D-11d0-B02C-00A0C90FEE3A")
    IRepositoryObjectVersion : public IWorkspaceItem
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_VersionInternalID( 
            /* [retval][out] */ VARIANT __RPC_FAR *psVersionID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_VersionID( 
            /* [retval][out] */ VARIANT __RPC_FAR *psVersionID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_IsFrozen( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbFrozen) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ObjectVersions( 
            /* [retval][out] */ IVersionCol __RPC_FAR *__RPC_FAR *ppObjVersions) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_SuccessorVersions( 
            /* [retval][out] */ IVersionCol __RPC_FAR *__RPC_FAR *ppSuccVersions) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_PredecessorVersions( 
            /* [retval][out] */ IVersionCol __RPC_FAR *__RPC_FAR *ppPredVersions) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateVersion( 
            /* [optional][in] */ VARIANT sVersionID,
            /* [retval][out] */ IRepositoryObjectVersion __RPC_FAR *__RPC_FAR *ppCreatedVersion) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE FreezeVersion( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE MergeVersion( 
            /* [in] */ IRepositoryObjectVersion __RPC_FAR *pOtherVersion,
            /* [in] */ long fFlags) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_PredecessorCreationVersion( 
            /* [retval][out] */ IRepositoryObjectVersion __RPC_FAR *__RPC_FAR *ppPredCreationVersion) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ResolutionType( 
            /* [retval][out] */ LONG __RPC_FAR *pResolutionType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRepositoryObjectVersionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRepositoryObjectVersion __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRepositoryObjectVersion __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Type )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psTypeID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Repository )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [retval][out] */ IRepository __RPC_FAR *__RPC_FAR *ppIRepository);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pName);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Name )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [in] */ BSTR Name);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Interface )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [in] */ VARIANT Iface,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppIIface);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Delete )( 
            IRepositoryObjectVersion __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Lock )( 
            IRepositoryObjectVersion __RPC_FAR * This);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ObjectID )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psObjID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_InternalID )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psIntID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Refresh )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [in] */ long iMilliseconds);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Checkout )( 
            IRepositoryObjectVersion __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Checkin )( 
            IRepositoryObjectVersion __RPC_FAR * This);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Workspaces )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [retval][out] */ IVersionCol __RPC_FAR *__RPC_FAR *ppWorkspaces);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CheckOutWorkspace )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [retval][out] */ IWorkspace __RPC_FAR *__RPC_FAR *ppIWorkspace);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IsCheckedOut )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbCheckedOut);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_VersionInternalID )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psVersionID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_VersionID )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psVersionID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IsFrozen )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbFrozen);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ObjectVersions )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [retval][out] */ IVersionCol __RPC_FAR *__RPC_FAR *ppObjVersions);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SuccessorVersions )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [retval][out] */ IVersionCol __RPC_FAR *__RPC_FAR *ppSuccVersions);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PredecessorVersions )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [retval][out] */ IVersionCol __RPC_FAR *__RPC_FAR *ppPredVersions);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateVersion )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [optional][in] */ VARIANT sVersionID,
            /* [retval][out] */ IRepositoryObjectVersion __RPC_FAR *__RPC_FAR *ppCreatedVersion);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreezeVersion )( 
            IRepositoryObjectVersion __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MergeVersion )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [in] */ IRepositoryObjectVersion __RPC_FAR *pOtherVersion,
            /* [in] */ long fFlags);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PredecessorCreationVersion )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [retval][out] */ IRepositoryObjectVersion __RPC_FAR *__RPC_FAR *ppPredCreationVersion);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ResolutionType )( 
            IRepositoryObjectVersion __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pResolutionType);
        
        END_INTERFACE
    } IRepositoryObjectVersionVtbl;

    interface IRepositoryObjectVersion
    {
        CONST_VTBL struct IRepositoryObjectVersionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRepositoryObjectVersion_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRepositoryObjectVersion_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRepositoryObjectVersion_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRepositoryObjectVersion_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRepositoryObjectVersion_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRepositoryObjectVersion_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRepositoryObjectVersion_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRepositoryObjectVersion_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#define IRepositoryObjectVersion_get_Type(This,psTypeID)	\
    (This)->lpVtbl -> get_Type(This,psTypeID)

#define IRepositoryObjectVersion_get_Repository(This,ppIRepository)	\
    (This)->lpVtbl -> get_Repository(This,ppIRepository)

#define IRepositoryObjectVersion_get_Name(This,pName)	\
    (This)->lpVtbl -> get_Name(This,pName)

#define IRepositoryObjectVersion_put_Name(This,Name)	\
    (This)->lpVtbl -> put_Name(This,Name)

#define IRepositoryObjectVersion_get_Interface(This,Iface,ppIIface)	\
    (This)->lpVtbl -> get_Interface(This,Iface,ppIIface)

#define IRepositoryObjectVersion_Delete(This)	\
    (This)->lpVtbl -> Delete(This)

#define IRepositoryObjectVersion_Lock(This)	\
    (This)->lpVtbl -> Lock(This)


#define IRepositoryObjectVersion_get_ObjectID(This,psObjID)	\
    (This)->lpVtbl -> get_ObjectID(This,psObjID)

#define IRepositoryObjectVersion_get_InternalID(This,psIntID)	\
    (This)->lpVtbl -> get_InternalID(This,psIntID)

#define IRepositoryObjectVersion_Refresh(This,iMilliseconds)	\
    (This)->lpVtbl -> Refresh(This,iMilliseconds)


#define IRepositoryObjectVersion_Checkout(This)	\
    (This)->lpVtbl -> Checkout(This)

#define IRepositoryObjectVersion_Checkin(This)	\
    (This)->lpVtbl -> Checkin(This)

#define IRepositoryObjectVersion_get_Workspaces(This,ppWorkspaces)	\
    (This)->lpVtbl -> get_Workspaces(This,ppWorkspaces)

#define IRepositoryObjectVersion_get_CheckOutWorkspace(This,ppIWorkspace)	\
    (This)->lpVtbl -> get_CheckOutWorkspace(This,ppIWorkspace)

#define IRepositoryObjectVersion_get_IsCheckedOut(This,pbCheckedOut)	\
    (This)->lpVtbl -> get_IsCheckedOut(This,pbCheckedOut)


#define IRepositoryObjectVersion_get_VersionInternalID(This,psVersionID)	\
    (This)->lpVtbl -> get_VersionInternalID(This,psVersionID)

#define IRepositoryObjectVersion_get_VersionID(This,psVersionID)	\
    (This)->lpVtbl -> get_VersionID(This,psVersionID)

#define IRepositoryObjectVersion_get_IsFrozen(This,pbFrozen)	\
    (This)->lpVtbl -> get_IsFrozen(This,pbFrozen)

#define IRepositoryObjectVersion_get_ObjectVersions(This,ppObjVersions)	\
    (This)->lpVtbl -> get_ObjectVersions(This,ppObjVersions)

#define IRepositoryObjectVersion_get_SuccessorVersions(This,ppSuccVersions)	\
    (This)->lpVtbl -> get_SuccessorVersions(This,ppSuccVersions)

#define IRepositoryObjectVersion_get_PredecessorVersions(This,ppPredVersions)	\
    (This)->lpVtbl -> get_PredecessorVersions(This,ppPredVersions)

#define IRepositoryObjectVersion_CreateVersion(This,sVersionID,ppCreatedVersion)	\
    (This)->lpVtbl -> CreateVersion(This,sVersionID,ppCreatedVersion)

#define IRepositoryObjectVersion_FreezeVersion(This)	\
    (This)->lpVtbl -> FreezeVersion(This)

#define IRepositoryObjectVersion_MergeVersion(This,pOtherVersion,fFlags)	\
    (This)->lpVtbl -> MergeVersion(This,pOtherVersion,fFlags)

#define IRepositoryObjectVersion_get_PredecessorCreationVersion(This,ppPredCreationVersion)	\
    (This)->lpVtbl -> get_PredecessorCreationVersion(This,ppPredCreationVersion)

#define IRepositoryObjectVersion_get_ResolutionType(This,pResolutionType)	\
    (This)->lpVtbl -> get_ResolutionType(This,pResolutionType)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepositoryObjectVersion_get_VersionInternalID_Proxy( 
    IRepositoryObjectVersion __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *psVersionID);


void __RPC_STUB IRepositoryObjectVersion_get_VersionInternalID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepositoryObjectVersion_get_VersionID_Proxy( 
    IRepositoryObjectVersion __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *psVersionID);


void __RPC_STUB IRepositoryObjectVersion_get_VersionID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepositoryObjectVersion_get_IsFrozen_Proxy( 
    IRepositoryObjectVersion __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pbFrozen);


void __RPC_STUB IRepositoryObjectVersion_get_IsFrozen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepositoryObjectVersion_get_ObjectVersions_Proxy( 
    IRepositoryObjectVersion __RPC_FAR * This,
    /* [retval][out] */ IVersionCol __RPC_FAR *__RPC_FAR *ppObjVersions);


void __RPC_STUB IRepositoryObjectVersion_get_ObjectVersions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepositoryObjectVersion_get_SuccessorVersions_Proxy( 
    IRepositoryObjectVersion __RPC_FAR * This,
    /* [retval][out] */ IVersionCol __RPC_FAR *__RPC_FAR *ppSuccVersions);


void __RPC_STUB IRepositoryObjectVersion_get_SuccessorVersions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepositoryObjectVersion_get_PredecessorVersions_Proxy( 
    IRepositoryObjectVersion __RPC_FAR * This,
    /* [retval][out] */ IVersionCol __RPC_FAR *__RPC_FAR *ppPredVersions);


void __RPC_STUB IRepositoryObjectVersion_get_PredecessorVersions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRepositoryObjectVersion_CreateVersion_Proxy( 
    IRepositoryObjectVersion __RPC_FAR * This,
    /* [optional][in] */ VARIANT sVersionID,
    /* [retval][out] */ IRepositoryObjectVersion __RPC_FAR *__RPC_FAR *ppCreatedVersion);


void __RPC_STUB IRepositoryObjectVersion_CreateVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRepositoryObjectVersion_FreezeVersion_Proxy( 
    IRepositoryObjectVersion __RPC_FAR * This);


void __RPC_STUB IRepositoryObjectVersion_FreezeVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRepositoryObjectVersion_MergeVersion_Proxy( 
    IRepositoryObjectVersion __RPC_FAR * This,
    /* [in] */ IRepositoryObjectVersion __RPC_FAR *pOtherVersion,
    /* [in] */ long fFlags);


void __RPC_STUB IRepositoryObjectVersion_MergeVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepositoryObjectVersion_get_PredecessorCreationVersion_Proxy( 
    IRepositoryObjectVersion __RPC_FAR * This,
    /* [retval][out] */ IRepositoryObjectVersion __RPC_FAR *__RPC_FAR *ppPredCreationVersion);


void __RPC_STUB IRepositoryObjectVersion_get_PredecessorCreationVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepositoryObjectVersion_get_ResolutionType_Proxy( 
    IRepositoryObjectVersion __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pResolutionType);


void __RPC_STUB IRepositoryObjectVersion_get_ResolutionType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRepositoryObjectVersion_INTERFACE_DEFINED__ */


#ifndef __IRepositoryObjectStorage_INTERFACE_DEFINED__
#define __IRepositoryObjectStorage_INTERFACE_DEFINED__

/* interface IRepositoryObjectStorage */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IRepositoryObjectStorage,0x6E22711D,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E22711D-F799-11cf-9227-00AA00A1EB95")
    IRepositoryObjectStorage : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE InitNew( 
            /* [in] */ IRepository __RPC_FAR *pIRepos,
            /* [in] */ long lCookie) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ IRepository __RPC_FAR *pIRepos,
            /* [in] */ long lCookie) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_PropertyInterface( 
            /* [in] */ VARIANT sIface,
            /* [retval][out] */ IRepositoryDispatch __RPC_FAR *__RPC_FAR *ppIIface) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRepositoryObjectStorageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRepositoryObjectStorage __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRepositoryObjectStorage __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRepositoryObjectStorage __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRepositoryObjectStorage __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRepositoryObjectStorage __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRepositoryObjectStorage __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRepositoryObjectStorage __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitNew )( 
            IRepositoryObjectStorage __RPC_FAR * This,
            /* [in] */ IRepository __RPC_FAR *pIRepos,
            /* [in] */ long lCookie);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Load )( 
            IRepositoryObjectStorage __RPC_FAR * This,
            /* [in] */ IRepository __RPC_FAR *pIRepos,
            /* [in] */ long lCookie);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PropertyInterface )( 
            IRepositoryObjectStorage __RPC_FAR * This,
            /* [in] */ VARIANT sIface,
            /* [retval][out] */ IRepositoryDispatch __RPC_FAR *__RPC_FAR *ppIIface);
        
        END_INTERFACE
    } IRepositoryObjectStorageVtbl;

    interface IRepositoryObjectStorage
    {
        CONST_VTBL struct IRepositoryObjectStorageVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRepositoryObjectStorage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRepositoryObjectStorage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRepositoryObjectStorage_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRepositoryObjectStorage_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRepositoryObjectStorage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRepositoryObjectStorage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRepositoryObjectStorage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRepositoryObjectStorage_InitNew(This,pIRepos,lCookie)	\
    (This)->lpVtbl -> InitNew(This,pIRepos,lCookie)

#define IRepositoryObjectStorage_Load(This,pIRepos,lCookie)	\
    (This)->lpVtbl -> Load(This,pIRepos,lCookie)

#define IRepositoryObjectStorage_get_PropertyInterface(This,sIface,ppIIface)	\
    (This)->lpVtbl -> get_PropertyInterface(This,sIface,ppIIface)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IRepositoryObjectStorage_InitNew_Proxy( 
    IRepositoryObjectStorage __RPC_FAR * This,
    /* [in] */ IRepository __RPC_FAR *pIRepos,
    /* [in] */ long lCookie);


void __RPC_STUB IRepositoryObjectStorage_InitNew_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRepositoryObjectStorage_Load_Proxy( 
    IRepositoryObjectStorage __RPC_FAR * This,
    /* [in] */ IRepository __RPC_FAR *pIRepos,
    /* [in] */ long lCookie);


void __RPC_STUB IRepositoryObjectStorage_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepositoryObjectStorage_get_PropertyInterface_Proxy( 
    IRepositoryObjectStorage __RPC_FAR * This,
    /* [in] */ VARIANT sIface,
    /* [retval][out] */ IRepositoryDispatch __RPC_FAR *__RPC_FAR *ppIIface);


void __RPC_STUB IRepositoryObjectStorage_get_PropertyInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRepositoryObjectStorage_INTERFACE_DEFINED__ */


#ifndef __IWorkspace_INTERFACE_DEFINED__
#define __IWorkspace_INTERFACE_DEFINED__

/* interface IWorkspace */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IWorkspace,0x96BA8C5D,0xE9B4,0x11d0,0xA8,0x40,0x00,0xC0,0x4F,0xC2,0xF8,0x97);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96BA8C5D-E9B4-11d0-A840-00C04FC2F897")
    IWorkspace : public IRepositoryDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_CheckOuts( 
            /* [retval][out] */ IVersionCol __RPC_FAR *__RPC_FAR *ppWSVersions) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Contents( 
            /* [retval][out] */ IVersionCol __RPC_FAR *__RPC_FAR *ppWSVersions) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWorkspaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IWorkspace __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IWorkspace __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IWorkspace __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IWorkspace __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IWorkspace __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IWorkspace __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IWorkspace __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IWorkspace __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CheckOuts )( 
            IWorkspace __RPC_FAR * This,
            /* [retval][out] */ IVersionCol __RPC_FAR *__RPC_FAR *ppWSVersions);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Contents )( 
            IWorkspace __RPC_FAR * This,
            /* [retval][out] */ IVersionCol __RPC_FAR *__RPC_FAR *ppWSVersions);
        
        END_INTERFACE
    } IWorkspaceVtbl;

    interface IWorkspace
    {
        CONST_VTBL struct IWorkspaceVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWorkspace_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWorkspace_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWorkspace_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWorkspace_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IWorkspace_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IWorkspace_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IWorkspace_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IWorkspace_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#define IWorkspace_get_CheckOuts(This,ppWSVersions)	\
    (This)->lpVtbl -> get_CheckOuts(This,ppWSVersions)

#define IWorkspace_get_Contents(This,ppWSVersions)	\
    (This)->lpVtbl -> get_Contents(This,ppWSVersions)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IWorkspace_get_CheckOuts_Proxy( 
    IWorkspace __RPC_FAR * This,
    /* [retval][out] */ IVersionCol __RPC_FAR *__RPC_FAR *ppWSVersions);


void __RPC_STUB IWorkspace_get_CheckOuts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IWorkspace_get_Contents_Proxy( 
    IWorkspace __RPC_FAR * This,
    /* [retval][out] */ IVersionCol __RPC_FAR *__RPC_FAR *ppWSVersions);


void __RPC_STUB IWorkspace_get_Contents_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWorkspace_INTERFACE_DEFINED__ */


#ifndef __IWorkspaceContainer_INTERFACE_DEFINED__
#define __IWorkspaceContainer_INTERFACE_DEFINED__

/* interface IWorkspaceContainer */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IWorkspaceContainer,0x2C983A1C,0x65D9,0x11d1,0xAE,0xF8,0x00,0xC0,0x4F,0xB6,0xE9,0x33);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2C983A1C-65D9-11d1-AEF8-00C04FB6E933")
    IWorkspaceContainer : public IRepositoryDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IWorkspaceContainerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IWorkspaceContainer __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IWorkspaceContainer __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IWorkspaceContainer __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IWorkspaceContainer __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IWorkspaceContainer __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IWorkspaceContainer __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IWorkspaceContainer __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IWorkspaceContainer __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        END_INTERFACE
    } IWorkspaceContainerVtbl;

    interface IWorkspaceContainer
    {
        CONST_VTBL struct IWorkspaceContainerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWorkspaceContainer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWorkspaceContainer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWorkspaceContainer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWorkspaceContainer_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IWorkspaceContainer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IWorkspaceContainer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IWorkspaceContainer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IWorkspaceContainer_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWorkspaceContainer_INTERFACE_DEFINED__ */


#ifndef __IRelationship_INTERFACE_DEFINED__
#define __IRelationship_INTERFACE_DEFINED__

/* interface IRelationship */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IRelationship,0x6E2270F3,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E2270F3-F799-11cf-9227-00AA00A1EB95")
    IRelationship : public IRepositoryItem
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Source( 
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIReposObj) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Target( 
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIReposObj) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Origin( 
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIReposObj) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Destination( 
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIReposObj) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRelationshipVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRelationship __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRelationship __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRelationship __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRelationship __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRelationship __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRelationship __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRelationship __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IRelationship __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Type )( 
            IRelationship __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psTypeID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Repository )( 
            IRelationship __RPC_FAR * This,
            /* [retval][out] */ IRepository __RPC_FAR *__RPC_FAR *ppIRepository);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IRelationship __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pName);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Name )( 
            IRelationship __RPC_FAR * This,
            /* [in] */ BSTR Name);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Interface )( 
            IRelationship __RPC_FAR * This,
            /* [in] */ VARIANT Iface,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppIIface);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Delete )( 
            IRelationship __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Lock )( 
            IRelationship __RPC_FAR * This);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Source )( 
            IRelationship __RPC_FAR * This,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIReposObj);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Target )( 
            IRelationship __RPC_FAR * This,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIReposObj);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Origin )( 
            IRelationship __RPC_FAR * This,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIReposObj);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Destination )( 
            IRelationship __RPC_FAR * This,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIReposObj);
        
        END_INTERFACE
    } IRelationshipVtbl;

    interface IRelationship
    {
        CONST_VTBL struct IRelationshipVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRelationship_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRelationship_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRelationship_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRelationship_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRelationship_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRelationship_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRelationship_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRelationship_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#define IRelationship_get_Type(This,psTypeID)	\
    (This)->lpVtbl -> get_Type(This,psTypeID)

#define IRelationship_get_Repository(This,ppIRepository)	\
    (This)->lpVtbl -> get_Repository(This,ppIRepository)

#define IRelationship_get_Name(This,pName)	\
    (This)->lpVtbl -> get_Name(This,pName)

#define IRelationship_put_Name(This,Name)	\
    (This)->lpVtbl -> put_Name(This,Name)

#define IRelationship_get_Interface(This,Iface,ppIIface)	\
    (This)->lpVtbl -> get_Interface(This,Iface,ppIIface)

#define IRelationship_Delete(This)	\
    (This)->lpVtbl -> Delete(This)

#define IRelationship_Lock(This)	\
    (This)->lpVtbl -> Lock(This)


#define IRelationship_get_Source(This,ppIReposObj)	\
    (This)->lpVtbl -> get_Source(This,ppIReposObj)

#define IRelationship_get_Target(This,ppIReposObj)	\
    (This)->lpVtbl -> get_Target(This,ppIReposObj)

#define IRelationship_get_Origin(This,ppIReposObj)	\
    (This)->lpVtbl -> get_Origin(This,ppIReposObj)

#define IRelationship_get_Destination(This,ppIReposObj)	\
    (This)->lpVtbl -> get_Destination(This,ppIReposObj)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRelationship_get_Source_Proxy( 
    IRelationship __RPC_FAR * This,
    /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIReposObj);


void __RPC_STUB IRelationship_get_Source_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRelationship_get_Target_Proxy( 
    IRelationship __RPC_FAR * This,
    /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIReposObj);


void __RPC_STUB IRelationship_get_Target_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRelationship_get_Origin_Proxy( 
    IRelationship __RPC_FAR * This,
    /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIReposObj);


void __RPC_STUB IRelationship_get_Origin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRelationship_get_Destination_Proxy( 
    IRelationship __RPC_FAR * This,
    /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIReposObj);


void __RPC_STUB IRelationship_get_Destination_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRelationship_INTERFACE_DEFINED__ */


#ifndef __IVersionedRelationship_INTERFACE_DEFINED__
#define __IVersionedRelationship_INTERFACE_DEFINED__

/* interface IVersionedRelationship */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IVersionedRelationship,0x5E945310,0xC7E9,0x11d0,0xB0,0x36,0x00,0xA0,0xC9,0x0F,0xEE,0x3A);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5E945310-C7E9-11d0-B036-00A0C90FEE3A")
    IVersionedRelationship : public IRelationship
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_TargetVersions( 
            /* [retval][out] */ IVersionCol __RPC_FAR *__RPC_FAR *ppTargetVersions) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Pin( 
            /* [in] */ IRepositoryObjectVersion __RPC_FAR *pIReposVersion) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Unpin( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVersionedRelationshipVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IVersionedRelationship __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IVersionedRelationship __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IVersionedRelationship __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IVersionedRelationship __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IVersionedRelationship __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IVersionedRelationship __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IVersionedRelationship __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IVersionedRelationship __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Type )( 
            IVersionedRelationship __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psTypeID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Repository )( 
            IVersionedRelationship __RPC_FAR * This,
            /* [retval][out] */ IRepository __RPC_FAR *__RPC_FAR *ppIRepository);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IVersionedRelationship __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pName);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Name )( 
            IVersionedRelationship __RPC_FAR * This,
            /* [in] */ BSTR Name);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Interface )( 
            IVersionedRelationship __RPC_FAR * This,
            /* [in] */ VARIANT Iface,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppIIface);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Delete )( 
            IVersionedRelationship __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Lock )( 
            IVersionedRelationship __RPC_FAR * This);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Source )( 
            IVersionedRelationship __RPC_FAR * This,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIReposObj);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Target )( 
            IVersionedRelationship __RPC_FAR * This,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIReposObj);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Origin )( 
            IVersionedRelationship __RPC_FAR * This,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIReposObj);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Destination )( 
            IVersionedRelationship __RPC_FAR * This,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIReposObj);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TargetVersions )( 
            IVersionedRelationship __RPC_FAR * This,
            /* [retval][out] */ IVersionCol __RPC_FAR *__RPC_FAR *ppTargetVersions);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Pin )( 
            IVersionedRelationship __RPC_FAR * This,
            /* [in] */ IRepositoryObjectVersion __RPC_FAR *pIReposVersion);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Unpin )( 
            IVersionedRelationship __RPC_FAR * This);
        
        END_INTERFACE
    } IVersionedRelationshipVtbl;

    interface IVersionedRelationship
    {
        CONST_VTBL struct IVersionedRelationshipVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVersionedRelationship_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVersionedRelationship_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVersionedRelationship_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVersionedRelationship_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IVersionedRelationship_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IVersionedRelationship_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IVersionedRelationship_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IVersionedRelationship_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#define IVersionedRelationship_get_Type(This,psTypeID)	\
    (This)->lpVtbl -> get_Type(This,psTypeID)

#define IVersionedRelationship_get_Repository(This,ppIRepository)	\
    (This)->lpVtbl -> get_Repository(This,ppIRepository)

#define IVersionedRelationship_get_Name(This,pName)	\
    (This)->lpVtbl -> get_Name(This,pName)

#define IVersionedRelationship_put_Name(This,Name)	\
    (This)->lpVtbl -> put_Name(This,Name)

#define IVersionedRelationship_get_Interface(This,Iface,ppIIface)	\
    (This)->lpVtbl -> get_Interface(This,Iface,ppIIface)

#define IVersionedRelationship_Delete(This)	\
    (This)->lpVtbl -> Delete(This)

#define IVersionedRelationship_Lock(This)	\
    (This)->lpVtbl -> Lock(This)


#define IVersionedRelationship_get_Source(This,ppIReposObj)	\
    (This)->lpVtbl -> get_Source(This,ppIReposObj)

#define IVersionedRelationship_get_Target(This,ppIReposObj)	\
    (This)->lpVtbl -> get_Target(This,ppIReposObj)

#define IVersionedRelationship_get_Origin(This,ppIReposObj)	\
    (This)->lpVtbl -> get_Origin(This,ppIReposObj)

#define IVersionedRelationship_get_Destination(This,ppIReposObj)	\
    (This)->lpVtbl -> get_Destination(This,ppIReposObj)


#define IVersionedRelationship_get_TargetVersions(This,ppTargetVersions)	\
    (This)->lpVtbl -> get_TargetVersions(This,ppTargetVersions)

#define IVersionedRelationship_Pin(This,pIReposVersion)	\
    (This)->lpVtbl -> Pin(This,pIReposVersion)

#define IVersionedRelationship_Unpin(This)	\
    (This)->lpVtbl -> Unpin(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IVersionedRelationship_get_TargetVersions_Proxy( 
    IVersionedRelationship __RPC_FAR * This,
    /* [retval][out] */ IVersionCol __RPC_FAR *__RPC_FAR *ppTargetVersions);


void __RPC_STUB IVersionedRelationship_get_TargetVersions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IVersionedRelationship_Pin_Proxy( 
    IVersionedRelationship __RPC_FAR * This,
    /* [in] */ IRepositoryObjectVersion __RPC_FAR *pIReposVersion);


void __RPC_STUB IVersionedRelationship_Pin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IVersionedRelationship_Unpin_Proxy( 
    IVersionedRelationship __RPC_FAR * This);


void __RPC_STUB IVersionedRelationship_Unpin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVersionedRelationship_INTERFACE_DEFINED__ */


#ifndef __IReposProperty_INTERFACE_DEFINED__
#define __IReposProperty_INTERFACE_DEFINED__

/* interface IReposProperty */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IReposProperty,0x6E2270F4,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E2270F4-F799-11cf-9227-00AA00A1EB95")
    IReposProperty : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR __RPC_FAR *pName) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ VARIANT __RPC_FAR *psTypeID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ VARIANT __RPC_FAR *psValue) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ VARIANT sValue) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IReposPropertyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IReposProperty __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IReposProperty __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IReposProperty __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IReposProperty __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IReposProperty __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IReposProperty __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IReposProperty __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IReposProperty __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pName);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Type )( 
            IReposProperty __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psTypeID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Value )( 
            IReposProperty __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psValue);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Value )( 
            IReposProperty __RPC_FAR * This,
            /* [in] */ VARIANT sValue);
        
        END_INTERFACE
    } IReposPropertyVtbl;

    interface IReposProperty
    {
        CONST_VTBL struct IReposPropertyVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IReposProperty_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IReposProperty_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IReposProperty_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IReposProperty_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IReposProperty_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IReposProperty_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IReposProperty_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IReposProperty_get_Name(This,pName)	\
    (This)->lpVtbl -> get_Name(This,pName)

#define IReposProperty_get_Type(This,psTypeID)	\
    (This)->lpVtbl -> get_Type(This,psTypeID)

#define IReposProperty_get_Value(This,psValue)	\
    (This)->lpVtbl -> get_Value(This,psValue)

#define IReposProperty_put_Value(This,sValue)	\
    (This)->lpVtbl -> put_Value(This,sValue)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IReposProperty_get_Name_Proxy( 
    IReposProperty __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pName);


void __RPC_STUB IReposProperty_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IReposProperty_get_Type_Proxy( 
    IReposProperty __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *psTypeID);


void __RPC_STUB IReposProperty_get_Type_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IReposProperty_get_Value_Proxy( 
    IReposProperty __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *psValue);


void __RPC_STUB IReposProperty_get_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IReposProperty_put_Value_Proxy( 
    IReposProperty __RPC_FAR * This,
    /* [in] */ VARIANT sValue);


void __RPC_STUB IReposProperty_put_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IReposProperty_INTERFACE_DEFINED__ */


#ifndef __IReposPropertyLarge_INTERFACE_DEFINED__
#define __IReposPropertyLarge_INTERFACE_DEFINED__

/* interface IReposPropertyLarge */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IReposPropertyLarge,0x6E2270F4,0xF799,0x11cf,0x92,0x27,0xFE,0xAA,0x00,0xA1,0xEB,0x9F);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E2270F4-F799-11cf-9227-FEAA00A1EB9F")
    IReposPropertyLarge : public IReposProperty
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Read( 
            /* [in] */ LONG lSizeToRead,
            /* [out] */ LONG __RPC_FAR *plSizeRead,
            /* [out] */ VARIANT __RPC_FAR *psBlob) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Write( 
            /* [in] */ VARIANT sBlob) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [retval][out] */ LONG __RPC_FAR *plSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_CurrentPosition( 
            /* [retval][out] */ LONG __RPC_FAR *plCurrentPosition) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_CurrentPosition( 
            /* [in] */ LONG lCurrentPosition) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadFromFile( 
            /* [in] */ BSTR FileName) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE WriteToFile( 
            /* [in] */ BSTR FileName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IReposPropertyLargeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IReposPropertyLarge __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IReposPropertyLarge __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IReposPropertyLarge __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IReposPropertyLarge __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IReposPropertyLarge __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IReposPropertyLarge __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IReposPropertyLarge __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IReposPropertyLarge __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pName);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Type )( 
            IReposPropertyLarge __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psTypeID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Value )( 
            IReposPropertyLarge __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psValue);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Value )( 
            IReposPropertyLarge __RPC_FAR * This,
            /* [in] */ VARIANT sValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Read )( 
            IReposPropertyLarge __RPC_FAR * This,
            /* [in] */ LONG lSizeToRead,
            /* [out] */ LONG __RPC_FAR *plSizeRead,
            /* [out] */ VARIANT __RPC_FAR *psBlob);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Write )( 
            IReposPropertyLarge __RPC_FAR * This,
            /* [in] */ VARIANT sBlob);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Size )( 
            IReposPropertyLarge __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IReposPropertyLarge __RPC_FAR * This);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CurrentPosition )( 
            IReposPropertyLarge __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plCurrentPosition);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CurrentPosition )( 
            IReposPropertyLarge __RPC_FAR * This,
            /* [in] */ LONG lCurrentPosition);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadFromFile )( 
            IReposPropertyLarge __RPC_FAR * This,
            /* [in] */ BSTR FileName);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteToFile )( 
            IReposPropertyLarge __RPC_FAR * This,
            /* [in] */ BSTR FileName);
        
        END_INTERFACE
    } IReposPropertyLargeVtbl;

    interface IReposPropertyLarge
    {
        CONST_VTBL struct IReposPropertyLargeVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IReposPropertyLarge_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IReposPropertyLarge_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IReposPropertyLarge_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IReposPropertyLarge_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IReposPropertyLarge_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IReposPropertyLarge_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IReposPropertyLarge_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IReposPropertyLarge_get_Name(This,pName)	\
    (This)->lpVtbl -> get_Name(This,pName)

#define IReposPropertyLarge_get_Type(This,psTypeID)	\
    (This)->lpVtbl -> get_Type(This,psTypeID)

#define IReposPropertyLarge_get_Value(This,psValue)	\
    (This)->lpVtbl -> get_Value(This,psValue)

#define IReposPropertyLarge_put_Value(This,sValue)	\
    (This)->lpVtbl -> put_Value(This,sValue)


#define IReposPropertyLarge_Read(This,lSizeToRead,plSizeRead,psBlob)	\
    (This)->lpVtbl -> Read(This,lSizeToRead,plSizeRead,psBlob)

#define IReposPropertyLarge_Write(This,sBlob)	\
    (This)->lpVtbl -> Write(This,sBlob)

#define IReposPropertyLarge_get_Size(This,plSize)	\
    (This)->lpVtbl -> get_Size(This,plSize)

#define IReposPropertyLarge_Close(This)	\
    (This)->lpVtbl -> Close(This)

#define IReposPropertyLarge_get_CurrentPosition(This,plCurrentPosition)	\
    (This)->lpVtbl -> get_CurrentPosition(This,plCurrentPosition)

#define IReposPropertyLarge_put_CurrentPosition(This,lCurrentPosition)	\
    (This)->lpVtbl -> put_CurrentPosition(This,lCurrentPosition)

#define IReposPropertyLarge_ReadFromFile(This,FileName)	\
    (This)->lpVtbl -> ReadFromFile(This,FileName)

#define IReposPropertyLarge_WriteToFile(This,FileName)	\
    (This)->lpVtbl -> WriteToFile(This,FileName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IReposPropertyLarge_Read_Proxy( 
    IReposPropertyLarge __RPC_FAR * This,
    /* [in] */ LONG lSizeToRead,
    /* [out] */ LONG __RPC_FAR *plSizeRead,
    /* [out] */ VARIANT __RPC_FAR *psBlob);


void __RPC_STUB IReposPropertyLarge_Read_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IReposPropertyLarge_Write_Proxy( 
    IReposPropertyLarge __RPC_FAR * This,
    /* [in] */ VARIANT sBlob);


void __RPC_STUB IReposPropertyLarge_Write_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IReposPropertyLarge_get_Size_Proxy( 
    IReposPropertyLarge __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plSize);


void __RPC_STUB IReposPropertyLarge_get_Size_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IReposPropertyLarge_Close_Proxy( 
    IReposPropertyLarge __RPC_FAR * This);


void __RPC_STUB IReposPropertyLarge_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IReposPropertyLarge_get_CurrentPosition_Proxy( 
    IReposPropertyLarge __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plCurrentPosition);


void __RPC_STUB IReposPropertyLarge_get_CurrentPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IReposPropertyLarge_put_CurrentPosition_Proxy( 
    IReposPropertyLarge __RPC_FAR * This,
    /* [in] */ LONG lCurrentPosition);


void __RPC_STUB IReposPropertyLarge_put_CurrentPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IReposPropertyLarge_ReadFromFile_Proxy( 
    IReposPropertyLarge __RPC_FAR * This,
    /* [in] */ BSTR FileName);


void __RPC_STUB IReposPropertyLarge_ReadFromFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IReposPropertyLarge_WriteToFile_Proxy( 
    IReposPropertyLarge __RPC_FAR * This,
    /* [in] */ BSTR FileName);


void __RPC_STUB IReposPropertyLarge_WriteToFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IReposPropertyLarge_INTERFACE_DEFINED__ */


#ifndef __IReposProperty2_INTERFACE_DEFINED__
#define __IReposProperty2_INTERFACE_DEFINED__

/* interface IReposProperty2 */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IReposProperty2,0xBA870D30,0x0187,0x11d3,0x83,0xD3,0x00,0xC0,0x4F,0x6E,0xA6,0x48);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BA870D30-0187-11d3-83D3-00C04F6EA648")
    IReposProperty2 : public IReposProperty
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_PropType( 
            /* [retval][out] */ VARIANT __RPC_FAR *pIIfaceMember) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_IsBaseMember( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pIsBase) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_APIType( 
            /* [retval][out] */ LONG __RPC_FAR *pAPIType) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_IsOriginCollection( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pIsOrigin) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_IsReadOnly( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pIsReadOnly) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Flags( 
            /* [retval][out] */ LONG __RPC_FAR *pFlags) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_IsMostDerived( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pIsMostDerived) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IReposProperty2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IReposProperty2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IReposProperty2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IReposProperty2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IReposProperty2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IReposProperty2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IReposProperty2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IReposProperty2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IReposProperty2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pName);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Type )( 
            IReposProperty2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psTypeID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Value )( 
            IReposProperty2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psValue);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Value )( 
            IReposProperty2 __RPC_FAR * This,
            /* [in] */ VARIANT sValue);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PropType )( 
            IReposProperty2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pIIfaceMember);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IsBaseMember )( 
            IReposProperty2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pIsBase);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_APIType )( 
            IReposProperty2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pAPIType);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IsOriginCollection )( 
            IReposProperty2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pIsOrigin);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IsReadOnly )( 
            IReposProperty2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pIsReadOnly);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Flags )( 
            IReposProperty2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pFlags);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IsMostDerived )( 
            IReposProperty2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pIsMostDerived);
        
        END_INTERFACE
    } IReposProperty2Vtbl;

    interface IReposProperty2
    {
        CONST_VTBL struct IReposProperty2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IReposProperty2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IReposProperty2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IReposProperty2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IReposProperty2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IReposProperty2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IReposProperty2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IReposProperty2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IReposProperty2_get_Name(This,pName)	\
    (This)->lpVtbl -> get_Name(This,pName)

#define IReposProperty2_get_Type(This,psTypeID)	\
    (This)->lpVtbl -> get_Type(This,psTypeID)

#define IReposProperty2_get_Value(This,psValue)	\
    (This)->lpVtbl -> get_Value(This,psValue)

#define IReposProperty2_put_Value(This,sValue)	\
    (This)->lpVtbl -> put_Value(This,sValue)


#define IReposProperty2_get_PropType(This,pIIfaceMember)	\
    (This)->lpVtbl -> get_PropType(This,pIIfaceMember)

#define IReposProperty2_get_IsBaseMember(This,pIsBase)	\
    (This)->lpVtbl -> get_IsBaseMember(This,pIsBase)

#define IReposProperty2_get_APIType(This,pAPIType)	\
    (This)->lpVtbl -> get_APIType(This,pAPIType)

#define IReposProperty2_get_IsOriginCollection(This,pIsOrigin)	\
    (This)->lpVtbl -> get_IsOriginCollection(This,pIsOrigin)

#define IReposProperty2_get_IsReadOnly(This,pIsReadOnly)	\
    (This)->lpVtbl -> get_IsReadOnly(This,pIsReadOnly)

#define IReposProperty2_get_Flags(This,pFlags)	\
    (This)->lpVtbl -> get_Flags(This,pFlags)

#define IReposProperty2_get_IsMostDerived(This,pIsMostDerived)	\
    (This)->lpVtbl -> get_IsMostDerived(This,pIsMostDerived)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IReposProperty2_get_PropType_Proxy( 
    IReposProperty2 __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pIIfaceMember);


void __RPC_STUB IReposProperty2_get_PropType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IReposProperty2_get_IsBaseMember_Proxy( 
    IReposProperty2 __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pIsBase);


void __RPC_STUB IReposProperty2_get_IsBaseMember_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IReposProperty2_get_APIType_Proxy( 
    IReposProperty2 __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pAPIType);


void __RPC_STUB IReposProperty2_get_APIType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IReposProperty2_get_IsOriginCollection_Proxy( 
    IReposProperty2 __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pIsOrigin);


void __RPC_STUB IReposProperty2_get_IsOriginCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IReposProperty2_get_IsReadOnly_Proxy( 
    IReposProperty2 __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pIsReadOnly);


void __RPC_STUB IReposProperty2_get_IsReadOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IReposProperty2_get_Flags_Proxy( 
    IReposProperty2 __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pFlags);


void __RPC_STUB IReposProperty2_get_Flags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IReposProperty2_get_IsMostDerived_Proxy( 
    IReposProperty2 __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pIsMostDerived);


void __RPC_STUB IReposProperty2_get_IsMostDerived_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IReposProperty2_INTERFACE_DEFINED__ */


#ifndef __IRelationshipCol_INTERFACE_DEFINED__
#define __IRelationshipCol_INTERFACE_DEFINED__

/* interface IRelationshipCol */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IRelationshipCol,0x6E2270F7,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E2270F7-F799-11cf-9227-00AA00A1EB95")
    IRelationshipCol : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *piCount) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT sItem,
            /* [retval][out] */ IRelationship __RPC_FAR *__RPC_FAR *ppIItem) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE _NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppIEnum) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ IDispatch __RPC_FAR *pIReposObj,
            /* [defaultvalue][in] */ BSTR Name,
            /* [retval][out] */ IRelationship __RPC_FAR *__RPC_FAR *ppIRelship) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ VARIANT sItem) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ VARIANT __RPC_FAR *psTypeID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Insert( 
            /* [in] */ IDispatch __RPC_FAR *pIReposObj,
            /* [in] */ long iIndex,
            /* [defaultvalue][in] */ BSTR Name,
            /* [retval][out] */ IRelationship __RPC_FAR *__RPC_FAR *ppIRelship) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Move( 
            /* [in] */ long iIndexFrom,
            /* [in] */ long iIndexTo) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Refresh( 
            /* [in] */ long iMilliseconds) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Source( 
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIObj) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRelationshipColVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRelationshipCol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRelationshipCol __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRelationshipCol __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRelationshipCol __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRelationshipCol __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRelationshipCol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRelationshipCol __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IRelationshipCol __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *piCount);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IRelationshipCol __RPC_FAR * This,
            /* [in] */ VARIANT sItem,
            /* [retval][out] */ IRelationship __RPC_FAR *__RPC_FAR *ppIItem);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *_NewEnum )( 
            IRelationshipCol __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppIEnum);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IRelationshipCol __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *pIReposObj,
            /* [defaultvalue][in] */ BSTR Name,
            /* [retval][out] */ IRelationship __RPC_FAR *__RPC_FAR *ppIRelship);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove )( 
            IRelationshipCol __RPC_FAR * This,
            /* [in] */ VARIANT sItem);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Type )( 
            IRelationshipCol __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psTypeID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Insert )( 
            IRelationshipCol __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *pIReposObj,
            /* [in] */ long iIndex,
            /* [defaultvalue][in] */ BSTR Name,
            /* [retval][out] */ IRelationship __RPC_FAR *__RPC_FAR *ppIRelship);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Move )( 
            IRelationshipCol __RPC_FAR * This,
            /* [in] */ long iIndexFrom,
            /* [in] */ long iIndexTo);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Refresh )( 
            IRelationshipCol __RPC_FAR * This,
            /* [in] */ long iMilliseconds);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Source )( 
            IRelationshipCol __RPC_FAR * This,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIObj);
        
        END_INTERFACE
    } IRelationshipColVtbl;

    interface IRelationshipCol
    {
        CONST_VTBL struct IRelationshipColVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRelationshipCol_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRelationshipCol_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRelationshipCol_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRelationshipCol_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRelationshipCol_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRelationshipCol_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRelationshipCol_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRelationshipCol_get_Count(This,piCount)	\
    (This)->lpVtbl -> get_Count(This,piCount)

#define IRelationshipCol_get_Item(This,sItem,ppIItem)	\
    (This)->lpVtbl -> get_Item(This,sItem,ppIItem)

#define IRelationshipCol__NewEnum(This,ppIEnum)	\
    (This)->lpVtbl -> _NewEnum(This,ppIEnum)

#define IRelationshipCol_Add(This,pIReposObj,Name,ppIRelship)	\
    (This)->lpVtbl -> Add(This,pIReposObj,Name,ppIRelship)

#define IRelationshipCol_Remove(This,sItem)	\
    (This)->lpVtbl -> Remove(This,sItem)

#define IRelationshipCol_get_Type(This,psTypeID)	\
    (This)->lpVtbl -> get_Type(This,psTypeID)

#define IRelationshipCol_Insert(This,pIReposObj,iIndex,Name,ppIRelship)	\
    (This)->lpVtbl -> Insert(This,pIReposObj,iIndex,Name,ppIRelship)

#define IRelationshipCol_Move(This,iIndexFrom,iIndexTo)	\
    (This)->lpVtbl -> Move(This,iIndexFrom,iIndexTo)

#define IRelationshipCol_Refresh(This,iMilliseconds)	\
    (This)->lpVtbl -> Refresh(This,iMilliseconds)

#define IRelationshipCol_get_Source(This,ppIObj)	\
    (This)->lpVtbl -> get_Source(This,ppIObj)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRelationshipCol_get_Count_Proxy( 
    IRelationshipCol __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *piCount);


void __RPC_STUB IRelationshipCol_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRelationshipCol_get_Item_Proxy( 
    IRelationshipCol __RPC_FAR * This,
    /* [in] */ VARIANT sItem,
    /* [retval][out] */ IRelationship __RPC_FAR *__RPC_FAR *ppIItem);


void __RPC_STUB IRelationshipCol_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IRelationshipCol__NewEnum_Proxy( 
    IRelationshipCol __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppIEnum);


void __RPC_STUB IRelationshipCol__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRelationshipCol_Add_Proxy( 
    IRelationshipCol __RPC_FAR * This,
    /* [in] */ IDispatch __RPC_FAR *pIReposObj,
    /* [defaultvalue][in] */ BSTR Name,
    /* [retval][out] */ IRelationship __RPC_FAR *__RPC_FAR *ppIRelship);


void __RPC_STUB IRelationshipCol_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRelationshipCol_Remove_Proxy( 
    IRelationshipCol __RPC_FAR * This,
    /* [in] */ VARIANT sItem);


void __RPC_STUB IRelationshipCol_Remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRelationshipCol_get_Type_Proxy( 
    IRelationshipCol __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *psTypeID);


void __RPC_STUB IRelationshipCol_get_Type_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRelationshipCol_Insert_Proxy( 
    IRelationshipCol __RPC_FAR * This,
    /* [in] */ IDispatch __RPC_FAR *pIReposObj,
    /* [in] */ long iIndex,
    /* [defaultvalue][in] */ BSTR Name,
    /* [retval][out] */ IRelationship __RPC_FAR *__RPC_FAR *ppIRelship);


void __RPC_STUB IRelationshipCol_Insert_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRelationshipCol_Move_Proxy( 
    IRelationshipCol __RPC_FAR * This,
    /* [in] */ long iIndexFrom,
    /* [in] */ long iIndexTo);


void __RPC_STUB IRelationshipCol_Move_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRelationshipCol_Refresh_Proxy( 
    IRelationshipCol __RPC_FAR * This,
    /* [in] */ long iMilliseconds);


void __RPC_STUB IRelationshipCol_Refresh_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRelationshipCol_get_Source_Proxy( 
    IRelationshipCol __RPC_FAR * This,
    /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIObj);


void __RPC_STUB IRelationshipCol_get_Source_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRelationshipCol_INTERFACE_DEFINED__ */


#ifndef __IObjectCol2_INTERFACE_DEFINED__
#define __IObjectCol2_INTERFACE_DEFINED__

/* interface IObjectCol2 */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IObjectCol2,0x63FD21FD,0xB44E,0x11d1,0x98,0xB7,0x00,0xC0,0x4F,0xC3,0x0B,0x4A);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("63FD21FD-B44E-11d1-98B7-00C04FC30B4A")
    IObjectCol2 : public IObjectCol
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_LoadStatus( 
            /* [retval][out] */ long __RPC_FAR *piStatus) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IObjectCol2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IObjectCol2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IObjectCol2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IObjectCol2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IObjectCol2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IObjectCol2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IObjectCol2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IObjectCol2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IObjectCol2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *piCount);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IObjectCol2 __RPC_FAR * This,
            /* [in] */ VARIANT sItem,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIItem);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *_NewEnum )( 
            IObjectCol2 __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppIEnum);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Refresh )( 
            IObjectCol2 __RPC_FAR * This,
            /* [in] */ long iMilliseconds);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LoadStatus )( 
            IObjectCol2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *piStatus);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Cancel )( 
            IObjectCol2 __RPC_FAR * This);
        
        END_INTERFACE
    } IObjectCol2Vtbl;

    interface IObjectCol2
    {
        CONST_VTBL struct IObjectCol2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IObjectCol2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IObjectCol2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IObjectCol2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IObjectCol2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IObjectCol2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IObjectCol2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IObjectCol2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IObjectCol2_get_Count(This,piCount)	\
    (This)->lpVtbl -> get_Count(This,piCount)

#define IObjectCol2_get_Item(This,sItem,ppIItem)	\
    (This)->lpVtbl -> get_Item(This,sItem,ppIItem)

#define IObjectCol2__NewEnum(This,ppIEnum)	\
    (This)->lpVtbl -> _NewEnum(This,ppIEnum)

#define IObjectCol2_Refresh(This,iMilliseconds)	\
    (This)->lpVtbl -> Refresh(This,iMilliseconds)


#define IObjectCol2_get_LoadStatus(This,piStatus)	\
    (This)->lpVtbl -> get_LoadStatus(This,piStatus)

#define IObjectCol2_Cancel(This)	\
    (This)->lpVtbl -> Cancel(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IObjectCol2_get_LoadStatus_Proxy( 
    IObjectCol2 __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *piStatus);


void __RPC_STUB IObjectCol2_get_LoadStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IObjectCol2_Cancel_Proxy( 
    IObjectCol2 __RPC_FAR * This);


void __RPC_STUB IObjectCol2_Cancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IObjectCol2_INTERFACE_DEFINED__ */


#ifndef __IRepositoryTransaction_INTERFACE_DEFINED__
#define __IRepositoryTransaction_INTERFACE_DEFINED__

/* interface IRepositoryTransaction */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IRepositoryTransaction,0x6E2270F9,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E2270F9-F799-11cf-9227-00AA00A1EB95")
    IRepositoryTransaction : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Begin( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Commit( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Abort( void) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Status( 
            /* [retval][out] */ long __RPC_FAR *piStatus) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetOption( 
            /* [in] */ long iOption,
            /* [retval][out] */ VARIANT __RPC_FAR *psValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetOption( 
            /* [in] */ long iOption,
            /* [in] */ VARIANT sValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Flush( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRepositoryTransactionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRepositoryTransaction __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRepositoryTransaction __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRepositoryTransaction __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRepositoryTransaction __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRepositoryTransaction __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRepositoryTransaction __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRepositoryTransaction __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Begin )( 
            IRepositoryTransaction __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Commit )( 
            IRepositoryTransaction __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Abort )( 
            IRepositoryTransaction __RPC_FAR * This);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Status )( 
            IRepositoryTransaction __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *piStatus);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOption )( 
            IRepositoryTransaction __RPC_FAR * This,
            /* [in] */ long iOption,
            /* [retval][out] */ VARIANT __RPC_FAR *psValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetOption )( 
            IRepositoryTransaction __RPC_FAR * This,
            /* [in] */ long iOption,
            /* [in] */ VARIANT sValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Flush )( 
            IRepositoryTransaction __RPC_FAR * This);
        
        END_INTERFACE
    } IRepositoryTransactionVtbl;

    interface IRepositoryTransaction
    {
        CONST_VTBL struct IRepositoryTransactionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRepositoryTransaction_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRepositoryTransaction_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRepositoryTransaction_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRepositoryTransaction_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRepositoryTransaction_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRepositoryTransaction_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRepositoryTransaction_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRepositoryTransaction_Begin(This)	\
    (This)->lpVtbl -> Begin(This)

#define IRepositoryTransaction_Commit(This)	\
    (This)->lpVtbl -> Commit(This)

#define IRepositoryTransaction_Abort(This)	\
    (This)->lpVtbl -> Abort(This)

#define IRepositoryTransaction_get_Status(This,piStatus)	\
    (This)->lpVtbl -> get_Status(This,piStatus)

#define IRepositoryTransaction_GetOption(This,iOption,psValue)	\
    (This)->lpVtbl -> GetOption(This,iOption,psValue)

#define IRepositoryTransaction_SetOption(This,iOption,sValue)	\
    (This)->lpVtbl -> SetOption(This,iOption,sValue)

#define IRepositoryTransaction_Flush(This)	\
    (This)->lpVtbl -> Flush(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IRepositoryTransaction_Begin_Proxy( 
    IRepositoryTransaction __RPC_FAR * This);


void __RPC_STUB IRepositoryTransaction_Begin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRepositoryTransaction_Commit_Proxy( 
    IRepositoryTransaction __RPC_FAR * This);


void __RPC_STUB IRepositoryTransaction_Commit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRepositoryTransaction_Abort_Proxy( 
    IRepositoryTransaction __RPC_FAR * This);


void __RPC_STUB IRepositoryTransaction_Abort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepositoryTransaction_get_Status_Proxy( 
    IRepositoryTransaction __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *piStatus);


void __RPC_STUB IRepositoryTransaction_get_Status_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRepositoryTransaction_GetOption_Proxy( 
    IRepositoryTransaction __RPC_FAR * This,
    /* [in] */ long iOption,
    /* [retval][out] */ VARIANT __RPC_FAR *psValue);


void __RPC_STUB IRepositoryTransaction_GetOption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRepositoryTransaction_SetOption_Proxy( 
    IRepositoryTransaction __RPC_FAR * This,
    /* [in] */ long iOption,
    /* [in] */ VARIANT sValue);


void __RPC_STUB IRepositoryTransaction_SetOption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRepositoryTransaction_Flush_Proxy( 
    IRepositoryTransaction __RPC_FAR * This);


void __RPC_STUB IRepositoryTransaction_Flush_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRepositoryTransaction_INTERFACE_DEFINED__ */


#ifndef __IRepositoryTransaction2_INTERFACE_DEFINED__
#define __IRepositoryTransaction2_INTERFACE_DEFINED__

/* interface IRepositoryTransaction2 */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IRepositoryTransaction2,0xF9009CB6,0xE959,0x11d2,0xA8,0xC5,0x00,0xC0,0x4F,0xC2,0xF8,0x97);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F9009CB6-E959-11d2-A8C5-00C04FC2F897")
    IRepositoryTransaction2 : public IRepositoryTransaction
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_DTCTransaction( 
            /* [retval][out] */ VARIANT __RPC_FAR *psVarTxn) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE JoinTransaction( 
            /* [in] */ VARIANT sVarTxn) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRepositoryTransaction2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRepositoryTransaction2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRepositoryTransaction2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRepositoryTransaction2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRepositoryTransaction2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRepositoryTransaction2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRepositoryTransaction2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRepositoryTransaction2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Begin )( 
            IRepositoryTransaction2 __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Commit )( 
            IRepositoryTransaction2 __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Abort )( 
            IRepositoryTransaction2 __RPC_FAR * This);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Status )( 
            IRepositoryTransaction2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *piStatus);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOption )( 
            IRepositoryTransaction2 __RPC_FAR * This,
            /* [in] */ long iOption,
            /* [retval][out] */ VARIANT __RPC_FAR *psValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetOption )( 
            IRepositoryTransaction2 __RPC_FAR * This,
            /* [in] */ long iOption,
            /* [in] */ VARIANT sValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Flush )( 
            IRepositoryTransaction2 __RPC_FAR * This);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DTCTransaction )( 
            IRepositoryTransaction2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *psVarTxn);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *JoinTransaction )( 
            IRepositoryTransaction2 __RPC_FAR * This,
            /* [in] */ VARIANT sVarTxn);
        
        END_INTERFACE
    } IRepositoryTransaction2Vtbl;

    interface IRepositoryTransaction2
    {
        CONST_VTBL struct IRepositoryTransaction2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRepositoryTransaction2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRepositoryTransaction2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRepositoryTransaction2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRepositoryTransaction2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRepositoryTransaction2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRepositoryTransaction2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRepositoryTransaction2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRepositoryTransaction2_Begin(This)	\
    (This)->lpVtbl -> Begin(This)

#define IRepositoryTransaction2_Commit(This)	\
    (This)->lpVtbl -> Commit(This)

#define IRepositoryTransaction2_Abort(This)	\
    (This)->lpVtbl -> Abort(This)

#define IRepositoryTransaction2_get_Status(This,piStatus)	\
    (This)->lpVtbl -> get_Status(This,piStatus)

#define IRepositoryTransaction2_GetOption(This,iOption,psValue)	\
    (This)->lpVtbl -> GetOption(This,iOption,psValue)

#define IRepositoryTransaction2_SetOption(This,iOption,sValue)	\
    (This)->lpVtbl -> SetOption(This,iOption,sValue)

#define IRepositoryTransaction2_Flush(This)	\
    (This)->lpVtbl -> Flush(This)


#define IRepositoryTransaction2_get_DTCTransaction(This,psVarTxn)	\
    (This)->lpVtbl -> get_DTCTransaction(This,psVarTxn)

#define IRepositoryTransaction2_JoinTransaction(This,sVarTxn)	\
    (This)->lpVtbl -> JoinTransaction(This,sVarTxn)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepositoryTransaction2_get_DTCTransaction_Proxy( 
    IRepositoryTransaction2 __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *psVarTxn);


void __RPC_STUB IRepositoryTransaction2_get_DTCTransaction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRepositoryTransaction2_JoinTransaction_Proxy( 
    IRepositoryTransaction2 __RPC_FAR * This,
    /* [in] */ VARIANT sVarTxn);


void __RPC_STUB IRepositoryTransaction2_JoinTransaction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRepositoryTransaction2_INTERFACE_DEFINED__ */


#ifndef __IRepository2_INTERFACE_DEFINED__
#define __IRepository2_INTERFACE_DEFINED__

/* interface IRepository2 */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IRepository2,0x0A81A780,0xD05D,0x11d0,0xB0,0x37,0x00,0xA0,0xC9,0x0F,0xEE,0x3A);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0A81A780-D05D-11d0-B037-00A0C90FEE3A")
    IRepository2 : public IRepository
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Version( 
            /* [in] */ VARIANT sVersionID,
            /* [retval][out] */ IRepositoryObjectVersion __RPC_FAR *__RPC_FAR *ppIReposVersion) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE VersionIDToInternalID( 
            /* [in] */ VARIANT sExtVersionID,
            /* [retval][out] */ VARIANT __RPC_FAR *psIntVersionID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE InternalIDToVersionID( 
            /* [in] */ VARIANT sIntVersionID,
            /* [retval][out] */ VARIANT __RPC_FAR *psExtVersionID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_MajorDBVersion( 
            /* [retval][out] */ long __RPC_FAR *piMajorDBVersion) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_MinorDBVersion( 
            /* [retval][out] */ long __RPC_FAR *piMinorDBVersion) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateObjectEx( 
            /* [in] */ VARIANT sTypeID,
            /* [optional][in] */ VARIANT sObjID,
            /* [optional][in] */ VARIANT sExtVersionID,
            /* [retval][out] */ IRepositoryObjectVersion __RPC_FAR *__RPC_FAR *ppIReposObjVer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRepository2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRepository2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRepository2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRepository2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRepository2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRepository2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRepository2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRepository2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Create )( 
            IRepository2 __RPC_FAR * This,
            /* [defaultvalue][in] */ BSTR Connect,
            /* [defaultvalue][in] */ BSTR User,
            /* [defaultvalue][in] */ BSTR Password,
            /* [defaultvalue][in] */ long fFlags,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIRoot);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IRepository2 __RPC_FAR * This,
            /* [defaultvalue][in] */ BSTR Connect,
            /* [defaultvalue][in] */ BSTR User,
            /* [defaultvalue][in] */ BSTR Password,
            /* [defaultvalue][in] */ long fFlags,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIRoot);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateObject )( 
            IRepository2 __RPC_FAR * This,
            /* [in] */ VARIANT sTypeID,
            /* [optional][in] */ VARIANT sObjID,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIReposObj);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RootObject )( 
            IRepository2 __RPC_FAR * This,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIRoot);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Object )( 
            IRepository2 __RPC_FAR * This,
            /* [in] */ VARIANT sObjID,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIReposObj);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Refresh )( 
            IRepository2 __RPC_FAR * This,
            /* [in] */ long iMilliseconds);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ObjectIDToInternalID )( 
            IRepository2 __RPC_FAR * This,
            /* [in] */ VARIANT sObjID,
            /* [retval][out] */ VARIANT __RPC_FAR *psIntID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InternalIDToObjectID )( 
            IRepository2 __RPC_FAR * This,
            /* [in] */ VARIANT sIntID,
            /* [retval][out] */ VARIANT __RPC_FAR *psObjID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Transaction )( 
            IRepository2 __RPC_FAR * This,
            /* [retval][out] */ IRepositoryTransaction __RPC_FAR *__RPC_FAR *ppITxn);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Version )( 
            IRepository2 __RPC_FAR * This,
            /* [in] */ VARIANT sVersionID,
            /* [retval][out] */ IRepositoryObjectVersion __RPC_FAR *__RPC_FAR *ppIReposVersion);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *VersionIDToInternalID )( 
            IRepository2 __RPC_FAR * This,
            /* [in] */ VARIANT sExtVersionID,
            /* [retval][out] */ VARIANT __RPC_FAR *psIntVersionID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InternalIDToVersionID )( 
            IRepository2 __RPC_FAR * This,
            /* [in] */ VARIANT sIntVersionID,
            /* [retval][out] */ VARIANT __RPC_FAR *psExtVersionID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MajorDBVersion )( 
            IRepository2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *piMajorDBVersion);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MinorDBVersion )( 
            IRepository2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *piMinorDBVersion);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateObjectEx )( 
            IRepository2 __RPC_FAR * This,
            /* [in] */ VARIANT sTypeID,
            /* [optional][in] */ VARIANT sObjID,
            /* [optional][in] */ VARIANT sExtVersionID,
            /* [retval][out] */ IRepositoryObjectVersion __RPC_FAR *__RPC_FAR *ppIReposObjVer);
        
        END_INTERFACE
    } IRepository2Vtbl;

    interface IRepository2
    {
        CONST_VTBL struct IRepository2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRepository2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRepository2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRepository2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRepository2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRepository2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRepository2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRepository2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRepository2_Create(This,Connect,User,Password,fFlags,ppIRoot)	\
    (This)->lpVtbl -> Create(This,Connect,User,Password,fFlags,ppIRoot)

#define IRepository2_Open(This,Connect,User,Password,fFlags,ppIRoot)	\
    (This)->lpVtbl -> Open(This,Connect,User,Password,fFlags,ppIRoot)

#define IRepository2_CreateObject(This,sTypeID,sObjID,ppIReposObj)	\
    (This)->lpVtbl -> CreateObject(This,sTypeID,sObjID,ppIReposObj)

#define IRepository2_get_RootObject(This,ppIRoot)	\
    (This)->lpVtbl -> get_RootObject(This,ppIRoot)

#define IRepository2_get_Object(This,sObjID,ppIReposObj)	\
    (This)->lpVtbl -> get_Object(This,sObjID,ppIReposObj)

#define IRepository2_Refresh(This,iMilliseconds)	\
    (This)->lpVtbl -> Refresh(This,iMilliseconds)

#define IRepository2_ObjectIDToInternalID(This,sObjID,psIntID)	\
    (This)->lpVtbl -> ObjectIDToInternalID(This,sObjID,psIntID)

#define IRepository2_InternalIDToObjectID(This,sIntID,psObjID)	\
    (This)->lpVtbl -> InternalIDToObjectID(This,sIntID,psObjID)

#define IRepository2_get_Transaction(This,ppITxn)	\
    (This)->lpVtbl -> get_Transaction(This,ppITxn)


#define IRepository2_get_Version(This,sVersionID,ppIReposVersion)	\
    (This)->lpVtbl -> get_Version(This,sVersionID,ppIReposVersion)

#define IRepository2_VersionIDToInternalID(This,sExtVersionID,psIntVersionID)	\
    (This)->lpVtbl -> VersionIDToInternalID(This,sExtVersionID,psIntVersionID)

#define IRepository2_InternalIDToVersionID(This,sIntVersionID,psExtVersionID)	\
    (This)->lpVtbl -> InternalIDToVersionID(This,sIntVersionID,psExtVersionID)

#define IRepository2_get_MajorDBVersion(This,piMajorDBVersion)	\
    (This)->lpVtbl -> get_MajorDBVersion(This,piMajorDBVersion)

#define IRepository2_get_MinorDBVersion(This,piMinorDBVersion)	\
    (This)->lpVtbl -> get_MinorDBVersion(This,piMinorDBVersion)

#define IRepository2_CreateObjectEx(This,sTypeID,sObjID,sExtVersionID,ppIReposObjVer)	\
    (This)->lpVtbl -> CreateObjectEx(This,sTypeID,sObjID,sExtVersionID,ppIReposObjVer)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepository2_get_Version_Proxy( 
    IRepository2 __RPC_FAR * This,
    /* [in] */ VARIANT sVersionID,
    /* [retval][out] */ IRepositoryObjectVersion __RPC_FAR *__RPC_FAR *ppIReposVersion);


void __RPC_STUB IRepository2_get_Version_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRepository2_VersionIDToInternalID_Proxy( 
    IRepository2 __RPC_FAR * This,
    /* [in] */ VARIANT sExtVersionID,
    /* [retval][out] */ VARIANT __RPC_FAR *psIntVersionID);


void __RPC_STUB IRepository2_VersionIDToInternalID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRepository2_InternalIDToVersionID_Proxy( 
    IRepository2 __RPC_FAR * This,
    /* [in] */ VARIANT sIntVersionID,
    /* [retval][out] */ VARIANT __RPC_FAR *psExtVersionID);


void __RPC_STUB IRepository2_InternalIDToVersionID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepository2_get_MajorDBVersion_Proxy( 
    IRepository2 __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *piMajorDBVersion);


void __RPC_STUB IRepository2_get_MajorDBVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepository2_get_MinorDBVersion_Proxy( 
    IRepository2 __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *piMinorDBVersion);


void __RPC_STUB IRepository2_get_MinorDBVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRepository2_CreateObjectEx_Proxy( 
    IRepository2 __RPC_FAR * This,
    /* [in] */ VARIANT sTypeID,
    /* [optional][in] */ VARIANT sObjID,
    /* [optional][in] */ VARIANT sExtVersionID,
    /* [retval][out] */ IRepositoryObjectVersion __RPC_FAR *__RPC_FAR *ppIReposObjVer);


void __RPC_STUB IRepository2_CreateObjectEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRepository2_INTERFACE_DEFINED__ */


#ifndef __IRepositoryODBC_INTERFACE_DEFINED__
#define __IRepositoryODBC_INTERFACE_DEFINED__

/* interface IRepositoryODBC */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IRepositoryODBC,0x6E227118,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E227118-F799-11cf-9227-00AA00A1EB95")
    IRepositoryODBC : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ReposConnection( 
            /* [retval][out] */ long __RPC_FAR *pHdbc) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetNewConnection( 
            /* [retval][out] */ long __RPC_FAR *pHdbc) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE FreeConnection( 
            /* [in] */ long Hdbc) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ConnectionString( 
            /* [retval][out] */ BSTR __RPC_FAR *pConn) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ExecuteQuery( 
            /* [in] */ BSTR Query,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppICol) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRepositoryODBCVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRepositoryODBC __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRepositoryODBC __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRepositoryODBC __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRepositoryODBC __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRepositoryODBC __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRepositoryODBC __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRepositoryODBC __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ReposConnection )( 
            IRepositoryODBC __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pHdbc);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNewConnection )( 
            IRepositoryODBC __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pHdbc);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeConnection )( 
            IRepositoryODBC __RPC_FAR * This,
            /* [in] */ long Hdbc);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ConnectionString )( 
            IRepositoryODBC __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pConn);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExecuteQuery )( 
            IRepositoryODBC __RPC_FAR * This,
            /* [in] */ BSTR Query,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppICol);
        
        END_INTERFACE
    } IRepositoryODBCVtbl;

    interface IRepositoryODBC
    {
        CONST_VTBL struct IRepositoryODBCVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRepositoryODBC_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRepositoryODBC_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRepositoryODBC_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRepositoryODBC_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRepositoryODBC_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRepositoryODBC_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRepositoryODBC_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRepositoryODBC_get_ReposConnection(This,pHdbc)	\
    (This)->lpVtbl -> get_ReposConnection(This,pHdbc)

#define IRepositoryODBC_GetNewConnection(This,pHdbc)	\
    (This)->lpVtbl -> GetNewConnection(This,pHdbc)

#define IRepositoryODBC_FreeConnection(This,Hdbc)	\
    (This)->lpVtbl -> FreeConnection(This,Hdbc)

#define IRepositoryODBC_get_ConnectionString(This,pConn)	\
    (This)->lpVtbl -> get_ConnectionString(This,pConn)

#define IRepositoryODBC_ExecuteQuery(This,Query,ppICol)	\
    (This)->lpVtbl -> ExecuteQuery(This,Query,ppICol)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepositoryODBC_get_ReposConnection_Proxy( 
    IRepositoryODBC __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pHdbc);


void __RPC_STUB IRepositoryODBC_get_ReposConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRepositoryODBC_GetNewConnection_Proxy( 
    IRepositoryODBC __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pHdbc);


void __RPC_STUB IRepositoryODBC_GetNewConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRepositoryODBC_FreeConnection_Proxy( 
    IRepositoryODBC __RPC_FAR * This,
    /* [in] */ long Hdbc);


void __RPC_STUB IRepositoryODBC_FreeConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IRepositoryODBC_get_ConnectionString_Proxy( 
    IRepositoryODBC __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pConn);


void __RPC_STUB IRepositoryODBC_get_ConnectionString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRepositoryODBC_ExecuteQuery_Proxy( 
    IRepositoryODBC __RPC_FAR * This,
    /* [in] */ BSTR Query,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppICol);


void __RPC_STUB IRepositoryODBC_ExecuteQuery_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRepositoryODBC_INTERFACE_DEFINED__ */


#ifndef __IRepositoryODBC2_INTERFACE_DEFINED__
#define __IRepositoryODBC2_INTERFACE_DEFINED__

/* interface IRepositoryODBC2 */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IRepositoryODBC2,0x8780D159,0xB879,0x11d1,0x98,0xBA,0x00,0xC0,0x4F,0xC3,0x0B,0x4A);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8780D159-B879-11d1-98BA-00C04FC30B4A")
    IRepositoryODBC2 : public IRepositoryODBC
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetOption( 
            /* [in] */ long iOption,
            /* [retval][out] */ VARIANT __RPC_FAR *psValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetOption( 
            /* [in] */ long iOption,
            /* [in] */ VARIANT sValue) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRepositoryODBC2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRepositoryODBC2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRepositoryODBC2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRepositoryODBC2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRepositoryODBC2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRepositoryODBC2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRepositoryODBC2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRepositoryODBC2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ReposConnection )( 
            IRepositoryODBC2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pHdbc);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNewConnection )( 
            IRepositoryODBC2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pHdbc);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeConnection )( 
            IRepositoryODBC2 __RPC_FAR * This,
            /* [in] */ long Hdbc);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ConnectionString )( 
            IRepositoryODBC2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pConn);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExecuteQuery )( 
            IRepositoryODBC2 __RPC_FAR * This,
            /* [in] */ BSTR Query,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppICol);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOption )( 
            IRepositoryODBC2 __RPC_FAR * This,
            /* [in] */ long iOption,
            /* [retval][out] */ VARIANT __RPC_FAR *psValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetOption )( 
            IRepositoryODBC2 __RPC_FAR * This,
            /* [in] */ long iOption,
            /* [in] */ VARIANT sValue);
        
        END_INTERFACE
    } IRepositoryODBC2Vtbl;

    interface IRepositoryODBC2
    {
        CONST_VTBL struct IRepositoryODBC2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRepositoryODBC2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRepositoryODBC2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRepositoryODBC2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRepositoryODBC2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRepositoryODBC2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRepositoryODBC2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRepositoryODBC2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRepositoryODBC2_get_ReposConnection(This,pHdbc)	\
    (This)->lpVtbl -> get_ReposConnection(This,pHdbc)

#define IRepositoryODBC2_GetNewConnection(This,pHdbc)	\
    (This)->lpVtbl -> GetNewConnection(This,pHdbc)

#define IRepositoryODBC2_FreeConnection(This,Hdbc)	\
    (This)->lpVtbl -> FreeConnection(This,Hdbc)

#define IRepositoryODBC2_get_ConnectionString(This,pConn)	\
    (This)->lpVtbl -> get_ConnectionString(This,pConn)

#define IRepositoryODBC2_ExecuteQuery(This,Query,ppICol)	\
    (This)->lpVtbl -> ExecuteQuery(This,Query,ppICol)


#define IRepositoryODBC2_GetOption(This,iOption,psValue)	\
    (This)->lpVtbl -> GetOption(This,iOption,psValue)

#define IRepositoryODBC2_SetOption(This,iOption,sValue)	\
    (This)->lpVtbl -> SetOption(This,iOption,sValue)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IRepositoryODBC2_GetOption_Proxy( 
    IRepositoryODBC2 __RPC_FAR * This,
    /* [in] */ long iOption,
    /* [retval][out] */ VARIANT __RPC_FAR *psValue);


void __RPC_STUB IRepositoryODBC2_GetOption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IRepositoryODBC2_SetOption_Proxy( 
    IRepositoryODBC2 __RPC_FAR * This,
    /* [in] */ long iOption,
    /* [in] */ VARIANT sValue);


void __RPC_STUB IRepositoryODBC2_SetOption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRepositoryODBC2_INTERFACE_DEFINED__ */


#ifndef __IReposOptions_INTERFACE_DEFINED__
#define __IReposOptions_INTERFACE_DEFINED__

/* interface IReposOptions */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IReposOptions,0x4FCC0C60,0xBD71,0x11d2,0x83,0xB7,0x00,0xC0,0x4F,0x6E,0xA6,0x48);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4FCC0C60-BD71-11d2-83B7-00C04F6EA648")
    IReposOptions : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetOption( 
            /* [in] */ BSTR OptionName,
            /* [retval][out] */ VARIANT __RPC_FAR *OptionValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetOption( 
            /* [in] */ BSTR OptionName,
            /* [in] */ VARIANT OptionValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ResetOptions( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IReposOptionsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IReposOptions __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IReposOptions __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IReposOptions __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IReposOptions __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IReposOptions __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IReposOptions __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IReposOptions __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOption )( 
            IReposOptions __RPC_FAR * This,
            /* [in] */ BSTR OptionName,
            /* [retval][out] */ VARIANT __RPC_FAR *OptionValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetOption )( 
            IReposOptions __RPC_FAR * This,
            /* [in] */ BSTR OptionName,
            /* [in] */ VARIANT OptionValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ResetOptions )( 
            IReposOptions __RPC_FAR * This);
        
        END_INTERFACE
    } IReposOptionsVtbl;

    interface IReposOptions
    {
        CONST_VTBL struct IReposOptionsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IReposOptions_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IReposOptions_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IReposOptions_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IReposOptions_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IReposOptions_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IReposOptions_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IReposOptions_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IReposOptions_GetOption(This,OptionName,OptionValue)	\
    (This)->lpVtbl -> GetOption(This,OptionName,OptionValue)

#define IReposOptions_SetOption(This,OptionName,OptionValue)	\
    (This)->lpVtbl -> SetOption(This,OptionName,OptionValue)

#define IReposOptions_ResetOptions(This)	\
    (This)->lpVtbl -> ResetOptions(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IReposOptions_GetOption_Proxy( 
    IReposOptions __RPC_FAR * This,
    /* [in] */ BSTR OptionName,
    /* [retval][out] */ VARIANT __RPC_FAR *OptionValue);


void __RPC_STUB IReposOptions_GetOption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IReposOptions_SetOption_Proxy( 
    IReposOptions __RPC_FAR * This,
    /* [in] */ BSTR OptionName,
    /* [in] */ VARIANT OptionValue);


void __RPC_STUB IReposOptions_SetOption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IReposOptions_ResetOptions_Proxy( 
    IReposOptions __RPC_FAR * This);


void __RPC_STUB IReposOptions_ResetOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IReposOptions_INTERFACE_DEFINED__ */


#ifndef __IAnnotationalProps_INTERFACE_DEFINED__
#define __IAnnotationalProps_INTERFACE_DEFINED__

/* interface IAnnotationalProps */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IAnnotationalProps,0x6E227114,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E227114-F799-11cf-9227-00AA00A1EB95")
    IAnnotationalProps : public IRepositoryDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IAnnotationalPropsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAnnotationalProps __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAnnotationalProps __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAnnotationalProps __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAnnotationalProps __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAnnotationalProps __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAnnotationalProps __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAnnotationalProps __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IAnnotationalProps __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        END_INTERFACE
    } IAnnotationalPropsVtbl;

    interface IAnnotationalProps
    {
        CONST_VTBL struct IAnnotationalPropsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAnnotationalProps_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAnnotationalProps_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAnnotationalProps_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAnnotationalProps_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAnnotationalProps_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAnnotationalProps_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAnnotationalProps_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAnnotationalProps_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAnnotationalProps_INTERFACE_DEFINED__ */


#ifndef __ISummaryInformation_INTERFACE_DEFINED__
#define __ISummaryInformation_INTERFACE_DEFINED__

/* interface ISummaryInformation */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_ISummaryInformation,0x6E2270F1,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E2270F1-F799-11cf-9227-00AA00A1EB95")
    ISummaryInformation : public IRepositoryDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct ISummaryInformationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISummaryInformation __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISummaryInformation __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISummaryInformation __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISummaryInformation __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISummaryInformation __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISummaryInformation __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISummaryInformation __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            ISummaryInformation __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        END_INTERFACE
    } ISummaryInformationVtbl;

    interface ISummaryInformation
    {
        CONST_VTBL struct ISummaryInformationVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISummaryInformation_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISummaryInformation_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISummaryInformation_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISummaryInformation_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISummaryInformation_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISummaryInformation_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISummaryInformation_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISummaryInformation_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISummaryInformation_INTERFACE_DEFINED__ */


#ifndef __INamedObject_INTERFACE_DEFINED__
#define __INamedObject_INTERFACE_DEFINED__

/* interface INamedObject */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_INamedObject,0x6E22711C,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E22711C-F799-11cf-9227-00AA00A1EB95")
    INamedObject : public IRepositoryDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct INamedObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            INamedObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            INamedObject __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            INamedObject __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            INamedObject __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            INamedObject __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            INamedObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            INamedObject __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            INamedObject __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        END_INTERFACE
    } INamedObjectVtbl;

    interface INamedObject
    {
        CONST_VTBL struct INamedObjectVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INamedObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INamedObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INamedObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INamedObject_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INamedObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INamedObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INamedObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INamedObject_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INamedObject_INTERFACE_DEFINED__ */


#ifndef __IVersionAdminInfo_INTERFACE_DEFINED__
#define __IVersionAdminInfo_INTERFACE_DEFINED__

/* interface IVersionAdminInfo */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IVersionAdminInfo,0x6F4DD3F0,0x037B,0x11d1,0xB0,0x42,0x00,0xA0,0xC9,0x0F,0xEE,0x3A);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6F4DD3F0-037B-11d1-B042-00A0C90FEE3A")
    IVersionAdminInfo : public IRepositoryDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IVersionAdminInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IVersionAdminInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IVersionAdminInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IVersionAdminInfo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IVersionAdminInfo __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IVersionAdminInfo __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IVersionAdminInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IVersionAdminInfo __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IVersionAdminInfo __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        END_INTERFACE
    } IVersionAdminInfoVtbl;

    interface IVersionAdminInfo
    {
        CONST_VTBL struct IVersionAdminInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVersionAdminInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVersionAdminInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVersionAdminInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVersionAdminInfo_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IVersionAdminInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IVersionAdminInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IVersionAdminInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IVersionAdminInfo_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVersionAdminInfo_INTERFACE_DEFINED__ */


#ifndef __IVersionAdminInfo2_INTERFACE_DEFINED__
#define __IVersionAdminInfo2_INTERFACE_DEFINED__

/* interface IVersionAdminInfo2 */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IVersionAdminInfo2,0x054996DC,0x49B6,0x11d2,0x90,0x3B,0x00,0x00,0xF8,0x7A,0x3B,0x33);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("054996DC-49B6-11d2-903B-0000F87A3B33")
    IVersionAdminInfo2 : public IVersionAdminInfo
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IVersionAdminInfo2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IVersionAdminInfo2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IVersionAdminInfo2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IVersionAdminInfo2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IVersionAdminInfo2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IVersionAdminInfo2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IVersionAdminInfo2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IVersionAdminInfo2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IVersionAdminInfo2 __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        END_INTERFACE
    } IVersionAdminInfo2Vtbl;

    interface IVersionAdminInfo2
    {
        CONST_VTBL struct IVersionAdminInfo2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVersionAdminInfo2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVersionAdminInfo2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVersionAdminInfo2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVersionAdminInfo2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IVersionAdminInfo2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IVersionAdminInfo2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IVersionAdminInfo2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IVersionAdminInfo2_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVersionAdminInfo2_INTERFACE_DEFINED__ */


#ifndef __IReposQuery_INTERFACE_DEFINED__
#define __IReposQuery_INTERFACE_DEFINED__

/* interface IReposQuery */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IReposQuery,0x6C8C3FA9,0xC698,0x11d2,0xA8,0xF9,0x00,0xC0,0x4F,0x99,0x18,0x1C);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6C8C3FA9-C698-11d2-A8F9-00C04F99181C")
    IReposQuery : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCollection( 
            /* [in] */ BSTR Filter,
            /* [defaultvalue][in] */ long fFlags,
            /* [retval][out] */ IObjectCol2 __RPC_FAR *__RPC_FAR *ppObjCol) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IReposQueryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IReposQuery __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IReposQuery __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IReposQuery __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IReposQuery __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IReposQuery __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IReposQuery __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IReposQuery __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCollection )( 
            IReposQuery __RPC_FAR * This,
            /* [in] */ BSTR Filter,
            /* [defaultvalue][in] */ long fFlags,
            /* [retval][out] */ IObjectCol2 __RPC_FAR *__RPC_FAR *ppObjCol);
        
        END_INTERFACE
    } IReposQueryVtbl;

    interface IReposQuery
    {
        CONST_VTBL struct IReposQueryVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IReposQuery_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IReposQuery_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IReposQuery_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IReposQuery_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IReposQuery_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IReposQuery_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IReposQuery_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IReposQuery_GetCollection(This,Filter,fFlags,ppObjCol)	\
    (This)->lpVtbl -> GetCollection(This,Filter,fFlags,ppObjCol)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IReposQuery_GetCollection_Proxy( 
    IReposQuery __RPC_FAR * This,
    /* [in] */ BSTR Filter,
    /* [defaultvalue][in] */ long fFlags,
    /* [retval][out] */ IObjectCol2 __RPC_FAR *__RPC_FAR *ppObjCol);


void __RPC_STUB IReposQuery_GetCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IReposQuery_INTERFACE_DEFINED__ */


#ifndef __ITransientObjectCol_INTERFACE_DEFINED__
#define __ITransientObjectCol_INTERFACE_DEFINED__

/* interface ITransientObjectCol */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_ITransientObjectCol,0x57DD7430,0x3011,0x11d3,0x83,0xE3,0x00,0xC0,0x4F,0x6E,0xA6,0x48);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("57DD7430-3011-11d3-83E3-00C04F6EA648")
    ITransientObjectCol : public IObjectCol
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ IDispatch __RPC_FAR *pIReposObj) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ VARIANT sItem) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITransientObjectColVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITransientObjectCol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITransientObjectCol __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITransientObjectCol __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ITransientObjectCol __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ITransientObjectCol __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ITransientObjectCol __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ITransientObjectCol __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            ITransientObjectCol __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *piCount);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            ITransientObjectCol __RPC_FAR * This,
            /* [in] */ VARIANT sItem,
            /* [retval][out] */ IRepositoryObject __RPC_FAR *__RPC_FAR *ppIItem);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *_NewEnum )( 
            ITransientObjectCol __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppIEnum);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Refresh )( 
            ITransientObjectCol __RPC_FAR * This,
            /* [in] */ long iMilliseconds);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            ITransientObjectCol __RPC_FAR * This,
            /* [in] */ IDispatch __RPC_FAR *pIReposObj);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove )( 
            ITransientObjectCol __RPC_FAR * This,
            /* [in] */ VARIANT sItem);
        
        END_INTERFACE
    } ITransientObjectColVtbl;

    interface ITransientObjectCol
    {
        CONST_VTBL struct ITransientObjectColVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransientObjectCol_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITransientObjectCol_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITransientObjectCol_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITransientObjectCol_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ITransientObjectCol_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ITransientObjectCol_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ITransientObjectCol_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ITransientObjectCol_get_Count(This,piCount)	\
    (This)->lpVtbl -> get_Count(This,piCount)

#define ITransientObjectCol_get_Item(This,sItem,ppIItem)	\
    (This)->lpVtbl -> get_Item(This,sItem,ppIItem)

#define ITransientObjectCol__NewEnum(This,ppIEnum)	\
    (This)->lpVtbl -> _NewEnum(This,ppIEnum)

#define ITransientObjectCol_Refresh(This,iMilliseconds)	\
    (This)->lpVtbl -> Refresh(This,iMilliseconds)


#define ITransientObjectCol_Add(This,pIReposObj)	\
    (This)->lpVtbl -> Add(This,pIReposObj)

#define ITransientObjectCol_Remove(This,sItem)	\
    (This)->lpVtbl -> Remove(This,sItem)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE ITransientObjectCol_Add_Proxy( 
    ITransientObjectCol __RPC_FAR * This,
    /* [in] */ IDispatch __RPC_FAR *pIReposObj);


void __RPC_STUB ITransientObjectCol_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE ITransientObjectCol_Remove_Proxy( 
    ITransientObjectCol __RPC_FAR * This,
    /* [in] */ VARIANT sItem);


void __RPC_STUB ITransientObjectCol_Remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITransientObjectCol_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_RepositoryObject,0x6E2270FB,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#ifdef __cplusplus

class DECLSPEC_UUID("6E2270FB-F799-11cf-9227-00AA00A1EB95")
RepositoryObject;
#endif

DEFINE_GUID(CLSID_RepositoryObjectVersion,0x03881000,0xB119,0x11d0,0xB0,0x32,0x00,0xA0,0xC9,0x0F,0xEE,0x3A);

#ifdef __cplusplus

class DECLSPEC_UUID("03881000-B119-11d0-B032-00A0C90FEE3A")
RepositoryObjectVersion;
#endif

DEFINE_GUID(CLSID_Relationship,0x6E2270FC,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#ifdef __cplusplus

class DECLSPEC_UUID("6E2270FC-F799-11cf-9227-00AA00A1EB95")
Relationship;
#endif

DEFINE_GUID(CLSID_VersionedRelationship,0x4EE4D646,0x9C8C,0x11D0,0xBD,0xF4,0x00,0xC0,0x4F,0xC2,0xF5,0x1A);

#ifdef __cplusplus

class DECLSPEC_UUID("4EE4D646-9C8C-11D0-BDF4-00C04FC2F51A")
VersionedRelationship;
#endif

DEFINE_GUID(CLSID_ReposProperty,0x6E2270FD,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#ifdef __cplusplus

class DECLSPEC_UUID("6E2270FD-F799-11cf-9227-00AA00A1EB95")
ReposProperty;
#endif

DEFINE_GUID(CLSID_ReposProperties,0x6E2270FE,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#ifdef __cplusplus

class DECLSPEC_UUID("6E2270FE-F799-11cf-9227-00AA00A1EB95")
ReposProperties;
#endif

DEFINE_GUID(CLSID_RelationshipCol,0x6E2270FF,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#ifdef __cplusplus

class DECLSPEC_UUID("6E2270FF-F799-11cf-9227-00AA00A1EB95")
RelationshipCol;
#endif

DEFINE_GUID(CLSID_ObjectCol,0x6E227100,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#ifdef __cplusplus

class DECLSPEC_UUID("6E227100-F799-11cf-9227-00AA00A1EB95")
ObjectCol;
#endif

DEFINE_GUID(CLSID_VersionCol,0x77FB2100,0xBA7F,0x11d0,0xB0,0x34,0x00,0xA0,0xC9,0x0F,0xEE,0x3A);

#ifdef __cplusplus

class DECLSPEC_UUID("77FB2100-BA7F-11d0-B034-00A0C90FEE3A")
VersionCol;
#endif

DEFINE_GUID(CLSID_TransientObjectCol,0xB23F2710,0x2FDF,0x11d3,0x83,0xE3,0x00,0xC0,0x4F,0x6E,0xA6,0x48);

#ifdef __cplusplus

class DECLSPEC_UUID("B23F2710-2FDF-11d3-83E3-00C04F6EA648")
TransientObjectCol;
#endif

DEFINE_GUID(CLSID_Repository,0x6E227101,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#ifdef __cplusplus

class DECLSPEC_UUID("6E227101-F799-11cf-9227-00AA00A1EB95")
Repository;
#endif

#ifndef __IReposTypeInfo_INTERFACE_DEFINED__
#define __IReposTypeInfo_INTERFACE_DEFINED__

/* interface IReposTypeInfo */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IReposTypeInfo,0x6E227119,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E227119-F799-11cf-9227-00AA00A1EB95")
    IReposTypeInfo : public IRepositoryDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IReposTypeInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IReposTypeInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IReposTypeInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IReposTypeInfo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IReposTypeInfo __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IReposTypeInfo __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IReposTypeInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IReposTypeInfo __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IReposTypeInfo __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        END_INTERFACE
    } IReposTypeInfoVtbl;

    interface IReposTypeInfo
    {
        CONST_VTBL struct IReposTypeInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IReposTypeInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IReposTypeInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IReposTypeInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IReposTypeInfo_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IReposTypeInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IReposTypeInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IReposTypeInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IReposTypeInfo_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IReposTypeInfo_INTERFACE_DEFINED__ */


#ifndef __IInterfaceDef_INTERFACE_DEFINED__
#define __IInterfaceDef_INTERFACE_DEFINED__

/* interface IInterfaceDef */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IInterfaceDef,0x6E227103,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E227103-F799-11cf-9227-00AA00A1EB95")
    IInterfaceDef : public IRepositoryDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateRelationshipColDef( 
            /* [in] */ VARIANT sObjID,
            /* [in] */ BSTR Name,
            /* [in] */ long iDispID,
            /* [in] */ VARIANT_BOOL IsOrigin,
            /* [in] */ short fFlags,
            /* [in] */ IReposTypeInfo __RPC_FAR *pIRelshipDef,
            /* [retval][out] */ ICollectionDef __RPC_FAR *__RPC_FAR *ppIColDef) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreatePropertyDef( 
            /* [in] */ VARIANT sObjID,
            /* [in] */ BSTR Name,
            /* [in] */ long iDispID,
            /* [in] */ short CType,
            /* [retval][out] */ IPropertyDef __RPC_FAR *__RPC_FAR *ppIPropDef) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateMethodDef( 
            /* [in] */ VARIANT sObjID,
            /* [in] */ BSTR Name,
            /* [in] */ long iDispID,
            /* [retval][out] */ IInterfaceMember __RPC_FAR *__RPC_FAR *ppIMethodDef) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ObjectInstances( 
            /* [retval][out] */ IObjectCol __RPC_FAR *__RPC_FAR *ppIObjectCol) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceDefVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IInterfaceDef __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IInterfaceDef __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IInterfaceDef __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IInterfaceDef __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IInterfaceDef __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IInterfaceDef __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IInterfaceDef __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IInterfaceDef __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateRelationshipColDef )( 
            IInterfaceDef __RPC_FAR * This,
            /* [in] */ VARIANT sObjID,
            /* [in] */ BSTR Name,
            /* [in] */ long iDispID,
            /* [in] */ VARIANT_BOOL IsOrigin,
            /* [in] */ short fFlags,
            /* [in] */ IReposTypeInfo __RPC_FAR *pIRelshipDef,
            /* [retval][out] */ ICollectionDef __RPC_FAR *__RPC_FAR *ppIColDef);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreatePropertyDef )( 
            IInterfaceDef __RPC_FAR * This,
            /* [in] */ VARIANT sObjID,
            /* [in] */ BSTR Name,
            /* [in] */ long iDispID,
            /* [in] */ short CType,
            /* [retval][out] */ IPropertyDef __RPC_FAR *__RPC_FAR *ppIPropDef);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateMethodDef )( 
            IInterfaceDef __RPC_FAR * This,
            /* [in] */ VARIANT sObjID,
            /* [in] */ BSTR Name,
            /* [in] */ long iDispID,
            /* [retval][out] */ IInterfaceMember __RPC_FAR *__RPC_FAR *ppIMethodDef);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ObjectInstances )( 
            IInterfaceDef __RPC_FAR * This,
            /* [retval][out] */ IObjectCol __RPC_FAR *__RPC_FAR *ppIObjectCol);
        
        END_INTERFACE
    } IInterfaceDefVtbl;

    interface IInterfaceDef
    {
        CONST_VTBL struct IInterfaceDefVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceDef_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IInterfaceDef_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IInterfaceDef_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IInterfaceDef_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IInterfaceDef_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IInterfaceDef_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IInterfaceDef_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IInterfaceDef_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#define IInterfaceDef_CreateRelationshipColDef(This,sObjID,Name,iDispID,IsOrigin,fFlags,pIRelshipDef,ppIColDef)	\
    (This)->lpVtbl -> CreateRelationshipColDef(This,sObjID,Name,iDispID,IsOrigin,fFlags,pIRelshipDef,ppIColDef)

#define IInterfaceDef_CreatePropertyDef(This,sObjID,Name,iDispID,CType,ppIPropDef)	\
    (This)->lpVtbl -> CreatePropertyDef(This,sObjID,Name,iDispID,CType,ppIPropDef)

#define IInterfaceDef_CreateMethodDef(This,sObjID,Name,iDispID,ppIMethodDef)	\
    (This)->lpVtbl -> CreateMethodDef(This,sObjID,Name,iDispID,ppIMethodDef)

#define IInterfaceDef_ObjectInstances(This,ppIObjectCol)	\
    (This)->lpVtbl -> ObjectInstances(This,ppIObjectCol)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IInterfaceDef_CreateRelationshipColDef_Proxy( 
    IInterfaceDef __RPC_FAR * This,
    /* [in] */ VARIANT sObjID,
    /* [in] */ BSTR Name,
    /* [in] */ long iDispID,
    /* [in] */ VARIANT_BOOL IsOrigin,
    /* [in] */ short fFlags,
    /* [in] */ IReposTypeInfo __RPC_FAR *pIRelshipDef,
    /* [retval][out] */ ICollectionDef __RPC_FAR *__RPC_FAR *ppIColDef);


void __RPC_STUB IInterfaceDef_CreateRelationshipColDef_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IInterfaceDef_CreatePropertyDef_Proxy( 
    IInterfaceDef __RPC_FAR * This,
    /* [in] */ VARIANT sObjID,
    /* [in] */ BSTR Name,
    /* [in] */ long iDispID,
    /* [in] */ short CType,
    /* [retval][out] */ IPropertyDef __RPC_FAR *__RPC_FAR *ppIPropDef);


void __RPC_STUB IInterfaceDef_CreatePropertyDef_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IInterfaceDef_CreateMethodDef_Proxy( 
    IInterfaceDef __RPC_FAR * This,
    /* [in] */ VARIANT sObjID,
    /* [in] */ BSTR Name,
    /* [in] */ long iDispID,
    /* [retval][out] */ IInterfaceMember __RPC_FAR *__RPC_FAR *ppIMethodDef);


void __RPC_STUB IInterfaceDef_CreateMethodDef_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IInterfaceDef_ObjectInstances_Proxy( 
    IInterfaceDef __RPC_FAR * This,
    /* [retval][out] */ IObjectCol __RPC_FAR *__RPC_FAR *ppIObjectCol);


void __RPC_STUB IInterfaceDef_ObjectInstances_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IInterfaceDef_INTERFACE_DEFINED__ */


#ifndef __IInterfaceMember_INTERFACE_DEFINED__
#define __IInterfaceMember_INTERFACE_DEFINED__

/* interface IInterfaceMember */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IInterfaceMember,0x6E227116,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E227116-F799-11cf-9227-00AA00A1EB95")
    IInterfaceMember : public IRepositoryDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceMemberVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IInterfaceMember __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IInterfaceMember __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IInterfaceMember __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IInterfaceMember __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IInterfaceMember __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IInterfaceMember __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IInterfaceMember __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IInterfaceMember __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        END_INTERFACE
    } IInterfaceMemberVtbl;

    interface IInterfaceMember
    {
        CONST_VTBL struct IInterfaceMemberVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceMember_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IInterfaceMember_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IInterfaceMember_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IInterfaceMember_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IInterfaceMember_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IInterfaceMember_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IInterfaceMember_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IInterfaceMember_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceMember_INTERFACE_DEFINED__ */


#ifndef __IInterfaceMember2_INTERFACE_DEFINED__
#define __IInterfaceMember2_INTERFACE_DEFINED__

/* interface IInterfaceMember2 */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IInterfaceMember2,0x728C9B7C,0x57DB,0x11d2,0x97,0x9F,0x00,0xC0,0x4F,0xB6,0xDD,0x9A);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("728C9B7C-57DB-11d2-979F-00C04FB6DD9A")
    IInterfaceMember2 : public IInterfaceMember
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceMember2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IInterfaceMember2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IInterfaceMember2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IInterfaceMember2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IInterfaceMember2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IInterfaceMember2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IInterfaceMember2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IInterfaceMember2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IInterfaceMember2 __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        END_INTERFACE
    } IInterfaceMember2Vtbl;

    interface IInterfaceMember2
    {
        CONST_VTBL struct IInterfaceMember2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceMember2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IInterfaceMember2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IInterfaceMember2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IInterfaceMember2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IInterfaceMember2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IInterfaceMember2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IInterfaceMember2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IInterfaceMember2_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceMember2_INTERFACE_DEFINED__ */


#ifndef __IClassDef_INTERFACE_DEFINED__
#define __IClassDef_INTERFACE_DEFINED__

/* interface IClassDef */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IClassDef,0x6E227102,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E227102-F799-11cf-9227-00AA00A1EB95")
    IClassDef : public IRepositoryDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AddInterface( 
            /* [in] */ IInterfaceDef __RPC_FAR *pIInterfaceDef,
            /* [defaultvalue][in] */ BSTR Flags = L"") = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateInterfaceDef( 
            /* [in] */ VARIANT sObjID,
            /* [in] */ BSTR Name,
            /* [in] */ VARIANT sIID,
            /* [defaultvalue][in] */ IInterfaceDef __RPC_FAR *pIAncestor,
            /* [defaultvalue][in] */ BSTR Flags,
            /* [retval][out] */ IInterfaceDef __RPC_FAR *__RPC_FAR *ppIIfaceDef) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ObjectInstances( 
            /* [retval][out] */ IObjectCol __RPC_FAR *__RPC_FAR *ppIObjectCol) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClassDefVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IClassDef __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IClassDef __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IClassDef __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IClassDef __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IClassDef __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IClassDef __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IClassDef __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IClassDef __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddInterface )( 
            IClassDef __RPC_FAR * This,
            /* [in] */ IInterfaceDef __RPC_FAR *pIInterfaceDef,
            /* [defaultvalue][in] */ BSTR Flags);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateInterfaceDef )( 
            IClassDef __RPC_FAR * This,
            /* [in] */ VARIANT sObjID,
            /* [in] */ BSTR Name,
            /* [in] */ VARIANT sIID,
            /* [defaultvalue][in] */ IInterfaceDef __RPC_FAR *pIAncestor,
            /* [defaultvalue][in] */ BSTR Flags,
            /* [retval][out] */ IInterfaceDef __RPC_FAR *__RPC_FAR *ppIIfaceDef);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ObjectInstances )( 
            IClassDef __RPC_FAR * This,
            /* [retval][out] */ IObjectCol __RPC_FAR *__RPC_FAR *ppIObjectCol);
        
        END_INTERFACE
    } IClassDefVtbl;

    interface IClassDef
    {
        CONST_VTBL struct IClassDefVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClassDef_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClassDef_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClassDef_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClassDef_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IClassDef_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IClassDef_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IClassDef_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IClassDef_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#define IClassDef_AddInterface(This,pIInterfaceDef,Flags)	\
    (This)->lpVtbl -> AddInterface(This,pIInterfaceDef,Flags)

#define IClassDef_CreateInterfaceDef(This,sObjID,Name,sIID,pIAncestor,Flags,ppIIfaceDef)	\
    (This)->lpVtbl -> CreateInterfaceDef(This,sObjID,Name,sIID,pIAncestor,Flags,ppIIfaceDef)

#define IClassDef_ObjectInstances(This,ppIObjectCol)	\
    (This)->lpVtbl -> ObjectInstances(This,ppIObjectCol)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IClassDef_AddInterface_Proxy( 
    IClassDef __RPC_FAR * This,
    /* [in] */ IInterfaceDef __RPC_FAR *pIInterfaceDef,
    /* [defaultvalue][in] */ BSTR Flags);


void __RPC_STUB IClassDef_AddInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IClassDef_CreateInterfaceDef_Proxy( 
    IClassDef __RPC_FAR * This,
    /* [in] */ VARIANT sObjID,
    /* [in] */ BSTR Name,
    /* [in] */ VARIANT sIID,
    /* [defaultvalue][in] */ IInterfaceDef __RPC_FAR *pIAncestor,
    /* [defaultvalue][in] */ BSTR Flags,
    /* [retval][out] */ IInterfaceDef __RPC_FAR *__RPC_FAR *ppIIfaceDef);


void __RPC_STUB IClassDef_CreateInterfaceDef_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IClassDef_ObjectInstances_Proxy( 
    IClassDef __RPC_FAR * This,
    /* [retval][out] */ IObjectCol __RPC_FAR *__RPC_FAR *ppIObjectCol);


void __RPC_STUB IClassDef_ObjectInstances_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClassDef_INTERFACE_DEFINED__ */


#ifndef __ICollectionDef_INTERFACE_DEFINED__
#define __ICollectionDef_INTERFACE_DEFINED__

/* interface ICollectionDef */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_ICollectionDef,0x6E227106,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E227106-F799-11cf-9227-00AA00A1EB95")
    ICollectionDef : public IRepositoryDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct ICollectionDefVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ICollectionDef __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ICollectionDef __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ICollectionDef __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ICollectionDef __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ICollectionDef __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ICollectionDef __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ICollectionDef __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            ICollectionDef __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        END_INTERFACE
    } ICollectionDefVtbl;

    interface ICollectionDef
    {
        CONST_VTBL struct ICollectionDefVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICollectionDef_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICollectionDef_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICollectionDef_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICollectionDef_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICollectionDef_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICollectionDef_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICollectionDef_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICollectionDef_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICollectionDef_INTERFACE_DEFINED__ */


#ifndef __IPropertyDef_INTERFACE_DEFINED__
#define __IPropertyDef_INTERFACE_DEFINED__

/* interface IPropertyDef */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IPropertyDef,0x6E227107,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E227107-F799-11cf-9227-00AA00A1EB95")
    IPropertyDef : public IRepositoryDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IPropertyDefVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPropertyDef __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPropertyDef __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPropertyDef __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IPropertyDef __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IPropertyDef __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IPropertyDef __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IPropertyDef __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IPropertyDef __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        END_INTERFACE
    } IPropertyDefVtbl;

    interface IPropertyDef
    {
        CONST_VTBL struct IPropertyDefVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPropertyDef_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPropertyDef_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPropertyDef_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPropertyDef_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPropertyDef_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPropertyDef_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPropertyDef_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPropertyDef_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPropertyDef_INTERFACE_DEFINED__ */


#ifndef __IPropertyDef2_INTERFACE_DEFINED__
#define __IPropertyDef2_INTERFACE_DEFINED__

/* interface IPropertyDef2 */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IPropertyDef2,0x6E227107,0xF799,0x11cf,0x92,0x27,0xFE,0xAA,0x00,0xA1,0xEB,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E227107-F799-11cf-9227-FEAA00A1EB95")
    IPropertyDef2 : public IPropertyDef
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IPropertyDef2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPropertyDef2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPropertyDef2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPropertyDef2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IPropertyDef2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IPropertyDef2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IPropertyDef2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IPropertyDef2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IPropertyDef2 __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        END_INTERFACE
    } IPropertyDef2Vtbl;

    interface IPropertyDef2
    {
        CONST_VTBL struct IPropertyDef2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPropertyDef2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPropertyDef2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPropertyDef2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPropertyDef2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPropertyDef2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPropertyDef2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPropertyDef2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPropertyDef2_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPropertyDef2_INTERFACE_DEFINED__ */


#ifndef __IEnumerationDef_INTERFACE_DEFINED__
#define __IEnumerationDef_INTERFACE_DEFINED__

/* interface IEnumerationDef */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IEnumerationDef,0xE57290F0,0x2A5C,0x11d3,0x83,0xE0,0x00,0xC0,0x4F,0x6E,0xA6,0x48);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E57290F0-2A5C-11d3-83E0-00C04F6EA648")
    IEnumerationDef : public IRepositoryDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IEnumerationDefVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEnumerationDef __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEnumerationDef __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEnumerationDef __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IEnumerationDef __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IEnumerationDef __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IEnumerationDef __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IEnumerationDef __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IEnumerationDef __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        END_INTERFACE
    } IEnumerationDefVtbl;

    interface IEnumerationDef
    {
        CONST_VTBL struct IEnumerationDefVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumerationDef_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumerationDef_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumerationDef_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumerationDef_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IEnumerationDef_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IEnumerationDef_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IEnumerationDef_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IEnumerationDef_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumerationDef_INTERFACE_DEFINED__ */


#ifndef __IEnumerationValueDef_INTERFACE_DEFINED__
#define __IEnumerationValueDef_INTERFACE_DEFINED__

/* interface IEnumerationValueDef */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IEnumerationValueDef,0xE57290F1,0x2A5C,0x11d3,0x83,0xE0,0x00,0xC0,0x4F,0x6E,0xA6,0x48);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E57290F1-2A5C-11d3-83E0-00C04F6EA648")
    IEnumerationValueDef : public IRepositoryDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IEnumerationValueDefVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEnumerationValueDef __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEnumerationValueDef __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEnumerationValueDef __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IEnumerationValueDef __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IEnumerationValueDef __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IEnumerationValueDef __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IEnumerationValueDef __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IEnumerationValueDef __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        END_INTERFACE
    } IEnumerationValueDefVtbl;

    interface IEnumerationValueDef
    {
        CONST_VTBL struct IEnumerationValueDefVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumerationValueDef_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumerationValueDef_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumerationValueDef_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumerationValueDef_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IEnumerationValueDef_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IEnumerationValueDef_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IEnumerationValueDef_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IEnumerationValueDef_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumerationValueDef_INTERFACE_DEFINED__ */


#ifndef __IViewClassDef_INTERFACE_DEFINED__
#define __IViewClassDef_INTERFACE_DEFINED__

/* interface IViewClassDef */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IViewClassDef,0x47ACBC68,0x2A7E,0x11d3,0xA8,0xD2,0x00,0xC0,0x4F,0xC2,0xF8,0x97);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("47ACBC68-2A7E-11d3-A8D2-00C04FC2F897")
    IViewClassDef : public IRepositoryDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IViewClassDefVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IViewClassDef __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IViewClassDef __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IViewClassDef __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IViewClassDef __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IViewClassDef __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IViewClassDef __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IViewClassDef __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IViewClassDef __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        END_INTERFACE
    } IViewClassDefVtbl;

    interface IViewClassDef
    {
        CONST_VTBL struct IViewClassDefVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IViewClassDef_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IViewClassDef_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IViewClassDef_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IViewClassDef_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IViewClassDef_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IViewClassDef_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IViewClassDef_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IViewClassDef_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IViewClassDef_INTERFACE_DEFINED__ */


#ifndef __IInterfaceDef2_INTERFACE_DEFINED__
#define __IInterfaceDef2_INTERFACE_DEFINED__

/* interface IInterfaceDef2 */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IInterfaceDef2,0x2A4BEFEA,0x5C9D,0x11d2,0xAA,0x8E,0x00,0xC0,0x4F,0x99,0x18,0x1C);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2A4BEFEA-5C9D-11d2-AA8E-00C04F99181C")
    IInterfaceDef2 : public IInterfaceDef
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateAlias( 
            /* [in] */ VARIANT sObjID,
            /* [in] */ BSTR Name,
            /* [in] */ long iDispID,
            /* [in] */ IInterfaceMember __RPC_FAR *pBase,
            /* [retval][out] */ IInterfaceMember2 __RPC_FAR *__RPC_FAR *ppAlias) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceDef2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IInterfaceDef2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IInterfaceDef2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IInterfaceDef2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IInterfaceDef2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IInterfaceDef2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IInterfaceDef2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IInterfaceDef2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IInterfaceDef2 __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateRelationshipColDef )( 
            IInterfaceDef2 __RPC_FAR * This,
            /* [in] */ VARIANT sObjID,
            /* [in] */ BSTR Name,
            /* [in] */ long iDispID,
            /* [in] */ VARIANT_BOOL IsOrigin,
            /* [in] */ short fFlags,
            /* [in] */ IReposTypeInfo __RPC_FAR *pIRelshipDef,
            /* [retval][out] */ ICollectionDef __RPC_FAR *__RPC_FAR *ppIColDef);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreatePropertyDef )( 
            IInterfaceDef2 __RPC_FAR * This,
            /* [in] */ VARIANT sObjID,
            /* [in] */ BSTR Name,
            /* [in] */ long iDispID,
            /* [in] */ short CType,
            /* [retval][out] */ IPropertyDef __RPC_FAR *__RPC_FAR *ppIPropDef);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateMethodDef )( 
            IInterfaceDef2 __RPC_FAR * This,
            /* [in] */ VARIANT sObjID,
            /* [in] */ BSTR Name,
            /* [in] */ long iDispID,
            /* [retval][out] */ IInterfaceMember __RPC_FAR *__RPC_FAR *ppIMethodDef);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ObjectInstances )( 
            IInterfaceDef2 __RPC_FAR * This,
            /* [retval][out] */ IObjectCol __RPC_FAR *__RPC_FAR *ppIObjectCol);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateAlias )( 
            IInterfaceDef2 __RPC_FAR * This,
            /* [in] */ VARIANT sObjID,
            /* [in] */ BSTR Name,
            /* [in] */ long iDispID,
            /* [in] */ IInterfaceMember __RPC_FAR *pBase,
            /* [retval][out] */ IInterfaceMember2 __RPC_FAR *__RPC_FAR *ppAlias);
        
        END_INTERFACE
    } IInterfaceDef2Vtbl;

    interface IInterfaceDef2
    {
        CONST_VTBL struct IInterfaceDef2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceDef2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IInterfaceDef2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IInterfaceDef2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IInterfaceDef2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IInterfaceDef2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IInterfaceDef2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IInterfaceDef2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IInterfaceDef2_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#define IInterfaceDef2_CreateRelationshipColDef(This,sObjID,Name,iDispID,IsOrigin,fFlags,pIRelshipDef,ppIColDef)	\
    (This)->lpVtbl -> CreateRelationshipColDef(This,sObjID,Name,iDispID,IsOrigin,fFlags,pIRelshipDef,ppIColDef)

#define IInterfaceDef2_CreatePropertyDef(This,sObjID,Name,iDispID,CType,ppIPropDef)	\
    (This)->lpVtbl -> CreatePropertyDef(This,sObjID,Name,iDispID,CType,ppIPropDef)

#define IInterfaceDef2_CreateMethodDef(This,sObjID,Name,iDispID,ppIMethodDef)	\
    (This)->lpVtbl -> CreateMethodDef(This,sObjID,Name,iDispID,ppIMethodDef)

#define IInterfaceDef2_ObjectInstances(This,ppIObjectCol)	\
    (This)->lpVtbl -> ObjectInstances(This,ppIObjectCol)


#define IInterfaceDef2_CreateAlias(This,sObjID,Name,iDispID,pBase,ppAlias)	\
    (This)->lpVtbl -> CreateAlias(This,sObjID,Name,iDispID,pBase,ppAlias)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IInterfaceDef2_CreateAlias_Proxy( 
    IInterfaceDef2 __RPC_FAR * This,
    /* [in] */ VARIANT sObjID,
    /* [in] */ BSTR Name,
    /* [in] */ long iDispID,
    /* [in] */ IInterfaceMember __RPC_FAR *pBase,
    /* [retval][out] */ IInterfaceMember2 __RPC_FAR *__RPC_FAR *ppAlias);


void __RPC_STUB IInterfaceDef2_CreateAlias_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IInterfaceDef2_INTERFACE_DEFINED__ */


#ifndef __IViewInterfaceDef_INTERFACE_DEFINED__
#define __IViewInterfaceDef_INTERFACE_DEFINED__

/* interface IViewInterfaceDef */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IViewInterfaceDef,0x95619A60,0x2903,0x11d3,0xA8,0xD1,0x00,0xC0,0x4F,0xC2,0xF8,0x97);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("95619A60-2903-11d3-A8D1-00C04FC2F897")
    IViewInterfaceDef : public IRepositoryDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IViewInterfaceDefVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IViewInterfaceDef __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IViewInterfaceDef __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IViewInterfaceDef __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IViewInterfaceDef __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IViewInterfaceDef __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IViewInterfaceDef __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IViewInterfaceDef __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IViewInterfaceDef __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        END_INTERFACE
    } IViewInterfaceDefVtbl;

    interface IViewInterfaceDef
    {
        CONST_VTBL struct IViewInterfaceDefVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IViewInterfaceDef_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IViewInterfaceDef_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IViewInterfaceDef_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IViewInterfaceDef_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IViewInterfaceDef_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IViewInterfaceDef_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IViewInterfaceDef_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IViewInterfaceDef_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IViewInterfaceDef_INTERFACE_DEFINED__ */


#ifndef __IViewPropertyDef_INTERFACE_DEFINED__
#define __IViewPropertyDef_INTERFACE_DEFINED__

/* interface IViewPropertyDef */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IViewPropertyDef,0x95619A62,0x2903,0x11d3,0xA8,0xD1,0x00,0xC0,0x4F,0xC2,0xF8,0x97);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("95619A62-2903-11d3-A8D1-00C04FC2F897")
    IViewPropertyDef : public IRepositoryDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IViewPropertyDefVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IViewPropertyDef __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IViewPropertyDef __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IViewPropertyDef __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IViewPropertyDef __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IViewPropertyDef __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IViewPropertyDef __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IViewPropertyDef __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IViewPropertyDef __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        END_INTERFACE
    } IViewPropertyDefVtbl;

    interface IViewPropertyDef
    {
        CONST_VTBL struct IViewPropertyDefVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IViewPropertyDef_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IViewPropertyDef_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IViewPropertyDef_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IViewPropertyDef_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IViewPropertyDef_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IViewPropertyDef_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IViewPropertyDef_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IViewPropertyDef_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IViewPropertyDef_INTERFACE_DEFINED__ */


#ifndef __IReposTypeLib_INTERFACE_DEFINED__
#define __IReposTypeLib_INTERFACE_DEFINED__

/* interface IReposTypeLib */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IReposTypeLib,0x6E227104,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E227104-F799-11cf-9227-00AA00A1EB95")
    IReposTypeLib : public IRepositoryDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateClassDef( 
            /* [in] */ VARIANT sObjID,
            /* [in] */ BSTR Name,
            /* [in] */ VARIANT sClsID,
            /* [retval][out] */ IClassDef __RPC_FAR *__RPC_FAR *ppIClassDef) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateInterfaceDef( 
            /* [in] */ VARIANT sObjID,
            /* [in] */ BSTR Name,
            /* [in] */ VARIANT sIID,
            /* [defaultvalue][in] */ IInterfaceDef __RPC_FAR *pIAncestor,
            /* [retval][out] */ IInterfaceDef __RPC_FAR *__RPC_FAR *ppIIfaceDef) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateRelationshipDef( 
            /* [in] */ VARIANT ObjID,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IReposTypeInfo __RPC_FAR *__RPC_FAR *ppIRelshipDef) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IReposTypeLibVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IReposTypeLib __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IReposTypeLib __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IReposTypeLib __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IReposTypeLib __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IReposTypeLib __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IReposTypeLib __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IReposTypeLib __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IReposTypeLib __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateClassDef )( 
            IReposTypeLib __RPC_FAR * This,
            /* [in] */ VARIANT sObjID,
            /* [in] */ BSTR Name,
            /* [in] */ VARIANT sClsID,
            /* [retval][out] */ IClassDef __RPC_FAR *__RPC_FAR *ppIClassDef);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateInterfaceDef )( 
            IReposTypeLib __RPC_FAR * This,
            /* [in] */ VARIANT sObjID,
            /* [in] */ BSTR Name,
            /* [in] */ VARIANT sIID,
            /* [defaultvalue][in] */ IInterfaceDef __RPC_FAR *pIAncestor,
            /* [retval][out] */ IInterfaceDef __RPC_FAR *__RPC_FAR *ppIIfaceDef);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateRelationshipDef )( 
            IReposTypeLib __RPC_FAR * This,
            /* [in] */ VARIANT ObjID,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IReposTypeInfo __RPC_FAR *__RPC_FAR *ppIRelshipDef);
        
        END_INTERFACE
    } IReposTypeLibVtbl;

    interface IReposTypeLib
    {
        CONST_VTBL struct IReposTypeLibVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IReposTypeLib_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IReposTypeLib_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IReposTypeLib_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IReposTypeLib_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IReposTypeLib_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IReposTypeLib_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IReposTypeLib_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IReposTypeLib_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#define IReposTypeLib_CreateClassDef(This,sObjID,Name,sClsID,ppIClassDef)	\
    (This)->lpVtbl -> CreateClassDef(This,sObjID,Name,sClsID,ppIClassDef)

#define IReposTypeLib_CreateInterfaceDef(This,sObjID,Name,sIID,pIAncestor,ppIIfaceDef)	\
    (This)->lpVtbl -> CreateInterfaceDef(This,sObjID,Name,sIID,pIAncestor,ppIIfaceDef)

#define IReposTypeLib_CreateRelationshipDef(This,ObjID,Name,ppIRelshipDef)	\
    (This)->lpVtbl -> CreateRelationshipDef(This,ObjID,Name,ppIRelshipDef)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IReposTypeLib_CreateClassDef_Proxy( 
    IReposTypeLib __RPC_FAR * This,
    /* [in] */ VARIANT sObjID,
    /* [in] */ BSTR Name,
    /* [in] */ VARIANT sClsID,
    /* [retval][out] */ IClassDef __RPC_FAR *__RPC_FAR *ppIClassDef);


void __RPC_STUB IReposTypeLib_CreateClassDef_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IReposTypeLib_CreateInterfaceDef_Proxy( 
    IReposTypeLib __RPC_FAR * This,
    /* [in] */ VARIANT sObjID,
    /* [in] */ BSTR Name,
    /* [in] */ VARIANT sIID,
    /* [defaultvalue][in] */ IInterfaceDef __RPC_FAR *pIAncestor,
    /* [retval][out] */ IInterfaceDef __RPC_FAR *__RPC_FAR *ppIIfaceDef);


void __RPC_STUB IReposTypeLib_CreateInterfaceDef_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IReposTypeLib_CreateRelationshipDef_Proxy( 
    IReposTypeLib __RPC_FAR * This,
    /* [in] */ VARIANT ObjID,
    /* [in] */ BSTR Name,
    /* [retval][out] */ IReposTypeInfo __RPC_FAR *__RPC_FAR *ppIRelshipDef);


void __RPC_STUB IReposTypeLib_CreateRelationshipDef_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IReposTypeLib_INTERFACE_DEFINED__ */


#ifndef __IReposTypeLib2_INTERFACE_DEFINED__
#define __IReposTypeLib2_INTERFACE_DEFINED__

/* interface IReposTypeLib2 */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IReposTypeLib2,0x9FB83CC0,0xB259,0x11d2,0x83,0xB1,0x00,0xC0,0x4F,0x6E,0xA6,0x48);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9FB83CC0-B259-11d2-83B1-00C04F6EA648")
    IReposTypeLib2 : public IReposTypeLib
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IReposTypeLib2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IReposTypeLib2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IReposTypeLib2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IReposTypeLib2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IReposTypeLib2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IReposTypeLib2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IReposTypeLib2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IReposTypeLib2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IReposTypeLib2 __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateClassDef )( 
            IReposTypeLib2 __RPC_FAR * This,
            /* [in] */ VARIANT sObjID,
            /* [in] */ BSTR Name,
            /* [in] */ VARIANT sClsID,
            /* [retval][out] */ IClassDef __RPC_FAR *__RPC_FAR *ppIClassDef);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateInterfaceDef )( 
            IReposTypeLib2 __RPC_FAR * This,
            /* [in] */ VARIANT sObjID,
            /* [in] */ BSTR Name,
            /* [in] */ VARIANT sIID,
            /* [defaultvalue][in] */ IInterfaceDef __RPC_FAR *pIAncestor,
            /* [retval][out] */ IInterfaceDef __RPC_FAR *__RPC_FAR *ppIIfaceDef);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateRelationshipDef )( 
            IReposTypeLib2 __RPC_FAR * This,
            /* [in] */ VARIANT ObjID,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IReposTypeInfo __RPC_FAR *__RPC_FAR *ppIRelshipDef);
        
        END_INTERFACE
    } IReposTypeLib2Vtbl;

    interface IReposTypeLib2
    {
        CONST_VTBL struct IReposTypeLib2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IReposTypeLib2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IReposTypeLib2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IReposTypeLib2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IReposTypeLib2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IReposTypeLib2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IReposTypeLib2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IReposTypeLib2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IReposTypeLib2_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#define IReposTypeLib2_CreateClassDef(This,sObjID,Name,sClsID,ppIClassDef)	\
    (This)->lpVtbl -> CreateClassDef(This,sObjID,Name,sClsID,ppIClassDef)

#define IReposTypeLib2_CreateInterfaceDef(This,sObjID,Name,sIID,pIAncestor,ppIIfaceDef)	\
    (This)->lpVtbl -> CreateInterfaceDef(This,sObjID,Name,sIID,pIAncestor,ppIIfaceDef)

#define IReposTypeLib2_CreateRelationshipDef(This,ObjID,Name,ppIRelshipDef)	\
    (This)->lpVtbl -> CreateRelationshipDef(This,ObjID,Name,ppIRelshipDef)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IReposTypeLib2_INTERFACE_DEFINED__ */


#ifndef __IViewRelationshipDef_INTERFACE_DEFINED__
#define __IViewRelationshipDef_INTERFACE_DEFINED__

/* interface IViewRelationshipDef */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IViewRelationshipDef,0x95619A61,0x2903,0x11d3,0xA8,0xD1,0x00,0xC0,0x4F,0xC2,0xF8,0x97);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("95619A61-2903-11d3-A8D1-00C04FC2F897")
    IViewRelationshipDef : public IRepositoryDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IViewRelationshipDefVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IViewRelationshipDef __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IViewRelationshipDef __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IViewRelationshipDef __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IViewRelationshipDef __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IViewRelationshipDef __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IViewRelationshipDef __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IViewRelationshipDef __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IViewRelationshipDef __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        END_INTERFACE
    } IViewRelationshipDefVtbl;

    interface IViewRelationshipDef
    {
        CONST_VTBL struct IViewRelationshipDefVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IViewRelationshipDef_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IViewRelationshipDef_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IViewRelationshipDef_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IViewRelationshipDef_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IViewRelationshipDef_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IViewRelationshipDef_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IViewRelationshipDef_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IViewRelationshipDef_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IViewRelationshipDef_INTERFACE_DEFINED__ */


#ifndef __IReposTypeInfo2_INTERFACE_DEFINED__
#define __IReposTypeInfo2_INTERFACE_DEFINED__

/* interface IReposTypeInfo2 */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IReposTypeInfo2,0xD5454E93,0x348C,0x11d3,0xA9,0x15,0x00,0xC0,0x4F,0x99,0x18,0x1C);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D5454E93-348C-11d3-A915-00C04F99181C")
    IReposTypeInfo2 : public IReposTypeInfo
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IReposTypeInfo2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IReposTypeInfo2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IReposTypeInfo2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IReposTypeInfo2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IReposTypeInfo2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IReposTypeInfo2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IReposTypeInfo2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IReposTypeInfo2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IReposTypeInfo2 __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        END_INTERFACE
    } IReposTypeInfo2Vtbl;

    interface IReposTypeInfo2
    {
        CONST_VTBL struct IReposTypeInfo2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IReposTypeInfo2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IReposTypeInfo2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IReposTypeInfo2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IReposTypeInfo2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IReposTypeInfo2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IReposTypeInfo2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IReposTypeInfo2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IReposTypeInfo2_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IReposTypeInfo2_INTERFACE_DEFINED__ */


#ifndef __IManageReposTypeLib_INTERFACE_DEFINED__
#define __IManageReposTypeLib_INTERFACE_DEFINED__

/* interface IManageReposTypeLib */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IManageReposTypeLib,0x6E227105,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E227105-F799-11cf-9227-00AA00A1EB95")
    IManageReposTypeLib : public IRepositoryDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateTypeLib( 
            /* [in] */ VARIANT sObjID,
            /* [in] */ BSTR Name,
            /* [in] */ VARIANT TypeLibID,
            /* [retval][out] */ IReposTypeLib __RPC_FAR *__RPC_FAR *ppITypeLib) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IManageReposTypeLibVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IManageReposTypeLib __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IManageReposTypeLib __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IManageReposTypeLib __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IManageReposTypeLib __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IManageReposTypeLib __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IManageReposTypeLib __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IManageReposTypeLib __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IManageReposTypeLib __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateTypeLib )( 
            IManageReposTypeLib __RPC_FAR * This,
            /* [in] */ VARIANT sObjID,
            /* [in] */ BSTR Name,
            /* [in] */ VARIANT TypeLibID,
            /* [retval][out] */ IReposTypeLib __RPC_FAR *__RPC_FAR *ppITypeLib);
        
        END_INTERFACE
    } IManageReposTypeLibVtbl;

    interface IManageReposTypeLib
    {
        CONST_VTBL struct IManageReposTypeLibVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IManageReposTypeLib_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IManageReposTypeLib_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IManageReposTypeLib_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IManageReposTypeLib_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IManageReposTypeLib_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IManageReposTypeLib_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IManageReposTypeLib_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IManageReposTypeLib_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#define IManageReposTypeLib_CreateTypeLib(This,sObjID,Name,TypeLibID,ppITypeLib)	\
    (This)->lpVtbl -> CreateTypeLib(This,sObjID,Name,TypeLibID,ppITypeLib)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IManageReposTypeLib_CreateTypeLib_Proxy( 
    IManageReposTypeLib __RPC_FAR * This,
    /* [in] */ VARIANT sObjID,
    /* [in] */ BSTR Name,
    /* [in] */ VARIANT TypeLibID,
    /* [retval][out] */ IReposTypeLib __RPC_FAR *__RPC_FAR *ppITypeLib);


void __RPC_STUB IManageReposTypeLib_CreateTypeLib_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IManageReposTypeLib_INTERFACE_DEFINED__ */


#ifndef __IReposRoot_INTERFACE_DEFINED__
#define __IReposRoot_INTERFACE_DEFINED__

/* interface IReposRoot */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IReposRoot,0x6E227117,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E227117-F799-11cf-9227-00AA00A1EB95")
    IReposRoot : public IRepositoryDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IReposRootVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IReposRoot __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IReposRoot __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IReposRoot __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IReposRoot __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IReposRoot __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IReposRoot __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IReposRoot __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IReposRoot __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        END_INTERFACE
    } IReposRootVtbl;

    interface IReposRoot
    {
        CONST_VTBL struct IReposRootVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IReposRoot_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IReposRoot_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IReposRoot_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IReposRoot_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IReposRoot_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IReposRoot_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IReposRoot_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IReposRoot_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IReposRoot_INTERFACE_DEFINED__ */


#ifndef __IParameterDef_INTERFACE_DEFINED__
#define __IParameterDef_INTERFACE_DEFINED__

/* interface IParameterDef */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IParameterDef,0x65E8656D,0x5F98,0x11d2,0x90,0x3B,0x00,0x00,0xF8,0x7A,0x3B,0x33);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("65E8656D-5F98-11d2-903B-0000F87A3B33")
    IParameterDef : public IRepositoryDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IParameterDefVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IParameterDef __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IParameterDef __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IParameterDef __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IParameterDef __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IParameterDef __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IParameterDef __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IParameterDef __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IParameterDef __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        END_INTERFACE
    } IParameterDefVtbl;

    interface IParameterDef
    {
        CONST_VTBL struct IParameterDefVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IParameterDef_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IParameterDef_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IParameterDef_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IParameterDef_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IParameterDef_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IParameterDef_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IParameterDef_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IParameterDef_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IParameterDef_INTERFACE_DEFINED__ */


#ifndef __IMethodDef_INTERFACE_DEFINED__
#define __IMethodDef_INTERFACE_DEFINED__

/* interface IMethodDef */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IMethodDef,0x65E8657B,0x5F98,0x11d2,0x90,0x3B,0x00,0x00,0xF8,0x7A,0x3B,0x33);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("65E8657B-5F98-11d2-903B-0000F87A3B33")
    IMethodDef : public IRepositoryDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateParameterDef( 
            /* [in] */ VARIANT sObjID,
            /* [in] */ BSTR Name,
            /* [in] */ long Type,
            /* [in] */ long Flags,
            /* [in] */ BSTR Description,
            /* [in] */ BSTR Default,
            /* [retval][out] */ IParameterDef __RPC_FAR *__RPC_FAR *ppIParamDef) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMethodDefVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IMethodDef __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IMethodDef __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IMethodDef __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IMethodDef __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IMethodDef __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IMethodDef __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IMethodDef __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IMethodDef __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateParameterDef )( 
            IMethodDef __RPC_FAR * This,
            /* [in] */ VARIANT sObjID,
            /* [in] */ BSTR Name,
            /* [in] */ long Type,
            /* [in] */ long Flags,
            /* [in] */ BSTR Description,
            /* [in] */ BSTR Default,
            /* [retval][out] */ IParameterDef __RPC_FAR *__RPC_FAR *ppIParamDef);
        
        END_INTERFACE
    } IMethodDefVtbl;

    interface IMethodDef
    {
        CONST_VTBL struct IMethodDefVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMethodDef_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMethodDef_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMethodDef_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMethodDef_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IMethodDef_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IMethodDef_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IMethodDef_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IMethodDef_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#define IMethodDef_CreateParameterDef(This,sObjID,Name,Type,Flags,Description,Default,ppIParamDef)	\
    (This)->lpVtbl -> CreateParameterDef(This,sObjID,Name,Type,Flags,Description,Default,ppIParamDef)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IMethodDef_CreateParameterDef_Proxy( 
    IMethodDef __RPC_FAR * This,
    /* [in] */ VARIANT sObjID,
    /* [in] */ BSTR Name,
    /* [in] */ long Type,
    /* [in] */ long Flags,
    /* [in] */ BSTR Description,
    /* [in] */ BSTR Default,
    /* [retval][out] */ IParameterDef __RPC_FAR *__RPC_FAR *ppIParamDef);


void __RPC_STUB IMethodDef_CreateParameterDef_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMethodDef_INTERFACE_DEFINED__ */


#ifndef __IScriptDef_INTERFACE_DEFINED__
#define __IScriptDef_INTERFACE_DEFINED__

/* interface IScriptDef */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IScriptDef,0xD675E22A,0xCAE9,0x11d2,0xAF,0x7B,0x00,0xC0,0x4F,0x99,0x17,0x9F);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D675E22A-CAE9-11d2-AF7B-00C04F99179F")
    IScriptDef : public IRepositoryDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ValidateScript( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IScriptDefVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IScriptDef __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IScriptDef __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IScriptDef __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IScriptDef __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IScriptDef __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IScriptDef __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IScriptDef __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IScriptDef __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ValidateScript )( 
            IScriptDef __RPC_FAR * This);
        
        END_INTERFACE
    } IScriptDefVtbl;

    interface IScriptDef
    {
        CONST_VTBL struct IScriptDefVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScriptDef_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IScriptDef_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IScriptDef_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IScriptDef_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IScriptDef_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IScriptDef_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IScriptDef_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IScriptDef_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#define IScriptDef_ValidateScript(This)	\
    (This)->lpVtbl -> ValidateScript(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IScriptDef_ValidateScript_Proxy( 
    IScriptDef __RPC_FAR * This);


void __RPC_STUB IScriptDef_ValidateScript_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IScriptDef_INTERFACE_DEFINED__ */


#ifndef __IClassDef2_INTERFACE_DEFINED__
#define __IClassDef2_INTERFACE_DEFINED__

/* interface IClassDef2 */
/* [object][dual][helpstring][uuid] */ 


DEFINE_GUID(IID_IClassDef2,0xC27DDB7B,0xCB5B,0x11d2,0xAF,0x7B,0x00,0xC0,0x4F,0x99,0x17,0x9F);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C27DDB7B-CB5B-11d2-AF7B-00C04F99179F")
    IClassDef2 : public IClassDef
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IClassDef2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IClassDef2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IClassDef2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IClassDef2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IClassDef2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IClassDef2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IClassDef2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IClassDef2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Properties )( 
            IClassDef2 __RPC_FAR * This,
            /* [retval][out] */ IReposProperties __RPC_FAR *__RPC_FAR *ppIProps);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddInterface )( 
            IClassDef2 __RPC_FAR * This,
            /* [in] */ IInterfaceDef __RPC_FAR *pIInterfaceDef,
            /* [defaultvalue][in] */ BSTR Flags);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateInterfaceDef )( 
            IClassDef2 __RPC_FAR * This,
            /* [in] */ VARIANT sObjID,
            /* [in] */ BSTR Name,
            /* [in] */ VARIANT sIID,
            /* [defaultvalue][in] */ IInterfaceDef __RPC_FAR *pIAncestor,
            /* [defaultvalue][in] */ BSTR Flags,
            /* [retval][out] */ IInterfaceDef __RPC_FAR *__RPC_FAR *ppIIfaceDef);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ObjectInstances )( 
            IClassDef2 __RPC_FAR * This,
            /* [retval][out] */ IObjectCol __RPC_FAR *__RPC_FAR *ppIObjectCol);
        
        END_INTERFACE
    } IClassDef2Vtbl;

    interface IClassDef2
    {
        CONST_VTBL struct IClassDef2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClassDef2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClassDef2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClassDef2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClassDef2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IClassDef2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IClassDef2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IClassDef2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IClassDef2_get_Properties(This,ppIProps)	\
    (This)->lpVtbl -> get_Properties(This,ppIProps)


#define IClassDef2_AddInterface(This,pIInterfaceDef,Flags)	\
    (This)->lpVtbl -> AddInterface(This,pIInterfaceDef,Flags)

#define IClassDef2_CreateInterfaceDef(This,sObjID,Name,sIID,pIAncestor,Flags,ppIIfaceDef)	\
    (This)->lpVtbl -> CreateInterfaceDef(This,sObjID,Name,sIID,pIAncestor,Flags,ppIIfaceDef)

#define IClassDef2_ObjectInstances(This,ppIObjectCol)	\
    (This)->lpVtbl -> ObjectInstances(This,ppIObjectCol)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IClassDef2_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_ClassDef,0x6E227108,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#ifdef __cplusplus

class DECLSPEC_UUID("6E227108-F799-11cf-9227-00AA00A1EB95")
ClassDef;
#endif

DEFINE_GUID(CLSID_InterfaceDef,0x6E227109,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#ifdef __cplusplus

class DECLSPEC_UUID("6E227109-F799-11cf-9227-00AA00A1EB95")
InterfaceDef;
#endif

DEFINE_GUID(CLSID_CollectionDef,0x6E22710A,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#ifdef __cplusplus

class DECLSPEC_UUID("6E22710A-F799-11cf-9227-00AA00A1EB95")
CollectionDef;
#endif

DEFINE_GUID(CLSID_MethodDef,0x6E22710B,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#ifdef __cplusplus

class DECLSPEC_UUID("6E22710B-F799-11cf-9227-00AA00A1EB95")
MethodDef;
#endif

DEFINE_GUID(CLSID_PropertyDef,0x6E22710C,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#ifdef __cplusplus

class DECLSPEC_UUID("6E22710C-F799-11cf-9227-00AA00A1EB95")
PropertyDef;
#endif

DEFINE_GUID(CLSID_RelationshipDef,0x6E22710D,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#ifdef __cplusplus

class DECLSPEC_UUID("6E22710D-F799-11cf-9227-00AA00A1EB95")
RelationshipDef;
#endif

DEFINE_GUID(CLSID_ReposTypeLib,0x6E22710E,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#ifdef __cplusplus

class DECLSPEC_UUID("6E22710E-F799-11cf-9227-00AA00A1EB95")
ReposTypeLib;
#endif

DEFINE_GUID(CLSID_ReposRoot,0x6E22710F,0xF799,0x11cf,0x92,0x27,0x00,0xAA,0x00,0xA1,0xEB,0x95);

#ifdef __cplusplus

class DECLSPEC_UUID("6E22710F-F799-11cf-9227-00AA00A1EB95")
ReposRoot;
#endif

DEFINE_GUID(CLSID_Workspace,0xB1D4ED44,0xEE64,0x11d0,0x97,0xE6,0x00,0xC0,0x4F,0xC3,0x0B,0x4A);

#ifdef __cplusplus

class DECLSPEC_UUID("B1D4ED44-EE64-11d0-97E6-00C04FC30B4A")
Workspace;
#endif

DEFINE_GUID(CLSID_Alias,0x62EC9F22,0x5E30,0x11d2,0x97,0xA1,0x00,0xC0,0x4F,0xB6,0xDD,0x9A);

#ifdef __cplusplus

class DECLSPEC_UUID("62EC9F22-5E30-11d2-97A1-00C04FB6DD9A")
Alias;
#endif

DEFINE_GUID(CLSID_ParameterDef,0x65E865BE,0x5F98,0x11d2,0x90,0x3B,0x00,0x00,0xF8,0x7A,0x3B,0x33);

#ifdef __cplusplus

class DECLSPEC_UUID("65E865BE-5F98-11d2-903B-0000F87A3B33")
ParameterDef;
#endif

DEFINE_GUID(CLSID_ScriptDef,0xD675E22B,0xCAE9,0x11d2,0xAF,0x7B,0x00,0xC0,0x4F,0x99,0x17,0x9F);

#ifdef __cplusplus

class DECLSPEC_UUID("D675E22B-CAE9-11d2-AF7B-00C04F99179F")
ScriptDef;
#endif
#endif /* __RepositoryTypeLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
