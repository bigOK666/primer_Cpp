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
	vector<int> a(10, 2);

	for (auto it = a.begin(); it != a.end(); ++it) {
		*it = *it * (*it);
		cout << *it << endl;
	}

	return 0;
}