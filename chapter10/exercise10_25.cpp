#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
#include<functional>
using namespace std::placeholders;

using namespace std;
void elimDups(vector<string>& v_s)
{
	sort(v_s.begin(), v_s.end());
	auto unique_iter = unique(v_s.begin(), v_s.end());

	v_s.erase(unique_iter, v_s.end());
}

bool check_size(const string& s, string::size_type sz)
{
	return s.size() >= sz;
}


void biggies(vector<string>& words, vector<string>::size_type sz)
{
	elimDups(words);

	stable_sort(words.begin(), words.end(), [](const string& a, const string& b) {return a.size() < b.size(); });

	auto newCall = bind(check_size, _1, sz);
	
	auto wc = partition(words.begin(), words.end(), newCall);

	//auto wc = partition(words.begin(), words.end(), [sz](const string& a) {return a.size() < sz; });

	auto count = wc-words.begin();

	for_each(words.begin(), wc, [](const string& s) {cout << s << endl; });
}

int main()
{
	vector<string> words{ "this", "is", "a", "testfor", "fivewords" };

	biggies(words, 4);
}