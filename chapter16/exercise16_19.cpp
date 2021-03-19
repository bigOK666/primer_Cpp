#include<iostream>
#include<vector>
template<typename T>void print_container(T& container) {
	for (typename T::size_type i = 0; i < container.size(); ++i) {
		std::cout << container[i] << " ";
	}
}


int main()
{
	std::vector<int> l_i{ 1,2,3 };

	print_container(l_i);
}
