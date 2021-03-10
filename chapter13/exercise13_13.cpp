#include<iostream>
#include<vector>

struct X
{
	X() { std::cout << "X()" << std::endl; }
	X(const X&) { std::cout << "X(const X&)" << std::endl; }
	X& operator=(const X&) { std::cout << "X& operator=(const X&)" << std::endl; return *this; }
	~X() { std::cout << "~X()" << std::endl; }
};

void print(X& x1) { X i; i = x1; }
void print2(X x2) { X i; i = x2; }
int main()
{
	X i, i3;
	X i2 = i;
	i3 = i2;
	std::cout << "Reference define" << std::endl;
	X& i4 = i2;
	std::cout << "allocate memory" << std::endl;
	X* i5 = new X();
	std::cout << "vector" << std::endl;
	std::vector<X> v_x{ i,i4 };
	std::cout << "push back" << std::endl;
	v_x.push_back(*i5);
	std::cout << "print reference" << std::endl;
	print(i);
	std::cout << "print copy constructor" << std::endl;
	print(i3);

	delete i5;
}