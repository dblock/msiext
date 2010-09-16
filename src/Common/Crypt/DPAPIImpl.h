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
            std::wstring Protect(const std::wstring& input, const std::wstring& entropy = L"");
            std::string Protect(const std::string& input, const std::string& entropy = "");
            std::wstring UnProtect(const std::wstring& input, const std::wstring& entropy = L"");
            std::string UnProtect(const std::string& input, const std::string& entropy = "");
        };
    }
}