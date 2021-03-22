#include<regex>
#include<string>
#include<iostream>
using namespace std;

int main()
{
	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern);
	string temp;
	smatch results;
	while (cin >> temp) {
		regex_search(temp,results, r);
		if (results.empty()) {
			cout << "Word is correct" << endl; 
		}
		else
		{
			cout << results.str() << " is not correct." << endl;
		}
	}
}