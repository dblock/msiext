#include "StdAfx.h"
#include "SqlHandle.h"

using namespace AppSecInc::DataSource;

SqlHandle::SqlHandle(short type) 
{ 
	m_type = type; 
	m_h = NULL;
}

SqlHandle::SqlHandle(SQLHANDLE h, short type) 
{ 
	m_type = type; 
	m_h = h; 
}

SqlHandle::~SqlHandle() 
{ 
	Release();
}

SQLHANDLE* SqlHandle::operator &() 
{ 
	Release(); 
	return & m_h; 
}

void SqlHandle::Release() 
{ 
	if (NULL != m_h) 
	{ 
		::SQLFreeHandle(m_type, m_h); 
		m_h = NULL; 
	} 
}
