#pragma once
#include "PlatformDetection.h"

#ifdef M_EXPORT
    #ifdef M_PLATFORM_OSX		
        #define MAPI __attribute__((visibility("default")))
    #endif
#else
    #ifdef M_PLATFORM_OSX
        #define MAPI __attribute__((visibility("default")))
    #endif
#endif