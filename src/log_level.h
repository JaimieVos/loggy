#pragma once

#include <string>

#include <colors.h>

namespace loggy
{
	/**
	 * @brief The log levels.
	 */
	enum LogLevel
	{
		DEBUG,
		INFO,
		WARNING,
		ERROR,
		FATAL
	};

	/**
	 * @brief Convert a log level to a string.
	 * 
	 * @param logLevel The log level.
	 * @return The log level as a string.
	 */
	inline const char* toString(LogLevel logLevel)
	{
		switch (logLevel)
		{
		case DEBUG:   return "DEBUG";
		case INFO:	  return "INFO";
		case WARNING: return "WARNING";
		case ERROR:   return "ERROR";
		case FATAL:   return "FATAL";
		default:      return "UNKNOWN";
		}
	}

	inline std::string toColor(LogLevel logLevel)
	{
		switch (logLevel)
		{
		case DEBUG:   return ANSI_BG_BLUE + std::string(ANSI_WHITE);
		case INFO:	  return ANSI_BG_GREEN + std::string(ANSI_WHITE);
		case WARNING: return ANSI_BG_YELLOW + std::string(ANSI_WHITE);
		case ERROR:   return ANSI_BG_RED + std::string(ANSI_WHITE);
		case FATAL:   return ANSI_BG_RED + std::string(ANSI_WHITE);
		default:      return ANSI_BG_RESET;
		}
	}
}