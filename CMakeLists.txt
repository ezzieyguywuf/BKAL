cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_BUILD_TYPE "Debug")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

project(GTAL)

set(OCC_INCLUDE "/home/wolfie/Program/FreeCAD_dev/opencascade-7.1.0/inc")
set(OCC_LIBRARIES "/home/wolfie/Program/FreeCAD_dev/opencascade-7.1.0/build/lin64/gcc/libd")
set(FreeCAD_BASE "/home/wolfie/Program/FreeCAD_dev/FreeCAD_ezziey")

include_directories(
    "include"
    ${OCC_INCLUDE}
)

link_directories(
    ${OCC_LIBRARIES}
)

set(CTEST_ENVIRONMENT CTEST_OUTPUT_ON_FAILURE=1)
enable_testing()

add_subdirectory("src")
add_subdirectory("test")
