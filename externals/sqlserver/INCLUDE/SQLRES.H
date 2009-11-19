/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Aug 06 00:51:56 2000
 */
/* Compiler settings for q:\SPHINX\SQLREPL\RECONCLR\INC\sqlres.idl:
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

#ifndef __sqlres_h__
#define __sqlres_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IConnectionInfo_FWD_DEFINED__
#define __IConnectionInfo_FWD_DEFINED__
typedef interface IConnectionInfo IConnectionInfo;
#endif 	/* __IConnectionInfo_FWD_DEFINED__ */


#ifndef __IReplRowChange_FWD_DEFINED__
#define __IReplRowChange_FWD_DEFINED__
typedef interface IReplRowChange IReplRowChange;
#endif 	/* __IReplRowChange_FWD_DEFINED__ */


#ifndef __ICustomResolver_FWD_DEFINED__
#define __ICustomResolver_FWD_DEFINED__
typedef interface ICustomResolver ICustomResolver;
#endif 	/* __ICustomResolver_FWD_DEFINED__ */


#ifndef __IVBCustomResolver_FWD_DEFINED__
#define __IVBCustomResolver_FWD_DEFINED__

#ifdef __cplusplus
typedef class IVBCustomResolver IVBCustomResolver;
#else
typedef struct IVBCustomResolver IVBCustomResolver;
#endif /* __cplusplus */

#endif 	/* __IVBCustomResolver_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_sqlres_0000 */
/* [local] */ 

typedef /* [public][v1_enum] */ 
enum __MIDL___MIDL_itf_sqlres_0000_0001
    {	REPOLEType_SQL_UNKNOWN_TYPE	= 0,
	REPOLEType_SQL_CHAR	= 1,
	REPOLEType_SQL_NUMERIC	= 2,
	REPOLEType_SQL_DECIMAL	= 3,
	REPOLEType_SQL_INTEGER	= 4,
	REPOLEType_SQL_SMALLINT	= 5,
	REPOLEType_SQL_FLOAT	= 6,
	REPOLEType_SQL_REAL	= 7,
	REPOLEType_SQL_DOUBLE	= 8,
	REPOLEType_SQL_DATETIME	= 9,
	REPOLEType_SQL_VARCHAR	= 12,
	REPOLEType_SQL_DATE	= 9,
	REPOLEType_SQL_INTERVAL	= 10,
	REPOLEType_SQL_TIME	= 10,
	REPOLEType_SQL_TIMESTAMP	= 11,
	REPOLEType_SQL_LONGVARCHAR	= -1,
	REPOLEType_SQL_BINARY	= -2,
	REPOLEType_SQL_VARBINARY	= -3,
	REPOLEType_SQL_LONGVARBINARY	= -4,
	REPOLEType_SQL_BIGINT	= -5,
	REPOLEType_SQL_TINYINT	= -6,
	REPOLEType_SQL_BIT	= -7,
	REPOLEType_SQL_GUID	= -11
    }	REPOLE_SQL_DATATYPE;

typedef /* [public][public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_sqlres_0000_0002
    {	REPOLEDataSource_Native	= 0,
	REPOLEDataSource_ODBC	= 0x1,
	REPOLEDataSource_Jet	= 0x2,
	REPOLEDataSource_OLEDB	= 0x3,
	REPOLEDataSource_Exchange	= 0x4,
	REPOLEDataSource_Oracle	= 0x5,
	REPOLEDataSource_DB2Universal	= 0x6,
	REPOLEDataSource_SSCE	= 0x7,
	REPOLEDataSource_XML	= 0x8
    }	REPOLE_DATASOURCE_TYPE;

typedef /* [public][public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_sqlres_0000_0003
    {	REPOLESecurity_Min	= 0,
	REPOLESecurity_Normal	= 0,
	REPOLESecurity_Integrated	= 1,
	REPOLESecurity_Mixed	= 2,
	REPOLESecurity_Max	= 2,
	REPOLESecurity_Invalid	= -1
    }	REPOLE_SECURITY_TYPE;

typedef /* [public] */ 
enum __MIDL___MIDL_itf_sqlres_0000_0004
    {	METADATA_TYPE_Missing	= 0,
	METADATA_TYPE_Tombstone	= 0x1,
	METADATA_TYPE_Contents	= 0x2,
	METADATA_TYPE_ContentsDeferred	= 0x3,
	METADATA_TYPE_Reserved	= 0x4,
	METADATA_TYPE_PartialDelete	= 0x5,
	METADATA_TYPE_SystemDelete	= 0x6
    }	METADATA_TYPE;

typedef /* [public][public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_sqlres_0000_0005
    {	REPOLEChange_SubscriberInsert	= 0x1,
	REPOLEChange_PublisherInsert	= 0x10000,
	REPOLEChange_SubscriberDelete_NoConflict	= 0x2,
	REPOLEChange_PublisherDelete_NoConflict	= 0x20000,
	REPOLEChange_SubscriberSystemDelete	= 0x4,
	REPOLEChange_PublisherSystemDelete	= 0x40000,
	REPOLEChange_SubscriberDelete_Conflict	= 0x8,
	REPOLEChange_PublisherDelete_Conflict	= 0x80000,
	REPOLEChange_SubscriberRemoveFromPartial	= 0x10,
	REPOLEChange_PublisherRemoveFromPartial	= 0x100000,
	REPOLEChange_SubscriberUpdate_NoConflict	= 0x20,
	REPOLEChange_PublisherUpdate_NoConflict	= 0x200000,
	REPOLEChange_SubscriberUpdate_ConflictWithDelete	= 0x40,
	REPOLEChange_PublisherUpdate_ConflictWithDelete	= 0x400000,
	REPOLEChange_SubscriberUpdate_ConflictColTrack	= 0x80,
	REPOLEChange_PublisherUpdate_ConflictColTrack	= 0x800000,
	REPOLEChange_SubscriberUpdate_ConflictNoColTrack	= 0x100,
	REPOLEChange_PublisherUpdate_ConflictNoColTrack	= 0x1000000,
	REPOLEChange_UploadInsertFailed	= 0x200,
	REPOLEChange_DownloadInsertFailed	= 0x2000000,
	REPOLEChange_UploadDeleteFailed	= 0x400,
	REPOLEChange_DownloadDeleteFailed	= 0x4000000,
	REPOLEChange_UploadUpdateFailed	= 0x800,
	REPOLEChange_DownloadUpdateFailed	= 0x8000000,
	REPOLEUpdateConflicts	= REPOLEChange_SubscriberUpdate_ConflictColTrack | REPOLEChange_PublisherUpdate_ConflictColTrack | REPOLEChange_SubscriberUpdate_ConflictNoColTrack | REPOLEChange_PublisherUpdate_ConflictNoColTrack,
	REPOLEAllConflicts	= REPOLEChange_SubscriberDelete_Conflict | REPOLEChange_PublisherDelete_Conflict | REPOLEChange_SubscriberUpdate_ConflictWithDelete | REPOLEChange_PublisherUpdate_ConflictWithDelete | REPOLEUpdateConflicts,
	REPOLEAllErrors	= REPOLEChange_UploadInsertFailed | REPOLEChange_DownloadInsertFailed | REPOLEChange_UploadDeleteFailed | REPOLEChange_DownloadDeleteFailed | REPOLEChange_UploadUpdateFailed | REPOLEChange_DownloadUpdateFailed,
	REPOLEAllNonConflicts	= REPOLEChange_SubscriberInsert | REPOLEChange_PublisherInsert | REPOLEChange_SubscriberDelete_NoConflict | REPOLEChange_PublisherDelete_NoConflict | REPOLEChange_SubscriberSystemDelete | REPOLEChange_PublisherSystemDelete | REPOLEChange_SubscriberRemoveFromPartial | REPOLEChange_SubscriberUpdate_NoConflict | REPOLEChange_PublisherUpdate_NoConflict,
	REPOLEAllChanges	= REPOLEAllConflicts | REPOLEAllErrors | REPOLEAllNonConflicts
    }	REPOLE_CHANGE_TYPE;

typedef /* [public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_sqlres_0000_0006
    {	REPOLEConflict_Min	= 1,
	REPOLEConflict_UpdateConflict	= 1,
	REPOLEConflict_ColumnUpdateConflict	= 2,
	REPOLEConflict_UpdateDeleteWinsConflict	= 3,
	REPOLEConflict_UpdateWinsDeleteConflict	= 4,
	REPOLEConflict_UploadInsertFailed	= 5,
	REPOLEConflict_DownloadInsertFailed	= 6,
	REPOLEConflict_UploadDeleteFailed	= 7,
	REPOLEConflict_DownloadDeleteFailed	= 8,
	REPOLEConflict_UploadUpdateFailed	= 9,
	REPOLEConflict_DownloadUpdateFailed	= 10,
	REPOLEConflict_ResolutionDone	= 11,
	REPOLEConflict_Max	= 11
    }	REPOLE_CONFLICT_TYPE;

typedef /* [public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_sqlres_0000_0007
    {	REPOLEColumn_NotUpdated	= 0x1,
	REPOLEColumn_UpdatedNoConflict	= 0x2,
	REPOLEColumn_UpdatedWithConflict	= 0x3,
	REPOLEColumn_DifferNoTrack	= 0x4
    }	REPOLE_COLSTATUS_TYPE;

typedef /* [public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_sqlres_0000_0008
    {	REPOLEPriority_Source	= 0x1,
	REPOLEPriority_Destination	= 0x2,
	REPOLEPriority_Equal	= 0x3
    }	REPOLE_PRIORITY_TYPE;

typedef /* [public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_sqlres_0000_0009
    {	REPOLEColumnAttribute_Updatable	= 0x1,
	REPOLEColumnAttribute_Identity	= 0x2
    }	REPOLE_COLUMN_ATTRIBUTES;

typedef /* [public][public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_sqlres_0000_0010
    {	REPOLEExtErrorNoneOrNotSpecified	= 0,
	REPOLEExtErrorDupKey	= 0x1,
	REPOLEExtErrorDupUniqueIndex	= 0x2
    }	REPOLE_EXTENDEDERROR_TYPE;

typedef /* [public][v1_enum] */ 
enum __MIDL___MIDL_itf_sqlres_0000_0011
    {	REPOLEBool_FALSE	= 0,
	REPOLEBool_TRUE	= 1
    }	REPOLE_BOOL;

