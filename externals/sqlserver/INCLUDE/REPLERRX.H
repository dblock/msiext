/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Aug 06 00:28:30 2000
 */
/* Compiler settings for q:\SPHINX\SQLREPL\common\inc\replerrx.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __replerrx_h__
#define __replerrx_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ISQLReplError_FWD_DEFINED__
#define __ISQLReplError_FWD_DEFINED__
typedef interface ISQLReplError ISQLReplError;
#endif 	/* __ISQLReplError_FWD_DEFINED__ */


#ifndef __ISQLReplErrors_FWD_DEFINED__
#define __ISQLReplErrors_FWD_DEFINED__
typedef interface ISQLReplErrors ISQLReplErrors;
#endif 	/* __ISQLReplErrors_FWD_DEFINED__ */


#ifndef ___ReplErrorEvents_FWD_DEFINED__
#define ___ReplErrorEvents_FWD_DEFINED__
typedef interface _ReplErrorEvents _ReplErrorEvents;
#endif 	/* ___ReplErrorEvents_FWD_DEFINED__ */


#ifndef __SQLReplErrors_FWD_DEFINED__
#define __SQLReplErrors_FWD_DEFINED__

#ifdef __cplusplus
typedef class SQLReplErrors SQLReplErrors;
#else
typedef struct SQLReplErrors SQLReplErrors;
#endif /* __cplusplus */

#endif 	/* __SQLReplErrors_FWD_DEFINED__ */


#ifndef __SQLReplError_FWD_DEFINED__
#define __SQLReplError_FWD_DEFINED__

#ifdef __cplusplus
typedef class SQLReplError SQLReplError;
#else
typedef struct SQLReplError SQLReplError;
#endif /* __cplusplus */

#endif 	/* __SQLReplError_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_replerrx_0000 */
/* [local] */ 

#ifndef AGENT_STATUS_DEFINED
#define AGENT_STATUS_DEFINED
typedef 
enum AGENT_STATUS
    {	REPLAGENT_IN_PROGRESS	= 1,
	REPLAGENT_SUCCEED	= 2,
	REPLAGENT_RETRY	= 3,
	REPLAGENT_FAIL	= 4
    }	REPLAGENT_STATUS;

#endif /* AGENT_STATUS_DEFINED */
typedef 
enum ERRORSOURCE_TYPE
    {	INVALID_SOURCE_TYPE	= 0,
	SQL_COMMAND	= 1,
	REPL_CONTROL	= 2,
	OPERATING_SYSTEM	= 3,
	ODBC_API	= 4,
	SQLSERVER_ENGINE	= 5,
	NET_LIBRARY	= 6,
	SQLDMO	= 7,
	MERGE_PROVIDER	= 8,
	MERGE_PROCESS	= 9
    }	REPL_ERRORSOURCE_TYPE;

#define REPLX_E_DBEXISTS				MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x0e00)
#define REPLX_E_DBNOTFOUND			MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x0e01)
#define REPLX_E_SUBEXISTS			MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x0e02)
#define REPLX_E_SUBNOTFOUND			MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x0e03)
#define REPLX_E_SUBEXPIRED			MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x0e04)
#define REPLX_E_DEADLOCK				MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x0e05)
#define REPLX_E_PROFILENOTFOUND		MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x0e06)
#define REPLX_E_RETRYFAILURE			MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x0e07)
#define REPLX_E_LOGINFAILURE			MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x0e08)
#define REPLX_S_VALIDATIONFAILED		MAKE_SCODE(SEVERITY_SUCCESS,FACILITY_ITF,0x0100)
#define REPLX_S_CONFLICTSOCCURRED	MAKE_SCODE(SEVERITY_SUCCESS,FACILITY_ITF,0x0101)


extern RPC_IF_HANDLE __MIDL_itf_replerrx_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_replerrx_0000_v0_0_s_ifspec;

#ifndef __ISQLReplError_INTERFACE_DEFINED__
#define __ISQLReplError_INTERFACE_DEFINED__

