#ifndef OCCSolid_H
#define OCCSolid_H

#include <ISolid.h>
#include <TopoDS_Solid.hxx>
#include <BKALTypes.h>

using BKAL::pIEdges;
using BKAL::pIFaces;

namespace Occ{
class Solid : public BKAL::ISolid
    {
        public:
            Solid(const TopoDS_Solid& aSolid);
            const pIEdges& getEdgeVector() const override;
            const pIFaces& getFaceVector() const override;
            const TopoDS_Solid& getSolid() const;

        protected:
            TopoDS_Solid mySolid;
            pIEdges myEdges;
            pIFaces myFaces;
    };
}

#endif /* OCCSolid_H */