typedef struct  REPLGUID
    {
    long Data1;
    short Data2;
    short Data3;
    unsigned char Data4[ 8 ];
    }	REPLGUID;



extern RPC_IF_HANDLE __MIDL_itf_sqlres_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_sqlres_0000_v0_0_s_ifspec;

#ifndef __IConnectionInfo_INTERFACE_DEFINED__
#define __IConnectionInfo_INTERFACE_DEFINED__

/* interface IConnectionInfo */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IConnectionInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("37E95A52-1CA3-11d0-A11B-00AA003E4672")
    IConnectionInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetConnectName( 
            /* [size_is][string][out] */ LPWSTR ConnectName,
            DWORD cbConnectName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetServerName( 
            /* [size_is][string][out] */ LPWSTR ServerName,
            DWORD cbServerName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHostName( 
            /* [size_is][string][out] */ LPWSTR HostName,
            DWORD cbHostName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetServerRole( 
            /* [size_is][string][out] */ LPWSTR ServerRole,
            DWORD cbServerRole) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInternetAddress( 
            /* [size_is][string][out] */ LPWSTR InternetAddress,
            DWORD cbInternetAddress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInternetNetwork( 
            /* [size_is][string][out] */ LPWSTR InternetNetwork,
            DWORD cbInternetNetwork) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDatabase( 
            /* [size_is][string][out] */ LPWSTR Database,
            DWORD cbDatabase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDatabaseStatus( 
            /* [out] */ long __RPC_FAR *plDatabaseStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDatasourcePath( 
            /* [size_is][string][out] */ LPWSTR DatasourcePath,
            DWORD cbDatasourcePath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDataSourceType( 
            /* [out] */ REPOLE_DATASOURCE_TYPE __RPC_FAR *pRetValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSecurityMode( 
            /* [out] */ REPOLE_SECURITY_TYPE __RPC_FAR *pRetValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLogin( 
            /* [size_is][string][out] */ LPWSTR Login,
            DWORD cbLogin) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPassword( 
            /* [size_is][string][out] */ LPWSTR Password,
            DWORD cbPassword) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetODBCEnvironmentHandle( 
            /* [out] */ long __RPC_FAR *phenv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLoginTimeout( 
            /* [out] */ long __RPC_FAR *plLoginTimeout) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetQueryTimeout( 
            /* [out] */ long __RPC_FAR *plQueryTimeout) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPacketSize( 
            /* [out] */ unsigned long __RPC_FAR *pusPacketSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetApplicationName( 
            /* [size_is][string][out] */ LPWSTR ApplicationName,
            DWORD cbApplicationName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProviderName( 
            /* [size_is][string][out] */ LPWSTR ProviderName,
            DWORD cbProviderName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDatasource( 
            /* [size_is][string][out] */ LPWSTR Datasource,
            DWORD cbDatasource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLocation( 
            /* [size_is][string][out] */ LPWSTR Location,
            DWORD cbLocation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProviderString( 
            /* [size_is][string][out] */ LPWSTR ProviderString,
            DWORD cbProviderString) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCatalog( 
            /* [size_is][string][out] */ LPWSTR Catalog,
            DWORD cbCatalog) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDBCreatedThisSession( 
            /* [out] */ BOOL __RPC_FAR *pbDBCreatedThisSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetConnectName( 
            /* [in] */ LPCWSTR ConnectName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetServerName( 
            /* [in] */ LPCWSTR ServerName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHostName( 
            /* [in] */ LPCWSTR HostName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetServerRole( 
            /* [in] */ LPCWSTR ServerRole) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetInternetAddress( 
            /* [in] */ LPCWSTR InternetAddress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetInternetNetwork( 
            /* [in] */ LPCWSTR InternetNetwork) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDatabase( 
            /* [in] */ LPCWSTR Database) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDatabaseStatus( 
            /* [in] */ LONG lDatabaseStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDatasourcePath( 
            /* [in] */ LPCWSTR DatasourcePath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDataSourceType( 
            /* [in] */ REPOLE_DATASOURCE_TYPE DataSourceType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSecurityMode( 
            /* [in] */ REPOLE_SECURITY_TYPE SecurityMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLogin( 
            /* [in] */ LPCWSTR Login) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPassword( 
            /* [in] */ LPCWSTR Password) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetODBCEnvironmentHandle( 
            /* [in] */ long henv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLoginTimeout( 
            /* [in] */ LONG lLoginTimeout) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetQueryTimeout( 
            /* [in] */ LONG lQueryTimeout) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPacketSize( 
            /* [in] */ unsigned long usPacketSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetApplicationName( 
            /* [in] */ LPCWSTR ApplicationName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProviderName( 
            /* [in] */ LPCWSTR ProviderName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDatasource( 
            /* [in] */ LPCWSTR Datasource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLocation( 
            /* [in] */ LPCWSTR Location) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProviderString( 
            /* [in] */ LPCWSTR ProviderString) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCatalog( 
            /* [in] */ LPCWSTR Catalog) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDBCreatedThisSession( 
            /* [in] */ BOOL bDBCreatedThisSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBcpBatchSize( 
            /* [in] */ LONG lBcpBatchSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBcpBatchSize( 
            /* [out] */ LONG __RPC_FAR *plBcpBatchSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWaitServerResponse( 
            /* [out] */ BOOL __RPC_FAR *pbWaitingForResponse,
            /* [out] */ DWORD __RPC_FAR *pdwWaitingSinceTickCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetWaitServerResponse( 
            /* [in] */ BOOL bWaitingForResponse,
            /* [in] */ DWORD dwWaitingSinceTickCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUseInprocLoader( 
            /* [out] */ BOOL __RPC_FAR *pbUseInprocLoader) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUseInprocLoader( 
            /* [in] */ BOOL bUseInprocLoader) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCodePage( 
            /* [in] */ LONG lCodePage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCodePage( 
            /* [out] */ LONG __RPC_FAR *plCodePage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLCID( 
            /* [in] */ LONG lLCID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLCID( 
            /* [out] */ LONG __RPC_FAR *plLCID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetComparisonStyle( 
            /* [in] */ LONG lComparisonStyle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetComparisonStyle( 
            /* [out] */ LONG __RPC_FAR *plComparisonStyle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNumDeadlockRetries( 
            /* [in] */ LONG lNumDeadlockRetries) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNumDeadlockRetries( 
            /* [out] */ LONG __RPC_FAR *plNumDeadlockRetries) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMajorVersion( 
            LONG lMajorVersion) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMajorVersion( 
            LONG __RPC_FAR *plMajorVersion) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMinorVersion( 
            LONG lMinorVersion) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMinorVersion( 
            LONG __RPC_FAR *plMinorVersion) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IConnectionInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IConnectionInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IConnectionInfo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetConnectName )( 
            IConnectionInfo __RPC_FAR * This,
            /* [size_is][string][out] */ LPWSTR ConnectName,
            DWORD cbConnectName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetServerName )( 
            IConnectionInfo __RPC_FAR * This,
            /* [size_is][string][out] */ LPWSTR ServerName,
            DWORD cbServerName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHostName )( 
            IConnectionInfo __RPC_FAR * This,
            /* [size_is][string][out] */ LPWSTR HostName,
            DWORD cbHostName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetServerRole )( 
            IConnectionInfo __RPC_FAR * This,
            /* [size_is][string][out] */ LPWSTR ServerRole,
            DWORD cbServerRole);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInternetAddress )( 
            IConnectionInfo __RPC_FAR * This,
            /* [size_is][string][out] */ LPWSTR InternetAddress,
            DWORD cbInternetAddress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInternetNetwork )( 
            IConnectionInfo __RPC_FAR * This,
            /* [size_is][string][out] */ LPWSTR InternetNetwork,
            DWORD cbInternetNetwork);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDatabase )( 
            IConnectionInfo __RPC_FAR * This,
            /* [size_is][string][out] */ LPWSTR Database,
            DWORD cbDatabase);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDatabaseStatus )( 
            IConnectionInfo __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plDatabaseStatus);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDatasourcePath )( 
            IConnectionInfo __RPC_FAR * This,
            /* [size_is][string][out] */ LPWSTR DatasourcePath,
            DWORD cbDatasourcePath);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDataSourceType )( 
            IConnectionInfo __RPC_FAR * This,
            /* [out] */ REPOLE_DATASOURCE_TYPE __RPC_FAR *pRetValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSecurityMode )( 
            IConnectionInfo __RPC_FAR * This,
            /* [out] */ REPOLE_SECURITY_TYPE __RPC_FAR *pRetValue);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLogin )( 
            IConnectionInfo __RPC_FAR * This,
            /* [size_is][string][out] */ LPWSTR Login,
            DWORD cbLogin);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPassword )( 
            IConnectionInfo __RPC_FAR * This,
            /* [size_is][string][out] */ LPWSTR Password,
            DWORD cbPassword);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetODBCEnvironmentHandle )( 
            IConnectionInfo __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *phenv);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLoginTimeout )( 
            IConnectionInfo __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plLoginTimeout);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetQueryTimeout )( 
            IConnectionInfo __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *plQueryTimeout);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPacketSize )( 
            IConnectionInfo __RPC_FAR * This,
            /* [out] */ unsigned long __RPC_FAR *pusPacketSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetApplicationName )( 
            IConnectionInfo __RPC_FAR * This,
            /* [size_is][string][out] */ LPWSTR ApplicationName,
            DWORD cbApplicationName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetProviderName )( 
            IConnectionInfo __RPC_FAR * This,
            /* [size_is][string][out] */ LPWSTR ProviderName,
            DWORD cbProviderName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDatasource )( 
            IConnectionInfo __RPC_FAR * This,
            /* [size_is][string][out] */ LPWSTR Datasource,
            DWORD cbDatasource);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLocation )( 
            IConnectionInfo __RPC_FAR * This,
            /* [size_is][string][out] */ LPWSTR Location,
            DWORD cbLocation);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetProviderString )( 
            IConnectionInfo __RPC_FAR * This,
            /* [size_is][string][out] */ LPWSTR ProviderString,
            DWORD cbProviderString);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCatalog )( 
            IConnectionInfo __RPC_FAR * This,
            /* [size_is][string][out] */ LPWSTR Catalog,
            DWORD cbCatalog);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDBCreatedThisSession )( 
            IConnectionInfo __RPC_FAR * This,
            /* [out] */ BOOL __RPC_FAR *pbDBCreatedThisSession);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetConnectName )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ LPCWSTR ConnectName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetServerName )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ LPCWSTR ServerName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetHostName )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ LPCWSTR HostName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetServerRole )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ LPCWSTR ServerRole);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetInternetAddress )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ LPCWSTR InternetAddress);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetInternetNetwork )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ LPCWSTR InternetNetwork);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDatabase )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ LPCWSTR Database);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDatabaseStatus )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ LONG lDatabaseStatus);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDatasourcePath )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ LPCWSTR DatasourcePath);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDataSourceType )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ REPOLE_DATASOURCE_TYPE DataSourceType);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSecurityMode )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ REPOLE_SECURITY_TYPE SecurityMode);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLogin )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ LPCWSTR Login);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPassword )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ LPCWSTR Password);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetODBCEnvironmentHandle )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ long henv);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLoginTimeout )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ LONG lLoginTimeout);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetQueryTimeout )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ LONG lQueryTimeout);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPacketSize )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ unsigned long usPacketSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetApplicationName )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ LPCWSTR ApplicationName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetProviderName )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ LPCWSTR ProviderName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDatasource )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ LPCWSTR Datasource);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLocation )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ LPCWSTR Location);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetProviderString )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ LPCWSTR ProviderString);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCatalog )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ LPCWSTR Catalog);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDBCreatedThisSession )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ BOOL bDBCreatedThisSession);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBcpBatchSize )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ LONG lBcpBatchSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBcpBatchSize )( 
            IConnectionInfo __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plBcpBatchSize);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetWaitServerResponse )( 
            IConnectionInfo __RPC_FAR * This,
            /* [out] */ BOOL __RPC_FAR *pbWaitingForResponse,
            /* [out] */ DWORD __RPC_FAR *pdwWaitingSinceTickCount);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetWaitServerResponse )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ BOOL bWaitingForResponse,
            /* [in] */ DWORD dwWaitingSinceTickCount);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetUseInprocLoader )( 
            IConnectionInfo __RPC_FAR * This,
            /* [out] */ BOOL __RPC_FAR *pbUseInprocLoader);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetUseInprocLoader )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ BOOL bUseInprocLoader);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCodePage )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ LONG lCodePage);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCodePage )( 
            IConnectionInfo __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plCodePage);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLCID )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ LONG lLCID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLCID )( 
            IConnectionInfo __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plLCID);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetComparisonStyle )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ LONG lComparisonStyle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetComparisonStyle )( 
            IConnectionInfo __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plComparisonStyle);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetNumDeadlockRetries )( 
            IConnectionInfo __RPC_FAR * This,
            /* [in] */ LONG lNumDeadlockRetries);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumDeadlockRetries )( 
            IConnectionInfo __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plNumDeadlockRetries);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMajorVersion )( 
            IConnectionInfo __RPC_FAR * This,
            LONG lMajorVersion);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMajorVersion )( 
            IConnectionInfo __RPC_FAR * This,
            LONG __RPC_FAR *plMajorVersion);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMinorVersion )( 
            IConnectionInfo __RPC_FAR * This,
            LONG lMinorVersion);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMinorVersion )( 
            IConnectionInfo __RPC_FAR * This,
            LONG __RPC_FAR *plMinorVersion);
        
        END_INTERFACE
    } IConnectionInfoVtbl;

    interface IConnectionInfo
    {
        CONST_VTBL struct IConnectionInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IConnectionInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IConnectionInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IConnectionInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IConnectionInfo_GetConnectName(This,ConnectName,cbConnectName)	\
    (This)->lpVtbl -> GetConnectName(This,ConnectName,cbConnectName)

#define IConnectionInfo_GetServerName(This,ServerName,cbServerName)	\
    (This)->lpVtbl -> GetServerName(This,ServerName,cbServerName)

#define IConnectionInfo_GetHostName(This,HostName,cbHostName)	\
    (This)->lpVtbl -> GetHostName(This,HostName,cbHostName)

#define IConnectionInfo_GetServerRole(This,ServerRole,cbServerRole)	\
    (This)->lpVtbl -> GetServerRole(This,ServerRole,cbServerRole)

#define IConnectionInfo_GetInternetAddress(This,InternetAddress,cbInternetAddress)	\
    (This)->lpVtbl -> GetInternetAddress(This,InternetAddress,cbInternetAddress)

#define IConnectionInfo_GetInternetNetwork(This,InternetNetwork,cbInternetNetwork)	\
    (This)->lpVtbl -> GetInternetNetwork(This,InternetNetwork,cbInternetNetwork)

#define IConnectionInfo_GetDatabase(This,Database,cbDatabase)	\
    (This)->lpVtbl -> GetDatabase(This,Database,cbDatabase)

#define IConnectionInfo_GetDatabaseStatus(This,plDatabaseStatus)	\
    (This)->lpVtbl -> GetDatabaseStatus(This,plDatabaseStatus)

#define IConnectionInfo_GetDatasourcePath(This,DatasourcePath,cbDatasourcePath)	\
    (This)->lpVtbl -> GetDatasourcePath(This,DatasourcePath,cbDatasourcePath)

#define IConnectionInfo_GetDataSourceType(This,pRetValue)	\
    (This)->lpVtbl -> GetDataSourceType(This,pRetValue)

#define IConnectionInfo_GetSecurityMode(This,pRetValue)	\
    (This)->lpVtbl -> GetSecurityMode(This,pRetValue)

#define IConnectionInfo_GetLogin(This,Login,cbLogin)	\
    (This)->lpVtbl -> GetLogin(This,Login,cbLogin)

#define IConnectionInfo_GetPassword(This,Password,cbPassword)	\
    (This)->lpVtbl -> GetPassword(This,Password,cbPassword)

#define IConnectionInfo_GetODBCEnvironmentHandle(This,phenv)	\
    (This)->lpVtbl -> GetODBCEnvironmentHandle(This,phenv)

#define IConnectionInfo_GetLoginTimeout(This,plLoginTimeout)	\
    (This)->lpVtbl -> GetLoginTimeout(This,plLoginTimeout)

#define IConnectionInfo_GetQueryTimeout(This,plQueryTimeout)	\
    (This)->lpVtbl -> GetQueryTimeout(This,plQueryTimeout)

#define IConnectionInfo_GetPacketSize(This,pusPacketSize)	\
    (This)->lpVtbl -> GetPacketSize(This,pusPacketSize)

#define IConnectionInfo_GetApplicationName(This,ApplicationName,cbApplicationName)	\
    (This)->lpVtbl -> GetApplicationName(This,ApplicationName,cbApplicationName)

#define IConnectionInfo_GetProviderName(This,ProviderName,cbProviderName)	\
    (This)->lpVtbl -> GetProviderName(This,ProviderName,cbProviderName)

#define IConnectionInfo_GetDatasource(This,Datasource,cbDatasource)	\
    (This)->lpVtbl -> GetDatasource(This,Datasource,cbDatasource)

#define IConnectionInfo_GetLocation(This,Location,cbLocation)	\
    (This)->lpVtbl -> GetLocation(This,Location,cbLocation)

#define IConnectionInfo_GetProviderString(This,ProviderString,cbProviderString)	\
    (This)->lpVtbl -> GetProviderString(This,ProviderString,cbProviderString)

#define IConnectionInfo_GetCatalog(This,Catalog,cbCatalog)	\
    (This)->lpVtbl -> GetCatalog(This,Catalog,cbCatalog)

#define IConnectionInfo_GetDBCreatedThisSession(This,pbDBCreatedThisSession)	\
    (This)->lpVtbl -> GetDBCreatedThisSession(This,pbDBCreatedThisSession)

#define IConnectionInfo_SetConnectName(This,ConnectName)	\
    (This)->lpVtbl -> SetConnectName(This,ConnectName)

#define IConnectionInfo_SetServerName(This,ServerName)	\
    (This)->lpVtbl -> SetServerName(This,ServerName)

#define IConnectionInfo_SetHostName(This,HostName)	\
    (This)->lpVtbl -> SetHostName(This,HostName)

#define IConnectionInfo_SetServerRole(This,ServerRole)	\
    (This)->lpVtbl -> SetServerRole(This,ServerRole)

#define IConnectionInfo_SetInternetAddress(This,InternetAddress)	\
    (This)->lpVtbl -> SetInternetAddress(This,InternetAddress)

#define IConnectionInfo_SetInternetNetwork(This,InternetNetwork)	\
    (This)->lpVtbl -> SetInternetNetwork(This,InternetNetwork)

#define IConnectionInfo_SetDatabase(This,Database)	\
    (This)->lpVtbl -> SetDatabase(This,Database)

#define IConnectionInfo_SetDatabaseStatus(This,lDatabaseStatus)	\
    (This)->lpVtbl -> SetDatabaseStatus(This,lDatabaseStatus)

#define IConnectionInfo_SetDatasourcePath(This,DatasourcePath)	\
    (This)->lpVtbl -> SetDatasourcePath(This,DatasourcePath)

#define IConnectionInfo_SetDataSourceType(This,DataSourceType)	\
    (This)->lpVtbl -> SetDataSourceType(This,DataSourceType)

#define IConnectionInfo_SetSecurityMode(This,SecurityMode)	\
    (This)->lpVtbl -> SetSecurityMode(This,SecurityMode)

#define IConnectionInfo_SetLogin(This,Login)	\
    (This)->lpVtbl -> SetLogin(This,Login)

#define IConnectionInfo_SetPassword(This,Password)	\
    (This)->lpVtbl -> SetPassword(This,Password)

#define IConnectionInfo_SetODBCEnvironmentHandle(This,henv)	\
    (This)->lpVtbl -> SetODBCEnvironmentHandle(This,henv)

#define IConnectionInfo_SetLoginTimeout(This,lLoginTimeout)	\
    (This)->lpVtbl -> SetLoginTimeout(This,lLoginTimeout)

#define IConnectionInfo_SetQueryTimeout(This,lQueryTimeout)	\
    (This)->lpVtbl -> SetQueryTimeout(This,lQueryTimeout)

#define IConnectionInfo_SetPacketSize(This,usPacketSize)	\
    (This)->lpVtbl -> SetPacketSize(This,usPacketSize)

#define IConnectionInfo_SetApplicationName(This,ApplicationName)	\
    (This)->lpVtbl -> SetApplicationName(This,ApplicationName)

#define IConnectionInfo_SetProviderName(This,ProviderName)	\
    (This)->lpVtbl -> SetProviderName(This,ProviderName)

#define IConnectionInfo_SetDatasource(This,Datasource)	\
    (This)->lpVtbl -> SetDatasource(This,Datasource)

#define IConnectionInfo_SetLocation(This,Location)	\
    (This)->lpVtbl -> SetLocation(This,Location)

#define IConnectionInfo_SetProviderString(This,ProviderString)	\
    (This)->lpVtbl -> SetProviderString(This,ProviderString)

#define IConnectionInfo_SetCatalog(This,Catalog)	\
    (This)->lpVtbl -> SetCatalog(This,Catalog)

#define IConnectionInfo_SetDBCreatedThisSession(This,bDBCreatedThisSession)	\
    (This)->lpVtbl -> SetDBCreatedThisSession(This,bDBCreatedThisSession)

#define IConnectionInfo_SetBcpBatchSize(This,lBcpBatchSize)	\
    (This)->lpVtbl -> SetBcpBatchSize(This,lBcpBatchSize)

#define IConnectionInfo_GetBcpBatchSize(This,plBcpBatchSize)	\
    (This)->lpVtbl -> GetBcpBatchSize(This,plBcpBatchSize)

#define IConnectionInfo_GetWaitServerResponse(This,pbWaitingForResponse,pdwWaitingSinceTickCount)	\
    (This)->lpVtbl -> GetWaitServerResponse(This,pbWaitingForResponse,pdwWaitingSinceTickCount)

#define IConnectionInfo_SetWaitServerResponse(This,bWaitingForResponse,dwWaitingSinceTickCount)	\
    (This)->lpVtbl -> SetWaitServerResponse(This,bWaitingForResponse,dwWaitingSinceTickCount)

#define IConnectionInfo_GetUseInprocLoader(This,pbUseInprocLoader)	\
    (This)->lpVtbl -> GetUseInprocLoader(This,pbUseInprocLoader)

#define IConnectionInfo_SetUseInprocLoader(This,bUseInprocLoader)	\
    (This)->lpVtbl -> SetUseInprocLoader(This,bUseInprocLoader)

#define IConnectionInfo_SetCodePage(This,lCodePage)	\
    (This)->lpVtbl -> SetCodePage(This,lCodePage)

#define IConnectionInfo_GetCodePage(This,plCodePage)	\
    (This)->lpVtbl -> GetCodePage(This,plCodePage)

#define IConnectionInfo_SetLCID(This,lLCID)	\
    (This)->lpVtbl -> SetLCID(This,lLCID)

#define IConnectionInfo_GetLCID(This,plLCID)	\
    (This)->lpVtbl -> GetLCID(This,plLCID)

#define IConnectionInfo_SetComparisonStyle(This,lComparisonStyle)	\
    (This)->lpVtbl -> SetComparisonStyle(This,lComparisonStyle)

#define IConnectionInfo_GetComparisonStyle(This,plComparisonStyle)	\
    (This)->lpVtbl -> GetComparisonStyle(This,plComparisonStyle)

#define IConnectionInfo_SetNumDeadlockRetries(This,lNumDeadlockRetries)	\
    (This)->lpVtbl -> SetNumDeadlockRetries(This,lNumDeadlockRetries)

#define IConnectionInfo_GetNumDeadlockRetries(This,plNumDeadlockRetries)	\
    (This)->lpVtbl -> GetNumDeadlockRetries(This,plNumDeadlockRetries)

#define IConnectionInfo_SetMajorVersion(This,lMajorVersion)	\
    (This)->lpVtbl -> SetMajorVersion(This,lMajorVersion)

#define IConnectionInfo_GetMajorVersion(This,plMajorVersion)	\
    (This)->lpVtbl -> GetMajorVersion(This,plMajorVersion)

#define IConnectionInfo_SetMinorVersion(This,lMinorVersion)	\
    (This)->lpVtbl -> SetMinorVersion(This,lMinorVersion)

#define IConnectionInfo_GetMinorVersion(This,plMinorVersion)	\
    (This)->lpVtbl -> GetMinorVersion(This,plMinorVersion)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IConnectionInfo_GetConnectName_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [size_is][string][out] */ LPWSTR ConnectName,
    DWORD cbConnectName);


