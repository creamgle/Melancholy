#pragma once

namespace Melancholy {

    class GraphicsContext {
    public:
        virtual ~GraphicsContext() = default;

        static GraphicsContext* Create();

        virtual bool Initialise(void* handle) = 0;
        virtual void Shutdown() = 0;

    	virtual void SwapBuffers() = 0;
    };

}