#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int arr[10] = {};
	int j = 0;
	for (auto &i : arr) {
		i = j;
		++j;
		cout << arr[i] << endl;
	}
	
	int arr2[10] = {};
	for (auto a : arr) {
		arr2[a] = a;
		cout << arr2[a] << endl;
	}

	//地址不一样。cout << (arr2 == arr) << endl;
	

	vector<int> v(10);
	int k = 0;
	for (auto &vi : v) {
		cout << vi << endl;
		vi = k;
		cout << v[k] << endl;

		++k;
	}

	vector<int> v2 = v;

	for (auto v2i : v2) {
		cout << v2i << endl;
	}
	return 0;


}