#pragma once
#include "Melancholy/Core.h" 
#include <string>

namespace Melancholy {

    struct WindowProps {
        uint32 Width;
        uint32 Height;
        std::string Title;
    };

    MAPI class Window {
    public:
        virtual ~Window() = default;

        static Window* CreateWindow(const WindowProps& props);

        virtual bool Create() = 0;
        virtual void Destroy() = 0;

        virtual void PollEvents() = 0;
        virtual bool ShouldClose() = 0;

    protected:
        WindowProps mProps;
    };

}