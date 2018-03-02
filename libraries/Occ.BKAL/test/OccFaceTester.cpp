#include <OccFace.h>
#include <IFace.h>
#include <BRepPrimAPI_MakeBox.hxx>
#include <TopoDS_Solid.hxx>
#include <TopExp.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopoDS.hxx>
#include "gtest/gtest.h"

using Occ::Face;
using BKAL::IFace;
using BKAL::pIFace;

TEST(OccFace, Equals){
    BRepPrimAPI_MakeBox mkBox(10.0, 10.0, 10.0);
    mkBox.Build();
    TopoDS_Shape box = mkBox.Shape();
    TopTools_IndexedMapOfShape faces;
    TopExp::MapShapes(box, TopAbs_FACE, faces);
    IFace* face1 = new Face(TopoDS::Face(faces.FindKey(1)));
    IFace* face2 = new Face(TopoDS::Face(faces.FindKey(1)));
    IFace* face3 = new Face(TopoDS::Face(faces.FindKey(2)));
    EXPECT_EQ(*face1, *face2);
    EXPECT_NE(*face1, *face3);
}

TEST (OccFace, sharesEdge){
    BRepPrimAPI_MakeBox mkBox(10.0, 10.0, 10.0);
    mkBox.Build();
    TopoDS_Shape box = mkBox.Shape();
    pIFace front(new Occ::Face(mkBox.FrontFace()));
    pIFace top(new Occ::Face(mkBox.TopFace()));
    pIFace back(new Occ::Face(mkBox.BackFace()));
    EXPECT_TRUE(front->sharesEdge(*top));
    EXPECT_FALSE(front->sharesEdge(*back));
}
