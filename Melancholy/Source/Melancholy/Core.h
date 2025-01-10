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
#include <memory>

namespace Melancholy {

    template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}