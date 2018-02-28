#ifndef FakeBox_H
#define  FakeBox_H

#include <BKAL/Fake/Solid.h>
#include <BKAL/Types.h>
#include <BKAL/IBox.h>
#include <BKAL/IFace.h>
#include <array>

using BKAL::pIFace;

namespace Fake{
    class Box : public Solid , public IBox
    {
        public:
            Box(std::array<uint, 12> edges);
            ~Box(){};

            const pIFaces& getFaceVector() const override;
            const pIEdges& getEdgeVector() const override;

            const IFace& front() const override;
            const IFace& back() const override;
            const IFace& left() const override;
            const IFace& right() const override;
            const IFace& top() const override;
            const IFace& bottom() const override;
    };
}

#endif /*  FakeBox_H */
