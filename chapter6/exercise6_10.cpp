#include<iostream>

int swap(int *a, int *b) 
{
	int temp = *b;
	*b = *a;
	*a = temp;

	return 0;
}

int main()
{
	int i = 2, j = 5;

	swap(&i, &j);

	std::cout << i << " " << j;

	return 0;
}