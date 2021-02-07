#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
	string s1, s2;
	bool repeat = false;
	while (cin >> s1) {
		if (s1[0] != toupper(s1[0])) {
			continue;
		}
		if (s1 == s2) {
			cout << s1 << " is repeated." << endl;
			repeat = true;
			break;
		}
		else {
			s2 = s1;
		}
	}

	if (!repeat) {
		cout << "No repeated word." << endl;
	}

	return 0;
}