#include "StdAfx.h"
#include "CoInitialize.h"



using namespace AppSecInc::Com;

CCoInitialize::CCoInitialize(void)
{
    CHECK_HR(CoInitializeEx(NULL, COINIT_MULTITHREADED),
        L"CoInitializeEx");
}

CCoInitialize::~CCoInitialize(void)
{
	CoUninitialize();
}
