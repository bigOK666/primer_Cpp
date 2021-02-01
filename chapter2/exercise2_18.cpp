#include<iostream>

int main()
{
	int* p = 0, i = 10; 
	//更改指针的值
	p = &i;
	//更改指针对象的值
	*p = 14;

	std::cout << i;

	return 0;
}