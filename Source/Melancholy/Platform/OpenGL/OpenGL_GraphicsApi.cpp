#include "OpenGL_GraphicsApi.h"
#include <glad/glad.h>

namespace Melancholy::Platform::OpenGL {

	void OpenGL_GraphicsApi::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGL_GraphicsApi::SetClearColor(float r, float g, float b, float a)
	{
		glClearColor(r, g, b, a);
	}

}