/* interface ISQLReplError */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISQLReplError;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("35CE087C-2E4E-11D2-B6D4-00C04FB93D6B")
    ISQLReplError : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Description( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Source( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Source( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ErrorNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ErrorNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SourceType( 
            /* [retval][out] */ REPL_ERRORSOURCE_TYPE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SourceType( 
            /* [in] */ REPL_ERRORSOURCE_TYPE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ErrorNumberString( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ErrorNumberString( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISQLReplErrorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISQLReplError __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISQLReplError __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISQLReplError __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISQLReplError __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISQLReplError __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISQLReplError __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISQLReplError __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Description )( 
            ISQLReplError __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Description )( 
            ISQLReplError __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Source )( 
            ISQLReplError __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Source )( 
            ISQLReplError __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ErrorNumber )( 
            ISQLReplError __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ErrorNumber )( 
            ISQLReplError __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SourceType )( 
            ISQLReplError __RPC_FAR * This,
            /* [retval][out] */ REPL_ERRORSOURCE_TYPE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SourceType )( 
            ISQLReplError __RPC_FAR * This,
            /* [in] */ REPL_ERRORSOURCE_TYPE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ErrorNumberString )( 
            ISQLReplError __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ErrorNumberString )( 
            ISQLReplError __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } ISQLReplErrorVtbl;

    interface ISQLReplError
    {
        CONST_VTBL struct ISQLReplErrorVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISQLReplError_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISQLReplError_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISQLReplError_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISQLReplError_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISQLReplError_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISQLReplError_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISQLReplError_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISQLReplError_get_Description(This,pVal)	\
    (This)->lpVtbl -> get_Description(This,pVal)

#define ISQLReplError_put_Description(This,newVal)	\
    (This)->lpVtbl -> put_Description(This,newVal)

#define ISQLReplError_get_Source(This,pVal)	\
    (This)->lpVtbl -> get_Source(This,pVal)

#define ISQLReplError_put_Source(This,newVal)	\
    (This)->lpVtbl -> put_Source(This,newVal)

#define ISQLReplError_get_ErrorNumber(This,pVal)	\
    (This)->lpVtbl -> get_ErrorNumber(This,pVal)

#define ISQLReplError_put_ErrorNumber(This,newVal)	\
    (This)->lpVtbl -> put_ErrorNumber(This,newVal)

#define ISQLReplError_get_SourceType(This,pVal)	\
    (This)->lpVtbl -> get_SourceType(This,pVal)

#define ISQLReplError_put_SourceType(This,newVal)	\
    (This)->lpVtbl -> put_SourceType(This,newVal)

#define ISQLReplError_get_ErrorNumberString(This,pVal)	\
    (This)->lpVtbl -> get_ErrorNumberString(This,pVal)

#define ISQLReplError_put_ErrorNumberString(This,newVal)	\
    (This)->lpVtbl -> put_ErrorNumberString(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLReplError_get_Description_Proxy( 
    ISQLReplError __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLReplError_get_Description_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLReplError_put_Description_Proxy( 
    ISQLReplError __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLReplError_put_Description_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLReplError_get_Source_Proxy( 
    ISQLReplError __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLReplError_get_Source_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLReplError_put_Source_Proxy( 
    ISQLReplError __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLReplError_put_Source_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLReplError_get_ErrorNumber_Proxy( 
    ISQLReplError __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ISQLReplError_get_ErrorNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLReplError_put_ErrorNumber_Proxy( 
    ISQLReplError __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB ISQLReplError_put_ErrorNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLReplError_get_SourceType_Proxy( 
    ISQLReplError __RPC_FAR * This,
    /* [retval][out] */ REPL_ERRORSOURCE_TYPE __RPC_FAR *pVal);


void __RPC_STUB ISQLReplError_get_SourceType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLReplError_put_SourceType_Proxy( 
    ISQLReplError __RPC_FAR * This,
    /* [in] */ REPL_ERRORSOURCE_TYPE newVal);


void __RPC_STUB ISQLReplError_put_SourceType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLReplError_get_ErrorNumberString_Proxy( 
    ISQLReplError __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLReplError_get_ErrorNumberString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLReplError_put_ErrorNumberString_Proxy( 
    ISQLReplError __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLReplError_put_ErrorNumberString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISQLReplError_INTERFACE_DEFINED__ */


#ifndef __ISQLReplErrors_INTERFACE_DEFINED__
#define __ISQLReplErrors_INTERFACE_DEFINED__

/* interface ISQLReplErrors */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISQLReplErrors;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("35CE087B-2E4E-11D2-B6D4-00C04FB93D6B")
    ISQLReplErrors : public IDispatch
    {
    public:
        virtual /* [helpstring][restricted][id][propget] */ HRESULT STDMETHODCALLTYPE get_NewEnum( 
            /* [retval][out] */ LPUNKNOWN __RPC_FAR *ppvObject) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *cMembers) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddReplError( 
            /* [in] */ BSTR bstrDescription,
            /* [in] */ BSTR bstrSource,
            /* [in] */ long lErrorNumber,
            /* [in] */ REPL_ERRORSOURCE_TYPE ErrorSourceType,
            /* [in] */ BSTR bstrErrorNumberString) = 0;
        
        virtual /* [helpstring][restricted][id] */ HRESULT STDMETHODCALLTYPE ClearErrors( void) = 0;
        
        virtual /* [hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT varIndex,
            /* [retval][out] */ ISQLReplError __RPC_FAR *__RPC_FAR *ppobj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ ISQLReplError __RPC_FAR *pISQLReplError) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISQLReplErrorsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISQLReplErrors __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISQLReplErrors __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISQLReplErrors __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISQLReplErrors __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISQLReplErrors __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISQLReplErrors __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISQLReplErrors __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][restricted][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_NewEnum )( 
            ISQLReplErrors __RPC_FAR * This,
            /* [retval][out] */ LPUNKNOWN __RPC_FAR *ppvObject);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            ISQLReplErrors __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *cMembers);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddReplError )( 
            ISQLReplErrors __RPC_FAR * This,
            /* [in] */ BSTR bstrDescription,
            /* [in] */ BSTR bstrSource,
            /* [in] */ long lErrorNumber,
            /* [in] */ REPL_ERRORSOURCE_TYPE ErrorSourceType,
            /* [in] */ BSTR bstrErrorNumberString);
        
        /* [helpstring][restricted][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClearErrors )( 
            ISQLReplErrors __RPC_FAR * This);
        
        /* [hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            ISQLReplErrors __RPC_FAR * This,
            /* [in] */ VARIANT varIndex,
            /* [retval][out] */ ISQLReplError __RPC_FAR *__RPC_FAR *ppobj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            ISQLReplErrors __RPC_FAR * This,
            /* [in] */ ISQLReplError __RPC_FAR *pISQLReplError);
        
        END_INTERFACE
    } ISQLReplErrorsVtbl;

    interface ISQLReplErrors
    {
        CONST_VTBL struct ISQLReplErrorsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISQLReplErrors_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISQLReplErrors_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISQLReplErrors_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISQLReplErrors_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISQLReplErrors_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISQLReplErrors_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISQLReplErrors_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISQLReplErrors_get_NewEnum(This,ppvObject)	\
    (This)->lpVtbl -> get_NewEnum(This,ppvObject)

#define ISQLReplErrors_get_Count(This,cMembers)	\
    (This)->lpVtbl -> get_Count(This,cMembers)

#define ISQLReplErrors_AddReplError(This,bstrDescription,bstrSource,lErrorNumber,ErrorSourceType,bstrErrorNumberString)	\
    (This)->lpVtbl -> AddReplError(This,bstrDescription,bstrSource,lErrorNumber,ErrorSourceType,bstrErrorNumberString)

#define ISQLReplErrors_ClearErrors(This)	\
    (This)->lpVtbl -> ClearErrors(This)

#define ISQLReplErrors_get_Item(This,varIndex,ppobj)	\
    (This)->lpVtbl -> get_Item(This,varIndex,ppobj)

#define ISQLReplErrors_Add(This,pISQLReplError)	\
    (This)->lpVtbl -> Add(This,pISQLReplError)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][restricted][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLReplErrors_get_NewEnum_Proxy( 
    ISQLReplErrors __RPC_FAR * This,
    /* [retval][out] */ LPUNKNOWN __RPC_FAR *ppvObject);


void __RPC_STUB ISQLReplErrors_get_NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLReplErrors_get_Count_Proxy( 
    ISQLReplErrors __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *cMembers);


void __RPC_STUB ISQLReplErrors_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLReplErrors_AddReplError_Proxy( 
    ISQLReplErrors __RPC_FAR * This,
    /* [in] */ BSTR bstrDescription,
    /* [in] */ BSTR bstrSource,
    /* [in] */ long lErrorNumber,
    /* [in] */ REPL_ERRORSOURCE_TYPE ErrorSourceType,
    /* [in] */ BSTR bstrErrorNumberString);


void __RPC_STUB ISQLReplErrors_AddReplError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][restricted][id] */ HRESULT STDMETHODCALLTYPE ISQLReplErrors_ClearErrors_Proxy( 
    ISQLReplErrors __RPC_FAR * This);


void __RPC_STUB ISQLReplErrors_ClearErrors_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLReplErrors_get_Item_Proxy( 
    ISQLReplErrors __RPC_FAR * This,
    /* [in] */ VARIANT varIndex,
    /* [retval][out] */ ISQLReplError __RPC_FAR *__RPC_FAR *ppobj);


void __RPC_STUB ISQLReplErrors_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLReplErrors_Add_Proxy( 
    ISQLReplErrors __RPC_FAR * This,
    /* [in] */ ISQLReplError __RPC_FAR *pISQLReplError);


void __RPC_STUB ISQLReplErrors_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISQLReplErrors_INTERFACE_DEFINED__ */



#ifndef __REPLERRXLib_LIBRARY_DEFINED__
#define __REPLERRXLib_LIBRARY_DEFINED__

/* library REPLERRXLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_REPLERRXLib;

#ifndef ___ReplErrorEvents_DISPINTERFACE_DEFINED__
#define ___ReplErrorEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ReplErrorEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__ReplErrorEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("2A744FF0-EEB0-11d2-A002-0080C7FDD26E")
    _ReplErrorEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ReplErrorEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _ReplErrorEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _ReplErrorEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _ReplErrorEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _ReplErrorEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _ReplErrorEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _ReplErrorEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _ReplErrorEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _ReplErrorEventsVtbl;

    interface _ReplErrorEvents
    {
        CONST_VTBL struct _ReplErrorEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ReplErrorEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _ReplErrorEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _ReplErrorEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _ReplErrorEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _ReplErrorEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _ReplErrorEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _ReplErrorEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ReplErrorEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SQLReplErrors;

#ifdef __cplusplus

class DECLSPEC_UUID("08b0b2ea-3fb3-11d3-a4de-00c04f610189")
SQLReplErrors;
#endif

EXTERN_C const CLSID CLSID_SQLReplError;

#ifdef __cplusplus

class DECLSPEC_UUID("08b0b2eb-3fb3-11d3-a4de-00c04f610189")
SQLReplError;
#endif
#endif /* __REPLERRXLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long __RPC_FAR *, unsigned long            , VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long __RPC_FAR *, VARIANT __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
