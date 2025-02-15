#include "Logger.h"
#include "Melancholy/Core/PlatformDetection.h"
#include <iostream>
#include <fstream>
#include <filesystem>

namespace Melancholy::Logger {

    static bool _initialised = false;
    static std::ofstream _log_output_file;

    static LogCallback _custom_log_callback;

    bool Initialise()
    {
        // Create a folder to store log output files
        if (!std::filesystem::exists("Logs"))
        {
            if (!std::filesystem::create_directory("Logs"))
            {
                // Print this error using "cout" since our logger isnt setup yet
                std::cout << "Failed to create a directory to store log outputs" << std::endl;
                // TODO: Create a workaround case to avoid a fatal error
                // this prolly wont be necesarry hince why im not making a rush
                // to add it, but it would still be nice to have just in case
                return false;
            }
        }

        _log_output_file.open("logs/output.txt");

        _initialised = true;
        return true;
    }

    void Shutdown()
    {
        _log_output_file.close();
    }

    void SetCustomLogCallback(LogCallback callback)
    {
        _custom_log_callback = callback;
    }

    void ml_internal_logger_output(const Level &level, const std::string &message)
    {
        if (_custom_log_callback)
        {
            _custom_log_callback(level, message);
            return;
        }

        if (!_initialised)
            return;

        static const std::string level_tags[6] = {
            "[FATAL]: ",
            "[ERROR]: ",
            "[WARNING]: ",
            "[INFO]: ",
            "[TRACE]: ",
            "[DEBUG]: "
        };

        // If the platform isnt win32 we use ansi-codes to color the output text
        // if it is then we use win32 specific print functions
        std::string ansi_coloring;
        std::string ansi_reset;
        #ifndef ML_PLATFORM_WIN32 // Use ansi to color the output message
            static const std::string ansi_codes[6] = {
                "\e[0;101m",
                "\e[0;31m",
                "\e[0;33m",
                "\e[0;32m",
                "\e[0;35m",
                "\e[0;34m"
            };

            ansi_coloring = ansi_codes[(uint8)level];
            ansi_reset = "\e[0m";
        #endif
        
        std::string out_string = level_tags[(uint8)level] + message + "\n";
        std::cout << ansi_coloring << out_string << ansi_reset;

        _log_output_file << out_string;
    }

}