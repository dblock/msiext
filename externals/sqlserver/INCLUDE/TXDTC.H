/* ----------------------------------------------------------------------------
 Microsoft Distributed Transaction Coordinator (Microsoft Confidential)
	 Copyright 1995 - 1995 Microsoft Corporation.  All Rights Reserved.
 
 @doc
 
 @module TXDTC.H | <nl>Header for 
 								<i IResourceManagerFactory>,
								<i IResourceManager>,
								<i IXATransLookup>,
								<i IPrepareInfo>,
								<i IGetDispenser>.<nl><nl>

-------------------------------------------------------------------------------
 @rev 7 | 09/30/96 | gaganc		| Added interfaces IXAResourceManagerFactoryCreate,
										IXAResourceManager, and IXATransaction
 @rev 6 | 08/13/96 | gaganc		| Added IRMInfo, and IXAObtainRMInfo interfaces
 @rev 5 | 04/20/96 | gaganc		| Added IXaConfig
 @rev 4 | 09/14/95 | gaganc		| Added IID_IXATransLookUp
 @rev 3 | 08/25/95 | gaganc		| Added IResourceManagerSink interface
 @rev 2 | 05/16/95 | gaganc		| Added guids for the RM to Proxy int. guids
 @rev 1 | 05/05/95 | mohsena 		| Created: For M0.2 from msdtcprx.h
 @rev 0 | 03/28/95 | gaganc		| Created msdtcprx.h
----------------------------------------------------------------------------- */

#ifndef __TXDTC_H__
#	define __TXDTC_H__

// ===============================
// INCLUDES:
// ===============================
#ifdef WIN32								// OLE inclusions:
#	include <objbase.h>                                         
#else
#	include <windows.h>
#	include <ole2.h>
#endif WIN32

#include "transact.h"						// Definition of ITransaction, ...etc
#include "txcoord.h"						// Definition of ITransactionResource,...etc
#include "xa.h"

//---------------------------------------------------------
//	Macros
//---------------------------------------------------------
#define XACTTOMSG(dwXact) (dwXact-0x00040000+0x40000000)


//---------------------------------------------------------
//	Error Messages
//---------------------------------------------------------
#define XACT_E_CONNECTION_REQUEST_DENIED	0x8004D100L
#define XACT_E_TOOMANY_ENLISTMENTS			0x8004D101L
#define XACT_E_DUPLICATE_GUID				0x8004D102L
#define XACT_E_NOTSINGLEPHASE				0x8004D103L
#define XACT_E_RECOVERYALREADYDONE			0x8004D104L
#define XACT_E_PROTOCOL						0x8004D105L
#define	XACT_E_RM_FAILURE					0x8004D106L
#define XACT_E_RECOVERY_FAILED				0x8004D107L


//---------------------------------------------------------
//	Status Messages
//---------------------------------------------------------
#define XACT_S_NONOTIFY						0x0004D100L
#define XACT_OK_NONOTIFY					0x0004D101L

//---------------------------------------------------------
//			 Consts
//---------------------------------------------------------
const	DWORD	dwUSER_MS_SQLSERVER			= 0x0000FFFF;


//---------------------------------------------------------
//			 GUIDs
//---------------------------------------------------------
//IID_IResourceManagerFactory 13741d20-87eb-11ce-8081-0080c758527e
DEFINE_GUID(IID_IResourceManagerFactory,
    		0x13741d20,
    		0x87eb,
    		0x11ce,
    		0x80, 0x81, 0x00, 0x80, 0xc7, 0x58, 0x52, 0x7e);


//IID_IResourceManager 13741d21-87eb-11ce-8081-0080c758527e 
DEFINE_GUID(IID_IResourceManager,
    		0x13741d21,
    		0x87eb,
    		0x11ce,
    		0x80, 0x81, 0x00, 0x80, 0xc7, 0x58, 0x52, 0x7e);



//IID_IPrepareInfo 80c7bfd0-87ee-11ce-8081-0080c758527e
DEFINE_GUID(IID_IPrepareInfo,
		    0x80c7bfd0,
		    0x87ee,
		    0x11ce,
		    0x80, 0x81, 0x00, 0x80, 0xc7, 0x58, 0x52, 0x7e);


