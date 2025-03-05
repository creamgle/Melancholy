#include "Melancholy/Platform/Platform.h"

#ifdef ML_PLATFORM_DESKTOP
#include "glfw_Window.h"
#include "Melancholy/Core/Logger.h"
#include <GLFW/glfw3.h>

static void glfw_error_callback(int code, const char* description)
{
    MERROR("GLFW ERROR[{}]: {}", code, description);
}

namespace Melancholy::Platform::GLFW {


    glfw_Window::glfw_Window(const WindowProps& props) : mProps(props)
    {
        
    }

    glfw_Window::~glfw_Window()
    {

    }

    bool glfw_Window::Initialise()
    {
        glfwSetErrorCallback(glfw_error_callback);

        if (!sGlfwInitialised)
        {
            if (glfwInit())
            {
                sGlfwInitialised = true;
                MTRACE("glfw has been successfully initialised");
            }
            else
            {
                MFATAL("Failed to initialise glfw!");
                return false;
            }
        }

        glfwDefaultWindowHints();

        mWindowPtr = glfwCreateWindow(mProps.Width, mProps.Height, mProps.Title.c_str(), NULL, NULL);
        if (!mWindowPtr)
        {
            MFATAL("Failed to create a glfw window context!");
            return false;   
        }

        sWindowCount++;

        return true;
    }

    void glfw_Window::Shutdown()
    {
        glfwDestroyWindow(mWindowPtr);
        sWindowCount--;

        if (sWindowCount <= 0)
            glfwTerminate();
    }

    void glfw_Window::PollEvents()
    {
        glfwPollEvents();
    }

    bool glfw_Window::ShouldClose()
    {
        return glfwWindowShouldClose(mWindowPtr);
    }

}

#endif