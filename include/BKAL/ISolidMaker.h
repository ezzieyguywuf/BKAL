#ifndef BKAL_ISolidMaker
#define BKAL_ISolidMaker

#include <BKAL/ISolid.h>
#include <BKAL/Types.h>

class ISolidMaker{
    ~ISolid pIMaker(){};
    // Length = X, Width = Y, Height = Z
    virtual pISolid makeBox(uint L, uint W, uint H) const = 0;
}

#endif /* ifndef BKAL_ISolidMaker */
