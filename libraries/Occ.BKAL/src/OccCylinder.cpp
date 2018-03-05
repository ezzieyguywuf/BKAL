#include <OccCylinder.h>
#include <OccFace.h>
#include <TopoDS.hxx>
#include <BRepPrim_Cylinder.hxx>

using Occ::Face;
using Occ::Cylinder;
using Occ::Solid;

Cylinder::Cylinder(BRepPrimAPI_MakeCylinder mkCylinder)
    : Solid(TopoDS::Solid(mkCylinder.Shape())), myMakeCylinder(mkCylinder)
{
    BRepPrim_Cylinder cyl = myMakeCylinder.Cylinder();
    pIFace lateral(new Face(cyl.LateralFace()));
    pIFace top(new Face(cyl.TopFace()));
    pIFace bottom(new Face(cyl.BottomFace()));
    int i = 0;
    for(const pIFace& aFace : this->getFaceVector()){
        if(*aFace == *lateral){
            myIndices["lateral"] = i;
        }
        else if(*aFace == *top){
            myIndices["top"] = i;
        }
        else if(*aFace == *bottom){
            myIndices["bottom"] = i;
        }
        i++;
    }
}

const pIFaces& Cylinder::getFaceVector() const 
{
    return Solid::getFaceVector();
}
const pIEdges& Cylinder::getEdgeVector() const
{
    return Solid::getEdgeVector();
}


const IFace& Cylinder::lateral() const
{
    return *(this->getFaceVector()[myIndices.at("lateral")]);
}

const IFace& Cylinder::top() const
{
    return *(this->getFaceVector()[myIndices.at("top")]);
}


const IFace& Cylinder::bottom() const
{
    return *(this->getFaceVector()[myIndices.at("bottom")]);
}
