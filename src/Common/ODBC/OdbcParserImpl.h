#pragma once

#include "OdbcParser.h"

namespace AppSecInc 
{
	namespace Databases 
	{
		namespace ODBC 
		{
			class CommandSet;

			class OdbcParserImpl {
			public:
				OdbcParserImpl();
				virtual ~OdbcParserImpl();

				void setPathResolver(PathResolver* resolver);
				void setDelimiters(const std::vector<const std::wstring>& delimiters);
				void setSqlFlavour(const std::wstring& sqlFlavour);
				PathResolver* getPathResolver() const;
				
				// insert additional input from the specified source
				// (e.g. file) in the current point
				void insertSource(const std::wstring& path);
				// insert additional input in the current point
				void insertInput(const std::wstring& input);

				bool hasMore() const;
				std::wstring getNextBatch();
				
				bool exitOnErrorFlag();
				void setExitOnErrorFlag( bool on );
				
				std::wstring processInsertsOnly();
				
				void checkInitialState();
				
			private:
				void prepareNext(std::wstring& buffer, bool processInsertsOnly);
				void nextline(std::wstring& buffer);

				CommandSet*               commandSet;
				PathResolver*             pathResolver;
				unsigned int              currPos;
				std::wstring              sql;
				bool                      exitOnError;
			};
		}
	}
}
