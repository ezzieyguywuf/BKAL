#ifndef ICylinder_H
#define ICylinder_H

#include <BKAL/ISolid.h>
#include <BKAL/IFace.h>
#include <BKAL/Types.h>

class ICylinder : public ISolid
{
    public:
        virtual inline ~ICylinder() = default;
        virtual const IFace& lateral() const = 0;
        virtual const IFace& top() const = 0;
        virtual const IFace& bottom() const = 0;
};

#endif /* ICylinder_H */
