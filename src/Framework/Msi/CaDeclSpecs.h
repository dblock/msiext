#pragma once

#if defined(CA_EXPORTS)
#define CA_API __declspec(dllexport)
#elif defined(CPPUNIT_TEST)
#define CA_API
#else
#define CA_API __declspec(dllimport)
#endif

