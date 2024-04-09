cmake_minimum_required(VERSION 3.18)      
project(    
    matrixlib
    VERSION 0.0.0
    DESCRIPTION "Cpp library"
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

# точность вычислений (float или double)
option(MATH_USE_DOUBLE_PRECISION "Use double precision for calculations" ON)


set(sources                               
    matrixlib/matrix.h
    matrixlib/matrix.cpp

    matrixlib/export.h
    matrixlib/c/c_api.h
    matrixlib/c/c_api.cpp
)

include(GenerateExportHeader)

# собираем статическую библиотеку
add_library(static-matrixlib STATIC ${sources})
target_include_directories(static-matrixlib PUBLIC 
    "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)
generate_export_header(static-matrixlib 
    EXPORT_FILE_NAME "${PROJECT_BINARY_DIR}/export_static.h"
    BASE_NAME matrixlib
)
target_compile_definitions(static-matrixlib 
    PUBLIC
        MATH_STATIC_DEFINE
        "$<$<BOOL:${MATH_USE_DOUBLE_PRECISION}>:MATH_DOUBLE_PRECISION_DEFINE>")
set_target_properties(static-matrixlib PROPERTIES PREFIX "")

# собираем динамическую библиотеку
add_library(shared-matrixlib SHARED ${sources})
target_include_directories(shared-matrixlib PUBLIC 
    "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)
generate_export_header(shared-matrixlib 
    EXPORT_FILE_NAME "${PROJECT_BINARY_DIR}/export_shared.h"
    BASE_NAME matrixlib
)
target_compile_definitions(shared-matrixlib 
    PUBLIC
        "$<$<BOOL:${MATH_USE_DOUBLE_PRECISION}>:MATH_DOUBLE_PRECISION_DEFINE>")
set_target_properties(shared-matrixlib PROPERTIES PREFIX "")

# создаем тестовый exe-файл для статической библиотеки
add_executable(test-static-matrix 
    matrixlib/test/test-matrix-static.cpp
)
target_include_directories(test-static-matrix  PUBLIC 
    "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)
target_link_libraries(test-static-matrix PRIVATE static-matrixlib)


# создаем тестовый exe-файл для динамической библиотеки
add_executable(test-shared-matrix 
    matrixlib/test/test-matrix-shared.cpp
)
target_include_directories(test-shared-matrix  PUBLIC 
    "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)
target_link_libraries(test-shared-matrix PRIVATE shared-matrixlib)