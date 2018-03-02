#ifndef IFace_HEADER
#define IFace_HEADER

#include <IEdge.h>
#include <BKALTypes.h>
#include <memory>

using BKAL::pIEdge;
using BKAL::pIEdges;

namespace BKAL
{
    class IFace
    {
        public:
            inline ~IFace(){};
            inline bool operator==(const IFace& aFace) const;
            inline bool operator!=(const IFace& aFace) const;
            inline bool sharesEdge(const IFace& aFace) const;
            inline const pIEdges& getEdges() const;

        protected:
            virtual bool checkEquals_(const IFace& aFace) const = 0;
            virtual const pIEdges& getEdgeVector() const = 0 ;
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

    bool IFace::sharesEdge(const IFace& aFace) const
    {
        for (const auto& myEdge : this->getEdges()){
            for (const auto& checkEdge : aFace.getEdges()){
                if (myEdge->isFlipped(*checkEdge)){
                    return true;
                }
            }
        }
        return false;
    }


    const pIEdges& IFace::getEdges() const{
        return this->getEdgeVector();
    }

    template <class T>
    bool IFace_<T>::checkEquals_(const IFace& aFace) const
    {
        const T* other = dynamic_cast<const T*>(&aFace);
        return (other != nullptr) && (static_cast<const T&>(*this) == *other);
    }
}

#endif //IFace_HEADER
