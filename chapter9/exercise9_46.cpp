#include<string>
#include<iostream>
using namespace std;

string addExtra(const string& s, const string& pre, const string& tail)
{
	string newName = s;
	return newName.insert(0, pre).insert(newName.size()+pre.size()," "+ tail);//newName.size()��δ����ǰ�Ĵ�С,��÷ֿ�д������ִ���

	

}

int main()
{
	string name{ "Tom" };

	cout << addExtra(name, "Mr.", "Jr.");
}