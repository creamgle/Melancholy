#include "Melancholy/Core/Log.h"

using namespace Melancholy;

int main()
{
    Log::LogOutput(LogLevel::Fatal, "Hello, {} {}!", "World", 3.14f);
    Log::LogOutput(LogLevel::Error, "Hello, {} {}!", "World", 3.14f);
    Log::LogOutput(LogLevel::Warning, "Hello, {} {}!", "World", 3.14f);
    Log::LogOutput(LogLevel::Info, "Hello, {} {}!", "World", 3.14f);
    Log::LogOutput(LogLevel::Trace, "Hello, {} {}!", "World", 3.14f);
    Log::LogOutput(LogLevel::Debug, "Hello, {} {}!", "World", 3.14f);
    return 0;
}