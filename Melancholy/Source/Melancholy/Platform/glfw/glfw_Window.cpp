#include "Melancholy/Platform/PlatformDetection.h"
#include "Melancholy/Platform/glfw/glfw_Window.h"

#ifdef M_PLATFORM_DESKTOP
#include <GLFW/glfw3.h>

namespace Melancholy::glfw {

    glfw_Window::~glfw_Window() { }

    bool glfw_Window::Create() {
        if (!glfwInit()) {
            MFATAL("Failed to initialise glfw! [REASON]: {}", glfwGetError(NULL));
            return false;
        }

        glfwDefaultWindowHints();
        mWindow = glfwCreateWindow(mProps.Width, mProps.Height, mProps.Title.c_str(), NULL, NULL);

        if (!mWindow) {
            MFATAL("Failed to create glfw window! [REASON]: {}", glfwGetError(NULL));
            return false;
        }

        return true;
    }
    
    void glfw_Window::Destroy() {
        glfwDestroyWindow(mWindow);
        glfwTerminate();
    }

    void glfw_Window::PollEvents() {
        glfwPollEvents();
    }
        
    bool glfw_Window::ShouldClose() {
        return glfwWindowShouldClose(mWindow);
    }

}

#endif