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
	int input=0;
	vector<int> input_vector;
	while (cin >> input) {
		input_vector.push_back(input);
	
	}
	for (auto element : input_vector) {
		cout << element << endl;
	}
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