//IID_IGetDispenser c23cc370-87ef-11ce-8081-0080c758527e
DEFINE_GUID(IID_IGetDispenser,
		    0xc23cc370,
		    0x87ef,
		    0x11ce,
		    0x80, 0x81, 0x00, 0x80, 0xc7, 0x58, 0x52, 0x7e);


//IID_IResourceManagerSink {0D563181-DEFB-11ce-AED1-00AA0051E2C4}
DEFINE_GUID(IID_IResourceManagerSink, 
			0xd563181,
			0xdefb,
			0x11ce,
			0xae, 0xd1, 0x0, 0xaa, 0x0, 0x51, 0xe2, 0xc4);

//IID_IXATransLookup {F3B1F131-EEDA-11ce-AED4-00AA0051E2C4}
DEFINE_GUID(IID_IXATransLookup, 
			0xf3b1f131,
			0xeeda,
			0x11ce,
			0xae, 0xd4, 0x0, 0xaa, 0x0, 0x51, 0xe2, 0xc4);


// IID_IXAConfig {C8A6E3A1-9A8C-11cf-A308-00A0C905416E}
DEFINE_GUID(IID_IXAConfig, 
			0xc8a6e3a1,
			0x9a8c,
			0x11cf,
			0xa3, 0x8, 0x0, 0xa0, 0xc9, 0x5, 0x41, 0x6e);

//IID_IRMInfo {E793F6D1-F53D-11cf-A60D-00A0C905416E}
DEFINE_GUID(IID_IRMInfo, 
			0xe793f6d1,
			0xf53d,
			0x11cf,
			0xa6, 0xd, 0x0, 0xa0, 0xc9, 0x5, 0x41, 0x6e);


//IID_IXAObtainRMInfo {E793F6D2-F53D-11cf-A60D-00A0C905416E}
DEFINE_GUID(IID_IXAObtainRMInfo, 
			0xe793f6d2,
			0xf53d,
			0x11cf,
			0xa6, 0xd, 0x0, 0xa0, 0xc9, 0x5, 0x41, 0x6e);


// IID_ITransactionVoterFactory {319FAC10-A391-11cf-A535-00AA006887C3}
DEFINE_GUID(IID_ITransactionVoterFactory, 
			0x319fac10, 
			0xa391, 
			0x11cf, 
			0xa5, 0x35, 0x0, 0xaa, 0x0, 0x68, 0x87, 0xc3);


// IID_ITransactionVoterNotifyAsync {319FAC11-A391-11cf-A535-00AA006887C3}
DEFINE_GUID(IID_ITransactionVoterNotifyAsync, 
			0x319fac11, 
			0xa391, 
			0x11cf, 
			0xa5, 0x35, 0x0, 0xaa, 0x0, 0x68, 0x87, 0xc3);


// IID_ITransactionVoterBallotAsync {319FAC12-A391-11cf-A535-00AA006887C3}
DEFINE_GUID(IID_ITransactionVoterBallotAsync, 
			0x319fac12, 
			0xa391, 
			0x11cf, 
			0xa5, 0x35, 0x0, 0xaa, 0x0, 0x68, 0x87, 0xc3);


// IID_ITransactionTransmitterFactory {59313E00-B36C-11cf-A539-00AA006887C3}
DEFINE_GUID(IID_ITransactionTransmitterFactory, 
			0x59313e00, 
			0xb36c, 
			0x11cf, 
			0xa5, 0x39, 0x0, 0xaa, 0x0, 0x68, 0x87, 0xc3);


// IID_ITransactionTransmitter {59313E01-B36C-11cf-A539-00AA006887C3}
DEFINE_GUID(IID_ITransactionTransmitter, 
			0x59313e01, 
			0xb36c, 
			0x11cf, 
			0xa5, 0x39, 0x0, 0xaa, 0x0, 0x68, 0x87, 0xc3);


// IID_ITransactionReceiverFactory {59313E02-B36C-11cf-A539-00AA006887C3}
DEFINE_GUID(IID_ITransactionReceiverFactory, 
			0x59313e02, 
			0xb36c, 
			0x11cf, 
			0xa5, 0x39, 0x0, 0xaa, 0x0, 0x68, 0x87, 0xc3);


