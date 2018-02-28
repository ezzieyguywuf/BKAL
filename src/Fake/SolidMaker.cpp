#include <BKAL/Fake/SolidMaker.h>
#include <BKAL/Fake/Box.h>
#include <BKAL/Types.h>

#include <array>

//using Fake::pIEdge;
//using Fake::pIEdges;
//using Fake::PIFace;
//using Fake::PIFaces;
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

//---------------------------------------------------------------------------
//          private methods
//---------------------------------------------------------------------------

uint SolidMaker::getValue() const{
    EDGE_COUNT++;
    return EDGE_COUNT;
}
