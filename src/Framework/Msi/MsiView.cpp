#include "StdAfx.h"
#include "MsiView.h"

MsiView::MsiView() 
	: m_h(0)
{

}

MsiView::MsiView(MSIHANDLE h)
	: m_h(h)
{

}

MsiView::~MsiView()
{
    if (m_h!=0) 
    {
        MsiViewClose(m_h);
        MsiCloseHandle(m_h);
    }
}

void MsiView::operator =(MSIHANDLE h) 
{
    if (m_h) 
    {
        MsiViewClose(m_h); 
        MsiCloseHandle(m_h);
    }

    m_h = h;
}

MsiView::operator MSIHANDLE() 
{
    return m_h;
}

MSIHANDLE * MsiView::operator &() 
{
    if (m_h) 
    {
        MsiViewClose(m_h); 
        MsiCloseHandle(m_h);
        m_h = 0;
    }

    return &m_h;
}
