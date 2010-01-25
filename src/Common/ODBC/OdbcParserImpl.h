#include "OdbcParser.h"
#include <boost/shared_ptr.hpp>

namespace AppSecInc 
{
	namespace Databases 
	{
		namespace ODBC 
		{
			class Command;
			typedef boost::shared_ptr<Command> CommandPtr;

			class CommandSet {
			  public:
				CommandSet();
				virtual ~CommandSet();
				virtual Command* findCommand(const std::wstring& line) const;
				
				static CommandSet* getForFlavour(const std::wstring& flavour);
				static CommandSet* getForDelimiters(const std::vector<const std::wstring>& delimiters);
			  protected:
				std::vector<CommandPtr> commands;
			};

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
				
				std::wstring processInsertsOnly();
				
				void checkInitialState();
				
			private:
				void prepareNext(std::wstring& buffer, bool processInsertsOnly);
				
				CommandSet*               commandSet;
				PathResolver*             pathResolver;
				unsigned int              currPos;
				std::vector<std::wstring> lines;
			};

			class Command {
			public:
				Command(const std::wstring& name, bool params, bool insert, bool terminator);
				virtual ~Command();
				std::wstring getName() const   { return name; }
				bool hasParams() const         { return params; }
				bool isInsert() const          { return insert; }
				bool isBatchTerminator() const { return batchTerminator; }
				virtual void process(const std::wstring& line, OdbcParserImpl& parser);
			protected:
				std::wstring name;
				bool params;
				bool insert;
				bool batchTerminator;
			};
		}
	}
}
