/* ----------------------------------------------------------------------------
Microsoft	D.T.C (Distributed Transaction Coordinator)

(c)	1995	Microsoft Corporation.	All Rights Reserved


@module		XOLEHLP.H	|
		// contains DTC helper APIs used by SQL Server and application clients
		// to obtain the transaction manager
-------------------------------------------------------------------------------
@rev	0	|	13-Mar-1995	|	GaganC	|	Created
----------------------------------------------------------------------------- */

#ifndef __XOLEHLP__H__
#define __XOLEHLP__H__


//----------------------------------------
//	All defines and constants go here
//----------------------------------------
#define EXPORTAPI __declspec( dllexport )HRESULT

//----------------------------------------
//	All function prototypes go here
//----------------------------------------

//This API should be used to obtain an IUnknown or a ITransactionDispenser
//interface from the Microsoft Distributed Transaction Coordinator's proxy.
//Typically, a NULL is passed for the host name and the TM Name. In which 
//case the MS DTC on the same host is contacted and the interface provided
//for it.
EXPORTAPI DtcGetTransactionManager( char *  pszHost,
									char *	pszTmName,
									/* in */ REFIID rid,
								    /* in */ DWORD	dwReserved1,
								    /* in */ WORD	wcbReserved2,
								    /* in */ void FAR * pvReserved2,
									/*out */ void** ppvObject
									)	;
EXTERN_C EXPORTAPI DtcGetTransactionManagerC
									(	char *  pszHost,
										char *	pszTmName,
										/* in */ REFIID rid,
										/* in */ DWORD	dwReserved1,
										/* in */ WORD	wcbReserved2,
										/* in */ void FAR * pvReserved2,
										/*out */ void** ppvObject
									);



//The following API is here for historical purpose only and should
//not be used as it will be phased out eventually.
EXPORTAPI  DtcSelectTransactionManager( 	char *  pszHost,
										char *	pszTmName,
									   /* in */ REFIID rid,
									   /* in */ DWORD	dwReserved1,
									   /* in */ WORD	wcbReserved2,
									   /* in */ void FAR * pvReserved2,
									   /*out */ void** ppvObject ) ;


#endif // __XOLEHLP__H__
