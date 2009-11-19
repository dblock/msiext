#pragma once

/*!
\brief HexEncodeW hex-encodes data, each byte transformed into two bytes of humanly-readable characters.
\param HEXENCODE_DATA Data to encode.
\return HEXENCODE_RESULT Hex-encoded data.
*/
CA_API UINT __stdcall HexEncodeW(MSIHANDLE hInstall);

/*!
\brief HexEncodeA hex-encodes non-unicode data, each byte transformed into two bytes of humanly-readable characters.
\param HEXENCODE_DATA Data to encode.
\return HEXENCODE_RESULT Hex-encoded data.
*/
CA_API UINT __stdcall HexEncodeA(MSIHANDLE hInstall);

/*!
\brief HexDecodeW hex-decodes data, each two bytes transformed into one byte.
\param HEXDECODE_DATA Data to decode.
\return HEXDECODE_RESULT Hex-decoded data.
*/
CA_API UINT __stdcall HexDecodeW(MSIHANDLE hInstall);

/*!
\brief HexDecodeA hex-decodes data, each two bytes transformed into one byte of non-unicode characters.
\param HEXDECODE_DATA Data to decode.
\return HEXDECODE_RESULT Hex-decoded data.
*/
CA_API UINT __stdcall HexDecodeA(MSIHANDLE hInstall);
