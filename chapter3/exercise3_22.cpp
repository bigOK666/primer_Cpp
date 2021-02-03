#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main()
{
	vector<string> text;
	string w;
	while (cin >> w) {
		text.push_back(w);
	}
	for (auto it = text.begin(); it != text.end() && !it->empty();++it) {
		for (auto cit = it->begin(); cit != it->end(); ++cit) {
			*cit = toupper(*cit);
		}
		cout << *it << endl;
	}

	return 0;
}