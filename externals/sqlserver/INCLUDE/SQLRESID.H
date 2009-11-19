/////////////////////////////////////////////////////////////////////////////////////////
// Header file for Replication Custom Resolver Component Object Interface IIDs.
// Copyright 1994-1997 Microsoft Corporation.
/////////////////////////////////////////////////////////////////////////////////////////
 #ifndef SQLRESID_H_
#define SQLRESID_H_

// {FC2F91C1-1CA2-11d0-A11B-00AA003E4672}
DEFINE_GUID(IID_ICustomResolver, 0xfc2f91c1, 0x1ca2, 0x11d0, 0xa1, 0x1b, 0x0, 0xaa, 0x0, 0x3e, 0x46, 0x72);

// {FC2F91C2-1CA2-11d0-A11B-00AA003E4672}
DEFINE_GUID(IID_IReplRowChange, 0xfc2f91c2, 0x1ca2, 0x11d0, 0xa1, 0x1b, 0x0, 0xaa, 0x0, 0x3e, 0x46, 0x72);

// {37E95A52-1CA3-11d0-A11B-00AA003E4672}
DEFINE_GUID(IID_IConnectionInfo, 0x37e95a52, 0x1ca3, 0x11d0, 0xa1, 0x1b, 0x0, 0xaa, 0x0, 0x3e, 0x46, 0x72);

// {AEF21081-CD22-11d2-A8E8-00C04F9FC436}
DEFINE_GUID(CATID_MSSQLConflictResolvers, 0xaef21081, 0xcd22, 0x11d2, 0xa8, 0xe8, 0x0, 0xc0, 0x4f, 0x9f, 0xc4, 0x36);

// {AEF21082-CD22-11d2-A8E8-00C04F9FC436}
DEFINE_GUID(CATID_MSSQLInteractiveConflictResolvers, 0xaef21082, 0xcd22, 0x11d2, 0xa8, 0xe8, 0x0, 0xc0, 0x4f, 0x9f, 0xc4, 0x36);

#define REPOLE_S_CATEGORY_MSSQLCONFLICTRESOLVERS L"SQL Server Conflict Resolvers"
#define REPOLE_S_CATEGORY_MSSQLINTERACTCONFLICTRESOLVERS L"SQL Server Interactive Conflict Resolvers"

#endif /* SQLRESID_H_ */



