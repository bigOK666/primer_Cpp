#include<vector>
#include<iostream>
using std::vector;
//declare a function
int foo(int, int);
//a vector contains pointer to that function
vector<decltype(foo)*> v;
//define a type for a pointer to that function
using fooType = int(*)(int, int);

typedef int (*foTy)(int, int);

vector<fooType> v2;



int addDemo(int a, int b)
{
	return a + b;
}

int minusDemo(int a, int b)
{
	return a - b;
}

int productDemo(int a, int b)
{
	return a * b;
}

int devideDemo(int a, int b)
{
	return a / b;
}
foTy p = addDemo;
fooType q = minusDemo;
foTy x = productDemo;
foTy y = devideDemo;

vector<fooType> v3 = { addDemo, minusDemo, productDemo, devideDemo };


int main()
{
	for (auto func : v3) {
		std::cout<<func(6, 3);
	}
}