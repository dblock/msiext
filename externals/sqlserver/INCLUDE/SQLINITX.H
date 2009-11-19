/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Aug 06 01:26:58 2000
 */
/* Compiler settings for q:\SPHINX\SQLREPL\SQLINITX\sqlinitx.idl:
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

#ifndef __sqlinitx_h__
#define __sqlinitx_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ISQLSnapshot_FWD_DEFINED__
#define __ISQLSnapshot_FWD_DEFINED__
typedef interface ISQLSnapshot ISQLSnapshot;
#endif 	/* __ISQLSnapshot_FWD_DEFINED__ */


#ifndef ___SQLSnapshotEvents_FWD_DEFINED__
#define ___SQLSnapshotEvents_FWD_DEFINED__
typedef interface _SQLSnapshotEvents _SQLSnapshotEvents;
#endif 	/* ___SQLSnapshotEvents_FWD_DEFINED__ */


#ifndef __SQLSnapshot_FWD_DEFINED__
#define __SQLSnapshot_FWD_DEFINED__

#ifdef __cplusplus
typedef class SQLSnapshot SQLSnapshot;
#else
typedef struct SQLSnapshot SQLSnapshot;
#endif /* __cplusplus */

#endif 	/* __SQLSnapshot_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "replerrx.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_sqlinitx_0000 */
/* [local] */ 

typedef 
enum REPLICATION_TYPE
    {	TRANSACTIONAL	= 1,
	MERGE	= 2
    }	REPL_REPLICATION_TYPE;

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


extern RPC_IF_HANDLE __MIDL_itf_sqlinitx_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sqlinitx_0000_v0_0_s_ifspec;

#ifndef __ISQLSnapshot_INTERFACE_DEFINED__
#define __ISQLSnapshot_INTERFACE_DEFINED__

