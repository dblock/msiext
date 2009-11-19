//
// DTSPump.h
//	Header file for the OLEDB DTSDataPump Service Provider.
//	Copyright 1997 Microsoft Corporation
//
#ifndef DTSDataPump_H_
#define DTSDataPump_H_

#ifndef DTSDataPumpVersion_Major
	#define DTSDataPumpVersion_Major 2
	#define DTSDataPumpVersion_Minor 0
#endif // DTSDataPumpVersion_Major

#ifndef DTSDataPump_VersionOnly

// The default Blob size used in this version of the DataPump.
// May be overridden on a per-Transform or per-column basis.
#define DTS_DEFAULT_INMEMORY_BLOB_SIZE (1024 * 1024)

// Default number of successful InsertRows which will be Committed if supported by provider.
// Currently set to 0 which means not to do a commit until all rows have been transferred.
#define DTS_DEFAULT_InsertCommitSize	0

///////////////////////////////////////////////////////////////////////////////////////
// CPP and OleAut Enumerations and constants.
///////////////////////////////////////////////////////////////////////////////////////
#ifndef DTSDataPump_CONSTANTS_
#define DTSDataPump_CONSTANTS_

// To avoid the need to cast on bitwise operations (which defeats typesafety anyway),
// define the datatype as DWORD for C/CPP.  OleAut languages don't do typechecking
// and organize by the enum name.
#ifdef DTSDataPump_ODL_
	#define DP_ENUM_BEGIN(tdef, hstring)	[helpcontext(H_##tdef), helpstring(hstring)] enum tdef
		// item = value, ...
	#define DP_ENUM_END(tdef)				tdef, *LP##tdef
#else
	#define DP_ENUM_BEGIN(tdef, hstring)	DWORD tdef, *LP##tdef; enum tag##tdef
		// item = value, ...
	#define DP_ENUM_END(tdef)				
#endif

typedef DP_ENUM_BEGIN(DTSDataPumpError, "Error ranges for DTSDataPump execution") {
	DTSDataPump_E_NotImplemented				= 0x2000,
	DTSDataPump_E_RowsetsAlreadySet				= 0x2001,
	DTSDataPump_E_TransformsAlreadySet			= 0x2002,
	DTSDataPump_E_DestRowsetNotSupplied			= 0x2003,
	DTSDataPump_E_RowsetsNotSupplied			= 0x2004,
	DTSDataPump_E_SourceColumnsRequired			= 0x2005,
	DTSDataPump_E_ColCountButNoCols				= 0x2006,
	DTSDataPump_E_MismatchColOrdAndName			= 0x2007,
	DTSDataPump_E_ColumnNameNotFound			= 0x2008,
	DTSDataPump_E_ColumnOutOfRange				= 0x2009,
	DTSDataPump_E_DestColumnAlreadySpecified	= 0x200a,
	DTSDataPump_E_IDataConvertRequired			= 0x200b,
	DTSDataPump_E_NullVariantIUnknown			= 0x200c,
	DTSDataPump_E_NotReentrant					= 0x200d,
	DTSDataPump_E_RowsetChangeMustInsert		= 0x200e,
	DTSDataPump_E_DataPumpNotReentrant			= 0x200f,
	DTSDataPump_E_DestColumnReadOnly			= 0x2010,
	DTSDataPump_E_MustSpecifyDestOrTransform	= 0x2011,
	DTSDataPump_E_BadTransformFlag				= 0x2012,
	DTSDataPump_E_BadTransformStatusReturned	= 0x2013,
	DTSDataPump_E_TransformServerException		= 0x2014,
	DTSDataPump_E_CannotRebindColumn			= 0x2015,
	DTSDataPump_E_InvalidFetchBufferSize		= 0x2016,
	DTSDataPump_E_InvalidDTSBindMode			= 0x2017,
	DTSDataPump_E_SourceBlobBinding				= 0x2018,
	DTSDataPump_E_NonBlobStorageBind			= 0x2019,
	DTSDataPump_E_LookupDupName					= 0x201a,
	DTSDataPump_E_CannotTransformChapterColumns	= 0x201b,

	DTSDataPump_E_DestinationBlobBinding		= 0x2020,

	DTSDataPump_E_Copy_NeedSrcAndDestColumns	= 0x2024,
	DTSDataPump_E_Copy_ValidateSchemaError		= 0x2025,

	DTSDataPump_E_Convert_DestNotNull			= 0x2026,
	DTSDataPump_E_Convert_BadBindInfo			= 0x2027,
	DTSDataPump_E_Convert_DestOverflow			= 0x2028,
	DTSDataPump_E_Convert_SourceInvalidVariant	= 0x2029,
	DTSDataPump_E_Convert_SourceInvalidLength	= 0x202a,
	DTSDataPump_E_Convert_ConversionInvalid		= 0x202b,
	DTSDataPump_E_Convert_ConversionFailed		= 0x202c,
	DTSDataPump_E_Convert_ProviderOwnedTypeMismatch	= 0x202d,
	DTSDataPump_E_Convert_BlobStorageNoInterface	= 0x202e,

	DTSDataPump_E_AxScript_RequiredParams		= 0x2040,
	DTSDataPump_E_AxScript_ValidateSchemaError	= 0x2041,
	DTSDataPump_E_AxScript_ParseError			= 0x2042,
	DTSDataPump_E_AxScript_BadTransformFunction	= 0x2043,
	DTSDataPump_E_AxScript_CantChangeSrcCols	= 0x2044,
	DTSDataPump_E_AxScript_CantResetAfterInitialize	= 0x2045,
	DTSDataPump_E_AxScript_CantInitializeEngine	= 0x2046,
	DTSDataPump_E_AxScript_RunTimeError			= 0x2047,

	DTSDataPump_E_AutoBufferInterfaceNotSupported	= 0x2051,
	DTSDataPump_E_InvalidSpecifyBlobDefaults	= 0x2051,
	DTSDataPump_E_LineageVariableNotFound		= 0x2052,
	DTSDataPump_E_LastRowCantBeLessThanFirst	= 0x2053,

	DTSDataPump_E_DDQ_NeedTransformStatus		= 0x2060,
	DTSDataPump_E_DDQ_NeedInsertQuery			= 0x2061,
	DTSDataPump_E_DDQ_NeedUpdateQuery			= 0x2062,
	DTSDataPump_E_DDQ_NeedDeleteQuery			= 0x2063,
	DTSDataPump_E_DDQ_NeedUserQuery				= 0x2064,
	DTSDataPump_E_DDQ_InformationNotSet			= 0x2065,
	DTSDataPump_E_DDQ_BadTransformStatusContext	= 0x2065,
	DTSDataPump_E_DDQ_DestColumnNotTransformed	= 0x2066,
	DTSDataPump_E_DDQ_DestColumnNeedsLength		= 0x2067,
	DTSDataPump_E_DDQ_DestDoesNotSupportSQL		= 0x2068,
	DTSDataPump_E_DDQ_TransformStatusForced		= 0x2069,
	DTSDataPump_E_RowFailuresExceedLimit		= 0x206a,

	DTSDataPump_E_TransformString_NeedSrcAndDestColumns		= 0x2080,
	DTSDataPump_E_TransformString_ColumnCount				= 0x2081,
	DTSDataPump_E_TransformReadFile_NeedSrcAndDestColumns	= 0x2082,
	DTSDataPump_E_TransformString_ValidateSchemaError		= 0x2083,
	DTSDataPump_E_TransformString_DestStringTrunc			= 0x2084,

	DTSDataPump_E_TransformDateTimeString_NeedSrcAndDestColumns		= 0x2090,
	DTSDataPump_E_TransformDateTimeString_IndexOutOfRange			= 0x2091,
	DTSDataPump_E_TransformDateTimeString_InvalidNameOrFormat		= 0x2092,
	DTSDataPump_E_TransformDateTimeString_InvalidY2KCutoff			= 0x2093,
	DTSDataPump_E_TransformDateTimeString_ErrorParsingInputFormat	= 0x2094,
	DTSDataPump_E_TransformDateTimeString_ErrorParsingOutputFormat	= 0x2095,
	DTSDataPump_E_TransformDateTimeString_ErrorParsingInputData		= 0x2096,
	DTSDataPump_E_TransformDateTimeString_InvalidFormatString		= 0x2097,

	DTSDataPump_E_TransformWriteFile_NeedSrcAndDestColumns		= 0x2100,
	DTSDataPump_E_TransformWriteFile_FileAlreadyExists			= 0x2101,
	DTSDataPump_E_TransformWriteFile_FileColumnNameNotFound		= 0x2102,
	DTSDataPump_E_TransformWriteFile_InvalidSourceSchema		= 0x2103,
	DTSDataPump_E_TransformWriteFile_InvalidDestSchema			= 0x2104,
	DTSDataPump_E_TransformWriteFile_InvalidFileColumnName		= 0x2105,
	DTSDataPump_E_TransformWriteFile_FetchedNullFileName		= 0x2106,

	DTSDataPump_E_TransformReadFile_FileNotFound				= 0x2120,
	DTSDataPump_E_TransformReadFile_InvalidSourceSchema			= 0x2121,
	DTSDataPump_E_TransformReadFile_InvalidDestSchema			= 0x2122,
	DTSDataPump_E_TransformReadFile_DestStringTrunc				= 0x2123,

	DTSDataPump_E_BadTransformPhase								= 0x2130,
	DTSDataPump_E_InvalidStatusForPhase							= 0x2131,
	DTSDataPump_E_UnsupportedPhase								= 0x2132,
	DTSDataPump_E_InvalidDataPumpOption							= 0x2133,
	DTSDataPump_E_AxScript_InvalidPhaseColumnAccess				= 0x2134,

	DTSDataPump_E_AxScript_AbortPumpReturned					= 0x2136,
	DTSDataPump_E_AxScript_NoPhaseFunc							= 0x2137,

} DP_ENUM_END(DTSDataPumpError);

// These allow definition of how the transform will proceed.
typedef DP_ENUM_BEGIN(DTSTransformFlags, "Flags (int or long) controlling Transform") {
	// No flags are specified; essentially, the conversion must be between exact types.
	// Note that this allows string <--> nonstring conversions, because every nonstring datatype
	// has a meaningful string representation.  This may be overridden by RequireExactType,
	// which is even stricter.
	DTSTransformFlag_Strict						= 0x00000000,

	// This flag means that IDTSDataPumpTransform::ValidateSchema should allow the transfer to proceed 
	// even if there are potential overflows, under the assumption that the consumer is aware of this but
	// knows the source values are all (or mostly) within the destination column’s range.  Any overflows during
	// transformation will cause the row to be exceptioned.  This flag is generally of interest only to 
	// the IID_IDTSDataPumpTransformCopy implementation, as this is a direct copy, whereas other
	// implementations would probably convert the values or determine validity on a specific case-by-case basis.
	// This value is also used for date/time conversions which result in loss, such as DATE -> DBTIME,
	// where a subset of the source value is still meaningful.
	DTSTransformFlag_AllowDemotion 				= 0x00000001,

	// This flag means that IDTSDataPumpTransform::ValidateSchema should allow the transfer to proceed 
	// when there is promotion in the data range when moving from the source to the destination types,
	// such as I2->I4 or I4->float/double.  Note that in some cases, such as I4->R4, the data range
	// increases but at the loss of some digits of precision.
	// If AllowLossless is specified, this is allowed by the Transform.
	DTSTransformFlag_AllowPromotion 			= 0x00000002,

	// This flag allows column (w)char or byte data to be truncated silently, such as when moving data
	// from a char(60) to a char(40) column.  AllowDemotion is implied but overflow will be
	// silently truncated instead of causing an error.
	DTSTransformFlag_AllowStringTruncation 		= 0x00000004,

	// This flag means that IDTSDataPumpTransform::ValidateSchema should allow the transfer to proceed 
	// even in the event that the source is a floating-point or numeric/decimal type and the destination
	// is an integral type.  This is a numeric flavour of AllowDemotion and will not cause an error 
	// (integer overflow will still be an error; i.e. left-of-decimal digits are significant).
	DTSTransformFlag_AllowNumericTruncation		= 0x00000008,

	// This flag means that IDTSDataPumpTransform::ValidateSchema should allow the transfer to proceed 
	// even if the source column allows NULL values and the destination column does not.  As with
	// AllowDemotion, errors may be encountered during a transform.
	// If AllowLossless is specified, this is allowed by the Transform if going from nonNULLable to NULLable.
	DTSTransformFlag_AllowNullChange			= 0x00000010,

	// This flag means that IDTSDataPumpTransform::ValidateSchema should allow the transfer to proceed 
	// even in the event that the source and destination have a signed vs. unsigned mismatch.  As with
	// AllowDemotion, errors may be encountered during a transform.
	// If AllowLossless is specified, this is allowed by the Transform when going from unsigned to signed
	// with promotion (e.g. UI2 -> I4).
	DTSTransformFlag_AllowSignChange			= 0x00000020,

	// Require that the destination column's datatype be exactly the same as the source column's
	// (including length or precision/scale, fixed vs. variable length, sign, and nullability).
	// This overrides any other flags specified for column conversion validation.
	// Cannot be specified with ForceConvert.
	DTSTransformFlag_RequireExactType			= 0x00000040,

	// Allow the conversion to proceed at all times, even when the source and destination types are
	// fundamentally different.  Currently this applies to:
	//		<nonchar> <--> bytes:		Does a bitwise copy; caveats apply for endian, machine representations.
	//		int/real <--> date:			DATE is a double so this just converts between int and double.
	//		real <--> date:				DATE is a double so this just copies.
	// Cannot be specified with RequireExactType.
	DTSTransformFlag_ForceConvert				= 0x00000080,

	// Causes the TransformServer to not ClearBindingData() the destination-row storage
	// for the columns in this Transform during OnRowComplete().  This allows the
	// destination row's values to be reused by the next transform.
	DTSTransformFlag_PreserveDestRows			= 0x00000100,

	// Causes the TransformServer to allow all conversions for which a lossless conversion is
	// possible - e.g. Promotion, nonNULLable -> NULLable, unsigned -> promoted signed.
	DTSTransformFlag_AllowLosslessConversion	= 0x00000200,

	// No flags are specified; essentially, the conversion must be between exact types.
	// Note that this allows string <--> nonstring conversions, because every nonstring datatype
	// has a meaningful string representation.  This may be overridden by RequireExactType.
	DTSTransformFlag_Default					= (DTSTransformFlag_AllowDemotion | DTSTransformFlag_AllowPromotion | DTSTransformFlag_AllowStringTruncation | DTSTransformFlag_AllowNumericTruncation | DTSTransformFlag_AllowNullChange | DTSTransformFlag_AllowSignChange)

} DP_ENUM_END(DTSTransformFlags);

// These allow definition of how the transform will proceed.
typedef DP_ENUM_BEGIN(DTSTransformPhaseEnum, "Bitmask (int or long) indicating supported or requested Transform Phases.") {
	DTSTransformPhase_None						= 0x00000000,

	// Identify which phase(s) the transform is to be called in.
	// These must be passed to DataPump::AddTransform2 or the transform will not
	// be called for that phase.
	DTSTransformPhase_PreSourceData				= 0x00000001,
	DTSTransformPhase_PostSourceData			= 0x00000002,
	DTSTransformPhase_Transform					= 0x00000004,
	DTSTransformPhase_OnTransformFailure		= 0x00000008,
	DTSTransformPhase_OnInsertSuccess			= 0x00000010,
	DTSTransformPhase_OnInsertFailure			= 0x00000020,
	DTSTransformPhase_OnBatchComplete			= 0x00000040,

	// This may also be passed to DataPump::AddTransform2, but if not, the DataPump will
	// query IDTSTransformServer2::GetTransformServerInfo to see if it supports this phase,
	// and will call it in place of OnTransformComplete if so.
	DTSTransformPhase_OnPumpComplete			= 0x00000080,

	// Bitmask of all valid phases.
	DTSTransformPhase_All						= 0x000000FF,

} DP_ENUM_END(DTSTransformPhaseEnum);

