#include<iostream>
#include<vector>
#include<list>
#include<string>


template<typename T1, typename T2> T1 find(T1 beginIter, T1 endIter, const T2& target)
{
	while (beginIter != endIter) {
		if (*beginIter == target) {
			return beginIter;
		}
		else {
			++beginIter;
		}
	}

	return endIter;
}

int main()
{
	std::vector<int> v_i{ 1,2,3,4,5 };
	std::list<std::string> l_i{ "he", "she", "it","test" };

	if (::find(v_i.begin(), v_i.end(), 4) != v_i.end()) { std::cout << "find!"; }
	if (::find(l_i.begin(), l_i.end(), "he") != l_i.end()) { std::cout << "found!"; }
}