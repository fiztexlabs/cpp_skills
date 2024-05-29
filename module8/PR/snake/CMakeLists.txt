cmake_minimum_required(VERSION 3.14)
project(snake
    VERSION 0.0.1
    DESCRIPTION "Snake games"
    LANGUAGES CXX)


set(CMAKE_BUILD_TYPE Debug)

set(LINK_FLAGS "-mwindows -mconsole -Wl,-subsystem,console")

# Qt features support
# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)

# language features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(sources 
   ./src/Snake.h
   ./src/Snake.cpp
   ./src/main.cpp
)
add_executable(snake WIN32 ${sources})

target_link_libraries(snake PRIVATE 
    Qt5::Core 
    Qt5::Widgets 
    ${LINK_FLAGS})

set_property(TARGET snake PROPERTY WIN32_EXECUTABLE true)