// Status returned from a Transform operation.
// All "normal" errors from DTSDataPumpTransform::Execute should be returned as
// one of these flags, with a SUCCEEDED HRESULT (possibly with the addition of
// OLEDB Error Records via the IDTSErrorRecords interface passed to 
// IDTSDataPumpTransform::AddVariable).  A FAILED HRESULT returned from
// DTSDataPumpTransform::Execute indicates an unrecoverable error and aborts
// the DataPump.
typedef DP_ENUM_BEGIN(DTSTransformStatus, "Return value (int or long) from ActiveX Scripting Transform") {
	// Default; conversions (if any) succeeded; write the row to destination if
	// specified, without calling any error handlers.  Default is to do Insert;
	// this may be overridden for data-driven queries by other flags to do Insert,
	// Update, Delete, or UserQuery for a user-defined ad-hoc query.
	DTSTransformStat_OK							= 0x00000001,

	// Success with additional info, which the app may want to process further
	// by reading its pvTransformUserData (if it shares that knowledge with the
	// transform server) or thru OLEDB Error Records; therefore, the Pump will 
	// call the ErrorSink if one was specified, but does not increment the error
	// row count.  The DTSTransformStatus result of the operation is passed to
	// the ErrorSink, so the app can switch on this bit.
	DTSTransformStat_Info						= 0x00001000,

	// Write row if destination specified; also call ErrorSink with Info.
	DTSTransformStat_OKInfo						= 0x00001001,

	// Abort further processing of this row, for non-error reasons.
	DTSTransformStat_SkipRow					= 0x00000002,

	// Abort further processing of this row, and calls ErrorSink with Info.
	DTSTransformStat_SkipRowInfo				= 0x00001002,

	// Do not fetch the next row; re-execute all transforms against the current
	// source and destination rows.  No initialization is done to the destination
	// row, so this could be used to generate multiple output rows from a single
	// input row.  Subsequent transforms are still executed unless a SkipRow* flag
	// is also present.
	DTSTransformStat_SkipFetch					= 0x00000004,

	// Do not write the current row to destination.  Usually used to fetch the next
	// source row to generate a simple aggregate.  Subsequent transforms are still
	// executed unless a SkipRow* flag is also present.  DTSTransformStat_SkipInsert
	// forces DTSTransformFlag_PreserveDestRows behaviour for the row for which it
	// is specified.
	DTSTransformStat_SkipInsert					= 0x00000008,

	// The following 4 flags are not compatible together.  They execute the
	// similarly-named statement passed to SetRowsetAndQueries on the Destination,
	// with values from the currently transformed Destination Row.
	DTSTransformStat_InsertQuery				= 0x00000010,
	DTSTransformStat_UpdateQuery				= 0x00000020,
	DTSTransformStat_DeleteQuery				= 0x00000040,
	DTSTransformStat_UserQuery					= 0x00000080,

	// This flag is set by transforms which do not require setting data into the
	// destination (for example, WriteFile).  If all Transforms set this flag, no
	// Insert (or DataDrivenQuery) is done.  Implies DTSTransformStat_OK, which can
	// also be OR'd in.
	// This is similar to SkipInsert, except that SkipInsert will always skip;
	// DestDataNotSet will only skip the insert if all transforms return it.
	// Therefore, it is always cleared from the transform status referenced by
	// the pointer passed to the TransformServer.
	DTSTransformStat_DestDataNotSet				= 0x00000200,

	// May be bit-OR'd into the following error returns.
	DTSTransformStat_Error						= 0x00002000,

	// Abort further processing of this row due to error and call the error sink,
	// but do not write to exception file.  Should be handled by the ErrorSink.
	DTSTransformStat_ErrorSkipRow				= 0x00002002,

	// Abort further processing of this row as an exception and call the error sink,
	// and write this row to exception file.  Should be handled by the ErrorSink.
	// Note this bit does not map to any non-error bits.
	DTSTransformStat_ExceptionRow				= 0x00002100,

	// Or’d with prior bits to abort processing any further rows and return
	// DTSTransformExec_AbortPump from IDTSDataPump::Execute().  
	// This does not include the Error bit so &'ing with it will only return
	// TRUE for this bit.
	DTSTransformStat_AbortPump					= 0x00004000,

	// Transform determined that this row is the last one to be operated on,
	// so allows the pump to be aborted "normally" (without signifying an error).
	// May be or'd with other bits to skip the current row; otherwise it will go
	// to the next transforms and then write it to destination (in accordance with
	// how the following transforms specify).
	DTSTransformStat_NoMoreRows					= 0x00008000,

} DP_ENUM_END(DTSTransformStatus);

// Status returned from an IDataPump::Execute operation.
typedef DP_ENUM_BEGIN(DTSExecuteStatus, "Return value (int or long) from DataPump Execution") {
	// All rows copied (or skipped) without error.
	DTSTransformExec_OK							= 0x00000000,

	// Bit-OR’d into the following error returns.
	DTSTransformExec_Error						= 0x00001000,	// Bit-or’d into following

	// Pump continued to completion but errors were encountered
	DTSTransformExec_OKErrors					= 0x00001001,

	// Pump aborted because too many rows had errors.
	DTSTransformExec_ErrorCountExceeded			= 0x00001002,

	// Pump aborted due to Transform request or ErrorSink return.
	DTSTransformExec_AbortPump					= 0x00001004,
} DP_ENUM_END(DTSExecuteStatus);

#endif	// DTSDataPump_CONSTANTS_

////////////////////////////////////////////
// CPP-only definitions
////////////////////////////////////////////

#ifndef DTSDataPump_ODL_

// Define parameter usage.
#define DP_IN
#define DP_OUT
#define DP_INOUT

#ifdef NONAMELESSUNION
#define DP_UNION_NAME(u)	u
#else
#define DP_UNION_NAME(u)
#endif

// For safety, struct initialization values are set in ctors for C++ clients.
#if !defined(__cplusplus) && !defined(DP_NO_AUTOCTOR)
#define DP_NO_AUTOCTOR
#endif

// These are the conversion flags indicating what may happen during an individual column
// Convert() call, and accounts for the column lengths, nullability, sign, etc.
// See DTSTransformFlags for a more detailed discussion of the similarly-named TransformFlag
// which will allow conversion to proceed when these conditions are present.
//	Keys:
//		<T> - TransformFlag is available to explicitly allow this.
//		<E>	- Error may be encountered during Convert()
//		<F> - Fatal; Convert() will error as unsupported or with overflow.
//
typedef DP_ENUM_BEGIN(DTSConvertFlags, "DTSConvertFlags") {
	// The conversion is between columns of identical type, length or precision/scale,
	// and nullability, or is between text and another type, with the text being of
	// sufficient length for a representation of that datatype.  Errors should not be
	// encountered during Convert() unless a text conversion contains invalid data.
	DTSConvertFlag_ExactType					= 0x00000000,

	// The conversion will promote the range of data from source to destination
	// (e.g. I4 -> I2, [var]char -> longer [var]char, numeric(x, y) -> numeric(x+1, y+1)).
	// <T>
	DTSConvertFlag_Promotion					= 0x00000001,
	
	// Conversion will demote (e.g. I4 -> I2); overflow error possible.
	// <T, E> 
	DTSConvertFlag_Demotion						= 0x00000002,
	
	// Conversion may do string or byte truncation; truncation error possible if
	// this flag is not specified on Convert().
	// <T, E>
	DTSConvertFlag_StringTruncation				= 0x00000004,
	
	// Conversion may do integral rounding from float or numeric, or move a larger
	// scale into a smaller scale (both cases resulting in truncation of digits to
	// the right of the decimal point).  This is also flagged when moving from integral
	// or numeric to float/double when source precision is greater than FLT/DBL_DIG.
	// <T> 
	DTSConvertFlag_NumericTruncation			= 0x00000008,
	
	// Conversion may try to put NULL source data into a NonNULL destination column,
	// which will error, or vice-versa, which will be safe.
	// <T, E>
	DTSConvertFlag_NullChange					= 0x00000010,
	
	// Conversion may try to put a signed value int/float into an unsigned destination, 
	// or vice-versa.  This may error if the source value is negative and destination
	// is unsigned, or if the source is unsigned and its value is larger than the
	// signed destination's maximum signed value (overflow).
	// <T, E>
	DTSConvertFlag_SignChange					= 0x00000020,
	
	// Destination column size is too short for a meaningful conversion from source
	// column type.
	// <F>
	DTSConvertFlag_DestTooShort					= 0x00000040,
	
	// Source column size is too short for a meaningful conversion to destination
	// column type.
	// <F>
	DTSConvertFlag_SourceTooShort				= 0x00000080,
	
	// Source and destination datatypes are not really compatible, but conversion can be forced.
	// <T>
	DTSConvertFlag_ForceConvert					= 0x00000100,
	
	// Conversion fails because of bad or incompatible column types.
	// <F>
	DTSConvertFlag_Unsupported					= 0x00001000,

} DP_ENUM_END(DTSConvertFlags);

// Binding modes for column data; returned from IDTSDataPumpTransform::ValidateSchema
// via DTSTransformColumnInfo.  Normally the DataPump default handling does not need to
// be changed, but for Blob ((DBCOLUMNFLAGS_ISLONG) columns, custom Transforms are able
// to adjust bindings to maximize performance.
//
typedef DP_ENUM_BEGIN(DTSBindMode, "DTSBindMode") {
	// Indicates data should be bound "in-memory, out of line".  Currently this is only supported
	// by the OLEDB specification for variable-length types: DBTYPE_((W)STR|BYTES); therefore,
	// the DataPump will error if it is specified for other types.  DTSBindMode_(Client|Provider)Owned
	// must be specified with DTSBindMode_Byref.
	// 
	// For source, the returned data will be a direct pointer to the provider's data if
	// DTSBindMode_ProviderOwned is specified (in which case it must not be free'd or written to),
	// or a CoTaskMemAlloc()'d pointer if DTSBindMode_ClientOwned is specified (in which case it
	// is the client's property and must be freed).
	//
	// For destination, the transformation server must place the data pointer in
	// pDestColumnInfo->pvRowData.  If DTSBindMode_ClientOwned is specified, then the data
	// is assumed to require freeing after the InsertRow operation completes.  The DataPump
	// will never perform a non-Byref, in-memory destination binding for a Blob, so this flag
	// must be specified unless a Storage Object is used.
	//
	DTSBindMode_Byref							= 0x00000001,

	// Default "in-memory, inline" binding mode; space for the source and destination data, including
	// the full length of a DBTYPE_((W)STR|BYTES) column, is allocated in rgColumnData[ii].pvData and
	// passed to IDTSDataPumpTransform::Execute.
	//
	// For a BLOB (DBCOLUMNFLAGS_ISLONG) column, IDTSDataPumpTransform::ValidateSchema returns
	// the length to use for this binding in ppDTSColBinding[ii].cbInMemoryBlobSize.  This will
	// result in a separate allocation for that Blob column (i.e. multiple Blobs are not
	// allocated within a single contiguous row).
	//
	// On fetch from Source, the DBSTATUS in the binding will indicate whether the data was
	// truncated; it is up to the Transform server how (or if) this is handled.
	//
	// For performance reasons, this flag should not be specified for non-Blob (W)STR|BYTES
	// source columns; DTSBindMode_Byref_ProviderOwned is the default, to use a pointer to the
	// provider's data cache and avoid an unnecessary copy.
	//
	// For DBTYPE_BSTR and DBTYPE_VARIANT, this specifies that the binding is DBMEMOWNER_CLIENTOWNED
	// (without BYREF), and the client is responsible for freeing it (e.g. IDTSDataConvert::ClearBindingData).
	//
	DTSBindMode_ClientOwned						= 0x00000002,

	// For Source DBTYPE_((W)STR|BYTES), this flag causes the OLEDB binding to be done as DBTYPE_BYREF
	// with DBMEMOWNER_CLIENTOWNED, resulting in a CoTaskMemAlloc which the client is
	// responsible for freeing (e.g. via IDTSDataConvert::ClearBindingData).  For a BLOB
	// column, the length to use for this binding is returned from ValidateSchema() in 
	// ppDTSColBinding[ii].cbInMemoryBlobSize.  On fetch from Source, the DBSTATUS in the binding
	// will indicate whether the data was truncated; it is up to the Transform server how (or if)
	// this is handled.
	//
	// This flag causes each row to have a separate CoTaskMemAlloc for the source column.  This is
	// somewhat less efficient than the other in-memory options, and thus should only be used by
	// a Transform which wants to assume ownership of that allocation.  The Transform is responsible
	// for tracking and freeing the allocation (and for ensuring that OnRowComplete does not free
	// it if it is to be used in subsequent Transforms).
	//
	// For destination columns, this is the "safest" way to pass an in-memory pointer, as some providers
	// may not allow ProviderOwned on a destination (such as with Blob columns).  The Transform must
	// ensure that it does not double-free a pointer.
	//
	DTSBindMode_Byref_ClientOwned				= 0x00000003,

	// By itself, ProviderOwned is seldom used by itself except for BSTR, which does not always
	// support Byref.  It is primarily for DBTYPE_((W)STR|BYTES) with Byref, to reduce allocations
	// and/or copies, as described below.  It may not be supported by providers for other datatypes.
	//
	DTSBindMode_ProviderOwned					= 0x00000004,

	// This flag causes source columns to be bound to return a pointer into the provider's memory
	// space for DBTYPE_((W)STR|BYTES).  This pointer is read-only and must not be freed.
	//
	// For Blob columns, the Source Provider may not support (Byref_)ProviderOwned Blobs; this
	// would require that the entire Blob be buffered contiguously.  Therefore, unless you have
	// specific knowledge of the provider, this flag is discouraged.
	//
	// For DBTYPE_BSTR, the BYREF specification may not be supported, and may require DBMEMOWNER_PROVIDEROWNED
	// (without BYREF).  The client must not free the data.
	//
	// For other types, including DBTYPE_VARIANT, OLEDB raises an error for this specification
	// when creating an accessor.
	//
	// For the destination, specifying ProviderOwned requires that the data be shallow-copied into
	// the destination binding to avoid memory leaks (this is automatically done by IDTSDataConvert::
	// ConvertToBinding).
	//
	DTSBindMode_Byref_ProviderOwned				= 0x00000005,

	// This indicates whether the Pump should buffer Source Blob Storage Objects.  For most cases,
	// this should be left _BufferDefault; for performance reasons, the DataPump will only buffer
	// where it is necessary to avoid data loss.  This is in the following cases:
	//	DTSBindMode_Blob_BufferAlways
	//	DTSBindMode_Blob_BufferDefault, provider doesn't allow multiple SO's, and any of following:
	//		The column is referenced in a subsequent transform.
	//		The column is not the rightmost column of all transforms up to and including it.
	//
	// The DataPump can buffer from a source provider's ISequentialStream or ILockBytes, and
	// exposes both these interfaces on its own object.  Because it is a buffer, the object's data
	// can be edited via Write(At) to reduce memory requirements in the TransformServer (allowing the
	// source object to be placed in the destination row, if the destination supports Storage Objects).
	//
	// DTSBindMode_Blob_* is ignored for in-memory binding, which is an implicit buffering.
	DTSBindMode_Blob_BufferDefault				= 0x00000010,
	DTSBindMode_Blob_BufferAlways				= 0x00000020,
	DTSBindMode_Blob_BufferNever				= 0x00000040,

	// This indicates whether to use a Structured Storage object for binding a BLOB column.  The Transform
	// Server should indicate which interface it wants in DTSBindInfo::fStorageObject, on return from
	// ValidateSchema().  The DataPump supports the following behaviour:
	//    Custom Transformations:
	//       For Source, if the DataPump does not buffer, only the provider-supported Storage Object interfaces
	//			are available.  Generally this will always include ISequentialStream.  See comments regarding
	//			DTSBindMode_Blob_Buffer*; if the DataPump buffers the Blob data, it supports only ISequentialStream
	//			and ILockBytes.
	//          If the source does not support storage objects, then the Transform Server must not request a
	//			Storage Object, and must bind the source data as in-memory, specifying DTSBindInfo::cbInMemoryBlobSize.
	//       For Destination, the Transform Server supplies the Storage object placed into the row, and must
	//			specify one interface from fProviderStorageObjects for the DataPump to bind the destination.
	//          If the destination does not support storage objects, then the TransformServer must not request
	//			a Storage Object, and must bind the destination data as in-memory, ClientOwned or ProviderOwned,
	//			specifying DTSBindInfo::cbInMemoryBlobSize.
	//    Default (DataPump-supplied) TransformCopy:
	//       If either Source or Destination do not support ISequentialStream, then the DataPump will bind both
	//          as ClientOwned in-memory, using the source column's DTSBindInfo::cbInMemoryBlobSize.
	//			Otherwise, the DataPump will bind to the providers as ISequentialStream, with default buffering.
	//			See also comments regarding DTSBindMode_Blob_Buffer*; this can be specified to override the
	//			Pump's default handling even in the TransformCopy case.
	//
	// DTSBindMode_Blob_StorageObject cannot be specified with non-DTSBindMode_Blob_* flags.
	DTSBindMode_Blob_StorageObject				= 0x00000100,

	// Allow a Byref or StorageObject binding to be downgraded to an inline binding by a subsequent transform.
	// If not set and a subsequent transform tries to change the binding, it will fail.
	DTSBindMode_AllowInlineOverride				= 0x00001000,

	// Column has already been bound by a prior transform.  Current transform should avoid re-specifying
	// bind info, or may attempt legal rebinding (AllowInlineOverride).
	DTSBindMode_BoundInPriorTransform			= 0x00002000,
} DP_ENUM_END(DTSBindMode);

// Indicates which of the DataPump defaults are to be overridden on a single AddTransform().
typedef DP_ENUM_BEGIN(DTSSpecifyBlobDefaults, "Specify overrides of DataPump Blob-handling defaults") {
	DTSBlobDefault_DataPumpDefaults		= 0x0000,	// None (initialization)
	DTSBlobDefault_BufferSource			= 0x0001,	// Override DTSBindMode_Blob_BufferDefault for source Blob Storage Objects
	DTSBlobDefault_InMemorySize			= 0x0002,	// Override DTS_DEFAULT_INMEMORY_BLOB_SIZE.
	DTSBlobDefault_ForceInMemory 		= 0x0004,	// Force Blobs to be InMemory (no Storage Objects) for this Transform.
													// Forces DTSTransformColumnInfo.fProviderStorageObjects
													// sent to the Transformer to be 0.
	DTSBlobDefault_ForceMultipleStorageObjects	= 0x0008,	// Forces DTSTransformColumnInfo.dtsProviderFlags sent to the
													// Transformer to include DTSProviderFlag_Blob_MultipleStorageObjects.
													// This could be an optimization if the Source provider supports multiple
													// storage objects and the destination is known to support them only
													// multiple blobs for insert, since the OLEDB spec does not distinguish
													// between multiple-StorageObject support for GetData vs. SetData/Insert.
} DP_ENUM_END(DTSSpecifyBlobDefaults);

// Flags indicating known Provider Blob capabilities; their absence indicates
// corresponding Provider restrictions or requirements.
typedef DP_ENUM_BEGIN(DTSProviderFlags, "Provider behaviour characteristics") {
	DTSProviderFlag_None					= 0x00000000,	// None

	DTSProviderFlag_ProviderOwned			= 0x00000001,	// Provider supports Byref binding (some may not).

	DTSProviderFlag_Blob_InsertNoLength		= 0x00000100,	// Blob Inserts do not require length to be prespecified
	DTSProviderFlag_Blob_Revisitable		= 0x00000200,	// Provider guarantees that Blob data is not skipped when succeeding columns fetched
	DTSProviderFlag_Blob_Rewindable			= 0x00000400,	// Provider guarantees Blob data supports random access
	DTSProviderFlag_Blob_ProviderOwned		= 0x00000800,	// Provider allows the PROVIDEROWNED flag for use with Blobs
	DTSProviderFlag_Blob_MultipleStorageObjects = 0x00001000,		// Provider supports multiple storage objects per row.
	DTSProviderFlag_Blob_NonBlockingStorageObjects = 0x00002000,	// Provider supports multiple nonblocking storage objects per row.
} DP_ENUM_END(DTSProviderFlags);

