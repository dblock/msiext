/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Aug 06 01:08:06 2000
 */
/* Compiler settings for q:\SPHINX\SQLREPL\SQLDISTX\sqldistx.idl:
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

#ifndef __sqldistx_h__
#define __sqldistx_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ISQLDistribution_FWD_DEFINED__
#define __ISQLDistribution_FWD_DEFINED__
typedef interface ISQLDistribution ISQLDistribution;
#endif 	/* __ISQLDistribution_FWD_DEFINED__ */


#ifndef ___SQLDistributionEvents_FWD_DEFINED__
#define ___SQLDistributionEvents_FWD_DEFINED__
typedef interface _SQLDistributionEvents _SQLDistributionEvents;
#endif 	/* ___SQLDistributionEvents_FWD_DEFINED__ */


#ifndef __SQLDistribution_FWD_DEFINED__
#define __SQLDistribution_FWD_DEFINED__

#ifdef __cplusplus
typedef class SQLDistribution SQLDistribution;
#else
typedef struct SQLDistribution SQLDistribution;
#endif /* __cplusplus */

#endif 	/* __SQLDistribution_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "replerrx.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_sqldistx_0000 */
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

#define S_REPLX_CANCELLED	MAKE_SCODE(SEVERITY_SUCCESS,FACILITY_ITF,0x0101)
#define E_REPLX_NAMETOOLONG	MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x0102)
#define E_REPLX_NAMETOOSHORT	MAKE_SCODE(SEVERITY_ERROR,FACILITY_ITF,0x0103)
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

#endif // COMMON_REPL_ENUMS_DEFINED
typedef 
enum REPL_FAILOVER_MODE
    {	FAILOVER_NONE	= 0,
	FAILOVER_IMMEDIATE	= 1,
	FAILOVER_QUEUED	= 2
    }	REPL_FAILOVER_MODE_TYPE;

typedef 
enum SUBSCRIPTION_UPDATE_MODE
    {	UPDMODE_READONLY	= 0,
	UPDMODE_SYNCTRAN	= 1,
	UPDMODE_QUEUEDTRAN	= 2,
	UPDMODE_FAILOVER	= 3
    }	REPL_SUBSCRIPTION_UPDATE_MODE;

typedef 
enum REPLRPC_SECURITY_TYPE
    {	RPC_STANDARD_MODE	= 0,
	RPC_STATIC_MODE	= 2
    }	REPLRPC_SECURITY_TYPE;



extern RPC_IF_HANDLE __MIDL_itf_sqldistx_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sqldistx_0000_v0_0_s_ifspec;

#ifndef __ISQLDistribution_INTERFACE_DEFINED__
#define __ISQLDistribution_INTERFACE_DEFINED__