// IID_ITransactionReceiver {59313E03-B36C-11cf-A539-00AA006887C3}
DEFINE_GUID(IID_ITransactionReceiver, 
			0x59313e03, 
			0xb36c, 
			0x11cf, 
			0xa5, 0x39, 0x0, 0xaa, 0x0, 0x68, 0x87, 0xc3);




//IID_ITransactionDisableCommit {C27D5D20-F79B-11cf-8CB5-00C04FD658E5}
DEFINE_GUID(IID_ITransactionDisableCommit, 
			0xc27d5d20, 
			0xf79b, 
			0x11cf, 
			0x8c, 0xb5, 0x0, 0xc0, 0x4f, 0xd6, 0x58, 0xe5);


//IID_ITransactionEnableCommit {C27D5D21-F79B-11cf-8CB5-00C04FD658E5}
DEFINE_GUID(IID_ITransactionEnableCommit, 
			0xc27d5d21, 
			0xf79b, 
			0x11cf, 
			0x8c, 0xb5, 0x0, 0xc0, 0x4f, 0xd6, 0x58, 0xe5);



//IID_IXAResourceManagerFactory {4131E750-1AEA-11d0-944B-00A0C905416E}
DEFINE_GUID(IID_IXAResourceManagerFactory, 
			0x4131e750,
			0x1aea,
			0x11d0,
			0x94, 0x4b, 0x0, 0xa0, 0xc9, 0x5, 0x41, 0x6e);

//IID_IXAResourceManager {4131E751-1AEA-11d0-944B-00A0C905416E}
DEFINE_GUID(IID_IXAResourceManager, 
			0x4131e751,
			0x1aea,
			0x11d0,
			0x94, 0x4b, 0x0, 0xa0, 0xc9, 0x5, 0x41, 0x6e);

//IID_IXATransaction {4131E752-1AEA-11d0-944B-00A0C905416E}
DEFINE_GUID(IID_IXATransaction, 
			0x4131e752,
			0x1aea,
			0x11d0,
			0x94, 0x4b, 0x0, 0xa0, 0xc9, 0x5, 0x41, 0x6e);


//---------------------------------------------------------
//		typedefs
//---------------------------------------------------------

typedef struct _ProxyConfigParams
			{
				WORD	wcThreadsMax;
			}	PROXY_CONFIG_PARAMS;



// @interface IXATransLookup | See class <c IXATransLookup>. 
// -----------------------------------------------------------------------
// @class IXATransLookup | XA Lookup support interface.<nl>
// Description:<nl>
// Usage:<nl>
// Notes:<nl>
//	UNDONE:
// .
// -----------------------------------------------------------------------
// @rev 0 | 03/05/96 |gaganc | created
// -----------------------------------------------------------------------
#undef INTERFACE
#define INTERFACE IXATransLookup

DECLARE_INTERFACE_ (IXATransLookup, IUnknown)	// @base public | IUnknown
{
	// IUnknown interface methods:
	STDMETHOD	(QueryInterface)	(THIS_ REFIID riid, LPVOID FAR * ppv) PURE;
 	STDMETHOD_	(ULONG, AddRef)		(THIS) 	PURE;
 	STDMETHOD_	(ULONG, Release)	(THIS) 	PURE;

	STDMETHOD	(Lookup) ( /* [out] */
				 ITransaction ** ppTransaction) PURE;
};



// @interface IResourceManagerSink | See class <c IResourceManager>. 
// -----------------------------------------------------------------------
// @class IResourceManager | SQL Server enlistment support.<nl>
// Description:<nl>
// Usage:<nl>
// -----------------------------------------------------------------------
// @rev 0 | 08/25/95 |gaganc | created
// -----------------------------------------------------------------------
#undef INTERFACE
#define INTERFACE IResourceManagerSink

DECLARE_INTERFACE_ (IResourceManagerSink, IUnknown)	// @base public | IUnknown
{
	// IUnknown interface methods:
	STDMETHOD	(QueryInterface)	(THIS_ REFIID riid, LPVOID FAR * ppv) PURE;
 	STDMETHOD_	(ULONG, AddRef)		(THIS) 	PURE;
 	STDMETHOD_	(ULONG, Release)	(THIS) 	PURE;

	STDMETHOD	(TMDown) (void) PURE;
};



