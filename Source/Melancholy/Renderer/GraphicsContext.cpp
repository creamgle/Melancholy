#include "GraphicsContext.h"
#include "Melancholy/Platform/OpenGL/OpenGL_Context.h"

namespace Melancholy {

    GraphicsContext* GraphicsContext::Create()
    {
        return new Platform::OpenGL::OpenGL_Context();
    }

}