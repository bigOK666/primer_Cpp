#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::vector;

int main()
{
	vector<int> v1 = { 1, 2,3, 4, 5 };
	vector<int> v2 = { 1, 2, 2 };
	vector<int> small;
	vector<int> big;
	if (v1.size() >= v2.size()) {
		big = v1;
		small = v2;
	}
	else {
		big = v2;
		small = v1;
	}
	
	
	
		for (auto itr = small.begin(), j = big.begin(); itr != small.end(); ++itr) {
			if (*itr != *j) {
				cout << "v2 is not the prefix";
				return 0;
			}
			else {
				++j;
			}
		}
		cout << "v2 is the prefex";
		return 0;
	
}