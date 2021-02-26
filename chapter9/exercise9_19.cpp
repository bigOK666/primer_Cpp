#include<iostream>
#include<list>
#include<string>
int main()
{
	std::list<std::string> de_str;
	std::string temp;
	while (std::cin >> temp) {
		de_str.push_back(temp);
	}

	for (auto item : de_str) {
		std::cout << item << " ";
	}
}