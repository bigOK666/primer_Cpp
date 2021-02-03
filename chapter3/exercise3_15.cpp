#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
	string s;
	vector<string> s_vector;

	while (cin >> s) {
		s_vector.push_back(s);
	}

	for (auto s_el : s_vector) {
		cout << s_el << endl;
	}

	return 0;

}