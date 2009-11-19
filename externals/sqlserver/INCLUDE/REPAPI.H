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
// REPAPI.H
//
// This module contains some of the key GUID declarations for the Repository,
// as well as the error handling definitions.  The actual API can be found
// in the .odl generated repauto.h file.
//
// Copyright (c) 1995-2000 by Microsoft Corporation, All Rights Reserved
//*****************************************************************************
#ifndef __REPAPI_H__
#define __REPAPI_H__
#include "repauto.h"					// Repository OLE automation interfaces
#include "reperr.h"						// Repository Error definitions.




// {EA43C550-2CFD-11d0-9236-00AA00A1EB95}
DEFINE_GUID(CLSID_RClassImplIface, 
0xea43c550, 0x2cfd, 0x11d0, 0x92, 0x36, 0x0, 0xaa, 0x0, 0xa1, 0xeb, 0x95);

// {EA43C551-2CFD-11d0-9236-00AA00A1EB95}
DEFINE_GUID(CLSID_RIfaceInheritsFromIface, 
0xea43c551, 0x2cfd, 0x11d0, 0x92, 0x36, 0x0, 0xaa, 0x0, 0xa1, 0xeb, 0x95);

// {EA43C552-2CFD-11d0-9236-00AA00A1EB95}
DEFINE_GUID(CLSID_RIfaceHasMembers, 
0xea43c552, 0x2cfd, 0x11d0, 0x92, 0x36, 0x0, 0xaa, 0x0, 0xa1, 0xeb, 0x95);

// {EA43C553-2CFD-11d0-9236-00AA00A1EB95}
DEFINE_GUID(CLSID_RColContainsItems, 
0xea43c553, 0x2cfd, 0x11d0, 0x92, 0x36, 0x0, 0xaa, 0x0, 0xa1, 0xeb, 0x95);

// {EA43C554-2CFD-11d0-9236-00AA00A1EB95}
DEFINE_GUID(CLSID_RContainerContextForReposTLBs, 
0xea43c554, 0x2cfd, 0x11d0, 0x92, 0x36, 0x0, 0xaa, 0x0, 0xa1, 0xeb, 0x95);

// {EA43C555-2CFD-11d0-9236-00AA00A1EB95}
DEFINE_GUID(CLSID_RReposTLBScopeForReposTypeInfo, 
0xea43c555, 0x2cfd, 0x11d0, 0x92, 0x36, 0x0, 0xaa, 0x0, 0xa1, 0xeb, 0x95);

// {6E2C9C28-65EA-11d1-AEF8-00C04FB6E933}
DEFINE_GUID(CLSID_RWksContainerContainsWorkspaces, 
0x6e2c9c28, 0x65ea, 0x11d1, 0xae, 0xf8, 0x0, 0xc0, 0x4f, 0xb6, 0xe9, 0x33);

// {D0094C72-5E1C-11d2-AA8E-00C04F99181C}
DEFINE_GUID(CLSID_RInterfaceImpliesInterface, 
0xd0094c72, 0x5e1c, 0x11d2, 0xaa, 0x8e, 0x0, 0xc0, 0x4f, 0x99, 0x18, 0x1c);

// {283998FC-5E31-11d2-97A1-00C04FB6DD9A}
DEFINE_GUID(CLSID_RBaseMemberServicesDerivedMembers, 
0x283998fc, 0x5e31, 0x11d2, 0x97, 0xa1, 0x0, 0xc0, 0x4f, 0xb6, 0xdd, 0x9a);

// {EB563CC3-5F9C-11d2-903B-0000F87A3B33}
DEFINE_GUID(CLSID_RInterfaceMemberHasParameters, 
0xeb563cc3, 0x5f9c, 0x11d2, 0x90, 0x3b, 0x0, 0x0, 0xf8, 0x7a, 0x3b, 0x33);

// {A4FD30F6-0B49-11cf-9208-00AA00A1EB95}
DEFINE_GUID(IID_IIntRepos, 
0xa4fd30f6, 0xb49, 0x11cf, 0x92, 0x8, 0x0, 0xaa, 0x0, 0xa1, 0xeb, 0x95);

// {847D1A61-BA79-11cf-8AE8-00A0C90541B2}
DEFINE_GUID(IID_IReposErrorQueueHandler, 
0x847d1a61, 0xba79, 0x11cf, 0x8a, 0xe8, 0x0, 0xa0, 0xc9, 0x5, 0x41, 0xb2);

