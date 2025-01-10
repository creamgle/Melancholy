#pragma once
#include "Melancholy/Core.h"
#include "Melancholy/Core/Window.h"

struct GLFWwindow;

namespace Melancholy::glfw {

    MAPI class glfw_Window : public Window {
    public:
        glfw_Window() = default;
        ~glfw_Window() override;

        bool Create() override;
        void Destroy() override;

        void PollEvents() override;
        bool ShouldClose() override;
        
        void SetSize(uint32 width, uint32 height) override;
        void SetTitle(const std::string& title) override;

    private:
        GLFWwindow* mWindow;
    };

}