// @interface IResourceManager | See class <c IResourceManager>. 
// -----------------------------------------------------------------------
// @class IResourceManager | SQL Server enlistment support.<nl>
// -----------------------------------------------------------------------
// @rev 0 | 05/06/95 |gaganc | created
// -----------------------------------------------------------------------
#undef INTERFACE
#define INTERFACE IResourceManager

DECLARE_INTERFACE_ (IResourceManager, IUnknown)	// @base public | IUnknown
{
	// IUnknown interface methods:
	STDMETHOD	(QueryInterface)	(THIS_ REFIID riid, LPVOID * ppv) PURE;
 	STDMETHOD_	(ULONG, AddRef)		(THIS) 	PURE;
 	STDMETHOD_	(ULONG, Release)	(THIS) 	PURE;

	STDMETHOD	(Enlist) ( 
        /* [in] */ ITransaction  *pTransaction,
        /* [in] */ ITransactionResourceAsync  *pRes,
        /* [out][in] */ GUID  *pUOW,
        /* [out] */ LONG  *pisoLevel,
        /* [out] */ ITransactionEnlistmentAsync  ** ppEnlist) PURE;

    STDMETHOD (Reenlist) ( 
        /* [in] */ unsigned char  *pPrepInfo,
        /* [in] */ ULONG cbPrepInfo,
        /* [in] */ DWORD lTimeout,
        /* [in-out] */ XACTSTAT *pXactStat) PURE;
    
	// @cmember .
    STDMETHOD (ReenlistmentComplete) ( void) PURE;
    
	//\@cmember .
    STDMETHOD (GetDistributedTransactionManager) ( 
		/* [in] */ REFIID rid, 
        /* [out] */ void  ** ppvObject) PURE;
};



// @interface IXAConfig 
/* ----------------------------------------------------------------------------
	@class IXAConfig | XA RM support.<nl>

-------------------------------------------------------------------------------
 @rev 0 | 04/20/96 |gaganc | created
---------------------------------------------------------------------------- */
#undef INTERFACE
#define INTERFACE IXAConfig

DECLARE_INTERFACE_ (IXAConfig, IUnknown)
{
	// IUnknown interface methods:
	STDMETHOD	(QueryInterface)	(THIS_ REFIID riid, LPVOID * ppv) PURE;
 	STDMETHOD_	(ULONG, AddRef)		(THIS) 	PURE;
 	STDMETHOD_	(ULONG, Release)	(THIS) 	PURE;

	STDMETHOD	(Initialize) (GUID clsidHelperDll) PURE;

    STDMETHOD (Terminate) ( void) PURE;
};


// @interface IRMHelper
/* ----------------------------------------------------------------------------
	@class IRMHelper | XA RM support.<nl>

-------------------------------------------------------------------------------
 @rev 0 | 08/13/96 |gaganc | created
---------------------------------------------------------------------------- */
#undef INTERFACE
#define INTERFACE IRMHelper

DECLARE_INTERFACE_ (IRMHelper, IUnknown)
{
	// IUnknown interface methods:
	STDMETHOD	(QueryInterface)	(THIS_ REFIID riid, LPVOID * ppv) PURE;
 	STDMETHOD_	(ULONG, AddRef)		(THIS) 	PURE;
 	STDMETHOD_	(ULONG, Release)	(THIS) 	PURE;

	STDMETHOD	(RMCount) (DWORD dwcTotalNumberOfRMs) PURE;

	STDMETHOD	(RMInfo)	(
								xa_switch_t * pXa_Switch,
								BOOL	fCDeclCallingConv,
								char * pszOpenString,
								char * pszCloseString,
								GUID guidRMRecovery	
							) PURE;
};



// @interface IXAObtainRMInfo 
/* ----------------------------------------------------------------------------
	@class IXAObtainRMInfo | XA RM support.<nl>

-------------------------------------------------------------------------------
 @rev 0 | 08/13/96 |gaganc | created
---------------------------------------------------------------------------- */
#undef INTERFACE
#define INTERFACE IXAObtainRMInfo

DECLARE_INTERFACE_ (IXAObtainRMInfo, IUnknown)
{
	// IUnknown interface methods:
	STDMETHOD	(QueryInterface)	(THIS_ REFIID riid, LPVOID * ppv) PURE;
 	STDMETHOD_	(ULONG, AddRef)		(THIS) 	PURE;
 	STDMETHOD_	(ULONG, Release)	(THIS) 	PURE;

	STDMETHOD	(ObtainRMInfo) (IRMHelper * pIRMHelper) PURE;
};


