#include "Shader.h"
#include "Melancholy/Platform/OpenGL/OpenGL_Shader.h"

namespace Melancholy {

    Ref<Shader> Shader::Create(const std::string& vertex, const std::string& fragment)
    {
        return CreateRef<OpenGL::OpenGL_Shader>(vertex, fragment);
    }

}