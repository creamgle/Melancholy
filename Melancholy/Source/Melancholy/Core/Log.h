#pragma once
#include "MCore.h"
#include <string>

namespace Melancholy {

    enum LogLevel {
        Fatal,
        Error,
        Warning,
        Info,
        Debug
    };

    namespace Log {

        MAPI bool Initialise();
        MAPI void Shutdown();

        MAPI void Fatal(const std::string& message);
        MAPI void Error(const std::string& message);

        MAPI void Warn(const std::string& message);
        MAPI void Info(const std::string& message);
        
        MAPI void Debug(const std::string& message);

    }

}