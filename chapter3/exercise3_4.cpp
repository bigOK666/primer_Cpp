#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
	string x, y;
	cin >> x >> y;
	if (x == y) {
		cout << x << " is the same as " << y << endl;
	}
	else {
		if (x > y) {
			cout << x;
		}
		else {
			cout << y;
		}
	}


	if (x.size() == y.size()) {
		cout << x << " has the same size as " << y << endl;

	}
	else {
		if (x.size() > y.size()) {
			cout << x;
		}
		else {
			cout << y;
		}
	}
	return 0;
}