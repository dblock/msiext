#pragma once

namespace AppSecInc
{
    namespace Crypt
    {
        /*! \namespace CryptoPPImpl
	        \brief Implements basic cryptographic operations using the Crypto++ library.
        */
        namespace CryptoPPImpl
        {
	        /*! 
		        \fn DESEDE3GenerateKey
		        \brief Generate a key for encryption using DES_EDE3.
	        */
            std::vector<byte> DESEDE3GenerateKey();
        	
	        /*! 
		        \fn DESEDE3Encrypt
		        \brief Encrypt using DES_EDE3.
	        */
            std::vector<byte> DESEDE3Encrypt(const std::vector<byte>& input, const std::vector<byte>& key);

	        /*! 
		        \fn DESEDE3Decrypt
		        \brief Decrypt using DES_EDE3.
	        */
            std::vector<byte> DESEDE3Decrypt(const std::vector<byte>& input, const std::vector<byte>& key);
        	
	        /*! 
		        \fn Base64Encode
		        \brief Base64 Encode the input.
	        */
            std::string Base64Encode(const std::vector<byte>& input);

	        /*! 
		        \fn Base64Decode
		        \brief Base64 Decode the input.
	        */
            std::vector<byte> Base64Decode(const std::string& input);
        	
	        /*! 
		        \fn HexEncode
		        \brief Hex Encode the input string.
	        */
            std::string HexEncode(const std::vector<byte>& input);

	        /*! 
		        \fn HexDecode
		        \brief Hex Decode the input string.
	        */
            std::vector<byte> HexDecode(const std::string& input);
        		
	        /*! 
		        \fn Pad
		        \brief Pad a string with the correct amount of bytes needed for a block cipher.
	        */
            void Pad(const std::vector<byte>& input, int size, std::vector<byte>& output, int& nBlocks);
            std::vector<byte> Pad(const std::vector<byte>& input, int size);

	        /*! 
		        \fn GenerateRandom
		        \brief Generate a random block of bytes.
	        */
			std::vector<byte> GenerateRandom(long size);
        };
    }
}