#ifndef BKAL_ISolidMaker
#define BKAL_ISolidMaker

#include <ISolid.h>
#include <BKALTypes.h>

using BKAL::pIBox;
using BKAL::pICylinder;

namespace BKAL{
    class ISolidMaker
    {
        public:
            ~ISolidMaker(){};
            // Length = X, Width = Y, Height = Z
            virtual pIBox makeBox(uint L, uint W, uint H) const = 0;
            virtual pICylinder makeCylinder(uint R, uint H) const = 0;
            virtual pISolid makeFusion(const pISolid& base, const pISolid& tool) const = 0;
    };
}

#endif /* ifndef BKAL_ISolidMaker */
