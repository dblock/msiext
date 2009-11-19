
#include "rpc.h"
#include "rpcndr.h"

#ifndef __sqlnsx_h__
#define __sqlnsx_h__

#ifndef DO_ODL_TYPDEFS_
#define DO_ODL_TYPDEFS_
#define DO_HELP_CONSTANTS_
#include "sqlnsdef.h"
#endif

#ifdef __cplusplus

extern "C"{

#ifndef SQLNS_INTERNAL 

#define ISQLNSDispatch IDispatch

// Repeat the IDispatch members because C doesn't provide inheritance.
#define SQLNS_DISPATCH_BASE(itf)															\
		STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID * ppvObj) PURE;				\
		STDMETHOD_(ULONG,AddRef) (THIS) PURE;												\
		STDMETHOD_(ULONG,Release) (THIS) PURE;												\
		STDMETHOD(GetTypeInfoCount)(THIS_ UINT * pcTypeInfo) PURE;							\
		STDMETHOD(GetTypeInfo)(THIS_ UINT iTypeInfo, LCID lcid, ITypeInfo ** ppTI) PURE;	\
		STDMETHOD(GetIDsOfNames)(THIS_ REFIID riid, LPOLESTR * rgszNames, UINT cNames,		\
								LCID lcid, DISPID * rgdispid) PURE;							\
		STDMETHOD(Invoke)(THIS_ DISPID dispidMember, REFIID riid, LCID lcid, WORD wFlags,	\
								DISPPARAMS * pdispparams, LPVARIANT pvarResult,				\
								LPEXCEPINFO pexcepinfo, UINT * puArgErr) PURE;

#endif	// ndef SQLNS_INTERNAL

#endif 

/* Forward Declarations */ 

#ifndef __ISQLNamespace_FWD_DEFINED__
#define __ISQLNamespace_FWD_DEFINED__
typedef interface ISQLNamespace ISQLNamespace;
#endif 	/* __ISQLNamespace_FWD_DEFINED__ */


#ifndef __ISQLNamespaceObject_FWD_DEFINED__
#define __ISQLNamespaceObject_FWD_DEFINED__
typedef interface ISQLNamespaceObject ISQLNamespaceObject;
#endif 	/* __ISQLNamespaceObject_FWD_DEFINED__ */


#ifndef __ISQLNamespaceCommand_FWD_DEFINED__
#define __ISQLNamespaceCommand_FWD_DEFINED__
typedef interface ISQLNamespaceCommand ISQLNamespaceCommand;
#endif 	/* __ISQLNamespaceCommand_FWD_DEFINED__ */


#ifndef __ISQLNamespaceCommands_FWD_DEFINED__
#define __ISQLNamespaceCommands_FWD_DEFINED__
typedef interface ISQLNamespaceCommands ISQLNamespaceCommands;
#endif 	/* __ISQLNamespaceCommands_FWD_DEFINED__ */


#ifndef __SQLNamespace_FWD_DEFINED__
#define __SQLNamespace_FWD_DEFINED__

#ifdef __cplusplus
typedef class SQLNamespace SQLNamespace;
#else
typedef struct SQLNamespace SQLNamespace;
#endif /* __cplusplus */

#endif 	/* __SQLNamespace_FWD_DEFINED__ */


void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 


#ifndef __SQLNS_LIBRARY_DEFINED__
#define __SQLNS_LIBRARY_DEFINED__

/****************************************
 * Generated header for library: SQLNS
 * at Sat Nov 29 12:59:01 1997
 * using MIDL 3.01.75
 ****************************************/
/* [helpcontext][helpstring][helpfile][lcid][uuid][version] */ 







DEFINE_GUID(LIBID_SQLNS,0x00026f30,0xEB1C,0x11cf,0xAE,0x6E,0x00,0xAA,0x00,0x4A,0x34,0xD5);

#ifndef __ISQLNamespace_INTERFACE_DEFINED__
#define __ISQLNamespace_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ISQLNamespace
 * at Sat Nov 29 12:59:01 1997
 * using MIDL 3.01.75
 ****************************************/
/* [object][helpcontext][helpstring][uuid][nonextensible][dual] */ 



