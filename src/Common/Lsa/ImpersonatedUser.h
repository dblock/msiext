#pragma once

namespace AppSecInc 
{
    namespace LSA
    {
        //! This class lets the calling thread manage the impersonated security context of a logged-on user.
        class ImpersonatedUser : public LoggedOnUser
        {
        private:
            bool m_impersonated;
        public:
            ImpersonatedUser();
            virtual ~ImpersonatedUser();
            //! impersonate the logged-on user
            void Impersonate();
            //! revert to the prior security context of the currently impersonated thread
            void RevertToSelf();
            //! returns true if the user is impersonated
            bool IsImpersonated() const { return m_impersonated; }
        };
    }
}

