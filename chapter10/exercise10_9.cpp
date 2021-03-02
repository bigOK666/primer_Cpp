#include<vector>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
void elimDups(vector<string>& v_s)
{
	sort(v_s.begin(), v_s.end());
	auto unique_iter = unique(v_s.begin(), v_s.end());

	v_s.erase(unique_iter, v_s.end());
}

int main() {
	vector<string> text{ "this", "is", "a","test", "to", "test", "elimate", "duplicates" };

	elimDups(text);

	cout << count(text.cbegin(), text.cend(), "test");
}