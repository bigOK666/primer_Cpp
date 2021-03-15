#include<string>
#include<iostream>
int main()
{
	std::string s("test");
	std::string* sptr = &s;
	//string的指针可以直接用下标调用！！
	std::cout<< sptr[0];
}