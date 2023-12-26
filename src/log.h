#pragma once

#include <sstream>

namespace loggy
{
	class Log
	{
	public:
		Log() = default;
		
		/**
		 * @brief Appends a value to the log.
		 */
		template<typename T>
		Log& operator<<(const T& log)
		{
			m_Buffer << log;
			return *this;
		}

		/**
		 * @brief Gets the log as a string.
		 * 
		 * @return The log as a string.
		 */
		operator std::string() const
		{
			return m_Buffer.str();
		}

	private:
		/**
		 * @brief The string buffer of the log.
		 */
		std::ostringstream m_Buffer;
	};
}