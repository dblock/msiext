#pragma once

/*!
\brief Generate a new key and returns a hex-encoded version of it.
\return DESEDE3_KEY A 192-bit hex-encoded key that can be used in DESEDE3Encrypt or DESEDE3Decrypt.
*/
CA_API UINT __stdcall DESEDE3_GenerateKey(MSIHANDLE hInstall);

/*!
\brief Encrypt data with DESEDE3.
\param DESEDE3_KEY A 192-bit hex-encoded key.
\param DESEDE3_CLEARTEXT_DATA Clear-text data to encrypt with DESEDE3_KEY.
\return DESEDE3_ENCRYPTED_DATA Clear-text data encrypted and hex-encoded.
*/
CA_API UINT __stdcall DESEDE3_Encrypt(MSIHANDLE hInstall);

/*!
\brief Decrypt data with DESEDE3.
\param DESEDE3_KEY A 192-bit hex-encoded key.
\param DESEDE3_ENCRYPTED_DATA Encrypted and hex-encoded text data.
\return DESEDE3_CLEARTEXT_DATA Clear-text decrypted.
*/
CA_API UINT __stdcall DESEDE3_Decrypt(MSIHANDLE hInstall);
