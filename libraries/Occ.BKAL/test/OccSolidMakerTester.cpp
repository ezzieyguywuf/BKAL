#include <ISolidMaker.h>
#include <IBox.h>
#include <ICylinder.h>
#include <IFace.h>
#include <BKALTypes.h>
#include <OccSolidMaker.h>
#include <OccBox.h>
#include "gtest/gtest.h"

using BKAL::pIFace;
using BKAL::pIBox;
using BKAL::pICylinder;
using BKAL::pISolidMaker;
using BKAL::ISolidMaker;
using BKAL::IBox;
using BKAL::ICylinder;
using BKAL::IFace;
using Occ::SolidMaker;

class OccSolidMakerTest : public testing::Test{
    public:
        OccSolidMakerTest()
            : myMaker(new SolidMaker())
            {};
        pISolidMaker myMaker;
};

TEST_F(OccSolidMakerTest, makeBox){
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

TEST_F(OccSolidMakerTest, makeCylinder){
    pICylinder cyl(myMaker->makeCylinder(1, 1));

    EXPECT_TRUE(cyl->lateral().sharesEdge(cyl->top()));
    EXPECT_TRUE(cyl->lateral().sharesEdge(cyl->bottom()));
    EXPECT_FALSE(cyl->top().sharesEdge(cyl->bottom()));

    EXPECT_EQ(cyl->lateral().getEdges().size(), 3);
    EXPECT_EQ(cyl->top().getEdges().size(), 1);
    EXPECT_EQ(cyl->bottom().getEdges().size(), 1);

    EXPECT_EQ(cyl->getFaces().size(), 3);
}

TEST_F(OccSolidMakerTest, makeFusion){
    // Are there other tests we should perform here?
    //pISolid box(myMaker->makeBox(1, 1, 1));
    //pISolid cyl(myMaker->makeCylinder(1, 1));
    //pISolid fused(myMaker->makeFusion(box, cyl));

    //EXPECT_EQ(fused->getFaces().size(), 7);
    //EXPECT_EQ(fused->getEdges().size(), 15);
}
