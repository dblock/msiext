#pragma once

namespace AppSecInc
{
    namespace Crypt
    {
        /*! \class DPAPICryptProvider
	        \brief Implements CryptProvider functions. This class uses Microsoft 
		           Data Protect API (DPAPI) to protect and unprotect the data.
		           A non-admin user can run the functions defined in this class.
        */
        class DPAPICryptProvider : public CryptProvider
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

            /*! 
		        \fn CanUnprotect
		        \brief Checks if DPAPI_ENCRYPTED_PREFIX is present in the input and then decides if it can
			           unprotect it.
	        */
	        bool CanUnprotect(const std::string& input);	

        protected:
	        /*! The optional entropy gives only our code the opportunity to decrypt the data.
		        It acts like a double password and is useful when the data blob is persisted. */
	        std::string m_Entropy; 

        public:
	        /*! This value gets embedded in the final encrypted string
	            and it helps in identifying the encryption style during unprotect. */
	        static const std::string DPAPI_ENCRYPTED_PREFIX;

        public:
	        DPAPICryptProvider();
	        DPAPICryptProvider(const std::string&);
	        ~DPAPICryptProvider();
        	
	        /*! 
		        \fn SetEntropy
		        \brief Set a entropy string for used by the DPAPI functions. This acts as a double password.
	        */
	        void SetEntropy(const std::string& entropy);

	        /*! 
		        \fn GetEntropy
		        \brief Gets the entropy value.
	        */
	        const std::string& GetEntropy() const;
        };
    }
}