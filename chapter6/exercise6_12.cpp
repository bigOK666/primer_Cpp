#include<iostream>

void swap(int& i, int& j)
{
	int temp = j;
	j = i;
	i = temp;
}

int main()
{
	int i = 2, j = 5;

	swap(i, j);

	std::cout << i << " " << j;

	return 0;
}