#include <memory>
#include <vector>
#include <iostream>

class Base;
typedef std::unique_ptr<Base> uBase;
typedef std::vector<uBase> vuBase;

class Base{
    public:
        virtual ~Base() = default;
        virtual int getVal() const = 0;
};

class Child : public Base{
    public:
        Child(int i);
        int getVal() const override;

    private:
        int myVal;
};

class Container{
    public:
        Container();
        const vuBase& getVector() const;
    protected:
        vuBase myBases;
};

class ContainerChild : Container
{
    public:
        const Base& getValue(int i) const;
};

int main(void)
{
    ContainerChild myChild;
    const Child& aChild = static_cast<const Child&>(myChild.getValue(1));
    std::cout << "myChild.getValue(1) = " << aChild.getVal() << std::endl;
    return 0;
}

Child::Child(int i)
    : myVal(i)
{}

int Child::getVal() const
{
    return myVal;
}

Container::Container(){
    myBases.push_back(uBase(new Child(0)));
    myBases.push_back(uBase(new Child(1)));
    myBases.push_back(uBase(new Child(2)));
}

const Base& ContainerChild::getValue(int i) const
{
    return *(this->myBases[i]);
}
