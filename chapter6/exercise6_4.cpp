#include<iostream>
using std::cout;
using std::endl;
using std::cin;

int fact_interact() {
	int result = 1;
	int a;
	cout << "Enter a number:";
	cin >> a;
	for (int i = 1; i <= a; ++i) {
		result *= i;
	}

	return result;
}

int main()
{
	
	cout << fact_interact() << endl;
	return 0;
}