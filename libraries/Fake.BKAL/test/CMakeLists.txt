#ADD_DEFINITIONS("-DBOOST_TEST_DYN_LINK")

include(${CMAKE_HELPER_DIR}/functions.cmake)

AddTest(FakeEdgeTester "FakeEdge")
AddTest(FakeFaceTester "FakeFace")
AddTest(FakeSolidMakerTester "FakeSolidMaker")

#add_executable(SimpleCase SimpleCase.cpp)
#target_link_libraries(SimpleCase "FakeSolidMaker")
