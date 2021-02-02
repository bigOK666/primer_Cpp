#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
	string x, y, z;
	while (cin>>x) {
		y += x;
		z = z + " " + x;
		
	}
	cout << y << endl;
	cout << z << endl;
	return 0;
}