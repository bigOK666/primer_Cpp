#include<vector>
#include<string>
#include<iostream>
template<typename T>unsigned countNr(const std::vector<T>& v, const T &target) {
	unsigned ctr = 0;
	for (auto i : v) {
		if (i == target)
			++ctr;
	}
	return ctr;
}


int main()
{
	std::vector<int> v_i{ 1,2,3,4,5,2,2,2 };
	std::vector<double> v_d{ 2.3,4.43,5.3,8.2,5.3 };
	std::vector<std::string> v_s{ "test", "sd2", "whi" };
	std::string t("what");
	std::cout << countNr(v_i, 2);
	std::cout << countNr(v_d, 5.3);
	std::cout << countNr(v_s, t);
}