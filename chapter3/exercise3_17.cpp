#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::cin;
using std::vector;
using std::string;

int main()
{
	vector<string> v;
	string s;

	while (cin >> s) {
		
		v.push_back(s);
	}

	for (auto sele : v) {
		cout << sele << " ";
		for (auto &c : sele) {
			c = toupper(c);
		}
		cout << sele << " ";
	}

	return 0;


}