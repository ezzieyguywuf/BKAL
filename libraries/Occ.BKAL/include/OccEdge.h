#ifndef OCCEDGE_H
#define OCCEDGE_H

#include <IEdge.h>
#include <TopoDS_Edge.hxx>

namespace Occ{
class Edge : public BKAL::IEdge_<Edge>
    {
        public:
            Edge(TopoDS_Edge anEdge);
            bool operator==(const Edge& anEdge) const override;
            bool isFlipped(const Edge& anEdge) const override;
            const TopoDS_Edge& getEdge() const;

        private:
            TopoDS_Edge myEdge;
    };
}

#endif /* OCCEDGE_H */
