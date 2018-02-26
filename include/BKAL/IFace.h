#ifndef IFace_HEADER
#define IFace_HEADER

#include <BKAL/IEdge.h>
#include <BKAL/Types.h>
#include <vector>
#include <memory>

using std::unique_ptr;
using std::vector;

class IFace{
    public:
        inline ~IFace(){};
        inline bool operator==(const IFace& aFace) const;
        inline bool operator!=(const IFace& aFace) const;
        inline const IEdge& getEdge(const GTAL::EdgeIndex index) const;
        inline const vector<unique_ptr<IEdge>>& getEdges() const;

    protected:
        virtual bool checkEquals_(const IFace& aFace) const = 0;
        virtual const vector<unique_ptr<IEdge>>& getEdgeVector() const = 0 ;
};

template <class T>
class IFace_ : public IFace
{
    public:
        ~IFace_(){};
    protected:
        bool checkEquals_(const IFace& aFace) const override;

    private:
        virtual bool operator==(const T& aFace) const = 0 ;
        virtual bool isFlipped(const T& aFace) const = 0;
};

// ----- Definitions for abstract classes must be in the header file -------

bool IFace::operator==(const IFace& aFace) const
{
    return this->checkEquals_(aFace);
}

bool IFace::operator!=(const IFace& aFace) const
{
    return !(this->checkEquals_(aFace));
}

const IEdge& IFace::getEdge(const GTAL::EdgeIndex index) const
{
    return *(this->getEdgeVector()[index.get()]);
}

const vector<unique_ptr<IEdge>>& IFace::getEdges() const{
    return this->getEdgeVector();
}

template <class T>
bool IFace_<T>::checkEquals_(const IFace& aFace) const
{
    const T* other = dynamic_cast<const T*>(&aFace);
    return (other != nullptr) && (static_cast<const T&>(*this) == *other);
}

#endif //IFace_HEADER
