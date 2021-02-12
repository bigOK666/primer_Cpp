#include<vector>
using std::vector;

int foo(int, int);

using fooType = int(*)(int, int);
vector<decltype(foo)*> v;
vector<fooType> v2;


