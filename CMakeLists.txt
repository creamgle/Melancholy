cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)

project(Melancholy)

add_library(Melancholy STATIC
    Source/Melancholy/Core/Logger.h
    Source/Melancholy/Core/Logger.cpp
)

target_include_directories(Melancholy PUBLIC Source/)