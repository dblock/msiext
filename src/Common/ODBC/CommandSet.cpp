#include "stdafx.h"
#include "OdbcParserImpl.h"

using namespace AppSecInc::Databases::ODBC;

Command::Command(const std::wstring& name, bool params, bool insert, bool terminator)
: name(name), params(params), insert(insert), batchTerminator(terminator) {
}

Command::~Command()
{
}

void Command::process(const std::wstring& line, OdbcParserImpl& parser) {
    // default - do nothing
}

class InsertCommand: public Command 
{
public:
	InsertCommand(const std::wstring& name)
	: Command(name,true,true,false) {
	}
	virtual void process(const std::wstring& line, OdbcParserImpl& parser) {
		std::wstring sourceName = line.substr( name.size() );
		AppSecInc::StringUtils::lrtrim( sourceName, L" \t\r" );
		parser.insertSource( sourceName );
	}
};

CommandSet::CommandSet() {
}
CommandSet::~CommandSet() {
}

Command* CommandSet::findCommand(const std::wstring& line) const 
{
	std::wstring ln(line);
	AppSecInc::StringUtils::rtrim(ln, L" \t\r");
	AppSecInc::StringUtils::lowercase(ln);
	
	for (unsigned int i = 0; i < commands.size(); i++) {
		if (!commands[i]->hasParams()) {
			if (commands[i]->getName() == ln)
				return commands[i].get();
		}
		else {
			if (AppSecInc::StringUtils::startsWith(ln, commands[i]->getName()))
				return commands[i].get();
		}
	}
	return 0;
}

class SqlcmdCommandSet: public CommandSet {
public:
	SqlcmdCommandSet() {
		commands.push_back( CommandPtr(new Command(L"go", false, false, true)) );
		commands.push_back( CommandPtr(new InsertCommand(L":r ")) );
	}
};

class SqlplusCommandSet: public CommandSet {
public:
	SqlplusCommandSet() {
		commands.push_back( CommandPtr(new Command(L"/", false, false, true)) );
		commands.push_back( CommandPtr(new InsertCommand(L"@@")) );
		commands.push_back( CommandPtr(new InsertCommand(L"@")) );
		commands.push_back( CommandPtr(new Command(L"set ", true, false, false)) );
		commands.push_back( CommandPtr(new Command(L"spool ", true, false, false)) );
	}
};

CommandSet* CommandSet::getForFlavour(const std::wstring& flavour) 
{
	std::wstring flavour_ci = flavour;
	AppSecInc::StringUtils::lowercase( flavour_ci );
	if (L"sql server" == flavour_ci
	 || L"sqlserver"  == flavour_ci
	 || L"mssql"      == flavour_ci
	 || L"tsql"       == flavour_ci
	 || L"osql"       == flavour_ci
	 || L"sqlcmd"     == flavour_ci) {
		static SqlcmdCommandSet sqlcmdSet;
		return &sqlcmdSet;
	}
	if (L"oracle"   == flavour_ci
	 || L"sqlplus"  == flavour_ci
	 || L"sql*plus" == flavour_ci) {
		static SqlplusCommandSet sqlplusSet;
		return &sqlplusSet;
	}
	throw std::logic_error("Unsupported flavour");
}

typedef boost::shared_ptr<CommandSet> CommandSetPtr;
typedef std::pair<std::vector<const std::wstring>,CommandSetPtr> DelimsCsPair;

CommandSet* CommandSet::getForDelimiters(
                        const std::vector<const std::wstring>& delimiters)
{
	static std::vector<DelimsCsPair> csets;
	
	for (unsigned int i = 0;  i < csets.size();  i++) {
		if (csets[i].first == delimiters) {
			return csets[i].second.get();
		}
	}
	CommandSetPtr cs(new CommandSet());
	for (unsigned int i = 0; i< delimiters.size(); i++) {
		std::wstring delim(delimiters[i]);
		AppSecInc::StringUtils::lowercase(delim);
		cs->commands.push_back(CommandPtr(new Command(delim,false,false,true)));
	}
	csets.push_back(DelimsCsPair(delimiters, cs));
	return cs.get();
}
