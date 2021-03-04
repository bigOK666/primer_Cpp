#include<map>
#include<iostream>
#include<set>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	map<string, size_t> word_count;

	string word;
	string token{ ",." };
	while (cin >> word) {
		/*
		if (word.find_first_of(token) != string::npos) {
			word.erase(word.find_first_of(token), 1);
		}
		*/
		word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
		for_each(word.begin(), word.end(), [](char &c) {c = tolower(c); });
		cout << word << endl;;
		++word_count[word];
	}

	for (auto& w : word_count) {
		cout << w.first << " occurs" << w.second << " " << (w.second > 1 ? "times" : "time") << endl;
	}
}