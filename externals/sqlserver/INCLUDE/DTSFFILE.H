//
// DTSFFile.h
//	Header file for the OLEDB DTSFlatFile Service Provider.
//	Copyright 1997 Microsoft Corporation
//
#ifndef DTSFlatFile_H_
#define DTSFlatFile_H_

#ifndef UNICODE_BOM
	#define UNICODE_BOM  0xFEFF
#endif

#ifndef DTSFlatFileVersion_Major
	#define DTSFlatFileVersion_Major 1
	#define DTSFlatFileVersion_Minor 0
#endif // DTSFlatFileVersion_Major

///////////////////////////////////////////////////////////////////////////////////////
// CPP Enumerations, constants, and data structures.
///////////////////////////////////////////////////////////////////////////////////////

#define FF_ENUM_BEGIN(tdef, hstring)	DWORD tdef, *LP##tdef; enum tag##tdef
	// item = value, ...
#define FF_ENUM_END(tdef)				

typedef FF_ENUM_BEGIN(DTSFlatFileError, "Error ranges for DTSFlatFile execution") {
	DTSFlatFile_E_InvalidColumnFlags			= 0x3000,
	DTSFlatFile_E_DuplicateColumnName			= 0x3001,
	DTSFlatFile_E_LinkFileColumnNoSelfRef		= 0x3002,
	DTSFlatFile_E_LinkFileColumnNotFound		= 0x3003,
	DTSFlatFile_E_OnlyOneSession				= 0x3004,
	DTSFlatFile_E_OnlyOneRowset					= 0x3005,
	DTSFlatFile_E_ColumnOutOfRange				= 0x3006,
	DTSFlatFile_E_NoBindPart					= 0x3007,
	DTSFlatFile_E_CantConvert					= 0x3008,
	DTSFlatFile_E_ByrefNotOnFixedDatatypes		= 0x3009,
	DTSFlatFile_E_RowDelimiterNotFound			= 0x300a,
	DTSFlatFile_E_NoUpdatability				= 0x300b,
	DTSFlatFile_E_RowRefCountNotZero			= 0x300c,
	DTSFlatFile_E_FileInfoIncomplete			= 0x300d,
	DTSFlatFile_E_NumberOfColumnConflict		= 0x300e,
	DTSFlatFile_E_ZeroColumnLength				= 0x300f,
	DTSFlatFile_E_GetConvSizeFail				= 0x3010,
	DTSFlatFile_E_ColumnDelimiterNotFound		= 0x3011,
	DTSFlatFile_E_TextQualifierNotFound			= 0x3012,
	DTSFlatFile_E_TooManyColumnFound			= 0x3013,
	DTSFlatFile_E_NoColDelimTextQualAllowed		= 0x3014,
	DTSFlatFile_E_InvalidDelimitedData			= 0x3015,
	DTSFlatFile_E_InvalidBracketing				= 0x3016,
	DTSFlatFile_E_EmptyDataFile					= 0x3017,

} FF_ENUM_END(DTSFlatFileError);

typedef FF_ENUM_BEGIN(DTSFlatFileColumnFlags, "Flags for DTSFlatFile column metadata") {
	DTSFlatFileColumn_None						= 0x0000,

	// Column data flags.
	DTSFlatFileColumn_Nullable					= 0x0001,
	DTSFlatFileColumn_IsLong					= 0x0002,

	// Column behaviour flags.
	DTSFlatFileColumn_SkipOnRead				= 0x1001,
	DTSFlatFileColumn_AppendToFile				= 0x1002,

} FF_ENUM_END(DTSFlatFileColumnFlags);

#define DBPROP_DTS_ROWDELIMITER					0x10000001
#define DBPROP_DTS_FILEFORMAT					0x10000002
#define DBPROP_DTS_FIXEDFIELD_LENGTHS			0x10000003	
#define DBPROP_DTS_COLUMNDELIMITER				0x10000004
#define DBPROP_DTS_COLUMNMETADATA				0x10000005
#define DBPROP_DTS_FILETYPE						0x10000006
#define DBPROP_DTS_NUMBEROFCOLUMNS				0x10000007
#define DBPROP_DTS_TEXTQUALIFIER				0x10000008
#define DBPROP_DTS_SKIPROWS						0x10000009
#define DBPROP_DTS_FIRSTROWCOLUMNNAME			0x1000000a
#define DBPROP_DTS_COLUMNNAMES					0x1000000b
#define DBPROP_DTS_TEXTQUALIFIER_COLMASK		0x1000000c
#define DBPROP_DTS_XML_ROOT_ELEMENT				0x1000000d
#define DBPROP_DTS_XML_ROW_ELEMENT				0x1000000e
#define DBPROP_DTS_MAX_DELIM_COLWIDTH			0x1000000f
#define DBPROP_DTS_BLOB_COLMASK					0x10000010

#define DBPROPVAL_DTS_FILEFORMAT_NONE			0x0000
#define DBPROPVAL_DTS_FILEFORMAT_DELIMITED		0x0001
#define DBPROPVAL_DTS_FILEFORMAT_FIXEDLENGTH	0x0002
#define DBPROPVAL_DTS_FILEFORMAT_PREFIXLENGTH	0x0003
#define DBPROPVAL_DTS_FILEFORMAT_XML			0x0004

#define DBPROPVAL_DTS_FILETYPE_ASCII			0x0001
#define DBPROPVAL_DTS_FILETYPE_UNICODE			0x0002
#define DBPROPVAL_DTS_FILETYPE_AUTODETECT		0x0003
#define DBPROPVAL_DTS_FILETYPE_OEM				0x0004

