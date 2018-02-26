cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_BUILD_TYPE "Debug")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

project(BKAL)

include_directories(
    "include"
)

set(CTEST_ENVIRONMENT CTEST_OUTPUT_ON_FAILURE=1)
enable_testing()

add_subdirectory("src")
add_subdirectory("test")
