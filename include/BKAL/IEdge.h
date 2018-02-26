#ifndef IEdge_HEADER
#define IEdge_HEADER

class IEdge
{
    // This class uses the 'template method pattern'.
    // (this)[http:://www.gotw.ca/publications/mill18.htm] article does a good job
    // explaining this pattern and why it is a good idea to use.
    public:
        inline IEdge(){};
        inline ~IEdge(){};

        inline bool operator==(const IEdge& anEdge) const;
        inline bool operator!=(const IEdge& anEdge) const;
        inline bool isFlipped(const IEdge& anEdge) const;
        
    protected:
        virtual bool checkEquality_(const IEdge& anEdge) const = 0;
        virtual bool checkFlipped_(const IEdge& anEdge) const = 0;
};

template <class T>
class IEdge_ : public IEdge
{               
    public:
        ~IEdge_(){};
    // This class uses the 'curiously recurring template pattern' in order to allow
    // IEdge to be used by client without having to be aware of implementation T
    protected:
        bool checkEquality_(const IEdge& anEdge) const;
        bool checkFlipped_(const IEdge& anEdge) const;

    private:
        virtual bool operator==(const T& t) const = 0;
        virtual bool isFlipped(const T& t) const = 0;
};

// ----- Definitions for abstract classes must be in the header file -------

bool IEdge::operator==(const IEdge& anEdge) const
{
    return this->checkEquality_(anEdge);
}

bool IEdge::operator!=(const IEdge& anEdge) const
{
    return !(this->checkEquality_(anEdge));
}

bool IEdge::isFlipped(const IEdge& anEdge) const
{
    return this->checkFlipped_(anEdge);
}

template <class T>
bool IEdge_<T>::checkEquality_(const IEdge& anEdge) const
{
    const T* other = dynamic_cast<const T*>(&anEdge);
    // if check1 == false then anEdge is not a T
    //bool check1 = (other != nullptr);
    // if check2 == false then although other IS a T, it does not == this
    //bool check2 = (static_cast<const T&>(*this) == *other)
    return (other != nullptr) && (*(static_cast<const T*>(this)) == *other);
}

template <class T>
bool IEdge_<T>::checkFlipped_(const IEdge& anEdge) const
{
    const T* other = dynamic_cast<const T*>(&anEdge);
    return (other != nullptr) && (static_cast<const T*>(this)->isFlipped(*other));
}
#endif //IEdge_HEADER
