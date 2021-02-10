#include<string>
#include<iostream>
using std::string;
bool uppercaseExist(const string& s)
{
	for (auto c : s) {
		if (c == toupper(c)) {
			return true;
		}
	}

	return false;
}

void sToLower(string& s)
{
	for (auto &c : s) {
		if (c == toupper(c)) {
			c = tolower(c);
		}
	}
	
}

int main()
{
	string s("This is a TEST");
	if (uppercaseExist(s)) {
		sToLower(s);
	}

	std::cout << s;

	return 0;
}