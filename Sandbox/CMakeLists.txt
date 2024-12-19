project(Sandbox)
set(CMAKE_CXX_STANDARD 23)

add_executable(Sandbox Source/Main.cpp)

# target_include_directories(Sandbox PRIVATE ${INC_MELANCHOLY})
target_link_libraries(Sandbox PRIVATE Melancholy)