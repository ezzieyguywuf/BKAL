#ifndef OccCylinder_H
#define  OccCylinder_H

#include <BKALTypes.h>
#include <ICylinder.h>
#include <IFace.h>
#include <OccSolid.h>
#include <BRepPrimAPI_MakeCylinder.hxx>
#include <array>
#include <map>
#include <string>

using BKAL::pIFace;
using BKAL::IFace;
using BKAL::ICylinder;

namespace Occ{
    class Cylinder : virtual public Solid, public ICylinder
    {
        public:
            Cylinder(BRepPrimAPI_MakeCylinder mkCylinder);

            const pIFaces& getFaceVector() const override;
            const pIEdges& getEdgeVector() const override;

            const IFace& lateral() const override;
            const IFace& top() const override;
            const IFace& bottom() const override;
        private:
            BRepPrimAPI_MakeCylinder myMakeCylinder;
            std::map<std::string, int> myIndices;
    };
}

#endif /*  OccCylinder_H */
