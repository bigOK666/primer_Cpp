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

bool isShorter(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
}

int main() {
	vector<string> text{ "this", "is", "a","test", "to", "test", "elimate", "duplicates" };
	elimDups(text);
	stable_sort(text.begin(), text.end(), isShorter);

	for (auto &word : text) {
		cout << word << endl;
	}
}