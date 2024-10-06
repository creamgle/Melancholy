#pragma once
#include "Melancholy/Core/PlatformDetection.h"

#ifdef ML_PLATFORM_MACOS
    #ifdef ML_EXPORT
        #define MAPI __attribute__((visibility("default")))
    #else
        #define MAPI
    #endif
#endif

#include "Melancholy/Core/Log.h"