/* interface ISQLDistribution */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ISQLDistribution;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9BD37E1C-BB55-11D0-94E7-00C04FC2DB9C")
    ISQLDistribution : public IDispatch
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxDeliveredTransactions( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxDeliveredTransactions( 
            /* [in] */ long newVal) = 0;
        
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Subscriber( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Subscriber( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubscriberDatabase( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubscriberDatabase( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubscriberDatabasePath( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubscriberDatabasePath( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubscriberLogin( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubscriberLogin( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubscriberPassword( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubscriberPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubscriberSecurityMode( 
            /* [retval][out] */ REPL_SECURITY_TYPE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubscriberSecurityMode( 
            /* [in] */ REPL_SECURITY_TYPE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubscriberDatasourceType( 
            /* [retval][out] */ REPL_DATASOURCE_TYPE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubscriberDatasourceType( 
            /* [in] */ REPL_DATASOURCE_TYPE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubscriptionType( 
            /* [retval][out] */ REPL_SUBSCRIPTION_TYPE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubscriptionType( 
            /* [in] */ REPL_SUBSCRIPTION_TYPE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UndeliveredCommands( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UndeliveredTransactions( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FTPAddress( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FTPAddress( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FTPLogin( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FTPLogin( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FTPPassword( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FTPPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FTPPort( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FTPPort( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Initialize( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddSubscription( 
            /* [in] */ REPL_DBADDOPTION DBAddOption,
            /* [in] */ REPL_SUBSCRIPTION_HOST SubscriptionHost) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DropSubscription( 
            /* [in] */ REPL_DBDROPOPTION DBDropOption) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Run( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Terminate( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReinitializeSubscription( void) = 0;
        
        virtual /* [helpstring][restricted][id][propput] */ HRESULT STDMETHODCALLTYPE put_DistributorEncryptedPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][restricted][id][propput] */ HRESULT STDMETHODCALLTYPE put_PublisherEncryptedPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][restricted][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubscriberEncryptedPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ProfileName( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ProfileName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ErrorRecords( 
            /* [retval][out] */ ISQLReplErrors __RPC_FAR *__RPC_FAR *pVal) = 0;
        
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DTSPackageFileName( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DTSPackageFileName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DTSPackagePassword( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DTSPackagePassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CopySubscription( 
            /* [in] */ BSTR bstrSubscriptionFileName,
            /* [defaultvalue][in] */ REPL_FILECREATE_OPTION FileCreateOption = CREATE_NEW_FILE) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetFailoverMode( 
            /* [in] */ REPL_FAILOVER_MODE_TYPE failoverMode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SynchronizationType( 
            /* [retval][out] */ REPL_SYNCHRONIZATION_TYPE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SynchronizationType( 
            /* [in] */ REPL_SYNCHRONIZATION_TYPE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SkipErrors( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SkipErrors( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubscriptionUpdateMode( 
            /* [retval][out] */ REPL_SUBSCRIPTION_UPDATE_MODE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubscriptionUpdateMode( 
            /* [in] */ REPL_SUBSCRIPTION_UPDATE_MODE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PublisherRPCLogin( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PublisherRPCLogin( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PublisherRPCPassword( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PublisherRPCPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HostName( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HostName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastUpdatedTime( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PublisherRPCSecurityMode( 
            /* [retval][out] */ REPLRPC_SECURITY_TYPE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PublisherRPCSecurityMode( 
            /* [in] */ REPLRPC_SECURITY_TYPE newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISQLDistributionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISQLDistribution __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISQLDistribution __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISQLDistribution __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Distributor )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Distributor )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DistributorLogin )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DistributorLogin )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DistributorPassword )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DistributorPassword )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DistributorSecurityMode )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ REPL_SECURITY_TYPE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DistributorSecurityMode )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ REPL_SECURITY_TYPE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LoginTimeout )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_LoginTimeout )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MaxDeliveredTransactions )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_MaxDeliveredTransactions )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Publication )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Publication )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Publisher )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Publisher )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PublisherDatabase )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PublisherDatabase )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PublisherLogin )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PublisherLogin )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PublisherPassword )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PublisherPassword )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PublisherSecurityMode )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ REPL_SECURITY_TYPE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PublisherSecurityMode )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ REPL_SECURITY_TYPE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_QueryTimeout )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_QueryTimeout )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Subscriber )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Subscriber )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SubscriberDatabase )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SubscriberDatabase )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SubscriberDatabasePath )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SubscriberDatabasePath )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SubscriberLogin )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SubscriberLogin )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SubscriberPassword )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SubscriberPassword )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SubscriberSecurityMode )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ REPL_SECURITY_TYPE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SubscriberSecurityMode )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ REPL_SECURITY_TYPE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SubscriberDatasourceType )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ REPL_DATASOURCE_TYPE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SubscriberDatasourceType )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ REPL_DATASOURCE_TYPE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SubscriptionType )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ REPL_SUBSCRIPTION_TYPE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SubscriptionType )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ REPL_SUBSCRIPTION_TYPE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_UndeliveredCommands )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_UndeliveredTransactions )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DistributorAddress )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DistributorAddress )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DistributorNetwork )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ REPL_NETWORK_TYPE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DistributorNetwork )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ REPL_NETWORK_TYPE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PublisherAddress )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PublisherAddress )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PublisherNetwork )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ REPL_NETWORK_TYPE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PublisherNetwork )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ REPL_NETWORK_TYPE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FTPAddress )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FTPAddress )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FTPLogin )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FTPLogin )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FTPPassword )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FTPPassword )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FTPPort )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FTPPort )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Initialize )( 
            ISQLDistribution __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddSubscription )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ REPL_DBADDOPTION DBAddOption,
            /* [in] */ REPL_SUBSCRIPTION_HOST SubscriptionHost);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DropSubscription )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ REPL_DBDROPOPTION DBDropOption);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Run )( 
            ISQLDistribution __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Terminate )( 
            ISQLDistribution __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReinitializeSubscription )( 
            ISQLDistribution __RPC_FAR * This);
        
        /* [helpstring][restricted][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DistributorEncryptedPassword )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][restricted][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PublisherEncryptedPassword )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][restricted][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SubscriberEncryptedPassword )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ProfileName )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ProfileName )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ErrorRecords )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ ISQLReplErrors __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SubscriptionName )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SubscriptionName )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][restricted][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HostType )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ REPL_SUBSCRIPTION_HOST newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AltSnapshotFolder )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_AltSnapshotFolder )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_WorkingDirectory )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_WorkingDirectory )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FileTransferType )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ REPL_FILE_TRANSFER_TYPE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FileTransferType )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ REPL_FILE_TRANSFER_TYPE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DTSPackageFileName )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DTSPackageFileName )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DTSPackagePassword )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DTSPackagePassword )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CopySubscription )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR bstrSubscriptionFileName,
            /* [defaultvalue][in] */ REPL_FILECREATE_OPTION FileCreateOption);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFailoverMode )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ REPL_FAILOVER_MODE_TYPE failoverMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SynchronizationType )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ REPL_SYNCHRONIZATION_TYPE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SynchronizationType )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ REPL_SYNCHRONIZATION_TYPE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SkipErrors )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SkipErrors )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SubscriptionUpdateMode )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ REPL_SUBSCRIPTION_UPDATE_MODE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SubscriptionUpdateMode )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ REPL_SUBSCRIPTION_UPDATE_MODE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PublisherRPCLogin )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PublisherRPCLogin )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PublisherRPCPassword )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PublisherRPCPassword )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HostName )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HostName )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LastUpdatedTime )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PublisherRPCSecurityMode )( 
            ISQLDistribution __RPC_FAR * This,
            /* [retval][out] */ REPLRPC_SECURITY_TYPE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PublisherRPCSecurityMode )( 
            ISQLDistribution __RPC_FAR * This,
            /* [in] */ REPLRPC_SECURITY_TYPE newVal);
        
        END_INTERFACE
    } ISQLDistributionVtbl;

    interface ISQLDistribution
    {
        CONST_VTBL struct ISQLDistributionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISQLDistribution_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISQLDistribution_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISQLDistribution_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISQLDistribution_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISQLDistribution_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISQLDistribution_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISQLDistribution_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISQLDistribution_get_Distributor(This,pVal)	\
    (This)->lpVtbl -> get_Distributor(This,pVal)

#define ISQLDistribution_put_Distributor(This,newVal)	\
    (This)->lpVtbl -> put_Distributor(This,newVal)

#define ISQLDistribution_get_DistributorLogin(This,pVal)	\
    (This)->lpVtbl -> get_DistributorLogin(This,pVal)

#define ISQLDistribution_put_DistributorLogin(This,newVal)	\
    (This)->lpVtbl -> put_DistributorLogin(This,newVal)

#define ISQLDistribution_get_DistributorPassword(This,pVal)	\
    (This)->lpVtbl -> get_DistributorPassword(This,pVal)

#define ISQLDistribution_put_DistributorPassword(This,newVal)	\
    (This)->lpVtbl -> put_DistributorPassword(This,newVal)

#define ISQLDistribution_get_DistributorSecurityMode(This,pVal)	\
    (This)->lpVtbl -> get_DistributorSecurityMode(This,pVal)

#define ISQLDistribution_put_DistributorSecurityMode(This,newVal)	\
    (This)->lpVtbl -> put_DistributorSecurityMode(This,newVal)

#define ISQLDistribution_get_LoginTimeout(This,pVal)	\
    (This)->lpVtbl -> get_LoginTimeout(This,pVal)

#define ISQLDistribution_put_LoginTimeout(This,newVal)	\
    (This)->lpVtbl -> put_LoginTimeout(This,newVal)

#define ISQLDistribution_get_MaxDeliveredTransactions(This,pVal)	\
    (This)->lpVtbl -> get_MaxDeliveredTransactions(This,pVal)

#define ISQLDistribution_put_MaxDeliveredTransactions(This,newVal)	\
    (This)->lpVtbl -> put_MaxDeliveredTransactions(This,newVal)

#define ISQLDistribution_get_Publication(This,pVal)	\
    (This)->lpVtbl -> get_Publication(This,pVal)

#define ISQLDistribution_put_Publication(This,newVal)	\
    (This)->lpVtbl -> put_Publication(This,newVal)

#define ISQLDistribution_get_Publisher(This,pVal)	\
    (This)->lpVtbl -> get_Publisher(This,pVal)

#define ISQLDistribution_put_Publisher(This,newVal)	\
    (This)->lpVtbl -> put_Publisher(This,newVal)

#define ISQLDistribution_get_PublisherDatabase(This,pVal)	\
    (This)->lpVtbl -> get_PublisherDatabase(This,pVal)

#define ISQLDistribution_put_PublisherDatabase(This,newVal)	\
    (This)->lpVtbl -> put_PublisherDatabase(This,newVal)

#define ISQLDistribution_get_PublisherLogin(This,pVal)	\
    (This)->lpVtbl -> get_PublisherLogin(This,pVal)

#define ISQLDistribution_put_PublisherLogin(This,newVal)	\
    (This)->lpVtbl -> put_PublisherLogin(This,newVal)

#define ISQLDistribution_get_PublisherPassword(This,pVal)	\
    (This)->lpVtbl -> get_PublisherPassword(This,pVal)

#define ISQLDistribution_put_PublisherPassword(This,newVal)	\
    (This)->lpVtbl -> put_PublisherPassword(This,newVal)

#define ISQLDistribution_get_PublisherSecurityMode(This,pVal)	\
    (This)->lpVtbl -> get_PublisherSecurityMode(This,pVal)

#define ISQLDistribution_put_PublisherSecurityMode(This,newVal)	\
    (This)->lpVtbl -> put_PublisherSecurityMode(This,newVal)

#define ISQLDistribution_get_QueryTimeout(This,pVal)	\
    (This)->lpVtbl -> get_QueryTimeout(This,pVal)

#define ISQLDistribution_put_QueryTimeout(This,newVal)	\
    (This)->lpVtbl -> put_QueryTimeout(This,newVal)

#define ISQLDistribution_get_Subscriber(This,pVal)	\
    (This)->lpVtbl -> get_Subscriber(This,pVal)

#define ISQLDistribution_put_Subscriber(This,newVal)	\
    (This)->lpVtbl -> put_Subscriber(This,newVal)

#define ISQLDistribution_get_SubscriberDatabase(This,pVal)	\
    (This)->lpVtbl -> get_SubscriberDatabase(This,pVal)

#define ISQLDistribution_put_SubscriberDatabase(This,newVal)	\
    (This)->lpVtbl -> put_SubscriberDatabase(This,newVal)

#define ISQLDistribution_get_SubscriberDatabasePath(This,pVal)	\
    (This)->lpVtbl -> get_SubscriberDatabasePath(This,pVal)

#define ISQLDistribution_put_SubscriberDatabasePath(This,newVal)	\
    (This)->lpVtbl -> put_SubscriberDatabasePath(This,newVal)

#define ISQLDistribution_get_SubscriberLogin(This,pVal)	\
    (This)->lpVtbl -> get_SubscriberLogin(This,pVal)

#define ISQLDistribution_put_SubscriberLogin(This,newVal)	\
    (This)->lpVtbl -> put_SubscriberLogin(This,newVal)

#define ISQLDistribution_get_SubscriberPassword(This,pVal)	\
    (This)->lpVtbl -> get_SubscriberPassword(This,pVal)

#define ISQLDistribution_put_SubscriberPassword(This,newVal)	\
    (This)->lpVtbl -> put_SubscriberPassword(This,newVal)

#define ISQLDistribution_get_SubscriberSecurityMode(This,pVal)	\
    (This)->lpVtbl -> get_SubscriberSecurityMode(This,pVal)

#define ISQLDistribution_put_SubscriberSecurityMode(This,newVal)	\
    (This)->lpVtbl -> put_SubscriberSecurityMode(This,newVal)

#define ISQLDistribution_get_SubscriberDatasourceType(This,pVal)	\
    (This)->lpVtbl -> get_SubscriberDatasourceType(This,pVal)

#define ISQLDistribution_put_SubscriberDatasourceType(This,newVal)	\
    (This)->lpVtbl -> put_SubscriberDatasourceType(This,newVal)

#define ISQLDistribution_get_SubscriptionType(This,pVal)	\
    (This)->lpVtbl -> get_SubscriptionType(This,pVal)

#define ISQLDistribution_put_SubscriptionType(This,newVal)	\
    (This)->lpVtbl -> put_SubscriptionType(This,newVal)

#define ISQLDistribution_get_UndeliveredCommands(This,pVal)	\
    (This)->lpVtbl -> get_UndeliveredCommands(This,pVal)

#define ISQLDistribution_get_UndeliveredTransactions(This,pVal)	\
    (This)->lpVtbl -> get_UndeliveredTransactions(This,pVal)

#define ISQLDistribution_get_DistributorAddress(This,pVal)	\
    (This)->lpVtbl -> get_DistributorAddress(This,pVal)

#define ISQLDistribution_put_DistributorAddress(This,newVal)	\
    (This)->lpVtbl -> put_DistributorAddress(This,newVal)

#define ISQLDistribution_get_DistributorNetwork(This,pVal)	\
    (This)->lpVtbl -> get_DistributorNetwork(This,pVal)

#define ISQLDistribution_put_DistributorNetwork(This,newVal)	\
    (This)->lpVtbl -> put_DistributorNetwork(This,newVal)

#define ISQLDistribution_get_PublisherAddress(This,pVal)	\
    (This)->lpVtbl -> get_PublisherAddress(This,pVal)

#define ISQLDistribution_put_PublisherAddress(This,newVal)	\
    (This)->lpVtbl -> put_PublisherAddress(This,newVal)

#define ISQLDistribution_get_PublisherNetwork(This,pVal)	\
    (This)->lpVtbl -> get_PublisherNetwork(This,pVal)

#define ISQLDistribution_put_PublisherNetwork(This,newVal)	\
    (This)->lpVtbl -> put_PublisherNetwork(This,newVal)

#define ISQLDistribution_get_FTPAddress(This,pVal)	\
    (This)->lpVtbl -> get_FTPAddress(This,pVal)

#define ISQLDistribution_put_FTPAddress(This,newVal)	\
    (This)->lpVtbl -> put_FTPAddress(This,newVal)

#define ISQLDistribution_get_FTPLogin(This,pVal)	\
    (This)->lpVtbl -> get_FTPLogin(This,pVal)

#define ISQLDistribution_put_FTPLogin(This,newVal)	\
    (This)->lpVtbl -> put_FTPLogin(This,newVal)

#define ISQLDistribution_get_FTPPassword(This,pVal)	\
    (This)->lpVtbl -> get_FTPPassword(This,pVal)

#define ISQLDistribution_put_FTPPassword(This,newVal)	\
    (This)->lpVtbl -> put_FTPPassword(This,newVal)

#define ISQLDistribution_get_FTPPort(This,pVal)	\
    (This)->lpVtbl -> get_FTPPort(This,pVal)

#define ISQLDistribution_put_FTPPort(This,newVal)	\
    (This)->lpVtbl -> put_FTPPort(This,newVal)

#define ISQLDistribution_Initialize(This)	\
    (This)->lpVtbl -> Initialize(This)

#define ISQLDistribution_AddSubscription(This,DBAddOption,SubscriptionHost)	\
    (This)->lpVtbl -> AddSubscription(This,DBAddOption,SubscriptionHost)

#define ISQLDistribution_DropSubscription(This,DBDropOption)	\
    (This)->lpVtbl -> DropSubscription(This,DBDropOption)

#define ISQLDistribution_Run(This)	\
    (This)->lpVtbl -> Run(This)

#define ISQLDistribution_Terminate(This)	\
    (This)->lpVtbl -> Terminate(This)

#define ISQLDistribution_ReinitializeSubscription(This)	\
    (This)->lpVtbl -> ReinitializeSubscription(This)

#define ISQLDistribution_put_DistributorEncryptedPassword(This,newVal)	\
    (This)->lpVtbl -> put_DistributorEncryptedPassword(This,newVal)

#define ISQLDistribution_put_PublisherEncryptedPassword(This,newVal)	\
    (This)->lpVtbl -> put_PublisherEncryptedPassword(This,newVal)

#define ISQLDistribution_put_SubscriberEncryptedPassword(This,newVal)	\
    (This)->lpVtbl -> put_SubscriberEncryptedPassword(This,newVal)

#define ISQLDistribution_get_ProfileName(This,pVal)	\
    (This)->lpVtbl -> get_ProfileName(This,pVal)

#define ISQLDistribution_put_ProfileName(This,newVal)	\
    (This)->lpVtbl -> put_ProfileName(This,newVal)

#define ISQLDistribution_get_ErrorRecords(This,pVal)	\
    (This)->lpVtbl -> get_ErrorRecords(This,pVal)

#define ISQLDistribution_get_SubscriptionName(This,pVal)	\
    (This)->lpVtbl -> get_SubscriptionName(This,pVal)

#define ISQLDistribution_put_SubscriptionName(This,newVal)	\
    (This)->lpVtbl -> put_SubscriptionName(This,newVal)

#define ISQLDistribution_put_HostType(This,newVal)	\
    (This)->lpVtbl -> put_HostType(This,newVal)

#define ISQLDistribution_get_AltSnapshotFolder(This,pVal)	\
    (This)->lpVtbl -> get_AltSnapshotFolder(This,pVal)

#define ISQLDistribution_put_AltSnapshotFolder(This,newVal)	\
    (This)->lpVtbl -> put_AltSnapshotFolder(This,newVal)

#define ISQLDistribution_get_WorkingDirectory(This,pVal)	\
    (This)->lpVtbl -> get_WorkingDirectory(This,pVal)

#define ISQLDistribution_put_WorkingDirectory(This,newVal)	\
    (This)->lpVtbl -> put_WorkingDirectory(This,newVal)

#define ISQLDistribution_get_FileTransferType(This,pVal)	\
    (This)->lpVtbl -> get_FileTransferType(This,pVal)

#define ISQLDistribution_put_FileTransferType(This,newVal)	\
    (This)->lpVtbl -> put_FileTransferType(This,newVal)

#define ISQLDistribution_get_DTSPackageFileName(This,pVal)	\
    (This)->lpVtbl -> get_DTSPackageFileName(This,pVal)

#define ISQLDistribution_put_DTSPackageFileName(This,newVal)	\
    (This)->lpVtbl -> put_DTSPackageFileName(This,newVal)

#define ISQLDistribution_get_DTSPackagePassword(This,pVal)	\
    (This)->lpVtbl -> get_DTSPackagePassword(This,pVal)

#define ISQLDistribution_put_DTSPackagePassword(This,newVal)	\
    (This)->lpVtbl -> put_DTSPackagePassword(This,newVal)

#define ISQLDistribution_CopySubscription(This,bstrSubscriptionFileName,FileCreateOption)	\
    (This)->lpVtbl -> CopySubscription(This,bstrSubscriptionFileName,FileCreateOption)

#define ISQLDistribution_SetFailoverMode(This,failoverMode)	\
    (This)->lpVtbl -> SetFailoverMode(This,failoverMode)

#define ISQLDistribution_get_SynchronizationType(This,pVal)	\
    (This)->lpVtbl -> get_SynchronizationType(This,pVal)

#define ISQLDistribution_put_SynchronizationType(This,newVal)	\
    (This)->lpVtbl -> put_SynchronizationType(This,newVal)

#define ISQLDistribution_get_SkipErrors(This,pVal)	\
    (This)->lpVtbl -> get_SkipErrors(This,pVal)

#define ISQLDistribution_put_SkipErrors(This,newVal)	\
    (This)->lpVtbl -> put_SkipErrors(This,newVal)

#define ISQLDistribution_get_SubscriptionUpdateMode(This,pVal)	\
    (This)->lpVtbl -> get_SubscriptionUpdateMode(This,pVal)

#define ISQLDistribution_put_SubscriptionUpdateMode(This,newVal)	\
    (This)->lpVtbl -> put_SubscriptionUpdateMode(This,newVal)

#define ISQLDistribution_get_PublisherRPCLogin(This,pVal)	\
    (This)->lpVtbl -> get_PublisherRPCLogin(This,pVal)

#define ISQLDistribution_put_PublisherRPCLogin(This,newVal)	\
    (This)->lpVtbl -> put_PublisherRPCLogin(This,newVal)

#define ISQLDistribution_get_PublisherRPCPassword(This,pVal)	\
    (This)->lpVtbl -> get_PublisherRPCPassword(This,pVal)

#define ISQLDistribution_put_PublisherRPCPassword(This,newVal)	\
    (This)->lpVtbl -> put_PublisherRPCPassword(This,newVal)

#define ISQLDistribution_get_HostName(This,pVal)	\
    (This)->lpVtbl -> get_HostName(This,pVal)

#define ISQLDistribution_put_HostName(This,newVal)	\
    (This)->lpVtbl -> put_HostName(This,newVal)

#define ISQLDistribution_get_LastUpdatedTime(This,pVal)	\
    (This)->lpVtbl -> get_LastUpdatedTime(This,pVal)

#define ISQLDistribution_get_PublisherRPCSecurityMode(This,pVal)	\
    (This)->lpVtbl -> get_PublisherRPCSecurityMode(This,pVal)

#define ISQLDistribution_put_PublisherRPCSecurityMode(This,newVal)	\
    (This)->lpVtbl -> put_PublisherRPCSecurityMode(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_Distributor_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_Distributor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_Distributor_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_Distributor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_DistributorLogin_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_DistributorLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_DistributorLogin_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_DistributorLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_DistributorPassword_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_DistributorPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_DistributorPassword_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_DistributorPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_DistributorSecurityMode_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ REPL_SECURITY_TYPE __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_DistributorSecurityMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_DistributorSecurityMode_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ REPL_SECURITY_TYPE newVal);


void __RPC_STUB ISQLDistribution_put_DistributorSecurityMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_LoginTimeout_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_LoginTimeout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_LoginTimeout_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB ISQLDistribution_put_LoginTimeout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_MaxDeliveredTransactions_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_MaxDeliveredTransactions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_MaxDeliveredTransactions_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB ISQLDistribution_put_MaxDeliveredTransactions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_Publication_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_Publication_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_Publication_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_Publication_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_Publisher_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_Publisher_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_Publisher_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_Publisher_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_PublisherDatabase_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_PublisherDatabase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_PublisherDatabase_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_PublisherDatabase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_PublisherLogin_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_PublisherLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_PublisherLogin_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_PublisherLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_PublisherPassword_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_PublisherPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_PublisherPassword_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_PublisherPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_PublisherSecurityMode_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ REPL_SECURITY_TYPE __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_PublisherSecurityMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_PublisherSecurityMode_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ REPL_SECURITY_TYPE newVal);


