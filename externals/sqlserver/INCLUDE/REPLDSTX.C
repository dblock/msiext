/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Aug 06 01:08:06 2000
 */
/* Compiler settings for q:\SPHINX\SQLREPL\SQLDISTX\sqldistx.idl:
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

const IID IID_ISQLDistribution = {0x9BD37E1C,0xBB55,0x11D0,{0x94,0xE7,0x00,0xC0,0x4F,0xC2,0xDB,0x9C}};


const IID LIBID_SQLDISTXLib = {0x08b0b2e5,0x3fb3,0x11d3,{0xa4,0xde,0x00,0xc0,0x4f,0x61,0x01,0x89}};


const IID DIID__SQLDistributionEvents = {0x05E219F6,0xBB55,0x11D0,{0x94,0xE7,0x00,0xC0,0x4F,0xC2,0xDB,0x9C}};


const CLSID CLSID_SQLDistribution = {0x08b0b2e6,0x3fb3,0x11d3,{0xa4,0xde,0x00,0xc0,0x4f,0x61,0x01,0x89}};


#ifdef __cplusplus
}
#endif

