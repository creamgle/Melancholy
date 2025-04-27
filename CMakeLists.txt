cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)

project(Melancholy)

add_library(Melancholy STATIC
    Source/Melancholy/Core/Logger.h
    Source/Melancholy/Core/Logger.cpp
    Source/Melancholy/Core/Application.h
    Source/Melancholy/Core/Application.cpp
    Source/Melancholy/Core/Window.h
    Source/Melancholy/Core/Window.cpp
    Source/Melancholy/Core/Math.cpp
    Source/Melancholy/Core/Math.h

    Source/Melancholy/Renderer/GraphicsContext.h
    Source/Melancholy/Renderer/GraphicsContext.cpp
    Source/Melancholy/Renderer/GraphicsApi.h
    Source/Melancholy/Renderer/GraphicsApi.cpp
    Source/Melancholy/Renderer/Mesh.cpp
    Source/Melancholy/Renderer/Mesh.h

    Source/Melancholy/Platform/Platform.h

    Source/Melancholy/Platform/glfw/glfw_Window.h
    Source/Melancholy/Platform/glfw/glfw_Window.cpp

    Source/Melancholy/Platform/OpenGL/OpenGL_Context.h
    Source/Melancholy/Platform/OpenGL/OpenGL_Context.cpp
    Source/Melancholy/Platform/OpenGL/OpenGL_GraphicsApi.h
    Source/Melancholy/Platform/OpenGL/OpenGL_GraphicsApi.cpp
    Source/Melancholy/Platform/OpenGL/OpenGL_Mesh.cpp
    Source/Melancholy/Platform/OpenGL/OpenGL_Mesh.h
    Source/Melancholy/Renderer/Shader.cpp
    Source/Melancholy/Renderer/Shader.h
    Source/Melancholy/Platform/OpenGL/OpenGL_Shader.cpp
    Source/Melancholy/Platform/OpenGL/OpenGL_Shader.h
)

if(APPLE)
    target_link_libraries(Melancholy
        "-framework Metal"
        "-framework MetalKit"
        "-framework AppKit"
        "-framework Foundation"
        "-framework QuartzCore"
    )
endif()

target_include_directories(Melancholy PUBLIC Source/)

add_subdirectory(Thirdparty/glfw)
add_subdirectory(Thirdparty/glad)
target_link_libraries(Melancholy glfw glad)