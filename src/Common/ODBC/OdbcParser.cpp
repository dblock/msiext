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

void OdbcParser::setPathResolver(PathResolver* resolver)
{
	pimpl->setPathResolver(resolver);
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

std::wstring OdbcParser::processInsertsOnly()
{
	return pimpl->processInsertsOnly();
}

//-----------------------------------------------------------------------------
std::wstring FilesystemPathResolver::readContent(const std::wstring& path) {
	std::wstring content;
	AppSecInc::File::ReadToEnd(path, content);
	return content;
}

