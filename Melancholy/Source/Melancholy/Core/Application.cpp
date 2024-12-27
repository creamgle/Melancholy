#include "Application.h"

namespace Melancholy {

    bool Application::Run() {
        WindowProps props = {
            .Width = 800,
            .Height = 450,
            .Title = "Melancholy :p"
        };

        mWindow = Window::CreateWindow(props);
        if (!mWindow)
            return false;

        if (!mWindow->Create()) {
            MFATAL("Failed to create window! [SEE ABOVE ERROR ^]");
            return false;
        }

        if (!Create()) {
            MFATAL("Application->Create() returned a value of false or is not defined!");
            return false;
        }

        while (!mWindow->ShouldClose()) {
            Update();
            mWindow->PollEvents();
        }

        mWindow->Destroy();
        delete mWindow;

        return true;
    }

}