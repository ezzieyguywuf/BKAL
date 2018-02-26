#include <BKAL/Fake/Face.h>
#include <BKAL/Fake/Edge.h>
#include <BKAL/Types.h>
#include "gtest/gtest.h"

#include <memory> // for std::move et. al.
#include <vector>

using Fake::Edge;
using Fake::Face;
using BKAL::pIFace;
using BKAL::pIEdges;

TEST(FakeFace, Equals){
    // First, create three IEdges (for a triangular face)
    pIEdges IEdges1, IEdges2;
    IEdges1.push_back(std::move(pIEdge(new Edge(1))));
    IEdges1.push_back(std::move(pIEdge(new Edge(2))));
    IEdges1.push_back(std::move(pIEdge(new Edge(3))));
    IEdges2.push_back(std::move(pIEdge(new Edge(1))));
    IEdges2.push_back(std::move(pIEdge(new Edge(2))));
    IEdges2.push_back(std::move(pIEdge(new Edge(3))));

    // Next, create two faces with these same Edges
    pIFace face1(new Face(std::move(IEdges1)));
    pIFace face2(new Face(std::move(IEdges2)));

    // Now, assert these faces are equal
    EXPECT_EQ(*face1.get(), *face2.get());
}
