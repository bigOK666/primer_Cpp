#include<iostream>

void print(const int& i)
{
	std::cout << i;
}

void print(const int * j, size_t size)
{
	for (size_t i = 0; i < size; ++i) {
		std::cout << j[i];
	}
	
}


int main()
{
	int i = 10;
	int j[2] = { 1,2 };

	print(i);
	print(j, 2);
	return 0;
}