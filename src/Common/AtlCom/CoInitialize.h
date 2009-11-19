#pragma once

namespace AppSecInc
{
    namespace Com
    {
		//! A smart pointer that calls CoInitializeEx
        class CCoInitialize
        {
        public:
            CCoInitialize(void);
            ~CCoInitialize(void);
        private:
            CCoInitialize(const CCoInitialize&);
            void operator=(const CCoInitialize&);
        };
    }
}