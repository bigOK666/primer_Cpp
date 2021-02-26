#include<iostream>
#include<deque>
#include<string>
int main()
{
	std::deque<std::string> de_str;
	std::string temp;
	while (std::cin >> temp ) {
		de_str.push_back(temp);
	}

	for (auto item : de_str) {
		std::cout << item << " ";
	}
}