#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

class HasPtr {
	friend void swap(HasPtr&, HasPtr&);
	friend bool operator<(const HasPtr& lhs, const HasPtr& rhs);
public:
	HasPtr(const std::string& s = std::string()) :ps(new std::string(s)), i(0) {}

	HasPtr(const HasPtr& original);
	HasPtr& operator =(const HasPtr&);
	 
	~HasPtr() { delete ps; }//指针和引用不会隐式调用析构函数
	void display() { std::cout << *ps << std::endl; }
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
bool operator<(const HasPtr& lhs, const HasPtr& rhs) { return *lhs.ps < *rhs.ps; }
int main()
{
	HasPtr test1("test1"), test2("test2");

	//std::swap(test1, test2);
	//swap(test1, test2);

	std::vector<HasPtr> v_h;
	v_h.push_back(test2);
	v_h.push_back(test1);
	v_h.push_back(HasPtr("test"));

	std::sort(v_h.begin(),v_h.end());
	
	for (auto ele : v_h) {
		ele.display();
	}

}