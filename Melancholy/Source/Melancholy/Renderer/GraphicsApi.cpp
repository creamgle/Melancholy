#include "GraphicsApi.h"
#include "Melancholy/Platform/OpenGL/OpenGL_Api.h"

namespace Melancholy {

    Scope<GraphicsApi> GraphicsApi::Create()
    {
        return CreateScope<OpenGL::OpenGL_Api>();
    }

}