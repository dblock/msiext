#pragma once

/*!
\brief Base64EncodeW encodes data in base-64.
\param BASE64ENCODE_DATA Data to encode.
\return BASE64ENCODE_RESULT Base64-encoded data.
*/
CA_API UINT __stdcall Base64EncodeW(MSIHANDLE hInstall);

/*!
\brief Base64EncodeA encodes non-unicode data in base-64.
\param BASE64ENCODE_DATA Data to encode.
\return BASE64ENCODE_RESULT Base64-encoded data.
*/
CA_API UINT __stdcall Base64EncodeA(MSIHANDLE hInstall);

/*!
\brief Base64DecodeW decodes data from base-64.
\param BASE64DECODE_DATA Data to decode.
\return BASE64DECODE_RESULT Base64-decoded data.
*/
CA_API UINT __stdcall Base64DecodeW(MSIHANDLE hInstall);

/*!
\brief Base64DecodeA decodes data from base-64.
\param BASE64DECODE_DATA Data to decode.
\return BASE64DECODE_RESULT Base64-decoded data.
*/
CA_API UINT __stdcall Base64DecodeA(MSIHANDLE hInstall);
