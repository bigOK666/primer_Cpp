#include<iostream>

template<typename T, unsigned N>void print(const T (&arr)[N])
{
	for (auto item : arr) {
		std::cout << item << std::endl;
	}
}

int main()
{
	print("Test");
	print({ 1,3,2 });
}