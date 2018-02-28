#include <BKAL/ISolidMaker.h>
#include <BKAL/IBox.h>
#include <BKAL/ICylinder.h>
#include <BKAL/IFace.h>
#include <BKAL/Fake/SolidMaker.h>
#include <BKAL/Types.h>
#include <BKAL/Fake/Box.h>
#include "gtest/gtest.h"

using BKAL::pIFace;
using BKAL::pIBox;
using BKAL::pICylinder;
using BKAL::pISolidMaker;
using Fake::SolidMaker;

class FakeSolidMakerTest : public testing::Test{
    public:
        FakeSolidMakerTest()
            : myMaker(new SolidMaker())
            {};
        pISolidMaker myMaker;
};

TEST_F(FakeSolidMakerTest, makeBox){
    pIBox box(myMaker->makeBox(1, 1, 1));

    EXPECT_TRUE(box->front().sharesEdge(box->top()));
    EXPECT_TRUE(box->front().sharesEdge(box->left()));
    EXPECT_TRUE(box->front().sharesEdge(box->right()));
    EXPECT_TRUE(box->front().sharesEdge(box->bottom()));

    EXPECT_TRUE(box->back().sharesEdge(box->top()));
    EXPECT_TRUE(box->back().sharesEdge(box->left()));
    EXPECT_TRUE(box->back().sharesEdge(box->right()));
    EXPECT_TRUE(box->back().sharesEdge(box->bottom()));

    EXPECT_FALSE(box->front().sharesEdge(box->back()));

    EXPECT_EQ(box->front().getEdges().size(), 4);
    EXPECT_EQ(box->back().getEdges().size(), 4);
    EXPECT_EQ(box->left().getEdges().size(), 4);
    EXPECT_EQ(box->right().getEdges().size(), 4);
    EXPECT_EQ(box->top().getEdges().size(), 4);
    EXPECT_EQ(box->bottom().getEdges().size(), 4);

    EXPECT_EQ(box->getFaces().size(), 6);
}

TEST_F(FakeSolidMakerTest, makeCylinder){
    pICylinder cyl(myMaker->makeCylinder(1, 1));

    EXPECT_TRUE(cyl->lateral().sharesEdge(cyl->top()));
    EXPECT_TRUE(cyl->lateral().sharesEdge(cyl->bottom()));
    EXPECT_FALSE(cyl->top().sharesEdge(cyl->bottom()));

    EXPECT_EQ(cyl->lateral().getEdges().size(), 3);
    EXPECT_EQ(cyl->top().getEdges().size(), 1);
    EXPECT_EQ(cyl->bottom().getEdges().size(), 1);

    EXPECT_EQ(cyl->getFaces().size(), 3);
}
