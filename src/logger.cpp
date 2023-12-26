#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <iostream>

#include <logger.h>

#ifdef _WIN32
#define localtime_safe(a, b) localtime_s(a, b)
#else
#define localtime_safe(a, b) localtime_r(b, a)
#endif

namespace loggy
{
	void Logger::initialize()
	{
		setDefaultLogLevel(LogLevel::DEBUG);
		setTimestampFormat("%Y-%m-%d %H:%M:%S");
		setSourceInfoFormat("%f:%l");
		setLogFormat("%t [%l] %s: %m");
	}

	void Logger::log(const Log& logMessage, const char* file, const int line)
	{
		log(logMessage, m_DefaultLogLevel, file, line);
	}

	void Logger::log(const Log& logMessage, const LogLevel logLevel, const char* file, const int line)
	{
		const std::string formattedLogMessage = getFormattedLogMessage(logMessage, logLevel, file, line);
		
		std::lock_guard<std::mutex> lock(m_Mutex);
		std::cout << formattedLogMessage << '\n';
	}

	void Logger::setDefaultLogLevel(LogLevel logLevel)
	{
		std::lock_guard<std::mutex> lock(m_Mutex);
		m_DefaultLogLevel = logLevel;
	}

	void Logger::setTimestampFormat(const std::string& timestampFormat)
	{
		std::lock_guard<std::mutex> lock(m_Mutex);
		m_TimestampFormat = timestampFormat;
	}

	void Logger::setSourceInfoFormat(const std::string& sourceInfoFormat)
	{
		std::lock_guard<std::mutex> lock(m_Mutex);
		m_SourceInfoFormat = sourceInfoFormat;
	}

	void Logger::setLogFormat(const std::string& logFormat)
	{
		std::lock_guard<std::mutex> lock(m_Mutex);
		m_LogFormat = logFormat;
	}

	std::string Logger::getTimestamp()
	{
		std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		
		struct tm timeinfo;
		if (localtime_safe(&timeinfo, &now) != 0)
		{
			return "Error in " + std::string(__FILE__) + ":" + std::string(__FUNCTION__) + " - localtime_s failed";
		}

		std::ostringstream os;
		os << std::put_time(&timeinfo, m_TimestampFormat.c_str());
		
		return os.str();
	}

	std::string Logger::getSourceInfo(const char* file, const int line)
	{
		std::string formattedInfo = m_SourceInfoFormat;

		// Replace %f with the file name
		size_t found = formattedInfo.find("%f");
		while (found != std::string::npos)
		{
			formattedInfo.replace(found, 2, file);
			found = formattedInfo.find("%f", found + 1);
		}

		// Replace %l with the line number
		found = formattedInfo.find("%l");
		while (found != std::string::npos)
		{
			formattedInfo.replace(found, 2, std::to_string(line));
			found = formattedInfo.find("%l", found + 1);
		}

		return formattedInfo;
	}

	std::string Logger::getFormattedLogMessage(const std::string& logMessage, const LogLevel logLevel, const char* file, const int line)
	{
		std::string formattedInfo = m_LogFormat;

		// Replace %t with the timestamp
		size_t found = formattedInfo.find("%t");
		while (found != std::string::npos)
		{
			formattedInfo.replace(found, 2, getTimestamp());
			found = formattedInfo.find("%t", found + 1);
		}

		// Replace %l with the log level
		found = formattedInfo.find("%l");
		while (found != std::string::npos)
		{
			formattedInfo.replace(found, 2, toString(logLevel));
			found = formattedInfo.find("%l", found + 1);
		}

		// Replace %s with the source info
		found = formattedInfo.find("%s");
		while (found != std::string::npos)
		{
			formattedInfo.replace(found, 2, getSourceInfo(file, line));
			found = formattedInfo.find("%s", found + 1);
		}

		// Replace %m with the log message
		found = formattedInfo.find("%m");
		while (found != std::string::npos)
		{
			formattedInfo.replace(found, 2, logMessage);
			found = formattedInfo.find("%m", found + 1);
		}

		return formattedInfo;
	}

	std::mutex Logger::m_Mutex;
	LogLevel Logger::m_DefaultLogLevel;
	std::string Logger::m_TimestampFormat;
	std::string Logger::m_SourceInfoFormat;
	std::string Logger::m_LogFormat;
}