#ADD_DEFINITIONS("-DBOOST_TEST_DYN_LINK")

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

function(AddTest SrcName)
    add_executable(${SrcName} "${SrcName}.cpp")
    target_link_libraries(${SrcName} "gtest_main" ${ARGN})
    add_test(NAME "TEST_${SrcName}" COMMAND $<TARGET_FILE:${SrcName}>)
endfunction(AddTest)

AddTest(FakeEdgeTester "FakeEdge")
AddTest(FakeFaceTester "FakeFace")
AddTest(FakeSolidMakerTester "FakeSolidMaker" "FakeEdge")

add_executable(SimpleCase SimpleCase.cpp)
target_link_libraries(SimpleCase "FakeSolidMaker")
