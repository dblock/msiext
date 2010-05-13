#include "stdafx.h"
#include "OdbcParserImpl.h"

using namespace AppSecInc::Databases::ODBC;

OdbcParser::OdbcParser()
{
	pimpl = new OdbcParserImpl();
}

OdbcParser::~OdbcParser()
{
	delete pimpl;
}

void OdbcParser::setSqlFlavour(const std::wstring& sqlFlavour)
{
	pimpl->setSqlFlavour(sqlFlavour);
}

void OdbcParser::setDelimiters(const std::vector<const std::wstring>& delimiters)
{
	pimpl->setDelimiters(delimiters);
}

void OdbcParser::setSqlTypeOrDelimiter(
	const std::wstring& sqltype, 
    const std::wstring& delimiter)
{
	if (!sqltype.empty()) 
	{
		pimpl->setSqlFlavour(sqltype);
	}
	else if (! delimiter.empty()) 
	{
		std::vector<const std::wstring> delims;
		delims.push_back(delimiter);
		pimpl->setDelimiters(delims);
	}
}

void OdbcParser::setPathResolver(PathResolver* resolver)
{
	pimpl->setPathResolver(resolver);
}

PathResolver * OdbcParser::getPathResolver() const
{
	return pimpl->getPathResolver();
}

void OdbcParser::setSourcePath(const std::wstring& path)
{
	pimpl->checkInitialState();
	pimpl->insertSource(path);
}

void OdbcParser::setInput(const std::wstring& input)
{
	pimpl->checkInitialState();
	pimpl->insertInput(input);
}

bool OdbcParser::hasMore()
{
	return pimpl->hasMore();
}

std::wstring OdbcParser::getNextBatch()
{
	return pimpl->getNextBatch();
}

bool OdbcParser::exitOnErrorFlag()
{
	return pimpl->exitOnErrorFlag();
}

std::wstring OdbcParser::processInsertsOnly()
{
	return pimpl->processInsertsOnly();
}