void __RPC_STUB IConnectionInfo_GetConnectName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetServerName_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [size_is][string][out] */ LPWSTR ServerName,
    DWORD cbServerName);


void __RPC_STUB IConnectionInfo_GetServerName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetHostName_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [size_is][string][out] */ LPWSTR HostName,
    DWORD cbHostName);


void __RPC_STUB IConnectionInfo_GetHostName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetServerRole_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [size_is][string][out] */ LPWSTR ServerRole,
    DWORD cbServerRole);


void __RPC_STUB IConnectionInfo_GetServerRole_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetInternetAddress_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [size_is][string][out] */ LPWSTR InternetAddress,
    DWORD cbInternetAddress);


void __RPC_STUB IConnectionInfo_GetInternetAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetInternetNetwork_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [size_is][string][out] */ LPWSTR InternetNetwork,
    DWORD cbInternetNetwork);


void __RPC_STUB IConnectionInfo_GetInternetNetwork_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetDatabase_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [size_is][string][out] */ LPWSTR Database,
    DWORD cbDatabase);


void __RPC_STUB IConnectionInfo_GetDatabase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetDatabaseStatus_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plDatabaseStatus);


void __RPC_STUB IConnectionInfo_GetDatabaseStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetDatasourcePath_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [size_is][string][out] */ LPWSTR DatasourcePath,
    DWORD cbDatasourcePath);


