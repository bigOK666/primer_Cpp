#include<list>
#include<iostream>
int main()
{
	std::list<int> li{ 1,2,3,4,5 };
	auto iter = li.erase(li.begin(), li.begin());

	for (auto i : li) {
		std::cout << i << std::endl;
	}

	std::cout << *iter;
}