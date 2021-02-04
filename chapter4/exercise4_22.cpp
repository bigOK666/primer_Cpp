#include<string>
#include<iostream>

using std::cout;
using std::endl;
using std::string;

int main()
{
	string finalgrade;
	int grade = 80;
	finalgrade = (grade > 90) ? "high pass" : (grade > 75) ? "low pass" : (grade < 60) ? "fail" : "pass";

	cout << finalgrade << endl;

	if (grade > 90) {
		cout << "high pass if";
	}
	else if (grade > 75) {
		cout << "low pass";
	}
	else if (grade < 60) {
		cout << "fail";
	}
	else {
		cout << "pass";
	}

	return 0;
}