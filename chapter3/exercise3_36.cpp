#include<iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::begin;
using std::end;
using std::vector;
int main()
{
	int arr1[] = { 1, 2, 3, 5 };
	int arr2[] = { 1, 2, 5, 5 };
	vector<int> v1(4, 10);
	vector<int> v2(4, 11);

	int* b1 = begin(arr1);
	int* b2 = begin(arr2);
	int* e1 = end(arr1);
	int* e2 = end(arr2);

	if (e1 - b1 != e2 - b2) {
		cout << "arr1 is not the same as arr2" << endl;
	}
	else {
		int diff = 0;
		for (b1; b1 < e1; ++b1) {
			if (*b1 != *b2) {
				++diff;
				break;
			}
			++b2;
		}
		if (diff != 0) {
			cout << "arr1 is not the same as arr2" << endl;

		}
		else {
			cout << "arr1 is the same as arr2" << endl;

		}

	}

	cout << (v1 == v2) << endl;
}