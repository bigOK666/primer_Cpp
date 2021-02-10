#include<initializer_list>
#include<iostream>
using std::initializer_list;

int sumInitList(initializer_list<int> il)
{
	int sum = 0;
	for (const auto& ele : il) {
		sum += ele;
	}
	return sum;
}

int main()
{
	initializer_list<int> il1 = { 1,2,3,4,5,6,7,8,9,10 };

	std::cout << sumInitList(il1);

	return 0;
}