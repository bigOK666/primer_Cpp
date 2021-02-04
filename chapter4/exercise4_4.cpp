#include<iostream>

using std::cout;
using std::endl;

int main()
{
	cout << (12 / 3 * 4 + 5 * 15 + 24 % 4 / 2) << endl;
	cout << (-30 * 3 + 21 / 5) << endl;
	cout << -30 + 3 * 21 / 5 << endl;
	cout << 30 / 3 * 21 % 5 << endl;
	cout << -30 / 3 * 21 % 4 << endl;
	int x = 20;
	cout << (x % 2 == 0 )<< endl;
	x = 21;
	cout << (x % 2 == 0) << endl;

	return 0;
}