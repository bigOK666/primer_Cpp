#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
#include"exercise14_38.h"
using namespace std;

class sizeComp {
public:
	bool operator()(const string& s1, const string& s2) {
		return s1.size() < s2.size();
	}
};

class lessSize {
public:
	lessSize(size_t n) : size(n) {}
	bool operator() (const std::string& s) {
		return s.size() < size;
	}
private:
	size_t size;
};
void elimDups(vector<string>& v_s)
{
	sort(v_s.begin(), v_s.end());
	auto unique_iter = unique(v_s.begin(), v_s.end());

	v_s.erase(unique_iter, v_s.end());
}

void biggies(vector<string>& words, vector<string>::size_type sz)
{
	elimDups(words);

	stable_sort(words.begin(), words.end(), sizeComp());

	auto wc = partition(words.begin(), words.end(), lessSize(sz));

	auto count = words.end() - wc;

	for_each(wc, words.end(), [](const string& s) {cout << s << endl; });
}

int main()
{
	vector<string> words{ "this", "is", "a", "testfor", "fivewords" };

	biggies(words, 4);
}