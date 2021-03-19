#include<iostream>
#include<list>
template<typename T>void print_container(T& container) {
	typename T::iterator beg = container.begin();
	
	while (beg != container.end()) {
		std::cout << *beg << " ";
		++beg;
	}

}


int main()
{
	std::list<int> l_i{ 1,2,3 };

	print_container(l_i);
}
