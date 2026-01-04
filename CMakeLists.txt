cmake_minimum_required(VERSION 3.10)

project(app LANGUAGES CXX)

set(CMAKE_CXX_VERSION 17)
set(CMAKE_CXX_VERSION_REQUIRED ON)
set(CMAKE_CXX_EXTENTION OFF)

add_executable(app WIN32 src/main.cpp)

target_compile_definitions(app PRIVATE UNICODE _UNICODE)