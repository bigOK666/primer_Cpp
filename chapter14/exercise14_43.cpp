#include<vector>
#include<functional>
#include<iostream>
int main()
{
	std::vector<int> v_i{ 2,3,4,5,6,67 };
	std::modulus<int> modu;
	for (auto i : v_i) {
		
		if (modu(i, 2)) {
			std::cout << i<<" cannot be divieded totally" << std::endl;
			break;
		}
	}
}