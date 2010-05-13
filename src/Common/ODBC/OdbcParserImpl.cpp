#include "stdafx.h"
#include "OdbcParserImpl.h"
#include "CommandSet.h"

using namespace AppSecInc::Databases::ODBC;

static FilesystemPathResolver defaultPathResolver;
static CommandSet emptySet;

OdbcParserImpl::OdbcParserImpl()
	: commandSet(&emptySet)
	, pathResolver(&defaultPathResolver)
	, currPos(0)
	, exitOnError(true)
{

}

OdbcParserImpl::~OdbcParserImpl()
{

}

void OdbcParserImpl::setPathResolver(PathResolver* resolver) 
{
	checkInitialState();
	pathResolver = resolver;
}

PathResolver* OdbcParserImpl::getPathResolver() const
{
	return pathResolver;
}

void OdbcParserImpl::setDelimiters(const std::vector<const std::wstring>& delimiters) 
{
	checkInitialState();
	commandSet = CommandSet::getForDelimiters(delimiters);
}

void OdbcParserImpl::setSqlFlavour(const std::wstring& sqlFlavour) 
{
	checkInitialState();
	commandSet = CommandSet::getForFlavour(sqlFlavour);
}

void OdbcParserImpl::insertSource(const std::wstring& path) 
{
	insertInput( pathResolver->readContent(path) );
}

void OdbcParserImpl::insertInput(const std::wstring& input)
{
	char inputDelimiter = (input.length() > 0) ? input[input.length() - 1] : 0;
	char sqlDelimiter = (currPos < sql.length()) ? sql[currPos] : 0;

	if (inputDelimiter != L'\n' && inputDelimiter != L'\r' 
		&& sqlDelimiter != L'\n' && sqlDelimiter != L'\r')
	{
		sql.insert(currPos, L"\n");
	}

	sql.insert(currPos, input);
}

bool OdbcParserImpl::hasMore() const
{
	return currPos < sql.length();
}

std::wstring OdbcParserImpl::getNextBatch()
{
	std::wstring next;
	prepareNext(next, false);
	AppSecInc::StringUtils::lrtrimcrlf(next);
	return next;
}

std::wstring OdbcParserImpl::processInsertsOnly()
{
	std::wstring buffer;
	prepareNext(buffer, true);
	return buffer;
}

void OdbcParserImpl::nextline(std::wstring& buffer)
{
	int start = currPos;
	while(currPos < sql.length() && sql[currPos] != L'\n' && sql[currPos] != L'\r')
		currPos++;
	buffer = sql.substr(start, currPos - start + 1);
	currPos++;
}

void OdbcParserImpl::prepareNext(std::wstring& buffer, bool processInsertsOnly)
{
	while (currPos < sql.length()) 
	{
		std::wstring currLine;
		nextline(currLine);
		Command* cmd = commandSet->findCommand( currLine );
		if (cmd == 0 || (processInsertsOnly && ! cmd->isInsert())) 
		{
			buffer.append( currLine );
		}
		else 
		{
			cmd->process( currLine, *this );
			
			if (cmd->isBatchTerminator()) 
			{
				break;
			}
		}
	}
}

void OdbcParserImpl::checkInitialState()
{
	if (currPos > 0) 
	{
		throw std::exception("Illegal operation - allowed only in initial state");
	}
}

bool OdbcParserImpl::exitOnErrorFlag()
{
	return exitOnError;
}

void OdbcParserImpl::setExitOnErrorFlag( bool on )
{
	exitOnError = on;
}

