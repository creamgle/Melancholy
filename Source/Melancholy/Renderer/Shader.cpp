#include "Shader.h"

#include "Melancholy/Platform/OpenGL/OpenGL_Shader.h"

namespace Melancholy {

	Shader* Shader::Create(const std::string& vertex_source, const std::string& fragment_source)
	{
		return new Platform::OpenGL::OpenGL_Shader(vertex_source, fragment_source);
	}

}