// @interface IXAResourceManager
/* ----------------------------------------------------------------------------
	@class IXAResourceManager | XA RM support.<nl>

-------------------------------------------------------------------------------
 @rev 0 | 09/30/96 |gaganc | created
---------------------------------------------------------------------------- */
#undef INTERFACE
#define INTERFACE IXAResourceManager

DECLARE_INTERFACE_ (IXAResourceManager, IUnknown)
{
	// IUnknown interface methods:
	STDMETHOD	(QueryInterface)	(THIS_ REFIID riid, LPVOID * ppv) PURE;
 	STDMETHOD_	(ULONG, AddRef)		(THIS) 	PURE;
 	STDMETHOD_	(ULONG, Release)	(THIS) 	PURE;

}; //end interface IXAResourceManager


// @interface IXAResourceManagerFactory
/* ----------------------------------------------------------------------------
	@class IXAResourceManagerFactory | XA RM support.<nl>

-------------------------------------------------------------------------------
 @rev 0 | 09/30/96 |gaganc | created
---------------------------------------------------------------------------- */
#undef INTERFACE
#define INTERFACE IXAResourceManagerFactory

DECLARE_INTERFACE_ (IXAResourceManagerFactory, IUnknown)
{
	// IUnknown interface methods:
	STDMETHOD	(QueryInterface)	(THIS_ REFIID riid, LPVOID * ppv) PURE;
 	STDMETHOD_	(ULONG, AddRef)		(THIS) 	PURE;
 	STDMETHOD_	(ULONG, Release)	(THIS) 	PURE;

    STDMETHOD (Create) ( 
						/*[in] */ char * pszDSN, 
						/*[in] */ CLSID pclsidRMHelper,
						/*[out] */ IXAResourceManager ** ppIXaResMgr
						) PURE;
    
}; //end interface IXAResourceManagerFactory




// @interface IXATransaction
/* ----------------------------------------------------------------------------
	@class IXATransaction | XA RM support.<nl>

-------------------------------------------------------------------------------
 @rev 0 | 09/30/96 |gaganc | created
---------------------------------------------------------------------------- */
#undef INTERFACE
#define INTERFACE IXATransaction

DECLARE_INTERFACE_ (IXATransaction, ITransaction)
{
	// IUnknown interface methods:
	STDMETHOD	(QueryInterface)	(THIS_ REFIID riid, LPVOID * ppv) PURE;
 	STDMETHOD_	(ULONG, AddRef)		(THIS) 	PURE;
 	STDMETHOD_	(ULONG, Release)	(THIS) 	PURE;

	//methods from ITransaction
    STDMETHOD (Commit)
        (
			/*[in]*/ BOOL  fRetaining, 
			/*[in]*/ DWORD grfTC,
			/*[in]*/ DWORD grfRM
        ) PURE;

    STDMETHOD (Abort)
        (
			/*[in]*/ BOID* pboidReason,
			/*[in]*/ BOOL  fRetaining,
			/*[in]*/ BOOL  fAsync
        )PURE;

    STDMETHOD (GetTransactionInfo)
        (
			/* [out] */ XACTTRANSINFO* pinfo
        ) PURE;	


	//additional methods
	STDMETHOD (Join)
		(
			/*[in]*/ IXAResourceManager * pIXAResourceManager
		) PURE;
		

	STDMETHOD (UnJoin)
		(
			void	
		) PURE;
				    
}; //end interface IXATransaction






// @interface IResourceManagerFactory | See class <c IResourceManagerFactory>. 
// -----------------------------------------------------------------------
// @class IResourceManagerFactory | Creates <c IResourceManager> instances.<nl>
// Description:<nl>
// Usage:<nl>
// Notes:<nl>
//	UNDONE:
// .
// -----------------------------------------------------------------------
// @rev 0 | 05/06/95 |mohsena | created
// -----------------------------------------------------------------------
DECLARE_INTERFACE_ (IResourceManagerFactory, IUnknown)		// @base public | IUnknown
{
	// IUnknown interface methods:
	STDMETHOD	(QueryInterface)	(THIS_ REFIID riid, LPVOID * ppv) PURE;
 	STDMETHOD_	(ULONG, AddRef)		(THIS) 	PURE;
 	STDMETHOD_	(ULONG, Release)	(THIS) 	PURE;

	// IResourceManagerFactory interface methods
    STDMETHOD	(Create)			(
									THIS_ 
									GUID __RPC_FAR *pguidRM,
									TCHAR __RPC_FAR *pszRMName,
									IResourceManagerSink	* pIResMgrSink,
									IResourceManager __RPC_FAR *__RPC_FAR *ppResMgr
									) PURE;
    
};

