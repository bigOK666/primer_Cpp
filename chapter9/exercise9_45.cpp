#include<string>
#include<iostream>
using namespace std;

string addExtra(const string& s, const string& pre, const string& tail)
{
	string newName = s;
	//insert iterator�汾���ص��ǵ�������
	newName.append(" " + tail).insert(newName.begin(), pre.cbegin(), pre.cend());

	return newName;
}

int main()
{
	string name{ "Tom" };

	cout << addExtra(name, "Mr.", "Jr.");
}


