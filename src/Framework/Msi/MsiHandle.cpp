#include "StdAfx.h"
#include "MsiHandle.h"

MsiHandle::MsiHandle() 
	: m_h(0)
{

}

MsiHandle::MsiHandle(MSIHANDLE h)
	: m_h(h)
{

}

MsiHandle::~MsiHandle()
{
    if (m_h != 0) 
    {
        Close();
    }
}

void MsiHandle::Close()
{
    CHECK_WIN32_DWORD(::MsiCloseHandle(m_h),
        L"Error closing handle " << std::hex << m_h);

    m_h = NULL;
}

void MsiHandle::operator =(MSIHANDLE h) 
{
    if (m_h) 
    {
        Close();
    }

    m_h = h;
}

MsiHandle::operator MSIHANDLE() 
{
    return m_h;
}

MSIHANDLE * MsiHandle::operator &() 
{
    if (m_h) 
    {
        Close();
    }

    return &m_h;
}