// Extended options on DataPump operation.
typedef DP_ENUM_BEGIN(DTSDataPumpOptions, "Extended options on DataPump operation") {
	DTSDataPumpOpt_Default						= 0x00000000,	// Default operation

	// Always commit final batch even on DataPump abort (to support restartability).
	DTSDataPumpOpt_AlwaysCommitFinalBatch		= 0x00000001,

} DP_ENUM_END(DTSDataPumpOptions);
typedef DTSDataPumpOptions *LPDTSDataPumpOptions;

// The actual structure passed to AddTransform to specify overriding Blob defaults.
// This is most useful for the default TransformCopy case, but can also be used by
// a client who predetermines (e.g. via a query) the maximum Blob size in the coming
// result set, for the most efficient memory allocations.
#ifndef DP_NO_AUTOCTOR
	struct DTSTransformBlobDefaults {
#else   // DP_NO_AUTOCTOR
	typedef struct {
#endif  // DP_NO_AUTOCTOR
		DTSSpecifyBlobDefaults dtsSpecifyMask;		// Which of the following items to override.
		BOOL bBufferSource;							// If dtsSpecifyMask & DTSBlobDefault_BufferSource;
													// TRUE or FALSE forces Pump to buffer source Blobs or not.
		ULONG cbInMemorySize;						// If dtsSpecifyMask & DTSBlobDefault_InMemorySize;
													// overrides DTS_DEFAULT_INMEMORY_BLOB_SIZE.  Size in bytes.
#ifndef DP_NO_AUTOCTOR
		DTSTransformBlobDefaults()
				: dtsSpecifyMask(DTSBlobDefault_DataPumpDefaults)
			{	}
	};
#else   // DP_NO_AUTOCTOR
	} DTSTransformBlobDefaults;
#endif  // DP_NO_AUTOCTOR
typedef DTSTransformBlobDefaults *LPDTSTransformBlobDefaults;
typedef const DTSTransformBlobDefaults *LPCDTSTransformBlobDefaults;

// Specifies an individual column passed to AddTransform.  The column may be specified by
// name, or if the name is NULL, by an ordinal (this makes unnamed columns easier for the
// consumer to specify).
typedef struct {
	LPOLESTR pwzColumnName;						// Name of column
	ULONG ulColumnOrdinal;						// Ordinal of column if name is NULL; 1-based for OLEDB consistency.
} DTSTransformColumnSpecification, *LPDTSTransformColumnSpecification;
typedef const DTSTransformColumnSpecification *LPCDTSTransformColumnSpecification;

// Specifies a list of columns passed to AddTransform.
#ifndef DP_NO_AUTOCTOR
	struct DTSTransformColumnsSpecification {
#else   // DP_NO_AUTOCTOR
	typedef struct {
#endif  // DP_NO_AUTOCTOR

		ULONG cSourceColumns;						// Specify source columns
		LPCDTSTransformColumnSpecification pSourceColumns;
		ULONG cDestinationColumns;					// Specify destination columns
		LPCDTSTransformColumnSpecification pDestinationColumns;
		DTSTransformBlobDefaults BlobDefaults;		// Blob default overrides if specified

#ifndef DP_NO_AUTOCTOR
		DTSTransformColumnsSpecification() 
				: cSourceColumns(0)
				, pSourceColumns(NULL)
				, cDestinationColumns(0)
				, pDestinationColumns(NULL)
			{	}
	};
#else   // DP_NO_AUTOCTOR
	} DTSTransformColumnsSpecification;
#endif   // DP_NO_AUTOCTOR
typedef DTSTransformColumnsSpecification *LPDTSTransformColumnsSpecification;
typedef const DTSTransformColumnsSpecification *LPCDTSTransformColumnsSpecification;

// Specifies a query and list of columns for IDTSDataDrivenQuery.
#ifndef DP_NO_AUTOCTOR
	struct DTSTransformQuerySpecification {
#else   // DP_NO_AUTOCTOR
	typedef struct {
#endif  // DP_NO_AUTOCTOR

		LPCOLESTR wzQuery;								// The Parameterized Query
		ULONG cColumns;									// Specify count of columns
		LPCDTSTransformColumnSpecification pColumns;	// Specify column mapping to parameters, in order found in query.

#ifndef DP_NO_AUTOCTOR
		DTSTransformQuerySpecification() 
				: wzQuery(NULL)
				, cColumns(0)
				, pColumns(NULL)
			{	}
	};
#else   // DP_NO_AUTOCTOR
	} DTSTransformQuerySpecification;
#endif   // DP_NO_AUTOCTOR
typedef DTSTransformQuerySpecification *LPDTSTransformQuerySpecification;
typedef const DTSTransformQuerySpecification *LPCDTSTransformQuerySpecification;

// Transform-server specifiable binding information.  An array of these structures is passed to
// ValidateSchema() with default values (possibly derived from DTSTransformBlobDefaults overrides),
// and the Transform Server can set the values.  Because source columns can appear multiple times
// in the same or different transactions, the last specification wins; therefore, a TransformServer's
// Execute() method should gracefully handle a source binding different from what it specified in
// ValidateSchema().
typedef struct {
	DTSBindMode eBindMode;						// Per above.  For Blobs, specifying a Buffering mode overrides
												// the DataPump and any DTSTransformBlobDefaults default.
	DWORD fStorageObject;						// For DTSBindMode_Blob_StorageObject; one of DBPROPVAL_SS_*.  If
												// specified, eBindMode must be DTSBindMode_Blob_StorageObject.
	ULONG cbInMemoryBlobSize;					// For DTSBindMode of inmemory Blobs.  Setting this value overrides
												// the DataPump and any DTSTransformBlobDefaults default.  Size in bytes.
} DTSBindInfo;

// This is a single column definition, binding, and data item for DTSTransformColumnInfo.
typedef struct {
	const DBCOLUMNINFO *pDBColumnInfo;			// Pointer to source or destination DBCOLUMNINFO for this column.
	const DBBINDING *pDBBinding;				// Pointer to source or destination DBBINDING for this column.
												// wType == DBTYPE_EMPTY if this column is not referenced in any transform.
	DTSBindInfo *pDTSBindInfo;					// Pointer to source or destination DTSBindInfo for this column.
	LPBYTE pvData;								// Data space for this column, indexed by pDBBinding offsets.
												// NULL if this column was not referenced in any Transform.
} DTSColumnData;

// The DBCOLUMNFLAGS and pwszName are in DBCOLUMNINFO and not DBBINDING;
// therefore pass both structures to transform code.  The COM Transform server uses the
// binding info to access the pvRowData.  This structure is passed to ITransformExecute::
// Execute to expose the source and destination columns specified by the Transform.
typedef struct {
	DWORD fProviderStorageObjects;				// DBPROPVAL_SS_*; Blob Storage Object interfaces supported
												// by source or destination provider.  Will be 0 if none supported,
												// or if DTSTransformBlobDefaults::bForceBlobsInMemory is specified.
	DTSProviderFlags dtsProviderFlags;			// Provider characterstics, e.g Blob Flags.
	ULONG cColumns;								// Count of columns in rgColumns
	DTSColumnData *rgColumnData;				// Column schema and binding information
	ULONG cPriorBlobStorageObjects;				// Number of Blobs bound as Storage Objects in prior transforms.
												// Can be used with DTSProviderFlag_Blob_MultipleStorageObjects
												// to determine if the current Transform can use a storage object.
} DTSTransformColumnInfo, *LPDTSTransformColumnInfo;
typedef const DTSTransformColumnInfo *LPCDTSTransformColumnInfo;

typedef enum {
	DTSGuid_Variant,
	DTSGuid_Guid,
	DTSGuid_OleStr
} DTSGuidType;

typedef struct {
	DTSGuidType eType;							// Indexes union.
	union {
		GUID Guid;								// GUID form
		VARIANT Variant;						// BSTR == progid or clsid (differentiated by looking for ‘.’ in name)
												// BYTE/LONG == guid encoding (e.g. Repository))
												// UNKNOWN == pointer to IID_IDTSDataPumpTransform
		LPOLESTR OleStr;						// Progid or clsid (differentiated by looking for ‘.’ in name)
	} DP_UNION_NAME(u);
} DTSGuid;

#define DTS_DEFAULT_LookupCacheSize		100

// Specifies a query and list of columns for IDTSDataDrivenQuery.
#ifndef DP_NO_AUTOCTOR
	struct DTSTransformLookupSpecification {
#else   // DP_NO_AUTOCTOR
	typedef struct {
#endif  // DP_NO_AUTOCTOR

		LPCOLESTR wzName;								// Name of the Lookup (for disambiguation)
		LPCOLESTR wzQuery;								// The Parameterized Query
		IUnknown *pIUnkSession;							// Session to use for the Lookup
		ULONG cMaxCacheRows;							// Number of rows to cache

#ifndef DP_NO_AUTOCTOR
		DTSTransformLookupSpecification() 
				: wzName(NULL)
				, wzQuery(NULL)
				, pIUnkSession(NULL)
				, cMaxCacheRows(DTS_DEFAULT_LookupCacheSize)
			{	}
	};
#else   // DP_NO_AUTOCTOR
	} DTSTransformLookupSpecification;
#endif   // DP_NO_AUTOCTOR
typedef DTSTransformLookupSpecification *LPDTSTransformLookupSpecification;
typedef const DTSTransformLookupSpecification *LPCDTSTransformLookupSpecification;

// Receives returned information about Pump execution.
#ifndef DP_NO_AUTOCTOR
	struct DTSExecuteInfo {
#else   // DP_NO_AUTOCTOR
	typedef struct {
#endif  // DP_NO_AUTOCTOR

		// These are parameters moved from Execute() for ExecuteInit/ExecuteRow.
		ULARGE_INTEGER uliRowsComplete;					// Total number of source rows processed (including those skipped).
		ULONG ulErrorRows;								// Total number of error rows encountered.
		DTSExecuteStatus eExecStatus;					// Pump return status.

		// This is used by ExecuteRow to force a specific data driven query to be executed at the destination.
		DTSTransformStatus eForceDDQTransformStatus;

		// This allows hierarchical control.  hSrcChapterIn allows restriction of pump
		// fetches to a specific subset of the rowset.  If phSrcRowOut is not NULL,
		// it receives the HROW of the last row fetched from the source rowset by ExecuteRow,
		// or DB_NULL_HROW if eExecStatus failed.  It is addref'd upon return and must be
		// released by the datapump consumer via the source rowset before the next ExecuteRow
		// or ExecuteComplete is called.  It is used by the DataPump consumer to obtain child
		// chapters of the source rowset, in order to pump data in hierarchical sequence.
		// hDestChapterIn and phDestRowOut function similarly, for hierarchical inserts.
		HCHAPTER hSrcChapterIn;							// Input chapter for fetches in ExecuteRow.
		HCHAPTER hDestChapterIn;						// Input chapter for inserts in ExecuteRow.
		HROW *phSrcRowOut;								// Output hrow for fetches in ExecuteRow.
		HROW *phDestRowOut;								// Output hrow for inserts in ExecuteRow.

#ifndef DP_NO_AUTOCTOR
		DTSExecuteInfo()
				: ulErrorRows(0)
				, eExecStatus(DTSTransformExec_OK)
				, eForceDDQTransformStatus(DTSTransformStat_OK)
				, hSrcChapterIn(DB_NULL_HCHAPTER)
				, hDestChapterIn(DB_NULL_HCHAPTER)
				, phSrcRowOut(NULL)
				, phDestRowOut(NULL)
			{
				uliRowsComplete.QuadPart = 0;
			}
	};
#else   // DP_NO_AUTOCTOR
	} DTSExecuteInfo;
#endif   // DP_NO_AUTOCTOR
typedef DTSExecuteInfo *LPDTSExecuteInfo;
typedef const DTSExecuteInfo *LPCDTSExecuteInfo;

// Receives returned information about Pump execution.
#ifndef DP_NO_AUTOCTOR
	struct DTSTransformPhaseInfo {
#else   // DP_NO_AUTOCTOR
	typedef struct {
#endif  // DP_NO_AUTOCTOR

		// These show current Execute() status.
		ULARGE_INTEGER uliCurrentSourceRow;				// Current source row being processed (total source rows, for PostSourceData).
		ULARGE_INTEGER uliDestRowsComplete;				// Destination rows inserted or queries executed so far (incremented for post-insert phases).
		ULONG ulErrorRows;								// Total number of error rows encountered (includes current row if in a failure phase).
		HRESULT hrStatus;								// Errorcode of operation preceding current phase.
		DTSTransformStatus eTransformStatus;			// Row Transform status.  Not updated after Insert or DDQ Query execution.
		DTSTransformPhaseEnum eCurrentPhase;			// Current Transform phase.

#ifndef DP_NO_AUTOCTOR
		DTSTransformPhaseInfo()
				: ulErrorRows(0)
				, hrStatus(NOERROR)
				, eTransformStatus(DTSTransformStat_OK)
				, eCurrentPhase(DTSTransformPhase_None)
			{
				uliCurrentSourceRow.QuadPart = 0;
				uliDestRowsComplete.QuadPart = 0;
			}
	};
#else   // DP_NO_AUTOCTOR
	} DTSTransformPhaseInfo;
#endif   // DP_NO_AUTOCTOR
typedef DTSTransformPhaseInfo *LPDTSTransformPhaseInfo;
typedef const DTSTransformPhaseInfo *LPCDTSTransformPhaseInfo;

// Passed to IDTSDataPumpTransform2::PreValidateSchema.
#ifndef DP_NO_AUTOCTOR
	struct DTSTransformColumnMetadata {
#else   // DP_NO_AUTOCTOR
	typedef struct {
#endif  // DP_NO_AUTOCTOR

		ULONG cColumns;
		DBCOLUMNINFO *rgDBColumnInfo;

#ifndef DP_NO_AUTOCTOR
		DTSTransformColumnMetadata()
				: cColumns(0)
				, rgDBColumnInfo(NULL)
			{	}
	};
#else   // DP_NO_AUTOCTOR
	} DTSTransformColumnMetadata;
#endif   // DP_NO_AUTOCTOR
typedef DTSTransformColumnMetadata *LPDTSTransformColumnMetadata;
typedef const DTSTransformColumnMetadata *LPCDTSTransformColumnMetadata;

///////////////////////////////////////////////////////////////////////////////////////
// Class and IID definitions
///////////////////////////////////////////////////////////////////////////////////////

// Forward-define all interfaces.
#define DP_FWD_DEFINE_INTERFACE(itf)					\
	interface itf;										\
	typedef interface itf * LP##itf;

// Repeat the IUnknown and IDispatch members because C doesn't provide inheritance.
#ifndef DTSDataPump_Unknown_Base
#define DTSDataPump_Unknown_Base()															\
		STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID * ppvObj) PURE;				\
		STDMETHOD_(ULONG,AddRef) (THIS) PURE;												\
		STDMETHOD_(ULONG,Release) (THIS) PURE;
#endif
#ifndef DTSDataPump_Dispatch_Base
#define DTSDataPump_Dispatch_Base(itf)														\
		DTSDataPump_Unknown_Base()															\
		STDMETHOD(GetTypeInfoCount)(UINT FAR* pcTypeInfo) PURE;								\
		STDMETHOD(GetTypeInfo)(UINT iTypeInfo, LCID lcid, ITypeInfo FAR* FAR* ppTI) PURE;	\
		STDMETHOD(GetIDsOfNames)(REFIID riid, LPOLESTR FAR* rgszNames, UINT cNames,			\
								LCID lcid, DISPID FAR* rgdispid) PURE;						\
		STDMETHOD(Invoke)(DISPID dispidMember, REFIID riid, LCID lcid, WORD wFlags,			\
								DISPPARAMS FAR* pdispparams, LPVARIANT pvarResult,			\
								LPEXCEPINFO pexcepinfo, UINT FAR* puArgErr) PURE;
#define DTSDataPump_Dispatch_Base_2b(itf)	DTSDataPump_Dispatch_Base(itf)
#define DTSDataPump_Dispatch_Base_2d(itf)	DTSDataPump_Dispatch_Base(itf)
#endif
#ifndef DTSDataPump_IDispatch
#define DTSDataPump_IDispatch IDispatch
#endif

// Include <initguid.h> to define ownership of these GUIDs.
// {xxxxxxxx-740b-11d0-ae7b-00aa004a34d5}
#define DEFINE_DTSDataPumpGUID(name, lval) \
      DEFINE_GUID(name, 0x##lval, 0x740b, 0x11d0, 0xae, 0x7b, 0x0, 0xaa, 0x0, 0x4a, 0x34, 0xd5);

// DTSPump-supplied classes and interfaces.
DP_FWD_DEFINE_INTERFACE(IDTSDataPump)
#define Progid_DTSDataPump			OLESTR("DTS.DataPump")
DEFINE_DTSDataPumpGUID(CLSID_DTSDataPump, 10010100)
DEFINE_DTSDataPumpGUID(IID_IDTSDataPump, 10010101)
DEFINE_DTSDataPumpGUID(IID_IDTSDataPump2, 10010110)

#define Progid_DTSErrorLookup		OLESTR("DTS.ErrorLookup")
DEFINE_DTSDataPumpGUID(CLSID_DTSErrorLookup, 10010102)

DP_FWD_DEFINE_INTERFACE(IDTSDataConvert)
#define Progid_DTSDataConvert		OLESTR("DTS.DataConvert")
DEFINE_DTSDataPumpGUID(CLSID_DTSDataConvert, 10010103)
DEFINE_DTSDataPumpGUID(IID_IDTSDataConvert, 10010104)
DEFINE_DTSDataPumpGUID(IID_IDTSDataDrivenQuery, 10010105)
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpSpecifyLookups, 10010106)

