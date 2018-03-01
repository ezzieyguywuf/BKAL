
#ifndef FakeCylinder_H
#define  FakeCylinder_H

#include <BKALTypes.h>
#include <ICylinder.h>
#include <IFace.h>
#include <FakeSolid.h>
#include <array>

using BKAL::pIFace;
using BKAL::ICylinder;
using BKAL::IFace;

namespace Fake{
    class Cylinder : public Solid , public ICylinder
    {
        public:
            Cylinder(std::array<uint, 3> edges);
            ~Cylinder(){};

            const pIFaces& getFaceVector() const override;
            const pIEdges& getEdgeVector() const override;

            const IFace& lateral() const override;
            const IFace& top() const override;
            const IFace& bottom() const override;
    };
}

#endif /*  FakeCylinder_H */
