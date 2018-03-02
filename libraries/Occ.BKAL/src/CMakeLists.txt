add_library(OccEdge OccEdge.cpp)
target_link_libraries(OccEdge ${OCC_LIBS})

add_library(OccFace OccFace.cpp)
target_link_libraries(OccFace ${OCC_LIBS} OccEdge)
