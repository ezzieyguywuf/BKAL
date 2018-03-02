#ifndef BKAL_Types_HEADER
#define BKAL_Types_HEADER

//#include "IEdge.h"
//#include "IFace.h"
//#include "ISolid.h"
#include <vector>
#include <memory>
#include <vector>
#include <utility> // for std::pair

namespace BKAL{
    class IEdge;
    class IFace;
    class ISolid;
    class ISolidMaker;
    class IBox;
    class ICylinder;

    typedef std::unique_ptr<IEdge> pIEdge;
    typedef std::vector<pIEdge> pIEdges;
    typedef std::unique_ptr<IFace> pIFace;
    typedef std::vector<pIFace> pIFaces;
    typedef std::unique_ptr<ISolid> pISolid;
    typedef std::unique_ptr<ISolidMaker> pISolidMaker;
    typedef std::unique_ptr<IBox> pIBox;
    typedef std::unique_ptr<ICylinder> pICylinder;
    typedef unsigned int uint;
    typedef std::vector<uint> uints;
    typedef std::vector<std::pair<uint, uint>> vecPair_uint;
    //typedef pISolids = std::vector<std::unique_ptr<ISolid>>;

}
#endif //BKAL_Types_HEADER
