#ifndef OCCSolid_H
#define OCCSolid_H

#include <ISolid.h>
#include <TopoDS_Compound.hxx>
#include <TopoDS_CompSolid.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_Shape.hxx>
#include <BKALTypes.h>

using BKAL::pIEdges;
using BKAL::pIFaces;

namespace Occ{
class Solid : public virtual BKAL::ISolid
    {
        public:
            // rule of 5
            Solid(const Solid& aSolid);
            Solid(Solid&& aSolid);
            Solid operator=(const Solid& aSolid);
            Solid operator=(Solid&& aSolid);
            ~Solid() = default;

            // other constructors
            Solid(const TopoDS_Solid& aSolid);
            Solid(const TopoDS_CompSolid& aSolid);
            Solid(const TopoDS_Compound& aSolid);

            const pIEdges& getEdgeVector() const override;
            const pIFaces& getFaceVector() const override;
            const TopoDS_Shape& getSolid() const;

        protected:
            void processSolid();
            TopoDS_Shape mySolid;
            pIEdges myEdges;
            pIFaces myFaces;
    };
}

#endif /* OCCSolid_H */
