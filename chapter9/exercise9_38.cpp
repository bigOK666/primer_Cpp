#include<vector>
#include<iostream>
int main()
{
	std::vector<int> v_i;
	for (int i = 0; i < 12; ++i) {
		std::cout << v_i.size() << std::endl;
		std::cout << v_i.capacity() << std::endl;
		v_i.push_back(i);
		std::cout << v_i.size() << std::endl;
		std::cout << v_i.capacity() << std::endl;
	}
}