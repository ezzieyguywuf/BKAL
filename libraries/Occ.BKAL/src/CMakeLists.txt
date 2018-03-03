add_library(OccEdge OccEdge.cpp)
target_link_libraries(OccEdge ${OCC_LIBS})

add_library(OccFace OccFace.cpp)
target_link_libraries(OccFace ${OCC_LIBS} OccEdge)

add_library(OccSolid OccSolid.cpp)
target_link_libraries(OccSolid ${OCC_LIBS} OccFace)

add_library(OccBox OccBox.cpp)
target_link_libraries(OccBox ${OCC_LIBS} OccSolid)

add_library(OccCylinder OccCylinder.cpp)
target_link_libraries(OccCylinder ${OCC_LIBS} OccSolid)
