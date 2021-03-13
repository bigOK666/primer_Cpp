#include<vector>
#include<algorithm>
#include<iostream>
class Foo {
public:
	Foo& operator=(const Foo&)&;
	Foo sorted()&&;
	Foo sorted() const&;
private:
	std::vector<int> data;

};

Foo& Foo::operator=(const Foo& rhs)&
{
	return *this;
}

Foo Foo::sorted()&&
{
	sort(data.begin(), data.end());

	
	std::cout << "right ref" << std::endl;
	return *this;
}

Foo Foo::sorted() const&
{
	Foo ret(*this);
	//sort(ret.data.begin(), ret.data.end());
	std::cout << "left ref" << std::endl;
	return ret.sorted();
}