#pragma once

namespace AppSecInc
{
	namespace Databases
	{
		namespace ODBC
		{
			/*! This interface abstracts resolving inserted paths and reading
			  corresponding content. It allows to support insertion both from
			  a file system and e.g. MSI binary streams where inserted paths
			  may be mapped to the corresponding binary stream IDs.
			*/
			class PathResolver 
			{
			  public:
				//! Locate the path and read its content
				virtual std::wstring readContent(const std::wstring& path) = 0;
				
				//! Set base path for resolving relative paths
				virtual void setBasePath(const std::wstring& path) = 0;
				
				//! get folder of the provided path
				virtual std::wstring getFolderPath(const std::wstring& path) const = 0;
			};
			
			
			//! default implementation of PathResolver
			class FilesystemPathResolver: public PathResolver 
			{
			  public:
				FilesystemPathResolver();
				virtual ~FilesystemPathResolver();
				
				virtual std::wstring readContent(const std::wstring& path);
				virtual void setBasePath(const std::wstring& path);
				virtual std::wstring getFolderPath(const std::wstring& path) const;
			
			  private:
				FilesystemPathResolver(const FilesystemPathResolver& other);
				FilesystemPathResolver& operator=(const FilesystemPathResolver& other);
				std::wstring getFullPath(const std::wstring path) const;
				std::wstring basepath;
			};
		}
	}
}
