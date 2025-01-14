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
        
		static Application& GetInstance() { return *mInstance; }

        virtual bool Create() = 0;
        virtual void Update() { }
		virtual void Draw() { }

		bool Run(ApplicationConfig config = ApplicationConfig());

		Window& GetWindow() const { return *mWindow; }

    private:
		inline static Application* mInstance;

		ApplicationConfig mConfig;
        Window* mWindow;
    };

}
