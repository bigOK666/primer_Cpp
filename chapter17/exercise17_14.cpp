#include<regex>
#include<iostream>
int main()
{
	std::regex r("[^c]ie");
	std::smatch results;
	if (regex_search("my.cc", results, r)) {
		std::cout << results.str();
	}

	std::regex r2("[^");
	std::cmatch r2results;
	regex_search("my.cc", r2results, r);
}