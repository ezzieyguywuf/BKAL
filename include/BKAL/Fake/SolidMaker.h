#ifndef FakeSolidMaker_H
#define FakeSolidMaker_H

#include <BKAL/ISolidMaker.h>
#include <BKAL/Types.h>

namespace Fake{
    class SolidMaker : public ISolidMaker
    {
        public:
            pISolid makeBox(uint L, uint W, uint H) const override;

        private:
            // creates a unique value for each Face, Edge, etc.
            uint getValue() const;

            static uint EDGE_COUNT;
    };
}

#endif /* FakeSolidMaker_H */
