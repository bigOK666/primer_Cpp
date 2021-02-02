#include<iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
	cout << "Enter two numbers: " << endl;
	int v1 = 0, v2 = 0;

	cin >> v1 >> v2;

	if (v2 < v1) {
		int tmp = v1;
		v1 = v2;
		v2 = tmp;
	}

	while (v1 <= v2) {
		cout << v1 << endl;
		++v1;
	}

	return 0;
}