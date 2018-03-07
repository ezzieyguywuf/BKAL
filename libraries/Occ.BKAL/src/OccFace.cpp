#include <OccEdge.h>
#include <OccFace.h>
#include <TopoDS.hxx>
#include <TopoDS_Solid.hxx>
#include <TopExp.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopAbs_ShapeEnum.hxx>

#include <iostream>

using Occ::Face;

Face::Face(const Face& aFace)
    : myFace(aFace.myFace)
{
    this->processFace();
}

Face::Face(Face&& aFace)
    : myFace(aFace.myFace), myEdges(std::move(aFace.myEdges))
{
    aFace.myFace.Nullify();
}

Face Face::operator=(const Face& aFace)
{
    myFace = aFace.myFace;
    myEdges.clear();
    this->processFace();
    return *this;
}

Face Face::operator=(Face&& aFace)
{
    myFace = aFace.myFace;
    myEdges = std::move(aFace.myEdges);
    aFace.myFace.Nullify();
    return *this;
}

Face::Face(const TopoDS_Face& aFace)
    : myFace(aFace)
{
    this->processFace();
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

//--------------------------------------------------
//------- Private Methods --------------------------
//--------------------------------------------------
void Face::processFace()
{
    TopTools_IndexedMapOfShape edges;
    TopExp::MapShapes(myFace, TopAbs_EDGE, edges);
    for (int i=1; i <= edges.Extent() ; i++)
    {
        TopoDS_Edge anEdge = TopoDS::Edge(edges.FindKey(i));
        myEdges.push_back(std::move(pIEdge(new Occ::Edge(anEdge))));
    }
}
