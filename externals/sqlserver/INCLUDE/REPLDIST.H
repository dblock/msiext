#ifndef _REPLDIST_H_
#define _REPLDIST_H_

// OLEDB header
#include "oledb.h"

#ifndef __IDistributionStore_FWD_DEFINED__
#define __IDistributionStore_FWD_DEFINED__
typedef interface IDistributionStore IDistributionStore;
#endif 	/* __IDistributionStore_FWD_DEFINED__ */

#ifndef __IDistributionStore_INTERFACE_DEFINED__
#define __IDistributionStore_INTERFACE_DEFINED__

//	SQLDistributionStore's CLSID
// {16D9A8E2-C326-11d0-94E9-00C04FC2DB9C}
DEFINE_GUID(CLSID_SQLDistribution, 
0x16d9a8e2, 0xc326, 0x11d0, 0x94, 0xe9, 0x0, 0xc0, 0x4f, 0xc2, 0xdb, 0x9c);

 // {63797CA0-9684-11d0-94DD-00C04FC2DB9C}
DEFINE_GUID(IID_IDistributionStore, 
0x63797ca0, 0x9684, 0x11d0, 0x94, 0xdd, 0x0, 0xc0, 0x4f, 0xc2, 0xdb, 0x9c);

// {074EACFD-A791-11d0-94E0-00C04FC2DB9C}
DEFINE_GUID(IID_IDistributionLog, 
0x74eacfd, 0xa791, 0x11d0, 0x94, 0xe0, 0x0, 0xc0, 0x4f, 0xc2, 0xdb, 0x9c);

typedef DWORD DISTCMDTYPE;

class DistByteArray 
{
private:
	BYTE rgDistByteArray[16];
public:
	DistByteArray(){memset(rgDistByteArray, 0, sizeof(rgDistByteArray));}
	~DistByteArray(){}

	BYTE* operator& ()
	{
		return rgDistByteArray;
	}

	// Pre-increment
	DistByteArray& operator++ ()
	{
		return Increment();
	}

	// Post-increment
	DistByteArray& operator++ (int dummy)
	{
		return Increment();
	}

	DistByteArray& Increment()
	{
		for (int i=sizeof(rgDistByteArray)-1; i>=0; i--)
		{
			UCHAR *pByte = ((UCHAR *) rgDistByteArray + i);
			if (0xFF == *pByte)
			{
				*pByte = 0;
				continue;
			}
			else
			{
				(*pByte)++;
				break;
			}
		}
		return *this;
	}
};

enum DISTCMDTYPEENUM
    {	
	DISTCMDTYPE_SQL	= 1,
	DISTCMDTYPE_SCRIPT = 2,
	DISTCMDTYPE_NATIVE_BCP = 3,
	DISTCMDTYPE_CHAR_BCP = 4,
	DISTCMDTYPE_SQL_WORKINGDIR = 7
    };

typedef struct  tagDISTCOMMANDDESC
    {
    INT		PublicationId;
    INT		ArticleId;
	INT		CommandId;
	DISTCMDTYPE	CommandType;
	BOOL	fPartialCommand;
	LPSTR	szCommand;
	BYTE*	pXactId;
	BYTE*	pXactSeqno;
	LPSTR	szOriginator;
	LPSTR	szOriginatorDB;
    }	DISTCOMMANDDESC;


// Error source type
typedef enum {
	DIST_SOURCE_NULL		= 0,
	DIST_SOURCE_COMMAND		= 1,
	DIST_SOURCE_AGENT		= 2,
	DIST_SOURCE_OS			= 3,
	DIST_SOURCE_ODBC		= 4,
	DIST_SOURCE_SQLSERVER	= 5
} DISTERRSRCTYPE;


typedef struct  tagDISTERRORDESC
    {
    DISTERRSRCTYPE		SourceType; 
	CHAR				szSourceName[31]; 
	CHAR				szErrorCode[31];
	BSTR				bstrErrorText;
    }	DISTERRORDESC;

typedef DWORD DISTLOGSTATUS;

enum DISTLOGSTATUSENUM
    {	
	DISTLOG_STARTUP = 1,
	DISTLOG_SUCCESS = 2,
	DISTLOG_INPROGRESS = 3,
	DISTLOG_IDLE = 4,
	DISTLOG_RETRY = 5,
	DISTLOG_FAILURE = 6
    };

typedef BYTE DISTAPPTYPE;

enum DISTTYPEENUM
    {	
	DISTTYPE_SNAPSHOT = 0,
	DISTTYPE_LOGREADER = 1
    };


