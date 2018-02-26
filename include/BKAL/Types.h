#ifndef BKAL_Types_HEADER
#define BKAL_Types_HEADER

//#include "IEdge.h"
//#include "IFace.h"
//#include "ISolid.h"
#include <vector>
#include <memory>

class IEdge;
class IFace;

namespace BKAL{
    typedef std::unique_ptr<IEdge> pIEdge;
    typedef std::vector<pIEdge> pIEdges;
    typedef std::unique_ptr<IFace> pIFace;
    typedef std::vector<pIFace> pIFaces;
    //typedef pISolid = std::unique_ptr<ISolid>;
    //typedef pISolids = std::vector<std::unique_ptr<ISolid>>;

    class Index{
        public:
            inline Index();
            inline Index(const Index& anIndex);
            inline Index(unsigned int anIndex);
            inline virtual ~Index() = 0;
            inline Index& operator=(const Index& anIndex);
            inline unsigned int get() const;
            inline bool isValid() const;
            inline bool operator <(const Index& anIndex) const;
            inline bool operator >(const Index& anIndex) const;
            inline bool operator ==(const Index& anIndex) const;
            inline bool operator !=(const Index& anIndex) const;

        protected:
            unsigned int index;
            bool valid;
    };

    class FaceIndex : public Index{
        public:
            inline FaceIndex();
            inline FaceIndex(const FaceIndex& aFaceIndex);
            inline FaceIndex(unsigned int anIndex);
            inline ~FaceIndex();
            inline FaceIndex operator=(const FaceIndex& aFaceIndex);
    };
    class EdgeIndex : public Index{
        public:
            inline EdgeIndex();
            inline EdgeIndex(const EdgeIndex& aEdgeIndex);
            inline EdgeIndex(unsigned int anIndex);
            inline ~EdgeIndex();
            inline EdgeIndex operator=(const EdgeIndex& aEdgeIndex);
    };

}
// ------------- Must define methods in pure virtual class in header ------------

using BKAL::Index;
using BKAL::FaceIndex;
using BKAL::EdgeIndex;

Index::Index()
    : valid(false){};

Index::Index(const Index& anIndex)
    : index(anIndex.index), valid(anIndex.valid)
{}
Index::Index(unsigned int anIndex)
    : index(anIndex), valid(true)
{}

Index::~Index(){}

Index& Index::operator=(const Index& anIndex)
{
    this->valid = anIndex.valid;
    this->index = anIndex.index;
    return *this;
}

unsigned int Index::get() const
{
    if (not this->isValid())
        throw std::runtime_error("Index is not valid");
    return this->index;
}

bool Index::isValid() const
{
    return this->valid;
}

bool Index::operator<(const Index& anIndex) const
{
    if (not this->isValid())
        throw std::runtime_error("Index is not valid");
    return this->index < anIndex.get();
}

bool Index::operator>(const Index& anIndex) const
{
    if (not this->isValid())
        throw std::runtime_error("Index is not valid");
    return this->index > anIndex.get();
}

bool Index::operator==(const Index& anIndex) const
{
    if (not valid)
        throw std::runtime_error("Index is not valid");
    return this->index == anIndex.get();
}

bool Index::operator!=(const Index& anIndex) const
{
    if (not valid)
        throw std::runtime_error("Index is not valid");
    return this->index != anIndex.get();
}


FaceIndex::FaceIndex()
    : Index()
{}

FaceIndex::FaceIndex(const FaceIndex& aFaceIndex)
    : Index(aFaceIndex)
{}

FaceIndex::FaceIndex(unsigned int anIndex)
    : Index(anIndex)
{}

FaceIndex::~FaceIndex()
{}

FaceIndex FaceIndex::operator=(const FaceIndex& aFaceIndex)
{
    Index::operator=(aFaceIndex);
    return *this;
}

EdgeIndex::EdgeIndex()
    : Index()
{}

EdgeIndex::EdgeIndex(const EdgeIndex& aEdgeIndex)
    : Index(aEdgeIndex)
{}

EdgeIndex::EdgeIndex(unsigned int anIndex)
    : Index(anIndex)
{}

EdgeIndex::~EdgeIndex()
{}

EdgeIndex EdgeIndex::operator=(const EdgeIndex& aEdgeIndex)
{
    Index::operator=(aEdgeIndex);
    return *this;
}

#endif //BKAL_Types_HEADER
