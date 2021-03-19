class Sales_data{};

#include<iostream>

template<typename T> int compare(const T& t1, const T& t2)
{
	if (t1 < t2) return 1;
	if (t2 < t1) return -1;
	return 0;

}

int main()
{
	std::cout << compare(Sales_data(), Sales_data());
}