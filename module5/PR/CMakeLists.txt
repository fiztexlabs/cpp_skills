cmake_minimum_required(VERSION 3.18)      
project(    
    cars
    VERSION 0.0.0
    DESCRIPTION "Module 6 practice"
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

# создаем тестовый exe-файл для динамической библиотеки
add_executable(cars 
    src/car.h
    src/car.cpp
    src/lorry.h
    src/lorry.cpp

    src/main.cpp
)

# подключаем текущую директорию
target_include_directories(cars PUBLIC 
    "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)