void __RPC_STUB ISQLDistribution_put_PublisherSecurityMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_QueryTimeout_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_QueryTimeout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_QueryTimeout_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB ISQLDistribution_put_QueryTimeout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_Subscriber_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_Subscriber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_Subscriber_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_Subscriber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_SubscriberDatabase_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_SubscriberDatabase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_SubscriberDatabase_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_SubscriberDatabase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_SubscriberDatabasePath_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_SubscriberDatabasePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_SubscriberDatabasePath_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_SubscriberDatabasePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_SubscriberLogin_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_SubscriberLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_SubscriberLogin_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_SubscriberLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_SubscriberPassword_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_SubscriberPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_SubscriberPassword_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_SubscriberPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_SubscriberSecurityMode_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ REPL_SECURITY_TYPE __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_SubscriberSecurityMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_SubscriberSecurityMode_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ REPL_SECURITY_TYPE newVal);


void __RPC_STUB ISQLDistribution_put_SubscriberSecurityMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_SubscriberDatasourceType_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ REPL_DATASOURCE_TYPE __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_SubscriberDatasourceType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_SubscriberDatasourceType_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ REPL_DATASOURCE_TYPE newVal);


void __RPC_STUB ISQLDistribution_put_SubscriberDatasourceType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_SubscriptionType_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ REPL_SUBSCRIPTION_TYPE __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_SubscriptionType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_SubscriptionType_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ REPL_SUBSCRIPTION_TYPE newVal);


