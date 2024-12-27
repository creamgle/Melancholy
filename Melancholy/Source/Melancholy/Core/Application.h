#pragma once
#include "Melancholy/Core.h"
#include "Melancholy/Core/Window.h"

namespace Melancholy {

    MAPI class Application {
    public:
        virtual ~Application() = default;
        
        virtual bool Create() = 0;
        virtual void Update() { }

        bool Run();

    private:
        Window* mWindow;
    };

}