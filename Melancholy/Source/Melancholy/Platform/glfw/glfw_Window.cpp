#include "Melancholy/Core/Log.h"
#include "Melancholy/Platform/PlatformDetection.h"
#include "Melancholy/Platform/glfw/glfw_Window.h"
#include "Melancholy/Renderer/GraphicsContext.h"

#ifdef M_PLATFORM_DESKTOP
#include <GLFW/glfw3.h>

namespace Melancholy::glfw {

    static void _ErrorCallback(int error, const char* description)
    {
        MFATAL("[GLFW ERROR] {}", description);
    }

    glfw_Window::~glfw_Window() { }

    bool glfw_Window::Create() 
    {
        glfwSetErrorCallback(_ErrorCallback);

        if (!glfwInit()) 
        {
            MFATAL("Failed to initialise glfw! [REASON]: {}", glfwGetError(NULL));
            return false;
        }

        glfwDefaultWindowHints();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        mWindow = glfwCreateWindow(mProps.Width, mProps.Height, mProps.Title.c_str(), NULL, NULL);

        if (!mWindow) 
        {
            MFATAL("Failed to create glfw window! [REASON]: ^");
            return false;
        }

        mGraphicsContext = GraphicsContext::Create();
        if (!mGraphicsContext->Initialise(mWindow))
        {
            return false;
        }

        return true;
    }
    
    void glfw_Window::Destroy() 
    {
        glfwDestroyWindow(mWindow);
        glfwTerminate();
    }

    void glfw_Window::PollEvents() 
    {
        glfwPollEvents();
    }
        
    bool glfw_Window::ShouldClose() 
    {
        return glfwWindowShouldClose(mWindow);
    }

    void glfw_Window::SetSize(uint32 width, uint32 height)
    {
        if (width <= 0 || height <= 0) 
        {
            MWARN("Attempting to set window size to invalid[{}, {}]!", width, height);
            return;
        }

        mProps.Width = width;
        mProps.Height = height;

        if (mWindow)
        {
            glfwSetWindowSize(mWindow, width, height);
        }
    }

    void glfw_Window::SetTitle(const std::string& title)
    {
        mProps.Title = title;

        if (mWindow)
        {
            glfwSetWindowTitle(mWindow, title.c_str());
        }
    }

}

#endif