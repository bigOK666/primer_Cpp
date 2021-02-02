#include<iostream>
#include<string>
#include<typeinfo>
using std::string;
using std::cout;
using std::endl;
int main()
{
	string s("This should be X");

	for (auto &c : s) {
		cout << typeid(c).name() << endl;
		c = 'X';
	}

	cout << s;

	return 0;
}