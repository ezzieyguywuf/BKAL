ADD_DEFINITIONS("-DBOOST_TEST_DYN_LINK")

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} include)

set(LIBS "gtest_main" "FakeEdge")
function(AddTest SrcName)
    add_executable(${SrcName} "${SrcName}.cpp")
    target_link_libraries(${SrcName} ${LIBS})
    add_test(NAME "TEST_${SrcName}" COMMAND $<TARGET_FILE:${SrcName}>)
endfunction(AddTest)

AddTest(FakeEdgeTester)
