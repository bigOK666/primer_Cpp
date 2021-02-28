#include<string>
#include<iostream>
int main()
{
	char c;
	std::string store;
	store.reserve(100);
	while (std::cin >> c) {
		store.push_back(c);
	}

	std::cout << store;
}