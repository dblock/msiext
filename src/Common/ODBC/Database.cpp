#include "StdAfx.h"
#include "Database.h"

using namespace AppSecInc::Databases::ODBC;

ODBCDatabase::ODBCDatabase()
{

}

ODBCDatabase::~ODBCDatabase()
{

}

void ODBCDatabase::CreateIfNotExists()
{
    if (! Exists())
    {
        Create();
    }
}

void ODBCDatabase::DropIfExists()
{
    if (Exists())
    {
        Drop();
    }
}