
#ifndef FakeCylinder_H
#define  FakeCylinder_H

#include <BKAL/Fake/Solid.h>
#include <BKAL/Types.h>
#include <BKAL/ICylinder.h>
#include <BKAL/IFace.h>
#include <array>

using BKAL::pIFace;

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
