#include<string>

class HasPtr {
public:
	HasPtr(const std::string& s = std::string()) :ps(new std::string(s)), i(0) {}

	HasPtr(const HasPtr& original);
	HasPtr& operator =(const HasPtr&);
	~HasPtr() { delete ps; }//ָ������ò�����ʽ������������
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
	ps = new std::string(*original.ps);
	i = original.i;
	return *this;
}