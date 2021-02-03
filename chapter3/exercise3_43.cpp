#include<iostream>
using std::cout;
using std::endl;
int main()
{
	int ia[3][4] = {
		{0,1,2,3},
		{4,5,6,7},
		{8,9,10,11} };

	//version1 range for loop
	cout << "range for" << endl;
	for (int (&p)[4]:ia) {
		for (int q : p) {
			cout << q;
		}
	}

	//version2 for index
	cout << "for index" << endl;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << ia[i][j] << endl;
		}
	}

	//version3 for pointer
	cout << "for pointer" << endl;
	for (int(*p)[4] = ia; p != ia + 3; ++p) {
		for (int* q = *p; q != *p + 4; ++q) {
			cout << *q << endl;
		}
	}

	//use alias type
	cout << "use alias type" << endl;
	using int_array = int[4];

	for (int_array* p = ia; p != ia + 3; ++p) {
		for (int* q = *p; q != *p + 4; ++q) {
			cout << *q << endl;
		}
	}

	for (int_array& p : ia) {
		for (int q : p) {
			cout << q;
		}
	}

	//use auto
	cout << "use auto" << endl;
	for (auto& row : ia) {
		for (auto col : row) {
			cout << col << endl;
		}
	}

	return 0;
	
}