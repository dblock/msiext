#pragma once

namespace AppSecInc {
namespace Msi {

//! A smart pointer for an MSIHANDLE that represents an MSI view
class MsiView
{
 public:
	MsiView();
	MsiView(MSIHANDLE h);
    ~MsiView();
	void operator =(MSIHANDLE h);
	operator MSIHANDLE();
	MSIHANDLE* operator &();
private:
	MSIHANDLE m_h;
};

}}
