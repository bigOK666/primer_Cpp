#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<functional>
using namespace std;
using namespace std::placeholders;
bool isLessEqualThan(const string& s, string::size_type sz)
{
	return s.size() <= sz;
}

int main()
{
	vector<string> words{ "this", "is", "a", "testfor", "fivewords" };

	size_t number = 6;

	cout << count_if(words.cbegin(), words.cend(), [number](const string& s) {return s.size() <= number; }) << endl;

	auto newCall = bind(isLessEqualThan, _1, number);

	//cout << count_if(words.cbegin(), words.cend(), isLessEqualThan) << endl;

	cout << count_if(words.cbegin(), words.cend(), newCall);

}