#pragma once
#include "Melancholy/Defines.h"
#include "Melancholy/Core/Window.h"
#include "Melancholy/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Melancholy::Platform::GLFW {

    class glfw_Window : public Window {
    public:
        glfw_Window(const WindowProps& props);
        ~glfw_Window() override;

        bool Initialise() override;
        void Shutdown() override;

		void PollEvents() override;
		void SwapBuffers() override;

        bool ShouldClose() override;

		void Center() override;

		void SetSize(int width, int height) override;
    	void SetTitle(const std::string& title) override;

    	int GetWidth() const override { return m_Props.Width; }
    	int GetHeight() const override { return m_Props.Height; }

    private:
        inline static bool s_GlfwInitialised = false;
        inline static uint8 s_WindowCount = 0;

        GLFWwindow* m_WindowPtr;
        WindowProps m_Props;

    	GraphicsContext* m_GraphicsContext = nullptr;
    };

}