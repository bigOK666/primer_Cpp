#include<map>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
using FamilyMap = multimap<string, vector<string>>;
void addFamily(const string& s, FamilyMap& fm)
{
	fm.insert(make_pair(s, vector<string>()));
}

void addChildren(const string& name, const string& family, FamilyMap& fm) {
	fm.insert(make_pair(family, vector<string>{name}));
	//fm[family].push_back(make_pair(name, birthday));
}

int main()
{
	FamilyMap family_children;


	addFamily("F1", family_children);
	addChildren("childf2", "F2", family_children);
	addChildren("childf1", "F1", family_children);


	cout << family_children.size();
}