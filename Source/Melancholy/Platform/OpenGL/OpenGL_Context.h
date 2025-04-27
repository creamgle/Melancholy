#pragma once
#include "Melancholy/Renderer/GraphicsContext.h"

namespace Melancholy::Platform::OpenGL {

    class OpenGL_Context : public GraphicsContext {
    public:
        ~OpenGL_Context() override = default;

        bool Initialise(void* handle) override;
        void Shutdown() override;

    	void SwapBuffers() override;
    private:
        void* m_Handle;
    };

}