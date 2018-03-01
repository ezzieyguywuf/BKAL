#ifndef FakeSolidMaker_H
#define FakeSolidMaker_H

#include <ISolidMaker.h>

using BKAL::ISolidMaker;

namespace Fake{
    class SolidMaker : public ISolidMaker
    {
        public:
            pIBox makeBox(uint L, uint W, uint H) const override;
            pICylinder makeCylinder(uint R, uint H) const override;

        private:
            // creates a unique value for each Face, Edge, etc.
            uint getValue() const;

            static uint EDGE_COUNT;
    };
}

#endif /* FakeSolidMaker_H */
