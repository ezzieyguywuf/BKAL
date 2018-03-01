#include <FakeCylinder.h>

using Fake::Cylinder;

Cylinder::Cylinder(std::array<uint, 3> edges)
    : Fake::Solid({
            Fake::Face({edges[0],edges[1],edges[2]}),
            Fake::Face(vector<uint>({edges[1]})),
            Fake::Face(vector<uint>({edges[2]}))
            })
{
}

const pIFaces& Cylinder::getFaceVector() const 
{
    return Fake::Solid::getFaceVector();
}
const pIEdges& Cylinder::getEdgeVector() const
{
    return Fake::Solid::getEdgeVector();
}

const IFace& Cylinder::lateral() const
{
    return *(this->myFaces[0]);
}

const IFace& Cylinder::top() const
{
    return *(this->myFaces[1]);
}


const IFace& Cylinder::bottom() const
{
    return *(this->myFaces[2]);
}
