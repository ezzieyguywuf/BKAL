include(${CMAKE_HELPER_DIR}/functions.cmake)

AddTest(OccEdgeTester "OccEdge")
AddTest(OccFaceTester "OccFace")
AddTest(OccSolidMakerTester "OccSolidMaker")

add_executable(SimpleCase SimpleCase.cpp)
target_link_libraries(SimpleCase ${OCC_LIBS} OccSolidMaker OccSolid OccBox OccCylinder OccFace)

add_executable(SimpleCase2 SimpleCase2.cpp)
