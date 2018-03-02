#ifndef OccBox_H
#define  OccBox_H

#include <BKALTypes.h>
#include <IBox.h>
#include <IFace.h>
#include <OccSolid.h>
#include <BRepPrimAPI_MakeBox.hxx>
#include <array>
#include <map>
#include <string>

using BKAL::pIFace;
using BKAL::IFace;
using BKAL::IBox;

namespace Occ{
    class Box : public Solid , public IBox
    {
        public:
            Box(BRepPrimAPI_MakeBox mkBox);
            ~Box(){};

            const pIFaces& getFaceVector() const override;
            const pIEdges& getEdgeVector() const override;

            const IFace& front() const override;
            const IFace& back() const override;
            const IFace& left() const override;
            const IFace& right() const override;
            const IFace& top() const override;
            const IFace& bottom() const override;
        private:
            BRepPrimAPI_MakeBox myMakeBox;
            std::map<std::string, int> myIndices;
    };
}

#endif /*  OccBox_H */
