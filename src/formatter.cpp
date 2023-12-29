#include <formatter.h>

namespace loggy
{
	std::string replaceSymbol(const std::string& symbol, const std::string& replacement, std::string string)
	{
		size_t found = string.find(symbol);
		while (found != std::string::npos)
		{
			string.replace(found, 2, replacement);
			found = string.find(symbol, found + 1);
		}

		return string;
	}
}