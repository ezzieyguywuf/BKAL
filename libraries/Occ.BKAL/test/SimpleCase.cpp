//#include <BRepPrimAPI_MakeBox.hxx>
//#include <TopoDS_Shape.hxx>
//#include <TopoDS_Face.hxx>
//#include <TopoDS_Solid.hxx>
//#include <TopoDS.hxx>
//#include <TopExp.hxx>
//#include <TopTools_IndexedMapOfShape.hxx>
//#include <TopAbs_ShapeEnum.hxx>
//#include <OccFace.h>
#include <OccSolidMaker.h>
#include <OccBox.h>
#include <OccCylinder.h>
#include <BKALTypes.h>

#include <iostream>

using BKAL::ISolid;
//using BKAL::pIBox;
//using BKAL::pICylinder;
using BKAL::pISolidMaker;
//using BKAL::pISolid;

int main(void)
{
    pISolidMaker myMaker(new Occ::SolidMaker); 
    pISolid box(myMaker->makeBox(1, 1, 1));
    pISolid cyl(myMaker->makeCylinder(0.25, 1));
    pISolid fused(myMaker->makeFusion(box, cyl));

    std::cout << "HELLO!" << std::endl;
    //std::cout << std::boolalpha;
    //std::cout << "front.sharesEdge(top) = " << occBox.front().sharesEdge(occBox.top()) << std::endl;
    //std::cout << "front.sharesEdge(back) = " << occBox.front().sharesEdge(occBox.back()) << std::endl;
    return 0;
}
