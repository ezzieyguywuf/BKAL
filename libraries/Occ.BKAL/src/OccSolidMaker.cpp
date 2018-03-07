#include <OccSolidMaker.h>
#include <OccBox.h>
#include <OccCylinder.h>
#include <OccSolid.h>
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>
#include <BRepAlgoAPI_Fuse.hxx>
#include <TopoDS.hxx>

using Occ::SolidMaker;

pIBox SolidMaker::makeBox(double L, double W, double H) const 
{
    BRepPrimAPI_MakeBox mkBox(L, W, H);
    return pIBox(new Occ::Box(mkBox));
}

pICylinder SolidMaker::makeCylinder(double R, double H) const 
{
    BRepPrimAPI_MakeCylinder mkCyl(R, H);
    return pICylinder(new Occ::Cylinder(mkCyl));
}

pISolid SolidMaker::makeFusion(const Solid& base, const Solid& tool) const 
{
    BRepAlgoAPI_Fuse mkFuse(base.getSolid(), tool.getSolid());
    mkFuse.Build();
    TopoDS_Compound aCompound = TopoDS::Compound(mkFuse.Shape());
    // TODO: is a mkFuse.Shape() always a TopoDS_Compound?
    return pISolid(new Occ::Solid(aCompound));
}
