#include<vector>
#include<list>
#include<iostream>
bool isEqual(const std::list<int>& l1, const std::vector<int>& v2) {
	std::vector<int> v1;
	v1.assign(l1.begin(), l1.end());
	
	return v1 == v2;
}
int main()
{
	std::list<int> l1{ 2,3,54 };
	std::vector<int> v2{ 2,3,54 };
	std::cout << isEqual(l1, v2) << std::endl;

}