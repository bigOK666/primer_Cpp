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
	vector<unsigned> scores(11, 0);
	unsigned grade;
	auto it = scores.begin();
	while (cin >> grade) {
		if (grade<= 100)
		++(*(it + grade / 10));
	}
	for (it; it != scores.end(); ++it) {
		cout << *it << endl;;
	}
	

	return 0;
}