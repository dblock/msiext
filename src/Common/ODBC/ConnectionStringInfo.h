#pragma once

namespace AppSecInc
{
	namespace Databases
	{
        namespace ODBC
        {
			//! A generic connection info class with a fixed connection string.
            class ODBCConnectionStringInfo : public ODBCConnectionInfo
		    {
            private:
                std::wstring m_cs;
		    public:
                ODBCConnectionStringInfo(const std::wstring& cs);
			    virtual ~ODBCConnectionStringInfo();
                std::wstring GetConnectionString() const { return m_cs; }
		    };
        }
	}
}

