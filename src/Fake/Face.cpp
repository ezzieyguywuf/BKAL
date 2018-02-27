#include <BKAL/Fake/Face.h>
#include <BKAL/Fake/Edge.h>

using Fake::Face;
using std::vector;

Face::Face (const pIEdges& edges)
{
    for (const auto& anEdge : edges)
    {
        const Fake::Edge* tmpEdge = static_cast<const Fake::Edge*>(anEdge.get());
        myEdges.push_back(std::move(pIEdge(new Fake::Edge(*tmpEdge))));
    }
}

Face::Face(const vector<uint>& edgeVals)
{
    for (const uint& i : edgeVals)
    {
        myEdges.push_back(std::move(pIEdge(new Fake::Edge(i))));
    }
}

Face::Face (const Face& aFace)
{
    for (const auto& edge : aFace.myEdges)
    {
        const IEdge* tmpIEdge = edge.get();
        const Fake::Edge*  tmpFakeEdge = static_cast<const Fake::Edge*>(tmpIEdge);
        myEdges.push_back(std::move(pIEdge(new Fake::Edge(*tmpFakeEdge))));
    }
}

Face::Face(Face&& aFace)
    : myEdges(std::move(aFace.myEdges))
{
    aFace.myEdges.clear();
}

Face Face::operator=(const Face& aFace)
{
    myEdges.clear();
    for (const auto& edge : aFace.myEdges)
    {
        const IEdge* tmpIEdge = edge.get();
        const Fake::Edge*  tmpFakeEdge = static_cast<const Fake::Edge*>(tmpIEdge);
        myEdges.push_back(std::move(pIEdge(new Fake::Edge(*tmpFakeEdge))));
    }
    return *this;
}

Face Face::operator=(Face&& aFace)
{
    if (this != & aFace)
    {
        myEdges.clear();

        myEdges = std::move(aFace.myEdges);

        aFace.myEdges.clear();
    }
    return *this;
}

bool Face::operator==(const Face& aFace) const
{
    bool check = false;
    for (const auto& myEdge : myEdges){
        for (const auto& checkEdge : aFace.getEdgeVector()){
            if (*myEdge.get() == *checkEdge.get()){
                check = true;
            }
        }
        if (not check){
            return false;
        }
        else{
            check = false;
        }
    }
    return true;
}

bool Face::isFlipped(const Face& aFace) const
{
    return (*this) == aFace;
}

const pIEdges& Face::getEdgeVector() const
{
    return myEdges;
}

void Face::changeEdge(int which, const Fake::Edge& newEdge)
{
    myEdges[which] = std::move(pIEdge(new Fake::Edge(newEdge.getVal())));
}

void Face::changeEdge(int index, const pIEdge& newIEdge)
{
    const Fake::Edge* newEdge = static_cast<const Fake::Edge*>(newIEdge.get());
    this->changeEdge(index, *newEdge);
}

Fake::Edge Face::getEdge(int index)
{
    IEdge* tmpIEdge = myEdges[index].get();
    Fake::Edge*  tmpFakeEdge = static_cast<Fake::Edge*>(tmpIEdge);
    Fake::Edge outEdge(*tmpFakeEdge);
    return outEdge;
}
