/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Aug 06 01:26:58 2000
 */
/* Compiler settings for q:\SPHINX\SQLREPL\SQLINITX\sqlinitx.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_ISQLSnapshot = {0xE02C121C,0xC12A,0x11d2,{0xB6,0xDB,0x00,0xC0,0x4F,0x68,0x8E,0x8F}};


const IID LIBID_SQLINITXLib = {0xE02C121D,0xC12A,0x11d2,{0xB6,0xDB,0x00,0xC0,0x4F,0x68,0x8E,0x8F}};


const IID DIID__SQLSnapshotEvents = {0xE02C121E,0xC12A,0x11d2,{0xB6,0xDB,0x00,0xC0,0x4F,0x68,0x8E,0x8F}};


const CLSID CLSID_SQLSnapshot = {0xE02C121F,0xC12A,0x11d2,{0xB6,0xDB,0x00,0xC0,0x4F,0x68,0x8E,0x8F}};


#ifdef __cplusplus
}
#endif

