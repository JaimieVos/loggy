#pragma once

#include <string>

#include <log_level.h>

namespace loggy
{
	/**
	 * @brief Replace all instances of a symbol in a string with a replacement.
	 * 
	 * @param symbol The symbol to replace.
	 * @param replacement The replacement string
	 * @param string The input string to do the replacements for
	 * @return A new string with the symbols replaced
	 */
	std::string replaceSymbol(const std::string& symbol, const std::string& replacement, std::string string);
}