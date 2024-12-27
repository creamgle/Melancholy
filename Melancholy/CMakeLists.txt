project(Melancholy)
set(CMAKE_CXX_STANDARD 23)

add_library(Melancholy STATIC
    Source/Melancholy/Core/Log.h
    Source/Melancholy/Core/Log.cpp
    Source/Melancholy/Core/Window.h
    Source/Melancholy/Core/Window.cpp
    Source/Melancholy/Core/Application.h
    Source/Melancholy/Core/Application.cpp

    Source/Melancholy/Platform/glfw/glfw_Window.h
    Source/Melancholy/Platform/glfw/glfw_Window.cpp
)

target_include_directories(Melancholy PUBLIC Source)

if(APPLE)
    target_link_libraries(Melancholy
        "-framework Metal"
        "-framework MetalKit"
        "-framework AppKit"
        "-framework Foundation"
        "-framework QuartzCore"
    )

    target_include_directories(Melancholy PRIVATE Thirdparty/metal-cpp)
endif()

add_subdirectory(Thirdparty/fmt)
add_subdirectory(Thirdparty/glfw)

target_link_libraries(Melancholy fmt::fmt glfw)
