#pragma once
#include "Melancholy/Core.h" 
#include "Melancholy/Renderer/GraphicsContext.h"
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

        virtual void SetSize(uint32 width, uint32 height) = 0;
        virtual void SetTitle(const std::string& title) = 0;

        const uint32 GetWidth() const { return mProps.Width; }
        const uint32 GetHeight() const { return mProps.Height; }

        GraphicsContext& GetGraphicsContext() const { return *mGraphicsContext; }

    protected:
        WindowProps mProps;
        Scope<GraphicsContext> mGraphicsContext;
    };

}