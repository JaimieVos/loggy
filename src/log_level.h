#pragma once

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
}