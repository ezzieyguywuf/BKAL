#ifndef BKAL_ISolidMaker
#define BKAL_ISolidMaker

#include <BKAL/ISolid.h>
#include <BKAL/Types.h>

using BKAL::pIBox;
using BKAL::pICylinder;

class ISolidMaker{
    public:
        ~ISolidMaker(){};
        // Length = X, Width = Y, Height = Z
        virtual pIBox makeBox(uint L, uint W, uint H) const = 0;
        virtual pICylinder makeCylinder(uint R, uint H) const = 0;
};

#endif /* ifndef BKAL_ISolidMaker */
