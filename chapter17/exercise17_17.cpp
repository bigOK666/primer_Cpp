#include<regex>
#include<string>
#include<iostream>
using namespace std;

int main()
{
	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern, regex::icase);
	string temp;
	smatch results;
	while (getline(cin,temp)) {
		

		for (sregex_iterator it(temp.begin(), temp.end(), r), end_it;
			it != end_it; ++it) {
			cout << it->str() << endl;
		}
		
	}
}