#ifndef LOGGER_H
#define LOGGER_H

#include "Logger_EXPORTS.h"

#include <string>
#include <sstream>		// for std::ostringstream
#include <memory>		// for std::shared_ptr

namespace logger {

enum class LogLevel
{
	Info,
	Error
};

class Logger_EXPORT LogProxy
{
public:
	LogProxy(const std::string& name, const LogLevel& level);
	~LogProxy();

	template <typename T>
	LogProxy& operator<<(const T& rhs)
	{
		*m_ostream << rhs;

		return *this;
	}

private:
	std::shared_ptr<std::ostringstream> m_ostream;
};

class Logger_EXPORT Logger
{
public:
	Logger(const std::string& name);

	LogProxy operator<<(const LogLevel& level);

private:
	std::string m_name;
};

} // namespace logger

#endif // LOGGER_H

