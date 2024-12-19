#pragma once
#include "Platform/PlatformDetection.h"

#if defined(M_PLATFORM_OSX)
    #ifdef MEXPORT
        #define MAPI __attribute__((__visibility__("default")))
    #else
        #define MAPI
    #endif
#endif

typedef unsigned char      uint8;
typedef unsigned short     uint16;
typedef unsigned int       uint32;
typedef unsigned long long uint64;

#include "Melancholy/Core/Log.h"