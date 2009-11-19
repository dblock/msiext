/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Aug 06 01:25:44 2000
 */
/* Compiler settings for q:\SPHINX\SQLREPL\SQLMERGX\sqlmergx.idl:
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

#ifndef __sqlmergx_h__
#define __sqlmergx_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAlternateSyncPartner_FWD_DEFINED__
#define __IAlternateSyncPartner_FWD_DEFINED__
typedef interface IAlternateSyncPartner IAlternateSyncPartner;
#endif 	/* __IAlternateSyncPartner_FWD_DEFINED__ */


#ifndef __IAlternateSyncPartners_FWD_DEFINED__
#define __IAlternateSyncPartners_FWD_DEFINED__
typedef interface IAlternateSyncPartners IAlternateSyncPartners;
#endif 	/* __IAlternateSyncPartners_FWD_DEFINED__ */


#ifndef __ISQLMerge_FWD_DEFINED__
#define __ISQLMerge_FWD_DEFINED__
typedef interface ISQLMerge ISQLMerge;
#endif 	/* __ISQLMerge_FWD_DEFINED__ */


#ifndef ___SQLMergeEvents_FWD_DEFINED__
#define ___SQLMergeEvents_FWD_DEFINED__
typedef interface _SQLMergeEvents _SQLMergeEvents;
#endif 	/* ___SQLMergeEvents_FWD_DEFINED__ */


#ifndef __SQLMerge_FWD_DEFINED__
#define __SQLMerge_FWD_DEFINED__

#ifdef __cplusplus
typedef class SQLMerge SQLMerge;
#else
typedef struct SQLMerge SQLMerge;
#endif /* __cplusplus */

#endif 	/* __SQLMerge_FWD_DEFINED__ */


#ifndef __AlternateSyncPartner_FWD_DEFINED__
#define __AlternateSyncPartner_FWD_DEFINED__

#ifdef __cplusplus
typedef class AlternateSyncPartner AlternateSyncPartner;
#else
typedef struct AlternateSyncPartner AlternateSyncPartner;
#endif /* __cplusplus */

#endif 	/* __AlternateSyncPartner_FWD_DEFINED__ */


#ifndef __AlternateSyncPartners_FWD_DEFINED__
#define __AlternateSyncPartners_FWD_DEFINED__

#ifdef __cplusplus
typedef class AlternateSyncPartners AlternateSyncPartners;
#else
typedef struct AlternateSyncPartners AlternateSyncPartners;
#endif /* __cplusplus */

#endif 	/* __AlternateSyncPartners_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "replerrx.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_sqlmergx_0000 */
/* [local] */ 

#ifndef COMMON_REPL_ENUMS_DEFINED
#define COMMON_REPL_ENUMS_DEFINED
typedef 
enum SECURITY_TYPE
    {	DB_AUTHENTICATION	= 0,
	NT_AUTHENTICATION	= 1
    }	REPL_SECURITY_TYPE;

typedef 
enum DATASOURCE_TYPE
    {	SQL_SERVER	= 0,
	ODBC_DSN	= 1,
	JET4_DATABASE	= 2,
	OLEDB_DATASOURCE	= 3,
	EXCHANGE	= 4,
	ORACLE	= 5,
	DB2_UNIVERSAL	= 6
    }	REPL_DATASOURCE_TYPE;

typedef 
enum SUBSCRIPTION_TYPE
    {	PUSH	= 0,
	PULL	= 1,
	ANONYMOUS	= 2
    }	REPL_SUBSCRIPTION_TYPE;

typedef 
enum NETWORK_TYPE
    {	DEFAULT_NETWORK	= 0,
	TCPIP_SOCKETS	= 1,
	MULTI_PROTOCOL	= 2
    }	REPL_NETWORK_TYPE;

typedef 
enum DBADDOPTION
    {	EXISTING_DATABASE	= 0,
	CREATE_DATABASE	= 1,
	ATTACH_DATABASE	= 2,
	ATTACH_SUBSCRIPTION	= 3,
	REGISTER_SUBSCRIPTION	= 4
    }	REPL_DBADDOPTION;

typedef 
enum DBDROPOPTION
    {	LEAVE_DATABASE	= 0,
	DROP_DATABASE	= 1,
	UNREGISTER_SUBSCRIPTION	= 2
    }	REPL_DBDROPOPTION;

typedef 
enum SUBSCRIPTION_HOST
    {	NONE	= 0,
	SYNC_MANAGER	= 1
    }	REPL_SUBSCRIPTION_HOST;

typedef 
enum STATUS_RETURN_CODE
    {	SUCCESS	= 0,
	CANCEL	= 1
    }	REPL_STATUS_RETURN_CODE;

typedef 
enum FILE_TRANSFER_TYPE
    {	FILETRANSFERUNC	= 0,
	FILETRANSFERFTP	= 1
    }	REPL_FILE_TRANSFER_TYPE;

typedef 
enum SYNCHRONIZATION_TYPE
    {	AUTOMATIC	= 1,
	NOSYNC	= 2
    }	REPL_SYNCHRONIZATION_TYPE;

typedef 
enum FILECREATE_OPTION
    {	CREATE_NEW_FILE	= 0,
	OVERWRITE_EXISTING_FILE	= 1
    }	REPL_FILECREATE_OPTION;

#define S_REPLX_CANCELLED	MAKE_SCODE(SEVERITY_SUCCESS,FACILITY_ITF,0x0101)
#define E_REPLX_NAMETOOLONG	MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x0102)
#define E_REPLX_NAMETOOSHORT	MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x0103)
#endif //COMMON_REPL_ENUMS_DEFINED
typedef 
enum VALIDATE_TYPE
    {	NO_VALIDATION	= 0,
	ROWCOUNT_ONLY	= 1,
	ROWCOUNT_AND_CHECKSUM	= 2,
	FAST_ROWCOUNT_ONLY	= 3,
	FAST_ROWCOUNT_AND_CHECKSUM	= 4,
	ROWCOUNT_AND_BINARYCHECKSUM	= 5,
	FAST_ROWCOUNT_AND_BINARYCHECKSUM	= 6
    }	REPL_VALIDATE_TYPE;

typedef 
enum EXCHANGE_TYPE
    {	UPLOAD	= 1,
	DOWNLOAD	= 2,
	BIDIRECTIONAL	= 3
    }	REPL_EXCHANGE_TYPE;