// {53200701-BB06-11cf-8AE8-00A0C90541B2}
DEFINE_GUID(IID_IRepositoryErrorQueue, 
0x53200701, 0xbb06, 0x11cf, 0x8a, 0xe8, 0x0, 0xa0, 0xc9, 0x5, 0x41, 0xb2);

// {D4429821-5825-11cf-88A5-00AA006FF9A0}
DEFINE_GUID(IID_IEnumRepositoryErrors, 
0xd4429821, 0x5825, 0x11cf, 0x88, 0xa5, 0x0, 0xaa, 0x0, 0x6f, 0xf9, 0xa0);

// {7C4888D0-B22E-11d2-83B1-00C04F6EA648}
DEFINE_GUID(CLSID_RReposTypeLib2Dependency,
0x7c4888d0, 0xb22e, 0x11d2, 0x83, 0xb1, 0x0, 0xc0, 0x4f, 0x6e, 0xa6, 0x48);

// {D02C647B-CB4D-11d2-AF7B-00C04F99179F}
DEFINE_GUID(CLSID_RClassUsesScript, 
0xd02c647b, 0xcb4d, 0x11d2, 0xaf, 0x7b, 0x0, 0xc0, 0x4f, 0x99, 0x17, 0x9f);

// {D02C647C-CB4D-11d2-AF7B-00C04F99179F}
DEFINE_GUID(CLSID_RInterafceUsesScript, 
0xd02c647c, 0xcb4d, 0x11d2, 0xaf, 0x7b, 0x0, 0xc0, 0x4f, 0x99, 0x17, 0x9f);

// {D02C647D-CB4D-11d2-AF7B-00C04F99179F}
DEFINE_GUID(CLSID_RMemberUsesScript, 
0xd02c647d, 0xcb4d, 0x11d2, 0xaf, 0x7b, 0x0, 0xc0, 0x4f, 0x99, 0x17, 0x9f);

// {6DA0C9D1-2A91-11d3-83E0-00C04F6EA648}
DEFINE_GUID(CLSID_REnumerationValue, 
0x6da0c9d1, 0x2a91, 0x11d3, 0x83, 0xe0, 0x0, 0xc0, 0x4f, 0x6e, 0xa6, 0x48);

// {6DA0C9D2-2A91-11d3-83E0-00C04F6EA648}
DEFINE_GUID(CLSID_REnumerationForProperty, 
0x6da0c9d2, 0x2a91, 0x11d3, 0x83, 0xe0, 0x0, 0xc0, 0x4f, 0x6e, 0xa6, 0x48);

// {E57290F2-2A5C-11d3-83E0-00C04F6EA648}
DEFINE_GUID(CLSID_EnumerationDef, 
0xe57290f2, 0x2a5c, 0x11d3, 0x83, 0xe0, 0x0, 0xc0, 0x4f, 0x6e, 0xa6, 0x48);

// {E57290F3-2A5C-11d3-83E0-00C04F6EA648}
DEFINE_GUID(CLSID_EnumerationValueDef, 
0xe57290f3, 0x2a5c, 0x11d3, 0x83, 0xe0, 0x0, 0xc0, 0x4f, 0x6e, 0xa6, 0x48);

// Constant size values.
const int RELSHIPNAMESIZE		= 260;	// Max size of a relship name.
const int MEMBERNAMESIZE		= 128;	// Max property name.
const int VIEWNAMESIZE			= 128;	// Max view name.
const int COLPREFIXSIZE			= 119;	// Max column name prefix in jn view
const int PROPVALSIZE			= 220;  // Max annotational property value.
const int TABLENAMESIZE			= 255;
const int COLUMNNAMESIZE		= 255;
const int TYPEINFONAMESIZE		= 128;
const int TYPELIBNAMESIZE		= 64;
const int USERSIZE				= 64;
const int PASSWORDSIZE			= 64;
const int OLDNAMESIZE			= 32;
const int MAXROWSPERBATCH		= 1000;	// #Rows in insert and delete batches
const int AKANAMESIZE			= 127;

// Internal repository object IDs.
struct INTID
{
	ULONG		iSiteID;
	ULONG		iLocalID;
};
typedef const INTID &REFINTID;

// Some useful overloaded operators.
inline BOOL operator==(const INTID& One, const INTID& Other)
{
	return ((One.iLocalID == Other.iLocalID) &&
			(One.iSiteID == Other.iSiteID));
}

inline BOOL operator!=(const INTID& One, const INTID& Other)
{
	return ((One.iLocalID != Other.iLocalID) ||
			(One.iSiteID != Other.iSiteID));
}

