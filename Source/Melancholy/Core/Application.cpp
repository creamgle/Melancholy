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

        m_Window = Window::Create();
        if (!m_Window->Initialise())
        {
            MFATAL("Failed to initialise window! see above reason ^");
            return false;
        }

        if (!Create())
        {
            MFATAL("Application->Create() returned with a value of false! ABORTING...");
            return false;
        }

        while (!m_Window->ShouldClose())
        {
	        Draw();
        	m_Window->SwapBuffers();
        	m_Window->PollEvents();
        }

        m_Window->Shutdown();
        delete m_Window;

        Logger::Shutdown();

        return true;
    }

}