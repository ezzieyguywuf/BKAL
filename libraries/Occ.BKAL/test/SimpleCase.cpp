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

    std::cout << std::boolalpha;
    std::cout << "front.sharesEdge(top) = " << occBox.front().sharesEdge(occBox.top()) << std::endl;
    std::cout << "front.sharesEdge(back) = " << occBox.front().sharesEdge(occBox.back()) << std::endl;
    return 0;
}
