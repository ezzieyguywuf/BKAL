#include <MockObjectMaker.h>
#include <Mock_Edge.h>

#include <stdexcept>
#include <iostream>
#include <memory>
#include <utility>
#include <sstream>

const unsigned int MockObjectMaker::EDGE=0;
const unsigned int MockObjectMaker::FACE=1;
unsigned int MockObjectMaker::EDGE_COUNT;
unsigned int MockObjectMaker::FACE_COUNT;
const std::map<std::string, int> MockObjectMaker::BoxFaces = {
    {"front", 0},
    {"back", 1},
    {"top", 2},
    {"bottom", 3},
    {"left", 4},
    {"right", 5}
}; 
const std::map<std::string, int> MockObjectMaker::CylFaces = {
    {"top", 0},
    {"lateral", 1},
    {"bot", 2}
};
const std::map<std::string, int> MockObjectMaker::FusTallFaces = {
    {"front", 0},
    {"back", 1},
    {"top", 2},
    {"bottom", 3},
    {"left", 4},
    {"right", 5},
    {"lateral", 6},
    {"cylinder_top", 7},
};

MockObjectMaker::MockObjectMaker()
{
}

std::unique_ptr<IEdge> MockObjectMaker::makeEdge(){
    int name = this->getValue(EDGE);
    return std::unique_ptr<IEdge>(new Mock::Edge(name));
}

std::unique_ptr<IFace> MockObjectMaker::makeFace(){
    return this->makeFace(this->makeMockEdges());
}

//Face MockObjectMaker::makeFace(Edge anEdge){
    //Face aFace = this->makeFace();
    //aFace.myEdges[0] = anEdge;
    //return aFace;
//}

//Face MockObjectMaker::makeFace(Edge anEdge, int which){
    //Face aFace = this->makeFace();
    //aFace.myEdges[which] = anEdge;
    //return aFace;
//}

std::unique_ptr<IFace> MockObjectMaker::makeFace(std::vector<Mock::Edge> Edges){
    int name  = this->getValue(FACE);
    Mock::Face* aFace = new Mock::Face(name, Edges);
    return std::unique_ptr<IFace>(aFace);
}

std::unique_ptr<ISolid> MockObjectMaker::makeBox()
{
    return std::unique_ptr<ISolid>(new Mock::Solid(this->buildBoxFaces()));
}

std::unique_ptr<ISolid> MockObjectMaker::makeCylinder(){
    Mock::Face topFace = this->makeMockFace(1);
    Mock::Face latFace = this->makeMockFace(3);
    Mock::Face botFace = this->makeMockFace(1);

    latFace.changeEdge(0, topFace.getEdge(0));
    latFace.changeEdge(1, botFace.getEdge(0));

    std::vector<Mock::Face> Faces;
    Faces.push_back(topFace);
    Faces.push_back(latFace);
    Faces.push_back(botFace);
    return std::unique_ptr<ISolid>(new Mock::Solid(Faces));
}

tuple<unique_ptr<ISolid>, vector<pair<FaceIndex, FaceIndex>>> 
    MockObjectMaker::increaseBoxHeight(const ISolid& origBox)
{
    unsigned int frt, bck, top, bot, lft, rgt;
    std::vector<Mock::Face> Faces = this->buildBoxFaces();

    frt = BoxFaces.at("front");
    bck = BoxFaces.at("back");
    top = BoxFaces.at("top");
    bot = BoxFaces.at("bottom");
    lft = BoxFaces.at("left");
    rgt = BoxFaces.at("right");

    // Swap some faces around to challenge the topological namer. This simulates what
    // (usually) happens in opencascade
    Mock::Face temp = Faces[frt];
    Faces[frt] = Faces[bck];
    Faces[bck] = temp;
    temp = Faces[lft];
    Faces[lft] = Faces[rgt];
    Faces[rgt] = temp;

    vector<pair<FaceIndex, FaceIndex>> modifiedFaces = {
        {FaceIndex(frt), FaceIndex(frt)},
        {FaceIndex(bck), FaceIndex(bck)},
        {FaceIndex(lft), FaceIndex(lft)},
        {FaceIndex(rgt), FaceIndex(rgt)},
        {FaceIndex(top), FaceIndex(top)},
        {FaceIndex(bot), FaceIndex(bot)}
    };
    return std::tuple<std::unique_ptr<ISolid>, std::vector<std::pair<FaceIndex, FaceIndex>>>
        (std::unique_ptr<ISolid>(new Mock::Solid(Faces)), modifiedFaces);
}

