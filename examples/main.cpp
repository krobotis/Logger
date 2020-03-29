#include <logger/Logger.h>

using namespace logger;

int main()
{
	Logger logger("main");

	logger << LogLevel::Info << "Hello world!\n";
	logger << LogLevel::Error << "Critical Error!\n";

	return 0;
}