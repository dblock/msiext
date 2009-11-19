/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Aug 06 00:28:30 2000
 */
/* Compiler settings for q:\SPHINX\SQLREPL\common\inc\replerrx.idl:
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

const IID IID_ISQLReplError = {0x35CE087C,0x2E4E,0x11D2,{0xB6,0xD4,0x00,0xC0,0x4F,0xB9,0x3D,0x6B}};


const IID IID_ISQLReplErrors = {0x35CE087B,0x2E4E,0x11D2,{0xB6,0xD4,0x00,0xC0,0x4F,0xB9,0x3D,0x6B}};


const IID LIBID_REPLERRXLib = {0x08b0b2e9,0x3fb3,0x11d3,{0xa4,0xde,0x00,0xc0,0x4f,0x61,0x01,0x89}};


const IID DIID__ReplErrorEvents = {0x2A744FF0,0xEEB0,0x11d2,{0xA0,0x02,0x00,0x80,0xC7,0xFD,0xD2,0x6E}};


const CLSID CLSID_SQLReplErrors = {0x08b0b2ea,0x3fb3,0x11d3,{0xa4,0xde,0x00,0xc0,0x4f,0x61,0x01,0x89}};


const CLSID CLSID_SQLReplError = {0x08b0b2eb,0x3fb3,0x11d3,{0xa4,0xde,0x00,0xc0,0x4f,0x61,0x01,0x89}};


#ifdef __cplusplus
}
#endif

