#include <OccEdge.h>
#include <OccFace.h>
#include <TopoDS.hxx>
#include <TopoDS_Solid.hxx>
#include <TopExp.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopAbs_ShapeEnum.hxx>

using Occ::Face;

Face::Face(TopoDS_Face aFace)
    : myFace(aFace)
{
    TopTools_IndexedMapOfShape edges;
    TopExp::MapShapes(myFace, TopAbs_EDGE, edges);
    for (int i=1; i < edges.Extent() ; i++)
    {
        TopoDS_Edge anEdge = TopoDS::Edge(edges.FindKey(i));
        myEdges.push_back(std::move(pIEdge(new Occ::Edge(anEdge))));
    }
}

bool Face::operator==(const Face& aFace) const
{
    return myFace.IsEqual(aFace.getFace());
}

bool Face::isFlipped(const Face& aFace) const
{
    return myFace.IsSame(aFace.getFace());
}

const pIEdges& Face::getEdgeVector() const
{
    return myEdges;
}

const TopoDS_Face& Face::getFace() const
{
    return this->myFace;
}
