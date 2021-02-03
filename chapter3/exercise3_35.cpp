#include<iostream>
//#include <array>

using std::cout;
using std::cin;
using std::endl;
using std::begin;
using std::end;
int main()
{
	int arr[] = { 0, 2, 4,6,98,32 };
	int* beg = begin(arr);
	int* last = end(arr);

	for (beg; beg != last; ++beg) {
		*beg = 0;
	}

	for (auto ele : arr) {
		cout << ele << endl;
	}

	return 0;

}