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
	int x = 0;
	vector<int> v;
	while (cin >> x) {
		v.push_back(x);
	}
	decltype(v.size()) n = v.size();
	for (auto it = v.begin(); it != v.end(); it+=2) {
		if ((it +1) == v.end()) {
			cout << *it << endl;
			break;
		}
		cout << *it + *(it+1) << endl;
	}
	auto n2 = v.end() - v.begin();
	//cout << v.end() - v.begin() << endl;
	auto it_end = v.end();
	for (auto it2 = v.begin(); it2 < v.begin() + n2/ 2; ++it2) {
		cout << *it2 + *(it_end-1) << endl;
		--it_end;
		//cout << n2 << endl;
	}
	
	if (n2 % 2 == 1) {

		cout << *(v.begin() + (v.end() - v.begin()) / 2) << endl;
	}
	

	return 0;
}