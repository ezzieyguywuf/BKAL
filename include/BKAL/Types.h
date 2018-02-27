#ifndef BKAL_Types_HEADER
#define BKAL_Types_HEADER

//#include "IEdge.h"
//#include "IFace.h"
//#include "ISolid.h"
#include <vector>
#include <memory>

class IEdge;
class IFace;

namespace BKAL{
    typedef std::unique_ptr<IEdge> pIEdge;
    typedef std::vector<pIEdge> pIEdges;
    typedef std::unique_ptr<IFace> pIFace;
    typedef std::vector<pIFace> pIFaces;
    //typedef pISolid = std::unique_ptr<ISolid>;
    //typedef pISolids = std::vector<std::unique_ptr<ISolid>>;

}
#endif //BKAL_Types_HEADER
