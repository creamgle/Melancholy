#include "Application.h"
#include "Melancholy/Core/Logger.h"

namespace Melancholy {

    bool Application::Run()
    {
        if (!Logger::Initialise())
        {
            MFATAL("Failed to initialise logger! ABORTING...");
            return false;
        }

        mWindow = Window::Create();
        if (!mWindow->Initialise())
        {
            MFATAL("Failed to initialise window! see above reason ^");
            return false;
        }

        if (!Create())
        {
            MFATAL("Application->Create() returned with a value of false! ABORTING...");
            return false;
        }

        while (!mWindow->ShouldClose())
        {
            mWindow->PollEvents();
        }

        mWindow->Shutdown();
        delete mWindow;

        Logger::Shutdown();

        return true;
    }

}