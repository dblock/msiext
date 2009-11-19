#pragma once

namespace AppSecInc
{
    namespace Crypt
    {
        /*! \class CryptoPPImpl
	        \brief This class implements basic cryptographic operations using the Crypto++ library.
		           This is a utility class and is not tied to any Crypt Provider.
        */
        class CryptoPPImpl
        {
        public:
	        /*! 
		        \fn DESEDE3GenerateKey
		        \brief Generate a key for encryption using DES_EDE3.
	        */
            static std::string DESEDE3GenerateKey();
        	
	        /*! 
		        \fn DESEDE3Encrypt
		        \brief Encrypt using DES_EDE3.
	        */
            static std::string DESEDE3Encrypt(const std::string& input, const std::string& key);

	        /*! 
		        \fn DESEDE3Decrypt
		        \brief Decrypt using DES_EDE3.
	        */
            static std::string DESEDE3Decrypt(const std::string& input, const std::string& key);
        	
	        /*! 
		        \fn Base64Encode
		        \brief Base64 Encode the input.
	        */
            static std::string Base64Encode(const std::string& input);

	        /*! 
		        \fn Base64Decode
		        \brief Base64 Decode the input.
	        */
            static std::string Base64Decode(const std::string& input);
        	
	        /*! 
		        \fn HexEncode
		        \brief Hex Encode the input string.
	        */
            static std::string HexEncode(const std::string& input);
            static std::wstring HexEncode(const std::wstring& input);

	        /*! 
		        \fn HexDecode
		        \brief Hex Decode the input string.
	        */
            static std::string HexDecode(const std::string& input);
            static std::wstring HexDecode(const std::wstring& input);
        		
	        /*! 
		        \fn Pad
		        \brief Pad a string with the correct amount of bytes needed for a block cipher.
	        */
            static void Pad(const std::string& input, int size, std::string& output, int& nBlocks);
            static std::string Pad(const std::string& input, int size);

        private:	
	        CryptoPPImpl(); // making this private as this class only exposes static objects
        };
    }
}