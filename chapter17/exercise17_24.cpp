#include<string>
#include<vector>
#include<regex>
#include<iostream>
using namespace std;
int main()
{
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	std::cout << "before regex" << endl;
	
	regex r(phone);
	
	
	std::cout << "before string s" << endl;
	string s;
	smatch m;
	string fmt = "$2.$5.$7";
	std::cout << "befor getline" << endl;
	while (getline(std::cin, s)) {
		std::cout << regex_replace(s, r, fmt) << endl;

		
	}
	return 0;

}

