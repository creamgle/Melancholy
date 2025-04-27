#include "Melancholy/Platform/Platform.h"

#ifdef ML_PLATFORM_DESKTOP
#include "glfw_Window.h"
#include "Melancholy/Core/Logger.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

static void glfw_error_callback(int code, const char* description)
{
    MERROR("GLFW ERROR[{}]: {}", code, description);
}

namespace Melancholy::Platform::GLFW {


    glfw_Window::glfw_Window(const WindowProps& props) : m_Props(props)
    {
        
    }

    glfw_Window::~glfw_Window()
    {

    }

    bool glfw_Window::Initialise()
    {
        glfwSetErrorCallback(glfw_error_callback);

        if (!s_GlfwInitialised)
        {
            if (glfwInit())
            {
                s_GlfwInitialised = true;
                MTRACE("glfw has been successfully initialised");
            }
            else
            {
                MFATAL("Failed to initialise glfw!");
                return false;
            }
        }

        glfwDefaultWindowHints();
    	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

        m_WindowPtr = glfwCreateWindow(m_Props.Width, m_Props.Height, m_Props.Title.c_str(), NULL, NULL);
        if (!m_WindowPtr)
        {
            MFATAL("Failed to create a glfw window context!");
            return false;   
        }

		m_GraphicsContext = GraphicsContext::Create();
    	if (!m_GraphicsContext->Initialise(m_WindowPtr))
    	{
    		MFATAL("Failed to initialise graphics context!");
    		return false;
    	}

        s_WindowCount++;

        return true;
    }

    void glfw_Window::Shutdown()
    {
    	m_GraphicsContext->Shutdown();
    	glfwDestroyWindow(m_WindowPtr);
		s_WindowCount--;

        if (s_WindowCount <= 0)
            glfwTerminate();
    }

    void glfw_Window::PollEvents()
    {
        glfwPollEvents();
    }

	void glfw_Window::SwapBuffers()
    {
    	m_GraphicsContext->SwapBuffers();
    }

    bool glfw_Window::ShouldClose()
    {
        return glfwWindowShouldClose(m_WindowPtr);
    }

	void glfw_Window::Center()
	{
		const GLFWvidmode* vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    	glfwSetWindowPos(m_WindowPtr, (vidmode->width / 2) - (m_Props.Width / 2), (vidmode->height / 2) - (m_Props.Height / 2));
	}

	void glfw_Window::SetSize(int width, int height)
    {
    	m_Props.Width = width;
    	m_Props.Height = height;

    	if (m_WindowPtr)
    	{
    		glfwSetWindowSize(m_WindowPtr, m_Props.Width, m_Props.Height);
    	}
    }

	void glfw_Window::SetTitle(const std::string& title)
    {
	    m_Props.Title = title;
    	if (m_WindowPtr)
    	{
    		glfwSetWindowTitle(m_WindowPtr, m_Props.Title.c_str());
    	}
    }

}

#endif