void __RPC_STUB ISQLDistribution_put_SubscriptionType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_UndeliveredCommands_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_UndeliveredCommands_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_UndeliveredTransactions_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_UndeliveredTransactions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_DistributorAddress_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_DistributorAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_DistributorAddress_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_DistributorAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_DistributorNetwork_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ REPL_NETWORK_TYPE __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_DistributorNetwork_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_DistributorNetwork_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ REPL_NETWORK_TYPE newVal);


void __RPC_STUB ISQLDistribution_put_DistributorNetwork_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_PublisherAddress_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_PublisherAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_PublisherAddress_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_PublisherAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_PublisherNetwork_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ REPL_NETWORK_TYPE __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_PublisherNetwork_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_PublisherNetwork_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ REPL_NETWORK_TYPE newVal);


void __RPC_STUB ISQLDistribution_put_PublisherNetwork_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_FTPAddress_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_FTPAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_FTPAddress_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_FTPAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_FTPLogin_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_FTPLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_FTPLogin_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_FTPLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_FTPPassword_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_FTPPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_FTPPassword_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_FTPPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_FTPPort_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_FTPPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_FTPPort_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB ISQLDistribution_put_FTPPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_Initialize_Proxy( 
    ISQLDistribution __RPC_FAR * This);


void __RPC_STUB ISQLDistribution_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_AddSubscription_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ REPL_DBADDOPTION DBAddOption,
    /* [in] */ REPL_SUBSCRIPTION_HOST SubscriptionHost);


