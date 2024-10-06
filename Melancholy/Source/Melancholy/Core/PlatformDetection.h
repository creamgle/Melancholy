#pragma once

#ifdef __APPLE__
    #include <TargetConditionals.h>

    #if TARGET_OS_MAC == 1
        #define ML_PLATFORM_MACOS
    #else
        #error "The only supported AppleOS is macOS!"
    #endif 
#else
    #error "Platform currently not supported!"
#endif