// DTS Typelib IID's.
DEFINE_DTSDataPumpGUID(LIBID_DataPump, 10010200)
DP_FWD_DEFINE_INTERFACE(IDTSDataPumpColumns)
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpColumns, 10010201)
DP_FWD_DEFINE_INTERFACE(IDTSDataPumpColumn)
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpColumn, 10010202)
DEFINE_DTSDataPumpGUID(IID_IDTSErrorRecords, 10010203)
DP_FWD_DEFINE_INTERFACE(IDTSDataPumpLookups)
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpLookups, 10010204)
DP_FWD_DEFINE_INTERFACE(IDTSDataPumpLookup)
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpLookup, 10010205)
DP_FWD_DEFINE_INTERFACE(IDTSDataPumpLookupVariant)
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpLookupVariant, 10010206)
DP_FWD_DEFINE_INTERFACE(IDTSTransformPhaseInfo)
DEFINE_DTSDataPumpGUID(IID_IDTSTransformPhaseInfo, 10010207)
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpColumn2, 10010208)

// Repository Storage IIDs.
DEFINE_DTSDataPumpGUID(IID_IDTSRepositoryProvider, 100202F1)
DEFINE_DTSDataPumpGUID(IID_IDTSRepositoryStorage, 100202F2)

/////////////////////////////////////////////////////////////////////////////////
// Category id of DTS custom transforms.
/////////////////////////////////////////////////////////////////////////////////
DEFINE_DTSDataPumpGUID(CATID_DTSCustomXform, 10010100)	//we will use the same id as the pump clsid.

// Consumer-supplied classes and interfaces.
DP_FWD_DEFINE_INTERFACE(IDTSDataPumpTransform)
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpTransform, 10010300)

DP_FWD_DEFINE_INTERFACE(IDTSDataPumpErrorSink)
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpErrorSink, 10010301)

DP_FWD_DEFINE_INTERFACE(IDTSDataPumpProgressSink)
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpProgressSink, 10010302)

DP_FWD_DEFINE_INTERFACE(IDTSDataDrivenQuerySink)
DEFINE_DTSDataPumpGUID(IID_IDTSDataDrivenQuerySink, 10010303)

// Extended transform server interface.
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpTransform2, 10010304)

// DTSDataPump-supplied COM Transform Servers
// A "Transformation Server" coclass consists of:
//		coclass TTransformServer {
//			required IDTSDataPumpTransform;
//			optional IDTSDataPumpTransform2;
//
//			// The following are optional if the TransformServer has no custom
//			// properties requiring editing.  If it has, these are required.
//			optional <Custom OleAut properties interface>;
//			optional ISpecifyPropertyPages;
//				optional IPropertyPage;
//			optional IPersistPropertyBag;
//		}

// 7.0 progid, valid in 7.5 also.
#define Progid_DTSDataPumpTransformCopy			OLESTR("DTS.DataPumpTransformCopy")
// 7.0 sp2 and 7.5 preferred progid (now in typelib).
#define Progid_DTSPump_DataPumpTransformCopy	OLESTR("DTSPump.DataPumpTransformCopy")
DEFINE_DTSDataPumpGUID(CLSID_DTSDataPumpTransformCopy, 10010400)
DP_FWD_DEFINE_INTERFACE(IDTSDataPumpTransformCopyProperties)
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpTransformCopy, 10010401)
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpTransformCopyProperties, 10010402);

// 7.0 progid, valid in 7.5 also.
#define Progid_DTSDataPumpTransformScript		OLESTR("DTS.DataPumpTransformScript")
// 7.0 sp2 and 7.5 preferred progid (per typelib).
#define Progid_DTSPump_DataPumpTransformScript	OLESTR("DTSPump.DataPumpTransformScript")
DEFINE_DTSDataPumpGUID(CLSID_DTSDataPumpTransformScript, 10010501);
DP_FWD_DEFINE_INTERFACE(IDTSDataPumpTransformScriptProperties)
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpTransformScriptProperties, 10010502);
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpTransformScript, 10010503);
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpTransformScriptProperties2, 10010504);

//optional interface to be implemented by custom transform providers - used by DTS UI to configure the transforms
DEFINE_DTSDataPumpGUID(IID_IDTSCustomTransformUI, 10010601);

#define Progid_DTSPump_DataPumpTransformUpperString		OLESTR("DTSPump.DataPumpTransformUpperString")
DEFINE_DTSDataPumpGUID(CLSID_DTSDataPumpTransformUpperString, 10010701);
DP_FWD_DEFINE_INTERFACE(IDTSDataPumpTransformUpperStringProperties)
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpTransformUpperStringProperties, 10010702);
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpTransformUpperString, 10010703);

#define Progid_DTSPump_DataPumpTransformLowerString		OLESTR("DTSPump.DataPumpTransformLowerString")
DEFINE_DTSDataPumpGUID(CLSID_DTSDataPumpTransformLowerString, 10010801);
DP_FWD_DEFINE_INTERFACE(IDTSDataPumpTransformLowerStringProperties)
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpTransformLowerStringProperties, 10010802);
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpTransformLowerString, 10010803);

#define Progid_DTSPump_DataPumpTransformMidString		OLESTR("DTSPump.DataPumpTransformMidString")
DEFINE_DTSDataPumpGUID(CLSID_DTSDataPumpTransformMidString, 10010901);
DP_FWD_DEFINE_INTERFACE(IDTSDataPumpTransformMidStringProperties)
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpTransformMidStringProperties, 10010902);
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpTransformMidString, 10010903);

#define Progid_DTSPump_DataPumpTransformReadFile		OLESTR("DTSPump.DataPumpTransformReadFile")
DEFINE_DTSDataPumpGUID(CLSID_DTSDataPumpTransformReadFile, 10010a01);
DP_FWD_DEFINE_INTERFACE(IDTSDataPumpTransformReadFileProperties)
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpTransformReadFileProperties, 10010a02);
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpTransformReadFile, 10010a03);

#define Progid_DTSPump_DataPumpTransformDateTimeString	OLESTR("DTSPump.DataPumpTransformDateTimeString")
DEFINE_DTSDataPumpGUID(CLSID_DTSDataPumpTransformDateTimeString, 10010b01);
DP_FWD_DEFINE_INTERFACE(IDTSDataPumpTransformDateTimeStringProperties)
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpTransformDateTimeStringProperties, 10010b02);
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpTransformDateTimeString, 10010b03);

#define Progid_DTSPump_DataPumpTransformWriteFile		OLESTR("DTSPump.DataPumpTransformWriteFile")
DEFINE_DTSDataPumpGUID(CLSID_DTSDataPumpTransformWriteFile, 10010c01);
DP_FWD_DEFINE_INTERFACE(IDTSDataPumpTransformWriteFileProperties)
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpTransformWriteFileProperties, 10010c02);
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpTransformWriteFile, 10010c03);

#define Progid_DTSPump_DataPumpTransformTrimString		OLESTR("DTSPump.DataPumpTransformTrimString")
DEFINE_DTSDataPumpGUID(CLSID_DTSDataPumpTransformTrimString, 10010d01);
DP_FWD_DEFINE_INTERFACE(IDTSDataPumpTransformTrimStringProperties)
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpTransformTrimStringProperties, 10010d02);
DEFINE_DTSDataPumpGUID(IID_IDTSDataPumpTransformTrimString, 10010d03);


////////////////////////////////////////////////////////////////////////////////////////
//
//	DataPump-supplied Transform variables.
//
// These are passed to IDTSDataPumpTransform::AddVariable.  They are all of type
// VT_VARIANT.  IDTSErrorRecords (interface defined below) allows any transform
// to append OLEDB Error Records to IErrorInfo for the current thread.  The name
// "DTSErrorRecords" is what is passed to IDTSDataPumpTransform::AddVariable; the
// VT_DISPATCH ma be QI'd (or cast) to IDTSErrorRecords.  This object is also
// inserted into ActiveX Scripting namespaces invoked by the Pump.  All DTS-generated
// variables are inserted into ActiveX scripting namespaces as non-global variables
// (i.e. their methods must be qualified with the object name).
//
//		Name					Type
//		----					----
//		DTSError				DTS.Error
#define wzDTSErrorRecords	OLESTR("DTSErrorRecords")

//
// These are inserted by name into the global namespace of an ActiveX scripting transform.
// View the type library to see the type definitions.  Note that the return value from the
// method (FunctionEntry) must be an integral type.
//
//		Name					Type
//		----					----
//		DTSSource				DTS.Columns
//		DTSDestination			DTS.Columns
//		(return value)			adInt or adSmallInt (DTSTransformStatus)
//

//
// These are inserted by name into the global namespace of an ActiveX scripting transform,
// as well as being passed to IDTSDataPumpTransform::AddVariable.
//
//		Name					Type
//		----					----
//		DTSLookups				DTS.Lookups
#define wzDTSLookups		OLESTR("DTSLookups")

// These are the DTS-Package-supplied global variables, if the Pump is being run from
// the Package.
#define wzDTSGlobalVariables		OLESTR("DTSGlobalVariables")

// These are special pseudo-columnnames corresponding to Lineage.  They are also
// the names of the corresponding GlobalVariables; TransformCopy will automatically
// map them over to the specified destination column.  These names must not be used
// by source column names.
#define wzDTSLineage_FullString		OLESTR("DTSLineage_Full")
#define wzDTSLineage_IntegerCRC		OLESTR("DTSLineage_Short")

////////////////////////////////////////////////////////////////////////////////////////
//
//	Other ActiveX Transform objects.
//
//	These are inserted into the executing script's namespace.
//

// This makes the ProcessPhase pPhaseInfo parameter available within the script.
#define wzDTSTransformPhaseInfo		OLESTR("DTSTransformPhaseInfo")

