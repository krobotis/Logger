#ifndef LOGGER_H
#define LOGGER_H

#include "Logger_EXPORTS.h"

#include <string>
#include <sstream>		// for std::ostringstream
#include <ostream>		// for std::ostream
#include <memory>		// for std::shared_ptr

namespace logging {

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

	// Output operator for I/O manipulators.
	LogProxy& operator<<(std::ostream& (*var)(std::ostream&))
	{
		*m_ostream << var;
		
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

} // namespace logging

#endif // LOGGER_H

