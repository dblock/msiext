#include "StdAfx.h"
#include "DemoService.h"

int _tmain(int argc, _TCHAR* argv[])
{
	DemoService demo;
	demo.Start();
	demo.Wait();
	return 0;
}
