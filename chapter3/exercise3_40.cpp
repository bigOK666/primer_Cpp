#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

int main()
{
	char c1[] = "string1";
	char c2[] = "string2";
	char c3[20];
	char c4[20];
	strcpy(c3, c1);
	cout << c3 << endl;

	strcat(c3, c2);

	cout << c3 << endl;

	return 0;

}