DEFINE_GUID(IID_ISQLNamespace,0x00026f20,0xEB1C,0x11cf,0xAE,0x6E,0x00,0xAA,0x00,0x4A,0x34,0xD5);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //interface DECLSPEC_UUID("00026f20-EB1C-11cf-AE6E-00AA004A34D5")
    //ISQLNamespace
    //{
    //public:
	DECLARE_INTERFACE_(ISQLNamespace, ISQLNSDispatch)
	{
		SQLNS_DISPATCH_BASE(ISQLNamespace);
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ BSTR bstrAppName,
            /* [optional][in] */ SQLNSRootType rootType,
            /* [optional][in] */ VARIANT * pRootInfo,
            /* [optional][in] */ long hWnd) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRootItem( 
            /* [retval][out] */ HSQLNSITEM __RPC_FAR *pItemOut) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE GetChildrenCount( 
            /* [in] */ HSQLNSITEM ItemIn,
            /* [retval][out] */ long __RPC_FAR *pRetVal) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFirstChildItem( 
            /* [in] */ HSQLNSITEM ItemIn,
            /* [optional][in] */ SQLNSObjectType matchType,
            /* [optional][in] */ BSTR matchName,
            /* [retval][out] */ HSQLNSITEM __RPC_FAR *pItemOut) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNextSiblingItem( 
            /* [in] */ HSQLNSITEM ItemIn,
            /* [optional][in] */ SQLNSObjectType matchType,
            /* [optional][in] */ BSTR matchName,
            /* [retval][out] */ HSQLNSITEM __RPC_FAR *pItemOut) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPreviousSiblingItem( 
            /* [in] */ HSQLNSITEM ItemIn,
            /* [optional][in] */ SQLNSObjectType matchType,
            /* [optional][in] */ BSTR matchName,
            /* [retval][out] */ HSQLNSITEM __RPC_FAR *pItemOut) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE GetParentItem( 
            /* [in] */ HSQLNSITEM ItemIn,
            /* [retval][out] */ HSQLNSITEM __RPC_FAR *pItemOut) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE GetName( 
            /* [in] */ HSQLNSITEM ItemIn,
            /* [retval][out] */ BSTR __RPC_FAR *pRetVal) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE GetType( 
            /* [in] */ HSQLNSITEM ItemIn,
            /* [retval][out] */ SQLNSObjectType __RPC_FAR *pRetVal) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSQLNamespaceObject( 
            /* [in] */ HSQLNSITEM ItemIn,
            /* [retval][out] */ ISQLNamespaceObject __RPC_FAR *__RPC_FAR *pRetVal) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSQLDMOObject( 
            /* [in] */ HSQLNSITEM ItemIn,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pRetVal) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( 
            /* [in] */ HSQLNSITEM ItemIn) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE SetLCID( 
            /* [in] */ long lcid) = 0;
    };
    
