#include "stdafx.h"
#include "Command.h"
#include "OdbcParserImpl.h"

using namespace AppSecInc::Databases::ODBC;

Command::Command(const std::wstring& name, bool params, bool insert, bool terminator)
	: name(name)
	, params(params)
	, insert(insert)
	, batchTerminator(terminator) 
{

}

Command::~Command()
{
}

void Command::process(const std::wstring& line, OdbcParserImpl& parser) 
{
    // default - do nothing
}

InsertCommand::InsertCommand(const std::wstring& name) 
	: Command(name, true, true, false) 
{

}

void InsertCommand::process(const std::wstring& line, OdbcParserImpl& parser) 
{
	std::wstring sourceName = line.substr( name.size() );
	AppSecInc::StringUtils::lrtrim( sourceName, L" \t\r\n" );
	parser.insertSource( sourceName );
}

OnErrorCommand::OnErrorCommand(
	const std::wstring& name,
	const std::wstring& eParam,
	const std::wstring& cParam)
	: Command(name, true, false, false)
	, exitParam(eParam)
	, continueParam(cParam)
{

}

void OnErrorCommand::process(const std::wstring& line, OdbcParserImpl& parser) 
{
	std::wstring param = line.substr(name.size());
	AppSecInc::StringUtils::lrtrim(param, L" \t\r");
	AppSecInc::StringUtils::lowercase(param);
	if (AppSecInc::StringUtils::startsWith(param, exitParam))
	{
		parser.setExitOnErrorFlag( true );
	}
	else if (AppSecInc::StringUtils::startsWith(param, continueParam))
	{
		parser.setExitOnErrorFlag( false );
	}
	else
	{
		THROW(L"Unsupported command: " << param);
	}
}
