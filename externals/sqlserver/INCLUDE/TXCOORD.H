//.-------------------------------------------------------------------------
//.
//.  Microsoft Windows
//.  Copyright (C) Microsoft Corporation, 1995.
//.
//.  File: txcoord.idl
//.
//.  Contents: Transaction types and interfaces related to
//.            transaction coordination.
//.
//.--------------------------------------------------------------------------


/* File created by MIDL compiler version 2.00.0102 */
/* at Wed Jan 24 15:45:40 1996
 */
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __txcoord_h__
#define __txcoord_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ITransactionResourceAsync_FWD_DEFINED__
#define __ITransactionResourceAsync_FWD_DEFINED__
typedef interface ITransactionResourceAsync ITransactionResourceAsync;
#endif 	/* __ITransactionResourceAsync_FWD_DEFINED__ */

#ifndef __ITransactionResource_FWD_DEFINED__
#define __ITransactionResource_FWD_DEFINED__
typedef interface ITransactionResource ITransactionResource;
#endif 	/* __ITransactionResource_FWD_DEFINED__ */



#ifndef __ITransactionEnlistmentAsync_FWD_DEFINED__
#define __ITransactionEnlistmentAsync_FWD_DEFINED__
typedef interface ITransactionEnlistmentAsync ITransactionEnlistmentAsync;
#endif 	/* __ITransactionEnlistmentAsync_FWD_DEFINED__ */


#ifndef __ITransactionExportFactory_FWD_DEFINED__
#define __ITransactionExportFactory_FWD_DEFINED__
typedef interface ITransactionExportFactory ITransactionExportFactory;
#endif 	/* __ITransactionExportFactory_FWD_DEFINED__ */


#ifndef __ITransactionImportWhereabouts_FWD_DEFINED__
#define __ITransactionImportWhereabouts_FWD_DEFINED__
typedef interface ITransactionImportWhereabouts ITransactionImportWhereabouts;
#endif 	/* __ITransactionImportWhereabouts_FWD_DEFINED__ */


#ifndef __ITransactionExport_FWD_DEFINED__
#define __ITransactionExport_FWD_DEFINED__
typedef interface ITransactionExport ITransactionExport;
#endif 	/* __ITransactionExport_FWD_DEFINED__ */


#ifndef __ITransactionImport_FWD_DEFINED__
#define __ITransactionImport_FWD_DEFINED__
typedef interface ITransactionImport ITransactionImport;
#endif 	/* __ITransactionImport_FWD_DEFINED__ */


/* header files for imported files */
#include "transact.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/****************************************
 * Generated header for interface: __MIDL__intf_0000
 * at Wed Jan 24 15:45:40 1996
 * using MIDL 2.00.0102
 ****************************************/
/* [local] */ 


			/* size is 0 */

			/* size is 0 */

			/* size is 0 */

			/* size is 0 */

			/* size is 0 */

			/* size is 0 */



extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_s_ifspec;

#ifndef __ITransactionResourceAsync_INTERFACE_DEFINED__
#define __ITransactionResourceAsync_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITransactionResourceAsync
 * at Wed Jan 24 15:45:40 1996
 * using MIDL 2.00.0102
 ****************************************/
/* [unique][uuid][object] */ 



