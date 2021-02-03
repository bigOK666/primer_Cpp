#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::endl;
using std::string;
using std::begin;
using std::end;
using std::vector;

int main()
{
	int arr[] = { 1, 2, 4, 5 };
	vector<int> v(begin(arr), end(arr));
	for (auto i : v) {
		cout << i << endl;

	}
	
	int arr2[4];
	size_t d = 0;
	for (auto e : v) {
		arr2[d] = e;
		++d;
	}

	for (auto el : arr2) cout << el << endl;
	return 0;
}