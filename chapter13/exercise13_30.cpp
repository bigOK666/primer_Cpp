#include<string>
#include<iostream>

class HasPtr {
	friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const std::string& s = std::string()) :ps(new std::string(s)), i(0) {}

	HasPtr(const HasPtr& original);
	HasPtr& operator =(const HasPtr&);
	~HasPtr() { delete ps; }//指针和引用不会隐式调用析构函数
private:
	std::string* ps;
	int i;
};

HasPtr::HasPtr(const HasPtr& original) :
	ps(new std::string((*original.ps))),
	i(original.i)
{}

HasPtr& HasPtr::operator=(const HasPtr& original)
{
	//这样能满足自身赋值给自身
	auto copy = new std::string(*original.ps);
	delete ps;
	ps = copy;
	i = original.i;
	return *this;
}

void swap(HasPtr& a, HasPtr& b)
{
	using std::swap;

	swap(a.ps, b.ps);
	swap(a.i, b.i);

	std::cout << "swap for HasPtr" << std::endl;

}

int main()
{
	HasPtr test1("test1"), test2("test2");

	std::swap(test1, test2);
	swap(test1, test2);
}