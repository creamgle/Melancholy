#pragma once
#include "Melancholy/Core.h"
#include <type_traits>

#define FMT_HEADER_ONLY
#include "fmt/format.h"

#include <iostream>
#include <string>

namespace Melancholy {

    enum class LogLevel {
        Fatal   = 0,
        Error   = 1,
        Warning = 2,            
        Info    = 3,
        Trace   = 4,
        Debug   = 5
    };

    class MAPI Log {
    public:
        static void SetLogOutputCallback(void (*cbfunLogOutput)(const LogLevel& level, const std::string& message));

        template<typename ... Args>
        static void LogOutput(const LogLevel& level, const std::string& message, Args ... args)
        {
            static std::string tags[6] = {
                "[FATAL] ",
                "[ERROR] ",
                "[WARNING] ",
                "[INFO] ",
                "[TRACE] ",
                "[DEBUG] "
            };

            // i hate c++
            // convertes enum class value to int :3
            int levelValue = static_cast<std::underlying_type<LogLevel>::type>(level);

            std::string formatted = fmt::vformat(message, fmt::make_format_args(args...));
            std::cout << tags[levelValue] << formatted << std::endl;
        }

    private:
        inline static void (*sCbfunLogOutput)(const LogLevel&, const std::string&) = nullptr;
    };
}