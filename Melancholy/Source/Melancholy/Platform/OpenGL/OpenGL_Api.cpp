#include "OpenGL_Api.h"
#include <glad/glad.h>

namespace Melancholy::OpenGL {

    void OpenGL_Api::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OpenGL_Api::SetClearColor(float r, float g, float b, float a) 
    {
        glClearColor(r, g, b, a);
    }

}