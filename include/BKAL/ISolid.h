#ifndef ISolid_HEADER
#define ISolid_HEADER

#include <BKAL/IFace.h>
#include <BKAL/Types.h>

#include <vector>
#include <memory>
#include <stdexcept>

using std::vector;
using std::unique_ptr;

class ISolid
{
    public:
        inline ~ISolid(){};
        inline const IEdge& getEdge(unsigned int index) const;
        inline const IFace& getFace(unsigned int index) const;
        inline const vector<unique_ptr<IFace>>& getFaces() const;
        inline const vector<unique_ptr<IEdge>>& getEdges() const;
        // TODO: will this method get confused with ISolidManager::getIndex? should this
        // return an unsigned int instead so that the user has to manually create the
        // BKAL::FaceIndex and in so doing hopefully prevent disaster?
        inline const BKAL::FaceIndex getIndex(const IFace& anIFace) const;

    private:
        virtual const vector<unique_ptr<IFace>>& getFaceVector() const = 0;
        virtual const vector<unique_ptr<IEdge>>& getEdgeVector() const = 0;
};

const IEdge& ISolid::getEdge(unsigned int index) const
{
    return *(this->getEdges()[index]);
}

const IFace& ISolid::getFace(unsigned int index) const
{
    return *(this->getFaces()[index]);
}

const vector<unique_ptr<IFace>>& ISolid::getFaces() const
{
    return this->getFaceVector();
}

const vector<unique_ptr<IEdge>>& ISolid::getEdges() const
{
    return this->getEdgeVector();
}

const BKAL::FaceIndex ISolid::getIndex(const IFace& anIFace) const
{
    unsigned int i = 0;
    for (const auto& checkFace : this->getFaces())
    {
        if (*checkFace == anIFace)
        {
            return BKAL::FaceIndex(i);
        }
        i += 1;
    }
    throw std::runtime_error("Was unable to find that face is the solid");
}

#endif //ISolid_HEADER
