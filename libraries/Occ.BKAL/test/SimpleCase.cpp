#include <BRepPrimAPI_MakeBox.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS.hxx>
#include <TopExp.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <OccBox.h>
#include <OccFace.h>
#include <BKALTypes.h>

#include <iostream>

using BKAL::pIFace;

int main(void)
{
    BRepPrimAPI_MakeBox mkBox(1, 1, 1);
    TopoDS_Solid myBox(TopoDS::Solid(mkBox.Shape()));
    Occ::Box occBox(mkBox);

    const IFace& front = occBox.front();
    const IFace& top = occBox.top();

    const Occ::Face& occFront = static_cast<const Occ::Face&>(front);
    const Occ::Face& occTop = static_cast<const Occ::Face&>(top);

    front.sharesEdge(top);
    return 0;
}
