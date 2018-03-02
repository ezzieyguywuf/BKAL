#ifndef FakeSolidMaker_H
#define FakeSolidMaker_H

#include <ISolidMaker.h>
#include <FakeSolid.h>

using BKAL::ISolidMaker;
using BKAL::pISolid;

namespace Fake{
    class SolidMaker : public ISolidMaker
    {
        public:
            pIBox makeBox(uint L, uint W, uint H) const override;
            pICylinder makeCylinder(uint R, uint H) const override;
            pISolid makeFusion(const pISolid& base, const pISolid& tool) const override;

            pISolid fuseBoxAndCylinderFlush() const;

        private:
            // creates a unique value for each Face, Edge, etc.
            uint getValue() const;

            static uint EDGE_COUNT;
    };
}

#endif /* FakeSolidMaker_H */
