#include "stdafx.h"
#include "OdbcParserImpl.h"
#include "CommandSet.h"

using namespace AppSecInc::Databases::ODBC;

static FilesystemPathResolver defaultPathResolver;
static CommandSet emptySet;


OdbcParserImpl::OdbcParserImpl()
: commandSet(&emptySet),pathResolver(&defaultPathResolver), currPos(0),
  exitOnError(true)
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
	std::vector<std::wstring> inp;
	AppSecInc::StringUtils::tokenize(input, inp, L"\n");
	// do not insert last empty line (artefact of tokenizing when '\n' is at the end)
	int skiplast = 0;
	if (inp.size() > 0 && inp[inp.size() - 1] == L"") {
		skiplast = 1;
	}
	lines.insert(lines.begin() + currPos, inp.begin(), inp.end() - skiplast);
}

bool OdbcParserImpl::hasMore() const
{
	return currPos < lines.size();
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


void OdbcParserImpl::prepareNext(std::wstring& buffer, bool processInsertsOnly)
{
	while (currPos < lines.size()) {
		std::wstring& currLine = lines[currPos++];
		Command* cmd = commandSet->findCommand( currLine );
		if (cmd == 0 || (processInsertsOnly && !cmd->isInsert())) {
			if (!buffer.empty())
				buffer.append(L"\n");
			buffer.append( currLine );
		}
		else {
			cmd->process( currLine, *this );
			if (cmd->isBatchTerminator()) {
				break;
			}
		}
	}
}

void OdbcParserImpl::checkInitialState()
{
	if (currPos >0) {
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

