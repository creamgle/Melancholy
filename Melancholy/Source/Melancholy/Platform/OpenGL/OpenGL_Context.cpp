#include "OpenGL_Context.h"
#include "Melancholy/Core/Log.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

namespace Melancholy::OpenGL {

    OpenGL_Context::~OpenGL_Context()
    {

    }

    bool OpenGL_Context::Initialise(void* handle)
    {
        mHandle = handle;
        glfwMakeContextCurrent((GLFWwindow*)mHandle);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            MFATAL("Failed to load OpenGL!");
            return false;
        }

        /* Get OpenGL specs and print them for debugging */
        MTRACE("Created OpenGL context:");
        MTRACE("\tVendor  : {}", (const char*)glGetString(GL_VENDOR));
        MTRACE("\tVersion : {}", (const char*)glGetString(GL_VERSION));
        MTRACE("\tRenderer: {}", (const char*)glGetString(GL_RENDERER));

        return true;
    }
    
    void OpenGL_Context::Destroy()
    {
        
    }

    void OpenGL_Context::SwapBuffers()
    {
        glfwSwapBuffers((GLFWwindow*)mHandle);
    }

}