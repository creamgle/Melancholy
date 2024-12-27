#pragma once

/* M_PLATFORM_*
 * 
 * M_PLATFORM_INVALID           -- Unsupported OS / Compiler that doesnt define OS's properly
 * 
 * M_PLATFORM_DESKTOP           -- Desktop platforms / Any platform that has a floating window system and mouse and keyboard input (Windows, macOS, Linux)
 * M_PLATFORM_APPLE             -- Any Apple platform (osx, iOS, tvOS, etc...)   
 *   M_PLATFORM_OSX             -- macOS / osx only
 */

#if defined(__APPLE__)
    #include <TargetConditionals.h>

    #define M_PLATFORM_APPLE
    
    #if TARGET_OS_OSX == 1
        #define M_PLATFORM_OSX
        #define M_PLATFORM_DESKTOP
    #endif 
#else
    #define M_PLATFORM_INVALID
#endif