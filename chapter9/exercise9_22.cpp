#include<vector>
#include<iostream>
using std::vector;


int main()
{
	vector<int>iv{ 1,2,3,4,5,6,7,8,9,10 };
	vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
	int some_value(2);

	while (iter != mid) {
		//std::cout << *iter << std::endl;
		//std::cout << *mid << std::endl;
		if (*iter == some_value) {
			++(iter = iv.insert(iter, 2 * some_value));//++的优先级高于=，所以需要括号
			
		}
		std::cout << *iter << std::endl;
		++iter;
		std::cout << *iter << std::endl;
		mid = iv.begin() + iv.size() / 2;
	}

	for (auto i : iv) {
		std::cout << i << " ";
	}
}