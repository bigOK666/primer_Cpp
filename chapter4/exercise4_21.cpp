#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
	vector<int> v{ 1,3,5,8,9 };
	for (auto& i : v) {
		i % 2 == 1 ? i = i * i : i = i;
	}
	
	for (const auto j : v) {
		cout << j << endl;
	}

	return 0;
	
}