set (CMAKE_HELPER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/cmake_helper")

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_subdirectory(Fake.BKAL)
add_subdirectory(Occ.BKAL)
