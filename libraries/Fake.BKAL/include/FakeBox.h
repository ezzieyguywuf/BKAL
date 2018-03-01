#ifndef FakeBox_H
#define  FakeBox_H

#include <BKALTypes.h>
#include <IBox.h>
#include <IFace.h>
#include <FakeSolid.h>
#include <array>

using BKAL::pIFace;
using BKAL::IFace;
using BKAL::IBox;

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