enum DISTPROPENUM  
    {	DBPROP_INIT_PUBLISHER_NAME = 0xFF1,
		DBPROP_INIT_PUBLISHER_DATASOURCE = 0xFF2,
		DBPROP_INIT_XACTID_SIZE = 0xFF3,
		DBPROP_INIT_XACT_SEQNO_SIZE = 0xFF4,
		DBPROP_PUBLICATION_NAME = 0xFF5,
		DBPROP_APPLICATION_NAME = 0xFF6,
		DBPROP_APPLICATION_TYPE = 0xFF7
    };

EXTERN_C const IID IID_IDistributionStore;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IDistributionStore : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Abort( void) = 0;
        virtual HRESULT STDMETHODCALLTYPE Commit( void) = 0;
        virtual HRESULT STDMETHODCALLTYPE GetLastTransaction(
			/* [out] */ BYTE* pXactId,
			/* [out] */ BYTE* pXactSeqno) = 0;
        virtual HRESULT STDMETHODCALLTYPE AddTransactionCommands( 
            /* [in] */ ULONG cCommandDescs,
            /* [size_is][in] */ const DISTCOMMANDDESC __RPC_FAR rgCommandDescs[  ]) = 0;
        virtual HRESULT STDMETHODCALLTYPE StartTransaction( void) = 0;
    };
    
#else 	/* C style interface */

    typedef struct IDistributionStoreVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDistributionStore __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDistributionStore __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDistributionStore __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Abort )( 
            IDistributionStore __RPC_FAR * This);

        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Commit )( 
            IDistributionStore __RPC_FAR * This);
        
		HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLastTransaction )( 
            IDistributionStore __RPC_FAR * This,
			/* [out] */ BYTE* pXactId,
			/* [out] */ BYTE* pXactSeqno);
        
		HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddTransactionCommands )( 
            IDistributionStore __RPC_FAR * This,
            /* [in] */ ULONG cCommandDescs,
            /* [size_is][in] */ const DISTCOMMANDDESC __RPC_FAR rgCommandDescs[  ]);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StartTransaction )( 
            IDistributionStore __RPC_FAR * This);

        END_INTERFACE
    } IDistributionStoreVtbl;

    interface IDistributionStore
    {
        CONST_VTBL struct IDistributionStoreVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS

#define IDistributionStore_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDistributionStore_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDistributionStore_Release(This)	\
    (This)->lpVtbl -> Release(This)

#define IDistributionStore_Abort(This)	\
    (This)->lpVtbl -> Abort(This)

#define IDistributionStore_Commit(This)	\
    (This)->lpVtbl -> Commit(This)

#define IDistributionStore_GetLastTransaction(This)	\
    (This)->lpVtbl -> GetLastTransaction(This, pXactId, pXactSeqno)

#define IDistributionStore_AddTransactionCommands(This)	\
    (This)->lpVtbl -> AddTransactionCommands(This, cCommandDescs, rgCommandDescs)

#define IDistributionStore_StartTransaction(This)	\
    (This)->lpVtbl -> StartTransaction(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IDistributionStore_Abort_Proxy( 
    IDistributionStore __RPC_FAR * This);


void __RPC_STUB IDistributionStore_Abort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);

HRESULT STDMETHODCALLTYPE IDistributionStore_Commit_Proxy( 
    IDistributionStore __RPC_FAR * This);


void __RPC_STUB IDistributionStore_Commit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDistributionStore_GetLastTransaction_Proxy( 
    IDistributionStore __RPC_FAR * This,
	BYTE* pXactId,
	BYTE* pXactSeqno);


void __RPC_STUB IDistributionStore_GetLastTransaction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDistributionStore_AddTransactionCommands_Proxy( 
    IDistributionStore __RPC_FAR * This,
    ULONG cCommandDescs,
    const DISTCOMMANDDESC __RPC_FAR rgCommandDescs[  ]);


void __RPC_STUB IDistributionStore_AddTransactionCommands_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDistributionStore_StartTransaction_Proxy( 
    IDistributionStore __RPC_FAR * This);


void __RPC_STUB IDistributionStore_StartTransaction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


#endif 	/* __IDistributionStore_INTERFACE_DEFINED__ */

#ifndef __IDistributionLog_FWD_DEFINED__
#define __IDistributionLog_FWD_DEFINED__
typedef interface IDistributionLog IDistributionLog;
#endif 	/* __IDistributionLog_FWD_DEFINED__ */

#ifndef __IDistributionLog_INTERFACE_DEFINED__
#define __IDistributionLog_INTERFACE_DEFINED__

EXTERN_C const IID IID_IDistributionLog;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IDistributionLog : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddLog( 
            /* [in] */ DWORD dwStatusId,
            /* [in] */ LPSTR szComment,
			/* [in] */ BYTE* pXactSeqno,
			/* [in] */ ULONG ulTransactions,
			/* [in] */ ULONG ulCommands,
            /* [in] */ ULONG cErrorDescs,
            /* [size_is][in] */ const DISTERRORDESC __RPC_FAR rgErrorDescs[  ]) = 0;
    };
    
