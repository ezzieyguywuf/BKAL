#ifndef BKAL_Box_H
#define BKAL_Box_H

#include <BKAL/Types.h>

struct BoxIndices;

template<class T>
class Box
{
    public:
        Box(pISolid aSolid, BoxIndices indices);
        Box(const Box& aBox);
        Box(const Box&& aBox);
        operator=(const Box& aBox);
        operator=(Box&& aBox);
        ~Box(){};

        inline const pIFace& front() const;
        inline const pIFace& back() const;
        inline const pIFace& left() const;
        inline const pIFace& right() const;
        inline const pIFace& top() const;
        inline const pIFace& bottom() const;

    private:
        pISolid mySolid;
        BoxIndices myIndices;
};

struct BoxIndices{
    friend class Box;
    BoxIndices(uint f, uint b, uint l, uint r, uint t, uint bot)
        : front(f), back(b), left(l), right(r), top(t), bottom(bot){};
    private:
        uint front, back, left, right, top, bottom;
}

#endif /* BKAL_Box_H */
