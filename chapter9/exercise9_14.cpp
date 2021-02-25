#include<list>
#include<vector>
#include<string>
#include<iostream>
int main()
{
	std::list<const char*> li_ch{ "test", "sls", "sdfa" };
	std::vector<std::string> v_str;

	v_str.assign(li_ch.cbegin(), li_ch.cend());

	for (auto v_s : v_str) {
		std::cout << v_s << std::endl;
	}
}