void __RPC_STUB ISQLDistribution_AddSubscription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_DropSubscription_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ REPL_DBDROPOPTION DBDropOption);


void __RPC_STUB ISQLDistribution_DropSubscription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_Run_Proxy( 
    ISQLDistribution __RPC_FAR * This);


void __RPC_STUB ISQLDistribution_Run_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_Terminate_Proxy( 
    ISQLDistribution __RPC_FAR * This);


void __RPC_STUB ISQLDistribution_Terminate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_ReinitializeSubscription_Proxy( 
    ISQLDistribution __RPC_FAR * This);


void __RPC_STUB ISQLDistribution_ReinitializeSubscription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][restricted][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_DistributorEncryptedPassword_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_DistributorEncryptedPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][restricted][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_PublisherEncryptedPassword_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_PublisherEncryptedPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][restricted][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_SubscriberEncryptedPassword_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_SubscriberEncryptedPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_ProfileName_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_ProfileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_ProfileName_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_ProfileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_ErrorRecords_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ ISQLReplErrors __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_ErrorRecords_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_SubscriptionName_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_SubscriptionName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_SubscriptionName_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_SubscriptionName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][restricted][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_HostType_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ REPL_SUBSCRIPTION_HOST newVal);


void __RPC_STUB ISQLDistribution_put_HostType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_AltSnapshotFolder_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_AltSnapshotFolder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_AltSnapshotFolder_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_AltSnapshotFolder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_WorkingDirectory_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_WorkingDirectory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_WorkingDirectory_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_WorkingDirectory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_FileTransferType_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ REPL_FILE_TRANSFER_TYPE __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_FileTransferType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_FileTransferType_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ REPL_FILE_TRANSFER_TYPE newVal);


