#include<iostream>

int main()
{
	int* p = 0, i = 10; 
	//����ָ���ֵ
	p = &i;
	//����ָ������ֵ
	*p = 14;

	std::cout << i;

	return 0;
}