#else 	/* C style interface */

    typedef struct ISQLNamespaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISQLNamespace __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISQLNamespace __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISQLNamespace __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISQLNamespace __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISQLNamespace __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISQLNamespace __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISQLNamespace __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Initialize )( 
            ISQLNamespace __RPC_FAR * This,
            /* [in] */ BSTR bstrAppName,
            /* [optional][in] */ SQLNSRootType rootType,
            /* [optional][in] */ VARIANT * pRootInfo,
            /* [optional][in] */ long hWnd);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRootItem )( 
            ISQLNamespace __RPC_FAR * This,
            /* [retval][out] */ HSQLNSITEM __RPC_FAR *pItemOut);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetChildrenCount )( 
            ISQLNamespace __RPC_FAR * This,
            /* [in] */ HSQLNSITEM ItemIn,
            /* [retval][out] */ long __RPC_FAR *pRetVal);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFirstChildItem )( 
            ISQLNamespace __RPC_FAR * This,
            /* [in] */ HSQLNSITEM ItemIn,
            /* [optional][in] */ SQLNSObjectType matchType,
            /* [optional][in] */ BSTR matchName,
            /* [retval][out] */ HSQLNSITEM __RPC_FAR *pItemOut);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNextSiblingItem )( 
            ISQLNamespace __RPC_FAR * This,
            /* [in] */ HSQLNSITEM ItemIn,
            /* [optional][in] */ SQLNSObjectType matchType,
            /* [optional][in] */ BSTR matchName,
            /* [retval][out] */ HSQLNSITEM __RPC_FAR *pItemOut);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPreviousSiblingItem )( 
            ISQLNamespace __RPC_FAR * This,
            /* [in] */ HSQLNSITEM ItemIn,
            /* [optional][in] */ SQLNSObjectType matchType,
            /* [optional][in] */ BSTR matchName,
            /* [retval][out] */ HSQLNSITEM __RPC_FAR *pItemOut);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetParentItem )( 
            ISQLNamespace __RPC_FAR * This,
            /* [in] */ HSQLNSITEM ItemIn,
            /* [retval][out] */ HSQLNSITEM __RPC_FAR *pItemOut);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetName )( 
            ISQLNamespace __RPC_FAR * This,
            /* [in] */ HSQLNSITEM ItemIn,
            /* [retval][out] */ BSTR __RPC_FAR *pRetVal);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetType )( 
            ISQLNamespace __RPC_FAR * This,
            /* [in] */ HSQLNSITEM ItemIn,
            /* [retval][out] */ SQLNSObjectType __RPC_FAR *pRetVal);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSQLNamespaceObject )( 
            ISQLNamespace __RPC_FAR * This,
            /* [in] */ HSQLNSITEM ItemIn,
            /* [retval][out] */ ISQLNamespaceObject __RPC_FAR *__RPC_FAR *pRetVal);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSQLDMOObject )( 
            ISQLNamespace __RPC_FAR * This,
            /* [in] */ HSQLNSITEM ItemIn,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pRetVal);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Refresh )( 
            ISQLNamespace __RPC_FAR * This,
            /* [in] */ HSQLNSITEM ItemIn);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLCID )( 
            ISQLNamespace __RPC_FAR * This,
            /* [in] */ long lcid);
        
        END_INTERFACE
    } ISQLNamespaceVtbl;

    interface ISQLNamespace
    {
        CONST_VTBL struct ISQLNamespaceVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISQLNamespace_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISQLNamespace_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISQLNamespace_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISQLNamespace_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISQLNamespace_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISQLNamespace_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISQLNamespace_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISQLNamespace_Initialize(This,bstrAppName,rootType,pRootInfo,hWnd)	\
    (This)->lpVtbl -> Initialize(This,bstrAppName,rootType,pRootInfo,hWnd)

#define ISQLNamespace_GetRootItem(This,pItemOut)	\
    (This)->lpVtbl -> GetRootItem(This,pItemOut)

#define ISQLNamespace_GetChildrenCount(This,ItemIn,pRetVal)	\
    (This)->lpVtbl -> GetChildrenCount(This,ItemIn,pRetVal)

#define ISQLNamespace_GetFirstChildItem(This,ItemIn,matchType,matchName,pItemOut)	\
    (This)->lpVtbl -> GetFirstChildItem(This,ItemIn,matchType,matchName,pItemOut)

#define ISQLNamespace_GetNextSiblingItem(This,ItemIn,matchType,matchName,pItemOut)	\
    (This)->lpVtbl -> GetNextSiblingItem(This,ItemIn,matchType,matchName,pItemOut)

#define ISQLNamespace_GetPreviousSiblingItem(This,ItemIn,matchType,matchName,pItemOut)	\
    (This)->lpVtbl -> GetPreviousSiblingItem(This,ItemIn,matchType,matchName,pItemOut)

#define ISQLNamespace_GetParentItem(This,ItemIn,pItemOut)	\
    (This)->lpVtbl -> GetParentItem(This,ItemIn,pItemOut)

#define ISQLNamespace_GetName(This,ItemIn,pRetVal)	\
    (This)->lpVtbl -> GetName(This,ItemIn,pRetVal)

#define ISQLNamespace_GetType(This,ItemIn,pRetVal)	\
    (This)->lpVtbl -> GetType(This,ItemIn,pRetVal)

#define ISQLNamespace_GetSQLNamespaceObject(This,ItemIn,pRetVal)	\
    (This)->lpVtbl -> GetSQLNamespaceObject(This,ItemIn,pRetVal)

#define ISQLNamespace_GetSQLDMOObject(This,ItemIn,pRetVal)	\
    (This)->lpVtbl -> GetSQLDMOObject(This,ItemIn,pRetVal)

#define ISQLNamespace_Refresh(This,ItemIn)	\
    (This)->lpVtbl -> Refresh(This,ItemIn)

#define ISQLNamespace_SetLCID(This,lcid)	\
    (This)->lpVtbl -> SetLCID(This,lcid)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespace_Initialize_Proxy( 
    ISQLNamespace __RPC_FAR * This,
    /* [in] */ BSTR bstrAppName,
    /* [optional][in] */ SQLNSRootType rootType,
    /* [optional][in] */ VARIANT * pRootInfo,
    /* [optional][in] */ long hWnd);


void __RPC_STUB ISQLNamespace_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespace_GetRootItem_Proxy( 
    ISQLNamespace __RPC_FAR * This,
    /* [retval][out] */ HSQLNSITEM __RPC_FAR *pItemOut);


void __RPC_STUB ISQLNamespace_GetRootItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespace_GetChildrenCount_Proxy( 
    ISQLNamespace __RPC_FAR * This,
    /* [in] */ HSQLNSITEM ItemIn,
    /* [retval][out] */ long __RPC_FAR *pRetVal);


void __RPC_STUB ISQLNamespace_GetChildrenCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespace_GetFirstChildItem_Proxy( 
    ISQLNamespace __RPC_FAR * This,
    /* [in] */ HSQLNSITEM ItemIn,
    /* [optional][in] */ SQLNSObjectType matchType,
    /* [optional][in] */ BSTR matchName,
    /* [retval][out] */ HSQLNSITEM __RPC_FAR *pItemOut);


void __RPC_STUB ISQLNamespace_GetFirstChildItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespace_GetNextSiblingItem_Proxy( 
    ISQLNamespace __RPC_FAR * This,
    /* [in] */ HSQLNSITEM ItemIn,
    /* [optional][in] */ SQLNSObjectType matchType,
    /* [optional][in] */ BSTR matchName,
    /* [retval][out] */ HSQLNSITEM __RPC_FAR *pItemOut);


void __RPC_STUB ISQLNamespace_GetNextSiblingItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespace_GetPreviousSiblingItem_Proxy( 
    ISQLNamespace __RPC_FAR * This,
    /* [in] */ HSQLNSITEM ItemIn,
    /* [optional][in] */ SQLNSObjectType matchType,
    /* [optional][in] */ BSTR matchName,
    /* [retval][out] */ HSQLNSITEM __RPC_FAR *pItemOut);


void __RPC_STUB ISQLNamespace_GetPreviousSiblingItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespace_GetParentItem_Proxy( 
    ISQLNamespace __RPC_FAR * This,
    /* [in] */ HSQLNSITEM ItemIn,
    /* [retval][out] */ HSQLNSITEM __RPC_FAR *pItemOut);


void __RPC_STUB ISQLNamespace_GetParentItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespace_GetName_Proxy( 
    ISQLNamespace __RPC_FAR * This,
    /* [in] */ HSQLNSITEM ItemIn,
    /* [retval][out] */ BSTR __RPC_FAR *pRetVal);


void __RPC_STUB ISQLNamespace_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespace_GetType_Proxy( 
    ISQLNamespace __RPC_FAR * This,
    /* [in] */ HSQLNSITEM ItemIn,
    /* [retval][out] */ SQLNSObjectType __RPC_FAR *pRetVal);


void __RPC_STUB ISQLNamespace_GetType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespace_GetSQLNamespaceObject_Proxy( 
    ISQLNamespace __RPC_FAR * This,
    /* [in] */ HSQLNSITEM ItemIn,
    /* [retval][out] */ ISQLNamespaceObject __RPC_FAR *__RPC_FAR *pRetVal);


void __RPC_STUB ISQLNamespace_GetSQLNamespaceObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespace_GetSQLDMOObject_Proxy( 
    ISQLNamespace __RPC_FAR * This,
    /* [in] */ HSQLNSITEM ItemIn,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pRetVal);


void __RPC_STUB ISQLNamespace_GetSQLDMOObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespace_Refresh_Proxy( 
    ISQLNamespace __RPC_FAR * This,
    /* [in] */ HSQLNSITEM ItemIn);


void __RPC_STUB ISQLNamespace_Refresh_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespace_SetLCID_Proxy( 
    ISQLNamespace __RPC_FAR * This,
    /* [in] */ long lcid);


void __RPC_STUB ISQLNamespace_SetLCID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISQLNamespace_INTERFACE_DEFINED__ */


#ifndef __ISQLNamespaceObject_INTERFACE_DEFINED__
#define __ISQLNamespaceObject_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ISQLNamespaceObject
 * at Sat Nov 29 12:59:01 1997
 * using MIDL 3.01.75
 ****************************************/
/* [object][helpcontext][helpstring][uuid][nonextensible][dual] */ 



DEFINE_GUID(IID_ISQLNamespaceObject,0x00026f21,0xEB1C,0x11cf,0xAE,0x6E,0x00,0xAA,0x00,0x4A,0x34,0xD5);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //interface DECLSPEC_UUID("00026f21-EB1C-11cf-AE6E-00AA004A34D5")
    //ISQLNamespaceObject
    //{
    //public:
	DECLARE_INTERFACE_(ISQLNamespaceObject, ISQLNSDispatch)
	{
		SQLNS_DISPATCH_BASE(ISQLNamespaceObject);

        virtual /* [helpcontext][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE GetCommands( 
            /* [retval][out] */ ISQLNamespaceCommands __RPC_FAR *__RPC_FAR *pRetVal) = 0;
        
        virtual /* [helpcontext][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE GetName( 
            /* [retval][out] */ BSTR __RPC_FAR *pRetVal) = 0;
        
        virtual /* [helpcontext][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE GetType( 
            /* [retval][out] */ SQLNSObjectType __RPC_FAR *pRetVal) = 0;
        
        virtual /* [helpcontext][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE GetHandle( 
            /* [retval][out] */ HSQLNSITEM __RPC_FAR *pRetVal) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ExecuteCommandByName( 
            /* [in] */ BSTR bstrCommand,
            /* [optional][in] */ long hwnd,
            /* [optional][in] */ SQLNSModality modality) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ExecuteCommandByID( 
            /* [in] */ SQLNSCommandID CommandID,
            /* [optional][in] */ long hwnd,
            /* [optional][in] */ SQLNSModality modality) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISQLNamespaceObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISQLNamespaceObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISQLNamespaceObject __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISQLNamespaceObject __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISQLNamespaceObject __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISQLNamespaceObject __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISQLNamespaceObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISQLNamespaceObject __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpcontext][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCommands )( 
            ISQLNamespaceObject __RPC_FAR * This,
            /* [retval][out] */ ISQLNamespaceCommands __RPC_FAR *__RPC_FAR *pRetVal);
        
        /* [helpcontext][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetName )( 
            ISQLNamespaceObject __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pRetVal);
        
        /* [helpcontext][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetType )( 
            ISQLNamespaceObject __RPC_FAR * This,
            /* [retval][out] */ SQLNSObjectType __RPC_FAR *pRetVal);
        
        /* [helpcontext][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHandle )( 
            ISQLNamespaceObject __RPC_FAR * This,
            /* [retval][out] */ HSQLNSITEM __RPC_FAR *pRetVal);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExecuteCommandByName )( 
            ISQLNamespaceObject __RPC_FAR * This,
            /* [in] */ BSTR bstrCommand,
            /* [optional][in] */ long hwnd,
            /* [optional][in] */ SQLNSModality modality);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExecuteCommandByID )( 
            ISQLNamespaceObject __RPC_FAR * This,
            /* [in] */ SQLNSCommandID CommandID,
            /* [optional][in] */ long hwnd,
            /* [optional][in] */ SQLNSModality modality);
        
        END_INTERFACE
    } ISQLNamespaceObjectVtbl;

    interface ISQLNamespaceObject
    {
        CONST_VTBL struct ISQLNamespaceObjectVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISQLNamespaceObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISQLNamespaceObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISQLNamespaceObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISQLNamespaceObject_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISQLNamespaceObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISQLNamespaceObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISQLNamespaceObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISQLNamespaceObject_GetCommands(This,pRetVal)	\
    (This)->lpVtbl -> GetCommands(This,pRetVal)

#define ISQLNamespaceObject_GetName(This,pRetVal)	\
    (This)->lpVtbl -> GetName(This,pRetVal)

#define ISQLNamespaceObject_GetType(This,pRetVal)	\
    (This)->lpVtbl -> GetType(This,pRetVal)

#define ISQLNamespaceObject_GetHandle(This,pRetVal)	\
    (This)->lpVtbl -> GetHandle(This,pRetVal)

#define ISQLNamespaceObject_ExecuteCommandByName(This,bstrCommand,hwnd,modality)	\
    (This)->lpVtbl -> ExecuteCommandByName(This,bstrCommand,hwnd,modality)

#define ISQLNamespaceObject_ExecuteCommandByID(This,CommandID,hwnd,modality)	\
    (This)->lpVtbl -> ExecuteCommandByID(This,CommandID,hwnd,modality)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpcontext][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespaceObject_GetCommands_Proxy( 
    ISQLNamespaceObject __RPC_FAR * This,
    /* [retval][out] */ ISQLNamespaceCommands __RPC_FAR *__RPC_FAR *pRetVal);


void __RPC_STUB ISQLNamespaceObject_GetCommands_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespaceObject_GetName_Proxy( 
    ISQLNamespaceObject __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pRetVal);


void __RPC_STUB ISQLNamespaceObject_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespaceObject_GetType_Proxy( 
    ISQLNamespaceObject __RPC_FAR * This,
    /* [retval][out] */ SQLNSObjectType __RPC_FAR *pRetVal);


void __RPC_STUB ISQLNamespaceObject_GetType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespaceObject_GetHandle_Proxy( 
    ISQLNamespaceObject __RPC_FAR * This,
    /* [retval][out] */ HSQLNSITEM __RPC_FAR *pRetVal);


void __RPC_STUB ISQLNamespaceObject_GetHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespaceObject_ExecuteCommandByName_Proxy( 
    ISQLNamespaceObject __RPC_FAR * This,
    /* [in] */ BSTR bstrCommand,
    /* [optional][in] */ long hwnd,
    /* [optional][in] */ SQLNSModality modality);


void __RPC_STUB ISQLNamespaceObject_ExecuteCommandByName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespaceObject_ExecuteCommandByID_Proxy( 
    ISQLNamespaceObject __RPC_FAR * This,
    /* [in] */ SQLNSCommandID CommandID,
    /* [optional][in] */ long hwnd,
    /* [optional][in] */ SQLNSModality modality);


void __RPC_STUB ISQLNamespaceObject_ExecuteCommandByID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISQLNamespaceObject_INTERFACE_DEFINED__ */


#ifndef __ISQLNamespaceCommand_INTERFACE_DEFINED__
#define __ISQLNamespaceCommand_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ISQLNamespaceCommand
 * at Sat Nov 29 12:59:01 1997
 * using MIDL 3.01.75
 ****************************************/
/* [object][helpcontext][helpstring][uuid][nonextensible][dual] */ 



DEFINE_GUID(IID_ISQLNamespaceCommand,0x00026f22,0xEB1C,0x11cf,0xAE,0x6E,0x00,0xAA,0x00,0x4A,0x34,0xD5);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //interface DECLSPEC_UUID("00026f22-EB1C-11cf-AE6E-00AA004A34D5")
    //ISQLNamespaceCommand
    //{
    //public:
	DECLARE_INTERFACE_(ISQLNamespaceCommand, ISQLNSDispatch)
	{
		SQLNS_DISPATCH_BASE(ISQLNamespaceCommand);

        virtual /* [helpcontext][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE GetName( 
            /* [retval][out] */ BSTR __RPC_FAR *pRetVal) = 0;
        
        virtual /* [helpcontext][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE GetCommandID( 
            /* [retval][out] */ SQLNSCommandID __RPC_FAR *pRetVal) = 0;
        
        virtual /* [helpcontext][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE GetHelpString( 
            /* [retval][out] */ BSTR __RPC_FAR *pRetVal) = 0;
        
        virtual /* [helpcontext][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE GetCommandGroup( 
            /* [retval][out] */ long __RPC_FAR *pRetVal) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE Execute( 
            /* [optional][in] */ long hwnd,
            /* [optional][in] */ SQLNSModality modality) = 0;

		virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ExecuteWithParam( 
            /* [optional][in] */ long hwnd,
            /* [optional][in] */ SQLNSModality modality,
            /* [optional][in][out] */ LPVARIANT pVarParam) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISQLNamespaceCommandVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISQLNamespaceCommand __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISQLNamespaceCommand __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISQLNamespaceCommand __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISQLNamespaceCommand __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISQLNamespaceCommand __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISQLNamespaceCommand __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISQLNamespaceCommand __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpcontext][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHelpString )( 
            ISQLNamespaceCommand __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pRetVal);
        
        /* [helpcontext][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCommandID )( 
            ISQLNamespaceCommand __RPC_FAR * This,
            /* [retval][out] */ SQLNSCommandID __RPC_FAR *pRetVal);
        
        /* [helpcontext][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCommandGroup )( 
            ISQLNamespaceCommand __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pRetVal);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Execute )( 
            ISQLNamespaceCommand __RPC_FAR * This,
            /* [optional][in] */ long hwnd,
            /* [optional][in] */ SQLNSModality modality);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExecuteWithParam )( 
            SQLNamespaceCommand __RPC_FAR * This,
            /* [optional][in] */ long hwnd,
            /* [optional][in] */ SQLNSModality modality,
            /* [optional][in][out] */ LPVARIANT pVarParam);

        END_INTERFACE
    } ISQLNamespaceCommandVtbl;

    interface ISQLNamespaceCommand
    {
        CONST_VTBL struct ISQLNamespaceCommandVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISQLNamespaceCommand_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISQLNamespaceCommand_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISQLNamespaceCommand_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISQLNamespaceCommand_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISQLNamespaceCommand_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISQLNamespaceCommand_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISQLNamespaceCommand_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISQLNamespaceCommand_GetHelpString(This,pRetVal)	\
    (This)->lpVtbl -> GetHelpString(This,pRetVal)

#define ISQLNamespaceCommand_GetCommandID(This,pRetVal)	\
    (This)->lpVtbl -> GetCommandID(This,pRetVal)

#define ISQLNamespaceCommand_GetCommandGroup(This,pRetVal)	\
    (This)->lpVtbl -> GetCommandGroup(This,pRetVal)

#define ISQLNamespaceCommand_Execute(This,hwnd,modality)	\
    (This)->lpVtbl -> Execute(This,hwnd,modality)

#define SQLNamespaceCommand_ExecuteWithParam(This,hwnd,modality,pVarParam)	\
    (This)->lpVtbl -> ExecuteWithParam(This,hwnd,modality,pVarParam)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpcontext][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespaceCommand_GetHelpString_Proxy( 
    ISQLNamespaceCommand __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pRetVal);


void __RPC_STUB ISQLNamespaceCommand_GetHelpString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespaceCommand_GetCommandID_Proxy( 
    ISQLNamespaceCommand __RPC_FAR * This,
    /* [retval][out] */ SQLNSCommandID __RPC_FAR *pRetVal);


void __RPC_STUB ISQLNamespaceCommand_GetCommandID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespaceCommand_GetCommandGroup_Proxy( 
    ISQLNamespaceCommand __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pRetVal);


void __RPC_STUB ISQLNamespaceCommand_GetCommandGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespaceCommand_Execute_Proxy( 
    ISQLNamespaceCommand __RPC_FAR * This,
    /* [optional][in] */ long hwnd,
    /* [optional][in] */ SQLNSModality modality);


void __RPC_STUB ISQLNamespaceCommand_Execute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespaceCommand_ExecuteWithParam_Proxy( 
    ISQLNamespaceCommand __RPC_FAR * This,
    /* [optional][in] */ long hwnd,
    /* [optional][in] */ SQLNSModality modality,
    /* [optional][in][out] */ LPVARIANT pVarParam);


void __RPC_STUB ISQLNamespaceCommand_ExecuteWithParam_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


#endif 	/* __ISQLNamespaceCommand_INTERFACE_DEFINED__ */


#ifndef __ISQLNamespaceCommands_INTERFACE_DEFINED__
#define __ISQLNamespaceCommands_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ISQLNamespaceCommands
 * at Sat Nov 29 12:59:01 1997
 * using MIDL 3.01.75
 ****************************************/
/* [object][helpcontext][helpstring][uuid][nonextensible][dual] */ 



DEFINE_GUID(IID_ISQLNamespaceCommands,0x00026f23,0xEB1C,0x11cf,0xAE,0x6E,0x00,0xAA,0x00,0x4A,0x34,0xD5);
DEFINE_GUID(IID_IReplicationCustomization,0x00026f24,0xEB1C,0x11cf,0xAE,0x6E,0x00,0xAA,0x00,0x4A,0x34,0xD5);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //interface DECLSPEC_UUID("00026f23-EB1C-11cf-AE6E-00AA004A34D5")
    //ISQLNamespaceCommands
    //{
    //public:
	DECLARE_INTERFACE_(ISQLNamespaceCommands, ISQLNSDispatch)
	{
		SQLNS_DISPATCH_BASE(ISQLNamespaceCommands);

        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ ISQLNamespaceCommand __RPC_FAR *__RPC_FAR *pRetVal) = 0;
        
        virtual /* [helpcontext][helpstring][propget][restricted][id] */ HRESULT STDMETHODCALLTYPE Get_NewEnum( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppEnum) = 0;
        
        virtual /* [helpcontext][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE GetCount( 
            /* [retval][out] */ long __RPC_FAR *pRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISQLNamespaceCommandsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISQLNamespaceCommands __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISQLNamespaceCommands __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISQLNamespaceCommands __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISQLNamespaceCommands __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISQLNamespaceCommands __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISQLNamespaceCommands __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISQLNamespaceCommands __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Item )( 
            ISQLNamespaceCommands __RPC_FAR * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ ISQLNamespaceCommand __RPC_FAR *__RPC_FAR *pRetVal);
        
        /* [helpcontext][helpstring][propget][restricted][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Get_NewEnum )( 
            ISQLNamespaceCommands __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppEnum);
        
        /* [helpcontext][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCount )( 
            ISQLNamespaceCommands __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pRetVal);
        
        END_INTERFACE
    } ISQLNamespaceCommandsVtbl;

    interface ISQLNamespaceCommands
    {
        CONST_VTBL struct ISQLNamespaceCommandsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISQLNamespaceCommands_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISQLNamespaceCommands_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISQLNamespaceCommands_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISQLNamespaceCommands_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISQLNamespaceCommands_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISQLNamespaceCommands_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISQLNamespaceCommands_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISQLNamespaceCommands_Item(This,Index,pRetVal)	\
    (This)->lpVtbl -> Item(This,Index,pRetVal)

#define ISQLNamespaceCommands_Get_NewEnum(This,ppEnum)	\
    (This)->lpVtbl -> Get_NewEnum(This,ppEnum)

#define ISQLNamespaceCommands_GetCount(This,pRetVal)	\
    (This)->lpVtbl -> GetCount(This,pRetVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespaceCommands_Item_Proxy( 
    ISQLNamespaceCommands __RPC_FAR * This,
    /* [in] */ VARIANT Index,
    /* [retval][out] */ ISQLNamespaceCommand __RPC_FAR *__RPC_FAR *pRetVal);


void __RPC_STUB ISQLNamespaceCommands_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][propget][restricted][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespaceCommands_Get_NewEnum_Proxy( 
    ISQLNamespaceCommands __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *ppEnum);


void __RPC_STUB ISQLNamespaceCommands_Get_NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE ISQLNamespaceCommands_GetCount_Proxy( 
    ISQLNamespaceCommands __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pRetVal);


void __RPC_STUB ISQLNamespaceCommands_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISQLNamespaceCommands_INTERFACE_DEFINED__ */


#ifdef __cplusplus
DEFINE_GUID(CLSID_SQLNamespace,0x00026f00,0xEB1C,0x11cf,0xAE,0x6E,0x00,0xAA,0x00,0x4A,0x34,0xD5);

class DECLSPEC_UUID("00026f10-EB1C-11cf-AE6E-00AA004A34D5")
SQLNamespaceEx;
#endif
#endif /* __SQLNS_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
