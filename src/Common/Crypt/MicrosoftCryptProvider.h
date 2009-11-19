///////////////////////////////////////////////////////////////////////////////
///  \file MicrosoftCryptProvider.h
///////////////////////////////////////////////////////////////////////////////
#pragma once

namespace AppSecInc
{
    namespace Crypt
    {
        /*! \class MicrosoftCryptProvider
	        \brief Implements the Microsoft CryptProvider.
        */
        class MicrosoftCryptProvider
        {
        private:
	        HCRYPTPROV _hprov;
        public:
	        HCRYPTPROV Peek() const { return _hprov; }
	        void Initialize();
	        void UnInitialize();
	        MicrosoftCryptProvider();
	        ~MicrosoftCryptProvider();
        };
    }
}