#include<list>
#include<deque>
#include<iostream>
int main()
{
	std::list<int> l_i{ 1,2,3,4,5,6,7,8,9 };
	std::deque<int> de_even;
	std::deque<int> de_odd;

	for (auto li : l_i) {
		if (li % 2 == 0) {
			de_even.push_back(li);
		}
		else {
			de_odd.push_back(li);
		}
	}

	for (auto even : de_even) {
		std::cout << even << " ";
	}

	for (auto odd: de_odd)
	{
		std::cout << odd << " ";
	}
}