
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 5.03.0266 */
/* at Mon May 24 02:08:48 1999
 */
/* Compiler settings for msdadc.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32 (32b run), ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
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

#ifndef __msdadc_h__
#define __msdadc_h__

/* Forward Declarations */ 

#ifndef __IDataConvert_FWD_DEFINED__
#define __IDataConvert_FWD_DEFINED__
typedef interface IDataConvert IDataConvert;
#endif 	/* __IDataConvert_FWD_DEFINED__ */


#ifndef __IDCInfo_FWD_DEFINED__
#define __IDCInfo_FWD_DEFINED__
typedef interface IDCInfo IDCInfo;
#endif 	/* __IDCInfo_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "oledb.h"

#ifdef __cplusplus
extern "C"{
#endif 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_msdadc_0000 */
/* [local] */ 

#undef OLEDBDECLSPEC
#if _MSC_VER >= 1100
#define OLEDBDECLSPEC __declspec(selectany)
#else
#define OLEDBDECLSPEC 
#endif //_MSC_VER


extern RPC_IF_HANDLE __MIDL_itf_msdadc_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_msdadc_0000_v0_0_s_ifspec;

#ifndef __IDataConvert_INTERFACE_DEFINED__
#define __IDataConvert_INTERFACE_DEFINED__

/* interface IDataConvert */
/* [unique][helpstring][uuid][object] */ 

typedef DWORD DBDATACONVERT;


enum DBDATACONVERTENUM
    {	DBDATACONVERT_DEFAULT	= 0,
	DBDATACONVERT_SETDATABEHAVIOR	= 0x1,
	DBDATACONVERT_LENGTHFROMNTS	= 0x2,
	DBDATACONVERT_DSTISFIXEDLENGTH	= 0x4
    };

EXTERN_C const IID IID_IDataConvert;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a8d-2a1c-11ce-ade5-00aa0044773d")
    IDataConvert : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE DataConvert( 
            /* [in] */ DBTYPE wSrcType,
            /* [in] */ DBTYPE wDstType,
            /* [in] */ DBLENGTH cbSrcLength,
            /* [out][in] */ DBLENGTH __RPC_FAR *pcbDstLength,
            /* [in] */ void __RPC_FAR *pSrc,
            /* [out] */ void __RPC_FAR *pDst,
            /* [in] */ DBLENGTH cbDstMaxLength,
            /* [in] */ DBSTATUS dbsSrcStatus,
            /* [out] */ DBSTATUS __RPC_FAR *pdbsStatus,
            /* [in] */ BYTE bPrecision,
            /* [in] */ BYTE bScale,
            /* [in] */ DBDATACONVERT dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CanConvert( 
            /* [in] */ DBTYPE wSrcType,
            /* [in] */ DBTYPE wDstType) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetConversionSize( 
            /* [in] */ DBTYPE wSrcType,
            /* [in] */ DBTYPE wDstType,
            /* [in] */ DBLENGTH __RPC_FAR *pcbSrcLength,
            /* [out] */ DBLENGTH __RPC_FAR *pcbDstLength,
            /* [size_is][in] */ void __RPC_FAR *pSrc) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDataConvertVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDataConvert __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDataConvert __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDataConvert __RPC_FAR * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DataConvert )( 
            IDataConvert __RPC_FAR * This,
            /* [in] */ DBTYPE wSrcType,
            /* [in] */ DBTYPE wDstType,
            /* [in] */ DBLENGTH cbSrcLength,
            /* [out][in] */ DBLENGTH __RPC_FAR *pcbDstLength,
            /* [in] */ void __RPC_FAR *pSrc,
            /* [out] */ void __RPC_FAR *pDst,
            /* [in] */ DBLENGTH cbDstMaxLength,
            /* [in] */ DBSTATUS dbsSrcStatus,
            /* [out] */ DBSTATUS __RPC_FAR *pdbsStatus,
            /* [in] */ BYTE bPrecision,
            /* [in] */ BYTE bScale,
            /* [in] */ DBDATACONVERT dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CanConvert )( 
            IDataConvert __RPC_FAR * This,
            /* [in] */ DBTYPE wSrcType,
            /* [in] */ DBTYPE wDstType);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetConversionSize )( 
            IDataConvert __RPC_FAR * This,
            /* [in] */ DBTYPE wSrcType,
            /* [in] */ DBTYPE wDstType,
            /* [in] */ DBLENGTH __RPC_FAR *pcbSrcLength,
            /* [out] */ DBLENGTH __RPC_FAR *pcbDstLength,
            /* [size_is][in] */ void __RPC_FAR *pSrc);
        
        END_INTERFACE
    } IDataConvertVtbl;

    interface IDataConvert
    {
        CONST_VTBL struct IDataConvertVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDataConvert_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDataConvert_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDataConvert_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDataConvert_DataConvert(This,wSrcType,wDstType,cbSrcLength,pcbDstLength,pSrc,pDst,cbDstMaxLength,dbsSrcStatus,pdbsStatus,bPrecision,bScale,dwFlags)	\
    (This)->lpVtbl -> DataConvert(This,wSrcType,wDstType,cbSrcLength,pcbDstLength,pSrc,pDst,cbDstMaxLength,dbsSrcStatus,pdbsStatus,bPrecision,bScale,dwFlags)

#define IDataConvert_CanConvert(This,wSrcType,wDstType)	\
    (This)->lpVtbl -> CanConvert(This,wSrcType,wDstType)

#define IDataConvert_GetConversionSize(This,wSrcType,wDstType,pcbSrcLength,pcbDstLength,pSrc)	\
    (This)->lpVtbl -> GetConversionSize(This,wSrcType,wDstType,pcbSrcLength,pcbDstLength,pSrc)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [local] */ HRESULT STDMETHODCALLTYPE IDataConvert_DataConvert_Proxy( 
    IDataConvert __RPC_FAR * This,
    /* [in] */ DBTYPE wSrcType,
    /* [in] */ DBTYPE wDstType,
    /* [in] */ DBLENGTH cbSrcLength,
    /* [out][in] */ DBLENGTH __RPC_FAR *pcbDstLength,
    /* [in] */ void __RPC_FAR *pSrc,
    /* [out] */ void __RPC_FAR *pDst,
    /* [in] */ DBLENGTH cbDstMaxLength,
    /* [in] */ DBSTATUS dbsSrcStatus,
    /* [out] */ DBSTATUS __RPC_FAR *pdbsStatus,
    /* [in] */ BYTE bPrecision,
    /* [in] */ BYTE bScale,
    /* [in] */ DBDATACONVERT dwFlags);


void __RPC_STUB IDataConvert_DataConvert_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDataConvert_CanConvert_Proxy( 
    IDataConvert __RPC_FAR * This,
    /* [in] */ DBTYPE wSrcType,
    /* [in] */ DBTYPE wDstType);


void __RPC_STUB IDataConvert_CanConvert_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [local] */ HRESULT STDMETHODCALLTYPE IDataConvert_GetConversionSize_Proxy( 
    IDataConvert __RPC_FAR * This,
    /* [in] */ DBTYPE wSrcType,
    /* [in] */ DBTYPE wDstType,
    /* [in] */ DBLENGTH __RPC_FAR *pcbSrcLength,
    /* [out] */ DBLENGTH __RPC_FAR *pcbDstLength,
    /* [size_is][in] */ void __RPC_FAR *pSrc);


void __RPC_STUB IDataConvert_GetConversionSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDataConvert_INTERFACE_DEFINED__ */


#ifndef __IDCInfo_INTERFACE_DEFINED__
#define __IDCInfo_INTERFACE_DEFINED__

/* interface IDCInfo */
/* [unique][helpstring][uuid][object] */ 

typedef DWORD DCINFOTYPE;


enum DCINFOTYPEENUM
    {	DCINFOTYPE_VERSION	= 1
    };
typedef struct tagDCINFO
    {
    DCINFOTYPE eInfoType;
    VARIANT vData;
    }	DCINFO;


EXTERN_C const IID IID_IDCInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0c733a9c-2a1c-11ce-ade5-00aa0044773d")
    IDCInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetInfo( 
            /* [in] */ ULONG cInfo,
            /* [size_is][in] */ DCINFOTYPE __RPC_FAR rgeInfoType[  ],
            /* [size_is][out] */ DCINFO __RPC_FAR *__RPC_FAR *prgInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetInfo( 
            /* [in] */ ULONG cInfo,
            /* [size_is][in] */ DCINFO __RPC_FAR rgInfo[  ]) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDCInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDCInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDCInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDCInfo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInfo )( 
            IDCInfo __RPC_FAR * This,
            /* [in] */ ULONG cInfo,
            /* [size_is][in] */ DCINFOTYPE __RPC_FAR rgeInfoType[  ],
            /* [size_is][out] */ DCINFO __RPC_FAR *__RPC_FAR *prgInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetInfo )( 
            IDCInfo __RPC_FAR * This,
            /* [in] */ ULONG cInfo,
            /* [size_is][in] */ DCINFO __RPC_FAR rgInfo[  ]);
        
        END_INTERFACE
    } IDCInfoVtbl;

    interface IDCInfo
    {
        CONST_VTBL struct IDCInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDCInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDCInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDCInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDCInfo_GetInfo(This,cInfo,rgeInfoType,prgInfo)	\
    (This)->lpVtbl -> GetInfo(This,cInfo,rgeInfoType,prgInfo)

#define IDCInfo_SetInfo(This,cInfo,rgInfo)	\
    (This)->lpVtbl -> SetInfo(This,cInfo,rgInfo)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IDCInfo_GetInfo_Proxy( 
    IDCInfo __RPC_FAR * This,
    /* [in] */ ULONG cInfo,
    /* [size_is][in] */ DCINFOTYPE __RPC_FAR rgeInfoType[  ],
    /* [size_is][out] */ DCINFO __RPC_FAR *__RPC_FAR *prgInfo);


void __RPC_STUB IDCInfo_GetInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDCInfo_SetInfo_Proxy( 
    IDCInfo __RPC_FAR * This,
    /* [in] */ ULONG cInfo,
    /* [size_is][in] */ DCINFO __RPC_FAR rgInfo[  ]);


void __RPC_STUB IDCInfo_SetInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDCInfo_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_msdadc_0348 */
/* [local] */ 

extern const GUID OLEDBDECLSPEC IID_IDataConvert = { 0x0c733a8dL,0x2a1c,0x11ce, { 0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d } };
extern const GUID OLEDBDECLSPEC IID_IDCInfo = { 0x0c733a9cL,0x2a1c,0x11ce, { 0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d } };


extern RPC_IF_HANDLE __MIDL_itf_msdadc_0348_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_msdadc_0348_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long __RPC_FAR *, unsigned long            , VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long __RPC_FAR *, VARIANT __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