////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////
//
//	DataPump-supplied interface definitions.
//
////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////
// IDTSDataPump - Primary interface to specify source and destination rowsets,
// add Transforms, and Execute() the transfer.  AddTransform will error if
// SetRowsets has not been called, and SetRowsets will error if any transforms
// have been added (because ValidateSchema has been done on them already).
// InitNew() reinitializes the IDTSDataPump object.  Execute returns E_FAIL if aborted,
// DB_E_ERRORSOCCURRED if max error count exceeded; DB_S_ERRORSOCCURRED if errors
// less than the max allowed occurred, possible provider-specific errors, or NOERROR
// if completed with no errors.
///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IDTSDataPump
DECLARE_INTERFACE_(INTERFACE, IUnknown)
{
	DTSDataPump_Unknown_Base()

	STDMETHOD(InitNew)(THIS) PURE;
	STDMETHOD(GetRowsets)(THIS_ 
			DP_OUT IRowset **ppSrcRowset,
			DP_OUT IRowsetChange **ppDestRowsetChange
		) PURE;
	STDMETHOD(SetRowsets)(THIS_ 
			DP_IN IRowset *pSrcRowset,							// Must be able to retrieve these rows
			DP_IN IRowsetChange *pDestRowsetChange				// Must have DBPROP_UPDATABILITY: DPBROP_UP_INSERT
		) PURE;
	STDMETHOD(SetProgressRowCount)(THIS_
			DP_IN ULONG cIn										// Interval for IDTSDataPumpProgressSink::OnIntervalComplete; default == 1000
		) PURE;
	STDMETHOD(SetMaximumErrorRowCount)(THIS_
			DP_IN ULONG cIn										// Maximum allowable error rows; default = 0 (abort on first error row).
		) PURE;
	STDMETHOD(SetFetchBufferSize)(THIS_
			DP_IN ULONG cIn										// Size of the GetNextRows HROW buffer (default = 1)
		) PURE;
	STDMETHOD(SetInsertCommitSize)(THIS_
			DP_IN ULONG cIn										// Number of successful InsertRows between "Commits", if supported by provider (default == 0; all rows in one batch).
		) PURE;
	STDMETHOD(AddTransform)(THIS_ 
			DP_IN LPCOLESTR pwzName,							// Transform name
			DP_IN LPBYTE pvUserData,							// Will be passed to Sink if event occurs on Transform.
			DP_IN LPCDTSTransformColumnsSpecification pColumns,	// Source and destination columns
			DP_IN DTSGuid ServerClsid,							// COM server ProgID or CLSID or IUnknown
			DP_IN VARIANT ServerParameters,						// Parameters to server for this transform
			DP_IN DTSTransformFlags dwFlags,					// Transformation column-validation flags
			DP_IN IStorage *pIStorage							// Pointer to persistent storage of Transform properties
		) PURE;
	STDMETHOD(AddTransformVariable)(THIS_ 
			DP_IN LPCOLESTR pwzName,							// Variable name
			DP_IN BOOL bGlobal,									// For ActiveX scripts, indicates whether this variable's
																// methods must be qualified by the object name.
			DP_IN VARIANT Variable								// Variable value; passed to and updatable by Transform
		) PURE;
	STDMETHOD(Execute)(THIS_ 
			DP_IN LPBYTE pvUserData,							// User data passed back to Sinks.
			DP_OUT ULARGE_INTEGER *puliRowsComplete,			// Total number of source rows processed (including those skipped).
			DP_OUT ULONG *pulErrorRows,							// Total number of error rows encountered.
			DP_OUT LPDTSExecuteStatus pExecStatus				// Pump return status.
		) PURE;
	STDMETHOD(SetFirstRow)(THIS_
			DP_IN ULARGE_INTEGER cIn							// First source row to copy. Default is 1 (first row).
		) PURE;
	STDMETHOD(SetLastRow)(THIS_
			DP_IN ULARGE_INTEGER cIn							// Last source row to copy. Default is 0 (copy all rows).
		) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSDataPump2
DECLARE_INTERFACE_(INTERFACE, IDTSDataPump)
{
#ifndef NO_BASEINTERFACE_FUNCS
	DTSDataPump_Unknown_Base()

	STDMETHOD(InitNew)(THIS) PURE;
	STDMETHOD(GetRowsets)(THIS_ 
			DP_OUT IRowset **ppSrcRowset,
			DP_OUT IRowsetChange **ppDestRowsetChange
		) PURE;
	STDMETHOD(SetRowsets)(THIS_ 
			DP_IN IRowset *pSrcRowset,							// Must be able to retrieve these rows
			DP_IN IRowsetChange *pDestRowsetChange				// Must have DBPROP_UPDATABILITY: DPBROP_UP_INSERT
		) PURE;
	STDMETHOD(SetProgressRowCount)(THIS_
			DP_IN ULONG cIn										// Interval for IDTSDataPumpProgressSink::OnIntervalComplete; default == 1000
		) PURE;
	STDMETHOD(SetMaximumErrorRowCount)(THIS_
			DP_IN ULONG cIn										// Maximum allowable error rows; default = 0 (abort on first error row).
		) PURE;
	STDMETHOD(SetFetchBufferSize)(THIS_
			DP_IN ULONG cIn										// Size of the GetNextRows HROW buffer (default = 1)
		) PURE;
	STDMETHOD(SetInsertCommitSize)(THIS_
			DP_IN ULONG cIn										// Number of successful InsertRows between "Commits", if supported by provider (default == 0; all rows in one batch).
		) PURE;
	STDMETHOD(AddTransform)(THIS_ 
			DP_IN LPCOLESTR pwzName,							// Transform name
			DP_IN LPBYTE pvUserData,							// Will be passed to Sink if event occurs on Transform.
			DP_IN LPCDTSTransformColumnsSpecification pColumns,	// Source and destination columns
			DP_IN DTSGuid ServerClsid,							// COM server ProgID or CLSID or IUnknown
			DP_IN VARIANT ServerParameters,						// Parameters to server for this transform
			DP_IN DTSTransformFlags dwFlags,					// Transformation column-validation flags
			DP_IN IStorage *pIStorage							// Pointer to persistent storage of Transform properties
		) PURE;
	STDMETHOD(AddTransformVariable)(THIS_ 
			DP_IN LPCOLESTR pwzName,							// Variable name
			DP_IN BOOL bGlobal,									// For ActiveX scripts, indicates whether this variable's
																// methods must be qualified by the object name.
			DP_IN VARIANT Variable								// Variable value; passed to and updatable by Transform
		) PURE;
	STDMETHOD(Execute)(THIS_ 
			DP_IN LPBYTE pvUserData,							// User data passed back to Sinks.
			DP_OUT ULARGE_INTEGER *puliRowsComplete,			// Total number of source rows processed (including those skipped).
			DP_OUT ULONG *pulErrorRows,							// Total number of error rows encountered.
			DP_OUT LPDTSExecuteStatus pExecStatus				// Pump return status.
		) PURE;
	STDMETHOD(SetFirstRow)(THIS_
			DP_IN ULARGE_INTEGER cIn							// First source row to copy. Default is 1 (first row).
		) PURE;
	STDMETHOD(SetLastRow)(THIS_
			DP_IN ULARGE_INTEGER cIn							// Last source row to copy. Default is 0 (copy all rows).
		) PURE;
#endif // NO_BASEINTERFACE_FUNCS

	// Allow for single-row execution.  Caller must call at least ExecuteInit, ExecuteRow (loop), and
	// ExecuteComplete.  If ExecuteComplete is not called, Insert batches may not be completed successfully
	// and TransformServers may not be correctly cleaned up.  GetExecuteInfo may be called at any point
	// after ExecuteInit.
	STDMETHOD(ExecuteInit)(THIS_ 
			DP_IN LPBYTE pvUserData,							// User data passed back to Sinks.
			DP_OUT BOOL *pbEndOfRowset,							// Set TRUE if at end of source rowset.
			DP_INOUT LPDTSExecuteInfo pExecInfo					// Execution info to be initialized
		) PURE;

	// This executes a single row.  If MaximumErrorRowCount is > 0, it will continue
	// trying until success or MaximumErrorRowCount is exceeded.
	STDMETHOD(ExecuteRow)(THIS_
			DP_OUT BOOL *pbEndOfRowset,							// Set TRUE if at end of source rowset.
			DP_INOUT LPDTSExecuteInfo pExecInfo					// Execution info to be filled in on DB_S_ENDOFROWSET
		) PURE;
	STDMETHOD(ExecuteComplete)(THIS_							// Returns completion HRESULT from ExecuteRow series
			DP_INOUT LPDTSExecuteInfo pExecInfo					// Execution info to be filled in on DB_S_ENDOFROWSET
		) PURE;
	STDMETHOD(GetExecuteInfo)(THIS_
			DP_INOUT LPDTSExecuteInfo pExecInfo					// Execution info to be filled in on DB_S_ENDOFROWSET
		) PURE;

	// Some transforms may generate thread-specific state which requires cleanup to be executed on that thread.
	// If ExecuteInit or ExecuteRow is executed on a worker thread which is not the same as ExecuteComplete,
	// SetExecuteThreadComplete must be called on all such threads when they have completed their operations
	// (prior to ExecuteComplete).  The sequence of one or more ExecuteRow calls followed by SetExecuteThreadComplete
	// may be done multiple times for the same thread.  Currently this is specific to the ActiveScript Transform, due
	// to this requirement for IActiveScript::Close().  This method is ignored for threads for which no state exists.
	// Note that because IActiveScript execution state cannot be transferred across threads, any variables
	// in the script, including "global variables" outside function scope, will be independent across multiple
	// threads calling ExecuteRow.  Calling this method calls SetExecuteThreadComplete on all TransformServers
	// supporting the IDTSDataPumpTransform2 interface.
	STDMETHOD(SetExecuteThreadComplete)(THIS) PURE;

	// Adds a new Transform with extended (multiphase) capability.
	STDMETHOD(AddTransform2)(THIS_ 
			DP_IN LPCOLESTR pwzName,							// Transform name
			DP_IN LPBYTE pvUserData,							// Will be passed to Sink if event occurs on Transform.
			DP_IN LPCDTSTransformColumnsSpecification pColumns,	// Source and destination columns
			DP_IN DTSGuid ServerClsid,							// COM server ProgID or CLSID or IUnknown
			DP_IN VARIANT ServerParameters,						// Parameters to server for this transform
			DP_IN DTSTransformFlags dwFlags,					// Transformation column-validation flags
			DP_IN DTSTransformPhaseEnum ePhases,				// Phase(s) for which this Transform is to be called.
			DP_IN IStorage *pIStorage							// Pointer to persistent storage of Transform properties
		) PURE;

	// Sets extended options on the DataPump interface.
	STDMETHOD(SetOptions)(THIS_
			DP_IN DTSDataPumpOptions eOptions					// Additional options
		) PURE;
	STDMETHOD(GetOptions)(THIS_
			DP_IN LPDTSDataPumpOptions peOptions				// Additional options
		) PURE;
};

///////////////////////////////////////
// IDTSDataDrivenQuery - Allows specification of individual queries instead
// of simple Insert at the Destination.  QI'd from IDTSDataPump.
///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IDTSDataDrivenQuery
DECLARE_INTERFACE_(IDTSDataDrivenQuery, IUnknown)
{
	DTSDataPump_Unknown_Base()

	// The following four pairs of properties and methods should be called in the
	// order listed.

	// Specify and retrieve the source rowset from which data will be read.
	STDMETHOD(SetSourceRowset)(THIS_ 
			DP_IN IRowset *pSrcRowset
		) PURE;
	STDMETHOD(GetSourceRowset)(THIS_ 
			DP_OUT IRowset **ppSrcRowset
		) PURE;

	// Specify and retrieve the destination session and column schema; this defines how the
	// parameters to the queries will be bound.  Specifying the schema is done in one of two ways:
	//	- If cColumnDescs is 0, then rgColumnDescs is ignored and pDestConnection must
	//	  be a Rowset.  Rowset information will be retrieved, but the Rowset itself will not
	//	  be retained.  The Session will be retrieved from the Rowset and retained.
	//	- If cColumnDescs is not 0, then rgColumnDescs must not be NULL and pDestConnection
	//	  must be a Session.  The destination column definitions are created from the DBCOLUMNDESCs.
	//
	STDMETHOD(SetDestinationInfo)(THIS_
			DP_IN IUnknown *pDestConnection,
			DP_IN ULONG cColumnDescs,
			DP_IN DBCOLUMNDESC rgColumnDescs[]
		) PURE;
	// pcColumns, prgInfo, and ppStringsBuffer are allocated as in IColumnsInfo::GetColumnInfo.
	STDMETHOD(GetDestinationInfo)(THIS_
			DP_IN REFIID riidSession, 
			DP_OUT IUnknown **ppIUnkSession,
			DP_OUT ULONG *pcColumns,
			DP_OUT DBCOLUMNINFO **prgInfo,
			DP_OUT OLECHAR **ppStringsBuffer
		) PURE;

	// Specify and retrieve the destination queries and their column mappings to parameters.
	// Unused queries may be NULL, in which case a Transform return status of DTSTransformStat_*Query
	// indicating an unset query will result in an error.
	STDMETHOD(SetDestinationQueries)(THIS_ 
			DP_IN LPCDTSTransformQuerySpecification pInsertQuerySpec,
			DP_IN LPCDTSTransformQuerySpecification pUpdateQuerySpec,
			DP_IN LPCDTSTransformQuerySpecification pDeleteQuerySpec,
			DP_IN LPCDTSTransformQuerySpecification pUserQuerySpec
		) PURE;
	// Each pointer is a single CoTaskMemAlloc containing space for the base QuerySpecification structure,
	// the array of column info, and the string buffer.  Internal pointers are based (with alignment)
	// according to this allocated space.
	STDMETHOD(GetDestinationQueries)(THIS_ 
			DP_OUT LPDTSTransformQuerySpecification *ppInsertQuerySpec,
			DP_OUT LPDTSTransformQuerySpecification *ppUpdateQuerySpec,
			DP_OUT LPDTSTransformQuerySpecification *ppDeleteQuerySpec,
			DP_OUT LPDTSTransformQuerySpecification *ppUserQuerySpec
		) PURE;
};

///////////////////////////////////////
// IDTSDataPumpLookups - Allows specification of Lookups for TransformServer use.
///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IDTSDataPumpSpecifyLookups
DECLARE_INTERFACE_(IDTSDataPumpSpecifyLookups, IUnknown)
{
	DTSDataPump_Unknown_Base()

	// Specify and retrieve the lookup specifications for this DataPump instance.
	STDMETHOD(SetLookups)(THIS_ 
			DP_IN ULONG cLookups,
			DP_IN LPCDTSTransformLookupSpecification pLookups
		) PURE;
	// The pointer is a single CoTaskMemAlloc containing space for the base LookupSpecification structure
	// and the string buffer.  Internal pointers are based (with alignment) according to this allocated space.
	// pIUnkSession is AddRef'd and must be released.
	STDMETHOD(GetLookups)(THIS_ 
			DP_IN ULONG *pcLookups,
			DP_IN LPDTSTransformLookupSpecification *ppLookups
		) PURE;
};

///////////////////////////////////////
// IDTSDataConvert - The DTS data-conversion interface.
///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IDTSDataConvert
DECLARE_INTERFACE_(IDTSDataConvert, IDataConvert)
{
	DTSDataPump_Unknown_Base()

	//////////////////////////////////////////////////////
	// IDataConvert interface members (msdadc.h required).
	//////////////////////////////////////////////////////

	// Copies or converts data from one DBTYPE to another.  If wDstType includes DBTYPE_BYREF,
	// it must be a variable-length type (DBTYPE_((W)STR|BYTES)) or this method will error.
	// Otherwise, for all DBTYPE_BYREF destination conversions, this method CoTaskMemAlloc(s)
	// the destination data pointer, and it is the caller's responsibility to CoTaskMemFree it.
	// This method should not be used to place data into the DataPump's destination binding;
	// instead, use the ConvertToBinding method.
	STDMETHOD(DataConvert)( 
			DP_IN DBTYPE wSrcType,
			DP_IN DBTYPE wDstType,
			DP_IN ULONG cbSrcLength,
			DP_INOUT ULONG *pcbDstLength,
			DP_IN void *pSrc,
			DP_OUT void *pDst,
			DP_IN ULONG cbDstMaxLength,
			DP_IN DBSTATUS dbsSrcStatus,
			DP_OUT DBSTATUS *pdbsStatus,
			DP_IN BYTE bPrecision,
			DP_IN BYTE bScale,
			DP_IN DBDATACONVERT dwFlags
		) PURE;

	// Determines if two types are potentially compatible.  See GetConvertFlags
	// for more detailed information about what the conversion may encounter.
	STDMETHOD(CanConvert)( 
			DP_IN DBTYPE wSrcType,
			DP_IN DBTYPE wDstType
		) PURE;

	// Returns the required conversion size in bytes.  May base this on pcbSrcLength
	// and/or pSrc, if supplied, to get per-data-item information.
	//
	// DBTYPE_BSTR is considered a fixed type; its binding length is sizeof(BSTR).
	// To determine the length necessary to pre-allocate a BSTR, pass in DBTYPE_STR
	// for the destination type - for this type, character count == byte count.
	// Alternatively, use WSTR and divide the return by sizeof(WCHAR).
	//
	STDMETHOD(GetConversionSize)( 
			DP_IN DBTYPE wSrcType,
			DP_IN DBTYPE wDstType,
			DP_IN ULONG *pcbSrcLength,
			DP_OUT ULONG *pcbDstLength,
			DP_IN void *pSrc
		) PURE;

	//////////////////////////////////////////////////////
	// DTS extensions.
	//////////////////////////////////////////////////////

	// This method first calls CanConvert() to determine if the conversion can succeed at all
	// given the source and destination datatypes, and if so, returns extended information about
	// how (or if) the conversion can proceed after that.
	// It uses the following fields for source and destination (S and D):
	//	DBCOLUMNINFO - validates all conversion info between columns.
	//		dwFlags					S,D
	//		ulColumnSize			S,D
	//		wType					S,D
	//		bPrecision				S,D
	//		bScale					S,D
	//	Fields other than dwFlags and wType can be zero'd and the output ConvertFlags
	//	tested for the Unsupported bit if length validation is not required.
	// Note that this does not set a flag for nontext <-> text if the text length is
	// sufficient to accommodate it; this is because all such conversions should be valid
	// If this level of exactness is required, simply compare the datatypes for equality.
	STDMETHOD(GetConvertFlags)(
			DP_IN const DBCOLUMNINFO *pSrcColumnInfo,		// Source column metadata
			DP_IN const DBCOLUMNINFO *pDestColumnInfo,		// Destination column metadata
			DP_OUT DTSConvertFlags *pConvertFlags			// Output conversion flags
		) PURE;

	// This method allows the Transform Server to convert source data (which may come from
	// the source binding directly, as in the comment examples, or from ad-hoc source data).
	// It uses the following fields in the destination binding (S is fields that are used
	// from a source binding if that is how the source data is stored):
	//	DBBINDING:
	//		obValue					S,D		-- must be bound
	//		obLength				S,D		-- must be bound
	//		obStatus				S,D		-- must be bound
	//		dwPart					S,D		-- must include length, value, status
	//		cbMaxLen				D
	//		wType					S,D
	//		bPrecision				D
	//		bScale					D
	//
	// The destination data is set according to eTransformFlags and pDestBind->dwMemOwner, which
	// is handled as follows:
	//
	// DBMEMOWNER_CLIENTOWNED: normal conversion is done; data is copied from source to destination,
	//		converted as needed, and allocations are done as needed.  Specifically:
	//			BSTR data is deep-copied
	//			BYREF destination data is copied into a CoTaskMemAlloc()'d pointer.
	//			IUnknown and IDispatch pointers are AddRef()'d.
	//		The destination binding data must always be free'd.  The foregoing lists what is freed
	//		(or Release()'d) by IDTSDataConvert::ClearBindingData.
	//
	// DBMEMOWNER_PROVIDEROWNED:  Conversion will attempt to shallow-copy data, avoiding allocations.
	//		This requires that the source and destination datatypes be identical (except for DBTYPE_BYREF).
	//		This is intended as a performance enhancement and requires that the source data remain stable
	//		for the lifetime of the Destination binding (such as while being inserted via the DataPump).
	//		It handles only the following cases:
	//			If the destination type includes DBTYPE_BYREF	// it must therefore be ((W)STR|BYTES)
	//				*pvDestData = pvSrcData (or *pvSrcData if source type is BYREF)
	//				StringTruncation is performed by adjusting destination datalength
	//			else if destination type is BSTR
	//				*pvDestData = *pvSrcData (or **pvSrcData if source type is BYREF)
	//				StringTruncation is NOT checked here as this is a fixed-length datatype
	//			else 
	//				Normal conversion is done, including:
	//					AddRefs of IDispatch/IUnknown pointers
	//					VariantCopy (OLEDB behaviour does not allow PROVIDEROWNED Variant binding).
	// DBMEMOWNER_PROVIDEROWNED binding data will not be freed by IDTSDataConvert::ClearBindingData.
	// If a custom allocator is used for BYREF destination data, then it must be freed by a corresponding
	// custom deallocator, rather than by ClearBindingData.  Therefore, it should be bound ProviderOwned;
	// the pointer will be shallow-copied into the binding by IDTSDataConvert::ConvertToBinding.
	//
	STDMETHOD(ConvertToBinding)(
			DP_IN DBTYPE wSrcType,							// Source datatype:  e.g. pSrcBind->wType
			DP_IN ULONG cbSrcLength,						// Source data length:  e.g. *(reinterpret_cast<ULONG *>(pSrcColumnInfo->pvRowData + pSrcBind->obLength));
			DP_IN DBSTATUS dbsSrcStatus,					// Source data status:  e.g. *(reinterpret_cast<DBSTATUS *>(pSrcColumnInfo->pvRowData + pSrcBind->obStatus));
			DP_IN const BYTE *pvSrcColData,					// Source column data: e.g. pSrcColumnInfo->pvRowData + pSrcBind->obValue;
			DP_IN const DBBINDING *pDestBind,				// Dest binding info
			DP_IN BYTE *pvDestRowData,						// Dest row data; NOT obValue-offset as the Binding will reference it 3 ways (obLength, obValue, obStatus)
			DP_IN DBCOLUMNFLAGS dwDestColumnFlags,			// Dest flags such as nullability
			DP_IN ULONG ulDestColumnSize,					// If nonzero and Dest is BYREF, tested for String Truncation
			DP_IN DTSTransformFlags eTransformFlags			// Transformation flags.  Currently considered:
															//		DTSTransformFlag_AllowStringTruncation
															//		DTSTransformFlag_ForceConvert as it applies to foregoing
		) PURE;

	// This method frees any CLIENTOWNED allocations in the Binding, as discussed in ConvertToBinding.
	// This method always sets length to 0 and status to DBSTATUS_S_ISNULL, and can zeroinit if specified.
	STDMETHOD(ClearBindingData)(
			DP_IN const DBBINDING *pDestBind,				// Dest binding info
			DP_IN BYTE *pvDestRowData,						// Dest row data; NOT obValue-offset as the Binding will reference it 3 ways (obLength, obValue, obStatus)
			DP_IN BOOL bZeroInit							// If TRUE, zero's the data value
		) PURE;
};

///////////////////////////////////////
// IDTSErrorRecords - Allows the caller to append OLEDB Error Records to the current
// thread's IErrorInfo.  The Error Lookup Service is CLSID_DTSErrorLookup.
// This interface is derived from IDispatch and may be used in ActiveX Scripts as
// well as from C/C++.
///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IDTSErrorRecords
DECLARE_INTERFACE_(IDTSErrorRecords, DTSDataPump_IDispatch)
{
	DTSDataPump_Dispatch_Base(IDTSErrorRecords)

    STDMETHOD(Clear)(THIS) PURE;
	STDMETHOD(Add)(THIS_ DP_IN long Number,
				DP_IN long NativeError,
				DP_IN BSTR Description,
				DP_IN BSTR Source,
				DP_IN BSTR Helpfile,
				DP_IN long Helpid
			) PURE;
};

///////////////////////////////////////
// IDTSDataPumpColumns - Columns collection as exposed to AxScript.
// We expose DTSSource and DTSDestination collections.
// This interface is derived from IDispatch and may be used in ActiveX Scripts as
// well as from C/C++.  This is identical to the ADO.Field interface.
///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IDTSDataPumpColumns
DECLARE_INTERFACE_(IDTSDataPumpColumns, DTSDataPump_IDispatch)
{
	DTSDataPump_Dispatch_Base(IDTSDataPumpColumns)

	STDMETHOD(Item)(THIS_ DP_IN VARIANT Index, DP_OUT IDTSDataPumpColumn **pRetVal) PURE;
    STDMETHOD(get__NewEnum)(THIS_ DP_OUT IUnknown **ppEnum) PURE;
    STDMETHOD(get_Count)(THIS_ DP_OUT long *pRetVal) PURE;
};

///////////////////////////////////////
// IDTSDataPumpColumn - Column object as exposed to AxScript.
// These objects make up the DTSSource and DTSDestination collections.
// They provide access to the column value and its metadata
// This interface is derived from IDispatch and may be used in ActiveX Scripts as
// well as from C/C++.  This is identical to the ADO.Field interface.
///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IDTSDataPumpColumn
DECLARE_INTERFACE_(IDTSDataPumpColumn, DTSDataPump_IDispatch)
{
	DTSDataPump_Dispatch_Base_2b(IDTSDataPumpColumn)

    STDMETHOD(get_Value)(THIS_ DP_OUT VARIANT *pRetVal) PURE;
    STDMETHOD(put_Value)(THIS_ DP_IN VARIANT NewValue) PURE;
    STDMETHOD(get_ActualSize)(THIS_ DP_OUT long  *pl) PURE;
    STDMETHOD(get_Attributes)(THIS_ DP_OUT long  *pl) PURE;
    STDMETHOD(get_DefinedSize)(THIS_ DP_OUT long  *pl) PURE;
    STDMETHOD(get_Name)(THIS_ DP_OUT BSTR  *pbstr) PURE;
    STDMETHOD(get_Type)(THIS_ DP_OUT long  *pDataType) PURE;
    STDMETHOD(get_Precision)(THIS_ DP_OUT BYTE  *pbPrecision) PURE;
    STDMETHOD(get_NumericScale)(THIS_ DP_OUT BYTE  *pbNumericScale) PURE;
    STDMETHOD(get_OriginalValue)(THIS_ DP_OUT VARIANT  *pvar) PURE;
    STDMETHOD(get_UnderlyingValue)(THIS_ DP_OUT VARIANT  *pvar) PURE;
    STDMETHOD(AppendChunk)(THIS_ DP_IN VARIANT Data) PURE;
    STDMETHOD(GetChunk)(THIS_ DP_IN long Length, DP_OUT VARIANT  *pvar) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSDataPumpColumn2
DECLARE_INTERFACE_(INTERFACE, IDTSDataPumpColumn)
{
#ifndef NO_BASEINTERFACE_FUNCS
	DTSDataPump_Dispatch_Base_2d(IDTSDataPumpColumn2)

    STDMETHOD(get_Value)(THIS_ DP_OUT VARIANT *pRetVal) PURE;
    STDMETHOD(put_Value)(THIS_ DP_IN VARIANT NewValue) PURE;
    STDMETHOD(get_ActualSize)(THIS_ DP_OUT long  *pl) PURE;
    STDMETHOD(get_Attributes)(THIS_ DP_OUT long  *pl) PURE;
    STDMETHOD(get_DefinedSize)(THIS_ DP_OUT long  *pl) PURE;
    STDMETHOD(get_Name)(THIS_ DP_OUT BSTR  *pbstr) PURE;
    STDMETHOD(get_Type)(THIS_ DP_OUT long  *pDataType) PURE;
    STDMETHOD(get_Precision)(THIS_ DP_OUT BYTE  *pbPrecision) PURE;
    STDMETHOD(get_NumericScale)(THIS_ DP_OUT BYTE  *pbNumericScale) PURE;
    STDMETHOD(get_OriginalValue)(THIS_ DP_OUT VARIANT  *pvar) PURE;
    STDMETHOD(get_UnderlyingValue)(THIS_ DP_OUT VARIANT  *pvar) PURE;
    STDMETHOD(AppendChunk)(THIS_ DP_IN VARIANT Data) PURE;
    STDMETHOD(GetChunk)(THIS_ DP_IN long Length, DP_OUT VARIANT  *pvar) PURE;
#endif // NO_BASEINTERFACE_FUNCS

    STDMETHOD(get_Status)(THIS_ DP_OUT long  *pl) PURE;
};

///////////////////////////////////////
// IDTSDataPumpLookups - Lookups collection as exposed to AxScript.
// We expose DTSLookups as a collection.
// This interface is derived from IDispatch and may be used in ActiveX Scripts as
// well as from C/C++.
///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IDTSDataPumpLookups
DECLARE_INTERFACE_(IDTSDataPumpLookups, DTSDataPump_IDispatch)
{
	DTSDataPump_Dispatch_Base(IDTSDataPumpLookups)

	STDMETHOD(Item)(THIS_ DP_IN VARIANT Index, DP_OUT IDTSDataPumpLookup **pRetVal) PURE;
    STDMETHOD(Get_NewEnum)(THIS_ DP_OUT IUnknown **ppEnum) PURE;
    STDMETHOD(GetCount)(THIS_ DP_OUT long *pRetVal) PURE;
};

///////////////////////////////////////
// IDTSDataPumpLookup - Lookup object as exposed to AxScript.
// These objects make up the DTSLookups collection.
// This interface is derived from IDispatch and may be used in ActiveX Scripts as
// well as from C/C++.  The KeyValues input parameter to the methods is a SafeArray
// of Variant, using the vararg attribute on the methods, for best use in ActiveX
// scripts.  The return value is a variant (if single-valued) or an array of variants
// (if multi-valued) corresponding to the sequence of columns in the single output
// row resulting from execution of the query.  If multiple rows are returned, only
// the first is returned in the output variant.  LastRowCount is used in case an
// app wants to assert that only one row was returned.
///////////////////////////////////////

// This form is understood by scripting languages to take a variable number of
// arguments in the key values specification.  It can be used from C++ as well.
#undef INTERFACE
#define INTERFACE IDTSDataPumpLookup
DECLARE_INTERFACE_(IDTSDataPumpLookup, DTSDataPump_IDispatch)
{
	DTSDataPump_Dispatch_Base(IDTSDataPumpLookup)

    STDMETHOD(get_Name)(THIS_ DP_OUT BSTR  *pbstr) PURE;
	STDMETHOD(get_LastRowCount)(THIS_ LONG *pRetVal) PURE;
    STDMETHOD(Execute)(THIS_ DP_IN SAFEARRAY * KeyValues, DP_OUT VARIANT *pRetVal) PURE;
    STDMETHOD(AddToCache)(THIS_ DP_IN VARIANT DataValues, DP_IN SAFEARRAY * KeyValues) PURE;
    STDMETHOD(RemoveFromCache)(THIS_ DP_IN SAFEARRAY * KeyValues) PURE;
};

// This is a form of the interface which takes a single Variant, more convenient
// for C++ programs which know they'll only have a single key column.  The variant
// may be a single value or may itself contain a safearray.
#undef INTERFACE
#define INTERFACE IDTSDataPumpLookupVariant
DECLARE_INTERFACE_(IDTSDataPumpLookupVariant, IUnknown)
{
    STDMETHOD(Execute)(THIS_ DP_IN VARIANT KeyValues, DP_OUT VARIANT *pRetVal) PURE;
    STDMETHOD(AddToCache)(THIS_ DP_IN VARIANT DataValues, DP_IN VARIANT KeyValues) PURE;
    STDMETHOD(RemoveFromCache)(THIS_ DP_IN VARIANT KeyValues) PURE;
};

///////////////////////////////////////
// IDTSTransformPhaseInfo - Wraps the DTSTransformPhaseInfo for AxScript.
///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IDTSTransformPhaseInfo
DECLARE_INTERFACE_(IDTSTransformPhaseInfo, DTSDataPump_IDispatch)
{
	DTSDataPump_Dispatch_Base(IDTSTransformPhaseInfo)

    STDMETHOD(get_CurrentSourceRow)(THIS_ DP_OUT VARIANT *pRetVal) PURE;
    STDMETHOD(get_DestinationRowsComplete)(THIS_ DP_OUT VARIANT *pRetVal) PURE;
    STDMETHOD(get_ErrorRows)(THIS_ DP_OUT VARIANT *pRetVal) PURE;
	STDMETHOD(get_ErrorCode)(THIS_ LONG *pRetVal) PURE;
	STDMETHOD(get_TransformStatus)(THIS_ DTSTransformStatus *pRetVal) PURE;
	STDMETHOD(get_CurrentPhase)(THIS_ DTSTransformPhaseEnum *pRetVal) PURE;
};

////////////////////////////////////////////////////////////////////////////////////////
//
//	Pump-supplied Transform custom-property interfaces.
//
////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////
// IDTSDataPumpTransformScriptProperties - Sets custom properties for the
// ActiveX scripting transformation server.
///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IDTSDataPumpTransformScriptProperties
DECLARE_INTERFACE_(IDTSDataPumpTransformScriptProperties, DTSDataPump_IDispatch)
{
	DTSDataPump_Dispatch_Base_2b(IDTSDataPumpTransformScriptProperties)

	STDMETHOD(GetText)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetText)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetLanguage)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetLanguage)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetFunctionEntry)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetFunctionEntry)(THIS_ DP_IN BSTR NewValue) PURE;
};

