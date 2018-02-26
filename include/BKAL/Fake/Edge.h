#ifndef FakeEdge_HEADER
#define FakeEdge_HEADER

#include <BKAL/IEdge.h>

namespace Fake{
    // An implementation of the IEdge interface. Notice that we inherit from IEdge_
    // instead of IEdge directly. This is because IEdge_ contains some basic,
    // 'boilerplate' that any descendent of IEdge must have, therefore it has been put in
    // one common location.
    class Edge : public IEdge_<Edge>
    {
        public:
            Edge(int val);
            Edge(const Edge& anEdge);
            Edge(Edge&& anEdge);
            Edge operator=(const Edge& anEdge);
            Edge operator=(Edge&& anEdge);
            ~Edge(){};

            bool operator==(const Edge& anEdge) const override;
            bool isFlipped(const Edge& anEdge) const override;

            int getVal() const;
        private:
            int val;
    };
};

#endif //FakeEdge_HEADER