// @interface IPrepareInfo | See class <c IPrepareInfo>. 
// -----------------------------------------------------------------------
// @class IPrepareInfo | Defines <i IPrepareInfo>.<nl>
// Description:<nl>
// Usage:<nl>
// Notes:<nl>
//	UNDONE:
// .
// -----------------------------------------------------------------------
// @rev 0 | 03/28/95 |gaganc | created
// -----------------------------------------------------------------------
DECLARE_INTERFACE_ (IPrepareInfo, IUnknown)			// @base public | IUnknown
{
	// IUnknown interface methods:
	STDMETHOD	(QueryInterface)	(THIS_ REFIID riid, LPVOID * ppv) PURE;
 	STDMETHOD_	(ULONG, AddRef)		(THIS) 	PURE;
 	STDMETHOD_	(ULONG, Release)	(THIS) 	PURE;

	// IPrepareInfo methods
    STDMETHOD	(GetPrepareInfoSize)	(THIS_ 
										/*[out]*/ ULONG __RPC_FAR *pcbPrepInfo) PURE;
        
	STDMETHOD	(GetPrepareInfo)		(THIS_
										/*[in/out]*/ unsigned char __RPC_FAR *pPrepInfo) PURE;
};


// @interface IGetDispenser | See class <c IGetDispenser>. 
// -----------------------------------------------------------------------
// @class IGetDispenser | Defines <i IGetDispenser>.<nl>
// Description:<nl>
// Usage:<nl>
// Notes:<nl>
//	UNDONE:
// .
// -----------------------------------------------------------------------
// @rev 0 | 03/28/95 |gaganc | created
// -----------------------------------------------------------------------
DECLARE_INTERFACE_ (IGetDispenser, IUnknown)			// @base public | IUnknown
{
	// IUnknown interface methods:
	STDMETHOD	(QueryInterface)	(THIS_ REFIID riid, LPVOID * ppv) PURE;
 	STDMETHOD_	(ULONG, AddRef)		(THIS) 	PURE;
 	STDMETHOD_	(ULONG, Release)	(THIS) 	PURE;

	// IGetDispenser methods
    STDMETHOD	(GetDispenser)		(THIS_
									/*[in]*/ REFIID rid,
									/*[in/out]*/ void** ppvObject) PURE;
};


// @interface ITransactionVoterNotifyAsync | <nl>. 
// -----------------------------------------------------------------------
// @class ITransactionVoterNotifyAsync | Defines <i ITransactionVoterNotifyAsync>.<nl>
// Description: This interface is implemented by a voters object.<nl>
// Usage: Register an object supporting this interface with the DTC proxy
//		  using the ITransactionVoterFactory::Create <nl>
// Notes:<nl>
//	UNDONE:
// .
// -----------------------------------------------------------------------
// @rev 0 | 05/01/95 | shaiwals | created
// -----------------------------------------------------------------------
DECLARE_INTERFACE_ (ITransactionVoterNotifyAsync, ITransactionOutcomeEvents)	
					// @base public | ITransactionOutcomeEvents
{
	// IUnknown interface methods:
	STDMETHOD	(QueryInterface)	(THIS_ REFIID riid, LPVOID * ppv) PURE;
 	STDMETHOD_	(ULONG, AddRef)		(THIS) 	PURE;
 	STDMETHOD_	(ULONG, Release)	(THIS) 	PURE;

	// ITransactionOutcomeEvents methods
    STDMETHOD	(Committed)			(THIS_
									/*[in]*/ BOOL fRetaining,
									/*[in]*/ XACTUOW __RPC_FAR *pNewUOW,
									/*[in]*/ HRESULT hr) PURE;
    
    STDMETHOD	(Aborted)			(THIS_
									/*[in]*/ BOID __RPC_FAR *pboidReason,
									/*[in]*/ BOOL fRetaining,
									/*[in]*/ XACTUOW __RPC_FAR *pNewUOW,
									/*[in]*/ HRESULT hr) PURE;
    
    STDMETHOD	(HeuristicDecision)	(THIS_
									/*[in]*/ DWORD dwDecision,
									/*[in]*/ BOID __RPC_FAR *pboidReason,
									/*[in]*/ HRESULT hr) PURE;
    
    STDMETHOD	(Indoubt)			(THIS) PURE;

	// ITransactionVoterNotifyAsync methods
	STDMETHOD	(VoteRequest)		(THIS) PURE;
};