#undef INTERFACE
#define INTERFACE IDTSDataPumpTransformScriptProperties2
DECLARE_INTERFACE_(INTERFACE, IDTSDataPumpTransformScriptProperties)
{
#ifndef NO_BASEINTERFACE_FUNCS
	DTSDataPump_Dispatch_Base_2d(IDTSDataPumpTransformScriptProperties2)

	STDMETHOD(GetText)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetText)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetLanguage)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetLanguage)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetFunctionEntry)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetFunctionEntry)(THIS_ DP_IN BSTR NewValue) PURE;
#endif // NO_BASEINTERFACE_FUNCS

	STDMETHOD(GetPreSourceDataFunctionEntry)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetPreSourceDataFunctionEntry)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetPostSourceDataFunctionEntry)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetPostSourceDataFunctionEntry)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetTransformFailureFunctionEntry)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetTransformFailureFunctionEntry)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetInsertSuccessFunctionEntry)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetInsertSuccessFunctionEntry)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetInsertFailureFunctionEntry)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetInsertFailureFunctionEntry)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetBatchCompleteFunctionEntry)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetBatchCompleteFunctionEntry)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetPumpCompleteFunctionEntry)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetPumpCompleteFunctionEntry)(THIS_ DP_IN BSTR NewValue) PURE;
};

///////////////////////////////////////
// IDTSDataPumpTransformCopyProperties - Sets custom properties for the
// Copy transformation server.
///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IDTSDataPumpTransformCopyProperties
DECLARE_INTERFACE_(IDTSDataPumpTransformCopyProperties, DTSDataPump_IDispatch)
{
	DTSDataPump_Dispatch_Base(IDTSDataPumpTransformCopyProperties)
};

///////////////////////////////////////
// IDTSDataPumpTransformUpperStringProperties - Sets custom properties for the
// UpperString transformation server.
///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IDTSDataPumpTransformUpperStringProperties
DECLARE_INTERFACE_(IDTSDataPumpTransformUpperStringProperties, DTSDataPump_IDispatch)
{
	DTSDataPump_Dispatch_Base(IDTSDataPumpTransformUpperStringProperties)
};

///////////////////////////////////////
// IDTSDataPumpTransformLowerStringProperties - Sets custom properties for the
// LowerString transformation server.
///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IDTSDataPumpTransformLowerStringProperties
DECLARE_INTERFACE_(IDTSDataPumpTransformLowerStringProperties, DTSDataPump_IDispatch)
{
	DTSDataPump_Dispatch_Base(IDTSDataPumpTransformLowerStringProperties)
};

///////////////////////////////////////
// IDTSDataPumpTransformMidStringProperties - Sets custom properties for the
// MidString transformation server.
///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IDTSDataPumpTransformMidStringProperties
DECLARE_INTERFACE_(IDTSDataPumpTransformMidStringProperties, DTSDataPump_IDispatch)
{
	DTSDataPump_Dispatch_Base(IDTSDataPumpTransformMidStringProperties)

	STDMETHOD(GetCharacterStart)(THIS_ DP_OUT LONG *pRetVal) PURE;
	STDMETHOD(SetCharacterStart)(THIS_ DP_IN LONG NewValue) PURE;
	STDMETHOD(GetCharacterCount)(THIS_ DP_OUT LONG *pRetVal) PURE;
	STDMETHOD(SetCharacterCount)(THIS_ DP_IN LONG NewValue) PURE;
	STDMETHOD(GetTrimLeadingWhiteSpace)(THIS_ DP_OUT VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetTrimLeadingWhiteSpace)(THIS_ DP_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetTrimTrailingWhiteSpace)(THIS_ DP_OUT VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetTrimTrailingWhiteSpace)(THIS_ DP_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetTrimEmbeddedWhiteSpace)(THIS_ DP_OUT VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetTrimEmbeddedWhiteSpace)(THIS_ DP_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetUpperCaseString)(THIS_ DP_OUT VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetUpperCaseString)(THIS_ DP_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetLowerCaseString)(THIS_ DP_OUT VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetLowerCaseString)(THIS_ DP_IN VARIANT_BOOL NewValue) PURE;
};

///////////////////////////////////////
// IDTSDataPumpTransformTrimStringProperties - Sets custom properties for the
// MidString transformation server.
///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IDTSDataPumpTransformTrimStringProperties
DECLARE_INTERFACE_(IDTSDataPumpTransformTrimStringProperties, DTSDataPump_IDispatch)
{
	DTSDataPump_Dispatch_Base(IDTSDataPumpTransformTrimStringProperties)

	STDMETHOD(GetTrimLeadingWhiteSpace)(THIS_ DP_OUT VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetTrimLeadingWhiteSpace)(THIS_ DP_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetTrimTrailingWhiteSpace)(THIS_ DP_OUT VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetTrimTrailingWhiteSpace)(THIS_ DP_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetTrimEmbeddedWhiteSpace)(THIS_ DP_OUT VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetTrimEmbeddedWhiteSpace)(THIS_ DP_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetUpperCaseString)(THIS_ DP_OUT VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetUpperCaseString)(THIS_ DP_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetLowerCaseString)(THIS_ DP_OUT VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetLowerCaseString)(THIS_ DP_IN VARIANT_BOOL NewValue) PURE;
};

///////////////////////////////////////
// IDTSDataPumpTransformReadFileProperties - Sets custom properties for the
// ReadFile transformation server.
///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IDTSDataPumpTransformReadFileProperties
DECLARE_INTERFACE_(IDTSDataPumpTransformReadFileProperties, DTSDataPump_IDispatch)
{
	DTSDataPump_Dispatch_Base(IDTSDataPumpTransformReadFileProperties)

	STDMETHOD(GetErrorIfFileNotFound)(THIS_ DP_OUT VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetErrorIfFileNotFound)(THIS_ DP_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetFilePath)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetFilePath)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetUnicodeFile)(THIS_ DP_OUT VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetUnicodeFile)(THIS_ DP_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetOEMFile)(THIS_ DP_OUT VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetOEMFile)(THIS_ DP_IN VARIANT_BOOL NewValue) PURE;
};

///////////////////////////////////////
// IDTSDataPumpTransformWriteFileProperties - Sets custom properties for the
// WriteFile transformation server.
///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IDTSDataPumpTransformWriteFileProperties
DECLARE_INTERFACE_(IDTSDataPumpTransformWriteFileProperties, DTSDataPump_IDispatch)
{
	DTSDataPump_Dispatch_Base(IDTSDataPumpTransformWriteFileProperties)

	STDMETHOD(GetErrorIfFileExists)(THIS_ DP_OUT VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetErrorIfFileExists)(THIS_ DP_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetAppendIfFileExists)(THIS_ DP_OUT VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetAppendIfFileExists)(THIS_ DP_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetFilePath)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetFilePath)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetFileColumnName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetFileColumnName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetUnicodeFile)(THIS_ DP_OUT VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetUnicodeFile)(THIS_ DP_IN VARIANT_BOOL NewValue) PURE;
	STDMETHOD(GetOEMFile)(THIS_ DP_OUT VARIANT_BOOL *pRetVal) PURE;
	STDMETHOD(SetOEMFile)(THIS_ DP_IN VARIANT_BOOL NewValue) PURE;
};

///////////////////////////////////////
// IDTSDataPumpTransformDateTimeStringProperties - Sets custom properties for the
// DateTimeString transformation server.
///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IDTSDataPumpTransformDateTimeStringProperties
DECLARE_INTERFACE_(IDTSDataPumpTransformDateTimeStringProperties, DTSDataPump_IDispatch)
{
	DTSDataPump_Dispatch_Base(IDTSDataPumpTransformDateTimeStringProperties)

	STDMETHOD(GetMonth1LongName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetMonth1LongName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetMonth2LongName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetMonth2LongName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetMonth3LongName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetMonth3LongName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetMonth4LongName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetMonth4LongName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetMonth5LongName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetMonth5LongName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetMonth6LongName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetMonth6LongName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetMonth7LongName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetMonth7LongName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetMonth8LongName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetMonth8LongName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetMonth9LongName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetMonth9LongName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetMonth10LongName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetMonth10LongName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetMonth11LongName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetMonth11LongName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetMonth12LongName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetMonth12LongName)(THIS_ DP_IN BSTR NewValue) PURE;

	STDMETHOD(GetMonth1ShortName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetMonth1ShortName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetMonth2ShortName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetMonth2ShortName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetMonth3ShortName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetMonth3ShortName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetMonth4ShortName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetMonth4ShortName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetMonth5ShortName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetMonth5ShortName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetMonth6ShortName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetMonth6ShortName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetMonth7ShortName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetMonth7ShortName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetMonth8ShortName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetMonth8ShortName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetMonth9ShortName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetMonth9ShortName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetMonth10ShortName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetMonth10ShortName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetMonth11ShortName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetMonth11ShortName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetMonth12ShortName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetMonth12ShortName)(THIS_ DP_IN BSTR NewValue) PURE;

	STDMETHOD(GetDay1LongName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetDay1LongName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetDay2LongName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetDay2LongName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetDay3LongName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetDay3LongName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetDay4LongName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetDay4LongName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetDay5LongName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetDay5LongName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetDay6LongName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetDay6LongName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetDay7LongName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetDay7LongName)(THIS_ DP_IN BSTR NewValue) PURE;

	STDMETHOD(GetDay1ShortName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetDay1ShortName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetDay2ShortName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetDay2ShortName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetDay3ShortName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetDay3ShortName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetDay4ShortName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetDay4ShortName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetDay5ShortName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetDay5ShortName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetDay6ShortName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetDay6ShortName)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetDay7ShortName)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetDay7ShortName)(THIS_ DP_IN BSTR NewValue) PURE;

	STDMETHOD(GetInputFormat)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetInputFormat)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetOutputFormat)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetOutputFormat)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetAMSymbol)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetAMSymbol)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetPMSymbol)(THIS_ DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetPMSymbol)(THIS_ DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetShortYear2000Cutoff)(THIS_ DP_OUT LONG *pRetVal) PURE;
	STDMETHOD(SetShortYear2000Cutoff)(THIS_ DP_IN LONG NewValue) PURE;

	// Methods
	STDMETHOD(GetMonthLongName)(THIS_ DP_IN LONG MonthNumber, DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetMonthLongName)(THIS_ DP_IN LONG MonthNumber, DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetMonthShortName)(THIS_ DP_IN LONG MonthNumber, DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetMonthShortName)(THIS_ DP_IN LONG MonthNumber, DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetDayLongName)(THIS_ DP_IN LONG DayNumber, DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetDayLongName)(THIS_ DP_IN LONG DayNumber, DP_IN BSTR NewValue) PURE;
	STDMETHOD(GetDayShortName)(THIS_ DP_IN LONG DayNumber, DP_OUT BSTR *pRetVal) PURE;
	STDMETHOD(SetDayShortName)(THIS_ DP_IN LONG DayNumber, DP_IN BSTR NewValue) PURE;
};

