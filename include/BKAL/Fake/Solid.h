#ifndef FakeSolid_HEADER
#define FakeSolid_HEADER

#include <BKAL/ISolid.h>
#include <BKAL/IFace.h>
#include <BKAL/Fake/Face.h>
#include <BKAL/Types.h>

#include <vector>

using std::vector;
using BKAL::pIFace;
using BKAL::pIFaces;
using BKAL::pIEdge;
using BKAL::pIEdges;

namespace Fake{
    class Solid : public ISolid
    {
        public:
            Solid(pIFaces faces);
            Solid(const Solid& aSolid);
            Solid(Solid&& aSolid);
            Solid operator=(const Solid& aSolid);
            Solid operator=(Solid&& aSolid);
            ~Solid(){};

            const pIFaces& getFaceVector() const override;
            const pIEdges& getEdgeVector() const override;

            const pIFace& getFace(int which) const;

        private:
            bool checkEdge(const pIEdge& anEdge) const;
            void addEdges(const pIEdges& edges);
            void addFace(const Face& aFace);
            pIFaces myFaces;
            pIEdges myEdges;
            vector<unsigned int> myEdgeVals;
    };
}

#endif //FakeSolid_HEADER
