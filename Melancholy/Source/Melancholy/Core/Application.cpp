#include "Application.h"
#include "Melancholy/Renderer/Renderer2D.h"

namespace Melancholy {
    
	bool Application::Run(ApplicationConfig config) {
		mConfig = config;
		
		mWindow = Window::CreateWindow(config.WindowConfig);
        if (!mWindow)
            return false;

        if (!mWindow->Create()) {
            MFATAL("Failed to create window! [SEE ABOVE ERROR ^]");
            return false;
        }

		// Not the best place to do this, but it works for now :)
		if (!Renderer2D::Initialise())
		{
			MFATAL("Failed to initialise Renderer2D!");
			return false;
		}

        if (!Create()) {
            MFATAL("Application->Create() returned a value of false or is not defined!");
            return false;
        }

        while (!mWindow->ShouldClose()) {
            Update();
            mWindow->PollEvents();
			
			Draw();
            mWindow->GetGraphicsContext().SwapBuffers();
        }

        mWindow->Destroy();
        delete mWindow;

        return true;
    }

}
