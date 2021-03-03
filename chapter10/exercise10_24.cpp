#include<vector>
#include<iostream>
#include<string>
#include<functional>
#include<algorithm>
using namespace std;
using namespace std::placeholders;
bool check_size(const string& s, string::size_type sz)
{
	return s.size() >= sz;
}

int main()
{
	string s{ "Test" };
	vector<int> v_i{ 1,2,3,4,5,6,76,9 };

	auto newCall = bind(check_size, s, _1);

	auto iter = find_if_not(v_i.cbegin(), v_i.cend(), newCall);
	cout << *iter << endl;
}