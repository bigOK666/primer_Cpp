#include<map>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
using FamilyMap = map<string, vector<string>>;
void addFamily(const string& s, FamilyMap& fm)
{
	fm[s];
}

void addChildren(const string& name, const string& family, FamilyMap& fm) {
	fm[family].push_back(name);
}

int main()
{
	map<string, vector<string>> family_children;
	string familyName;
	
	addFamily("F1", family_children);
	addChildren("childf2", "F2", family_children);
	addChildren("childf1", "F1", family_children);


	cout << family_children.size();
}