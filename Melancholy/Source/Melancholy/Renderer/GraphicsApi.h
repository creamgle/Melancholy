#pragma once
#include "Melancholy/Core.h"

namespace Melancholy {

    MAPI class GraphicsApi {
    public:
        virtual ~GraphicsApi() = default;

        static Scope<GraphicsApi> Create();

        virtual void Clear() = 0;

        virtual void SetClearColor(float r, float g, float b, float a) = 0;
    };

}
