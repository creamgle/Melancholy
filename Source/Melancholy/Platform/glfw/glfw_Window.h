#pragma once
#include "Melancholy/Defines.h"
#include "Melancholy/Core/Window.h"

struct GLFWwindow;

namespace Melancholy::Platform::GLFW {

    class glfw_Window : public Window {
    public:
        glfw_Window(const WindowProps& props);
        ~glfw_Window() override;

        bool Initialise() override;
        void Shutdown() override;

		void PollEvents() override;
        bool ShouldClose() override;

    private:
        inline static bool sGlfwInitialised = false;
        inline static uint8 sWindowCount = 0;

        GLFWwindow* mWindowPtr;
        WindowProps mProps;
    };

}