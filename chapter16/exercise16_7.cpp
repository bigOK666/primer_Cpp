template<typename T, unsigned N> constexpr unsigned size_new(const T(&arr)[N])
{
	return N;



}

#include<iostream>

int main()
{
	int arr[] = { 1,2,3,4,54 };
	std::cout << size_new(arr);

	int arr2[size_new(arr)];

	std::cout << size_new(arr2);
}