#ifndef ISolid_HEADER
#define ISolid_HEADER

#include <BKAL/IFace.h>
#include <BKAL/Types.h>

#include <stdexcept>

using BKAL::pIEdges;
using BKAL::pIFaces;

class ISolid
{
    public:
        virtual inline ~ISolid() = default;
        inline const IEdge& getEdge(unsigned int index) const;
        inline const IFace& getFace(unsigned int index) const;
        inline const pIFaces& getFaces() const;
        inline const pIEdges& getEdges() const;

    private:
        virtual const pIFaces& getFaceVector() const = 0;
        virtual const pIEdges& getEdgeVector() const = 0;
};

const IEdge& ISolid::getEdge(unsigned int index) const
{
    return *(this->getEdges()[index]);
}

const IFace& ISolid::getFace(unsigned int index) const
{
    return *(this->getFaces()[index]);
}

const pIFaces& ISolid::getFaces() const
{
    return this->getFaceVector();
}

const pIEdges& ISolid::getEdges() const
{
    return this->getEdgeVector();
}

#endif //ISolid_HEADER
