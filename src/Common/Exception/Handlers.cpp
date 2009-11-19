#include "StdAfx.h"
#include "Handlers.h"

void AppSecInc::Exceptions::COM_EXCEPTION_HANDLER_BLOCK_impl(_com_error& e) 
{
	std::wstringstream os;
	os << "_com_error: [";
	os <<	e.WCode()
		<< "] "
		<< e.ErrorMessage()
		<< ".";
	OutputDebugStringW(os.str().c_str());
}

void AppSecInc::Exceptions::STD_EXCEPTION_HANDLER_BLOCK_impl(std::exception& e) 
{
	std::string errmsg("std::exception: ");
	errmsg += e.what();
	OutputDebugStringA(errmsg.c_str());
}

void AppSecInc::Exceptions::ELLIPSIS_EXCEPTION_HANDLER_BLOCK_impl() 
{
	OutputDebugStringW(L"caught unknown C++ exception");
}
