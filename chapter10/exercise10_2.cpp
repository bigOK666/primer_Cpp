#include<string>
#include<list>
#include<iostream>

using namespace std;

int main()
{
	string input;
	list<string> l_s;
	while (cin >> input) {
		l_s.push_back(input);
	}

	cout << count(l_s.cbegin(), l_s.cend(), "test");
}