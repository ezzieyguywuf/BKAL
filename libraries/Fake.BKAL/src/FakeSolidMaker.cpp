#include <FakeSolidMaker.h>
#include <FakeBox.h>
#include <FakeCylinder.h>
#include <BKALTypes.h>

#include <array>

using Fake::SolidMaker;

unsigned int SolidMaker::EDGE_COUNT;

pIBox SolidMaker::makeBox(uint L, uint W, uint H) const
{
    std::array<uint, 12> edges;
    for (int i = 0; i <=11; i++)
    {
        edges[i] = getValue();
    }
    return pIBox(new Fake::Box(edges));
}

pICylinder SolidMaker::makeCylinder(uint R, uint H) const
{
    std::array<uint, 3> edges;
    for (int i = 0; i <=2; i++)
    {
        edges[i] = getValue();
    }
    return pICylinder(new Fake::Cylinder(edges));
}

//---------------------------------------------------------------------------
//          private methods
//---------------------------------------------------------------------------

uint SolidMaker::getValue() const{
    EDGE_COUNT++;
    return EDGE_COUNT;
}
