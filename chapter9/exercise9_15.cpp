#include<vector>
#include<list>
#include<iostream>
bool isEqual(const std::vector<int>& v1, const std::vector<int>& v2) {
	return v1 == v2;
}
int main()
{
	std::vector<int> v1{ 1,2,3 };
	std::vector<int> v2{ 2,3,54 };
	std::cout << isEqual(v1, v2) << std::endl;

}