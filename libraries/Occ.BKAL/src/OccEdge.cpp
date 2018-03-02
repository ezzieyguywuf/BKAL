#include <OccEdge.h>

using Occ::Edge;

Edge::Edge(TopoDS_Edge anEdge)
    : myEdge(anEdge)
{}

bool Edge::operator==(const Edge& anEdge) const
{
    return myEdge.IsEqual(anEdge.getEdge());
}

bool Edge::isFlipped(const Edge& anEdge) const
{
    return myEdge.IsSame(anEdge.getEdge());
}

const TopoDS_Edge& Edge::getEdge() const
{
    return this->myEdge;
}
