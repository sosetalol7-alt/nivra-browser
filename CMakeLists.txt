cmake_minimum_required(VERSION 3.20)

project(Nivra LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Nivra
    src/main.cpp
    src/core/Application.cpp
    src/core/Window.cpp
)

target_include_directories(Nivra PRIVATE
    src
)

target_compile_definitions(Nivra PRIVATE
    UNICODE
    _UNICODE
)
