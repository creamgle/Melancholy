#pragma once
#if 0
#include "Melancholy/Core.h"
#include <functional>
#include <string>
#include <type_traits>

// This is so dificult i want to kill myself :(

template<typename T>
using cbfun_Event = std::function<void(const T&)>;

namespace Melancholy {

    MAPI class Event {
    public:
        virtual ~Event() = default;

        const std::string GetName() const { return mName; }

    private:
        const std::string mName;
    };

    MAPI class EventManager {
    public:
        template<typename T>
        static void Subscribe(cbfun_Event<T> cbfun_Event) 
        {
            if (!std::is_base_of<T, Event>()) 
            {
                MWARN("Cannot subscribe to event [T is not derived from Event!]");
                return;
            }
        }

    private:

    };

}

#endif