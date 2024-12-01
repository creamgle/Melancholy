#pragma once

/*
    Platforms:
        M_PLATFORM_APPLE | Is defined for any Apple platform (macOS, iOS, tvOS, etc.)
        M_PLATFORM_OSX | Is defined for only macOS
*/

#if defined(__APPLE__)
    #include <TargetConditionals.h>

    #define M_PLATFORM_APPLE

    #if TARGET_OS_OSX == 1
        #define M_PLATFORM_OSX
    #endif
#else
    #error "Current platform is not yet supported!"
#endif