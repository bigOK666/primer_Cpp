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
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4{ 10 };
	vector<int> v5{ 10, 42 };
	vector<string>v6{ 10 };
	vector<string> v7{ 10, "hi" };

	vector<vector<int>> vv{ v1, v2, v3, v4, v5 };
	vector<vector<string>> svv{ v6, v7 };

	for (auto v : vv) {
		cout << v.size() << endl;
		for (auto ele : v) {
			cout << ele << endl;
		}
	}

	for (auto sv : svv) {
		cout << sv.size() << endl;
		for (auto sele : sv) {
			cout << sele << endl;
		}
	}

	return 0;
	
}