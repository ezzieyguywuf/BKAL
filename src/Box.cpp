#include <BKAL/Box.h>

#include <memory> // for std::move

Box::Box(pISolid aSolid, BoxIndices indices)
    : mySolid(std::move(aSolid)), myIndices(indices)
{}

Box::Box(const Box&& aBox)
{}

const pIFace& Box::front() const
{
    return mySolid->getFaces()[myIndices.front];
}

const pIFace& Box::back() const
{
    return mySolid->getFaces()[myIndices.back];
}

const pIFace& Box::left() const
{
    return mySolid->getFaces()[myIndices.left];
}

const pIFace& Box::right() const
{
    return mySolid->getFaces()[myIndices.right];
}

const pIFace& Box::top() const
{
    return mySolid->getFaces()[myIndices.top];
}

const pIFace& Box::bottom() const
{
    return mySolid->getFaces()[myIndices.bottom];
}
