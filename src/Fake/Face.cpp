#include <BKAL/Fake/Face.h>
#include <BKAL/Fake/Edge.h>

using Fake::Face;
using Fake::Edge;
using std::unique_ptr;
using std::vector;

Face::Face (int value, vector<Fake::Edge> edges)
    : myValue(value)
{
    for (auto edge : edges)
    {
        myEdges.push_back(std::move(unique_ptr<IEdge>(new Fake::Edge(edge.getVal()))));
    }
}

Face::Face (const Face& aFace)
    : myValue(aFace.myValue)
{
    for (const auto& edge : aFace.myEdges)
    {
        const IEdge* tmpIEdge = edge.get();
        const Fake::Edge*  tmpFakeEdge = static_cast<const Fake::Edge*>(tmpIEdge);
        myEdges.push_back(std::move(unique_ptr<IEdge>(new Fake::Edge(*tmpFakeEdge))));
    }
}

Face::Face(Face&& aFace)
    : myValue(aFace.myValue), myEdges(std::move(aFace.myEdges))
{
    aFace.myValue = 0;
    aFace.myEdges.clear();
}

Face Face::operator=(const Face& aFace)
{
    myEdges.clear();
    for (const auto& edge : aFace.myEdges)
    {
        const IEdge* tmpIEdge = edge.get();
        const Fake::Edge*  tmpFakeEdge = static_cast<const Fake::Edge*>(tmpIEdge);
        myEdges.push_back(std::move(unique_ptr<IEdge>(new Fake::Edge(*tmpFakeEdge))));
    }
    myValue = aFace.myValue;
    return *this;
}

Face Face::operator=(Face&& aFace)
{
    if (this != & aFace)
    {
        myValue = 0;
        myEdges.clear();

        myValue = aFace.myValue;
        myEdges = std::move(aFace.myEdges);

        aFace.myValue = 0;
        aFace.myEdges.clear();
    }
    return *this;
}

bool Face::operator==(const Face& aFace) const
{
    return this->myValue == aFace.getValue();
}

bool Face::isFlipped(const Face& aFace) const
{
    return (*this) == aFace;
}

const vector<unique_ptr<IEdge>>& Face::getEdgeVector() const
{
    return myEdges;
}

int Face::getValue() const{
    return myValue;
}


void Face::changeEdge(int which, const Fake::Edge& newEdge)
{
    myEdges[which] = std::move(unique_ptr<IEdge>(new Fake::Edge(newEdge.getVal())));
}

void Face::changeEdge(int index, const unique_ptr<IEdge>& newIEdge)
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