////////////////////////////////////////////////////////////////////////////////////////
//
//	Consumer-supplied interface definitions.
//
////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////
// IDTSDataPumpTransform - Required interface of the "COM Server" instantiated by ServerClsid
// passed to IDTSDataPump::AddTransform.  This interface is retrieved and its methods called
// by the Pump to perform individual transforms. 
//
// ServerParameters allows the DataPump Consumer to instantiate a single instance of an
// IDTSDataPumpTransform implementation and pass it to multiple IDTSDataPump::AddTransform calls.
// This is only useful for custom Transform Servers (the DTS-supplied ones ignore this), and may be
// helpful for internal summations etc.  If this is done, the TransformServer should track this in its
// pvTransformServerData to optimize operations such as AddVariable, On(Row|Transform)Complete, etc.
///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IDTSDataPumpTransform
DECLARE_INTERFACE_(IDTSDataPumpTransform, IUnknown)
{
	DTSDataPump_Unknown_Base()

	// Allows the TransformServer to initialize its state for the current Transform.  The output
	// LPBYTE is passed to all subsequent methods, so a single TransformServer instance may be
	// used to implement multiple separate transforms.
	STDMETHOD(Initialize)(THIS_
			DP_IN LPCOLESTR pwzName,							// Transform name
			DP_IN VARIANT ServerParameters,						// Parameters to server for this transform
			DP_OUT LPBYTE *ppvTransformServerData				// Transform server state data.
		) PURE;

	// Validates the schema that will be transformed.  Allows the TransformServer to specify
	// certain modifications to the default binding modes, such as for BLOBs.  The default 
	// p(Src|Dest)ColumnInfo->ppDTSColBinding[ii].eBindModes intialized by the DataPump are:
	//
	// All BLOBs must be ClientOwned by OLEDB spec, so Source and Destination BLOBs are always
	// DTSBindMode_Byref_ClientOwned.
	// 
	// Source:  For efficiency, nonBLOB ((W)STR|BYTES) binding defaults to _Byref_ProviderOwned
	// to avoid unnecessary copying.  BSTR defaults to ProviderOwned.  All other types must be
	// non-Byref ClientOwned by OLEDB spec and behaviour.
	//
	// Destination:  Because the destination data is likely to be the result of a transformation,
	// destination binding always defaults to ClientOwned for all datatypes.  All nonBLOB types are
	// allocated Inline; this includes ((W)STR|BYTES), to minimize per-row (re)allocation overhead.
	//
	// A Transformation which simply passes-thru nonBLOB ((W)STR|BYTES)s or BSTRs from the Source
	// IRowset to the destination (and doesn't use the TransformCopy server, which is supplied for
	// this purpose) should override this to ProviderOwned to avoid unnecessary (re)allocations.
	//
	STDMETHOD(ValidateSchema)(THIS_
			DP_IN LPBYTE pvTransformServerData,					// Transform server state data.
			DP_INOUT LPCDTSTransformColumnInfo pSrcColumnInfo, 	// Source columns and rowdata
			DP_INOUT LPCDTSTransformColumnInfo pDestColumnInfo, // Dest columns and rowdata
			DP_IN IDTSDataConvert *pIDTSDataConvert,			// Pointer to the data conversion interface
			DP_IN DTSTransformFlags eTransformFlags				// Input Flags for Transformation validation and execution
		) PURE;

	// Adds a variable to the TransformServer's execution context.  This is always called once before
	// ValidateSchema, in order to add the IDTSErrorRecords object.
	STDMETHOD(AddVariable)(THIS_ 
			DP_IN LPBYTE pvTransformServerData,					// Transform server state data.
			DP_IN LPCOLESTR pwzName,							// Variable name
			DP_IN BOOL bGlobal,									// For ActiveX scripts, indicates whether this variable's
																// methods must be qualified by the object name.
			DP_IN VARIANT Variable								// Variable value; passed to and updatable by Transform
		) PURE;

	// Executes the transformation for a single row.  This method should return a SUCCEED
	// hr except in catastrophic failure; a FAILED hr here will abort the Pump.  "Normal"
	// errors such as data violations should be handled as a returned pTransformStatus,
	// which will cause IDTSDataPumpErrorSink::OnTransformError to be called.
	//
	// Because some providers may have restrictions on the number of Storage Objects which
	// may be open, Execute() should release any Blob Storage Objects in the source upon
	// completion, rather than waiting for OnRowComplete.  The DataPump handles refcounting
	// for multiple transforms of its buffered Source objects.  If the Blob column is
	// buffered by the DataPump or the Transform has knowledge of the Source Provider, it
	// can defer Release()ing the Source Storage Object until OnRowComplete.  Note that
	// returning DTSTransformStat_SkipFetch (and therefore not releasing the Source Storage
	// Object) may require buffering of the source Blob data.
	STDMETHOD(Execute)(THIS_
			DP_IN LPBYTE pvTransformServerData,					// Transform server state data.
			DP_IN LPCDTSTransformColumnInfo pSrcColumnInfo, 	// Source columns and rowdata
			DP_INOUT LPDTSTransformColumnInfo pDestColumnInfo, 	// Dest columns and rowdata
			DP_IN IDTSDataConvert *pIDTSDataConvert,			// Pointer to the data conversion interface
			DP_OUT LPDTSTransformStatus peTransformStatus		// Result of transform
		) PURE;

	// After a successful Fetch, the pump calls Execute and then attempts to insert the row into the
	// destination IRowsetChange (if one is specified).  OnRowComplete is called for every successful
	// Fetch (whether the Execute() and InsertRow succeeded or failed); this allows the TransformServer
	// to free per-row allocations and CLIENTOWNED data in both source and destination rows (such as
	// by calling pIDTSDataConvert->ClearBindingData).  A FAILED return from OnRowComplete aborts the Pump.
	// hrInsert indicates whether the IRowsetChange::InsertRow() succeeded; eTransformStatus indicates
	// if errors occurred such that InsertRow was not called.
	//
	// Note that OLEDB specifies that IRowsetChange::InsertRow() Releases any contained Storage Objects
	// in the row (but not other types of "allocations"), so the Transform server must be careful not to 
	// call pIDTSDataConvert->ClearBindingData on an already final-released Storage Object (in the event
	// that InsertRow is not called due to a Transform returning an error, the DataPump will release any
	// Storage Objects in the dest row for any Transforms for which Execute was called prior to the erroring
	// Transform, to present a consistent refcounting interface to TransformServers:  If Execute() returned
	// a non-NULL Storage Object in the row, it will be released once before OnRowComplete is called).
	//
	STDMETHOD(OnRowComplete)(THIS_
			DP_IN LPBYTE pvTransformServerData,					// Transform server state data.
			DP_INOUT LPDTSTransformColumnInfo pSrcColumnInfo,	// Source columns and rowdata
			DP_INOUT LPDTSTransformColumnInfo pDestColumnInfo, 	// Dest columns and rowdata
			DP_IN IDTSDataConvert *pIDTSDataConvert,			// Pointer to the data conversion interface
			DP_IN DTSTransformStatus eTransformStatus,			// Result of Execute()
			DP_IN HRESULT hrInsert								// Result of IRowsetChange::InsertRow()
		) PURE;

	// After all rows have been transformed (or the pump has been shutdown due to errors),
	// OnTransformComplete is called to give the TransformServer a chance to clean up all
	// allocations made for the Transform.  OnTransformComplete is called only if ValidateSchema
	// returned successfully.
	STDMETHOD(OnTransformComplete)(THIS_
			DP_IN LPBYTE pvTransformServerData,					// Transform server state data.
			DP_INOUT LPDTSTransformColumnInfo pSrcColumnInfo,	// Source columns and rowdata
			DP_INOUT LPDTSTransformColumnInfo pDestColumnInfo, 	// Dest columns and rowdata
			DP_IN IDTSDataConvert *pIDTSDataConvert				// Pointer to the data conversion interface
		) PURE;
};

///////////////////////////////////////
// IDTSDataPumpTransform2 - Extends IDTSDataPumpTransform.
///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IDTSDataPumpTransform2
DECLARE_INTERFACE_(INTERFACE, IDTSDataPumpTransform)
{
#ifndef NO_BASEINTERFACE_FUNCS
	DTSDataPump_Unknown_Base()

	STDMETHOD(Initialize)(THIS_
			DP_IN LPCOLESTR pwzName,							// Transform name
			DP_IN VARIANT ServerParameters,						// Parameters to server for this transform
			DP_OUT LPBYTE *ppvTransformServerData				// Transform server state data.
		) PURE;
	STDMETHOD(ValidateSchema)(THIS_
			DP_IN LPBYTE pvTransformServerData,					// Transform server state data.
			DP_INOUT LPCDTSTransformColumnInfo pSrcColumnInfo, 	// Source columns and rowdata
			DP_INOUT LPCDTSTransformColumnInfo pDestColumnInfo, // Dest columns and rowdata
			DP_IN IDTSDataConvert *pIDTSDataConvert,			// Pointer to the data conversion interface
			DP_IN DTSTransformFlags eTransformFlags				// Input Flags for Transformation validation and execution
		) PURE;
	STDMETHOD(AddVariable)(THIS_ 
			DP_IN LPBYTE pvTransformServerData,					// Transform server state data.
			DP_IN LPCOLESTR pwzName,							// Variable name
			DP_IN BOOL bGlobal,									// For ActiveX scripts, indicates whether this variable's
																// methods must be qualified by the object name.
			DP_IN VARIANT Variable								// Variable value; passed to and updatable by Transform
		) PURE;
	STDMETHOD(Execute)(THIS_
			DP_IN LPBYTE pvTransformServerData,					// Transform server state data.
			DP_IN LPCDTSTransformColumnInfo pSrcColumnInfo, 	// Source columns and rowdata
			DP_INOUT LPDTSTransformColumnInfo pDestColumnInfo, 	// Dest columns and rowdata
			DP_IN IDTSDataConvert *pIDTSDataConvert,			// Pointer to the data conversion interface
			DP_OUT LPDTSTransformStatus peTransformStatus		// Result of transform
		) PURE;
	STDMETHOD(OnRowComplete)(THIS_
			DP_IN LPBYTE pvTransformServerData,					// Transform server state data.
			DP_INOUT LPDTSTransformColumnInfo pSrcColumnInfo,	// Source columns and rowdata
			DP_INOUT LPDTSTransformColumnInfo pDestColumnInfo, 	// Dest columns and rowdata
			DP_IN IDTSDataConvert *pIDTSDataConvert,			// Pointer to the data conversion interface
			DP_IN DTSTransformStatus eTransformStatus,			// Result of Execute()
			DP_IN HRESULT hrInsert								// Result of IRowsetChange::InsertRow()
		) PURE;
	STDMETHOD(OnTransformComplete)(THIS_
			DP_IN LPBYTE pvTransformServerData,					// Transform server state data.
			DP_INOUT LPDTSTransformColumnInfo pSrcColumnInfo,	// Source columns and rowdata
			DP_INOUT LPDTSTransformColumnInfo pDestColumnInfo, 	// Dest columns and rowdata
			DP_IN IDTSDataConvert *pIDTSDataConvert				// Pointer to the data conversion interface
		) PURE;
#endif // NO_BASEINTERFACE_FUNCS

	// Retrieve information for the Transform server which describes its functionality.
	// Any output parameter may be NULL if that information is not desired.
	STDMETHOD(GetTransformServerInfo)(THIS_
			DP_OUT BSTR *pbstrHelpString,						// Description of the server's implementation
			DP_OUT LPDTSTransformPhaseEnum peSupportedPhases	// Phases supported by this server
		) PURE;

	// Prevalidate schema based on metadata, and any custom property settings if supported.
	STDMETHOD(PreValidateSchema)(THIS_
			DP_IN LPCDTSTransformColumnMetadata pSrcMetadata,	// May be NULL if not required by Transform Server
			DP_IN LPCDTSTransformColumnMetadata pDestMetadata,	// May be NULL if not required by Transform Server
			DP_IN DTSTransformFlags eTransformFlags,			// Input Flags for Transformation validation and execution
			DP_IN DTSTransformPhaseEnum ePhases					// Phase(s) for which this Transform is to be called.
		) PURE;

	// For future use, to be called prior to ValidateSchema.  When implemented, pUnkExtendedInfo
	// will QueryInterface to one or more interfaces supplying extended information, and must
	// be released in (or prior to) OnTransformComplete.
	STDMETHOD(SetExtendedInfo)(THIS_
			DP_IN IUnknown *pUnkExtendedInfo					// Pointer to object supplying extended information.
		) PURE;

	// Called for each phase for which the Transform was added (as specified in DTSTransformPhaseEnum
	// on DataPump::AddTransform2).  The following phases are available:
	//	DTSTransformPhase_PreSourceData
	//		Called before first fetch of source data.  Valid destination codes may be returned
	//		in peTransformStatus (i.e. destination data may be inserted, or DDQ queries executed).
	//		SkipFetch may be returned to loop and add multiple records.
	//	DTSTransformPhase_PostSourceData
	//		Same as _PreSourceData, except called after the last row of source data has been fetched.
	//	DTSTransformPhase_Transform
	//		Same as Execute, with the additional pPhaseInfo parameter.
	//	DTSTransformPhase_OnTransformFailure
	//		Called when "normal" transform phase results in DTSTransformStat_Error or _ExceptionRow.
	//		The returned peTransformStatus will override the value returned by "normal" transforms,
	//		allowing some degree of recovery and possible later manipulation of the data,
	//	DTSTransformPhase_OnInsertSuccess
	//	DTSTransformPhase_OnInsertFailure
	//		Called on success or failure of the Insert (or query if DataDrivenQuery is used).
	//		Separate success and failure phases are supplied to reduce per-row performance impact.
	//		No destination operations may be specified in the returned peTransformStatus, but
	//		DTSTransformStat_AbortPump may be specified.
	//	DTSTransformPhase_OnBatchComplete
	//		Called on success or failure of a DataPump batch, as defined by InsertCommitSize.
	//	DTSTransformPhase_OnPumpComplete
	//		Called when the DataPump execution is complete (success or failure).  Return value
	//		is not used and must be set to DTSTransformStat_OK.  If this phase is not not specified
	//		on DataPump::AddTransform2, the DataPump will query IDTSTransformServer2::GetTransformServerInfo
	//		to see if it supports this phase, and will call it in place of OnTransformComplete if so.
	//		This ensures the transform server has pPhaseInfo available on final cleanup.
	STDMETHOD(ProcessPhase)(THIS_
			DP_IN LPBYTE pvTransformServerData,					// Transform server state data.
			DP_IN LPCDTSTransformColumnInfo pSrcColumnInfo, 	// Source columns and rowdata
			DP_INOUT LPDTSTransformColumnInfo pDestColumnInfo, 	// Dest columns and rowdata
			DP_IN IDTSDataConvert *pIDTSDataConvert,			// Pointer to the data conversion interface
			DP_IN LPCDTSTransformPhaseInfo pPhaseInfo,			// Pointer to phase info structure
			DP_OUT LPDTSTransformStatus peTransformStatus		// Result of transform
		) PURE;

	// Called when IDTSDataPump2::SetExecuteThreadComplete is called.
	STDMETHOD(SetExecuteThreadComplete)(THIS) PURE;
};

///////////////////////////////////////
// IDTSDataPumpErrorSink - Specifies pump error handler sink.  Only one method will
// be called for any row, and the method called indicates where the error was encountered:
// reading from source, transforming, or writing to destination.
///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IDTSDataPumpErrorSink
DECLARE_INTERFACE_(IDTSDataPumpErrorSink, IUnknown)
{
	DTSDataPump_Unknown_Base()

	// An error occurred on Binding in CreateAccessor.  This is only useful for designing custom Transform
	// Servers, primarily for diagnosing Blob difficulties.
	STDMETHOD(OnBindingError)(THIS_ 
			DP_IN LPBYTE pvExecUserData,				// User data pointer passed to IDTSDataPump::Execute
			DP_IN HRESULT hrError,						// The errorcode from CreateAccessor; for Destination if pDestinationRow, else for Source.
			DP_IN LPCDTSTransformColumnInfo pSourceRow,	// Pointer to the source row and binding info.
			DP_IN const DBBINDSTATUS *pSourceDBBindStatus,		// Pointer to source binding status returns.
			DP_IN LPCDTSTransformColumnInfo pDestinationRow,	// Pointer to the destination row and binding info; NULL if from Source Binding error.
			DP_IN const DBBINDSTATUS *pDestinationDBBindStatus	// Pointer to destination binding status returns; NULL if from Source Binding error.
		) PURE;

	// An error occurred during GetNextRows or GetData.
	STDMETHOD(OnSourceError)(THIS_ 
			DP_IN LPBYTE pvExecUserData,				// User data pointer passed to IDTSDataPump::Execute
			DP_IN LPDTSTransformColumnInfo pSourceRow,	// Pointer to the source row and binding info; NULL if GetNextRows or GetData failed.
			DP_IN HRESULT hrError,						// The errorcode from the OLEDB or system call.
			DP_IN ULARGE_INTEGER uliRow,				// Number of the row failing.
			DP_IN ULONG cErrors,						// Number of error rows encountered so far (including this one).
			DP_OUT BOOL *pbAbort						// Set TRUE by Sink if this error should abort IDTSDataPump::Execute.
														// Otherwise, Execute() continues until MaximumErrorRowCount is exceeded.
		) PURE;

	// An error occurred on one or more Transforms.
	STDMETHOD(OnTransformError)(THIS_ 
			DP_IN LPBYTE pvExecUserData,				// User data pointer passed to IDTSDataPump::Execute
			DP_IN LPCOLESTR pwzName,					// Transform name
			DP_IN LPBYTE pvTransformUserData,			// User data pointer passed to IDTSDataPump::AddTransform
														// in LPCDTSTransformColumnsSpecification parameter.
			DP_IN IDTSDataPumpTransform *pTransformServer,	// The transform server raising the error; can be QI'd to custom interface for more info.
			DP_IN LPDTSTransformColumnInfo pSourceRow,	// Pointer to the source row and binding info.
			DP_IN DTSTransformStatus TransformStatus,	// Returned status code from the transformation.
			DP_IN HRESULT hrTransform,					// The HRESULT returned from DTSDataPumpTransform::Execute.
			DP_IN ULARGE_INTEGER uliRow,				// Number of the row failing.
			DP_IN ULONG cErrors,						// Number of error rows encountered so far (including this one).
			DP_OUT BOOL *pbAbort						// Set TRUE by Sink if this error should abort IDTSDataPump::Execute.
														// Otherwise, Execute() continues until MaximumErrorRowCount is exceeded.
		) PURE;

	// An error occurred during InsertRow.
	STDMETHOD(OnDestinationError)(THIS_ 
			DP_IN LPBYTE pvExecUserData,				// User data pointer passed to IDTSDataPump::Execute
			DP_IN LPDTSTransformColumnInfo pSourceRow,	// Pointer to the source row.
			DP_IN LPDTSTransformColumnInfo pDestinationRow,	// Pointer to the destination row and binding info; NULL if prior to transform execution.
			DP_IN HRESULT hrError,						// The errorcode from the OLEDB or system call.
			DP_IN ULARGE_INTEGER uliRow,				// Number of the row failing.
			DP_IN ULONG cErrors,						// Number of error rows encountered so far (including this one).
			DP_OUT BOOL *pbAbort						// Set TRUE by Sink if this error should abort IDTSDataPump::Execute.
														// Otherwise, Execute() continues until MaximumErrorRowCount is exceeded.
		) PURE;
};

