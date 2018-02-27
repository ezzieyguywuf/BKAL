#ifndef FakeBox_H
#define  FakeBox_H

#include <BKAL/Fake/Solid.h>
#include <BKAL/Types.h>
#include <array>

namespace Fake{
    class Box : public Solid
    {
        public:
            Box(std::array<uint, 12> edges);

            const pIFace& front() const;
            const pIFace& back() const;
            const pIFace& left() const;
            const pIFace& right() const;
            const pIFace& top() const;
            const pIFace& bottom() const;
    };
}

#endif /*  FakeBox_H */
