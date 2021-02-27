#include<list>
#include<forward_list>
#include<iostream>
int main()
{
	std::list<int> vi = { 0,1,2,3,4,5,6,7,8 };

	auto iter = vi.begin();
	while (iter != vi.end()) {
		if (*iter % 2) {
			iter = vi.insert(iter, *iter);
			++iter;
			++iter;
		}
		else {
			iter = vi.erase(iter);
		}
	}

	std::forward_list<int> f_i = { 0,1,2,3,4,5,6,7,8 };
	auto iter_f = f_i.begin();
	auto prev = f_i.before_begin();

	while (iter_f != f_i.end()) {
		if (*iter_f % 2) {
			iter_f = f_i.insert_after(iter_f, *iter_f);
			//iter_f = f_i.insert_after(prev, *iter_f);
			++prev, ++iter_f;
			++prev;
			//++prev, ++iter_f;
		}
		else {
			iter_f = f_i.erase_after(prev);
		}
	}

	for (auto i : f_i) {
		std::cout << i << " ";
	}
}