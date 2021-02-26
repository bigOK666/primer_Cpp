#include<vector>
#include<list>
#include<iostream>
int main()
{
	int ia[] = { 0, 1,1,2,3,5,8,13,21,55,89 };
	std::vector<int> v_i;
	std::list<int> l_i;
	for (auto i : ia) {
		v_i.push_back(i);
		l_i.push_back(i);
	}

	for (auto ele_l : l_i) {
		std::cout << "List elements" << std::endl;
		std::cout << ele_l << std::endl;
	}
	
	for (auto ele_v : v_i) {
		std::cout << "Vector elements" << std::endl;
		std::cout << ele_v << std::endl;
	}
	

	auto iter = v_i.begin();
	while (iter != v_i.end()) {
		if (*iter % 2==0)
			iter = v_i.erase(iter);
		else
			++iter;
	}
	
	auto it = l_i.begin();
	while (it != l_i.end()) {
		if (*it % 2)
			it = l_i.erase(it);
		else
			++it;
	}
	
	/*continue之后还会再执行++it,所以应该用while
	for (auto it = l_i.begin(); it != l_i.end(); ++it) {
		if (*it % 2) {
			it = l_i.erase(it);
			continue;
		}
	}
	*/
	
	for (auto iter = v_i.begin(); iter != v_i.end(); ++iter) {
		std::cout << "Vector elements:" << std::endl;
		std::cout << *iter << std::endl;
	}
	

	for (auto ele_l:l_i) {
		std::cout << "List elements" << std::endl;
		std::cout << ele_l << std::endl;
	}


	
}