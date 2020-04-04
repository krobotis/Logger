#include <logger/Logger.h>

#include <iostream>		// for std::cout
#include <mutex>
#include <stdexcept>	// for std::invalid_argument

namespace logging {
namespace {
	std::mutex coutMutex;
}

LogProxy::LogProxy(const std::string& name, const LogLevel& level)
	: m_ostream(std::make_shared<std::ostringstream>())
{
	switch (level)
	{
	case LogLevel::Info:
		*m_ostream << "[INFO] ";
		break;
	case LogLevel::Error:
		*m_ostream << "[ERROR] ";
		break;
	default:
		throw std::invalid_argument("LogLevel");
		break;
	}

	*m_ostream << "[" << name << "] ";
}

LogProxy::~LogProxy()
{
	std::lock_guard<std::mutex> lock(coutMutex);

	std::cout << m_ostream->str();
}

Logger::Logger(const std::string& name)
	: m_name(name)
{}

LogProxy Logger::operator<<(const LogLevel& level)
{
	return LogProxy(m_name, level);
}

} // namespace logging