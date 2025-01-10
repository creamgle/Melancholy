#pragma once
#include "Melancholy/Core.h"
#include "Melancholy/Renderer/GraphicsContext.h"

namespace Melancholy::OpenGL {

    class OpenGL_Context : public GraphicsContext {
    public:
        ~OpenGL_Context() override;

        bool Initialise(void* handle) override;
        void Destroy() override;

        void SwapBuffers() override;

    private:
        void* mHandle;
    };

}