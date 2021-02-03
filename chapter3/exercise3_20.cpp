#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main() {

	int x=0;
	vector<int> v;
	while (cin >> x) {
		v.push_back(x);
	}

	

	for (decltype(v.size()) i = 0; i < v.size(); i = i + 2) {
		if (i + 1 == v.size()) {
			cout << v[i] << endl;
		}
		else {
			cout << v[i] + v[i + 1] << endl;
		}
	}
	decltype(v.size()) n = v.size();
	for (decltype(v.size()) j = 0; j < v.size() / 2; ++j) {
		
			cout << v[j] + v[n - 1] << endl;
			--n;
	}
	if (v.size() % 2 == 1) {
		cout << v[v.size() / 2] << endl;
	}
	return 0;
}