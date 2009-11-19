#pragma once

namespace AppSecInc
{
    namespace Crypt
    {
        /*! \class CryptoPPCryptProvider
	        \brief Implements CryptProvider functions using DES_EDE3 encryption.
        */
        class CryptoPPCryptProvider : public CryptProvider
        {
        public:
	        /*! 
		        \fn GenerateKey
		        \brief Generate a key for encryption
	        */
            std::string GenerateKey();
        	
	        /*! 
		        \fn Encrypt
		        \brief Encrypt the input given a key.
	        */
            std::string Encrypt(const std::string& input, const std::string& key);
        	
	        /*! 
		        \fn Decrypt
		        \brief Decrypt the input given a key.
	        */
            std::string Decrypt(const std::string& input, const std::string& key);

	        /*! 
		        \fn Protect
		        \brief Protect encrypts and encodes the input.
	        */
            std::string Protect(const std::string& input);

	        /*! 
		        \fn Unprotect
		        \brief Unprotect decodes and decrypts the input.
	        */
            std::string Unprotect(const std::string& input);

	        /*! 
		        \fn Encode
		        \brief Hex Encode the input string.
	        */
            std::string Encode(const std::string& input);

	        /*! 
		        \fn Decode
		        \brief Hex Decode the input string
	        */
            std::string Decode(const std::string& input);

        public:	
	        CryptoPPCryptProvider();
	        ~CryptoPPCryptProvider();
        };
    }
}