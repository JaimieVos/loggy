#pragma once

#include <logger.h>
#include <log.h>

namespace loggy
{
#define LOGGY_INIT() Logger::initialize();
#define LOGGY_SET_DEFAULT_LOG_LEVEL(logLevel) Logger::setDefaultLogLevel(logLevel)
#define LOGGY_SET_TIMESTAMP_FORMAT(timestampFormat) Logger::setTimestampFormat(timestampFormat)
#define LOGGY_SET_SOURCE_INFO_FORMAT(sourceInfoFormat) Logger::setSourceInfoFormat(sourceInfoFormat)
#define LOGGY_SET_LOG_FORMAT(logFormat) Logger::setLogFormat(logFormat)

#define LOGGY_LOG1(logMessage) Logger::log(Log() << logMessage, __FILE__, __LINE__)
#define LOGGY_LOG2(logMessage, logLevel) Logger::log(Log() << logMessage, logLevel, __FILE__, __LINE__)

#define EXPAND(x) x
#define GET_MACRO(_1, _2, NAME, ...) NAME
#define LOGGY_LOG(...) EXPAND(GET_MACRO(__VA_ARGS__, LOGGY_LOG2, LOGGY_LOG1)(__VA_ARGS__))
}