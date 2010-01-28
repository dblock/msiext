#pragma once

#include <boost/shared_ptr.hpp>

namespace AppSecInc 
{
	namespace Databases 
	{
		namespace ODBC 
		{
			class OdbcParserImpl;
			
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

			typedef boost::shared_ptr<Command> CommandPtr;

			// class that provides generic insert command processing
			class InsertCommand: public Command {
			public:
				InsertCommand(const std::wstring& name);
				virtual void process(const std::wstring& line, OdbcParserImpl& parser);
			};
			
			// class that provides generic processing for 'on error' command
			// with the following format: 
			// <on-error-command> {<exit-param>|<continue-param>} [other params]
			// e.g. for sqlcmd: :ON ERROR EXIT, :ON ERROR IGNORE
			class OnErrorCommand: public Command {
			public:
				OnErrorCommand(const std::wstring& name,
				               const std::wstring& exitParam,
				               const std::wstring& continueParam);
				virtual void process(const std::wstring& line, OdbcParserImpl& parser);
			private:
				std::wstring exitParam;
				std::wstring continueParam;
			};
			
		}
	}
}
