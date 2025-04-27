#include "OpenGL_Context.h"
#include "Melancholy/Core/Logger.h"

// TODO: Should check to make sure glfw is being used
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Melancholy::Platform::OpenGL {

    bool OpenGL_Context::Initialise(void* handle)
    {
		m_Handle = handle;

		if (static_cast<GLFWwindow*>(m_Handle) == nullptr)
		{
			MFATAL("Failed to case window handle to GLFWwindow (this is so my bad im sory)!");
			return false;
		}

		glfwMakeContextCurrent(static_cast<GLFWwindow*>(m_Handle));
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			MFATAL("Failed to load an OpenGL context!");
			return false;
		}

    	MTRACE("Created graphics context: OpenGL");
    	MTRACE("\tVersion: {}", (char*)glGetString(GL_VERSION));
    	MTRACE("\tVendor: {}", (char*)glGetString(GL_VENDOR));
    	MTRACE("\tRenderer: {}", (char*)glGetString(GL_RENDERER));

		return true;
    }

	void OpenGL_Context::Shutdown()
	{
	}

	void OpenGL_Context::SwapBuffers()
    {
	    glfwSwapBuffers(static_cast<GLFWwindow*>(m_Handle));
    }

}