#else 	/* C style interface */

    typedef struct IDistributionLogVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDistributionLog __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDistributionLog __RPC_FAR * This);
        
       	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddLog )( 
            IDistributionLog __RPC_FAR * This,
            /* [in] */ DWORD dwStatusId,
            /* [in] */ LPSTR szComment,
			/* [in] */ BYTE* pXactSeqno,
			/* [in] */ ULONG ulTransactions,
			/* [in] */ ULONG ulCommands,
            /* [in] */ ULONG cErrorDescs,
            /* [size_is][in] */ const DISTERRORDESC __RPC_FAR rgErrorDescs[  ]);
        
        END_INTERFACE
    } IDistributionLogVtbl;

    interface IDistributionLog
    {
        CONST_VTBL struct IDistributionLogVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS

#define IDistributionLog_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDistributionLog_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDistributionLog_Release(This)	\
    (This)->lpVtbl -> Release(This)

#define IDistributionLog_AddLog(This)	\
    (This)->lpVtbl -> AddLog(This, dwStatusId, szComment, pXactSeqno, cTransactions, cCommands, cErrorDescs, rgErrorDescs)

#endif /* COBJMACROS */


#endif 	/* C style interface */


HRESULT STDMETHODCALLTYPE IDistributionLog_AddLog_Proxy( 
    IDistributionLog __RPC_FAR * This,
	DWORD dwStatusId,
    LPSTR szComment,
	BYTE* pXactSeqno,
	ULONG ulTransactions,
	ULONG ulCommands,
    ULONG cErrorDescs,
    const DISTERRORDESC __RPC_FAR rgErrorDescs[  ]);


void __RPC_STUB IDistributionLog_AddLog_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);

#endif 	/* __IDistributionLog_INTERFACE_DEFINED__ */


#ifndef __IGetCustomErrorInfo_FWD_DEFINED__
#define __IGetCustomErrorInfo_FWD_DEFINED__
typedef interface IGetCustomErrorInfo IGetCustomErrorInfo ;
#endif 	/* __IGetCustomErrorInfo_FWD_DEFINED__ */


#ifndef __IGetCustomErrorInfo_INTERFACE_DEFINED__
#define __IGetCustomErrorInfo_INTERFACE_DEFINED__

// @msg IID_IGetCustomErrorInfo |  {D83B7C8D-F22F-11d0-9AE8-00C04FB6B6EF}
// Interface ID to the IGetCustomErrorInfo interface
DEFINE_GUID(IID_IGetCustomErrorInfo, 0xd83b7c8d, 0xf22f, 0x11d0, 0x9a, 0xe8, 0x0, 0xc0, 0x4f, 0xb6, 0xb6, 0xef);

// @msg CLSID_DistErrorLookup | {246CBC55-F3E8-11d0-9AEB-00C04FB6B6EF}
// ID of the Distribution Error Lookup Service class
DEFINE_GUID(CLSID_DistErrorLookup,0x246cbc55, 0xf3e8, 0x11d0, 0x9a, 0xeb, 0x0, 0xc0, 0x4f, 0xb6, 0xb6, 0xef);


EXTERN_C const IID IID_IGetCustomErrorInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IGetCustomErrorInfo : public IUnknown
    {
    public:
		virtual HRESULT STDMETHODCALLTYPE GetCustomErrorInfo(DISTERRORDESC * pDistErrorDesc) = 0;
    };
    
#else 	/* C style interface */

    typedef struct IGetCustomErrorInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGetCustomErrorInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGetCustomErrorInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGetCustomErrorInfo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCustomErrorInfo )( 
            IGetCustomErrorInfo __RPC_FAR * This,
			/* out */ REPL_ERROR * pReplError);
        
        END_INTERFACE
    } IGetCustomErrorInfoVtbl;

    interface IGetCustomErrorInfo
    {
        CONST_VTBL struct IGetCustomErrorInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGetCustomErrorInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGetCustomErrorInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGetCustomErrorInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)

#define IGetCustomErrorInfo_GetCustomErrorInfo(This,pReplError)	\
    (This)->lpVtbl -> GetCustomErrorInfo(This,pReplError)

#endif /* COBJMACROS */


#endif 	/* C style interface */

#endif 	/* __IGetCustomErrorInfo_INTERFACE_DEFINED__ */

#endif // _REPLDIST_H_
