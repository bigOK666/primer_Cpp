#include<iostream>

#include<vector>
using vec_iter = std::vector<int>::iterator;

vec_iter exist(vec_iter begin_iter, vec_iter end_iter, int goal)
{
	if (begin_iter > end_iter) {
		std::cerr << "iterator is not valid" << std::endl;
		return end_iter;
	}
	else {
		while (begin_iter != end_iter) {
			if (*begin_iter == goal) {
				return begin_iter;
			}
			else {
				++begin_iter;
			}
		}
		return end_iter;
	}
}