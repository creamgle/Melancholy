#include "Window.h"
#include "Melancholy/Core/Logger.h"
#include "Melancholy/Platform/Platform.h"


#ifdef ML_PLATFORM_DESKTOP
    #include "Melancholy/Platform/glfw/glfw_Window.h"
#endif

namespace Melancholy {

    Window* Window::Create(const WindowProps& props)
    {
        #ifdef ML_PLATFORM_DESKTOP
            return new Platform::GLFW::glfw_Window(props);
        #endif

        MFATAL("Current platform does not have a window!");
        return nullptr;
    }

}