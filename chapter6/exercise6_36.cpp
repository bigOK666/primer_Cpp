#include<string>
//这种声明方式也比较简洁
std::string (&foo(int i))[10];
//这种声明方式比较简洁
using sArry = std::string [10];

sArry &fooSArry(int i);
//这种声明方式凑合
auto fooTr(int i)->std::string(&)[10];
//这种声明方式不好，因为需要先定义一个同类型的变量
std::string sA[10];

decltype(sA) &fooDec(int i);