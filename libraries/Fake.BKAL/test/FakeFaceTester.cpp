#include <FakeFace.h>
#include <FakeEdge.h>
#include <BKALTypes.h>
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
    EXPECT_EQ(*face1, *face2);
}

TEST(FakeFace, NotEquals){
    // First, create three IEdges (for a triangular face)
    pIEdges IEdges1, IEdges2;
    IEdges1.push_back(std::move(pIEdge(new Edge(1))));
    IEdges1.push_back(std::move(pIEdge(new Edge(2))));
    IEdges1.push_back(std::move(pIEdge(new Edge(3))));
    IEdges2.push_back(std::move(pIEdge(new Edge(1))));
    IEdges2.push_back(std::move(pIEdge(new Edge(4))));
    IEdges2.push_back(std::move(pIEdge(new Edge(5))));

    // Next, create two faces with these Edges
    pIFace face1(new Face(std::move(IEdges1)));
    pIFace face2(new Face(std::move(IEdges2)));

    // Now, assert these faces are not equal
    EXPECT_NE(*face1, *face2);
}

TEST(FakeFace, SharedEdge){
    // First, create three IEdges (for a triangular face)
    pIEdges IEdges1, IEdges2, IEdges3;
    IEdges1.push_back(std::move(pIEdge(new Edge(1))));
    IEdges1.push_back(std::move(pIEdge(new Edge(2))));
    IEdges1.push_back(std::move(pIEdge(new Edge(3))));
    IEdges2.push_back(std::move(pIEdge(new Edge(1))));
    IEdges2.push_back(std::move(pIEdge(new Edge(4))));
    IEdges2.push_back(std::move(pIEdge(new Edge(5))));
    IEdges3.push_back(std::move(pIEdge(new Edge(6))));
    IEdges3.push_back(std::move(pIEdge(new Edge(7))));
    IEdges3.push_back(std::move(pIEdge(new Edge(8))));

    // Next, create two faces with these Edges
    pIFace face1(new Face(std::move(IEdges1)));
    pIFace face2(new Face(std::move(IEdges2)));
    pIFace face3(new Face(std::move(IEdges3)));

    // Now, assert that face1 and face2 share an Edge, and thate face1 and face3 don't.
    EXPECT_TRUE(face1->sharesEdge(*face2));
    EXPECT_FALSE(face1->sharesEdge(*face3));
    EXPECT_FALSE(face2->sharesEdge(*face3));
}
