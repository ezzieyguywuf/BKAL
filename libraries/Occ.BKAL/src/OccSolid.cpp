
#include <OccEdge.h>
#include <OccSolid.h>
#include <TopoDS.hxx>
#include <TopoDS_Solid.hxx>
#include <TopExp.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopAbs_ShapeEnum.hxx>

using Occ::Solid;

Solid::Solid(TopoDS_Solid aSolid)
    : mySolid(aSolid)
{
    TopTools_IndexedMapOfShape edges;
    TopExp::MapShapes(mySolid, TopAbs_EDGE, edges);
    for (int i=1; i < edges.Extent() ; i++)
    {
        TopoDS_Edge anEdge = TopoDS::Edge(edges.FindKey(i));
        myEdges.push_back(std::move(pIEdge(new Occ::Edge(anEdge))));
    }
}

const pIEdges& Solid::getEdgeVector() const
{
    return myEdges;
}

const pIFaces& Solid::getFaceVector() const
{
    return myFaces;
}

const TopoDS_Solid& Solid::getSolid() const
{
    return this->mySolid;
}
