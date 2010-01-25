#pragma once

namespace AppSecInc
{
	namespace Databases
	{
		namespace ODBC
		{
			class OdbcParserImpl;
			class PathResolver;
			
			/*! Class provides parsing of sql scripts that emulates parsing
			  in vendor-specific command-line tools (sqlplus, osql, etc.),
			  particularly:
			    - Splitting of sql scripts to executable batches by vendor-specific
			      delimiters (e.g. by 'go' for MSSQL and '/' in Oracle)
			    - Inserting other sql scripts (':r' and '@' commands).
			  Other vendor-specific sql commands may also be supported 
			  (e.g. output control, ignoring/respecting sql errors, etc).
			  
			  Parsing follows common command-line tools conventions:
			   - All commands/delimiters are case-insensitive.
			   - All commands/delimiters are recognized only at the beginning
			     of line.
			  
			  Type of command-line tool is selected with setSqlFlavor() method;
			  method setDelimiters() is provided only for compatibility with
			  existing MSI actions and odbq --delimiter option, 
			  without  insertion support.
			  
			  Parser may be used both with files and other sources, e.g. with
			  MSI binary streams, see PathResolver below.
			  
			  Parser input is provided either with setSourcePath() or with
			  setInput() method.
			*/
			class OdbcParser
			{
			  public:
				OdbcParser();
				virtual ~OdbcParser();

				/*! \brief select sql flavor (type of command-line tool)
				    \param sqlFlavour sql flavour, case-insensitive.
				                      One of 'sqlserver', 'mssql', 'osql', 'tsql',
				                      'sqlcmd', 'oracle',sqlplus', 'sql*plus'.*/
				void setSqlFlavour(const std::wstring& sqlFlavour);
				//! set arbitrary delimiters (insert commands not supported)
				void setDelimiters(const std::vector<const std::wstring>& delimiters);
				//! set path resolver (default - file system path resolver)
				void setPathResolver(PathResolver* pathResolver);
				//! set input source path (e.g. file name or MSI binary ID)
				void setSourcePath(const std::wstring& sourceName);
				//! set input string to process
				void setInput(const std::wstring& input);
				
				//! check if there are more batches in the input
				bool hasMore();
				//! get next batch to execute
				std::wstring getNextBatch();

				// return input with all files inserted (flatten input)
				std::wstring processInsertsOnly();
				
			  private:
				OdbcParser(const OdbcParser& other);
				OdbcParser& operator=(const OdbcParser& other);
				OdbcParserImpl* pimpl;
			};

			/*! This interface abstracts resolving inserted paths and reading
			  corresponding content. It allows to support insertion both from
			  a file system and e.g. MSI binary streams where inserted paths
			  may be mapped to the corresponding binary stream IDs.
			*/
			class PathResolver {
			  public:
				//! Locate the path and read its content
				virtual std::wstring readContent(const std::wstring& path) = 0;
				/*! These two method are reserved for supporting paths relative to
				    the current file (@@ command in Oracle, not supported now):
				*/
				virtual void setBasePath(const std::wstring& path) {}
				virtual std::wstring getFolderPath(const std::wstring& path) {return L"";}
			};
			
			//! default implementation of PathResolver
			class FilesystemPathResolver: public PathResolver {
			  public:
				virtual std::wstring readContent(const std::wstring& path);
			};
		}
	}
}
