#pragma once

#if defined(__APPLE__)
    #include <TargetConditionals.h>

    #if TARGET_OS_OSX == 1
        #define ML_PLATFORM_OSX
    #endif
#endif