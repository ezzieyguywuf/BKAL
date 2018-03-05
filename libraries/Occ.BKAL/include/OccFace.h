#ifndef OCCFace_H
#define OCCFace_H

#include <IFace.h>
#include <TopoDS_Face.hxx>
#include <BKALTypes.h>

using BKAL::pIEdges;

namespace Occ{
class Face : public BKAL::IFace_<Face>
    {
        public:
            Face(const TopoDS_Face& aFace);
            bool operator==(const Face& aFace) const override;
            bool isFlipped(const Face& aFace) const override;
            const pIEdges& getEdgeVector() const override;
            const TopoDS_Face& getFace() const;

        private:
            TopoDS_Face myFace;
            pIEdges myEdges;
    };
}

#endif /* OCCFace_H */
