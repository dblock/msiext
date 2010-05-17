#pragma once

namespace AppSecInc
{
	//! Win32 File support functions
	namespace File
	{
		/*!
         \brief Create a temporary file and return its name.
		 \return name of the temporary file
		*/
		std::string GetTemporaryFileNameA();
		std::wstring GetTemporaryFileNameW();

		/*!
         \brief Get the location of the temporary directory.
		 \return name of the temporary directory
		*/
		std::string GetTemporaryDirectoryA();
		std::wstring GetTemporaryDirectoryW();

		/*!
         \brief Get the full path to the module's filename.
		 \return the result from Win32 ::GetModuleFilename
		*/
		std::string GetModuleFileNameA(HINSTANCE h = NULL);
		std::wstring GetModuleFileNameW(HINSTANCE h = NULL);

		/*!
         \brief Get the full path (directory) of the module's filename.
		 \return directory portion of the result from Win32 ::GetModuleFilename
		*/
		std::string GetModuleDirectoryA();
		std::wstring GetModuleDirectoryW();

		/*!
         \brief Get the directory portion of a full path.
		 \param path input path
		 \return directory portion of the path
		*/
		std::string GetFileDirectoryA(const std::string& path);
		std::wstring GetFileDirectoryW(const std::wstring& path);

		/*!
         \brief Get the filename portion of a full path.
		 \param path input path
		 \return file name portion of the path
		*/
		std::string GetFileNameA(const std::string& path);
		std::wstring GetFileNameW(const std::wstring& path);

		/*!
         \brief Get the current directory.
		 \return current directory
		*/
		std::string GetCurrentDirectoryA();
		std::wstring GetCurrentDirectoryW();

		/*!
         \brief Check whether a file exists.
		 
		 Unlike Win32 ::PathFileExists this function fails when the parameter is not a file 
		 (eg. a directory) or on other errors (eg. access denied).
		 \param filename full path of the file to check
		 \return true if file exists, false otherwise
		*/
		bool FileExists(const std::string& filename);
		bool FileExists(const std::wstring& filename);

		/*!
		  \brief Delete a file.
		  \param filename full path of the file to delete		  
		*/
		void FileDelete(const std::string& filename);
		void FileDelete(const std::wstring& filename);

		/*!
		  \brief Check whether a directory exists.

		  Unlike Win32 ::PathFileExists this function fails when the parameter is not a directory 
		  (eg. a file) or on other errors (eg. access denied).
		  \param path full path of the directory to check
		  \return true if directory exists, false otherwise
		*/
		bool DirectoryExists(const std::string& path);
		bool DirectoryExists(const std::wstring& path);

		/*!
		  \brief Create a directory.
		  \param path full path to the directory to create
		  \return first path created

		  Create a directory with any subdirectories missing.
		  This function will create subdirectories and will return the first directory actually created.
		*/
		std::string DirectoryCreate(const std::string& path);
		std::wstring DirectoryCreate(const std::wstring& path);

        enum DELETE_DIRECTORY_FLAGS
        {
            DELETE_DIRECTORY_FILES = 1, //! delete files
            DELETE_DIRECTORY_FOLDERS = 2, //! delete folders
            DELETE_DIRECTORY_SUBDIRECTORIES = 4, //! delete subdirectories
            DELETE_DIRECTORY_EMPTY = DELETE_DIRECTORY_FOLDERS | DELETE_DIRECTORY_SUBDIRECTORIES, //! delete empty (sub)directories only
            DELETE_DIRECTORY_ALL = DELETE_DIRECTORY_FILES | DELETE_DIRECTORY_FOLDERS | DELETE_DIRECTORY_SUBDIRECTORIES //! delete everything
        };

		/*!
		  \brief Delete a directory.
		  \param path full path to the directory to delete
          \param flags flags for directory deletion
          \return true if directory (and all subdirectories and files) have been deleted, false otherwise

		  Delete directories with subdirectories. Optionally delete files
          and subdirectories. If flags is DELETE_DIRECTORY_FOLDERS deletes empty (sub)directories
          only. If an error occurs, the process aborts with an exception.

		  No error is thrown if the directory doesn't exist or if it contains no files or subdirectories.
		*/
		bool DirectoryDelete(const std::string& path, int flags = DELETE_DIRECTORY_ALL);
		bool DirectoryDelete(const std::wstring& path, int flags = DELETE_DIRECTORY_ALL);

        /*!
         \brief Get file size.
         \return file size in bytes, note that some directories may return a positive size
        */
        long GetFileSize(const std::wstring& filename);
        long GetFileSize(const std::string& filename);

        enum FILESIZE_STRING_TYPE
        {
            FILESIZE_AUTO = 0, //! automatically adjust
            FILESIZE_BYTES = 2, //! byte(s)
            FILESIZE_KBYTES = 3, //! Kb
            FILESIZE_MBYTES = 4, //! Mb
            FILESIZE_GBYTES = 5, //! Gb
        };

        const long BYTE = 1;
        const long KBYTE = BYTE * 1024;
        const long MBYTE = KBYTE * 1024;
        const long GBYTE = MBYTE * 1024;

