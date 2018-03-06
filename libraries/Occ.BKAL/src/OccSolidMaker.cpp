#include <OccSolidMaker.h>
#include <OccBox.h>
#include <OccCylinder.h>
#include <OccSolid.h>
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>
#include <BRepAlgoAPI_Fuse.hxx>
#include <TopoDS.hxx>

using Occ::SolidMaker;

pIBox SolidMaker::makeBox(uint L, uint W, uint H) const 
{
    BRepPrimAPI_MakeBox mkBox(L, W, H);
    return pIBox(new Occ::Box(mkBox));
}

pICylinder SolidMaker::makeCylinder(uint R, uint H) const 
{
    BRepPrimAPI_MakeCylinder mkCyl(R, H);
    return pICylinder(new Occ::Cylinder(mkCyl));
}

pISolid SolidMaker::makeFusion(const pISolid& base, const pISolid& tool) const 
{
    const Occ::Solid& occBase = dynamic_cast<const Occ::Solid&>(*base);
    const Occ::Solid& occTool = dynamic_cast<const Occ::Solid&>(*tool);
    BRepAlgoAPI_Fuse mkFuse(occBase.getSolid(), occTool.getSolid());
    mkFuse.Build();
    return pISolid(new Occ::Solid(TopoDS::Solid(mkFuse.Shape())));
}