// @interface ITransactionVoterBallotAsync | See class <c CImpTxVoterBallotAsync>. 
// -----------------------------------------------------------------------
// @class ITransactionVoterBallotAsync | Defines <i ITransactionVoterBallotAsync>.<nl>
// Description:<nl>
// Usage:<nl>
// Notes:<nl>
//	UNDONE:
// .
// -----------------------------------------------------------------------
// @rev 0 | 05/01/95 | shaiwals | created
// -----------------------------------------------------------------------
DECLARE_INTERFACE_ (ITransactionVoterBallotAsync, IUnknown)	// @base public | IUnknown
{
	// IUnknown interface methods:
	STDMETHOD	(QueryInterface)	(THIS_ REFIID riid, LPVOID * ppv) PURE;
 	STDMETHOD_	(ULONG, AddRef)		(THIS) 	PURE;
 	STDMETHOD_	(ULONG, Release)	(THIS) 	PURE;

	// ITransactionVoterBallotAsync methods
    STDMETHOD	(VoteRequestDone)	(THIS_
									/*[in]*/ HRESULT hr,
									/*[in]*/ BOID * pboidReason
									) PURE;
};


// @interface ITransactionVoterFactory | See class <c CImpTxVoterFactory>. 
// -----------------------------------------------------------------------
// @class ITransactionVoterFactory | Defines <i ITransactionVoterFactory>.<nl>
// Description:<nl>
// Usage:<nl>
// Notes:<nl>
//	UNDONE:
// .
// -----------------------------------------------------------------------
// @rev 0 | 05/01/95 | shaiwals | created
// -----------------------------------------------------------------------
DECLARE_INTERFACE_ (ITransactionVoterFactory, IUnknown)	// @base public | IUnknown
{
	// IUnknown interface methods:
	STDMETHOD	(QueryInterface)	(THIS_ REFIID riid, LPVOID * ppv) PURE;
 	STDMETHOD_	(ULONG, AddRef)		(THIS) 	PURE;
 	STDMETHOD_	(ULONG, Release)	(THIS) 	PURE;

	// ITransactionVoterFactory methods
    STDMETHOD	(Create)			(THIS_
									/*[in]*/ ITransaction * pTransaction,
									/*[in]*/ ITransactionVoterNotifyAsync * pVoterNotify,
									/*[in/out]*/ ITransactionVoterBallotAsync ** ppVoterBallot
									) PURE;
};


// @interface ITransactionTransmitter | See class <c CImpTxTransmitter>. 
// -----------------------------------------------------------------------
// @class ITransactionTransmitter | Defines <i ITransactionTransmitter>.<nl>
// Description:<nl>
// Usage:<nl>
// Notes:<nl>
//	UNDONE:
// .
// -----------------------------------------------------------------------
// @rev 0 | 05/01/95 | shaiwals | created
// -----------------------------------------------------------------------
DECLARE_INTERFACE_ (ITransactionTransmitter, IUnknown)	// @base public | IUnknown
{
	// IUnknown interface methods:
	STDMETHOD	(QueryInterface)	(THIS_ REFIID riid, LPVOID * ppv) PURE;
 	STDMETHOD_	(ULONG, AddRef)		(THIS) 	PURE;
 	STDMETHOD_	(ULONG, Release)	(THIS) 	PURE;

	// ITransactionTransmitter methods
    STDMETHOD	(Set)				(THIS_
									/*[in]*/ ITransaction * pTransaction
									) PURE;

	STDMETHOD	(GetPropagationTokenSize)(THIS_
									/*[in/out]*/ ULONG *pcbToken
									) PURE;

	STDMETHOD	(MarshalPropagationToken)(THIS_
									/*[in]*/ ULONG pcbToken,
									/*[in/out]*/ BYTE *rgbToken,
									/*[in/out]*/ ULONG *pcbUsed
									) PURE;

	STDMETHOD	(UnmarshalReturnToken)(THIS_
									/*[in]*/ ULONG pcbReturnToken,
									/*[in]*/ BYTE *rgbReturnToken
									) PURE;

	STDMETHOD	(Reset)				(THIS) PURE;
};


