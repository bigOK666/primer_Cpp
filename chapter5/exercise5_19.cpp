#include<iostream>
#include<string>

int main()
{
	std::string rsp;

	do {
		std::string s1, s2;
		std::cin >> s1 >> s2;
		if (s1.size() <= s2.size()) {
			std::cout << s1;
		}
		else
		{
			std::cout << s2;
		}

		std::cout << "continue input? yes or no" << std::endl;
		std::cin >> rsp;
	} while (!rsp.empty() && rsp[0] != 'n');

	return 0;
}