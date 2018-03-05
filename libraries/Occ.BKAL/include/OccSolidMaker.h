#ifndef OccSolidMaker_H
#define OccSolidMaker_H

#include <ISolidMaker.h>
#include <OccSolid.h>

using BKAL::ISolidMaker;
using BKAL::pISolid;

namespace Occ{
    class SolidMaker : public ISolidMaker
    {
        public:
            pIBox makeBox(uint L, uint W, uint H) const override;
            pICylinder makeCylinder(uint R, uint H) const override;
            pISolid makeFusion(const pISolid& base, const pISolid& tool) const override;
    };
}

#endif /* OccSolidMaker_H */
