#include<utility>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
void store(const string& s, int i, vector<pair<string, int>> &storeData) {
	//storeData.push_back({s, i});
	//storeData.push_back(pair<string, int>(s, i));
	storeData.push_back(make_pair(s, i));
}

int main()
{
	string s1;
	int j = 0;
	vector<pair<string, int>> v_p;
	while (cin >> s1 >> j) {
		store(s1, j, v_p);
	}

	for_each(v_p.cbegin(), v_p.cend(), [](const pair<string, int>& p) {cout << p.first << " " << p.second << endl; });
	
}