#include "StdAfx.h"
#include "DemoService.h"

DemoService::DemoService()
	: AppSecInc::Service::ServiceImpl(L"MsiExtDemoService")
{

}

void DemoService::Run()
{
	OutputDebugStringW(L"DemoService is running ...");
	while(_running)
	{
		Sleep(1000);
	}
	OutputDebugStringW(L"DemoService stopped.");
}
