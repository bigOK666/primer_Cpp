#include<vector>
using std::vector;

int foo(int, int);

using fooType = int(*)(int, int);

typedef int (*foTy)(int, int);
vector<decltype(foo)*> v;
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


