#include <BKAL/Fake/Box.h>

using Fake::Box;

Box::Box(std::array<uint, 12> edges)
    : Fake::Solid({
            Fake::Face({edges[0],edges[1],edges[2],edges[3]}),
            Fake::Face({edges[4],edges[5],edges[6],edges[7]}),
            Fake::Face({edges[0],edges[4],edges[8],edges[9]}),
            Fake::Face({edges[1],edges[5],edges[10],edges[11]}),
            Fake::Face({edges[2],edges[6],edges[8],edges[10]}),
            Fake::Face({edges[3],edges[7],edges[9],edges[11]})
            })
{
}

const pIFaces& Box::getFaceVector() const 
{
    return Fake::Solid::getFaceVector();
}
const pIEdges& Box::getEdgeVector() const
{
    return Fake::Solid::getEdgeVector();
}

const IFace& Box::front() const
{
    return *(this->myFaces[0]);
}

const IFace& Box::back() const
{
    return *(this->myFaces[1]);
}

const IFace& Box::left() const
{
    return *(this->myFaces[2]);
}

const IFace& Box::right() const
{
    return *(this->myFaces[3]);
}

const IFace& Box::top() const
{
    return *(this->myFaces[4]);
}


const IFace& Box::bottom() const
{
    return *(this->myFaces[5]);
}
