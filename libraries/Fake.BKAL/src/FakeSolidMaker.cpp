#include <FakeSolidMaker.h>
#include <FakeBox.h>
#include <FakeCylinder.h>
#include <BKALTypes.h>

#include <array>

using Fake::SolidMaker;
using Fake::Solid;
using BKAL::uint;

unsigned int SolidMaker::EDGE_COUNT;

pIBox SolidMaker::makeBox(uint L, uint W, uint H) const
{
    // suppress "unused parameter" warning
    (void) L;
    (void) W;
    (void) H;
    std::array<uint, 12> edges;
    for (int i = 0; i <=11; i++)
    {
        edges[i] = getValue();
    }
    return pIBox(new Fake::Box(edges));
}

pICylinder SolidMaker::makeCylinder(uint R, uint H) const
{
    // suppress "unused parameter" warning
    (void) R;
    (void) H;
    std::array<uint, 3> edges;
    for (int i = 0; i <=2; i++)
    {
        edges[i] = getValue();
    }
    return pICylinder(new Fake::Cylinder(edges));
}

pISolid SolidMaker::makeFusion(const Solid& base, const Solid& tool) const
{
    // suppress "unused parameter" warning
    (void) base;
    (void) tool;
    return this->fuseBoxAndCylinderFlush();
}

pISolid SolidMaker::fuseBoxAndCylinderFlush() const
{
    std::array<uint, 14> e;
    for (int i=0; i<=14; i++)
    {
        e[i] = this->getValue();
    }
    return pISolid(new Fake::Solid(
                    {Fake::Face({e[0], e[1], e[2], e[3]}), // front
                    Fake::Face({e[4], e[5], e[6], e[7]}), // back
                    Fake::Face({e[0], e[8], e[9], e[10]}), // left
                    Fake::Face({e[1], e[4], e[11], e[12]}), // right
                    Fake::Face({e[2], e[5], e[8], e[11], e[13]}), // top
                    Fake::Face({e[3], e[6], e[9], e[12], e[14]}), // bottom
                    Fake::Face({e[13], e[14], e[10], e[7]}) //cylinder
                           }));
}

//---------------------------------------------------------------------------
//          private methods
//---------------------------------------------------------------------------

uint SolidMaker::getValue() const{
    EDGE_COUNT++;
    return EDGE_COUNT;
}
