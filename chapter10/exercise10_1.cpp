#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int input;
	vector<int> v_i;
	while (cin >> input) {
		v_i.push_back(input);
	}

	cout << count(v_i.cbegin(), v_i.cend(), 5);
}