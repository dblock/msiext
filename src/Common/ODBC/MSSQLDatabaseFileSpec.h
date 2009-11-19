#pragma once

namespace AppSecInc
{
	namespace Databases
	{
		namespace MSSQL
		{
			//! A Microsoft SQL Server database file specification.
            class MSSQLDatabaseFileSpec
			{
            private:
                std::wstring _type;
                std::wstring _filename;
                std::wstring _name;
                std::wstring _growthsize;
                std::wstring _maxsize;
                std::wstring _size;
            public:
                //! the file spec type, eg. PRIMARY, LOG ON or FILEGROUP Group1
                const std::wstring& GetType() const { return _type; }
                void SetType(const std::wstring& value) { _type = value; }
                //! the operating-system file name for the database file
                const std::wstring& GetFilename() const { return _filename; }
                void SetFilename(const std::wstring& value) { _filename = value; }
                //! the logical name for the database file
                const std::wstring& GetName() const { return _name; }
                void SetName(const std::wstring& value) { _name = value; }
                //! the size of the database file, eg. 10MB
                const std::wstring& GetSize() const { return _size; }
                void SetSize(std::wstring value) { _size = value; }
                //! maximum size to which the database file can grow
                const std::wstring& GetMaxSize() const { return _maxsize; }
                void SetMaxSize(std::wstring value) { _maxsize = value; }
                //! growth increment of the database file
                const std::wstring& GetGrowthSize() const { return _growthsize; }
                void SetGrowthSize(std::wstring value) { _growthsize = value; }
			public:
                std::wstring GetCreateQuery() const;
                friend std::wostream& operator<<(std::wostream&, const MSSQLDatabaseFileSpec&);
                //! copy constructor and operator=
                MSSQLDatabaseFileSpec& operator=(const MSSQLDatabaseFileSpec&);
				//! constructors/destructors
                MSSQLDatabaseFileSpec();
                MSSQLDatabaseFileSpec(const MSSQLDatabaseFileSpec& connectioninfo);
				~MSSQLDatabaseFileSpec();
                //! serialize the file spec to xml
                MSXML2::IXMLDOMNodePtr Save(AppSecInc::Xml::XmlDocument& xmldoc, MSXML2::IXMLDOMNodePtr parent) const;
                //! deserialize the file spec from xml
                void Load(AppSecInc::Xml::XmlDocument& xmldoc, MSXML2::IXMLDOMNodePtr root);
			};
		}
	}
}