/* interface ISQLSnapshot */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISQLSnapshot;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E02C121C-C12A-11d2-B6DB-00C04F688E8F")
    ISQLSnapshot : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Distributor( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Distributor( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DistributorLogin( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DistributorLogin( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DistributorPassword( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DistributorPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DistributorSecurityMode( 
            /* [retval][out] */ REPL_SECURITY_TYPE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DistributorSecurityMode( 
            /* [in] */ REPL_SECURITY_TYPE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LoginTimeout( 
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LoginTimeout( 
            /* [in] */ short newVal) = 0;
        
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PublisherLogin( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PublisherLogin( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PublisherPassword( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PublisherPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PublisherSecurityMode( 
            /* [retval][out] */ REPL_SECURITY_TYPE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PublisherSecurityMode( 
            /* [in] */ REPL_SECURITY_TYPE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_QueryTimeout( 
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_QueryTimeout( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Initialize( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Run( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Terminate( void) = 0;
        
        virtual /* [helpstring][restricted][id][propput] */ HRESULT STDMETHODCALLTYPE put_DistributorEncryptedPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][restricted][id][propput] */ HRESULT STDMETHODCALLTYPE put_PublisherEncryptedPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ProfileName( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ProfileName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ErrorRecords( 
            /* [retval][out] */ ISQLReplErrors __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ReplicationType( 
            /* [retval][out] */ REPL_REPLICATION_TYPE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ReplicationType( 
            /* [in] */ REPL_REPLICATION_TYPE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DynamicFilterLogin( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DynamicFilterLogin( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DynamicFilterHostName( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DynamicFilterHostName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DynamicSnapshotLocation( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DynamicSnapshotLocation( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISQLSnapshotVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISQLSnapshot __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISQLSnapshot __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Distributor )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Distributor )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DistributorLogin )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DistributorLogin )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DistributorPassword )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DistributorPassword )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DistributorSecurityMode )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [retval][out] */ REPL_SECURITY_TYPE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DistributorSecurityMode )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [in] */ REPL_SECURITY_TYPE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LoginTimeout )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_LoginTimeout )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Publication )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Publication )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Publisher )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Publisher )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PublisherDatabase )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PublisherDatabase )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PublisherLogin )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PublisherLogin )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PublisherPassword )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PublisherPassword )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PublisherSecurityMode )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [retval][out] */ REPL_SECURITY_TYPE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PublisherSecurityMode )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [in] */ REPL_SECURITY_TYPE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_QueryTimeout )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_QueryTimeout )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Initialize )( 
            ISQLSnapshot __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Run )( 
            ISQLSnapshot __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Terminate )( 
            ISQLSnapshot __RPC_FAR * This);
        
        /* [helpstring][restricted][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DistributorEncryptedPassword )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][restricted][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PublisherEncryptedPassword )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ProfileName )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ProfileName )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ErrorRecords )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [retval][out] */ ISQLReplErrors __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ReplicationType )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [retval][out] */ REPL_REPLICATION_TYPE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ReplicationType )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [in] */ REPL_REPLICATION_TYPE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DynamicFilterLogin )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DynamicFilterLogin )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DynamicFilterHostName )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DynamicFilterHostName )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DynamicSnapshotLocation )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DynamicSnapshotLocation )( 
            ISQLSnapshot __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } ISQLSnapshotVtbl;

    interface ISQLSnapshot
    {
        CONST_VTBL struct ISQLSnapshotVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISQLSnapshot_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISQLSnapshot_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISQLSnapshot_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISQLSnapshot_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISQLSnapshot_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISQLSnapshot_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISQLSnapshot_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISQLSnapshot_get_Distributor(This,pVal)	\
    (This)->lpVtbl -> get_Distributor(This,pVal)

#define ISQLSnapshot_put_Distributor(This,newVal)	\
    (This)->lpVtbl -> put_Distributor(This,newVal)

#define ISQLSnapshot_get_DistributorLogin(This,pVal)	\
    (This)->lpVtbl -> get_DistributorLogin(This,pVal)

#define ISQLSnapshot_put_DistributorLogin(This,newVal)	\
    (This)->lpVtbl -> put_DistributorLogin(This,newVal)

#define ISQLSnapshot_get_DistributorPassword(This,pVal)	\
    (This)->lpVtbl -> get_DistributorPassword(This,pVal)

#define ISQLSnapshot_put_DistributorPassword(This,newVal)	\
    (This)->lpVtbl -> put_DistributorPassword(This,newVal)

#define ISQLSnapshot_get_DistributorSecurityMode(This,pVal)	\
    (This)->lpVtbl -> get_DistributorSecurityMode(This,pVal)

#define ISQLSnapshot_put_DistributorSecurityMode(This,newVal)	\
    (This)->lpVtbl -> put_DistributorSecurityMode(This,newVal)

#define ISQLSnapshot_get_LoginTimeout(This,pVal)	\
    (This)->lpVtbl -> get_LoginTimeout(This,pVal)

#define ISQLSnapshot_put_LoginTimeout(This,newVal)	\
    (This)->lpVtbl -> put_LoginTimeout(This,newVal)

#define ISQLSnapshot_get_Publication(This,pVal)	\
    (This)->lpVtbl -> get_Publication(This,pVal)

#define ISQLSnapshot_put_Publication(This,newVal)	\
    (This)->lpVtbl -> put_Publication(This,newVal)

#define ISQLSnapshot_get_Publisher(This,pVal)	\
    (This)->lpVtbl -> get_Publisher(This,pVal)

#define ISQLSnapshot_put_Publisher(This,newVal)	\
    (This)->lpVtbl -> put_Publisher(This,newVal)

#define ISQLSnapshot_get_PublisherDatabase(This,pVal)	\
    (This)->lpVtbl -> get_PublisherDatabase(This,pVal)

#define ISQLSnapshot_put_PublisherDatabase(This,newVal)	\
    (This)->lpVtbl -> put_PublisherDatabase(This,newVal)

#define ISQLSnapshot_get_PublisherLogin(This,pVal)	\
    (This)->lpVtbl -> get_PublisherLogin(This,pVal)

#define ISQLSnapshot_put_PublisherLogin(This,newVal)	\
    (This)->lpVtbl -> put_PublisherLogin(This,newVal)

#define ISQLSnapshot_get_PublisherPassword(This,pVal)	\
    (This)->lpVtbl -> get_PublisherPassword(This,pVal)

#define ISQLSnapshot_put_PublisherPassword(This,newVal)	\
    (This)->lpVtbl -> put_PublisherPassword(This,newVal)

#define ISQLSnapshot_get_PublisherSecurityMode(This,pVal)	\
    (This)->lpVtbl -> get_PublisherSecurityMode(This,pVal)

#define ISQLSnapshot_put_PublisherSecurityMode(This,newVal)	\
    (This)->lpVtbl -> put_PublisherSecurityMode(This,newVal)

#define ISQLSnapshot_get_QueryTimeout(This,pVal)	\
    (This)->lpVtbl -> get_QueryTimeout(This,pVal)

#define ISQLSnapshot_put_QueryTimeout(This,newVal)	\
    (This)->lpVtbl -> put_QueryTimeout(This,newVal)

#define ISQLSnapshot_Initialize(This)	\
    (This)->lpVtbl -> Initialize(This)

#define ISQLSnapshot_Run(This)	\
    (This)->lpVtbl -> Run(This)

#define ISQLSnapshot_Terminate(This)	\
    (This)->lpVtbl -> Terminate(This)

#define ISQLSnapshot_put_DistributorEncryptedPassword(This,newVal)	\
    (This)->lpVtbl -> put_DistributorEncryptedPassword(This,newVal)

#define ISQLSnapshot_put_PublisherEncryptedPassword(This,newVal)	\
    (This)->lpVtbl -> put_PublisherEncryptedPassword(This,newVal)

#define ISQLSnapshot_get_ProfileName(This,pVal)	\
    (This)->lpVtbl -> get_ProfileName(This,pVal)

#define ISQLSnapshot_put_ProfileName(This,newVal)	\
    (This)->lpVtbl -> put_ProfileName(This,newVal)

#define ISQLSnapshot_get_ErrorRecords(This,pVal)	\
    (This)->lpVtbl -> get_ErrorRecords(This,pVal)

#define ISQLSnapshot_get_ReplicationType(This,pVal)	\
    (This)->lpVtbl -> get_ReplicationType(This,pVal)

#define ISQLSnapshot_put_ReplicationType(This,newVal)	\
    (This)->lpVtbl -> put_ReplicationType(This,newVal)

#define ISQLSnapshot_get_DynamicFilterLogin(This,pVal)	\
    (This)->lpVtbl -> get_DynamicFilterLogin(This,pVal)

#define ISQLSnapshot_put_DynamicFilterLogin(This,newVal)	\
    (This)->lpVtbl -> put_DynamicFilterLogin(This,newVal)

#define ISQLSnapshot_get_DynamicFilterHostName(This,pVal)	\
    (This)->lpVtbl -> get_DynamicFilterHostName(This,pVal)

#define ISQLSnapshot_put_DynamicFilterHostName(This,newVal)	\
    (This)->lpVtbl -> put_DynamicFilterHostName(This,newVal)

#define ISQLSnapshot_get_DynamicSnapshotLocation(This,pVal)	\
    (This)->lpVtbl -> get_DynamicSnapshotLocation(This,pVal)

#define ISQLSnapshot_put_DynamicSnapshotLocation(This,newVal)	\
    (This)->lpVtbl -> put_DynamicSnapshotLocation(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_get_Distributor_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLSnapshot_get_Distributor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_put_Distributor_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLSnapshot_put_Distributor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_get_DistributorLogin_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLSnapshot_get_DistributorLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_put_DistributorLogin_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLSnapshot_put_DistributorLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_get_DistributorPassword_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLSnapshot_get_DistributorPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_put_DistributorPassword_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLSnapshot_put_DistributorPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_get_DistributorSecurityMode_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [retval][out] */ REPL_SECURITY_TYPE __RPC_FAR *pVal);


void __RPC_STUB ISQLSnapshot_get_DistributorSecurityMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_put_DistributorSecurityMode_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [in] */ REPL_SECURITY_TYPE newVal);


