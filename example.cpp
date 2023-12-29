#include <loggy.h>

using namespace loggy;

int main()
{
	LOGGY_SET_DEFAULT_LOG_LEVEL(LogLevel::DEBUG);
	LOGGY_SET_TIMESTAMP_FORMAT("%Y-%m-%d %H:%M:%S");
	LOGGY_SET_SOURCE_INFO_FORMAT("%f:%l");
	LOGGY_SET_LOG_FORMAT("%t [%l] %s: %m");
	
	LOGGY_LOG("DEBUG" << ": This is the first message", LogLevel::DEBUG);
	LOGGY_LOG("INFO!", LogLevel::INFO);
	LOGGY_LOG("WARNING", LogLevel::WARNING);
	LOGGY_LOG("ERROR", LogLevel::ERROR);
	LOGGY_LOG("FATAL", LogLevel::FATAL);
	
	return 0;
}