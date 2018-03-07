#ifndef OccSolidMaker_H
#define OccSolidMaker_H

#include <ISolidMaker.h>
#include <OccSolid.h>

using BKAL::pISolid;

namespace Occ{
    class SolidMaker : public BKAL::ISolidMaker_<Solid>
    {
        public:
            pIBox makeBox(double L, double W, double H) const override;
            pICylinder makeCylinder(double R, double H) const override;
            pISolid makeFusion(const Solid& base, const Solid& tool) const;
    };
}

#endif /* OccSolidMaker_H */
