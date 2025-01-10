#pragma once
#include "Melancholy/Core.h"
#include "fmt/base.h"
#include <fmt/format.h>

namespace Melancholy {

    namespace Log { 
        
        enum class Level : uint32 {
            Fatal   = 0,
            Error   = 1,
            Warning = 2,
            Info    = 3,
            Trace   = 4,
            Debug   = 5
        };

        template<typename... Args>
        void LogOutput(const Level& level, std::string message, Args&&... args) 
        {
            static const std::string levelTags[6] = {
                "[FATAL] ",
                "[ERROR] ",
                "[WARNING] ",
                "[INFO] ",
                "[TRACE] ",
                "[DEBUG] "
            };

            std::string formatted = fmt::vformat(message, fmt::make_format_args(args...));
            fmt::println("{}{}", levelTags[(uint32)level], formatted);
        }
    }
}

#define MFATAL(message, ...) Melancholy::Log::LogOutput(Melancholy::Log::Level::Fatal, message, ##__VA_ARGS__)
#define MERROR(message, ...) Melancholy::Log::LogOutput(Melancholy::Log::Level::Error, message, ##__VA_ARGS__)

#define MWARN(message, ...) Melancholy::Log::LogOutput(Melancholy::Log::Level::Warning, message, ##__VA_ARGS__)
#define MINFO(message, ...) Melancholy::Log::LogOutput(Melancholy::Log::Level::Info, message, ##__VA_ARGS__)

#define MTRACE(message, ...) Melancholy::Log::LogOutput(Melancholy::Log::Level::Trace, message, ##__VA_ARGS__)
#define MDEBUG(message, ...) Melancholy::Log::LogOutput(Melancholy::Log::Level::Debug, message, ##__VA_ARGS__)

#define MASSERT(expr, message) \
    if (!(expr)) { \
        MFATAL("Assertion Failed: {} ({}) at {}:{}", #expr, message, __FILE_NAME__, __LINE__); \
    }