void __RPC_STUB IConnectionInfo_GetDatasourcePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetDataSourceType_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [out] */ REPOLE_DATASOURCE_TYPE __RPC_FAR *pRetValue);


void __RPC_STUB IConnectionInfo_GetDataSourceType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetSecurityMode_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [out] */ REPOLE_SECURITY_TYPE __RPC_FAR *pRetValue);


void __RPC_STUB IConnectionInfo_GetSecurityMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetLogin_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [size_is][string][out] */ LPWSTR Login,
    DWORD cbLogin);


void __RPC_STUB IConnectionInfo_GetLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetPassword_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [size_is][string][out] */ LPWSTR Password,
    DWORD cbPassword);


void __RPC_STUB IConnectionInfo_GetPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetODBCEnvironmentHandle_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *phenv);


void __RPC_STUB IConnectionInfo_GetODBCEnvironmentHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetLoginTimeout_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plLoginTimeout);


void __RPC_STUB IConnectionInfo_GetLoginTimeout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetQueryTimeout_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *plQueryTimeout);


void __RPC_STUB IConnectionInfo_GetQueryTimeout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetPacketSize_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [out] */ unsigned long __RPC_FAR *pusPacketSize);


void __RPC_STUB IConnectionInfo_GetPacketSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetApplicationName_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [size_is][string][out] */ LPWSTR ApplicationName,
    DWORD cbApplicationName);


