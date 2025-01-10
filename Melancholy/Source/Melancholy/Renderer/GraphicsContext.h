#pragma once
#include "Melancholy/Core.h"

namespace Melancholy {

    MAPI class GraphicsContext {
    public:
        virtual ~GraphicsContext() = default;

        static Scope<GraphicsContext> Create();

        virtual bool Initialise(void* handle) = 0;
        virtual void Destroy() = 0;

        virtual void SwapBuffers() = 0;
    };

}