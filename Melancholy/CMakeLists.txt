project(Melancholy)
set(CMAKE_CXX_STANDARD 23)

add_library(Melancholy STATIC
    Source/Melancholy/Core/Log.h
    Source/Melancholy/Core/Log.cpp
    Source/Melancholy/Core/Window.h
    Source/Melancholy/Core/Window.cpp
    Source/Melancholy/Core/Application.h
    Source/Melancholy/Core/Application.cpp
	Source/Melancholy/Core/Math.h
	Source/Melancholy/Core/Math.cpp

    Source/Melancholy/Renderer/GraphicsContext.h
    Source/Melancholy/Renderer/GraphicsContext.cpp
	Source/Melancholy/Renderer/GraphicsApi.h
	Source/Melancholy/Renderer/GraphicsApi.cpp
	Source/Melancholy/Renderer/Renderer2D.h
	Source/Melancholy/Renderer/Renderer2D.cpp
    Source/Melancholy/Renderer/Mesh.h
    Source/Melancholy/Renderer/Mesh.cpp
    Source/Melancholy/Renderer/Shader.h
    Source/Melancholy/Renderer/Shader.cpp
    Source/Melancholy/Renderer/Texture2D.h
    Source/Melancholy/Renderer/Texture2D.cpp

    Source/Melancholy/Platform/glfw/glfw_Window.h
    Source/Melancholy/Platform/glfw/glfw_Window.cpp

    Source/Melancholy/Platform/OpenGL/OpenGL_Context.h
    Source/Melancholy/Platform/OpenGL/OpenGL_Context.cpp
	Source/Melancholy/Platform/OpenGL/OpenGL_Api.h
	Source/Melancholy/Platform/OpenGL/OpenGL_Api.cpp
    Source/Melancholy/Platform/OpenGL/OpenGL_Mesh.h
    Source/Melancholy/Platform/OpenGL/OpenGL_Mesh.cpp
    Source/Melancholy/Platform/OpenGL/OpenGL_Shader.h
    Source/Melancholy/Platform/OpenGL/OpenGL_Shader.cpp
    Source/Melancholy/Platform/OpenGL/OpenGL_Texture2D.h
    Source/Melancholy/Platform/OpenGL/OpenGL_Texture2D.cpp
)

target_include_directories(Melancholy PUBLIC Source "Thirdparty/stb/include")

if(APPLE)
    target_link_libraries(Melancholy
        "-framework Metal"
        "-framework MetalKit"
        "-framework AppKit"
        "-framework Foundation"
        "-framework QuartzCore"
    )
endif()

add_subdirectory(Thirdparty/fmt)
add_subdirectory(Thirdparty/glfw)
add_subdirectory(Thirdparty/glad)

target_link_libraries(Melancholy fmt::fmt glfw glad)
