#include<map>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
using FamilyMap = map<string, vector<pair<string, string>>>;
void addFamily(const string& s, FamilyMap& fm)
{
	fm[s];
}

void addChildren(const string& name, const string& birthday,const string& family, FamilyMap& fm) {
	fm[family].push_back(make_pair(name, birthday));
}

int main()
{
	FamilyMap family_children;
	

	addFamily("F1", family_children);
	addChildren("childf2", "1990-1-23", "F2", family_children);
	addChildren("childf1", "2010-2-12", "F1", family_children);


	cout << family_children.size();
}