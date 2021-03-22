#include<regex>
#include<iostream>
int main()
{
	std::regex r("(\\d{5})([-]?\\d{4})?");

	std::string s{"123451234"};

	std::string fmt = "$1-$2";

	std::cout << std::regex_replace(s, r, fmt) << std::endl;


}