typedef 
enum SUBSCRIPTION_PRIORITY_TYPE
    {	GLOBAL_PRIORITY	= 1,
	LOCAL_PRIORITY	= 2
    }	REPL_SUBSCRIPTION_PRIORITY_TYPE;



extern RPC_IF_HANDLE __MIDL_itf_sqlmergx_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sqlmergx_0000_v0_0_s_ifspec;

#ifndef __IAlternateSyncPartner_INTERFACE_DEFINED__
#define __IAlternateSyncPartner_INTERFACE_DEFINED__

/* interface IAlternateSyncPartner */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAlternateSyncPartner;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0A98450D-04A9-11D3-A8FB-00C04F9FC436")
    IAlternateSyncPartner : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FriendlyName( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FriendlyName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Distributor( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Distributor( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Publication( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Publication( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PublisherDatabase( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PublisherDatabase( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Publisher( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Publisher( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAlternateSyncPartnerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAlternateSyncPartner __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAlternateSyncPartner __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAlternateSyncPartner __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAlternateSyncPartner __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAlternateSyncPartner __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAlternateSyncPartner __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAlternateSyncPartner __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FriendlyName )( 
            IAlternateSyncPartner __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FriendlyName )( 
            IAlternateSyncPartner __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Distributor )( 
            IAlternateSyncPartner __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Distributor )( 
            IAlternateSyncPartner __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Publication )( 
            IAlternateSyncPartner __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Publication )( 
            IAlternateSyncPartner __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PublisherDatabase )( 
            IAlternateSyncPartner __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PublisherDatabase )( 
            IAlternateSyncPartner __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Publisher )( 
            IAlternateSyncPartner __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Publisher )( 
            IAlternateSyncPartner __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IAlternateSyncPartnerVtbl;

    interface IAlternateSyncPartner
    {
        CONST_VTBL struct IAlternateSyncPartnerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAlternateSyncPartner_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAlternateSyncPartner_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAlternateSyncPartner_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAlternateSyncPartner_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAlternateSyncPartner_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAlternateSyncPartner_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAlternateSyncPartner_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAlternateSyncPartner_get_FriendlyName(This,pVal)	\
    (This)->lpVtbl -> get_FriendlyName(This,pVal)

#define IAlternateSyncPartner_put_FriendlyName(This,newVal)	\
    (This)->lpVtbl -> put_FriendlyName(This,newVal)

#define IAlternateSyncPartner_get_Distributor(This,pVal)	\
    (This)->lpVtbl -> get_Distributor(This,pVal)

#define IAlternateSyncPartner_put_Distributor(This,newVal)	\
    (This)->lpVtbl -> put_Distributor(This,newVal)

#define IAlternateSyncPartner_get_Publication(This,pVal)	\
    (This)->lpVtbl -> get_Publication(This,pVal)

#define IAlternateSyncPartner_put_Publication(This,newVal)	\
    (This)->lpVtbl -> put_Publication(This,newVal)

#define IAlternateSyncPartner_get_PublisherDatabase(This,pVal)	\
    (This)->lpVtbl -> get_PublisherDatabase(This,pVal)

#define IAlternateSyncPartner_put_PublisherDatabase(This,newVal)	\
    (This)->lpVtbl -> put_PublisherDatabase(This,newVal)

#define IAlternateSyncPartner_get_Publisher(This,pVal)	\
    (This)->lpVtbl -> get_Publisher(This,pVal)

#define IAlternateSyncPartner_put_Publisher(This,newVal)	\
    (This)->lpVtbl -> put_Publisher(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAlternateSyncPartner_get_FriendlyName_Proxy( 
    IAlternateSyncPartner __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IAlternateSyncPartner_get_FriendlyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAlternateSyncPartner_put_FriendlyName_Proxy( 
    IAlternateSyncPartner __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IAlternateSyncPartner_put_FriendlyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAlternateSyncPartner_get_Distributor_Proxy( 
    IAlternateSyncPartner __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IAlternateSyncPartner_get_Distributor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAlternateSyncPartner_put_Distributor_Proxy( 
    IAlternateSyncPartner __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IAlternateSyncPartner_put_Distributor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAlternateSyncPartner_get_Publication_Proxy( 
    IAlternateSyncPartner __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IAlternateSyncPartner_get_Publication_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAlternateSyncPartner_put_Publication_Proxy( 
    IAlternateSyncPartner __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IAlternateSyncPartner_put_Publication_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAlternateSyncPartner_get_PublisherDatabase_Proxy( 
    IAlternateSyncPartner __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IAlternateSyncPartner_get_PublisherDatabase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAlternateSyncPartner_put_PublisherDatabase_Proxy( 
    IAlternateSyncPartner __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IAlternateSyncPartner_put_PublisherDatabase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAlternateSyncPartner_get_Publisher_Proxy( 
    IAlternateSyncPartner __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IAlternateSyncPartner_get_Publisher_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IAlternateSyncPartner_put_Publisher_Proxy( 
    IAlternateSyncPartner __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IAlternateSyncPartner_put_Publisher_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAlternateSyncPartner_INTERFACE_DEFINED__ */


#ifndef __IAlternateSyncPartners_INTERFACE_DEFINED__
#define __IAlternateSyncPartners_INTERFACE_DEFINED__

/* interface IAlternateSyncPartners */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAlternateSyncPartners;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0A98450F-04A9-11D3-A8FB-00C04F9FC436")
    IAlternateSyncPartners : public IDispatch
    {
    public:
        virtual /* [hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT varIndex,
            /* [retval][out] */ IAlternateSyncPartner __RPC_FAR *__RPC_FAR *ppv) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *cMembers) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ IAlternateSyncPartner __RPC_FAR *pPartner) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][restricted][id][propget] */ HRESULT STDMETHODCALLTYPE get_NewEnum( 
            /* [retval][out] */ LPUNKNOWN __RPC_FAR *ppvObject) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAlternateSyncPartnersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAlternateSyncPartners __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAlternateSyncPartners __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAlternateSyncPartners __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAlternateSyncPartners __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAlternateSyncPartners __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAlternateSyncPartners __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAlternateSyncPartners __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            IAlternateSyncPartners __RPC_FAR * This,
            /* [in] */ VARIANT varIndex,
            /* [retval][out] */ IAlternateSyncPartner __RPC_FAR *__RPC_FAR *ppv);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IAlternateSyncPartners __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *cMembers);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IAlternateSyncPartners __RPC_FAR * This,
            /* [in] */ IAlternateSyncPartner __RPC_FAR *pPartner);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clear )( 
            IAlternateSyncPartners __RPC_FAR * This);
        
        /* [helpstring][restricted][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_NewEnum )( 
            IAlternateSyncPartners __RPC_FAR * This,
            /* [retval][out] */ LPUNKNOWN __RPC_FAR *ppvObject);
        
        END_INTERFACE
    } IAlternateSyncPartnersVtbl;

    interface IAlternateSyncPartners
    {
        CONST_VTBL struct IAlternateSyncPartnersVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAlternateSyncPartners_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAlternateSyncPartners_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAlternateSyncPartners_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAlternateSyncPartners_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAlternateSyncPartners_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAlternateSyncPartners_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAlternateSyncPartners_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAlternateSyncPartners_get_Item(This,varIndex,ppv)	\
    (This)->lpVtbl -> get_Item(This,varIndex,ppv)

#define IAlternateSyncPartners_get_Count(This,cMembers)	\
    (This)->lpVtbl -> get_Count(This,cMembers)

#define IAlternateSyncPartners_Add(This,pPartner)	\
    (This)->lpVtbl -> Add(This,pPartner)

#define IAlternateSyncPartners_Clear(This)	\
    (This)->lpVtbl -> Clear(This)

#define IAlternateSyncPartners_get_NewEnum(This,ppvObject)	\
    (This)->lpVtbl -> get_NewEnum(This,ppvObject)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [hidden][id][propget] */ HRESULT STDMETHODCALLTYPE IAlternateSyncPartners_get_Item_Proxy( 
    IAlternateSyncPartners __RPC_FAR * This,
    /* [in] */ VARIANT varIndex,
    /* [retval][out] */ IAlternateSyncPartner __RPC_FAR *__RPC_FAR *ppv);


void __RPC_STUB IAlternateSyncPartners_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IAlternateSyncPartners_get_Count_Proxy( 
    IAlternateSyncPartners __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *cMembers);


void __RPC_STUB IAlternateSyncPartners_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IAlternateSyncPartners_Add_Proxy( 
    IAlternateSyncPartners __RPC_FAR * This,
    /* [in] */ IAlternateSyncPartner __RPC_FAR *pPartner);


void __RPC_STUB IAlternateSyncPartners_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IAlternateSyncPartners_Clear_Proxy( 
    IAlternateSyncPartners __RPC_FAR * This);


void __RPC_STUB IAlternateSyncPartners_Clear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][restricted][id][propget] */ HRESULT STDMETHODCALLTYPE IAlternateSyncPartners_get_NewEnum_Proxy( 
    IAlternateSyncPartners __RPC_FAR * This,
    /* [retval][out] */ LPUNKNOWN __RPC_FAR *ppvObject);


void __RPC_STUB IAlternateSyncPartners_get_NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAlternateSyncPartners_INTERFACE_DEFINED__ */


#ifndef __ISQLMerge_INTERFACE_DEFINED__
#define __ISQLMerge_INTERFACE_DEFINED__

/* interface ISQLMerge */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISQLMerge;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("84923188-F94B-11d0-A8E8-00C04FC2DEB3")
    ISQLMerge : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Publication( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Publication( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Publisher( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Publisher( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PublisherDatabase( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PublisherDatabase( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PublisherSecurityMode( 
            /* [retval][out] */ REPL_SECURITY_TYPE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PublisherSecurityMode( 
            /* [in] */ REPL_SECURITY_TYPE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PublisherLogin( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PublisherLogin( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PublisherPassword( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PublisherPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Distributor( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Distributor( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DistributorSecurityMode( 
            /* [retval][out] */ REPL_SECURITY_TYPE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DistributorSecurityMode( 
            /* [in] */ REPL_SECURITY_TYPE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DistributorLogin( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DistributorLogin( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DistributorPassword( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DistributorPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Subscriber( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Subscriber( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubscriberDatabase( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubscriberDatabase( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubscriberSecurityMode( 
            /* [retval][out] */ REPL_SECURITY_TYPE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubscriberSecurityMode( 
            /* [in] */ REPL_SECURITY_TYPE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubscriberLogin( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubscriberLogin( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubscriberPassword( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubscriberPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubscriberDatasourceType( 
            /* [retval][out] */ REPL_DATASOURCE_TYPE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubscriberDatasourceType( 
            /* [in] */ REPL_DATASOURCE_TYPE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubscriberDatabasePath( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubscriberDatabasePath( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubscriptionType( 
            /* [retval][out] */ REPL_SUBSCRIPTION_TYPE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubscriptionType( 
            /* [in] */ REPL_SUBSCRIPTION_TYPE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ExchangeType( 
            /* [retval][out] */ REPL_EXCHANGE_TYPE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ExchangeType( 
            /* [in] */ REPL_EXCHANGE_TYPE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LoginTimeout( 
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LoginTimeout( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_QueryTimeout( 
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_QueryTimeout( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FTPAddress( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FTPAddress( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FTPPort( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FTPPort( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FTPLogin( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FTPLogin( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FTPPassword( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FTPPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DistributorAddress( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DistributorAddress( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DistributorNetwork( 
            /* [retval][out] */ REPL_NETWORK_TYPE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DistributorNetwork( 
            /* [in] */ REPL_NETWORK_TYPE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PublisherAddress( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PublisherAddress( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PublisherNetwork( 
            /* [retval][out] */ REPL_NETWORK_TYPE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PublisherNetwork( 
            /* [in] */ REPL_NETWORK_TYPE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PublisherChanges( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PublisherConflicts( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubscriberChanges( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubscriberConflicts( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Validate( 
            /* [retval][out] */ REPL_VALIDATE_TYPE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Validate( 
            /* [in] */ REPL_VALIDATE_TYPE newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Initialize( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddSubscription( 
            /* [in] */ REPL_DBADDOPTION DBAddOption,
            /* [in] */ REPL_SUBSCRIPTION_HOST SubscriptionHost) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DropSubscription( 
            /* [in] */ REPL_DBDROPOPTION DBDropOption) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Run( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Terminate( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReinitializeSubscription( 
            /* [defaultvalue][in] */ VARIANT_BOOL bUploadBeforeReinit = FALSE) = 0;
        
        virtual /* [helpstring][restricted][id][propput] */ HRESULT STDMETHODCALLTYPE put_PublisherEncryptedPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][restricted][id][propput] */ HRESULT STDMETHODCALLTYPE put_DistributorEncryptedPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][restricted][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubscriberEncryptedPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ProfileName( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ProfileName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ErrorRecords( 
            /* [retval][out] */ ISQLReplErrors __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HostName( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HostName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubscriptionName( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubscriptionName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][restricted][id][propput] */ HRESULT STDMETHODCALLTYPE put_HostType( 
            /* [in] */ REPL_SUBSCRIPTION_HOST newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AltSnapshotFolder( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AltSnapshotFolder( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WorkingDirectory( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_WorkingDirectory( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FileTransferType( 
            /* [retval][out] */ REPL_FILE_TRANSFER_TYPE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FileTransferType( 
            /* [in] */ REPL_FILE_TRANSFER_TYPE newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CopySubscription( 
            /* [in] */ BSTR bstrSubscriptionFileName,
            /* [defaultvalue][in] */ REPL_FILECREATE_OPTION FileCreateOption = CREATE_NEW_FILE) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UseInteractiveResolver( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseInteractiveResolver( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AlternateSyncPartners( 
            /* [retval][out] */ IAlternateSyncPartners __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SyncToAlternate( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SyncToAlternate( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubscriptionPriorityType( 
            /* [retval][out] */ REPL_SUBSCRIPTION_PRIORITY_TYPE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubscriptionPriorityType( 
            /* [in] */ REPL_SUBSCRIPTION_PRIORITY_TYPE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubscriptionPriority( 
            /* [retval][out] */ float __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubscriptionPriority( 
            /* [in] */ float newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SynchronizationType( 
            /* [retval][out] */ REPL_SYNCHRONIZATION_TYPE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SynchronizationType( 
            /* [in] */ REPL_SYNCHRONIZATION_TYPE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DynamicSnapshotLocation( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DynamicSnapshotLocation( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastUpdatedTime( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISQLMergeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISQLMerge __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISQLMerge __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISQLMerge __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Publication )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Publication )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Publisher )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Publisher )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PublisherDatabase )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PublisherDatabase )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PublisherSecurityMode )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ REPL_SECURITY_TYPE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PublisherSecurityMode )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ REPL_SECURITY_TYPE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PublisherLogin )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PublisherLogin )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PublisherPassword )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PublisherPassword )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Distributor )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Distributor )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DistributorSecurityMode )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ REPL_SECURITY_TYPE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DistributorSecurityMode )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ REPL_SECURITY_TYPE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DistributorLogin )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DistributorLogin )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DistributorPassword )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DistributorPassword )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Subscriber )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Subscriber )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SubscriberDatabase )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SubscriberDatabase )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SubscriberSecurityMode )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ REPL_SECURITY_TYPE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SubscriberSecurityMode )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ REPL_SECURITY_TYPE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SubscriberLogin )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SubscriberLogin )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SubscriberPassword )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SubscriberPassword )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SubscriberDatasourceType )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ REPL_DATASOURCE_TYPE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SubscriberDatasourceType )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ REPL_DATASOURCE_TYPE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SubscriberDatabasePath )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SubscriberDatabasePath )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SubscriptionType )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ REPL_SUBSCRIPTION_TYPE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SubscriptionType )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ REPL_SUBSCRIPTION_TYPE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ExchangeType )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ REPL_EXCHANGE_TYPE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ExchangeType )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ REPL_EXCHANGE_TYPE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LoginTimeout )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_LoginTimeout )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_QueryTimeout )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_QueryTimeout )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FTPAddress )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FTPAddress )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FTPPort )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FTPPort )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FTPLogin )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FTPLogin )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FTPPassword )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FTPPassword )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DistributorAddress )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DistributorAddress )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DistributorNetwork )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ REPL_NETWORK_TYPE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DistributorNetwork )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ REPL_NETWORK_TYPE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PublisherAddress )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PublisherAddress )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PublisherNetwork )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ REPL_NETWORK_TYPE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PublisherNetwork )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ REPL_NETWORK_TYPE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PublisherChanges )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PublisherConflicts )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SubscriberChanges )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SubscriberConflicts )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Validate )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ REPL_VALIDATE_TYPE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Validate )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ REPL_VALIDATE_TYPE newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Initialize )( 
            ISQLMerge __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddSubscription )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ REPL_DBADDOPTION DBAddOption,
            /* [in] */ REPL_SUBSCRIPTION_HOST SubscriptionHost);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DropSubscription )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ REPL_DBDROPOPTION DBDropOption);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Run )( 
            ISQLMerge __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Terminate )( 
            ISQLMerge __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReinitializeSubscription )( 
            ISQLMerge __RPC_FAR * This,
            /* [defaultvalue][in] */ VARIANT_BOOL bUploadBeforeReinit);
        
        /* [helpstring][restricted][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PublisherEncryptedPassword )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][restricted][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DistributorEncryptedPassword )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][restricted][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SubscriberEncryptedPassword )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ProfileName )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ProfileName )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ErrorRecords )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ ISQLReplErrors __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HostName )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HostName )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SubscriptionName )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SubscriptionName )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][restricted][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HostType )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ REPL_SUBSCRIPTION_HOST newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AltSnapshotFolder )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_AltSnapshotFolder )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_WorkingDirectory )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_WorkingDirectory )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FileTransferType )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ REPL_FILE_TRANSFER_TYPE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FileTransferType )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ REPL_FILE_TRANSFER_TYPE newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CopySubscription )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR bstrSubscriptionFileName,
            /* [defaultvalue][in] */ REPL_FILECREATE_OPTION FileCreateOption);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_UseInteractiveResolver )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_UseInteractiveResolver )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AlternateSyncPartners )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ IAlternateSyncPartners __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SyncToAlternate )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SyncToAlternate )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SubscriptionPriorityType )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ REPL_SUBSCRIPTION_PRIORITY_TYPE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SubscriptionPriorityType )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ REPL_SUBSCRIPTION_PRIORITY_TYPE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SubscriptionPriority )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ float __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SubscriptionPriority )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ float newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SynchronizationType )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ REPL_SYNCHRONIZATION_TYPE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SynchronizationType )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ REPL_SYNCHRONIZATION_TYPE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DynamicSnapshotLocation )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DynamicSnapshotLocation )( 
            ISQLMerge __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LastUpdatedTime )( 
            ISQLMerge __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        END_INTERFACE
    } ISQLMergeVtbl;

    interface ISQLMerge
    {
        CONST_VTBL struct ISQLMergeVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISQLMerge_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISQLMerge_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISQLMerge_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISQLMerge_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISQLMerge_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISQLMerge_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISQLMerge_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISQLMerge_get_Publication(This,pVal)	\
    (This)->lpVtbl -> get_Publication(This,pVal)

#define ISQLMerge_put_Publication(This,newVal)	\
    (This)->lpVtbl -> put_Publication(This,newVal)

#define ISQLMerge_get_Publisher(This,pVal)	\
    (This)->lpVtbl -> get_Publisher(This,pVal)

#define ISQLMerge_put_Publisher(This,newVal)	\
    (This)->lpVtbl -> put_Publisher(This,newVal)

#define ISQLMerge_get_PublisherDatabase(This,pVal)	\
    (This)->lpVtbl -> get_PublisherDatabase(This,pVal)

#define ISQLMerge_put_PublisherDatabase(This,newVal)	\
    (This)->lpVtbl -> put_PublisherDatabase(This,newVal)

#define ISQLMerge_get_PublisherSecurityMode(This,pVal)	\
    (This)->lpVtbl -> get_PublisherSecurityMode(This,pVal)

#define ISQLMerge_put_PublisherSecurityMode(This,newVal)	\
    (This)->lpVtbl -> put_PublisherSecurityMode(This,newVal)

#define ISQLMerge_get_PublisherLogin(This,pVal)	\
    (This)->lpVtbl -> get_PublisherLogin(This,pVal)

#define ISQLMerge_put_PublisherLogin(This,newVal)	\
    (This)->lpVtbl -> put_PublisherLogin(This,newVal)

#define ISQLMerge_get_PublisherPassword(This,pVal)	\
    (This)->lpVtbl -> get_PublisherPassword(This,pVal)

#define ISQLMerge_put_PublisherPassword(This,newVal)	\
    (This)->lpVtbl -> put_PublisherPassword(This,newVal)

#define ISQLMerge_get_Distributor(This,pVal)	\
    (This)->lpVtbl -> get_Distributor(This,pVal)

#define ISQLMerge_put_Distributor(This,newVal)	\
    (This)->lpVtbl -> put_Distributor(This,newVal)

#define ISQLMerge_get_DistributorSecurityMode(This,pVal)	\
    (This)->lpVtbl -> get_DistributorSecurityMode(This,pVal)

#define ISQLMerge_put_DistributorSecurityMode(This,newVal)	\
    (This)->lpVtbl -> put_DistributorSecurityMode(This,newVal)

#define ISQLMerge_get_DistributorLogin(This,pVal)	\
    (This)->lpVtbl -> get_DistributorLogin(This,pVal)

#define ISQLMerge_put_DistributorLogin(This,newVal)	\
    (This)->lpVtbl -> put_DistributorLogin(This,newVal)

#define ISQLMerge_get_DistributorPassword(This,pVal)	\
    (This)->lpVtbl -> get_DistributorPassword(This,pVal)

#define ISQLMerge_put_DistributorPassword(This,newVal)	\
    (This)->lpVtbl -> put_DistributorPassword(This,newVal)

#define ISQLMerge_get_Subscriber(This,pVal)	\
    (This)->lpVtbl -> get_Subscriber(This,pVal)

#define ISQLMerge_put_Subscriber(This,newVal)	\
    (This)->lpVtbl -> put_Subscriber(This,newVal)

#define ISQLMerge_get_SubscriberDatabase(This,pVal)	\
    (This)->lpVtbl -> get_SubscriberDatabase(This,pVal)

#define ISQLMerge_put_SubscriberDatabase(This,newVal)	\
    (This)->lpVtbl -> put_SubscriberDatabase(This,newVal)

#define ISQLMerge_get_SubscriberSecurityMode(This,pVal)	\
    (This)->lpVtbl -> get_SubscriberSecurityMode(This,pVal)

#define ISQLMerge_put_SubscriberSecurityMode(This,newVal)	\
    (This)->lpVtbl -> put_SubscriberSecurityMode(This,newVal)

#define ISQLMerge_get_SubscriberLogin(This,pVal)	\
    (This)->lpVtbl -> get_SubscriberLogin(This,pVal)

#define ISQLMerge_put_SubscriberLogin(This,newVal)	\
    (This)->lpVtbl -> put_SubscriberLogin(This,newVal)

#define ISQLMerge_get_SubscriberPassword(This,pVal)	\
    (This)->lpVtbl -> get_SubscriberPassword(This,pVal)

#define ISQLMerge_put_SubscriberPassword(This,newVal)	\
    (This)->lpVtbl -> put_SubscriberPassword(This,newVal)

#define ISQLMerge_get_SubscriberDatasourceType(This,pVal)	\
    (This)->lpVtbl -> get_SubscriberDatasourceType(This,pVal)

#define ISQLMerge_put_SubscriberDatasourceType(This,newVal)	\
    (This)->lpVtbl -> put_SubscriberDatasourceType(This,newVal)

#define ISQLMerge_get_SubscriberDatabasePath(This,pVal)	\
    (This)->lpVtbl -> get_SubscriberDatabasePath(This,pVal)

#define ISQLMerge_put_SubscriberDatabasePath(This,newVal)	\
    (This)->lpVtbl -> put_SubscriberDatabasePath(This,newVal)

#define ISQLMerge_get_SubscriptionType(This,pVal)	\
    (This)->lpVtbl -> get_SubscriptionType(This,pVal)

#define ISQLMerge_put_SubscriptionType(This,newVal)	\
    (This)->lpVtbl -> put_SubscriptionType(This,newVal)

#define ISQLMerge_get_ExchangeType(This,pVal)	\
    (This)->lpVtbl -> get_ExchangeType(This,pVal)

#define ISQLMerge_put_ExchangeType(This,newVal)	\
    (This)->lpVtbl -> put_ExchangeType(This,newVal)

#define ISQLMerge_get_LoginTimeout(This,pVal)	\
    (This)->lpVtbl -> get_LoginTimeout(This,pVal)

#define ISQLMerge_put_LoginTimeout(This,newVal)	\
    (This)->lpVtbl -> put_LoginTimeout(This,newVal)

#define ISQLMerge_get_QueryTimeout(This,pVal)	\
    (This)->lpVtbl -> get_QueryTimeout(This,pVal)

#define ISQLMerge_put_QueryTimeout(This,newVal)	\
    (This)->lpVtbl -> put_QueryTimeout(This,newVal)

#define ISQLMerge_get_FTPAddress(This,pVal)	\
    (This)->lpVtbl -> get_FTPAddress(This,pVal)

#define ISQLMerge_put_FTPAddress(This,newVal)	\
    (This)->lpVtbl -> put_FTPAddress(This,newVal)

#define ISQLMerge_get_FTPPort(This,pVal)	\
    (This)->lpVtbl -> get_FTPPort(This,pVal)

#define ISQLMerge_put_FTPPort(This,newVal)	\
    (This)->lpVtbl -> put_FTPPort(This,newVal)

#define ISQLMerge_get_FTPLogin(This,pVal)	\
    (This)->lpVtbl -> get_FTPLogin(This,pVal)

#define ISQLMerge_put_FTPLogin(This,newVal)	\
    (This)->lpVtbl -> put_FTPLogin(This,newVal)

#define ISQLMerge_get_FTPPassword(This,pVal)	\
    (This)->lpVtbl -> get_FTPPassword(This,pVal)

#define ISQLMerge_put_FTPPassword(This,newVal)	\
    (This)->lpVtbl -> put_FTPPassword(This,newVal)

#define ISQLMerge_get_DistributorAddress(This,pVal)	\
    (This)->lpVtbl -> get_DistributorAddress(This,pVal)

#define ISQLMerge_put_DistributorAddress(This,newVal)	\
    (This)->lpVtbl -> put_DistributorAddress(This,newVal)

#define ISQLMerge_get_DistributorNetwork(This,pVal)	\
    (This)->lpVtbl -> get_DistributorNetwork(This,pVal)

#define ISQLMerge_put_DistributorNetwork(This,newVal)	\
    (This)->lpVtbl -> put_DistributorNetwork(This,newVal)

#define ISQLMerge_get_PublisherAddress(This,pVal)	\
    (This)->lpVtbl -> get_PublisherAddress(This,pVal)

#define ISQLMerge_put_PublisherAddress(This,newVal)	\
    (This)->lpVtbl -> put_PublisherAddress(This,newVal)

#define ISQLMerge_get_PublisherNetwork(This,pVal)	\
    (This)->lpVtbl -> get_PublisherNetwork(This,pVal)

#define ISQLMerge_put_PublisherNetwork(This,newVal)	\
    (This)->lpVtbl -> put_PublisherNetwork(This,newVal)

#define ISQLMerge_get_PublisherChanges(This,pVal)	\
    (This)->lpVtbl -> get_PublisherChanges(This,pVal)

#define ISQLMerge_get_PublisherConflicts(This,pVal)	\
    (This)->lpVtbl -> get_PublisherConflicts(This,pVal)

#define ISQLMerge_get_SubscriberChanges(This,pVal)	\
    (This)->lpVtbl -> get_SubscriberChanges(This,pVal)

#define ISQLMerge_get_SubscriberConflicts(This,pVal)	\
    (This)->lpVtbl -> get_SubscriberConflicts(This,pVal)

#define ISQLMerge_get_Validate(This,pVal)	\
    (This)->lpVtbl -> get_Validate(This,pVal)

#define ISQLMerge_put_Validate(This,newVal)	\
    (This)->lpVtbl -> put_Validate(This,newVal)

#define ISQLMerge_Initialize(This)	\
    (This)->lpVtbl -> Initialize(This)

#define ISQLMerge_AddSubscription(This,DBAddOption,SubscriptionHost)	\
    (This)->lpVtbl -> AddSubscription(This,DBAddOption,SubscriptionHost)

#define ISQLMerge_DropSubscription(This,DBDropOption)	\
    (This)->lpVtbl -> DropSubscription(This,DBDropOption)

#define ISQLMerge_Run(This)	\
    (This)->lpVtbl -> Run(This)

#define ISQLMerge_Terminate(This)	\
    (This)->lpVtbl -> Terminate(This)

#define ISQLMerge_ReinitializeSubscription(This,bUploadBeforeReinit)	\
    (This)->lpVtbl -> ReinitializeSubscription(This,bUploadBeforeReinit)

#define ISQLMerge_put_PublisherEncryptedPassword(This,newVal)	\
    (This)->lpVtbl -> put_PublisherEncryptedPassword(This,newVal)

#define ISQLMerge_put_DistributorEncryptedPassword(This,newVal)	\
    (This)->lpVtbl -> put_DistributorEncryptedPassword(This,newVal)

#define ISQLMerge_put_SubscriberEncryptedPassword(This,newVal)	\
    (This)->lpVtbl -> put_SubscriberEncryptedPassword(This,newVal)

#define ISQLMerge_get_ProfileName(This,pVal)	\
    (This)->lpVtbl -> get_ProfileName(This,pVal)

#define ISQLMerge_put_ProfileName(This,newVal)	\
    (This)->lpVtbl -> put_ProfileName(This,newVal)

#define ISQLMerge_get_ErrorRecords(This,pVal)	\
    (This)->lpVtbl -> get_ErrorRecords(This,pVal)

#define ISQLMerge_get_HostName(This,pVal)	\
    (This)->lpVtbl -> get_HostName(This,pVal)

#define ISQLMerge_put_HostName(This,newVal)	\
    (This)->lpVtbl -> put_HostName(This,newVal)

#define ISQLMerge_get_SubscriptionName(This,pVal)	\
    (This)->lpVtbl -> get_SubscriptionName(This,pVal)

#define ISQLMerge_put_SubscriptionName(This,newVal)	\
    (This)->lpVtbl -> put_SubscriptionName(This,newVal)

#define ISQLMerge_put_HostType(This,newVal)	\
    (This)->lpVtbl -> put_HostType(This,newVal)

#define ISQLMerge_get_AltSnapshotFolder(This,pVal)	\
    (This)->lpVtbl -> get_AltSnapshotFolder(This,pVal)

#define ISQLMerge_put_AltSnapshotFolder(This,newVal)	\
    (This)->lpVtbl -> put_AltSnapshotFolder(This,newVal)

#define ISQLMerge_get_WorkingDirectory(This,pVal)	\
    (This)->lpVtbl -> get_WorkingDirectory(This,pVal)

#define ISQLMerge_put_WorkingDirectory(This,newVal)	\
    (This)->lpVtbl -> put_WorkingDirectory(This,newVal)

#define ISQLMerge_get_FileTransferType(This,pVal)	\
    (This)->lpVtbl -> get_FileTransferType(This,pVal)

#define ISQLMerge_put_FileTransferType(This,newVal)	\
    (This)->lpVtbl -> put_FileTransferType(This,newVal)

#define ISQLMerge_CopySubscription(This,bstrSubscriptionFileName,FileCreateOption)	\
    (This)->lpVtbl -> CopySubscription(This,bstrSubscriptionFileName,FileCreateOption)

#define ISQLMerge_get_UseInteractiveResolver(This,pVal)	\
    (This)->lpVtbl -> get_UseInteractiveResolver(This,pVal)

#define ISQLMerge_put_UseInteractiveResolver(This,newVal)	\
    (This)->lpVtbl -> put_UseInteractiveResolver(This,newVal)

#define ISQLMerge_get_AlternateSyncPartners(This,pVal)	\
    (This)->lpVtbl -> get_AlternateSyncPartners(This,pVal)

#define ISQLMerge_get_SyncToAlternate(This,pVal)	\
    (This)->lpVtbl -> get_SyncToAlternate(This,pVal)

#define ISQLMerge_put_SyncToAlternate(This,newVal)	\
    (This)->lpVtbl -> put_SyncToAlternate(This,newVal)

#define ISQLMerge_get_SubscriptionPriorityType(This,pVal)	\
    (This)->lpVtbl -> get_SubscriptionPriorityType(This,pVal)

#define ISQLMerge_put_SubscriptionPriorityType(This,newVal)	\
    (This)->lpVtbl -> put_SubscriptionPriorityType(This,newVal)

#define ISQLMerge_get_SubscriptionPriority(This,pVal)	\
    (This)->lpVtbl -> get_SubscriptionPriority(This,pVal)

#define ISQLMerge_put_SubscriptionPriority(This,newVal)	\
    (This)->lpVtbl -> put_SubscriptionPriority(This,newVal)

#define ISQLMerge_get_SynchronizationType(This,pVal)	\
    (This)->lpVtbl -> get_SynchronizationType(This,pVal)

#define ISQLMerge_put_SynchronizationType(This,newVal)	\
    (This)->lpVtbl -> put_SynchronizationType(This,newVal)

#define ISQLMerge_get_DynamicSnapshotLocation(This,pVal)	\
    (This)->lpVtbl -> get_DynamicSnapshotLocation(This,pVal)

#define ISQLMerge_put_DynamicSnapshotLocation(This,newVal)	\
    (This)->lpVtbl -> put_DynamicSnapshotLocation(This,newVal)

#define ISQLMerge_get_LastUpdatedTime(This,pVal)	\
    (This)->lpVtbl -> get_LastUpdatedTime(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_Publication_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_Publication_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_Publication_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_Publication_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_Publisher_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_Publisher_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_Publisher_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_Publisher_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_PublisherDatabase_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_PublisherDatabase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_PublisherDatabase_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_PublisherDatabase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_PublisherSecurityMode_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ REPL_SECURITY_TYPE __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_PublisherSecurityMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_PublisherSecurityMode_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ REPL_SECURITY_TYPE newVal);


void __RPC_STUB ISQLMerge_put_PublisherSecurityMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_PublisherLogin_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_PublisherLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_PublisherLogin_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_PublisherLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_PublisherPassword_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_PublisherPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_PublisherPassword_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_PublisherPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_Distributor_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_Distributor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_Distributor_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_Distributor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_DistributorSecurityMode_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ REPL_SECURITY_TYPE __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_DistributorSecurityMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_DistributorSecurityMode_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ REPL_SECURITY_TYPE newVal);


void __RPC_STUB ISQLMerge_put_DistributorSecurityMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_DistributorLogin_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_DistributorLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_DistributorLogin_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_DistributorLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_DistributorPassword_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_DistributorPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_DistributorPassword_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_DistributorPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_Subscriber_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_Subscriber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_Subscriber_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_Subscriber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_SubscriberDatabase_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_SubscriberDatabase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_SubscriberDatabase_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_SubscriberDatabase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_SubscriberSecurityMode_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ REPL_SECURITY_TYPE __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_SubscriberSecurityMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_SubscriberSecurityMode_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ REPL_SECURITY_TYPE newVal);


void __RPC_STUB ISQLMerge_put_SubscriberSecurityMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_SubscriberLogin_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_SubscriberLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_SubscriberLogin_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_SubscriberLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_SubscriberPassword_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_SubscriberPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_SubscriberPassword_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_SubscriberPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_SubscriberDatasourceType_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ REPL_DATASOURCE_TYPE __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_SubscriberDatasourceType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_SubscriberDatasourceType_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ REPL_DATASOURCE_TYPE newVal);


void __RPC_STUB ISQLMerge_put_SubscriberDatasourceType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_SubscriberDatabasePath_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_SubscriberDatabasePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_SubscriberDatabasePath_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_SubscriberDatabasePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_SubscriptionType_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ REPL_SUBSCRIPTION_TYPE __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_SubscriptionType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_SubscriptionType_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ REPL_SUBSCRIPTION_TYPE newVal);


void __RPC_STUB ISQLMerge_put_SubscriptionType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_ExchangeType_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ REPL_EXCHANGE_TYPE __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_ExchangeType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_ExchangeType_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ REPL_EXCHANGE_TYPE newVal);


void __RPC_STUB ISQLMerge_put_ExchangeType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_LoginTimeout_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_LoginTimeout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_LoginTimeout_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB ISQLMerge_put_LoginTimeout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_QueryTimeout_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_QueryTimeout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_QueryTimeout_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB ISQLMerge_put_QueryTimeout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_FTPAddress_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_FTPAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_FTPAddress_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_FTPAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_FTPPort_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_FTPPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_FTPPort_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB ISQLMerge_put_FTPPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_FTPLogin_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_FTPLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_FTPLogin_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_FTPLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_FTPPassword_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_FTPPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_FTPPassword_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_FTPPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_DistributorAddress_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_DistributorAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_DistributorAddress_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_DistributorAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_DistributorNetwork_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ REPL_NETWORK_TYPE __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_DistributorNetwork_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_DistributorNetwork_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ REPL_NETWORK_TYPE newVal);


void __RPC_STUB ISQLMerge_put_DistributorNetwork_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_PublisherAddress_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_PublisherAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_PublisherAddress_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_PublisherAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_PublisherNetwork_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ REPL_NETWORK_TYPE __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_PublisherNetwork_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_PublisherNetwork_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ REPL_NETWORK_TYPE newVal);


void __RPC_STUB ISQLMerge_put_PublisherNetwork_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_PublisherChanges_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_PublisherChanges_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_PublisherConflicts_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_PublisherConflicts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_SubscriberChanges_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_SubscriberChanges_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_SubscriberConflicts_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_SubscriberConflicts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_Validate_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ REPL_VALIDATE_TYPE __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_Validate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_Validate_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ REPL_VALIDATE_TYPE newVal);


void __RPC_STUB ISQLMerge_put_Validate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLMerge_Initialize_Proxy( 
    ISQLMerge __RPC_FAR * This);


void __RPC_STUB ISQLMerge_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLMerge_AddSubscription_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ REPL_DBADDOPTION DBAddOption,
    /* [in] */ REPL_SUBSCRIPTION_HOST SubscriptionHost);


void __RPC_STUB ISQLMerge_AddSubscription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLMerge_DropSubscription_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ REPL_DBDROPOPTION DBDropOption);


void __RPC_STUB ISQLMerge_DropSubscription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLMerge_Run_Proxy( 
    ISQLMerge __RPC_FAR * This);


void __RPC_STUB ISQLMerge_Run_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLMerge_Terminate_Proxy( 
    ISQLMerge __RPC_FAR * This);


void __RPC_STUB ISQLMerge_Terminate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLMerge_ReinitializeSubscription_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [defaultvalue][in] */ VARIANT_BOOL bUploadBeforeReinit);


void __RPC_STUB ISQLMerge_ReinitializeSubscription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][restricted][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_PublisherEncryptedPassword_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_PublisherEncryptedPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][restricted][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_DistributorEncryptedPassword_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_DistributorEncryptedPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][restricted][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_SubscriberEncryptedPassword_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_SubscriberEncryptedPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_ProfileName_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_ProfileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_ProfileName_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_ProfileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_ErrorRecords_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ ISQLReplErrors __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_ErrorRecords_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_HostName_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_HostName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_HostName_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_HostName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_SubscriptionName_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_SubscriptionName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_SubscriptionName_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_SubscriptionName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][restricted][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_HostType_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ REPL_SUBSCRIPTION_HOST newVal);


void __RPC_STUB ISQLMerge_put_HostType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_AltSnapshotFolder_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_AltSnapshotFolder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_AltSnapshotFolder_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_AltSnapshotFolder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_WorkingDirectory_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_WorkingDirectory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_WorkingDirectory_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_WorkingDirectory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_FileTransferType_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ REPL_FILE_TRANSFER_TYPE __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_FileTransferType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_FileTransferType_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ REPL_FILE_TRANSFER_TYPE newVal);


void __RPC_STUB ISQLMerge_put_FileTransferType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLMerge_CopySubscription_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR bstrSubscriptionFileName,
    /* [defaultvalue][in] */ REPL_FILECREATE_OPTION FileCreateOption);


void __RPC_STUB ISQLMerge_CopySubscription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_UseInteractiveResolver_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_UseInteractiveResolver_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_UseInteractiveResolver_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB ISQLMerge_put_UseInteractiveResolver_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_AlternateSyncPartners_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ IAlternateSyncPartners __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_AlternateSyncPartners_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_SyncToAlternate_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_SyncToAlternate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_SyncToAlternate_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB ISQLMerge_put_SyncToAlternate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_SubscriptionPriorityType_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ REPL_SUBSCRIPTION_PRIORITY_TYPE __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_SubscriptionPriorityType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_SubscriptionPriorityType_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ REPL_SUBSCRIPTION_PRIORITY_TYPE newVal);


void __RPC_STUB ISQLMerge_put_SubscriptionPriorityType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_SubscriptionPriority_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ float __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_SubscriptionPriority_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_SubscriptionPriority_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ float newVal);


