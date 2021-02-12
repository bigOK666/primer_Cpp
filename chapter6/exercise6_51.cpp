#include<iostream>

void f() 
{
	std::cout << "empty parameter";
}

void f(int)
{
	std::cout << "1 parameter";
}

void f(int, int)
{
	std::cout << "2 int parameter";
}

void f(double, double = 3.14) {
	std::cout << "2 double";
}

int main()
{
	//f(2.56, 42);
	f(42);
	f(42, 0);
	f(2.56, 3.14);
}
