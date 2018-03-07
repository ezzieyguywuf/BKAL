
#include <OccEdge.h>
#include <OccFace.h>
#include <OccSolid.h>
#include <TopoDS.hxx>
#include <TopoDS_Solid.hxx>
#include <TopExp.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopAbs_ShapeEnum.hxx>

using Occ::Solid;
using BKAL::pIFace;

Solid::Solid(const Solid& aSolid)
    : mySolid(aSolid.mySolid)
{
    this->processSolid();
}

Solid::Solid(Solid&& aSolid)
    : mySolid(aSolid.mySolid), myEdges(std::move(aSolid.myEdges)), myFaces(std::move(aSolid.myFaces))
{
    aSolid.mySolid.Nullify();
}

Solid Solid::operator=(const Solid& aSolid)
{
    mySolid = aSolid.mySolid;
    myEdges.clear();
    myFaces.clear();
    this->processSolid();
    return *this;
}

Solid Solid::operator=(Solid&& aSolid)
{
    if (this != &aSolid)
    {
        myEdges = std::move(aSolid.myEdges);
        myFaces = std::move(aSolid.myFaces);
        mySolid = aSolid.mySolid;
        aSolid.mySolid.Nullify();
    }
    return *this;
}

Solid::Solid(const TopoDS_Solid& aSolid)
    : mySolid(aSolid)
{
    this->processSolid();
}

Solid::Solid(const TopoDS_CompSolid& aSolid)
    : mySolid(aSolid)
{
    this->processSolid();
}

Solid::Solid(const TopoDS_Compound& aSolid)
    : mySolid(aSolid)
{
    this->processSolid();
}

const pIEdges& Solid::getEdgeVector() const
{
    return myEdges;
}

const pIFaces& Solid::getFaceVector() const
{
    return myFaces;
}

const TopoDS_Shape& Solid::getSolid() const
{
    return this->mySolid;
}

//--------------------------------------------------
//------- Private Methods --------------------------
//--------------------------------------------------
void Solid::processSolid()
{
    TopTools_IndexedMapOfShape edges;
    TopExp::MapShapes(mySolid, TopAbs_EDGE, edges);
    for (int i=1; i <= edges.Extent() ; i++)
    {
        TopoDS_Edge anEdge = TopoDS::Edge(edges.FindKey(i));
        myEdges.push_back(std::move(pIEdge(new Occ::Edge(anEdge))));
    }

    TopTools_IndexedMapOfShape faces;
    TopExp::MapShapes(mySolid, TopAbs_FACE, faces);
    for (int i=1; i <= faces.Extent() ; i++)
    {
        TopoDS_Face anFace = TopoDS::Face(faces.FindKey(i));
        myFaces.push_back(std::move(pIFace(new Occ::Face(anFace))));
    }
}
