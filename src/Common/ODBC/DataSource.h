#pragma once

namespace AppSecInc
{
	namespace Databases
	{
		namespace ODBC
		{
			//! An ODBC DataSource
			namespace ODBCDataSource
			{
                //! adds, modifies, or deletes data sources
                void Configure(WORD fRequest, const std::wstring& driver, const std::wstring& attributes);
                //! retrieves errors from SQLInstallerError
                std::vector<ODBCError> GetErrors();
                //! retrieves a combined string error from SQLInstallerError
                std::wstring GetError();
			};
		}
	}
}








