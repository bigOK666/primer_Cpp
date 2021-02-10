#include<iostream>

int biggerOne(const int a, const int* b)
{
	return a > *b ? a : *b;
}

int main()
{
	int i = 10, j = 20;
	std::cout << biggerOne(i, &j);

	return 0;
}