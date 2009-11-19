#pragma once

namespace AppSecInc
{
    namespace Crypt
    {
        /*! \class CryptProvider
	        \brief Abstract class that defines the key functionalities of a Crypt Provider.
        */
        class CryptProvider
        {
        public:	
        	
	        /*! 
		        \fn GenerateKey
		        \brief Generate a key for encryption
	        */
            virtual std::string GenerateKey() = 0;
        	
	        /*! 
		        \fn Encrypt
		        \brief Encrypt the input given a key.
	        */
            virtual std::string Encrypt(const std::string& input, const std::string& key) = 0;
        	
	        /*! 
		        \fn Decrypt
		        \brief Decrypt the input given a key.
	        */
            virtual std::string Decrypt(const std::string& input, const std::string& key) = 0;

	        /*! 
		        \fn Protect
		        \brief Protect encrypts and encodes the input.
	        */
	        virtual std::string Protect(const std::string& input) = 0;

	        /*! 
		        \fn Unprotect
		        \brief Unprotect decodes and decrypts the input.
	        */
	        virtual std::string Unprotect(const std::string& input) = 0;

	        /*! 
		        \fn Encode
		        \brief Hex Encode the input string.
	        */
	        virtual std::string Encode(const std::string& input) = 0;

	        /*! 
		        \fn Decode
		        \brief Hex Decode the input string
	        */
	        virtual std::string Decode(const std::string& input) = 0;
        	
        public:
	        CryptProvider();
	        virtual ~CryptProvider();
        };
    }
}