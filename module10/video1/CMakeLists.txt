cmake_minimum_required(VERSION 3.20)
project(
    video1
    VERSION 0.0.1
    DESCRIPTION "Example"
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Python COMPONENTS Interpreter Development REQUIRED)

add_subdirectory(libs/pybind11)
pybind11_add_module(video1 src/cpp2py.cpp)

