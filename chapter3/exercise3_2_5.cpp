#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() 
{	
	string x;
	while (getline(cin, x)) {
		cout << x << endl;
	}

	return 0;
}