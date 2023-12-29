#pragma once

#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

#include <log_level.h>
#include <log.h>

namespace loggy
{
	class Logger
	{
	public:
		/**
		 * @brief Initialize the logger
		 */
		static void initialize();

		/**
		 * @brief Log a message to the console.
		 * 
		 * @param logMessage The log message.
		 * @param file The file the log message is from.
		 * @param line The line the log message is from.
		 */
		static void log(const Log& logMessage, const char* file, const int line);

		/**
		 * @brief Log a message to the console.
		 *
		 * @param logMessage The log message.
		 * @param logLevel The log level of the message.
		 * @param file The file the log message is from.
		 * @param line The line the log message is from.
		 */
		static void log(const Log& logMessage, const LogLevel logLevel, const char* file, const int line);
		
		/**
		 * @brief Sets the default log level.
		 * 
		 * @param logLevel The default log level.
		 */
		static void setDefaultLogLevel(LogLevel logLevel);

		/**
		 * @brief Sets the timestamp format.
		 * 
		 * @param timestampFormat The timestamp format.
		 */
		static void setTimestampFormat(const std::string& timestampFormat);

		/**
		 * @brief Sets the source info format.
		 * 
		 * @param sourceInfoFormat The source info format.
		 */
		static void setSourceInfoFormat(const std::string& sourceInfoFormat);

		/**
		 * @brief Sets the log format.
		 * 
		 * @param logFormat The log format.
		 */
		static void setLogFormat(const std::string& logFormat);

	private:
		/**
		 * @brief Gets the formatted timestamp.
		 * 
		 * @return The formatted timestamp.
		 */
		static std::string getTimestamp();

		/**
		 * @brief Gets the formatted source info string.
		 * 
		 * @param file The file name.
		 * @param line The line number.
		 * @return The formatted source info string.
		 */
		static std::string getSourceInfo(const char* file, const int line);

		/**
		 * @brief Format a log message.
		 *
		 * @param logMessage The log message
		 * @param logLevel The log level of the message.
		 * @param file The file the log message is from.
		 * @param line The line the log message is from.
		 * @return The formatted log message.
		 */
		static std::string getFormattedLogMessage(const std::string& logMessage, const LogLevel logLevel, const char* file, const int line);

	private:
		/**
		 * @brief The mutex used for thread safety.
		 */
		static std::mutex m_Mutex;
		
		/**
		 * @brief The default log level.
		 */
		static LogLevel m_DefaultLogLevel;

		/**
		 * @brief The format for the timestamp
		 */
		static std::string m_TimestampFormat;

		/**
		 * @brief The format for the source info
		 */
		static std::string m_SourceInfoFormat;

		/**
		 * @brief The format for the log message
		 */
		static std::string m_LogFormat;
	};
}