EXTERN_C const IID IID_ITransactionResourceAsync;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ITransactionResourceAsync : public IUnknown
    {
    public:
        virtual HRESULT __stdcall PrepareRequest( 
            /* [in] */ BOOL fRetaining,
            /* [in] */ DWORD grfRM,
            /* [in] */ BOOL fWantMoniker,
            /* [in] */ BOOL fSinglePhase) = 0;
        
        virtual HRESULT __stdcall CommitRequest( 
            /* [in] */ DWORD grfRM,
            /* [in] */ XACTUOW __RPC_FAR *pNewUOW) = 0;
        
        virtual HRESULT __stdcall AbortRequest( 
            /* [in] */ BOID __RPC_FAR *pboidReason,
            /* [in] */ BOOL fRetaining,
            /* [in] */ XACTUOW __RPC_FAR *pNewUOW) = 0;
        
        virtual HRESULT __stdcall TMDown( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITransactionResourceAsyncVtbl
    {
        
        HRESULT ( __stdcall __RPC_FAR *QueryInterface )( 
            ITransactionResourceAsync __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( __stdcall __RPC_FAR *AddRef )( 
            ITransactionResourceAsync __RPC_FAR * This);
        
        ULONG ( __stdcall __RPC_FAR *Release )( 
            ITransactionResourceAsync __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *PrepareRequest )( 
            ITransactionResourceAsync __RPC_FAR * This,
            /* [in] */ BOOL fRetaining,
            /* [in] */ DWORD grfRM,
            /* [in] */ BOOL fWantMoniker,
            /* [in] */ BOOL fSinglePhase);
        
        HRESULT ( __stdcall __RPC_FAR *CommitRequest )( 
            ITransactionResourceAsync __RPC_FAR * This,
            /* [in] */ DWORD grfRM,
            /* [in] */ XACTUOW __RPC_FAR *pNewUOW);
        
        HRESULT ( __stdcall __RPC_FAR *AbortRequest )( 
            ITransactionResourceAsync __RPC_FAR * This,
            /* [in] */ BOID __RPC_FAR *pboidReason,
            /* [in] */ BOOL fRetaining,
            /* [in] */ XACTUOW __RPC_FAR *pNewUOW);
        
        HRESULT ( __stdcall __RPC_FAR *TMDown )( 
            ITransactionResourceAsync __RPC_FAR * This);
        
    } ITransactionResourceAsyncVtbl;

    interface ITransactionResourceAsync
    {
        CONST_VTBL struct ITransactionResourceAsyncVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransactionResourceAsync_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITransactionResourceAsync_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITransactionResourceAsync_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITransactionResourceAsync_PrepareRequest(This,fRetaining,grfRM,fWantMoniker,fSinglePhase)	\
    (This)->lpVtbl -> PrepareRequest(This,fRetaining,grfRM,fWantMoniker,fSinglePhase)

#define ITransactionResourceAsync_CommitRequest(This,grfRM,pNewUOW)	\
    (This)->lpVtbl -> CommitRequest(This,grfRM,pNewUOW)

#define ITransactionResourceAsync_AbortRequest(This,pboidReason,fRetaining,pNewUOW)	\
    (This)->lpVtbl -> AbortRequest(This,pboidReason,fRetaining,pNewUOW)

#define ITransactionResourceAsync_TMDown(This)	\
    (This)->lpVtbl -> TMDown(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ITransactionResourceAsync_PrepareRequest_Proxy( 
    ITransactionResourceAsync __RPC_FAR * This,
    /* [in] */ BOOL fRetaining,
    /* [in] */ DWORD grfRM,
    /* [in] */ BOOL fWantMoniker,
    /* [in] */ BOOL fSinglePhase);


void __RPC_STUB ITransactionResourceAsync_PrepareRequest_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ITransactionResourceAsync_CommitRequest_Proxy( 
    ITransactionResourceAsync __RPC_FAR * This,
    /* [in] */ DWORD grfRM,
    /* [in] */ XACTUOW __RPC_FAR *pNewUOW);


void __RPC_STUB ITransactionResourceAsync_CommitRequest_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ITransactionResourceAsync_AbortRequest_Proxy( 
    ITransactionResourceAsync __RPC_FAR * This,
    /* [in] */ BOID __RPC_FAR *pboidReason,
    /* [in] */ BOOL fRetaining,
    /* [in] */ XACTUOW __RPC_FAR *pNewUOW);


void __RPC_STUB ITransactionResourceAsync_AbortRequest_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ITransactionResourceAsync_TMDown_Proxy( 
    ITransactionResourceAsync __RPC_FAR * This);


void __RPC_STUB ITransactionResourceAsync_TMDown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITransactionResourceAsync_INTERFACE_DEFINED__ */


#ifndef __ITransactionResource_INTERFACE_DEFINED__
#define __ITransactionResource_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITransactionResource
 * at Wed Jan 24 15:45:40 1996
 * using MIDL 2.00.0102
 ****************************************/
/* [unique][uuid][object] */ 

EXTERN_C const IID IID_ITransactionResource;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ITransactionResource : public IUnknown
    {
    public:
        virtual HRESULT __stdcall PrepareRequest( 
            /* [in] */ BOOL fRetaining,
            /* [in] */ DWORD grfRM,
            /* [in] */ BOOL fWantMoniker,
            /* [in] */ BOOL fSinglePhase) = 0;
        
        virtual HRESULT __stdcall CommitRequest( 
            /* [in] */ DWORD grfRM,
            /* [in] */ XACTUOW __RPC_FAR *pNewUOW) = 0;
        
        virtual HRESULT __stdcall AbortRequest( 
            /* [in] */ BOID __RPC_FAR *pboidReason,
            /* [in] */ BOOL fRetaining,
            /* [in] */ XACTUOW __RPC_FAR *pNewUOW) = 0;
        
        virtual HRESULT __stdcall TMDown( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITransactionResourceVtbl
    {
        
        HRESULT ( __stdcall __RPC_FAR *QueryInterface )( 
            ITransactionResource __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( __stdcall __RPC_FAR *AddRef )( 
            ITransactionResource __RPC_FAR * This);
        
        ULONG ( __stdcall __RPC_FAR *Release )( 
            ITransactionResource __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *PrepareRequest )( 
            ITransactionResource __RPC_FAR * This,
            /* [in] */ BOOL fRetaining,
            /* [in] */ DWORD grfRM,
            /* [in] */ BOOL fWantMoniker,
            /* [in] */ BOOL fSinglePhase);
        
        HRESULT ( __stdcall __RPC_FAR *CommitRequest )( 
            ITransactionResource __RPC_FAR * This,
            /* [in] */ DWORD grfRM,
            /* [in] */ XACTUOW __RPC_FAR *pNewUOW);
        
        HRESULT ( __stdcall __RPC_FAR *AbortRequest )( 
            ITransactionResource __RPC_FAR * This,
            /* [in] */ BOID __RPC_FAR *pboidReason,
            /* [in] */ BOOL fRetaining,
            /* [in] */ XACTUOW __RPC_FAR *pNewUOW);
        
        HRESULT ( __stdcall __RPC_FAR *TMDown )( 
            ITransactionResource __RPC_FAR * This);
        
    } ITransactionResourceVtbl;

    interface ITransactionResource
    {
        CONST_VTBL struct ITransactionResourceVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransactionResource_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITransactionResource_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITransactionResource_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITransactionResource_PrepareRequest(This,fRetaining,grfRM,fWantMoniker,fSinglePhase)	\
    (This)->lpVtbl -> PrepareRequest(This,fRetaining,grfRM,fWantMoniker,fSinglePhase)

#define ITransactionResource_CommitRequest(This,grfRM,pNewUOW)	\
    (This)->lpVtbl -> CommitRequest(This,grfRM,pNewUOW)

#define ITransactionResource_AbortRequest(This,pboidReason,fRetaining,pNewUOW)	\
    (This)->lpVtbl -> AbortRequest(This,pboidReason,fRetaining,pNewUOW)

#define ITransactionResource_TMDown(This)	\
    (This)->lpVtbl -> TMDown(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ITransactionResource_PrepareRequest_Proxy( 
    ITransactionResourceAsync __RPC_FAR * This,
    /* [in] */ BOOL fRetaining,
    /* [in] */ DWORD grfRM,
    /* [in] */ BOOL fWantMoniker,
    /* [in] */ BOOL fSinglePhase);


void __RPC_STUB ITransactionResource_PrepareRequest_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ITransactionResource_CommitRequest_Proxy( 
    ITransactionResourceAsync __RPC_FAR * This,
    /* [in] */ DWORD grfRM,
    /* [in] */ XACTUOW __RPC_FAR *pNewUOW);


void __RPC_STUB ITransactionResource_CommitRequest_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ITransactionResource_AbortRequest_Proxy( 
    ITransactionResourceAsync __RPC_FAR * This,
    /* [in] */ BOID __RPC_FAR *pboidReason,
    /* [in] */ BOOL fRetaining,
    /* [in] */ XACTUOW __RPC_FAR *pNewUOW);


void __RPC_STUB ITransactionResource_AbortRequest_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ITransactionResource_TMDown_Proxy( 
    ITransactionResourceAsync __RPC_FAR * This);


void __RPC_STUB ITransactionResource_TMDown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITransactionResource_INTERFACE_DEFINED__ */




#ifndef __ITransactionEnlistmentAsync_INTERFACE_DEFINED__
#define __ITransactionEnlistmentAsync_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITransactionEnlistmentAsync
 * at Wed Jan 24 15:45:40 1996
 * using MIDL 2.00.0102
 ****************************************/
/* [unique][uuid][object] */ 



EXTERN_C const IID IID_ITransactionEnlistmentAsync;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ITransactionEnlistmentAsync : public IUnknown
    {
    public:
        virtual HRESULT __stdcall PrepareRequestDone( 
            /* [in] */ HRESULT hr,
            /* [in] */ IMoniker __RPC_FAR *pmk,
            /* [in] */ BOID __RPC_FAR *pboidReason) = 0;
        
        virtual HRESULT __stdcall CommitRequestDone( 
            /* [in] */ HRESULT hr) = 0;
        
        virtual HRESULT __stdcall AbortRequestDone( 
            /* [in] */ HRESULT hr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITransactionEnlistmentAsyncVtbl
    {
        
        HRESULT ( __stdcall __RPC_FAR *QueryInterface )( 
            ITransactionEnlistmentAsync __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( __stdcall __RPC_FAR *AddRef )( 
            ITransactionEnlistmentAsync __RPC_FAR * This);
        
        ULONG ( __stdcall __RPC_FAR *Release )( 
            ITransactionEnlistmentAsync __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *PrepareRequestDone )( 
            ITransactionEnlistmentAsync __RPC_FAR * This,
            /* [in] */ HRESULT hr,
            /* [in] */ IMoniker __RPC_FAR *pmk,
            /* [in] */ BOID __RPC_FAR *pboidReason);
        
        HRESULT ( __stdcall __RPC_FAR *CommitRequestDone )( 
            ITransactionEnlistmentAsync __RPC_FAR * This,
            /* [in] */ HRESULT hr);
        
        HRESULT ( __stdcall __RPC_FAR *AbortRequestDone )( 
            ITransactionEnlistmentAsync __RPC_FAR * This,
            /* [in] */ HRESULT hr);
        
    } ITransactionEnlistmentAsyncVtbl;

    interface ITransactionEnlistmentAsync
    {
        CONST_VTBL struct ITransactionEnlistmentAsyncVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransactionEnlistmentAsync_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITransactionEnlistmentAsync_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITransactionEnlistmentAsync_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITransactionEnlistmentAsync_PrepareRequestDone(This,hr,pmk,pboidReason)	\
    (This)->lpVtbl -> PrepareRequestDone(This,hr,pmk,pboidReason)

#define ITransactionEnlistmentAsync_CommitRequestDone(This,hr)	\
    (This)->lpVtbl -> CommitRequestDone(This,hr)

#define ITransactionEnlistmentAsync_AbortRequestDone(This,hr)	\
    (This)->lpVtbl -> AbortRequestDone(This,hr)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ITransactionEnlistmentAsync_PrepareRequestDone_Proxy( 
    ITransactionEnlistmentAsync __RPC_FAR * This,
    /* [in] */ HRESULT hr,
    /* [in] */ IMoniker __RPC_FAR *pmk,
    /* [in] */ BOID __RPC_FAR *pboidReason);


void __RPC_STUB ITransactionEnlistmentAsync_PrepareRequestDone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ITransactionEnlistmentAsync_CommitRequestDone_Proxy( 
    ITransactionEnlistmentAsync __RPC_FAR * This,
    /* [in] */ HRESULT hr);


void __RPC_STUB ITransactionEnlistmentAsync_CommitRequestDone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ITransactionEnlistmentAsync_AbortRequestDone_Proxy( 
    ITransactionEnlistmentAsync __RPC_FAR * This,
    /* [in] */ HRESULT hr);


void __RPC_STUB ITransactionEnlistmentAsync_AbortRequestDone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITransactionEnlistmentAsync_INTERFACE_DEFINED__ */


#ifndef __ITransactionExportFactory_INTERFACE_DEFINED__
#define __ITransactionExportFactory_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITransactionExportFactory
 * at Wed Jan 24 15:45:40 1996
 * using MIDL 2.00.0102
 ****************************************/
/* [unique][uuid][object] */ 



EXTERN_C const IID IID_ITransactionExportFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ITransactionExportFactory : public IUnknown
    {
    public:
        virtual HRESULT __stdcall GetRemoteClassId( 
            /* [out] */ CLSID __RPC_FAR *pclsid) = 0;
        
        virtual HRESULT __stdcall Create( 
            /* [in] */ ULONG cbWhereabouts,
            /* [size_is][in] */ BYTE __RPC_FAR *rgbWhereabouts,
            /* [out] */ ITransactionExport __RPC_FAR *__RPC_FAR *ppExport) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITransactionExportFactoryVtbl
    {
        
        HRESULT ( __stdcall __RPC_FAR *QueryInterface )( 
            ITransactionExportFactory __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( __stdcall __RPC_FAR *AddRef )( 
            ITransactionExportFactory __RPC_FAR * This);
        
        ULONG ( __stdcall __RPC_FAR *Release )( 
            ITransactionExportFactory __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *GetRemoteClassId )( 
            ITransactionExportFactory __RPC_FAR * This,
            /* [out] */ CLSID __RPC_FAR *pclsid);
        
        HRESULT ( __stdcall __RPC_FAR *Create )( 
            ITransactionExportFactory __RPC_FAR * This,
            /* [in] */ ULONG cbWhereabouts,
            /* [size_is][in] */ BYTE __RPC_FAR *rgbWhereabouts,
            /* [out] */ ITransactionExport __RPC_FAR *__RPC_FAR *ppExport);
        
    } ITransactionExportFactoryVtbl;

    interface ITransactionExportFactory
    {
        CONST_VTBL struct ITransactionExportFactoryVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransactionExportFactory_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITransactionExportFactory_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITransactionExportFactory_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITransactionExportFactory_GetRemoteClassId(This,pclsid)	\
    (This)->lpVtbl -> GetRemoteClassId(This,pclsid)

#define ITransactionExportFactory_Create(This,cbWhereabouts,rgbWhereabouts,ppExport)	\
    (This)->lpVtbl -> Create(This,cbWhereabouts,rgbWhereabouts,ppExport)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ITransactionExportFactory_GetRemoteClassId_Proxy( 
    ITransactionExportFactory __RPC_FAR * This,
    /* [out] */ CLSID __RPC_FAR *pclsid);


void __RPC_STUB ITransactionExportFactory_GetRemoteClassId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall ITransactionExportFactory_Create_Proxy( 
    ITransactionExportFactory __RPC_FAR * This,
    /* [in] */ ULONG cbWhereabouts,
    /* [size_is][in] */ BYTE __RPC_FAR *rgbWhereabouts,
    /* [out] */ ITransactionExport __RPC_FAR *__RPC_FAR *ppExport);


void __RPC_STUB ITransactionExportFactory_Create_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITransactionExportFactory_INTERFACE_DEFINED__ */


#ifndef __ITransactionImportWhereabouts_INTERFACE_DEFINED__
#define __ITransactionImportWhereabouts_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITransactionImportWhereabouts
 * at Wed Jan 24 15:45:40 1996
 * using MIDL 2.00.0102
 ****************************************/
/* [unique][uuid][object] */ 



EXTERN_C const IID IID_ITransactionImportWhereabouts;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ITransactionImportWhereabouts : public IUnknown
    {
    public:
        virtual HRESULT __stdcall GetWhereaboutsSize( 
            /* [out] */ ULONG __RPC_FAR *pcbWhereabouts) = 0;
        
        virtual /* [local] */ HRESULT __stdcall GetWhereabouts( 
            /* [in] */ ULONG cbWhereabouts,
            /* [size_is][out] */ BYTE __RPC_FAR *rgbWhereabouts,
            /* [out] */ ULONG __RPC_FAR *pcbUsed) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITransactionImportWhereaboutsVtbl
    {
        
        HRESULT ( __stdcall __RPC_FAR *QueryInterface )( 
            ITransactionImportWhereabouts __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( __stdcall __RPC_FAR *AddRef )( 
            ITransactionImportWhereabouts __RPC_FAR * This);
        
        ULONG ( __stdcall __RPC_FAR *Release )( 
            ITransactionImportWhereabouts __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *GetWhereaboutsSize )( 
            ITransactionImportWhereabouts __RPC_FAR * This,
            /* [out] */ ULONG __RPC_FAR *pcbWhereabouts);
        
        /* [local] */ HRESULT ( __stdcall __RPC_FAR *GetWhereabouts )( 
            ITransactionImportWhereabouts __RPC_FAR * This,
            /* [in] */ ULONG cbWhereabouts,
            /* [size_is][out] */ BYTE __RPC_FAR *rgbWhereabouts,
            /* [out] */ ULONG __RPC_FAR *pcbUsed);
        
    } ITransactionImportWhereaboutsVtbl;

    interface ITransactionImportWhereabouts
    {
        CONST_VTBL struct ITransactionImportWhereaboutsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransactionImportWhereabouts_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITransactionImportWhereabouts_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITransactionImportWhereabouts_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITransactionImportWhereabouts_GetWhereaboutsSize(This,pcbWhereabouts)	\
    (This)->lpVtbl -> GetWhereaboutsSize(This,pcbWhereabouts)

#define ITransactionImportWhereabouts_GetWhereabouts(This,cbWhereabouts,rgbWhereabouts,pcbUsed)	\
    (This)->lpVtbl -> GetWhereabouts(This,cbWhereabouts,rgbWhereabouts,pcbUsed)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ITransactionImportWhereabouts_GetWhereaboutsSize_Proxy( 
    ITransactionImportWhereabouts __RPC_FAR * This,
    /* [out] */ ULONG __RPC_FAR *pcbWhereabouts);


void __RPC_STUB ITransactionImportWhereabouts_GetWhereaboutsSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall ITransactionImportWhereabouts_RemoteGetWhereabouts_Proxy( 
    ITransactionImportWhereabouts __RPC_FAR * This,
    /* [out] */ ULONG __RPC_FAR *pcbUsed,
    /* [in] */ ULONG cbWhereabouts,
    /* [length_is][size_is][out] */ BYTE __RPC_FAR *rgbWhereabouts);


void __RPC_STUB ITransactionImportWhereabouts_RemoteGetWhereabouts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITransactionImportWhereabouts_INTERFACE_DEFINED__ */


#ifndef __ITransactionExport_INTERFACE_DEFINED__
#define __ITransactionExport_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITransactionExport
 * at Wed Jan 24 15:45:40 1996
 * using MIDL 2.00.0102
 ****************************************/
/* [unique][uuid][object] */ 



EXTERN_C const IID IID_ITransactionExport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ITransactionExport : public IUnknown
    {
    public:
        virtual HRESULT __stdcall Export( 
            /* [in] */ IUnknown __RPC_FAR *punkTransaction,
            /* [out] */ ULONG __RPC_FAR *pcbTransactionCookie) = 0;
        
        virtual /* [local] */ HRESULT __stdcall GetTransactionCookie( 
            /* [in] */ IUnknown __RPC_FAR *punkTransaction,
            /* [in] */ ULONG cbTransactionCookie,
            /* [size_is][out] */ BYTE __RPC_FAR *rgbTransactionCookie,
            /* [out] */ ULONG __RPC_FAR *pcbUsed) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITransactionExportVtbl
    {
        
        HRESULT ( __stdcall __RPC_FAR *QueryInterface )( 
            ITransactionExport __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( __stdcall __RPC_FAR *AddRef )( 
            ITransactionExport __RPC_FAR * This);
        
        ULONG ( __stdcall __RPC_FAR *Release )( 
            ITransactionExport __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *Export )( 
            ITransactionExport __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *punkTransaction,
            /* [out] */ ULONG __RPC_FAR *pcbTransactionCookie);
        
        /* [local] */ HRESULT ( __stdcall __RPC_FAR *GetTransactionCookie )( 
            ITransactionExport __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *punkTransaction,
            /* [in] */ ULONG cbTransactionCookie,
            /* [size_is][out] */ BYTE __RPC_FAR *rgbTransactionCookie,
            /* [out] */ ULONG __RPC_FAR *pcbUsed);
        
    } ITransactionExportVtbl;

    interface ITransactionExport
    {
        CONST_VTBL struct ITransactionExportVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransactionExport_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITransactionExport_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITransactionExport_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITransactionExport_Export(This,punkTransaction,pcbTransactionCookie)	\
    (This)->lpVtbl -> Export(This,punkTransaction,pcbTransactionCookie)

#define ITransactionExport_GetTransactionCookie(This,punkTransaction,cbTransactionCookie,rgbTransactionCookie,pcbUsed)	\
    (This)->lpVtbl -> GetTransactionCookie(This,punkTransaction,cbTransactionCookie,rgbTransactionCookie,pcbUsed)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ITransactionExport_Export_Proxy( 
    ITransactionExport __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *punkTransaction,
    /* [out] */ ULONG __RPC_FAR *pcbTransactionCookie);


void __RPC_STUB ITransactionExport_Export_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall ITransactionExport_RemoteGetTransactionCookie_Proxy( 
    ITransactionExport __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *punkTransaction,
    /* [out] */ ULONG __RPC_FAR *pcbUsed,
    /* [in] */ ULONG cbTransactionCookie,
    /* [length_is][size_is][out] */ BYTE __RPC_FAR *rgbTransactionCookie);


void __RPC_STUB ITransactionExport_RemoteGetTransactionCookie_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITransactionExport_INTERFACE_DEFINED__ */


#ifndef __ITransactionImport_INTERFACE_DEFINED__
#define __ITransactionImport_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ITransactionImport
 * at Wed Jan 24 15:45:40 1996
 * using MIDL 2.00.0102
 ****************************************/
/* [unique][uuid][object] */ 



EXTERN_C const IID IID_ITransactionImport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ITransactionImport : public IUnknown
    {
    public:
        virtual HRESULT __stdcall Import( 
            /* [in] */ ULONG cbTransactionCookie,
            /* [size_is][in] */ BYTE __RPC_FAR *rgbTransactionCookie,
            /* [in] */ IID __RPC_FAR *piid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvTransaction) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITransactionImportVtbl
    {
        
        HRESULT ( __stdcall __RPC_FAR *QueryInterface )( 
            ITransactionImport __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( __stdcall __RPC_FAR *AddRef )( 
            ITransactionImport __RPC_FAR * This);
        
        ULONG ( __stdcall __RPC_FAR *Release )( 
            ITransactionImport __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *Import )( 
            ITransactionImport __RPC_FAR * This,
            /* [in] */ ULONG cbTransactionCookie,
            /* [size_is][in] */ BYTE __RPC_FAR *rgbTransactionCookie,
            /* [in] */ IID __RPC_FAR *piid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvTransaction);
        
    } ITransactionImportVtbl;

    interface ITransactionImport
    {
        CONST_VTBL struct ITransactionImportVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransactionImport_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITransactionImport_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITransactionImport_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITransactionImport_Import(This,cbTransactionCookie,rgbTransactionCookie,piid,ppvTransaction)	\
    (This)->lpVtbl -> Import(This,cbTransactionCookie,rgbTransactionCookie,piid,ppvTransaction)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ITransactionImport_Import_Proxy( 
    ITransactionImport __RPC_FAR * This,
    /* [in] */ ULONG cbTransactionCookie,
    /* [size_is][in] */ BYTE __RPC_FAR *rgbTransactionCookie,
    /* [in] */ IID __RPC_FAR *piid,
    /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvTransaction);


void __RPC_STUB ITransactionImport_Import_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITransactionImport_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* [local] */ HRESULT __stdcall ITransactionImportWhereabouts_GetWhereabouts_Proxy( 
    ITransactionImportWhereabouts __RPC_FAR * This,
    /* [in] */ ULONG cbWhereabouts,
    /* [size_is][out] */ BYTE __RPC_FAR *rgbWhereabouts,
    /* [out] */ ULONG __RPC_FAR *pcbUsed);


/* [call_as] */ HRESULT __stdcall ITransactionImportWhereabouts_GetWhereabouts_Stub( 
    ITransactionImportWhereabouts __RPC_FAR * This,
    /* [out] */ ULONG __RPC_FAR *pcbUsed,
    /* [in] */ ULONG cbWhereabouts,
    /* [length_is][size_is][out] */ BYTE __RPC_FAR *rgbWhereabouts);

/* [local] */ HRESULT __stdcall ITransactionExport_GetTransactionCookie_Proxy( 
    ITransactionExport __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *punkTransaction,
    /* [in] */ ULONG cbTransactionCookie,
    /* [size_is][out] */ BYTE __RPC_FAR *rgbTransactionCookie,
    /* [out] */ ULONG __RPC_FAR *pcbUsed);


/* [call_as] */ HRESULT __stdcall ITransactionExport_GetTransactionCookie_Stub( 
    ITransactionExport __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *punkTransaction,
    /* [out] */ ULONG __RPC_FAR *pcbUsed,
    /* [in] */ ULONG cbTransactionCookie,
    /* [length_is][size_is][out] */ BYTE __RPC_FAR *rgbTransactionCookie);



/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif

///////////////////////////////////////////////////////////////////////
//
// IID definitions for interfaces defined in this header file
//

#if !defined(_txcoord_iid_) && defined(INITGUID)
#define      _txcoord_iid_
const IID IID_ITransactionResourceAsync = {0x69E971F0,0x23CE,0x11cf,{0xAD,0x60,0x00,0xAA,0x00,0xA7,0x4C,0xCD}};
const IID IID_ITransactionResource = {0xEE5FF7B3,0x4572,0x11d0,{0x94,0x52,0x00,0xA0,0xC9,0x05,0x41,0x6E}};
const IID IID_ITransactionEnlistmentAsync = {0x0fb15081,0xaf41,0x11ce,{0xbd,0x2b,0x20,0x4c,0x4f,0x4f,0x50,0x20}};
const IID IID_ITransactionExportFactory = {0xE1CF9B53,0x8745,0x11ce,{0xA9,0xBA,0x00,0xAA,0x00,0x6C,0x37,0x06}};
const IID IID_ITransactionImportWhereabouts = {0x0141fda4,0x8fc0,0x11ce,{0xbd,0x18,0x20,0x4c,0x4f,0x4f,0x50,0x20}};
const IID IID_ITransactionExport = {0x0141fda5,0x8fc0,0x11ce,{0xbd,0x18,0x20,0x4c,0x4f,0x4f,0x50,0x20}};
const IID IID_ITransactionImport = {0xE1CF9B5A,0x8745,0x11ce,{0xA9,0xBA,0x00,0xAA,0x00,0x6C,0x37,0x06}};
#endif

///////////////////////////////////////////////////////////////////////

