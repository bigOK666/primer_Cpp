#include<iostream>


void print(const int a[10])
{
	for (size_t i = 0; i != 10; ++i) {
		std::cout << a[i] << std::endl;
	}
}

int main()
{
	int a[] = { 1,2,3,4,5,4,4,4,4,4 };

	print(a);

	return 0;
}