// @interface ITransactionTransmitterFactory | See class <c CImpTxTransmitterFactory>. 
// -----------------------------------------------------------------------
// @class ITransactionTransmitterFactory | Defines <i ITransactionTransmitterFactory>.<nl>
// Description:<nl>
// Usage:<nl>
// Notes:<nl>
//	UNDONE:
// .
// -----------------------------------------------------------------------
// @rev 0 | 05/01/95 | shaiwals | created
// -----------------------------------------------------------------------
DECLARE_INTERFACE_ (ITransactionTransmitterFactory, IUnknown)	// @base public | IUnknown
{
	// IUnknown interface methods:
	STDMETHOD	(QueryInterface)	(THIS_ REFIID riid, LPVOID * ppv) PURE;
 	STDMETHOD_	(ULONG, AddRef)		(THIS) 	PURE;
 	STDMETHOD_	(ULONG, Release)	(THIS) 	PURE;

	// ITransactionTransmitterFactory methods
    STDMETHOD	(Create)			( THIS_
									/*[in/out]*/ ITransactionTransmitter ** ppTransmitter
									) PURE;
};


// @interface ITransactionReceiver | See class <c CImpTxReceiver>. 
// -----------------------------------------------------------------------
// @class ITransactionReceiver | Defines <i ITransactionReceiver>.<nl>
// Description:<nl>
// Usage:<nl>
// Notes:<nl>
//	UNDONE:
// .
// -----------------------------------------------------------------------
// @rev 0 | 05/01/95 | shaiwals | created
// -----------------------------------------------------------------------
DECLARE_INTERFACE_ (ITransactionReceiver, IUnknown)	// @base public | IUnknown
{
	// IUnknown interface methods:
	STDMETHOD	(QueryInterface)	(THIS_ REFIID riid, LPVOID * ppv) PURE;
 	STDMETHOD_	(ULONG, AddRef)		(THIS) 	PURE;
 	STDMETHOD_	(ULONG, Release)	(THIS) 	PURE;

	// ITransactionReceiver methods
	STDMETHOD	(UnmarshalPropagationToken)(THIS_
									/*[in]*/ ULONG pcbToken,
									/*[in]*/ BYTE *rgbToken,
									/*[in/out]*/ ITransaction ** ppTransaction
									) PURE;

	STDMETHOD	(GetReturnTokenSize)(THIS_
									/*[in/out]*/ ULONG *pcbReturnToken
									) PURE;

	STDMETHOD	(MarshalReturnToken)(THIS_
									/*[in]*/ ULONG pcbReturnToken,
									/*[in\out]*/ BYTE *rgbReturnToken,
									/*[in\out]*/ ULONG *pcbUsed
									) PURE;

	STDMETHOD	(Reset)				(THIS) PURE;
};


// @interface ITransactionReceiverFactory | See class <c CImpTxReceiverFactory>. 
// -----------------------------------------------------------------------
// @class ITransactionReceiverFactory | Defines <i ITransactionReceiverFactory>.<nl>
// Description:<nl>
// Usage:<nl>
// Notes:<nl>
//	UNDONE:
// .
// -----------------------------------------------------------------------
// @rev 0 | 05/01/95 | shaiwals | created
// -----------------------------------------------------------------------
DECLARE_INTERFACE_ (ITransactionReceiverFactory, IUnknown)	// @base public | IUnknown
{
	// IUnknown interface methods:
	STDMETHOD	(QueryInterface)	(THIS_ REFIID riid, LPVOID * ppv) PURE;
 	STDMETHOD_	(ULONG, AddRef)		(THIS) 	PURE;
 	STDMETHOD_	(ULONG, Release)	(THIS) 	PURE;

	// ITransactionReceiverFactory methods
    STDMETHOD	(Create)			(THIS_
									/*[in/out]*/ ITransactionReceiver ** ppReceiver
									) PURE;
};


#endif 