#include "Melancholy/Core/Log.h"
#include <iostream>

namespace Melancholy::Log {

    void LogOutput(const LogLevel& level, const std::string& message)
    {
        const std::string levelTags[5] = {
            "[FATAL] ",
            "[ERROR] ",
            "[WARNING] ",
            "[INFO] ",
            "[DEBUG] "
        };

        std::cout << levelTags[level] << message << "\n";
    }

    bool Initialise()
    {
        return true;
    }

    void Shutdown()
    {

    }

    void Fatal(const std::string& message)
    {
        LogOutput(LogLevel::Fatal, message);
    }

    void Error(const std::string& message)
    {
        LogOutput(LogLevel::Error, message);
    }

    void Warn(const std::string& message)
    {
        LogOutput(LogLevel::Warning, message);
    }

    void Info(const std::string& message)
    {
        LogOutput(LogLevel::Info, message);
    }
        
    void Debug(const std::string& message)
    {
        LogOutput(LogLevel::Debug, message);
    }
}