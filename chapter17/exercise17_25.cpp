#include<string>
#include<vector>
#include<regex>
#include<iostream>
#include<iterator>
using namespace std;
int main()
{
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	std::cout << "before regex" << endl;

	regex r(phone);


	std::cout << "before string s" << endl;
	string s;
	smatch m;
	string dest;
	string fmt = "$2.$5.$7";
	std::cout << "befor getline" << endl;
	
	while (getline(std::cin, s)) {
		dest = regex_replace(s, r, fmt);
		cout << string(dest.begin(), dest.begin() + 12) << endl;


	}
	return 0;

}

