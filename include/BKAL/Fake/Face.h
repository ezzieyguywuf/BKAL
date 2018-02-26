#ifndef FakeFace_HEADER
#define FakeFace_HEADER

#include <BKAL/IFace.h>
#include <BKAL/IEdge.h>
#include <BKAL/Fake/Edge.h>
#include <BKAL/Types.h>
#include <vector>
#include <memory>

using std::vector;
using std::unique_ptr;
using BKAL::pIEdges;
using BKAL::pIEdge;

namespace Fake{
    class Face : public IFace_<Face>
    {
        public:
            Face(pIEdges edges);
            Face (const Face& aFace);
            Face (Face&& aFace);
            Face operator=(const Face& aFace);
            Face operator=(Face&& aFace);
            ~Face(){};

            // overrides from IFace_
            bool operator==(const Face& aFace) const override;
            bool isFlipped(const Face& aFace) const override;
            const pIEdges& getEdgeVector() const override;

            // unique to Fake::Face
            void changeEdge(int index, const Edge& newEdge);
            void changeEdge(int index, const pIEdge& newEdge);
            Edge getEdge(int index);
        private:
            pIEdges myEdges;
    };
};
#endif //FakeFace_HEADER
