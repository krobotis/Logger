## Logger
A simple cpp logger

### Sample usage
```C++
#include <logger/Logger.h>

using namespace logger;

int main()
{
	Logger logger("logger.name");

	logger << LogLevel::Info << "Hello world!\n";
	logger << LogLevel::Error << "Critical Error!\n";

	return 0;
}
```
### Output
<pre>
[INFO] [logger.name] Hello world!
[ERROR] [logger.name] Critical Error!
</pre>
