#include<iostream>
using std::cout;
using std::endl;
int fact(int x) {
	int result = 1;
	for (int i = 1; i <= x; ++i) {
		result *= i;
	}

	return result;
}

int main()
{
	cout << fact(1) << endl;
}
