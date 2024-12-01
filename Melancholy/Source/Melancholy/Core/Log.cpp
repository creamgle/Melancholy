#include "Log.h"

namespace Melancholy {

    void Log::SetLogOutputCallback(void (*cbfunLogOutput)(const LogLevel&, const std::string&))
    {
        sCbfunLogOutput = cbfunLogOutput;
    }

}