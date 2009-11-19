
#ifndef __IFX_H_
#define __IFX_H_

#define OBJID_TYPELIB_IFX L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},00000003}"



#define OBJID_IfxServer L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},0000000B}"
#define OBJID_IfxDatabase L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},0000000C}"
#define OBJID_IfxTable L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},0000000D}"
#define OBJID_IfxIndex L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},0000000E}"
#define OBJID_IfxBlobColumn L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},0000000F}"
#define OBJID_IfxSpace L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},00000010}"
#define OBJID_IfxProcedure L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},00000011}"
#define OBJID_IfxFragment L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},0000007F}"
#define OBJID_IfxStorage L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},00000080}"
#define OBJID_IfxSlice L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},00000081}"
#define OBJID_IfxConnection L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},00000090}"
#define OBJID_IfxVarChar L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},0000002F}"
#define OBJID_IfxNVarChar L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},00000030}"
#define DISPID_IIfxServer_Version 18000
#define DISPID_IIfxServer_Options 18001
#define DISPID_IIfxServer_NumCoservers 18002
#define DISPID_IIfxServer_Locale 18003
#define IOID_IIfxServer L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},00000004}"
DEFINE_GUID(IID_IIfxServer,
0x94fd5c09, 0x4c06, 0x11d2, 0x8a, 0x46, 0x00, 0xc0, 0x4f, 0x8e, 0xc0, 0x30);

#define DISPID_IIfxDatabase_Owner 18004
#define DISPID_IIfxDatabase_LogMode 18005
#define DISPID_IIfxDatabase_IsNls 18006
#define DISPID_IIfxDatabase_Locale 18007
#define DISPID_IIfxDatabase_Space 18026
#define DISPID_IIfxDatabase_Database 18027
#define IOID_IIfxDatabase L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},00000005}"
DEFINE_GUID(IID_IIfxDatabase,
0x94fd5c0a, 0x4c06, 0x11d2, 0x8a, 0x46, 0x00, 0xc0, 0x4f, 0x8e, 0xc0, 0x30);

#define DISPID_IIfxTable_LockMode 18008
#define DISPID_IIfxTable_Type 18009
#define DISPID_IIfxTable_Fragment 18028
#define DISPID_IIfxTable_Table 18029
#define IOID_IIfxTable L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},00000006}"
DEFINE_GUID(IID_IIfxTable,
0x94fd5c0b, 0x4c06, 0x11d2, 0x8a, 0x46, 0x00, 0xc0, 0x4f, 0x8e, 0xc0, 0x30);

#define DISPID_IIfxIndex_Mode 18010
#define DISPID_IIfxIndex_IsBitMap 18011
#define DISPID_IIfxIndex_IsGKIndex 18012
#define DISPID_IIfxIndex_GKSelectClause 18013
#define DISPID_IIfxIndex_AttachType 18014
#define DISPID_IIfxIndex_Fragment 18030
#define DISPID_IIfxIndex_Index 18031
#define IOID_IIfxIndex L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},00000007}"
DEFINE_GUID(IID_IIfxIndex,
0x94fd5c0c, 0x4c06, 0x11d2, 0x8a, 0x46, 0x00, 0xc0, 0x4f, 0x8e, 0xc0, 0x30);

#define DISPID_IIfxBlobColumn_Space 18032
#define DISPID_IIfxBlobColumn_Column 18033
#define IOID_IIfxBlobColumn L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},00000008}"
DEFINE_GUID(IID_IIfxBlobColumn,
0x94fd5c0d, 0x4c06, 0x11d2, 0x8a, 0x46, 0x00, 0xc0, 0x4f, 0x8e, 0xc0, 0x30);

#define DISPID_IIfxSpace_Type 18015
#define DISPID_IIfxSpace_IsTemp 18016
#define DISPID_IIfxSpace_Space 18032
#define DISPID_IIfxSpace_Column 18033
#define DISPID_IIfxSpace_Slice 18035
#define DISPID_IIfxSpace_Database 18027
#define IOID_IIfxSpace L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},00000009}"
DEFINE_GUID(IID_IIfxSpace,
0x94fd5c0e, 0x4c06, 0x11d2, 0x8a, 0x46, 0x00, 0xc0, 0x4f, 0x8e, 0xc0, 0x30);

#define DISPID_IIfxProcedure_IsDBA 18017
#define IOID_IIfxProcedure L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},0000000A}"
DEFINE_GUID(IID_IIfxProcedure,
0x94fd5c0f, 0x4c06, 0x11d2, 0x8a, 0x46, 0x00, 0xc0, 0x4f, 0x8e, 0xc0, 0x30);

#define DISPID_IIfxFragment_Strategy 18018
#define DISPID_IIfxFragment_Expression 18019
#define DISPID_IIfxFragment_Storage 18036
#define DISPID_IIfxFragment_Fragment 18037
#define DISPID_IIfxFragment_Table 18029
#define DISPID_IIfxFragment_Index 18031
#define IOID_IIfxFragment L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},0000006A}"
DEFINE_GUID(IID_IIfxFragment,
0x6c91ed38, 0x62d9, 0x11d2, 0x8a, 0x48, 0x00, 0xc0, 0x4f, 0x8e, 0xc0, 0x30);

#define DISPID_IIfxStorage_Storage 18036
#define DISPID_IIfxStorage_Fragment 18037
#define IOID_IIfxStorage L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},0000006E}"
DEFINE_GUID(IID_IIfxStorage,
0x6c91ed39, 0x62d9, 0x11d2, 0x8a, 0x48, 0x00, 0xc0, 0x4f, 0x8e, 0xc0, 0x30);

#define DISPID_IIfxSlice_Space 18034
#define DISPID_IIfxSlice_Slice 18035
#define IOID_IIfxSlice L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},0000006F}"
DEFINE_GUID(IID_IIfxSlice,
0x6c91ed3a, 0x62d9, 0x11d2, 0x8a, 0x48, 0x00, 0xc0, 0x4f, 0x8e, 0xc0, 0x30);

#define DISPID_IIfxConnection_HostName 18020
#define DISPID_IIfxConnection_Protocol 18021
#define DISPID_IIfxConnection_PortNumber 18022
#define DISPID_IIfxConnection_ServiceName 18023
#define IOID_IIfxConnection L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},0000008B}"
DEFINE_GUID(IID_IIfxConnection,
0xb4e583e8, 0x7f7a, 0x11d2, 0xb7, 0xf8, 0x00, 0xc0, 0x4f, 0x8e, 0xf2, 0x96);

#define DISPID_IIfxVarChar_Reserve 18024
#define IOID_IIfxVarChar L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},0000002C}"
DEFINE_GUID(IID_IIfxVarChar,
0x94fd5c23, 0x4c06, 0x11d2, 0x8a, 0x46, 0x00, 0xc0, 0x4f, 0x8e, 0xc0, 0x30);

#define DISPID_IIfxNVarChar_Reserve 18025
#define IOID_IIfxNVarChar L"{{94FD5C06-4C06-11d2-8A46-00C04F8EC030},0000002D}"
DEFINE_GUID(IID_IIfxNVarChar,
0x94fd5c24, 0x4c06, 0x11d2, 0x8a, 0x46, 0x00, 0xc0, 0x4f, 0x8e, 0xc0, 0x30);


#endif // __IFX_H_
