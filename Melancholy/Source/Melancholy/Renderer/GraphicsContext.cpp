#include "GraphicsContext.h"
#include "Melancholy/Platform/OpenGL/OpenGL_Context.h"

namespace Melancholy {

    Scope<GraphicsContext> GraphicsContext::Create()
    {
        MERROR("Failed to find apporiate graphics context! Defaulting to OpenGL...");
        return CreateScope<OpenGL::OpenGL_Context>();
    }

}