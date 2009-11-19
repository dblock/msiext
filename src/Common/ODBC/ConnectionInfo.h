#pragma once

namespace AppSecInc
{
	namespace Databases
	{
        namespace ODBC
        {
		    //! A generic connection info
		    class ODBCConnectionInfo
		    {
		    public:
			    ODBCConnectionInfo();
			    virtual ~ODBCConnectionInfo();
                virtual std::wstring GetConnectionString() const = 0;
		    };
        }
	}
}

