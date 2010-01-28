#pragma once

#include "Command.h"

namespace AppSecInc 
{
	namespace Databases 
	{
		namespace ODBC 
		{
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
		}
	}
}
