#pragma once

namespace AppSecInc
{
	namespace Databases
	{
		namespace ODBC
		{
            //! An ODBC parameters
			class ODBCParameters
			{
			private:
                //! parameters bound to the statement
				std::vector<ODBCParameter> _parameters;
                //! copy a parameters is forbidden
                ODBCParameters& operator=(const ODBCParameters& value) { };
			public:
                //! get the number of parameters
                unsigned int GetParameterCount() const { return _parameters.size(); }
                //! get a parameter by name
				const ODBCParameter& operator[](const std::wstring& name) const;
                //! get a parameter by index
                const ODBCParameter& operator[](int index) const;
                //! add a named parameter
				void AddParameter(const ODBCParameter& p);
                //! bind the parameters to a connection
				void Bind(SQLHSTMT stmt);
				ODBCParameters();
				virtual ~ODBCParameters();
			};
		}
	}
}
