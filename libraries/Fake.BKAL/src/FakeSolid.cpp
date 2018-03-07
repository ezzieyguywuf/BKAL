#include <FakeSolid.h>
#include <algorithm>

using Fake::Solid;
using Fake::Edge;
using Fake::Face;

Solid::Solid(vector<Face> faces)
{
    for(const auto& aFace : faces){
        myFaces.push_back(std::move(pIFace(new Face(aFace))));
        this->addEdges(myFaces.back()->getEdges());
    }
}

Solid::Solid(const Solid& aSolid)
{
    for (const auto& faceptr : aSolid.myFaces)
    {
        const IFace* tmpIFace = faceptr.get();
        const Face* tmpFace = static_cast<const Face*>(tmpIFace);
        this->addFace(*tmpFace);
    }
}

Solid::Solid(Solid&& aSolid)
    : myFaces(std::move(aSolid.myFaces)), myEdges(std::move(aSolid.myEdges)), myEdgeVals(aSolid.myEdgeVals)
{
}

Solid Solid::operator=(const Solid& aSolid)
{
    myFaces.clear();
    myEdges.clear();
    myEdgeVals.clear();
    for (const auto& faceptr : aSolid.myFaces)
    {
        const IFace* tmpIFacePtr = faceptr.get();
        const Face* tmpFacePtr = static_cast<const Face*>(tmpIFacePtr);
        this->addFace(*tmpFacePtr);
    }
    return *this;
}

Solid Solid::operator=(Solid&& aSolid)
{
    if (this != &aSolid)
    {
        myFaces = std::move(aSolid.myFaces);
        myEdges = std::move(aSolid.myEdges);
        myEdgeVals = aSolid.myEdgeVals;
    }
    return *this;
}

const pIFaces& Solid::getFaceVector() const
{
    return myFaces;
}

const pIEdges& Solid::getEdgeVector() const
{
    return myEdges;
}

const pIFace& Solid::getFace(int which) const{
    return myFaces[which];
}

// -------------------------------------------------------------
//                private methods
// -------------------------------------------------------------

bool Solid::checkEdge(const pIEdge& anEdge) const
{
    for (const auto& edge : myEdges)
    {
        if (*edge == *anEdge)
        {
            return true;
        }
    }
    return false;
}

void Solid::addEdges(const pIEdges& edges)
{
    for (const auto& edge : edges)
    {
        if (! this->checkEdge(edge))
        {
            Fake::Edge* tmpEdge = static_cast<Fake::Edge*>(edge.get());
            myEdges.push_back(std::move(pIEdge(new Fake::Edge(tmpEdge->getValue()))));
            myEdgeVals.push_back(tmpEdge->getValue());
        }
    }
}

void Solid::addFace(const Face& aFace)
{
    myFaces.push_back(std::move(pIFace(new Fake::Face(aFace))));
    this->addEdges(aFace.getEdges());
}