tuple<unique_ptr<ISolid>, vector<pair<FaceIndex, FaceIndex>>>
    MockObjectMaker::fuseTallerCylinder()
{
    unsigned int frt, bck, top, bot, lft, rgt, lat, ctp;
    std::vector<Mock::Face> Faces;

    frt = FusTallFaces.at("front");
    bck = FusTallFaces.at("back");
    top = FusTallFaces.at("top");
    bot = FusTallFaces.at("bottom");
    lft = FusTallFaces.at("left");
    rgt = FusTallFaces.at("right");
    lat = FusTallFaces.at("lateral");
    ctp = FusTallFaces.at("cylinder_top");

    for(int i=0; i<=7; i++){
        int numFaces = 4;
        if (i == lat || i == top || i == bot)
        {
            // Since the cylinder will be taller than the box, the lateral face will
            // actually have five edges. Subsequently, the top face of the box will also
            // have five edges.
            //
            // The bottom will have five edges due to the bottom portion of the cylinder,
            // which will be co-planar to the bottom of the box. This edge will be between
            // the lateral face of the cylinder and the (extended) bottom face of the box
            numFaces = 5;
        }
        else if(i == ctp)
        {
            // The circular top of the cylinder only has a single edge.
            numFaces = 1;
        }
        Faces.push_back(this->makeMockFace(numFaces));
    }

    Faces[top].changeEdge(0, Faces[frt].getEdge(0));
    Faces[bot].changeEdge(0, Faces[frt].getEdge(1));
    Faces[lft].changeEdge(0, Faces[frt].getEdge(2));
    Faces[rgt].changeEdge(0, Faces[frt].getEdge(3));

    Faces[top].changeEdge(1, Faces[bck].getEdge(0));
    Faces[bot].changeEdge(1, Faces[bck].getEdge(1));
    Faces[rgt].changeEdge(1, Faces[bck].getEdge(2));
    Faces[lat].changeEdge(0, Faces[bck].getEdge(3));

    Faces[lft].changeEdge(1, Faces[lat].getEdge(1));
    Faces[lft].changeEdge(2, Faces[top].getEdge(2));
    Faces[lft].changeEdge(3, Faces[bot].getEdge(2));

    Faces[rgt].changeEdge(2, Faces[top].getEdge(3));
    Faces[rgt].changeEdge(3, Faces[bot].getEdge(3));

    Faces[top].changeEdge(4, Faces[lat].getEdge(2));
    Faces[bot].changeEdge(4, Faces[lat].getEdge(3));

    Faces[lat].changeEdge(4, Faces[ctp].getEdge(0));
    
    vector<pair<FaceIndex, FaceIndex>> modifiedFaces = {
        {FaceIndex(frt), FaceIndex(frt)},
        {FaceIndex(lft), FaceIndex(lft)},
        {FaceIndex(rgt), FaceIndex(rgt)},
        {FaceIndex(top), FaceIndex(top)},
        {FaceIndex(bot), FaceIndex(bot)},
        {FaceIndex(bck), FaceIndex(bck)},
        {FaceIndex(), FaceIndex(lat)},
        {FaceIndex(), FaceIndex(ctp)}
    };
    return std::tuple<std::unique_ptr<ISolid>, std::vector<std::pair<FaceIndex, FaceIndex>>>
        (std::unique_ptr<ISolid>(new Mock::Solid(Faces)), modifiedFaces);
}

//std::unique_ptr<ISolid> MockObjectMaker::filletBox(
        //const std::unique_ptr<ISolid>& aBox,
        //const std::unique_ptr<IEdge>& anEdge)
//{
//}

//FakePartFillet MockObjectMaker::FilletedBox(){
    //unsigned int frt, top, lft, rgt;

    //// Start with a box
    //FakePartFeature box = this->Box();

    //// Need a new face, since the fillet (or chamfer) creates a face
    //FakeOCCFace filletFace = this->makeFace();

    //// Fillet shares an Edge with four of the box faces.
    //frt = boxFaces.front;
    //top = boxFaces.top;
    //lft = boxFaces.left;
    //rgt = boxFaces.right;

    //unsigned int val1, val2, val3, val4;
    //val1 = this->getValue(FACE);
    //val2 = this->getValue(FACE);
    //val3 = this->getValue(FACE);
    //val4 = this->getValue(FACE);
    //FakeOCCFace Face1(val1), Face2(val2), Face3(val3), Face4(val4);
    //Face1 = box.Shape.Faces[frt];
    //Face2 = box.Shape.Faces[top];
    //Face3 = box.Shape.Faces[lft];
    //Face4 = box.Shape.Faces[rgt];

    //Face1.myEdges[0] = filletFace.myEdges[0];
    //Face2.myEdges[0] = filletFace.myEdges[1];
    //Face3.myEdges.push_back(filletFace.myEdges[2]);
    //Face4.myEdges.push_back(filletFace.myEdges[3]);

    //box.Shape.Faces[frt] = Face1;
    //box.Shape.Faces[top] = Face2;
    //box.Shape.Faces[lft] = Face3;
    //box.Shape.Faces[rgt] = Face4;

    //FakePartFillet fillet(box.Shape, filletFace);
    //return fillet;
