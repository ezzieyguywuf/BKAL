#include <OccEdge.h>
#include <IEdge.h>
#include <BRepPrimAPI_MakeBox.hxx>
#include <TopoDS_Solid.hxx>
#include <TopExp.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopoDS.hxx>
#include "gtest/gtest.h"

using Occ::Edge;
using BKAL::IEdge;

TEST(OccEdge, Equals){
    //Edge edge1(1), edge2(1), edge3(2);
    BRepPrimAPI_MakeBox mkBox(10.0, 10.0, 10.0);
    mkBox.Build();
    TopoDS_Shape box = mkBox.Shape();
    TopTools_IndexedMapOfShape edges;
    TopExp::MapShapes(box, TopAbs_EDGE, edges);
    IEdge* edge1 = new Edge(TopoDS::Edge(edges.FindKey(1)));
    IEdge* edge2 = new Edge(TopoDS::Edge(edges.FindKey(1)));
    IEdge* edge3 = new Edge(TopoDS::Edge(edges.FindKey(2)));
    EXPECT_EQ(*edge1, *edge2);
    EXPECT_NE(*edge1, *edge3);
}
