#ifndef ISolid_HEADER
#define ISolid_HEADER

#include <IFace.h>
#include <Types.h>

#include <stdexcept>

using BKAL::pIEdges;
using BKAL::pIFaces;

namespace BKAL{
    class ISolid
    {
        public:
            virtual inline ~ISolid() = default;
            inline const pIFaces& getFaces() const;
            inline const pIEdges& getEdges() const;

        private:
            virtual const pIFaces& getFaceVector() const = 0;
            virtual const pIEdges& getEdgeVector() const = 0;
    };

    const pIFaces& ISolid::getFaces() const
    {
        return this->getFaceVector();
    }

    const pIEdges& ISolid::getEdges() const
    {
        return this->getEdgeVector();
    }
}

#endif //ISolid_HEADER
