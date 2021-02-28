#include<string>
#include<iostream>
using namespace std;

string addExtra(const string& s, const string& pre, const string& tail)
{
	string newName = s;
	//insert iterator版本返回的是迭代器。
	newName.append(" " + tail).insert(newName.begin(), pre.cbegin(), pre.cend());

	return newName;
}

int main()
{
	string name{ "Tom" };

	cout << addExtra(name, "Mr.", "Jr.");
}


