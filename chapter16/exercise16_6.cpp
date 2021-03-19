#include<iostream>

template<typename T1, unsigned N>T1* begin_new(const T1(&arr)[N])
{
	auto ptr = const_cast<T1*>(arr);
	return ptr;
}

template<typename T1, unsigned N> T1* end_new(const T1(&arr)[N])
{
	auto ptr = const_cast<T1*>(arr) + N;
	return ptr;
}

int main()
{
	int arr[] = { 1,2,3,4,5 };

	std::cout << *(begin_new("test"));
}