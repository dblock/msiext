#include "StdAfx.h"
#include "LoggedOnUser.h"
#include "ImpersonatedUser.h"

using namespace AppSecInc::LSA;

ImpersonatedUser::ImpersonatedUser()
    : m_impersonated(false)
{

}

ImpersonatedUser::~ImpersonatedUser()
{
    if (m_impersonated)
    {
        RevertToSelf();
    }
}

void ImpersonatedUser::Impersonate()
{
    if (m_impersonated)
    {
        RevertToSelf();
    }

    CHECK_BOOL(IsLoggedOn(),
        L"User must be logged on first");

    CHECK_WIN32_BOOL(::ImpersonateLoggedOnUser(m_hUser),
        L"Error in ImpersonateLoggedOnUser");

    m_impersonated = true;
}

void ImpersonatedUser::RevertToSelf()
{
    CHECK_BOOL(m_impersonated,
        L"Not impersonated");

    CHECK_WIN32_BOOL(::RevertToSelf(),
        L"Error in RevertToSelf");

    m_impersonated = false;
}

