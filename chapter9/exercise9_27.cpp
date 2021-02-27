#include<forward_list>

int main()
{
	std::forward_list<int> f_i{ 1,2,3,4,5,6,7,8,9,10 };
	auto prev = f_i.before_begin();
	auto curr = f_i.begin();

	while (curr != f_i.end()) {
		if (*curr % 2) {
			curr = f_i.erase_after(prev);
		}
		else {
			prev = curr;
			++curr;
		}
	}
}