#define FILE_ATTRIBUTE_READ						0x0000
#define FILE_ATTRIBUTE_WRITE					0x0001
#define FILE_ATTRIBUTE_APPEND					0x0002
#define FILE_ATTRIBUTE_WRITEABLE				0x0003

#ifdef NONAMELESSUNION
#define FF_UNION_NAME(u)	u
#else
#define FF_UNION_NAME(u)
#endif

// Metadata structure.  Metafile representation is keyed on field name and text value.
typedef struct {
	LPCOLESTR wzName;					// Name of the field (column).
	DBTYPE dbType;						// Field datatype
	union {
		ULONG ulLength;					// Field data length (byte length, or char length
										// for [W]STR).  Ignored for fixed-length types.
		struct {
			BYTE bPrecision;			// Numeric precision
			BYTE bScale;				// Numeric scale
		} FF_UNION_NAME(p);
	} FF_UNION_NAME(u);
	LPOLESTR wzDelimiter;				// Delimiter for [W]STR column.
	LPOLESTR wzTextQualifier;			// Text Qualifer
	DBTYPE dbLengthPrefixType;			// DBTYPE_I[124] dynamic length prefix for [W]STR|BYTES column;
										// ignored otherwise or if DBTYPE_EMPTY
	LPCOLESTR wzLinkFileColumnName;		// Name of column (field) containing file name to read from or
										// write to for [W]STR|BYTES column; ignored otherwise or if NULL.
	DTSFlatFileColumnFlags dtsFlags;	// Column flags from enum
	LPCOLESTR wzNullValue;				// Char representation of NULL value (e.g. NULL, "-0-",
										// 0xFFFFFF7F, etc.).  Converted to column datatype.
} DTSFlatFileColumnMetadata, *LPDTSFlatFileColumnMetadata;
typedef DTSFlatFileColumnMetadata const * LPCDTSFlatFileColumnMetadata;
										
// DTSFlatFileMetadata.wzDatafileName allows applications to SetMetafile and then GetMetadata 
// to retrieve the datafile name.  This is useful if the metafile is specific to a single 
// datafile; otherwise, it can function as metadata for multiple datafiles.  In any case, 
// an application must set the DBPROP_INIT_DATASOURCE property to the datafile name, which must 
// match wzDatafileName if wzDatafileName is non-NULL.

typedef struct {
	BOOL	 bUnicode;					// Unicode or OEM File 
	BOOL	 bFirstRowColumnName;		// First Row contains column name
	LPOLESTR wzRowDelimiter;			// Row Delimiter.
	LPOLESTR wzDefaultColDelimiter;		// Default Column Delimiter.
	LPOLESTR wzDefaultTextQualifier;	// Default Text Qualifer.
	LPOLESTR wzDataFileName;			// UNC or fully-qualified filename.
	LPOLESTR wzRootElementName;			// XML root element name.
	LPOLESTR wzRowElementName;			// XML element collection object name.
	ULONG cColumns;
	ULONG cSkipRows;
	LPDTSFlatFileColumnMetadata pColumnMetadata;
} DTSFlatFileMetadata, *LPDTSFlatFileMetadata;
typedef DTSFlatFileMetadata const * LPCDTSFlatFileMetadata;


///////////////////////////////////////////////////////////////////////////////////////
// Class and IID definitions
///////////////////////////////////////////////////////////////////////////////////////

// Include <initguid.h> to define ownership of these GUIDs.
// {xxxxxxxx-0224-11d1-B7B8-00C04FB6EFD5}
#define DEFINE_DTSFlatFileGUID(name, lval) \
	DEFINE_GUID(name, 0x##lval, 0x224, 0x11d1, 0xb7, 0xb8, 0x0, 0xc0, 0x4f, 0xb6, 0xef, 0xd5);

// DTSFlatFile DataSourceObject CLSID.
#define Progid_DTSFlatFile			OLESTR("DTSFlatFile")
DEFINE_DTSFlatFileGUID(CLSID_DTSFlatFile, 10010100)

// DTSFlatFile metadata interface IID.
DEFINE_DTSFlatFileGUID(IID_IDTSFlatFileMetadata, 10010200)

///////////////////////////////////////////////////////////////////////////////////////
// Interface definitions
///////////////////////////////////////////////////////////////////////////////////////

// Repeat the IUnknown members because C doesn't provide inheritance.
#ifndef DTSFlatFile_Unknown_Base
#define DTSFlatFile_Unknown_Base()															\
		STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID * ppvObj) PURE;				\
		STDMETHOD_(ULONG,AddRef) (THIS) PURE;												\
		STDMETHOD_(ULONG,Release) (THIS) PURE;
#endif

#undef INTERFACE
#define INTERFACE IDTSFlatFileMetadata
DECLARE_INTERFACE_(INTERFACE, IUnknown)
{
	DTSFlatFile_Unknown_Base()

	STDMETHOD(GetMetadata)(THIS_
            /* [size_is][size_is][out] */ DTSFlatFileMetadata __RPC_FAR * __RPC_FAR *ppMetadata
		) PURE;
	STDMETHOD(UninitializeMetadata)(THIS_ 
		) PURE;
	STDMETHOD(SetMetadata)(THIS_
            /* [size_is][in] */ const DTSFlatFileMetadata __RPC_FAR *pMetadata
		) PURE;
	STDMETHOD(SetMetafile)(THIS_
			/* [string][in] */ const OLECHAR __RPC_FAR *wzFileName
		) PURE;
};

#endif // DTSFlatFile_H_
