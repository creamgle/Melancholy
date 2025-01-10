#pragma once
#include "Melancholy/Core.h"
#include "Melancholy/Core/Window.h"

namespace Melancholy {

	struct ApplicationConfig {
		WindowProps WindowConfig = {
			.Width = 800,
			.Height = 450,
			.Title = "Melancholy :p"
		};
	};

    MAPI class Application {
    public:
        virtual ~Application() = default;
        
        virtual bool Create() = 0;
        virtual void Update() { }
		virtual void Draw() { }

		bool Run(ApplicationConfig config = ApplicationConfig());

    private:
		ApplicationConfig mConfig;
        Window* mWindow;
    };

}
