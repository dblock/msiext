#pragma once

namespace AppSecInc {
namespace Msi {

//! A wrapper for an MSIHANDLE with MSI support functions
class MsiImpersonatedInstall : public MsiInstall
{
private:
    AppSecInc::LSA::ImpersonatedUser m_impersonated_user;
public:
    MsiImpersonatedInstall(MSIHANDLE h);
    ~MsiImpersonatedInstall();
};

}}

