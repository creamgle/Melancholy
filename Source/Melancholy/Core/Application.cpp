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

        if (!Create())
        {
            MFATAL("Application->Create() returned with a value of false! ABORTING...");
            return false;
        }

        Logger::Shutdown();
    }

}