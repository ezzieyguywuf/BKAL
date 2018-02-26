#ifndef FakeFace_HEADER
#define FakeFace_HEADER

#include <BKAL/IFace.h>
#include <BKAL/IEdge.h>
#include <BKAL/Fake/Edge.h>
#include <vector>
#include <memory>

using std::vector;
using std::unique_ptr;

namespace Fake{
    class Face : public IFace_<Face>
    {
        public:
            Face(int myValue, vector<Mock::Edge> edges);
            Face (const Face& aFace);
            Face (Face&& aFace);
            Face operator=(const Face& aFace);
            Face operator=(Face&& aFace);
            ~Face(){};

            // overrides from IFace_
            bool operator==(const Face& aFace) const override;
            bool isFlipped(const Face& aFace) const override;
            const vector<unique_ptr<IEdge>>& getEdgeVector() const override;

            // unique to Mock::Face
            int getValue() const;
            void changeEdge(int index, const Mock::Edge& newEdge);
            void changeEdge(int index, const unique_ptr<IEdge>& newEdge);
            Mock::Edge getEdge(int index);
        private:
            int myValue;
            vector<unique_ptr<IEdge>> myEdges;
    };
};
#endif //FakeFace_HEADER
