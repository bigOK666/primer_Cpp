#include<vector>
#include<iostream>
#include<algorithm>
#include<iterator>
using namespace std;

int main()
{
	vector<int> v_i;
	int i;
	while (cin >> i) {
		if (find(v_i.cbegin(), v_i.cend(), i) == v_i.cend()) {
			v_i.push_back(i);
		}
	}

	ostream_iterator<int> out(cout, " ");

	copy(v_i.cbegin(), v_i.cend(), out);
}