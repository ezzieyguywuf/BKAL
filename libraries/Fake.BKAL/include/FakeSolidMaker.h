#ifndef FakeSolidMaker_H
#define FakeSolidMaker_H

#include <ISolidMaker.h>
#include <FakeSolid.h>

using BKAL::pISolid;

namespace Fake{
    class SolidMaker : public BKAL::ISolidMaker_<Solid>
    {
        public:
            pIBox makeBox(double L, double W, double H) const override;
            pICylinder makeCylinder(double R, double H) const override;
            pISolid makeFusion(const Solid& base, const Solid& tool) const override;

            pISolid fuseBoxAndCylinderFlush() const;

        private:
            // creates a unique value for each Face, Edge, etc.
            uint getValue() const;

            static uint EDGE_COUNT;
    };
}

#endif /* FakeSolidMaker_H */
