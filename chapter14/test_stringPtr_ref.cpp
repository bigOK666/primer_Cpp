#include<string>
#include<iostream>
int main()
{
	std::string s("test");
	std::string* sptr = &s;
	//string��ָ�����ֱ�����±���ã���
	std::cout<< sptr[0];
}