#include <string>
#include<iostream>
class HasPtr {
public:
    friend void swap(HasPtr&, HasPtr&);
    HasPtr(const std::string& s = std::string());
    HasPtr(const HasPtr& hp);
    HasPtr(HasPtr&& p) noexcept;
    HasPtr& operator=(const HasPtr &rhs);
    HasPtr& operator=(HasPtr&& rhs) noexcept;
    
    ~HasPtr();

private:
    std::string* ps;
    int i;
};

inline void swap(HasPtr& lhs, HasPtr& rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "swap" << std::endl;
}

HasPtr::HasPtr(const std::string& s) : ps(new std::string(s)), i(0)
{
    std::cout << "HasPtr(const std::string& s)" << std::endl;
}

HasPtr::HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i)
{
    std::cout << "HasPtr(const HasPtr& hp)" << std::endl;
}

HasPtr::HasPtr(HasPtr&& p) noexcept : ps(p.ps), i(p.i)
{
    p.ps = nullptr;
    std::cout << "HasPtr(HasPtr&& p)" << std::endl;
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    std::string* newptr = new std::string(*rhs.ps);
    delete ps;
    ps = newptr;
    i = rhs.i;
    return *this;
}

HasPtr& HasPtr::operator=(HasPtr&& rhs)
{
    if (this != &rhs) {
        delete ps;
        ps = rhs.ps;
        i = rhs.i;
        rhs.ps = nullptr;
        
    }
    return *this;
}

HasPtr::~HasPtr()
{
    std::cout << "call destructor" << std::endl;
    delete ps;
}