inline BOOL operator>(const INTID& One, const INTID& Other)
{
	if ((One.iSiteID > Other.iSiteID) ||
		((One.iSiteID == Other.iSiteID) && (One.iLocalID > Other.iLocalID)))
		return TRUE;

	return FALSE;
}

inline BOOL operator<(const INTID& One, const INTID& Other)
{
	if ((One.iSiteID < Other.iSiteID) ||
		((One.iSiteID == Other.iSiteID) && (One.iLocalID < Other.iLocalID)))
		return TRUE;

	return FALSE;
}

inline int Compare(const INTID& One, const INTID& Other)
{
	if (One < Other)
		return -1;

	if (One == Other)
		return 0;

	return 1;
}

inline int DBCompare(const INTID& One, const INTID& Other)
{
	return (memcmp(&One, &Other, sizeof(INTID)));
}

inline BOOL operator==(IRepositoryObject &One, IRepositoryObject &Two)
{
	BOOL		bSame;
	VARIANT		sOne, sTwo;
	HRESULT		hr;
	::VariantInit(&sOne);
	::VariantInit(&sTwo);
	if (FAILED(hr = One.get_InternalID(&sOne)) ||
		FAILED(hr = Two.get_InternalID(&sTwo)))
		return (FALSE);
	bSame = *(INTID*)sOne.parray->pvData == *(INTID*)sTwo.parray->pvData;
	::VariantClear(&sOne);
	::VariantClear(&sTwo);
	return (bSame);
}

inline BOOL operator!=(IRepositoryObject &One, IRepositoryObject &Two)
{
	return (!(One == Two));
}


//*****************************************************************************
// Repository object IDs are represented as a GUID identifying where they
// were created plus a 4 byte identifier unique to that location.
//*****************************************************************************
typedef OBJECTID OBJID;
typedef const OBJID& REFOBJID;

// This defines the instantiation of the object IDs.
#ifndef INITGUID
#define DEFINE_OBJID(name, u, guid) \
    EXTERN_C const OBJID CDECL FAR name
#else
#define DEFINE_OBJID(name, u, guid) \
    EXTERN_C const OBJID CDECL __based(__segname("_CODE")) name \
= { guid, u }
#endif // INITGUID

// Some useful overloaded operators.
inline BOOL operator==(const OBJID& objidOne, const OBJID& objidOther)
{
    return !memcmp(&objidOne,&objidOther,sizeof(OBJID));
}
inline BOOL operator!=(const OBJID& objidOne, const OBJID& objidOther)
{
    return !(objidOne == objidOther);
}

// Forwards...
interface IReposErrorHandler;

//*****************************************************************************
// These flags are returned in an REPOSERROR struct in the fFlags field.
//*****************************************************************************
#define REPOSERROR_OBJKNOWN		0x00000001L	// Object ID is known.
#define REPOSERROR_SQLINFO		0x00000002L	// SQL error information is valid.
#define REPOSERROR_HELPAVAIL	0x00000004L // rcHelpFile and dwHelpContext valid.

#define REPOSERROR_MSG_SIZE		256

//*****************************************************************************
// Defines one error that has occured in repsonse to a Repository method call.
//*****************************************************************************
struct REPOSERROR
{
	ULONG		iSize;					// Size of this struct.
	ULONG		fFlags;					// REPOSERROR_* flags.
	HRESULT		hr;						// The error code.
	TCHAR		rcMsg[REPOSERROR_MSG_SIZE];	// Message text.
	TCHAR		rcHelpFile[_MAX_PATH];	// The name of the help file
	ULONG		dwHelpContext;			// Help context for error.
	long		iNativeError;			// Supplied by database, if applicable.
	TCHAR		rcSqlState[6];			// Supplied by database, if applicable.
	short		iReserved;				// For Repository use only.
	OBJID		sObjID;					// OBJID in error.
	GUID		clsid;					// CLSID of object with the error.
	GUID		iid;					// Interface with error or GUID_NULL.
};

//*****************************************************************************
// This interface is used to enumerate extended error information.
//*****************************************************************************
interface IEnumRepositoryErrors : public IUnknown
{
	STDMETHOD(Next)(
		ULONG		iCount,
		REPOSERROR	*psErrors,
		ULONG		*piFetched) = 0;

	STDMETHOD(Next)(
		IErrorInfo	**ppIErrorInfo) = 0;

	STDMETHOD(Skip)(
		ULONG		iCount) = 0;

	STDMETHOD(Reset)() = 0;