//}

//FakePartFeature MockObjectMaker::Cylinder(){
    //std::vector<FakeOCCEdge> Edges, EdgesTop, EdgesBot;
    //for (int i=1; i<=3; i++){
        //FakeOCCEdge anEdge = this->makeEdge();
        //Edges.push_back(anEdge);
    //}

    //EdgesTop.push_back(Edges[0]);
    //EdgesBot.push_back(Edges[1]);

    //unsigned int val1, val2, val3;
    //val1 = this->getValue(FACE);
    //val2 = this->getValue(FACE);
    //val3 = this->getValue(FACE);

    //FakeOCCFace bot_face(val1, EdgesBot);
    //FakeOCCFace top_face(val2, EdgesTop);
    //FakeOCCFace lat_face(val3, Edges);

    //std::vector<FakeOCCFace> Faces;
    //Faces.push_back(bot_face);
    //Faces.push_back(top_face);
    //Faces.push_back(lat_face);

    //FakePartFeature mock_feature = FakePartFeature();
    //mock_feature.Shape.Faces = Faces;
    //return mock_feature;
//}

//---------------------------------------------------------------------------
//          private methods
//---------------------------------------------------------------------------

int MockObjectMaker::getValue(unsigned int which) const{
    switch (which) {
        case EDGE:
            EDGE_COUNT++;
            return EDGE_COUNT;
        case FACE:
            FACE_COUNT++;
            return FACE_COUNT;
        default:
            throw std::invalid_argument("which must be EDGE or FACE");
    }
}

Mock::Face MockObjectMaker::makeMockFace(unsigned int num_edges){
    int name = this->getValue(FACE);
    Mock::Face outFace(name, this->makeMockEdges(num_edges));
    return outFace;
}

Mock::Edge MockObjectMaker::makeMockEdge(){
    int name = this->getValue(EDGE);
    return Mock::Edge(name);
}

std::vector<Mock::Edge> MockObjectMaker::makeMockEdges(unsigned int count){
    std::vector<Mock::Edge> outEdges;
    for (int i=0; i<count ; i++)
    {
        int name = this->getValue(EDGE);
        outEdges.push_back(Mock::Edge(name));
    }
    return outEdges;
}

// ------------------- Private Methods ------------------------
std::vector<Mock::Face> MockObjectMaker::buildBoxFaces()
{
    unsigned int frt, bck, top, bot, lft, rgt;
    std::vector<Mock::Face> Faces;

    frt = BoxFaces.at("front");
    bck = BoxFaces.at("back");
    top = BoxFaces.at("top");
    bot = BoxFaces.at("bottom");
    lft = BoxFaces.at("left");
    rgt = BoxFaces.at("right");

    for(int i=1; i<=6; i++){
        Mock::Face aFace = this->makeMockFace();
        Faces.push_back(aFace);
    }

    Faces[top].changeEdge(0, Faces[frt].getEdge(0));
    Faces[bot].changeEdge(0, Faces[frt].getEdge(1));
    Faces[lft].changeEdge(0, Faces[frt].getEdge(2));
    Faces[rgt].changeEdge(0, Faces[frt].getEdge(3));

    Faces[top].changeEdge(1, Faces[bck].getEdge(0));
    Faces[bot].changeEdge(1, Faces[bck].getEdge(1));
    Faces[lft].changeEdge(1, Faces[bck].getEdge(2));
    Faces[rgt].changeEdge(1, Faces[bck].getEdge(3));

    Faces[lft].changeEdge(2, Faces[top].getEdge(2));
    Faces[lft].changeEdge(3, Faces[bot].getEdge(2));

    Faces[rgt].changeEdge(2, Faces[top].getEdge(3));
    Faces[rgt].changeEdge(3, Faces[bot].getEdge(3));
    return Faces;
}
