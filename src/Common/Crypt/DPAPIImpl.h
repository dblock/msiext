#pragma once

namespace AppSecInc
{
    namespace Crypt
    {
        /*! \namespace DPAPI
	        \brief This class implements basic cryptographic operations using the Microsoft DPAPI
        */
        namespace DPAPIImpl
        {
            std::string Protect(const std::string& input, const std::string& entropy = "");
            std::string UnProtect(const std::string& input, const std::string& entropy = "");
        };
    }
}