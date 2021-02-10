#include<iostream>

void reset(int& i)
{
	i = 0;
}

int main()
{
	int j = 44;
	reset(j);
	std::cout << j;

	return 0;
}