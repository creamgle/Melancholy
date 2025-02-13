#pragma once
#include "Melancholy/Defines.h"
#include <string>
#include <format>

namespace Melancholy::Logger {

    enum class Level : uint8 {
        Fatal   = 0, // A very bad error has accured that cannot be recovered from
        Error   = 1, // A slightly less bad error that can be saved but the application wont function properly
        Warning = 2, // An issue has accured that can either be; fixed, or it wont affect the application poorly
        Info    = 3, // Just general information about what the program has discovered and the users specs; info is mostly for development
        Trace   = 4, // Information about where the program is currently at; IS ONLY ACTIVE WHEN THE "DEBUG" FLAG IS DEFINED
        Debug   = 5, // Used for basic termainl debugging; only enabled when the "DEBUG" flag is defined
    };

    bool Initialise();
    void Shutdown();

    template<typename ... Args>
    void LogOutput(const Level& level, const std::string& message, Args&& ... args)
    {
        ml_internal_logger_output(level, std::vformat(message, std::make_format_args(args...)));
    }

    void ml_internal_logger_output(const Level& level, const std::string& message);

}

#define MFATAL(message, ...) Melancholy::Logger::LogOutput(Melancholy::Logger::Level::Fatal, message, ##__VA_ARGS__)
#define MERROR(message, ...) Melancholy::Logger::LogOutput(Melancholy::Logger::Level::Error, message, ##__VA_ARGS__)

#define MWARN(message, ...) Melancholy::Logger::LogOutput(Melancholy::Logger::Level::Warning, message, ##__VA_ARGS__)
#define MINFO(message, ...) Melancholy::Logger::LogOutput(Melancholy::Logger::Level::Info, message, ##__VA_ARGS__)

#define MTRACE(message, ...) Melancholy::Logger::LogOutput(Melancholy::Logger::Level::Trace, message, ##__VA_ARGS__)
#define MDEBUG(message, ...) Melancholy::Logger::LogOutput(Melancholy::Logger::Level::Debug, message, ##__VA_ARGS__)