void __RPC_STUB ISQLDistribution_put_FileTransferType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_DTSPackageFileName_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_DTSPackageFileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_DTSPackageFileName_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_DTSPackageFileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_DTSPackagePassword_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_DTSPackagePassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_DTSPackagePassword_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_DTSPackagePassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_CopySubscription_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR bstrSubscriptionFileName,
    /* [defaultvalue][in] */ REPL_FILECREATE_OPTION FileCreateOption);


void __RPC_STUB ISQLDistribution_CopySubscription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_SetFailoverMode_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ REPL_FAILOVER_MODE_TYPE failoverMode);


void __RPC_STUB ISQLDistribution_SetFailoverMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_SynchronizationType_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ REPL_SYNCHRONIZATION_TYPE __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_SynchronizationType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_SynchronizationType_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ REPL_SYNCHRONIZATION_TYPE newVal);


void __RPC_STUB ISQLDistribution_put_SynchronizationType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_SkipErrors_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_SkipErrors_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_SkipErrors_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_SkipErrors_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_SubscriptionUpdateMode_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ REPL_SUBSCRIPTION_UPDATE_MODE __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_SubscriptionUpdateMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_SubscriptionUpdateMode_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ REPL_SUBSCRIPTION_UPDATE_MODE newVal);


void __RPC_STUB ISQLDistribution_put_SubscriptionUpdateMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_PublisherRPCLogin_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_PublisherRPCLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_PublisherRPCLogin_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_PublisherRPCLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_PublisherRPCPassword_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_PublisherRPCPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_PublisherRPCPassword_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_PublisherRPCPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_HostName_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_HostName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_HostName_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ISQLDistribution_put_HostName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_LastUpdatedTime_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_LastUpdatedTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_get_PublisherRPCSecurityMode_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [retval][out] */ REPLRPC_SECURITY_TYPE __RPC_FAR *pVal);


