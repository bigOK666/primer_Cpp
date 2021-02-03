#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

int main()
{
	string s1("test1");
	string s2("test2");
	cout << (s1 == s2) << endl;

	const char c1[] = { 't', 'e', 's','1','\0' };
	const char c2[] = { 't', 'e', 's','2','\0' };

	cout << strcmp(c1, c2) << endl;
}