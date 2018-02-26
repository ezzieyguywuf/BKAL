#include <BKAL/Fake/Edge.h>
#include <BKAL/IEdge.h>
#include "gtest/gtest.h"

using Fake::Edge;

TEST(FakeEdge, Equals){
    //Edge edge1(1), edge2(1), edge3(2);
    IEdge* edge1 = new Edge(1);
    IEdge* edge2 = new Edge(1);
    IEdge* edge3 = new Edge(2);
    EXPECT_EQ(*edge1, *edge2);
    EXPECT_NE(*edge1, *edge3);
}
