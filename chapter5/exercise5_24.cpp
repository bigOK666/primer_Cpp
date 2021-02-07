#include<iostream>
#include<stdexcept>
using std::cin;
using std::cout;
using std::runtime_error;
int main()
{
	int i1, i2;
	cin >> i1 >> i2;

	if (i2 == 0) {
		throw runtime_error("divider should be non-zero");
	}
	cout << i1 / i2;

	return 0;
}