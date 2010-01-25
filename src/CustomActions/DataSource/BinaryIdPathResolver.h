#pragma once

namespace AppSecInc {
namespace Databases {
namespace ODBC {

	class BinaryIdPathResolver: public AppSecInc::Databases::ODBC::PathResolver
	{
		MsiInstall* msiInstall;
		
	  public:
		BinaryIdPathResolver(MsiInstall* msiInstall);

		//! convert path to binary ID and read its content from msi.
		virtual std::wstring readContent(const std::wstring& path);
		
		virtual void setBasePath(const std::wstring& path) {}
		virtual std::wstring getFolderPath(const std::wstring& path) const {return L"";}

		/*! 
		  Convert path to MSI ID using the following algorithm:
			 a) .\ and ..\ are skipped
			 b) \\ is considered as \
			 c) every \ is replaced with '_'
			 d) every other non-valid ID character is replaced with '_'
		   Example:
			 path '..\\dir\.\file1.sql' converted into 'dir_file1_sql'
		*/
		std::wstring pathToId(const std::wstring& path);
		
		//! replace all non-valid ID characters with '_'
		void replaceNonIdCharsWithUnderscore(std::wstring& str);
	};
}
}
}
