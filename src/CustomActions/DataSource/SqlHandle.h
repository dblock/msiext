#pragma once

namespace AppSecInc {
namespace DataSource {

//! A smart pointer for an SQLHANDLE
class SqlHandle
{
 public:
	SqlHandle(short type);
	SqlHandle(SQLHANDLE h, short type);
	~SqlHandle();
	operator SQLHANDLE() { return m_h; }
	SQLHANDLE* operator &();
	void Release();
private:
	short m_type;
	SQLHANDLE m_h;
};

}}
