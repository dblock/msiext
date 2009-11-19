#pragma once

namespace AppSecInc
{
    namespace Crypt
    {
        /*! \class DPAPIImpl
	        \brief This class implements basic cryptographic operations using the Microsoft DPAPI
        */
        class DPAPIImpl
        {
        public:
            static std::string Protect(const std::string& input, const std::string& entropy = "");
            static std::string UnProtect(const std::string& input, const std::string& entropy = "");
        private:	
	        DPAPIImpl(); // making this private as this class only exposes static objects
        };
    }
}