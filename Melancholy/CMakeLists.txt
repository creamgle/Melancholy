project(Melancholy)
set(CMAKE_CXX_STANDARD 23)

add_library(Melancholy STATIC 
    Source/Melancholy/Core/Log.cpp
)

target_include_directories(Melancholy PUBLIC Source)

add_subdirectory(Thirdparty/fmt)
target_link_libraries(Melancholy fmt::fmt)