void __RPC_STUB ISQLSnapshot_put_DistributorSecurityMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_get_LoginTimeout_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB ISQLSnapshot_get_LoginTimeout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_put_LoginTimeout_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB ISQLSnapshot_put_LoginTimeout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_get_Publication_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLSnapshot_get_Publication_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_put_Publication_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLSnapshot_put_Publication_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_get_Publisher_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLSnapshot_get_Publisher_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_put_Publisher_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLSnapshot_put_Publisher_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_get_PublisherDatabase_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLSnapshot_get_PublisherDatabase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_put_PublisherDatabase_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLSnapshot_put_PublisherDatabase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_get_PublisherLogin_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLSnapshot_get_PublisherLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_put_PublisherLogin_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLSnapshot_put_PublisherLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_get_PublisherPassword_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLSnapshot_get_PublisherPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_put_PublisherPassword_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLSnapshot_put_PublisherPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_get_PublisherSecurityMode_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [retval][out] */ REPL_SECURITY_TYPE __RPC_FAR *pVal);


void __RPC_STUB ISQLSnapshot_get_PublisherSecurityMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_put_PublisherSecurityMode_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [in] */ REPL_SECURITY_TYPE newVal);


void __RPC_STUB ISQLSnapshot_put_PublisherSecurityMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_get_QueryTimeout_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB ISQLSnapshot_get_QueryTimeout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_put_QueryTimeout_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB ISQLSnapshot_put_QueryTimeout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_Initialize_Proxy( 
    ISQLSnapshot __RPC_FAR * This);


