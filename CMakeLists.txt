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

    Source/Melancholy/Platform/Platform.h

    Source/Melancholy/Platform/glfw/glfw_Window.h
    Source/Melancholy/Platform/glfw/glfw_Window.cpp
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
target_link_libraries(Melancholy glfw)