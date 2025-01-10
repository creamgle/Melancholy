#include "Window.h"

#ifdef M_PLATFORM_DESKTOP
    #include "Melancholy/Platform/glfw/glfw_Window.h"
#endif

namespace Melancholy {

    Window* Window::CreateWindow(const WindowProps& props) 
    {
        #ifdef M_PLATFORM_DESKTOP
            glfw::glfw_Window* window = new glfw::glfw_Window();
            window->mProps = props;
            return window;
        #endif
        MFATAL("Failed to get appropriate window for platform!");
        return nullptr;
    }

}