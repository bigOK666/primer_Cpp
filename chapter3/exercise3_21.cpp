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
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4{ 10 };
	vector<int> v5{ 10, 42 };
	vector<string>v6{ 10 };
	vector<string> v7{ 10, "hi" };

	vector<vector<int>> vv{ v1, v2, v3, v4, v5 };
	vector<vector<string>> svv{ v6, v7 };

	for (auto vit = vv.cbegin(); vit != vv.cend(); ++vit) {
		cout << vit->size() << endl;
		for (auto it  = vit->cbegin(); it !=vit->cend(); ++it) {
			cout << *it << endl;
		}
	}

	for (auto svit = svv.cbegin(); svit != svv.cend();++svit) {
		cout << svit->size() << endl;
		for (auto it = svit->cbegin(); it != svit->cend();++it) {
			cout << *it << endl;
		}
	}

	return 0;

}