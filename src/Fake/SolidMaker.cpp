#include <BKAL/Fake/SolidMaker.h>
#include <BKAL/Fake/Box.h>
#include <BKAL/Types.h>

#include <array>;

//using Fake::pIEdge;
//using Fake::pIEdges;
//using Fake::PIFace;
//using Fake::PIFaces;
using Fake::pISolid;
using Fake::SolidMaker;

unsigned int MockObjectMaker::EDGE_COUNT;

pISolid SolidMaker::makeBox(uint L, uint W, uint H) const
{
    std::array<uint, 12> edges;
    for (int i = 0; i <=11; i++)
    {
        edges[i] = getValue();;
    }
    return new Fake::Box(edges);
}

//---------------------------------------------------------------------------
//          private methods
//---------------------------------------------------------------------------

uint MockObjectMaker::getValue(){
    EDGE_COUNT++;
    return EDGE_COUNT;
}