///////////////////////////////////////
// IDTSDataDrivenQuerySink - Specifies event sink for Data Driven Queries.
///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IDTSDataDrivenQuerySink
DECLARE_INTERFACE_(IDTSDataDrivenQuerySink, IUnknown)
{
	DTSDataPump_Unknown_Base()

	STDMETHOD(OnDDQBindingError)(THIS_ 
			DP_IN LPBYTE pvExecUserData,				// User data pointer passed to IDTSDataPump::Execute
			DP_IN DTSTransformStatus fQueryType,		// Insert, Update, Delete, or User Query.
			DP_IN HRESULT hrError,						// The errorcode from CreateAccessor for Command parameters
			DP_IN LPCDTSTransformColumnInfo pDestinationRow,	// Pointer to the destination row and transform binding info
			DP_IN ULONG cParameterColumns,				// Number of parameter columns
			DP_IN const DBBINDING *pParameterDBBinding,	// Pointer to destination parameter bindings
			DP_IN const DBBINDSTATUS *pParameterDBBindStatus	// Pointer to destination parameter binding status returns
		) PURE;

	STDMETHOD(OnDDQCommandError)(THIS_ 
			DP_IN LPBYTE pvExecUserData,				// User data pointer passed to IDTSDataPump::Execute
			DP_IN DTSTransformStatus fQueryType,		// Insert, Update, Delete, or User Query.
			DP_IN LPDTSTransformColumnInfo pSourceRow,	// Pointer to the source row.
			DP_IN LPDTSTransformColumnInfo pDestinationRow,	// Pointer to the destination row and binding info.
			DP_IN HRESULT hrError,						// The errorcode from the OLEDB or system call.
			DP_IN ULARGE_INTEGER uliRow,				// Number of the row failing.
			DP_IN ULONG cErrors,						// Number of error rows encountered so far (including this one).
			DP_OUT BOOL *pbAbort						// Set TRUE by Sink if this error should abort IDTSDataPump::Execute.
														// Otherwise, Execute() continues until MaximumErrorRowCount is exceeded.
		) PURE;

	STDMETHOD(OnDDQCommandComplete)(THIS_ 
			DP_IN LPBYTE pvExecUserData,				// User data pointer passed to IDTSDataPump::Execute
			DP_IN DTSTransformStatus fQueryType,		// Insert, Update, Delete, or User Query.
			DP_IN LPDTSTransformColumnInfo pSourceRow,	// Pointer to the source row.
			DP_IN LPDTSTransformColumnInfo pDestinationRow,	// Pointer to the destination row and binding info.
			DP_IN LONG cDestinationRowsAffected,		// Rows affected by Command; -1 if provider unable to determine.
			DP_IN ULARGE_INTEGER uliRow					// Number of the source row for which the Query was Execute()d.
		) PURE;
};

///////////////////////////////////////
// IDTSCustomTransformUI - 
// optional interface to be implemented by custom transform providers - used by DTS UI to configure the transforms
///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IDTSCustomTransformUI
DECLARE_INTERFACE_(IDTSCustomTransformUI, IUnknown)
{
	DTSDataPump_Unknown_Base()

	STDMETHOD(Initialize)(THIS_ DP_IN LPUNKNOWN pDTSPkgTransformObject) PURE;
	STDMETHOD(New)(THIS_ DP_IN long hwndParent) PURE;
	STDMETHOD(Edit)(THIS_ DP_IN long hwndParent) PURE;
	STDMETHOD(Delete)(THIS_ DP_IN long hwndParent) PURE;
	STDMETHOD(Help)(THIS_ DP_IN long hwndParent) PURE;
};

///////////////////////////////////////
// IDTSDataPumpProgressSink - Progress indicator event sink.
///////////////////////////////////////

#undef INTERFACE
#define INTERFACE IDTSDataPumpProgressSink
DECLARE_INTERFACE_(IDTSDataPumpProgressSink, IUnknown)
{
	DTSDataPump_Unknown_Base()

	STDMETHOD(OnIntervalComplete)(THIS_
			DP_IN LPBYTE pvExecUserData,				// User data pointer passed to IDTSDataPump::Execute
			DP_IN ULARGE_INTEGER uliRowsComplete,		// Total Source Rows processed at this interval (includes those skipped)
			DP_OUT BOOL *pbAbort						// Set TRUE by Sink to abort IDTSDataPump::Execute.
		) PURE;
};

/////////////////////////////////////////////////////////////////////////////////
// DTS Repository-support interfaces.
/////////////////////////////////////////////////////////////////////////////////

// Repository interfaces and definitions are shared between DTSDataPump and DTSPackage.

#ifdef OBJID_DtsTransformationTask

// A covering utility interface around a Repository object, provided by the DTS Package
// when requesting repository storage from a custom Task or Transformation.  This interface
// is passed to IDTSRepositoryStorage methods during DTSPackage.SaveToRepository.
#undef INTERFACE
#define INTERFACE IDTSRepositoryProvider
DECLARE_INTERFACE_(INTERFACE, IUnknown)
{
	DTSDataPump_Unknown_Base()

	// Return a reference to the Repository object.
	STDMETHOD(GetRepository)(THIS_
			DP_OUT IRepository **ppIRepository				// The repository object.
		) PURE;

	// Creates an object and sets its name.
	STDMETHOD(CreateObject)(THIS_
			DP_IN LPCOLESTR wzObjidClass					// Repository class to create
			, DP_IN LPCOLESTR wzObjidInstance				// class instance (object) id, or NULL
			, DP_IN LPCOLESTR wzInstanceName				// class instance (object) name, or NULL
			, DP_OUT IRepositoryObject **ppRepositoryObject	// created object
		) PURE;

	// Finds an IDbmConnection object for a DTS connection in the associated DTS Package.
	STDMETHOD(FindConnection)(THIS_
			DP_IN LPCOLESTR wzName							// DTSConnection.Name
			, DP_IN long lID								// DTSConnection.ID
			, DP_OUT IRepositoryDispatch **ppIDbmConnection	// output object
		) PURE;

	// When a custom Task or Transformation references a table or view, it should create a
	// relationship to that table or view if the appropriate datasource and catalog's metadata
	// has been scanned (by dbscanner) into the Repository.  To do so, the IDTSRepositoryStorage
	// implementation should call FindScannedObject, passing the name of the table or view
	// to be referenced.  Note that this name should be qualified as necessary to resolve
	// ambiguity, if multi-part names are supported by the connection provider.  This qualification
	// must be done according to DBPROP_CATALOGUSAGE and DBPROP_SCHEMAUSAGE, and the following
	// DBLITERALs:
	//		DBLITERAL_QUOTE_PREFIX
	//		DBLITERAL_QUOTE_SUFFIX
	//		DBLITERAL_CATALOG_SEPARATOR
	//		DBLITERAL_SCHEMA_SEPARATOR
	//
	// DTSPackage.SaveToRepository will search for a scanned catalog contained within any
	// IDbmDataSource with IsPublic TRUE.  A table or view resides in the repository as follows:
	//		Root(IUmlPackage).Elements
	//			... possibly some intervening level of package or system...
	//			IDbmDataSource(IUmlPackage).Elements
	//				IDbmDeployedCatalog(IUmlPackage).Elements
	//					IDbmSchema(IUmlPackage).Elements
	//						IDbmDeployedTable, IDbmDeployedView
	// The catalog in which wzObjectName is resolved is determined by the first name found in
	// the following order:
	//		A catalog name parsed from wzObjectName
	//		DBPROP_CURRENTCATALOG after IDTSConnection.OpenConnection; this may be set by either of:
	//			IDTSConnection.DefaultCatalog
	//			IDTSConnection.ConnectionProperties(DBPROP_INIT_CATALOG)
	//		If DBPROP_CURRENTCATALOG is not supported, a placeholder catalog is 
	//			created by the scanner; this catalog is used to resolve scanned object references.
	//		
	// The schema in which wzObjectName is resolved is determined by the first name found in
	// the following order:
	//		A schema name parsed from wzObjectName
	//		IDTSConnection.UserID
	//		IDTSConnection.ConnectionProperties(DBPROP_AUTH_USERID)
	//
	// Because the connection's UserID may be simply a login id and different from the actual
	// object owner, wzObjectName should be qualified.  Only one schema will be searched for the
	// object; that schema is determined by:
	//		If a Schema-qualified wzObjectName is passed, that Schema is searched.
	//		Else if only one Schema is specified, it is searched.
	//		Else if a UserID is specified, it is used.
	//		Else EREP_OBJ_NOTFOUND.
	//
	// FindScannedObject returns the following, in order:
	//		If the call to DTSPackage.SaveToRepository specified that no scanner resolution be done,
	//		FindScannedObject returns NULL and S_FALSE.  In this case, AddUnscannedObject should be
	//		called, to create an DTSPackage-level object for AddTransformationUses to relate to.
	//
	//		If the provider does not support SchemaRowsets (necessary for scan), FindScannedObject
	//		returns NULL and S_FALSE.
	//
	//		If the catalog has not been scanned, or if the call to DTSPackage.SaveToRepository
	//		specified to rescan, then the catalog is scanned.  Any error from the dbscanner (such as
	//		the catalog not being found) is returned.
	//
	//		If wzObjectName is not found, EREP_OBJ_NOTFOUND is returned.
	//
	//		If wzObjectName is not found uniquely, such as an unqualified name appearing in more than
	//		one schema, EREP_OBJ_NOTFOUND is returned.
	//
	//		If wzObjectName is found uniquely, the IDbmDeployedTable or IDbmDeployedView is placed in
	//		ppIScannedObject and S_OK is returned.
	//
	// Note that FindScannedObject should not be called for an IDbmQuery object, as these are not
	// scanned into the repository as part of a Catalog; they are owned by the connection consumer.
	// IDbmQuery objects should be added via AddUnscannedObject.
	//
	// Generally a custom Task or Transformation will do the following (with most error handling omitted
	// for brevity):
	//	pIRepositoryProvider->CreateObject(OBJID_MyCustomTaskOrTransform
	//			, NULL
	//			, wzObjectName
	//			, &pICustomTaskOrTransform);
	//	if (referencing a table or view) {
	//		if FAILED(pIRepositoryProvider->FindScannedObject(<name>
	//			, IID_IRepositoryObject
	//			, pIDbmConnection
	//			, &pINewObject))
	//			return error;
	//	}
	//	if (NULL == pUnk) {
	//		pIRepositoryProvider->CreateObject(<parameters for the table, view, query, or other object>,
	//			, &pINewObject);
	//		pIRepositoryProvider->AddUnscannedObject(pIDbmConnection
	//			, pINewObject);
	//	}
	//	pIRepositoryProvider->AddTransformationUses(L"Source Table"
	//			, pICustomTaskOrTransform
	//			, pINewObject);
	//
	STDMETHOD(FindScannedObject)(THIS_
			DP_IN LPCOLESTR wzObjectName					// Name of the object (may be qualified by catalog.schema.name)
			, DP_IN REFIID iidToGet							// an IID the object must support; ignored if IID_NULL
			, DP_IN IRepositoryDispatch *pIDbmConnection	// Connection object (e.g. from FindConnection)
			, DP_OUT IRepositoryObject **ppIScannedObject	// returns scanned object or NULL on error.
		) PURE;

	// This method adds an object to the repository as a way for AddTransformationUses to form a
	// relationship.  This object is not visible outside the scope of the saved DTSPackage.  pINewObject
	// is created (e.g. by CreateObject) and may be a table or view, or query, or a specialization (derived
	// class) of one, according to the following mapping:
	//		Object type		Must support		Added to
	//		-----------		------------		---------
	//		Query			ITfmQuery			ITfmTransformation(IUmlType).Members
	//											ITfmTransformationTask(IUmlType).Members
	//		Table			IDbmDeployedTable	Package-local DataSource/Catalog/Schema
	//		View			IDbmDeployedView	Package-local DataSource/Catalog/Schema
	//		other			IUmlMember			ITfmTransformation(IUmlType).Members
	//											ITfmTransformationTask(IUmlType).Members
	//
	STDMETHOD(AddUnscannedObject)(THIS_
			DP_IN IRepositoryDispatch *pIDbmConnection		// Connection object (e.g. from FindConnection)
			, DP_IN IRepositoryObject *pINewObject			// Task/Transform-created object.
		) PURE;

	// This method creates a relationship between an ITfmTransformation or ITfmTransformationTask
	// and an IDbmColumnSet specialization (such as an IDbmDeployedTable, IDbmDeployedView, or ITfmQuery)
	// via the ITfmTransformationUses specialization of IUmlDependency, where
	//		ITfmTransformationUses(IUmlDependency).SourceElement = pITaskOrTransform
	//		ITfmTransformationUses(IUmlDependency).TargetElement = pINewObject
	//
	// Any dependencies added in this manner can be retrieved during LoadFromRepository by:
	//		pITaskOrTransform(IID_IUmlElement).TargetDependencies
	//
	STDMETHOD(AddTransformationUses)(THIS_
			DP_IN LPCOLESTR wzDependencyType				// A string describing the dependency; e.g., L"Source Table".
			, DP_IN IRepositoryObject *pITaskOrTransform	// Task/Transform-created object.
			, DP_IN IRepositoryObject *pINewObject			// Task/Transform-created object.
		) PURE;

	// Creates a datatype object which maps the passed DBTYPE and other information to
	// its Repository equivalent, and creates and returns a matching object.
	STDMETHOD(CreateMappedDatatypeObject)(THIS_
			DP_IN DBTYPE dbType								// The OLEDB datatype
			, DP_IN LONG lSize								// Column size in characters (ignored if a fixed-length datatype)
			, DP_IN LONG lPrecision							// Column precision if DECIMAL or NUMERIC
			, DP_IN LONG lScale								// Column scale if DECIMAL or NUMERIC
			, DP_OUT IRepositoryObject **ppRepositoryObject	// output object
		) PURE;

	// Gets information from a datatype object created by CreateMappedDataTypeObject.
	STDMETHOD(GetMappedDatatypeInfo)(THIS_
			DP_IN IRepositoryObject *pRepositoryObject		// input object
			, DP_OUT DBTYPE *pdbType						// The OLEDB datatype
			, DP_OUT LONG *plSize							// Column size in characters (ignored if a fixed-length datatype)
			, DP_OUT LONG *plPrecision						// Column precision if DECIMAL or NUMERIC
			, DP_OUT LONG *plScale							// Column scale if DECIMAL or NUMERIC
		) PURE;
};

// If a custom task or custom transform server wants to manage its Repository persistence itself,
// it must implement IDTSRepositoryStorage.  Otherwise, the Package will simply enumerate the
// OleAutomation properties of the custom task/transform IDispatch and store all those which
// can be Set() as (Variant)TaggedValues of an IDtsCustomTask repository object.
#undef INTERFACE
#define INTERFACE IDTSRepositoryStorage
DECLARE_INTERFACE_(INTERFACE, IUnknown)
{
	DTSDataPump_Unknown_Base()

	// The implementation must create its own Repository object via pIRepositoryProvider->CreateObject,
	// and the returned ppIRepositoryObject must be fully populated and must support IDtsCustomTask
	// (if a custom DTSPackage Task) or IDts(Blob)Transformation (if a custom DTSPump Transform server).
	// After this method returns, the DTSPackage will set properties for Task Name via INamedObject::Name
	// and ServerID (the ProgID or string form of CLSID by which the custom task/transformation server is
	// CoCreateInstance()'d) and any other base-class values needed.  Custom objects should not set tagged
	// values in the base object classes, to avoid possible name conflicts.
	STDMETHOD(SaveToRepository)(THIS_
			DP_IN IDTSRepositoryProvider *pIRepositoryProvider
			, DP_OUT IRepositoryObject **ppIRepositoryObject
		) PURE;

	// The implementation loads its own properties from this object.  If access to the IRepository
	// object is necessary, use pIRepositoryObject->get_Repository().
	STDMETHOD(LoadFromRepository)(THIS_
			DP_IN IDTSRepositoryProvider *pIRepositoryProvider
			, DP_IN IRepositoryObject *pIRepositoryObject
		) PURE;
};

#endif // def OBJID_DtsTransformationTask

#endif // ndef DTSDataPump_VersionOnly

#endif // ndef DTSDataPump_ODL_

#endif // DTSDataPump_H_
