#include <BKAL/Fake/SolidMaker.h>
#include <BKAL/Fake/Box.h>
#include <BKAL/Types.h>
#include <array>

#include <memory>
#include <iostream>

using BKAL::uint;
using BKAL::pIBox;

int main(void)
{
    std::array<uint, 12> edges;
    for (int i = 0; i <=11; i++)
    {
        edges[i] = i;
    }
    //Fake::Box* aBox = new Fake::Box(edges);
    //
    Fake::Box* myBox = new Fake::Box(edges);
    myBox->front();

    const IBox& aBox = *myBox;
    aBox.top();

    std::unique_ptr<IBox> pBox(new Fake::Box(edges));
    //IBox* pBox = new Fake::Box(edges);
    std::cout << "Hello wolf!" << std::endl;

    return 0;
}