        /*!
         \brief Convert a file size into a pair of strings.
         \param size size to convert
         \param type type of conversion
         \param precision decimal precision
         \return a pair of string representation of a size and its type
        */
        std::pair<std::string, std::string> SizeToStringPairA(long size, FILESIZE_STRING_TYPE type = FILESIZE_AUTO, int precision = 0);
        std::pair<std::wstring, std::wstring> SizeToStringPairW(long size, FILESIZE_STRING_TYPE type = FILESIZE_AUTO, int precision = 0);

        /*!
         \brief Convert a file size into a string.
         \param size size to convert
         \param type type of conversion
         \param precision decimal precision
         \return a string representation of a size, including its type
        */
        std::string SizeToStringA(long size, FILESIZE_STRING_TYPE type = FILESIZE_AUTO, int precision = 0);
        std::wstring SizeToStringW(long size, FILESIZE_STRING_TYPE type = FILESIZE_AUTO, int precision = 0);

		/*!
		  \brief Combine two directory paths and an optional file.
		*/
        std::wstring DirectoryCombine(const std::wstring& dir, const std::wstring& file);

        enum GET_FILES_FLAGS
        {
            GET_FILES_FILES = 1, //! return files
            GET_FILES_DIRECTORIES = 2, //! return directory names
            GET_FILES_RECURSIVE = 4, //! recurse into subdirectories
            GET_FILES_ALL = GET_FILES_FILES | GET_FILES_DIRECTORIES | GET_FILES_RECURSIVE
        };

		/*!
		  \brief Get a list of files in a directory structure.
          \return a list of files and/or directories with or without subdirectories
          \param path path at which to start looking
          \param flags combination of \ref GET_FILES_FLAGS
		*/
        std::list<std::wstring> GetFiles(const std::wstring& path, const std::wstring& wildcard = L"*.*", int flags = GET_FILES_FILES);

		/*!
		  \brief Get a list of files in a directory structure.
          \return a list of files and/or directories with or without subdirectories
          \param path_and_wildcard a combination of path and wildcard at which to start looking
          \param flags combination of \ref GET_FILES_FLAGS
		*/
        std::list<std::wstring> GetFiles(const std::wstring& path_and_wildcard, int flags);

        /*! 
         \brief Get a list of file names in path
         \param path full path
         \param wildcard of files to find
		 \note Unlike GetFiles, this function doesn't return the full path to the file(s).
        */
        std::list<std::wstring> GetDirectoryFiles(const std::wstring& path, const std::wstring& wildcard = L"*.*");

        /*!
         \brief Read the entire contents of file.
         \param filename path to a file with non-UNICODE contents
         \return full contents of file as a UNICODE string
        */
        void ReadToEnd(const std::wstring& filename, std::wstring& data);

        /*!
         \brief Read the entire contents of file.
         \param filename path to a file
         \return full contents of file as an ANSI string
        */
        void ReadToEnd(const std::wstring& filename, std::string& data);

        /*!
         \brief Read the entire contents of file.
         \param filename path to a file
         \return full contents of file
        */
        void ReadToEnd(const std::wstring& filename, std::vector<char>& data);

		/*! UTF8 byte order mark */
		static unsigned char utf8_bom[] = { 0xef, 0xbb, 0xbf };

        /*!
         \brief Read the entire contents of file and convert to UNICODE depending on the file marker.			    
         \param filename path to a file
         \data output, full contents of file in UNICODE format
		 \return true if UTF8 conversion has occurred
		 \remarks Currently supports UTF-8 only.
        */
		bool ReadAndConvertToEnd(const std::wstring& filename, std::wstring& data);

        /*!
         \brief Write data to a file
         \param data data to write
         \param dwShareMode share mode
         \param dwCreationDisposition creation disposition
         \param dwFlagsAndAttributes flags and attributes
         */
        void FileWrite(
            const std::wstring& filename, 
            const std::vector<char>& data,
            DWORD dwShareMode = GENERIC_READ | GENERIC_WRITE,
            DWORD dwCreationDisposition = CREATE_ALWAYS,
            DWORD dwFlagsAndAttributes = FILE_ATTRIBUTE_NORMAL);

        /*!
         \brief Create an empty file
         \param dwShareMode share mode
         \param dwCreationDisposition creation disposition
         \param dwFlagsAndAttributes flags and attributes
         */
        void FileCreate(
            const std::wstring& filename, 
            DWORD dwShareMode = GENERIC_READ | GENERIC_WRITE,
            DWORD dwCreationDisposition = CREATE_ALWAYS,
            DWORD dwFlagsAndAttributes = FILE_ATTRIBUTE_NORMAL);

        /*!
         \brief Get the parent directory of a path.
         \param path existing directory
		 \return parent directory, an empty string if path is empty and the same value if there's no parent directory
         */
		std::string GetParentDirectory(const std::string& path);


        /*!
         \brief Get the parent directory of a path.
         \param path existing directory
		 \return parent directory terminated by a backslash, an empty string if path is empty and the same value if there's no parent directory		 
         */
		std::wstring GetParentDirectory(const std::wstring& path);

        /*!
         \brief Takes the CSIDL of a folder and returns the path.
         \param csidl a CSIDL value that identifies the folder whose path is to be retrieved
		 \param create Indicates whether the folder should be created if it does not already exist.
		 \return special folder path
         */
		std::wstring GetSpecialFolderPath(int csidl, BOOL create = FALSE);
		
		//!returns true if provided path is absolute, false otherwise
		bool IsAbsolutePath(const std::wstring& path);
	}
}