void __RPC_STUB ISQLDistribution_get_PublisherRPCSecurityMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISQLDistribution_put_PublisherRPCSecurityMode_Proxy( 
    ISQLDistribution __RPC_FAR * This,
    /* [in] */ REPLRPC_SECURITY_TYPE newVal);


void __RPC_STUB ISQLDistribution_put_PublisherRPCSecurityMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISQLDistribution_INTERFACE_DEFINED__ */



#ifndef __SQLDISTXLib_LIBRARY_DEFINED__
#define __SQLDISTXLib_LIBRARY_DEFINED__

/* library SQLDISTXLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_SQLDISTXLib;

#ifndef ___SQLDistributionEvents_DISPINTERFACE_DEFINED__
#define ___SQLDistributionEvents_DISPINTERFACE_DEFINED__

/* dispinterface _SQLDistributionEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__SQLDistributionEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("05E219F6-BB55-11D0-94E7-00C04FC2DB9C")
    _SQLDistributionEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _SQLDistributionEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _SQLDistributionEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _SQLDistributionEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _SQLDistributionEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _SQLDistributionEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _SQLDistributionEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _SQLDistributionEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _SQLDistributionEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _SQLDistributionEventsVtbl;

    interface _SQLDistributionEvents
    {
        CONST_VTBL struct _SQLDistributionEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _SQLDistributionEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _SQLDistributionEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _SQLDistributionEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _SQLDistributionEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _SQLDistributionEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _SQLDistributionEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _SQLDistributionEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___SQLDistributionEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SQLDistribution;

#ifdef __cplusplus

class DECLSPEC_UUID("08b0b2e6-3fb3-11d3-a4de-00c04f610189")
SQLDistribution;
#endif
#endif /* __SQLDISTXLib_LIBRARY_DEFINED__ */

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
