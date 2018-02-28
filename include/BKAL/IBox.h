#ifndef IBOX_H
#define IBOX_H

#include <BKAL/ISolid.h>
#include <BKAL/IFace.h>
#include <BKAL/Types.h>

class IBox : public ISolid
{
    public:
        virtual inline ~IBox() = default;
        virtual const IFace& front() const = 0;
        virtual const IFace& back() const = 0;
        virtual const IFace& left() const = 0;
        virtual const IFace& right() const = 0;
        virtual const IFace& top() const = 0;
        virtual const IFace& bottom() const = 0;
};

#endif /* IBOX_H */