void __RPC_STUB IConnectionInfo_GetApplicationName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetProviderName_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [size_is][string][out] */ LPWSTR ProviderName,
    DWORD cbProviderName);


void __RPC_STUB IConnectionInfo_GetProviderName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetDatasource_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [size_is][string][out] */ LPWSTR Datasource,
    DWORD cbDatasource);


void __RPC_STUB IConnectionInfo_GetDatasource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetLocation_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [size_is][string][out] */ LPWSTR Location,
    DWORD cbLocation);


void __RPC_STUB IConnectionInfo_GetLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetProviderString_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [size_is][string][out] */ LPWSTR ProviderString,
    DWORD cbProviderString);


void __RPC_STUB IConnectionInfo_GetProviderString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetCatalog_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [size_is][string][out] */ LPWSTR Catalog,
    DWORD cbCatalog);


void __RPC_STUB IConnectionInfo_GetCatalog_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetDBCreatedThisSession_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [out] */ BOOL __RPC_FAR *pbDBCreatedThisSession);


void __RPC_STUB IConnectionInfo_GetDBCreatedThisSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetConnectName_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ LPCWSTR ConnectName);


void __RPC_STUB IConnectionInfo_SetConnectName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetServerName_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ LPCWSTR ServerName);


void __RPC_STUB IConnectionInfo_SetServerName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetHostName_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ LPCWSTR HostName);


void __RPC_STUB IConnectionInfo_SetHostName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetServerRole_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ LPCWSTR ServerRole);


void __RPC_STUB IConnectionInfo_SetServerRole_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetInternetAddress_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ LPCWSTR InternetAddress);


void __RPC_STUB IConnectionInfo_SetInternetAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetInternetNetwork_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ LPCWSTR InternetNetwork);


void __RPC_STUB IConnectionInfo_SetInternetNetwork_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetDatabase_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ LPCWSTR Database);


void __RPC_STUB IConnectionInfo_SetDatabase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetDatabaseStatus_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ LONG lDatabaseStatus);


void __RPC_STUB IConnectionInfo_SetDatabaseStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetDatasourcePath_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ LPCWSTR DatasourcePath);


void __RPC_STUB IConnectionInfo_SetDatasourcePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetDataSourceType_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ REPOLE_DATASOURCE_TYPE DataSourceType);


void __RPC_STUB IConnectionInfo_SetDataSourceType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetSecurityMode_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ REPOLE_SECURITY_TYPE SecurityMode);


void __RPC_STUB IConnectionInfo_SetSecurityMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetLogin_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ LPCWSTR Login);


void __RPC_STUB IConnectionInfo_SetLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetPassword_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ LPCWSTR Password);


void __RPC_STUB IConnectionInfo_SetPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetODBCEnvironmentHandle_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ long henv);


void __RPC_STUB IConnectionInfo_SetODBCEnvironmentHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetLoginTimeout_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ LONG lLoginTimeout);


void __RPC_STUB IConnectionInfo_SetLoginTimeout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetQueryTimeout_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ LONG lQueryTimeout);


void __RPC_STUB IConnectionInfo_SetQueryTimeout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetPacketSize_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ unsigned long usPacketSize);


void __RPC_STUB IConnectionInfo_SetPacketSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetApplicationName_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ LPCWSTR ApplicationName);


void __RPC_STUB IConnectionInfo_SetApplicationName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetProviderName_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ LPCWSTR ProviderName);


void __RPC_STUB IConnectionInfo_SetProviderName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetDatasource_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ LPCWSTR Datasource);


void __RPC_STUB IConnectionInfo_SetDatasource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetLocation_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ LPCWSTR Location);


void __RPC_STUB IConnectionInfo_SetLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetProviderString_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ LPCWSTR ProviderString);


void __RPC_STUB IConnectionInfo_SetProviderString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetCatalog_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ LPCWSTR Catalog);


void __RPC_STUB IConnectionInfo_SetCatalog_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetDBCreatedThisSession_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ BOOL bDBCreatedThisSession);


void __RPC_STUB IConnectionInfo_SetDBCreatedThisSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetBcpBatchSize_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ LONG lBcpBatchSize);


void __RPC_STUB IConnectionInfo_SetBcpBatchSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetBcpBatchSize_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *plBcpBatchSize);


void __RPC_STUB IConnectionInfo_GetBcpBatchSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetWaitServerResponse_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [out] */ BOOL __RPC_FAR *pbWaitingForResponse,
    /* [out] */ DWORD __RPC_FAR *pdwWaitingSinceTickCount);


void __RPC_STUB IConnectionInfo_GetWaitServerResponse_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetWaitServerResponse_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ BOOL bWaitingForResponse,
    /* [in] */ DWORD dwWaitingSinceTickCount);


void __RPC_STUB IConnectionInfo_SetWaitServerResponse_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetUseInprocLoader_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [out] */ BOOL __RPC_FAR *pbUseInprocLoader);


void __RPC_STUB IConnectionInfo_GetUseInprocLoader_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetUseInprocLoader_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ BOOL bUseInprocLoader);


void __RPC_STUB IConnectionInfo_SetUseInprocLoader_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetCodePage_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ LONG lCodePage);


void __RPC_STUB IConnectionInfo_SetCodePage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetCodePage_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *plCodePage);


void __RPC_STUB IConnectionInfo_GetCodePage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetLCID_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ LONG lLCID);


void __RPC_STUB IConnectionInfo_SetLCID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetLCID_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *plLCID);


void __RPC_STUB IConnectionInfo_GetLCID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetComparisonStyle_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ LONG lComparisonStyle);


void __RPC_STUB IConnectionInfo_SetComparisonStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetComparisonStyle_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *plComparisonStyle);


void __RPC_STUB IConnectionInfo_GetComparisonStyle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetNumDeadlockRetries_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [in] */ LONG lNumDeadlockRetries);


void __RPC_STUB IConnectionInfo_SetNumDeadlockRetries_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetNumDeadlockRetries_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *plNumDeadlockRetries);


void __RPC_STUB IConnectionInfo_GetNumDeadlockRetries_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetMajorVersion_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    LONG lMajorVersion);


void __RPC_STUB IConnectionInfo_SetMajorVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetMajorVersion_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    LONG __RPC_FAR *plMajorVersion);


void __RPC_STUB IConnectionInfo_GetMajorVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_SetMinorVersion_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    LONG lMinorVersion);


void __RPC_STUB IConnectionInfo_SetMinorVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IConnectionInfo_GetMinorVersion_Proxy( 
    IConnectionInfo __RPC_FAR * This,
    LONG __RPC_FAR *plMinorVersion);


void __RPC_STUB IConnectionInfo_GetMinorVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IConnectionInfo_INTERFACE_DEFINED__ */


#ifndef __IReplRowChange_INTERFACE_DEFINED__
#define __IReplRowChange_INTERFACE_DEFINED__

