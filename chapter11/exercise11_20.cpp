#include<map>
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string word;
	map<string, int> wordCount;

	while (cin >> word) {
		auto ret = wordCount.insert(make_pair(word, 1));

		if (!ret.second) {
			++ret.first->second;
		}
	}
}