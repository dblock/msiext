#pragma once

namespace AppSecInc {
namespace Msi {

//! A smart pointer for an MSIHANDLE
class MsiHandle
{
 public:
	MsiHandle();
	MsiHandle(MSIHANDLE h);
    virtual ~MsiHandle();
	void operator =(MSIHANDLE h);
    virtual void Close();
    virtual bool IsOpen() const { return m_h != NULL; }
	operator MSIHANDLE();
	MSIHANDLE* operator &();
protected:
	MSIHANDLE m_h;
};

}}