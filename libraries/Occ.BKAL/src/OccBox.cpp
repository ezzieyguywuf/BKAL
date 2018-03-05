#include <OccBox.h>
#include <OccFace.h>
#include <TopoDS.hxx>

using Occ::Face;
using Occ::Box;
using Occ::Solid;

Box::Box(BRepPrimAPI_MakeBox mkBox)
    : Solid(TopoDS::Solid(mkBox.Shape())), myMakeBox(mkBox)
{
    pIFace front(new Face(mkBox.FrontFace()));
    pIFace back(new Face(mkBox.BackFace()));
    pIFace left(new Face(mkBox.LeftFace()));
    pIFace right(new Face(mkBox.RightFace()));
    pIFace top(new Face(mkBox.TopFace()));
    pIFace bottom(new Face(mkBox.BottomFace()));
    int i = 0;
    for(const pIFace& aFace : this->getFaceVector()){
        if(*aFace == *front){
            myIndices["front"] = i;
        }
        else if(*aFace == *back){
            myIndices["back"] = i;
        }
        else if(*aFace == *left){
            myIndices["left"] = i;
        }
        else if(*aFace == *right){
            myIndices["right"] = i;
        }
        else if(*aFace == *top){
            myIndices["top"] = i;
        }
        else if(*aFace == *bottom){
            myIndices["bottom"] = i;
        }
        i++;
    }
}

const pIFaces& Box::getFaceVector() const 
{
    return Solid::getFaceVector();
}
const pIEdges& Box::getEdgeVector() const
{
    return Solid::getEdgeVector();
}


const IFace& Box::front() const
{
    return *(this->myFaces[myIndices.at("front")]);
}

const IFace& Box::back() const
{
    return *(this->myFaces[myIndices.at("back")]);
}

const IFace& Box::left() const
{
    return *(this->myFaces[myIndices.at("left")]);
}

const IFace& Box::right() const
{
    return *(this->myFaces[myIndices.at("right")]);
}

const IFace& Box::top() const
{
    return *(this->myFaces[myIndices.at("top")]);
}


const IFace& Box::bottom() const
{
    return *(this->myFaces[myIndices.at("bottom")]);
}
