#ifndef IBOX_H
#define IBOX_H

#include <ISolid.h>
#include <IFace.h>
#include <BKALTypes.h>

namespace BKAL{
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
}
#endif /* IBOX_H */