void __RPC_STUB ISQLSnapshot_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_Run_Proxy( 
    ISQLSnapshot __RPC_FAR * This);


void __RPC_STUB ISQLSnapshot_Run_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_Terminate_Proxy( 
    ISQLSnapshot __RPC_FAR * This);


void __RPC_STUB ISQLSnapshot_Terminate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][restricted][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_put_DistributorEncryptedPassword_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLSnapshot_put_DistributorEncryptedPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][restricted][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_put_PublisherEncryptedPassword_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLSnapshot_put_PublisherEncryptedPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_get_ProfileName_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLSnapshot_get_ProfileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_put_ProfileName_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLSnapshot_put_ProfileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_get_ErrorRecords_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [retval][out] */ ISQLReplErrors __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB ISQLSnapshot_get_ErrorRecords_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_get_ReplicationType_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [retval][out] */ REPL_REPLICATION_TYPE __RPC_FAR *pVal);


void __RPC_STUB ISQLSnapshot_get_ReplicationType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_put_ReplicationType_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [in] */ REPL_REPLICATION_TYPE newVal);


void __RPC_STUB ISQLSnapshot_put_ReplicationType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_get_DynamicFilterLogin_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLSnapshot_get_DynamicFilterLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_put_DynamicFilterLogin_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLSnapshot_put_DynamicFilterLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_get_DynamicFilterHostName_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLSnapshot_get_DynamicFilterHostName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_put_DynamicFilterHostName_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLSnapshot_put_DynamicFilterHostName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_get_DynamicSnapshotLocation_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLSnapshot_get_DynamicSnapshotLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLSnapshot_put_DynamicSnapshotLocation_Proxy( 
    ISQLSnapshot __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLSnapshot_put_DynamicSnapshotLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISQLSnapshot_INTERFACE_DEFINED__ */



#ifndef __SQLINITXLib_LIBRARY_DEFINED__
#define __SQLINITXLib_LIBRARY_DEFINED__

/* library SQLINITXLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_SQLINITXLib;

#ifndef ___SQLSnapshotEvents_DISPINTERFACE_DEFINED__
#define ___SQLSnapshotEvents_DISPINTERFACE_DEFINED__

/* dispinterface _SQLSnapshotEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__SQLSnapshotEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("E02C121E-C12A-11d2-B6DB-00C04F688E8F")
    _SQLSnapshotEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _SQLSnapshotEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _SQLSnapshotEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _SQLSnapshotEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _SQLSnapshotEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _SQLSnapshotEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _SQLSnapshotEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _SQLSnapshotEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _SQLSnapshotEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _SQLSnapshotEventsVtbl;

    interface _SQLSnapshotEvents
    {
        CONST_VTBL struct _SQLSnapshotEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _SQLSnapshotEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _SQLSnapshotEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _SQLSnapshotEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _SQLSnapshotEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _SQLSnapshotEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _SQLSnapshotEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _SQLSnapshotEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___SQLSnapshotEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SQLSnapshot;

#ifdef __cplusplus

class DECLSPEC_UUID("E02C121F-C12A-11d2-B6DB-00C04F688E8F")
SQLSnapshot;
#endif
#endif /* __SQLINITXLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
