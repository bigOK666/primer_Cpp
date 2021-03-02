#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
using namespace std;

bool moreThan5(const string& s) {
	return s.size() >= 5;
}

int main()
{
	vector<string> words{ "this", "is", "a", "testfor", "fivewords" };

	auto iterAfterLast = partition(words.begin(), words.end(), moreThan5);
	auto iterWords = words.begin();
	while (iterWords != iterAfterLast) {
		cout << *iterWords << endl;;
		++iterWords;
	}
}

