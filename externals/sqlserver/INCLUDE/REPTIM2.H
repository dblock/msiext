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
// REPTIM2.H
//
// This module contains the declarations of the meta-meta model components.
// These can be used to browse the meta-meta model by ID, or might be required
// to create your own meta model in the Repository.
//
// Copyright (c) 1995-2000 by Microsoft Corporation, All Rights Reserved
//*****************************************************************************
#ifndef __REPTIM2_H__
#define __REPTIM2_H__

#include "reptim.h"


// Local ID definitions
#define LCLID_IReposVersion			71
#define LCLID_IVersionCol			72
#define LCLID_IVersionedRelship		73

#define LCLID_Workspace				74

#define	LCLID_IWorkspace			75
#define	LCLID_IWorkspaceItem		76

#define LCLID_IVersionAdminInfo		77

#define LCLID_VersionCreateTime		78
#define LCLID_VersionModifyTime		79
#define LCLID_CreateByUser			80
#define LCLID_ModifyByUser			81

#define LCLID_IWorkspaceContainer	82

#define LCLID_RWksContainerContainsWorkspaces	83

#define LCLID_ContainedWorkspaces	84
#define LCLID_WorkspaceContainers	85

#define LCLID_InsertSProcName		86


// Internal ID definitions.
const INTID	INTID_IReposVersion		= {SITEID_METAMETA, LCLID_IReposVersion};
const INTID	INTID_IVersionCol		= {SITEID_METAMETA, LCLID_IVersionCol};
const INTID	INTID_IVersionedRelship	= {SITEID_METAMETA, LCLID_IVersionedRelship};

const INTID	INTID_Workspace			= {SITEID_METAMETA, LCLID_Workspace};

const INTID	INTID_IWorkspaceItem	= {SITEID_METAMETA,	LCLID_IWorkspaceItem};
const INTID	INTID_IWorkspace		= {SITEID_METAMETA, LCLID_IWorkspace};

const INTID INTID_IVersionAdminInfo	= {SITEID_METAMETA, LCLID_IVersionAdminInfo};

const INTID INTID_VersionCreateTime	= {SITEID_METAMETA, LCLID_VersionCreateTime};
const INTID INTID_VersionModifyTime	= {SITEID_METAMETA, LCLID_VersionModifyTime};
const INTID INTID_CreateByUser		= {SITEID_METAMETA, LCLID_CreateByUser};
const INTID INTID_ModifyByUser		= {SITEID_METAMETA, LCLID_ModifyByUser};

const INTID INTID_IWorkspaceContainer	= {SITEID_METAMETA, LCLID_IWorkspaceContainer};

const INTID INTID_RWksContainerContainsWorkspaces	= {SITEID_METAMETA, LCLID_RWksContainerContainsWorkspaces};

const INTID INTID_ContainedWorkspaces	= {SITEID_METAMETA, LCLID_ContainedWorkspaces};
const INTID INTID_WorkspaceContainers	= {SITEID_METAMETA, LCLID_WorkspaceContainers};

const INTID INTID_InsertSProcName	= {SITEID_METAMETA, LCLID_InsertSProcName};

// DispatchID definitions.
#define DISPID_VersionCreateTime	LCLID_VersionCreateTime
#define DISPID_VersionModifyTime	LCLID_VersionModifyTime
#define DISPID_CreateByUser			LCLID_CreateByUser
#define DISPID_ModifyByUser			LCLID_ModifyByUser

#define DISPID_ContainedWorkspaces	LCLID_ContainedWorkspaces
#define DISPID_WorkspaceContainers	LCLID_WorkspaceContainers

#define DISPID_InsertSProcName		LCLID_InsertSProcName

// Object ID definitions.
DEFINE_OBJID(OBJID_IReposVersion, LCLID_IReposVersion, METAMETA_GUID);
DEFINE_OBJID(OBJID_IVersionCol, LCLID_IVersionCol, METAMETA_GUID);
DEFINE_OBJID(OBJID_IVersionedRelship, LCLID_IVersionedRelship, METAMETA_GUID);

DEFINE_OBJID(OBJID_Workspace, LCLID_Workspace, METAMETA_GUID);

DEFINE_OBJID(OBJID_IWorkspaceItem, LCLID_IWorkspaceItem, METAMETA_GUID);
DEFINE_OBJID(OBJID_IWorkspace,     LCLID_IWorkspace,     METAMETA_GUID);

DEFINE_OBJID(OBJID_IVersionAdminInfo, LCLID_IVersionAdminInfo, METAMETA_GUID);

DEFINE_OBJID(OBJID_VersionCreateTime, LCLID_VersionCreateTime, METAMETA_GUID);
DEFINE_OBJID(OBJID_VersionModifyTime, LCLID_VersionModifyTime, METAMETA_GUID);
DEFINE_OBJID(OBJID_CreateByUser, LCLID_CreateByUser, METAMETA_GUID);
DEFINE_OBJID(OBJID_ModifyByUser, LCLID_ModifyByUser, METAMETA_GUID);

DEFINE_OBJID(OBJID_IWorkspaceContainer, LCLID_IWorkspaceContainer, METAMETA_GUID);

DEFINE_OBJID(OBJID_RWksContainerContainsWorkspaces, LCLID_RWksContainerContainsWorkspaces, METAMETA_GUID);
DEFINE_OBJID(OBJID_ContainedWorkspaces, LCLID_ContainedWorkspaces, METAMETA_GUID);
DEFINE_OBJID(OBJID_WorkspaceContainers, LCLID_WorkspaceContainers, METAMETA_GUID);

DEFINE_OBJID(OBJID_InsertSProcName, LCLID_InsertSProcName, METAMETA_GUID);

// To be used as a parameter for CreateVersion.
DEFINE_OBJID(EXTVERSIONID_NULL, LCLID_NULL, METAMETA_GUID);

#endif // __REPTIM2_H__
