#include <BKAL/Fake/Edge.h>
#include "gtest/gtest.h"

using Fake::Edge;

TEST(FakeEdge, Equals){
    Edge edge1(1), edge2(1);
    EXPECT_EQ(edge1, edge2);
}