void __RPC_STUB ISQLMerge_put_SubscriptionPriority_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_SynchronizationType_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ REPL_SYNCHRONIZATION_TYPE __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_SynchronizationType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_SynchronizationType_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ REPL_SYNCHRONIZATION_TYPE newVal);


void __RPC_STUB ISQLMerge_put_SynchronizationType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_DynamicSnapshotLocation_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_DynamicSnapshotLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLMerge_put_DynamicSnapshotLocation_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLMerge_put_DynamicSnapshotLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLMerge_get_LastUpdatedTime_Proxy( 
    ISQLMerge __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLMerge_get_LastUpdatedTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISQLMerge_INTERFACE_DEFINED__ */



#ifndef __SQLMERGXLib_LIBRARY_DEFINED__
#define __SQLMERGXLib_LIBRARY_DEFINED__

/* library SQLMERGXLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_SQLMERGXLib;

#ifndef ___SQLMergeEvents_DISPINTERFACE_DEFINED__
#define ___SQLMergeEvents_DISPINTERFACE_DEFINED__

/* dispinterface _SQLMergeEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__SQLMergeEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("84923186-F94B-11d0-A8E8-00C04FC2DEB3")
    _SQLMergeEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _SQLMergeEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _SQLMergeEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _SQLMergeEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _SQLMergeEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _SQLMergeEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _SQLMergeEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _SQLMergeEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _SQLMergeEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _SQLMergeEventsVtbl;

    interface _SQLMergeEvents
    {
        CONST_VTBL struct _SQLMergeEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _SQLMergeEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _SQLMergeEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _SQLMergeEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _SQLMergeEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _SQLMergeEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _SQLMergeEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _SQLMergeEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___SQLMergeEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SQLMerge;

#ifdef __cplusplus

class DECLSPEC_UUID("08b0b2e8-3fb3-11d3-a4de-00c04f610189")
SQLMerge;
#endif

EXTERN_C const CLSID CLSID_AlternateSyncPartner;

#ifdef __cplusplus

class DECLSPEC_UUID("0A98450E-04A9-11D3-A8FB-00C04F9FC436")
AlternateSyncPartner;
#endif

EXTERN_C const CLSID CLSID_AlternateSyncPartners;

#ifdef __cplusplus

class DECLSPEC_UUID("0A984510-04A9-11D3-A8FB-00C04F9FC436")
AlternateSyncPartners;
#endif
#endif /* __SQLMERGXLib_LIBRARY_DEFINED__ */

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