	STDMETHOD(Clone)(
		IEnumRepositoryErrors **ppIEnum) = 0;
};


//*****************************************************************************
// This interface is used to perform operations on the error queue. 
//*****************************************************************************
interface IRepositoryErrorQueue : public IUnknown
{
	STDMETHOD(Insert)(
		ULONG		iIndex,
		REPOSERROR	*psError) = 0;

	STDMETHOD(Remove)(
		ULONG		iIndex) = 0;

	STDMETHOD_(ULONG, Count)() = 0;

	STDMETHOD(Item)(
		ULONG		iIndex,
		REPOSERROR	*psError) = 0;

	STDMETHOD(Item)(
		ULONG		iIndex,
		IErrorInfo	**ppIErrorInfo) = 0;

	STDMETHOD(_NewEnum)(
		IEnumRepositoryErrors **ppIEnum) = 0; 
};

//*****************************************************************************
// This interface is used to handle the error queue. 
//*****************************************************************************
interface IReposErrorQueueHandler : public IUnknown
{
	STDMETHOD(CreateErrorQueue)(
		IRepositoryErrorQueue	**ppIErrorQueue) = 0;

	STDMETHOD(SetErrorQueue)(
		IRepositoryErrorQueue	*pIErrorQueue) = 0;

	STDMETHOD(GetErrorQueue)(
		IRepositoryErrorQueue	**ppIErrorQueue) = 0;
};


// ===========================================================================
//								V2  Additions
// ===========================================================================

typedef OBJID EXTVERSIONID;
typedef const EXTVERSIONID& REFEXTVERSIONID;

//*****************************************************************************
// Repository Version IDs in the database are represented as a three part stucture
// of intid (8 byte binary), branchid (4 byte int/long), VS( 4 byte int/long)
// Internally, we will use the following structure. The VERSIONID is an internal
// structure. The proper type to use for external version ID is EXTVERSIONID.
//*****************************************************************************
typedef long BRANCHID;
typedef long VERSIONNUM;

#define VERINFINITY	2147483647L	// This represents our VE infinity value
#define STARTVS		0			// Version start of first version of an obj
#define WILDBRANCH	-1			// This is the wild card branch id.
#define WILDVS		-1			// This is the wild card Version start.
#define WILDVE		-1			// This is the wild card Version end.

struct VERSIONID
{
	INTID		sIntID;
	BRANCHID	iBranchID;
	VERSIONNUM	iVersionStart;
};

typedef const VERSIONID &REFVERSIONID;

// Some useful branch/version constants.
const BRANCHID PRIMARYBRANCH	= 0;
const BRANCHID NULLBRANCH		= (-2147483647L - 1);
const VERSIONNUM NULLVERSION	= (-2147483647L - 1);
	
// Some useful overloaded operators.
inline BOOL operator==(const VERSIONID& One, const VERSIONID& Other)
{
	return ((One.sIntID == Other.sIntID) &&
			(One.iBranchID == Other.iBranchID) &&
			(One.iVersionStart == Other.iVersionStart));
}

inline BOOL operator!=(const VERSIONID& One, const VERSIONID& Other)
{
	return ((One.sIntID != Other.sIntID) ||
			(One.iBranchID != Other.iBranchID) ||
			(One.iVersionStart != Other.iVersionStart));
}

inline BOOL operator>(const VERSIONID& One, const VERSIONID& Other)
{
	if ((One.sIntID > Other.sIntID) ||
		((One.sIntID == Other.sIntID) && (One.iBranchID > Other.iBranchID)) ||
		((One.sIntID == Other.sIntID) && (One.iBranchID == Other.iBranchID) && (One.iVersionStart > Other.iVersionStart)))
		return TRUE;

	return FALSE;
}

inline BOOL operator<(const VERSIONID& One, const VERSIONID& Other)
{
	if ((One.sIntID < Other.sIntID) ||
		((One.sIntID == Other.sIntID) && (One.iBranchID < Other.iBranchID)) ||
		((One.sIntID == Other.sIntID) && (One.iBranchID == Other.iBranchID) && (One.iVersionStart < Other.iVersionStart)))
		return TRUE;

	return FALSE;
}

inline int Compare(const VERSIONID& One, const VERSIONID& Other)
{
	if (One < Other)
		return -1;

	if (One == Other)
		return 0;

	return 1;
}

inline BOOL IsSameBranch(const VERSIONID& One, const VERSIONID& Other)
{
	return (One.sIntID == Other.sIntID &&
			One.iBranchID == Other.iBranchID);
}



#endif // __REPAPI_H__
