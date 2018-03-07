#ifndef BKAL_ISolidMaker
#define BKAL_ISolidMaker

#include <ISolid.h>
#include <BKALTypes.h>

using BKAL::pIBox;
using BKAL::pICylinder;

namespace BKAL{
    class ISolidMaker
    {
        public:
            virtual ~ISolidMaker() = default;
            // Length = X, Width = Y, Height = Z
            virtual pIBox makeBox(uint L, uint W, uint H) const = 0;
            virtual pICylinder makeCylinder(uint R, uint H) const = 0;
            inline pISolid makeFusion(const pISolid& base, const pISolid& tool) const;

        private:
            virtual pISolid makeFusion_(const pISolid& base, const pISolid& tool) const = 0;
    };

    template <class T>
    class ISolidMaker_ : public ISolidMaker
    {
        public:
            inline pISolid makeFusion_(const pISolid&, const pISolid&) const override;

        private:
            virtual pISolid makeFusion(const T&, const T&) const = 0;


    };

    pISolid ISolidMaker::makeFusion(const pISolid& base, const pISolid& tool) const
    {
        return this->makeFusion_(base, tool);
    }

    template <class T>
    pISolid ISolidMaker_<T>::makeFusion_(const pISolid& base, const pISolid& tool) const
    {
        const T& T_base = dynamic_cast<const T&>(*base);
        const T& T_tool = dynamic_cast<const T&>(*tool);
        // TODO: check return value of dynamic_cast for null?

        return this->makeFusion(T_base, T_tool);
    }
}

#endif /* ifndef BKAL_ISolidMaker */
