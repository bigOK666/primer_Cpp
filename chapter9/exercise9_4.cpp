#include<iostream>

#include<vector>
using vec_iter = std::vector<int>::iterator;

bool exist(vec_iter begin_iter, vec_iter end_iter, int goal)
{
	if (begin_iter > end_iter) {
		std::cerr << "iterator is not valid" << std::endl;
		return false;
	}
	else {
		while (begin_iter != end_iter) {
			if (*begin_iter == goal) {
				return true;
			}
			else {
				++begin_iter;
			}
		}
		return false;
	}
}

int main()
{
	std::vector<int> vec_i{ 1,2,3,4,5 };
	std::cout << exist(vec_i.begin(), vec_i.end(), 5);
	
}