/* interface IReplRowChange */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IReplRowChange;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FC2F91C2-1CA2-11d0-A11B-00AA003E4672")
    IReplRowChange : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetTableName( 
            /* [size_is][string][out] */ LPWSTR pTableName,
            DWORD cbTableName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRowIdentifier( 
            /* [out] */ LPGUID pRowGuid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetResolverProcedureName( 
            /* [size_is][string][out] */ LPWSTR pResolverProcedureName,
            DWORD cbResolverProcedureName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNumColumns( 
            /* [out] */ DWORD __RPC_FAR *pdwColumnCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetChangeType( 
            /* [out] */ REPOLE_CHANGE_TYPE __RPC_FAR *pChangeType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetColumnStatus( 
            DWORD ColumnId,
            /* [out] */ REPOLE_COLSTATUS_TYPE __RPC_FAR *pColStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetColumnName( 
            DWORD ColumnId,
            /* [size_is][string][out] */ LPWSTR pColumnName,
            DWORD cbColumnName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetColumnDatatype( 
            DWORD ColumnId,
            /* [out] */ long __RPC_FAR *plDataType) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetSourceColumnValue( 
            DWORD ColumnId,
            /* [out] */ void __RPC_FAR *pvBuffer,
            /* [in] */ DWORD bBufferMax,
            /* [out] */ DWORD __RPC_FAR *pcbBufferActual) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetDestinationColumnValue( 
            DWORD ColumnId,
            /* [out] */ void __RPC_FAR *pvBuffer,
            /* [in] */ DWORD cbBufferMax,
            /* [out] */ DWORD __RPC_FAR *pcbBufferActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPriorityWinner( 
            /* [out] */ REPOLE_PRIORITY_TYPE __RPC_FAR *pPriorityWinner) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSourceConnectionInfo( 
            /* [out] */ IConnectionInfo __RPC_FAR *__RPC_FAR *ppSourceConnectionInfo,
            /* [out] */ BOOL __RPC_FAR *pfIsPublisher) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDestinationConnectionInfo( 
            /* [out] */ IConnectionInfo __RPC_FAR *__RPC_FAR *ppDestinationConnectionInfo,
            /* [out] */ BOOL __RPC_FAR *pfIsPublisher) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteRow( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CopyRowFromSource( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CopyColumnFromSource( 
            DWORD ColumnId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ForceRememberChange( void) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE SetColumn( 
            DWORD ColumnId,
            /* [in] */ void __RPC_FAR *pvBuffer,
            DWORD cbBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateRow( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InsertRow( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LogConflict( 
            /* [in] */ BOOL bLogSourceConflict,
            /* [in] */ REPOLE_CONFLICT_TYPE ConflictType,
            /* [in] */ BOOL bOnlyLogIfUpdater,
            /* [defaultvalue][optional][string][in] */ BSTR pszConflictMessage = L"",
            /* [defaultvalue][optional][in] */ BOOL bLogConflictOnUpload = FALSE) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LogError( 
            /* [in] */ REPOLE_CHANGE_TYPE ChangeType,
            /* [defaultvalue][optional][string][in] */ BSTR pszErrorMessage = L"") = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetErrorInfo( 
            /* [out] */ DWORD __RPC_FAR *pErrCode,
            /* [string] */ LPWSTR pErrText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoDummyUpdate( 
            /* [in] */ BOOL fUpLineage,
            /* [in] */ BOOL fAtPublisher) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTableOwnerName( 
            /* [size_is][string][out] */ LPWSTR pOwnerName,
            DWORD cbOwnerName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRowGuidColName( 
            /* [size_is][string][out] */ LPWSTR pRowGuidColName,
            DWORD cbRowGuidColName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDestinationOwnerName( 
            /* [size_is][string][out] */ LPWSTR pDestOwnerName,
            DWORD cbDestName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetColumnAttributes( 
            DWORD ColumnId,
            /* [out] */ REPOLE_COLUMN_ATTRIBUTES __RPC_FAR *plColumnAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExtendedError( 
            /* [out] */ REPOLE_EXTENDEDERROR_TYPE __RPC_FAR *pExtError) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetExtendedError( 
            /* [in] */ REPOLE_EXTENDEDERROR_TYPE ExtError) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IReplRowChangeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IReplRowChange __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IReplRowChange __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IReplRowChange __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTableName )( 
            IReplRowChange __RPC_FAR * This,
            /* [size_is][string][out] */ LPWSTR pTableName,
            DWORD cbTableName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRowIdentifier )( 
            IReplRowChange __RPC_FAR * This,
            /* [out] */ LPGUID pRowGuid);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetResolverProcedureName )( 
            IReplRowChange __RPC_FAR * This,
            /* [size_is][string][out] */ LPWSTR pResolverProcedureName,
            DWORD cbResolverProcedureName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumColumns )( 
            IReplRowChange __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pdwColumnCount);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetChangeType )( 
            IReplRowChange __RPC_FAR * This,
            /* [out] */ REPOLE_CHANGE_TYPE __RPC_FAR *pChangeType);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColumnStatus )( 
            IReplRowChange __RPC_FAR * This,
            DWORD ColumnId,
            /* [out] */ REPOLE_COLSTATUS_TYPE __RPC_FAR *pColStatus);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColumnName )( 
            IReplRowChange __RPC_FAR * This,
            DWORD ColumnId,
            /* [size_is][string][out] */ LPWSTR pColumnName,
            DWORD cbColumnName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColumnDatatype )( 
            IReplRowChange __RPC_FAR * This,
            DWORD ColumnId,
            /* [out] */ long __RPC_FAR *plDataType);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSourceColumnValue )( 
            IReplRowChange __RPC_FAR * This,
            DWORD ColumnId,
            /* [out] */ void __RPC_FAR *pvBuffer,
            /* [in] */ DWORD bBufferMax,
            /* [out] */ DWORD __RPC_FAR *pcbBufferActual);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDestinationColumnValue )( 
            IReplRowChange __RPC_FAR * This,
            DWORD ColumnId,
            /* [out] */ void __RPC_FAR *pvBuffer,
            /* [in] */ DWORD cbBufferMax,
            /* [out] */ DWORD __RPC_FAR *pcbBufferActual);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPriorityWinner )( 
            IReplRowChange __RPC_FAR * This,
            /* [out] */ REPOLE_PRIORITY_TYPE __RPC_FAR *pPriorityWinner);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSourceConnectionInfo )( 
            IReplRowChange __RPC_FAR * This,
            /* [out] */ IConnectionInfo __RPC_FAR *__RPC_FAR *ppSourceConnectionInfo,
            /* [out] */ BOOL __RPC_FAR *pfIsPublisher);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDestinationConnectionInfo )( 
            IReplRowChange __RPC_FAR * This,
            /* [out] */ IConnectionInfo __RPC_FAR *__RPC_FAR *ppDestinationConnectionInfo,
            /* [out] */ BOOL __RPC_FAR *pfIsPublisher);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteRow )( 
            IReplRowChange __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CopyRowFromSource )( 
            IReplRowChange __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CopyColumnFromSource )( 
            IReplRowChange __RPC_FAR * This,
            DWORD ColumnId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ForceRememberChange )( 
            IReplRowChange __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColumn )( 
            IReplRowChange __RPC_FAR * This,
            DWORD ColumnId,
            /* [in] */ void __RPC_FAR *pvBuffer,
            DWORD cbBuffer);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UpdateRow )( 
            IReplRowChange __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InsertRow )( 
            IReplRowChange __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LogConflict )( 
            IReplRowChange __RPC_FAR * This,
            /* [in] */ BOOL bLogSourceConflict,
            /* [in] */ REPOLE_CONFLICT_TYPE ConflictType,
            /* [in] */ BOOL bOnlyLogIfUpdater,
            /* [defaultvalue][optional][string][in] */ BSTR pszConflictMessage,
            /* [defaultvalue][optional][in] */ BOOL bLogConflictOnUpload);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LogError )( 
            IReplRowChange __RPC_FAR * This,
            /* [in] */ REPOLE_CHANGE_TYPE ChangeType,
            /* [defaultvalue][optional][string][in] */ BSTR pszErrorMessage);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetErrorInfo )( 
            IReplRowChange __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pErrCode,
            /* [string] */ LPWSTR pErrText);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DoDummyUpdate )( 
            IReplRowChange __RPC_FAR * This,
            /* [in] */ BOOL fUpLineage,
            /* [in] */ BOOL fAtPublisher);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTableOwnerName )( 
            IReplRowChange __RPC_FAR * This,
            /* [size_is][string][out] */ LPWSTR pOwnerName,
            DWORD cbOwnerName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRowGuidColName )( 
            IReplRowChange __RPC_FAR * This,
            /* [size_is][string][out] */ LPWSTR pRowGuidColName,
            DWORD cbRowGuidColName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDestinationOwnerName )( 
            IReplRowChange __RPC_FAR * This,
            /* [size_is][string][out] */ LPWSTR pDestOwnerName,
            DWORD cbDestName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColumnAttributes )( 
            IReplRowChange __RPC_FAR * This,
            DWORD ColumnId,
            /* [out] */ REPOLE_COLUMN_ATTRIBUTES __RPC_FAR *plColumnAttributes);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetExtendedError )( 
            IReplRowChange __RPC_FAR * This,
            /* [out] */ REPOLE_EXTENDEDERROR_TYPE __RPC_FAR *pExtError);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetExtendedError )( 
            IReplRowChange __RPC_FAR * This,
            /* [in] */ REPOLE_EXTENDEDERROR_TYPE ExtError);
        
        END_INTERFACE
    } IReplRowChangeVtbl;

    interface IReplRowChange
    {
        CONST_VTBL struct IReplRowChangeVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IReplRowChange_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IReplRowChange_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IReplRowChange_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IReplRowChange_GetTableName(This,pTableName,cbTableName)	\
    (This)->lpVtbl -> GetTableName(This,pTableName,cbTableName)

#define IReplRowChange_GetRowIdentifier(This,pRowGuid)	\
    (This)->lpVtbl -> GetRowIdentifier(This,pRowGuid)

#define IReplRowChange_GetResolverProcedureName(This,pResolverProcedureName,cbResolverProcedureName)	\
    (This)->lpVtbl -> GetResolverProcedureName(This,pResolverProcedureName,cbResolverProcedureName)

#define IReplRowChange_GetNumColumns(This,pdwColumnCount)	\
    (This)->lpVtbl -> GetNumColumns(This,pdwColumnCount)

#define IReplRowChange_GetChangeType(This,pChangeType)	\
    (This)->lpVtbl -> GetChangeType(This,pChangeType)

#define IReplRowChange_GetColumnStatus(This,ColumnId,pColStatus)	\
    (This)->lpVtbl -> GetColumnStatus(This,ColumnId,pColStatus)

#define IReplRowChange_GetColumnName(This,ColumnId,pColumnName,cbColumnName)	\
    (This)->lpVtbl -> GetColumnName(This,ColumnId,pColumnName,cbColumnName)

#define IReplRowChange_GetColumnDatatype(This,ColumnId,plDataType)	\
    (This)->lpVtbl -> GetColumnDatatype(This,ColumnId,plDataType)

#define IReplRowChange_GetSourceColumnValue(This,ColumnId,pvBuffer,bBufferMax,pcbBufferActual)	\
    (This)->lpVtbl -> GetSourceColumnValue(This,ColumnId,pvBuffer,bBufferMax,pcbBufferActual)

#define IReplRowChange_GetDestinationColumnValue(This,ColumnId,pvBuffer,cbBufferMax,pcbBufferActual)	\
    (This)->lpVtbl -> GetDestinationColumnValue(This,ColumnId,pvBuffer,cbBufferMax,pcbBufferActual)

#define IReplRowChange_GetPriorityWinner(This,pPriorityWinner)	\
    (This)->lpVtbl -> GetPriorityWinner(This,pPriorityWinner)

#define IReplRowChange_GetSourceConnectionInfo(This,ppSourceConnectionInfo,pfIsPublisher)	\
    (This)->lpVtbl -> GetSourceConnectionInfo(This,ppSourceConnectionInfo,pfIsPublisher)

#define IReplRowChange_GetDestinationConnectionInfo(This,ppDestinationConnectionInfo,pfIsPublisher)	\
    (This)->lpVtbl -> GetDestinationConnectionInfo(This,ppDestinationConnectionInfo,pfIsPublisher)

#define IReplRowChange_DeleteRow(This)	\
    (This)->lpVtbl -> DeleteRow(This)

#define IReplRowChange_CopyRowFromSource(This)	\
    (This)->lpVtbl -> CopyRowFromSource(This)

#define IReplRowChange_CopyColumnFromSource(This,ColumnId)	\
    (This)->lpVtbl -> CopyColumnFromSource(This,ColumnId)

#define IReplRowChange_ForceRememberChange(This)	\
    (This)->lpVtbl -> ForceRememberChange(This)

#define IReplRowChange_SetColumn(This,ColumnId,pvBuffer,cbBuffer)	\
    (This)->lpVtbl -> SetColumn(This,ColumnId,pvBuffer,cbBuffer)

#define IReplRowChange_UpdateRow(This)	\
    (This)->lpVtbl -> UpdateRow(This)

#define IReplRowChange_InsertRow(This)	\
    (This)->lpVtbl -> InsertRow(This)

#define IReplRowChange_LogConflict(This,bLogSourceConflict,ConflictType,bOnlyLogIfUpdater,pszConflictMessage,bLogConflictOnUpload)	\
    (This)->lpVtbl -> LogConflict(This,bLogSourceConflict,ConflictType,bOnlyLogIfUpdater,pszConflictMessage,bLogConflictOnUpload)

#define IReplRowChange_LogError(This,ChangeType,pszErrorMessage)	\
    (This)->lpVtbl -> LogError(This,ChangeType,pszErrorMessage)

#define IReplRowChange_GetErrorInfo(This,pErrCode,pErrText)	\
    (This)->lpVtbl -> GetErrorInfo(This,pErrCode,pErrText)

#define IReplRowChange_DoDummyUpdate(This,fUpLineage,fAtPublisher)	\
    (This)->lpVtbl -> DoDummyUpdate(This,fUpLineage,fAtPublisher)

#define IReplRowChange_GetTableOwnerName(This,pOwnerName,cbOwnerName)	\
    (This)->lpVtbl -> GetTableOwnerName(This,pOwnerName,cbOwnerName)

#define IReplRowChange_GetRowGuidColName(This,pRowGuidColName,cbRowGuidColName)	\
    (This)->lpVtbl -> GetRowGuidColName(This,pRowGuidColName,cbRowGuidColName)

#define IReplRowChange_GetDestinationOwnerName(This,pDestOwnerName,cbDestName)	\
    (This)->lpVtbl -> GetDestinationOwnerName(This,pDestOwnerName,cbDestName)

#define IReplRowChange_GetColumnAttributes(This,ColumnId,plColumnAttributes)	\
    (This)->lpVtbl -> GetColumnAttributes(This,ColumnId,plColumnAttributes)

#define IReplRowChange_GetExtendedError(This,pExtError)	\
    (This)->lpVtbl -> GetExtendedError(This,pExtError)

#define IReplRowChange_SetExtendedError(This,ExtError)	\
    (This)->lpVtbl -> SetExtendedError(This,ExtError)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IReplRowChange_GetTableName_Proxy( 
    IReplRowChange __RPC_FAR * This,
    /* [size_is][string][out] */ LPWSTR pTableName,
    DWORD cbTableName);


void __RPC_STUB IReplRowChange_GetTableName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IReplRowChange_GetRowIdentifier_Proxy( 
    IReplRowChange __RPC_FAR * This,
    /* [out] */ LPGUID pRowGuid);


void __RPC_STUB IReplRowChange_GetRowIdentifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IReplRowChange_GetResolverProcedureName_Proxy( 
    IReplRowChange __RPC_FAR * This,
    /* [size_is][string][out] */ LPWSTR pResolverProcedureName,
    DWORD cbResolverProcedureName);


void __RPC_STUB IReplRowChange_GetResolverProcedureName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IReplRowChange_GetNumColumns_Proxy( 
    IReplRowChange __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *pdwColumnCount);


void __RPC_STUB IReplRowChange_GetNumColumns_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IReplRowChange_GetChangeType_Proxy( 
    IReplRowChange __RPC_FAR * This,
    /* [out] */ REPOLE_CHANGE_TYPE __RPC_FAR *pChangeType);


void __RPC_STUB IReplRowChange_GetChangeType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IReplRowChange_GetColumnStatus_Proxy( 
    IReplRowChange __RPC_FAR * This,
    DWORD ColumnId,
    /* [out] */ REPOLE_COLSTATUS_TYPE __RPC_FAR *pColStatus);


void __RPC_STUB IReplRowChange_GetColumnStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IReplRowChange_GetColumnName_Proxy( 
    IReplRowChange __RPC_FAR * This,
    DWORD ColumnId,
    /* [size_is][string][out] */ LPWSTR pColumnName,
    DWORD cbColumnName);


void __RPC_STUB IReplRowChange_GetColumnName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IReplRowChange_GetColumnDatatype_Proxy( 
    IReplRowChange __RPC_FAR * This,
    DWORD ColumnId,
    /* [out] */ long __RPC_FAR *plDataType);


void __RPC_STUB IReplRowChange_GetColumnDatatype_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IReplRowChange_RemoteGetSourceColumnValue_Proxy( 
    IReplRowChange __RPC_FAR * This,
    DWORD ColumnId,
    /* [out] */ VARIANT __RPC_FAR *pvBuffer,
    /* [in] */ DWORD cbBufferMax,
    /* [out] */ DWORD __RPC_FAR *pcbBufferActual);


void __RPC_STUB IReplRowChange_RemoteGetSourceColumnValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IReplRowChange_RemoteGetDestinationColumnValue_Proxy( 
    IReplRowChange __RPC_FAR * This,
    DWORD ColumnId,
    /* [out] */ VARIANT __RPC_FAR *pvBuffer,
    /* [in] */ DWORD cbBufferMax,
    /* [out] */ DWORD __RPC_FAR *pcbBufferActual);


void __RPC_STUB IReplRowChange_RemoteGetDestinationColumnValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IReplRowChange_GetPriorityWinner_Proxy( 
    IReplRowChange __RPC_FAR * This,
    /* [out] */ REPOLE_PRIORITY_TYPE __RPC_FAR *pPriorityWinner);


void __RPC_STUB IReplRowChange_GetPriorityWinner_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IReplRowChange_GetSourceConnectionInfo_Proxy( 
    IReplRowChange __RPC_FAR * This,
    /* [out] */ IConnectionInfo __RPC_FAR *__RPC_FAR *ppSourceConnectionInfo,
    /* [out] */ BOOL __RPC_FAR *pfIsPublisher);


void __RPC_STUB IReplRowChange_GetSourceConnectionInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IReplRowChange_GetDestinationConnectionInfo_Proxy( 
    IReplRowChange __RPC_FAR * This,
    /* [out] */ IConnectionInfo __RPC_FAR *__RPC_FAR *ppDestinationConnectionInfo,
    /* [out] */ BOOL __RPC_FAR *pfIsPublisher);


void __RPC_STUB IReplRowChange_GetDestinationConnectionInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IReplRowChange_DeleteRow_Proxy( 
    IReplRowChange __RPC_FAR * This);


void __RPC_STUB IReplRowChange_DeleteRow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IReplRowChange_CopyRowFromSource_Proxy( 
    IReplRowChange __RPC_FAR * This);


void __RPC_STUB IReplRowChange_CopyRowFromSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IReplRowChange_CopyColumnFromSource_Proxy( 
    IReplRowChange __RPC_FAR * This,
    DWORD ColumnId);


void __RPC_STUB IReplRowChange_CopyColumnFromSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IReplRowChange_ForceRememberChange_Proxy( 
    IReplRowChange __RPC_FAR * This);


void __RPC_STUB IReplRowChange_ForceRememberChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IReplRowChange_RemoteSetColumn_Proxy( 
    IReplRowChange __RPC_FAR * This,
    DWORD ColumnId,
    /* [in] */ VARIANT __RPC_FAR *pvBuffer,
    DWORD cbBuffer);


void __RPC_STUB IReplRowChange_RemoteSetColumn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IReplRowChange_UpdateRow_Proxy( 
    IReplRowChange __RPC_FAR * This);


void __RPC_STUB IReplRowChange_UpdateRow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IReplRowChange_InsertRow_Proxy( 
    IReplRowChange __RPC_FAR * This);


void __RPC_STUB IReplRowChange_InsertRow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IReplRowChange_LogConflict_Proxy( 
    IReplRowChange __RPC_FAR * This,
    /* [in] */ BOOL bLogSourceConflict,
    /* [in] */ REPOLE_CONFLICT_TYPE ConflictType,
    /* [in] */ BOOL bOnlyLogIfUpdater,
    /* [defaultvalue][optional][string][in] */ BSTR pszConflictMessage,
    /* [defaultvalue][optional][in] */ BOOL bLogConflictOnUpload);


void __RPC_STUB IReplRowChange_LogConflict_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IReplRowChange_LogError_Proxy( 
    IReplRowChange __RPC_FAR * This,
    /* [in] */ REPOLE_CHANGE_TYPE ChangeType,
    /* [defaultvalue][optional][string][in] */ BSTR pszErrorMessage);


void __RPC_STUB IReplRowChange_LogError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IReplRowChange_GetErrorInfo_Proxy( 
    IReplRowChange __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *pErrCode,
    /* [string] */ LPWSTR pErrText);


void __RPC_STUB IReplRowChange_GetErrorInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IReplRowChange_DoDummyUpdate_Proxy( 
    IReplRowChange __RPC_FAR * This,
    /* [in] */ BOOL fUpLineage,
    /* [in] */ BOOL fAtPublisher);


void __RPC_STUB IReplRowChange_DoDummyUpdate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IReplRowChange_GetTableOwnerName_Proxy( 
    IReplRowChange __RPC_FAR * This,
    /* [size_is][string][out] */ LPWSTR pOwnerName,
    DWORD cbOwnerName);


void __RPC_STUB IReplRowChange_GetTableOwnerName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IReplRowChange_GetRowGuidColName_Proxy( 
    IReplRowChange __RPC_FAR * This,
    /* [size_is][string][out] */ LPWSTR pRowGuidColName,
    DWORD cbRowGuidColName);


void __RPC_STUB IReplRowChange_GetRowGuidColName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IReplRowChange_GetDestinationOwnerName_Proxy( 
    IReplRowChange __RPC_FAR * This,
    /* [size_is][string][out] */ LPWSTR pDestOwnerName,
    DWORD cbDestName);


void __RPC_STUB IReplRowChange_GetDestinationOwnerName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IReplRowChange_GetColumnAttributes_Proxy( 
    IReplRowChange __RPC_FAR * This,
    DWORD ColumnId,
    /* [out] */ REPOLE_COLUMN_ATTRIBUTES __RPC_FAR *plColumnAttributes);


void __RPC_STUB IReplRowChange_GetColumnAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IReplRowChange_GetExtendedError_Proxy( 
    IReplRowChange __RPC_FAR * This,
    /* [out] */ REPOLE_EXTENDEDERROR_TYPE __RPC_FAR *pExtError);


void __RPC_STUB IReplRowChange_GetExtendedError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IReplRowChange_SetExtendedError_Proxy( 
    IReplRowChange __RPC_FAR * This,
    /* [in] */ REPOLE_EXTENDEDERROR_TYPE ExtError);


void __RPC_STUB IReplRowChange_SetExtendedError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IReplRowChange_INTERFACE_DEFINED__ */


#ifndef __ICustomResolver_INTERFACE_DEFINED__
#define __ICustomResolver_INTERFACE_DEFINED__

/* interface ICustomResolver */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ICustomResolver;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FC2F91C1-1CA2-11d0-A11B-00AA003E4672")
    ICustomResolver : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE Reconcile( 
            /* [in] */ IReplRowChange __RPC_FAR *pRowChange,
            DWORD dwFlags,
            /* [in] */ void __RPC_FAR *pvReserved) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHandledStates( 
            /* [out][in] */ DWORD __RPC_FAR *ResolverBm) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICustomResolverVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ICustomResolver __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ICustomResolver __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ICustomResolver __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reconcile )( 
            ICustomResolver __RPC_FAR * This,
            /* [in] */ IReplRowChange __RPC_FAR *pRowChange,
            DWORD dwFlags,
            /* [in] */ void __RPC_FAR *pvReserved);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHandledStates )( 
            ICustomResolver __RPC_FAR * This,
            /* [out][in] */ DWORD __RPC_FAR *ResolverBm);
        
        END_INTERFACE
    } ICustomResolverVtbl;

    interface ICustomResolver
    {
        CONST_VTBL struct ICustomResolverVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICustomResolver_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICustomResolver_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICustomResolver_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICustomResolver_Reconcile(This,pRowChange,dwFlags,pvReserved)	\
    (This)->lpVtbl -> Reconcile(This,pRowChange,dwFlags,pvReserved)

#define ICustomResolver_GetHandledStates(This,ResolverBm)	\
    (This)->lpVtbl -> GetHandledStates(This,ResolverBm)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT STDMETHODCALLTYPE ICustomResolver_RemoteReconcile_Proxy( 
    ICustomResolver __RPC_FAR * This,
    /* [in] */ IReplRowChange __RPC_FAR *pRowChange,
    DWORD dwFlags,
    /* [in] */ IReplRowChange __RPC_FAR *pvReserved);


void __RPC_STUB ICustomResolver_RemoteReconcile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICustomResolver_GetHandledStates_Proxy( 
    ICustomResolver __RPC_FAR * This,
    /* [out][in] */ DWORD __RPC_FAR *ResolverBm);


void __RPC_STUB ICustomResolver_GetHandledStates_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICustomResolver_INTERFACE_DEFINED__ */



#ifndef __SQLResolver_LIBRARY_DEFINED__
#define __SQLResolver_LIBRARY_DEFINED__

/* library SQLResolver */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_SQLResolver;

EXTERN_C const CLSID CLSID_IVBCustomResolver;

#ifdef __cplusplus

class DECLSPEC_UUID("16469B61-92F0-11d2-A8DC-00C04F9FC436")
IVBCustomResolver;
#endif
#endif /* __SQLResolver_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long __RPC_FAR *, unsigned long            , VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long __RPC_FAR *, VARIANT __RPC_FAR * ); 

/* [local] */ HRESULT STDMETHODCALLTYPE IReplRowChange_GetSourceColumnValue_Proxy( 
    IReplRowChange __RPC_FAR * This,
    DWORD ColumnId,
    /* [out] */ void __RPC_FAR *pvBuffer,
    /* [in] */ DWORD bBufferMax,
    /* [out] */ DWORD __RPC_FAR *pcbBufferActual);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IReplRowChange_GetSourceColumnValue_Stub( 
    IReplRowChange __RPC_FAR * This,
    DWORD ColumnId,
    /* [out] */ VARIANT __RPC_FAR *pvBuffer,
    /* [in] */ DWORD cbBufferMax,
    /* [out] */ DWORD __RPC_FAR *pcbBufferActual);

/* [local] */ HRESULT STDMETHODCALLTYPE IReplRowChange_GetDestinationColumnValue_Proxy( 
    IReplRowChange __RPC_FAR * This,
    DWORD ColumnId,
    /* [out] */ void __RPC_FAR *pvBuffer,
    /* [in] */ DWORD cbBufferMax,
    /* [out] */ DWORD __RPC_FAR *pcbBufferActual);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IReplRowChange_GetDestinationColumnValue_Stub( 
    IReplRowChange __RPC_FAR * This,
    DWORD ColumnId,
    /* [out] */ VARIANT __RPC_FAR *pvBuffer,
    /* [in] */ DWORD cbBufferMax,
    /* [out] */ DWORD __RPC_FAR *pcbBufferActual);

/* [local] */ HRESULT STDMETHODCALLTYPE IReplRowChange_SetColumn_Proxy( 
    IReplRowChange __RPC_FAR * This,
    DWORD ColumnId,
    /* [in] */ void __RPC_FAR *pvBuffer,
    DWORD cbBuffer);


/* [call_as] */ HRESULT STDMETHODCALLTYPE IReplRowChange_SetColumn_Stub( 
    IReplRowChange __RPC_FAR * This,
    DWORD ColumnId,
    /* [in] */ VARIANT __RPC_FAR *pvBuffer,
    DWORD cbBuffer);

/* [local] */ HRESULT STDMETHODCALLTYPE ICustomResolver_Reconcile_Proxy( 
    ICustomResolver __RPC_FAR * This,
    /* [in] */ IReplRowChange __RPC_FAR *pRowChange,
    DWORD dwFlags,
    /* [in] */ void __RPC_FAR *pvReserved);


/* [call_as] */ HRESULT STDMETHODCALLTYPE ICustomResolver_Reconcile_Stub( 
    ICustomResolver __RPC_FAR * This,
    /* [in] */ IReplRowChange __RPC_FAR *pRowChange,
    DWORD dwFlags,
    /* [in] */ IReplRowChange __RPC_FAR *pvReserved);



/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
