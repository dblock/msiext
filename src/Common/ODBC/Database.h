#pragma once

namespace AppSecInc
{
	namespace Databases
	{
        namespace ODBC
        {
		    //! A generic database
		    class ODBCDatabase
		    {
		    public:
                //! constructor
			    ODBCDatabase();
                //! connect to the database server
                virtual void Connect() = 0;
                //! disconnect from the database server
                virtual void Disconnect() = 0;
                //! create the database, fail if exists
                virtual void Create() = 0;
                //! returns true if database exists
                virtual bool Exists() = 0;
                //! drop the database
                virtual void Drop() = 0;
                //! create the database if it doesn't exist
                virtual void CreateIfNotExists();
                //! drop the database if it exists
                virtual void DropIfExists();
                //! destructor
			    virtual ~ODBCDatabase();
		    };
        }
	}
}

