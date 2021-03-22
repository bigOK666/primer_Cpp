#include<regex>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern, regex::icase);
	string temp;
	smatch results;
	vector<string> escape_v{ "albeit", "neighbor" };
	while (getline(cin, temp)) {
		
		
		for (sregex_iterator it(temp.begin(), temp.end(), r), end_it;
			it != end_it; ++it) {
			if (find(escape_v.begin(), escape_v.end(), it->str()) != escape_v.end()) {
				continue;
			}
			cout << it->str() << endl;
		}

	}
}